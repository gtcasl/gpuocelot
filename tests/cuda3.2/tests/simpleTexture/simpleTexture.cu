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
#include <cutil_inline.h>

// includes, kernels
#include <simpleTexture_kernel.cu>

char *image_filename = "lena_bw.pgm";
char *ref_filename   = "ref_rotated.pgm";
float angle = 0.5f;    // angle to rotate image by (in radians)

#define MIN_EPSILON_ERROR 5e-3f


////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest( int argc, char** argv);

extern "C"
void computeGold( float* reference, float* idata, const unsigned int len);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int
main( int argc, char** argv) 
{
    runTest( argc, argv);

    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Run a simple test for CUDA
////////////////////////////////////////////////////////////////////////////////
void
runTest( int argc, char** argv) 
{
	// use command-line specified CUDA device, otherwise use device with highest Gflops/s
	if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
	{
		cutilDeviceInit(argc, argv);
	}
	else
	{
		cudaSetDevice( cutGetMaxGflopsDeviceId() );
	}

    // load image from disk
    float* h_data = NULL;
    unsigned int width, height;
    char* image_path = cutFindFilePath(image_filename, argv[0]);
    if (image_path == 0) {
        printf("Unable to source file file %s\n", image_filename);
        exit(EXIT_FAILURE);
    }
    cutilCheckError( cutLoadPGMf(image_path, &h_data, &width, &height));

    unsigned int size = width * height * sizeof(float);
    printf("Loaded '%s', %d x %d pixels\n", image_filename, width, height);

    // load reference image from image (output)
    float *h_data_ref = (float*) malloc(size);
    char* ref_path = cutFindFilePath(ref_filename, argv[0]);
    if (ref_path == 0) {
        printf("Unable to find reference file %s\n", ref_filename);
        exit(EXIT_FAILURE);
    }
    cutilCheckError( cutLoadPGMf(ref_path, &h_data_ref, &width, &height));

    // allocate device memory for result
    float* d_data = NULL;
    cutilSafeCall( cudaMalloc( (void**) &d_data, size));

    // allocate array and copy image data
    cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32, 0, 0, 0, cudaChannelFormatKindFloat);
    cudaArray* cu_array;
    cutilSafeCall( cudaMallocArray( &cu_array, &channelDesc, width, height )); 
    cutilSafeCall( cudaMemcpyToArray( cu_array, 0, 0, h_data, size, cudaMemcpyHostToDevice));

    // set texture parameters
    tex.addressMode[0] = cudaAddressModeWrap;
    tex.addressMode[1] = cudaAddressModeWrap;
    tex.filterMode = cudaFilterModeLinear;
    tex.normalized = true;    // access with normalized texture coordinates

    // Bind the array to the texture
    cutilSafeCall( cudaBindTextureToArray( tex, cu_array, channelDesc));

    dim3 dimBlock(8, 8, 1);
    dim3 dimGrid(width / dimBlock.x, height / dimBlock.y, 1);

    // warmup
    transformKernel<<< dimGrid, dimBlock, 0 >>>( d_data, width, height, angle);

    cutilSafeCall( cudaThreadSynchronize() );
    unsigned int timer = 0;
    cutilCheckError( cutCreateTimer( &timer));
    cutilCheckError( cutStartTimer( timer));

    // execute the kernel
    transformKernel<<< dimGrid, dimBlock, 0 >>>( d_data, width, height, angle);

    // check if kernel execution generated an error
    cutilCheckMsg("Kernel execution failed");

    cutilSafeCall( cudaThreadSynchronize() );
    cutilCheckError( cutStopTimer( timer));
    printf("Processing time: %f (ms)\n", cutGetTimerValue( timer));
    printf("%.2f Mpixels/sec\n", (width*height / (cutGetTimerValue( timer) / 1000.0f)) / 1e6);
    cutilCheckError( cutDeleteTimer( timer));

    // allocate mem for the result on host side
    float* h_odata = (float*) malloc( size);
    // copy result from device to host
    cutilSafeCall( cudaMemcpy( h_odata, d_data, size, cudaMemcpyDeviceToHost) );

    // write result to file
    char output_filename[1024];
    strcpy(output_filename, image_path);
    strcpy(output_filename + strlen(image_path) - 4, "_out.pgm");
    cutilCheckError( cutSavePGMf( output_filename, h_odata, width, height));
    printf("Wrote '%s'\n", output_filename);

    // write regression file if necessary
    if( cutCheckCmdLineFlag( argc, (const char**) argv, "regression"))
    {
        // write file for regression test
        cutilCheckError( cutWriteFilef( "./data/regression.dat", h_odata, width*height, 0.0));
    } 
    else 
    {
        // We need to reload the data from disk, because it is inverted upon output
        cutilCheckError( cutLoadPGMf(output_filename, &h_odata, &width, &height));

        printf("Comparing files\n");
        printf("\toutput:    <%s>\n", output_filename);
        printf("\treference: <%s>\n", ref_path);
        CUTBoolean res = cutComparefe( h_odata, h_data_ref, width*height, MIN_EPSILON_ERROR );
        printf( "%s\n", (1 == res) ? "PASSED" : "FAILED");
    }

    // cleanup memory
//    free(h_data);
//    free(h_data_ref);
//    free(h_odata);

    cutilSafeCall(cudaFree(d_data));
    cutilSafeCall(cudaFreeArray(cu_array));
    cutFree(image_path);
    cutFree(ref_path);

    // If we are doing the QAtest, we quite without prompting
    if( cutCheckCmdLineFlag( argc, (const char**) argv, "qatest") ||
        cutCheckCmdLineFlag( argc, (const char**) argv, "noprompt"))
    {
        cudaThreadExit();
        exit(0);
    }

    cudaThreadExit();
}
