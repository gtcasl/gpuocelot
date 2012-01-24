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
 
/*
* This sample demonstrates how use texture fetches in CUDA
*
* This sample takes an input PGM image (image_filename) and generates 
* an output PGM image (image_filename_out).  This CUDA kernel performs
* a simple 2D transform (rotation) on the texture coordinates (u,v).
*/

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
#include <sdkHelper.h>  // helper for shared that are common to CUDA SDK samples
#include <shrQATest.h>
#include <shrUtils.h>

// includes CUDA
#include <cuda_runtime.h>

// includes, kernels
#include <simpleSurfaceWrite_kernel.cu>

char *image_filename = "lena_bw.pgm";
char *ref_filename   = "ref_rotated.pgm";
float angle = 0.5f;    // angle to rotate image by (in radians)

static char *sSDKname = "simpleSurfaceWrite";

#define MIN_EPSILON_ERROR 5e-3f


////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest( int argc, char** argv);

extern "C"
void computeGold( float* reference, float* idata, const unsigned int len);

////////////////////////////////////////////////////////////////////////////////
// These are CUDA Helper functions

// This will output the proper CUDA error strings in the event that a CUDA host call returns an error
#define checkCudaErrors(err)  __checkCudaErrors (err, __FILE__, __LINE__)

inline void __checkCudaErrors(cudaError err, const char *file, const int line )
{
    if(cudaSuccess != err)
    {
        fprintf(stderr, "%s(%i) : CUDA Runtime API error %d: %s.\n",file, line, (int)err, cudaGetErrorString( err ) );
        exit(-1);        
    }
}

// This will output the proper error string when calling cudaGetLastError
#define getLastCudaError(msg)      __getLastCudaError (msg, __FILE__, __LINE__)

inline void __getLastCudaError(const char *errorMessage, const char *file, const int line )
{
    cudaError_t err = cudaGetLastError();
    if (cudaSuccess != err)
    {
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

    if (deviceCount == 0)
    {
        fprintf(stderr, "gpuDeviceInit() CUDA error: no devices supporting CUDA.\n");
        exit(-1);
    }

    if (devID < 0)
       devID = 0;
        
    if (devID > deviceCount-1)
    {
        fprintf(stderr, "\n");
        fprintf(stderr, ">> %d CUDA capable GPU device(s) detected. <<\n", deviceCount);
        fprintf(stderr, ">> gpuDeviceInit (-device=%d) is not a valid GPU device. <<\n", devID);
        fprintf(stderr, "\n");
        return -devID;
    }

    cudaDeviceProp deviceProp;
    checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );

    if (deviceProp.major < 1)
    {
        fprintf(stderr, "gpuDeviceInit(): GPU device does not support CUDA.\n");
        exit(-1);                                                  
    }
    
    checkCudaErrors( cudaSetDevice(devID) );
    printf("gpuDeviceInit() CUDA Device [%d]: \"%s\n", devID, deviceProp.name);

    return devID;
}

// This function returns the best GPU (with maximum GFLOPS)
int gpuGetMaxGflopsDeviceId()
{
    int current_device     = 0, sm_per_multiproc  = 0;
    int max_compute_perf   = 0, max_perf_device   = 0;
    int device_count       = 0, best_SM_arch      = 0;
    cudaDeviceProp deviceProp;
    cudaGetDeviceCount( &device_count );
    
    // Find the best major SM Architecture GPU device
    while (current_device < device_count)
    {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major > 0 && deviceProp.major < 9999)
        {
            best_SM_arch = MAX(best_SM_arch, deviceProp.major);
        }
        current_device++;
    }

    // Find the best CUDA capable GPU device
    current_device = 0;
    while( current_device < device_count )
    {
        cudaGetDeviceProperties( &deviceProp, current_device );
        if (deviceProp.major == 9999 && deviceProp.minor == 9999)
        {
            sm_per_multiproc = 1;
        }
        else
        {
            sm_per_multiproc = _ConvertSMVer2Cores(deviceProp.major, deviceProp.minor);
        }
        
        int compute_perf  = deviceProp.multiProcessorCount * sm_per_multiproc * deviceProp.clockRate;
        
    if( compute_perf  > max_compute_perf )
    {
            // If we find GPU with SM major > 2, search only these
            if ( best_SM_arch > 2 )
            {
                // If our device==dest_SM_arch, choose this, or else pass
                if (deviceProp.major == best_SM_arch)
                {
                    max_compute_perf  = compute_perf;
                    max_perf_device   = current_device;
                 }
            }
            else
            {
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
    if (checkCmdLineFlag(argc, argv, "device"))
    {
        devID = getCmdLineArgumentInt(argc, argv, "device=");
        if (devID < 0)
        {
            printf("Invalid command line parameter\n ");
            exit(-1);
        }
        else
        {
            devID = gpuDeviceInit(devID);
            if (devID < 0)
            {
                printf("exiting...\n");
                shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
                exit(-1);
            }
        }
    }
    else
    {
        // Otherwise pick the device with highest Gflops/s
        devID = gpuGetMaxGflopsDeviceId();
        checkCudaErrors( cudaSetDevice( devID ) );
        checkCudaErrors( cudaGetDeviceProperties(&deviceProp, devID) );
        printf("GPU Device %d: \"%s\" with compute capability %d.%d\n\n", devID, deviceProp.name, deviceProp.major, deviceProp.minor);
    }
    return devID;
}
// end of CUDA Helper Functions

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    runTest( argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runTest( int argc, char** argv) 
{
    bool bTestResult = true;
    shrQAStart(argc, argv);

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
	int devID = findCudaDevice(argc, (const char **)argv);

    // get number of SMs on this GPU
    cudaDeviceProp deviceProps;

	checkCudaErrors(cudaGetDeviceProperties(&deviceProps, devID));
    printf("CUDA device [%s] has %d Multi-Processors, SM %d.%d\n", deviceProps.name, deviceProps.multiProcessorCount, deviceProps.major, deviceProps.minor );

	if (deviceProps.major < 2) {
		printf("%s requires SM >= 2.0 for SurfaceWrites, exiting... \n", sSDKname);
		cudaDeviceReset();
        shrQAFinishExit(argc, (const char **)argv, QA_WAIVED);
	}

	// load image from disk
    float* h_data = NULL;
    unsigned int width, height;
    char* image_path = sdkFindFilePath(image_filename, argv[0]);
    if (image_path == NULL) {
        printf("Unable to source image input file: %s\n", image_filename);
        shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
    }
    sdkLoadPGM(image_path, &h_data, &width, &height);

    unsigned int size = width * height * sizeof(float);
    printf("Loaded '%s', %d x %d pixels\n", image_filename, width, height);

    // load reference image from image (output)
    float *h_data_ref = (float*) malloc(size);
    char* ref_path = sdkFindFilePath(ref_filename, argv[0]);
    if (ref_path == NULL) {
        printf("Unable to find reference image file: %s\n", ref_filename);
        shrQAFinishExit(argc, (const char **)argv, QA_FAILED);
    }
    sdkLoadPGM(ref_path, &h_data_ref, &width, &height);

	// allocate device memory for result
    float* d_data = NULL;
    checkCudaErrors( cudaMalloc( (void**) &d_data, size));

    // allocate array and copy image data
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32, 0, 0, 0, cudaChannelFormatKindFloat);
    cudaArray* cu_array;
    checkCudaErrors( cudaMallocArray( &cu_array, &channelDesc, width, height, cudaArraySurfaceLoadStore )); 

    dim3 dimBlock(8, 8, 1);
    dim3 dimGrid(width / dimBlock.x, height / dimBlock.y, 1);

#if 1
    checkCudaErrors( cudaMemcpy( d_data, h_data, size, cudaMemcpyHostToDevice) );
    checkCudaErrors(cudaBindSurfaceToArray(output_surface, cu_array));

    surfaceWriteKernel<<< dimGrid, dimBlock >>>( d_data, width, height);
#else // this is what differs from the example simpleTexture
    checkCudaErrors( cudaMemcpyToArray( cu_array, 0, 0, h_data, size, cudaMemcpyHostToDevice));
#endif

    // set texture parameters
    tex.addressMode[0] = cudaAddressModeWrap;
    tex.addressMode[1] = cudaAddressModeWrap;
    tex.filterMode = cudaFilterModeLinear;
    tex.normalized = true;    // access with normalized texture coordinates

    // Bind the array to the texture
    checkCudaErrors( cudaBindTextureToArray( tex, cu_array, channelDesc));

    // warmup
    transformKernel<<< dimGrid, dimBlock, 0 >>>( d_data, width, height, angle);

    checkCudaErrors( cudaDeviceSynchronize() );
    
	StopWatchInterface *timer = NULL;
    sdkCreateTimer( &timer );
    sdkStartTimer ( &timer );

    // execute the kernel
    transformKernel<<< dimGrid, dimBlock, 0 >>>( d_data, width, height, angle);

    // check if kernel execution generated an error
	getLastCudaError("Kernel execution failed");

    cudaDeviceSynchronize();
    sdkStopTimer( &timer );
    printf("Processing time: %f (ms)\n", sdkGetTimerValue( &timer ));
    printf("%.2f Mpixels/sec\n", (width*height / (sdkGetTimerValue( &timer ) / 1000.0f)) / 1e6);
    sdkDeleteTimer( &timer );

    // allocate mem for the result on host side
    float* h_odata = (float*) malloc( size);
    // copy result from device to host
    checkCudaErrors( cudaMemcpy( h_odata, d_data, size, cudaMemcpyDeviceToHost) );

    // write result to file
    char output_filename[1024];
    strcpy(output_filename, "output.pgm");
    sdkSavePGM( "output.pgm", h_odata, width, height );
    printf("Wrote '%s'\n", output_filename);

    // write regression file if necessary
    if( checkCmdLineFlag( argc, (const char**) argv, "regression"))
    {
        // write file for regression test
        sdkWriteFile<float>( "./data/regression.dat", h_odata, width*height, 0.0f, false );
    } 
    else 
    {
        // We need to reload the data from disk, because it is inverted upon output
        sdkLoadPGM(output_filename, &h_odata, &width, &height);

        printf("Comparing files\n");
        printf("\toutput:    <%s>\n", output_filename);
        printf("\treference: <%s>\n", ref_path);
        bTestResult = compareData( h_odata, h_data_ref, width*height, MIN_EPSILON_ERROR, 0.0f );
    }

    checkCudaErrors(cudaFree(d_data));
    checkCudaErrors(cudaFreeArray(cu_array));
    free(image_path);
    free(ref_path);

    cudaDeviceReset();
    shrQAFinishExit(argc, (const char **)argv, (bTestResult ? QA_PASSED : QA_FAILED) );
}
