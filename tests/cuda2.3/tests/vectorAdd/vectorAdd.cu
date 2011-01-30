/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation. 
 * Any use, reproduction, disclosure, or distribution of this software 
 * and related documentation without an express license agreement from
 * NVIDIA Corporation is strictly prohibited.
 *
 * Please refer to the applicable NVIDIA end user license agreement (EULA) 
 * associated with this source code for terms and conditions that govern 
 * your use of this NVIDIA software.
 * 
 */

/* Vector addition: C = A + B.
 *
 * This sample is a very basic sample that implements element by element
 * vector addition. It is the same as the sample illustrating Chapter 3
 * of the programming guide with some additions like error checking.
 *
 */

// Includes
#include <stdio.h>

// Variables
float* h_A;
float* h_B;
float* h_C;
float* d_A;
float* d_B;
float* d_C;
bool noprompt = false;

// Functions
void Cleanup(bool);
void RandomInit(float*, int);
void ParseArguments(int, char**);

// Device code
__global__ void VecAdd(const float* A, const float* B, float* C, int N)
{
    int i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < N)
        C[i] = A[i] + B[i];
}

// Host code
int main(int argc, char** argv)
{
    printf("Vector addition\n");
    int N = 50000;
    size_t size = N * sizeof(float);
    cudaError_t error;
    ParseArguments(argc, argv);

    // Allocate input vectors h_A and h_B in host memory
    h_A = (float*)malloc(size);
    if (h_A == 0) Cleanup(false);
    h_B = (float*)malloc(size);
    if (h_B == 0) Cleanup(false);
    h_C = (float*)malloc(size);
    if (h_C == 0) Cleanup(false);
    
    // Initialize input vectors
    RandomInit(h_A, N);
    RandomInit(h_B, N);

    // Allocate vectors in device memory
    error = cudaMalloc((void**)&d_A, size);
    if (error != cudaSuccess) Cleanup(false);
    error = cudaMalloc((void**)&d_B, size);
    if (error != cudaSuccess) Cleanup(false);
    error = cudaMalloc((void**)&d_C, size);
    if (error != cudaSuccess) Cleanup(false);

    // Copy vectors from host memory to device memory
    error = cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    if (error != cudaSuccess) Cleanup(false);
    error = cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);
    if (error != cudaSuccess) Cleanup(false);

    // Invoke kernel
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
    VecAdd<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, N);
    error = cudaGetLastError();
    if (error != cudaSuccess) Cleanup(false);
#ifdef _DEBUG
    error = cudaThreadSynchronize();
    if (error != cudaSuccess) Cleanup(false);
#endif

    // Copy result from device memory to host memory
    // h_C contains the result in host memory
    error = cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
    if (error != cudaSuccess) Cleanup(false);
    
    // Verify result
    int i;
    for (i = 0; i < N; ++i) {
        float sum = h_A[i] + h_B[i];
        if (fabs(h_C[i] - sum) > 1e-5)
            break;
    }
    printf("Test %s \n", (i == N) ? "PASSED" : "FAILED");
    
    Cleanup(true);
}

void Cleanup(bool noError)
{
    cudaError_t error;
        
    // Free device memory
    if (d_A)
        error = cudaFree(d_A);
    if (d_B)
        error = cudaFree(d_B);
    if (d_C)
        error = cudaFree(d_C);

    // Free host memory
    if (h_A)
        free(h_A);
    if (h_B)
        free(h_B);
    if (h_C)
        free(h_C);
        
    error = cudaThreadExit();
    
    if (!noError || error != cudaSuccess)
        printf("Function call failed\nTest FAILED\n");
    
    if (!noprompt) {
        printf("\nPress ENTER to exit...\n");
        fflush( stdout);
        fflush( stderr);
        getchar();
    }

    exit(0);
}

// Allocates an array with random float entries.
void RandomInit(float* data, int n)
{
    for (int i = 0; i < n; ++i)
        data[i] = rand() / (float)RAND_MAX;
}

// Parse program arguments
void ParseArguments(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i)
        if (strcmp(argv[i], "--noprompt") == 0 ||
			strcmp(argv[i], "-noprompt") == 0) 
		{
            noprompt = true;
            break;
        }
}
