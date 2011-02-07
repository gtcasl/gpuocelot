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
    __shared__ real callA[CACHE_SIZE+1];
    __shared__ real callB[CACHE_SIZE+1];
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
                callB[tid] = puByDf * callA[tid + 1] + pdByDf * callA[tid];
                k--;

                //Compute discounted expected value
                __syncthreads();
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
