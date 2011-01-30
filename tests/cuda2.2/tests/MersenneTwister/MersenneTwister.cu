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
 * This sample implements Mersenne Twister random number generator 
 * and Cartesian Box-Muller transformation on the GPU.
 * See supplied whitepaper for more explanations.
 */



#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <cutil_inline.h>
#include "MersenneTwister.h"



///////////////////////////////////////////////////////////////////////////////
// Common host and device function 
///////////////////////////////////////////////////////////////////////////////
//ceil(a / b)
extern "C" int iDivUp(int a, int b){
    return ((a % b) != 0) ? (a / b + 1) : (a / b);
}

//floor(a / b)
extern "C" int iDivDown(int a, int b){
    return a / b;
}

//Align a to nearest higher multiple of b
extern "C" int iAlignUp(int a, int b){
    return ((a % b) != 0) ?  (a - a % b + b) : a;
}

//Align a to nearest lower multiple of b
extern "C" int iAlignDown(int a, int b){
    return a - a % b;
}



///////////////////////////////////////////////////////////////////////////////
// Reference MT front-end and Box-Muller transform
///////////////////////////////////////////////////////////////////////////////
extern "C" void initMTRef(const char *fname);
extern "C" void RandomRef(float *h_Random, int NPerRng, unsigned int seed);
extern "C" void BoxMullerRef(float *h_Random, int NPerRng);



///////////////////////////////////////////////////////////////////////////////
// Fast GPU random number generator and Box-Muller transform
///////////////////////////////////////////////////////////////////////////////
#include "MersenneTwister_kernel.cuh"



///////////////////////////////////////////////////////////////////////////////
// Data configuration
///////////////////////////////////////////////////////////////////////////////
const int    PATH_N = 24000000;
const int N_PER_RNG = iAlignUp(iDivUp(PATH_N, MT_RNG_COUNT), 2);
const int    RAND_N = MT_RNG_COUNT * N_PER_RNG;

const unsigned int SEED = 777;



#define DO_BOXMULLER
///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    float
        *d_Rand;

    float
        *h_RandCPU,
        *h_RandGPU;

    double
        rCPU, rGPU, delta, sum_delta, max_delta, sum_ref, L1norm, gpuTime;

    int i, j;
    unsigned int hTimer;


    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError( cutCreateTimer(&hTimer) );

    printf("Initializing data for %i samples...\n", PATH_N);
        h_RandCPU  = (float *)malloc(RAND_N * sizeof(float));
        h_RandGPU  = (float *)malloc(RAND_N * sizeof(float));
        cutilSafeCall( cudaMalloc((void **)&d_Rand, RAND_N * sizeof(float)) );

    printf("Loading CPU and GPU twisters configurations...\n");
        const char *raw_path = cutFindFilePath("MersenneTwister.raw", argv[0]);
        const char *dat_path = cutFindFilePath("MersenneTwister.dat", argv[0]);
        initMTRef(raw_path);
        loadMTGPU(dat_path);
        seedMTGPU(SEED);

    printf("Generating random numbers on GPU...\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        RandomGPU<<<32, 128>>>(d_Rand, N_PER_RNG);
        cutilCheckMsg("RandomGPU() execution failed\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
    printf("Generated samples : %i \n", RAND_N);
    printf("RandomGPU() time  : %f \n", gpuTime);
    printf("Samples per second: %E \n", RAND_N / (gpuTime * 0.001));


#ifdef DO_BOXMULLER
    printf("Applying Box-Muller transformation on GPU...\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        BoxMullerGPU<<<32, 128>>>(d_Rand, N_PER_RNG);
        cutilCheckMsg("BoxMullerGPU() execution failed\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
    printf("Transformed samples : %i \n", RAND_N);
    printf("BoxMullerGPU() time : %f \n", gpuTime);
    printf("Samples per second  : %E \n", RAND_N / (gpuTime * 0.001));
#endif

    printf("Reading back the results...\n");
        cutilSafeCall( cudaMemcpy(h_RandGPU, d_Rand, RAND_N * sizeof(float), cudaMemcpyDeviceToHost) );


    printf("Checking GPU results...\n");
        printf("...generating random numbers on CPU using reference generator\n");
        RandomRef(h_RandCPU, N_PER_RNG, SEED);

        #ifdef DO_BOXMULLER
            printf("...applying Box-Muller transformation on CPU\n");
            BoxMullerRef(h_RandCPU, N_PER_RNG);
        #endif

        printf("...comparing the results\n");
        max_delta = 0;
        sum_delta = 0;
        sum_ref   = 0;
        for(i = 0; i < MT_RNG_COUNT; i++)
            for(j = 0; j < N_PER_RNG; j++){
                rCPU = h_RandCPU[i * N_PER_RNG + j];
                rGPU = h_RandGPU[i + j * MT_RNG_COUNT];
                delta = fabs(rCPU - rGPU);
                sum_delta += delta;
                sum_ref   += fabs(rCPU);
                if(delta >= max_delta) max_delta = delta;
            }
    L1norm = (float)(sum_delta / sum_ref);
    printf("Max absolute error: %E\n", max_delta);
    printf("L1 norm: %E\n", L1norm);
    printf((L1norm < 1e-6) ? "TEST PASSED\n" : "TEST FAILED\n");

    printf("Shutting down...\n");
        cutilSafeCall( cudaFree(d_Rand) );
        free(h_RandGPU);
        free(h_RandCPU);

    cutilCheckError( cutDeleteTimer( hTimer) );

    cudaThreadExit();

    cutilExit(argc, argv);
}
