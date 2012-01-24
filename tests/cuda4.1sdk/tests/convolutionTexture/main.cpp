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
 
 
/* 
 * This sample implements the same algorithm as the convolutionSeparable
 * CUDA SDK sample, but without using the shared memory at all.
 * Instead, it uses textures in exactly the same way an OpenGL-based
 * implementation would do. 
 * Refer to the "Performance" section of convolutionSeparable whitepaper.
 */




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <shrQATest.h>
#include "convolutionTexture_common.h"




////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    float
        *h_Kernel,
        *h_Input,
        *h_Buffer,
        *h_OutputCPU,
        *h_OutputGPU;

    cudaArray
        *a_Src;

    cudaChannelFormatDesc floatTex = cudaCreateChannelDesc<float>();

    float
        *d_Output;

    float
        gpuTime;

    unsigned int hTimer;

    const int imageW = 3072;
    const int imageH = 3072 / 2;
    const unsigned int iterations = 10;

    shrQAStart(argc, argv);

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError( cutCreateTimer(&hTimer) );

    printf("Initializing data...\n");
        h_Kernel    = (float *)malloc(KERNEL_LENGTH * sizeof(float));
        h_Input     = (float *)malloc(imageW * imageH * sizeof(float));
        h_Buffer    = (float *)malloc(imageW * imageH * sizeof(float));
        h_OutputCPU = (float *)malloc(imageW * imageH * sizeof(float));
        h_OutputGPU = (float *)malloc(imageW * imageH * sizeof(float));
        cutilSafeCall( cudaMallocArray(&a_Src, &floatTex, imageW, imageH) );
        cutilSafeCall( cudaMalloc((void **)&d_Output, imageW * imageH * sizeof(float)) );

        srand(2009);
        for(unsigned int i = 0; i < KERNEL_LENGTH; i++)
            h_Kernel[i] = (float)(rand() % 16);

        for(unsigned int i = 0; i < imageW * imageH; i++)
            h_Input[i] = (float)(rand() % 16);

        setConvolutionKernel(h_Kernel);
        cutilSafeCall( cudaMemcpyToArray(a_Src, 0, 0, h_Input, imageW * imageH * sizeof(float), cudaMemcpyHostToDevice) );


    printf("Running GPU rows convolution (%u identical iterations)...\n", iterations);
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        for(unsigned int i = 0; i < iterations; i++){
            convolutionRowsGPU(
                d_Output,
                a_Src,
                imageW,
                imageH
            );
        }
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer) / (float)iterations;
    printf("Average convolutionRowsGPU() time: %f msecs; //%f Mpix/s\n", gpuTime, imageW * imageH * 1e-6 / (0.001 * gpuTime));

    //While CUDA kernels can't write to textures directly, this copy is inevitable
    printf("Copying convolutionRowGPU() output back to the texture...\n");
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        cutilSafeCall( cudaMemcpyToArray(a_Src, 0, 0, d_Output, imageW * imageH * sizeof(float), cudaMemcpyDeviceToDevice) );
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
    printf("cudaMemcpyToArray() time: %f msecs; //%f Mpix/s\n", gpuTime, imageW * imageH * 1e-6 / (0.001 * gpuTime));

    printf("Running GPU columns convolution (%i iterations)\n", iterations);
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        for(int i = 0; i < iterations; i++){
            convolutionColumnsGPU(
                d_Output,
                a_Src,
                imageW,
                imageH
            );
        }
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer) / (float)iterations;
    printf("Average convolutionColumnsGPU() time: %f msecs; //%f Mpix/s\n", gpuTime, imageW * imageH * 1e-6 / (0.001 * gpuTime));

    printf("Reading back GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, imageW * imageH * sizeof(float), cudaMemcpyDeviceToHost) );

    printf("Checking the results...\n");
        printf("...running convolutionRowsCPU()\n");
        convolutionRowsCPU(
            h_Buffer,
            h_Input,
            h_Kernel,
            imageW,
            imageH,
            KERNEL_RADIUS
        );

        printf("...running convolutionColumnsCPU()\n");
        convolutionColumnsCPU(
            h_OutputCPU,
            h_Buffer,
            h_Kernel,
            imageW,
            imageH,
            KERNEL_RADIUS
        );

        double delta = 0;
        double sum = 0;
        for(unsigned int i = 0; i < imageW * imageH; i++){
            sum += h_OutputCPU[i] * h_OutputCPU[i];
            delta += (h_OutputGPU[i] - h_OutputCPU[i]) * (h_OutputGPU[i] - h_OutputCPU[i]);
        }
        double L2norm = sqrt(delta / sum);
        printf("Relative L2 norm: %E\n", L2norm);
    printf("Shutting down...\n");

        cutilSafeCall( cudaFree(d_Output)   );
        cutilSafeCall( cudaFreeArray(a_Src)   );
        free(h_OutputGPU);
        free(h_Buffer);
        free(h_Input);
        free(h_Kernel);

    cutilDeviceReset();

    shrQAFinishExit( argc, (const char **)argv, ((L2norm < 1e-6) ? QA_PASSED : QA_FAILED) );

}
