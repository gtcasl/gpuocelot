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



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>


#ifdef WIN32
#define strcasecmp strcmpi
#endif



#include "quasirandomGenerator_common.h"



////////////////////////////////////////////////////////////////////////////////
// CPU code
////////////////////////////////////////////////////////////////////////////////
extern "C" void initQuasirandomGenerator(
    unsigned int table[QRNG_DIMENSIONS][QRNG_RESOLUTION]
);

extern "C" float getQuasirandomValue(
    unsigned int table[QRNG_DIMENSIONS][QRNG_RESOLUTION],
    int i,
    int dim
);

extern "C" double getQuasirandomValue63(INT64 i, int dim);
extern "C" double MoroInvCNDcpu(double p);
extern "C" double AcklamInvCNDcpu(double p);



////////////////////////////////////////////////////////////////////////////////
// GPU code
////////////////////////////////////////////////////////////////////////////////
extern "C" void initTable_SM10(unsigned int tableCPU[QRNG_DIMENSIONS][QRNG_RESOLUTION]);
extern "C" void quasirandomGenerator_SM10(float *d_Output, unsigned int seed, unsigned int N);
extern "C" void inverseCND_SM10(float *d_Output, float *d_Input, unsigned int N);
extern "C" void initTable_SM13(unsigned int tableCPU[QRNG_DIMENSIONS][QRNG_RESOLUTION]);
extern "C" void quasirandomGenerator_SM13(float *d_Output, unsigned int seed, unsigned int N);
extern "C" void inverseCND_SM13(float *d_Output, float *d_Input, unsigned int N);



const int N = 1048576;



int main(int argc, char **argv){
    unsigned int useDoublePrecision;

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

    unsigned int tableCPU[QRNG_DIMENSIONS][QRNG_RESOLUTION];

    float
        *h_OutputGPU;

    float
        *d_Output;

    int
        dim, pos;

    double
        delta, ref, sumDelta, sumRef, L1norm, gpuTime;

    unsigned int hTimer;

    if(sizeof(INT64) != 8){
        printf("sizeof(INT64) != 8\n");
        return 0;
    }

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError(cutCreateTimer(&hTimer));

    int deviceIndex;
    cutilSafeCall(cudaGetDevice(&deviceIndex));
    cudaDeviceProp deviceProp;
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, deviceIndex));
    int version = deviceProp.major * 10 + deviceProp.minor;
    if(useDoublePrecision && version < 13){
        printf("Double precision not supported.\n");
        cudaThreadExit();
        return 0;
    }

    printf("Allocating GPU memory...\n");
        cutilSafeCall( cudaMalloc((void **)&d_Output, QRNG_DIMENSIONS * N * sizeof(float)) );

    printf("Allocating CPU memory...\n");
        h_OutputGPU = (float *)malloc(QRNG_DIMENSIONS * N * sizeof(float));

    printf("Initializing QRNG tables...\n");
        initQuasirandomGenerator(tableCPU);
        if(useDoublePrecision)
            initTable_SM13(tableCPU);
        else
            initTable_SM10(tableCPU);

    printf("Testing QRNG...\n");
        cutilSafeCall( cudaMemset(d_Output, 0, QRNG_DIMENSIONS * N * sizeof(float)) );
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
            if(useDoublePrecision)
                quasirandomGenerator_SM13(d_Output, 0, N);
            else
                quasirandomGenerator_SM10(d_Output, 0, N);
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        gpuTime = cutGetTimerValue(hTimer);
    printf("Gsamples/s: %f\n", (double)QRNG_DIMENSIONS * (double)N * 1E-9 / (gpuTime * 1E-3));

    printf("Reading GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, QRNG_DIMENSIONS * N * sizeof(float), cudaMemcpyDeviceToHost) );

    printf("Comparing to the CPU results...\n");
        sumDelta = 0;
        sumRef = 0;
        for(dim = 0; dim < QRNG_DIMENSIONS; dim++)
            for(pos = 0; pos < N; pos++){
                ref       = getQuasirandomValue63(pos, dim);
                delta     = (double)h_OutputGPU[dim * N + pos] - ref;
                sumDelta += fabs(delta);
                sumRef   += fabs(ref);
            }
    printf("L1 norm: %E\n", sumDelta / sumRef);

    printf("Testing inverseCNDgpu()...\n");
        cutilSafeCall( cudaMemset(d_Output, 0, QRNG_DIMENSIONS * N * sizeof(float)) );
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
            if(useDoublePrecision)
                inverseCND_SM13(d_Output, NULL, QRNG_DIMENSIONS * N);
            else
                inverseCND_SM10(d_Output, NULL, QRNG_DIMENSIONS * N);
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        gpuTime = cutGetTimerValue(hTimer);
    printf("Gsamples/s: %f\n", (double)QRNG_DIMENSIONS * (double)N * 1E-9 / (gpuTime * 1E-3));

    printf("Reading GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, QRNG_DIMENSIONS * N * sizeof(float), cudaMemcpyDeviceToHost) );

    printf("Comparing to the CPU results...\n");
        sumDelta = 0;
        sumRef = 0;
        for(pos = 0; pos < QRNG_DIMENSIONS * N; pos++){
            double  p = (double)(pos + 1) / (double)(QRNG_DIMENSIONS * N + 1);
            ref       = MoroInvCNDcpu(p);
            delta     = (double)h_OutputGPU[pos] - ref;
            sumDelta += fabs(delta);
            sumRef   += fabs(ref);
        }
    printf("L1 norm: %E\n", L1norm = sumDelta / sumRef);
    printf((L1norm < 1E-6) ? "TEST PASSED\n" : "TEST FAILED\n");

    printf("Shutting down...\n");
        cutilCheckError(cutDeleteTimer(hTimer));
        free(h_OutputGPU);
        cutilSafeCall( cudaFree(d_Output) );

    cudaThreadExit();

    cutilExit(argc,argv);
}
