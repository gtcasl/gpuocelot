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

// includes, system
#include <stdio.h>

// includes, project
#include <sdkHelper.h>  // helper for shared that are common to CUDA SDK samples
#include <shrQATest.h>  // This is for automated testing output (--qatest)

// includes CUDA
#include <cutil.h>
#include <cuda_runtime.h>

////////////////////////////////////////////////////////////////////////////////
// These are CUDA Helper functions

    // This will output the proper CUDA error strings in the event that a CUDA host call returns an error
    #define checkCudaErrors(err)           __checkCudaErrors (err, __FILE__, __LINE__)

    inline void __checkCudaErrors( cudaError err, const char *file, const int line )
    {
        if( cudaSuccess != err) {
		    fprintf(stderr, "%s(%i) : CUDA Runtime API error %d: %s.\n",
                    file, line, (int)err, cudaGetErrorString( err ) );
            exit(-1);
        }
    }

    // This will output the proper error string when calling cudaGetLastError
    #define getLastCudaError(msg)      __getLastCudaError (msg, __FILE__, __LINE__)

    inline void __getLastCudaError( const char *errorMessage, const char *file, const int line )
    {
        cudaError_t err = cudaGetLastError();
        if( cudaSuccess != err) {
            fprintf(stderr, "%s(%i) : getLastCudaError() CUDA error : %s : (%d) %s.\n",
                    file, line, errorMessage, (int)err, cudaGetErrorString( err ) );
            exit(-1);
        }
    }

    // General GPU Device CUDA Initialization
    int gpuDeviceInit(int devID)
    {
        int deviceCount;
        checkCudaErrors(cudaGetDeviceCount(&deviceCount));
        if (deviceCount == 0) {
            fprintf(stderr, "gpuDeviceInit() CUDA error: no devices supporting CUDA.\n");
            exit(-1);
        }
        if (devID < 0) 
            devID = 0;
        if (devID > deviceCount-1) {
            fprintf(stderr, "\n");
            fprintf(stderr, ">> %d CUDA capable GPU device(s) detected. <<\n", deviceCount);
            fprintf(stderr, ">> gpuDeviceInit (-device=%d) is not a valid GPU device. <<\n", devID);
            fprintf(stderr, "\n");
            return -devID;
        }

        cudaDeviceProp deviceProp;
        checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );
        if (deviceProp.major < 1) {
            fprintf(stderr, "gpuDeviceInit(): GPU device does not support CUDA.\n");
            exit(-1);                                                  \
        }

        checkCudaErrors( cudaSetDevice(devID) );
        printf("> gpuDeviceInit() CUDA device [%d]: %s\n", devID, deviceProp.name);
        return devID;
    }

    // This function returns the best GPU (with maximum GFLOPS)
    int gpuGetMaxGflopsDeviceId()
    {
	    int current_device   = 0, sm_per_multiproc = 0;
	    int max_compute_perf = 0, max_perf_device  = 0;
	    int device_count     = 0, best_SM_arch     = 0;
	    cudaDeviceProp deviceProp;

	    cudaGetDeviceCount( &device_count );
	    // Find the best major SM Architecture GPU device
	    while ( current_device < device_count ) {
		    cudaGetDeviceProperties( &deviceProp, current_device );
		    if (deviceProp.major > 0 && deviceProp.major < 9999) {
			    best_SM_arch = MAX(best_SM_arch, deviceProp.major);
		    }
		    current_device++;
	    }

        // Find the best CUDA capable GPU device
        current_device = 0;
        while( current_device < device_count ) {
           cudaGetDeviceProperties( &deviceProp, current_device );
           if (deviceProp.major == 9999 && deviceProp.minor == 9999) {
               sm_per_multiproc = 1;
		   } else {
               sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor);
           }

           int compute_perf  = deviceProp.multiProcessorCount * sm_per_multiproc * deviceProp.clockRate;
           if( compute_perf  > max_compute_perf ) {
               // If we find GPU with SM major > 2, search only these
               if ( best_SM_arch > 2 ) {
                   // If our device==dest_SM_arch, choose this, or else pass
                   if (deviceProp.major == best_SM_arch) {	
                       max_compute_perf  = compute_perf;
                       max_perf_device   = current_device;
                   }
               } else {
                   max_compute_perf  = compute_perf;
                   max_perf_device   = current_device;
               }
           }
           ++current_device;
	    }
	    return max_perf_device;
    }

    // Initialization code to find the best CUDA Device
    int findCudaDevice(int argc, const char **argv)
    {
        cudaDeviceProp deviceProp;
        int devID = 0;
        // If the command-line has a device number specified, use it
        if (checkCmdLineFlag(argc, argv, "device")) {
            devID = getCmdLineArgumentInt(argc, argv, "device=");
            if (devID < 0) {
                printf("Invalid command line parameters\n");
                exit(-1);
            } else {
                devID = gpuDeviceInit(devID);
                if (devID < 0) {
                   printf("exiting...\n");
                   shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
                   exit(-1);
                }
            }
        } else {
            // Otherwise pick the device with highest Gflops/s
            devID = gpuGetMaxGflopsDeviceId();
            checkCudaErrors( cudaSetDevice( devID ) );
            checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );
            printf("> Using CUDA device [%d]: %s\n", devID, deviceProp.name);
        }
        return devID;
    }
// end of CUDA Helper Functions


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
  const int nx = 2048;  
  const int ny = 2048;

  // shifts applied to x and y data
  const int x_shift = 5;
  const int y_shift = 7;

  shrQAStart(argc, argv);

  if ((nx%TILE_DIM != 0)  || (ny%TILE_DIM != 0)) {
    printf("nx and ny must be multiples of TILE_DIM\n");
    shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
  }

  // execution configuration parameters
  dim3 grid(nx/TILE_DIM, ny/TILE_DIM), threads(TILE_DIM, TILE_DIM);

  // This will pick the best possible CUDA capable device
  int devID = findCudaDevice((const int)argc, (const char **)argv);

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

  checkCudaErrors(cudaMallocPitch((void**) &d_idataPL, &d_pitchBytes, nx*sizeof(float), ny));

  // Array input data

  cudaArray *d_idataArray;
  cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc<float>();

  checkCudaErrors(cudaMallocArray(&d_idataArray, &channelDesc, nx, ny));

  // Pitch linear output data

  float *d_odata;
  checkCudaErrors(cudaMallocPitch( (void**) &d_odata, &d_pitchBytes, nx*sizeof(float), ny));

  // ------------------------
  // copy host data to device
  // ------------------------

  // Pitch linear

  size_t h_pitchBytes = nx*sizeof(float);

  checkCudaErrors(cudaMemcpy2D(d_idataPL, d_pitchBytes, h_idata, h_pitchBytes, 
			     nx*sizeof(float), ny, cudaMemcpyHostToDevice));

  // Array

  checkCudaErrors(cudaMemcpyToArray(d_idataArray, 0, 0, h_idata, 
				  nx*ny*sizeof(float), cudaMemcpyHostToDevice));

  // ----------------------
  // Bind texture to memory
  // ----------------------

  // Pitch linear

  texRefPL.normalized = 1;
  texRefPL.filterMode = cudaFilterModePoint;
  texRefPL.addressMode[0] = cudaAddressModeWrap;
  texRefPL.addressMode[1] = cudaAddressModeWrap;
  
  checkCudaErrors(cudaBindTexture2D(0, &texRefPL, d_idataPL, &channelDesc, nx, ny, d_pitchBytes));
  
  // Array

  texRefArray.normalized = 1;
  texRefArray.filterMode = cudaFilterModePoint;
  texRefArray.addressMode[0] = cudaAddressModeWrap;
  texRefArray.addressMode[1] = cudaAddressModeWrap;

  checkCudaErrors(cudaBindTextureToArray(texRefArray, d_idataArray, channelDesc));

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

  checkCudaErrors(cudaMemset2D(d_odata, d_pitchBytes, 0, nx*sizeof(float), ny));
  checkCudaErrors(cudaEventRecord(start, 0));
  for (int i=0; i < NUM_REPS; i++) {
    shiftPitchLinear<<<grid, threads>>>(d_odata, (int)(d_pitchBytes/sizeof(float)), nx, ny, 
					x_shift, y_shift);
  }
  checkCudaErrors(cudaEventRecord(stop, 0));
  checkCudaErrors(cudaEventSynchronize(stop));
  float timePL;
  checkCudaErrors(cudaEventElapsedTime(&timePL, start, stop));    

  // check results

  checkCudaErrors(cudaMemcpy2D(h_odata, h_pitchBytes, d_odata, d_pitchBytes, 
			     nx*sizeof(float), ny, cudaMemcpyDeviceToHost));

  bool res = compareData(gold, h_odata, nx*ny, 0.0f, 0.15f);

  bool success = true;
  if (res == false) {
    printf("*** shiftPitchLinear failed ***\n");
    success = false;
  }
    
  // ----------
  // shiftArray
  // ----------

  checkCudaErrors(cudaMemset2D(d_odata, d_pitchBytes, 0, nx*sizeof(float), ny));
  checkCudaErrors(cudaEventRecord(start, 0));
  for (int i=0; i < NUM_REPS; i++) {
    shiftArray<<<grid, threads>>>(d_odata, (int)(d_pitchBytes/sizeof(float)), nx, ny, x_shift, y_shift);
  }
  checkCudaErrors(cudaEventRecord(stop, 0));
  checkCudaErrors(cudaEventSynchronize(stop));
  float timeArray;
  checkCudaErrors(cudaEventElapsedTime(&timeArray, start, stop));    

  // check results

  checkCudaErrors(cudaMemcpy2D(h_odata, h_pitchBytes, d_odata, d_pitchBytes, 
		     nx*sizeof(float), ny, cudaMemcpyDeviceToHost));
  res = compareData(gold, h_odata, nx*ny, 0.0f, 0.15f);

  if (res == CUTFalse) {
    printf("*** shiftArray failed ***\n");
    success = CUTFalse;
  }
    
  float bandwidthPL = 2.f*1000.f*nx*ny*sizeof(float)/(1.e+9f)/(timePL/NUM_REPS);
  float bandwidthArray = 2.f*1000.f*nx*ny*sizeof(float)/(1.e+9f)/(timeArray/NUM_REPS);
  printf("\nBandwidth (GB/s) for pitch linear: %.2e; for array: %.2e\n", 
	 bandwidthPL, bandwidthArray);

  float fetchRatePL = nx*ny/1.e+6f/(timePL/(1000.0f*NUM_REPS));
  float fetchRateArray = nx*ny/1.e+6f/(timeArray/(1000.0f*NUM_REPS));
  printf("\nTexture fetch rate (Mpix/s) for pitch linear: %.2e; for array: %.2e\n\n", 
	 fetchRatePL, fetchRateArray);


  // cleanup
  free(h_idata);
  free(h_odata);
  free(gold);

  checkCudaErrors(cudaUnbindTexture(texRefPL));
  checkCudaErrors(cudaUnbindTexture(texRefArray));
  checkCudaErrors(cudaFree(d_idataPL));
  checkCudaErrors(cudaFreeArray(d_idataArray));
  checkCudaErrors(cudaFree(d_odata));

  checkCudaErrors(cudaEventDestroy(start));
  checkCudaErrors(cudaEventDestroy(stop));
  
  cudaDeviceReset();
  shrQAFinishExit(argc, (const char **)argv, (success == CUTTrue) ? QA_PASSED : QA_FAILED);
}
