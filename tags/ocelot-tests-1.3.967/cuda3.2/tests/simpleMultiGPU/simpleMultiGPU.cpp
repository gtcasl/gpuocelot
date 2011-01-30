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
 * This application demonstrates how to use the CUDA API to use multiple GPUs,
 * with an emphasis on simple illustration of the techniques (not on performance).
 *
 * There's one CUDA context per thread. To use multiple CUDA contexts you
 * have to create multiple threads. One for each GPU. For optimal performance,
 * the number of CPU cores should be equal to the number of GPUs in the system.
 *
 * Creating CPU threads has a certain overhead. So, this is only worth when you
 * have a significant amount of work to do per thread. It's also recommended to
 * create a pool of threads and reuse them to avoid this overhead.
 *
 * Note that in order to detect multiple GPUs in your system you have to disable
 * SLI in the nvidia control panel. Otherwise only one GPU is visible to the 
 * application. On the other side, you can still extend your desktop to screens 
 * attached to both GPUs.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <multithreading.h>

#include <cutil_inline.h>
#include <cuda_runtime_api.h>
#include "simpleMultiGPU.h"

////////////////////////////////////////////////////////////////////////////////
// GPU thread
////////////////////////////////////////////////////////////////////////////////
static CUT_THREADPROC solverThread(TGPUplan *plan){
    const int  BLOCK_N = 32;
    const int THREAD_N = 256;
    const int  ACCUM_N = BLOCK_N * THREAD_N;

    float *d_Data,*d_Sum;
    float *h_Sum;
    float sum;

    int i;
    //Set device
    cutilSafeCall( cudaSetDevice(plan->device) );

    //Allocate memory
    cutilSafeCall( cudaMalloc((void**)&d_Data, plan->dataN * sizeof(float)) );
    cutilSafeCall( cudaMalloc((void**)&d_Sum, ACCUM_N * sizeof(float)) );
    cutilSafeMalloc( h_Sum = (float *)malloc(ACCUM_N * sizeof(float)) );

    //Copy input data from CPU
    cutilSafeCall( cudaMemcpy(d_Data, plan->h_Data, plan->dataN * sizeof(float), cudaMemcpyHostToDevice) );

    //Perform GPU computations
    launch_reduceKernel(d_Sum, d_Data, plan->dataN, BLOCK_N, THREAD_N);
    cutilCheckMsg("reduceKernel() execution failed.\n");

    //Read back GPU results
    cutilSafeCall( cudaMemcpy(h_Sum, d_Sum, ACCUM_N * sizeof(float), cudaMemcpyDeviceToHost) );

    //Finalize GPU reduction for current subvector
    sum = 0;
    for(i = 0; i < ACCUM_N; i++)
        sum += h_Sum[i];
    *(plan->h_Sum) = (float)sum;

    //Shut down this GPU
    free(h_Sum);
    cutilSafeCall( cudaFree(d_Sum) );
    cutilSafeCall( cudaFree(d_Data) );
    CUT_THREADEND;
}

////////////////////////////////////////////////////////////////////////////////
// Data configuration
////////////////////////////////////////////////////////////////////////////////
const int MAX_GPU_COUNT = 32;
const int DATA_N        = 1048576 * 32;

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    //Solver config
    TGPUplan      plan[MAX_GPU_COUNT];

    //GPU reduction results
    float     h_SumGPU[MAX_GPU_COUNT];

    //OS thread ID
    CUTThread threadID[MAX_GPU_COUNT];

    float *h_Data;
    float sumGPU;
    double sumCPU, diff;

    int i, gpuBase, GPU_N;
    unsigned int hTimer;

    cutilCheckError(cutCreateTimer(&hTimer));

    cutilSafeCall(cudaGetDeviceCount(&GPU_N));
    if(GPU_N > MAX_GPU_COUNT) GPU_N = MAX_GPU_COUNT;
    printf("CUDA-capable device count: %i\n", GPU_N);

    printf("Generating input data...\n\n");
        h_Data = (float *)malloc(DATA_N * sizeof(float));
        for(i = 0; i < DATA_N; i++)
            h_Data[i] = (float)rand() / (float)RAND_MAX;

    //Subdividing input data across GPUs
    //Get data sizes for each GPU
    for(i = 0; i < GPU_N; i++)
        plan[i].dataN = DATA_N / GPU_N;

    //Take into account "odd" data sizes
    for(i = 0; i < DATA_N % GPU_N; i++)
        plan[i].dataN++;

    //Assign data ranges to GPUs
    gpuBase = 0;
    for(i = 0; i < GPU_N; i++){
        plan[i].device = i;
        plan[i].h_Data = h_Data + gpuBase;
        plan[i].h_Sum = h_SumGPU + i;
        gpuBase += plan[i].dataN;
    }

    //Start timing and compute on GPU(s)
    printf("Computing with %d GPU's...\n", GPU_N);
    cutilCheckError(cutResetTimer(hTimer));
    cutilCheckError(cutStartTimer(hTimer));
    for(i = 0; i < GPU_N; i++)
    {
            threadID[i] = cutStartThread((CUT_THREADROUTINE)solverThread, (void *)(plan + i));
    }
    cutWaitForThreads(threadID, GPU_N);
    sumGPU = 0;
    for(i = 0; i < GPU_N; i++)
    {
        sumGPU += h_SumGPU[i];
    }
    cutilCheckError(cutStopTimer(hTimer));
    printf("  GPU Processing time: %f (ms)\n\n", cutGetTimerValue(hTimer));

    // Compute on Host CPU 
    printf("Computing with Host CPU...\n\n");
    sumCPU = 0;
    for(i = 0; i < DATA_N; i++)
    {
        sumCPU += h_Data[i];
    }

    // Compare GPU and CPU results 
    printf("Comparing GPU and Host CPU results...\n");
    diff = fabs(sumCPU - sumGPU) / fabs(sumCPU);
    printf("  GPU sum: %f\n  CPU sum: %f\n", sumGPU, sumCPU);
    printf("  Relative difference: %E \n\n", diff);
    printf((diff < 1e-5) ? "PASSED\n\n" : "FAILED\n\n");

    // Cleanup and shutdown
    printf("Shutting down...\n");
    cutilCheckError(cutDeleteTimer(hTimer));
    free(h_Data);
    cudaThreadExit();
    cutilExit(argc, argv);
}
