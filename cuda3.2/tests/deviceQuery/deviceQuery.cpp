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

// utilities and system includes
#include <shrUtils.h>

// CUDA-C includes
#include <cuda_runtime_api.h>

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, const char** argv) 
{
    shrSetLogFileName ("deviceQuery.txt");
    shrLog("%s Starting...\n\n", argv[0]); 
    shrLog(" CUDA Device Query (Runtime API) version (CUDART static linking)\n\n");
        
    int deviceCount = 0;
	if (cudaGetDeviceCount(&deviceCount) != cudaSuccess) {
		shrLog("cudaGetDeviceCount FAILED CUDA Driver and Runtime version may be mismatched.\n");
		shrLog("\nFAILED\n");
		shrEXIT(argc, argv);
	}

    // This function call returns 0 if there are no CUDA capable devices.
    if (deviceCount == 0)
        shrLog("There is no device supporting CUDA\n");

    int dev;
	int driverVersion = 0, runtimeVersion = 0;     
    for (dev = 0; dev < deviceCount; ++dev) {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, dev);

        if (dev == 0) {
			// This function call returns 9999 for both major & minor fields, if no CUDA capable devices are present
            if (deviceProp.major == 9999 && deviceProp.minor == 9999)
                shrLog("There is no device supporting CUDA.\n");
            else if (deviceCount == 1)
                shrLog("There is 1 device supporting CUDA\n");
            else
                shrLog("There are %d devices supporting CUDA\n", deviceCount);
        }
        shrLog("\nDevice %d: \"%s\"\n", dev, deviceProp.name);

    #if CUDART_VERSION >= 2020
        // Console log
		cudaDriverGetVersion(&driverVersion);
		shrLog("  CUDA Driver Version:                           %d.%d\n", driverVersion/1000, driverVersion%100);
		cudaRuntimeGetVersion(&runtimeVersion);
		shrLog("  CUDA Runtime Version:                          %d.%d\n", runtimeVersion/1000, runtimeVersion%100);
    #endif
        shrLog("  CUDA Capability Major/Minor version number:    %d.%d\n", deviceProp.major, deviceProp.minor);

		char msg[256];
		sprintf(msg, "  Total amount of global memory:                 %llu bytes\n", (unsigned long long) deviceProp.totalGlobalMem);
		shrLog(msg);
    #if CUDART_VERSION >= 2000
        shrLog("  Multiprocessors x Cores/MP = Cores:            %d (MP) x %d (Cores/MP) = %d (Cores)\n", 
			deviceProp.multiProcessorCount,
			ConvertSMVer2Cores(deviceProp.major, deviceProp.minor),
			ConvertSMVer2Cores(deviceProp.major, deviceProp.minor) * deviceProp.multiProcessorCount);
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
        shrLog("  Clock rate:                                    %.2f GHz\n", deviceProp.clockRate * 1e-6f);
    #if CUDART_VERSION >= 2000
        shrLog("  Concurrent copy and execution:                 %s\n", deviceProp.deviceOverlap ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 2020
        shrLog("  Run time limit on kernels:                     %s\n", deviceProp.kernelExecTimeoutEnabled ? "Yes" : "No");
        shrLog("  Integrated:                                    %s\n", deviceProp.integrated ? "Yes" : "No");
        shrLog("  Support host page-locked memory mapping:       %s\n", deviceProp.canMapHostMemory ? "Yes" : "No");
        shrLog("  Compute mode:                                  %s\n", deviceProp.computeMode == cudaComputeModeDefault ?
			                                                            "Default (multiple host threads can use this device simultaneously)" :
		                                                                deviceProp.computeMode == cudaComputeModeExclusive ?
																		"Exclusive (only one host thread at a time can use this device)" :
		                                                                deviceProp.computeMode == cudaComputeModeProhibited ?
																		"Prohibited (no host thread can use this device)" :
																		"Unknown");
    #endif
    #if CUDART_VERSION >= 3000
        shrLog("  Concurrent kernel execution:                   %s\n", deviceProp.concurrentKernels ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 3010
        shrLog("  Device has ECC support enabled:                %s\n", deviceProp.ECCEnabled ? "Yes" : "No");
    #endif
    #if CUDART_VERSION >= 3020
		shrLog("  Device is using TCC driver mode:               %s\n", deviceProp.tccDriver ? "Yes" : "No");
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
	    sprintf_s(cTemp, 10, "%d.%d", driverVersion/1000, driverVersion%100);    
    #else
	    sprintf(cTemp, "%d.%d", driverVersion/1000, driverVersion%100);	
    #endif
    sProfileString +=  cTemp;
    
    // Runtime version
    sProfileString += ", CUDA Runtime Version = ";
    #ifdef WIN32
	    sprintf_s(cTemp, 10, "%d.%d", runtimeVersion/1000, runtimeVersion%100);
    #else
	    sprintf(cTemp, "%d.%d", runtimeVersion/1000, runtimeVersion%100);
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
    shrLog("\n\nPASSED\n");
    shrEXIT(argc, argv);
}
