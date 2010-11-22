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

/*
 * This sample evaluates fair call price for a
 * given set of European options using Monte Carlo approach.
 * See supplied whitepaper for more explanations.
 */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <multithreading.h>
#include "MonteCarlo_common.h"


#ifdef WIN32
#define strcasecmp strcmpi
#endif



////////////////////////////////////////////////////////////////////////////////
// Common functions
////////////////////////////////////////////////////////////////////////////////
float randFloat(float low, float high){
    float t = (float)rand() / (float)RAND_MAX;
    return (1.0f - t) * low + t * high;
}



///////////////////////////////////////////////////////////////////////////////
// CPU reference functions
///////////////////////////////////////////////////////////////////////////////
extern "C" void MonteCarloCPU(
    TOptionValue&   callValue,
    TOptionData optionData,
    float *h_Random,
    int pathN
);

//Black-Scholes formula for call options
extern "C" void BlackScholesCall(
    float& CallResult,
    TOptionData optionData
);

extern "C" double NormalDistribution(unsigned int i, unsigned int pathN);
extern "C" double MoroInvCND(double prob);



////////////////////////////////////////////////////////////////////////////////
// GPU kernel code
////////////////////////////////////////////////////////////////////////////////
extern "C" void initMonteCarlo_SM10(TOptionPlan *plan);
extern "C" void closeMonteCarlo_SM10(TOptionPlan *plan);
extern "C" void MonteCarlo_SM10(TOptionPlan *plan);
extern "C" void inverseCND_SM10(float *d_Output, float *d_Input, unsigned int N);
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void MonteCarlo_SM13(TOptionPlan *plan);
extern "C" void inverseCND_SM13(float *d_Output, float *d_Input, unsigned int N);



////////////////////////////////////////////////////////////////////////////////
// GPU-driving host thread
////////////////////////////////////////////////////////////////////////////////
unsigned int useDoublePrecision;

static CUT_THREADPROC solverThread(TOptionPlan *plan){
    unsigned int hTimer;
    cutilCheckError( cutCreateTimer(&hTimer) );

    //Init GPU
    cutilSafeCall( cudaSetDevice(plan->device) );

    cudaDeviceProp deviceProp;
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, plan->device));
    int version = deviceProp.major * 10 + deviceProp.minor;
    if(useDoublePrecision && version < 13){
        printf("Double precision is not supported on device %i.\n", plan->device);
        exit(0);
    }

    //Allocate memory for normally distributed samples
    cutilSafeCall( cudaMalloc(
        (void **)&plan->d_Samples,
        plan->pathN * sizeof(float)
    ) );

    //Generate normally distributed samples
    if(useDoublePrecision)
        inverseCND_SM13(plan->d_Samples, NULL, plan->pathN);
    else
        inverseCND_SM10(plan->d_Samples, NULL, plan->pathN);

    //Allocate intermediate memory for MC integrator
    if(useDoublePrecision)
        initMonteCarlo_SM13(plan);
    else
        initMonteCarlo_SM10(plan);

    //Main computations
    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutResetTimer(hTimer) );
    cutilCheckError( cutStartTimer(hTimer) );
        if(useDoublePrecision)
            MonteCarlo_SM13(plan);
        else
            MonteCarlo_SM10(plan);
    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStopTimer(hTimer) );
    plan->time = cutGetTimerValue(hTimer);

    //Shut down this GPU
    if(useDoublePrecision)
        closeMonteCarlo_SM13(plan);
    else
        closeMonteCarlo_SM10(plan);
    cutilSafeCall( cudaFree(plan->d_Samples) );
    cutilCheckError( cutDeleteTimer(hTimer) );

    cudaThreadExit();

    CUT_THREADEND;
}



///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
#define DO_CPU
#undef DO_CPU

#define PRINT_RESULTS
#undef PRINT_RESULTS



int main(int argc, char **argv){
    char *precisionChoice;
    cutGetCmdLineArgumentstr(argc, (const char **)argv, "type", &precisionChoice);
    if(precisionChoice == NULL)
        useDoublePrecision = 0;
    else{
        if(!strcasecmp(precisionChoice, "double"))
            useDoublePrecision = 1;
        else
            useDoublePrecision = 0;
    }

    const int MAX_GPU_COUNT = 8;
    const int         OPT_N = 256;
    const int        PATH_N = 1 << 18;
    const unsigned int SEED = 777;

    //Input data array
    TOptionData optionData[OPT_N];
    //Final GPU MC results
    TOptionValue callValueGPU[OPT_N];
    //"Theoretical" call values by Black-Scholes formula
    float callValueBS[OPT_N];
    //Solver config
    TOptionPlan optionSolver[MAX_GPU_COUNT];
    //OS thread ID
    CUTThread threadID[MAX_GPU_COUNT];


    //GPU number present in the system
    int GPU_N;
    int gpuBase, gpuIndex;
    int i;

    double
        delta, ref, sumDelta, sumRef, sumReserve;

    cutilSafeCall( cudaGetDeviceCount(&GPU_N) );

    printf("main(): generating input data...\n");
        srand(123);
        for(i = 0; i < OPT_N; i++){
            optionData[i].S = randFloat(5.0f, 50.0f);
            optionData[i].X = randFloat(10.0f, 25.0f);
            optionData[i].T = randFloat(1.0f, 5.0f);
            optionData[i].R = 0.06f;
            optionData[i].V = 0.10f;
            callValueGPU[i].Expected   = -1.0f;
            callValueGPU[i].Confidence = -1.0f;
        }

    printf("main(): starting %i host threads...\n", GPU_N);
        //Get option count for each GPU
        for(i = 0; i < GPU_N; i++)
            optionSolver[i].optionCount = OPT_N / GPU_N;
        //Take into account cases with "odd" option counts
        for(i = 0; i < (OPT_N % GPU_N); i++)
            optionSolver[i].optionCount++;

        //Assign GPU option ranges
        gpuBase = 0;
        for(i = 0; i < GPU_N; i++){
            optionSolver[i].device     = i;
            optionSolver[i].optionData = optionData   + gpuBase;
            optionSolver[i].callValue  = callValueGPU + gpuBase;
            optionSolver[i].seed       = SEED;
            optionSolver[i].pathN      = PATH_N;
            gpuBase += optionSolver[i].optionCount;
        }

        //Start CPU thread for each GPU
        for(gpuIndex = 0; gpuIndex < GPU_N; gpuIndex++)
            threadID[gpuIndex] = cutStartThread((CUT_THREADROUTINE)solverThread, &optionSolver[gpuIndex]);

    printf("main(): waiting for GPU results...\n");
        cutWaitForThreads(threadID, GPU_N);

    printf("main(): GPU statistics\n");
        for(i = 0; i < GPU_N; i++){
            printf("GPU #%i\n", optionSolver[i].device);
            printf("Options         : %i\n", optionSolver[i].optionCount);
            printf("Simulation paths: %i\n", optionSolver[i].pathN);
            printf("Time (ms.)      : %f\n", optionSolver[i].time);
            printf("Options per sec.: %f\n", optionSolver[i].optionCount / (optionSolver[i].time * 0.001));
        }


#ifdef DO_CPU
    printf("main(): running CPU MonteCarlo...\n");
        TOptionValue callValueCPU;
        sumDelta = 0;
        sumRef   = 0;
        for(i = 0; i < OPT_N; i++){
            MonteCarloCPU(
                callValueCPU,
                optionData[i],
                NULL,
                PATH_N
            );
            delta     = fabs(callValueCPU.Expected - callValueGPU[i].Expected);
            ref       = callValueCPU.Expected;
            sumDelta += delta;
            sumRef   += fabs(ref);
            printf("Exp : %f | %f\t", callValueCPU.Expected,   callValueGPU[i].Expected);
            printf("Conf: %f | %f\n", callValueCPU.Confidence, callValueGPU[i].Confidence);
        }
    printf("L1 norm: %E\n", sumDelta / sumRef);
#endif

    printf("main(): comparing Monte Carlo and Black-Scholes results...\n");
        sumDelta   = 0;
        sumRef     = 0;
        sumReserve = 0;
        for(i = 0; i < OPT_N; i++){
            BlackScholesCall(
                callValueBS[i],
                optionData[i]
            );
            delta     = fabs(callValueBS[i] - callValueGPU[i].Expected);
            ref       = callValueBS[i];
            sumDelta += delta;
            sumRef   += fabs(ref);
            if(delta > 1e-6) sumReserve += callValueGPU[i].Confidence / delta;
#ifdef PRINT_RESULTS
            printf("BS: %f; delta: %E\n", callValueBS[i], delta);
#endif
        }
    sumReserve /= OPT_N;
    printf("L1 norm        : %E\n", sumDelta / sumRef);
    printf("Average reserve: %f\n", sumReserve);
    printf((sumReserve > 1.0f) ? "TEST PASSED\n" : "TEST FAILED.\n");

    printf("Shutting down...\n");

    cutilExit(argc, argv);
}
