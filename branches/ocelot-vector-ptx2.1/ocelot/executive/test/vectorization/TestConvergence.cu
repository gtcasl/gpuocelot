/*!
	\file TestConvergence.cu
	\date 17 February 2011
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief Demonstrates convergent execution
*/

// Standard Library Includes
#include <stdio.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" __global__ void convergence(float *A) {
	int i = threadIdx.x;
	A[i] = i * 2.0f + 1.0f;;
}

static void testConvergence() {
	const int N = 4;
	float *A_host, *A_device;
	size_t bytes = N * sizeof(float);
	
	A_host = (float *)malloc(bytes);
	cudaMalloc((void **)&A_device, bytes);
	
	for (int i = 0; i < N; i++) {
		A_host[i] = (float)(i+1);
	}
	cudaMemcpy(A_device, A_host, bytes, cudaMemcpyHostToDevice);
	
	convergence<<< dim3(1,1), dim3(N, 1, 1) >>>(A_device);
	
	cudaMemcpy(A_host, A_device, bytes, cudaMemcpyDeviceToHost);
	
	int errors = 0;
	for (int i = 0; (errors < 5) && i < N; i++) {
		float expected = /* (float)(i+1) + */ 2.0f * i + 1.0f;
		float got = A_host[i];
		if (fabs(expected - got) > 0.001f) {
			++errors;
			printf("error [%d] - expected: %f, got %f\n", i, expected, got);
		}
	}
	
	printf("Test %s\n", (errors ? "FAILED": "Passed"));
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main( int argc, char** argv )
{
	testConvergence();

	return 0;
}
