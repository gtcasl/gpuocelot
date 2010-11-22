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

#ifndef _BOXFILTER_KERNEL_H_
#define _BOXFILTER_KERNEL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cutil_inline.h>
#include <cutil_math.h>

texture<float, 2> tex;
texture<uchar4, 2, cudaReadModeNormalizedFloat> rgbaTex;

cudaArray* d_array, *d_tempArray;

/*
    Perform a fast box filter using the sliding window method.

    As the kernel moves from left to right, we add in the contribution of the new
    sample on the right, and subtract the value of the exiting sample on the left.
    This only requires 2 adds and a mul per output value, independent of the filter radius.
    The box filter is separable, so to perform a 2D box filter we perform the filter in
    the x direction, followed by the same filter in the y direction.
    Applying multiple iterations of the box filter converges towards a Gaussian blur.
    Using CUDA, rows or columns of the image are processed in parallel.
    This version duplicates edge pixels.

    Note that the x (row) pass suffers from uncoalesced global memory reads,
    since each thread is reading from a different row. For this reason it is
    better to use texture lookups for the x pass.
    The y (column) pass is perfectly coalesced.

    Parameters
    id - pointer to input data in global memory
    od - pointer to output data in global memory
    w  - image width
    h  - image height
    r  - filter radius

    e.g. for r = 2, w = 8:

    0 1 2 3 4 5 6 7
    x - -
    - x - -
    - - x - -
      - - x - -
        - - x - -
          - - x - -
            - - x -
              - - x
*/

// process row
__device__ void
d_boxfilter_x(float *id, float *od, int w, int h, int r)
{
    float scale = 1.0f / (2*r+1);

    float t;
    // do left edge
    t = id[0] * r;
    for (int x = 0; x < r+1; x++) {
        t += id[x];
    }
    od[0] = t * scale;

    for(int x = 1; x < r+1; x++) {
        t += id[x+r];
        t -= id[0];
        od[x] = t * scale;
    }
    
    // main loop
    for(int x = r+1; x < w-r; x++) {
        t += id[x+r];
        t -= id[x-r-1];
        od[x] = t * scale;
    }

    // do right edge
    for (int x = w-r; x < w; x++) {
        t += id[w-1];
        t -= id[x-r-1];
        od[x] = t * scale;
    }
}

// process column
__device__ void
d_boxfilter_y(float *id, float *od, int w, int h, int r)
{
    float scale = 1.0f / (2*r+1);
    
    float t;
    // do left edge
    t = id[0] * r;
    for (int y = 0; y < r+1; y++) {
        t += id[y*w];
    }
    od[0] = t * scale;

    for(int y = 1; y < r+1; y++) {
        t += id[(y+r)*w];
        t -= id[0];
        od[y*w] = t * scale;
    }
    
    // main loop
    for(int y = r+1; y < h-r; y++) {
        t += id[(y+r)*w];
        t -= id[((y-r)*w)-w];
        od[y*w] = t * scale;
    }

    // do right edge
    for (int y = h-r; y < h; y++) {
        t += id[(h-1)*w];
        t -= id[((y-r)*w)-w];
        od[y*w] = t * scale;
    }
}

__global__ void
d_boxfilter_x_global(float *id, float *od, int w, int h, int r)
{
	unsigned int y = blockIdx.x*blockDim.x + threadIdx.x;
    d_boxfilter_x(&id[y*w], &od[y*w], w, h, r);
}

__global__ void
d_boxfilter_y_global(float *id, float *od, int w, int h, int r)
{
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	d_boxfilter_y(&id[x], &od[x], w, h, r);
}

// texture version
// texture fetches automatically clamp to edge of image
__global__ void
d_boxfilter_x_tex(float *od, int w, int h, int r)
{
    float scale = 1.0f / (2*r+1);
	unsigned int y = blockIdx.x*blockDim.x + threadIdx.x;

    float t = 0.0f;
    for(int x=-r; x<=r; x++) {
        t += tex2D(tex, x, y);
    }
    od[y*w] = t * scale;

    for(int x=1; x<w; x++) {
        t += tex2D(tex, x + r, y);
        t -= tex2D(tex, x - r - 1, y);
        od[y*w+x] = t * scale;
    }
}

__global__ void
d_boxfilter_y_tex(float *od, int w, int h, int r)
{
    float scale = 1.0f / (2*r+1);
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;

    float t = 0.0f;
    for(int y=-r; y<=r; y++) {
        t += tex2D(tex, x, y);
    }
    od[x] = t * scale;

    for(int y=1; y<h; y++) {
        t += tex2D(tex, x, y + r);
        t -= tex2D(tex, x, y - r - 1);
        od[y*w+x] = t * scale;
    }
}

// RGBA version
// reads from 32-bit uint array holding 8-bit RGBA

// convert floating point rgba color to 32-bit integer
__device__ uint rgbaFloatToInt(float4 rgba)
{
    rgba.x = __saturatef(rgba.x);   // clamp to [0.0, 1.0]
    rgba.y = __saturatef(rgba.y);
    rgba.z = __saturatef(rgba.z);
    rgba.w = __saturatef(rgba.w);
    return (uint(rgba.w*255)<<24) | (uint(rgba.z*255)<<16) | (uint(rgba.y*255)<<8) | uint(rgba.x*255);
}

__device__ float4 rgbaIntToFloat(uint c)
{
    float4 rgba;
    rgba.x = (c & 0xff) / 255.0f;
    rgba.y = ((c>>8) & 0xff) / 255.0f;
    rgba.z = ((c>>16) & 0xff) / 255.0f;
    rgba.w = ((c>>24) & 0xff) / 255.0f;
    return rgba;
}

// row pass using texture lookups
__global__ void
d_boxfilter_rgba_x(uint *od, int w, int h, int r)
{
    float scale = 1.0f / (2*r+1);
	unsigned int y = blockIdx.x*blockDim.x + threadIdx.x;

    // as long as address is always less than height, we do work
    if (y < h) {
        float4 t = make_float4(0.0f);
        for(int x=-r; x<=r; x++) {
            t += tex2D(rgbaTex, x, y);
        }
        od[y*w] = rgbaFloatToInt(t * scale);

        for(int x=1; x<w; x++) {
            t += tex2D(rgbaTex, x + r, y);
            t -= tex2D(rgbaTex, x - r - 1, y);
            od[y*w+x] = rgbaFloatToInt(t * scale);
        }
    }
}

// column pass using coalesced global memory reads
__global__ void
d_boxfilter_rgba_y(uint *id, uint *od, int w, int h, int r)
{
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
    id = &id[x];
    od = &od[x];

    float scale = 1.0f / (2*r+1);
    
    float4 t;
    // do left edge
    t = rgbaIntToFloat(id[0]) * r;
    for (int y = 0; y < r+1; y++) {
        t += rgbaIntToFloat(id[y*w]);
    }
    od[0] = rgbaFloatToInt(t * scale);

    for(int y = 1; y < r+1; y++) {
        t += rgbaIntToFloat(id[(y+r)*w]);
        t -= rgbaIntToFloat(id[0]);
        od[y*w] = rgbaFloatToInt(t * scale);
    }
    
    // main loop
    for(int y = r+1; y < h-r; y++) {
        t += rgbaIntToFloat(id[(y+r)*w]);
        t -= rgbaIntToFloat(id[((y-r)*w)-w]);
        od[y*w] = rgbaFloatToInt(t * scale);
    }

    // do right edge
    for (int y = h-r; y < h; y++) {
        t += rgbaIntToFloat(id[(h-1)*w]);
        t -= rgbaIntToFloat(id[((y-r)*w)-w]);
        od[y*w] = rgbaFloatToInt(t * scale);
    }
}

extern "C" 
void initTexture(int width, int height, void *pImage)
{
    int size = width * height * sizeof(unsigned int);

    // copy image data to array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsigned);
    cutilSafeCall( cudaMallocArray  ( &d_array, &channelDesc, width, height )); 
    cutilSafeCall( cudaMemcpyToArray( d_array, 0, 0, pImage, size, cudaMemcpyHostToDevice));

    cutilSafeCall( cudaMallocArray  ( &d_tempArray,   &channelDesc, width, height )); 

    // set texture parameters
    tex.addressMode[0] = cudaAddressModeClamp;
    tex.addressMode[1] = cudaAddressModeClamp;
    tex.filterMode = cudaFilterModePoint;
    tex.normalized = true;

    // Bind the array to the texture
    cutilSafeCall( cudaBindTextureToArray(tex, d_array, channelDesc) );
}

extern "C"
void freeTextures()
{
    cutilSafeCall(cudaFreeArray(d_array));
    cutilSafeCall(cudaFreeArray(d_tempArray));

}


/*
    Perform 2D box filter on image using CUDA

    Parameters:
    d_src  - pointer to input image in device memory
    d_temp - pointer to temporary storage in device memory
    d_dest - pointer to destination image in device memory
    width  - image width
    height - image height
    radius - filter radius
    iterations - number of iterations

*/
extern "C" 
void boxFilter(float *d_src, float *d_temp, float *d_dest, int width, int height, 
               int radius, int iterations, int nthreads)
{
    cutilSafeCall( cudaBindTextureToArray(tex, d_array) );

    for(int i=0; i<iterations; i++) {
        // use texture for horizontal pass
        d_boxfilter_x_tex<<< height / nthreads, nthreads, 0 >>>( d_temp, width, height, radius);
        d_boxfilter_y_global<<< width / nthreads, nthreads, 0 >>>( d_temp, d_dest, width, height, radius);
        if (iterations > 1) {
            // copy result back from global memory to array
            cutilSafeCall( cudaMemcpyToArray( d_tempArray, 0, 0, d_dest, width * height * sizeof(float), cudaMemcpyDeviceToDevice));
            cutilSafeCall( cudaBindTextureToArray(tex, d_tempArray) );
        }
    }
}

// RGBA version
extern "C" 
void boxFilterRGBA(uint *d_src, uint *d_temp, uint *d_dest, int width, int height, 
                   int radius, int iterations, int nthreads)
{
    cutilSafeCall( cudaBindTextureToArray(rgbaTex, d_array) );

    for(int i=0; i<iterations; i++) {
        // use texture for horizontal pass
        d_boxfilter_rgba_x<<< height / nthreads, nthreads, 0 >>>( d_temp, width, height, radius);
        d_boxfilter_rgba_y<<< width / nthreads, nthreads, 0 >>>( d_temp, d_dest, width, height, radius);
        if (iterations > 1) {
            // copy result back from global memory to array
            cutilSafeCall( cudaMemcpyToArray( d_tempArray, 0, 0, d_dest, width * height * sizeof(float), cudaMemcpyDeviceToDevice));
            cutilSafeCall( cudaBindTextureToArray(rgbaTex, d_tempArray) );
        }
    }
}


#endif // #ifndef _BOXFILTER_KERNEL_H_
