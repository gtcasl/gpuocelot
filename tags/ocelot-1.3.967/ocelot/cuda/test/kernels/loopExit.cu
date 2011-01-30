/*!
	\brief loopExit.cu
	\author Andrew Kerr

	\brief simple test of control-flow behavior of kernels
*/

#include <stdio.h>

extern "C" __global__ void kernelLoopExit(int *A, int N) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	__shared__ int S[64];
	
	S[threadIdx.x] = 0;
	A[i] = 0;
	for (int j = i; j < N; j++) {
		S[threadIdx.x] += 1;
	}
	__syncthreads();
	A[i] = S[threadIdx.x];
}


int main(int argc, char *arg[]) {

	const int N = 32;
	int *A_host, *A_gpu =0;
	int errors = 0;

	size_t bytes = sizeof(int)*N;

	if (cudaMalloc((void **)&A_gpu, bytes) != cudaSuccess) {
		printf("cudaMalloc() - failed to allocate %d bytes on device\n", (int)bytes);
		return -1;
	}

	A_host = (int *)malloc(bytes);
	for (int i = 0; i < N; i++) {
		A_host[i] = -1;
	}
	
	cudaMemcpy(A_gpu, A_host, bytes, cudaMemcpyHostToDevice);

	dim3 grid((N+31)/32,1);
	dim3 block(32, 1);
	
	kernelLoopExit<<< grid, block >>>(A_gpu, N);
	cudaMemcpy(A_host, A_gpu, bytes, cudaMemcpyDeviceToHost);

	for (int i = 0; (errors < 5) && i < N; ++i) {
		int got = A_host[i];
		int expected = N - i;
		if (expected != got) {
			printf("ERROR 1 [%d] - expected: %d, got: %d\n", i, expected, got);
			++errors;
		}
	}

	cudaFree(A_gpu);
	free(A_host);

	if (errors) {
		printf("Pass/Fail : Fail\n");
	}
	else {
		printf("Pass/Fail : Pass\n");
	}

	return 0;
}

