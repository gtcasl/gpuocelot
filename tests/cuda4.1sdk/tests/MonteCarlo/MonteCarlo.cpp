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
#include <shrQATest.h>
#include <string.h>
#include "MonteCarlo_common.h"

static char *sSDKsample = "Monte Carlo European Options pricing"; 

#ifdef WIN32
#define strcasecmp _strcmpi
#endif


////////////////////////////////////////////////////////////////////////////////
// Common host and device functions
////////////////////////////////////////////////////////////////////////////////
float randFloat(float low, float high){
    float t = (float)rand() / (float)RAND_MAX;
    return (1.0f - t) * low + t * high;
}



///////////////////////////////////////////////////////////////////////////////
// CPU gold function prototype
///////////////////////////////////////////////////////////////////////////////
extern "C" void MonteCarloCPU(
    TOptionValue&    callValue,
    TOptionData optionData,
    float *h_Samples,
    int pathN
);

extern "C" void BlackScholesCall(
    float& callValue,
    TOptionData optionData
);



///////////////////////////////////////////////////////////////////////////////
// GPU code
///////////////////////////////////////////////////////////////////////////////
extern "C" void initMonteCarlo_SM10(TOptionPlan *plan);
extern "C" void closeMonteCarlo_SM10(TOptionPlan *plan);
extern "C" void MonteCarlo_SM10(TOptionPlan *plan);
extern "C" void inverseCND_SM10(float *d_Output, unsigned int *d_Input, unsigned int N);
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void MonteCarlo_SM13(TOptionPlan *plan);
extern "C" void inverseCND_SM13(float *d_Output, unsigned int *d_Input, unsigned int N);



///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
#define DO_CPU
//#undef DO_CPU



int main(int argc, char **argv)
{
    unsigned int useDoublePrecision = 0;
    char *precisionChoice;

    shrQAStart(argc, argv);

    cutGetCmdLineArgumentstr(argc, (const char **)argv, "type", &precisionChoice);
    if(precisionChoice == NULL)
        useDoublePrecision = 0;
    else{
        if(!strcasecmp(precisionChoice, "double"))
            useDoublePrecision = 1;
        else
            useDoublePrecision = 0;
    }

    const int         OPT_N = 256;
    const int        PATH_N = 1 << 18;
    const unsigned int SEED = 0;

    //Input data array
    TOptionData optionData[OPT_N];
    //Final GPU MC results
    TOptionValue callValueGPU[OPT_N];
    //"Theoretical" call values by Black-Scholes formula
    float callValueBS[OPT_N];

    TOptionPlan plan;

    int i;
    double gpuTime, delta, sumDelta, ref, sumRef, sumReserve;

    unsigned int hTimer;

    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );
    cutilCheckError( cutCreateTimer(&hTimer) );

    int deviceIndex;
    cutilSafeCall(cudaGetDevice(&deviceIndex));
    cudaDeviceProp deviceProp;
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, deviceIndex));
    int version = deviceProp.major * 10 + deviceProp.minor;
    if(useDoublePrecision && version < 13){
        printf("Double precision is not supported.\n");
        return 0;
    }

    printf("Generating input data...\n");
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
        plan.device       = 0;
        plan.optionCount  = 0;
        plan.optionData   = optionData;
        plan.callValue    = callValueGPU;
        plan.seed         = SEED;
        plan.pathN        = 0;


    printf("Allocating memory...\n");
        cutilSafeCall( cudaMalloc((void **)&plan.d_Samples, PATH_N * sizeof(float)) );

    printf("Generating normally distributed samples...\n");
    if(useDoublePrecision)
        inverseCND_SM13(plan.d_Samples, NULL, PATH_N);
    else
        inverseCND_SM10(plan.d_Samples, NULL, PATH_N);

    if( cutCheckCmdLineFlag( argc, (const char**)argv, "shmoo") ){
        printf("Doing shmoo run\n");
        int rowCount = 0, colCount = 0;
        for(int opt = 8; opt <= OPT_N; opt *= 2)
            rowCount++;
        for(int path = 8192; path <= PATH_N; path *= 2)
            colCount++;

        float    *MCtime = (float *)malloc(rowCount * colCount * sizeof(float));
        int *optionLabel = (int *)malloc(rowCount * sizeof(int));
        int   *pathLabel = (int *)malloc(colCount * sizeof(int));

        for(int i = 0, opt = 8; i < rowCount; i++, opt *= 2){
            optionLabel[i] = opt;
            for(int j = 0, path = 8192; j < colCount; path *= 2, j++){
                pathLabel[j] = path;
                plan.optionCount = opt;
                plan.pathN = path;
                if(useDoublePrecision)
                    initMonteCarlo_SM13(&plan);
                else
                    initMonteCarlo_SM10(&plan);

                cutilSafeCall( cutilDeviceSynchronize() );
                cutilCheckError( cutResetTimer(hTimer) );
                cutilCheckError( cutStartTimer(hTimer) );
                if(useDoublePrecision)
                    MonteCarlo_SM13(&plan);
                else
                    MonteCarlo_SM10(&plan);

                cutilSafeCall( cutilDeviceSynchronize() );
                cutilCheckError( cutStopTimer(hTimer) );
                MCtime[i * colCount + j] = cutGetTimerValue(hTimer);

                if(useDoublePrecision)
                    closeMonteCarlo_SM13(&plan);
                else
                    closeMonteCarlo_SM10(&plan);
            }
        }

        printf("Monte Carlo GPU Time, # paths, \n");
        printf("# Options, ");
            for(int j = 0; j < colCount; j++)
                printf("%i, ", pathLabel[j]);
            printf("\n");

        for(int i = 0; i < rowCount; i++){
            printf("%i,", optionLabel[i]);
            for(int j = 0; j < colCount; j++)
                printf("%f, ", MCtime[i * colCount + j]);

            printf("\n");
        }

        free(pathLabel);
        free(optionLabel);
        free(MCtime);
    }
    else{
        printf("Running GPU Monte Carlo...\n");
        printf("Options         : %i\n", OPT_N);
        printf("Simulation paths: %i\n", PATH_N);
        plan.optionCount = OPT_N;
        plan.pathN = PATH_N;
        if(useDoublePrecision)
            initMonteCarlo_SM13(&plan);
        else
            initMonteCarlo_SM10(&plan);

        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        if(useDoublePrecision)
            MonteCarlo_SM13(&plan);
        else
            MonteCarlo_SM10(&plan);
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
        if(useDoublePrecision)
            closeMonteCarlo_SM13(&plan);
        else
            closeMonteCarlo_SM10(&plan);

        printf("Time (ms.)      : %f\n", gpuTime);
        printf("GPU options per sec.: %f\n", OPT_N / (gpuTime * 0.001));

        printf("GPU Monte Carlo vs. Black-Scholes statistics\n");
            sumDelta   = 0;
            sumRef     = 0;
            sumReserve = 0;
            for(i = 0; i < OPT_N; i++){
                BlackScholesCall(
                    callValueBS[i],
                    optionData[i]
                );
                delta       = fabs(callValueBS[i] - callValueGPU[i].Expected);
                ref         = callValueBS[i];
                sumDelta   += delta;
                sumRef     += ref;
                if(delta > 1e-6) sumReserve += callValueGPU[i].Confidence / delta;
            }
            sumReserve /= (double)OPT_N;
        printf("L1 norm        : %E\n", sumDelta / sumRef);
        printf("Average reserve: %f\n", sumReserve);

#ifdef DO_CPU
        printf("CPU Monte Carlo vs. Black-Scholes statistics...\n");
            TOptionValue callValueCPU[OPT_N];
            sumDelta   = 0;
            sumRef     = 0;
            sumReserve = 0;
            for(i = 0; i < OPT_N; i++){
                MonteCarloCPU(
                    callValueCPU[i],
                    optionData[i],
                    NULL,
                    PATH_N
                );
                delta     = fabs(callValueCPU[i].Expected - callValueBS[i]);
                ref       = callValueCPU[i].Expected;
                sumDelta += delta;
                sumRef   += fabs(ref);
                if(delta > 1e-6) sumReserve += callValueGPU[i].Confidence / delta;
            }
            sumReserve /= (double)OPT_N;
        printf("L1 norm: %E\n", sumDelta / sumRef);
        printf("Average reserve: %f\n", sumReserve);

        printf("CPU vs. GPU Monte Carlo statistics...\n");
            sumDelta   = 0;
            sumRef     = 0;
            for(i = 0; i < OPT_N; i++){
                delta     = fabs(callValueCPU[i].Expected - callValueGPU[i].Expected);
                ref       = callValueCPU[i].Expected;
                sumDelta += delta;
                sumRef   += fabs(ref);
            }
        printf("L1 norm: %E\n", sumDelta / sumRef);
#endif
    }


    printf("Shutting down...\n");
        cutilSafeCall( cudaFree(plan.d_Samples) );
        cutilCheckError( cutDeleteTimer( hTimer) );

    cutilDeviceReset();

	printf("[%s] - Test summary\n", sSDKsample);
    shrQAFinishExit( argc, (const char **)argv, (sumReserve > 1.0f) ? QA_PASSED : QA_FAILED);
}
