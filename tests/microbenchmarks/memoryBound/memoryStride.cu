/*!
	\file memoryStride.cu
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief test application measuring achieved device-to-device memory bandwidth 
*/

#define LINESIZE 64
#define BlockSize 4096

#include <hydrazine/implementation/Timer.h>
#include <stdio.h>
#include <assert.h>

#define cudaCheckCall(x) { cudaError_t result = x; if (result != cudaSuccess) \
	{ printf("Error: %s\n", cudaGetErrorString(result)); assert(0); } }

extern "C" __global__ void kernel_MemoryStride(int *dest, int threadCount, int threadStride) {
	int tid = threadIdx.x;
	
	dest += tid;
	for (int i = 0; i < threadCount; i++) {
		*dest = tid;
		dest += threadStride;
	}
}

double run(const int N, int threads, int stride) {
	int *A_gpu_dest;
	
	size_t bytes = sizeof(int) * N * threads;
	cudaCheckCall(cudaMalloc((void **)&A_gpu_dest, bytes));
	
	dim3 grid(1, 1);
	dim3 block(threads, 1, 1);
	
	hydrazine::Timer timer;
	timer.start();
	kernel_MemoryStride<<< grid, block >>>(A_gpu_dest, threads, stride);
	timer.stop();
	
	cudaFree(A_gpu_dest);
	
	double transferSize = (double)bytes;
	double GBperSec = transferSize / timer.seconds() / 1.0e9;
	
	return GBperSec;
}

int main(int argc, char *arg[]) {
	const int N = (1 << 14);
	for (int i = 1; i < 512; i++) {
		double bw_unit = run(N, i, 1);
		double bw_inter = run(N, i, i);
		printf("(%d, %f, %f),\n", i, bw_unit, bw_inter);
	}
	return 0;
}

