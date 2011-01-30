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

/* This sample queries the properties of the CUDA devices present in the system. */

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <cuda.h>

#include <cutil.h>

// utilities and system includes
#include <shrUtils.h>


////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
	CUdevice dev;
	int major = 0, minor = 0;
	int deviceCount = 0;
	char deviceName[256];

	// note your project will need to link with cuda.lib files on windows
	printf("CUDA Device Query (Driver API) statically linked version \n");

	CUresult err = cuInit(0);
    CU_SAFE_CALL_NO_SYNC(cuDeviceGetCount(&deviceCount));
	// This function call returns 0 if there are no CUDA capable devices.
	if (deviceCount == 0) {
        printf("There is no device supporting CUDA\n");
	}
    for (dev = 0; dev < deviceCount; ++dev) {
		CU_SAFE_CALL_NO_SYNC( cuDeviceComputeCapability(&major, &minor, dev) );

        if (dev == 0) {
			// This function call returns 9999 for both major & minor fields, if no CUDA capable devices are present
            if (major == 9999 && minor == 9999)
                printf("There is no device supporting CUDA.\n");
            else if (deviceCount == 1)
                printf("There is 1 device supporting CUDA\n");
            else
                printf("There are %d devices supporting CUDA\n", deviceCount);
        }
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetName(deviceName, 256, dev) );
        printf("\nDevice %d: \"%s\"\n", dev, deviceName);

    #if CUDA_VERSION >= 2020
		int driverVersion = 0;
		cuDriverGetVersion(&driverVersion);
		printf("  CUDA Driver Version:                           %d.%d\n", driverVersion/1000, driverVersion%100);
    #endif
        shrLog("  CUDA Capability Major/Minor version number:    %d.%d\n", major, minor);

		size_t totalGlobalMem;
		CU_SAFE_CALL_NO_SYNC( cuDeviceTotalMem(&totalGlobalMem, dev) );
        printf("  Total amount of global memory:                 %llu bytes\n", (unsigned long long)totalGlobalMem);

    #if CUDA_VERSION >= 2000
	    int multiProcessorCount;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &multiProcessorCount, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, dev ) );
        shrLog("  Multiprocessors x Cores/MP = Cores:            %d (MP) x %d (Cores/MP) = %d (Cores)\n", 
			     multiProcessorCount, ConvertSMVer2Cores(major, minor), 
				 ConvertSMVer2Cores(major, minor) * multiProcessorCount);
	#endif

 	    int totalConstantMemory;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &totalConstantMemory, CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, dev ) );
        printf("  Total amount of constant memory:               %u bytes\n", totalConstantMemory);
 	    int sharedMemPerBlock;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &sharedMemPerBlock, CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, dev ) );
        printf("  Total amount of shared memory per block:       %u bytes\n", sharedMemPerBlock);
 	    int regsPerBlock;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &regsPerBlock, CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, dev ) );
        printf("  Total number of registers available per block: %d\n", regsPerBlock);
 	    int warpSize;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &warpSize, CU_DEVICE_ATTRIBUTE_WARP_SIZE, dev ) );
        printf("  Warp size:                                     %d\n",	warpSize);
 	    int maxThreadsPerBlock;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &maxThreadsPerBlock, CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK, dev ) );
		printf("  Maximum number of threads per block:           %d\n",	maxThreadsPerBlock);
 	    int blockDim[3];
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &blockDim[0], CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X, dev ) );
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &blockDim[1], CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y, dev ) );
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &blockDim[2], CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z, dev ) );
        printf("  Maximum sizes of each dimension of a block:    %d x %d x %d\n", blockDim[0], blockDim[1], blockDim[2]);
 	    int gridDim[3];
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &gridDim[0], CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X, dev ) );
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &gridDim[1], CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y, dev ) );
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &gridDim[2], CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z, dev ) );
        printf("  Maximum sizes of each dimension of a grid:     %d x %d x %d\n", gridDim[0], gridDim[1], gridDim[2]);
  	    int memPitch;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &memPitch, CU_DEVICE_ATTRIBUTE_MAX_PITCH, dev ) );
        printf("  Maximum memory pitch:                          %u bytes\n", memPitch);
  	    int textureAlign;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &textureAlign, CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT, dev ) );
        printf("  Texture alignment:                             %u bytes\n", textureAlign);
  	    int clockRate;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &clockRate, CU_DEVICE_ATTRIBUTE_CLOCK_RATE, dev ) );
        printf("  Clock rate:                                    %.2f GHz\n", clockRate * 1e-6f);
    #if CUDA_VERSION >= 2000
	    int gpuOverlap;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &gpuOverlap, CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, dev ) );
        printf("  Concurrent copy and execution:                 %s\n",gpuOverlap ? "Yes" : "No");
    #endif

    #if CUDA_VERSION >= 2020
	    int kernelExecTimeoutEnabled;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &kernelExecTimeoutEnabled, CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT, dev ) );
        printf("  Run time limit on kernels:                     %s\n", kernelExecTimeoutEnabled ? "Yes" : "No");
	    int integrated;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &integrated, CU_DEVICE_ATTRIBUTE_INTEGRATED, dev ) );
        printf("  Integrated:                                    %s\n", integrated ? "Yes" : "No");
	    int canMapHostMemory;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &canMapHostMemory, CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY, dev ) );
        printf("  Support host page-locked memory mapping:       %s\n", canMapHostMemory ? "Yes" : "No");
    #endif

    #if CUDA_VERSION >= 3000
	    int concurrentKernels;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &concurrentKernels, CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS, dev ) );
        printf("  Concurrent kernel execution:                   %s\n", concurrentKernels ? "Yes" : "No");
	    int eccEnabled;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &eccEnabled,  CU_DEVICE_ATTRIBUTE_ECC_ENABLED, dev ) );
        printf("  Device has ECC support enabled:                %s\n", eccEnabled ? "Yes" : "No");
    #endif

    #if CUDA_VERSION >= 3020
	    int tccDriver ;
		CU_SAFE_CALL_NO_SYNC( cuDeviceGetAttribute( &tccDriver ,  CU_DEVICE_ATTRIBUTE_TCC_DRIVER, dev ) );
		printf("  Device is using TCC driver mode:               %s\n", tccDriver ? "Yes" : "No");
    #endif
	}
    printf("\nPASSED\n");
    CUT_EXIT(argc, argv);
}
