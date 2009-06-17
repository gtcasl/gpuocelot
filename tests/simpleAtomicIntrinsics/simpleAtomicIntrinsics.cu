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

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( dev = cutGetMaxGflopsDeviceId() );

    cutilSafeCall( cudaChooseDevice(&dev, &deviceProp) );
    cutilSafeCall( cudaGetDeviceProperties(&deviceProp, dev) );

    if(deviceProp.major > 1 || deviceProp.minor > 0)
    {
        printf("Using Device %d: \"%s\"\n", dev, deviceProp.name);
    }
    else
    {
        printf("There is no device supporting CUDA compute capability 1.1.\n");
        printf("TEST PASSED");
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

    //compute reference solution
    if(computeGold(h_odata, numThreads * numBlocks))
        printf("Test PASSED\n");
    else
        printf("Test FAILED\n");

    // cleanup memory
    free(h_odata);
    cutilSafeCall(cudaFree(d_odata));

    cudaThreadExit();
}
