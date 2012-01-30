/***************************************************************************
 *
 *            (C) Copyright 2010 The Board of Trustees of the
 *                        University of Illinois
 *                         All Rights Reserved
 *
 ***************************************************************************/

#include <stdio.h>
#include <cuda.h>

#include "util.h"

__device__ void calculateBin (
        const unsigned int bin,
        uchar4 *sm_mapping)
{
        unsigned char offset  =  bin        %   4;
        unsigned char indexlo = (bin >>  2) % 256;
        unsigned char indexhi = (bin >> 10) %  KB;
        unsigned char block   =  bin / BINS_PER_BLOCK;

        offset *= 8;

        uchar4 sm;
        sm.x = block;
        sm.y = indexhi;
        sm.z = indexlo;
        sm.w = offset;

        *sm_mapping = sm;
}

__global__ void histo_intermediates_kernel (
        uint2 *input,
        unsigned int height,
        unsigned int width,
        unsigned int input_pitch,
        uchar4 *sm_mappings)
{
        unsigned int line = UNROLL * blockIdx.x;// 16 is the unroll factor;

        uint2 *load_bin = input + line * input_pitch + threadIdx.x;

        unsigned int store = line * width + threadIdx.x;
        bool skip = (width % 2) && (threadIdx.x == (blockDim.x - 1));

        #pragma unroll
        for (int i = 0; i < UNROLL; i++)
        {
                uint2 bin_value = *load_bin;

                calculateBin (
                        bin_value.x,
                        &sm_mappings[store]
                );

                if (!skip) calculateBin (
                        bin_value.y,
                        &sm_mappings[store + blockDim.x]
                );

                load_bin += input_pitch;
                store += width;
        }
}
