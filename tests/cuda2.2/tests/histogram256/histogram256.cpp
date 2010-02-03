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
 * This sample implements full-range histogram calculation
 * of arbitrary-sized 8-bit data array
 */



#include <stdlib.h>
#include <stdio.h>
#include <cutil_inline.h>
#include <cuda_runtime.h>



////////////////////////////////////////////////////////////////////////////////
// Reference CPU histogram
////////////////////////////////////////////////////////////////////////////////
extern "C" void histogram256CPU(unsigned int *h_Result, unsigned int *h_Data, int dataN);



////////////////////////////////////////////////////////////////////////////////
// GPU histogram
////////////////////////////////////////////////////////////////////////////////
// Function prototypes
#include "histogram256_common.h"


////////////////////////////////////////////////////////////////////////////////
// Data configuration
////////////////////////////////////////////////////////////////////////////////
//Input data size
const int DATA_N = 100000;
const int DATA_SIZE = DATA_N * sizeof(unsigned char);

const int repetitions = 1;

int main(int argc, char **argv)
{
    unsigned char *h_Data;
    unsigned int *h_ResultCPU, *h_ResultGPU;
    unsigned char *d_Data;

    int i, delta;
    double timerValue;

    unsigned int hTimer;

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError(cutCreateTimer(&hTimer));

    printf("Initializing data...\n");

    printf("...allocating CPU memory.\n");
    h_Data      = (unsigned char *)malloc(DATA_SIZE);
    h_ResultCPU = (unsigned int *)malloc(HISTOGRAM_SIZE);
    h_ResultGPU = (unsigned int *)malloc(HISTOGRAM_SIZE);

    printf("...generating input data\n");
    srand(2007);
    for(i = 0; i < DATA_N; i++)
        h_Data[i] = rand() % 256;

    printf("...allocating GPU memory and copying input data\n");
    cutilSafeCall( cudaMalloc((void **)&d_Data,   DATA_SIZE ) );
    cutilSafeCall( cudaMemcpy(d_Data, h_Data, DATA_SIZE, cudaMemcpyHostToDevice) );

    printf("Running CPU histogram...\n");

    cutilCheckError( cutResetTimer(hTimer) );
    cutilCheckError( cutStartTimer(hTimer) );
    histogram256CPU(
        h_ResultCPU,
        (unsigned int *)h_Data,
        DATA_N / 4
    );
    cutilCheckError(cutStopTimer(hTimer));
    timerValue = cutGetTimerValue(hTimer);

    printf("histogramCPU() time : %f msec // %f MB/sec\n", timerValue, DATA_SIZE / (1048576.0 * timerValue * 0.001));


    int deviceIndex;
    cutilSafeCall(cudaGetDevice(&deviceIndex));
    
    cudaDeviceProp deviceProp;
    cutilSafeCall(cudaGetDeviceProperties(&deviceProp, deviceIndex));

    if (deviceProp.major >= 1)
    {
        printf("Running GPU histogram using SM10...\n");

        initHistogram256_SM10();
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
		for (i = 0; i < repetitions; i++)
			histogram256_SM10(h_ResultGPU, (unsigned int *) d_Data, DATA_N);
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        timerValue = cutGetTimerValue(hTimer);
        closeHistogram256_SM10();

        printf("histogram256_SM10() time : %f msec // %f MB/sec\n", timerValue / repetitions, DATA_SIZE / (1048576.0 * timerValue * 0.001) * repetitions);

        delta = 0;
        for(i = 0; i < BIN_COUNT; i++) delta += abs((int)h_ResultGPU[i] - (int)h_ResultCPU[i]);
        printf((delta == 0) ? "TEST PASSED\n" : "TEST FAILED\n");
    }

    if (deviceProp.major > 1 || (deviceProp.major == 1 && deviceProp.minor >= 1))
    {
        printf("Running GPU histogram using SM11...\n");

        initHistogram256_SM11();
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
		for (i = 0; i < repetitions; i++)
			histogram256_SM11(h_ResultGPU, (unsigned int *) d_Data, DATA_N);
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        timerValue = cutGetTimerValue(hTimer);
        closeHistogram256_SM11();

        printf("histogram256_SM11() time : %f msec // %f MB/sec\n", timerValue / repetitions, DATA_SIZE / (1048576.0 * timerValue * 0.001) * repetitions);

        delta = 0;
        for(i = 0; i < BIN_COUNT; i++) delta += abs((int)h_ResultGPU[i] - (int)h_ResultCPU[i]);
        printf((delta == 0) ? "TEST PASSED\n" : "TEST FAILED\n");
    }

    if (deviceProp.major > 1 || (deviceProp.major == 1 && deviceProp.minor >= 2))
    {
        printf("Running GPU histogram using SM12...\n");

        initHistogram256_SM12();
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
		for (i = 0; i < repetitions; i++)
			histogram256_SM12(h_ResultGPU, (unsigned int *) d_Data, DATA_N);
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        timerValue = cutGetTimerValue(hTimer);
        closeHistogram256_SM12();

        printf("histogram256_SM12() time : %f msec // %f MB/sec\n", timerValue / repetitions, DATA_SIZE / (1048576.0 * timerValue * 0.001) * repetitions);

        delta = 0;
        for(i = 0; i < BIN_COUNT; i++) delta += abs((int)h_ResultGPU[i] - (int)h_ResultCPU[i]);
        printf((delta == 0) ? "TEST PASSED\n" : "TEST FAILED\n");
    }

    printf("Shutting down...\n");

    cutilCheckError(cutDeleteTimer(hTimer));
    cutilSafeCall( cudaFree(d_Data) );
    free(h_ResultGPU);
    free(h_ResultCPU);
    free(h_Data);

    cudaThreadExit();

    cutilExit(argc, argv);
}
