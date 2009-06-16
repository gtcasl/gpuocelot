/*!
	\file simplerFFT.cu

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief implements a testbed for CUFFT
*/

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include <cufft.h>
#include <cutil_inline.h>

typedef float2 Complex; 

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Computes the discrete Fourier transform of a vector out of place
*/
void forward_DFT(Complex *input, Complex *output, int N) {
	double Pi = 3.1415926535898;
	double inv_N = 1.0 / (double)N;

	for (int k = 0; k < N; k++) {
		Complex sum = {0, 0};
		for (int n = 0; n < N; n++) {
			float w = (float)(-2.0 * Pi * inv_N * (double)k * (double)n);
			Complex x_n = input[n];
			Complex e = { cos(w), sin(w) };

			sum.x += x_n.x * e.x - x_n.y * e.y;
			sum.y += x_n.x * e.y + x_n.y * e.x;
		}
		output[k] = sum;
	}
}

/*!
	Computes the inverse discrete Fourier transform of a vector out of place
*/
void inverse_DFT(Complex *input, Complex *output, int N) {
	double Pi = 3.1415926535898;
	double inv_N = 1.0 / (double)N;

	for (int k = 0; k < N; k++) {
		Complex sum = {0, 0};
		for (int n = 0; n < N; n++) {
			float w = (float)(2.0 * Pi * inv_N * (double)k * (double)n);
			Complex x_n = input[n];
			Complex e = { cos(w), sin(w) };

			sum.x += x_n.x * e.x - x_n.y * e.y;
			sum.y += x_n.x * e.y + x_n.y * e.x;
		}
		output[k] = sum;
	}
}

/*!
	Computes the norm of two vectors. If the vector B does not exist, the norm of A is returned.
*/
double norm_difference(Complex *A, Complex *B, int N) {
	double norm_squared = 0;

	for (int n = 0; n < N; n++) {
		Complex a = A[n], b = {0, 0};
		if (B) {
			b = B[n];
		}
		a.x -= b.x;
		a.y -= b.y;
		norm_squared += a.x * a.x + a.y * a.y;
	}

	return sqrt(norm_squared);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Writes a complex vector to file data/simplefft/%s.m where %s is the vector's
	name. Defines two variables within the file, %s_len and %s. %s_len is the number
	of elements in the vector. %s is the vector itself.

	Padding with zeros is easily done without resizing the vector in memory.

	\param name name of vector and file
	\param data input data
	\param N number of elements in data
	\param padded_length length of vector as written

	\return 0 on success, -1 on I/O failure
*/
int write_vector(const char *name, Complex *data, int N, int padded_length) {
	char fname[256] = {0};
	FILE *file = 0;
	int n;

	sprintf(fname, "data/simplefft/%s.m", name);
	if (!(file = fopen(fname, "w"))) {
		fprintf(stderr, "failed to open file %s for writing\n", fname);
		return -1;
	}

	fprintf(file, "%s_len = %d;\n", name, padded_length);
	fprintf(file, "%s = [\n", name);

	for (n = 0; n < padded_length; n++) {
		if (n < N) {
			float r = data[n].x, i = data[n].y;
			fprintf(file, " %f %s %fi ;\n", r, (i >= 0 ? "+" : "-"), (float)fabs(i));
		}
		else {
			fprintf(file, " 0 ;\n");
		}
	}
	
	fprintf(file, "];\n");

	fclose(file);
	return 0;
}

/*!
	Returns a power of two not less than n.
*/
int ceiling_power_of_two(int n) {

	n |= (n >> (1<<0));
	n |= (n >> (1<<1));
	n |= (n >> (1<<2));
	n |= (n >> (1<<3));
	n |= (n >> (1<<4));

	return n + 1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
//////////////////////////////////////////////////////////////////////////////////////////////////
bool runTest(const int SIGNAL_LENGTH) 
{
	bool result = false;
	const size_t dataSize = sizeof(Complex ) * SIGNAL_LENGTH;

	Complex *DFT_signal_host = (Complex *)malloc(dataSize);
	Complex *T_signal_host = (Complex *)malloc(dataSize);
	Complex *T_signal_gpu = 0;
	Complex *F_signal_host = (Complex *)malloc(dataSize);
	Complex *F_signal_gpu = 0;

	cudaSetDevice( cutGetMaxGflopsDeviceId() );

	cudaMalloc((void **)&T_signal_gpu, dataSize);
	cudaMalloc((void **)&F_signal_gpu, dataSize);

	for (int n = 0; n < SIGNAL_LENGTH; n++) {
		T_signal_host[n].x = (float)((n % 16) - 8) / (float)(SIGNAL_LENGTH - 1);
		T_signal_host[n].y = 0;
		F_signal_host[n].x = 0;
		F_signal_host[n].y = 0;
	}

	cudaMemcpy(T_signal_gpu, T_signal_host, dataSize, cudaMemcpyHostToDevice);
	cudaMemcpy(F_signal_gpu, F_signal_host, dataSize, cudaMemcpyHostToDevice);

	// compute the DFT
	forward_DFT(T_signal_host, DFT_signal_host, SIGNAL_LENGTH);

	// CUFFT plan
	cufftHandle plan;
	cufftSafeCall(cufftPlan1d(&plan, SIGNAL_LENGTH, CUFFT_C2C, 1));

	// Transform signal and kernel
	cufftSafeCall(cufftExecC2C(plan, (cufftComplex *)T_signal_gpu, 
		(cufftComplex *)F_signal_gpu, CUFFT_FORWARD));

	cudaMemcpy(F_signal_host, F_signal_gpu, dataSize, cudaMemcpyDeviceToHost);

	double L2_error = norm_difference(DFT_signal_host, F_signal_host, SIGNAL_LENGTH);

	if (L2_error > 0.01) {
		printf("\nFFT FAILED with error %f\n", L2_error);

		write_vector("correct_F_signal", DFT_signal_host, SIGNAL_LENGTH, SIGNAL_LENGTH);
		write_vector("simple_T_signal", T_signal_host, SIGNAL_LENGTH, SIGNAL_LENGTH);
		write_vector("simple_F_signal", F_signal_host, SIGNAL_LENGTH, SIGNAL_LENGTH);
	}
	else {
		result = true;
	}

	cudaFree(F_signal_gpu);
	cudaFree(T_signal_gpu);

	free(T_signal_host);
	free(F_signal_host);
	free(DFT_signal_host);

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// Program main
//////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) {
	bool result = true;

	int size = 0;

	if (argc > 1) {
		size = atoi(argv[1]);
	}

	if (size) {
		result = runTest(size);
		if (result) {
			printf("TEST PASSED\nFFT size %d passed\n", size);
		}
		else {
			printf("TEST FAILED on FFT size %d\n", size);
		}
	}
	else {
		result = runTest(1024);

		if (result) {
			printf("TEST PASSED\n2^10 FFT size passed\n");
		}
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

