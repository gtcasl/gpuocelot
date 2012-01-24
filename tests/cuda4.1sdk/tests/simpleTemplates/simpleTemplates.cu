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
 
/* This sample is a templatized version of the template project.
* It also shows how to correctly templatize dynamically allocated shared
* memory arrays.
* Host code.
*/

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include <sdkHelper.h>  // helper for shared that are common to CUDA SDK samples
#include <shrQATest.h>  // This is for automated testing output (--qatest)
#include <shrUtils.h>

// includes CUDA
#include <cuda_runtime.h>

// includes, kernels
#include "simpleTemplates_kernel.cu"

int g_TotalFailures = 0;

////////////////////////////////////////////////////////////////////////////////
// These are CUDA Helper functions

// This will output the proper CUDA error strings in the event that a CUDA host call returns an error
#define checkCudaErrors(err)  __checkCudaErrors (err, __FILE__, __LINE__)

inline void __checkCudaErrors(cudaError err, const char *file, const int line )
{
    if(cudaSuccess != err)
    {
        fprintf(stderr, "%s(%i) : CUDA Runtime API error %d: %s.\n",file, line, (int)err, cudaGetErrorString( err ) );
        exit(-1);        
    }
}

// This will output the proper error string when calling cudaGetLastError
#define getLastCudaError(msg)      __getLastCudaError (msg, __FILE__, __LINE__)

inline void __getLastCudaError(const char *errorMessage, const char *file, const int line )
{
    cudaError_t err = cudaGetLastError();
    if (cudaSuccess != err)
    {
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

    if (deviceCount == 0)
    {
        fprintf(stderr, "gpuDeviceInit() CUDA error: no devices supporting CUDA.\n");
        exit(-1);
    }

    if (devID < 0)
       devID = 0;
        
    if (devID > deviceCount-1)
    {
        fprintf(stderr, "\n");
        fprintf(stderr, ">> %d CUDA capable GPU device(s) detected. <<\n", deviceCount);
        fprintf(stderr, ">> gpuDeviceInit (-device=%d) is not a valid GPU device. <<\n", devID);
        fprintf(stderr, "\n");
        return -devID;
    }

    cudaDeviceProp deviceProp;
    checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );

    if (deviceProp.major < 1)
    {
        fprintf(stderr, "gpuDeviceInit(): GPU device does not support CUDA.\n");
        exit(-1);                                                  
    }
    
    checkCudaErrors( cudaSetDevice(devID) );
    printf("gpuDeviceInit() CUDA Device [%d]: \"%s\n", devID, deviceProp.name);

    return devID;
}

// This function returns the best GPU (with maximum GFLOPS)
int gpuGetMaxGflopsDeviceId()
{
    int current_device     = 0, sm_per_multiproc  = 0;
    int max_compute_perf   = 0, max_perf_device   = 0;
    int device_count       = 0, best_SM_arch      = 0;
    cudaDeviceProp deviceProp;
    cudaGetDeviceCount( &device_count );
    
    // Find the best major SM Architecture GPU device
    while (current_device < device_count)
    {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major > 0 && deviceProp.major < 9999)
        {
            best_SM_arch = MAX(best_SM_arch, deviceProp.major);
        }
        current_device++;
    }

    // Find the best CUDA capable GPU device
    current_device = 0;
    while( current_device < device_count )
    {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major == 9999 && deviceProp.minor == 9999)
        {
            sm_per_multiproc = 1;
        }
        else
        {
            sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor);
        }
        
        int compute_perf  = deviceProp.multiProcessorCount * sm_per_multiproc * deviceProp.clockRate;
        
    if( compute_perf  > max_compute_perf )
    {
            // If we find GPU with SM major > 2, search only these
            if ( best_SM_arch > 2 )
            {
                // If our device==dest_SM_arch, choose this, or else pass
                if (deviceProp.major == best_SM_arch)
                {
                    max_compute_perf  = compute_perf;
                    max_perf_device   = current_device;
                 }
            }
            else
            {
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
    if (checkCmdLineFlag(argc, argv, "device"))
    {
        devID = getCmdLineArgumentInt(argc, argv, "device=");
        if (devID < 0)
        {
            printf("Invalid command line parameter\n ");
            exit(-1);
        }
        else
        {
            devID = gpuDeviceInit(devID);
            if (devID < 0)
            {
                printf("exiting...\n");
                shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
                exit(-1);
            }
        }
    }
    else
    {
        // Otherwise pick the device with highest Gflops/s
        devID = gpuGetMaxGflopsDeviceId();
        checkCudaErrors( cudaSetDevice( devID ) );
        checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );
        printf("GPU Device %d: \"%s\" with compute capability %d.%d\n\n", devID, deviceProp.name, deviceProp.major, deviceProp.minor);
    }
    return devID;
}
// end of CUDA Helper Functions

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
template <class T>
void runTest( int argc, char** argv, int len);

template<class T>
void
computeGold( T* reference, T* idata, const unsigned int len) 
{
    const T T_len = static_cast<T>( len);
    for( unsigned int i = 0; i < len; ++i) 
    {
        reference[i] = idata[i] * T_len;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    shrQAStart(argc, argv);

    printf("> runTest<float,32>\n");
    runTest<float>( argc, argv, 32);
    printf("> runTest<int,64>\n");
    runTest<int>( argc, argv, 64);

    printf("\n[simpleTemplates] -> Test Results: %d Failures\n", g_TotalFailures);

    cudaDeviceReset();
    shrQAFinishExit(argc, (const char **)argv, (g_TotalFailures == 0) ? QA_PASSED : QA_FAILED);
}

// To completely templatize runTest (below) with cutil, we need to use 
// template specialization to wrap up CUTIL's array comparison and file writing
// functions for different types.  

// Here's the generic wrapper for cutCompare*
template<class T>
class ArrayComparator
{
public:
    bool compare( const T* reference, T* data, unsigned int len)
    {
        fprintf(stderr, "Error: no comparison function implemented for this type\n");
        return false;
    }
};

// Here's the specialization for ints:
template<>
class ArrayComparator<int>
{
public:
    bool compare( const int* reference, int* data, unsigned int len)
    {
        return compareData(reference, data, len, 0.15f, 0.0f);
    }
};

// Here's the specialization for floats:
template<>
class ArrayComparator<float>
{
public:
    bool compare( const float* reference, float* data, unsigned int len)
    {
        return compareData(reference, data, len, 0.15f, 0.15f);
    }
};

// Here's the generic wrapper for cutWriteFile*
template<class T>
class ArrayFileWriter
{
public:
    bool write(const char* filename, T* data, unsigned int len, float epsilon)
    {
        fprintf(stderr, "Error: no file write function implemented for this type\n");
        return false;
    }
};

// Here's the specialization for ints:
template<>
class ArrayFileWriter<int>
{
public:
    bool write(const char* filename, int* data, unsigned int len, float epsilon)
    {
        return sdkWriteFile(filename, data, len, epsilon, false);
    }
};

// Here's the specialization for floats:
template<>
class ArrayFileWriter<float>
{
public:
    bool write(const char* filename, float* data, unsigned int len, float epsilon)
    {
        return sdkWriteFile(filename, data, len, epsilon, false);
    }
};


////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
template<class T>
void
runTest( int argc, char** argv, int len) 
{
    int devID;
    cudaDeviceProp deviceProps;

    devID = findCudaDevice(argc, (const char**)argv);
		
    // get number of SMs on this GPU
    checkCudaErrors(cudaGetDeviceProperties(&deviceProps, devID));
    printf("CUDA device [%s] has %d Multi-Processors\n", deviceProps.name, deviceProps.multiProcessorCount);

    StopWatchInterface *timer = NULL;
    sdkCreateTimer( &timer );
    sdkStartTimer ( &timer );

    unsigned int num_threads = len;
    unsigned int mem_size = sizeof( float) * num_threads;

    // allocate host memory
    T* h_idata = (T*) malloc( mem_size);
    // initalize the memory
    for( unsigned int i = 0; i < num_threads; ++i) 
    {
        h_idata[i] = (T) i;
    }

    // allocate device memory
    T* d_idata;
    checkCudaErrors( cudaMalloc( (void**) &d_idata, mem_size));
    // copy host memory to device
    checkCudaErrors( cudaMemcpy( d_idata, h_idata, mem_size,
                                cudaMemcpyHostToDevice) );

    // allocate device memory for result
    T* d_odata;
    checkCudaErrors( cudaMalloc( (void**) &d_odata, mem_size));

    // setup execution parameters
    dim3  grid( 1, 1, 1);
    dim3  threads( num_threads, 1, 1);

    // execute the kernel
    testKernel<T><<< grid, threads, mem_size >>>( d_idata, d_odata);

    // check if kernel execution generated and error
    getLastCudaError("Kernel execution failed");

    // allocate mem for the result on host side
    T* h_odata = (T*) malloc( mem_size);
    // copy result from device to host
    checkCudaErrors( cudaMemcpy( h_odata, d_odata, sizeof(T) * num_threads,
                                cudaMemcpyDeviceToHost) );

    sdkStopTimer( &timer );
    printf( "Processing time: %f (ms)\n", sdkGetTimerValue( &timer ));
    sdkDeleteTimer( &timer );

    // compute reference solution
    T* reference = (T*) malloc( mem_size);
    computeGold<T>( reference, h_idata, num_threads);

    ArrayComparator<T> comparator;
    ArrayFileWriter<T> writer;

    // check result
    if( checkCmdLineFlag( argc, (const char**) argv, "regression")) 
    {
        // write file for regression test
        writer.write( "./data/regression.dat", h_odata, num_threads, 0.0f );
    }
    else 
    {
        // custom output handling when no regression test running
        // in this case check if the result is equivalent to the expected soluion
        bool res = comparator.compare( reference, h_odata, num_threads);
        printf( "Compare %s\n\n", (1 == res) ? "OK" : "MISMATCH");
        g_TotalFailures += (1 != res);
    }

    // cleanup memory
    free( h_idata);
    free( h_odata);
    free( reference);
    checkCudaErrors(cudaFree(d_idata));
    checkCudaErrors(cudaFree(d_odata));

    cudaDeviceReset();
}
