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
 * This sample implements 64-bin histogram calculation
 * of arbitrary-sized 8-bit data array
 */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <cutil_inline.h>
#include <cutil_inline.h>



////////////////////////////////////////////////////////////////////////////////
// Reference CPU histogram
////////////////////////////////////////////////////////////////////////////////
extern "C" void histogram64CPU(
    unsigned int *h_Result,
    unsigned int *h_Data,
    int dataN
);



////////////////////////////////////////////////////////////////////////////////
// GPU histogram
////////////////////////////////////////////////////////////////////////////////
#include "histogram64_kernel.cuh"



////////////////////////////////////////////////////////////////////////////////
// Data configuration
////////////////////////////////////////////////////////////////////////////////
//Input data size
const int         DATA_N = 1000000;
const int      DATA_SIZE = DATA_N * sizeof(unsigned char);


//Repeat computations multiple times to improve timing precision
const int NUM_ITERATIONS = 1;

int main(int argc, char **argv){
    unsigned char
        *h_Data;

    unsigned int
        *h_HistogramCPU, *h_HistogramGPU;

    unsigned char
        *d_Data;

    unsigned int
        *d_Histogram;

    int i, sum, delta, iter;
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
        h_Data         = (unsigned char *)malloc(DATA_SIZE);
        h_HistogramCPU = (unsigned int *)malloc(HISTOGRAM_SIZE);
        h_HistogramGPU = (unsigned int *)malloc(HISTOGRAM_SIZE);

        printf("...generating input data\n");
        srand(2007);
        for(i = 0; i < DATA_N; i++) 
            h_Data[i] = rand() % 256;

        printf("...allocating GPU memory and copying input data\n");
        cutilSafeCall( cudaMalloc((void **)&d_Data, DATA_SIZE  ) );
        cutilSafeCall( cudaMalloc((void **)&d_Histogram, HISTOGRAM_SIZE  ) );
        cutilSafeCall( cudaMemcpy(d_Data, h_Data, DATA_SIZE, cudaMemcpyHostToDevice) );


    printf("Running GPU histogram (%i iterations)...\n", NUM_ITERATIONS);
        initHistogram64GPU();
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        for(iter = 0; iter < NUM_ITERATIONS; iter++);
            histogram64GPU(d_Histogram, (unsigned int *)d_Data, DATA_N);
        cutilSafeCall( cudaThreadSynchronize() );

        cutilCheckError(  cutStopTimer(hTimer));
        timerValue = cutGetTimerValue(hTimer) / NUM_ITERATIONS;
        closeHistogram64GPU();
    printf("histogram64GPU() time (average) : %f msec //%f MB/sec\n", timerValue, DATA_SIZE / (1e+6 * timerValue * 0.001));

    printf("Reading back GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_HistogramGPU, d_Histogram, HISTOGRAM_SIZE, cudaMemcpyDeviceToHost) );

    printf("Comparing the results...\n");
        printf("...histogramCPU()\n");
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        histogram64CPU(
            h_HistogramCPU,
            (unsigned int *)h_Data,
            DATA_N / 4
        );
        cutilCheckError(cutStopTimer(hTimer));
        timerValue = cutGetTimerValue(hTimer);
    printf("histogram64CPU() time : %f msec //%f MB/sec\n", timerValue, DATA_SIZE / (1048576.0 * timerValue * 0.001));

        sum   = 0;
        delta = 0;
        for(i = 0; i < BIN_COUNT; i++){
            sum   += h_HistogramGPU[i];
            delta += abs((int)h_HistogramGPU[i] - (int)h_HistogramCPU[i]);
        }

    printf("Total sum of histogram elements: %i\n", sum);
    printf("Sum of absolute differences: %i\n", delta);
    printf((delta == 0) ? "TEST PASSED\n" : "TEST FAILED\n");

    printf("Shutting down...\n");
        cutilCheckError(cutDeleteTimer(hTimer));
        cutilSafeCall( cudaFree(d_Histogram) );
        cutilSafeCall( cudaFree(d_Data) );
        free(h_HistogramGPU);
        free(h_HistogramCPU);
        free(h_Data);

    cudaThreadExit();

    cutilExit(argc, argv);
}
