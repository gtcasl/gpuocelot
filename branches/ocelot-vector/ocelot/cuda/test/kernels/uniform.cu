/*!

*/

#include <stdio.h>

/*!
	\brief simple kernel with uniform control flow
*/
extern "C" __global__ void kernel_uniform(float *A, float a) {
	int tid = threadIdx.x + blockDim.x * blockIdx.x;
	A[tid] = a * tid;
}

/*!
	\brief simple kernel with uniform control flow and a loop
*/
extern "C" __global__ void kernel_uniform_loop(float *A, float a, float *B, int b) {
	int tid = threadIdx.x + blockDim.x * blockIdx.x;
	A[tid] = a * tid;
	for (int i = 0; i < b; i++) {
		A[tid] += B[i];
	}
}

/*!

*/
int main() {
	const int N = 64;
	dim3 blockSize(32, 1);
	dim3 gridSize(N / blockSize.x, 1);

	float *A_gpu, *A_cpu, *B_cpu, *B_gpu;
	const int B = 5;

	size_t A_bytes = sizeof(float) * N;
	size_t B_bytes = sizeof(float) * B;

	A_cpu = (float *)malloc(A_bytes);
	B_cpu = (float *)malloc(B_bytes);
	cudaMalloc((void **)&A_gpu, A_bytes);
	cudaMalloc((void **)&B_gpu, B_bytes);

	for (int i = 0; i < N; i++) {
		A_cpu[i] = 0;
		if (i < B) {
			B_cpu[i] = 3 * i;
		}
	}

	cudaMemcpy(A_gpu, A_cpu, A_bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(B_gpu, B_cpu, B_bytes, cudaMemcpyHostToDevice);

	int errors = 0;
	float A_k = 3;

	if (!errors) {
		kernel_uniform<<< gridSize, blockSize >>>(A_gpu, A_k);
		cudaMemcpy(A_cpu, A_gpu, A_bytes, cudaMemcpyDeviceToHost);

		for (int i = 0; i < N; i++) {
			float expected = A_k * i;
			float got = A_cpu[i];
			if (fabs(expected - got) > 0.00001f) {
				++errors;
				printf("ERROR in kernel_uniform() - [%d] - expected: %f, got: %f\n", i, expected, got);
				if (errors >= 5) goto cleanup;
			}
		}
	}

	if (!errors) {
		kernel_uniform_loop<<< gridSize, blockSize >>>(A_gpu, A_k, B_gpu, B);
		cudaMemcpy(A_cpu, A_gpu, A_bytes, cudaMemcpyDeviceToHost);

		for (int i = 0; i < N; i++) {
			int expected = A_k * i;
			for (int b = 0; b < B; b++) {
				expected += B_cpu[b];
			}
			int got = A_cpu[i];
			if (expected != got) {
				++errors;
				printf("ERROR in kernel_uniform_loop() - [%d] - expected: %d, got: %d\n", i, expected, got);
				if (errors >= 5) goto cleanup;
			}
		}
	}

cleanup:

	printf("%s\n", (errors ? "FAILED" : "Passed"));

	cudaFree(A_gpu);
	cudaFree(B_gpu);
	free(A_cpu);
	free(B_cpu);

	return 0;
}

