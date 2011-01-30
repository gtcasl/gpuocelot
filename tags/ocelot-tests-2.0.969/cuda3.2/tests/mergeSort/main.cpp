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



#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <cutil_inline.h>
#include "mergeSort_common.h"



////////////////////////////////////////////////////////////////////////////////
// Test driver
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv){
    uint 
        *h_SrcKey, *h_SrcVal, *h_DstKey, *h_DstVal;
    uint 
        *d_SrcKey, *d_SrcVal, *d_BufKey, *d_BufVal, *d_DstKey, *d_DstVal;
    uint hTimer;

    const uint   N = 4 * 1048576;
    const uint DIR = 1;

    const uint numValues = 65536;


    printf("Allocating and initializing host arrays...\n\n");
        cutCreateTimer(&hTimer);
        h_SrcKey = (uint *)malloc(N * sizeof(uint));
        h_SrcVal = (uint *)malloc(N * sizeof(uint));
        h_DstKey = (uint *)malloc(N * sizeof(uint));
        h_DstVal = (uint *)malloc(N * sizeof(uint));

        srand(2009);
        for(uint i = 0; i < N; i++)
            h_SrcKey[i] = rand() % numValues;
        fillValues(h_SrcVal, N);

    printf("Allocating and initializing CUDA arrays...\n\n");
        cutilSafeCall( cudaMalloc((void **)&d_DstKey, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_DstVal, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_BufKey, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_BufVal, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_SrcKey, N * sizeof(uint)) );
        cutilSafeCall( cudaMalloc((void **)&d_SrcVal, N * sizeof(uint)) );
        cutilSafeCall( cudaMemcpy(d_SrcKey, h_SrcKey, N * sizeof(uint), cudaMemcpyHostToDevice) );
        cutilSafeCall( cudaMemcpy(d_SrcVal, h_SrcVal, N * sizeof(uint), cudaMemcpyHostToDevice) );

    printf("Initializing GPU merge sort...\n");
        initMergeSort();

    printf("Running GPU merge sort...\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutResetTimer(hTimer);
        cutStartTimer(hTimer);
            mergeSort(
                d_DstKey,
                d_DstVal,
                d_BufKey,
                d_BufVal,
                d_SrcKey,
                d_SrcVal,
                N,
                DIR
            );
        cutilSafeCall( cudaThreadSynchronize() );
        cutStopTimer(hTimer);
    printf("Time: %f ms\n", cutGetTimerValue(hTimer));

    printf("Reading back GPU merge sort results...\n");
        cutilSafeCall( cudaMemcpy(h_DstKey, d_DstKey, N * sizeof(uint), cudaMemcpyDeviceToHost) );
        cutilSafeCall( cudaMemcpy(h_DstVal, d_DstVal, N * sizeof(uint), cudaMemcpyDeviceToHost) );

    printf("Inspecting the results...\n");
        uint keysFlag = validateSortedKeys(
            h_DstKey,
            h_SrcKey,
            1,
            N,
            numValues,
            DIR
        );

        uint valuesFlag = validateSortedValues(
            h_DstKey,
            h_DstVal,
            h_SrcKey,
            1,
            N
        );

    printf( (keysFlag && valuesFlag) ? "TEST PASSED\n" : "TEST FAILED\n");

    printf("Shutting down...\n");
        closeMergeSort();
        cutilCheckError( cutDeleteTimer(hTimer) );
        cutilSafeCall( cudaFree(d_SrcVal) );
        cutilSafeCall( cudaFree(d_SrcKey) );
        cutilSafeCall( cudaFree(d_BufVal) );
        cutilSafeCall( cudaFree(d_BufKey) );
        cutilSafeCall( cudaFree(d_DstVal) );
        cutilSafeCall( cudaFree(d_DstKey) );
        free(h_DstVal);
        free(h_DstKey);
        free(h_SrcVal);
        free(h_SrcKey);
        cudaThreadExit();
        cutilExit(argc, argv);
}
