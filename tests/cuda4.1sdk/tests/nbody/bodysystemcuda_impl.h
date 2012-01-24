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

#include <cutil_inline.h>    // includes cuda.h and cuda_runtime_api.h

#include <assert.h>
#include <math.h>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <GL/glew.h>

#include <cuda_gl_interop.h>

template <typename T>
void integrateNbodySystem(DeviceData<T>* deviceData,
                          cudaGraphicsResource** pgres, unsigned int currentRead,
                          float deltaTime, float damping, 
                          unsigned int numBodies, unsigned int numDevices,
                          int p, int q, bool bUsePBO);

template<typename T>
BodySystemCUDA<T>::BodySystemCUDA(unsigned int numBodies, unsigned int numDevices, unsigned int p, unsigned int q, bool usePBO, bool useSysMem)
: m_numBodies(numBodies),
  m_numDevices(numDevices),
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
 
    m_deviceData = 0;

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

    m_deviceData = new DeviceData<T>[m_numDevices];

    // divide up the workload amongst Devices
    float *weights = new float[m_numDevices];
    int *numSms = new int[m_numDevices];
    float total = 0;

    for (unsigned int i = 0; i < m_numDevices; i++)
    {
        cudaDeviceProp props;
        cutilSafeCall(cudaGetDeviceProperties(&props, i));
        
        // Choose the weight based on the Compute Capability
        // We estimate that a CC2.0 SM is about 4.0x faster than a CC 1.x SM for
        // this application (since a 15-SM GF100 is about 2X faster than a 30-SM GT200).
        numSms[i] = props.multiProcessorCount;
        weights[i] = numSms[i] * (props.major >= 2 ? 4.f : 1.f);
        total += weights[i];
        
    }

    unsigned int offset = 0;
    unsigned int remaining = m_numBodies;
    for (unsigned int i = 0; i < m_numDevices; i++)
    {
        unsigned int count = (int)((weights[i] / total) * m_numBodies);
        unsigned int round = numSms[i] * 256;
        count = round * ((count + round - 1) / round);
        if (count > remaining) count = remaining;
        remaining -= count;
        m_deviceData[i].offset = offset;
        m_deviceData[i].numBodies = count;
        offset += count;
        if ((i == m_numDevices - 1) && (offset < m_numBodies-1))
            m_deviceData[i].numBodies += m_numBodies - offset;
    }

    delete [] weights;
    delete [] numSms;

    if (m_bUseSysMem)
    {
        cutilSafeCall(cudaHostAlloc((void **)&m_hPos[0], memSize, cudaHostAllocMapped | cudaHostAllocPortable));
        cutilSafeCall(cudaHostAlloc((void **)&m_hPos[1], memSize, cudaHostAllocMapped | cudaHostAllocPortable));
        cutilSafeCall(cudaHostAlloc((void **)&m_hVel,    memSize, cudaHostAllocMapped | cudaHostAllocPortable));     

        memset(m_hPos[0], 0, memSize);
        memset(m_hPos[1], 0, memSize);
        memset(m_hVel, 0, memSize);
        
        for (unsigned int i = 0; i < m_numDevices; i++)
        {
            if (m_numDevices > 1) 
                cutilSafeCall(cudaSetDevice(i));
            cutilSafeCall(cudaEventCreate(&m_deviceData[i].event));
            cutilSafeCall(cudaHostGetDevicePointer((void **)&m_deviceData[i].dPos[0], (void *)m_hPos[0], 0));
            cutilSafeCall(cudaHostGetDevicePointer((void **)&m_deviceData[i].dPos[1], (void *)m_hPos[1], 0));
            cutilSafeCall(cudaHostGetDevicePointer((void **)&m_deviceData[i].dVel,    (void *)m_hVel, 0));
        }
    }
    else
    {
        m_hPos[0] = new T[m_numBodies*4];
        m_hVel = new T[m_numBodies*4];

        memset(m_hPos[0], 0, memSize);
        memset(m_hVel, 0, memSize);

        cutilSafeCall(cudaEventCreate(&m_deviceData[0].event));
        
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
            cutilSafeCall(cudaMalloc((void **)&m_deviceData[0].dPos[0], memSize));
            cutilSafeCall(cudaMalloc((void **)&m_deviceData[0].dPos[1], memSize));
        } 

        cutilSafeCall(cudaMalloc((void **)&m_deviceData[0].dVel, memSize));
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

        for (unsigned int i = 0; i < m_numDevices; i++)
            cudaEventDestroy(m_deviceData[i].event);
    }
    else
    {
        delete [] m_hPos[0];
        delete [] m_hPos[1];
        delete [] m_hVel;

        cutilSafeCall(cudaFree((void**)m_deviceData[0].dVel));
        if (m_bUsePBO)
        {
            cutilSafeCall(cudaGraphicsUnregisterResource(m_pGRes[0]));
            cutilSafeCall(cudaGraphicsUnregisterResource(m_pGRes[1]));
            glDeleteBuffers(2, (const GLuint*)m_pbo);
        }
        else
        {
            cutilSafeCall(cudaFree((void**)m_deviceData[0].dPos[0]));
            cutilSafeCall(cudaFree((void**)m_deviceData[0].dPos[1]));
        }
    }

    delete [] m_deviceData;
}

template<typename T>
void BodySystemCUDA<T>::setSoftening(T softening)
{
    T softeningSq = softening*softening;

    for (unsigned int i = 0; i < m_numDevices; i++)
    {
        if (m_numDevices > 1)
            cutilSafeCall(cudaSetDevice(i));
        cutilSafeCall(cudaMemcpyToSymbol((sizeof(T) > 4) ? "softeningSquared_fp64" : "softeningSquared", 
                                         &softeningSq, 
                                         sizeof(T), 0, 
                                         cudaMemcpyHostToDevice));    
    }
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
        
    integrateNbodySystem<T>(m_deviceData, m_pGRes, m_currentRead, 
                            (float)deltaTime, (float)m_damping, 
                            m_numBodies, m_numDevices,
                            m_p, m_q, m_bUsePBO);
        
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
        ddata = m_deviceData[0].dPos[m_currentRead];
	    if (m_bUsePBO)
            pgres = m_pGRes[m_currentRead];
	        
        break;
    case BODYSYSTEM_VELOCITY:
        hdata = m_hVel;
        ddata = m_deviceData[0].dVel;
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
                    cutilSafeCall(cudaMemcpy(m_deviceData[0].dPos[m_currentRead], data, 
                                             m_numBodies * 4 * sizeof(T), 
                                             cudaMemcpyHostToDevice));
	        }
        }
        break;
    case BODYSYSTEM_VELOCITY:
        if (m_bUseSysMem)
            memcpy(m_hVel, data, m_numBodies * 4 * sizeof(T));
        else
            cutilSafeCall(cudaMemcpy(m_deviceData[0].dVel, data, m_numBodies * 4 * sizeof(T), 
                          cudaMemcpyHostToDevice));
        break;
    }       
}
