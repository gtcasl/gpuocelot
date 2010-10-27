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
 
 
/* pitchLinearTexture 
 *
 * This example demostrates how to use textures bound to pitch linear memory.  
 * It performs a shift of matrix elements using wrap addressing mode (aka
 * periodic boundary conditions) on two arrays, a pitch linear and a CUDA array,
 * in order to highlight the differences in using each. 
 *
 * Textures binding to pitch linear memory is a new feature in CUDA 2.2,
 * and allows use of texture features such as wrap addressing mode and 
 * filtering which are not possible with textures bound to regular linear memory 
 */

#include <stdio.h>
#include <cutil_inline.h>


#define NUM_REPS 100  // number of repetitions performed  
#define TILE_DIM 16   // tile/block size

// Texture references

texture<float, 2, cudaReadModeElementType> texRefPL;
texture<float, 2, cudaReadModeElementType> texRefArray;

// -------
// kernels
// -------
//
// NB: (1) The second argument "pitch" is in elements, not bytes
//     (2) normalized coordinates are used (required for wrap address mode)

__global__ void shiftPitchLinear(float* odata, int pitch, int width, int height, 
				 int shiftX, int shiftY)
{
  int xid = blockIdx.x * blockDim.x + threadIdx.x;
  int yid = blockIdx.y * blockDim.y + threadIdx.y;
  
  odata[yid*pitch+xid] = tex2D(texRefPL, 
			       (xid + shiftX)/(float)width, 
			       (yid + shiftY)/(float)height);
}

__global__ void shiftArray(float* odata, int pitch, int width, int height,
			   int shiftX, int shiftY)
{
  int xid = blockIdx.x * blockDim.x + threadIdx.x;
  int yid = blockIdx.y * blockDim.y + threadIdx.y;
  
  odata[yid*pitch+xid] = tex2D(texRefArray, 
			       (xid + shiftX)/(float)width, 
			       (yid + shiftY)/(float)height);
}

// ----
// main
// ----

int
main( int argc, char** argv) 
{
  // set array size

 #ifdef __DEVICE_EMULATION__
  const int nx = 64;  
  const int ny = 64;
#else
  const int nx = 2048;  
  const int ny = 2048;
#endif
  // shifts applied to x and y data

  const int x_shift = 5;
  const int y_shift = 7;

  if ((nx%TILE_DIM != 0)  || (ny%TILE_DIM != 0)) {
    printf("nx and ny must be multiples of TILE_DIM\nPASSED\n");
    cutilExit(argc, argv);
  }

  // execution configuration parameters

  dim3 grid(nx/TILE_DIM, ny/TILE_DIM), threads(TILE_DIM, TILE_DIM);

  // use command-line specified CUDA device, otherwise use device with highest Gflops/s
  if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
    cutilDeviceInit(argc, argv);
  else
    cudaSetDevice( cutGetMaxGflopsDeviceId() );

  // CUDA events for timing

  cudaEvent_t start, stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  // ----------------------------------
  // Host allocation and initialization
  // ----------------------------------

  float *h_idata = (float*) malloc(sizeof(float)*nx*ny);
  float *h_odata = (float*) malloc(sizeof(float)*nx*ny);
  float *gold = (float*) malloc(sizeof(float)*nx*ny);

  for(int i = 0; i < nx*ny; ++i) h_idata[i] = (float) i;  

  // ------------------------
  // Device memory allocation
  // ------------------------

  // Pitch linear input data

  float *d_idataPL;
  size_t d_pitchBytes;

  cutilSafeCall(cudaMallocPitch((void**) &d_idataPL, &d_pitchBytes, nx*sizeof(float), ny));

  // Array input data

  cudaArray *d_idataArray;
  cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<float>();

  cutilSafeCall(cudaMallocArray(&d_idataArray, &channelDesc, nx, ny));

  // Pitch linear output data

  float *d_odata;
  cutilSafeCall(cudaMallocPitch( (void**) &d_odata, &d_pitchBytes, nx*sizeof(float), ny));

  // ------------------------
  // copy host data to device
  // ------------------------

  // Pitch linear

  size_t h_pitchBytes = nx*sizeof(float);

  cutilSafeCall(cudaMemcpy2D(d_idataPL, d_pitchBytes, h_idata, h_pitchBytes, 
			     nx*sizeof(float), ny, cudaMemcpyHostToDevice));

  // Array

  cutilSafeCall(cudaMemcpyToArray(d_idataArray, 0, 0, h_idata, 
				  nx*ny*sizeof(float), cudaMemcpyHostToDevice));

  // ----------------------
  // Bind texture to memory
  // ----------------------

  // Pitch linear

  texRefPL.normalized = 1;
  texRefPL.filterMode = cudaFilterModePoint;
  texRefPL.addressMode[0] = cudaAddressModeWrap;
  texRefPL.addressMode[1] = cudaAddressModeWrap;
  
  cutilSafeCall(cudaBindTexture2D(0, &texRefPL, d_idataPL, &channelDesc, nx, ny, d_pitchBytes));
  
  // Array

  texRefArray.normalized = 1;
  texRefArray.filterMode = cudaFilterModePoint;
  texRefArray.addressMode[0] = cudaAddressModeWrap;
  texRefArray.addressMode[1] = cudaAddressModeWrap;

  cutilSafeCall(cudaBindTextureToArray(texRefArray, d_idataArray, channelDesc));

  // ---------------------
  // reference calculation
  // ---------------------

  for (int j = 0; j < ny; j++) {
    int jshift = (j+y_shift)%ny;
    for (int i = 0; i < nx; i++) {
      int ishift = (i+x_shift)%nx;
      gold[j*nx + i] = h_idata[jshift*nx + ishift];
    }
  }

  // ----------------
  // shiftPitchLinear
  // ----------------

  cutilSafeCall(cudaMemset2D(d_odata, d_pitchBytes, 0, nx*sizeof(float), ny));
  cutilSafeCall(cudaEventRecord(start, 0));
  for (int i=0; i < NUM_REPS; i++) {
    shiftPitchLinear<<<grid, threads>>>(d_odata, d_pitchBytes/sizeof(float), nx, ny, 
					x_shift, y_shift);
  }
  cutilSafeCall(cudaEventRecord(stop, 0));
  cutilSafeCall(cudaEventSynchronize(stop));
  float timePL;
  cutilSafeCall(cudaEventElapsedTime(&timePL, start, stop));    

  // check results

  cutilSafeCall(cudaMemcpy2D(h_odata, h_pitchBytes, d_odata, d_pitchBytes, 
			     nx*sizeof(float), ny, cudaMemcpyDeviceToHost));

  CUTBoolean res = cutComparef(gold, h_odata, nx*ny);

  CUTBoolean success = CUTTrue;;
  if (res == CUTFalse) {
    printf("*** shiftPitchLinear failed ***\n");
    success = CUTFalse;
  }
    
  // ----------
  // shiftArray
  // ----------

  cutilSafeCall(cudaMemset2D(d_odata, d_pitchBytes, 0, nx*sizeof(float), ny));
  cutilSafeCall(cudaEventRecord(start, 0));
  for (int i=0; i < NUM_REPS; i++) {
    shiftArray<<<grid, threads>>>(d_odata, d_pitchBytes/sizeof(float), nx, ny, x_shift, y_shift);
  }
  cutilSafeCall(cudaEventRecord(stop, 0));
  cutilSafeCall(cudaEventSynchronize(stop));
  float timeArray;
  cutilSafeCall(cudaEventElapsedTime(&timeArray, start, stop));    

  // check results

  cutilSafeCall(cudaMemcpy2D(h_odata, h_pitchBytes, d_odata, d_pitchBytes, 
		     nx*sizeof(float), ny, cudaMemcpyDeviceToHost));
  res = cutComparef(gold, h_odata, nx*ny);

  if (res == CUTFalse) {
    printf("*** shiftArray failed ***\n");
    success = CUTFalse;
  }
    
  float bandwidthPL = 2.f*1000*nx*ny*sizeof(float)/(1.e+9)/(timePL/NUM_REPS);
  float bandwidthArray = 2.f*1000*nx*ny*sizeof(float)/(1.e+9)/(timeArray/NUM_REPS);
  printf("\nBandwidth (GB/s) for pitch linear: %.2e; for array: %.2e\n", 
	 bandwidthPL, bandwidthArray);

  float fetchRatePL = nx*ny/1.e+6/(timePL/(1000.0f*NUM_REPS));
  float fetchRateArray = nx*ny/1.e+6/(timeArray/(1000.0f*NUM_REPS));
  printf("\nTexture fetch rate (Mpix/s) for pitch linear: %.2e; for array: %.2e\n\n", 
	 fetchRatePL, fetchRateArray);


  printf("%s\n", (success == CUTTrue) ? "PASSED" : "FAILED");

  // cleanup

  free(h_idata);
  free(h_odata);
  free(gold);

  cutilSafeCall(cudaUnbindTexture(texRefPL));
  cutilSafeCall(cudaUnbindTexture(texRefArray));
  cutilSafeCall(cudaFree(d_idataPL));
  cutilSafeCall(cudaFreeArray(d_idataArray));
  cutilSafeCall(cudaFree(d_odata));

  cutilSafeCall(cudaEventDestroy(start));
  cutilSafeCall(cudaEventDestroy(stop));
  
  cudaThreadExit();
  cutilExit(argc, argv);
}
