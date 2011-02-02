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

/*
 * This sample demonstrates how 2D convolutions 
 * with very large kernel sizes 
 * can be efficiently implemented 
 * using FFT transformations.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cufft.h>
#include <cutil_inline.h>



typedef float2 Complex;



////////////////////////////////////////////////////////////////////////////////
// Helper functions
////////////////////////////////////////////////////////////////////////////////
//Round a / b to nearest higher integer value
int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

//Align a to nearest higher multiple of b
int iAlignUp(int a, int b){
    return (a % b != 0) ?  (a - a % b + b) : a;
}



////////////////////////////////////////////////////////////////////////////////
// Reference straightfroward CPU convolution
////////////////////////////////////////////////////////////////////////////////
extern "C" void convolutionCPU(
    Complex *h_Result,
    Complex *h_Data,
    Complex *h_Kernel,
    int dataW,
    int dataH,
    int kernelW,
    int kernelH,
    int kernelX,
    int kernelY
);



////////////////////////////////////////////////////////////////////////////////
// Padding kernels
////////////////////////////////////////////////////////////////////////////////
#include "convolutionFFT2D_kernel.cuh"



////////////////////////////////////////////////////////////////////////////////
// Data configuration
////////////////////////////////////////////////////////////////////////////////
int calculateFFTsize(int dataSize){
    //Highest non-zero bit position of dataSize
    int hiBit;
    //Neares lower and higher powers of two numbers for dataSize
    unsigned int lowPOT, hiPOT;

    //Align data size to a multiple of half-warp
    //in order to have each line starting at properly aligned addresses
    //for coalesced global memory writes in padKernel() and padData()
    dataSize = iAlignUp(dataSize, 16);

    //Find highest non-zero bit
    for(hiBit = 31; hiBit >= 0; hiBit--)
        if(dataSize & (1U << hiBit)) break;

    //No need to align, if already power of two
    lowPOT = 1U << hiBit;
    if(lowPOT == dataSize) return dataSize;

    //Align to a nearest higher power of two, if the size is small enough,
    //else align only to a nearest higher multiple of 512,
    //in order to save computation and memory bandwidth
    hiPOT = 1U << (hiBit + 1);
    if(hiPOT <= 1024)
        return hiPOT;
    else 
        return iAlignUp(dataSize, 512);
}



//Kernel dimensions
const int KERNEL_W = 7;
const int KERNEL_H = 7;

//Kernel center position
const int KERNEL_X = 1;
const int KERNEL_Y = 6;

//Width and height of padding for "clamp to border" addressing mode
const int PADDING_W = KERNEL_W - 1;
const int PADDING_H = KERNEL_H - 1;

//Input data dimension
#if 1
const int DATA_W = 200;
const int DATA_H = 200;
#else
const int DATA_W = 1000;
const int DATA_H = 1000;
#endif

//Derive FFT size from data and kernel dimensions
const int FFT_W = calculateFFTsize(DATA_W + PADDING_W);
const int FFT_H = calculateFFTsize(DATA_H + PADDING_H);

const int    FFT_SIZE = FFT_W    * FFT_H    * sizeof(Complex);
const int KERNEL_SIZE = KERNEL_W * KERNEL_H * sizeof(Complex);
const int   DATA_SIZE = DATA_W   * DATA_H   * sizeof(Complex);



////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    Complex
        *h_Kernel,
        *h_Data,
        *h_ResultCPU,
        *h_ResultGPU;

    cudaArray
        *a_Kernel,
        *a_Data;

    cudaChannelFormatDesc float2tex 
        = cudaCreateChannelDesc<float2>();

    Complex
        *d_PaddedKernel,
        *d_PaddedData;

    cufftHandle FFTplan;

    Complex
        rCPU, rGPU;

    double
        max_delta_ref, delta, ref, sum_delta2, sum_ref2, L2norm;

    int i, x, y;

    unsigned int hTimer;


    // use command-line specified CUDA device, otherwise use device with highest Gflops/s

    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
	    cutilDeviceInit(argc, argv);
    else
    	cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError( cutCreateTimer(&hTimer) );

    printf("Input data size           : %i x %i\n", DATA_W,             DATA_H            );
    printf("Convolution kernel size   : %i x %i\n", KERNEL_W,           KERNEL_H          );
    printf("Padded image size         : %i x %i\n", DATA_W + PADDING_W, DATA_H + PADDING_H);
    printf("Aligned padded image size : %i x %i\n", FFT_W,              FFT_H             );

    printf("Allocating memory...\n");
        h_Kernel       = (Complex *)malloc(KERNEL_SIZE);
        h_Data         = (Complex *)malloc(DATA_SIZE);
        h_ResultCPU    = (Complex *)malloc(DATA_SIZE);
        h_ResultGPU    = (Complex *)malloc(FFT_SIZE);
        cutilSafeCall( cudaMallocArray(&a_Kernel, &float2tex, KERNEL_W, KERNEL_H) );
        cutilSafeCall( cudaMallocArray(&a_Data,   &float2tex,   DATA_W,   DATA_H) );
        cutilSafeCall( cudaMalloc((void **)&d_PaddedKernel, FFT_SIZE) );
        cutilSafeCall( cudaMalloc((void **)&d_PaddedData,   FFT_SIZE) );

    printf("Generating random input data...\n");
        srand(2007);
        for(i = 0; i < (KERNEL_W * KERNEL_H); i++){
            h_Kernel[i].x = (float)rand() / (float)RAND_MAX;
            h_Kernel[i].y = 0;
        }
        for(i = 0; i < (DATA_W * DATA_H); i++){
            h_Data[i].x = (float)rand() / (float)RAND_MAX;
            h_Data[i].y = 0;
        }

    printf("Creating FFT plan for %i x %i...\n", FFT_W, FFT_H);
        cufftSafeCall( cufftPlan2d(&FFTplan, FFT_H, FFT_W, CUFFT_C2C) );

    printf("Uploading to GPU and padding convolution kernel and input data...\n");
        printf("...initializing padded kernel and data storage with zeroes...\n");
        cutilSafeCall( cudaMemset(d_PaddedKernel, 0, FFT_SIZE) );
        cutilSafeCall( cudaMemset(d_PaddedData,   0, FFT_SIZE) );
        printf("...copying input data and convolution kernel from host to CUDA arrays\n");
        cutilSafeCall( cudaMemcpyToArray(a_Kernel, 0, 0, h_Kernel, KERNEL_SIZE, cudaMemcpyHostToDevice) );
        cutilSafeCall( cudaMemcpyToArray(a_Data,   0, 0, h_Data,   DATA_SIZE,   cudaMemcpyHostToDevice) );
        printf("...binding CUDA arrays to texture references\n");
        cutilSafeCall( cudaBindTextureToArray(texKernel, a_Kernel) );
        cutilSafeCall( cudaBindTextureToArray(texData,   a_Data)   );

        //Block width should be a multiple of maximum coalesced write size 
        //for coalesced memory writes in padKernel() and padData()
        dim3 threadBlock(16, 12);
        dim3 kernelBlockGrid(iDivUp(KERNEL_W, threadBlock.x), iDivUp(KERNEL_H, threadBlock.y));
        dim3 dataBlockGrid(iDivUp(FFT_W, threadBlock.x), iDivUp(FFT_H, threadBlock.y));

        printf("...padding convolution kernel\n");
        padKernel<<<kernelBlockGrid, threadBlock>>>(
            d_PaddedKernel,
            FFT_W,
            FFT_H,
            KERNEL_W,
            KERNEL_H,
            KERNEL_X,
            KERNEL_Y
        );
        cutilCheckMsg("padKernel() execution failed\n");

        printf("...padding input data array\n");
        padData<<<dataBlockGrid, threadBlock>>>(
            d_PaddedData,
            FFT_W,
            FFT_H,
            DATA_W,
            DATA_H,
            KERNEL_W,
            KERNEL_H,
            KERNEL_X,
            KERNEL_Y
        );
        cutilCheckMsg("padData() execution failed\n");

    //Not including kernel transformation into time measurement,
    //since convolution kernel is not changed very frequently
    printf("Transforming convolution kernel...\n");
        cufftSafeCall( cufftExecC2C(FFTplan, (cufftComplex *)d_PaddedKernel, (cufftComplex *)d_PaddedKernel, CUFFT_FORWARD) );

    printf("Running GPU FFT convolution...\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        cufftSafeCall( cufftExecC2C(FFTplan, (cufftComplex *)d_PaddedData,   (cufftComplex *)d_PaddedData,   CUFFT_FORWARD) );
        modulateAndNormalize<<<16, 128>>>(
            d_PaddedData,
            d_PaddedKernel,
            FFT_W * FFT_H
        );
        cutilCheckMsg("modulateAndNormalize() execution failed\n");
        cufftSafeCall( cufftExecC2C(FFTplan, (cufftComplex *)d_PaddedData,   (cufftComplex *)d_PaddedData,   CUFFT_INVERSE) );
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        double gpuTime = cutGetTimerValue(hTimer);
    printf("GPU time: %f msecs. //%f MPix/s\n", gpuTime, DATA_W * DATA_H * 1e-6 / (gpuTime * 0.001) );

    printf("Reading back GPU FFT results...\n");
        cutilSafeCall( cudaMemcpy(h_ResultGPU, d_PaddedData, FFT_SIZE, cudaMemcpyDeviceToHost) );


    printf("Checking GPU results...\n");
        printf("...running reference CPU convolution\n");
        convolutionCPU(
            h_ResultCPU,
            h_Data,
            h_Kernel,
            DATA_W,
            DATA_H,
            KERNEL_W,
            KERNEL_H,
            KERNEL_X,
            KERNEL_Y
        );

        printf("...comparing the results\n");
        sum_delta2 = 0;
        sum_ref2   = 0;
        max_delta_ref = 0;
        for(y = 0; y < DATA_H; y++)
            for(x = 0; x < DATA_W; x++){
                rCPU = h_ResultCPU[y * DATA_W + x];
                rGPU = h_ResultGPU[y * FFT_W  + x];
                delta = (rCPU.x - rGPU.x) * (rCPU.x - rGPU.x) + (rCPU.y - rGPU.y) * (rCPU.y - rGPU.y);
                ref   = rCPU.x * rCPU.x + rCPU.y * rCPU.y;
                if((delta / ref) > max_delta_ref) max_delta_ref = delta / ref;
                sum_delta2 += delta;
                sum_ref2   += ref;
            }
        L2norm = sqrt(sum_delta2 / sum_ref2);
    printf("Max delta / CPU value %E\n", sqrt(max_delta_ref));
    printf("L2 norm: %E\n", L2norm);
    printf((L2norm < 1e-6) ? "TEST PASSED\n" : "TEST FAILED\n");


    printf("Shutting down...\n");
        cutilSafeCall( cudaUnbindTexture(texData) );
        cutilSafeCall( cudaUnbindTexture(texKernel) );
        cufftSafeCall( cufftDestroy(FFTplan) );
        cutilSafeCall( cudaFree(d_PaddedData)   );
        cutilSafeCall( cudaFree(d_PaddedKernel) );
        cutilSafeCall( cudaFreeArray(a_Data)   );
        cutilSafeCall( cudaFreeArray(a_Kernel) );
        free(h_ResultGPU);
        free(h_ResultCPU);
        free(h_Data);
        free(h_Kernel);

    cudaThreadExit();

    cutilExit(argc, argv);
}
