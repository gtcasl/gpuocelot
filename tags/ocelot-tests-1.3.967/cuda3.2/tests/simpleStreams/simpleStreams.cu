/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 *
 *
 * This sample illustrates the usage of CUDA streams for overlapping
 * kernel execution with device/host memcopies.  The kernel is used to 
 * initialize an array to a specific value, after which the array is 
 * copied to the host (CPU) memory.  To increase performance, multiple 
 * kernel/memcopy pairs are launched asynchronously, each pair in its 
 * own stream.  Devices with Compute Capability 1.1 can overlap a kernel
 * and a memcopy as long as they are issued in different streams.  Kernels
 * are serialized.  Thus, if n pairs are launched, streamed approach
 * can reduce the memcopy cost to the (1/n)th of a single copy of the entire
 * data set.
 *
 * Additionally, this sample uses CUDA events to measure elapsed time for
 * CUDA calls.  Events are a part of CUDA API and provide a system independent
 * way to measure execution times on CUDA devices with approximately 0.5 
 * microsecond precision.
 *
 * Elapsed times are averaged over nreps repetitions (10 by default).
 *
*/

const char *sSDKsample = "simpleStreams";

#include <stdio.h>
#include <cutil_inline.h>

__global__ void init_array(int *g_data, int *factor, int num_iterations)
{ 
   int idx = blockIdx.x * blockDim.x + threadIdx.x;

    for(int i=0;i<num_iterations;i++)
	    g_data[idx] += *factor;	// non-coalesced on purpose, to burn time
}

int correct_data(int *a, const int n, const int c)
{
    for(int i = 0; i < n; i++)
        if(a[i] != c)
		{
			printf("%d: %d %d\n", i, a[i], c);
            return 0;
		}

    return 1;
}

int main(int argc, char *argv[])
{
    int cuda_device = 0;
    int nstreams = 4;               // number of streams for CUDA calls
    int nreps = 10;                 // number of times each experiment is repeated
    int n = 16 * 1024 * 1024;       // number of ints in the data set
    int nbytes = n * sizeof(int);   // number of data bytes
    dim3 threads, blocks;           // kernel launch configuration
    float elapsed_time, time_memcpy, time_kernel;   // timing variables
    float scale_factor = 1.0f;

	int niterations;	// number of iterations for the loop inside the kernel

    printf("[ %s ]\n", sSDKsample);
    if( cutCheckCmdLineFlag( argc, (const char **)argv, "help") )
    {
        printf("Usage: %s [--use_blocking_sync]\n", sSDKsample);
        printf("\t--use_blocking_sync (optional) enable blocking sync to demontrate\n");
        printf("\t\t low CPU utilization\n");
        exit(0);
    }
    bool use_blocking_sync = false; 
    if( cutCheckCmdLineFlag( argc, (const char **)argv, "use_blocking_sync") )
    {
        printf("Enabling blocking sync, setting reps to 100 to demonstrate steady state\n");
        nreps = 100;
        use_blocking_sync = true;
    }

	printf("\n> ");
	cuda_device = cutilChooseCudaDevice(argc, argv);

    // check the compute capability of the device
    int num_devices=0;
    cutilSafeCall( cudaGetDeviceCount(&num_devices) );
    if(0==num_devices)
    {
        printf("your system does not have a CUDA capable device\n");
        return 1;
	}
	
    // check if the command-line chosen device ID is within range, exit if not
    if( cuda_device >= num_devices )
	{
        printf("cuda_device=%d is invalid, must choose device ID between 0 and %d\n", cuda_device, num_devices-1);
		cutilExit(argc, argv);
        return 1;
	}

    cudaSetDevice( cuda_device );

    if( use_blocking_sync ) {
        // enable use of blocking sync, to reduce CPU usage
        cudaSetDeviceFlags( cudaDeviceBlockingSync );
    }

    cudaDeviceProp deviceProp;
	
    cutilSafeCall( cudaGetDeviceProperties(&deviceProp, cuda_device) );
    if( (1 == deviceProp.major) && (deviceProp.minor < 1))
        printf("%s does not have compute capability 1.1 or later\n", deviceProp.name);
    if(deviceProp.major >= 2)
        niterations = 100;
    else
	{		    
	    if(deviceProp.minor > 1)
		niterations = 5;
	    else
		niterations = 1; // reduced workload for compute capability 1.0 and 1.1
	}

#ifdef __DEVICE_EMULATION__
    n = 4096;   // reduced workload for emulation (n should be divisible by 512*nstreams)
#else
    // Anything that is less than 4 SM's will be scaled down in terms of workload
    scale_factor = max((4.0f / (float)deviceProp.multiProcessorCount), 1.0f);
    n = rint( (float)n / scale_factor );
#endif

//	printf("> Device name : %s\n", deviceProp.name );
    printf("> CUDA Capable SM %d.%d hardware with %d multi-processors\n", deviceProp.major, deviceProp.minor, deviceProp.multiProcessorCount); 
    printf("> scale_factor = %1.4f\n", 1.0f/scale_factor);
    printf("> array_size   = %d\n\n", n);

    // allocate host memory
    int c = 5;                      // value to which the array will be initialized
    int *a = 0;                     // pointer to the array data in host memory
    // allocate host memory (pinned is required for achieve asynchronicity)
    cutilSafeCall( cudaMallocHost((void**)&a, nbytes) ); 

    // allocate device memory
    int *d_a = 0, *d_c = 0;             // pointers to data and init value in the device memory
    cutilSafeCall( cudaMalloc((void**)&d_a, nbytes) );
    cutilSafeCall( cudaMalloc((void**)&d_c, sizeof(int)) );
    cutilSafeCall( cudaMemcpy(d_c, &c, sizeof(int), cudaMemcpyHostToDevice) );

    // allocate and initialize an array of stream handles
    cudaStream_t *streams = (cudaStream_t*) malloc(nstreams * sizeof(cudaStream_t));
    for(int i = 0; i < nstreams; i++)
        cutilSafeCall( cudaStreamCreate(&(streams[i])) );

    // create CUDA event handles
    // use blocking sync
    cudaEvent_t start_event, stop_event;
    int eventflags = ( use_blocking_sync ? cudaEventBlockingSync: cudaEventDefault );

    cutilSafeCall( cudaEventCreateWithFlags(&start_event, eventflags) );
    cutilSafeCall( cudaEventCreateWithFlags(&stop_event, eventflags) );

    // time memcopy from device
    cudaEventRecord(start_event, 0);     // record in stream-0, to ensure that all previous CUDA calls have completed
    cudaMemcpyAsync(a, d_a, nbytes, cudaMemcpyDeviceToHost, streams[0]);
    cudaEventRecord(stop_event, 0);
    cudaEventSynchronize(stop_event);   // block until the event is actually recorded
    cutilSafeCall( cudaEventElapsedTime(&time_memcpy, start_event, stop_event) );
    printf("memcopy:\t%.2f\n", time_memcpy);
    
    // time kernel
    threads=dim3(512, 1);
    blocks=dim3(n / threads.x, 1);
    cudaEventRecord(start_event, 0);
    init_array<<<blocks, threads, 0, streams[0]>>>(d_a, d_c, niterations);
    cudaEventRecord(stop_event, 0);
    cudaEventSynchronize(stop_event);
    cutilSafeCall( cudaEventElapsedTime(&time_kernel, start_event, stop_event) );
    printf("kernel:\t\t%.2f\n", time_kernel);

    //////////////////////////////////////////////////////////////////////
    // time non-streamed execution for reference
    threads=dim3(512, 1);
    blocks=dim3(n / threads.x, 1);
    cudaEventRecord(start_event, 0);
    for(int k = 0; k < nreps; k++)
    {
        init_array<<<blocks, threads>>>(d_a, d_c, niterations);
        cudaMemcpy(a, d_a, nbytes, cudaMemcpyDeviceToHost);
    }
    cudaEventRecord(stop_event, 0);
    cudaEventSynchronize(stop_event);
    cutilSafeCall( cudaEventElapsedTime(&elapsed_time, start_event, stop_event) );
    printf("non-streamed:\t%.2f (%.2f expected)\n", elapsed_time / nreps, time_kernel + time_memcpy);

    //////////////////////////////////////////////////////////////////////
    // time execution with nstreams streams
    threads=dim3(512,1);
    blocks=dim3(n/(nstreams*threads.x),1);
    memset(a, 255, nbytes);     // set host memory bits to all 1s, for testing correctness
    cudaMemset(d_a, 0, nbytes); // set device memory to all 0s, for testing correctness
    cudaEventRecord(start_event, 0);
    for(int k = 0; k < nreps; k++)
    {
        // asynchronously launch nstreams kernels, each operating on its own portion of data
        for(int i = 0; i < nstreams; i++)
            init_array<<<blocks, threads, 0, streams[i]>>>(d_a + i * n / nstreams, d_c, niterations);

        // asynchronoously launch nstreams memcopies.  Note that memcopy in stream x will only
        //   commence executing when all previous CUDA calls in stream x have completed
        for(int i = 0; i < nstreams; i++)
            cudaMemcpyAsync(a + i * n / nstreams, d_a + i * n / nstreams, nbytes / nstreams, cudaMemcpyDeviceToHost, streams[i]);
    }
    cudaEventRecord(stop_event, 0);
    cudaEventSynchronize(stop_event);
    cutilSafeCall( cudaEventElapsedTime(&elapsed_time, start_event, stop_event) );
    printf("%d streams:\t%.2f (%.2f expected with compute capability 1.1 or later)\n", nstreams, elapsed_time / nreps, time_kernel + time_memcpy / nstreams);

    // check whether the output is correct
    printf("-------------------------------\n");
    if(correct_data(a, n, c*nreps*niterations))	// each element should have been incremented by c a total of npres*niterations times
        printf("PASSED\n");
    else
        printf("FAILED\n");

    // release resources
    for(int i = 0; i < nstreams; i++)
        cudaStreamDestroy(streams[i]);
    cudaEventDestroy(start_event);
    cudaEventDestroy(stop_event);
    cudaFreeHost(a);
    cudaFree(d_a);
    cudaFree(d_c);

    cudaThreadExit();

    cutilExit(argc, argv);

    return 0;
}
