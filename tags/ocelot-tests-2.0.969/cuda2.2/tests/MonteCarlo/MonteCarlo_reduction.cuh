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



#ifndef MONTECARLO_REDUCTION_CUH
#define MONTECARLO_REDUCTION_CUH



// Needed by the optimized sum reduction for correct execution in device emulation
#if 1
    #define EMUSYNC __syncthreads()
#else
    #define EMUSYNC
#endif

template<class T, unsigned int blockSize>
__device__ void sumReduceSharedMem(T *sum, T *sum2, int tid)
{
    // do reduction in shared mem
    if (blockSize >= 512) { if (tid < 256) { sum[tid] += sum[tid + 256]; sum2[tid] += sum2[tid + 256]; } __syncthreads(); }
    if (blockSize >= 256) { if (tid < 128) { sum[tid] += sum[tid + 128]; sum2[tid] += sum2[tid + 128]; } __syncthreads(); }
    if (blockSize >= 128) { if (tid <  64) { sum[tid] += sum[tid +  64]; sum2[tid] += sum2[tid +  64]; } __syncthreads(); }
    
    if (tid < 32) if (blockSize >=  64) { sum[tid] += sum[tid + 32]; sum2[tid] += sum2[tid + 32]; } EMUSYNC;
    if (tid < 16) if (blockSize >=  32) { sum[tid] += sum[tid + 16]; sum2[tid] += sum2[tid + 16]; } EMUSYNC;
    if (tid < 8) if (blockSize >=  16) { sum[tid] += sum[tid +  8]; sum2[tid] += sum2[tid +  8]; } EMUSYNC;
    if (tid < 4) if (blockSize >=   8) { sum[tid] += sum[tid +  4]; sum2[tid] += sum2[tid +  4]; } EMUSYNC;
    if (tid < 2) if (blockSize >=   4) { sum[tid] += sum[tid +  2]; sum2[tid] += sum2[tid +  2]; } EMUSYNC;
    if (tid < 1) if (blockSize >=   2) { sum[tid] += sum[tid +  1]; sum2[tid] += sum2[tid +  1]; } EMUSYNC;
}

////////////////////////////////////////////////////////////////////////////////
// This function calculates total sum for each of the two input arrays.
// SUM_N must be power of two
// Unrolling provides a bit of a performance improvement for small
// to medium path counts.
////////////////////////////////////////////////////////////////////////////////
#define UNROLL_REDUCTION

template<class T, int SUM_N, int blockSize> 
__device__ void sumReduce(T *sum, T *sum2)
{
#ifdef UNROLL_REDUCTION
    for(int pos = threadIdx.x; pos < SUM_N; pos += blockSize){
        __syncthreads();
        sumReduceSharedMem<T, blockSize>(sum, sum2, pos);
    }
#else
    for(int stride = SUM_N / 2; stride > 0; stride >>= 1){
        __syncthreads();
        for(int pos = threadIdx.x; pos < stride; pos += blockSize){
            sum[pos] += sum[pos + stride];
            sum2[pos] += sum2[pos + stride];
        }
    }
#endif
}



#endif
