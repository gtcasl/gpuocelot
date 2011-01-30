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



//Fast integer multiplication macro
#define IMUL(a, b) __mul24(a, b)



//Input data texture reference
texture<float, 2, cudaReadModeElementType> texData;



////////////////////////////////////////////////////////////////////////////////
// Kernel configuration
////////////////////////////////////////////////////////////////////////////////
#define KERNEL_RADIUS 8
#define KERNEL_W      (2 * KERNEL_RADIUS + 1)
__device__ __constant__ float d_Kernel[KERNEL_W];



////////////////////////////////////////////////////////////////////////////////
// Loop unrolling templates, needed for best performance
////////////////////////////////////////////////////////////////////////////////
template<int i> __device__ float convolutionRow(float x, float y){
    return 
        tex2D(texData, x + KERNEL_RADIUS - i, y) * d_Kernel[i]
        + convolutionRow<i - 1>(x, y);
}

template<> __device__ float convolutionRow<-1>(float x, float y){
    return 0;
}

template<int i> __device__ float convolutionColumn(float x, float y){
    return 
        tex2D(texData, x, y + KERNEL_RADIUS - i) * d_Kernel[i]
        + convolutionColumn<i - 1>(x, y);
}

template<> __device__ float convolutionColumn<-1>(float x, float y){
    return 0;
}



////////////////////////////////////////////////////////////////////////////////
// Row convolution filter
////////////////////////////////////////////////////////////////////////////////
__global__ void convolutionRowGPU(
    float *d_Result,
    int dataW,
    int dataH
){
    const   int ix = IMUL(blockDim.x, blockIdx.x) + threadIdx.x;
    const   int iy = IMUL(blockDim.y, blockIdx.y) + threadIdx.y;
    const float  x = (float)ix + 0.5f;
    const float  y = (float)iy + 0.5f;

    if(ix < dataW && iy < dataH){
        float sum = 0;

#ifdef UNROLL_INNER
        sum = convolutionRow<2 * KERNEL_RADIUS>(x, y);
#else
        for(int k = -KERNEL_RADIUS; k <= KERNEL_RADIUS; k++)
            sum += tex2D(texData, x + k, y) * d_Kernel[KERNEL_RADIUS - k];
#endif

        d_Result[IMUL(iy, dataW) + ix] = sum;
    }
}



////////////////////////////////////////////////////////////////////////////////
// Column convolution filter
////////////////////////////////////////////////////////////////////////////////
__global__ void convolutionColumnGPU(
    float *d_Result,
    int dataW,
    int dataH
){
    const   int ix = IMUL(blockDim.x, blockIdx.x) + threadIdx.x;
    const   int iy = IMUL(blockDim.y, blockIdx.y) + threadIdx.y;
    const float  x = (float)ix + 0.5f;
    const float  y = (float)iy + 0.5f;

    if(ix < dataW && iy < dataH){
        float sum = 0;

#ifdef UNROLL_INNER
        sum =  convolutionColumn<2 * KERNEL_RADIUS>(x, y);
#else
        for(int k = -KERNEL_RADIUS; k <= KERNEL_RADIUS; k++)
            sum += tex2D(texData, x, y + k) * d_Kernel[KERNEL_RADIUS - k];
#endif

        d_Result[IMUL(iy, dataW) + ix] = sum;
    }
}
