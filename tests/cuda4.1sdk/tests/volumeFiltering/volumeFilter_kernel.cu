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

#ifndef _VOLUMEFILTER_KERNEL_CU_
#define _VOLUMEFILTER_KERNEL_CU_

#include <cutil_inline.h>    // includes cuda.h and cuda_runtime_api.h
#include <cutil_math.h>
#include <volumeFilter.h>

typedef unsigned int  uint;
typedef unsigned char uchar;

typedef unsigned char VolumeType;


texture<uchar, 3, cudaReadModeNormalizedFloat>  volumeTexIn;
surface<void,  3>                               volumeTexOut;

__constant__ float4 c_filterData[VOLUMEFILTER_MAXWEIGHTS];

__global__ void
d_filter_surface3d(int filterSize, float filter_offset,
           cudaExtent volumeSize)
{
  int x = blockIdx.x*blockDim.x + threadIdx.x;
  int y = blockIdx.y*blockDim.y + threadIdx.y;
  int z = blockIdx.z*blockDim.z + threadIdx.z;
  if (x >= volumeSize.width || y >= volumeSize.height || z >= volumeSize.depth){
    return;
  }

  float filtered = 0;
  float4 basecoord = make_float4(x,y,z,0);
  for (int i = 0; i < filterSize; i++){
    float4 coord = basecoord + c_filterData[i];
    filtered  += tex3D(volumeTexIn,coord.x,coord.y,coord.z) * c_filterData[i].w;
  }

  filtered    += filter_offset;
  
  uchar output = uint(__saturatef(filtered)*255);
  
  surf3Dwrite(output,volumeTexOut,x,y,z);

}

static int iDivUp(int a, int b){
  return (a % b != 0) ? (a / b + 1) : (a / b);
}

extern "C"
Volume* VolumeFilter_runFilter(Volume *input, Volume *output0, Volume *output1, int iterations, int numWeights, float4 *weights, float postWeightOffset)
{
  Volume* swap = 0;
  cudaExtent size = input->size;
  unsigned int dim = 32/sizeof(VolumeType);
  dim3 blockSize(dim,dim,1);
  dim3 gridSize(iDivUp(size.width,blockSize.x),iDivUp(size.height,blockSize.y),iDivUp(size.depth,blockSize.z));

  // set weights
  cutilSafeCall( cudaMemcpyToSymbol(c_filterData, weights, sizeof(float4)*numWeights) );

  for (int i = 0; i < iterations; i++){
    // bind array to 3D texture
    cutilSafeCall(cudaBindTextureToArray(volumeTexIn, input->content, input->channelDesc));
    cutilSafeCall(cudaBindSurfaceToArray(volumeTexOut,output0->content));

    d_filter_surface3d<<<gridSize, blockSize>>>( numWeights,postWeightOffset, size);

    cutilCheckMsg("filter kernel failed");

    swap = input;
    input = output0;
    output0 = swap;
    if (i == 0){
      output0 = output1;
    }
  }
  return input;
}
#endif

