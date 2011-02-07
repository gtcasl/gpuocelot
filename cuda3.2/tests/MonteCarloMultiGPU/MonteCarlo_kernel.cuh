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



#ifndef MONTECARLO_KERNEL_CUH
#define MONTECARLO_KERNEL_CUH



////////////////////////////////////////////////////////////////////////////////
// Global types
////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <cutil_inline.h>
#include "realtype.h"
#include "MonteCarlo_common.h"



////////////////////////////////////////////////////////////////////////////////
// Helper reduction template
// Please see the "reduction" CUDA SDK sample for more information
////////////////////////////////////////////////////////////////////////////////
#include "MonteCarlo_reduction.cuh"



////////////////////////////////////////////////////////////////////////////////
// Internal GPU-side data structures
////////////////////////////////////////////////////////////////////////////////
#define MAX_OPTIONS 2048

//Preprocessed input option data
typedef struct{
    real S;
    real X;
    real MuByT;
    real VBySqrtT;
} __TOptionData;
static __device__ __constant__ __TOptionData d_OptionData[MAX_OPTIONS];

//GPU outputs before CPU postprocessing
typedef struct{
    real Expected;
    real Confidence;
} __TOptionValue;
static __device__ __TOptionValue d_CallValue[MAX_OPTIONS];



////////////////////////////////////////////////////////////////////////////////
// Overloaded shortcut payoff functions for different precision modes
////////////////////////////////////////////////////////////////////////////////
#ifndef DOUBLE_PRECISION
__device__ inline float endCallValue(float S, float X, float r, float MuByT, float VBySqrtT){
    float callValue = S * __expf(MuByT + VBySqrtT * r) - X;
    return (callValue > 0) ? callValue : 0;
}
#else
__device__ inline double endCallValue(double S, double X, double r, double MuByT, double VBySqrtT){
    double callValue = S * exp(MuByT + VBySqrtT * r) - X;
    return (callValue > 0) ? callValue : 0;
}
#endif


////////////////////////////////////////////////////////////////////////////////
// This kernel computes partial integrals over all paths using a multiple thread
// blocks per option. It is used when a single thread block per option would not
// be enough to keep the GPU busy. Execution of this kernel is followed by
// MonteCarloReduce() to get the complete integral for each option.
////////////////////////////////////////////////////////////////////////////////
#define THREAD_N 256

static __global__ void MonteCarloKernel(
    __TOptionValue *d_Buffer,
    float *d_Samples,
    int pathN
){
    const int optionIndex = blockIdx.y;

    const real        S = d_OptionData[optionIndex].S;
    const real        X = d_OptionData[optionIndex].X;
    const real    MuByT = d_OptionData[optionIndex].MuByT;
    const real VBySqrtT = d_OptionData[optionIndex].VBySqrtT;

    //One thread per partial integral
    const int   iSum = blockIdx.x * blockDim.x + threadIdx.x;
    const int accumN = blockDim.x * gridDim.x;

    //Cycle through the entire samples array:
    //derive end stock price for each path
    //accumulate into intermediate global memory array
    __TOptionValue sumCall = {0, 0};
    for(int i = iSum; i < pathN; i += accumN){
        real              r = d_Samples[i];
        real      callValue = endCallValue(S, X, r, MuByT, VBySqrtT);
        sumCall.Expected   += callValue;
        sumCall.Confidence += callValue * callValue;
    }
    d_Buffer[optionIndex * accumN + iSum] = sumCall;
}



////////////////////////////////////////////////////////////////////////////////
// This kernel computes the integral over all paths using a single thread block
// per option. It is fastest when the number of thread blocks times the work per
// block is high enough to keep the GPU busy. When this is not the case, using
// more blocks per option is faster, so we use MonteCarloKernel() plus
// MonteCarloReduce() instead.
////////////////////////////////////////////////////////////////////////////////
static __global__ void MonteCarloOneBlockPerOption(
    float *d_Samples,
    int pathN
){
    const int SUM_N = THREAD_N;
    __shared__ real s_SumCall[SUM_N];
    __shared__ real s_Sum2Call[SUM_N];

    const int optionIndex = blockIdx.x;
    const real        S = d_OptionData[optionIndex].S;
    const real        X = d_OptionData[optionIndex].X;
    const real    MuByT = d_OptionData[optionIndex].MuByT;
    const real VBySqrtT = d_OptionData[optionIndex].VBySqrtT;

    //Cycle through the entire samples array:
    //derive end stock price for each path
    //accumulate partial integrals into intermediate shared memory buffer
    for(int iSum = threadIdx.x; iSum < SUM_N; iSum += blockDim.x){
        __TOptionValue sumCall = {0, 0};
        for(int i = iSum; i < pathN; i += SUM_N){
            real              r = d_Samples[i];
            real      callValue = endCallValue(S, X, r, MuByT, VBySqrtT);
            sumCall.Expected   += callValue;
            sumCall.Confidence += callValue * callValue;
        }
        s_SumCall[iSum]  = sumCall.Expected;
        s_Sum2Call[iSum] = sumCall.Confidence;
    }

    //Reduce shared memory accumulators
    //and write final result to global memory
    sumReduce<real, SUM_N, THREAD_N>(s_SumCall, s_Sum2Call);
    if(threadIdx.x == 0){
        __TOptionValue t = {s_SumCall[0], s_Sum2Call[0]};
        d_CallValue[optionIndex] = t;
    }
}



////////////////////////////////////////////////////////////////////////////////
//Finalizing reduction for MonteCarloKernel1()
//Final reduction for each per-option accumulator output
////////////////////////////////////////////////////////////////////////////////
static __global__ void MonteCarloReduce(
    __TOptionValue *d_Buffer,
    int accumN
){
    const int SUM_N = THREAD_N;
    __shared__ real s_SumCall[SUM_N];
    __shared__ real s_Sum2Call[SUM_N];
    __TOptionValue *d_SumBase = &d_Buffer[blockIdx.x * accumN];

    //Reduce global memory accumulators array for current option
    //to a set fitting into shared memory
    for(int iSum = threadIdx.x; iSum < SUM_N; iSum += blockDim.x){
        __TOptionValue sumCall = {0, 0};
        for(int pos = iSum; pos < accumN; pos += SUM_N){
            __TOptionValue    t = d_SumBase[pos];
            sumCall.Expected   += t.Expected;
            sumCall.Confidence += t.Confidence;
        }
        s_SumCall[iSum]  = sumCall.Expected;
        s_Sum2Call[iSum] = sumCall.Confidence;
    }

    //Reduce shared memory accumulators
    //and write final result to global memory
    sumReduce<real, SUM_N, THREAD_N>(s_SumCall, s_Sum2Call);
    if(threadIdx.x == 0){
        __TOptionValue t = {s_SumCall[0], s_Sum2Call[0]};
        d_CallValue[blockIdx.x] = t;
    }
}



////////////////////////////////////////////////////////////////////////////////
// Host-side interface to GPU Monte Carlo
////////////////////////////////////////////////////////////////////////////////
//Allocate internal device memory
static void initMonteCarloGPU(TOptionPlan *plan){
    const int doMultiBlock = (plan->pathN / plan->optionCount) >= 8192;
    if(doMultiBlock){
        const int blocksPerOption = (plan->optionCount < 16) ? 64 : 16;
        const int          accumN = THREAD_N * blocksPerOption;
        cutilSafeCall( cudaMalloc(
            (void **)&plan->d_Buffer,
            accumN * plan->optionCount * sizeof(__TOptionValue)
        ) );
    }
}

//Deallocate internal device memory
static void closeMonteCarloGPU(TOptionPlan *plan){
    const int doMultiBlock = (plan->pathN / plan->optionCount) >= 8192;
    if(doMultiBlock) cutilSafeCall( cudaFree(plan->d_Buffer) );
}

//Main computations
static void MonteCarloGPU(TOptionPlan *plan){
    __TOptionData h_OptionData[MAX_OPTIONS];
    __TOptionValue h_CallValue[MAX_OPTIONS];

    if(plan->optionCount <= 0 || plan->optionCount > MAX_OPTIONS){
        printf("MonteCarloGPU(): bad option count.\n");
        return;
    }

    for(int i = 0; i < plan->optionCount; i++){
        const double           T = plan->optionData[i].T;
        const double           R = plan->optionData[i].R;
        const double           V = plan->optionData[i].V;
        const double       MuByT = (R - 0.5 * V * V) * T;
        const double    VBySqrtT = V * sqrt(T);
        h_OptionData[i].S        = (real)plan->optionData[i].S;
        h_OptionData[i].X        = (real)plan->optionData[i].X;
        h_OptionData[i].MuByT    = (real)MuByT;
        h_OptionData[i].VBySqrtT = (real)VBySqrtT;
    }

    cutilSafeCall( cudaMemcpyToSymbol(
        d_OptionData,
        h_OptionData,
        plan->optionCount * sizeof(__TOptionData)
    ) );

    const int doMultiBlock = (plan->pathN / plan->optionCount) >= 8192;
    if(doMultiBlock){
        const int blocksPerOption = (plan->optionCount < 16) ? 64 : 16;
        const int          accumN = THREAD_N * blocksPerOption;
        const dim3 gridMain(blocksPerOption, plan->optionCount);
        MonteCarloKernel<<<gridMain, THREAD_N>>>(
            (__TOptionValue *)plan->d_Buffer,
            plan->d_Samples,
            plan->pathN
        );
        cutilCheckMsg("MonteCarloKernel() execution failed\n");
        MonteCarloReduce<<<plan->optionCount, THREAD_N>>>(
            (__TOptionValue *)plan->d_Buffer,
            accumN
        );
        cutilCheckMsg("MonteCarloReduce() execution failed\n");
    }else{
        MonteCarloOneBlockPerOption<<<plan->optionCount, THREAD_N>>>(
            plan->d_Samples,
            plan->pathN
        );
        cutilCheckMsg("MonteCarloOneBlockPerOption() execution failed\n");
    }
    cutilSafeCall( cudaMemcpyFromSymbol(
        h_CallValue,
        d_CallValue,
        plan->optionCount * sizeof(__TOptionValue)
    ) );

    for(int i = 0; i < plan->optionCount; i++){
        const double    RT = plan->optionData[i].R * plan->optionData[i].T;
        const double   sum = h_CallValue[i].Expected;
        const double  sum2 = h_CallValue[i].Confidence;
        const double pathN = plan->pathN;
        //Derive average from the total sum and discount by riskfree rate 
        plan->callValue[i].Expected = (float)(exp(-RT) * sum / pathN);
        //Standart deviation
        double stdDev = sqrt((pathN * sum2 - sum * sum)/ (pathN * (pathN - 1)));
        //Confidence width; in 95% of all cases theoretical value lies within these borders
        plan->callValue[i].Confidence = (float)(exp(-RT) * 1.96 * stdDev / sqrt(pathN));
    }
}



#endif
