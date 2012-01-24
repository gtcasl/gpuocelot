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

#ifndef _FILTER_KERNEL_H_
#define _FILTER_KERNEL_H_

#include <shrUtils.h>
#include <cutil_inline.h>    // includes cuda.h and cuda_runtime_api.h
#include <cutil_math.h>
#include <generalCuda.cuh>

texture<uchar4, 2, cudaReadModeNormalizedFloat> rgbaTex;
texture<float, 1, cudaReadModeElementType> gaussianTex;

cudaArray* d_array, *d_tempArray, *d_gaussianArray;

/*
    Perform a simple bilateral filter.

    Bilateral filter is a nonlinear filter that is a mixture of range 
    filter and domain filter, the previous one preserves crisp edges and 
    the latter one filters noise. The intensity value at each pixel in 
    an image is replaced by a weighted average of intensity values from 
    nearby pixels.

    The weight factor is calculated by the product of domain filter
    component(using the gaussian distribution as a spatial distance) as 
    well as range filter component(Euclidean distance between center pixel
    and the current neighbor pixel). Because this process is nonlinear, 
    the sample just uses a simple pixel by pixel step. 

    Texture fetches automatically clamp to edge of image. 1D gaussian array
    is mapped to a 1D texture instead of using shared memory, which may 
    cause severe bank conflict.

    Threads are y-pass(column-pass), because the output is coalesced.

    Parameters
    od - pointer to output data in global memory
    d_f - pointer to the 1D gaussian array
    e_d - euclidean delta
    w  - image width
    h  - image height
    r  - filter radius
*/

//column pass using coalesced global memory reads
__global__ void
d_bilateral_filter(uint *od,
                   float e_d, int w, int h, int r)
{
    uint x = __umul24(blockIdx.x, blockDim.x) + threadIdx.x;
    uint y = __umul24(blockIdx.y, blockDim.y) + threadIdx.y;
    if (x < w && y < h) {
        float sum = 0.0f;
        float factor;
        float4 t = make_float4(0.0f);
        float4 center = tex2D(rgbaTex, x, y);

        for(int i = -r; i <= r; i++)
        {
            for(int j = -r; j <= r; j++)
            {
                float4 curPix = tex2D(rgbaTex, x + j, y + i);
                factor = (tex1D(gaussianTex, i + r) * tex1D(gaussianTex, j + r)) *     //domain factor
                    euclideanLen(curPix, center, e_d); //range factor

                t += factor * curPix;
                sum += factor;
            }
        }
        od[y * w + x] = rgbaFloatToInt( t / sum);
    }
}

extern "C" 
void initTexture(int width, int height, void *pImage)
{
    int size = width * height * sizeof(unsigned int);

    // copy image data to array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsigned);
    cutilSafeCall( cudaMallocArray  ( &d_array, &channelDesc, width, height )); 
    cutilSafeCall( cudaMallocArray  ( &d_tempArray, &channelDesc, width, height ));
    cutilSafeCall( cudaMemcpyToArray( d_array, 0, 0, pImage, size, cudaMemcpyHostToDevice));
}

extern "C"
void freeTextures()
{
    cutilSafeCall(cudaFreeArray(d_array));
    cutilSafeCall(cudaFreeArray(d_tempArray));
    cutilSafeCall(cudaFreeArray(d_gaussianArray));
}

extern "C"
void updateGaussian(float delta, int radius)
{
    int size = 2 * radius + 1;

    float* d_gaussian;
    cutilSafeCall(cudaMalloc( (void**) &d_gaussian, 
        (2 * radius + 1)* sizeof(float)));

    //generate gaussian array
    d_generate_gaussian<<< 1, size>>>(d_gaussian, delta, radius);

    //create cuda array
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32, 0, 0, 0, cudaChannelFormatKindFloat);
    cutilSafeCall( cudaMallocArray( &d_gaussianArray, &channelDesc, size, 1 )); 
    cutilSafeCall( cudaMemcpyToArray( d_gaussianArray, 0, 0, d_gaussian, size * sizeof (float), cudaMemcpyDeviceToDevice));

    // Bind the array to the texture
    cutilSafeCall( cudaBindTextureToArray( gaussianTex, d_gaussianArray, channelDesc));
    cutilSafeCall( cudaFree(d_gaussian) );
}

/*
    Perform 2D bilateral filter on image using CUDA

    Parameters:
    d_dest - pointer to destination image in device memory
    width  - image width
    height - image height
    e_d    - euclidean delta
    radius - filter radius
    iterations - number of iterations
*/

// RGBA version
extern "C" 
double bilateralFilterRGBA(uint *d_dest,
                           int width, int height,
                           float e_d, int radius, int iterations,
                           int nthreads)
{
    // var for kernel computation timing
    double dKernelTime;

    // Bind the array to the texture
    cutilSafeCall( cudaBindTextureToArray(rgbaTex, d_array) );

    for(int i=0; i<iterations; i++) 
    {
        // sync host and start kernel computation timer
        dKernelTime = 0.0;
        cutilSafeCall(cutilDeviceSynchronize());
        shrDeltaT(0);

        dim3 gridSize((width + 16 - 1) / 16, (height + 16 - 1) / 16);
        dim3 blockSize(16, 16);
        d_bilateral_filter<<< gridSize, blockSize>>>( 
            d_dest, e_d, width, height, radius);

        // sync host and stop computation timer
        cutilSafeCall( cutilDeviceSynchronize() );
        dKernelTime += shrDeltaT(0);

        if (iterations > 1) {
            // copy result back from global memory to array
            cutilSafeCall( cudaMemcpyToArray( d_tempArray, 0, 0, d_dest, width * height * sizeof(float),
                cudaMemcpyDeviceToDevice));
            cutilSafeCall( cudaBindTextureToArray(rgbaTex, d_tempArray) );
        }
    }

    return (dKernelTime/(double)iterations);
}

#endif
