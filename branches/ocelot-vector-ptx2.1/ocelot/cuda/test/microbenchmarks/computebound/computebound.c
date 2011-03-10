/*!
	\file computebound.cu
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 5, 2010; March 8, 2011
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TOOLCHAIN
#define TOOLCHAIN 0
#endif

#define Iterations 1024

#define BLOCK1 { p1 = p1 * a + b; p2 = p2 * b + c; p3 = p3 * c + d; p4 = p4 * d + e; }

#define BLOCK2 { p1 = p1 * a + b; q1 = q1 + a; p2 = p2 * b + c; q2 = q2 + b; \
	p3 = p3 * c + d; q3 = q3 + c; p4 = p4 * d + e; q4 = q4 + d; }
	
#define BLOCK3 { p1 = p1 * a; p2 = p2 * b; p3 = p3 * c; p4 = p4 * d; }

#define BLOCK4 { p1 = p1 * a + a; p2 = p2 * b + b; p3 = p3 * c + c; p4 = p4 * d + d; }

#define BLOCK5 { p1 = p1 * a; q1 = q1 + a; p2 = p2 * b; q2 = q2 + b; \
	p3 = p3 * c; q3 = q3 + c; p4 = p4 * d; q4 = q4 + d; }

#define BLOCKN BLOCK5

#define GROUP1 BLOCKN BLOCKN BLOCKN BLOCKN
#define GROUP2 GROUP1 GROUP1 GROUP1 GROUP1
#define GROUP4 GROUP2 GROUP2 GROUP2 GROUP2
#define GROUP8 GROUP4 GROUP4 GROUP4 GROUP4

#define MADs 0
#define ADDs 2048
#define MULs 2048
void FloatComputeBound(
	float *A, const int N,
	const float a, const float b, const float c, const float d, const float e, int store) {
	int tid;
	for (tid = 0; tid < N; tid++) {
	
		float q1 = A[tid] - 1;
		float q2 = A[tid] * 0.75f;
		float q3 = A[tid] * 0.25f;
		float q4 = A[tid] * 0.5f;
	
		float p1 = A[tid] - 1;
		float p2 = A[tid] * 1.25f;
		float p3 = A[tid] * 0.75f;
		float p4 = A[tid] * 0.5f;
	
		int i;
		for (i = 0; i < Iterations; i++) {
			GROUP8
			GROUP8
		}
	
		if (store) {
			A[tid] = p1 - q1 + p2 - q2 + p3 - q3 + p4 - q4;
		}
	}
}

void run(const int M) {
	
	float *A_cpu;
	const int N = 576;
	
	const int K = M * N;
	size_t bytes = sizeof(float)*K;
	
	A_cpu = (float *)malloc(bytes);
	int i;
	for (i = 0; i < K; i++) {
		A_cpu[i] = (float)i / (float)(K - 1);
	}
	
	struct timeval startTime, endTime;
	
	gettimeofday(&startTime, 0);
	
	FloatComputeBound(A_cpu, M*N, 1.125f, 0.125f, 0.5f, 1.25f, 1.25f, 0);
	
	gettimeofday(&endTime, 0);
	
	double ms = (((double)endTime.tv_sec - (double)startTime.tv_sec) * 1000.0 + 
		((double)endTime.tv_usec - (double)startTime.tv_usec) / 1000.0);
	
	double s = ms / 1000.0;
	double GFLOPs = (2 * MADs + ADDs + MULs) / 1.0e6 * Iterations * K / 1.0e3;
	double GFLOPsPerSec = (GFLOPs / s);
	
	printf("%d\t\t%f\n", M, GFLOPsPerSec );
	
	free(A_cpu);
}

int main() {
	int i;
	printf("\n%s\n# blocks\tGFLOPs/second\n", (TOOLCHAIN == 1 ? "gcc" : (TOOLCHAIN == 2 ? "llvm" : "")));
	for (i = 1; i <= 4; i++) {
		run(i);
	}
	return 0;
}

