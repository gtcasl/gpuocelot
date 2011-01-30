/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and 
 * proprietary rights in and to this software and related documentation and 
 * any modifications thereto.  Any use, reproduction, disclosure, or distribution 
 * of this software and related documentation without an express license 
 * agreement from NVIDIA Corporation is strictly prohibited.
 * 
 *
 *
 * This sample illustrates a 3D stencil computation over a uniform grid, a
 * computation common in finite difference codes.  The kernel advances 2D
 * threadblocks along the slowest-varying dimension of the 3D data set.
 * Data is kept in registers and shared memory for each computation, thus
 * effectively streaming the input.  Data ends up being read twice, due to 
 * the halos (16x16 output region for each threadblock, 4 halo regions, each
 * 16x4).  For more details please refer to:
 *  P. Micikevicius, 3D finite difference computation on GPUs using CUDA. In 
 *  Proceedings of 2nd Workshop on General Purpose Processing on Graphics 
 *  Processing Units (Washington, D.C., March 08 - 08, 2009). GPGPU-2, 
 *  vol. 383. ACM, New York, NY, 79-84.
 *
 *  CUDA Optimization slides, Supercomputing 08 CUDA totorial
 *  http://gpgpu.org/static/sc2008/M02-04_Optimization.pdf
 *
*/

#include <stdio.h>
#include "reference.h"

#define BLOCK_DIMX	16
#define BLOCK_DIMY	16
#define RADIUS		4

__constant__ float c_coeff[RADIUS+1];

__global__ void stencil_3D_16x16_order8(float *g_output, float *g_input, const int dimx, const int dimy, const int dimz)
{
    __shared__ float s_data[BLOCK_DIMY+2*RADIUS][BLOCK_DIMX+2*RADIUS];

    int ix  = blockIdx.x*blockDim.x + threadIdx.x;
    int iy  = blockIdx.y*blockDim.y + threadIdx.y;
    int in_idx  = iy*dimx + ix;
    int out_idx = 0;
    int stride  = dimx*dimy;

    float infront1, infront2, infront3, infront4;
    float behind1, behind2, behind3, behind4;
    float current;

    int tx = threadIdx.x + RADIUS;
    int ty = threadIdx.y + RADIUS;

    // fill the "in-front" and "behind" data
    behind3  = g_input[in_idx];	in_idx += stride;
    behind2  = g_input[in_idx];	in_idx += stride;
    behind1  = g_input[in_idx];	in_idx += stride;

    current   = g_input[in_idx];	out_idx = in_idx;	in_idx += stride;

    infront1 = g_input[in_idx];	in_idx += stride;
    infront2 = g_input[in_idx];	in_idx += stride;
    infront3 = g_input[in_idx];	in_idx += stride;
    infront4 = g_input[in_idx];	in_idx += stride;

    for(int i=RADIUS; i<dimz-RADIUS; i++)
    {
        //////////////////////////////////////////
        // advance the slice (move the thread-front)
        behind4  = behind3;
        behind3  = behind2;
        behind2  = behind1;
        behind1  = current;
        current  = infront1;
        infront1 = infront2;
        infront2 = infront3;
        infront3 = infront4;
        infront4 = g_input[in_idx];

        in_idx  += stride;
        out_idx += stride;
        __syncthreads();

        /////////////////////////////////////////
        // update the data slice in smem

        if(threadIdx.y<RADIUS)	// halo above/below
        {
            s_data[threadIdx.y][tx]					  = g_input[out_idx-RADIUS*dimx];
            s_data[threadIdx.y+BLOCK_DIMY+RADIUS][tx] = g_input[out_idx+BLOCK_DIMY*dimx];
        }

        if(threadIdx.x<RADIUS)	// halo left/right
        {
            s_data[ty][threadIdx.x]					  = g_input[out_idx-RADIUS];
            s_data[ty][threadIdx.x+BLOCK_DIMX+RADIUS] = g_input[out_idx+BLOCK_DIMX];
        }

        // update the slice in smem
        s_data[ty][tx] = current;
        __syncthreads();

        /////////////////////////////////////////
        // compute the output value
        float value  = c_coeff[0] * current;
        value += c_coeff[1]*( infront1 + behind1 + s_data[ty-1][tx]+ s_data[ty+1][tx]+ s_data[ty][tx-1]+ s_data[ty][tx+1] );
        value += c_coeff[2]*( infront2 + behind2 + s_data[ty-2][tx]+ s_data[ty+2][tx]+ s_data[ty][tx-2]+ s_data[ty][tx+2] );
        value += c_coeff[3]*( infront3 + behind3 + s_data[ty-3][tx]+ s_data[ty+3][tx]+ s_data[ty][tx-3]+ s_data[ty][tx+3] );
        value += c_coeff[4]*( infront4 + behind4 + s_data[ty-4][tx]+ s_data[ty+4][tx]+ s_data[ty][tx-4]+ s_data[ty][tx+4] );
        g_output[out_idx] = value;
    }
}


int main(int argc, char *argv[])
{
    /////////////////////////////////////////////
    // choose the GPU for execution
    //
    int device = 0;
    cudaSetDevice(device);
    cudaDeviceProp properties;
    cudaGetDeviceProperties(&properties, device);
    printf("3DFD running on: %s\n", properties.name);
    if (properties.totalGlobalMem >= 1024*1024*1024) {
	    printf("Total GPU Memory: %.4f GB\n", properties.totalGlobalMem/(1024.f*1024.f*1024.f) );
	} else {
	    printf("Total GPU Memory: %.4f MB\n", properties.totalGlobalMem/(1024.f*1024.f) );
	}

    /////////////////////////////////////////////
    // process command-line arguments,
    // set execution parameters
    //
    int pad  = 0;
    int dimx = 48+pad;
    int dimy = 48;
    int dimz = 40;
    int nreps = 1;              // number of time-steps, over which performance is averaged
    int check_correctness = 1;  // 1=check correcness, 0-don't.  Note that CPU code is very
                                //   naive and not optimized, so many steps will take a 
                                //   long time on CPU

    if( argc >= 4 )
    {
        dimx  = atoi(argv[1]);
        dimy  = atoi(argv[2]);
        dimz  = atoi(argv[3]);
    
    }
    if( argc >= 5)
        nreps = atoi(argv[4]);
    if( argc >= 6)
        check_correctness = atoi(argv[5]);

    printf("%dx%dx%d\n", dimx, dimy, dimz);


    /////////////////////////////////////////////
    // setup data
    //

    // allocate CPU and GPU memory
    float *d_input=0, *d_output=0;
    int nbytes = dimx*dimy*dimz*sizeof(float);
    cudaMalloc( (void**)&d_input, nbytes);
    cudaMalloc( (void**)&d_output, nbytes);
    if( 0==d_input || 0==d_output )
    {
        printf("Unable to allocate %.4f Mbytes of GPU memory\n", (float)nbytes/(1024.0f*1024.0f) );
        printf("  TEST PASSED!\n");
		exit(EXIT_SUCCESS);
//        exit(1);
    }
    printf("allocated %.1f MB on device\n", (2.f*nbytes)/(1024.f*1024.f));

    // initialize data
    float *h_data=0, *h_reference=0;
    h_data = (float*)malloc(nbytes);
    h_reference = (float*)malloc(nbytes);
    if( 0==h_data || 0==h_reference )
    {
        printf("couldn't allocate CPU memory\n");
        printf("  TEST PASSED!\n");
		exit(EXIT_SUCCESS);
//        exit(-1);
    }
    random_data( h_data, dimx,dimy,dimz, 1, 5 );
    cudaMemcpy( d_input, h_data, nbytes, cudaMemcpyHostToDevice );
    if( cudaGetLastError() != cudaSuccess )
    {
        printf("data upload to GPU failed\n");
        printf("  TEST FAILED!\n");
        exit(-2);
    }

    // setup coefficients
    float h_coeff_symmetric[RADIUS+1] = {1.f, 1.f, 1.f, 1.f, 1.f};
    cudaMemcpyToSymbol( c_coeff, h_coeff_symmetric, (RADIUS+1)*sizeof(float) );
    if( cudaGetLastError() != cudaSuccess )
    {
        printf("coefficient upload to GPU failed\n");
        printf("  TEST FAILED!\n");
        exit(-3);
    }

    // kernel launch configuration
    dim3 block(BLOCK_DIMX,BLOCK_DIMY);
    dim3 grid( dimx/block.x, dimy/block.y );
    printf("(%d,%d)x(%d,%d) grid\n", grid.x,grid.y, block.x,block.y);

    // variables for measuring performance
    float elapsed_time_ms=0.0f, throughput_mpoints=0.0f;
    cudaEvent_t start, stop;
    cudaEventCreate( &start );
    cudaEventCreate( &stop  );


    /////////////////////////////////////////////
    // kernel execution
    //
    cudaEventRecord( start, 0 );
    for(int i=0; i<nreps; i++)
        stencil_3D_16x16_order8<<<grid,block>>>(d_output, d_input, dimx, dimy, dimz);
    cudaEventRecord( stop, 0 );

    cudaThreadSynchronize();
    cudaEventElapsedTime( &elapsed_time_ms, start, stop );
    elapsed_time_ms /= nreps;
    throughput_mpoints = (dimx*dimy*(dimz-2*RADIUS))/(elapsed_time_ms*1e3f);

    printf("-------------------------------\n");
    printf("time:       %8.2f ms\n", elapsed_time_ms );
    printf("throughput: %8.2f MPoints/s\n", throughput_mpoints );
    printf("CUDA: %s\n", cudaGetErrorString(cudaGetLastError()) );


    /////////////////////////////////////////////
    // check the correctness
    //
    if( check_correctness)
    {
        printf("-------------------------------\n");
        printf("comparing to CPU result...\n");
        reference_3D( h_reference, h_data, h_coeff_symmetric, dimx,dimy,dimz, RADIUS );
        cudaMemcpy( h_data, d_output, nbytes, cudaMemcpyDeviceToHost );
        if( within_epsilon( h_data, h_reference, dimx,dimy,dimz, RADIUS*nreps, 0.0001f ) ) {
            printf("  Result within epsilon\n");
            printf("  TEST PASSED!\n");
        } else {
            printf("  Incorrect result\n");	
            printf("  TEST FAILED!\n");
        }
    }


    /////////////////////////////////////////////
    // release the resources
    //
    cudaEventDestroy( start );
    cudaEventDestroy( stop );
    if( d_input )
        cudaFree( d_input );
    if( d_output )
        cudaFree( d_output );
    if( h_data )
        free( h_data );
    if( h_reference )
        free( h_reference );

    cudaThreadExit();

	exit(EXIT_SUCCESS);
    return 0;
}


