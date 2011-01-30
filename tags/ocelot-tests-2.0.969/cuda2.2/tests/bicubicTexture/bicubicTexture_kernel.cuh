/*
 * Copyright 1993-2008 NVIDIA Corporation.  All rights reserved.
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

/*
    Bicubic filtering
    See GPU Gems 2: "Fast Third-Order Texture Filtering", Sigg & Hadwiger
    http://http.developer.nvidia.com/GPUGems2/gpugems2_chapter20.html

    Reformulation thanks to Keenan Crane
*/

#ifndef _BICUBICTEXTURE_KERNEL_CUH_
#define _BICUBICTEXTURE_KERNEL_CUH_

#include "cutil_math.h"

enum Mode { MODE_NEAREST, MODE_BILINEAR, MODE_BICUBIC, MODE_FAST_BICUBIC };

texture<uchar, 2, cudaReadModeNormalizedFloat> tex;

// w0, w1, w2, and w3 are the four cubic B-spline basis functions
__host__ __device__
float w0(float a)
{
//    return (1.0f/6.0f)*(-a*a*a + 3.0f*a*a - 3.0f*a + 1.0f);
    return (1.0f/6.0f)*(a*(a*(-a + 3.0f) - 3.0f) + 1.0f);   // optimized
}

__host__ __device__
float w1(float a)
{
//    return (1.0f/6.0f)*(3.0f*a*a*a - 6.0f*a*a + 4.0f);
    return (1.0f/6.0f)*(a*a*(3.0f*a - 6.0f) + 4.0f);
}

__host__ __device__
float w2(float a)
{
//    return (1.0f/6.0f)*(-3.0f*a*a*a + 3.0f*a*a + 3.0f*a + 1.0f);
    return (1.0f/6.0f)*(a*(a*(-3.0f*a + 3.0f) + 3.0f) + 1.0f);
}

__host__ __device__
float w3(float a)
{
    return (1.0f/6.0f)*(a*a*a);
}

// g0 and g1 are the two amplitude functions
__device__ float g0(float a)
{
    return w0(a) + w1(a);
}

__device__ float g1(float a)
{
    return w2(a) + w3(a);
}

// h0 and h1 are the two offset functions
__device__ float h0(float a)
{
    // note +0.5 offset to compensate for CUDA linear filtering convention
    return -1.0f + w1(a) / (w0(a) + w1(a)) + 0.5f;
}

__device__ float h1(float a)
{
    return 1.0f + w3(a) / (w2(a) + w3(a)) + 0.5f;
}

// filter 4 values using cubic splines
template<class T>
__device__
T cubicFilter(float x, T c0, T c1, T c2, T c3)
{
    T r;
    r = c0 * w0(x);
    r += c1 * w1(x);
    r += c2 * w2(x);
    r += c3 * w3(x);
    return r;
}

// slow but precise bicubic lookup using 16 texture lookups
template<class T, class R>  // return type, texture type
__device__
R tex2DBicubic(const texture<T, 2, cudaReadModeNormalizedFloat> texref, float x, float y)
{
    x -= 0.5f;
    y -= 0.5f;
    float px = floor(x);
    float py = floor(y);
    float fx = x - px;
    float fy = y - py;

    return cubicFilter<R>(fy,
                          cubicFilter<R>(fx, tex2D(texref, px-1, py-1), tex2D(texref, px, py-1), tex2D(texref, px+1, py-1), tex2D(texref, px+2,py-1)),
                          cubicFilter<R>(fx, tex2D(texref, px-1, py),   tex2D(texref, px, py),   tex2D(texref, px+1, py),   tex2D(texref, px+2, py)),
                          cubicFilter<R>(fx, tex2D(texref, px-1, py+1), tex2D(texref, px, py+1), tex2D(texref, px+1, py+1), tex2D(texref, px+2, py+1)),
                          cubicFilter<R>(fx, tex2D(texref, px-1, py+2), tex2D(texref, px, py+2), tex2D(texref, px+1, py+2), tex2D(texref, px+2, py+2))
                          );
}

// fast bicubic texture lookup using 4 bilinear lookups
template<class T, class R>  // return type, texture type
__device__
R tex2DFastBicubic(const texture<T, 2, cudaReadModeNormalizedFloat> texref, float x, float y)
{
    x -= 0.5f;
    y -= 0.5f;
    float px = floor(x);
    float py = floor(y);
    float fx = x - px;
    float fy = y - py;

    // note: we could store these functions in a lookup table texture, but maths is cheap
    float g0x = g0(fx);
    float g1x = g1(fx);
    float h0x = h0(fx);
    float h1x = h1(fx);
    float h0y = h0(fy);
    float h1y = h1(fy);

    R r = g0(fy) * ( g0x * tex2D(texref, px + h0x, py + h0y)   +
                     g1x * tex2D(texref, px + h1x, py + h0y) ) +
          g1(fy) * ( g0x * tex2D(texref, px + h0x, py + h1y)   +
                     g1x * tex2D(texref, px + h1x, py + h1y) );
    return r;
}


// render image using normal bilinear texture lookup
__global__ void
d_render(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy)
{
	uint x = __umul24(blockIdx.x, blockDim.x) + threadIdx.x;
    uint y = __umul24(blockIdx.y, blockDim.y) + threadIdx.y;
    uint i = __umul24(y, width) + x;

    float u = (x-cx)*scale+cx + tx;
    float v = (y-cy)*scale+cy + ty;

    if ((x < width) && (y < height)) {
        // write output color
        float c = tex2D(tex, u, v);
        d_output[i] = make_uchar4(c * 0xff, c * 0xff, c * 0xff, 0);
    }
}

// render image using bicubic texture lookup
__global__ void
d_renderBicubic(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy)
{
	uint x = __umul24(blockIdx.x, blockDim.x) + threadIdx.x;
    uint y = __umul24(blockIdx.y, blockDim.y) + threadIdx.y;
    uint i = __umul24(y, width) + x;

    float u = (x-cx)*scale+cx + tx;
    float v = (y-cy)*scale+cy + ty;

    if ((x < width) && (y < height)) {
        // write output color
        float c = tex2DBicubic<uchar, float>(tex, u, v);
        d_output[i] = make_uchar4(c * 0xff, c * 0xff, c * 0xff, 0);
    }
}

// render image using fast bicubic texture lookup
__global__ void
d_renderFastBicubic(uchar4 *d_output, uint width, uint height, float tx, float ty, float scale, float cx, float cy)
{
	uint x = __umul24(blockIdx.x, blockDim.x) + threadIdx.x;
    uint y = __umul24(blockIdx.y, blockDim.y) + threadIdx.y;
    uint i = __umul24(y, width) + x;

    float u = (x-cx)*scale+cx + tx;
    float v = (y-cy)*scale+cy + ty;

    if ((x < width) && (y < height)) {
        // write output color
        float c = tex2DFastBicubic<uchar, float>(tex, u, v);
        d_output[i] = make_uchar4(c * 0xff, c * 0xff, c * 0xff, 0);
    }
}

#endif // _BICUBICTEXTURE_KERNEL_CUH_
