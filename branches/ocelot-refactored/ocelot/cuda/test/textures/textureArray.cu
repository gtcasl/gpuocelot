/*!
	\file textureArray.cu
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief tests implementation of cudaMallocArray() and cudaBindTextureToArray()
	\date February 12, 2010

	This was taken directly from the NVIDIA CUDA Programming Guide
*/

//////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////

// 2D float texture
texture<float, 2, cudaReadModeElementType> texRef;

// Simple transformation kernel
__global__ void transformKernel(float* output, int width, int height, float theta) {
  // Calculate normalized texture coordinates
  unsigned int x = blockIdx.x * blockDim.x + threadIdx.x;
  unsigned int y = blockIdx.y * blockDim.y + threadIdx.y;
  float u = x / (float)width;
  float v = y / (float)height;
  // Transform coordinates
  u -= 0.5f;
  v -= 0.5f;
  float tu = u * cosf(theta) – v * sinf(theta) + 0.5f;
  float tv = v * cosf(theta) + u * sinf(theta) + 0.5f;
  // Read from texture and write to global memory
  output[y * width + x] = tex2D(tex, tu, tv);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

// Host code
int main(int argc, char *arg[]) {

	// Allocate CUDA array in device memory
	cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32,0,0,0, cudaChannelFormatKindFloat);
	cudaArray* cuArray;
	cudaMallocArray(&cuArray, &channelDesc, width, height);

	// Copy to device memory some data located at address h_data
	// in host memory
	cudaMemcpyToArray(cuArray, 0, 0, h_data, size, cudaMemcpyHostToDevice);

	// Set texture parameters
	texRef.addressMode[0] = cudaAddressModeWrap;
	texRef.addressMode[1] = cudaAddressModeWrap;
	texRef.filterMode     = cudaFilterModeLinear;
	texRef.normalized     = true;

	// Bind the array to the texture
	cudaBindTextureToArray(texRef, cuArray, channelDesc);

	// Allocate result of transformation in device memory
	float* output;
	cudaMalloc((void**)&output, width * height * sizeof(float));

	// Invoke kernel
	dim3 dimBlock(16, 16);
	dim3 dimGrid((width + dimBlock.x – 1) / dimBlock.x,
		           (height + dimBlock.y – 1) / dimBlock.y);
	transformKernel<<<dimGrid, dimBlock>>>(output, width, height,  angle);

	// Free device memory
	cudaFreeArray(cuArray);
	cudaFree(output);

	return 0;
}

