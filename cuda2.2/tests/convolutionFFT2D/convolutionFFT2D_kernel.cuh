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



#define IMUL(a, b) __mul24(a, b)



////////////////////////////////////////////////////////////////////////////////
// Cyclically shift convolution kernel, so that the center is at (0, 0)
////////////////////////////////////////////////////////////////////////////////
texture<Complex, 2, cudaReadModeElementType> texKernel;

__global__ void padKernel(
    Complex *d_PaddedKernel,
    int fftW,
    int fftH,
    int kernelW,
    int kernelH,
    int kernelX,
    int kernelY
){
    const int x = IMUL(blockDim.x, blockIdx.x) + threadIdx.x;
    const int y = IMUL(blockDim.y, blockIdx.y) + threadIdx.y;

    if(x < kernelW && y < kernelH){
        int kx = x - kernelX; if(kx < 0) kx += fftW;
        int ky = y - kernelY; if(ky < 0) ky += fftH;
        d_PaddedKernel[IMUL(ky, fftW) + kx] =
            tex2D(texKernel, (float)x + 0.5f, (float)y + 0.5f);
    }
}


////////////////////////////////////////////////////////////////////////////////
// Copy input data array to the upper left corner and pad by border values
////////////////////////////////////////////////////////////////////////////////
texture<Complex, 2, cudaReadModeElementType> texData;

__global__ void padData(
    Complex *d_PaddedData,
    int fftW,
    int fftH,
    int dataW,
    int dataH,
    int kernelW,
    int kernelH,
    int kernelX,
    int kernelY
){
    const int x = IMUL(blockDim.x, blockIdx.x) + threadIdx.x;
    const int y = IMUL(blockDim.y, blockIdx.y) + threadIdx.y;
    const int borderW = dataW + kernelX;
    const int borderH = dataH + kernelY;
    int dx;
    int dy;

    if(x < fftW && y < fftH){
        if(x < dataW) dx = x;
        if(y < dataH) dy = y;
        if(x >= dataW && x < borderW) dx = dataW - 1;
        if(y >= dataH && y < borderH) dy = dataH - 1;
        if(x >= borderW) dx = 0;
        if(y >= borderH) dy = 0;

        d_PaddedData[IMUL(y, fftW) + x] =
            tex2D(texData, (float)dx + 0.5f, (float)dy + 0.5f);
    }
}



////////////////////////////////////////////////////////////////////////////////
// Modulate Fourier image of padded data by Fourier image of padded kernel
// and normalize by FFT size
////////////////////////////////////////////////////////////////////////////////
__device__ void complexMulAndScale(Complex& a, Complex b, float c){
    Complex t = {c * (a.x * b.x - a.y * b.y), c * (a.y * b.x + a.x * b.y)};
    a = t;
}

__global__ void modulateAndNormalize(
    Complex *d_PaddedData,
    Complex *d_PaddedKernel,
    int dataN
){
    const int     tid = IMUL(blockDim.x, blockIdx.x) + threadIdx.x;
    const int threadN = IMUL(blockDim.x, gridDim.x);
    const float     q = 1.0f / (float)dataN;

    for(int i = tid; i < dataN; i += threadN)
        complexMulAndScale(d_PaddedData[i], d_PaddedKernel[i], q);
}
