/*!
	\file textureFilters.cu

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief tests various filter modes for 2D textures

	\date 27 Oct 2009
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

// declare texture reference for 2D float texture
texture<float, 2, cudaReadModeElementType> surface;

/*!
	kernel in which each thread samples the texture and writes it to out, a row-major dense 
	block of samples
*/
extern "C" __global__ void kernelNormCoords(float *out, int width, int height) {
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;

	float sample = tex2D(surface, (float)x / (float)width, (float)y / (float)height);

	out[x + y * width] = sample;
}

static int testNormalizedCoordinates() {
	int width = 64, height = 64;

	float *in_data_host, *out_data_host;
	float *in_data_gpu, *out_data_gpu;

	size_t bytes = width * height * sizeof(float);
	in_data_host = (float *)malloc(bytes);
	out_data_host = (float *)malloc(bytes);

	// procedural texture generation
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			in_data_host[i * width + j] = (float)((122 + i*3 + j*2) % 128) / 128.0f;
			out_data_host[i*width+j] = 0;
		}
	}

	cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32, 0, 0, 0, cudaChannelFormatKindFloat);
	cudaMalloc((void **)&in_data_gpu, bytes);
	cudaMemcpy(in_data_gpu, in_data_host, bytes, cudaMemcpyHostToDevice);

	surface.addressMode[0] = cudaAddressModeWrap;
	surface.addressMode[1] = cudaAddressModeWrap;
	surface.filterMode = cudaFilterModePoint;
	surface.normalized = true;

	if (cudaBindTexture2D(0, &surface, in_data_gpu, &channelDesc, width, height, 
		width*sizeof(float)) != cudaSuccess) {
		printf("failed to bind texture: %s\n", cudaGetErrorString(cudaGetLastError()));
		free(in_data_host);
		free(out_data_host);
		cudaFree(in_data_gpu);
		return -2;
	}

	cudaMalloc((void **)&out_data_gpu, bytes);

	dim3 grid(width / 16, height / 16), block(16, 16);
	
	kernelNormCoords<<< grid, block >>>(out_data_gpu, width, height);

	cudaThreadSynchronize();

	cudaMemcpy(out_data_host, out_data_gpu, bytes, cudaMemcpyDeviceToHost);
	cudaFree(in_data_gpu);
	cudaFree(out_data_gpu);

	int errors = 0;
	for (int i = 0; i < height && errors < 5; i++) {
		for (int j = 0; j < width && errors < 5; j++) {
			float in = in_data_host[i * width + j];
			float out = out_data_host[i * width + j];
			if (fabs(in - out) > 0.001f) {
				++errors;
				printf("(%d, %d) - in = %f, out = %f %s\n", i, j, in, out, (errors ? "***":""));
			}
		}
	}

	printf("Pass/Fail : %s\n", (errors ? "Fail" : "Pass"));

	free(in_data_host);
	free(out_data_host);
	return errors;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

texture<ushort, 2, cudaReadModeNormalizedFloat> surfaceNormUshort;


/*!
	kernel in which each thread samples the texture and writes it to out, a row-major dense 
	block of samples
*/
extern "C" __global__ void kernelNormUshort(float *out, int width, int height) {
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;

	float sample = tex2D(surfaceNormUshort, x, y);

	out[x + y * width] = sample;
}

/*!
	\brief constructs a texture and samples
*/
static int testNormalizedUshort() {
	int width = 64, height = 64;

	ushort *in_data_host, *in_data_gpu;
	float *out_data_host, *out_data_gpu;

	size_t bytesIn = width * height * sizeof(ushort);
	size_t bytesOut = width * height * sizeof(float);
	in_data_host = (ushort *)malloc(bytesIn);
	out_data_host = (float *)malloc(bytesOut);

	// procedural texture generation
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			in_data_host[i * width + j] = ((10000 + i*3 + j*2) % (1 << 15));
			out_data_host[i*width+j] = 0;
		}
	}

	cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(16, 0, 0, 0, cudaChannelFormatKindUnsigned);
	cudaMalloc((void **)&in_data_gpu, bytesIn);
	cudaMemcpy(in_data_gpu, in_data_host, bytesIn, cudaMemcpyHostToDevice);

	surfaceNormUshort.addressMode[0] = cudaAddressModeWrap;
	surfaceNormUshort.addressMode[1] = cudaAddressModeWrap;
	surfaceNormUshort.filterMode = cudaFilterModePoint;
	surfaceNormUshort.normalized = false;

	if (cudaBindTexture2D(0, &surfaceNormUshort, in_data_gpu, &channelDesc, width, height, 
		width*sizeof(float)) != cudaSuccess) {
		printf("failed to bind texture: %s\n", cudaGetErrorString(cudaGetLastError()));
		free(in_data_host);
		free(out_data_host);
		cudaFree(in_data_gpu);
		return -2;
	}

	cudaMalloc((void **)&out_data_gpu, bytesOut);

	dim3 grid(width / 16, height / 16), block(16, 16);
	
	kernelNormUshort<<< grid, block >>>(out_data_gpu, width, height);

	cudaThreadSynchronize();

	cudaMemcpy(out_data_host, out_data_gpu, bytesOut, cudaMemcpyDeviceToHost);
	cudaFree(in_data_gpu);
	cudaFree(out_data_gpu);

	int errors = 0;
	for (int i = 0; i < height && errors < 5; i++) {
		for (int j = 0; j < width && errors < 5; j++) {
			ushort in = in_data_host[i * width + j];
			float out = out_data_host[i * width + j];
			float w = (float)in / (float)(0x0ffff);
			if (fabs(w - out) > 0.001f) {
				++errors;
				printf("(%d, %d) - w = %f, out = %f %s\n", i, j, w, out, (errors ? "***":""));
			}
		}
	}

	printf("Pass/Fail : %s\n", (errors ? "Fail" : "Pass"));

	free(in_data_host);
	free(out_data_host);
	return errors;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **arg) {
	int errors = testNormalizedCoordinates() + testNormalizedUshort();

	return (errors ? -1 : 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

