/*!
	\file computebound.cu
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 5, 2010; March 8, 2011
*/

// C++ includes
#include <stdio.h>
#include <stdlib.h>

// Hydrazine includes
#include <hydrazine/implementation/Timer.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TOOLCHAIN
#define TOOLCHAIN 0
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

#define Iterations 1536

#define BLOCK1 { p1 = p1 * a + b; p2 = p2 * b + c; p3 = p3 * c + d; p4 = p4 * d + e; }

#define BLOCK2 { p1 = p1 * a + b; q1 = q1 + a; p2 = p2 * b + c; q2 = q2 + b; \
	p3 = p3 * c + d; q3 = q3 + c; p4 = p4 * d + e; q4 = q4 + d; }
	
#define BLOCK3 { p1 = p1 * a; p2 = p2 * b; p3 = p3 * c; p4 = p4 * d; }

#define BLOCK4 { p1 = p1 * a + a; p2 = p2 * b + b; p3 = p3 * c + c; p4 = p4 * d + d; }

#define BLOCK5 { p1 = p1 * a; q1 = q1 + a; p2 = p2 * b; q2 = q2 + b; \
	p3 = p3 * c; q3 = q3 + c; p4 = p4 * d; q4 = q4 + d; }

#define BLOCKN BLOCK4

#define GROUP1 BLOCKN BLOCKN BLOCKN BLOCKN
#define GROUP2 GROUP1 GROUP1 GROUP1 GROUP1
#define GROUP4 GROUP2 GROUP2 GROUP2 GROUP2
#define GROUP8 GROUP4 GROUP4 GROUP4 GROUP4
#define GROUP16 GROUP8 GROUP8 GROUP8 GROUP8

#define MADs 0
#define ADDs 2048
#define MULs 2048
__global__ void FloatComputeBound(
	float *A, const int N,
	const float a, const float b, const float c, const float d, const float e, int store) {
	int tid = threadIdx.x;
	
	float q1 = A[tid] - 1;
	float q2 = A[tid] * 0.75f;
	float q3 = A[tid] * 0.25f;
	float q4 = A[tid] * 0.5f;

	float p1 = A[tid] - 1;
	float p2 = A[tid] * 1.25f;
	float p3 = A[tid] * 0.75f;
	float p4 = A[tid] * 0.5f;

	for (int i = 0; i < Iterations; i++) {
		GROUP8
		GROUP8
	}	

	if (store) {
		A[tid] = p1 - q1 + p2 - q2 + p3 - q3 + p4 - q4;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void run(const int M) {
	
	float *A_cpu;
	float *A_gpu;
	
	const size_t N = 576;
	
	const size_t kernelLaunches = 8;
	const size_t K = M * N;
	size_t bytes = sizeof(float)*K;
	
	A_cpu = (float *)malloc(bytes);
	int i;
	for (i = 0; i < K; i++) {
		A_cpu[i] = (float)i / (float)(K - 1);
	}
	cudaMalloc((void **)&A_gpu, bytes);
	
	hydrazine::Timer timer;
	
	timer.start();
	
	for (size_t i = 0; i < kernelLaunches; i++) {
		dim3 grid(M,1);
		dim3 block(N, 1, 1);
		FloatComputeBound<<< grid, block >>>(A_gpu, 1, 1.125f, 0.125f, 0.5f, 1.25f, 1.25f, 0);
	}
	
	timer.stop();
	
	double s = timer.seconds();
	double GFLOPs = (MADs + ADDs + MULs) / 1.0e6 * Iterations * K / 1.0e3 * kernelLaunches;
	double GFLOPsPerSec = (GFLOPs / s);
	
	printf("%d\t\t%f\n", M, GFLOPsPerSec );
	
	cudaFree(A_gpu);
	free(A_cpu);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	int i;
	printf("\n%s\n# blocks\tGFLOPs/second\n", (TOOLCHAIN == 1 ? "gcc" : (TOOLCHAIN == 2 ? "llvm" : "")));
	run(8);
	for (i = 8; i <= 33; i+=8) {
		run(i);
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

