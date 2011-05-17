/*!
	\file TestConvergence.cu
	\date 17 February 2011
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief Demonstrates divergent execution
*/

// Standard Library Includes
#include <stdio.h>
#include <math.h>

#define INCLUDE_TRANSPOSE 1

/////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" __global__ void divergence(float *A) {
	int i = threadIdx.x;
	if (i & 0x01) {
		A[i] = i * 2.0f + 1.0f;
	}
	else {
		A[i] *= 1.25f;
	}
}

#if INCLUDE_TRANSPOSE
/*!
	\brief computes the out-of-place transpose of an M-by-N matrix where M and N are divible by 4
*/
extern "C" __global__ void transpose(float *A, const float *B, int M, int N) {
	__shared__ float block[4][5];
	
	//
	// copy the block B[ by:by+4, bx:bx+4 ] to A[ bx:bx+4, by:by+4 ]
	//
	
	int bi = blockIdx.x * 4 + threadIdx.x + blockIdx.y * 4 * N;
	
	for (int i = 0; i < 4; i++) {
		block[i][threadIdx.x] = B[bi + i * N];
	}
	__syncthreads();
	
	//
	// A is N-by-M
	//
	int ai = blockIdx.y * 4 + threadIdx.x + blockIdx.x * 4 * M;
	for (int i = 0; i < 4; i++) {		
		A[ai + i * M] = block[threadIdx.x][i];
	}
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////

static float expectedValue(int n) {
	if (n & 0x01) {
		return n * 2.0f + 1.0f;
	}
	else {
		return 1.25f * ((float)n + 1.0f);
	}
}

static int testDivergence() {
	const int N = 4;
	float *A_host, *A_device;
	size_t bytes = N * sizeof(float);
	
	A_host = (float *)malloc(bytes);
	cudaMalloc((void **)&A_device, bytes);
	
	for (int i = 0; i < N; i++) {
		A_host[i] = (float)(i+1);
	}
	cudaMemcpy(A_device, A_host, bytes, cudaMemcpyHostToDevice);
	
	divergence<<< dim3(1,1), dim3(N, 1, 1) >>>(A_device);
	
	cudaMemcpy(A_host, A_device, bytes, cudaMemcpyDeviceToHost);
	
	int errors = 0;
	for (int i = 0; (errors < 5) && i < N; i++) {
		float expected = expectedValue(i);
		float got = A_host[i];
		if (fabs(expected - got) > 0.001f) {
			++errors;
			printf("error [%d] - expected: %f, got %f\n", i, expected, got);
		}
	}
	
	cudaFree(A_device);
	free(A_host);
	
	return errors;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

#if INCLUDE_TRANSPOSE
static int testTranspose() {
	const int M = 4;
	const int N = 4;
	
	float *A_gpu, *A_gpu2, *A_host;
	size_t bytes = sizeof(float)*M*N;
	cudaMalloc((void **)&A_gpu, bytes);
	cudaMalloc((void **)&A_gpu2, bytes);
	A_host = (float *)malloc(bytes);
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			A_host[i * N + j] = (float)(i * N) + (float)j;
		}
	}
	cudaMemcpy(A_gpu, A_host, bytes, cudaMemcpyHostToDevice);
	
	dim3 grid(M / 4, N / 4);
	dim3 block(4, 1);
	transpose<<< grid, block >>>(A_gpu2, A_gpu, M, N);
	cudaMemcpy(A_host, A_gpu2, bytes, cudaMemcpyDeviceToHost);
	
	// A is N-by-M
	int errors = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			float expected = (float)(j * N) + (float)i;
			float got = A_host[i * M + j];
			if (fabs(expected - got) > 0.001f) {
				++errors;
				printf("error [%d, %d] - expected: %f, got: %f\n", i, j, expected, got);
			}
			if (errors >= 5) {
				goto testTranspose_exit;
			}
		}
	}
testTranspose_exit:
	cudaFree(A_gpu);
	cudaFree(A_gpu2);
	free(A_host);
	
	return errors;
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv )
{
	int errors = 0;
	if (!errors) {
		errors = testDivergence();
	}
#if INCLUDE_TRANSPOSE
	if (!errors) {
		errors = testTranspose();
	}
#endif

	printf("Test %s\n", (errors ? "FAILED": "Passed"));
	return 0;
}
