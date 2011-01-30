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
#include <string.h>
#include "MonteCarlo_common.h"


#ifdef WIN32
#define strcasecmp strcmpi
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
extern "C" void inverseCND_SM10(float *d_Output, float *d_Input, unsigned int N);
extern "C" void initMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void closeMonteCarlo_SM13(TOptionPlan *plan);
extern "C" void MonteCarlo_SM13(TOptionPlan *plan);
extern "C" void inverseCND_SM13(float *d_Output, float *d_Input, unsigned int N);



///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
#define DO_CPU
//#undef DO_CPU



int main(int argc, char **argv){
    unsigned int useDoublePrecision = 0;

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

    const int         OPT_N = 256;
    const int        PATH_N = 1 << 16;
    const unsigned int SEED = 0;

    //Input data array
    TOptionData optionData[OPT_N];
    //Final GPU MC results
    TOptionValue callValueGPU[OPT_N];
    //"Theoretical" call values by Black-Scholes formula
    float callValueBS[OPT_N];

    TOptionPlan plan;

    int i;
    double
        gpuTime, delta, sumDelta, ref, sumRef, sumReserve;

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

                cutilSafeCall( cudaThreadSynchronize() );
                cutilCheckError( cutResetTimer(hTimer) );
                cutilCheckError( cutStartTimer(hTimer) );
                if(useDoublePrecision)
                    MonteCarlo_SM13(&plan);
                else
                    MonteCarlo_SM10(&plan);

                cutilSafeCall( cudaThreadSynchronize() );
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

        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        if(useDoublePrecision)
            MonteCarlo_SM13(&plan);
        else
            MonteCarlo_SM10(&plan);
        cutilSafeCall( cudaThreadSynchronize() );
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
        printf((sumReserve > 1.0f) ? "TEST PASSED\n" : "TEST FAILED\n");

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

    cudaThreadExit();

    cutilExit(argc, argv);
}
