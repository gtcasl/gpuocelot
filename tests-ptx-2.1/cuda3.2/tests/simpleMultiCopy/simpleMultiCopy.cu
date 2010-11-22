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
 * Quadro and Tesla GPUs with compute capability >= 2.0 can overlap two memcopies 
 * with kernel execution. This sample illustrates the usage of CUDA streams to 
 * achieve overlapping of kernel execution with copying data to and from the device. 
 *
 * Additionally, this sample uses CUDA events to measure elapsed time for
 * CUDA calls.  Events are a part of CUDA API and provide a system independent
 * way to measure execution times on CUDA devices with approximately 0.5 
 * microsecond precision.
 *
 * Elapsed times are averaged over nreps repetitions (10 by default).
 *
*/

const char *sSDKname = "simpleMultiCopy";

#include <stdio.h>
#include <cutil_inline.h>

#include <shrUtils.h>


__global__ void incKernel(int *g_out, int *g_in, int N, int inner_reps)
{ 
    int idx = blockIdx.x * blockDim.x + threadIdx.x;

    if( idx < N ) {
        for( int i=0; i<inner_reps; ++i ) {        
            g_out[idx] = g_in[idx] + 1;      
        }
    }
}

#define STREAM_COUNT 4


// Uncomment to simulate data source/sink IO times
//#define SIMULATE_IO


int *h_data_source;
int *h_data_sink;

int *h_data_in[STREAM_COUNT];
int *d_data_in[STREAM_COUNT];

int *h_data_out[STREAM_COUNT];
int *d_data_out[STREAM_COUNT];


cudaEvent_t cycleDone[STREAM_COUNT];
cudaStream_t stream[STREAM_COUNT];

cudaEvent_t start, stop;
    
int N = 1 << 22;
int nreps = 10;                 // number of times each experiment is repeated
int inner_reps = 5;

int memsize;

dim3 block(512);
dim3 grid;
    
int thread_blocks;


float processWithStreams(int streams_used);
void init();
bool test();


int main(int argc, char *argv[])
{
    int cuda_device = 0;
    float scale_factor;
    
    printf("[%s]\n", sSDKname);

    if(shrCheckCmdLineFlag(argc, (const char**)argv, "device"))
    {
       cuda_device = cutilDeviceInit(argc, argv);
       if (cuda_device < 0) {
          printf("exiting...\n");
		  cutilExit(argc, argv);
          exit(0);
      }
    }

    cudaDeviceProp deviceProp;	
    cutilSafeCall( cudaGetDeviceProperties(&deviceProp, cuda_device) );

    // Anything that is less than 4 SM's will have scaled down workload
    scale_factor = max((4.0f / (float)deviceProp.multiProcessorCount), 1.0f);
    N = (int)( (float)N / scale_factor );

    printf("> Device name: %s\n", deviceProp.name);
    printf("> CUDA Capability %d.%d hardware with %d multi-processors\n", 
		deviceProp.major, deviceProp.minor, 
		deviceProp.multiProcessorCount); 
    printf("> scale_factor = %.2f\n", 1.0f/scale_factor);
    printf("> array_size   = %d\n\n", N);

    memsize = N * sizeof(int);

    thread_blocks = N / block.x;
    
    grid.x = thread_blocks % 65535;
    grid.y = (thread_blocks / 65535 + 1);    
 

    // Allocate resources

    h_data_source = (int*) malloc(memsize);
    h_data_sink = (int*) malloc(memsize);    

    for( int i =0; i<STREAM_COUNT; ++i ) {
        
        CUDA_SAFE_CALL( cudaHostAlloc(&h_data_in[i], memsize, 
			cudaHostAllocDefault) );
        CUDA_SAFE_CALL( cudaMalloc(&d_data_in[i], memsize) );
        
        CUDA_SAFE_CALL( cudaHostAlloc(&h_data_out[i], memsize, 
			cudaHostAllocDefault) );
        CUDA_SAFE_CALL( cudaMalloc(&d_data_out[i], memsize) );

        
        CUDA_SAFE_CALL( cudaStreamCreate(&stream[i]) );
        CUDA_SAFE_CALL( cudaEventCreate(&cycleDone[i]) ); 
        
        cudaEventRecord(cycleDone[i], stream[i]);
    }

    cudaEventCreate(&start); cudaEventCreate(&stop);

    init();

    // Kernel warmup
    incKernel<<<grid, block>>>(d_data_out[0], d_data_in[0], N, inner_reps);

    
    // Time copies and kernel    
    cudaEventRecord(start,0);
    CUDA_SAFE_CALL( cudaMemcpyAsync(d_data_in[0], h_data_in[0], memsize, 
		cudaMemcpyHostToDevice,0) );
    cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
    
    float memcpy_h2d_time;    
    cudaEventElapsedTime(&memcpy_h2d_time, start, stop);

    
    cudaEventRecord(start,0);
    CUDA_SAFE_CALL( cudaMemcpyAsync(h_data_out[0], d_data_out[0], memsize, 
		cudaMemcpyDeviceToHost, 0) );        
    cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
    
    float memcpy_d2h_time;    
    cudaEventElapsedTime(&memcpy_d2h_time, start, stop);
    
    cudaEventRecord(start,0);
    incKernel<<<grid, block,0,0>>>(d_data_out[0], d_data_in[0], N, inner_reps);
    cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
    
    float kernel_time;    
    cudaEventElapsedTime(&kernel_time, start, stop);
    
    printf("Measured timings (throughput):\n");
    printf(" Memcpy host to device\t: %f ms (%f GB/s)\n", 
		memcpy_h2d_time, (memsize * 1e-6)/ memcpy_h2d_time );
    printf(" Memcpy device to host\t: %f ms (%f GB/s)\n", 
		memcpy_d2h_time, (memsize * 1e-6)/ memcpy_d2h_time);
    printf(" Kernel\t\t\t: %f ms (%f GB/s)\n", 
		kernel_time, (inner_reps * memsize * 2e-6)/ kernel_time);
	
    int type=0;
    if( deviceProp.major == 2 && strstr(deviceProp.name, "GeForce") == 0 )
        type = 2;
    else if( deviceProp.deviceOverlap )
        type = 1;

    printf("\nTheoretical limits for overlaps (* capability of this device):\n");
    printf(" %s        c <  1.0 \t: %f ms (No overlap, fully serial)\n", 
		type == 0 ? "*" : " ", memcpy_h2d_time + memcpy_d2h_time + kernel_time);
    printf(" %s 1.1 <= c <  2.0 \t: %f ms (Compute overlaps with one memcopy)\n",
		type == 1 ? "*" : " ", max((memcpy_h2d_time + memcpy_d2h_time), kernel_time));
    printf(" %s        c >= 2.0 \t: %f ms (Compute overlaps with two memcopies)\n",
		type == 2 ? "*" : " ", max(max(memcpy_h2d_time,memcpy_d2h_time), kernel_time));

	// Process pipelined work
    float serial_time = processWithStreams(1);  
    float overlap_time = processWithStreams(STREAM_COUNT);  

    printf("\nAverage measured timings over %d repetitions:\n", nreps);
    printf(" Avg. time when execution fully serialized\t: %f ms\n", 
		serial_time / nreps);
    printf(" Avg. time when overlapped using %d streams\t: %f ms\n", 
		STREAM_COUNT, overlap_time / nreps);
    printf(" Avg. latency hidden (serialized - overlapped)\t: %f ms\n", 
		(serial_time - overlap_time) / nreps);

    printf("\nMeasured throughput:\n");    
    printf(" Fully serialized execution\t\t: %f GB/s\n", 
		(nreps * (memsize * 2e-6))/ serial_time);
    printf(" Overlapped using %d streams\t\t: %f GB/s\n", 
		STREAM_COUNT, (nreps * (memsize * 2e-6))/ overlap_time);
    
    // Test result
    
    if(test())	
        printf("\nPASSED\n");
    else
        printf("\nFAILED\n");


    // Free resources

    free( h_data_source );
    free( h_data_sink );

    for( int i =0; i<STREAM_COUNT; ++i ) {
        
        cudaFreeHost(h_data_in[i]);
        cudaFree(d_data_in[i]);

        cudaFreeHost(h_data_out[i]);
        cudaFree(d_data_out[i]);
        
        cudaStreamDestroy(stream[i]);
        cudaEventDestroy(cycleDone[i]);        
    }
    
    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    
    cudaThreadExit();

    cutilExit(argc, argv);

    return 0;
}

float processWithStreams(int streams_used) {
    
    int current_stream = 0;

    float time;

    // Do processing in a loop
    //
    // Note: All memory commands are processed in the order  they are issued, 
    // independent of the stream they are enqueued in. Hence the pattern by 
    // which the copy and kernel commands are enqueued in the stream 
    // has an influence on the achieved overlap.

    cudaEventRecord(start, 0);
    for( int i=0; i<nreps; ++i ) {
        int next_stream = (current_stream + 1 ) % streams_used;

#ifdef SIMULATE_IO
        // Store the result
        memcpy(h_data_sink, h_data_out[current_stream],memsize);            

        // Read new input        
        memcpy(h_data_in[next_stream], h_data_source, memsize);
#endif

        // Ensure that processing and copying of the last cycle has finished
        cudaEventSynchronize(cycleDone[next_stream]);

        // Process current frame
        incKernel<<<grid, block, 0, stream[current_stream]>>>(
			d_data_out[current_stream],
			d_data_in[current_stream], 
			N, 
			inner_reps);
        
        // Upload next frame
        CUDA_SAFE_CALL( cudaMemcpyAsync(
			d_data_in[next_stream], 
			h_data_in[next_stream], 
			memsize, 
			cudaMemcpyHostToDevice, 
			stream[next_stream]) );

        // Download current frame
        CUDA_SAFE_CALL( cudaMemcpyAsync(
			h_data_out[current_stream], 
			d_data_out[current_stream], 
			memsize, 
			cudaMemcpyDeviceToHost, 
			stream[current_stream]) );    
        
        CUDA_SAFE_CALL( cudaEventRecord(
			cycleDone[current_stream], 
			stream[current_stream]) );
        
        current_stream = next_stream;
    }
    cudaEventRecord(stop, 0);    

    cudaThreadSynchronize();

    cudaEventElapsedTime(&time, start, stop);

    return time;

}

void init() {    
    for( int i=0; i<N; ++i) {        
        h_data_source[i] = 0;
    }
    
    for( int i =0; i<STREAM_COUNT; ++i ) {
        memcpy(h_data_in[i], h_data_source, memsize);        
    }
}


bool test() {

    bool passed = true;

    for( int j =0; j<STREAM_COUNT; ++j ) {
        for( int i =0; i<N; ++i ) {
            passed &= (h_data_out[j][i] == 1);
        }
    }

    return passed;
}
