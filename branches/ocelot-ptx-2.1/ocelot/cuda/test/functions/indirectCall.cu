/*!
	\file indirectCall.cu
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\brief demonstrates indirect function calling
*/

#include <iostream>

extern "C" __device__ __noinline__ int funcDouble(int a) {
	return a*2;
}

extern "C" __device__ __noinline__ int funcTriple(int a) {
	return a*3;
}

extern "C" __device__ __noinline__ int funcQuadruple(int a) {
	return a*4;
}

extern "C" __global__ void kernelEntry(int *A, const int N, int b) {

	int (*filter[])(int) = {
		&funcDouble,
		&funcTriple,
		&funcQuadruple
	};

	int i = threadIdx.x + blockDim.x * blockIdx.x;
	
	if (i < N) {
		int p = ((b + i) % 3);
		A[i] = filter[p](i);
	}
}

int main(int argc, char *arg[]) {

	const int P = 0;
	const int N = 32;
	int *A_gpu, *A_cpu;
	size_t bytes = sizeof(int) * N;
	
	cudaError_t result = cudaThreadSynchronize();
	if (result != cudaSuccess) {
		std::cout << "Initialization error: " << cudaGetErrorString(result) << std::endl;
		return 1;
	}
	
	result = cudaMalloc((void **)&A_gpu, bytes);
	if (result != cudaSuccess) {
		std::cout << "cudaMalloc() - failed to allocate " << bytes << " on the device" << std::endl;
		return 2;
	}
	
	A_cpu = (int *)malloc(bytes);
	for (int i = 0; i < N; i++) {
		A_cpu[i] = 0;
	}
	
	result = cudaMemcpy(A_gpu, A_cpu, bytes, cudaMemcpyHostToDevice);
	if (result != cudaSuccess) {
		std::cout << "cudaMemcpy() - failed to copy " << bytes << " bytes TO the device" << std::endl;
		return 2;
	}
	
	dim3 block(32, 1);
	dim3 grid((N + block.x - 1) / block.x, 1);
	
	kernelEntry<<< grid, block >>>(A_gpu, N, P);
	
	result = cudaThreadSynchronize();
	if (result != cudaSuccess) {
		std::cout << "Kernel launch error: " << cudaGetErrorString(result) << std::endl;
		return 3;
	}
	
	result = cudaMemcpy(A_cpu, A_gpu, bytes, cudaMemcpyDeviceToHost);
	if (result != cudaSuccess) {
		std::cout << "cudaMemcpy() - failed to copy " << bytes << " bytes FROM the device" << std::endl;
		return 2;
	}
	
	int errors = 0;
	for (int i = 0; i < N; i++) {
		int got = A_cpu[i];
		int dem = 0;
		
		int p = ((P + i) % 3);
		dem = ((p + 2) * i);
		
		if (got != dem) {
			std::cout << "Error[" << i << "] - expected: " << dem << ", got: " << got << std::endl;
			if (++errors > 5) {
				break;
			}
		}
	}
	
	cudaFree(A_gpu);
	free(A_cpu);
	
	if (errors) {
		std::cout << "FAILED" << std::endl;
		std::cout << " with " << errors << " errors" << std::endl;
	}
	else {
		std::cout << "Pass" << std::endl;
	}
	
	return 0;
}

