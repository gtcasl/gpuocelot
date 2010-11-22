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

/* 
 * CUDA Device code for particle simulation.
 */

#ifndef _PARTICLES_KERNEL_H_
#define _PARTICLES_KERNEL_H_

#include "cutil_math.h"
#include "math_constants.h"
#include "particles_kernel.cuh"

texture<float4, 3, cudaReadModeElementType> noiseTex;

// simulation parameters
__constant__ SimParams params;

// look up in 3D noise texture
__device__
float3 noise3D(float3 p)
{
    float4 n = tex3D(noiseTex, p.x, p.y, p.z);
    return make_float3(n.x, n.y, n.z);
}

__device__
float3 fractalSum3D(float3 p, int octaves, float lacunarity, float gain)
{
	float freq = 1.0f, amp = 0.5f;
	float3 sum = make_float3(0.0f);	
	for(int i=0; i<octaves; i++) {
		sum += noise3D(p*freq)*amp;
		freq *= lacunarity;
		amp *= gain;
	}
	return sum;
}

__device__
float3 turbulence3D(float3 p, int octaves, float lacunarity, float gain)
{
	float freq = 1.0f, amp = 0.5f;
	float3 sum = make_float3(0.0f);	
	for(int i=0; i<octaves; i++) {
		sum += fabs(noise3D(p*freq))*amp;
		freq *= lacunarity;
		amp *= gain;
	}
	return sum;
}

// integrate particle attributes
__global__ void
integrateD(float4* newPos, float4* newVel, 
           float4* oldPos, float4* oldVel, 
           float deltaTime,
		   int numParticles)
{
    int index = __mul24(blockIdx.x,blockDim.x) + threadIdx.x;
	if (index >= numParticles) return;

	volatile float4 posData = oldPos[index];	// ensure coalesced reads
    volatile float4 velData = oldVel[index];

    float3 pos = make_float3(posData.x, posData.y, posData.z);
    float3 vel = make_float3(velData.x, velData.y, velData.z);
    
    // update particle age
	float age = posData.w;	
	float lifetime = velData.w;
	if (age < lifetime) {
		age += deltaTime;
	} else {
	    age = lifetime;
    }

    // apply accelerations
    vel += params.gravity * deltaTime;

    // apply procedural noise
    float3 noise = noise3D(pos*params.noiseFreq + params.time*params.noiseSpeed);
    vel += noise * params.noiseAmp;

    // new position = old position + velocity * deltaTime
    pos += vel * deltaTime;

    vel *= params.globalDamping;

    // store new position and velocity
    newPos[index] = make_float4(pos, age);
    newVel[index] = make_float4(vel, velData.w);
}

// calculate sort depth for each particle
__global__ void calcDepthD(float4* pos, float* keys, uint *indices, float3 vector, int numParticles)
{
	uint index = __mul24(blockIdx.x,blockDim.x) + threadIdx.x;
	if (index >= numParticles) return;

	volatile float4 p = pos[index];
	float key = -dot(make_float3(p.x, p.y, p.z), vector);        // project onto sort vector
	
	keys[index] = key;
	indices[index] = index;
}

#endif
