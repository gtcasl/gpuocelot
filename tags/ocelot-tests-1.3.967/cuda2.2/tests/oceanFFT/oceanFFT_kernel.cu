/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */

///////////////////////////////////////////////////////////////////////////////
#include <cufft.h>
#include <math_constants.h>

//Round a / b to nearest higher integer value
int cuda_iDivUp(int a, int b)
{
    return (a + (b - 1)) / b;
}


// complex math functions
__device__
float2 conjugate(float2 arg)
{
    return make_float2(arg.x, -arg.y);
}

__device__
float2 complex_exp(float arg)
{
    return make_float2(cosf(arg), sinf(arg));
}

__device__
float2 complex_add(float2 a, float2 b)
{
    return make_float2(a.x + b.x, a.y + b.y);
}

__device__
float2 complex_mult(float2 ab, float2 cd)
{
    return make_float2(ab.x * cd.x - ab.y * cd.y, ab.x * cd.y + ab.y * cd.x);
}

// generate wave heightfield at time t based on initial heightfield and dispersion relationship
__global__ void generateSpectrumKernel(float2* h0, float2 *ht, unsigned int width, unsigned int height, float t, float patchSize)
{
    unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
    unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;
    unsigned int i = y*width+x;
    
    // calculate coordinates
    float2 k;
    k.x = CUDART_PI_F * x / (float) patchSize;
    k.y = 2.0f * CUDART_PI_F * y / (float) patchSize;

    // calculate dispersion w(k)
    float k_len = sqrtf(k.x*k.x + k.y*k.y);
    float w = sqrtf(9.81f * k_len);

    if ((x < width) && (y < height)) {
		float2 h0_k = h0[i];
		float2 h0_mk = h0[(((height-1)-y)*width)+x];

		float2 h_tilda = complex_add( complex_mult(h0_k, complex_exp(w * t)),
		                              complex_mult(conjugate(h0_mk), 
		                              complex_exp(-w * t)) );

		// output frequency-space complex values
        ht[i] = h_tilda;
    }
}


// generate slope by partial differences in spatial domain
__global__ void calculateSlopeKernel(float* h, float2 *slopeOut, unsigned int width, unsigned int height)
{
    unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
    unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;
    unsigned int i = y*width+x;

    float2 slope;
    if ((x > 0) && (y > 0) && (x < width-1) && (y < height-1)) {
        slope.x = h[i+1] - h[i-1];
        slope.y = h[i+width] - h[i-width];
    } else {
        slope = make_float2(0.0f, 0.0f);
    }
    slopeOut[i] = slope;
}

extern "C" 
void cudaGenerateSpectrumKernel(float2* d_h0, float2 *d_ht, 
                                unsigned int width, unsigned int height, 
                                float animTime, float patchSize)
{
    dim3 block(8, 8, 1);
    dim3 grid(cuda_iDivUp(width, block.x), cuda_iDivUp(height, block.y), 1);
    generateSpectrumKernel<<<grid, block>>>(d_h0, d_ht, width, height, animTime, patchSize);
}

extern "C"
void cudaCalculateSlopeKernel(  float* hptr, float2 *slopeOut, 
                                unsigned int width, unsigned int height)
{
    dim3 block(8, 8, 1);
    dim3 grid2(cuda_iDivUp(width, block.x), cuda_iDivUp(height, block.y), 1);
    calculateSlopeKernel<<<grid2, block>>>(hptr, slopeOut, width, height);
}
