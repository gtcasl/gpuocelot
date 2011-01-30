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

/* Matrix multiplication: C = A * B.
 * Host code.
 *
 * This sample implements matrix multiplication as described in Chapter 3
 * of the programming guide.
 * It has been written for clarity of exposition to illustrate various CUDA
 * programming principles, not with the goal of providing the most
 * performant generic kernel for matrix multiplication.
 *
 * CUBLAS provides high-performance matrix multiplication.
 * See also:
 * V. Volkov and J. Demmel, "Benchmarking GPUs to tune dense linear algebra,"
 * in Proc. 2008 ACM/IEEE Conf. on Superconducting (SC '08),
 * Piscataway, NJ: IEEE Press, 2008, pp. Art. 31:1-11. 
 *
 */

// Utilities and system includes
#include <shrUtils.h>
#include "cutil_inline.h"

// includes, kernels
#include <matrixMul_kernel.cu>

static char *sSDKsample = "matrixMul";

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest(int argc, char** argv);
void randomInit(float*, int);
void printDiff(float*, float*, int, int, int, float);

extern "C"
void computeGold(float*, const float*, const float*, unsigned int, unsigned int, unsigned int);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	printf("[ %s ]\n", sSDKsample);

    shrSetLogFileName ("matrixMul.txt");
    shrLog("%s Starting...\n\n", argv[0]);

    runTest(argc, argv);

    shrEXIT(argc, (const char**)argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void runTest(int argc, char** argv)
{
    if(shrCheckCmdLineFlag(argc, (const char**)argv, "device"))
    {
        cutilDeviceInit(argc, argv);
    }
    else
    {
        cudaSetDevice(cutGetMaxGflopsDeviceId());
    }

    int devID;
    cudaDeviceProp props;

    // get number of SMs on this GPU
    cutilSafeCall(cudaGetDevice(&devID));
    cutilSafeCall(cudaGetDeviceProperties(&props, devID));

    printf("Device %d: \"%s\" with Compute %d.%d capability\n", devID, props.name, props.major, props.minor);

	// set seed for rand()
    srand(2006);

    // Optional Command-line multiplier for matrix sizes
    unsigned int uiWA, uiHA, uiWB, uiHB, uiWC, uiHC;
    int iSizeMultiple = 1;
    shrGetCmdLineArgumenti(argc, (const char**)argv, "sizemult", &iSizeMultiple); 
    iSizeMultiple = CLAMP(iSizeMultiple, 1, 10);

	// For GPUs with fewer # of SM's, we limit the maximum size of the matrix
	if (props.multiProcessorCount <= 4) {
		uiWA = 2 * BLOCK_SIZE * iSizeMultiple;
		uiHA = 4 * BLOCK_SIZE * iSizeMultiple;
		uiWB = 2 * BLOCK_SIZE * iSizeMultiple;
		uiHB = 4 * BLOCK_SIZE * iSizeMultiple;
		uiWC = 2 * BLOCK_SIZE * iSizeMultiple;
		uiHC = 4 * BLOCK_SIZE * iSizeMultiple;
	} else {
		uiWA = WA * iSizeMultiple;
		uiHA = HA * iSizeMultiple;
		uiWB = WB * iSizeMultiple;
		uiHB = HB * iSizeMultiple;
		uiWC = WC * iSizeMultiple;
		uiHC = HC * iSizeMultiple;
	}
    shrLog("\nUsing Matrix Sizes: A(%u x %u), B(%u x %u), C(%u x %u)\n\n", 
            uiWA, uiHA, uiWB, uiHB, uiWC, uiHC);

    // allocate host memory for matrices A and B
    unsigned int size_A = uiWA * uiHA;
    unsigned int mem_size_A = sizeof(float) * size_A;
    float* h_A = (float*)malloc(mem_size_A);
    unsigned int size_B = uiWB * uiHB;
    unsigned int mem_size_B = sizeof(float) * size_B;
    float* h_B = (float*)malloc(mem_size_B);

    // initialize host memory
    randomInit(h_A, size_A);
    randomInit(h_B, size_B);

    // allocate device memory
    float* d_A;
    cutilSafeCall(cudaMalloc((void**) &d_A, mem_size_A));
    float* d_B;
    cutilSafeCall(cudaMalloc((void**) &d_B, mem_size_B));

    // copy host memory to device
    cutilSafeCall(cudaMemcpy(d_A, h_A, mem_size_A,
                              cudaMemcpyHostToDevice) );
    cutilSafeCall(cudaMemcpy(d_B, h_B, mem_size_B,
                              cudaMemcpyHostToDevice) );

    // allocate device memory for result
    unsigned int size_C = uiWC * uiHC;
    unsigned int mem_size_C = sizeof(float) * size_C;
    float* d_C;
    cutilSafeCall(cudaMalloc((void**) &d_C, mem_size_C));

    // allocate host memory for the result
    float* h_C = (float*) malloc(mem_size_C);
    

    // setup execution parameters
    dim3 threads(BLOCK_SIZE, BLOCK_SIZE);
    dim3 grid(uiWC / threads.x, uiHC / threads.y);

    // kernel warmup
    matrixMul<<< grid, threads >>>(d_C, d_A, d_B, uiWA, uiWB);
    cudaThreadSynchronize();
    
    // create and start timer
    shrLog("Run Kernels...\n\n");
    unsigned int timer = 0;
    cutilCheckError(cutCreateTimer(&timer));
    cutilCheckError(cutStartTimer(timer));

    // execute the kernel
    int nIter = 30;
    for (int j = 0; j < nIter; j++) 
		{
            matrixMul<<< grid, threads >>>(d_C, d_A, d_B, uiWA, uiWB);
        }

    // check if kernel execution generated and error
    cutilCheckMsg("Kernel execution failed");

    cudaThreadSynchronize();
    // stop and destroy timer
    cutilCheckError(cutStopTimer(timer));
    double dSeconds = cutGetTimerValue(timer)/((double)nIter * 1000.0);
    double dNumOps = 2.0 * (double)uiWA * (double)uiHA * (double)uiWB;
    double gflops = 1.0e-9 * dNumOps/dSeconds;

    //Log througput, etc
    shrLogEx(LOGBOTH | MASTER, 0, "matrixMul, Throughput = %.4f GFlop/s, Time = %.5f s, Size = %.0f Ops, NumDevsUsed = %d, Workgroup = %u\n", 
            gflops, dSeconds, dNumOps, 1, threads.x * threads.y);
    cutilCheckError(cutDeleteTimer(timer));

    // copy result from device to host
    cutilSafeCall(cudaMemcpy(h_C, d_C, mem_size_C,
                              cudaMemcpyDeviceToHost) );

    // compute reference solution
    shrLog("\nCheck against Host computation...\n\n");    
    float* reference = (float*)malloc(mem_size_C);
    computeGold(reference, h_A, h_B, uiHA, uiWA, uiWB);

    // check result
    shrBOOL res = shrCompareL2fe(reference, h_C, size_C, 1.0e-6f);
    if (res != shrTRUE) 
    {
        printDiff(reference, h_C, uiWC, uiHC, 100, 1.0e-5f);
    }
    shrLog("%s \n\n", (shrTRUE == res) ? "PASSED" : "FAILED");

    // clean up memory
    free(h_A);
    free(h_B);
    free(h_C);
    free(reference);
    cutilSafeCall(cudaFree(d_A));
    cutilSafeCall(cudaFree(d_B));
    cutilSafeCall(cudaFree(d_C));

    cudaThreadExit();
}

// Allocates a matrix with random float entries.
void randomInit(float* data, int size)
{
    for (int i = 0; i < size; ++i)
        data[i] = rand() / (float)RAND_MAX;
}

void printDiff(float *data1, float *data2, int width, int height, int iListLength, float fListTol)
{
    shrLog("Listing first %d Differences > %.6f...\n", iListLength, fListTol);
    int i,j,k;
    int error_count=0;
    for (j = 0; j < height; j++) 
    {
        if (error_count < iListLength)
        {
            shrLog("\n  Row %d:\n", j);
        }
        for (i = 0; i < width; i++) 
        {
            k = j * width + i;
            float fDiff = fabs(data1[k] - data2[k]);
            if (fDiff > fListTol) 
            {                
                if (error_count < iListLength)
                {
                    shrLog("    Loc(%d,%d)\tCPU=%.5f\tGPU=%.5f\tDiff=%.6f\n", i, j, data1[k], data2[k], fDiff);
                }
                error_count++;
            }
        }
    }
    shrLog(" \n  Total Errors = %d\n\n", error_count);
}
