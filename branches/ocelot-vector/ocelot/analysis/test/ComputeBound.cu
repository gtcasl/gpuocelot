/*!
	\file ComputeBound.cu
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 3, 2010
*/

#include <sys/time.h>
#include <stdio.h>

#define Iterations 1024

#define BLOCK1 { p1 = p1 * a + b; p2 = p2 * b + c; p3 = p3 * c + d; p4 = p4 * d + e; }
#define BLOCK2 { p1 = p1 * a + b; q1 = q1 + a; p2 = p2 * b + c; q2 = q2 + b; \
	p3 = p3 * c + d; q3 = q3 + c; p4 = p4 * d + e; q4 = q4 + d; }
#define BLOCK3 { p1 = p1 * a; p2 = p2 * b; p3 = p3 * c; p4 = p4 * d; }
#define BLOCK4 { p1 = p1 * a + a; p2 = p2 * b + b; p3 = p3 * c + c; p4 = p4 * d + d; }

#define BLOCKN BLOCK1

#define GROUP1 BLOCKN BLOCKN BLOCKN BLOCKN
#define GROUP2 GROUP1 GROUP1 GROUP1 GROUP1
#define GROUP4 GROUP2 GROUP2 GROUP2 GROUP2
#define GROUP8 GROUP4 GROUP4 GROUP4 GROUP4

#define MADs 2048
#define ADDs 0
#define MULs 0
extern "C" __global__ void FloatComputeBound(
	float *A, 
	const float a, const float b, const float c, const float d, const float e, bool store) {
	
	int tid = threadIdx.x + blockDim.x * blockIdx.x;
	
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

void run(const int M) {
	
	float *A_gpu, *A_cpu;
	const int N = 576;
	
	const int K = M * N;
	size_t bytes = sizeof(float)*K;
	
	cudaMalloc((void **)&A_gpu, bytes);
	A_cpu = (float *)malloc(bytes);
	for (int i = 0; i < K; i++) {
		A_cpu[i] = (float)i / (float)(K - 1);
	}
	cudaMemcpy(A_gpu, A_cpu, bytes, cudaMemcpyHostToDevice);
	
	struct timeval startTime, endTime;
	
	cudaThreadSynchronize();
	gettimeofday(&startTime, 0);
	FloatComputeBound<<< dim3(M,1), dim3(N, 1) >>>(A_gpu, 1.125f, 0.125f, 0.5f, 1.25f, 1.25f, false);
	cudaThreadSynchronize();
	gettimeofday(&endTime, 0);
	
	double ms = (((double)endTime.tv_sec - (double)startTime.tv_sec) * 1000.0 + 
		((double)endTime.tv_usec - (double)startTime.tv_usec) / 1000.0);
	
	double s = ms / 1000.0;
	double GFLOPs = (2 * MADs + ADDs + MULs) / 1.0e6 * Iterations * K / 1.0e3;
	double GFLOPsPerSec = (GFLOPs / s);
	
	// CTAs, GFLOPs/second, GFLOPs, ms
	printf("%d, %f\n", M, GFLOPsPerSec );
	
	free(A_cpu);
	cudaFree(A_gpu);
}

int main() {
	for (int i = 1; i < 50; i++) {
		run(i);
	}
	return 0;
}

