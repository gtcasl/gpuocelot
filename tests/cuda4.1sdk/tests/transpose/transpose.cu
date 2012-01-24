/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
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

// Utilities and system includes
#include <shrUtils.h>
#include <shrQATest.h>
#include <cutil_inline.h>

const char *sSDKsample = "Transpose";

// Each block transposes/copies a tile of TILE_DIM x TILE_DIM elements
// using TILE_DIM x BLOCK_ROWS threads, so that each thread transposes
// TILE_DIM/BLOCK_ROWS elements.  TILE_DIM must be an integral multiple of BLOCK_ROWS

#define TILE_DIM    16
#define BLOCK_ROWS  16

// This sample assumes that MATRIX_SIZE_X = MATRIX_SIZE_Y
int MATRIX_SIZE_X = 1024;
int MATRIX_SIZE_Y = 1024;
int MUL_FACTOR    = TILE_DIM;

#define FLOOR(a,b) (a-(a%b))

// Compute the tile size necessary to illustrate performance cases for SM12+ hardware
int MAX_TILES_SM12 = (FLOOR(MATRIX_SIZE_X,512) * FLOOR(MATRIX_SIZE_Y,512)) / (TILE_DIM*TILE_DIM);   
// Compute the tile size necessary to illustrate performance cases for SM10,SM11 hardware
int MAX_TILES_SM10 = (FLOOR(MATRIX_SIZE_X,384) * FLOOR(MATRIX_SIZE_Y,384)) / (TILE_DIM*TILE_DIM);

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
	  if (xIndex < width && yIndex < height)
        tile[threadIdx.y][threadIdx.x] = idata[index];
    }
  
    __syncthreads();
  
    for (int i=0; i<TILE_DIM; i+=BLOCK_ROWS) {
      if (xIndex < height && yIndex < width)
        odata[index] = tile[threadIdx.y][threadIdx.x];
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


void getParams(int argc, char **argv, cudaDeviceProp &deviceProp, int &size_x, int &size_y, int max_tile_dim)
{
    // set matrix size (if (x,y) dim of matrix is not square, then this will have to be modified
  if ( cutGetCmdLineArgumenti(argc, (const char **) argv, "dimx", &size_x) || 
	   cutGetCmdLineArgumenti(argc, (const char **) argv, "dimX", &size_x) ) {
      if (size_x > max_tile_dim) {
          shrLog("> MatrixSize X = %d is greater than the recommended size = %d\n", size_x, max_tile_dim);
      } else {
          shrLog("> MatrixSize X = %d\n", size_x);
      }
  } else {
      size_x = max_tile_dim;
      // If this is SM12 hardware, we want to round down to a multiple of 512
      if ((deviceProp.major == 1 && deviceProp.minor >= 2) || deviceProp.major > 1 ) {
          size_x = FLOOR(size_x, 512);
      } else { // else for SM10,SM11 we round down to a multiple of 384
          size_x = FLOOR(size_x, 384);
      }
  }

  if ( cutGetCmdLineArgumenti(argc, (const char **) argv, "dimy", &size_y) ||
	   cutGetCmdLineArgumenti(argc, (const char **) argv, "dimY", &size_y) ) {
      if (size_y > max_tile_dim) {
          shrLog("> MatrixSize Y = %d is greater than the recommended size = %d\n", size_y, max_tile_dim);
      } else {
          shrLog("> MatrixSize Y = %d\n", size_y);
      }
  } else {
      size_y = max_tile_dim;
      // If this is SM12 hardware, we want to round down to a multiple of 512
      if ((deviceProp.major == 1 && deviceProp.minor >= 2) || deviceProp.major > 1) {
          size_y = FLOOR(size_y, 512);
      } else { // else for SM10,SM11 we round down to a multiple of 384
          size_y = FLOOR(size_y, 384);
      }
  }
}


void
showHelp()
{
  shrLog("\n> Command line options\n", sSDKsample);
  shrLog("\t-device=n          (where n=0,1,2.... for the GPU device)\n\n");
  shrLog("> The default matrix size can be overridden with these parameters\n");
  shrLog("\t-dimX=row_dim_size (matrix row    dimensions)\n");
  shrLog("\t-dimY=col_dim_size (matrix column dimensions)\n");
}


// ----
// main
// ----

int
main( int argc, char** argv) 
{
  shrQAStart(argc, argv);

  // Start logs
  shrSetLogFileName ("transpose.txt");
  shrLog("%s Starting...\n\n", argv[0]);

  if( cutCheckCmdLineFlag(argc, (const char**)argv, "help") ) {
    showHelp();
    return 0;
  }

  // use command-line specified CUDA device, otherwise use device with highest Gflops/s
  if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
    cutilDeviceInit(argc, argv);
  else
    cutilSafeCall( cudaSetDevice( cutGetMaxGflopsDeviceId() ) );

  int devID;
  cudaDeviceProp deviceProp;

  // get number of SMs on this GPU
  cutilSafeCall(cudaGetDevice(&devID));
  cutilSafeCall(cudaGetDeviceProperties(&deviceProp, devID));

  // compute the scaling factor (for GPUs with fewer MPs)
  float scale_factor, total_tiles;
  scale_factor = max((192.0f / (ConvertSMVer2Cores(deviceProp.major, deviceProp.minor) * (float)deviceProp.multiProcessorCount) ), 1.0f);

  shrLog("> Device %d: \"%s\"\n", devID, deviceProp.name);
  shrLog("> SM Capability %d.%d detected:\n", deviceProp.major, deviceProp.minor);

  // Calculate number of tiles we will run for the Matrix Transpose performance tests
  int size_x, size_y, max_matrix_dim, matrix_size_test;

  if ((deviceProp.major == 1 && deviceProp.minor >= 2) || deviceProp.major > 1) {
      matrix_size_test = 512;  // we round down max_matrix_dim for this perf test
      total_tiles = (float)MAX_TILES_SM12 / scale_factor;
  } else {
      matrix_size_test = 384;  // we round down max_matrix_dim for this perf test
      total_tiles = (float)MAX_TILES_SM10 / scale_factor;
  }
  max_matrix_dim = FLOOR((int)(floor(sqrt(total_tiles))* TILE_DIM), matrix_size_test);

  // This is the minimum size allowed
  if (max_matrix_dim == 0) 
    max_matrix_dim = matrix_size_test;
	
  shrLog("> [%s] has %d MP(s) x %d (Cores/MP) = %d (Cores)\n", 
			deviceProp.name, deviceProp.multiProcessorCount,
			ConvertSMVer2Cores(deviceProp.major, deviceProp.minor),
			ConvertSMVer2Cores(deviceProp.major, deviceProp.minor) * deviceProp.multiProcessorCount);

  shrLog("> Compute performance scaling factor = %4.2f\n", scale_factor);

  // Extract parameters if there are any, command line -dimx and -dimy can override 
  // any of these settings
  getParams(argc, argv, deviceProp, size_x, size_y, max_matrix_dim);

  if (size_x != size_y) {
      shrLog("\n[%s] does not support non-square matrices (row_dim_size(%d) != col_dim_size(%d))\nExiting...\n\n", sSDKsample, size_x, size_y);
      cutilDeviceReset();
      shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
  }

  if (size_x%TILE_DIM != 0 || size_y%TILE_DIM != 0) {
    shrLog("[%s] Matrix size must be integral multiple of tile size\nExiting...\n\n", sSDKsample);
    cutilDeviceReset();
    shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
  }

  // kernel pointer and descriptor
  void (*kernel)(float *, float *, int, int, int);
  char *kernelName;

  // execution configuration parameters
  dim3 grid(size_x/TILE_DIM, size_y/TILE_DIM), threads(TILE_DIM,BLOCK_ROWS);
  
  if (grid.x < 1 || grid.y < 1) {
    shrLog("[%s] grid size computation incorrect in test \nExiting...\n\n", sSDKsample);
	cutilDeviceReset();
    shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
  }

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
  shrLog("\nMatrix size: %dx%d (%dx%d tiles), tile size: %dx%d, block size: %dx%d\n\n", 
	 size_x, size_y, size_x/TILE_DIM, size_y/TILE_DIM, TILE_DIM, TILE_DIM, TILE_DIM, BLOCK_ROWS);

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
      kernel = &copy;                           kernelName = "simple copy       "; break;
    case 1:
      kernel = &copySharedMem;                  kernelName = "shared memory copy"; break;
    case 2:
      kernel = &transposeNaive;                 kernelName = "naive             "; break;
    case 3:
      kernel = &transposeCoalesced;             kernelName = "coalesced         "; break;
    case 4:
      kernel = &transposeNoBankConflicts;       kernelName = "optimized         "; break;
    case 5:
      kernel = &transposeCoarseGrained;         kernelName = "coarse-grained    "; break;
    case 6:
      kernel = &transposeFineGrained;           kernelName = "fine-grained      "; break;
    case 7:
      kernel = &transposeDiagonal;              kernelName = "diagonal          "; break;
    }      

    // set reference solution
    if (kernel == &copy || kernel == &copySharedMem) {
      gold = h_idata;
    } else if (kernel == &transposeCoarseGrained || kernel == &transposeFineGrained) {
      gold = h_odata;   // fine- and coarse-grained kernels are not full transposes, so bypass check
    } else {
      gold = transposeGold;
    }

    // Clear error status
    cutilSafeCall( cudaGetLastError() );

    // warmup to avoid timing startup
    kernel<<<grid, threads>>>(d_odata, d_idata, size_x, size_y, 1);

    // take measurements for loop over kernel launches
    cutilSafeCall( cudaEventRecord(start, 0) );
    for (int i=0; i < NUM_REPS; i++) {
      kernel<<<grid, threads>>>(d_odata, d_idata, size_x, size_y, 1);
      // Ensure no launch failure
      cutilSafeCall( cudaGetLastError() );
    }
    cutilSafeCall( cudaEventRecord(stop, 0) );
    cutilSafeCall( cudaEventSynchronize(stop) );
    float outerTime;
    cutilSafeCall( cudaEventElapsedTime(&outerTime, start, stop) );

    cutilSafeCall( cudaMemcpy(h_odata, d_odata, mem_size, cudaMemcpyDeviceToHost) );
    CUTBoolean res = cutComparef(gold, h_odata, size_x*size_y);
    if (res == CUTFalse) {
      shrLog("*** %s kernel FAILED ***\n", kernelName);
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
      shrLog("*** %s kernel FAILED ***\n", kernelName);
      success = CUTFalse;
    }
    
    // report effective bandwidths
    float outerBandwidth = 2.0f * 1000.0f * mem_size/(1024*1024*1024)/(outerTime/NUM_REPS);
    float innerBandwidth = 2.0f * 1000.0f * mem_size/(1024*1024*1024)/(innerTime/NUM_REPS);
    
    shrLog("\n");
    shrLogEx(LOGBOTH | MASTER, 0, "transpose-Outer-%s, Throughput = %.4f GB/s, Time = %.5f s, Size = %u fp32 elements, NumDevsUsed = %u, Workgroup = %u\n", 
           kernelName,
           outerBandwidth, 
           outerTime/NUM_REPS, 
           (size_x * size_y), 1, TILE_DIM * BLOCK_ROWS); 
    shrLogEx(LOGBOTH | MASTER, 0, "transpose-Inner-%s, Throughput = %.4f GB/s, Time = %.5f s, Size = %u fp32 elements, NumDevsUsed = %u, Workgroup = %u\n", 
           kernelName,
           innerBandwidth, 
           innerTime/NUM_REPS, 
           (size_x * size_y), 1, TILE_DIM * BLOCK_ROWS);
                       
   }
  
  // cleanup
  free(h_idata);
  free(h_odata);
  free(transposeGold);
  cutilSafeCall( cudaFree(d_idata) );
  cutilSafeCall( cudaFree(d_odata) );

  cutilSafeCall( cudaEventDestroy(start) );
  cutilSafeCall( cudaEventDestroy(stop) );
  
  cutilDeviceReset();
  shrQAFinishExit(argc, (const char **)argv, (success == CUTTrue) ? QA_PASSED : QA_FAILED);
  return 0;
}
