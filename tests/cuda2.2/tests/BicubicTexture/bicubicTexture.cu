/*
 * Copyright 1993-2006 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:   
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and 
 * international Copyright laws.  
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE 
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR 
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF 
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.   
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL, 
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS 
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE 
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE 
 * OR PERFORMANCE OF THIS SOURCE CODE.  
 *
 * U.S. Government End Users.  This source code is a "commercial item" as 
 * that term is defined at 48 C.F.R. 2.101 (OCT 1995), consisting  of 
 * "commercial computer software" and "commercial computer software 
 * documentation" as such terms are used in 48 C.F.R. 12.212 (SEPT 1995) 
 * and is provided to the U.S. Government only as a commercial end item.  
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through 
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the 
 * source code with only those rights set forth herein.
 */

#ifndef _BICUBICTEXTURE_CU_
#define _BICUBICTEXTURE_CU_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cutil_inline.h>
#include <cutil_math.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#include <tests/BicubicTexture/bicubicTexture_kernel.cuh>

cudaArray *d_imageArray = 0;

extern "C"
void initTexture(int imageWidth, int imageHeight, uchar *h_data)
{
    // allocate array and copy image data
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsigned);
    cutilSafeCall( cudaMallocArray(&d_imageArray, &channelDesc, imageWidth, imageHeight) ); 
    uint size = imageWidth * imageHeight * sizeof(uchar);
    cutilSafeCall( cudaMemcpyToArray(d_imageArray, 0, 0, h_data, size, cudaMemcpyHostToDevice) );
    cutFree(h_data);

    // set texture parameters
    tex.addressMode[0] = cudaAddressModeClamp;
    tex.addressMode[1] = cudaAddressModeClamp;
    tex.filterMode = cudaFilterModeLinear;
    tex.normalized = false;    // access with integer texture coordinates

    // Bind the array to the texture
    cutilSafeCall( cudaBindTextureToArray(tex, d_imageArray, channelDesc) );
}

extern "C"
void freeTexture()
{
    cutilSafeCall(cudaFreeArray(d_imageArray));
}


// render image using CUDA
extern "C" 
void render(int width, int height, float tx, float ty, float scale, float cx, float cy, 
            dim3 blockSize, dim3 gridSize, int mode, uchar4 *output)
{
    // call CUDA kernel, writing results to PBO memory
    switch(mode) {
    case MODE_NEAREST:
        tex.filterMode = cudaFilterModePoint;
        d_render<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    case MODE_BILINEAR:
        tex.filterMode = cudaFilterModeLinear;
        d_render<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    case MODE_BICUBIC:
        tex.filterMode = cudaFilterModePoint;
        d_renderBicubic<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    case MODE_FAST_BICUBIC:
        tex.filterMode = cudaFilterModeLinear;
        d_renderFastBicubic<<<gridSize, blockSize>>>(output, width, height, tx, ty, scale, cx, cy);
        break;
    }
    cutilCheckMsg("kernel failed");
}

#endif
