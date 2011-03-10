/*!
	\file memoryBound.cu
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

extern "C" __global__ void kernel_MemoryBound(float *dest, float *source, int blockLines) {
	int tid = threadIdx.x;
	
	int blockLineSize = sizeof(float)*LINESIZE;
	int blockSize = blockLineSize * blockLines;
	int blockOffset = blockSize * blockIdx.x;
	
	float *destPtr = dest + tid + blockOffset;
	float *sourcePtr = source + tid + blockOffset;
	
	for (int i = 0; i < blockLines; i++) {
		*destPtr = *sourcePtr;
		destPtr += blockLineSize;
		sourcePtr += blockLineSize;
	}
}

void run(const int N) {
	int blockLines = BlockSize / LINESIZE;
	
	dim3 grid(N / BlockSize, 1);
	dim3 block(LINESIZE, 1);
	
	float *A_gpu_dest, *A_gpu_source;
	
	size_t bytes = sizeof(float)*N;
	cudaCheckCall(cudaMalloc((void **)&A_gpu_dest, bytes));
	cudaCheckCall(cudaMalloc((void **)&A_gpu_source, bytes));
	
	hydrazine::Timer timer;
	timer.start();
	
	kernel_MemoryBound<<< grid, block >>>(A_gpu_dest, A_gpu_source, blockLines);
	
	timer.stop();
	
	double transferSize = N * 2.0;
	double GBperSec = transferSize / timer.seconds() / 1.0e9;
	printf("Bandwidth: %f\n", GBperSec);
}

int main(int argc, char *arg[]) {

	run((10 << 20));
	
	return 0;
}

