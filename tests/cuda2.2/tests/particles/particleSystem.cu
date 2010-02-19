/*
 * Copyright 1993-2006 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.   
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.  This source code is a "commercial item" as 
 * that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer software" and "commercial computer software 
 * documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein.
 */

// This file contains C wrappers around the some of the CUDA API and the
// kernel functions so that they can be called from "particleSystem.cpp"

#include <cutil_inline.h>
#include <cstdlib>
#include <cstdio>
#include <string.h>

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <cuda_gl_interop.h>

#include "particles_kernel.cu"
#include "radixsort.cu"

extern "C"
{

void cudaInit(int argc, char **argv)
{   
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );
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
    cutilSafeCall(cudaThreadSynchronize());
}

void copyArrayFromDevice(void* host, const void* device, unsigned int vbo, int size)
{   
    if (vbo)
        cutilSafeCall(cudaGLMapBufferObject((void**)&device, vbo));

    cutilSafeCall(cudaMemcpy(host, device, size, cudaMemcpyDeviceToHost));
    
    if (vbo)
        cutilSafeCall(cudaGLUnmapBufferObject(vbo));
}

void copyArrayToDevice(void* device, const void* host, int offset, int size)
{
    cutilSafeCall(cudaMemcpy((char *) device + offset, host, size, cudaMemcpyHostToDevice));
}

void registerGLBufferObject(uint vbo)
{
    cutilSafeCall(cudaGLRegisterBufferObject(vbo));
}

void unregisterGLBufferObject(uint vbo)
{
    cutilSafeCall(cudaGLUnregisterBufferObject(vbo));
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

void 
integrateSystem(uint vboOldPos, uint vboNewPos, 
                float* oldVel, float* newVel, 
                float deltaTime,
                int numParticles)
{
    int numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

    float *oldPos, *newPos;
    cutilSafeCall(cudaGLMapBufferObject((void**)&oldPos, vboOldPos));
    cutilSafeCall(cudaGLMapBufferObject((void**)&newPos, vboNewPos));

    // execute the kernel
    integrate<<< numBlocks, numThreads >>>((float4*)newPos, (float4*)newVel,
                                           (float4*)oldPos, (float4*)oldVel,
                                           deltaTime);
    
    // check if kernel invocation generated an error
    cutilCheckMsg("integrate kernel execution failed");

    cutilSafeCall(cudaGLUnmapBufferObject(vboOldPos));
    cutilSafeCall(cudaGLUnmapBufferObject(vboNewPos));
}

void 
updateGrid(uint    vboPos, 
           uint*   gridCounters,
           uint*   gridCells,
           uint    numParticles,
           uint    numCells)
{
    int numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

    float *pos;
    cutilSafeCall(cudaGLMapBufferObject((void**)&pos, vboPos));

    cutilSafeCall(cudaMemset(gridCounters, 0, numCells*sizeof(uint)));

    // execute the kernel
    updateGridD<<< numBlocks, numThreads >>>((float4 *) pos,
                                             gridCounters,
                                             gridCells);
    
    // check if kernel invocation generated an error
    cutilCheckMsg("Kernel execution failed");

    cutilSafeCall(cudaGLUnmapBufferObject(vboPos));
}


void 
calcHash(uint    vboPos, 
         uint*   particleHash,
         int     numParticles)
{
    int numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

    float *pos;
    cutilSafeCall(cudaGLMapBufferObject((void**)&pos, vboPos));

    // execute the kernel
    calcHashD<<< numBlocks, numThreads >>>((float4 *) pos,
                                           (uint2 *) particleHash);
    
    // check if kernel invocation generated an error
    cutilCheckMsg("Kernel execution failed");

    cutilSafeCall(cudaGLUnmapBufferObject(vboPos));
}

void 
reorderDataAndFindCellStart(uint*  particleHash,
							uint   vboOldPos,
							float* oldVel,
							float* sortedPos,
							float* sortedVel,
							uint*  cellStart,
							uint   numParticles,
							uint   numCells)
{
    int numThreads, numBlocks;
    computeGridSize(numParticles, 256, numBlocks, numThreads);

	cutilSafeCall(cudaMemset(cellStart, 0xffffffff, numCells*sizeof(uint)));

    float *oldPos;
    cutilSafeCall(cudaGLMapBufferObject((void**)&oldPos, vboOldPos));

#if USE_TEX
    cutilSafeCall(cudaBindTexture(0, oldPosTex, oldPos, numParticles*sizeof(float4)));
    cutilSafeCall(cudaBindTexture(0, oldVelTex, oldVel, numParticles*sizeof(float4)));
#endif

    reorderDataAndFindCellStartD<<< numBlocks, numThreads >>>(
		(uint2 *)  particleHash,
        (float4 *) oldPos,
        (float4 *) oldVel,
        (float4 *) sortedPos,
        (float4 *) sortedVel,
        (uint *)   cellStart);
    cutilCheckMsg("Kernel execution failed: reorderDataAndFindCellStartD");

#if USE_TEX
    cutilSafeCall(cudaUnbindTexture(oldPosTex));
    cutilSafeCall(cudaUnbindTexture(oldVelTex));
#endif

    cutilSafeCall(cudaGLUnmapBufferObject(vboOldPos));
}

void
collide(uint   vboOldPos, uint vboNewPos,
        float* sortedPos, float* sortedVel,
        float* oldVel, float* newVel,
        uint*  gridCounters,
        uint*  gridCells,
        uint*  particleHash,
        uint*  cellStart,
        uint   numParticles,
        uint   numCells,
        uint   maxParticlesPerCell)
{
    float4 *oldPos, *newPos;
    cutilSafeCall(cudaGLMapBufferObject((void**)&oldPos, vboOldPos));
    cutilSafeCall(cudaGLMapBufferObject((void**)&newPos, vboNewPos));

#if USE_TEX

#if USE_SORT
    // use sorted arrays
    cutilSafeCall(cudaBindTexture(0, oldPosTex, sortedPos, numParticles*sizeof(float4)));
    cutilSafeCall(cudaBindTexture(0, oldVelTex, sortedVel, numParticles*sizeof(float4)));

    cutilSafeCall(cudaBindTexture(0, particleHashTex, particleHash, numParticles*sizeof(uint2)));
    cutilSafeCall(cudaBindTexture(0, cellStartTex, cellStart, numCells*sizeof(uint)));
#else

    cutilSafeCall(cudaBindTexture(0, oldPosTex, oldPos, numParticles*sizeof(float4)));
    cutilSafeCall(cudaBindTexture(0, oldVelTex, oldVel, numParticles*sizeof(float4)));

    cutilSafeCall(cudaBindTexture(0, gridCountersTex, gridCounters,numCells*sizeof(uint)));
    cutilSafeCall(cudaBindTexture(0, gridCellsTex, gridCells, numCells*maxParticlesPerCell*sizeof(uint)));
#endif

#endif

    // thread per particle
    int numThreads, numBlocks;
    computeGridSize(numParticles, BLOCKDIM, numBlocks, numThreads);

    // execute the kernel
    collideD<<< numBlocks, numThreads >>>((float4*)newPos, (float4*)newVel,
#if USE_SORT
                                          (float4*)sortedPos, (float4*)sortedVel,
                                          (uint2 *) particleHash,
                                          cellStart
#else
                                          (float4*)oldPos, (float4*)oldVel,
                                          gridCounters,
                                          gridCells
#endif
                                          );

    // check if kernel invocation generated an error
    cutilCheckMsg("Kernel execution failed");

    cutilSafeCall(cudaGLUnmapBufferObject(vboNewPos));
    cutilSafeCall(cudaGLUnmapBufferObject(vboOldPos));

#if USE_TEX
    cutilSafeCall(cudaUnbindTexture(oldPosTex));
    cutilSafeCall(cudaUnbindTexture(oldVelTex));

#if USE_SORT
    cutilSafeCall(cudaUnbindTexture(particleHashTex));
    cutilSafeCall(cudaUnbindTexture(cellStartTex));
#else
    cutilSafeCall(cudaUnbindTexture(gridCountersTex));
    cutilSafeCall(cudaUnbindTexture(gridCellsTex));
#endif
#endif
}

}   // extern "C"
