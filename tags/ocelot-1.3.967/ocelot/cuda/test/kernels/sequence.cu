/*!
	\brief sequence.cu
	\author Andrew Kerr

	\brief simple test of a CUDA implementation's ability to allocate memory on the device, launch
		a kernel, and fetch its results. One kernel requires no syncthreads, another kernel requires
		one synchronization
*/

#include <stdio.h>

extern "C" __global__ void sequence(int *A, int N) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	if (i < N) {
		A[i] = 2*i;
	}
}

extern "C" __global__ void testShr(int *A, const int *B) {
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	int b;
	__shared__ int storage[256];
	
	storage[threadIdx.x] = B[i];
	__syncthreads();
	if (i & 1) {
		b = storage[threadIdx.x ^ 1] * 2;
	}
	else {
		b = storage[threadIdx.x ^ 1] * 3;
	}
	A[i] = b;
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
	sequence<<< grid, block >>>(A_gpu, N);
	cudaMemcpy(A_host, A_gpu, bytes, cudaMemcpyDeviceToHost);
	for (int i = 0; i < N; i++) {
		if (A_host[i] != 2*i) {
			++errors;
		}
	}

	int *B_gpu = 0;
	if (cudaMalloc((void **)&B_gpu, bytes) != cudaSuccess) {
		printf("cudaMalloc() - failed to allocate %d bytes on device\n", (int)bytes);
		cudaFree(A_gpu);
		free(A_host);
		return -1;
	}
	
	sequence<<< grid, block >>>(A_gpu, N);
	testShr<<< grid, block >>>(B_gpu, A_gpu);
	
	if (cudaMemcpy(A_host, B_gpu, bytes, cudaMemcpyDeviceToHost) != cudaSuccess) {
		printf("cudaMemcpy(A, B) - failed to copy %d bytes from device to host\n", (int)bytes);
		cudaFree(A_gpu);
		cudaFree(B_gpu);
		free(A_host);
	}
	
	for (int i = 0; (errors < 5) && i < N; ++i) {
		int b;
		if (i & 1) {
			b = (i ^ 1) * 2 * 2;
		}
		else {
			b = (i ^ 1) * 2 * 3;
		}
		int got = A_host[i];
		if (b != got) {
			printf("ERROR 1 [%d] - expected: %d, got: %d\n", i, b, got);
			++errors;
		}
	}

	cudaFree(B_gpu);
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

