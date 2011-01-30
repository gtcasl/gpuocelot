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

    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
	    cutilDeviceInit(argc, argv);
    else
	    cudaSetDevice( cutGetMaxGflopsDeviceId() );


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
    printf( "Test PASSED\n");

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
