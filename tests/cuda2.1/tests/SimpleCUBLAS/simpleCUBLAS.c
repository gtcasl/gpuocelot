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

/* This example demonstrates how to use the CUBLAS library
 * by scaling an array of floating-point values on the device
 * and comparing the result to the same operation performed
 * on the host.
 */

/* Includes, system */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Includes, cuda */
#include "cublas.h"

/* Matrix size */
#define N  (275)

/* Host implementation of a simple version of sgemm */
static void simple_sgemm(int n, float alpha, const float *A, const float *B,
                         float beta, float *C)
{
    int i;
    int j;
    int k;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            float prod = 0;
            for (k = 0; k < n; ++k) {
                prod += A[k * n + i] * B[j * n + k];
            }
            C[j * n + i] = alpha * prod + beta * C[j * n + i];
        }
    }
}

static void print_matrix(FILE *file, float *A, int M, int n) {
	int i, j;
	fprintf(file, "[ ");

	for (i = 0; i < M; i++) {
		for (j = 0; j < n; j++) {
			fprintf(file, "%0.2f ", A[i + j * n]);
		}
		fprintf(file, ";\n");
	}

	fprintf(file, "];\n");
}

/* Main */
int main(int argc, char** argv)
{    
    cublasStatus status;
    float* h_A;
    float* h_B;
    float* h_C;
    float* h_C_ref;
    float* d_A = 0;
    float* d_B = 0;
    float* d_C = 0;
    float alpha = 1.0f;
    float beta = 0.0f;
    int n2 = N * N;
    int i, j;
    float error_norm;
    float ref_norm;
    float diff;

    /* Initialize CUBLAS */
    printf("simpleCUBLAS test running..\n");

    status = cublasInit();
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! CUBLAS initialization error\n");
        return EXIT_FAILURE;
    }

    /* Allocate host memory for the matrices */
    h_A = (float*)malloc(n2 * sizeof(h_A[0]));
    if (h_A == 0) {
        fprintf (stderr, "!!!! host memory allocation error (A)\n");
        return EXIT_FAILURE;
    }
    h_B = (float*)malloc(n2 * sizeof(h_B[0]));
    if (h_B == 0) {
        fprintf (stderr, "!!!! host memory allocation error (B)\n");
        return EXIT_FAILURE;
    }
    h_C = (float*)malloc(n2 * sizeof(h_C[0]));
    if (h_C == 0) {
        fprintf (stderr, "!!!! host memory allocation error (C)\n");
        return EXIT_FAILURE;
    }

    /* Fill the matrices with test data */
    for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
		    if(j < i) h_A[i + j * N] = 1; else h_A[i + j * N] = 0;
		    if(j < i) h_B[i + j * N] = 1; else h_B[i + j * N] = 0;
		    h_C[i + j * N] = 0;
		}
    }

    /* Allocate device memory for the matrices */
    status = cublasAlloc(n2, sizeof(d_A[0]), (void**)&d_A);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! device memory allocation error (A)\n");
        return EXIT_FAILURE;
    }
    status = cublasAlloc(n2, sizeof(d_B[0]), (void**)&d_B);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! device memory allocation error (B)\n");
        return EXIT_FAILURE;
    }
    status = cublasAlloc(n2, sizeof(d_C[0]), (void**)&d_C);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! device memory allocation error (C)\n");
        return EXIT_FAILURE;
    }

    /* Initialize the device matrices with the host matrices */
    status = cublasSetVector(n2, sizeof(h_A[0]), h_A, 1, d_A, 1);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! device access error (write A)\n");
        return EXIT_FAILURE;
    }
    status = cublasSetVector(n2, sizeof(h_B[0]), h_B, 1, d_B, 1);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! device access error (write B)\n");
        return EXIT_FAILURE;
    }
    status = cublasSetVector(n2, sizeof(h_C[0]), h_C, 1, d_C, 1);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! device access error (write C)\n");
        return EXIT_FAILURE;
    }
    
    /* Performs operation using plain C code */
    simple_sgemm(N, alpha, h_A, h_B, beta, h_C);
    h_C_ref = h_C;

    /* Clear last error */
    status = cublasGetError();

    /* Performs operation using cublas */
    cublasSgemm('n', 'n', N, N, N, alpha, d_A, N, d_B, N, beta, d_C, N);
    status = cublasGetError();
    if (status != CUBLAS_STATUS_SUCCESS) {
        switch (status) {
			case CUBLAS_STATUS_NOT_INITIALIZED:
				fprintf (stderr, "CUBLAS library not initialized\n");
				break;
			case CUBLAS_STATUS_ALLOC_FAILED:
				fprintf (stderr, "resource allocation failed\n");
				break;
			case CUBLAS_STATUS_INVALID_VALUE:
				fprintf (stderr, "unsupported numerical value was passed%s",
					" to function\n");
				break;
			case CUBLAS_STATUS_ARCH_MISMATCH:
				fprintf (stderr, "function requires an architectural%s", 
					" feature absent from the architecture of the device\n");
				break;
			case CUBLAS_STATUS_MAPPING_ERROR:
				fprintf (stderr, "access to GPU memory space failed\n");
				break;
			case CUBLAS_STATUS_EXECUTION_FAILED:
				fprintf (stderr, "GPU program failed to execute\n");
				break;
			case CUBLAS_STATUS_INTERNAL_ERROR:
				fprintf (stderr, "an internal CUBLAS operation failed\n");
				break;
			default: break;
        }
        return EXIT_FAILURE;
    }
    
    /* Allocate host memory for reading back the result from device memory */
    h_C = (float*)malloc(n2 * sizeof(h_C[0]));
    if (h_C == 0) {
        fprintf (stderr, "!!!! host memory allocation error (C)\n");
        return EXIT_FAILURE;
    }

    /* Read the result back */
    status = cublasGetVector(n2, sizeof(h_C[0]), d_C, 1, h_C, 1);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! device access error (read C)\n");
        return EXIT_FAILURE;
    }

    /* Check result against reference */
    error_norm = 0;
    ref_norm = 0;
    for (i = 0; i < n2; ++i) {
        diff = h_C_ref[i] - h_C[i];
        error_norm += diff * diff;
        ref_norm += h_C_ref[i] * h_C_ref[i];
    }
    error_norm = (float)sqrt((double)error_norm);
    ref_norm = (float)sqrt((double)ref_norm);
    if (fabs(ref_norm) < 1e-7) {
        fprintf (stderr, "!!!! reference norm is 0\n");
        return EXIT_FAILURE;
    }
    printf( "GPU error norm was %f\n", error_norm / ref_norm);
    
    if(error_norm / ref_norm < 1e-6f) {
    	printf("Test PASSED\n");
    }
    else {
		FILE *out = fopen("output.m", "w");
		fprintf(out, "A = ");
		print_matrix(out, h_A, N, N);
		fprintf(out, "\nB = ");
		print_matrix(out, h_B, N, N);
		fprintf(out, "\nC = ");
		print_matrix(out, h_C, N, N);
		fprintf(out, "\nC_ref = ");
		print_matrix(out, h_C_ref, N, N);
		fclose(out);
		printf("Test FAILED - matrix product incorrect\n");
	}

    /* Memory clean up */
    free(h_A);
    free(h_B);
    free(h_C);
    free(h_C_ref);
    status = cublasFree(d_A);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! memory free error (A)\n");
        return EXIT_FAILURE;
    }
    status = cublasFree(d_B);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! memory free error (B)\n");
        return EXIT_FAILURE;
    }
    status = cublasFree(d_C);
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! memory free error (C)\n");
        return EXIT_FAILURE;
    }

    /* Shutdown */
    status = cublasShutdown();
    if (status != CUBLAS_STATUS_SUCCESS) {
        fprintf (stderr, "!!!! shutdown error (A)\n");
        return EXIT_FAILURE;
    }

    if (argc > 1) {
        if (!strcmp(argv[1], "-noprompt") ||
            !strcmp(argv[1], "-qatest") ) 
        {
            return EXIT_SUCCESS;
        }
    } 
    else
    {
        printf("\nPress ENTER to exit...\n");
        getchar();
    }

    return EXIT_SUCCESS;
}
