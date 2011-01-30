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
 * This sample implemenets bitonic sort and odd-even merge sort, algorithms
 * belonging to the class of sorting networks. 
 * While generally subefficient on large sequences 
 * compared to algorithms with better asymptotic algorithmic complexity
 * (i.e. merge sort or radix sort), may be the algorithms of choice for sorting
 * batches of short- or mid-sized arrays.
 * Refer to the excellent tutorial by H. W. Lang:
 * http://www.iti.fh-flensburg.de/lang/algorithmen/sortieren/networks/indexen.htm
 * 
 * Victor Podlozhnyuk, 07/09/2009
 */

// Utilities and system includes
#include <shrUtils.h>
#include <cutil_inline.h>

#include "sortingNetworks_common.h"

////////////////////////////////////////////////////////////////////////////////
// Test driver
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    // Start logs
    shrSetLogFileName ("sortingNetworks.txt");
    shrLog("%s Starting...\n\n", argv[0]);
    
    shrLog("Starting up CUDA context...\n");
        if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
            cutilDeviceInit(argc, argv);
        else
            cudaSetDevice( cutGetMaxGflopsDeviceId() );

    uint *h_InputKey, *h_InputVal, *h_OutputKeyGPU, *h_OutputValGPU;
    uint *d_InputKey, *d_InputVal,    *d_OutputKey,    *d_OutputVal;
    uint hTimer;

    const uint             N = isDeviceEmulation() ? 8192 : 1048576;
    const uint           DIR = 0;
    const uint     numValues = 65536;
    const uint numIterations = 1;

    shrLog("Allocating and initializing host arrays...\n\n");
        cutCreateTimer(&hTimer);
        h_InputKey     = (uint *)malloc(N * sizeof(uint));
        h_InputVal     = (uint *)malloc(N * sizeof(uint));
        h_OutputKeyGPU = (uint *)malloc(N * sizeof(uint));
        h_OutputValGPU = (uint *)malloc(N * sizeof(uint));
        srand(2001);
        for(uint i = 0; i < N; i++){
            h_InputKey[i] = rand() % numValues;
            h_InputVal[i] = i;
        }

    shrLog("Allocating and initializing CUDA arrays...\n\n");
        cutilSafeCall( cudaMalloc((void **)&d_InputKey,  N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_InputVal,  N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_OutputKey, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_OutputVal, N * sizeof(uint)) );
        cutilSafeCall( cudaMemcpy(d_InputKey, h_InputKey, N * sizeof(uint), cudaMemcpyHostToDevice) );
        cutilSafeCall( cudaMemcpy(d_InputVal, h_InputVal, N * sizeof(uint), cudaMemcpyHostToDevice) );

    int flag = 1;
    shrLog("Running GPU bitonic sort (%u identical iterations)...\n\n", numIterations);
        for(uint arrayLength = 64; arrayLength <= N; arrayLength *= 2){
            shrLog("Testing array length %u (%u arrays per batch)...\n", arrayLength, N / arrayLength);
                cutilSafeCall( cudaThreadSynchronize() );
                cutResetTimer(hTimer);
                cutStartTimer(hTimer);
                uint threadCount = 0;
                for(uint i = 0; i < numIterations; i++)
                    threadCount = bitonicSort(
                        d_OutputKey,
                        d_OutputVal,
                        d_InputKey,
                        d_InputVal,
                        N / arrayLength,
                        arrayLength,
                        DIR
                    );
                cutilSafeCall( cudaThreadSynchronize() );
                cutStopTimer(hTimer);
            shrLog("Average time: %f ms\n\n", cutGetTimerValue(hTimer) / numIterations);

            if (arrayLength == N)
            {
                double dTimeSecs = 1.0e-3 * cutGetTimerValue(hTimer) / numIterations; 
                shrLogEx(LOGBOTH | MASTER, 0, "sortingNetworks-bitonic, Throughput = %.4f MElements/s, Time = %.5f s, Size = %u elements, NumDevsUsed = %u, Workgroup = %u\n", 
                       (1.0e-6 * (double)arrayLength/dTimeSecs), dTimeSecs, arrayLength, 1, threadCount);
            }

            shrLog("\nValidating the results...\n");
                shrLog("...reading back GPU results\n");
                    cutilSafeCall( cudaMemcpy(h_OutputKeyGPU, d_OutputKey, N * sizeof(uint), cudaMemcpyDeviceToHost) );
                    cutilSafeCall( cudaMemcpy(h_OutputValGPU, d_OutputVal, N * sizeof(uint), cudaMemcpyDeviceToHost) );
                    int keysFlag = validateSortedKeys(h_OutputKeyGPU, h_InputKey, N / arrayLength, arrayLength, numValues, DIR);
                    int valuesFlag = validateValues(h_OutputKeyGPU, h_OutputValGPU, h_InputKey, N / arrayLength, arrayLength);
            flag = flag && keysFlag && valuesFlag;

            shrLog("\n");
        }
    shrLog( flag ? "PASSED\n\n" : "FAILED\n\n");

    shrLog("Shutting down...\n");
        cutilCheckError( cutDeleteTimer(hTimer) );
        cutilSafeCall( cudaFree(d_OutputVal) );
        cutilSafeCall( cudaFree(d_OutputKey) );
        cutilSafeCall( cudaFree(d_InputVal) );
        cutilSafeCall( cudaFree(d_InputKey) );
        free(h_OutputValGPU);
        free(h_OutputKeyGPU);
        free(h_InputVal);
        free(h_InputKey);

        cudaThreadExit();
        shrEXIT(argc, (const char**)argv);
}
