/*!
	\file simplerCUFFTdriver.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief implements the simplerCUFFT application using the CUDA driver API
*/

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include <cuda.h>

typedef struct {
	float x, y;
} cuComplex;


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
	
	// driver API business
	{
		CUcontext context;
		CUmodule module;
		CUfunction function;
		CUresult result = cuInit(0);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuInit() - failed\n");
			return false;
		}

		result = cuCtxCreate(&context, 0, 0);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuCtxCreate() - failed\n");
			return false;
		}

		result = cuModuleLoad(&module, "kernel.ptx");
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuModuleLoad() - failed\n");
			return false;
		}

		result = cuModuleGetFunction(&function, module, "_Z23SP_c2c_radix2_sp_kernelifiPvS_i11tfStride_st");
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuModuleGetFunction() - failed\n");
			return false;
		}

		result = cuFuncSetBlockShape(function, 16, 1, 1);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuFuncSetBlockShape() - failed\n");
			return false;
		}

		result = cuFuncSetSharedSize(function, 256);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuFuncSetSharedSize() - failed\n");
			return false;
		}
		CUdeviceptr Y_gpu, X_gpu;
		result = cuMemAlloc(&Y_gpu, bytes);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuMemAlloc(&Y_gpu) - failed\n");
			return false;
		}
		result = cuMemAlloc(&X_gpu, bytes);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuMemAlloc(&X_gpu) - failed\n");
			return false;
		}

		result = cuMemcpyHtoD(Y_gpu, Y, bytes);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuMemcpyHtoD(Y) - failed\n");
			return false;
		}
		result = cuMemcpyHtoD(X_gpu, X, bytes);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuMemcpyHtoD(X) - failed\n");
			return false;
		}
		
		// setup params
		result = cuParamSetSize(function, 48);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSetSize() - failed\n");
			return false;
		}

		result = cuParamSeti(function, 0, 0x20);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSeti(offset 0) - failed\n");
			return false;
		}
		result = cuParamSetf(function, 4, 0.19635f);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSetf(offset 4) - failed\n");
			return false;
		}
		result = cuParamSeti(function, 8, 0x4);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSeti(offset 8) - failed\n");
			return false;
		}
		result = cuParamSeti(function, 12, X_gpu);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSeti(offset 12) - failed\n");
			return false;
		}
		result = cuParamSeti(function, 20, Y_gpu);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSeti(offset 20) - failed\n");
			return false;
		}
		result = cuParamSeti(function, 28, -1);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSeti(offset 28) - failed\n");
			return false;
		}
		char structPtr[16] = {0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20 };
		result = cuParamSetv(function, 32, (void *)structPtr, 16);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuParamSetv(offset 32) - failed\n");
			return false;
		}

		// launch
		result = cuLaunchGrid(function, 1, 1);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuLaunchGrid() - failed\n");
			return false;
		}

		cuCtxSynchronize();
		
		result = cuMemcpyDtoH(Y, Y_gpu, bytes);
		if (result != CUDA_SUCCESS) {
			fprintf(stderr, "cuMemcpyDtoH(Y) - failed\n");
			return false;
		}
	
		cuMemFree(Y_gpu);
		cuMemFree(X_gpu);
	}

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


