/*
 * Copyright 1993-2011 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

/*
 * This application demonstrates how to use the CUDA API to use multiple GPUs,
 * with an emphasis on simple illustration of the techniques (not on performance).
 *
 * Note that in order to detect multiple GPUs in your system you have to disable
 * SLI in the nvidia control panel. Otherwise only one GPU is visible to the 
 * application. On the other side, you can still extend your desktop to screens 
 * attached to both GPUs.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes
#include <sdkHelper.h>
#include <shrQATest.h>
#include <shrUtils.h>

#include <cuda_runtime_api.h>

#include "simpleMultiGPU.h"

////////////////////////////////////////////////////////////////////////////////
// These are CUDA Helper functions

// This will output the proper CUDA error strings in the event that a CUDA host call returns an error
#define checkCudaErrors(err)           __checkCudaErrors (err, __FILE__, __LINE__)

inline void __checkCudaErrors( cudaError err, const char *file, const int line )
{
    if( cudaSuccess != err) {
        fprintf(stderr, "%s(%i) : CUDA Runtime API error %d: %s.\n",
                file, line, (int)err, cudaGetErrorString( err ) );
        exit(-1);
    }
}

// This will output the proper error string when calling cudaGetLastError
#define getLastCudaError(msg)      __getLastCudaError (msg, __FILE__, __LINE__)

inline void __getLastCudaError( const char *errorMessage, const char *file, const int line )
{
    cudaError_t err = cudaGetLastError();
    if( cudaSuccess != err) {
        fprintf(stderr, "%s(%i) : getLastCudaError() CUDA error : %s : (%d) %s.\n",
                file, line, errorMessage, (int)err, cudaGetErrorString( err ) );
        exit(-1);
    }
}

// General GPU Device CUDA Initialization
int gpuDeviceInit(int devID)
{
    int deviceCount;
    checkCudaErrors(cudaGetDeviceCount(&deviceCount));
    if (deviceCount == 0) {
        fprintf(stderr, "gpuDeviceInit() CUDA error: no devices supporting CUDA.\n");
        exit(-1);
    }
    if (devID < 0) 
        devID = 0;
    if (devID > deviceCount-1) {
        fprintf(stderr, "\n");
        fprintf(stderr, ">> %d CUDA capable GPU device(s) detected. <<\n", deviceCount);
        fprintf(stderr, ">> gpuDeviceInit (-device=%d) is not a valid GPU device. <<\n", devID);
        fprintf(stderr, "\n");
        return -devID;
    }
    
    cudaDeviceProp deviceProp;
    checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );
    if (deviceProp.major < 1) {
        fprintf(stderr, "gpuDeviceInit(): GPU device does not support CUDA.\n");
        exit(-1);                                                  \
    }
    
    checkCudaErrors( cudaSetDevice(devID) );
    printf("> gpuDeviceInit() CUDA device [%d]: %s\n", devID, deviceProp.name);
    return devID;
}

// This function returns the best GPU (with maximum GFLOPS)
int gpuGetMaxGflopsDeviceId()
{
    int current_device   = 0, sm_per_multiproc = 0;
    int max_compute_perf = 0, max_perf_device  = 0;
    int device_count     = 0, best_SM_arch     = 0;
    cudaDeviceProp deviceProp;
    
    cudaGetDeviceCount( &device_count );
    // Find the best major SM Architecture GPU device
    while ( current_device < device_count ) {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major > 0 && deviceProp.major < 9999) {
            best_SM_arch = MAX(best_SM_arch, deviceProp.major);
        }
        current_device++;
    }
    
    // Find the best CUDA capable GPU device
    current_device = 0;
    while( current_device < device_count ) {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major == 9999 && deviceProp.minor == 9999) {
            sm_per_multiproc = 1;
        } else {
            sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor);
        }
        
        int compute_perf  = deviceProp.multiProcessorCount * sm_per_multiproc * deviceProp.clockRate;
        if( compute_perf  > max_compute_perf ) {
            // If we find GPU with SM major > 2, search only these
            if ( best_SM_arch > 2 ) {
                // If our device==dest_SM_arch, choose this, or else pass
                if (deviceProp.major == best_SM_arch) {	
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

// Initialization code to find the best CUDA Device
int findCudaDevice(int argc, const char **argv)
{
    cudaDeviceProp deviceProp;
    int devID = 0;
    // If the command-line has a device number specified, use it
    if (checkCmdLineFlag(argc, argv, "device")) {
        devID = getCmdLineArgumentInt(argc, argv, "device=");
        if (devID < 0) {
            printf("Invalid command line parameters\n");
            exit(-1);
        } else {
            devID = gpuDeviceInit(devID);
            if (devID < 0) {
                printf("exiting...\n");
                shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
                exit(-1);
            }
        }
    } else {
        // Otherwise pick the device with highest Gflops/s
        devID = gpuGetMaxGflopsDeviceId();
        checkCudaErrors( cudaSetDevice( devID ) );
        checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );
        printf("> Using CUDA device [%d]: %s\n", devID, deviceProp.name);
    }
    return devID;
}
// end of CUDA Helper Functions


////////////////////////////////////////////////////////////////////////////////
// Data configuration
////////////////////////////////////////////////////////////////////////////////
const int MAX_GPU_COUNT = 32;
const int DATA_N        = 1048576 * 32;

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    //Solver config
    TGPUplan      plan[MAX_GPU_COUNT];

    //GPU reduction results
    float     h_SumGPU[MAX_GPU_COUNT];

    float sumGPU;
    double sumCPU, diff;

    int i, j, gpuBase, GPU_N;
    StopWatchInterface *hTimer;

    const int  BLOCK_N = 32;
    const int THREAD_N = 256;
    const int  ACCUM_N = BLOCK_N * THREAD_N;

    shrQAStart(argc, argv);

    sdkCreateTimer( &hTimer );

    checkCudaErrors(cudaGetDeviceCount(&GPU_N));
    if(GPU_N > MAX_GPU_COUNT) GPU_N = MAX_GPU_COUNT;
    printf("CUDA-capable device count: %i\n", GPU_N);

    printf("Generating input data...\n\n");

    //Subdividing input data across GPUs
    //Get data sizes for each GPU
    for(i = 0; i < GPU_N; i++)
        plan[i].dataN = DATA_N / GPU_N;

    //Take into account "odd" data sizes
    for(i = 0; i < DATA_N % GPU_N; i++)
        plan[i].dataN++;

    //Assign data ranges to GPUs
    gpuBase = 0;
    for(i = 0; i < GPU_N; i++){
        plan[i].h_Sum = h_SumGPU + i;
        gpuBase += plan[i].dataN;
    }

    //Create streams for issuing GPU command asynchronously and allocate memory (GPU and System page-locked)
    for(i = 0; i < GPU_N; i++){
        checkCudaErrors( cudaSetDevice(i) );
        checkCudaErrors( cudaStreamCreate(&plan[i].stream) );
        //Allocate memory
        checkCudaErrors( cudaMalloc((void**)&plan[i].d_Data, plan[i].dataN * sizeof(float)) );
        checkCudaErrors( cudaMalloc((void**)&plan[i].d_Sum, ACCUM_N * sizeof(float)) );
        checkCudaErrors( cudaMallocHost((void**)&plan[i].h_Sum_from_device, ACCUM_N * sizeof(float)) );
        checkCudaErrors( cudaMallocHost((void**)&plan[i].h_Data, plan[i].dataN * sizeof(float)));
        for(j = 0; j < plan[i].dataN; j++)
        {
            plan[i].h_Data[j] = (float)rand() / (float)RAND_MAX;
        }
    }

    //Start timing and compute on GPU(s)
    printf("Computing with %d GPU's...\n", GPU_N);
    sdkResetTimer( &hTimer );
    sdkStartTimer( &hTimer );

    //Copy data to GPU, launch the kernel and copy data back. All asynchronously
    for(i = 0; i < GPU_N; i++)  
    {
        //Set device
        checkCudaErrors( cudaSetDevice(i) );

        //Copy input data from CPU
        checkCudaErrors( cudaMemcpyAsync(plan[i].d_Data, plan[i].h_Data, plan[i].dataN * sizeof(float), cudaMemcpyHostToDevice, plan[i].stream) );

        //Perform GPU computations
        launch_reduceKernel(plan[i].d_Sum, plan[i].d_Data, plan[i].dataN, BLOCK_N, THREAD_N, plan[i].stream);
        getLastCudaError("reduceKernel() execution failed.\n");

        //Read back GPU results
        checkCudaErrors( cudaMemcpyAsync(plan[i].h_Sum_from_device, plan[i].d_Sum, ACCUM_N * sizeof(float), cudaMemcpyDeviceToHost, plan[i].stream) );
    }

    //Process GPU results
    for(i = 0; i < GPU_N; i++)
    {
        float sum;

        //Set device
        checkCudaErrors( cudaSetDevice(i) );

        //Wait for all operations to finish
        cudaStreamSynchronize(plan[i].stream);

        //Finalize GPU reduction for current subvector
        sum = 0;
        for(j = 0; j < ACCUM_N; j++)
            sum += plan[i].h_Sum_from_device[j];
        *(plan[i].h_Sum) = (float)sum;

        //Shut down this GPU
        checkCudaErrors( cudaFreeHost(plan[i].h_Sum_from_device) );
        checkCudaErrors( cudaFree(plan[i].d_Sum) );
        checkCudaErrors( cudaFree(plan[i].d_Data) );
        checkCudaErrors( cudaStreamDestroy(plan[i].stream) );
    }

    sumGPU = 0;
    for(i = 0; i < GPU_N; i++)
    {
        sumGPU += h_SumGPU[i];
    }
    sdkStopTimer( &hTimer );
    printf("  GPU Processing time: %f (ms)\n\n", sdkGetTimerValue( &hTimer ));

    // Compute on Host CPU 
    printf("Computing with Host CPU...\n\n");
    
    sumCPU = 0;
    for(i = 0; i < GPU_N; i++){
        for(j = 0; j < plan[i].dataN; j++)
        {

            sumCPU += plan[i].h_Data[j];
        }
    }

    // Compare GPU and CPU results 
    printf("Comparing GPU and Host CPU results...\n");
    diff = fabs(sumCPU - sumGPU) / fabs(sumCPU);
    printf("  GPU sum: %f\n  CPU sum: %f\n", sumGPU, sumCPU);
    printf("  Relative difference: %E \n\n", diff);

    // Cleanup and shutdown
    sdkDeleteTimer( &hTimer );

    for(i = 0; i < GPU_N; i++)  
    {
        checkCudaErrors( cudaSetDevice(i) );
        cudaDeviceReset();
    }
    shrQAFinishExit(argc, (const char **)argv, (diff < 1e-5) ? QA_PASSED : QA_FAILED);
}
