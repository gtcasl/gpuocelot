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
 * This sample implements the same algorithm as the convolutionSeparable
 * CUDA SDK sample, but without using the shared memory at all.
 * Instead, it uses textures in exactly the same way an OpenGL-based
 * implementation would do. 
 * Refer to the "Performance" section of convolutionSeparable whitepaper.
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cutil_inline.h>



////////////////////////////////////////////////////////////////////////////////
// Common host and device functions
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
// Reference CPU convolution
////////////////////////////////////////////////////////////////////////////////
extern "C" void convolutionRowCPU(
    float *h_Result,
    float *h_DataA,
    float *h_Kernel,
    int dataW,
    int dataH,
    int kernelR
);

extern "C" void convolutionColumnCPU(
    float *h_Result,
    float *h_DataA,
    float *h_Kernel,
    int dataW,
    int dataH,
    int kernelR
);



////////////////////////////////////////////////////////////////////////////////
// GPU convolution
////////////////////////////////////////////////////////////////////////////////
#define UNROLL_INNER
#include "convolutionTexture_kernel.cu"



////////////////////////////////////////////////////////////////////////////////
// Data configuration
////////////////////////////////////////////////////////////////////////////////
#if 1
//Reduce problem size to have reasonable emulation time
const int     DATA_W = iAlignUp(256, 16);
const int     DATA_H = 256;
#else
const int     DATA_W = iAlignUp(3072, 16);
const int     DATA_H = 3072;
#endif

const int KERNEL_SIZE = KERNEL_W * sizeof(float);
const int   DATA_SIZE = DATA_W   * DATA_H   * sizeof(float);



////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    float
        *h_Kernel,
        *h_DataA,
        *h_DataB,
        *h_ResultGPU;

    cudaArray
        *a_Data;

    cudaChannelFormatDesc floatTex = cudaCreateChannelDesc<float>();

    float
        *d_Result;

    double
        gpuTime, L1norm, rCPU, rGPU, sum_delta, sum_ref;

    int i, x, y;

    unsigned int hTimer;


    // use command-line specified CUDA device, otherwise use device with highest Gflops/s

    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
	    cutilDeviceInit(argc, argv);
    else
    	cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError( cutCreateTimer(&hTimer) );

    printf("Initializing data...\n");
        h_Kernel    = (float *)malloc(KERNEL_SIZE);
        h_DataA     = (float *)malloc(DATA_SIZE);
        h_DataB     = (float *)malloc(DATA_SIZE);
        h_ResultGPU = (float *)malloc(DATA_SIZE);
        cutilSafeCall( cudaMallocArray(&a_Data, &floatTex, DATA_W, DATA_H) );
        cutilSafeCall( cudaMalloc((void **)&d_Result, DATA_SIZE) );

        float kernelSum = 0;
        for(i = 0; i < KERNEL_W; i++){
            float dist = (float)(i - KERNEL_RADIUS) / (float)KERNEL_RADIUS;
            h_Kernel[i] = expf(- dist * dist / 2);
            kernelSum += h_Kernel[i];
        }
        for(i = 0; i < KERNEL_W; i++)
            h_Kernel[i] /= kernelSum;

        srand(2007);
        for(i = 0; i < DATA_W * DATA_H; i++)
            h_DataA[i] = (float)rand() / (float)RAND_MAX;

        cutilSafeCall( cudaMemcpyToSymbol(d_Kernel, h_Kernel, KERNEL_SIZE) );
        cutilSafeCall( cudaMemcpyToArray(a_Data, 0, 0, h_DataA, DATA_SIZE, cudaMemcpyHostToDevice) );
        cutilSafeCall( cudaBindTextureToArray(texData, a_Data) );

        //Block width should be a multiple of maximum coalesced write size
        //for coalesced memory writes in convolutionRowGPU() and convolutionColumnGPU()
        dim3 threadBlock(16, 12);
        dim3 blockGrid(iDivUp(DATA_W, threadBlock.x), iDivUp(DATA_H, threadBlock.y));


    printf("convolutionRowGPU()\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        convolutionRowGPU<<<blockGrid, threadBlock>>>(
            d_Result,
            DATA_W,
            DATA_H
        );
        cutilCheckMsg("convolutionRowGPU() execution failed\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
    printf("...convolutionRowGPU() time: %f msecs; //%f Mpix/s\n", gpuTime, DATA_W * DATA_H * 1e-6 / (0.001 * gpuTime));


    //While CUDA kernels can't  directly write to textures, this copy is inevitable
    printf("Copying convolutionRowGPU() output back to a_Data...\n");
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        cutilSafeCall( cudaMemcpyToArray(a_Data, 0, 0, d_Result, DATA_SIZE, cudaMemcpyDeviceToDevice) );
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
    printf("...cudaMemcpyToArray() time: %f msecs; //%f Mpix/s\n", gpuTime, DATA_W * DATA_H * 1e-6 / (0.001 * gpuTime));


    printf("convolutionColumnGPU()...\n");
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        convolutionColumnGPU<<<blockGrid, threadBlock>>>(
            d_Result,
            DATA_W,
            DATA_H
        );
        cutilCheckMsg("convolutionColumnGPU() execution failed\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
        gpuTime = cutGetTimerValue(hTimer);
    printf("...convolutionColumnGPU() time: %f msecs; //%f Mpix/s\n", gpuTime, DATA_W * DATA_H * 1e-6 / (0.001 * gpuTime));


    printf("Reading back GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_ResultGPU, d_Result, DATA_SIZE, cudaMemcpyDeviceToHost) );


    printf("Checking GPU results...\n");
        printf("...convolutionRowCPU()\n");
        convolutionRowCPU(
            h_DataB,
            h_DataA,
            h_Kernel,
            DATA_W,
            DATA_H,
            KERNEL_RADIUS
        );

        printf("...convolutionColumnCPU()\n");
        convolutionColumnCPU(
            h_DataA,
            h_DataB,
            h_Kernel,
            DATA_W,
            DATA_H,
            KERNEL_RADIUS
        );

        printf("...comparing the results\n");
        sum_delta = 0;
        sum_ref   = 0;
        for(y = 0; y < DATA_H; y++)
            for(x = 0; x < DATA_W; x++){
                rCPU = h_DataA[y * DATA_W + x];
                rGPU = h_ResultGPU[y * DATA_W  + x];
                sum_delta += fabs(rCPU - rGPU);
                sum_ref   += fabs(rCPU);
            }
        L1norm = sum_delta / sum_ref;
        printf("L1 norm: %E\n", L1norm);
    printf((L1norm < 1e-6) ? "TEST PASSED\n" : "TEST FAILED\n");


    printf("Shutting down...\n");
        cutilSafeCall( cudaUnbindTexture(texData) );
        cutilSafeCall( cudaFree(d_Result)   );
        cutilSafeCall( cudaFreeArray(a_Data)   );
        free(h_ResultGPU);
        free(h_DataB);
        free(h_DataA);
        free(h_Kernel);

    cutilExit(argc, argv);

    cudaThreadExit();
}
