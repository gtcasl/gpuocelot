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



#ifndef HISTOGRAM64_KERNEL_CUH
#define HISTOGRAM64_KERNEL_CUH



//Total number of possible data values
#define      BIN_COUNT 64
#define HISTOGRAM_SIZE (BIN_COUNT * sizeof(unsigned int))



////////////////////////////////////////////////////////////////////////////////
// GPU-specific definitions
////////////////////////////////////////////////////////////////////////////////
//Fast mul on G8x / G9x / G100
#define IMUL(a, b) __mul24(a, b)

//Threads block size for histogram64Kernel()
//Preferred to be a multiple of 64 (refer to the supplied whitepaper)
#define THREAD_N 192

//Total size of subhistograms per thread block in bytes
#define BLOCK_MEMORY (THREAD_N * BIN_COUNT)

//Maximum number of 4-byte words processed by single thread block
#define BLOCK_DATA (THREAD_N * 63)



////////////////////////////////////////////////////////////////////////////////
// If threadPos == threadIdx.x, there are always  4-way bank conflicts,
// since each group of 16 threads (half-warp) accesses different bytes,
// but only within 4 shared memory banks. Having shuffled bits of threadIdx.x 
// as in histogram64GPU(), each half-warp accesses different shared memory banks
// avoiding any bank conflicts at all.
// Refer to the supplied whitepaper for detailed explanations.
////////////////////////////////////////////////////////////////////////////////
__device__ inline void addData64(unsigned char *s_Hist, int threadPos, unsigned int data){
    s_Hist[threadPos + IMUL(data, THREAD_N)]++;
}

////////////////////////////////////////////////////////////////////////////////
// Main computation pass: compute gridDim.x partial histograms
////////////////////////////////////////////////////////////////////////////////
__global__ void histogram64Kernel(unsigned int *d_Result, unsigned int *d_Data, int dataN){
    //Global base index in input data for current block
    const int  baseIndex = IMUL(blockIdx.x, BLOCK_DATA);
    //Current block size, clamp by array border
    const int   dataSize = min(dataN - baseIndex, BLOCK_DATA);
    //Encode thread index in order to avoid bank conflicts in s_Hist[] access:
    //each half-warp accesses consecutive shared memory banks
    //and the same bytes within the banks
    const int threadPos = 
        //[31 : 6] <== [31 : 6]
        ((threadIdx.x & (~63)) >> 0) |
        //[5  : 2] <== [3  : 0]
        ((threadIdx.x &    15) << 2) |
        //[1  : 0] <== [5  : 4]
        ((threadIdx.x &    48) >> 4);

    //Per-thread histogram storage
    __shared__ unsigned char s_Hist[BLOCK_MEMORY];

    //Don't forget to clear shared memory before utilization
    //No need in per-byte access at this stage
    for(int pos = threadIdx.x; pos < (BLOCK_MEMORY / 4); pos += blockDim.x)
        ((unsigned int *)s_Hist)[pos] = 0;

    __syncthreads();
    ////////////////////////////////////////////////////////////////////////////
    // Cycle through current block, update per-thread histograms
    // Since only 64-bit histogram of 8-bit input data array is calculated,
    // only highest 6 bits of each 8-bit data element are extracted,
    // leaving out 2 lower bits.
    ////////////////////////////////////////////////////////////////////////////
    for(int pos = threadIdx.x; pos < dataSize; pos += THREAD_N){
        unsigned int data4 = d_Data[baseIndex + pos];
        addData64(s_Hist, threadPos, (data4 >>  2) & 0x3FU);
        addData64(s_Hist, threadPos, (data4 >> 10) & 0x3FU);
        addData64(s_Hist, threadPos, (data4 >> 18) & 0x3FU);
        addData64(s_Hist, threadPos, (data4 >> 26) & 0x3FU);
    }

    __syncthreads();
    ////////////////////////////////////////////////////////////////////////////
    // Merge per-thread histograms into per-block and write to global memory.
    // Start accumulation positions for half-warp each thread are shifted
    // in order to avoid bank conflicts. 
    // See supplied whitepaper for detailed explanations.
    ////////////////////////////////////////////////////////////////////////////
    if(threadIdx.x < BIN_COUNT){
        unsigned int sum = 0;
        const int value = threadIdx.x;

        const int valueBase = IMUL(value, THREAD_N);
        const int  startPos = (threadIdx.x & 15) * 4;

        //Threads with non-zero start positions wrap around the THREAD_N border
        for(int i = 0, accumPos = startPos; i < THREAD_N; i++){
            sum += s_Hist[valueBase + accumPos];
            if(++accumPos == THREAD_N) accumPos = 0;
        }

        #ifndef CUDA_NO_SM_11_ATOMIC_INTRINSICS
            atomicAdd(d_Result + value, sum);
        #else
            d_Result[blockIdx.x * BIN_COUNT + value] = sum;
        #endif
    }
}



////////////////////////////////////////////////////////////////////////////////
// Merge blockN histograms into gridDim.x histograms
// blockDim.x == BIN_COUNT
// gridDim.x  == BLOCK_N2
////////////////////////////////////////////////////////////////////////////////
__global__ void mergeHistogram64Kernel(unsigned int *d_Result, int blockN){
    const int  globalTid = blockIdx.x * BIN_COUNT + threadIdx.x;
    const int numThreads = gridDim.x * BIN_COUNT;
    const int   dataSize = blockN * BIN_COUNT;

    unsigned int sum = 0;
    for(int pos = globalTid; pos < dataSize; pos += numThreads)
       sum += d_Result[pos];

    d_Result[globalTid] = sum;
}



////////////////////////////////////////////////////////////////////////////////
// CPU interface to GPU histogram calculator
////////////////////////////////////////////////////////////////////////////////
//histogram64Kernel() results buffer
unsigned int *d_Result64;
unsigned int *h_Result64;

//Maximum block count for histogram64kernel()
//Limits input data size to 756MB
const int MAX_BLOCK_N = 16384;

//Internal memory allocation
const int BLOCK_N2 = 32;

void initHistogram64GPU(void){
    #ifndef CUDA_NO_SM_11_ATOMIC_INTRINSICS
        cutilSafeCall( cudaMalloc((void **)&d_Result64, HISTOGRAM_SIZE) );
    #else
        h_Result64 = (unsigned int *)malloc(HISTOGRAM_SIZE * BLOCK_N2);
        cutilSafeCall( cudaMalloc((void **)&d_Result64, MAX_BLOCK_N * HISTOGRAM_SIZE) );
    #endif
}

//Internal memory deallocation
void closeHistogram64GPU(void){
    #ifndef CUDA_NO_SM_11_ATOMIC_INTRINSICS
        cutilSafeCall( cudaFree(d_Result64) );
    #else
        cutilSafeCall( cudaFree(d_Result64) );
        free(h_Result64);
    #endif
}

//Round a / b to nearest higher integer value
int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

void histogram64GPU(
    unsigned int *h_Result,
    unsigned int *d_Data,
    int dataN
){
    const int  blockN = iDivUp(dataN / 4, THREAD_N * 63);
    if(blockN > MAX_BLOCK_N){
        printf("histogram64GPU(): data size exceeds maximum\n");
        return;
    }

    #ifndef CUDA_NO_SM_11_ATOMIC_INTRINSICS
        cutilSafeCall( cudaMemset(d_Result64, 0, HISTOGRAM_SIZE) );
        histogram64Kernel<<<blockN, THREAD_N>>>(
            d_Result,
            (unsigned int *)d_Data,
            dataN / 4
        );
        cutilCheckMsg("histogram64Kernel() execution failed\n");
        cutilSafeCall( cudaMemcpy(h_Result, d_Result64, HISTOGRAM_SIZE, cudaMemcpyDeviceToHost) );

    #else
        histogram64Kernel<<<blockN, THREAD_N>>>(
            d_Result64,
            (unsigned int *)d_Data,
            dataN / 4
        );
        cutilCheckMsg("histogram64Kernel() execution failed\n");

        const int FINAL_BLOCK_N = min(BLOCK_N2, blockN);
        if(BLOCK_N2 < blockN){
            mergeHistogram64Kernel<<<BLOCK_N2, BIN_COUNT>>>(
                d_Result64,
                blockN
            );
            cutilCheckMsg("mergeHistogram64Kernel() execution failed\n");
        }

        cutilSafeCall( cudaMemcpy(h_Result64, d_Result64, FINAL_BLOCK_N * HISTOGRAM_SIZE, cudaMemcpyDeviceToHost) );
        for(int i = 1; i < FINAL_BLOCK_N; i++){
            for(int j = 0; j < BIN_COUNT; j++)
                h_Result64[j] += h_Result64[i * BIN_COUNT + j];
        }
        for(int i = 0; i < BIN_COUNT; i++)
            h_Result[i] = h_Result64[i];

    #endif
}



#endif
