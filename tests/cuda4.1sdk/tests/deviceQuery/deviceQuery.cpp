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
/* This sample queries the properties of the CUDA devices present in the system via CUDA Runtime API. */

// Shared Utilities (QA Testing)
#include <shrUtils.h>
#include <shrQATest.h>

// std::system includes
#include <memory>
#include <iostream>

// CUDA-C includes
#include <cuda.h>
#include <cuda_runtime_api.h>

int *pArgc = NULL;
char **pArgv = NULL;

// This function wraps the CUDA Driver API into a template function
template <class T>
inline void getCudaAttribute(T *attribute, CUdevice_attribute device_attribute, int device)
{
    CUresult error = 	cuDeviceGetAttribute( attribute, device_attribute, device );

    if( CUDA_SUCCESS != error) {
        fprintf(stderr, "cuSafeCallNoSync() Driver API error = %04d from file <%s>, line %i.\n",
                error, __FILE__, __LINE__);
        exit(-1);
    }
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
	pArgc = &argc;
	pArgv = argv;

    shrQAStart(argc, argv);

    shrSetLogFileName ("deviceQuery.txt");
    shrLog("%s Starting...\n\n", argv[0]); 
    shrLog(" CUDA Device Query (Runtime API) version (CUDART static linking)\n\n");
        
    int deviceCount = 0;
    cudaError_t error_id = cudaGetDeviceCount(&deviceCount);
    if (error_id != cudaSuccess) {
        shrLog( "cudaGetDeviceCount returned %d\n-> %s\n", (int)error_id, cudaGetErrorString(error_id) );
        shrQAFinishExit(*pArgc, (const char **)pArgv, QA_FAILED);
    }
    // This function call returns 0 if there are no CUDA capable devices.
    if (deviceCount == 0)
        shrLog("There is no device supporting CUDA\n");
    else
        shrLog("Found %d CUDA Capable device(s)\n", deviceCount);

    int dev, driverVersion = 0, runtimeVersion = 0;     
    for (dev = 0; dev < deviceCount; ++dev) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, dev);

        shrLog("\nDevice %d: \"%s\"\n", dev, deviceProp.name);

    #if CUDART_VERSION >= 2020
        // Console log
        cudaDriverGetVersion(&driverVersion);
        cudaRuntimeGetVersion(&runtimeVersion);
        shrLog("  CUDA Driver Version / Runtime Version          %d.%d / %d.%d\n", driverVersion/1000, (driverVersion%100)/10, runtimeVersion/1000, (runtimeVersion%100)/10);
    #endif
        shrLog("  CUDA Capability Major/Minor version number:    %d.%d\n", deviceProp.major, deviceProp.minor);

        char msg[256];
        sprintf(msg, "  Total amount of global memory:                 %.0f MBytes (%llu bytes)\n", 
                      (float)deviceProp.totalGlobalMem/1048576.0f, (unsigned long long) deviceProp.totalGlobalMem);
        shrLog(msg);
    #if CUDART_VERSION >= 2000
        shrLog("  (%2d) Multiprocessors x (%2d) CUDA Cores/MP:     %d CUDA Cores\n", 
			deviceProp.multiProcessorCount,
			ConvertSMVer2Cores(deviceProp.major, deviceProp.minor),
			ConvertSMVer2Cores(deviceProp.major, deviceProp.minor) * deviceProp.multiProcessorCount);
    #endif
        shrLog("  GPU Clock Speed:                               %.2f GHz\n", deviceProp.clockRate * 1e-6f);
    #if CUDART_VERSION >= 4000
	// This is not available in the CUDA Runtime API, so we make the necessary calls the driver API to support this for output
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

        shrLog("  Max Texture Dimension Size (x,y,z)             1D=(%d), 2D=(%d,%d), 3D=(%d,%d,%d)\n",
                                                        deviceProp.maxTexture1D, deviceProp.maxTexture2D[0], deviceProp.maxTexture2D[1],
                                                        deviceProp.maxTexture3D[0], deviceProp.maxTexture3D[1], deviceProp.maxTexture3D[2]);
        shrLog("  Max Layered Texture Size (dim) x layers        1D=(%d) x %d, 2D=(%d,%d) x %d\n",
                                                        deviceProp.maxTexture1DLayered[0], deviceProp.maxTexture1DLayered[1],
                                                        deviceProp.maxTexture2DLayered[0], deviceProp.maxTexture2DLayered[1], deviceProp.maxTexture2DLayered[2]);
    #endif
        shrLog("  Total amount of constant memory:               %u bytes\n", deviceProp.totalConstMem); 
        shrLog("  Total amount of shared memory per block:       %u bytes\n", deviceProp.sharedMemPerBlock);
        shrLog("  Total number of registers available per block: %d\n", deviceProp.regsPerBlock);
        shrLog("  Warp size:                                     %d\n", deviceProp.warpSize);
        shrLog("  Maximum number of threads per block:           %d\n", deviceProp.maxThreadsPerBlock);
        shrLog("  Maximum sizes of each dimension of a block:    %d x %d x %d\n",
               deviceProp.maxThreadsDim[0],
               deviceProp.maxThreadsDim[1],
               deviceProp.maxThreadsDim[2]);
        shrLog("  Maximum sizes of each dimension of a grid:     %d x %d x %d\n",
               deviceProp.maxGridSize[0],
               deviceProp.maxGridSize[1],
               deviceProp.maxGridSize[2]);
        shrLog("  Maximum memory pitch:                          %u bytes\n", deviceProp.memPitch);
		shrLog("  Texture alignment:                             %u bytes\n", deviceProp.textureAlignment);

    #if CUDART_VERSION >= 4000
        shrLog("  Concurrent copy and execution:                 %s with %d copy engine(s)\n", (deviceProp.deviceOverlap ? "Yes" : "No"), deviceProp.asyncEngineCount);
    #else
        shrLog("  Concurrent copy and execution:                 %s\n", deviceProp.deviceOverlap ? "Yes" : "No");
    #endif

    #if CUDART_VERSION >= 2020
        shrLog("  Run time limit on kernels:                     %s\n", deviceProp.kernelExecTimeoutEnabled ? "Yes" : "No");
        shrLog("  Integrated GPU sharing Host Memory:            %s\n", deviceProp.integrated ? "Yes" : "No");
        shrLog("  Support host page-locked memory mapping:       %s\n", deviceProp.canMapHostMemory ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 3000
        shrLog("  Concurrent kernel execution:                   %s\n", deviceProp.concurrentKernels ? "Yes" : "No");
        shrLog("  Alignment requirement for Surfaces:            %s\n", deviceProp.surfaceAlignment ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 3010
        shrLog("  Device has ECC support enabled:                %s\n", deviceProp.ECCEnabled ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 3020
        shrLog("  Device is using TCC driver mode:               %s\n", deviceProp.tccDriver ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 4000
        shrLog("  Device supports Unified Addressing (UVA):      %s\n", deviceProp.unifiedAddressing ? "Yes" : "No");
        shrLog("  Device PCI Bus ID / PCI location ID:           %d / %d\n", deviceProp.pciBusID, deviceProp.pciDeviceID );
    #endif

    #if CUDART_VERSION >= 2020
        const char *sComputeMode[] = {
            "Default (multiple host threads can use ::cudaSetDevice() with device simultaneously)",
            "Exclusive (only one host thread in one process is able to use ::cudaSetDevice() with this device)",
            "Prohibited (no host thread can use ::cudaSetDevice() with this device)",
            "Exclusive Process (many threads in one process is able to use ::cudaSetDevice() with this device)",
            "Unknown",
            NULL
        };
        shrLog("  Compute Mode:\n");
        shrLog("     < %s >\n", sComputeMode[deviceProp.computeMode]);
    #endif
    }

    // csv masterlog info
    // *****************************
    // exe and CUDA driver name 
    shrLog("\n");    
    std::string sProfileString = "deviceQuery, CUDA Driver = CUDART";        
    char cTemp[10];
    
    // driver version
    sProfileString += ", CUDA Driver Version = ";
    #ifdef WIN32
	    sprintf_s(cTemp, 10, "%d.%d", driverVersion/1000, (driverVersion%100)/10);
    #else
	    sprintf(cTemp, "%d.%d", driverVersion/1000, (driverVersion%100)/10);
    #endif
    sProfileString +=  cTemp;
    
    // Runtime version
    sProfileString += ", CUDA Runtime Version = ";
    #ifdef WIN32
	    sprintf_s(cTemp, 10, "%d.%d", runtimeVersion/1000, (runtimeVersion%100)/10);
    #else
	    sprintf(cTemp, "%d.%d", runtimeVersion/1000, (runtimeVersion%100)/10);
    #endif
    sProfileString +=  cTemp;  
    
    // Device count      
    sProfileString += ", NumDevs = ";
    #ifdef WIN32
        sprintf_s(cTemp, 10, "%d", deviceCount);
    #else
        sprintf(cTemp, "%d", deviceCount);
    #endif
    sProfileString += cTemp;
    
    // First 2 device names, if any
    for (dev = 0; dev < ((deviceCount > 2) ? 2 : deviceCount); ++dev) 
    {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, dev);
        sProfileString += ", Device = ";
        sProfileString += deviceProp.name;
    }
    sProfileString += "\n";
    shrLogEx(LOGBOTH | MASTER, 0, sProfileString.c_str());

    // finish
	shrQAFinishExit(argc, (const char **)argv, QA_PASSED);
}
