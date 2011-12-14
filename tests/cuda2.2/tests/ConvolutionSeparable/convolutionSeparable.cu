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
 * This sample implements a separable convolution filter 
 * of a 2D signal with a gaussian kernel.
 */



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cutil_inline.h>



////////////////////////////////////////////////////////////////////////////////
// Common host and device functions
////////////////////////////////////////////////////////////////////////////////
//Round a / b to nearest higher integer value
int iDivUp(int a, int b){
    return (a % b != 0) ? (a / b + 1) : (a / b);
}

//Round a / b to nearest lower integer value
int iDivDown(int a, int b){
    return a / b;
}

//Align a to nearest higher multiple of b
int iAlignUp(int a, int b){
    return (a % b != 0) ?  (a - a % b + b) : a;
}

//Align a to nearest lower multiple of b
int iAlignDown(int a, int b){
    return a - a % b;
}



////////////////////////////////////////////////////////////////////////////////
// Reference CPU convolution
////////////////////////////////////////////////////////////////////////////////
extern "C" void convolutionRowCPU(
    float *h_Result,
    float *h_Data,
    float *h_Kernel,
    int dataW,
    int dataH,
    int kernelR
);

extern "C" void convolutionColumnCPU(
    float *h_Result,
    float *h_Data,
    float *h_Kernel,
    int dataW,
    int dataH,
    int kernelR
);



////////////////////////////////////////////////////////////////////////////////
// GPU convolution
////////////////////////////////////////////////////////////////////////////////
//Global macro, controlling innermost convolution loop unrolling
#define UNROLL_INNER
#include <tests/ConvolutionSeparable/convolutionSeparable_kernel.cu>



////////////////////////////////////////////////////////////////////////////////
// Data configuration
////////////////////////////////////////////////////////////////////////////////
//Image width should be aligned to maximum coalesced read/write size
//for best global memory performance in both row and column filter.
#if 1
//Reduce problem size to have reasonable emulation time
const int      DATA_W = iAlignUp(256, 16);
const int      DATA_H = 256;
#else
const int      DATA_W = iAlignUp(3072, 16);
const int      DATA_H = 3072;
#endif
const int   DATA_SIZE = DATA_W * DATA_H * sizeof(float);
const int KERNEL_SIZE = KERNEL_W * sizeof(float);



//Carry out dummy calculations before main computation loop
//in order to "warm up" the hardware/driver
#define WARMUP
////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    float
        *h_Kernel,
        *h_DataA,
        *h_DataB,
        *h_ResultGPU;

    float
        *d_DataA,
        *d_DataB,
        *d_Temp;

    double
        sum_delta, sum_ref, L1norm, gpuTime;

    int i;

    unsigned int hTimer;

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s

    if ( cutCheckCmdLineFlag(argc, (const char **)argv, "device"))
	    cutilDeviceInit(argc, argv);
    else
	    cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError(cutCreateTimer(&hTimer));

    printf("%i x %i\n", DATA_W, DATA_H);
    printf("Initializing data...\n");
        h_Kernel    = (float *)malloc(KERNEL_SIZE);
        h_DataA     = (float *)malloc(DATA_SIZE);
        h_DataB     = (float *)malloc(DATA_SIZE);
        h_ResultGPU = (float *)malloc(DATA_SIZE);
        cutilSafeCall( cudaMalloc( (void **)&d_DataA, DATA_SIZE) );
        cutilSafeCall( cudaMalloc( (void **)&d_DataB, DATA_SIZE) );
        cutilSafeCall( cudaMalloc( (void **)&d_Temp , DATA_SIZE) );

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
        cutilSafeCall( cudaMemcpy(d_DataA, h_DataA, DATA_SIZE, cudaMemcpyHostToDevice) );


    dim3 blockGridRows(iDivUp(DATA_W, ROW_TILE_W), DATA_H);
    dim3 blockGridColumns(iDivUp(DATA_W, COLUMN_TILE_W), iDivUp(DATA_H, COLUMN_TILE_H));
    dim3 threadBlockRows(KERNEL_RADIUS_ALIGNED + ROW_TILE_W + KERNEL_RADIUS);
    dim3 threadBlockColumns(COLUMN_TILE_W, 8);


#ifdef WARMUP
    printf("Warm up...\n");
    convolutionRowGPU<<<blockGridRows, threadBlockRows>>>(
        d_Temp,
        d_DataA,
        DATA_W,
        DATA_H
    );
    cutilCheckMsg("convolutionRowGPU() execution failed\n");

    convolutionColumnGPU<<<blockGridColumns, threadBlockColumns>>>(
        d_Temp,
        d_DataA,
        DATA_W,
        DATA_H,
        COLUMN_TILE_W * threadBlockColumns.y,
        DATA_W * threadBlockColumns.y
    );
    cutilCheckMsg("convolutionColumnGPU() execution failed\n");
    cutilSafeCall( cudaThreadSynchronize() );
#endif


    printf("GPU convolution...\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        convolutionRowGPU<<<blockGridRows, threadBlockRows>>>(
            d_DataB,
            d_DataA,
            DATA_W,
            DATA_H
        );
        cutilCheckMsg("convolutionRowGPU() execution failed\n");

        convolutionColumnGPU<<<blockGridColumns, threadBlockColumns>>>(
            d_DataA,
            d_DataB,
            DATA_W,
            DATA_H,
            COLUMN_TILE_W * threadBlockColumns.y,
            DATA_W * threadBlockColumns.y
        );
        cutilCheckMsg("convolutionColumnGPU() execution failed\n");
    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError(cutStopTimer(hTimer));
    gpuTime = cutGetTimerValue(hTimer);
    printf("GPU convolution time : %f msec //%f Mpixels/sec\n", gpuTime, 1e-6 * DATA_W * DATA_H / (gpuTime * 0.001));

    printf("Reading back GPU results...\n");
        cutilSafeCall( cudaMemcpy(h_ResultGPU, d_DataA, DATA_SIZE, cudaMemcpyDeviceToHost) );


    printf("Checking the results...\n");
        printf("...running convolutionRowCPU()\n");
        convolutionRowCPU(
            h_DataB,
            h_DataA,
            h_Kernel,
            DATA_W,
            DATA_H,
            KERNEL_RADIUS
        );

        printf("...running convolutionColumnCPU()\n");
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
        for(i = 0; i < DATA_W * DATA_H; i++){
            sum_delta += fabs(h_DataA[i] - h_ResultGPU[i]);
            sum_ref   += fabs(h_DataA[i]);
        }
        L1norm = sum_delta / sum_ref;
        printf("L1 norm: %E\n", L1norm);
    printf((L1norm < 1e-6) ? "TEST PASSED\n" : "TEST FAILED\n");

    printf("Shutting down...\n");
        cutilSafeCall( cudaFree(d_Temp ) );
        cutilSafeCall( cudaFree(d_DataB) );
        cutilSafeCall( cudaFree(d_DataA) );
        free(h_ResultGPU);
        free(h_DataB);
        free(h_DataA);
        free(h_Kernel);

    cutilCheckError(cutDeleteTimer(hTimer));

    cudaThreadExit();

    cutilExit(argc, argv);
}
