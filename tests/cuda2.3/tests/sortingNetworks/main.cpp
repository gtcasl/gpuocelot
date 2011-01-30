/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation and 
 * any modifications thereto.  Any use, reproduction, disclosure, or distribution 
 * of this software and related documentation without an express license 
 * agreement from NVIDIA Corporation is strictly prohibited.
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



#include <stdio.h>
#include <stdlib.h>
#include <cutil_inline.h>
#include "sortingNetworks_common.h"



////////////////////////////////////////////////////////////////////////////////
// Helper function
////////////////////////////////////////////////////////////////////////////////
extern "C" uint factorRadix2(uint *log2L, uint L){
    if(!L){
        *log2L = 0;
        return 0;
    }else{
        for(*log2L = 0; (L & 1) == 0; L >>= 1, *log2L++);
        return L;
    }
}



////////////////////////////////////////////////////////////////////////////////
// Test driver
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv){
    printf("Starting up CUDA context...\n");
        if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
            cutilDeviceInit(argc, argv);
        else
            cudaSetDevice( cutGetMaxGflopsDeviceId() );

    uint *h_InputKey, *h_InputVal, *h_OutputKeyGPU, *h_OutputValGPU;
    uint *d_InputKey, *d_InputVal,    *d_OutputKey,    *d_OutputVal;
    uint hTimer;

    const uint             N = 65536;
    const uint           DIR = 1;
    const uint     numValues = 65536;
    const uint numIterations = 1;

    printf("Allocating and initializing host arrays...\n");
        cutCreateTimer(&hTimer);
        h_InputKey     = (uint *)malloc(N * sizeof(uint));
        h_InputVal     = (uint *)malloc(N * sizeof(uint));
        h_OutputKeyGPU = (uint *)malloc(N * sizeof(uint));
        h_OutputValGPU = (uint *)malloc(N * sizeof(uint));
        srand(2009);
        for(uint i = 0; i < N; i++)
            h_InputKey[i] = rand() % numValues;
        generateValuesFromKeys(h_InputVal, h_InputKey, N);

    printf("Allocating and initializing CUDA arrays...\n");
        cutilSafeCall( cudaMalloc((void **)&d_InputKey,  N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_InputVal,  N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_OutputKey, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_OutputVal, N * sizeof(uint)) );

    printf("Running GPU bitonic sort (%u identical iterations)...\n", numIterations);
        for(uint arrayLength = 64; arrayLength <= N; arrayLength *= 2){
            printf("Testing array length %u (%u arrays per batch)...\n", arrayLength, N / arrayLength);
            cutilSafeCall( cudaMemcpy(d_InputKey, h_InputKey, N * sizeof(uint), cudaMemcpyHostToDevice) );
            cutilSafeCall( cudaMemcpy(d_InputVal, h_InputVal, N * sizeof(uint), cudaMemcpyHostToDevice) );

            cutilSafeCall( cudaThreadSynchronize() );
            cutResetTimer(hTimer);
            cutStartTimer(hTimer);
            for(uint i = 0; i < numIterations; i++)
                bitonicSort(
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
            printf("\tAverage time: %f ms\n", cutGetTimerValue(hTimer) / numIterations);

            printf("\tReading back GPU results...\n");
            cutilSafeCall( cudaMemcpy(h_OutputKeyGPU, d_OutputKey, N * sizeof(uint), cudaMemcpyDeviceToHost) );
            cutilSafeCall( cudaMemcpy(h_OutputValGPU, d_OutputVal, N * sizeof(uint), cudaMemcpyDeviceToHost) );

            //Check if keys array is not corrupted and properly ordered
            printf("\tInspecting sorted results...\n");
            int keysFlag = validateSortedKeys(h_OutputKeyGPU, h_InputKey, N / arrayLength, arrayLength, numValues, DIR);
            //Check if values array is not corrupted
            int valuesFlag = validateValues(h_OutputValGPU, h_OutputKeyGPU, N);

            printf( (keysFlag || valuesFlag) ? "TEST PASSED\n" : "TEST FAILED\n");
        }


    printf("Shutting down...\n");
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
        cutilExit(argc, argv);
}
