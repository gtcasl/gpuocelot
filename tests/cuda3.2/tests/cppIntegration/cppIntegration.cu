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

/* Example of integrating CUDA functions into an existing 
 * application / framework.
 * Host part of the device code.
 * Compiled with Cuda compiler.
 */

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include <cutil_inline.h>

// includes, kernels
#include <cppIntegration_kernel.cu>
//
////////////////////////////////////////////////////////////////////////////////
// declaration, forward

extern "C" void
computeGold(char* reference, char* idata, const unsigned int len);
extern "C" void
computeGold2(int2* reference, int2* idata, const unsigned int len);

////////////////////////////////////////////////////////////////////////////////
//! Entry point for Cuda functionality on host side
//! @param argc  command line argument count
//! @param argv  command line arguments
//! @param data  data to process on the device
//! @param len   len of \a data
////////////////////////////////////////////////////////////////////////////////
extern "C" void
runTest(const int argc, const char** argv, char* data, int2* data_int2, unsigned int len)
{

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, (char**)argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    const unsigned int num_threads = len / 4;
    cutilCondition(0 == (len % 4));
    const unsigned int mem_size = sizeof(char) * len;
    const unsigned int mem_size_int2 = sizeof(int2) * len;

    // allocate device memory
    char* d_data;
    cutilSafeCall(cudaMalloc((void**) &d_data, mem_size));
    // copy host memory to device
    cutilSafeCall(cudaMemcpy(d_data, data, mem_size,
                            cudaMemcpyHostToDevice) );
    // allocate device memory for int2 version
    int2* d_data_int2;
    cutilSafeCall(cudaMalloc((void**) &d_data_int2, mem_size_int2));
    // copy host memory to device
    cutilSafeCall(cudaMemcpy(d_data_int2, data_int2, mem_size_int2,
                            cudaMemcpyHostToDevice) );

    // setup execution parameters
    dim3 grid(1, 1, 1);
    dim3 threads(num_threads, 1, 1);
    dim3 threads2(len, 1, 1); // more threads needed fir separate int2 version
    // execute the kernel
    kernel<<< grid, threads >>>((int*) d_data);
    kernel2<<< grid, threads2 >>>(d_data_int2);

    // check if kernel execution generated and error
    cutilCheckMsg("Kernel execution failed");

    // compute reference solutions
    char* reference = (char*) malloc(mem_size);
    computeGold(reference, data, len);
    int2* reference2 = (int2*) malloc(mem_size_int2);
    computeGold2(reference2, data_int2, len);

    // copy results from device to host
    cutilSafeCall(cudaMemcpy(data, d_data, mem_size,
                            cudaMemcpyDeviceToHost));
    cutilSafeCall(cudaMemcpy(data_int2, d_data_int2, mem_size_int2,
                            cudaMemcpyDeviceToHost));

    // check result
    bool success = true;
    for(unsigned int i = 0; i < len; i++ )
    {
        if( reference[i] != data[i] || 
	    reference2[i].x != data_int2[i].x || 
	    reference2[i].y != data_int2[i].y)
            success = false;
    }
    printf("%s\n", success ? "PASSED" : "FAILED");

    // cleanup memory
    cutilSafeCall(cudaFree(d_data));
    cutilSafeCall(cudaFree(d_data_int2));
    free(reference);
    free(reference2);

    cudaThreadExit();
}
