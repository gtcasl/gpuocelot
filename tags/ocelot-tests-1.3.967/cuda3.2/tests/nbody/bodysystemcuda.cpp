/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation. 
 * Any use, reproduction, disclosure, or distribution of this software 
 * and related documentation without an express license agreement from
 * NVIDIA Corporation is strictly prohibited.
 *
 * Please refer to the applicable NVIDIA end user license agreement (EULA) 
 * associated with this source code for terms and conditions that govern 
 * your use of this NVIDIA software.
 * 
 */

#include "bodysystemcuda.h"

#include <cutil_inline.h>

#include <assert.h>
#include <math.h>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <GL/glew.h>

extern "C"
{
    void cudaInit(int argc, char **argv);
    void setDeviceSoftening(float softening);
    void allocateNBodyArrays(float* vel[2], int numBodies);
    void deleteNBodyArrays(float* vel[2]);
    void integrateNbodySystem(float* newPos, float* newVel, 
                              float* oldPos, float* oldVel,
                              unsigned int pboOldPos, unsigned int pboNewPos,
                              float deltaTime, float damping, 
                              int numBodies, int p, int q,
							  int bUsePBO);
    void copyArrayFromDevice(float* host, const float* device, unsigned int pbo, int numBodies);
    void copyArrayToDevice(float* device, const float* host, int numBodies);
    void registerGLBufferObject(unsigned int pbo);
    void unregisterGLBufferObject(unsigned int pbo);
	void threadSync();
}


BodySystemCUDA::BodySystemCUDA(int numBodies, bool usePBO)
: BodySystem(numBodies),
  m_hPos(0),
  m_hVel(0),
  m_bUsePBO(usePBO),
  m_currentRead(0),
  m_currentWrite(1),
  m_p(256),
  m_q(1)
{
    m_dPos[0] = m_dPos[1] = 0;
    m_dVel[0] = m_dVel[1] = 0;

    _initialize(numBodies);
    setSoftening(0.00125f);
    setDamping(0.995f);
}

BodySystemCUDA::BodySystemCUDA(int numBodies, unsigned int p, unsigned int q, bool usePBO)
: BodySystem(numBodies),
  m_hPos(0),
  m_hVel(0),
  m_bUsePBO(usePBO),
  m_currentRead(0),
  m_currentWrite(1),
  m_p(p),
  m_q(q)
{
    m_dPos[0] = m_dPos[1] = 0;
    m_dVel[0] = m_dVel[1] = 0;

    _initialize(numBodies);
    setSoftening(0.00125f);
    setDamping(0.995f);   
}

BodySystemCUDA::~BodySystemCUDA()
{
    _finalize();
    m_numBodies = 0;
}

void
BodySystemCUDA::_initialize(int numBodies)
{
    assert(!m_bInitialized);

    m_numBodies = numBodies;

    m_hPos = new float[m_numBodies*4];
    m_hVel = new float[m_numBodies*4];

    memset(m_hPos, 0, m_numBodies*4*sizeof(float));
    memset(m_hVel, 0, m_numBodies*4*sizeof(float));

    if (m_bUsePBO)
    {
        // create the position pixel buffer objects for rendering
        // we will actually compute directly from this memory in CUDA too
        glGenBuffers(2, (GLuint*)m_pbo);   
        for (int i = 0; i < 2; ++i)
        {
            glBindBuffer(GL_ARRAY_BUFFER, m_pbo[i]);
            glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float) * m_numBodies, 
		         m_hPos, GL_DYNAMIC_DRAW);

            int size = 0;
            glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, (GLint*)&size); 
            
            if ((unsigned)size != 4 * (sizeof(float) * m_numBodies))
                fprintf(stderr, "WARNING: Pixel Buffer Object allocation FAILEDn");
            
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            registerGLBufferObject(m_pbo[i]);
        }
    }
    else
    {
        allocateNBodyArrays(m_dPos, m_numBodies);
    }

    allocateNBodyArrays(m_dVel, m_numBodies);

    m_bInitialized = true;
}

void
BodySystemCUDA::_finalize()
{
    assert(m_bInitialized);

    delete [] m_hPos;
    delete [] m_hVel;

    deleteNBodyArrays(m_dVel);
    if (m_bUsePBO)
    {
        unregisterGLBufferObject(m_pbo[0]);
        unregisterGLBufferObject(m_pbo[1]);
	glDeleteBuffers(2, (const GLuint*)m_pbo);
    }
    else
    {
        deleteNBodyArrays(m_dPos);
    }
}

void
BodySystemCUDA::setSoftening(float softening)
{
    setDeviceSoftening(softening);
}

void
BodySystemCUDA::setDamping(float damping)
{
    m_damping = damping;
}


void 
BodySystemCUDA::update(float deltaTime)
{
    assert(m_bInitialized);
    
    integrateNbodySystem(m_dPos[m_currentWrite], m_dVel[m_currentWrite], 
                         m_dPos[m_currentRead], m_dVel[m_currentRead],
                         m_pbo[m_currentRead], m_pbo[m_currentWrite],
			             deltaTime, m_damping, m_numBodies, m_p, m_q, (m_bUsePBO ? 1 : 0));
    
    std::swap(m_currentRead, m_currentWrite);
}

float* 
BodySystemCUDA::getArray(BodyArray array)
{
    assert(m_bInitialized);
 
    float* hdata = 0;
    float* ddata = 0;

    unsigned int pbo = 0;

    switch (array)
    {
    default:
    case BODYSYSTEM_POSITION:
        hdata = m_hPos;
        ddata = m_dPos[m_currentRead];
	if (m_bUsePBO)
	    pbo = m_pbo[m_currentRead];
        break;
    case BODYSYSTEM_VELOCITY:
        hdata = m_hVel;
        ddata = m_dVel[m_currentRead];
        break;
    }

    copyArrayFromDevice(hdata, ddata, pbo, m_numBodies);
    return hdata;
}

void
BodySystemCUDA::setArray(BodyArray array, const float* data)
{
    assert(m_bInitialized);
 
    switch (array)
    {
    default:
    case BODYSYSTEM_POSITION:
        {
	    if (m_bUsePBO)
	    {
	        unregisterGLBufferObject(m_pbo[m_currentRead]);
		glBindBuffer(GL_ARRAY_BUFFER, m_pbo[m_currentRead]);
		glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float) * m_numBodies, 
			     data, GL_DYNAMIC_DRAW);
		
		int size = 0;
		glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, (GLint*)&size); 
		if ((unsigned)size != 4 * (sizeof(float) * m_numBodies))
		    fprintf(stderr, "WARNING: Pixel Buffer Object download FAILEDn");
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		registerGLBufferObject(m_pbo[m_currentRead]);
	    }
	    else
	    {
	        copyArrayToDevice(m_dPos[m_currentRead], data, m_numBodies);
	    }
        }
        break;
    case BODYSYSTEM_VELOCITY:
        copyArrayToDevice(m_dVel[m_currentRead], data, m_numBodies);
        break;
    }       
}

void 
BodySystemCUDA::synchronizeThreads() const
{
	threadSync();
}
