/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO USER:
 *
 * This source code is subject to NVIDIA ownership rights under U.S. and
 * international Copyright laws.  Users and possessors of this source code
 * are hereby granted a nonexclusive, royalty-free license to use this code
 * in individual and commercial software.
 *
 * NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
 * CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
 * IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
 * OR PERFORMANCE OF THIS SOURCE CODE.
 *
 * U.S. Government End Users.   This source code is a "commercial item" as
 * that term is defined at  48 C.F.R. 2.numIterations1 (OCT 1995), consisting  of
 * "commercial computer  software"  and "commercial computer software
 * documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
 * and is provided to the U.S. Government only as a commercial end item.
 * Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
 * 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
 * source code with only those rights set forth herein.
 *
 * Any use of this source code in individual and commercial software must
 * include, in the user documentation and internal comments to the code,
 * the above Disclaimer and U.S. Government End Users Notice.
 */


// ----------------------------------------------------------------------------------------
// Transpose
//
// This file contains both device and host code for transposing a floating-point
// matrix.  It performs several transpose kernels, which incrementally improve performance
// through coalescing, removing shared memory bank conflicts, and eliminating partition
// camping.  Several of the kernels perform a copy, used to represent the best case
// performance that a transpose can achieve.
//
// Please see the whitepaper in the docs folder of the transpose project for a detailed
// description of this performance study.
// ----------------------------------------------------------------------------------------

#include <stdio.h>
#include <cutil_inline.h>

// Each block transposes/copies a tile of TILE_DIM x TILE_DIM elements
// using TILE_DIM x BLOCK_ROWS threads, so that each thread transposes
// TILE_DIM/BLOCK_ROWS elements.  TILE_DIM must be an integral multiple of BLOCK_ROWS

#define TILE_DIM 32
#define BLOCK_ROWS 8

// modified so it doesn't take forever to run on emulation mode
#if 1
int MATRIX_SIZE_X = 128;
int MATRIX_SIZE_Y = 128;
int MUL_FACTOR    = 4;
#else
int MATRIX_SIZE_X = 2048;
int MATRIX_SIZE_Y = 2048;
int MUL_FACTOR    = 32;
#endif


// Number of repetitions used for timing.  Two sets of repetitions are performed:
// 1) over kernel launches and 2) inside the kernel over just the loads and stores

#define NUM_REPS  100

// -------------------------------------------------------
// Copies
// width and height must be integral multiples of TILE_DIM
// -------------------------------------------------------

__global__ void copy(float *odata, float* idata, int width, int height, int nreps)
{
  int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx.y * TILE_DIM + threadIdx.y;
  
  int index  = xIndex + width*yIndex;
  for (int r=0; r < nreps; r++) {
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      odata[index+i*width] = idata[index+i*width];
    }
  }
}

__global__ void copySharedMem(float *odata, float *idata, int width, int height, int nreps)
{
  __shared__ float tile[TILE_DIM][TILE_DIM];

  int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx.y * TILE_DIM + threadIdx.y;
  
  int index  = xIndex + width*yIndex;
  for (int r=0; r < nreps; r++) {
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      tile[threadIdx.y+i][threadIdx.x] = idata[index+i*width];
    }
  
    __syncthreads();
  
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      odata[index+i*width] = tile[threadIdx.y+i][threadIdx.x];
    }
  }
}

// -------------------------------------------------------
// Transposes
// width and height must be integral multiples of TILE_DIM
// -------------------------------------------------------

__global__ void transposeNaive(float *odata, float* idata, int width, int height, int nreps)
{
  int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx.y * TILE_DIM + threadIdx.y;

  int index_in  = xIndex + width * yIndex;
  int index_out = yIndex + height * xIndex;
  for (int r=0; r < nreps; r++) {
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      odata[index_out+i] = idata[index_in+i*width];
    }
  }
}

// coalesced transpose (with bank conflicts)

__global__ void transposeCoalesced(float *odata, float *idata, int width, int height, int nreps)
{
  __shared__ float tile[TILE_DIM][TILE_DIM];

  int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx.y * TILE_DIM + threadIdx.y;  
  int index_in = xIndex + (yIndex)*width;

  xIndex = blockIdx.y * TILE_DIM + threadIdx.x;
  yIndex = blockIdx.x * TILE_DIM + threadIdx.y;
  int index_out = xIndex + (yIndex)*height;

  for (int r=0; r < nreps; r++) {
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      tile[threadIdx.y+i][threadIdx.x] = idata[index_in+i*width];
    }
  
    __syncthreads();
  
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      odata[index_out+i*height] = tile[threadIdx.x][threadIdx.y+i];
    }
  }
}

// Coalesced transpose with no bank conflicts

__global__ void transposeNoBankConflicts(float *odata, float *idata, int width, int height, int nreps)
{
  __shared__ float tile[TILE_DIM][TILE_DIM+1];

  int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx.y * TILE_DIM + threadIdx.y;  
  int index_in = xIndex + (yIndex)*width;

  xIndex = blockIdx.y * TILE_DIM + threadIdx.x;
  yIndex = blockIdx.x * TILE_DIM + threadIdx.y;
  int index_out = xIndex + (yIndex)*height;

  for (int r=0; r < nreps; r++) {
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      tile[threadIdx.y+i][threadIdx.x] = idata[index_in+i*width];
    }
  
    __syncthreads();
  
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      odata[index_out+i*height] = tile[threadIdx.x][threadIdx.y+i];
    }
  }
}

// Transpose that effectively reorders execution of thread blocks along diagonals of the 
// matrix (also coalesced and has no bank conflicts)
//
// Here blockIdx.x is interpreted as the distance along a diagonal and blockIdx.y as 
// corresponding to different diagonals
//
// blockIdx_x and blockIdx_y expressions map the diagonal coordinates to the more commonly 
// used cartesian coordinates so that the only changes to the code from the coalesced version 
// are the calculation of the blockIdx_x and blockIdx_y and replacement of blockIdx.x and 
// bloclIdx.y with the subscripted versions in the remaining code

__global__ void transposeDiagonal(float *odata, float *idata, int width, int height, int nreps)
{
  __shared__ float tile[TILE_DIM][TILE_DIM+1];

  int blockIdx_x, blockIdx_y;

  // do diagonal reordering
  if (width == height) {
    blockIdx_y = blockIdx.x;
    blockIdx_x = (blockIdx.x+blockIdx.y)%gridDim.x;
  } else {
    int bid = blockIdx.x + gridDim.x*blockIdx.y;
    blockIdx_y = bid%gridDim.y;
    blockIdx_x = ((bid/gridDim.y)+blockIdx_y)%gridDim.x;
  }    

  // from here on the code is same as previous kernel except blockIdx_x replaces blockIdx.x
  // and similarly for y

  int xIndex = blockIdx_x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx_y * TILE_DIM + threadIdx.y;  
  int index_in = xIndex + (yIndex)*width;

  xIndex = blockIdx_y * TILE_DIM + threadIdx.x;
  yIndex = blockIdx_x * TILE_DIM + threadIdx.y;
  int index_out = xIndex + (yIndex)*height;

  for (int r=0; r < nreps; r++) {
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      tile[threadIdx.y+i][threadIdx.x] = idata[index_in+i*width];
    }
  
    __syncthreads();
  
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      odata[index_out+i*height] = tile[threadIdx.x][threadIdx.y+i];
    }
  }
}

// --------------------------------------------------------------------
// Partial transposes
// NB: the coarse- and fine-grained routines only perform part of a 
//     transpose and will fail the test against the reference solution
//
//     They are used to assess performance characteristics of different
//     components of a full transpose
// --------------------------------------------------------------------

__global__ void transposeFineGrained(float *odata, float *idata, int width, int height,  int nreps)
{
  __shared__ float block[TILE_DIM][TILE_DIM+1];

  int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx.y * TILE_DIM + threadIdx.y;
  int index = xIndex + (yIndex)*width;

  for (int r=0; r<nreps; r++) {
    for (int i=0; i < TILE_DIM; i += BLOCK_ROWS) {
      block[threadIdx.y+i][threadIdx.x] = idata[index+i*width];
    }  
     
    __syncthreads();

    for (int i=0; i < TILE_DIM; i += BLOCK_ROWS) {
      odata[index+i*height] = block[threadIdx.x][threadIdx.y+i];
    }
  }
}


__global__ void transposeCoarseGrained(float *odata, float *idata, int width, int height, int nreps)
{
  __shared__ float block[TILE_DIM][TILE_DIM+1];

  int xIndex = blockIdx.x * TILE_DIM + threadIdx.x;
  int yIndex = blockIdx.y * TILE_DIM + threadIdx.y;
  int index_in = xIndex + (yIndex)*width;

  xIndex = blockIdx.y * TILE_DIM + threadIdx.x;
  yIndex = blockIdx.x * TILE_DIM + threadIdx.y;
  int index_out = xIndex + (yIndex)*height;

  for (int r=0; r<nreps; r++) {
    for (int i=0; i<TILE_DIM; i += BLOCK_ROWS) {
      block[threadIdx.y+i][threadIdx.x] = idata[index_in+i*width];
    }
  
    __syncthreads();

    for (int i=0; i<TILE_DIM; i += BLOCK_ROWS) {
      odata[index_out+i*height] = block[threadIdx.y+i][threadIdx.x];
    }
  }
}


// ---------------------
// host utility routines
// ---------------------

void computeTransposeGold(float* gold, float* idata,
			  const  int size_x, const  int size_y)
{
  for(  int y = 0; y < size_y; ++y) {
    for(  int x = 0; x < size_x; ++x) {
      gold[(x * size_y) + y] = idata[(y * size_x) + x];
    }
  }
}


// ----
// main
// ----

int
main( int argc, char** argv) 
{
  // use command-line specified CUDA device, otherwise use device with highest Gflops/s
  if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
    cutilDeviceInit(argc, argv);
  else
    cudaSetDevice( cutGetMaxGflopsDeviceId() );

  int devID;
  cudaDeviceProp props;

  // get number of SMs on this GPU
  cutilSafeCall(cudaGetDevice(&devID));
  cutilSafeCall(cudaGetDeviceProperties(&props, devID));

  int SMcount = 32 / props.multiProcessorCount;

  printf("CUDA device has %d Multi-Processors\n", props.multiProcessorCount);

    // set matrix size
  int size_x = max(MATRIX_SIZE_X / SMcount, TILE_DIM*MUL_FACTOR);
  int size_y = max(MATRIX_SIZE_Y / SMcount, TILE_DIM*MUL_FACTOR); 

  if (size_x%TILE_DIM != 0 || size_y%TILE_DIM != 0) {
    printf("Matrix size must be integral multiple of tile size\n\nTest PASSED\n");
    cutilExit(argc, argv);
  }

  // kernel pointer and descriptor
  void (*kernel)(float *, float *, int, int, int);
  char *kernelName;

  // execution configuration parameters
  dim3 grid(size_x/TILE_DIM, size_y/TILE_DIM), threads(TILE_DIM,BLOCK_ROWS);

  // CUDA events
  cudaEvent_t start, stop;

  // size of memory required to store the matrix
  const  int mem_size = sizeof(float) * size_x*size_y;


  // allocate host memory
  float *h_idata = (float*) malloc(mem_size);
  float *h_odata = (float*) malloc(mem_size);
  float *transposeGold = (float *) malloc(mem_size);  
  float *gold;

  // allocate device memory
  float *d_idata, *d_odata;
  cutilSafeCall( cudaMalloc( (void**) &d_idata, mem_size) );
  cutilSafeCall( cudaMalloc( (void**) &d_odata, mem_size) );

  // initalize host data
  for(  int i = 0; i < (size_x*size_y); ++i)
    h_idata[i] = (float) i;
  
  // copy host data to device
  cutilSafeCall( cudaMemcpy(d_idata, h_idata, mem_size, cudaMemcpyHostToDevice) );

  // Compute reference transpose solution
  computeTransposeGold(transposeGold, h_idata, size_x, size_y);

  // print out common data for all kernels
  printf("\nMatrix size: %dx%d, tile size: %dx%d, block size: %dx%d\n\n", 
	 size_x, size_y, TILE_DIM, TILE_DIM, TILE_DIM, BLOCK_ROWS);
  
  printf("Kernel\t\t\tLoop over kernel\tLoop within kernel\n");
  printf("------\t\t\t----------------\t------------------\n");

  // initialize events
  
  cutilSafeCall( cudaEventCreate(&start) );
  cutilSafeCall( cudaEventCreate(&stop) );

  //
  // loop over different kernels
  //

  CUTBoolean success = CUTTrue;

  for (int k = 0; k<8; k++) {
    // set kernel pointer
    switch (k) {
    case 0:
      kernel = &copy;                           kernelName = "simple copy           "; break;
    case 1:
      kernel = &copySharedMem;                  kernelName = "shared memory copy    "; break;
    case 2:
      kernel = &transposeNaive;                 kernelName = "naive transpose       "; break;
    case 3:
      kernel = &transposeCoalesced;             kernelName = "coalesced transpose   "; break;
    case 4:
      kernel = &transposeNoBankConflicts;       kernelName = "no bank conflict trans"; break;
    case 5:
      kernel = &transposeCoarseGrained;         kernelName = "coarse-grained        "; break;
    case 6:
      kernel = &transposeFineGrained;           kernelName = "fine-grained          "; break;
    case 7:
      kernel = &transposeDiagonal;              kernelName = "diagonal transpose    "; break;
    }      

    // set reference solution
    if (kernel == &copy || kernel == &copySharedMem) {
      gold = h_idata;
    } else if (kernel == &transposeCoarseGrained || kernel == &transposeFineGrained) {
      gold = h_odata;   // fine- and coarse-grained kernels are not full transposes, so bypass check
    } else {
      gold = transposeGold;
    }

    // warmup to avoid timing startup
    kernel<<<grid, threads>>>(d_odata, d_idata, size_x, size_y, 1);

    // take measurements for loop over kernel launches
    cutilSafeCall( cudaEventRecord(start, 0) );
    for (int i=0; i < NUM_REPS; i++) {
      kernel<<<grid, threads>>>(d_odata, d_idata, size_x, size_y, 1);
    }
    cutilSafeCall( cudaEventRecord(stop, 0) );
    cutilSafeCall( cudaEventSynchronize(stop) );
    float outerTime;
    cutilSafeCall( cudaEventElapsedTime(&outerTime, start, stop) );    

    cutilSafeCall( cudaMemcpy(h_odata, d_odata, mem_size, cudaMemcpyDeviceToHost) );
    CUTBoolean res = cutComparef(gold, h_odata, size_x*size_y);
    if (res == CUTFalse) {
      printf("*** %s kernel FAILED ***\n", kernelName);
      success = CUTFalse;
    }

    // take measurements for loop inside kernel
    cutilSafeCall( cudaEventRecord(start, 0) );
    kernel<<<grid, threads>>>(d_odata, d_idata, size_x, size_y, NUM_REPS);
    cutilSafeCall( cudaEventRecord(stop, 0) );
    cutilSafeCall( cudaEventSynchronize(stop) );
    float innerTime;
    cutilSafeCall( cudaEventElapsedTime(&innerTime, start, stop) );    

    cutilSafeCall( cudaMemcpy(h_odata, d_odata, mem_size, cudaMemcpyDeviceToHost) );
    res = cutComparef(gold, h_odata, size_x*size_y);
    if (res == CUTFalse) {
      printf("*** %s kernel FAILED ***\n", kernelName);
      success = CUTFalse;
    }
    
    // report effective bandwidths
    float outerBandwidth = 2.*1000*mem_size/(1024*1024*1024)/(outerTime/NUM_REPS);
    float innerBandwidth = 2.*1000*mem_size/(1024*1024*1024)/(innerTime/NUM_REPS);
    printf("%s\t%5.2f GB/s\t\t%5.2f GB/s\n", kernelName, outerBandwidth, innerBandwidth);
  }
  
  printf("\nTest %s\n", (success == CUTTrue) ? "PASSED" : "FAILED");

  // cleanup

  free(h_idata);
  free(h_odata);
  free(transposeGold);
  cutilSafeCall( cudaFree(d_idata) );
  cutilSafeCall( cudaFree(d_odata) );

  cutilSafeCall( cudaEventDestroy(start) );
  cutilSafeCall( cudaEventDestroy(stop) );
  
  cudaThreadExit();
  cutilExit(argc, argv);
  return 0;

}
