/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

#include <parboil.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "gpu_info.h"
#include "spmv_jds.h"
#include "jds_kernels.cu"

static int generate_vector(float *x_vector, int dim) 
{	
	srand(54321);	
	for(int i=0;i<dim;i++)
	{
		x_vector[i] = (rand() / (float) RAND_MAX);
	}
	return 0;
}

int main(int argc, char** argv) {
	struct pb_TimerSet timers;
	struct pb_Parameters *parameters;
	
	
	
	
	
	printf("CUDA accelerated sparse matrix vector multiplication****\n");
	printf("Li-Wen Chang <lchang20@illinois.edu> and Shengzhao Wu<wu14@illinois.edu>\n");
	parameters = pb_ReadParameters(&argc, argv);
	if ((parameters->inpFiles[0] == NULL) || (parameters->inpFiles[1] != NULL))
    {
      fprintf(stderr, "Expecting one input filename\n");
      exit(-1);
    }

	
	pb_InitializeTimerSet(&timers);
	pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
	
	//parameters declaration
	int len;
	int depth;
	int dim;
	int pad=32;
	int nzcnt_len;
	
	//host memory allocation
	//matrix
	float *h_data;
	int *h_indices;
	int *h_ptr;
	int *h_perm;
	int *h_nzcnt;
	//vector
	float *h_Ax_vector;
    float *h_x_vector;
	
	//device memory allocation
	//matrix
	float *d_data;
	int *d_indices;
	int *d_ptr;
	int *d_perm;
	int *d_nzcnt;
	//vector
	float *d_Ax_vector;
    float *d_x_vector;
	
    //load matrix from files
	pb_SwitchToTimer(&timers, pb_TimerID_IO);
	inputData(parameters->inpFiles[0], &len, &depth, &dim,&nzcnt_len,&pad,
	    &h_data, &h_indices, &h_ptr,
	    &h_perm, &h_nzcnt);
		
	
	pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
	h_Ax_vector=(float*)malloc(sizeof(float)*dim);	
	h_x_vector=(float*)malloc(sizeof(float)*dim);	
	generate_vector(h_x_vector, dim);
	
	cudaDeviceProp deviceProp;
    cudaGetDeviceProperties(&deviceProp, 0);
	
	
	pb_SwitchToTimer(&timers, pb_TimerID_COPY);
	//memory allocation
	cudaMalloc((void **)&d_data, len*sizeof(float));
	cudaMalloc((void **)&d_indices, len*sizeof(int));
	cudaMalloc((void **)&d_ptr, depth*sizeof(int));
	cudaMalloc((void **)&d_perm, dim*sizeof(int));
	cudaMalloc((void **)&d_nzcnt, nzcnt_len*sizeof(int));
	cudaMalloc((void **)&d_x_vector, dim*sizeof(float));
	cudaMalloc((void **)&d_Ax_vector,dim*sizeof(float));
	cudaMemset( (void *) d_Ax_vector, 0, dim*sizeof(float));
	
	//memory copy
	cudaMemcpy(d_data, h_data, len*sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(d_indices, h_indices, len*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_perm, h_perm, dim*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_x_vector, h_x_vector, dim*sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpyToSymbol(jds_ptr_int, h_ptr, depth*sizeof(int));
	cudaMemcpyToSymbol(sh_zcnt_int, h_nzcnt,nzcnt_len*sizeof(int));
	
	pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
	dim3 grid;
	dim3 block;
    compute_active_thread(&(block.x), &(grid.x),nzcnt_len,pad, deviceProp.major,deviceProp.minor,
					deviceProp.warpSize,deviceProp.multiProcessorCount);
//	grid.x=nzcnt_len;
//	block.x=pad;
	grid.y=1;
	grid.z=1;
	block.y=1;
	block.z=1;
	
	//main execution
	pb_SwitchToTimer(&timers, pb_TimerID_GPU);
	cudaBindTexture(0,tex_x_float, d_x_vector);
	spmv_jds_texture<<<grid, block>>>(d_Ax_vector,
							d_data,d_indices,d_perm,
							d_x_vector,d_nzcnt,dim);
							
    CUERR // check and clear any existing errors
    cudaUnbindTexture(tex_x_float);
	
	
	pb_SwitchToTimer(&timers, pb_TimerID_COPY);
	//HtoD memory copy
	cudaMemcpy(h_Ax_vector, d_Ax_vector,dim*sizeof(float), cudaMemcpyDeviceToHost);	
	
	cudaFree(d_data);
    cudaFree(d_indices);
    cudaFree(d_ptr);
	cudaFree(d_perm);
    cudaFree(d_nzcnt);
    cudaFree(d_x_vector);
	cudaFree(d_Ax_vector);
 
	if (parameters->outFile) {
		pb_SwitchToTimer(&timers, pb_TimerID_IO);
		outputData(parameters->outFile,h_Ax_vector,dim);
		
	}
	pb_SwitchToTimer(&timers, pb_TimerID_COMPUTE);
	
	free (h_data);
	free (h_indices);
	free (h_ptr);
	free (h_perm);
	free (h_nzcnt);
	free (h_Ax_vector);
	free (h_x_vector);
	pb_SwitchToTimer(&timers, pb_TimerID_NONE);

	pb_PrintTimerSet(&timers);
	pb_FreeParameters(parameters);

	return 0;

}
