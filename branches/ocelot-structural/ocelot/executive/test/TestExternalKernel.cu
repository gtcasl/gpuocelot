/*!
	\file TestExternalKernel.cu
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements tests for external kernel launching
*/

#include <stdio.h>

extern "C" __global__ void testExternalKernel(int *A, int N) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < N) {
		A[i] = i * 3;		// this gets overridden
	}
}

int main(int argc, char *arg[]) {
	int N = 64;
	size_t bytes = sizeof(int)*N;

	int *A_host, *A_device;	

	A_host = (int *)malloc(bytes);
	cudaMalloc((void **)&A_device, bytes);

	testExternalKernel<<< dim3((N+31) / 32, 1), dim3(32, 1) >>>(A_device, N);
	cudaMemcpy(A_host, A_device, bytes, cudaMemcpyDeviceToHost);

	int errors = 0;

	for (int i = 0; !errors && i < N; i++) {
		if (A_host[i] != i * 4) {
			++errors;
		}
	}

	free(A_host);
	cudaFree(A_device);

	if (errors) {
		printf("Test FAILED\n");
	}
	else {
		printf("Test PASSED\n");
	}

	return 0;
}

