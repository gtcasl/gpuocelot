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

#ifndef _SIMPLETEXTURE_KERNEL_H_
#define _SIMPLETEXTURE_KERNEL_H_

// declare texture reference for 2D float texture
texture<float, 2, cudaReadModeElementType> tex;
surface<void, 2> output_surface;

////////////////////////////////////////////////////////////////////////////////
//! Write to a cuArray (texture data source) using surface writes
//! @param g_idata input data in global memory
////////////////////////////////////////////////////////////////////////////////
__global__ void
surfaceWriteKernel( float* g_idata, int width, int height) 
{
    // calculate surface coordinates
    unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
    unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;

    // read from global memory and write to cuarray (via surface reference)
    surf2Dwrite(g_idata[y*width+x], output_surface, x*4, y, cudaBoundaryModeTrap);
}

////////////////////////////////////////////////////////////////////////////////
//! Transform an image using texture lookups
//! @param g_odata  output data in global memory
////////////////////////////////////////////////////////////////////////////////
__global__ void
transformKernel( float* g_odata, int width, int height, float theta) 
{
    // calculate normalized texture coordinates
    unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
    unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;

    float u = x / (float) width;
    float v = y / (float) height;

    // transform coordinates
    u -= 0.5f;
    v -= 0.5f;
    float tu = u*cosf(theta) - v*sinf(theta) + 0.5f;
    float tv = v*cosf(theta) + u*sinf(theta) + 0.5f;

    // read from texture and write to global memory
    g_odata[y*width + x] = tex2D(tex, tu, tv);
}

#endif // #ifndef _SIMPLETEXTURE_KERNEL_H_
