#include "find_ellipse_kernel.h"
#include <stdio.h>


// The number of sample points in each ellipse (stencil)
#define NPOINTS 150
// The maximum radius of a sample ellipse
#define MAX_RAD 20
// The total number of sample ellipses
#define NCIRCLES 7
// The size of the structuring element used in dilation
#define STREL_SIZE (12 * 2 + 1)


// Matrix used to store the maximal GICOV score at each pixels
// Produced by the GICOV kernel and consumed by the dilation kernel
float *device_gicov;


// Constant device arrays holding the stencil parameters used by the GICOV kernel
__constant__ float c_sin_angle[NPOINTS];
__constant__ float c_cos_angle[NPOINTS];
__constant__ int c_tX[NCIRCLES * NPOINTS];
__constant__ int c_tY[NCIRCLES * NPOINTS];

// Texture references to the gradient matrices used by the GICOV kernel
texture<float, 1, cudaReadModeElementType> t_grad_x;
texture<float, 1, cudaReadModeElementType> t_grad_y;

// Kernel to find the maximal GICOV value at each pixel of a
//  video frame, based on the input x- and y-gradient matrices
__global__ void GICOV_kernel(int grad_m, float *gicov) {
	int i, j, k, n, x, y;
	
	// Determine this thread's pixel
	i = blockIdx.x + MAX_RAD + 2;
	j = threadIdx.x + MAX_RAD + 2;

	// Initialize the maximal GICOV score to 0
	float max_GICOV = 0.f;

	// Iterate across each stencil
	for (k = 0; k < NCIRCLES; k++) {
		// Variables used to compute the mean and variance
		//  of the gradients along the current stencil
		float sum = 0.f, M2 = 0.f, mean = 0.f;		
		
		// Iterate across each sample point in the current stencil
		for (n = 0; n < NPOINTS; n++) {
			// Determine the x- and y-coordinates of the current sample point
			y = j + c_tY[(k * NPOINTS) + n];
			x = i + c_tX[(k * NPOINTS) + n];
			
			// Compute the combined gradient value at the current sample point
			int addr = x * grad_m + y;
			float p = tex1Dfetch(t_grad_x,addr) * c_cos_angle[n] + 
					  tex1Dfetch(t_grad_y,addr) * c_sin_angle[n];
			
			// Update the running total
			sum += p;
			
			// Partially compute the variance
			float delta = p - mean;
			mean = mean + (delta / (float) (n + 1));
			M2 = M2 + (delta * (p - mean));
		}
		
		// Finish computing the mean
		mean = sum / ((float) NPOINTS);
		
		// Finish computing the variance
		float var = M2 / ((float) (NPOINTS - 1));
		
		// Keep track of the maximal GICOV value seen so far
		if (((mean * mean) / var) > max_GICOV) max_GICOV = (mean * mean) / var;
	}
	
	// Store the maximal GICOV value
	gicov[(i * grad_m) + j] = max_GICOV;
}


// Sets up and invokes the GICOV kernel and returns its output
float *GICOV_CUDA(int grad_m, int grad_n, float *host_grad_x, float *host_grad_y) {

	int MaxR = MAX_RAD + 2;

	// Allocate device memory
	unsigned int grad_mem_size = sizeof(float) * grad_m * grad_n;
	float *device_grad_x, *device_grad_y;
	cudaMalloc((void**) &device_grad_x, grad_mem_size);
	cudaMalloc((void**) &device_grad_y, grad_mem_size);

	// Copy the input gradients to the device
	cudaMemcpy(device_grad_x, host_grad_x, grad_mem_size, cudaMemcpyHostToDevice);
	cudaMemcpy(device_grad_y, host_grad_y, grad_mem_size, cudaMemcpyHostToDevice);
    
	// Bind the device arrays to texture references
    cudaBindTexture(0, t_grad_x, device_grad_x, grad_mem_size);
    cudaBindTexture(0, t_grad_y, device_grad_y, grad_mem_size);

	// Allocate & initialize device memory for result
	// (some elements are not assigned values in the kernel)
	cudaMalloc((void**) &device_gicov, grad_mem_size);
	cudaMemset(device_gicov, 0, grad_mem_size);

	// Setup execution parameters
	int num_blocks = grad_n - (2 * MaxR);
	int threads_per_block = grad_m - (2 * MaxR);
    
	// Execute the GICOV kernel
	GICOV_kernel <<< num_blocks, threads_per_block >>> (grad_m, device_gicov);
	
	// Check for kernel errors
	cudaThreadSynchronize();
	cudaError_t error = cudaGetLastError();
	if (error != cudaSuccess) {
		printf("GICOV kernel error: %s\n", cudaGetErrorString(error));
		exit(EXIT_FAILURE);
	}

	// Copy the result to the host
	float *host_gicov = (float *) malloc(grad_mem_size);
	cudaMemcpy(host_gicov, device_gicov, grad_mem_size, cudaMemcpyDeviceToHost);

	// Cleanup memory
	cudaUnbindTexture(t_grad_x);
	cudaUnbindTexture(t_grad_y);
	cudaFree(device_grad_x);
	cudaFree(device_grad_y);

	return host_gicov;
}


// Constant device array holding the structuring element used by the dilation kernel
__constant__ float c_strel[STREL_SIZE * STREL_SIZE];

// Texture reference to the GICOV matrix used by the dilation kernel
texture<float, 1, cudaReadModeElementType> t_img;

// Kernel to compute the dilation of the GICOV matrix produced by the GICOV kernel
// Each element (i, j) of the output matrix is set equal to the maximal value in
//  the neighborhood surrounding element (i, j) in the input matrix
// Here the neighborhood is defined by the structuring element (c_strel)
__global__ void dilate_kernel(int img_m, int img_n, int strel_m, int strel_n, float *dilated) {	
	// Find the center of the structuring element
	int el_center_i = strel_m / 2;
	int el_center_j = strel_n / 2;

	// Determine this thread's location in the matrix
	int thread_id = (blockIdx.x * blockDim.x) + threadIdx.x;
	int i = thread_id % img_m;
	int j = thread_id / img_m;

	// Initialize the maximum GICOV score seen so far to zero
	float max = 0.0;

	// Iterate across the structuring element in one dimension
	int el_i, el_j, x, y;
	for(el_i = 0; el_i < strel_m; el_i++) {
		y = i - el_center_i + el_i;
		// Make sure we have not gone off the edge of the matrix
		if( (y >= 0) && (y < img_m) ) {
			// Iterate across the structuring element in the other dimension
			for(el_j = 0; el_j < strel_n; el_j++) {
				x = j - el_center_j + el_j;
				// Make sure we have not gone off the edge of the matrix
				//  and that the current structuring element value is not zero
				if( (x >= 0) &&
					(x < img_n) &&
					(c_strel[(el_i * strel_n) + el_j] != 0) ) {
						// Determine if this is maximal value seen so far
						int addr = (x * img_m) + y;
						float temp = tex1Dfetch(t_img, addr);
						if (temp > max) max = temp;
				}
			}
		}
	}
	
	// Store the maximum value found
	dilated[(i * img_n) + j] = max;
}


// Sets up and invokes the dilation kernel and returns its output
float *dilate_CUDA(int max_gicov_m, int max_gicov_n, int strel_m, int strel_n) {
	// Allocate device memory for result
	unsigned int max_gicov_mem_size = sizeof(float) * max_gicov_m * max_gicov_n;
	float* device_img_dilated;
	cudaMalloc( (void**) &device_img_dilated, max_gicov_mem_size);
	
	// Bind the input matrix of GICOV values to a texture reference
	cudaBindTexture(0, t_img, device_gicov, max_gicov_mem_size);
    
	// Setup execution parameters
	int num_threads = max_gicov_m * max_gicov_n;
	int threads_per_block = 176;
	int num_blocks = (int) (((float) num_threads / (float) threads_per_block) + 0.5);

	// Execute the dilation kernel
	dilate_kernel <<< num_blocks, threads_per_block >>> (max_gicov_m, max_gicov_n, strel_m, strel_n, device_img_dilated);
	
	// Check for kernel errors
	cudaThreadSynchronize();
	cudaError_t error = cudaGetLastError();
	if (error != cudaSuccess) {
		printf("Dilation kernel error: %s\n", cudaGetErrorString(error));
		exit(EXIT_FAILURE);
	}

	// Copy the result to the host
	float *host_img_dilated = (float*) malloc(max_gicov_mem_size);
	cudaMemcpy(host_img_dilated, device_img_dilated, max_gicov_mem_size, cudaMemcpyDeviceToHost);

	// Cleanup memory
	cudaUnbindTexture(t_img);
	cudaFree(device_gicov);
	cudaFree(device_img_dilated);

	return host_img_dilated;
}


// Chooses the most appropriate GPU on which to execute
void select_device() {
	// Figure out how many devices exist
	int num_devices, device;
	cudaGetDeviceCount(&num_devices);
	
	// Choose the device with the largest number of multiprocessors
	if (num_devices > 0) {
		int max_multiprocessors = 0, max_device = -1;
		for (device = 0; device < num_devices; device++) {
			cudaDeviceProp properties;
			cudaGetDeviceProperties(&properties, device);
			if (max_multiprocessors < properties.multiProcessorCount) {
				max_multiprocessors = properties.multiProcessorCount;
				max_device = device;
			}
		}
		cudaSetDevice(max_device);
	}
	
	// The following is to remove the API initialization overhead from the runtime measurements
	cudaFree(0);
}


// Transfers pre-computed constants used by the two kernels to the GPU
void transfer_constants(float *host_sin_angle, float *host_cos_angle, int *host_tX, int *host_tY, int strel_m, int strel_n, float *host_strel) {

	// Compute the sizes of the matrices
	unsigned int angle_mem_size = sizeof(float) * NPOINTS;
	unsigned int t_mem_size = sizeof(int) * NCIRCLES * NPOINTS;
	unsigned int strel_mem_size = sizeof(float) * strel_m * strel_n;

	// Copy the matrices from host memory to device constant memory
	cudaMemcpyToSymbol("c_sin_angle", host_sin_angle, angle_mem_size, 0, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol("c_cos_angle", host_cos_angle, angle_mem_size, 0, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol("c_tX", host_tX, t_mem_size, 0, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol("c_tY", host_tY, t_mem_size, 0, cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol("c_strel", host_strel, strel_mem_size, 0, cudaMemcpyHostToDevice);
}
