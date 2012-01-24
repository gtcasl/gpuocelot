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

// includes, system
#include <iostream>
#include <math.h>

// includes, CUDA
#include <cuda.h>
#include <builtin_types.h>
#include <drvapi_error_string.h>

// includes, project
#include <sdkHelper.h>
#include <shrQATest.h>
#include "ptxjit.h"

////////////////////////////////////////////////////////////////////////////////
// These are CUDA Helper functions

// This will output the proper CUDA error strings in the event that a CUDA host call returns an error
#define checkCudaErrors(err)  __checkCudaErrors (err, __FILE__, __LINE__)

// These are the inline versions for all of the SDK helper functions
inline void __checkCudaErrors( CUresult err, const char *file, const int line )
{
    if( CUDA_SUCCESS != err) {
        fprintf(stderr, "checkCudaErrors() Driver API error = %04d \"%s\" from file <%s>, line %i.\n",
                err, getCudaDrvErrorString(err), file, line );
        exit(-1);
    }
}

inline int cudaDeviceInit(int ARGC, char ** ARGV) 
{
    int cuDevice = 0;
    int deviceCount = 0;
    CUresult err = cuInit(0);
    if (CUDA_SUCCESS == err)
        checkCudaErrors(cuDeviceGetCount(&deviceCount));
    if (deviceCount == 0) {
        fprintf(stderr, "cudaDeviceInit error: no devices supporting CUDA\n");
        exit(-1);
    }
    int dev = 0;
    dev = getCmdLineArgumentInt(ARGC, (const char **) ARGV, "device=");
    if (dev < 0) dev = 0;
    if (dev > deviceCount-1) {
		fprintf(stderr, "\n");
		fprintf(stderr, ">> %d CUDA capable GPU device(s) detected. <<\n", deviceCount);
        fprintf(stderr, ">> cudaDeviceInit (-device=%d) is not a valid GPU device. <<\n", dev);
		fprintf(stderr, "\n");
        return -dev;
    }
    checkCudaErrors(cuDeviceGet(&cuDevice, dev));
    char name[100];
    cuDeviceGetName(name, 100, cuDevice);
    if (checkCmdLineFlag(ARGC, (const char **) ARGV, "quiet") == false) {
       printf("> Using CUDA Device [%d]: %s\n", dev, name);
   	}
    return dev;
}

// This function returns the best GPU based on performance
inline int getMaxGflopsDeviceId()
{
    CUdevice current_device = 0, max_perf_device = 0;
    int device_count     = 0, sm_per_multiproc = 0;
    int max_compute_perf = 0, best_SM_arch     = 0;
    int major = 0, minor = 0, multiProcessorCount, clockRate;

    cuInit(0);
    checkCudaErrors(cuDeviceGetCount(&device_count));

	// Find the best major SM Architecture GPU device
	while ( current_device < device_count ) {
		checkCudaErrors( cuDeviceComputeCapability(&major, &minor, current_device ) );
		if (major > 0 && major < 9999) {
			best_SM_arch = MAX(best_SM_arch, major);
		}
		current_device++;
	}

    // Find the best CUDA capable GPU device
	current_device = 0;
	while( current_device < device_count ) {
		checkCudaErrors( cuDeviceGetAttribute( &multiProcessorCount, 
                                                CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, 
                                                current_device ) );
        checkCudaErrors( cuDeviceGetAttribute( &clockRate, 
                                                CU_DEVICE_ATTRIBUTE_CLOCK_RATE, 
                                                current_device ) );
		checkCudaErrors( cuDeviceComputeCapability(&major, &minor, current_device ) );

		if (major == 9999 && minor == 9999) {
		    sm_per_multiproc = 1;
		} else {
		    sm_per_multiproc = _ConvertSMVer2Cores(major, minor);
		}

		int compute_perf  = multiProcessorCount * sm_per_multiproc * clockRate;
		if( compute_perf  > max_compute_perf ) {
            // If we find GPU with SM major > 2, search only these
			if ( best_SM_arch > 2 ) {
				// If our device==dest_SM_arch, choose this, or else pass
				if (major == best_SM_arch) {	
                    max_compute_perf  = compute_perf;
                    max_perf_device   = current_device;
				}
			} else {
				max_compute_perf  = compute_perf;
				max_perf_device   = current_device;
			}
		}
		++current_device;
	}
	return max_perf_device;
}

// General initialization call to pick the best CUDA Device
inline CUdevice findCudaDevice(int argc, char **argv, int *p_devID)
{
    CUdevice cuDevice;
    int devID = 0;
    // If the command-line has a device number specified, use it
    if( checkCmdLineFlag(argc, (const char**)argv, "device") ) {
        devID = cudaDeviceInit(argc, argv);
        if (devID < 0) {
            printf("exiting...\n");
            exit(0);
        }
    } else {
        // Otherwise pick the device with highest Gflops/s
        char name[100];
        devID = getMaxGflopsDeviceId();
        checkCudaErrors(cuDeviceGet(&cuDevice, devID));
        cuDeviceGetName(name, 100, cuDevice);
        printf("> Using CUDA Device [%d]: %s\n", devID, name);
    }
    cuDeviceGet(&cuDevice, devID);
    if (p_devID) *p_devID = devID;
    return cuDevice;
}
// end of CUDA Helper Functions

CUresult initCUDA(int argc, char **argv, CUcontext *phContext, CUdevice *phDevice, CUmodule *phModule, CUfunction *phKernel)
{
    int major = 0, minor = 0, deviceID = 0;
    char deviceName[256];

    // Use command-line specified CUDA device, otherwise use device 0
    *phDevice = findCudaDevice(argc, argv, &deviceID);

    // Get compute capabilities and the device name
    checkCudaErrors(cuDeviceComputeCapability(&major, &minor, *phDevice));
    checkCudaErrors(cuDeviceGetName(deviceName, 256, *phDevice));
    printf("> Running on GPU device %d: %s\n", deviceID, deviceName);
    printf("> GPU device has SM %d.%d compute capability\n", major, minor);

    // Create context on the device
    checkCudaErrors(cuCtxCreate(phContext, 0, *phDevice));

    if (sizeof(void *)==4) {
       // Load the PTX from the string myPtx32
       printf("Loading myPtx32[] program\n");
       checkCudaErrors(cuModuleLoadDataEx(phModule, myPtx32, 0, 0, 0));
    } else {
       // Load the PTX from the string myPtx (64-bit)
       printf("Loading myPtx[] program\n");
       checkCudaErrors(cuModuleLoadDataEx(phModule, myPtx, 0, 0, 0));
    }

    // Locate the kernel entry poin
    checkCudaErrors(cuModuleGetFunction(phKernel, *phModule, "_Z8myKernelPi"));

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

    shrQAStart(argc, argv);

    // Initialize the device and get a handle to the kernel
    checkCudaErrors(initCUDA(argc, argv, &hContext, &hDevice, &hModule, &hKernel));

    // Allocate memory on host and device
    if ((h_data = (int *)malloc(memSize)) == NULL)
    {
        std::cerr << "Could not allocate host memory" << std::endl;
        exit(-1);
    }
    checkCudaErrors(cuMemAlloc(&d_data, memSize));

    // Set the kernel parameters
    checkCudaErrors(cuFuncSetBlockShape(hKernel, nThreads, 1, 1));
    int paramOffset = 0;
    checkCudaErrors(cuParamSetv(hKernel, paramOffset, &d_data, sizeof(d_data)));
    paramOffset += sizeof(d_data);
    checkCudaErrors(cuParamSetSize(hKernel, paramOffset));

    // Launch the kernel
    checkCudaErrors(cuLaunchGrid(hKernel, nBlocks, 1));
    std::cout << "CUDA kernel launched" << std::endl;
    
    // Copy the result back to the host
    checkCudaErrors(cuMemcpyDtoH(h_data, d_data, memSize));

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

    // Cleanup
    if (d_data)
    {
        checkCudaErrors(cuMemFree(d_data));
        d_data = 0;
    }
    if (h_data)
    {
        free(h_data);
        h_data = 0;
    }
    if (hModule)
    {
        checkCudaErrors(cuModuleUnload(hModule));
        hModule = 0;
    }
    if (hContext)
    {
        checkCudaErrors(cuCtxDestroy(hContext));
        hContext = 0;
    }

    shrQAFinishExit(argc, (const char **)argv, (dataGood ? QA_PASSED : QA_FAILED));
}
