/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

#include <cutil_inline.h>
#include <cutil_math.h>

#ifndef _GENERAL_CUDA_H
#define _GENERAL_CUDA_H

// RGBA version
// reads from 32-bit uint array holding 8-bit RGBA

// convert floating point rgba color to 32-bit integer
__device__ uint rgbaFloatToInt(float4 rgba)
{
    rgba.x = __saturatef(fabs(rgba.x));   // clamp to [0.0, 1.0]
    rgba.y = __saturatef(fabs(rgba.y));
    rgba.z = __saturatef(fabs(rgba.z));
    rgba.w = __saturatef(fabs(rgba.w));
    return (uint(rgba.w * 255.0f) << 24) | (uint(rgba.z * 255.0f) << 16) | (uint(rgba.y * 255.0f) << 8) | uint(rgba.x * 255.0f);
}

__device__ float4 rgbaIntToFloat(uint c)
{
    float4 rgba;
    rgba.x = (c & 0xff) * 0.003921568627f;       //  /255.0f;
    rgba.y = ((c>>8) & 0xff) * 0.003921568627f;  //  /255.0f;
    rgba.z = ((c>>16) & 0xff) * 0.003921568627f; //  /255.0f;
    rgba.w = ((c>>24) & 0xff) * 0.003921568627f; //  /255.0f;
    return rgba;
}

/*
    Because a 2D gaussian mask is symmetry in row and column,
    here only generate a 1D mask, and use the product by row 
    and column index later.

    1D gaussian distribution :
        g(x, d) -- C * exp(-x^2/d^2), C is a constant amplifier

    parameters:
    og - output gaussian array in global memory
    delta - the 2nd parameter 'd' in the above function
    radius - half of the filter size
             (total filter size = 2 * radius + 1)
*/
//use only one block
__global__ void
d_generate_gaussian(float *og, float delta, int radius)
{
    int x = threadIdx.x - radius;
    og[threadIdx.x] = __expf(-(x * x) /
        (2 * delta * delta));
}                                     

/*
    Euclidean Distance (x, y, d) = exp((|x - y| / d)^2 / 2)
*/
__device__ float euclideanLen(float4 a, float4 b, float d)
{

    float mod = (b.x - a.x) * (b.x - a.x) +
                (b.y - a.y) * (b.y - a.y) +
                (b.z - a.z) * (b.z - a.z) +
                (b.w - a.w) * (b.w - a.w);

    return __expf(-mod / (2 * d * d));
}

extern "C"
void copyImage(uint *h_src, uint *d_dest,
               int width, int height)
{
    cutilSafeCall(cudaMemcpy(d_dest, h_src, width * height * sizeof(uint), cudaMemcpyHostToDevice));
}

#endif


