/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

#include <cutil_inline.h>

#include <assert.h>
#include <math.h>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <GL/glew.h>

#include <cuda_gl_interop.h>

template <typename T>
void integrateNbodySystem(T* newPos, T* oldPos, T* vel, 
                          cudaGraphicsResource** pgres, unsigned int currentRead,
                          float deltaTime, float damping, 
                          int numBodies, int p, int q,
                          bool bUsePBO);

template<typename T>
BodySystemCUDA<T>::BodySystemCUDA(int numBodies, bool usePBO)
: m_numBodies(numBodies),
  m_bInitialized(false),
  m_bUsePBO(usePBO),
  m_bUseSysMem(false),
  m_currentRead(0),
  m_currentWrite(1),
  m_p(256),
  m_q(1)
{
    m_hPos[0] = m_hPos[1] = 0;
    m_hVel = 0;
    m_dPos[0] = m_dPos[1] = 0;
    m_dVel = 0;

    _initialize(numBodies);
    setSoftening(0.00125f, (sizeof(T) > 4));
    setDamping(0.995f);
}

template<typename T>
BodySystemCUDA<T>::BodySystemCUDA(int numBodies, unsigned int p, unsigned int q, bool usePBO, bool useSysMem)
: m_numBodies(numBodies),
  m_bInitialized(false),
  m_bUsePBO(usePBO),
  m_bUseSysMem(useSysMem),
  m_currentRead(0),
  m_currentWrite(1),
  m_p(p),
  m_q(q)
{
    m_hPos[0] = m_hPos[1] = 0;
    m_hVel = 0;
    m_dPos[0] = m_dPos[1] = 0;
    m_dVel = 0;

    _initialize(numBodies);
    setSoftening(0.00125f);
    setDamping(0.995f);   
}

template<typename T>
BodySystemCUDA<T>::~BodySystemCUDA()
{
    _finalize();
    m_numBodies = 0;
}

template<typename T>
void BodySystemCUDA<T>::_initialize(int numBodies)
{
    assert(!m_bInitialized);

    m_numBodies = numBodies;

    unsigned int memSize = sizeof(T) * 4 * numBodies;

    if (m_bUseSysMem)
    {
        cutilSafeCall(cudaHostAlloc((void **)&m_hPos[0], memSize, cudaHostAllocMapped));
        cutilSafeCall(cudaHostAlloc((void **)&m_hPos[1], memSize, cudaHostAllocMapped));
        cutilSafeCall(cudaHostAlloc((void **)&m_hVel, memSize, cudaHostAllocMapped));     

        memset(m_hPos[0], 0, memSize);
        memset(m_hPos[1], 0, memSize);
        memset(m_hVel, 0, memSize);
        

        cutilSafeCall(cudaHostGetDevicePointer((void **)&m_dPos[0], (void *)m_hPos[0], 0));
        cutilSafeCall(cudaHostGetDevicePointer((void **)&m_dPos[1], (void *)m_hPos[1], 0));
        cutilSafeCall(cudaHostGetDevicePointer((void **)&m_dVel,    (void *)m_hVel, 0));
    }
    else
    {
        m_hPos[0] = new T[m_numBodies*4];
        m_hVel = new T[m_numBodies*4];

        memset(m_hPos[0], 0, memSize);
        memset(m_hVel, 0, memSize);
        
        if (m_bUsePBO)
        {
            // create the position pixel buffer objects for rendering
            // we will actually compute directly from this memory in CUDA too
            glGenBuffers(2, (GLuint*)m_pbo);   
            for (int i = 0; i < 2; ++i)
            {
                glBindBuffer(GL_ARRAY_BUFFER, m_pbo[i]);
                glBufferData(GL_ARRAY_BUFFER, memSize, m_hPos[0], GL_DYNAMIC_DRAW);

                int size = 0;
                glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, (GLint*)&size); 
                
                if ((unsigned)size != memSize)
                    fprintf(stderr, "WARNING: Pixel Buffer Object allocation failed!n");
                
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                cutilSafeCall(cudaGraphicsGLRegisterBuffer(&m_pGRes[i], 
                                                           m_pbo[i], 
                                                           cudaGraphicsMapFlagsNone));
            }
        }
        else
        {
            cutilSafeCall(cudaMalloc((void**)&m_dPos[0], memSize));
            cutilSafeCall(cudaMalloc((void**)&m_dPos[1], memSize));
        } 

        cutilSafeCall(cudaMalloc((void**)&m_dVel, memSize));
    }   

    m_bInitialized = true;
}

template<typename T>
void BodySystemCUDA<T>::_finalize()
{
    assert(m_bInitialized);

    if (m_bUseSysMem)
    {
        cutilSafeCall(cudaFreeHost(m_hPos[0]));
        cutilSafeCall(cudaFreeHost(m_hPos[1]));
        cutilSafeCall(cudaFreeHost(m_hVel));
    }
    else
    {
        delete [] m_hPos[0];
        delete [] m_hPos[1];
        delete [] m_hVel;

        cutilSafeCall(cudaFree((void**)m_dVel));
        if (m_bUsePBO)
        {
            cutilSafeCall(cudaGraphicsUnregisterResource(m_pGRes[0]));
            cutilSafeCall(cudaGraphicsUnregisterResource(m_pGRes[1]));
            glDeleteBuffers(2, (const GLuint*)m_pbo);
        }
        else
        {
            cutilSafeCall(cudaFree((void**)m_dPos[0]));
            cutilSafeCall(cudaFree((void**)m_dPos[1]));
        }
    }
}

template<typename T>
void BodySystemCUDA<T>::setSoftening(T softening)
{
    T softeningSq = softening*softening;

    cutilSafeCall(cudaMemcpyToSymbol((sizeof(T) > 4) ? "softeningSquared_fp64" : "softeningSquared", 
                                     &softeningSq, 
                                     sizeof(T), 0, 
                                     cudaMemcpyHostToDevice));    
}

template<typename T>
void BodySystemCUDA<T>::setDamping(T damping)
{
    m_damping = damping;
}

template<typename T>
void BodySystemCUDA<T>::update(T deltaTime)
{
    assert(m_bInitialized);
    
    
    integrateNbodySystem<T>(m_dPos[m_currentWrite], m_dPos[m_currentRead], m_dVel,
                            m_pGRes, m_currentRead,
		                    deltaTime, m_damping, m_numBodies, m_p, m_q, m_bUsePBO);
        
    std::swap(m_currentRead, m_currentWrite);
}

template<typename T>
T* BodySystemCUDA<T>::getArray(BodyArray array)
{
    assert(m_bInitialized);
 
    T* hdata = 0;
    T* ddata = 0;

    cudaGraphicsResource* pgres = NULL;

    int currentReadHost = m_bUseSysMem ? m_currentRead : 0;

    switch (array)
    {
    default:
    case BODYSYSTEM_POSITION:
        hdata = m_hPos[currentReadHost];
        ddata = m_dPos[m_currentRead];
	    if (m_bUsePBO)
            pgres = m_pGRes[m_currentRead];
	        
        break;
    case BODYSYSTEM_VELOCITY:
        hdata = m_hVel;
        ddata = m_dVel;
        break;
    }

    if (!m_bUseSysMem)
    {
        if (pgres)
        {
            cutilSafeCall(cudaGraphicsResourceSetMapFlags(pgres, cudaGraphicsMapFlagsReadOnly));     
            cutilSafeCall(cudaGraphicsMapResources(1, &pgres, 0));     
            size_t bytes;
            cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void**)&ddata, &bytes, pgres));
        }

        cutilSafeCall(cudaMemcpy(hdata, ddata, 
                                 m_numBodies*4*sizeof(T), cudaMemcpyDeviceToHost));

        if (pgres)
        {
            cutilSafeCall(cudaGraphicsUnmapResources(1, &pgres, 0));
        }           
    }
    return hdata;
}

template<typename T>
void BodySystemCUDA<T>::setArray(BodyArray array, const T* data)
{
    assert(m_bInitialized);

    m_currentRead = 0;
    m_currentWrite = 1;
 
    switch (array)
    {
    default:
    case BODYSYSTEM_POSITION:
        {
	        if (m_bUsePBO)
	        {
		        glBindBuffer(GL_ARRAY_BUFFER, m_pbo[m_currentRead]);
		        glBufferSubData(GL_ARRAY_BUFFER, 0, 4 * sizeof(T) * m_numBodies, data);
    		
		        int size = 0;
		        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, (GLint*)&size); 
		        if ((unsigned)size != 4 * (sizeof(T) * m_numBodies))
		            fprintf(stderr, "WARNING: Pixel Buffer Object download failed!n");
		        glBindBuffer(GL_ARRAY_BUFFER, 0);
	        }
	        else
	        {
                if (m_bUseSysMem)
                    memcpy(m_hPos[m_currentRead], data, m_numBodies * 4 * sizeof(T));
                else
                    cutilSafeCall(cudaMemcpy(m_dPos[m_currentRead], data, 
                                             m_numBodies * 4 * sizeof(T), 
                                             cudaMemcpyHostToDevice));
	        }
        }
        break;
    case BODYSYSTEM_VELOCITY:
        if (m_bUseSysMem)
            memcpy(m_hVel, data, m_numBodies * 4 * sizeof(T));
        else
            cutilSafeCall(cudaMemcpy(m_dVel, data, m_numBodies * 4 * sizeof(T), 
                          cudaMemcpyHostToDevice));
        break;
    }       
}
