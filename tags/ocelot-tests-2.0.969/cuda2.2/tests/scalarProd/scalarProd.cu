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
 * This sample calculates scalar products of a 
 * given set of input vector pairs
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <cutil_inline.h>



///////////////////////////////////////////////////////////////////////////////
// Calculate scalar products of VectorN vectors of ElementN elements on CPU
///////////////////////////////////////////////////////////////////////////////
extern "C"
void scalarProdCPU(
    float *h_C,
    float *h_A,
    float *h_B,
    int vectorN,
    int elementN
);



///////////////////////////////////////////////////////////////////////////////
// Calculate scalar products of VectorN vectors of ElementN elements on GPU
///////////////////////////////////////////////////////////////////////////////
#include "scalarProd_kernel.cu"



////////////////////////////////////////////////////////////////////////////////
// Helper function, returning uniformly distributed
// random float in [low, high] range
////////////////////////////////////////////////////////////////////////////////
float RandFloat(float low, float high){
    float t = (float)rand() / (float)RAND_MAX;
    return (1.0f - t) * low + t * high;
}



///////////////////////////////////////////////////////////////////////////////
// Data configuration
///////////////////////////////////////////////////////////////////////////////

//Total number of input vector pairs; arbitrary
const int VECTOR_N = 256;
//Number of elements per vector; arbitrary, 
//but strongly preferred to be a multiple of warp size
//to meet memory coalescing constraints
const int ELEMENT_N = 4096;
//Total number of data elements
const int    DATA_N = VECTOR_N * ELEMENT_N;

const int   DATA_SZ = DATA_N * sizeof(float);
const int RESULT_SZ = VECTOR_N  * sizeof(float);



///////////////////////////////////////////////////////////////////////////////
// Main program
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv){
    float *h_A, *h_B, *h_C_CPU, *h_C_GPU;
    float *d_A, *d_B, *d_C;
    double delta, ref, sum_delta, sum_ref, L1norm;
    unsigned int hTimer;
    int i;

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    cutilCheckError( cutCreateTimer(&hTimer) );

    printf("Initializing data...\n");
        printf("...allocating CPU memory.\n");
        h_A     = (float *)malloc(DATA_SZ);
        h_B     = (float *)malloc(DATA_SZ);
        h_C_CPU = (float *)malloc(RESULT_SZ);
        h_C_GPU = (float *)malloc(RESULT_SZ);

        printf("...allocating GPU memory.\n");
        cutilSafeCall( cudaMalloc((void **)&d_A, DATA_SZ)   );
        cutilSafeCall( cudaMalloc((void **)&d_B, DATA_SZ)   );
        cutilSafeCall( cudaMalloc((void **)&d_C, RESULT_SZ) );

        printf("...generating input data in CPU mem.\n");
        srand(123);
        //Generating input data on CPU
        for(i = 0; i < DATA_N; i++){
            h_A[i] = RandFloat(0.0f, 1.0f);
            h_B[i] = RandFloat(0.0f, 1.0f);
        }

        printf("...copying input data to GPU mem.\n");
        //Copy options data to GPU memory for further processing 
        cutilSafeCall( cudaMemcpy(d_A, h_A, DATA_SZ, cudaMemcpyHostToDevice) );
        cutilSafeCall( cudaMemcpy(d_B, h_B, DATA_SZ, cudaMemcpyHostToDevice) );
    printf("Data init done.\n");


    printf("Executing GPU kernel...\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutResetTimer(hTimer) );
        cutilCheckError( cutStartTimer(hTimer) );
        scalarProdGPU<<<128, 256>>>(d_C, d_A, d_B, VECTOR_N, ELEMENT_N);
        cutilCheckMsg("scalarProdGPU() execution failed\n");
        cutilSafeCall( cudaThreadSynchronize() );
        cutilCheckError( cutStopTimer(hTimer) );
    printf("GPU time: %f msecs.\n", cutGetTimerValue(hTimer));

    printf("Reading back GPU result...\n");
        //Read back GPU results to compare them to CPU results
        cutilSafeCall( cudaMemcpy(h_C_GPU, d_C, RESULT_SZ, cudaMemcpyDeviceToHost) );


    printf("Checking GPU results...\n");
        printf("..running CPU scalar product calculation\n");
        scalarProdCPU(h_C_CPU, h_A, h_B, VECTOR_N, ELEMENT_N);

        printf("...comparing the results\n");
        //Calculate max absolute difference and L1 distance
        //between CPU and GPU results
        sum_delta = 0;
        sum_ref   = 0;
        for(i = 0; i < VECTOR_N; i++){
            delta = fabs(h_C_GPU[i] - h_C_CPU[i]);
            ref   = h_C_CPU[i];
            sum_delta += delta;
            sum_ref   += ref;
        }
        L1norm = sum_delta / sum_ref;
    printf("L1 error: %E\n", L1norm);
    printf((L1norm < 1e-6) ? "TEST PASSED\n" : "TEST FAILED\n");


    printf("Shutting down...\n");
        cutilSafeCall( cudaFree(d_C) );
        cutilSafeCall( cudaFree(d_B)   );
        cutilSafeCall( cudaFree(d_A)   );
        free(h_C_GPU);
        free(h_C_CPU);
        free(h_B);
        free(h_A);
        cutilCheckError( cutDeleteTimer(hTimer) );

    cudaThreadExit();

    cutilExit(argc, argv);

}
