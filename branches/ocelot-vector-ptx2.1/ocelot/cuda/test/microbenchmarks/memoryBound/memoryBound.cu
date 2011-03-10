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

#define min(a, b) ((a) > (b) ? (b) : (a))

/////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" __global__ void kernel_Touch(
	float *buffer,
	float val,
	size_t elements) {
	
	int id = threadIdx.x + blockDim.x * blockIdx.x;
	for (; id < elements; id += blockDim.x) {
		buffer[id] = val;
	}
}

extern "C" __global__ void kernel_GlobalTransfer(
	float *destPtr,
	float *srcPtr,
	size_t threadBaseStride,
	size_t threadStride,
	size_t elementsPerThread) {
	
	int id = threadIdx.x * threadBaseStride + blockDim.x * blockIdx.x * elementsPerThread;
	destPtr += id;
	srcPtr += id;

	for (size_t i = 0; i < elementsPerThread; i++) {
		*destPtr = *srcPtr;
		destPtr += threadStride;
		srcPtr += threadStride;
	}	
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void run(size_t elements, int ctaSize = 256) {
	float *A_dest, *A_src;
	size_t bytes = sizeof(float)*elements;
	int runs = 10;
	
	cudaCheckCall(cudaMalloc((void **)&A_dest, bytes));
	cudaCheckCall(cudaMalloc((void **)&A_src, bytes));
	
	//kernel_Touch<<< dim3(min(16, elements/64), 1), dim3(64, 1) >>>(A_src, 2.0f, elements);
	//kernel_Touch<<< dim3(min(16, elements/64), 1), dim3(64, 1) >>>(A_dest, 0.0f, elements);
	
	// dense copies (enables coalesced accesses)
	hydrazine::Timer timer;
	timer.start();
	for (int i = 0; i < runs; i++) {
		float *ptrs[2] = { A_dest, A_src };
		
		size_t baseStride = 1;
		size_t intrathreadStride = ctaSize;
		size_t elementsPerThread = 8*ctaSize;
		
		dim3 block(ctaSize, 1);
		dim3 grid(elements / (ctaSize) / elementsPerThread, 1);
		
		kernel_GlobalTransfer<<< grid, block >>>(ptrs[(i) % 2], ptrs[(i+1)%2], 
			baseStride, intrathreadStride, elementsPerThread);
	}
	cudaThreadSynchronize();
	timer.stop();
	double coalescedRuntime = timer.seconds();
	
	// dense copies (enables coalesced accesses)
	timer.start();
	for (int i = 0; i < runs; i++) {
		float *ptrs[2] = { A_dest, A_src };
		
		size_t elementsPerThread = 8*ctaSize;
		size_t baseStride = elementsPerThread;
		size_t intrathreadStride = 1;
		
		dim3 block(ctaSize, 1);
		dim3 grid(elements / (ctaSize) / elementsPerThread, 1);
		
		kernel_GlobalTransfer<<< grid, block >>>(ptrs[(i) % 2], ptrs[(i+1)%2], 
			baseStride, intrathreadStride, elementsPerThread);
	}
	cudaThreadSynchronize();
	timer.stop();
	double sequentialRuntime = timer.seconds();
	
	cudaFree(A_dest);
	cudaFree(A_src);
	
	double coalescedBandwidth = (double)(elements >> 18) * 2 * runs / (coalescedRuntime * 1000.0) ;
	double serialBandwidth = (double)(elements >> 18) * 2 * runs / (sequentialRuntime * 1000.0);
	
	printf("allocation size: %d MB. Coalesced bandwidth: %f GB/s. Sequential bandwidth: %f GB/s\n",
		(elements>>18), coalescedBandwidth, serialBandwidth);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *arg[]) {

	run((100 << 20));
	
	return 0;
}

