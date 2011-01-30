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

#include <stdio.h>
#include <stdlib.h>

#include <cutil_inline.h>

#include "clock_kernel.cu"

// This example shows how to use the clock function to measure the performance of 
// a kernel accurately.
// 
// Blocks are executed in parallel and out of order. Since there's no synchronization
// mechanism between blocks, we measure the clock once for each block. The clock 
// samples are written to device memory.

#define NUM_BLOCKS    64
#define NUM_THREADS   256

// It's interesting to change the number of blocks and the number of threads to 
// understand how to keep the hardware busy.
//
// Here are some numbers I get on my G80:
//    blocks - clocks
//    1 - 3096
//    8 - 3232
//    16 - 3364
//    32 - 4615
//    64 - 9981
//
// With less than 16 blocks some of the multiprocessors of the device are idle. With
// more than 16 you are using all the multiprocessors, but there's only one block per
// multiprocessor and that doesn't allow you to hide the latency of the memory. With
// more than 32 the speed scales linearly.

int main(int argc, char** argv)

{
    // use command-line specified CUDA device, otherwise use device with highest Gflops/s

    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device")) {
        int devID = cutilDeviceInit(argc, argv);
        if (devID < 0) {
           printf("exiting...\n");
           cutilExit(argc, argv);
           exit(0);
        }
    } else {
        cudaSetDevice( cutGetMaxGflopsDeviceId() );
    }

    float * dinput = NULL;
    float * doutput = NULL;
    clock_t * dtimer = NULL;

    clock_t timer[NUM_BLOCKS * 2];
    float input[NUM_THREADS * 2];

    for (int i = 0; i < NUM_THREADS * 2; i++)
    {
        input[i] = (float)i;
    }

    cutilSafeCall(cudaMalloc((void**)&dinput, sizeof(float) * NUM_THREADS * 2));
    cutilSafeCall(cudaMalloc((void**)&doutput, sizeof(float) * NUM_BLOCKS));
    cutilSafeCall(cudaMalloc((void**)&dtimer, sizeof(clock_t) * NUM_BLOCKS * 2));

    cutilSafeCall(cudaMemcpy(dinput, input, sizeof(float) * NUM_THREADS * 2, cudaMemcpyHostToDevice));

    timedReduction<<<NUM_BLOCKS, NUM_THREADS, sizeof(float) * 2 * NUM_THREADS>>>(dinput, doutput, dtimer);

    //cutilSafeCall(cudaMemcpy(output, doutput, sizeof(float) * NUM_BLOCKS, cudaMemcpyDeviceToHost));
    cutilSafeCall(cudaMemcpy(timer, dtimer, sizeof(clock_t) * NUM_BLOCKS * 2, cudaMemcpyDeviceToHost));

    cutilSafeCall(cudaFree(dinput));
    cutilSafeCall(cudaFree(doutput));
    cutilSafeCall(cudaFree(dtimer));

    // This test always passes.
    printf( "PASSED\n");

    // Compute the difference between the last block end and the first block start.
    clock_t minStart = timer[0];
    clock_t maxEnd = timer[NUM_BLOCKS];

    for (int i = 1; i < NUM_BLOCKS; i++)
    {
        minStart = timer[i] < minStart ? timer[i] : minStart;
        maxEnd = timer[NUM_BLOCKS+i] > maxEnd ? timer[NUM_BLOCKS+i] : maxEnd;
    }

    printf("time = %d\n", maxEnd - minStart);

    cudaThreadExit();

    cutilExit(argc, argv);
}
