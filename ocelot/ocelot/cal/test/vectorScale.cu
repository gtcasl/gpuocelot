/*! \file vectorScale.cu
 *	\author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *	\date April 18, 2010
 *	\brief Checks basic functionality of the ATI GPU Device
 */

// Standard C Library includes
#include <stdio.h>
#include <stdlib.h>

__global__ void vectorScale(int *A, int *B)
{
	int i = threadIdx.x;
	B[i] = 2 * A[i];
}

int hA[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int hB[10];

int main()
{
	int *dA, *dB;
	cudaError err;

	cudaDeviceProp properties;
	cudaGetDeviceProperties(&properties, 0);
	if (strcmp(properties.name, "CAL Device")) {
		printf("No CAL devices found\n");
		exit(-1);
	}

	err = cudaMalloc((void**)&dA, 10 * sizeof(int));
	if (err != cudaSuccess) {
		printf("cudaMalloc() failed: %s\n", cudaGetErrorString(err));
		return -1;
	}

	err = cudaMalloc((void**)&dB, 10 * sizeof(int));
	if (err != cudaSuccess) {
		printf("cudaMalloc() failed: %s\n", cudaGetErrorString(err));
		return -1;
	}

	err = cudaMemcpy(dA, hA, 10 * sizeof(int), cudaMemcpyHostToDevice);
	if (err != cudaSuccess) {
		printf("cudaMemcpy() failed: %s\n", cudaGetErrorString(err));
		return -1;
	}

	vectorScale<<<1, 10>>>(dA, dB);

	err = cudaMemcpy(hB, dB, 10 * sizeof(int), cudaMemcpyDeviceToHost);
	if (err != cudaSuccess) {
		printf("cudaMemcpy() failed: %s\n", cudaGetErrorString(err));
		return -1;
	}

	err = cudaFree(dA);
	if (err != cudaSuccess) {
		printf("cudaFree() failed: %s\n", cudaGetErrorString(err));
		return -1;
	}

	err = cudaFree(dB);
	if (err != cudaSuccess) {
		printf("cudaFree() failed: %s\n", cudaGetErrorString(err));
		return -1;
	}

	int errors = 0;
	for (int i = 0 ; i < 10 ; i++) {
		int expected = 2 * hA[i];
		int got = hB[i];
		if (abs(expected - got) > 0.001) {
			printf("ERROR - [%d] - got: %d, expected: %d\n", i, got, expected);
			if (++errors > 5) { break; }
		}
	}

	printf("Pass/Fail : %s\n", (errors ? "Fail" : "Pass"));

	return 0;
}
