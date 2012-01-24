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

// This file contains C wrappers around the some of the CUDA API and the
// kernel functions so that they can be called from "particleSystem.cpp"

#include <cutil_inline.h>    // includes cuda.h and cuda_runtime_api.h
#include <shrQATest.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <cuda_gl_interop.h>

#include "thrust/device_ptr.h"
#include "thrust/for_each.h"
#include "thrust/iterator/zip_iterator.h"
#include "thrust/sort.h"

#include "particles_kernel.cu"

extern "C"
{

void cudaInit(int argc, char **argv)
{   
    int devID;
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
        devID = cutilDeviceInit(argc, argv);
        if (devID < 0) {
            printf("No CUDA Capable devices found, exiting...\n");
            shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
        }
    } else {
        devID = cutGetMaxGflopsDeviceId();
        cudaSetDevice( devID );
    }
}

void cudaGLInit(int argc, char **argv)
{   
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
        cutilDeviceInit(argc, argv);
    } else {
        cudaGLSetGLDevice( cutGetMaxGflopsDeviceId() );
    }
}

void allocateArray(void **devPtr, size_t size)
{
    cutilSafeCall(cudaMalloc(devPtr, size));
}

void freeArray(void *devPtr)
{
    cutilSafeCall(cudaFree(devPtr));
}

void threadSync()
{
    cutilSafeCall(cutilDeviceSynchronize());
}

void copyArrayToDevice(void* device, const void* host, int offset, int size)
{
    cutilSafeCall(cudaMemcpy((char *) device + offset, host, size, cudaMemcpyHostToDevice));
}

void registerGLBufferObject(uint vbo, struct cudaGraphicsResource **cuda_vbo_resource)
{
    cutilSafeCall(cudaGraphicsGLRegisterBuffer(cuda_vbo_resource, vbo, 
					       cudaGraphicsMapFlagsNone));
}

void unregisterGLBufferObject(struct cudaGraphicsResource *cuda_vbo_resource)
{
    cutilSafeCall(cudaGraphicsUnregisterResource(cuda_vbo_resource));	
}

void *mapGLBufferObject(struct cudaGraphicsResource **cuda_vbo_resource)
{
    void *ptr;
    cutilSafeCall(cudaGraphicsMapResources(1, cuda_vbo_resource, 0));
    size_t num_bytes; 
    cutilSafeCall(cudaGraphicsResourceGetMappedPointer((void **)&ptr, &num_bytes,  
						       *cuda_vbo_resource));
    return ptr;
}

void unmapGLBufferObject(struct cudaGraphicsResource *cuda_vbo_resource)
{
   cutilSafeCall(cudaGraphicsUnmapResources(1, &cuda_vbo_resource, 0));
}

void copyArrayFromDevice(void* host, const void* device, 
			 struct cudaGraphicsResource **cuda_vbo_resource, int size)
{   
    if (cuda_vbo_resource)
	device = mapGLBufferObject(cuda_vbo_resource);

    cutilSafeCall(cudaMemcpy(host, device, size, cudaMemcpyDeviceToHost));
    
    if (cuda_vbo_resource)
	unmapGLBufferObject(*cuda_vbo_resource);
}

void setParameters(SimParams *hostParams)
{
    // copy parameters to constant memory
    cutilSafeCall( cudaMemcpyToSymbol(params, hostParams, sizeof(SimParams)) );
}

//Round a / b to nearest higher integer value
uint iDivUp(uint a, uint b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

// compute grid and thread block size for a given number of elements
void computeGridSize(uint n, uint blockSize, uint &numBlocks, uint &numThreads)
{
    numThreads = min(blockSize, n);
    numBlocks = iDivUp(n, numThreads);
}

void integrateSystem(float *pos,
                     float *vel,
                     float deltaTime,
                     uint numParticles)
{
    thrust::device_ptr<float4> d_pos4((float4 *)pos);
    thrust::device_ptr<float4> d_vel4((float4 *)vel);

    thrust::for_each(
        thrust::make_zip_iterator(thrust::make_tuple(d_pos4, d_vel4)),
        thrust::make_zip_iterator(thrust::make_tuple(d_pos4+numParticles, d_vel4+numParticles)),
        integrate_functor(deltaTime));
}

void calcHash(uint*  gridParticleHash,
              uint*  gridParticleIndex,
              float* pos, 
              int    numParticles)
{
    uint numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

    // execute the kernel
    calcHashD<<< numBlocks, numThreads >>>(gridParticleHash,
                                           gridParticleIndex,
                                           (float4 *) pos,
                                           numParticles);
    
    // check if kernel invocation generated an error
    cutilCheckMsg("Kernel execution failed");
}

void reorderDataAndFindCellStart(uint*  cellStart,
							     uint*  cellEnd,
							     float* sortedPos,
							     float* sortedVel,
                                 uint*  gridParticleHash,
                                 uint*  gridParticleIndex,
							     float* oldPos,
							     float* oldVel,
							     uint   numParticles,
							     uint   numCells)
{
    uint numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

    // set all cells to empty
	cutilSafeCall(cudaMemset(cellStart, 0xffffffff, numCells*sizeof(uint)));

#if USE_TEX
    cutilSafeCall(cudaBindTexture(0, oldPosTex, oldPos, numParticles*sizeof(float4)));
    cutilSafeCall(cudaBindTexture(0, oldVelTex, oldVel, numParticles*sizeof(float4)));
#endif

    uint smemSize = sizeof(uint)*(numThreads+1);
    reorderDataAndFindCellStartD<<< numBlocks, numThreads, smemSize>>>(
        cellStart,
        cellEnd,
        (float4 *) sortedPos,
        (float4 *) sortedVel,
		gridParticleHash,
		gridParticleIndex,
        (float4 *) oldPos,
        (float4 *) oldVel,
        numParticles);
    cutilCheckMsg("Kernel execution failed: reorderDataAndFindCellStartD");

#if USE_TEX
    cutilSafeCall(cudaUnbindTexture(oldPosTex));
    cutilSafeCall(cudaUnbindTexture(oldVelTex));
#endif
}

void collide(float* newVel,
             float* sortedPos,
             float* sortedVel,
             uint*  gridParticleIndex,
             uint*  cellStart,
             uint*  cellEnd,
             uint   numParticles,
             uint   numCells)
{
#if USE_TEX
    cutilSafeCall(cudaBindTexture(0, oldPosTex, sortedPos, numParticles*sizeof(float4)));
    cutilSafeCall(cudaBindTexture(0, oldVelTex, sortedVel, numParticles*sizeof(float4)));
    cutilSafeCall(cudaBindTexture(0, cellStartTex, cellStart, numCells*sizeof(uint)));
    cutilSafeCall(cudaBindTexture(0, cellEndTex, cellEnd, numCells*sizeof(uint)));    
#endif

    // thread per particle
    uint numThreads, numBlocks;
    computeGridSize(numParticles, 64, numBlocks, numThreads);

    // execute the kernel
    collideD<<< numBlocks, numThreads >>>((float4*)newVel,
                                          (float4*)sortedPos,
                                          (float4*)sortedVel,
                                          gridParticleIndex,
                                          cellStart,
                                          cellEnd,
                                          numParticles);

    // check if kernel invocation generated an error
    cutilCheckMsg("Kernel execution failed");

#if USE_TEX
    cutilSafeCall(cudaUnbindTexture(oldPosTex));
    cutilSafeCall(cudaUnbindTexture(oldVelTex));
    cutilSafeCall(cudaUnbindTexture(cellStartTex));
    cutilSafeCall(cudaUnbindTexture(cellEndTex));
#endif
}


void sortParticles(uint *dGridParticleHash, uint *dGridParticleIndex, uint numParticles)
{
    thrust::sort_by_key(thrust::device_ptr<uint>(dGridParticleHash),
                        thrust::device_ptr<uint>(dGridParticleHash + numParticles),
                        thrust::device_ptr<uint>(dGridParticleIndex));
}

}   // extern "C"
