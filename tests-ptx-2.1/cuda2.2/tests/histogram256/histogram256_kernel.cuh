/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  Users and possessors of this source code 
 * are hereby granted a nonexclusive, royalty-free license to use this code 
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.   This source code is a "commercial item" as 
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer  software"  and "commercial computer software 
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein. 
 *
 * Any use of this source code in individual and commercial software must 
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */



#ifndef HISTOGRAM256_KERNEL_CUH
#define HISTOGRAM256_KERNEL_CUH



#include <stdio.h>
#include <cutil_inline.h>
#include "histogram256_common.h"



////////////////////////////////////////////////////////////////////////////////
// GPU-specific definitions
////////////////////////////////////////////////////////////////////////////////
//Fast mul on G8x / G9x / G100
#define IMUL(a, b) __mul24(a, b)

//Machine warp size
//G80's warp size is 32 threads
//Emulation effectively executes threads in warps of 1 thread
#if 0
    #define WARP_LOG2SIZE 5
#else
    #define WARP_LOG2SIZE 0
#endif

//Warps in thread block for histogram256Kernel()
#define WARP_N 6

//Corresponding thread block size in threads for histogram256Kernel()
#define THREAD_N (WARP_N << WARP_LOG2SIZE)

//Total histogram size (in counters) per thread block for histogram256Kernel()
#define BLOCK_MEMORY (WARP_N * BIN_COUNT)

//Thread block count for histogram256Kernel()
#define BLOCK_N 64

//Throw out an error for unsupported compilation target
#if(defined(SMEM_ATOMICS) && defined(CUDA_NO_SM_12_ATOMIC_INTRINSICS)) || (defined(GMEM_ATOMICS) && defined(CUDA_NO_SM_11_ATOMIC_INTRINSICS))
    #error Source-level macros and SM target versions do not match
#endif



////////////////////////////////////////////////////////////////////////////////
// Shortcut shared memory atomic addition functions
////////////////////////////////////////////////////////////////////////////////
#ifdef SMEM_ATOMICS
    __device__ inline void addData256(unsigned int *s_WarpHist, unsigned int data, unsigned int){
        atomicAdd(s_WarpHist + data, 1);
    }
#else
    __device__ inline void addData256(volatile unsigned int *s_WarpHist, unsigned int data, unsigned int threadTag){
        unsigned int count;
        do{
            count = s_WarpHist[data] & 0x07FFFFFFU;
            count = threadTag | (count + 1);
            s_WarpHist[data] = count;
        }while(s_WarpHist[data] != count);
    }
#endif


////////////////////////////////////////////////////////////////////////////////
// Main histogram calculation kernel
////////////////////////////////////////////////////////////////////////////////
static __global__ void histogram256Kernel(unsigned int *d_Result, unsigned int *d_Data, int dataN){
    //Current global thread index
    const int    globalTid = IMUL(blockIdx.x, blockDim.x) + threadIdx.x;
    //Total number of threads in the compute grid
    const int   numThreads = IMUL(blockDim.x, gridDim.x);

    //Thread tag for addData256()
    //WARP_LOG2SIZE higher bits of counter values are tagged
    //by lower WARP_LOG2SIZE threadID bits
    #if 0
        const unsigned int threadTag = threadIdx.x << (32 - WARP_LOG2SIZE);
    #else
        const unsigned int threadTag = 0;
    #endif

    //Shared memory storage for each warp
    #ifdef SMEM_ATOMICS
        __shared__ unsigned int s_Hist[BLOCK_MEMORY];
    #else
        volatile __shared__ unsigned int s_Hist[BLOCK_MEMORY];
    #endif

    //Current warp shared memory base
    const int warpBase = (threadIdx.x >> WARP_LOG2SIZE) * BIN_COUNT;

    //Clear shared memory buffer for current thread block before processing
    for(int pos = threadIdx.x; pos < BLOCK_MEMORY; pos += blockDim.x)
       s_Hist[pos] = 0;

    //Cycle through the entire data set, update subhistograms for each warp
    __syncthreads();
    int iterations = dataN % numThreads == 0 ? dataN / numThreads : (dataN / numThreads) + 1;
    for(int index = 0, pos = globalTid; index < iterations; ++index ) {
		if(pos < dataN){
		    unsigned int data4 = d_Data[pos];

		    addData256(s_Hist + warpBase, (data4 >>  0) & 0xFFU, threadTag);
		    addData256(s_Hist + warpBase, (data4 >>  8) & 0xFFU, threadTag);
		    addData256(s_Hist + warpBase, (data4 >> 16) & 0xFFU, threadTag);
		    addData256(s_Hist + warpBase, (data4 >> 24) & 0xFFU, threadTag);
		    pos += numThreads;
        }
        __syncthreads();
    }

    __syncthreads();
    //Merge per-warp histograms into per-block and write to global memory
    for(int pos = threadIdx.x; pos < BIN_COUNT; pos += blockDim.x){
        unsigned int sum = 0;

        for(int base = 0; base < BLOCK_MEMORY; base += BIN_COUNT)
            sum += s_Hist[base + pos] & 0x07FFFFFFU;

        #ifdef GMEM_ATOMICS
            atomicAdd(d_Result + pos, sum);
        #else
            d_Result[blockIdx.x * BIN_COUNT + pos] = sum;
        #endif
    }
}


#ifndef GMEM_ATOMICS
    ///////////////////////////////////////////////////////////////////////////////
    // Merge BLOCK_N subhistograms of BIN_COUNT bins into final histogram
    ///////////////////////////////////////////////////////////////////////////////
    // gridDim.x   == BIN_COUNT
    // blockDim.x  == BLOCK_N
    // blockIdx.x  == bin counter processed by current block
    // threadIdx.x == subhistogram index
    static __global__ void mergeHistogram256Kernel(unsigned int *d_Result){
        __shared__ unsigned int data[BLOCK_N];

        //Reads are uncoalesced, but this final stage takes
        //only a fraction of total processing time
        data[threadIdx.x] = d_Result[threadIdx.x * BIN_COUNT + blockIdx.x];

        for(int stride = BLOCK_N / 2; stride > 0; stride >>= 1){
            __syncthreads();
            if(threadIdx.x < stride)
                data[threadIdx.x] += data[threadIdx.x + stride];
        }

        if(threadIdx.x == 0)
            d_Result[blockIdx.x] = data[0];
    }
#endif


////////////////////////////////////////////////////////////////////////////////
// Host interface to GPU histogram
////////////////////////////////////////////////////////////////////////////////
//histogram256kernel() results buffer
static unsigned int *d_Result256;

//Internal memory allocation
static void initHistogram256GPU(void){
    #ifdef GMEM_ATOMICS
        cutilSafeCall( cudaMalloc((void **)&d_Result256, HISTOGRAM_SIZE ) );
    #else
        cutilSafeCall( cudaMalloc((void **)&d_Result256, BLOCK_N * HISTOGRAM_SIZE) );
    #endif
}

//Internal memory deallocation
static void closeHistogram256GPU(void){
    cutilSafeCall( cudaFree(d_Result256) );
}

//histogram256 CPU front-end
static void histogram256GPU(unsigned int *h_Result, unsigned int *d_Data, int dataN){
    #ifdef GMEM_ATOMICS
        cutilSafeCall( cudaMemset(d_Result256, 0, HISTOGRAM_SIZE) );
        histogram256Kernel<<<BLOCK_N, THREAD_N>>>(d_Result256, d_Data, dataN / 4);
        cutilCheckMsg("histogram256Kernel() execution failed\n");
    #else
        histogram256Kernel<<<BLOCK_N, THREAD_N>>>(d_Result256, d_Data, dataN / 4);
        cutilCheckMsg("histogram256Kernel() execution failed\n");
        mergeHistogram256Kernel<<<BIN_COUNT, BLOCK_N>>>(d_Result256);
        cutilCheckMsg("mergeHistogram256Kernel() execution failed\n");
    #endif

    cutilSafeCall( cudaMemcpy(h_Result, d_Result256, HISTOGRAM_SIZE, cudaMemcpyDeviceToHost) );
}



#endif
