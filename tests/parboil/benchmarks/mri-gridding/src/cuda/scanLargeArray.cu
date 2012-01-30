/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 1024
#define GRID_SIZE 65535
#define NUM_BANKS 16
#define LOG_NUM_BANKS 4

#define CONFLICT_FREE_OFFSET(index) ((index) >> LOG_NUM_BANKS + (index) >> (2*LOG_NUM_BANKS))
#define EXPANDED_SIZE(__x) (__x+(__x>>LOG_NUM_BANKS)+(__x>>(2*LOG_NUM_BANKS)))

////////////////////////////////////////////////////////////////////////////////
// Kernels
////////////////////////////////////////////////////////////////////////////////
__global__ void scan_L1_kernel(unsigned int n, unsigned int* data, unsigned int* inter)
{
    __shared__ unsigned int s_data[EXPANDED_SIZE(BLOCK_SIZE)]; 

    unsigned int thid = threadIdx.x;
    unsigned int g_ai = blockIdx.x*2*blockDim.x + threadIdx.x;
    unsigned int g_bi = g_ai + blockDim.x;

    unsigned int s_ai = thid;
    unsigned int s_bi = thid + blockDim.x;

    s_ai += CONFLICT_FREE_OFFSET(s_ai);
    s_bi += CONFLICT_FREE_OFFSET(s_bi);

    s_data[s_ai] = (g_ai < n) ? data[g_ai] : 0;
    s_data[s_bi] = (g_bi < n) ? data[g_bi] : 0;

    unsigned int stride = 1;
    for (unsigned int d = blockDim.x; d > 0; d >>= 1)
    {
        __syncthreads();

        if (thid < d)
        {
            unsigned int i  = 2*stride*thid;
            unsigned int ai = i + stride - 1;
            unsigned int bi = ai + stride;

            ai += CONFLICT_FREE_OFFSET(ai);
            bi += CONFLICT_FREE_OFFSET(bi);

            s_data[bi] += s_data[ai];
        }

        stride *= 2;
    }

    if (thid == 0){
        unsigned int last = blockDim.x*2 -1;
        last += CONFLICT_FREE_OFFSET(last);
        inter[blockIdx.x] = s_data[last];
        s_data[last] = 0;
    }

    for (unsigned int d = 1; d <= blockDim.x; d *= 2)
    {
        stride >>= 1;

        __syncthreads();

        if (thid < d)
        {
            unsigned int i  = 2*stride*thid;
            unsigned int ai = i + stride - 1;
            unsigned int bi = ai + stride;

            ai += CONFLICT_FREE_OFFSET(ai);
            bi += CONFLICT_FREE_OFFSET(bi);

            unsigned int t  = s_data[ai];
            s_data[ai] = s_data[bi];
            s_data[bi] += t;
        }
    }
    __syncthreads();

    if (g_ai < n) { data[g_ai] = s_data[s_ai]; }
    if (g_bi < n) { data[g_bi] = s_data[s_bi]; }
}

__global__ void scan_inter1_kernel(unsigned int* data, unsigned int iter)
{
    extern __shared__ unsigned int s_data[];

    unsigned int thid = threadIdx.x;
    unsigned int gthid = (blockIdx.x*blockDim.x + threadIdx.x);
    unsigned int gi = 2*iter*gthid;
    unsigned int g_ai = gi + iter - 1;
    unsigned int g_bi = g_ai + iter;

    unsigned int s_ai = 2*thid;
    unsigned int s_bi = 2*thid + 1;

    s_ai += CONFLICT_FREE_OFFSET(s_ai);
    s_bi += CONFLICT_FREE_OFFSET(s_bi);

    s_data[s_ai] = data[g_ai];
    s_data[s_bi] = data[g_bi];

    unsigned int stride = 1;
    for (unsigned int d = blockDim.x; d > 0; d >>= 1)
    {
        __syncthreads();

        if (thid < d)
        {
            unsigned int i  = 2*stride*thid;
            unsigned int ai = i + stride - 1;
            unsigned int bi = ai + stride;

            ai += CONFLICT_FREE_OFFSET(ai);
            bi += CONFLICT_FREE_OFFSET(bi);
            s_data[bi] += s_data[ai];
        }

        stride *= 2;
    }

    __syncthreads();

    data[g_ai] = s_data[s_ai];
    data[g_bi] = s_data[s_bi];
}

__global__ void scan_inter2_kernel(unsigned int* data, unsigned int iter)
{
    extern __shared__ unsigned int s_data[];

    unsigned int thid = threadIdx.x;
    unsigned int gthid = (blockIdx.x*blockDim.x + threadIdx.x);
    unsigned int gi = 2*iter*gthid;
    unsigned int g_ai = gi + iter - 1;
    unsigned int g_bi = g_ai + iter;

    unsigned int s_ai = 2*thid;
    unsigned int s_bi = 2*thid + 1;

    s_ai += CONFLICT_FREE_OFFSET(s_ai);
    s_bi += CONFLICT_FREE_OFFSET(s_bi);

    s_data[s_ai] = data[g_ai];
    s_data[s_bi] = data[g_bi];

    unsigned int stride = blockDim.x*2;

    for (unsigned int d = 1; d <= blockDim.x; d *= 2)
    {
        stride >>= 1;

        __syncthreads();

        if (thid < d)
        {
            unsigned int i  = 2*stride*thid;
            unsigned int ai = i + stride - 1;
            unsigned int bi = ai + stride;

            ai += CONFLICT_FREE_OFFSET(ai);
            bi += CONFLICT_FREE_OFFSET(bi);

            unsigned int t  = s_data[ai];
            s_data[ai] = s_data[bi];
            s_data[bi] += t;
        }
    }
    __syncthreads();

    data[g_ai] = s_data[s_ai];
    data[g_bi] = s_data[s_bi];
}

__global__ void uniformAdd(unsigned int n, unsigned int *data, unsigned int *inter)
{

    __shared__ unsigned int uni;
    if (threadIdx.x == 0) { uni = inter[blockIdx.x]; }
    __syncthreads();

    unsigned int g_ai = blockIdx.x*2*blockDim.x + threadIdx.x;
    unsigned int g_bi = g_ai + blockDim.x;

    if (g_ai < n) { data[g_ai] += uni; }
    if (g_bi < n) { data[g_bi] += uni; }
}

void scanLargeArray( unsigned int gridNumElements, unsigned int* data_d) {
    unsigned int gridNumElems = gridNumElements;    

    // allocate device memory input and output arrays
    unsigned int* inter_d = NULL;

    // Run the prescan
    unsigned int size = (gridNumElems+BLOCK_SIZE-1)/BLOCK_SIZE;

    unsigned int dim_block;
    unsigned int current_max = size*BLOCK_SIZE;
    for (int block_size = 128; block_size <= BLOCK_SIZE; block_size *= 2){
      unsigned int array_size = block_size;
      while(array_size < size){
        array_size *= block_size;
      }
      if (array_size <= current_max){
        current_max = array_size;
        dim_block = block_size;
      }
    }

    cudaMalloc( (void**) &inter_d, current_max*sizeof(unsigned int));
    cudaMemset (inter_d, 0, current_max*sizeof(unsigned int));

    for (unsigned int i=0; i < (size+GRID_SIZE-1)/GRID_SIZE; i++){
        unsigned int gridSize = ((size-(i*GRID_SIZE)) > GRID_SIZE) ? GRID_SIZE : (size-i*GRID_SIZE);
        unsigned int numElems = ((gridNumElems-(i*GRID_SIZE*BLOCK_SIZE)) > (GRID_SIZE*BLOCK_SIZE)) ? (GRID_SIZE*BLOCK_SIZE) : (gridNumElems-(i*GRID_SIZE*BLOCK_SIZE));

        dim3 block (BLOCK_SIZE/2);
        dim3 grid (gridSize);
        scan_L1_kernel<<<grid, block>>>(numElems, data_d+(i*GRID_SIZE*BLOCK_SIZE), inter_d+(i*GRID_SIZE));
    }

    unsigned int stride = 1;
    for (unsigned int d = current_max; d > 1; d /= dim_block)
    {
        dim3 block (dim_block/2);
        dim3 grid (d/dim_block);

        scan_inter1_kernel<<<grid, block, EXPANDED_SIZE(dim_block)*sizeof(unsigned int)>>>(inter_d, stride);

        stride *= dim_block;
    }

    cudaMemset(&(inter_d[current_max-1]), 0, sizeof(unsigned int));

    for (unsigned int d = dim_block; d <= current_max; d *= dim_block)
    {
        stride /= dim_block;
        dim3 block (dim_block/2);
        dim3 grid (d/dim_block);

        scan_inter2_kernel<<<grid, block, EXPANDED_SIZE(dim_block)*sizeof(unsigned int)>>>(inter_d, stride);
    }

    for (unsigned int i=0; i < (size+GRID_SIZE-1)/GRID_SIZE; i++){
        unsigned int gridSize = ((size-(i*GRID_SIZE)) > GRID_SIZE) ? GRID_SIZE : (size-i*GRID_SIZE);
        unsigned int numElems = ((gridNumElems-(i*GRID_SIZE*BLOCK_SIZE)) > (GRID_SIZE*BLOCK_SIZE)) ? (GRID_SIZE*BLOCK_SIZE) : (gridNumElems-(i*GRID_SIZE*BLOCK_SIZE));

        dim3 block (BLOCK_SIZE/2);
        dim3 grid (gridSize);

        uniformAdd<<<grid, block>>>(numElems, data_d+(i*GRID_SIZE*BLOCK_SIZE), inter_d+(i*GRID_SIZE));
    }

    cudaFree(inter_d);
}
