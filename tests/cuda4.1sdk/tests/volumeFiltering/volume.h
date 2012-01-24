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

#ifndef _VOLUME_H_
#define _VOLUME_H_

#include <cuda_runtime_api.h>

typedef unsigned char VolumeType;

extern "C" {

  struct Volume{
    cudaArray*            content;
    cudaExtent            size;
    cudaChannelFormatDesc channelDesc;
  };

  void Volume_init(Volume* vol, cudaExtent size, void *data, int allowStore);
  void Volume_deinit(Volume* vol);

};

#endif

