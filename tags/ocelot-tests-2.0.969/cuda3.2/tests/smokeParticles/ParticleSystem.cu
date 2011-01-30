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
	This file contains simple wrapper functions that call the CUDA kernels
 */

#include <cutil_inline.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <GL/glew.h>
#include <cuda_gl_interop.h>

#include "particles_kernel.cu"
#include "ParticleSystem.cuh"

extern "C"
{

cudaArray *noiseArray;

void initCuda(bool bUseGL)
{
	if (bUseGL) {
	    cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
	} else {
		cudaSetDevice( cutGetMaxGflopsDeviceId() );
	}
}

void setParameters(SimParams *hostParams)
{
    // copy parameters to constant memory
    cutilSafeCall( cudaMemcpyToSymbol(params, hostParams, sizeof(SimParams)) );
}

//Round a / b to nearest higher integer value
int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

// compute grid and thread block size for a given number of elements
void computeGridSize(int n, int blockSize, int &numBlocks, int &numThreads)
{
    numThreads = min(blockSize, n);
    numBlocks = iDivUp(n, numThreads);
}

inline float frand()
{
    return rand() / (float) RAND_MAX;
}

// create 3D texture containing random values
void createNoiseTexture(int w, int h, int d)
{
    cudaExtent size = make_cudaExtent(w, h, d);
    uint elements = (uint) size.width*size.height*size.depth;

    float *volumeData = (float *)malloc(elements*4*sizeof(float));
    float *ptr = volumeData;
    for(uint i=0; i<elements; i++) {
        *ptr++ = frand()*2.0f-1.0f;
        *ptr++ = frand()*2.0f-1.0f;
        *ptr++ = frand()*2.0f-1.0f;
        *ptr++ = frand()*2.0f-1.0f;
    }


    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<float4>();
    cutilSafeCall( cudaMalloc3DArray(&noiseArray, &channelDesc, size) );

    cudaMemcpy3DParms copyParams = { 0 };
    copyParams.srcPtr   = make_cudaPitchedPtr((void*)volumeData, size.width*sizeof(float4), size.width, size.height);
    copyParams.dstArray = noiseArray;
    copyParams.extent   = size;
    copyParams.kind     = cudaMemcpyHostToDevice;
    cutilSafeCall( cudaMemcpy3D(&copyParams) );

    free(volumeData);

    // set texture parameters
    noiseTex.normalized = true;                      // access with normalized texture coordinates
    noiseTex.filterMode = cudaFilterModeLinear;      // linear interpolation
    noiseTex.addressMode[0] = cudaAddressModeWrap;   // wrap texture coordinates
    noiseTex.addressMode[1] = cudaAddressModeWrap;
    noiseTex.addressMode[2] = cudaAddressModeWrap;

    // bind array to 3D texture
    cutilSafeCall(cudaBindTextureToArray(noiseTex, noiseArray, channelDesc));
}

void 
integrateSystem(float4 *oldPos, float4 *newPos,
				float4 *oldVel, float4 *newVel,
                float deltaTime,
                int numParticles)
{
    int numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

    // execute the kernel
    integrateD<<< numBlocks, numThreads >>>(newPos, newVel,
                                            oldPos, oldVel,
                                            deltaTime,
											numParticles);
    
    // check if kernel invocation generated an error
    cutilCheckMsg("Kernel execution failed");
}


void 
calcDepth(float4*  pos, 
		  float*   keys,		// output
          uint*    indices,		// output 
          float3   sortVector,
          int      numParticles)
{
    int numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

    // execute the kernel
    calcDepthD<<< numBlocks, numThreads >>>(pos, keys, indices, sortVector, numParticles);
    cutilCheckMsg("calcDepthD execution failed");
}

}   // extern "C"
