/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <cuda.h>

#include "util.h"

__global__ void histo_prescan_kernel (unsigned int* input, int size, unsigned int* minmax)
{
    __shared__ float Avg[PRESCAN_THREADS];
    __shared__ float StdDev[PRESCAN_THREADS];

    int stride = size/gridDim.x;
    int addr = blockIdx.x*stride+threadIdx.x;
    int end = blockIdx.x*stride + stride/8; // Only sample 1/8th of the input data

    // Compute the average per thread
    float avg = 0.0;
    unsigned int count = 0;
    while (addr < end){
        avg += input[addr];
        count++;
	addr += blockDim.x;
    }
    avg /= count;
    Avg[threadIdx.x] = avg;

    // Compute the standard deviation per thread
    int addr2 = blockIdx.x*stride+threadIdx.x;
    float stddev = 0;
    while (addr2 < end){
        stddev += (input[addr2]-avg)*(input[addr2]-avg);
        addr2 += blockDim.x;
    }
    stddev /= count;
    StdDev[threadIdx.x] = sqrtf(stddev);

#define SUM(stride__)\
if(threadIdx.x < stride__){\
    Avg[threadIdx.x] += Avg[threadIdx.x+stride__];\
    StdDev[threadIdx.x] += StdDev[threadIdx.x+stride__];\
}

    // Add all the averages and standard deviations from all the threads
    // and take their arithmetic average (as a simplified approximation of the
    // real average and standard deviation.
#if (PRESCAN_THREADS >= 32)    
    for (int stride = PRESCAN_THREADS/2; stride >= 32; stride = stride >> 1){
	__syncthreads();
	SUM(stride);
    }
#endif
#if (PRESCAN_THREADS >= 16)
    SUM(16);
#endif
#if (PRESCAN_THREADS >= 8)
    SUM(8);
#endif
#if (PRESCAN_THREADS >= 4)
    SUM(4);
#endif
#if (PRESCAN_THREADS >= 2)
    SUM(2);
#endif

    if (threadIdx.x == 0){
        float avg = Avg[0]+Avg[1];
	avg /= PRESCAN_THREADS;
	float stddev = StdDev[0]+StdDev[1];
	stddev /= PRESCAN_THREADS;

        // Take the maximum and minimum range from all the blocks. This will
        // be the final answer. The standard deviation is taken out to 10 sigma
        // away from the average. The value 10 was obtained empirically.
	    atomicMin(minmax,((unsigned int)(avg-10*stddev))/(KB*1024));
        atomicMax(minmax+1,((unsigned int)(avg+10*stddev))/(KB*1024));
    }
}
