/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
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

/*
    Parallel reduction kernels
*/

#ifndef _REDUCE_KERNEL_H_
#define _REDUCE_KERNEL_H_

#include <stdio.h>
#include "sharedmem.cuh"


#if 1
#define EMUSYNC __syncthreads()
#else
#define EMUSYNC
#endif

// Macros to append an SM version identifier to a function name
// This allows us to compile a file multiple times for different architecture
// versions
// The second macro is necessary to evaluate the value of the SMVERSION macro
// rather than appending "SMVERSION" itself
#define FUNCVERSION(x, y) x ## _ ## y
#define XFUNCVERSION(x, y) FUNCVERSION(x, y)
#define FUNC(NAME) XFUNCVERSION(NAME, SMVERSION) 

/*
    Parallel sum reduction using shared memory
    - takes log(n) steps for n input elements
    - uses n threads
    - only works for power-of-2 arrays
*/

/* This reduction interleaves which threads are active by using the modulo
   operator.  This operator is very expensive on GPUs, and the interleaved 
   inactivity means that no whole warps are active, which is also very 
   inefficient */
template <class T>
__global__ void
FUNC(reduce0)(T *g_idata, T *g_odata, unsigned int n)
{
    SharedMemory<T> smem;
    T *sdata = smem.getPointer();

    // load shared mem
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x*blockDim.x + threadIdx.x;
    
    sdata[tid] = (i < n) ? g_idata[i] : 0;
    
    __syncthreads();

    // do reduction in shared mem
    for(unsigned int s=1; s < blockDim.x; s *= 2) {
        // modulo arithmetic is slow!
        if ((tid % (2*s)) == 0) {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

    // write result for this block to global mem
    if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}

/* This version uses contiguous threads, but its interleaved 
   addressing results in many shared memory bank conflicts. */
template <class T>
__global__ void
FUNC(reduce1)(T *g_idata, T *g_odata, unsigned int n)
{
    SharedMemory<T> smem;
    T *sdata = smem.getPointer();

    // load shared mem
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x*blockDim.x + threadIdx.x;
    
    sdata[tid] = (i < n) ? g_idata[i] : 0;
    
    __syncthreads();

    // do reduction in shared mem
    for(unsigned int s=1; s < blockDim.x; s *= 2) 
    {
        int index = 2 * s * tid;

        if (index < blockDim.x) 
        {
            sdata[index] += sdata[index + s];
        }
        __syncthreads();
    }

    // write result for this block to global mem
    if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}

/*
    This version uses sequential addressing -- no divergence or bank conflicts.
*/
template <class T>
__global__ void
FUNC(reduce2)(T *g_idata, T *g_odata, unsigned int n)
{
    SharedMemory<T> smem;
    T *sdata = smem.getPointer();

    // load shared mem
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x*blockDim.x + threadIdx.x;
    
    sdata[tid] = (i < n) ? g_idata[i] : 0;
    
    __syncthreads();

    // do reduction in shared mem
    for(unsigned int s=blockDim.x/2; s>0; s>>=1) 
    {
        if (tid < s) 
        {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

    // write result for this block to global mem
    if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}

/*
    This version uses n/2 threads --
    it performs the first level of reduction when reading from global memory
*/
template <class T>
__global__ void
FUNC(reduce3)(T *g_idata, T *g_odata, unsigned int n)
{
    SharedMemory<T> smem;
    T *sdata = smem.getPointer();

    // perform first level of reduction,
    // reading from global memory, writing to shared memory
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x*(blockDim.x*2) + threadIdx.x;

    sdata[tid] = (i < n) ? g_idata[i] : 0;
    if (i + blockDim.x < n) 
        sdata[tid] += g_idata[i+blockDim.x];  

    __syncthreads();

    // do reduction in shared mem
    for(unsigned int s=blockDim.x/2; s>0; s>>=1) 
    {
        if (tid < s) 
        {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

    // write result for this block to global mem 
    if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}

/*
    This version unrolls the last warp to avoid synchronization where it 
    isn't needed
*/
template <class T, unsigned int blockSize>
__global__ void
FUNC(reduce4)(T *g_idata, T *g_odata, unsigned int n)
{
    SharedMemory<T> smem;
    T *sdata = smem.getPointer();

    // perform first level of reduction,
    // reading from global memory, writing to shared memory
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x*(blockDim.x*2) + threadIdx.x;

    sdata[tid] = (i < n) ? g_idata[i] : 0;
    if (i + blockSize < n) 
        sdata[tid] += g_idata[i+blockSize];  

    __syncthreads();

    // do reduction in shared mem
    for(unsigned int s=blockDim.x/2; s>32; s>>=1) 
    {
        if (tid < s)
        {
            sdata[tid] += sdata[tid + s];
        }
        __syncthreads();
    }

	if (tid < 32) if (blockSize >=  64) { sdata[tid] += sdata[tid + 32]; } EMUSYNC;
	if (tid < 16) if (blockSize >=  32) { sdata[tid] += sdata[tid + 16]; } EMUSYNC;
	if (tid < 8) if (blockSize >=  16) { sdata[tid] += sdata[tid +  8]; } EMUSYNC;
	if (tid < 4) if (blockSize >=   8) { sdata[tid] += sdata[tid +  4]; } EMUSYNC;
	if (tid < 2) if (blockSize >=   4) { sdata[tid] += sdata[tid +  2]; } EMUSYNC;
	if (tid < 1) if (blockSize >=   2) { sdata[tid] += sdata[tid +  1]; } EMUSYNC;

    // write result for this block to global mem 
    if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}

/*
    This version is completely unrolled.  It uses a template parameter to achieve 
    optimal code for any (power of 2) number of threads.  This requires a switch 
    statement in the host code to handle all the different thread block sizes at 
    compile time.
*/
template <class T, unsigned int blockSize>
__global__ void
FUNC(reduce5)(T *g_idata, T *g_odata, unsigned int n)
{
    SharedMemory<T> smem;
    T *sdata = smem.getPointer();

    // perform first level of reduction,
    // reading from global memory, writing to shared memory
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x*(blockSize*2) + threadIdx.x;

    sdata[tid] = (i < n) ? g_idata[i] : 0;
    if (i + blockSize < n) 
        sdata[tid] += g_idata[i+blockSize];  

    __syncthreads();

    // do reduction in shared mem
    if (blockSize >= 512) { if (tid < 256) { sdata[tid] += sdata[tid + 256]; } __syncthreads(); }
    if (blockSize >= 256) { if (tid < 128) { sdata[tid] += sdata[tid + 128]; } __syncthreads(); }
    if (blockSize >= 128) { if (tid <  64) { sdata[tid] += sdata[tid +  64]; } __syncthreads(); }
    
	if (tid < 32) if (blockSize >=  64) { sdata[tid] += sdata[tid + 32]; } EMUSYNC;
	if (tid < 16) if (blockSize >=  32) { sdata[tid] += sdata[tid + 16]; } EMUSYNC;
	if (tid < 8) if (blockSize >=  16) { sdata[tid] += sdata[tid +  8]; } EMUSYNC;
	if (tid < 4) if (blockSize >=   8) { sdata[tid] += sdata[tid +  4]; } EMUSYNC;
	if (tid < 2) if (blockSize >=   4) { sdata[tid] += sdata[tid +  2]; } EMUSYNC;
	if (tid < 1) if (blockSize >=   2) { sdata[tid] += sdata[tid +  1]; } EMUSYNC;
    
    // write result for this block to global mem 
    if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}

/*
    This version adds multiple elements per thread sequentially.  This reduces the overall
    cost of the algorithm while keeping the work complexity O(n) and the step complexity O(log n).
    (Brent's Theorem optimization)
*/
template <class T, unsigned int blockSize, bool nIsPow2>
__global__ void
FUNC(reduce6)(T *g_idata, T *g_odata, unsigned int n)
{
    SharedMemory<T> smem;
    T *sdata = smem.getPointer();

    // perform first level of reduction,
    // reading from global memory, writing to shared memory
    unsigned int tid = threadIdx.x;
    unsigned int i = blockIdx.x*(blockSize*2) + threadIdx.x;
    unsigned int gridSize = blockSize*2*gridDim.x;
    sdata[tid] = 0;

    // we reduce multiple elements per thread.  The number is determined by the 
    // number of active thread blocks (via gridDim).  More blocks will result
    // in a larger gridSize and therefore fewer elements per thread
    while (i < n)
    {         
        sdata[tid] += g_idata[i];
        // ensure we don't read out of bounds -- this is optimized away for powerOf2 sized arrays
        if (nIsPow2 || i + blockSize < n) 
            sdata[tid] += g_idata[i+blockSize];  
        i += gridSize;
    } 
    __syncthreads();

    // do reduction in shared mem
    if (blockSize >= 512) { if (tid < 256) { sdata[tid] += sdata[tid + 256]; } __syncthreads(); }
    if (blockSize >= 256) { if (tid < 128) { sdata[tid] += sdata[tid + 128]; } __syncthreads(); }
    if (blockSize >= 128) { if (tid <  64) { sdata[tid] += sdata[tid +  64]; } __syncthreads(); }
    
	if (tid < 32) if (blockSize >=  64) { sdata[tid] += sdata[tid + 32]; } EMUSYNC;
	if (tid < 16) if (blockSize >=  32) { sdata[tid] += sdata[tid + 16]; } EMUSYNC;
	if (tid < 8) if (blockSize >=  16) { sdata[tid] += sdata[tid +  8]; } EMUSYNC;
	if (tid < 4) if (blockSize >=   8) { sdata[tid] += sdata[tid +  4]; } EMUSYNC;
	if (tid < 2) if (blockSize >=   4) { sdata[tid] += sdata[tid +  2]; } EMUSYNC;
	if (tid < 1) if (blockSize >=   2) { sdata[tid] += sdata[tid +  1]; } EMUSYNC;
        
    // write result for this block to global mem 
    if (tid == 0) g_odata[blockIdx.x] = sdata[0];
}


extern "C"
bool isPow2(unsigned int x);


////////////////////////////////////////////////////////////////////////////////
// Wrapper function for kernel launch
////////////////////////////////////////////////////////////////////////////////
template <class T>
void 
FUNC(reduce)(int size, int threads, int blocks, 
             int whichKernel, T *d_idata, T *d_odata)
{
    dim3 dimBlock(threads, 1, 1);
    dim3 dimGrid(blocks, 1, 1);
    int smemSize = 2 * threads * sizeof(T);

    // choose which of the optimized versions of reduction to launch
    switch (whichKernel)
    {
    case 0:
        FUNC(reduce0)<T><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size);
        break;
    case 1:
        FUNC(reduce1)<T><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size);
        break;
    case 2:
        FUNC(reduce2)<T><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size);
        break;
    case 3:
        FUNC(reduce3)<T><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size);
        break;
    case 4:
        switch (threads)
        {
        case 512:
            FUNC(reduce4)<T, 512><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 256:
            FUNC(reduce4)<T, 256><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 128:
            FUNC(reduce4)<T, 128><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 64:
            FUNC(reduce4)<T,  64><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 32:
            FUNC(reduce4)<T,  32><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 16:
            FUNC(reduce4)<T,  16><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  8:
            FUNC(reduce4)<T,   8><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  4:
            FUNC(reduce4)<T,   4><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  2:
            FUNC(reduce4)<T,   2><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  1:
            FUNC(reduce4)<T,   1><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        }
        break; 
    case 5:
        switch (threads)
        {
        case 512:
            FUNC(reduce5)<T, 512><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 256:
            FUNC(reduce5)<T, 256><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 128:
            FUNC(reduce5)<T, 128><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 64:
            FUNC(reduce5)<T,  64><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 32:
            FUNC(reduce5)<T,  32><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case 16:
            FUNC(reduce5)<T,  16><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  8:
            FUNC(reduce5)<T,   8><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  4:
            FUNC(reduce5)<T,   4><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  2:
            FUNC(reduce5)<T,   2><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        case  1:
            FUNC(reduce5)<T,   1><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
        }
        break;       
    case 6:
    default:
        if (isPow2(size))
        {
            switch (threads)
            {
            case 512:
                FUNC(reduce6)<T, 512, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 256:
                FUNC(reduce6)<T, 256, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 128:
                FUNC(reduce6)<T, 128, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 64:
                FUNC(reduce6)<T,  64, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 32:
                FUNC(reduce6)<T,  32, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 16:
                FUNC(reduce6)<T,  16, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  8:
                FUNC(reduce6)<T,   8, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  4:
                FUNC(reduce6)<T,   4, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  2:
                FUNC(reduce6)<T,   2, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  1:
                FUNC(reduce6)<T,   1, true><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            }
        }
        else
        {
            switch (threads)
            {
            case 512:
                FUNC(reduce6)<T, 512, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 256:
                FUNC(reduce6)<T, 256, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 128:
                FUNC(reduce6)<T, 128, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 64:
                FUNC(reduce6)<T,  64, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 32:
                FUNC(reduce6)<T,  32, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case 16:
                FUNC(reduce6)<T,  16, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  8:
                FUNC(reduce6)<T,   8, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  4:
                FUNC(reduce6)<T,   4, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  2:
                FUNC(reduce6)<T,   2, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            case  1:
                FUNC(reduce6)<T,   1, false><<< dimGrid, dimBlock, smemSize >>>(d_idata, d_odata, size); break;
            }
        }
        break;       
    }
}

extern "C"
void FUNC(reduceInt)(int size, int threads, int blocks, 
                     int whichKernel, int *d_idata, int *d_odata)
{
    FUNC(reduce)<int>(size, threads, blocks, whichKernel, d_idata, d_odata);
}

extern "C"
void FUNC(reduceFloat)(int size, int threads, int blocks, 
                       int whichKernel, float *d_idata, float *d_odata)
{
    FUNC(reduce)<float>(size, threads, blocks, whichKernel, d_idata, d_odata);
}

extern "C"
void FUNC(reduceDouble)(int size, int threads, int blocks, 
                        int whichKernel, double *d_idata, double *d_odata)
{
    FUNC(reduce)<double>(size, threads, blocks, whichKernel, d_idata, d_odata);
}

#endif // #ifndef _REDUCE_KERNEL_H_
