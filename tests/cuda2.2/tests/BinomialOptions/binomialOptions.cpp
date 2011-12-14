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
 * given set of European options under binomial model.
 * See supplied whitepaper for more explanations.
 */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>


#ifdef WIN32
#define strcasecmp strcmpi
#endif

#ifdef WIN64
#define strcasecmp strcmpi
#endif


#include "binomialOptions_common.h"



////////////////////////////////////////////////////////////////////////////////
// Black-Scholes formula for binomial tree results validation
////////////////////////////////////////////////////////////////////////////////
extern "C" void BlackScholesCall(
    float& callResult,
    TOptionData optionData
);

////////////////////////////////////////////////////////////////////////////////
// Process single option on CPU
// Note that CPU code is for correctness testing only and not for benchmarking.
////////////////////////////////////////////////////////////////////////////////
extern "C" void binomialOptionsCPU(
    float& callResult,
    TOptionData optionData
);


////////////////////////////////////////////////////////////////////////////////
// Process an array of OptN options on GPU
////////////////////////////////////////////////////////////////////////////////
extern "C" void binomialOptions_SM10(
    float *callValue,
    TOptionData  *optionData,
    int optN
);

extern "C" void binomialOptions_SM13(
    float *callValue,
    TOptionData  *optionData,
    int optN
);

extern "C" int deviceEmulation(void);



////////////////////////////////////////////////////////////////////////////////
// Helper function, returning uniformly distributed
// random float in [low, high] range
////////////////////////////////////////////////////////////////////////////////
float randData(float low, float high){
    float t = (float)rand() / (float)RAND_MAX;
    return (1.0f - t) * low + t * high;
}



////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    const unsigned int OPT_N_MAX = 512;
    unsigned int useDoublePrecision;

    char *precisionChoice;
    cutGetCmdLineArgumentstr(argc, (const char **)argv, "type", &precisionChoice);
    if(precisionChoice == NULL) {
        useDoublePrecision = 0;
    } else {
        if(!strcasecmp(precisionChoice, "double"))
            useDoublePrecision = 1;
        else
            useDoublePrecision = 0;
    }
    printf(useDoublePrecision ? "Using double precision...\n" : "Using single precision...\n");
    const int OPT_N = deviceEmulation() ? 1 : OPT_N_MAX;

    TOptionData optionData[OPT_N_MAX];
    float
        callValueBS[OPT_N_MAX],
        callValueGPU[OPT_N_MAX],
        callValueCPU[OPT_N_MAX];

    double
        sumDelta, sumRef, gpuTime, errorVal;

    unsigned int hTimer;
    int i;

    cutilDeviceInit(argc, argv);
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
        //Generate options set
        srand(123);
        for(i = 0; i < OPT_N; i++){
            optionData[i].S = randData(5.0f, 30.0f);
            optionData[i].X = randData(1.0f, 100.0f);
            optionData[i].T = randData(0.25f, 10.0f);
            optionData[i].R = 0.06f;
            optionData[i].V = 0.10f;
            BlackScholesCall(callValueBS[i], optionData[i]);
        }

    printf("Running GPU binomial tree...\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );

        if(useDoublePrecision)
            binomialOptions_SM13(callValueGPU, optionData, OPT_N);
        else
            binomialOptions_SM10(callValueGPU, optionData, OPT_N);

        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
    printf("Options count            : %i     \n", OPT_N);
    printf("Time steps               : %i     \n", NUM_STEPS);
    printf("binomialOptionsGPU() time: %f msec\n", gpuTime);
    printf("Options per second       : %f     \n", OPT_N / (gpuTime * 0.001));

    printf("Running CPU binomial tree...\n");
        for(i = 0; i < OPT_N; i++)
            binomialOptionsCPU(callValueCPU[i], optionData[i]);

    printf("Comparing the results...\n");
    sumDelta = 0;
    sumRef   = 0;
    printf("GPU binomial vs. Black-Scholes\n");
    for(i = 0; i < OPT_N; i++){
        sumDelta += fabs(callValueBS[i] - callValueGPU[i]);
        sumRef += fabs(callValueBS[i]);
    }
    if(sumRef >1E-5)
        printf("L1 norm: %E\n", sumDelta / sumRef);
    else
        printf("Avg. diff: %E\n", sumDelta / (double)OPT_N);

    printf("CPU binomial vs. Black-Scholes\n");
    sumDelta = 0;
    sumRef   = 0;
    for(i = 0; i < OPT_N; i++){
        sumDelta += fabs(callValueBS[i]- callValueCPU[i]);
        sumRef += fabs(callValueBS[i]);
    }
    if(sumRef >1E-5)
        printf("L1 norm: %E\n", sumDelta / sumRef);
    else
        printf("Avg. diff: %E\n", sumDelta / (double)OPT_N);

    printf("CPU binomial vs. GPU binomial\n");
    sumDelta = 0;
    sumRef   = 0;
    for(i = 0; i < OPT_N; i++){
        sumDelta += fabs(callValueGPU[i] - callValueCPU[i]);
        sumRef += callValueCPU[i];
    }
    if(sumRef > 1E-5)
        printf("L1 norm: %E\n", errorVal = sumDelta / sumRef);
    else
        printf("Avg. diff: %E\n", errorVal = sumDelta / (double)OPT_N);

    printf((errorVal < 5e-4) ? "TEST PASSED\n" : "TEST FAILED\n");

    printf("Shutting down...\n");
    cutilCheckError( cutDeleteTimer(hTimer) );

    cudaThreadExit();

    cutilExit(argc, argv);
}
