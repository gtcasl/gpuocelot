/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include <cuda.h>
#include <stdio.h>

#include "scanLargeArray.h"

#define UINT32_MAX 4294967295
#define BITS 4
#define LNB 4

#define SORT_BS 256

#define CONFLICT_FREE_OFFSET(index) ((index) >> LNB + (index) >> (2*LNB))
#define BLOCK_P_OFFSET (4*SORT_BS+1+(4*SORT_BS+1)/16+(4*SORT_BS+1)/64)

__device__ void scan (unsigned int s_data[BLOCK_P_OFFSET]){
  unsigned int thid = threadIdx.x;

  __syncthreads();

  s_data[2*thid+1+CONFLICT_FREE_OFFSET(2*thid+1)] += s_data[2*thid+CONFLICT_FREE_OFFSET(2*thid)];
  s_data[2*(blockDim.x+thid)+1+CONFLICT_FREE_OFFSET(2*(blockDim.x+thid)+1)] += s_data[2*(blockDim.x+thid)+CONFLICT_FREE_OFFSET(2*(blockDim.x+thid))];

  unsigned int stride = 2;
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
    unsigned int last = 4*blockDim.x-1;
    last += CONFLICT_FREE_OFFSET(last);
    s_data[4*blockDim.x+CONFLICT_FREE_OFFSET(4*blockDim.x)] = s_data[last];
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

  unsigned int temp = s_data[2*thid+CONFLICT_FREE_OFFSET(2*thid)];
  s_data[2*thid+CONFLICT_FREE_OFFSET(2*thid)] = s_data[2*thid+1+CONFLICT_FREE_OFFSET(2*thid+1)];
  s_data[2*thid+1+CONFLICT_FREE_OFFSET(2*thid+1)] += temp;

  unsigned int temp2 = s_data[2*(blockDim.x+thid)+CONFLICT_FREE_OFFSET(2*(blockDim.x+thid))];
  s_data[2*(blockDim.x+thid)+CONFLICT_FREE_OFFSET(2*(blockDim.x+thid))] = s_data[2*(blockDim.x+thid)+1+CONFLICT_FREE_OFFSET(2*(blockDim.x+thid)+1)];
  s_data[2*(blockDim.x+thid)+1+CONFLICT_FREE_OFFSET(2*(blockDim.x+thid)+1)] += temp2;

  __syncthreads();
}

__global__ static void splitSort(int numElems, int iter, unsigned int* keys, unsigned int* values, unsigned int* histo)
{
    __shared__ unsigned int flags[BLOCK_P_OFFSET];
    __shared__ unsigned int histo_s[1<<BITS];

    const unsigned int tid = threadIdx.x;
    const unsigned int gid = blockIdx.x*4*SORT_BS+4*threadIdx.x;

    // Copy input to shared mem. Assumes input is always even numbered
    uint4 lkey = { UINT32_MAX, UINT32_MAX, UINT32_MAX, UINT32_MAX};
    uint4 lvalue;
    if (gid < numElems){
      lkey = *((uint4*)(keys+gid));
      lvalue = *((uint4*)(values+gid));
    }

    if(tid < (1<<BITS)){
      histo_s[tid] = 0;
    }
    __syncthreads();

    atomicAdd(histo_s+((lkey.x&((1<<(BITS*(iter+1)))-1))>>(BITS*iter)),1);
    atomicAdd(histo_s+((lkey.y&((1<<(BITS*(iter+1)))-1))>>(BITS*iter)),1);
    atomicAdd(histo_s+((lkey.z&((1<<(BITS*(iter+1)))-1))>>(BITS*iter)),1);
    atomicAdd(histo_s+((lkey.w&((1<<(BITS*(iter+1)))-1))>>(BITS*iter)),1);

    uint4 index = {4*tid, 4*tid+1, 4*tid+2, 4*tid+3};

    for (int i=BITS*iter; i<BITS*(iter+1);i++){
      const uint4 flag = {(lkey.x>>i)&0x1,(lkey.y>>i)&0x1,(lkey.z>>i)&0x1,(lkey.w>>i)&0x1};

      flags[index.x+CONFLICT_FREE_OFFSET(index.x)] = 1<<(16*flag.x);
      flags[index.y+CONFLICT_FREE_OFFSET(index.y)] = 1<<(16*flag.y);
      flags[index.z+CONFLICT_FREE_OFFSET(index.z)] = 1<<(16*flag.z);
      flags[index.w+CONFLICT_FREE_OFFSET(index.w)] = 1<<(16*flag.w);

      scan (flags);

      index.x = (flags[index.x+CONFLICT_FREE_OFFSET(index.x)]>>(16*flag.x))&0xFFFF;
      index.y = (flags[index.y+CONFLICT_FREE_OFFSET(index.y)]>>(16*flag.y))&0xFFFF;
      index.z = (flags[index.z+CONFLICT_FREE_OFFSET(index.z)]>>(16*flag.z))&0xFFFF;
      index.w = (flags[index.w+CONFLICT_FREE_OFFSET(index.w)]>>(16*flag.w))&0xFFFF;

      unsigned short offset = flags[4*blockDim.x+CONFLICT_FREE_OFFSET(4*blockDim.x)]&0xFFFF;
      index.x += (flag.x) ? offset : 0;
      index.y += (flag.y) ? offset : 0;
      index.z += (flag.z) ? offset : 0;
      index.w += (flag.w) ? offset : 0;

      __syncthreads();
    }

    // Write result.
    if (gid < numElems){
      keys[blockIdx.x*4*SORT_BS+index.x] = lkey.x;
      keys[blockIdx.x*4*SORT_BS+index.y] = lkey.y;
      keys[blockIdx.x*4*SORT_BS+index.z] = lkey.z;
      keys[blockIdx.x*4*SORT_BS+index.w] = lkey.w;

      values[blockIdx.x*4*SORT_BS+index.x] = lvalue.x;
      values[blockIdx.x*4*SORT_BS+index.y] = lvalue.y;
      values[blockIdx.x*4*SORT_BS+index.z] = lvalue.z;
      values[blockIdx.x*4*SORT_BS+index.w] = lvalue.w;
    }
    if (tid < (1<<BITS)){
      histo[gridDim.x*threadIdx.x+blockIdx.x] = histo_s[tid];
    }
}

__global__ void splitRearrange (int numElems, int iter, unsigned int* keys_i, unsigned int* keys_o, unsigned int* values_i, unsigned int* values_o, unsigned int* histo){
  __shared__ unsigned int histo_s[(1<<BITS)];
  __shared__ unsigned int array_s[4*SORT_BS];
  int index = blockIdx.x*4*SORT_BS + 4*threadIdx.x;

  if (threadIdx.x < (1<<BITS)){
    histo_s[threadIdx.x] = histo[gridDim.x*threadIdx.x+blockIdx.x];
  }

  uint4 mine, value;
  if (index < numElems){
    mine = *((uint4*)(keys_i+index));
    value = *((uint4*)(values_i+index));
  } else {
    mine.x = UINT32_MAX;
    mine.y = UINT32_MAX;
    mine.z = UINT32_MAX;
    mine.w = UINT32_MAX;
  }
  uint4 masks = {(mine.x&((1<<(BITS*(iter+1)))-1))>>(BITS*iter),
                 (mine.y&((1<<(BITS*(iter+1)))-1))>>(BITS*iter),
                 (mine.z&((1<<(BITS*(iter+1)))-1))>>(BITS*iter),
                 (mine.w&((1<<(BITS*(iter+1)))-1))>>(BITS*iter)};

  ((uint4*)array_s)[threadIdx.x] = masks;
  __syncthreads();

  uint4 new_index = {histo_s[masks.x],histo_s[masks.y],histo_s[masks.z],histo_s[masks.w]};

  int i = 4*threadIdx.x-1;
  while (i >= 0){
    if (array_s[i] == masks.x){
      new_index.x++;
      i--;
    } else {
      break;
    }
  }

  new_index.y = (masks.y == masks.x) ? new_index.x+1 : new_index.y;
  new_index.z = (masks.z == masks.y) ? new_index.y+1 : new_index.z;
  new_index.w = (masks.w == masks.z) ? new_index.z+1 : new_index.w;

  if (index < numElems){
    keys_o[new_index.x] = mine.x;
    values_o[new_index.x] = value.x;

    keys_o[new_index.y] = mine.y;
    values_o[new_index.y] = value.y;

    keys_o[new_index.z] = mine.z;
    values_o[new_index.z] = value.z;

    keys_o[new_index.w] = mine.w;
    values_o[new_index.w] = value.w;
  }
}

void sort (int numElems, unsigned int max_value, unsigned int* &dkeys, unsigned int* &dvalues){
  dim3 grid ((numElems+4*SORT_BS-1)/(4*SORT_BS));
  dim3 block (SORT_BS);

  unsigned int iterations = 0;
  while(max_value > 0){
    max_value >>= BITS;
    iterations++;
  }

  unsigned int *dhisto;
  unsigned int *dkeys_o, *dvalues_o;

  cudaMalloc((void**)&dhisto, (1<<BITS)*grid.x*sizeof(unsigned int));
  cudaMalloc((void**)&dkeys_o, numElems*sizeof(unsigned int));
  cudaMalloc((void**)&dvalues_o, numElems*sizeof(unsigned int));

  for (int i=0; i<iterations; i++){
    splitSort<<<grid,block>>>(numElems, i, dkeys, dvalues, dhisto);

    scanLargeArray(grid.x*(1<<BITS), dhisto);

    splitRearrange<<<grid,block>>>(numElems, i, dkeys, dkeys_o, dvalues, dvalues_o, dhisto);

    unsigned int* temp = dkeys;
    dkeys = dkeys_o;
    dkeys_o = temp;

    temp = dvalues;
    dvalues = dvalues_o;
    dvalues_o = temp;
  }

  cudaFree(dkeys_o);
  cudaFree(dvalues_o);
  cudaFree(dhisto);
}
