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
 * This sample implements a conjugate graident solver on GPU
 * using CUBLAS and CUSPARSE
 * 
 */


// Utilities and system includes
#include <shrUtils.h>
#include <cutil_inline.h>
#include <cusparse.h>
#include <cublas.h>

const char * sSDKname	  = "conjugateGradient";

/* genTridiag: generate a random tridiagonal symmetric matrix */
void genTridiag(int *I, int *J, float *val, int M, int N, int nz)
{
    I[0] = 0, J[0] = 0, J[1] = 1;
    val[0] = (float)rand()/RAND_MAX + 10.0;
    val[1] = (float)rand()/RAND_MAX;
    int start;
    for (int i = 1; i < N; i++) {
        if (i > 1) 
            I[i] = I[i-1]+3;
        else 
            I[1] = 2;
        start = (i-1)*3 + 2;
        J[start] = i - 1;
        J[start+1] = i;
        if (i < N-1) 
            J[start+2] = i + 1;
        val[start] = val[start-1];
        val[start+1] = (float)rand()/RAND_MAX + 10.0;
        if (i < N-1) 
            val[start+2] = (float)rand()/RAND_MAX;
    }
    I[N] = nz;
}

int main(int argc, char **argv)
{
	int M = 0, N = 0, nz = 0, *I = NULL, *J = NULL;
    float *val = NULL;
    const float tol = 1e-5;   
    const int max_iter = 10000;
    float *x; 
    float *rhs; 
    float a, b, r0, r1;
    int *d_col, *d_row;
    float *d_val, *d_x;
    float *d_r, *d_p, *d_Ax;
    int k;

    shrSetLogFileName ("conjugateGradient.txt");
    shrLog("%s Starting...\n\n", argv[0]);

    // This will pick the best possible CUDA capable device
    cudaDeviceProp deviceProp;
    int devID = cutilChooseCudaDevice(argc, argv);
    if (devID < 0) {
       printf("exiting...\n");
       cutilExit(argc, argv);
       exit(0);
    }
    cutilSafeCall( cudaGetDeviceProperties(&deviceProp, devID) );

    // Statistics about the GPU device
    printf("> GPU device has %d Multi-Processors, SM %d.%d compute capabilities\n\n", 
		deviceProp.multiProcessorCount, deviceProp.major, deviceProp.minor);

    int version = (deviceProp.major * 0x10 + deviceProp.minor);
    if(version < 0x11) 
    {
        printf("%s: requires a minimum CUDA compute 1.1 capability\n", sSDKname);
        printf("PASSED");
        cudaThreadExit();
        cutilExit(argc, argv);
    }

    /* Generate a random tridiagonal symmetric matrix in CSR format */
    M = N = 1048576;
    nz = (N-2)*3 + 4;
    I = (int*)malloc(sizeof(int)*(N+1));
    J = (int*)malloc(sizeof(int)*nz);
    val = (float*)malloc(sizeof(float)*nz);
    genTridiag(I, J, val, M, N, nz);

    x = (float*)malloc(sizeof(float)*N);
    rhs = (float*)malloc(sizeof(float)*N);

    for (int i = 0; i < N; i++) {
        rhs[i] = 1.0;
        x[i] = 0.0;
    }

    cusparseHandle_t handle = 0;
    cusparseStatus_t status;
    status = cusparseCreate(&handle);
    if (status != CUSPARSE_STATUS_SUCCESS) {
        fprintf( stderr, "!!!! CUSPARSE initialization error\n" );
        return EXIT_FAILURE;
    }

    cusparseMatDescr_t descr = 0;
    status = cusparseCreateMatDescr(&descr); 
    if (status != CUSPARSE_STATUS_SUCCESS) {
        fprintf( stderr, "!!!! CUSPARSE cusparseCreateMatDescr error\n" );
        return EXIT_FAILURE;
    } 
    cusparseSetMatType(descr,CUSPARSE_MATRIX_TYPE_GENERAL);
    cusparseSetMatIndexBase(descr,CUSPARSE_INDEX_BASE_ZERO);
    
    cutilSafeCall( cudaMalloc((void**)&d_col, nz*sizeof(int)) );
    cutilSafeCall( cudaMalloc((void**)&d_row, (N+1)*sizeof(int)) );
    cutilSafeCall( cudaMalloc((void**)&d_val, nz*sizeof(float)) );
    cutilSafeCall( cudaMalloc((void**)&d_x, N*sizeof(float)) );  
    cutilSafeCall( cudaMalloc((void**)&d_r, N*sizeof(float)) );
    cutilSafeCall( cudaMalloc((void**)&d_p, N*sizeof(float)) );
    cutilSafeCall( cudaMalloc((void**)&d_Ax, N*sizeof(float)) );

    cudaMemcpy(d_col, J, nz*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_row, I, (N+1)*sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_val, val, nz*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_x, x, N*sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_r, rhs, N*sizeof(float), cudaMemcpyHostToDevice);

    cusparseScsrmv(handle,CUSPARSE_OPERATION_NON_TRANSPOSE, N, N, 1.0, descr, d_val, d_row, d_col, d_x, 0.0, d_Ax);
    cublasSaxpy(N, -1.0, d_Ax, 1, d_r, 1);
    r1 = cublasSdot(N, d_r, 1, d_r, 1);

    k = 1;
    while (r1 > tol*tol && k <= max_iter) {
        if (k > 1) {
            b = r1 / r0;
            cublasSscal(N, b, d_p, 1);
            cublasSaxpy(N, 1.0, d_r, 1, d_p, 1);
        } else {
            cublasScopy(N, d_r, 1, d_p, 1);
        }

        cusparseScsrmv(handle, CUSPARSE_OPERATION_NON_TRANSPOSE, N, N, 1.0, descr, d_val, d_row, d_col, d_p, 0.0, d_Ax);
        a = r1 / cublasSdot(N, d_p, 1, d_Ax, 1);
        cublasSaxpy(N, a, d_p, 1, d_x, 1);
        cublasSaxpy(N, -a, d_Ax, 1, d_r, 1);

        r0 = r1;
        r1 = cublasSdot(N, d_r, 1, d_r, 1);
        cudaThreadSynchronize();
        shrLog("iteration = %3d, residual = %e\n", k, sqrt(r1));
        k++;
    }

    cudaMemcpy(x, d_x, N*sizeof(float), cudaMemcpyDeviceToHost);

    float rsum, diff, err = 0.0;
    for (int i = 0; i < N; i++) {
        rsum = 0.0;
        for (int j = I[i]; j < I[i+1]; j++) {
            rsum += val[j]*x[J[j]];
        }
        diff = fabs(rsum - rhs[i]);
        if (diff > err) err = diff;
    }

    shrLog("Test %s, err = %f\n", (k <= max_iter) ? "Passed." : "Failed!", err);
    cusparseDestroy(handle);

    free(I);
    free(J);
    free(val);
    free(x);
    free(rhs);
    cudaFree(d_col);
    cudaFree(d_row);
    cudaFree(d_val);
    cudaFree(d_x);
    cudaFree(d_r);
    cudaFree(d_p);
    cudaFree(d_Ax);

    cudaThreadExit();

    shrEXIT(argc, (const char**)argv);
}
