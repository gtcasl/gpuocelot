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

#include <cuda.h>
#include <iostream>
#include "cutil_inline.h"

#include "ptxjit.h"

CUresult initCUDA(int argc, char **argv, CUcontext *phContext, CUdevice *phDevice, CUmodule *phModule, CUfunction *phKernel)
{
    int major = 0, minor = 0, deviceID = 0;
    char deviceName[256];

    // Use command-line specified CUDA device, otherwise use device 0
    *phDevice = cutilChooseCudaDeviceDrv(argc, argv, &deviceID);

    // Get compute capabilities and the device name
    cutilDrvSafeCallNoSync(cuDeviceComputeCapability(&major, &minor, *phDevice));
    cutilDrvSafeCallNoSync(cuDeviceGetName(deviceName, 256, *phDevice));
    printf("> Running on GPU device %d: %s\n", deviceID, deviceName);
    printf("> GPU device has SM %d.%d compute capability\n", major, minor);

    // Create context on the device
    cutilDrvSafeCall(cuCtxCreate(phContext, 0, *phDevice));

    if (sizeof(void *)==4) {
       // Load the PTX from the string myPtx32
       printf("Loading myPtx32[] program\n");
       cutilDrvSafeCall(cuModuleLoadDataEx(phModule, myPtx32, 0, 0, 0));
    } else {
       // Load the PTX from the string myPtx (64-bit)
       printf("Loading myPtx[] program\n");
       cutilDrvSafeCall(cuModuleLoadDataEx(phModule, myPtx, 0, 0, 0));
    }

    // Locate the kernel entry point
    cutilDrvSafeCall(cuModuleGetFunction(phKernel, *phModule, "_Z8myKernelPi"));

    return CUDA_SUCCESS;
}

int main(int argc, char **argv)
{
    const unsigned int nThreads = 256;
    const unsigned int nBlocks  = 64;
    const size_t memSize = nThreads * nBlocks * sizeof(int);

    CUcontext    hContext = 0;
    CUdevice     hDevice  = 0;
    CUmodule     hModule  = 0;
    CUfunction   hKernel  = 0;
    CUdeviceptr  d_data   = 0;
    int         *h_data   = 0;

    // Initialize the device and get a handle to the kernel
    cutilDrvSafeCall(initCUDA(argc, argv, &hContext, &hDevice, &hModule, &hKernel));

    // Allocate memory on host and device
    if ((h_data = (int *)malloc(memSize)) == NULL)
    {
        std::cerr << "Could not allocate host memory" << std::endl;
        exit(-1);
    }
    cutilDrvSafeCall(cuMemAlloc(&d_data, memSize));

    // Set the kernel parameters
    cutilDrvSafeCall(cuFuncSetBlockShape(hKernel, nThreads, 1, 1));
    int paramOffset = 0;
    cutilDrvSafeCall(cuParamSetv(hKernel, paramOffset, &d_data, sizeof(d_data)));
    paramOffset += sizeof(d_data);
    cutilDrvSafeCall(cuParamSetSize(hKernel, paramOffset));

    // Launch the kernel
    cutilDrvSafeCall(cuLaunchGrid(hKernel, nBlocks, 1));
    std::cout << "CUDA kernel launched" << std::endl;
    
    // Copy the result back to the host
    cutilDrvSafeCall(cuMemcpyDtoH(h_data, d_data, memSize));

    // Check the result
    bool dataGood = true;
    for (unsigned int i = 0 ; dataGood && i < nBlocks * nThreads ; i++)
    {
        if (h_data[i] != (int)i)
        {
            std::cerr << "Error at " << i << std::endl;
            dataGood = false;
        }
    }
    if (dataGood)
    {
        std::cout << "PASSED" << std::endl;
    }
    else
    {
        std::cout << "FAILED" << std::endl;
    }

    // Cleanup
    if (d_data)
    {
        cutilDrvSafeCall(cuMemFree(d_data));
        d_data = 0;
    }
    if (h_data)
    {
        free(h_data);
        h_data = 0;
    }
    if (hModule)
    {
        cutilDrvSafeCall(cuModuleUnload(hModule));
        hModule = 0;
    }
    if (hContext)
    {
        cutilDrvSafeCall(cuCtxDestroy(hContext));
        hContext = 0;
    }

    cutilExit(argc,argv);
    return 0;
}
