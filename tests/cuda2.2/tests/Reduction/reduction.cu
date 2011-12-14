/*
* Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
*
* NOTICE TO USER:
*
* This source code is subject to NVIDIA ownership rights under U.S. and
* international Copyright laws.
*
* NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
* CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
* IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
* REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
* OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
* OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
* OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE
* OR PERFORMANCE OF THIS SOURCE CODE.
*
* U.S. Government End Users.  This source code is a "commercial item" as
* that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of
* "commercial computer software" and "commercial computer software
* documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995)
* and is provided to the U.S. Government only as a commercial end item.
* Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
* 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
* source code with only those rights set forth herein.
*/

/*
    Parallel reduction

    This sample shows how to perform a reduction operation on an array of values
    to produce a single value.

    Reductions are a very common computation in parallel algorithms.  Any time
    an array of values needs to be reduced to a single value using a binary 
    associative operator, a reduction can be used.  Example applications include
    statistics computaions such as mean and standard deviation, and image 
    processing applications such as finding the total luminance of an
    image.

    This code performs sum reductions, but any associative operator such as
    min() or max() could also be used.

    It assumes the input size is a power of 2.

    COMMAND LINE ARGUMENTS

    "--shmoo":         Test performance for 1 to 32M elements with each of the 7 different kernels
    "--n=<N>":         Specify the number of elements to reduce (default 1048576)
    "--threads=<N>":   Specify the number of threads per block (default 128)
    "--kernel=<N>":    Specify which kernel to run (0-6, default 6)
    "--maxblocks=<N>": Specify the maximum number of thread blocks to launch (kernel 6 only, default 64)
    "--cpufinal":      Read back the per-block results and do final sum of block sums on CPU (default false)
    "--cputhresh=<N>": The threshold of number of blocks sums below which to perform a CPU final reduction (default 1)
    
*/

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include <cutil_inline.h>

#include <tests/Reduction/reduction.h>

enum ReduceType
{
    REDUCE_INT,
    REDUCE_FLOAT,
    REDUCE_DOUBLE
};

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
template <class T>
void runTest( int argc, char** argv, ReduceType datatype);

#ifdef WIN32
#define strcasecmp strcmpi
#endif

extern "C"
bool isPow2(unsigned int x)
{
    return ((x&(x-1))==0);
}


////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    char *typeChoice;
    cutGetCmdLineArgumentstr( argc, (const char**) argv, "type", &typeChoice);

    if (0 == typeChoice)
    {
        typeChoice = (char*)malloc(4 * sizeof(char));
        strcpy(typeChoice, "int");
    }

    ReduceType datatype = REDUCE_INT;

    if (!strcasecmp(typeChoice, "float"))
        datatype = REDUCE_FLOAT;
    else if (!strcasecmp(typeChoice, "double"))
        datatype = REDUCE_DOUBLE;
    else
        datatype = REDUCE_INT;

    printf("Reducing array of type %s.\n", typeChoice);

    cudaDeviceProp deviceProp;
    deviceProp.major = 1;
    deviceProp.minor = 0;
    int desiredMinorRevision = 0;

    if (datatype == REDUCE_DOUBLE)
    {
        deviceProp.minor = 3;
        desiredMinorRevision = 3;
    }

    int dev;

    cutilSafeCallNoSync(cudaChooseDevice(&dev, &deviceProp));
    cutilSafeCallNoSync(cudaGetDeviceProperties(&deviceProp, dev));

    if(deviceProp.major > 1 || deviceProp.minor >= desiredMinorRevision)
    {
        printf("Using Device %d: \"%s\"\n", dev, deviceProp.name);
        cutilSafeCallNoSync(cudaSetDevice(dev));
    }
    else if (desiredMinorRevision == 3)
    {
        printf("There is no device supporting compute capability %d.%d.\n\n",
            1, desiredMinorRevision);
        printf("TEST PASSED");
        cudaThreadExit();
        cutilExit(argc, argv);
    }

    switch (datatype)
    {
    default:
    case REDUCE_INT:
        runTest<int>( argc, argv, datatype);
        break;
    case REDUCE_FLOAT:
        runTest<float>( argc, argv, datatype);
        break;
    case REDUCE_DOUBLE:
        runTest<double>( argc, argv, datatype);
        break;
    }
    
    cudaThreadExit();
    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Compute sum reduction on CPU
//! We use Kahan summation for an accurate sum of large arrays.
//! http://en.wikipedia.org/wiki/Kahan_summation_algorithm
//! 
//! @param data       pointer to input data
//! @param size       number of input data elements
////////////////////////////////////////////////////////////////////////////////
template<class T>
T reduceCPU(T *data, int size)
{
    T sum = data[0];
    T c = (T)0.0;              
    for (int i = 1; i < size; i++)
    {
        T y = data[i] - c;  
        T t = sum + y;      
        c = (t - sum) - y;  
        sum = t;            
    }
    return sum;
}

unsigned int nextPow2( unsigned int x ) {
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return ++x;
}

////////////////////////////////////////////////////////////////////////////////
// Compute the number of threads and blocks to use for the given reduction kernel
// For the kernels >= 3, we set threads / block to the minimum of maxThreads and
// n/2. For kernels < 3, we set to the minimum of maxThreads and n.  For kernel 
// 6, we observe the maximum specified number of blocks, because each thread in 
// that kernel can process a variable number of elements.
////////////////////////////////////////////////////////////////////////////////
void getNumBlocksAndThreads(int whichKernel, int n, int maxBlocks, int maxThreads, int &blocks, int &threads)
{
    
    
    
    if (whichKernel < 3)
    {
        threads = (n < maxThreads) ? nextPow2(n) : maxThreads;
        blocks = (n + threads - 1) / threads;
    }
    else
    {
        threads = (n < maxThreads*2) ? nextPow2((n + 1)/ 2) : maxThreads;
        blocks = (n + (threads * 2 - 1)) / (threads * 2);
    }
        

    if (whichKernel == 6)
        blocks = min(maxBlocks, blocks);
}

////////////////////////////////////////////////////////////////////////////////
// This function performs a reduction of the input data multiple times and 
// measures the average reduction time.
////////////////////////////////////////////////////////////////////////////////
template <class T>
T benchmarkReduce(int  n, 
                  int  numThreads,
                  int  numBlocks,
                  int  maxThreads,
                  int  maxBlocks,
                  int  whichKernel, 
                  int  testIterations,
                  bool cpuFinalReduction,
                  int  cpuFinalThreshold,
                  unsigned int timer,
                  bool useSM13,
                  T* h_odata,
                  T* d_idata, 
                  T* d_odata)
{
    T gpu_result = 0;
    bool needReadBack = true;

    for (int i = 0; i < testIterations; ++i)
    {
        gpu_result = 0;

        cudaThreadSynchronize();
        cutilCheckError( cutStartTimer( timer));

        // execute the kernel
        if (useSM13)
            reduce_sm13<T>(n, numThreads, numBlocks, whichKernel, d_idata, d_odata);
        else
            reduce_sm10<T>(n, numThreads, numBlocks, whichKernel, d_idata, d_odata);

        // check if kernel execution generated an error
        cutilCheckMsg("Kernel execution failed");

        if (cpuFinalReduction)
        {
            // sum partial sums from each block on CPU        
            // copy result from device to host
            cutilSafeCallNoSync( cudaMemcpy( h_odata, d_odata, numBlocks*sizeof(T), cudaMemcpyDeviceToHost) );

            for(int i=0; i<numBlocks; i++) 
            {
                gpu_result += h_odata[i];
            }

            needReadBack = false;
        }
        else
        {
            // sum partial block sums on GPU
            int s=numBlocks;
            int kernel = (whichKernel == 6) ? 5 : whichKernel;
            while(s > cpuFinalThreshold) 
            {
                int threads = 0, blocks = 0;
                getNumBlocksAndThreads(kernel, s, maxBlocks, maxThreads, blocks, threads);
                
                if (useSM13)
                    reduce_sm13<T>(s, threads, blocks, kernel, d_odata, d_odata);
                else
                    reduce_sm10<T>(s, threads, blocks, kernel, d_odata, d_odata);
                
                if (kernel < 3)
                    s = (s + threads - 1) / threads;
                else
                    s = (s + (threads*2-1)) / (threads*2);
            }
            
            if (s > 1)
            {
                // copy result from device to host
                cutilSafeCallNoSync( cudaMemcpy( h_odata, d_odata, s * sizeof(T), cudaMemcpyDeviceToHost) );

                for(int i=0; i < s; i++) 
                {
                    gpu_result += h_odata[i];
                }

                needReadBack = false;
            }
        }

        cudaThreadSynchronize();
        cutilCheckError( cutStopTimer(timer) );      
    }

    if (needReadBack)
    {
        // copy final sum from device to host
        cutilSafeCallNoSync( cudaMemcpy( &gpu_result, d_odata, sizeof(T), cudaMemcpyDeviceToHost) );
    }

    return gpu_result;
}

////////////////////////////////////////////////////////////////////////////////
// This function calls benchmarkReduce multple times for a range of array sizes
// and prints a report in CSV (comma-separated value) format that can be used for
// generating a "shmoo" plot showing the performance for each kernel variation
// over a wide range of input sizes.
////////////////////////////////////////////////////////////////////////////////
template <class T>
void shmoo(int minN, int maxN, int maxThreads, int maxBlocks, ReduceType datatype)
{ 
    bool useSM13 = (datatype == REDUCE_DOUBLE); 

    // create random input data on CPU
    unsigned int bytes = maxN * sizeof(T);

    T *h_idata = (T*) malloc(bytes);

    for(int i = 0; i < maxN; i++) {
        // Keep the numbers small so we don't get truncation error in the sum
        if (datatype == REDUCE_INT)
            h_idata[i] = (T)(rand() & 0xFF);
        else
            h_idata[i] = (rand() & 0xFF) / (T)RAND_MAX;
    }

    int maxNumBlocks = maxN / maxThreads;

    // allocate mem for the result on host side
    T* h_odata = (T*) malloc(maxNumBlocks*sizeof(T));

    // allocate device memory and data
    T* d_idata = NULL;
    T* d_odata = NULL;

    cutilSafeCallNoSync( cudaMalloc((void**) &d_idata, bytes) );
    cutilSafeCallNoSync( cudaMalloc((void**) &d_odata, maxNumBlocks*sizeof(T)) );

    // copy data directly to device memory
    cutilSafeCallNoSync( cudaMemcpy(d_idata, h_idata, bytes, cudaMemcpyHostToDevice) );
    cutilSafeCallNoSync( cudaMemcpy(d_odata, h_idata, maxNumBlocks*sizeof(T), cudaMemcpyHostToDevice) );

    // warm-up
#if 0
    for (int kernel = 0; kernel < 7; kernel++)
    {
        if (useSM13)
            reduce_sm13<T>(maxN, maxThreads, maxNumBlocks, kernel, d_idata, d_odata);
        else
            reduce_sm10<T>(maxN, maxThreads, maxNumBlocks, kernel, d_idata, d_odata);
    }
    int testIterations = 100;
#else
    int testIterations = 1;
#endif

    unsigned int timer = 0;
    cutilCheckError( cutCreateTimer( &timer));
    
    // print headers
    printf("Time in milliseconds for various numbers of elements for each kernel\n");
    printf("\n\n");
    printf("Kernel");
    for (int i = minN; i <= maxN; i *= 2)
    {
        printf(", %d", i);
    }
   
    for (int kernel = 0; kernel < 7; kernel++)
    {
        printf("\n");
        printf("%d", kernel);
        for (int i = minN; i <= maxN; i *= 2)
        {
            cutResetTimer(timer);
            int numBlocks = 0;
            int numThreads = 0;
            getNumBlocksAndThreads(kernel, i, maxBlocks, maxThreads, numBlocks, numThreads);
            
            
            benchmarkReduce(i, numThreads, numBlocks, maxThreads, maxBlocks, kernel, 
                            testIterations, false, 1, timer, useSM13, h_odata, d_idata, d_odata);

            float reduceTime = cutGetAverageTimerValue(timer);
            printf(", %f", reduceTime);
        }
        
    }

    // cleanup
    cutilCheckError(cutDeleteTimer(timer));
    free(h_idata);
    free(h_odata);

    cutilSafeCallNoSync(cudaFree(d_idata));
    cutilSafeCallNoSync(cudaFree(d_odata));    
}

////////////////////////////////////////////////////////////////////////////////
// The main function whihc runs the reduction test.
////////////////////////////////////////////////////////////////////////////////
template <class T>
void
runTest( int argc, char** argv, ReduceType datatype) 
{
    int size = 1<<20;    // number of elements to reduce
    int maxThreads = 128;  // number of threads per block
    int whichKernel = 6;
    int maxBlocks = 64;
    bool cpuFinalReduction = false;
    int cpuFinalThreshold = 1;

    cutGetCmdLineArgumenti( argc, (const char**) argv, "n", &size);
    cutGetCmdLineArgumenti( argc, (const char**) argv, "threads", &maxThreads);
    cutGetCmdLineArgumenti( argc, (const char**) argv, "kernel", &whichKernel);
    cutGetCmdLineArgumenti( argc, (const char**) argv, "maxblocks", &maxBlocks);
    
    printf("%d elements\n", size);
    printf("%d threads (max)\n", maxThreads);

    cpuFinalReduction = (cutCheckCmdLineFlag( argc, (const char**) argv, "cpufinal") == CUTTrue);
    cutGetCmdLineArgumenti( argc, (const char**) argv, "cputhresh", &cpuFinalThreshold);

    bool runShmoo = (cutCheckCmdLineFlag(argc, (const char**) argv, "shmoo") == CUTTrue);

    if (runShmoo)
    {
        shmoo<T>(1, 33554432, maxThreads, maxBlocks, datatype);
    }
    else
    {

        // create random input data on CPU
        unsigned int bytes = size * sizeof(T);

        T *h_idata = (T *) malloc(bytes);

        for(int i=0; i<size; i++) 
        {
            // Keep the numbers small so we don't get truncation error in the sum
            if (datatype == REDUCE_INT)
                h_idata[i] = (T)(rand() & 0xFF);
            else
                h_idata[i] = (rand() & 0xFF) / (T)RAND_MAX;
        }

        int numBlocks = 0;
        int numThreads = 0;
        getNumBlocksAndThreads(whichKernel, size, maxBlocks, maxThreads, numBlocks, numThreads);
        if (numBlocks == 1) cpuFinalThreshold = 1;

        // allocate mem for the result on host side
        T* h_odata = (T*) malloc(numBlocks*sizeof(T));

        printf("%d blocks\n", numBlocks);

        // allocate device memory and data
        T* d_idata = NULL;
        T* d_odata = NULL;

        cutilSafeCallNoSync( cudaMalloc((void**) &d_idata, bytes) );
        cutilSafeCallNoSync( cudaMalloc((void**) &d_odata, numBlocks*sizeof(T)) );

        // copy data directly to device memory
        cutilSafeCallNoSync( cudaMemcpy(d_idata, h_idata, bytes, cudaMemcpyHostToDevice) );
        cutilSafeCallNoSync( cudaMemcpy(d_odata, h_idata, numBlocks*sizeof(T), cudaMemcpyHostToDevice) );

    #if 0
        // warm-up
        if (datatype == REDUCE_DOUBLE)
            reduce_sm13<T>(size, numThreads, numBlocks, whichKernel, d_idata, d_odata);
        else
            reduce_sm10<T>(size, numThreads, numBlocks, whichKernel, d_idata, d_odata);
        
        int testIterations = 100;
    #else
        int testIterations = 1;
    #endif

        unsigned int timer = 0;
        cutilCheckError( cutCreateTimer( &timer));
        
        T gpu_result = 0;

        gpu_result = benchmarkReduce<T>(size, numThreads, numBlocks, maxThreads, maxBlocks,
                                        whichKernel, testIterations, cpuFinalReduction, 
                                        cpuFinalThreshold, timer, datatype == REDUCE_DOUBLE,
                                        h_odata, d_idata, d_odata);

        float reduceTime = cutGetAverageTimerValue(timer);
        printf("Average time: %f ms\n", reduceTime);
        printf("Bandwidth:    %f GB/s\n\n", (size * sizeof(int)) / (reduceTime * 1.0e6));

        // compute reference solution
        T cpu_result = reduceCPU<T>(h_idata, size);

        if (datatype == REDUCE_INT)
        {
            printf("GPU result = %d\n", gpu_result);
            printf("CPU result = %d\n", cpu_result);

            printf("TEST %s\n", (gpu_result == cpu_result) ? "PASSED" : "FAILED");
        }
        else
        {
            printf("GPU result = %0.12f\n", gpu_result);
            printf("CPU result = %0.12f\n", cpu_result);

            double threshold = (datatype == REDUCE_FLOAT) ? 1e-8 * size : 1e-12;
            double diff = abs((double)gpu_result - (double)cpu_result);
            printf("TEST %s\n", (diff < threshold) ? "PASSED" : "FAILED");
        }

        
      
        // cleanup
        cutilCheckError( cutDeleteTimer(timer) );
        free(h_idata);
        free(h_odata);

        cutilSafeCallNoSync(cudaFree(d_idata));
        cutilSafeCallNoSync(cudaFree(d_odata));
    }
}
