/*!

*/

#include <sys/time.h>
#include <stdio.h>

#define Iterations 1024

// #define EMITCPUKERNEL

#ifdef EMITCPUKERNEL
#define MADs 256
#define ADDs 132
#define MULs 0
extern "C" __global__ void FloatComputeBound(
	float *A, 
	const float a, const float b, const float c, const float d, const float e, bool store) {
	
	int tid = threadIdx.x + blockDim.x * blockIdx.x;	
	const float f = (float)tid;
	
	float t = A[tid] - 9;
	float u = A[tid] * 0.25f;
	float v = A[tid] - 1.25f;
	float w = A[tid];
	
	float q = A[tid] * 0.75f;
	float x = A[tid] * 1.25f;
	float y = A[tid] * 0.5f;
	float z = A[tid];
	
	for (int i = 0; i < Iterations; i++) {
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	x = x * b + c; u = u + d;
	y = y * c + d; 
	x = x * c + d; u = u + e;
	y = y * d + e; 
	
	}
	
	if (store) {
	// out
	A[tid] = q - t + x - u + y - v + w - z;
	}
}

#else	

// ifndef EMITCPUKERNEL
#define MADs 320
#define ADDs 328
#define MULs 0
extern "C" __global__ void FloatComputeBound(
	float *A, 
	const float a, const float b, const float c, const float d, const float e, bool store) {
	
	int tid = threadIdx.x + blockDim.x * blockIdx.x;	
	const float f = (float)tid;
	
	float t = A[tid] - 9;
	float u = A[tid] * 0.25f;
	float v = A[tid] - 1.25f;
	float w = A[tid];
	
	float q = A[tid] * 0.75f;
	float x = A[tid] * 1.25f;
	float y = A[tid] * 0.5f;
	float z = A[tid];
	
	for (int i = 0; i < Iterations; i++) {


	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;

	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;

	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;

	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	
	q = q * a + b; t = t + c;
	x = x * b + c; u = u + d;
	y = y * c + d; v = v + e;
	z = z * d + e; w = w + a;	
	q = q * b + c; t = t + d;
	x = x * c + d; u = u + e;
	y = y * d + e; v = v + f;
	z = z * e + f; w = w + a;
	}
	
	if (store) {
		// out
		A[tid] = q - t + x - u + y - v + w - z;
	}
}
#endif

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
	
	// const float d, const float c, const float f, const float g, const float h
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
	
	/*
	printf("M = %d\n", M);
	printf("Runtime: %f ms\n", ms);
	printf("GFLOPs: %f GFLOP/s per CTA\n\n", GFLOPs);
	*/
	printf("%d, %f, %f, %f\n", M, GFLOPsPerSec, GFLOPs, ms );
	
	free(A_cpu);
	cudaFree(A_gpu);
}

int main() {
	for (int i = 1; i < 50; i++) {
		run(i);
	}
	return 0;
}

