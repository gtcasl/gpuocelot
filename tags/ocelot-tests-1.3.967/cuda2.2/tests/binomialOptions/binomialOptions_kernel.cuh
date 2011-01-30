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



////////////////////////////////////////////////////////////////////////////////
// Global types and parameters
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <cutil_inline.h>
#include "realtype.h"
#include "binomialOptions_common.h"



////////////////////////////////////////////////////////////////////////////////
// Internal GPU-side constants and data structures
////////////////////////////////////////////////////////////////////////////////
#define  TIME_STEPS 16
#define CACHE_DELTA (2 * TIME_STEPS)
#define  CACHE_SIZE (256)
#define  CACHE_STEP (CACHE_SIZE - CACHE_DELTA)

#if NUM_STEPS % CACHE_DELTA
    #error Bad constants
#endif

//Preprocessed input option data
typedef struct{
    real S;
    real X;
    real vDt;
    real puByDf;
    real pdByDf;
} __TOptionData;
static __constant__ __TOptionData d_OptionData[MAX_OPTIONS];
static __device__           float d_CallValue[MAX_OPTIONS];
static __device__            real d_CallBuffer[MAX_OPTIONS * (NUM_STEPS + 16)];



////////////////////////////////////////////////////////////////////////////////
// Overloaded shortcut functions for different precision modes
////////////////////////////////////////////////////////////////////////////////
#ifndef DOUBLE_PRECISION
__device__ inline float expiryCallValue(float S, float X, float vDt, int i){
    real d = S * expf(vDt * (2.0f * i - NUM_STEPS)) - X;
    return (d > 0) ? d : 0;
}
#else
__device__ inline double expiryCallValue(double S, double X, double vDt, int i){
    double d = S * exp(vDt * (2.0 * i - NUM_STEPS)) - X;
    return (d > 0) ? d : 0;
}
#endif


////////////////////////////////////////////////////////////////////////////////
// GPU kernel
////////////////////////////////////////////////////////////////////////////////
static __global__ void binomialOptionsKernel(){
    __shared__ real callA[CACHE_SIZE];
    __shared__ real callB[CACHE_SIZE];
    //Global memory frame for current option (thread block)
    real *const d_Call = &d_CallBuffer[blockIdx.x * (NUM_STEPS + 16)];

    const int       tid = threadIdx.x;
    const real      S = d_OptionData[blockIdx.x].S;
    const real      X = d_OptionData[blockIdx.x].X;
    const real    vDt = d_OptionData[blockIdx.x].vDt;
    const real puByDf = d_OptionData[blockIdx.x].puByDf;
    const real pdByDf = d_OptionData[blockIdx.x].pdByDf;

    //Compute values at expiry date
    for(int i = tid; i <= NUM_STEPS; i += CACHE_SIZE)
        d_Call[i] = expiryCallValue(S, X, vDt, i);

    //Walk down binomial tree
    //So double-buffer and synchronize to avoid read-after-write hazards.
    for(int i = NUM_STEPS; i > 0; i -= CACHE_DELTA)
        for(int c_base = 0; c_base < i; c_base += CACHE_STEP){
            //Start and end positions within shared memory cache
            int c_start = min(CACHE_SIZE - 1, i - c_base);
            int c_end   = c_start - CACHE_DELTA;

            //Read data(with apron) to shared memory
            __syncthreads();
            if(tid <= c_start)
                callA[tid] = d_Call[c_base + tid];

            //Calculations within shared memory
            for(int k = c_start - 1; k >= c_end;){
                //Compute discounted expected value
                __syncthreads();
                if(tid <= k)
                    callB[tid] = puByDf * callA[tid + 1] + pdByDf * callA[tid];
                k--;

                //Compute discounted expected value
                __syncthreads();
                if(tid <= k)
                    callA[tid] = puByDf * callB[tid + 1] + pdByDf * callB[tid];
                k--;
            }

            //Flush shared memory cache
            __syncthreads();
            if(tid <= c_end)
                d_Call[c_base + tid] = callA[tid];
    }

    //Write the value at the top of the tree to destination buffer
    if(threadIdx.x == 0) d_CallValue[blockIdx.x] = (float)callA[0];
}



////////////////////////////////////////////////////////////////////////////////
// Host-side interface to GPU binomialOptions
////////////////////////////////////////////////////////////////////////////////
static void binomialOptionsGPU(
    float *callValue,
    TOptionData  *optionData,
    int optN
){
    __TOptionData h_OptionData[MAX_OPTIONS];

    for(int i = 0; i < optN; i++){
        const double      T = optionData[i].T;
        const double      R = optionData[i].R;
        const double      V = optionData[i].V;

        const double     dt = T / (double)NUM_STEPS;
        const double    vDt = V * sqrt(dt);
        const double    rDt = R * dt;
        //Per-step interest and discount factors
        const double     If = exp(rDt);
        const double     Df = exp(-rDt);
        //Values and pseudoprobabilities of upward and downward moves
        const double      u = exp(vDt);
        const double      d = exp(-vDt);
        const double     pu = (If - d) / (u - d);
        const double     pd = 1.0 - pu;
        const double puByDf = pu * Df;
        const double pdByDf = pd * Df;

        h_OptionData[i].S      = (real)optionData[i].S;
        h_OptionData[i].X      = (real)optionData[i].X;
        h_OptionData[i].vDt    = (real)vDt;
        h_OptionData[i].puByDf = (real)puByDf;
        h_OptionData[i].pdByDf = (real)pdByDf;
    }

    cutilSafeCall( cudaMemcpyToSymbol(d_OptionData, h_OptionData, optN * sizeof(__TOptionData)) );
    binomialOptionsKernel<<<optN, CACHE_SIZE>>>();
    cutilCheckMsg("binomialOptionsKernel() execution failed.\n");
    cutilSafeCall( cudaMemcpyFromSymbol(callValue, d_CallValue, optN * sizeof(float)) );
}
