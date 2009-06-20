/*!
	\file TestMemoryTraceGenerator_kernel.cu
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\brief defines kernels used in the TestMemoryTraceGenerator application
	
	You may run this kernel in a standalone fashion as follows:
	
		nvcc --run TestMemoryTraceGenerator_kernel.cu -DSTANDALONE
*/

#include <stdio.h>

//#include <cuda_runtime.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#define k_mv_SIZE 64
__global__ void k_mv_product(int M, int N, const float *A_gpu, const float *V_gpu, float *R_gpu) {
	unsigned int row = blockIdx.x * blockDim.x + threadIdx.x;
	__shared__ float V_shared[k_mv_SIZE];
	float r_sum = 0;
	
	V_gpu += threadIdx.x;
	A_gpu += row;
	R_gpu += row;
	
	for (int j = 0; j < N; j += k_mv_SIZE) {
		V_shared[threadIdx.x] = *V_gpu;
		__syncthreads();
		#pragma unroll
		for (int k = 0; k < k_mv_SIZE; k++) {
			r_sum += *A_gpu * V_shared[k];
			A_gpu += M;
		}
		V_gpu += k_mv_SIZE;
		__syncthreads();
	}
	
	*R_gpu = r_sum;
}

void matrix_vector_product(int M, int N, const float *A_gpu, const float *V_gpu, float *R_gpu) {
	if (!(N % k_mv_SIZE) && !(M % k_mv_SIZE)) {
		dim3 grid(M / k_mv_SIZE, 1);
		dim3 block(k_mv_SIZE, 1);
		k_mv_product<<< grid, block >>>(M, N, A_gpu, V_gpu, R_gpu);
	}
	else {
		printf("matrix_vector_product(%d, %d, ..) - matrix dimensions must be multiples of %d\n", M, N, k_mv_SIZE);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

#define signum(x) ((x) < 0 ? -1 : 1)

extern "C" int test_entry() {
	const int M = 256, N = 128;
	
	int i, j;
	int result = 0;
	
	float *A_gpu, *A_cpu, *V_gpu, *V_cpu, *R_gpu, *R_cpu;
	float sq_error;
	
	size_t A_size = M * N * sizeof(float);
	size_t V_size = N * sizeof(float);
	size_t R_size = M * sizeof(float);
	
	// allocate memory
	if (cudaMalloc((void **)&A_gpu, A_size) != cudaSuccess) {
		printf("failed to allocate %u bytes for A_gpu\n", (unsigned int)A_size);
		return -1;
	}
	if (cudaMalloc((void **)&V_gpu, V_size) != cudaSuccess) {
		printf("failed to allocate %u bytes for V_gpu\n", (unsigned int)V_size);
		return -1;
	}
	if (cudaMalloc((void **)&R_gpu, R_size) != cudaSuccess) {
		printf("failed to allocate %u bytes for R_gpu\n", (unsigned int)R_size);
		return -1;
	}
	
	cudaMallocHost((void **)&A_cpu, A_size);
	cudaMallocHost((void **)&V_cpu, V_size);
	cudaMallocHost((void **)&R_cpu, R_size);
	
	// initialize data
	for (j = 0; j < N; j++) {
		for (i = 0; i < M; i++) {
			A_cpu[i + j * M] = 1.0f / (float)(1 + abs(i - j)) * (float)signum(i - j);
			R_cpu[i] = -1;
		}
		V_cpu[j] = 1.0f + (float)(j % 4);
	}
	cudaMemcpy(A_gpu, A_cpu, A_size, cudaMemcpyHostToDevice);
	cudaMemcpy(V_gpu, V_cpu, V_size, cudaMemcpyHostToDevice);
	cudaMemcpy(R_gpu, R_cpu, R_size, cudaMemcpyHostToDevice);
	
	// invoke kernel
	matrix_vector_product(M, N, A_gpu, V_gpu, R_gpu);
	
	// validate result
	cudaMemcpy(R_cpu, R_gpu, R_size, cudaMemcpyDeviceToHost);
	
	sq_error = 0;
	for (i = 0; i < M; i++) {
		float sum = 0;
		for (j = 0; j < N; j++) {
			sum += A_cpu[i + j * M] * V_cpu[j];
		}
		sum = R_cpu[i] - sum;
		sq_error += sum * sum;
	}
	if (sq_error > 0.01) {
		result = -1;
	}
	
	// cleanup
	cudaFreeHost(A_cpu);
	cudaFreeHost(V_cpu);
	cudaFreeHost(R_cpu);
	
	cudaFree(A_gpu);
	cudaFree(V_gpu);
	cudaFree(R_gpu);
	
	return result;
}

#ifdef STANDALONE
int main() {
	int result = test_entry();
	if (result == 0) {
		printf("test succeeded\n");
	}
	else {
		printf("TEST FAILED\n");
	}
	return 0;
}
#endif

