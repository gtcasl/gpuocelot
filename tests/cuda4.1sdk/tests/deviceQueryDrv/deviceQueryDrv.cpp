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
#include <drvapi_error_string.h>

// utilities and system includes
#include <shrUtils.h>
#include <shrQATest.h>

// This function wraps the CUDA Driver API into a template function
template <class T>
inline void getCudaAttribute(T *attribute, CUdevice_attribute device_attribute, int device)
{
	CUresult error_result = cuDeviceGetAttribute( attribute, device_attribute, device );
    if (error_result != CUDA_SUCCESS) {
        shrLog( "cuDeviceGetAttribute returned %d\n-> %s\n", (int)error_result, getCudaDrvErrorString(error_result) );
		exit(0);
    }
}


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

    shrQAStart(argc, argv);

    // note your project will need to link with cuda.lib files on windows
    printf("CUDA Device Query (Driver API) statically linked version \n");

    CUresult error_id = cuInit(0);
    if (error_id != CUDA_SUCCESS) {
        printf("cuInit(0) returned %d\n-> %s\n", error_id, getCudaDrvErrorString(error_id));
        shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
    }

    error_id = cuDeviceGetCount(&deviceCount);
    if (error_id != CUDA_SUCCESS) {
        shrLog( "cuDeviceGetCount returned %d\n-> %s\n", (int)error_id, getCudaDrvErrorString(error_id) );
        shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
    }

    // This function call returns 0 if there are no CUDA capable devices.
    if (deviceCount == 0)
        printf("There are no available device(s) that support CUDA\n");
    else if (deviceCount == 1)
        printf("There is 1 device supporting CUDA\n");
    else
        printf("There are %d devices supporting CUDA\n", deviceCount);

    for (dev = 0; dev < deviceCount; ++dev) {
        error_id =  cuDeviceComputeCapability(&major, &minor, dev);
		if (error_id != CUDA_SUCCESS) {
			shrLog( "cuDeviceComputeCapability returned %d\n-> %s\n", (int)error_id, getCudaDrvErrorString(error_id) );
			shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
		}

        error_id = cuDeviceGetName(deviceName, 256, dev);
		if (error_id != CUDA_SUCCESS) {
			shrLog( "cuDeviceGetName returned %d\n-> %s\n", (int)error_id, getCudaDrvErrorString(error_id) );
			shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
		}

		printf("\nDevice %d: \"%s\"\n", dev, deviceName);

    #if CUDA_VERSION >= 2020
        int driverVersion = 0;
        cuDriverGetVersion(&driverVersion);
        printf("  CUDA Driver Version:                           %d.%d\n", driverVersion/1000, (driverVersion%100)/10);
    #endif
        shrLog("  CUDA Capability Major/Minor version number:    %d.%d\n", major, minor);

        size_t totalGlobalMem;
        error_id = cuDeviceTotalMem(&totalGlobalMem, dev);
		if (error_id != CUDA_SUCCESS) {
			shrLog( "cuDeviceTotalMem returned %d\n-> %s\n", (int)error_id, getCudaDrvErrorString(error_id) );
			shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
		}

        char msg[256];
        sprintf(msg, "  Total amount of global memory:                 %.0f MBytes (%llu bytes)\n",
                      (float)totalGlobalMem/1048576.0f, (unsigned long long) totalGlobalMem);
        shrLog(msg);

    #if CUDA_VERSION >= 2000
        int multiProcessorCount;
        getCudaAttribute<int>(&multiProcessorCount, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, dev);
        
        shrLog("  (%2d) Multiprocessors x (%2d) CUDA Cores/MP:     %d CUDA Cores\n",
                        multiProcessorCount, ConvertSMVer2Cores(major, minor),
                        ConvertSMVer2Cores(major, minor) * multiProcessorCount);
    #endif

        int clockRate;
        getCudaAttribute<int>(&clockRate, CU_DEVICE_ATTRIBUTE_CLOCK_RATE, dev);
        printf("  GPU Clock rate:                                %.2f GHz\n", clockRate * 1e-6f);
    #if CUDA_VERSION >= 4000
        int memoryClock;
        getCudaAttribute<int>( &memoryClock, CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE, dev );
        shrLog("  Memory Clock rate:                             %.2f Mhz\n", memoryClock * 1e-3f);
        int memBusWidth;
		getCudaAttribute<int>( &memBusWidth, CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH, dev );
        shrLog("  Memory Bus Width:                              %d-bit\n", memBusWidth);
        int L2CacheSize;
        getCudaAttribute<int>( &L2CacheSize, CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE, dev );
        if (L2CacheSize) {
            shrLog("  L2 Cache Size:                                 %d bytes\n", L2CacheSize);
        }

        int maxTex1D, maxTex2D[2], maxTex3D[3];
		getCudaAttribute<int>( &maxTex1D, CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH, dev );
		getCudaAttribute<int>( &maxTex2D[0], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH, dev );
		getCudaAttribute<int>( &maxTex2D[1], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT, dev );
		getCudaAttribute<int>( &maxTex3D[0], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH, dev );
		getCudaAttribute<int>( &maxTex3D[1], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT, dev );
		getCudaAttribute<int>( &maxTex3D[2], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH, dev );
        shrLog("  Max Texture Dimension Sizes                    1D=(%d) 2D=(%d,%d) 3D=(%d,%d,%d)\n",
                                                        maxTex1D, maxTex2D[0], maxTex2D[1], maxTex3D[0], maxTex3D[1], maxTex3D[2]);

        int  maxTex2DLayered[3];
        getCudaAttribute<int>( &maxTex2DLayered[0], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH, dev );
        getCudaAttribute<int>( &maxTex2DLayered[1], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT, dev );
        getCudaAttribute<int>( &maxTex2DLayered[2], CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS, dev );

        shrLog("  Max Layered Texture Size (dim) x layers        1D=(%d) x %d, 2D=(%d,%d) x %d\n",
                                                        maxTex2DLayered[0], maxTex2DLayered[2],
                                                        maxTex2DLayered[0], maxTex2DLayered[1], maxTex2DLayered[2]);
#endif

        int totalConstantMemory;
		getCudaAttribute<int>( &totalConstantMemory, CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, dev );
        printf("  Total amount of constant memory:               %u bytes\n", totalConstantMemory);
 	    int sharedMemPerBlock;
		getCudaAttribute<int>( &sharedMemPerBlock, CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, dev );
        printf("  Total amount of shared memory per block:       %u bytes\n", sharedMemPerBlock);
 	    int regsPerBlock;
		getCudaAttribute<int>( &regsPerBlock, CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, dev );
        printf("  Total number of registers available per block: %d\n", regsPerBlock);
 	    int warpSize;
		getCudaAttribute<int>( &warpSize, CU_DEVICE_ATTRIBUTE_WARP_SIZE, dev );
        printf("  Warp size:                                     %d\n",	warpSize);
 	    int maxThreadsPerBlock;
		getCudaAttribute<int>( &maxThreadsPerBlock, CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK, dev );
		printf("  Maximum number of threads per block:           %d\n",	maxThreadsPerBlock);
 	    int blockDim[3];
		getCudaAttribute<int>( &blockDim[0], CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X, dev );
		getCudaAttribute<int>( &blockDim[1], CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y, dev );
		getCudaAttribute<int>( &blockDim[2], CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z, dev );
        printf("  Maximum sizes of each dimension of a block:    %d x %d x %d\n", blockDim[0], blockDim[1], blockDim[2]);
 	    int gridDim[3];
		getCudaAttribute<int>( &gridDim[0], CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X, dev );
		getCudaAttribute<int>( &gridDim[1], CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y, dev );
		getCudaAttribute<int>( &gridDim[2], CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z, dev );
        printf("  Maximum sizes of each dimension of a grid:     %d x %d x %d\n", gridDim[0], gridDim[1], gridDim[2]);

        int textureAlign;
        getCudaAttribute<int>( &textureAlign, CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT, dev );
        printf("  Texture alignment:                             %u bytes\n", textureAlign);

        int memPitch;
		getCudaAttribute<int>( &memPitch, CU_DEVICE_ATTRIBUTE_MAX_PITCH, dev );
        printf("  Maximum memory pitch:                          %u bytes\n", memPitch);

    #if CUDA_VERSION >= 2000
        int gpuOverlap;
        getCudaAttribute<int>( &gpuOverlap, CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, dev );
    #endif
    #if CUDA_VERSION >= 4000
        int asyncEngineCount;
        getCudaAttribute<int>( &asyncEngineCount, CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT, dev );
        printf("  Concurrent copy and execution:                 %s with %d copy engine(s)\n", (gpuOverlap ? "Yes" : "No"), asyncEngineCount);
    #else
        printf("  Concurrent copy and execution:                 %s\n",gpuOverlap ? "Yes" : "No");
    #endif

    #if CUDA_VERSION >= 2020
        int kernelExecTimeoutEnabled;
        getCudaAttribute<int>( &kernelExecTimeoutEnabled, CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT, dev );
        printf("  Run time limit on kernels:                     %s\n", kernelExecTimeoutEnabled ? "Yes" : "No");
        int integrated;
        getCudaAttribute<int>( &integrated, CU_DEVICE_ATTRIBUTE_INTEGRATED, dev );
        printf("  Integrated GPU sharing Host Memory:            %s\n", integrated ? "Yes" : "No");
        int canMapHostMemory;
        getCudaAttribute<int>( &canMapHostMemory, CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY, dev );
        printf("  Support host page-locked memory mapping:       %s\n", canMapHostMemory ? "Yes" : "No");
    #endif

    #if CUDA_VERSION >= 3000
        int concurrentKernels;
        getCudaAttribute<int>( &concurrentKernels, CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS, dev );
        printf("  Concurrent kernel execution:                   %s\n", concurrentKernels ? "Yes" : "No");

        int surfaceAlignment;
        getCudaAttribute<int>( &surfaceAlignment, CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT, dev );
        printf("  Alignment requirement for Surfaces:            %s\n", surfaceAlignment ? "Yes" : "No");

        int eccEnabled;
        getCudaAttribute<int>( &eccEnabled,  CU_DEVICE_ATTRIBUTE_ECC_ENABLED, dev );
        printf("  Device has ECC support enabled:                %s\n", eccEnabled ? "Yes" : "No");
    #endif

    #if CUDA_VERSION >= 3020
        int tccDriver ;
        getCudaAttribute<int>( &tccDriver ,  CU_DEVICE_ATTRIBUTE_TCC_DRIVER, dev );
        printf("  Device is using TCC driver mode:               %s\n", tccDriver ? "Yes" : "No");
    #endif

    #if CUDA_VERSION >= 4000
        int unifiedAddressing;
        getCudaAttribute<int>( &unifiedAddressing, CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING, dev );
        printf("  Device supports Unified Addressing (UVA):      %s\n", unifiedAddressing ? "Yes" : "No");

        int pciBusID, pciDeviceID;
        getCudaAttribute<int>( &pciBusID, CU_DEVICE_ATTRIBUTE_PCI_BUS_ID, dev );
        getCudaAttribute<int>( &pciDeviceID, CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID, dev );
        printf("  Device PCI Bus ID / PCI location ID:           %d / %d\n", pciBusID, pciDeviceID );

        const char *sComputeMode[] = {
            "Default (multiple host threads can use ::cudaSetDevice() with device simultaneously)",
            "Exclusive (only one host thread in one process is able to use ::cudaSetDevice() with this device)",
            "Prohibited (no host thread can use ::cudaSetDevice() with this device)",
            "Exclusive Process (many threads in one process is able to use ::cudaSetDevice() with this device)",
            "Unknown",
            NULL
        };

        int computeMode;
        getCudaAttribute<int>( &computeMode, CU_DEVICE_ATTRIBUTE_COMPUTE_MODE, dev );
        printf("  Compute Mode:\n");
        printf("     < %s >\n", sComputeMode[computeMode]);
    #endif

    }
	shrQAFinishExit(argc, (const char **)argv, QA_PASSED);
}
