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

	if (errors) {
		printf("FAILED\n\n testNormalizedCoordinates() - failed\n");
	}

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
	int width = 128, height = 128;

	ushort *in_data_host, *in_data_gpu;
	float *out_data_host, *out_data_gpu;

	size_t bytesIn = width * height * sizeof(ushort);
	size_t bytesOut = width * height * sizeof(float);
	in_data_host = (ushort *)malloc(bytesIn);
	out_data_host = (float *)malloc(bytesOut);

	// procedural texture generation
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			in_data_host[i * width + j] = ((1000 + i*3 + j*2) % (1 << 14));
			out_data_host[i*width+j] = 0;
		}
	}

	cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(16, 0, 0, 0, 
		cudaChannelFormatKindUnsigned);
	size_t pitch = sizeof(ushort)*width;
	if (cudaMallocPitch((void **)&in_data_gpu, &pitch, width * sizeof(ushort), height) 
		!= cudaSuccess) {
		printf("cudaMallocPitch() failed\n");
		return 1;
	}
	if (cudaMemcpy2D(in_data_gpu, pitch, in_data_host, sizeof(ushort)*width, 
		width*sizeof(ushort), height, cudaMemcpyHostToDevice) != cudaSuccess) {
		printf("cudaMemcpy2D() failed\n");
	}

	surfaceNormUshort.addressMode[0] = cudaAddressModeWrap;
	surfaceNormUshort.addressMode[1] = cudaAddressModeWrap;
	surfaceNormUshort.filterMode = cudaFilterModePoint;
	surfaceNormUshort.normalized = false;

	if (cudaBindTexture2D(0, &surfaceNormUshort, in_data_gpu, &channelDesc, width, height, 
		pitch) != cudaSuccess) {
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

	if (errors) {
		printf("FAILED\n\n testNormalizedUshort() - failed\n");
	}

	free(in_data_host);
	free(out_data_host);
	return errors;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

texture<float, 2, cudaReadModeElementType> surfaceUpsample;

/*!
	kernel in which each thread samples the texture and writes it to out, a row-major dense 
	block of samples
*/
extern "C" __global__ void kernelUpsample(float *out, int width, int height) {
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;

	float u = (float)x / (float)width;
	float v = (float)y / (float)height;

	float sample = tex2D(surfaceUpsample, u, v);

	out[x + y * width] = sample;
}

/*!
	\brief constructs a texture and samples
*/
static int testUpsample() {
	const int inWidth = 32, inHeight = 32;
	const int outWidth = 128, outHeight = 128;

	float *in_data_host, *in_data_gpu;
	float *out_data_host, *out_data_gpu;

	size_t bytesIn = inWidth * inHeight * sizeof(float);
	size_t bytesOut = outWidth * outHeight * sizeof(float);

	size_t pitch = sizeof(float)*inWidth;
	int errors = 0;

	in_data_host = (float *)malloc(bytesIn);
	out_data_host = (float *)malloc(bytesOut);

	// procedural texture generation
	for (int i = 0; i < inHeight; i++) {
		for (int j = 0; j < inWidth; j++) {
			float x = ((123 + 7 * i + 11 * j) % 1024) / (1024.0f);
			in_data_host[i * inWidth + j] = x;
		}
	}
	for (int i = 0; i < outHeight; i++) {
		for (int j = 0; j < outWidth; j++) {
			out_data_host[i * outWidth + j] = 0;
		}
	}

	cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32, 0, 0, 0, 
		cudaChannelFormatKindFloat);
	if (cudaMallocPitch((void **)&in_data_gpu, &pitch, inWidth * sizeof(float), inHeight) 
		!= cudaSuccess) {
		printf("cudaMallocPitch() failed\n");
		return 1;
	}
	if (cudaMemcpy2D(in_data_gpu, pitch, in_data_host, sizeof(float)*inWidth, 
		inWidth*sizeof(float), inHeight, cudaMemcpyHostToDevice) != cudaSuccess) {
		printf("cudaMemcpy2D() failed\n");
	}

	surfaceUpsample.addressMode[0] = cudaAddressModeWrap;
	surfaceUpsample.addressMode[1] = cudaAddressModeWrap;
	surfaceUpsample.filterMode = cudaFilterModePoint;
	surfaceUpsample.normalized = true;

	if (cudaBindTexture2D(0, &surfaceUpsample, in_data_gpu, &channelDesc, inWidth, inHeight, 
		pitch) != cudaSuccess) {
		printf("failed to bind texture: %s\n", cudaGetErrorString(cudaGetLastError()));
		free(in_data_host);
		free(out_data_host);
		cudaFree(in_data_gpu);
		return -2;
	}

	cudaMalloc((void **)&out_data_gpu, bytesOut);

	dim3 grid(outWidth / 16, outHeight / 16), block(16, 16);
	
	kernelUpsample<<< grid, block >>>(out_data_gpu, outWidth, outHeight);

	cudaThreadSynchronize();

	cudaError_t cudaError = cudaGetLastError();
	if (cudaError != cudaSuccess) {
		printf("kernelNormLinear() returned with error %s\n", cudaGetErrorString(cudaError));
		++errors;
	} 

	cudaMemcpy(out_data_host, out_data_gpu, bytesOut, cudaMemcpyDeviceToHost);
	cudaFree(in_data_gpu);
	cudaFree(out_data_gpu);

	for (int i = 0; i < outHeight && errors < 5; i++) {
		for (int j = 0; j < outWidth && errors < 5; j++) {
			//
			// simulate nearest point sampling
			//
			float u = (float)j / (float)outWidth, v = (float)i / (float)outHeight;
			
			int tx = (int)(u * (float)inWidth), ty = (int)(v * (float)inHeight);
			float w = in_data_host[tx + inWidth * ty];

			float out = out_data_host[i * outWidth + j];
			if (fabs(w - out) > 0.001f) {
				++errors;
				printf("(%d, %d) - w = %f, out = %f %s\n", i, j, w, out, (errors ? "***":""));
			}
		}
	}

	if (errors) {
		printf("FAILED\n\n testUpsample() - failed\n");
	}

	free(in_data_host);
	free(out_data_host);
	return errors;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

texture<float, 2, cudaReadModeElementType> surfaceUpsampleLinear;

/*!
	kernel in which each thread samples the texture and writes it to out, a row-major dense 
	block of samples
*/
extern "C" __global__ void kernelUpsampleLinear(float *out, int width, int height) {
	unsigned int x = blockIdx.x*blockDim.x + threadIdx.x;
	unsigned int y = blockIdx.y*blockDim.y + threadIdx.y;

	float u = (float)x / (float)width;
	float v = (float)y / (float)height;

	float sample = tex2D(surfaceUpsampleLinear, u, v);

	out[x + y * width] = sample;
}

/*!
	\brief constructs a texture and samples
*/
static int testUpsampleLinear() {
	const int inWidth = 32, inHeight = 32;
	const int outWidth = 128, outHeight = 128;

	float *in_data_host, *in_data_gpu;
	float *out_data_host, *out_data_gpu;

	size_t bytesIn = inWidth * inHeight * sizeof(float);
	size_t bytesOut = outWidth * outHeight * sizeof(float);

	size_t pitch = sizeof(float)*inWidth;
	int errors = 0;

	in_data_host = (float *)malloc(bytesIn);
	out_data_host = (float *)malloc(bytesOut);

	// procedural texture generation
	for (int i = 0; i < inHeight; i++) {
		for (int j = 0; j < inWidth; j++) {
			float x = ((123 + 7 * i + 11 * j) % 1024) / (1024.0f);
			in_data_host[i * inWidth + j] = x;
		}
	}
	for (int i = 0; i < outHeight; i++) {
		for (int j = 0; j < outWidth; j++) {
			out_data_host[i * outWidth + j] = 0;
		}
	}

	cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32, 0, 0, 0, 
		cudaChannelFormatKindFloat);
	if (cudaMallocPitch((void **)&in_data_gpu, &pitch, inWidth * sizeof(float), inHeight) 
		!= cudaSuccess) {
		printf("cudaMallocPitch() failed\n");
		return 1;
	}
	if (cudaMemcpy2D(in_data_gpu, pitch, in_data_host, sizeof(float)*inWidth, 
		inWidth*sizeof(float), inHeight, cudaMemcpyHostToDevice) != cudaSuccess) {
		printf("cudaMemcpy2D() failed\n");
	}

	surfaceUpsampleLinear.addressMode[0] = cudaAddressModeWrap;
	surfaceUpsampleLinear.addressMode[1] = cudaAddressModeWrap;
	surfaceUpsampleLinear.filterMode = cudaFilterModeLinear;
	surfaceUpsampleLinear.normalized = true;

	if (cudaBindTexture2D(0, &surfaceUpsampleLinear, in_data_gpu, &channelDesc, inWidth, inHeight, 
		pitch) != cudaSuccess) {
		printf("failed to bind texture: %s\n", cudaGetErrorString(cudaGetLastError()));
		free(in_data_host);
		free(out_data_host);
		cudaFree(in_data_gpu);
		return -2;
	}

	cudaMalloc((void **)&out_data_gpu, bytesOut);

	dim3 grid(outWidth / 16, outHeight / 16), block(16, 16);
	
	kernelUpsampleLinear<<< grid, block >>>(out_data_gpu, outWidth, outHeight);

	cudaThreadSynchronize();

	cudaError_t cudaError = cudaGetLastError();
	if (cudaError != cudaSuccess) {
		printf("kernelNormLinear() returned with error %s\n", cudaGetErrorString(cudaError));
		++errors;
	} 

	cudaMemcpy(out_data_host, out_data_gpu, bytesOut, cudaMemcpyDeviceToHost);
	cudaFree(in_data_gpu);
	cudaFree(out_data_gpu);

	printf("\n\nChecking bilinear interpolation\n");

	for (int i = 4; i < outHeight - 4 && errors < 5; i++) {
		for (int j = 4; j < outWidth - 4 && errors < 5; j++) {
			//
			// simulate bilinear sampling
			//
			float u = (float)j / (float)outWidth, v = (float)i / (float)outHeight;
			int tx = (int)(u * (float)inWidth), ty = (int)(v * (float)inHeight);

			float s0 = 0, s1 = 0, s2 = 0, s3 = 0;

			// nearest point sampling of four pixels containing texture sample (u, v)
			s0 = in_data_host[tx + ty * inWidth];
			s1 = in_data_host[tx+1 + ty * inWidth];
			s2 = in_data_host[tx + (ty + 1) * inWidth];
			s3 = in_data_host[tx + 1 + (ty + 1) * inWidth];			

			// bilinear interpolate
			float itu = (u * (float)inWidth) - (float)tx;
			float itv = (v * (float)inHeight) - (float)ty;

			float w = (s0 * (1.0f - itu) + s1 * itu) * (1.0f - itv) +
				(s2 * (1.0f - itu) + s3 * itu) * itv;
			
			// correctness test
			float out = out_data_host[i * outWidth + j];
			if (fabs(w - out) > 0.001f) {
				++errors;
				printf("(%d, %d) - w = %f, out = %f %s\n", j, i, w, out, (errors ? "***":""));
				printf("      (u, v) = %f, %f\n", u, v);
				printf("  (itu, itv) = %f, %f\n", itu, itv);
				printf("  s0 = %f\n", s0);
				printf("  s1 = %f\n", s1);
				printf("  s2 = %f\n", s2);
				printf("  s3 = %f\n", s3);
			}
		}
	}

	if (errors) {
		printf("FAILED\n\n testUpsampleLinear() - failed\n");
	}

	free(in_data_host);
	free(out_data_host);
	return errors;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **arg) {
	int errors = testNormalizedCoordinates() + testNormalizedUshort() 
		+ testUpsample();

	printf("Pass/Fail : %s\n", (errors ? "Fail" : "Pass"));
	return (errors ? -1 : 0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

