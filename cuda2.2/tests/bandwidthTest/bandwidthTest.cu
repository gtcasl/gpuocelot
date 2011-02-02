/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */

/* 
 * This is a simple test program to measure the memcopy bandwidth of the GPU.
 * It can measure device to device copy bandwidth, host to device copy bandwidth 
 * for pageable and pinned memory, and device to host copy bandwidth for pageable 
 * and pinned memory.
 *
 * Usage:
 * ./bandwidthTest [option]...
 */

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include <cutil_inline.h>
#include <cuda.h>

// defines, project
#define MEMCOPY_ITERATIONS  10
#define DEFAULT_SIZE        ( 32 * ( 1 << 20 ) )    //32 M
#define DEFAULT_INCREMENT   (1 << 22)               //4 M
#define CACHE_CLEAR_SIZE    (1 << 24)               //16 M

//shmoo mode defines
#define SHMOO_MEMSIZE_MAX     (1 << 26)         //64 M
#define SHMOO_MEMSIZE_START   (1 << 10)         //1 KB
#define SHMOO_INCREMENT_1KB   (1 << 10)         //1 KB
#define SHMOO_INCREMENT_2KB   (1 << 11)         //2 KB
#define SHMOO_INCREMENT_10KB  (10 * (1 << 10))  //10KB
#define SHMOO_INCREMENT_100KB (100 * (1 << 10)) //100 KB
#define SHMOO_INCREMENT_1MB   (1 << 20)         //1 MB
#define SHMOO_INCREMENT_2MB   (1 << 21)         //2 MB
#define SHMOO_INCREMENT_4MB   (1 << 22)         //4 MB
#define SHMOO_LIMIT_20KB      (20 * (1 << 10))  //20 KB
#define SHMOO_LIMIT_50KB      (50 * (1 << 10))  //50 KB
#define SHMOO_LIMIT_100KB     (100 * (1 << 10)) //100 KB
#define SHMOO_LIMIT_1MB       (1 << 20)         //1 MB
#define SHMOO_LIMIT_16MB      (1 << 24)         //16 MB
#define SHMOO_LIMIT_32MB      (1 << 25)         //32 MB

//enums, project
enum testMode { QUICK_MODE, RANGE_MODE, SHMOO_MODE };
enum memcpyKind { DEVICE_TO_HOST, HOST_TO_DEVICE, DEVICE_TO_DEVICE };
enum printMode { USER_READABLE, CSV };
enum memoryMode { PINNED, PAGEABLE };

// if true, use CPU based timing for everything
static bool bDontUseGPUTiming;

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest(const int argc, const char **argv);
void testBandwidth( unsigned int start, unsigned int end, unsigned int increment, 
                   testMode mode, memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc);
void testBandwidthQuick(unsigned int size, memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc);
void testBandwidthRange(unsigned int start, unsigned int end, unsigned int increment, 
                        memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc);
void testBandwidthShmoo(memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc);
float testDeviceToHostTransfer(unsigned int memSize, memoryMode memMode, bool wc);
float testHostToDeviceTransfer(unsigned int memSize, memoryMode memMode, bool wc);
float testDeviceToDeviceTransfer(unsigned int memSize);
void printResultsReadable(unsigned int *memSizes, float *bandwidths, unsigned int count);
void printResultsCSV(unsigned int *memSizes, float *bandwidths, unsigned int count);
void printHelp(void);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main(int argc, char** argv) 
{
    runTest(argc, (const char**)argv);
    cutilExit(argc, argv);
}

///////////////////////////////////////////////////////////////////////////////
//Parse args, run the appropriate tests
///////////////////////////////////////////////////////////////////////////////
void runTest(const int argc, const char **argv)
{
    int start = DEFAULT_SIZE;
    int end = DEFAULT_SIZE;
    int startDevice = 0;
    int endDevice = 0;
    int increment = DEFAULT_INCREMENT;
    testMode mode = QUICK_MODE;
    bool htod = false;
    bool dtoh = false;
    bool dtod = false;
    bool wc = false;
    char *modeStr;
    char *device = NULL;
    printMode printmode = USER_READABLE;
    char *memModeStr = NULL;
    memoryMode memMode = PAGEABLE;

    //process command line args
    if(cutCheckCmdLineFlag( argc, argv, "help"))
    {
        printHelp();
        return;
    }

    if(cutCheckCmdLineFlag( argc, argv, "csv"))
    {
        printmode = CSV;
    }

    if( cutGetCmdLineArgumentstr(argc, argv, "memory", &memModeStr) )
    {
        if( strcmp(memModeStr, "pageable") == 0 )
        {
            memMode = PAGEABLE;
        }
        else if( strcmp(memModeStr, "pinned") == 0)
        {
            memMode = PINNED;
        }
        else
        {
            printf("Invalid memory mode - valid modes are pageable or pinned\n");
            printf("See --help for more information\n");
            return;
        }
    }
    else
    {
        //default - pageable memory
        memMode = PAGEABLE;
    }

    if( cutGetCmdLineArgumentstr(argc, argv, "device", &device) )
    {
        int deviceCount;
        cudaGetDeviceCount(&deviceCount);
        if( deviceCount == 0 )
        {
            printf("!!!!!No devices found!!!!!\n");
            return;
        } 
        if( strcmp (device, "all") == 0 )
        {
            printf ("\n!!!!!Cumulative Bandwidth to be computed from all the devices !!!!!!\n\n");
            startDevice = 0;
            endDevice = deviceCount-1;
        }
        else
        {
            startDevice = endDevice = atoi(device);
            if( startDevice >= deviceCount || startDevice < 0)
            {
                printf("\n!!!!!Invalid GPU number %d given hence default gpu %d will be used !!!!!\n", startDevice,0);
                startDevice = endDevice = 0;
            }
        }
    }
    printf("Running on......\n");
    for( int currentDevice = startDevice; currentDevice <= endDevice; currentDevice++)
    {
        cudaDeviceProp deviceProp;
        cudaGetDeviceProperties(&deviceProp, currentDevice);
        printf ("      device %d:%s\n", currentDevice,deviceProp.name);
    }

    if( cutGetCmdLineArgumentstr(argc, argv, "mode", &modeStr) )
    {
        //figure out the mode
        if( strcmp(modeStr, "quick") == 0 )
        {
            mode = QUICK_MODE;
        }
        else if( strcmp(modeStr, "shmoo") == 0 )
        {
            mode = SHMOO_MODE;
        }
        else if( strcmp(modeStr, "range") == 0 )
        {
            mode = RANGE_MODE;
        }
        else
        {
            printf("Invalid mode - valid modes are quick, range, or shmoo\n");
            printf("See --help for more information\n");
            return;
        }
    }
    else
    {
        //default mode - quick
        mode = QUICK_MODE;
    }
    
    if(cutCheckCmdLineFlag( argc, argv, "htod"))
        htod = true;
    if(cutCheckCmdLineFlag( argc, argv, "dtoh"))
        dtoh = true;
    if(cutCheckCmdLineFlag( argc, argv, "dtod"))
        dtod = true;
#if CUDART_VERSION >= 2020
    if(cutCheckCmdLineFlag( argc, argv, "wc"))
        wc = true;
#endif
    if(cutCheckCmdLineFlag( argc, argv, "cputiming"))
        bDontUseGPUTiming = true;

    if( !htod && !dtoh && !dtod )
    {
        //default:  All
        htod = true;
        dtoh = true;
        dtod = true;
    }

    if( RANGE_MODE == mode )
    {
        if( cutGetCmdLineArgumenti( argc, argv, "start", &start) )
        {
            if( start <= 0 )
            {
                printf("Illegal argument - start must be greater than zero\n");
                return;
            }   
        }
        else
        {
            printf("Must specify a starting size in range mode\n");
            printf("See --help for more information\n");
            return;
        }

        if( cutGetCmdLineArgumenti( argc, argv, "end", &end) )
        {
            if( end <= 0 )
            {
                printf("Illegal argument - end must be greater than zero\n");
                return;
            }

            if( start > end )
            {
                printf("Illegal argument - start is greater than end\n");
                return;
            }
        }
        else
        {
            printf("Must specify an end size in range mode.\n");
            printf("See --help for more information\n");
            return;
        }


        if( cutGetCmdLineArgumenti( argc, argv, "increment", &increment) )
        {
            if( increment <= 0 )
            {
                printf("Illegal argument - increment must be greater than zero\n");
                return;
            }
        }
        else
        {
            printf("Must specify an increment in user mode\n");
            printf("See --help for more information\n");
            return;
        }
    }
   
    if( htod )
    {
        testBandwidth((unsigned int)start, (unsigned int)end, (unsigned int)increment, 
                       mode, HOST_TO_DEVICE, printmode, memMode, startDevice, endDevice, wc);
    }                       
    if( dtoh )
    {
        testBandwidth((unsigned int)start, (unsigned int)end, (unsigned int)increment,
                       mode, DEVICE_TO_HOST, printmode, memMode, startDevice, endDevice, wc);
    }                       
    if( dtod )
    {
        testBandwidth((unsigned int)start, (unsigned int)end, (unsigned int)increment,
                      mode, DEVICE_TO_DEVICE, printmode, memMode, startDevice, endDevice, wc);
    }                       

    printf("&&&& Test PASSED\n");

    cutFree( memModeStr); 

    return;
}

///////////////////////////////////////////////////////////////////////////////
//  Run a bandwidth test
///////////////////////////////////////////////////////////////////////////////
void
testBandwidth(unsigned int start, unsigned int end, unsigned int increment, 
              testMode mode, memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc)
{
    switch( mode )
    {
    case QUICK_MODE:
        printf("Quick Mode\n");
        testBandwidthQuick( DEFAULT_SIZE, kind, printmode, memMode, startDevice, endDevice, wc );
        break;
    case RANGE_MODE:
        printf("Range Mode\n");
        testBandwidthRange(start, end, increment, kind, printmode, memMode, startDevice, endDevice, wc);
        break;
    case SHMOO_MODE: 
        printf("Shmoo Mode\n");
        testBandwidthShmoo(kind, printmode, memMode, startDevice, endDevice, wc);
        break;
    default:  
        printf("Invalid testing mode\n");
        break;
    }

}

//////////////////////////////////////////////////////////////////////
//  Run a quick mode bandwidth test
//////////////////////////////////////////////////////////////////////
void
testBandwidthQuick(unsigned int size, memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc)
{
    testBandwidthRange(size, size, DEFAULT_INCREMENT, kind, printmode, memMode, startDevice, endDevice, wc);
}

///////////////////////////////////////////////////////////////////////
//  Run a range mode bandwidth test
//////////////////////////////////////////////////////////////////////
void
testBandwidthRange(unsigned int start, unsigned int end, unsigned int increment, 
                   memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc)
{
    //count the number of copies we're going to run
    unsigned int count = 1 + ((end - start) / increment);
    
    unsigned int *memSizes = ( unsigned int * )malloc( count * sizeof( unsigned int ) );
    float *bandwidths = ( float * ) malloc( count * sizeof(float) );

    //print information for use
    switch(kind)
    {
    case DEVICE_TO_HOST:    printf("Device to Host Bandwidth for ");
        break;
    case HOST_TO_DEVICE:    printf("Host to Device Bandwidth for ");
        break;
    case DEVICE_TO_DEVICE:  printf("Device to Device Bandwidth\n");
        break;
    }
    if( DEVICE_TO_DEVICE != kind )
    {   switch(memMode)
        {
        case PAGEABLE:  printf("Pageable memory\n");
            break;
        case PINNED:    printf("Pinned memory\n");
						if (wc) printf("Write-Combined memory enabled\n");
            break;
        }
    }

    // Before calculating the cumulative bandwidth, initialize bandwidths array to NULL
    for (int i = 0; i < count; i++)
        bandwidths[i] = 0.0f;

    // Use the device asked by the user
    for (int currentDevice = startDevice; currentDevice <= endDevice; currentDevice++)
    {
        cudaSetDevice(currentDevice);
	    //run each of the copies
	    for(unsigned int i = 0; i < count; i++)
	    {

			memSizes[i] = start + i * increment;
	        switch(kind)
	        {
	        case DEVICE_TO_HOST:    bandwidths[i] = testDeviceToHostTransfer( memSizes[i], memMode, wc );
	            break;
	        case HOST_TO_DEVICE:    bandwidths[i] = testHostToDeviceTransfer( memSizes[i], memMode, wc );
	            break;
	        case DEVICE_TO_DEVICE:  bandwidths[i] = testDeviceToDeviceTransfer( memSizes[i] );
	            break;
	        }
	        printf(".");
		}
		cudaThreadExit();
    } // Complete the bandwidth computation on all the devices
    printf("\n");

    //print results
    if(printmode == CSV)
    {
        printResultsCSV(memSizes, bandwidths, count);
    }
    else
    {
        printResultsReadable(memSizes, bandwidths, count);
    }

    //clean up
    free(memSizes);
    free(bandwidths);
}

//////////////////////////////////////////////////////////////////////////////
// Intense shmoo mode - covers a large range of values with varying increments
//////////////////////////////////////////////////////////////////////////////
void
testBandwidthShmoo(memcpyKind kind, printMode printmode, memoryMode memMode, int startDevice, int endDevice, bool wc)
{
    //print info for user
    switch(kind)
    {
    case DEVICE_TO_HOST:    printf("Device to Host Bandwidth for ");
        break;
    case HOST_TO_DEVICE:    printf("Host to Device Bandwidth for ");
        break;
    case DEVICE_TO_DEVICE:  printf("Device to Device Bandwidth\n");
        break;
    }
    if( DEVICE_TO_DEVICE != kind )
    {   switch(memMode)
        {
        case PAGEABLE:  printf("Pageable memory\n");
            break;
        case PINNED:    printf("Pinned memory\n");
						if (wc) printf("Write-Combined memory enabled\n");
            break;
        }
    }

    //count the number of copies to make
    unsigned int count = 1 + (SHMOO_LIMIT_20KB  / SHMOO_INCREMENT_1KB)
                        + ((SHMOO_LIMIT_50KB - SHMOO_LIMIT_20KB) / SHMOO_INCREMENT_2KB)
                        + ((SHMOO_LIMIT_100KB - SHMOO_LIMIT_50KB) / SHMOO_INCREMENT_10KB)
                        + ((SHMOO_LIMIT_1MB - SHMOO_LIMIT_100KB) / SHMOO_INCREMENT_100KB)
                        + ((SHMOO_LIMIT_16MB - SHMOO_LIMIT_1MB) / SHMOO_INCREMENT_1MB)
                        + ((SHMOO_LIMIT_32MB - SHMOO_LIMIT_16MB) / SHMOO_INCREMENT_2MB)
                        + ((SHMOO_MEMSIZE_MAX - SHMOO_LIMIT_32MB) / SHMOO_INCREMENT_4MB);

    unsigned int *memSizes = ( unsigned int * )malloc( count * sizeof( unsigned int ) );
    float *bandwidths = ( float * ) malloc( count * sizeof(float) );


    // Before calculating the cumulative bandwidth, initialize bandwidths array to NULL
    for (int i = 0; i < count; i++)
        bandwidths[i] = 0.0f;
   
    // Use the device asked by the user
    for (int currentDevice = startDevice; currentDevice <= endDevice; currentDevice++)
    {
        cudaSetDevice(currentDevice);
        //Run the shmoo
        int iteration = 0;
        unsigned int memSize = 0;
        while( memSize <= SHMOO_MEMSIZE_MAX )
        {
            if( memSize < SHMOO_LIMIT_20KB )
            {
                memSize += SHMOO_INCREMENT_1KB;
            }
            else if( memSize < SHMOO_LIMIT_50KB )
            {
                memSize += SHMOO_INCREMENT_2KB;
            }else if( memSize < SHMOO_LIMIT_100KB )
            {
                memSize += SHMOO_INCREMENT_10KB;
            }else if( memSize < SHMOO_LIMIT_1MB )
            {
                memSize += SHMOO_INCREMENT_100KB;
            }else if( memSize < SHMOO_LIMIT_16MB )
            {
                memSize += SHMOO_INCREMENT_1MB;
            }else if( memSize < SHMOO_LIMIT_32MB )
            {
                memSize += SHMOO_INCREMENT_2MB;
            }else 
            {
                memSize += SHMOO_INCREMENT_4MB;
            }

            memSizes[iteration] = memSize;
            switch(kind)
            {
            case DEVICE_TO_HOST:    bandwidths[iteration] += testDeviceToHostTransfer( memSizes[iteration], memMode, wc );
                break;
            case HOST_TO_DEVICE:    bandwidths[iteration] += testHostToDeviceTransfer( memSizes[iteration], memMode, wc );
                break;
            case DEVICE_TO_DEVICE:  bandwidths[iteration] += testDeviceToDeviceTransfer( memSizes[iteration] );
                break;
            }
            iteration++;
            printf(".");
       }
    } // Complete the bandwidth computation on all the devices

    printf("\n");

    //print results
    if( CSV == printmode)
    {
        printResultsCSV(memSizes, bandwidths, count);
    }
    else
    {
        printResultsReadable(memSizes, bandwidths, count);
    }

    //clean up
    free(memSizes);
    free(bandwidths);
}

///////////////////////////////////////////////////////////////////////////////
//  test the bandwidth of a device to host memcopy of a specific size
///////////////////////////////////////////////////////////////////////////////
float
testDeviceToHostTransfer(unsigned int memSize, memoryMode memMode, bool wc)
{
    unsigned int timer = 0;
    float elapsedTimeInMs = 0.0f;
    float bandwidthInMBs = 0.0f;
    unsigned char *h_idata = NULL;
    unsigned char *h_odata = NULL;
    cudaEvent_t start, stop;

    cutilCheckError( cutCreateTimer( &timer ) );
    cutilSafeCall  ( cudaEventCreate( &start ) );
    cutilSafeCall  ( cudaEventCreate( &stop ) );
    
    //allocate host memory
    if( PINNED == memMode )
    {
        //pinned memory mode - use special function to get OS-pinned memory
#if CUDART_VERSION >= 2020
		cutilSafeCall( cudaHostAlloc( (void**)&h_idata, memSize, (wc) ? cudaHostAllocWriteCombined : 0 ) );
        cutilSafeCall( cudaHostAlloc( (void**)&h_odata, memSize, (wc) ? cudaHostAllocWriteCombined : 0 ) );
#else
		cutilSafeCall( cudaMallocHost( (void**)&h_idata, memSize ) );
        cutilSafeCall( cudaMallocHost( (void**)&h_odata, memSize ) );
#endif
    }
    else
    {
        //pageable memory mode - use malloc
        h_idata = (unsigned char *)malloc( memSize );
        h_odata = (unsigned char *)malloc( memSize );
    }
    //initialize the memory
    for(unsigned int i = 0; i < memSize/sizeof(unsigned char); i++)
    {
        h_idata[i] = (unsigned char) (i & 0xff);
    }

    // allocate device memory
    unsigned char* d_idata;
    cutilSafeCall( cudaMalloc( (void**) &d_idata, memSize));

    //initialize the device memory
    cutilSafeCall( cudaMemcpy( d_idata, h_idata, memSize,
                                cudaMemcpyHostToDevice) );

    //copy data from GPU to Host
    cutilCheckError( cutStartTimer( timer));
    cutilSafeCall( cudaEventRecord( start, 0 ) );
    if( PINNED == memMode )
    {
        for( unsigned int i = 0; i < MEMCOPY_ITERATIONS; i++ )
        {
            cutilSafeCall( cudaMemcpyAsync( h_odata, d_idata, memSize,
                                    cudaMemcpyDeviceToHost, 0) );
        }
    }
    else
    {
        for( unsigned int i = 0; i < MEMCOPY_ITERATIONS; i++ )
        {
            cutilSafeCall( cudaMemcpy( h_odata, d_idata, memSize,
                                    cudaMemcpyDeviceToHost) );
        }
    }
    cutilSafeCall( cudaEventRecord( stop, 0 ) );

    // make sure GPU has finished copying
    cutilSafeCall( cudaThreadSynchronize() );
    //get the the total elapsed time in ms
    cutilCheckError( cutStopTimer( timer));
    cutilSafeCall( cudaEventElapsedTime( &elapsedTimeInMs, start, stop ) );
    if( PINNED != memMode || bDontUseGPUTiming )
    {
        elapsedTimeInMs = cutGetTimerValue( timer);
    }
    
    //calculate bandwidth in MB/s
    bandwidthInMBs = (1e3f * memSize * (float)MEMCOPY_ITERATIONS) / 
                                        (elapsedTimeInMs * (float)(1 << 20));

    //clean up memory
    cutilSafeCall( cudaEventDestroy(stop) );
    cutilSafeCall( cudaEventDestroy(start) );
    cutilCheckError( cutDeleteTimer( timer));
    if( PINNED == memMode )
    {
        cutilSafeCall( cudaFreeHost(h_idata) );
        cutilSafeCall( cudaFreeHost(h_odata) );
    }
    else
    {
        free(h_idata);
        free(h_odata);
    }
    cutilSafeCall(cudaFree(d_idata));
    
    return bandwidthInMBs;
}

///////////////////////////////////////////////////////////////////////////////
//! test the bandwidth of a host to device memcopy of a specific size
///////////////////////////////////////////////////////////////////////////////
float
testHostToDeviceTransfer(unsigned int memSize, memoryMode memMode, bool wc)
{
    unsigned int timer = 0;
    float elapsedTimeInMs = 0.0f;
    float bandwidthInMBs = 0.0f;
    cudaEvent_t start, stop;
    cutilCheckError( cutCreateTimer( &timer ) );
    cutilSafeCall( cudaEventCreate( &start ) );
    cutilSafeCall( cudaEventCreate( &stop ) );

    //allocate host memory
    unsigned char *h_odata = NULL;
    if( PINNED == memMode )
    {
#if CUDART_VERSION >= 2020
        //pinned memory mode - use special function to get OS-pinned memory
        cutilSafeCall( cudaHostAlloc( (void**)&h_odata, memSize, (wc) ? cudaHostAllocWriteCombined : 0 ) );
#else
        //pinned memory mode - use special function to get OS-pinned memory
        cutilSafeCall( cudaMallocHost( (void**)&h_odata, memSize ) );
#endif
    }
    else
    {
        //pageable memory mode - use malloc
        h_odata = (unsigned char *)malloc( memSize );
    }
    unsigned char *h_cacheClear1 = (unsigned char *)malloc( CACHE_CLEAR_SIZE );
    unsigned char *h_cacheClear2 = (unsigned char *)malloc( CACHE_CLEAR_SIZE );
    //initialize the memory
    for(unsigned int i = 0; i < memSize/sizeof(unsigned char); i++)
    {
        h_odata[i] = (unsigned char) (i & 0xff);
    }
    for(unsigned int i = 0; i < CACHE_CLEAR_SIZE / sizeof(unsigned char); i++)
    {
        h_cacheClear1[i] = (unsigned char) (i & 0xff);
        h_cacheClear2[i] = (unsigned char) (0xff - (i & 0xff));
    }

    //allocate device memory
    unsigned char* d_idata;
    cutilSafeCall( cudaMalloc( (void**) &d_idata, memSize));

    cutilCheckError( cutStartTimer( timer));
    cutilSafeCall( cudaEventRecord( start, 0 ) );
    //copy host memory to device memory
    if( PINNED == memMode )
    {
        for(unsigned int i = 0; i < MEMCOPY_ITERATIONS; i++)
        {
            cutilSafeCall( cudaMemcpyAsync( d_idata, h_odata, memSize,
                                    cudaMemcpyHostToDevice, 0) );
        }
    }
    else {
        for(unsigned int i = 0; i < MEMCOPY_ITERATIONS; i++)
        {
            cutilSafeCall( cudaMemcpy( d_idata, h_odata, memSize,
                                    cudaMemcpyHostToDevice) );
        }
    }

    cutilSafeCall( cudaEventRecord( stop, 0 ) );
    cutilSafeCall( cudaThreadSynchronize() );
    //total elapsed time in ms
    cutilCheckError( cutStopTimer( timer));
    cutilSafeCall( cudaEventElapsedTime( &elapsedTimeInMs, start, stop ) );
    if ( PINNED != memMode || bDontUseGPUTiming )
    {
        elapsedTimeInMs = cutGetTimerValue( timer);
    }
    cutilCheckError( cutResetTimer( timer));
        
    //calculate bandwidth in MB/s
    bandwidthInMBs = (1e3f * memSize * (float)MEMCOPY_ITERATIONS) / 
                                        (elapsedTimeInMs * (float)(1 << 20));

    //clean up memory
    cutilSafeCall( cudaEventDestroy(stop) );
    cutilSafeCall( cudaEventDestroy(start) );
    cutilCheckError( cutDeleteTimer( timer));
    if( PINNED == memMode )
    {
        cutilSafeCall( cudaFreeHost(h_odata) );
    }
    else
    {
        free(h_odata);
    }
    free(h_cacheClear1);
    free(h_cacheClear2);
    cutilSafeCall(cudaFree(d_idata));

    return bandwidthInMBs;
}

///////////////////////////////////////////////////////////////////////////////
//! test the bandwidth of a device to device memcopy of a specific size
///////////////////////////////////////////////////////////////////////////////
float
testDeviceToDeviceTransfer(unsigned int memSize)
{
    unsigned int timer = 0;
    float elapsedTimeInMs = 0.0f;
    float bandwidthInMBs = 0.0f;
    cudaEvent_t start, stop;

    cutilCheckError( cutCreateTimer( &timer ) );
    cutilSafeCall( cudaEventCreate( &start ) );
    cutilSafeCall( cudaEventCreate( &stop ) );

    //allocate host memory
    unsigned char *h_idata = (unsigned char *)malloc( memSize );
    //initialize the host memory
    for(unsigned int i = 0; i < memSize/sizeof(unsigned char); i++)
    {
        h_idata[i] = (unsigned char) (i & 0xff);
    }

    //allocate device memory
    unsigned char *d_idata;
    cutilSafeCall( cudaMalloc( (void**) &d_idata, memSize));
    unsigned char *d_odata;
    cutilSafeCall( cudaMalloc( (void**) &d_odata, memSize));

    //initialize memory
    cutilSafeCall( cudaMemcpy( d_idata, h_idata, memSize,
                                cudaMemcpyHostToDevice) );

    //run the memcopy
    cutilCheckError( cutStartTimer( timer));
    cutilSafeCall( cudaEventRecord( start, 0 ) );
    for( unsigned int i = 0; i < MEMCOPY_ITERATIONS; i++ )
    {
        cutilSafeCall( cudaMemcpy( d_odata, d_idata, memSize,
                                cudaMemcpyDeviceToDevice) );
    }
    cutilSafeCall( cudaEventRecord( stop, 0 ) );
  
    //Since device to device memory copies are non-blocking,
    //cudaThreadSynchronize() is required in order to get
    //proper timing.
    cutilSafeCall( cudaThreadSynchronize() );

    //get the the total elapsed time in ms
    cutilCheckError( cutStopTimer( timer));
    cutilSafeCall( cudaEventElapsedTime( &elapsedTimeInMs, start, stop ) );
    if ( bDontUseGPUTiming )
    {
        elapsedTimeInMs = cutGetTimerValue( timer);
    }
    
    //calculate bandwidth in MB/s
    bandwidthInMBs = 2.0f * (1e3f * memSize * (float)MEMCOPY_ITERATIONS) / 
                                        (elapsedTimeInMs * (float)(1 << 20));
    
    //clean up memory
    cutilCheckError( cutDeleteTimer( timer));
    free(h_idata);
    cutilSafeCall(cudaEventDestroy(stop));
    cutilSafeCall(cudaEventDestroy(start));
    cutilSafeCall(cudaFree(d_idata));
    cutilSafeCall(cudaFree(d_odata));

    return bandwidthInMBs;
}

/////////////////////////////////////////////////////////
//print results in an easily read format
////////////////////////////////////////////////////////
void printResultsReadable(unsigned int *memSizes, float *bandwidths, unsigned int count)
{
    printf("Transfer Size (Bytes)\tBandwidth(MB/s)\n");
    for(unsigned int i = 0; i < count; i++)
    {
        printf("%9u\t\t%.1f\n", memSizes[i], bandwidths[i]);
    }
    printf("\n");
    fflush(stdout);
}

///////////////////////////////////////////////////////////////////////////
//print results in CSV format
///////////////////////////////////////////////////////////////////////////
void printResultsCSV(unsigned int *memSizes, float *bandwidths, unsigned int count)
{
    printf("Transfer size (Bytes),");
    for(unsigned int i = 0; i < count; i++)
    {
        printf("%u,", memSizes[i]);
    }
    printf("\n");

    printf("Bandwidth (MB/s),");
    for(unsigned int i = 0; i < count; i++)
    {
        printf("%.1f,", bandwidths[i]);
    }
    printf("\n\n");
    fflush(stdout);
}

///////////////////////////////////////////////////////////////////////////
//Print help screen
///////////////////////////////////////////////////////////////////////////
void printHelp(void)
{
    printf("Usage:  bandwidthTest [OPTION]...\n");
    printf("Test the bandwidth for device to host, host to device, and device to device transfers\n");
    printf("\n");
    printf("Example:  measure the bandwidth of device to host pinned memory copies in the range 1024 Bytes to 102400 Bytes in 1024 Byte increments\n");
    printf("./bandwidthTest --memory=pinned --mode=range --start=1024 --end=102400 --increment=1024 --dtoh\n");

    printf("\n");
    printf("Options:\n");
    printf("--help\tDisplay this help menu\n");
    printf("--csv\tPrint results as a CSV\n");
    printf("--device=[deviceno]\tSpecify the device device to be used\n");
    printf("  all - compute cumulative bandwidth on all the devices\n");
    printf("  0,1,2,...,n - Specify any particular device to be used\n");
    printf("--memory=[MEMMODE]\tSpecify which memory mode to use\n");
    printf("  pageable - pageable memory\n");
    printf("  pinned   - non-pageable system memory\n");
    printf("--mode=[MODE]\tSpecify the mode to use\n");
    printf("  quick - performs a quick measurement\n");
    printf("  range - measures a user-specified range of values\n");
    printf("  shmoo - performs an intense shmoo of a large range of values\n");

    printf("--htod\tMeasure host to device transfers\n");   
    printf("--dtoh\tMeasure device to host transfers\n");
    printf("--dtod\tMeasure device to device transfers\n");
#if CUDART_VERSION >= 2020
	printf("--wc\tAllocate pinned memory as write-combined\n");
#endif
    printf("--cputiming\tForce CPU-based timing always\n");
    
    printf("Range mode options\n");
    printf("--start=[SIZE]\tStarting transfer size in bytes\n");
    printf("--end=[SIZE]\tEnding transfer size in bytes\n");
    printf("--increment=[SIZE]\tIncrement size in bytes\n");
}
