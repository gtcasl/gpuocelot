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

#include "FDTD3dGPU.h"

#include <iostream>
#include <algorithm>
#include <cutil_inline.h>
#include <shrUtils.h>
#include "FDTD3dGPUKernel.cuh"

bool getTargetDeviceGlobalMemSize(memsize_t *result, const int argc, const char **argv)
{
    bool ok = true;
    int               deviceCount  = 0;
    int               targetDevice = 0;
    size_t            memsize      = 0;
    cudaError         errnum       = cudaSuccess;

    // Get the number of CUDA enabled GPU devices
    if (ok)
    {
        shrLog(" cudaGetDeviceCount\n");
        errnum = cudaGetDeviceCount(&deviceCount);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaGetDeviceCount '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    // Select target device (device 0 by default)
    if (ok)
    {
        char *device = 0;
        if (shrGetCmdLineArgumentstr(argc, argv, "device", &device))
        {
            targetDevice = (unsigned int)atoi(device);
            if (targetDevice >= deviceCount)
            {
                shrLogEx(LOGBOTH | ERRORMSG, 0, "invalid target device specified on command line (device %d does not exist).\n", targetDevice);
                ok = false;
            }
        }
        else
        {
            targetDevice = cutGetMaxGflopsDeviceId();
        }
        if (device)
            free(device);
    }

    // Query target device for maximum memory allocation
    if (ok)
    {
        shrLog(" cudaGetDeviceProperties\n"); 
        struct cudaDeviceProp deviceProp;
        errnum = cudaGetDeviceProperties(&deviceProp, targetDevice);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaGetDeviceProperties '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
        memsize = deviceProp.totalGlobalMem;
    }

    // Save the result
    if (ok)
    {
        *result = (memsize_t)memsize;
    }

    return ok;
}

bool fdtdGPU(float *output, const float *input, const float *coeff, const int dimx, const int dimy, const int dimz, const int radius, const int timesteps, const int argc, const char **argv)
{
    bool ok = true;
    const int         outerDimx  = dimx + 2 * radius;
    const int         outerDimy  = dimy + 2 * radius;
    const int         outerDimz  = dimz + 2 * radius;
    const size_t      volumeSize = outerDimx * outerDimy * outerDimz;
    int               deviceCount  = 0;
    int               targetDevice = 0;
    float            *bufferOut    = 0;
    float            *bufferIn     = 0;
    dim3              dimBlock;
    dim3              dimGrid;
    cudaError errnum = cudaSuccess;

    // Ensure that the inner data starts on a 128B boundary
    const int padding = (128 / sizeof(float)) - radius;
    const size_t paddedVolumeSize = volumeSize + padding;

#ifdef GPU_PROFILING
    cudaEvent_t profileStart = 0;
    cudaEvent_t profileEnd   = 0;
    const int profileTimesteps = timesteps - 1;
    if (ok)
    {
        if (profileTimesteps < 1)
        {
            shrLog(" cannot profile with fewer than two timesteps (timesteps=%d), profiling is disabled.\n", timesteps);
        }
    }
#endif

    // Check the radius is valid
    if (ok)
    {
        if (radius != RADIUS)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "radius is invalid, must be %d - see kernel for details.\n", RADIUS);
            ok = false;
        }
    }

    // Get the number of CUDA enabled GPU devices
    if (ok)
    {
        shrLog(" cudaGetDeviceCount\n");
        errnum = cudaGetDeviceCount(&deviceCount);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaGetDeviceCount '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    // Select target device (device 0 by default)
    if (ok)
    {
        char *device = 0;
        if (shrGetCmdLineArgumentstr(argc, argv, "device", &device))
        {
            targetDevice = (unsigned int)atoi(device);
            if (targetDevice >= deviceCount)
            {
                shrLogEx(LOGBOTH | ERRORMSG, 0, "invalid target device specified on command line (device %d does not exist).\n", targetDevice);
                ok = false;
            }
        }
        else
        {
            targetDevice = cutGetMaxGflopsDeviceId();
        }
        shrLog(" cudaSetDevice (device %d)\n", targetDevice);
        errnum = cudaSetDevice(targetDevice);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaSetDevice '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
        if (device)
            free(device);
    }

    // Allocate memory buffers
    if (ok)
    {
        shrLog(" cudaMalloc bufferOut\n");
        errnum = cudaMalloc((void **)&bufferOut, paddedVolumeSize * sizeof(float));
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaMalloc '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }
    if (ok)
    {
        shrLog(" cudaMalloc bufferIn\n");
        errnum = cudaMalloc((void **)&bufferIn, paddedVolumeSize * sizeof(float));
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaMalloc '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    // Check for a command-line specified block size
    int userBlockSize;
    if (ok)
    {
        if (shrGetCmdLineArgumenti(argc, argv, "block-size", &userBlockSize))
        {
            // Constrain to a multiple of k_blockDimX
            userBlockSize = (userBlockSize / k_blockDimX * k_blockDimX);
            // Constrain within allowed bounds
            userBlockSize = CLAMP(userBlockSize, k_blockSizeMin, k_blockSizeMax);
        }
        else
        {
            userBlockSize = k_blockSizeMax;
        }
    }

    // Check the device limit on the number of threads
    if (ok)
    {
        shrLog(" cudaFuncGetAttributes\n"); 
        struct cudaFuncAttributes funcAttrib;
        errnum = cudaFuncGetAttributes(&funcAttrib, FiniteDifferencesKernel);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaFuncGetAttributes '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
        userBlockSize = MIN(userBlockSize, funcAttrib.maxThreadsPerBlock);
    }

    // Set the block size
    if (ok)
    {
        dimBlock.x = k_blockDimX;
        // Visual Studio 2005 does not like std::min
        //    dimBlock.y = std::min<size_t>(userBlockSize / k_blockDimX, (size_t)k_blockDimMaxY);
        dimBlock.y = ((userBlockSize / k_blockDimX) < (size_t)k_blockDimMaxY) ? (userBlockSize / k_blockDimX) : (size_t)k_blockDimMaxY;
        dimGrid.x  = (unsigned int)ceil((float)dimx / dimBlock.x);
        dimGrid.y  = (unsigned int)ceil((float)dimy / dimBlock.y);
        shrLog(" set block size to %dx%d\n", dimBlock.x, dimBlock.y);
        shrLog(" set grid size to %dx%d\n", dimGrid.x, dimGrid.y);
    }

    // Check the block size is valid
    if (ok)
    {
        if (dimBlock.x < RADIUS || dimBlock.y < RADIUS)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "invalid block size, x (%d) and y (%d) must be >= radius (%d).\n", dimBlock.x, dimBlock.y, RADIUS);
            ok = false;
        }
    }
    
    // Copy the input to the device input buffer
    if (ok)
    {
        shrLog(" cudaMemcpy (HostToDevice) bufferIn\n");
        errnum = cudaMemcpy(bufferIn + padding, input, volumeSize * sizeof(float), cudaMemcpyHostToDevice);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaMemcpy '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    // Copy the input to the device output buffer (actually only need the halo)
    if (ok)
    {
        shrLog(" cudaMemcpy (HostToDevice) bufferOut\n");
        errnum = cudaMemcpy(bufferOut + padding, input, volumeSize * sizeof(float), cudaMemcpyHostToDevice);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaMemcpy '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    // Copy the coefficients to the device coefficient buffer
    if (ok)
    {
        shrLog(" cudaMemcpyToSymbol (HostToDevice) stencil\n");
        errnum = cudaMemcpyToSymbol(stencil, (void *)coeff, (radius + 1) * sizeof(float));
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaMemcpyToSymbol '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

#ifdef GPU_PROFILING
    // Create the events
    if (ok)
    {
        shrLog(" cudaEventCreate\n");
        errnum = cudaEventCreate(&profileStart);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaEventCreate '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }
    if (ok)
    {
        shrLog(" cudaEventCreate\n");
        errnum = cudaEventCreate(&profileEnd);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaEventCreate '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }
#endif
    
    // Execute the FDTD
    float *bufferSrc = bufferIn + padding;
    float *bufferDst = bufferOut + padding;
    shrLog(" GPU FDTD loop\n");
    for (int it = 0 ; ok && it < timesteps ; it++)
    {
        shrLog("\tt = %d ", it);

#ifdef GPU_PROFILING
        // Enqueue start event
        if (ok && it == 1)
        {
            errnum = cudaEventRecord(profileStart, 0);
            if (errnum != cudaSuccess)
            {
                shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaEventRecord '%s'.\n", cudaGetErrorString(errnum));
                ok = false;
            }
        }
#endif

        // Launch the kernel
        if (ok)
        {
            shrLog("launch kernel\n");
            FiniteDifferencesKernel<<<dimGrid, dimBlock>>>(bufferDst, bufferSrc, dimx, dimy, dimz);
        }
        // Toggle the buffers
        // Visual Studio 2005 does not like std::swap
        //    std::swap<float *>(bufferSrc, bufferDst);
        float *tmp = bufferDst;
        bufferDst = bufferSrc;
        bufferSrc = tmp;
    }
    shrLog("\n");

#ifdef GPU_PROFILING
    // Enqueue end event
    if (ok)
    {
        errnum = cudaEventRecord(profileEnd, 0);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaEventRecord '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }
#endif

    // Wait for the kernel to complete
    if (ok)
    {
        shrLog(" cudaThreadSynchronize\n");
        errnum = cudaThreadSynchronize();
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaThreadSynchronize '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    // Read the result back, result is in bufferSrc (after final toggle)
    if (ok)
    {
        shrLog(" cudaMemcpy (DeviceToHost)\n");
        errnum = cudaMemcpy(output, bufferSrc, volumeSize * sizeof(float), cudaMemcpyDeviceToHost);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaMemcpy '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    // Report time
#ifdef GPU_PROFILING
    float elapsedTimeMS = 0;
    if (ok && profileTimesteps > 0)
    {
        shrLog(" cudaEventElapsedTime\n\n");
        errnum = cudaEventElapsedTime(&elapsedTimeMS, profileStart, profileEnd);
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaEventElapsedTime '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }
    if (ok && profileTimesteps > 0)
    {
        // Convert milliseconds to seconds
        double elapsedTime    = elapsedTimeMS * 1.0e-3;
        double avgElapsedTime = elapsedTime / (double)profileTimesteps;
        // Determine number of computations per timestep
        size_t pointsComputed = dimx * dimy * dimz;
        // Determine throughput
        double throughputM    = 1.0e-6 * (double)pointsComputed / avgElapsedTime;
        shrLogEx(LOGBOTH | MASTER, 0, "FDTD3d, Throughput = %.4f MPoints/s, Time = %.5f s, Size = %u Points, NumDevsUsed = %u, Blocksize = %u\n", 
            throughputM, avgElapsedTime, pointsComputed, 1, dimBlock.x * dimBlock.y); 
    }
#endif
    
    // Cleanup
    if (bufferIn)
        cudaFree(bufferIn);
    if (bufferOut)
        cudaFree(bufferOut);
#ifdef GPU_PROFILING
    if (profileStart)
        cudaEventDestroy(profileStart);
    if (profileEnd)
        cudaEventDestroy(profileEnd);
#endif

    if (ok)
    {
        shrLog("\n cudaThreadExit\n");
        errnum = cudaThreadExit();
        if (errnum != cudaSuccess)
        {
            shrLogEx(LOGBOTH | ERRORMSG, 0, "cudaThreadExit '%s'.\n", cudaGetErrorString(errnum));
            ok = false;
        }
    }

    return ok;
}
