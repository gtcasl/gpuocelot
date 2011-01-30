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

#ifndef __BODYSYSTEMCUDA_H__
#define __BODYSYSTEMCUDA_H__

#include "bodysystem.h"


// CUDA BodySystem: runs on the GPU
template <typename T>
class BodySystemCUDA : public BodySystem<T>
{
public:
    BodySystemCUDA(int numBodies, bool usePBO);
    BodySystemCUDA(int numBodies, unsigned int p, unsigned int q, bool usePBO, bool useSysMem = false);
    virtual ~BodySystemCUDA();

    virtual void update(T deltaTime);

    virtual void setSoftening(T softening);
    virtual void setDamping(T damping);

    virtual T* getArray(BodyArray array);
    virtual void   setArray(BodyArray array, const T* data);

    virtual unsigned int getCurrentReadBuffer() const 
    { 
        return m_pbo[m_currentRead]; 
    }

    virtual unsigned int getNumBodies() const { return m_numBodies; }

protected: // methods
    BodySystemCUDA() {}

    virtual void _initialize(int numBodies);
    virtual void _finalize();
    
protected: // data
    unsigned int m_numBodies;
    bool m_bInitialized;

    // CPU data
    T* m_hPos[2];
    T* m_hVel;

    // GPU data
    T* m_dPos[2];
    T* m_dVel;

    bool m_bUsePBO;
    bool m_bUseSysMem;
	unsigned int m_SMVersion;

    T m_damping;

    unsigned int m_pbo[2];
    cudaGraphicsResource* m_pGRes[2];
    unsigned int m_currentRead;
    unsigned int m_currentWrite;

    unsigned int m_p;
    unsigned int m_q;
};

#include "bodysystemcuda_impl.h"

#endif // __BODYSYSTEMCUDA_H__
