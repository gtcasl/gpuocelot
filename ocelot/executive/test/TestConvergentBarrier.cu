/*!
	\file TestConvergentBarrier.cu
	\date 31 January 2012
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief Demonstrates convergent execution
*/

// Standard Library Includes
#include <stdio.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" __global__ void convergence(int *A) {
	int i = threadIdx.x;
	__shared__ float x[4];
	x[threadIdx.x] = A[i];
	__syncthreads();
	A[i] = x[3 - threadIdx.x] * 2;
}

static void testConvergence() {
	const int N = 4;
	int *A_host, *A_device;
	size_t bytes = N * sizeof(int);
	
	A_host = (int *)malloc(bytes);
	cudaMalloc((void **)&A_device, bytes);
	
	for (int i = 0; i < N; i++) {
		A_host[i] = (int)(i+1);
	}
	cudaMemcpy(A_device, A_host, bytes, cudaMemcpyHostToDevice);
	
	convergence<<< dim3(1,1), dim3(N, 1, 1) >>>(A_device);
	
	cudaMemcpy(A_host, A_device, bytes, cudaMemcpyDeviceToHost);
	
	int errors = 0;
	for (int i = 0; (errors < 5) && i < N; i++) {
		int expected = (4-(i)) * 2;
		int got = A_host[i];
		if (expected != got) {
			++errors;
			printf("error [%d] - expected: %d, got %d\n", i, expected, got);
		}
	}
	
	free(A_host);
	cudaFree(A_device);
	
	printf("Pass/Fail : %s\n", (errors ? "Fail":"Pass"));
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv )
{
	testConvergence();

	return 0;
}
