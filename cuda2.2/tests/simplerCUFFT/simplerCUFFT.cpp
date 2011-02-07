/*!
	\file simplerCUFFTdriver.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief implements the simplerCUFFT application using the CUDA driver API
*/

#include <stdio.h>
#include <stdlib.h>
#include <cufft.h>
#include <cuda_runtime.h>


/*!
	computes the N-point DFT of signal X and stores in Y
*/
bool host_dft(cuComplex *Y, cuComplex *X, float scale, int N) {
	const float Pi = 3.14159265358979f;
	for (int n = 0; n < N; n++) {
		cuComplex X_n = {0, 0};	
		for (int k = 0; k < N; k++) {
			float w = -2.0f * Pi / (float)N * (float)n * (float)k;
			cuComplex e = {(float)cos(w), (float)sin(w)};
			cuComplex x_k = X[k];
			X_n.x += e.x * x_k.x - e.y * x_k.y;
			X_n.y += e.y * x_k.x + e.x * x_k.y;
		}
		X_n.x *= scale;
		X_n.y *= scale;
		Y[n] = X_n;
	}
	return true;
}

/*!
	computes the N-point DFT of signal X and stores in Y using CUDA's FFT library
*/
bool cuda_dft(cuComplex *Y, cuComplex *X, float scale, int N) {
	size_t bytes = (size_t)N * sizeof(cuComplex);
	cuComplex *Y_gpu, *X_gpu;
	
	cudaMalloc((void **)&Y_gpu, bytes);
	cudaMalloc((void **)&X_gpu, bytes);

	cudaMemcpy(Y_gpu, Y, bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(X_gpu, X, bytes, cudaMemcpyHostToDevice);

	cufftHandle plan;
	cufftPlan1d(&plan, N, CUFFT_C2C, 1);

	cufftExecC2C(plan, X_gpu, Y_gpu, CUFFT_FORWARD);

	cufftDestroy(plan);

	cudaMemcpy(Y, Y_gpu, bytes, cudaMemcpyDeviceToHost);

	cudaFree(Y_gpu);
	cudaFree(X_gpu);

	for (int n = 0; n < N; n++) {
		Y[n].x *= scale;
		Y[n].y *= scale;
	}

	return true;
}

int main(int argc, char *arg[]) {

	int N = 32;
	size_t bytes = (size_t)N * sizeof(cuComplex);
	cuComplex *X, *Y_ref, *Y_exp;
	
	X = (cuComplex *)malloc(bytes);
	Y_ref = (cuComplex *)malloc(bytes);
	Y_exp = (cuComplex *)malloc(bytes);

	//
	// initialize data
	//
	srand(2009);
	for (int n = 0; n < N; n++) {
		X[n].x = (float)(rand() % 1000) / 500.0f - 1.0f;
		X[n].y = (float)((rand()+7) % 1000) / 500.0f - 1.0f;
		Y_ref[n].x = 0;
		Y_ref[n].y = 0;
		Y_exp[n].x = 0;
		Y_exp[n].y = 0;
	}

	//
	// perform DFTs
	//
	host_dft(Y_ref, X, 1.0f, N);
	cuda_dft(Y_exp, X, 1.0f, N);

	//
	// compare results
	//
	int errors = 0;
	for (int n = 0; (errors < 10) && n < N; n++) {
		cuComplex e = Y_ref[n], g = Y_exp[n];
		cuComplex error = {e.x - g.x, e.y - g.y};
		float mag_sq_error = error.x * error.x + error.y * error.y;
		if (mag_sq_error >= 0.000001f) {
			// error on element n
			++errors;
			printf("[n=%d]: expected (%f+%fi), got (%f+%fi)\n", n, e.x, e.y, g.x, g.y);
		}
	}
	printf("DFT %s\n", (errors ? "FAILED" : "passed"));

	//
	// cleanup
	//
	free(X);
	free(Y_ref);
	free(Y_exp);

	return 0;
}


