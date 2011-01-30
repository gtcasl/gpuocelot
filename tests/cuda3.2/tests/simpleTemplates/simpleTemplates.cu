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
#include <cutil_inline.h>

// includes, kernels
#include "simpleTemplates_kernel.cu"

int g_TotalFailures = 0;

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
    printf("[simpleTemplates]\n");

    printf("> runTest<float,32>\n");
    runTest<float>( argc, argv, 32);
    printf("> runTest<int,64>\n");
    runTest<int>( argc, argv, 64);

    printf("\n[simpleTemplates] -> Test Results: %d Failures\n", g_TotalFailures);
    printf( (g_TotalFailures == 0) ? "PASSED\n" : "FAILED\n" );

    cutilExit(argc, argv);
}

// To completely templatize runTest (below) with cutil, we need to use 
// template specialization to wrap up CUTIL's array comparison and file writing
// functions for different types.  

// Here's the generic wrapper for cutCompare*
template<class T>
class ArrayComparator
{
public:
    CUTBoolean compare( const T* reference, T* data, unsigned int len)
    {
        fprintf(stderr, "Error: no comparison function implemented for this type\n");
        return CUTFalse;
    }
};

// Here's the specialization for ints:
template<>
class ArrayComparator<int>
{
public:
    CUTBoolean compare( const int* reference, int* data, unsigned int len)
    {
        return cutComparei(reference, data, len);
    }
};

// Here's the specialization for floats:
template<>
class ArrayComparator<float>
{
public:
    CUTBoolean compare( const float* reference, float* data, unsigned int len)
    {
        return cutComparef(reference, data, len);
    }
};

// Here's the generic wrapper for cutWriteFile*
template<class T>
class ArrayFileWriter
{
public:
    CUTBoolean write(const char* filename, T* data, unsigned int len, float epsilon)
    {
        fprintf(stderr, "Error: no file write function implemented for this type\n");
        return CUTFalse;
    }
};

// Here's the specialization for ints:
template<>
class ArrayFileWriter<int>
{
public:
    CUTBoolean write(const char* filename, int* data, unsigned int len, float epsilon)
    {
        return cutWriteFilei(filename, data, len, epsilon != 0);
    }
};

// Here's the specialization for floats:
template<>
class ArrayFileWriter<float>
{
public:
    CUTBoolean write(const char* filename, float* data, unsigned int len, float epsilon)
    {
        return cutWriteFilef(filename, data, len, epsilon);
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

	if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") ) {
	    devID = cutilDeviceInit(argc, argv);
            if (devID < 0) {
               printf("exiting...\n");
               cutilExit(argc, argv);
               exit(0);
            }
	}
	else {
	    devID = cutGetMaxGflopsDeviceId();
	    cudaSetDevice( devID );
	}
		
    // get number of SMs on this GPU
    cutilSafeCall(cudaGetDeviceProperties(&deviceProps, devID));
    printf("CUDA device [%s] has %d Multi-Processors\n", deviceProps.name, deviceProps.multiProcessorCount);

    unsigned int timer = 0;
    cutilCheckError( cutCreateTimer( &timer));
    cutilCheckError( cutStartTimer( timer));

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
    cutilSafeCall( cudaMalloc( (void**) &d_idata, mem_size));
    // copy host memory to device
    cutilSafeCall( cudaMemcpy( d_idata, h_idata, mem_size,
                                cudaMemcpyHostToDevice) );

    // allocate device memory for result
    T* d_odata;
    cutilSafeCall( cudaMalloc( (void**) &d_odata, mem_size));

    // setup execution parameters
    dim3  grid( 1, 1, 1);
    dim3  threads( num_threads, 1, 1);

    // execute the kernel
    testKernel<T><<< grid, threads, mem_size >>>( d_idata, d_odata);

    // check if kernel execution generated and error
    cutilCheckMsg("Kernel execution failed");

    // allocate mem for the result on host side
    T* h_odata = (T*) malloc( mem_size);
    // copy result from device to host
    cutilSafeCall( cudaMemcpy( h_odata, d_odata, sizeof(T) * num_threads,
                                cudaMemcpyDeviceToHost) );

    cutilCheckError( cutStopTimer( timer));
    printf( "Processing time: %f (ms)\n", cutGetTimerValue( timer));
    cutilCheckError( cutDeleteTimer( timer));

    // compute reference solution
    T* reference = (T*) malloc( mem_size);
    computeGold<T>( reference, h_idata, num_threads);

    ArrayComparator<T> comparator;
    ArrayFileWriter<T> writer;

    // check result
    if( cutCheckCmdLineFlag( argc, (const char**) argv, "regression")) 
    {
        // write file for regression test
        cutilCheckError( writer.write( "./data/regression.dat",
                                     h_odata, num_threads, 0.0));
    }
    else 
    {
        // custom output handling when no regression test running
        // in this case check if the result is equivalent to the expected soluion
        CUTBoolean res = comparator.compare( reference, h_odata, num_threads);
        printf( "Compare %s\n\n", (1 == res) ? "OK" : "MISMATCH");
        g_TotalFailures += (1 != res);
    }

    // cleanup memory
    free( h_idata);
    free( h_odata);
    free( reference);
    cutilSafeCall(cudaFree(d_idata));
    cutilSafeCall(cudaFree(d_odata));

    cudaThreadExit();
}
