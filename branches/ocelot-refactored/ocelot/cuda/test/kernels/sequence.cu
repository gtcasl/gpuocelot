/*!
	\brief sequence.cu
	\author Andrew Kerr

	\brief simple test of a CUDA implementation's ability to allocate memory on the device, launch
		a kernel, and fetch its results
*/

#include <stdio.h>

extern "C" __global__ void sequence(int *A, int N) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	if (i < N) {
		A[i] = 2*i;
	}
}


int main(int argc, char *arg[]) {

	const int N = 1024;
	int *A_host, *A_gpu;
	int errors = 0;

	size_t bytes = sizeof(int)*N;

	if (cudaMalloc((void **)A_gpu, bytes) != cudaSuccess) {
		printf("cudaMalloc() - failed to allocate %d bytes on device\n", bytes);
		return -1;
	}

	A_host = (int *)malloc(bytes);
	for (int i = 0; i < N; i++) {
		A_host[i] = -1;
	}
	cudaMemcpy(A_gpu, A_host, bytes, cudaMemcpyHostToDevice);

	sequence<<< grid, block >>>(A_gpu, N);

	cudaMemcpy(A_host, A_gpu, bytes, cudaMemcpyDeviceToHost);

	for (int i = 0; i < N; i++) {
		if (A_host[i] != 2*i) {
			++errors;
		}
	}

	cudaFree(A_gpu);
	free(A_host);

	if (errors) {
		printf("FAILED\n");
	}
	else {
		printf("PASSED\n");
	}

	return 0;
}

