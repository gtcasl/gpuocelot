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

/* A simple program demonstrating trivial use of global memory atomic 
   device functions (atomic*() functions).
*/

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include "cutil_inline.h"

// includes, kernels
#include "simpleAtomicIntrinsics_kernel.cu"

static char *sSDKsample = "[simpleAtomicIntrinsics]\0";

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest( int argc, char** argv);

extern "C"
int computeGold( int* gpuData, const int len);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    runTest( argc, argv);

    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runTest( int argc, char **argv)
{
    cudaDeviceProp deviceProp;
    deviceProp.major = 0;
    deviceProp.minor = 0;
    int dev;

	printf("%s\n", sSDKsample);

    // This will pick the best possible CUDA capable device
    dev = cutilChooseCudaDevice(argc, argv);

    cutilSafeCall( cudaGetDeviceProperties(&deviceProp, dev) );

    // Statistics about the GPU device
    printf("> GPU device has %d Multi-Processors, SM %d.%d compute capabilities\n\n", 
		deviceProp.multiProcessorCount, deviceProp.major, deviceProp.minor);

    int version = (deviceProp.major * 0x10 + deviceProp.minor);

    if(version < 0x11) 
    {
        printf("%s: requires a minimum CUDA compute 1.1 capability\n", sSDKsample);
        printf("PASSED");
        cudaThreadExit();
        cutilExit(argc, argv);
    }

    unsigned int timer = 0;
    cutilCheckError( cutCreateTimer( &timer));
    cutilCheckError( cutStartTimer( timer));

    unsigned int numThreads = 256;
    unsigned int numBlocks = 64;
    unsigned int numData = 11;
    unsigned int memSize = sizeof(int) * numData;

    //allocate mem for the result on host side
    int *h_odata = (int *)malloc(memSize);

    //initalize the memory
    for(unsigned int i = 0; i < numData; i++)
        h_odata[i] = 0;

    //To make the AND and XOR tests generate something other than 0...
    h_odata[8] = h_odata[10] = 0xff; 

    // allocate device memory for result
    int *d_odata;
    cutilSafeCall( cudaMalloc( (void**) &d_odata, memSize));
    // copy host memory to device to initialize to zers
    cutilSafeCall( cudaMemcpy( d_odata, h_odata, memSize, cudaMemcpyHostToDevice) );


    // execute the kernel
    testKernel<<<numBlocks, numThreads>>>(d_odata);
    cutilCheckMsg("Kernel execution failed");
    //Copy result from device to host
    cutilSafeCall( cudaMemcpy( h_odata, d_odata, memSize, cudaMemcpyDeviceToHost) );

    cutilCheckError( cutStopTimer( timer));
    printf( "Processing time: %f (ms)\n", cutGetTimerValue( timer));
    cutilCheckError( cutDeleteTimer( timer));

	printf("\n%s - Test Summary\n", sSDKsample);

    //compute reference solution
    if(computeGold(h_odata, numThreads * numBlocks))
        printf("PASSED\n");
    else
        printf("FAILED\n");

    // cleanup memory
    free(h_odata);
    cutilSafeCall(cudaFree(d_odata));

    cudaThreadExit();
}
