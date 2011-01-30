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
        if(useDoublePrecision)
            MonteCarlo_SM13(plan);
        else
            MonteCarlo_SM10(plan);
    cutilSafeCall( cudaThreadSynchronize() );

    //Shut down this GPU
    if(useDoublePrecision)
        closeMonteCarlo_SM13(plan);
    else
        closeMonteCarlo_SM10(plan);
    cutilSafeCall( cudaFree(plan->d_Samples) );

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

    //Timer
    unsigned int hTimer;
    float time;

    double
        delta, ref, sumDelta, sumRef, sumReserve;

    cutilSafeCall( cudaGetDeviceCount(&GPU_N) );
    cutilCheckError( cutCreateTimer(&hTimer) );

#ifdef _EMU
	GPU_N = 1;
#endif
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

        //Start the timer
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );

        //Start CPU thread for each GPU
        for(gpuIndex = 0; gpuIndex < GPU_N; gpuIndex++)
            threadID[gpuIndex] = cutStartThread((CUT_THREADROUTINE)solverThread, &optionSolver[gpuIndex]);

        //Stop the timer
        cutilCheckError( cutStopTimer(hTimer) );
        time = cutGetTimerValue(hTimer);
        
    printf("main(): waiting for GPU results...\n");
        cutWaitForThreads(threadID, GPU_N);

    printf("main(): GPU statistics\n");
        for(i = 0; i < GPU_N; i++){
            printf("GPU #%i\n", optionSolver[i].device);
            printf("Options         : %i\n", optionSolver[i].optionCount);
            printf("Simulation paths: %i\n", optionSolver[i].pathN);
        }
        printf("\nTotal time (ms.): %f\n", time);
        printf("Options per sec.: %f\n", OPT_N / (time * 0.001));

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
    printf((sumReserve > 1.0f) ? "PASSED\n" : "FAILED.\n");

    printf("Shutting down...\n");

    cutilCheckError( cutDeleteTimer(hTimer) );
    cutilExit(argc, argv);
}
