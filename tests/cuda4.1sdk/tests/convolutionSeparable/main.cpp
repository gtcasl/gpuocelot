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
 * This sample implements a separable convolution filter 
 * of a 2D image with an arbitrary kernel.
 */

// Utilities and system includes
#include <shrUtils.h>
#include <shrQATest.h>
#include <cutil_inline.h>

#include "convolutionSeparable_common.h"

////////////////////////////////////////////////////////////////////////////////
// Reference CPU convolution
////////////////////////////////////////////////////////////////////////////////
extern "C" void convolutionRowCPU(
    float *h_Result,
    float *h_Data,
    float *h_Kernel,
    int imageW,
    int imageH,
    int kernelR
);

extern "C" void convolutionColumnCPU(
    float *h_Result,
    float *h_Data,
    float *h_Kernel,
    int imageW,
    int imageH,
    int kernelR
);




////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    shrQAStart(argc, argv);

    // start logs
    shrSetLogFileName ("convolutionSeparable.txt");
    shrLog("%s Starting...\n\n", argv[0]); 

    float
        *h_Kernel,
        *h_Input,
        *h_Buffer,
        *h_OutputCPU,
        *h_OutputGPU;

    float
        *d_Input,
        *d_Output,
        *d_Buffer;


    const int imageW = 3072;
    const int imageH = 3072;
    const int iterations = 16;

    unsigned int hTimer;

    //Use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if ( shrCheckCmdLineFlag(argc, (const char **)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError(cutCreateTimer(&hTimer));

    shrLog("Image Width x Height = %i x %i\n\n", imageW, imageH);
    shrLog("Allocating and initializing host arrays...\n");
        h_Kernel    = (float *)malloc(KERNEL_LENGTH * sizeof(float));
        h_Input     = (float *)malloc(imageW * imageH * sizeof(float));
        h_Buffer    = (float *)malloc(imageW * imageH * sizeof(float));
        h_OutputCPU = (float *)malloc(imageW * imageH * sizeof(float));
        h_OutputGPU = (float *)malloc(imageW * imageH * sizeof(float));
        srand(200);
        for(unsigned int i = 0; i < KERNEL_LENGTH; i++)
            h_Kernel[i] = (float)(rand() % 16);
        for(unsigned i = 0; i < imageW * imageH; i++)
            h_Input[i] = (float)(rand() % 16);

    shrLog("Allocating and initializing CUDA arrays...\n");
        cutilSafeCall( cudaMalloc((void **)&d_Input,   imageW * imageH * sizeof(float)) );
        cutilSafeCall( cudaMalloc((void **)&d_Output,  imageW * imageH * sizeof(float)) );
        cutilSafeCall( cudaMalloc((void **)&d_Buffer , imageW * imageH * sizeof(float)) );

        setConvolutionKernel(h_Kernel);
        cutilSafeCall( cudaMemcpy(d_Input, h_Input, imageW * imageH * sizeof(float), cudaMemcpyHostToDevice) );

    shrLog("Running GPU convolution (%u identical iterations)...\n\n", iterations);
        for(int i = -1; i < iterations; i++){
            //i == -1 -- warmup iteration
            if(i == 0){
                cutilSafeCall( cutilDeviceSynchronize() );
                cutilCheckError( cutResetTimer(hTimer) );
                cutilCheckError( cutStartTimer(hTimer) );
            }

            convolutionRowsGPU(
                d_Buffer,
                d_Input,
                imageW,
                imageH
            );

            convolutionColumnsGPU(
                d_Output,
                d_Buffer,
                imageW,
                imageH
            );
        }
        cutilSafeCall( cutilDeviceSynchronize() );
        cutilCheckError(cutStopTimer(hTimer));
        double gpuTime = 0.001 * cutGetTimerValue(hTimer) / (double)iterations;
    shrLogEx(LOGBOTH | MASTER, 0, "convolutionSeparable, Throughput = %.4f MPixels/sec, Time = %.5f s, Size = %u Pixels, NumDevsUsed = %i, Workgroup = %u\n", 
        (1.0e-6 * (double)(imageW * imageH)/ gpuTime), gpuTime, (imageW * imageH), 1, 0);

    shrLog("\nReading back GPU results...\n\n");
        cutilSafeCall( cudaMemcpy(h_OutputGPU, d_Output, imageW * imageH * sizeof(float), cudaMemcpyDeviceToHost) );

    shrLog("Checking the results...\n");
        shrLog(" ...running convolutionRowCPU()\n");
        convolutionRowCPU(
            h_Buffer,
            h_Input,
            h_Kernel,
            imageW,
            imageH,
            KERNEL_RADIUS
        );

        shrLog(" ...running convolutionColumnCPU()\n");
        convolutionColumnCPU(
            h_OutputCPU,
            h_Buffer,
            h_Kernel,
            imageW,
            imageH,
            KERNEL_RADIUS
        );

        shrLog(" ...comparing the results\n");
        double sum = 0, delta = 0;
        for(unsigned i = 0; i < imageW * imageH; i++){
            delta += (h_OutputGPU[i] - h_OutputCPU[i]) * (h_OutputGPU[i] - h_OutputCPU[i]);
            sum   += h_OutputCPU[i] * h_OutputCPU[i];
        }
        double L2norm = sqrt(delta / sum);
        shrLog(" ...Relative L2 norm: %E\n\n", L2norm);
        shrLog("Shutting down...\n");


        cutilSafeCall( cudaFree(d_Buffer ) );
        cutilSafeCall( cudaFree(d_Output) );
        cutilSafeCall( cudaFree(d_Input) );
        free(h_OutputGPU);
        free(h_OutputCPU);
        free(h_Buffer);
        free(h_Input);
        free(h_Kernel);

    cutilCheckError(cutDeleteTimer(hTimer));

    cutilDeviceReset();

    shrQAFinishExit(argc, (const char **)argv, ((L2norm < 1e-6) ? QA_PASSED : QA_FAILED) );
}
