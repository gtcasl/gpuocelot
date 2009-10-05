/*!
	\file mult.c

	\author Andrew Kerr
	\brief implements matrix multiplication test
*/


#include <stdio.h>
#include <math.h>

#include "matmult.h"
#include "vsipl-timer.h"

#define ELEMENTS 64
#define ITERATIONS 1

///////////////////////////////////////////////////////////////////////////////////////////////////

void init_matrix_lower(float *cpu, int M, int N) {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			cpu[i * N + j] = (i >= j ? 1 : 0);
		}
	}
}

void init_matrix_upper(float *cpu, int M, int N ) {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			cpu[i * N + j] = (i <= j ? 1 : 0);
		}
	}
}

void matrix_multiply(float *A_cpu, float *B_cpu, float *C_cpu, int A_rows, int A_cols, int B_cols) {
	int i, j, k;
	for (i = 0; i < A_rows; i++) {
		for (j = 0; j < B_cols; j++) {
			float c = 0;

			for (k = 0; k < A_cols; k++) {
				c += A_cpu[i * A_cols + k] * B_cpu[k * B_cols + j];
			}
			
			C_cpu[i * B_cols + j] = c;
		}
	}
}

void transpose(float *A_ptr, int M, int N) {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = i+1; j < N; j++) {
			float t = A_ptr[i * N + j];
			A_ptr[i * N + j] = A_ptr[j * N + i];
			A_ptr[j * N + i] = t;
		}
	}
}

// returns nonzero if A and R differ
int is_matrix_incorrect(float *A, float *R, int M, int N) {
	int i, j;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (fabs(A[i * N + j] - R[i * N + j]) > 0.1f) {
				return 1;
			}
		}
	}
	return 0;
}

void print_matrix(FILE *file, float *A, int M, int N) {
	int i, j;
	fprintf(file, "[ ");

	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			fprintf(file, "%0.2f ", A[i * N + j]);
		}
		fprintf(file, ";\n");
	}

	fprintf(file, "];\n");
}

#define cudaMemcpyHostToDevice 1
#define cudaMemcpyDeviceToHost 2

int main() {
	float *A_gpu, *B_gpu, *C_gpu;
	float *A_cpu, *B_cpu, *C_cpu, *C_ref;

	int AM = ELEMENTS;
	int AN = ELEMENTS;
	int BN = ELEMENTS;

	int error = 0;	
	printf("Matrix multiplication example\n");

	cudaMalloc((void **)&A_gpu, sizeof(float)*AN*AM);
	cudaMalloc((void **)&B_gpu, sizeof(float)*AN*BN);
	cudaMalloc((void **)&C_gpu, sizeof(float)*AM*BN);

	cudaMallocHost((void **)&A_cpu, sizeof(float)*AM*AN);
	cudaMallocHost((void **)&B_cpu, sizeof(float)*AN*BN);
	cudaMallocHost((void **)&C_cpu, sizeof(float)*AM*BN);
	cudaMallocHost((void **)&C_ref, sizeof(float)*AM*BN);

	/* initialize matrices */
	init_matrix_upper(A_cpu, AM, AN);
	init_matrix_lower(B_cpu, AN, BN);

#if MATRIX_COL_MAJOR
	transpose(A_cpu, AM, AN);
	transpose(B_cpu, AN, BN);
#endif
	cudaMemcpy(A_gpu, A_cpu, sizeof(float)*AM*AN, cudaMemcpyHostToDevice);
	cudaMemcpy(B_gpu, B_cpu, sizeof(float)*AN*BN, cudaMemcpyHostToDevice);

	gpuvsip_timer timer;

	printf("fill_matrix called ..\n"); fflush(stdout);
	printf("  C_gpu = 0x%p\n", C_gpu);
	fill_matrix(C_gpu, AM, BN, -1);
	printf("fill_matrix returned\n"); fflush(stdout);

	matrix_multiply_GPU(A_gpu, B_gpu, C_gpu, AM, AN, BN);
	printf("matrix_multiply returned\n"); fflush(stdout);
	cudaThreadSynchronize();
	
	cudaMemcpy(C_cpu, C_gpu, sizeof(float)*AM*BN, cudaMemcpyDeviceToHost);
#if MATRIX_COL_MAJOR
	transpose(C_cpu, AM, BN);
	transpose(A_cpu, AM, AN);
	transpose(B_cpu, AN, BN);
#endif
	matrix_multiply(A_cpu, B_cpu, C_ref, AM, AN, BN);
	
	if (is_matrix_incorrect(C_cpu, C_ref, AM, BN)) {
		FILE *out = fopen("output.m", "w");
		fprintf(out, "A = ");
		print_matrix(out, A_cpu, AM, AN);
		fprintf(out, "\nB = ");
		print_matrix(out, B_cpu, AN, BN);
		fprintf(out, "\nC = ");
		print_matrix(out, C_cpu, AM, BN);
		fprintf(out, "\nref = ");
		print_matrix(out, C_ref, AM, BN);
		fclose(out);
		printf("Pass/Fail : Fail\n");
		printf("FAIL - matrix product incorrect\n");
		error ++;
	}
	else {
		printf("Pass/Fail : Pass\n");
		printf("PASS - matrix product correct\n"); 
	}

	cudaThreadSynchronize();
	
	if (!error) {
		gpuvsip_start_timer(&timer);
		int i;

		const int C = ITERATIONS;
		for (i = 0; i < C; i++) {
			matrix_multiply_GPU(A_gpu, B_gpu, C_gpu, AM, AN, BN);
			matrix_multiply_GPU(A_gpu, B_gpu, C_gpu, AM, AN, BN);
			matrix_multiply_GPU(A_gpu, B_gpu, C_gpu, AM, AN, BN);
			matrix_multiply_GPU(A_gpu, B_gpu, C_gpu, AM, AN, BN);
			matrix_multiply_GPU(A_gpu, B_gpu, C_gpu, AM, AN, BN);
		}

		cudaThreadSynchronize();
		gpuvsip_stop_timer(&timer);

		double GFLOPs = ((double)AM / 1000.0 * (double)BN / 1000.0) * (AN * 2.0) / 1000.0;

		double duration = gpuvsip_timer_duration(&timer) / (double)(C * 5);
		printf("(%dx%d) * (%dx%d) in %f ms - %f GFLOP/s\n", 
			AM, AN, AN, BN, duration*1000.0, GFLOPs / duration);
	}

	cudaFree(A_gpu);
	cudaFree(B_gpu);
	cudaFree(C_gpu);
	cudaFreeHost(A_cpu);
	cudaFreeHost(B_cpu);
	cudaFreeHost(C_cpu);
	cudaFreeHost(C_ref);
	
	return error;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

