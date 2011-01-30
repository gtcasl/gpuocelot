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

#include <math.h>

////////////////////////////////////////////////////////////////////////////////
// export C interface
extern "C" 
void computeGold( float* reference, float* idata, const unsigned int len);

void
bodyBodyInteraction(float accel[3], float posMass0[4], float posMass1[4], float softeningSquared) 
{
    float r[3];

    // r_01  [3 FLOPS]
    r[0] = posMass0[0] - posMass1[0];
    r[1] = posMass0[1] - posMass1[1];
    r[2] = posMass0[2] - posMass1[2];

    // d^2 + e^2 [6 FLOPS]
    float distSqr = r[0] * r[0] + r[1] * r[1] + r[2] * r[2];
    distSqr += softeningSquared;

    // invDistCube =1/distSqr^(3/2)  [4 FLOPS (2 mul, 1 sqrt, 1 inv)]
    float invDist = 1.0f / sqrtf(distSqr);
	float invDistCube =  invDist * invDist * invDist;

    // s = m_j * invDistCube [1 FLOP]
    float s = posMass1[3] * invDistCube;

    // (m_1 * r_01) / (d^2 + e^2)^(3/2)  [6 FLOPS]
    accel[0] += r[0] * s;
    accel[1] += r[1] * s;
    accel[2] += r[2] * s;
}

////////////////////////////////////////////////////////////////////////////////
//! Compute reference data set
//! Each element is multiplied with the number of threads / array length
//! @param reference  reference data, computed but preallocated
//! @param idata      input data as provided to device
//! @param len        number of elements in reference / idata
////////////////////////////////////////////////////////////////////////////////
void
computeGold( float* force, float* pos, const unsigned int numBodies, float softeningSquared) 
{
    for(unsigned int i = 0; i < numBodies; ++i)
    {
        force[i*4  ] = 0;
		force[i*4+1] = 0;
		force[i*4+2] = 0;
		force[i*4+3] = 0;
    }

    for(unsigned int i = 0; i < numBodies; ++i) 
    {
        for(unsigned int j = 0; j < numBodies; ++j) 
	    {
	        float f[4];		
	        bodyBodyInteraction(f, &pos[j*4], &pos[i*4], softeningSquared);	
	        for (int k = 0; k < 3; ++k)
	        {
	            force[i*4+k] += f[k];
	        }
	    }
    }
}

