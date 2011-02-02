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

/* Computation of eigenvalues of a large symmetric, tridiagonal matrix */

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

// includes, project
#include "cutil_inline.h"
#include "config.h"
#include "structs.h"
#include "util.h"
#include "matlab.h"

#include "bisect_large.cuh"

// includes, kernels
#include "bisect_kernel_large.cu"
#include "bisect_kernel_large_onei.cu"
#include "bisect_kernel_large_multi.cu"


////////////////////////////////////////////////////////////////////////////////
//! Initialize variables and memory for result
//! @param  result handles to memory
//! @param  matrix_size  size of the matrix
////////////////////////////////////////////////////////////////////////////////
void
initResultDataLargeMatrix( ResultDataLarge& result, const unsigned int mat_size) {

  // helper variables to initialize memory
    unsigned int zero = 0;
    unsigned int mat_size_f = sizeof(float) * mat_size;
    unsigned int mat_size_ui = sizeof(unsigned int) * mat_size;

    float* tempf = (float*) malloc( mat_size_f);
    unsigned int* tempui = (unsigned int*) malloc( mat_size_ui);
    for( unsigned int i = 0; i < mat_size; ++i) {
      tempf[i] = 0.0f;
      tempui[i] = 0;
    }

    // number of intervals containing only one eigenvalue after the first step
    cutilSafeCall( cudaMalloc( (void**) &result.g_num_one, 
                              sizeof( unsigned int)) );
    cutilSafeCall( cudaMemcpy( result.g_num_one, &zero, sizeof(unsigned int),
                              cudaMemcpyHostToDevice));

    // number of (thread) blocks of intervals with multiple eigenvalues after
    // the first iteration
    cutilSafeCall( cudaMalloc( (void**) &result.g_num_blocks_mult, 
                              sizeof(unsigned int)));
    cutilSafeCall( cudaMemcpy( result.g_num_blocks_mult, &zero, 
                              sizeof(unsigned int),
                              cudaMemcpyHostToDevice ));

    
    cutilSafeCall( cudaMalloc( (void**) &result.g_left_one, mat_size_f));
    cutilSafeCall( cudaMalloc( (void**) &result.g_right_one, mat_size_f));
    cutilSafeCall( cudaMalloc( (void**) &result.g_pos_one, mat_size_ui));

    cutilSafeCall( cudaMalloc( (void**) &result.g_left_mult, mat_size_f));
    cutilSafeCall( cudaMalloc( (void**) &result.g_right_mult, mat_size_f));
    cutilSafeCall( cudaMalloc( (void**) &result.g_left_count_mult,
                              mat_size_ui));
    cutilSafeCall( cudaMalloc( (void**) &result.g_right_count_mult,
                              mat_size_ui));

    cutilSafeCall( cudaMemcpy( result.g_left_one, tempf, mat_size_f,
                              cudaMemcpyHostToDevice));
    cutilSafeCall( cudaMemcpy( result.g_right_one, tempf, mat_size_f,
                              cudaMemcpyHostToDevice));
    cutilSafeCall( cudaMemcpy( result.g_pos_one, tempui, mat_size_ui,
                              cudaMemcpyHostToDevice));

    cutilSafeCall( cudaMemcpy( result.g_left_mult, tempf, mat_size_f,
                              cudaMemcpyHostToDevice));
    cutilSafeCall( cudaMemcpy( result.g_right_mult, tempf, mat_size_f,
                              cudaMemcpyHostToDevice));
    cutilSafeCall( cudaMemcpy( result.g_left_count_mult, tempui, mat_size_ui,
                              cudaMemcpyHostToDevice));
    cutilSafeCall( cudaMemcpy( result.g_right_count_mult, tempui, mat_size_ui,
                              cudaMemcpyHostToDevice));

    cutilSafeCall( cudaMalloc( (void**) &result.g_blocks_mult, mat_size_ui));
    cutilSafeCall( cudaMemcpy( result.g_blocks_mult, tempui, mat_size_ui,
                              cudaMemcpyHostToDevice ));
    cutilSafeCall(cudaMalloc((void**) &result.g_blocks_mult_sum, mat_size_ui));
    cutilSafeCall( cudaMemcpy( result.g_blocks_mult_sum, tempui, mat_size_ui,
                              cudaMemcpyHostToDevice ));

    cutilSafeCall( cudaMalloc( (void**) &result.g_lambda_mult, mat_size_f));
    cutilSafeCall( cudaMemcpy( result.g_lambda_mult, tempf, mat_size_f,
                              cudaMemcpyHostToDevice )); 
    cutilSafeCall( cudaMalloc( (void**) &result.g_pos_mult, mat_size_ui));
    cutilSafeCall( cudaMemcpy( result.g_pos_mult, tempf, mat_size_ui,
                              cudaMemcpyHostToDevice )); 
}
   
////////////////////////////////////////////////////////////////////////////////
//! Cleanup result memory
//! @param result  handles to memory
////////////////////////////////////////////////////////////////////////////////
void
cleanupResultDataLargeMatrix( ResultDataLarge& result) {

  cutilSafeCall( cudaFree( result.g_num_one));
  cutilSafeCall( cudaFree( result.g_num_blocks_mult));
  cutilSafeCall( cudaFree( result.g_left_one));
  cutilSafeCall( cudaFree( result.g_right_one));
  cutilSafeCall( cudaFree( result.g_pos_one));
  cutilSafeCall( cudaFree( result.g_left_mult));
  cutilSafeCall( cudaFree( result.g_right_mult));
  cutilSafeCall( cudaFree( result.g_left_count_mult));
  cutilSafeCall( cudaFree( result.g_right_count_mult));
  cutilSafeCall( cudaFree( result.g_blocks_mult));
  cutilSafeCall( cudaFree( result.g_blocks_mult_sum));
  cutilSafeCall( cudaFree( result.g_lambda_mult));
  cutilSafeCall( cudaFree( result.g_pos_mult));
}

////////////////////////////////////////////////////////////////////////////////
//! Run the kernels to compute the eigenvalues for large matrices
//! @param  input   handles to input data
//! @param  result  handles to result data 
//! @param  mat_size  matrix size
//! @param  precision  desired precision of eigenvalues
//! @param  lg  lower limit of Gerschgorin interval
//! @param  ug  upper limit of Gerschgorin interval
//! @param  iterations  number of iterations (for timing)
////////////////////////////////////////////////////////////////////////////////
void
computeEigenvaluesLargeMatrix( const InputData& input, const ResultDataLarge& result,
                               const unsigned int mat_size, const float precision,
                               const float lg, const float ug,
                               const unsigned int iterations )
{   
    dim3  blocks( 1, 1, 1);
    dim3  threads( MAX_THREADS_BLOCK, 1, 1);

    unsigned int timer_step1 = 0;
    unsigned int timer_step2_one = 0;
    unsigned int timer_step2_mult = 0;
    unsigned int timer_total = 0;
    cutilCheckError( cutCreateTimer( &timer_step1));
    cutilCheckError( cutCreateTimer( &timer_step2_one));
    cutilCheckError( cutCreateTimer( &timer_step2_mult));
    cutilCheckError( cutCreateTimer( &timer_total));

    cutilCheckError( cutStartTimer( timer_total));

    // do for multiple iterations to improve timing accuracy
    for( unsigned int iter = 0; iter < iterations; ++iter) {

      cutilCheckError( cutStartTimer( timer_step1));
      bisectKernelLarge<<< blocks, threads >>>
        ( input.g_a, input.g_b, mat_size,
          lg, ug, 0, mat_size, precision,
          result.g_num_one, result.g_num_blocks_mult,
          result.g_left_one, result.g_right_one, result.g_pos_one,
          result.g_left_mult, result.g_right_mult,
          result.g_left_count_mult, result.g_right_count_mult,
          result.g_blocks_mult, result.g_blocks_mult_sum
        );
      cutilSafeCall( cudaThreadSynchronize());
      cutilCheckError( cutStopTimer( timer_step1));
      cutilCheckMsg( "Kernel launch failed.");

      // get the number of intervals containing one eigenvalue after the first
      // processing step
      unsigned int num_one_intervals;
      cutilSafeCall( cudaMemcpy( &num_one_intervals, result.g_num_one, 
                                sizeof(unsigned int),
                                cudaMemcpyDeviceToHost));

      dim3 grid_onei;
      grid_onei.x = getNumBlocksLinear( num_one_intervals, MAX_THREADS_BLOCK);
      dim3 threads_onei;
      // use always max number of available threads to better balance load times
      // for matrix data
      threads_onei.x = MAX_THREADS_BLOCK;  

      // compute eigenvalues for intervals that contained only one eigenvalue 
      // after the first processing step
      cutilCheckError( cutStartTimer( timer_step2_one));

      bisectKernelLarge_OneIntervals<<< grid_onei , threads_onei >>>
          ( input.g_a, input.g_b, mat_size, num_one_intervals,
            result.g_left_one, result.g_right_one, result.g_pos_one,
            precision
          ); 

      cutilSafeCall( cudaThreadSynchronize());
      cutilCheckError( cutStopTimer( timer_step2_one));

      // process intervals that contained more than one eigenvalue after
      // the first processing step

      // get the number of blocks of intervals that contain, in total when
      // each interval contains only one eigenvalue, not more than 
      // MAX_THREADS_BLOCK threads
      unsigned int  num_blocks_mult = 0;
      cutilSafeCall( cudaMemcpy( &num_blocks_mult, result.g_num_blocks_mult,
                                sizeof( unsigned int),
                                cudaMemcpyDeviceToHost));

      // setup the execution environment
      dim3  grid_mult( num_blocks_mult, 1, 1);
      dim3  threads_mult( MAX_THREADS_BLOCK, 1, 1);

      cutilCheckError( cutStartTimer( timer_step2_mult));
      
      bisectKernelLarge_MultIntervals<<< grid_mult, threads_mult >>>
          ( input.g_a, input.g_b, mat_size,
            result.g_blocks_mult, result.g_blocks_mult_sum,
            result.g_left_mult, result.g_right_mult,
            result.g_left_count_mult, result.g_right_count_mult,
            result.g_lambda_mult, result.g_pos_mult,
            precision
          );

      cutilCheckError( cutStopTimer( timer_step2_mult));
      cutilCheckMsg( "bisectKernelLarge_MultIntervals() FAILED.");
    }

    cutilCheckError( cutStopTimer( timer_total));


    printf( "Average time step 1: %f ms\n", 
            cutGetTimerValue( timer_step1) / (float) iterations );
    printf( "Average time step 2, one intervals: %f ms\n", 
            cutGetTimerValue( timer_step2_one) / (float) iterations );
    printf( "Average time step 2, mult intervals: %f ms\n", 
            cutGetTimerValue( timer_step2_mult) / (float) iterations );

    printf( "Average time TOTAL: %f ms\n", 
            cutGetTimerValue( timer_total) / (float) iterations );

    cutilCheckError( cutDeleteTimer( timer_step1));
    cutilCheckError( cutDeleteTimer( timer_step2_one));
    cutilCheckError( cutDeleteTimer( timer_step2_mult));
    cutilCheckError( cutDeleteTimer( timer_total));
}

////////////////////////////////////////////////////////////////////////////////
//! Process the result, that is obtain result from device and do simple sanity
//! checking
//! @param  input   handles to input data
//! @param  result  handles to result data
//! @param  mat_size  matrix size
//! @param  filename  output filename
////////////////////////////////////////////////////////////////////////////////
void
processResultDataLargeMatrix( const InputData& input, const ResultDataLarge& result,
                              const unsigned int mat_size, 
                              const char* filename, 
                              const unsigned int user_defined, char* exec_path) 
{
  const unsigned int mat_size_ui = sizeof(unsigned int) * mat_size;
  const unsigned int mat_size_f  = sizeof(float) * mat_size;

  // copy data from intervals that contained more than one eigenvalue after
  // the first processing step
  float* lambda_mult = (float*) malloc( sizeof(float) * mat_size);
  cutilSafeCall( cudaMemcpy( lambda_mult, result.g_lambda_mult,
                            sizeof(float) * mat_size,
                            cudaMemcpyDeviceToHost ));
  unsigned int* pos_mult = 
      (unsigned int*) malloc( sizeof(unsigned int) * mat_size);
  cutilSafeCall( cudaMemcpy( pos_mult, result.g_pos_mult,
                            sizeof(unsigned int) * mat_size,
                            cudaMemcpyDeviceToHost ));

  unsigned int* blocks_mult_sum = 
    (unsigned int*) malloc( sizeof(unsigned int) * mat_size);
  cutilSafeCall( cudaMemcpy( blocks_mult_sum, result.g_blocks_mult_sum,
                            sizeof( unsigned int) * mat_size,
                            cudaMemcpyDeviceToHost ));

  unsigned int num_one_intervals;
  cutilSafeCall( cudaMemcpy( &num_one_intervals, result.g_num_one, 
                            sizeof(unsigned int),
                            cudaMemcpyDeviceToHost));

  unsigned int sum_blocks_mult = mat_size - num_one_intervals;


  // copy data for intervals that contained one eigenvalue after the first 
  // processing step
  float* left_one = (float*) malloc( mat_size_f);
  float* right_one = (float*) malloc( mat_size_f);
  unsigned int* pos_one = (unsigned int*) malloc( mat_size_ui);
  cutilSafeCall( cudaMemcpy( left_one, result.g_left_one, mat_size_f,
                            cudaMemcpyDeviceToHost) );
  cutilSafeCall( cudaMemcpy( right_one, result.g_right_one, mat_size_f,
                            cudaMemcpyDeviceToHost) );
  cutilSafeCall( cudaMemcpy( pos_one, result.g_pos_one, mat_size_ui,
                            cudaMemcpyDeviceToHost) );
 
  // extract eigenvalues
  float* eigenvals = (float*) malloc( mat_size_f);

  // singleton intervals generated in the second step
  for( unsigned int i = 0; i < sum_blocks_mult; ++i) {

    eigenvals[pos_mult[i] - 1] = lambda_mult[i];
  }

  // singleton intervals generated in the first step
  unsigned int index = 0;
  for( unsigned int i = 0; i < num_one_intervals; ++i, ++index) {

    eigenvals[pos_one[i] - 1] = left_one[i];
  }

  if( 1 == user_defined) {
    // store result
    writeTridiagSymMatlab( filename, input.a, input.b+1, eigenvals, mat_size);
    // cutilCheckError( cutWriteFilef( filename, eigenvals, mat_size, 0.0f));
  }
  else {
    
    // compare with reference solution

    float* reference = NULL;
    unsigned int input_data_size = 0;

    char* ref_path = cutFindFilePath( "reference.dat", exec_path);
    cutilCondition( 0 != ref_path);
    cutilCheckError( cutReadFilef( ref_path, &reference, &input_data_size));
    cutilCondition( input_data_size == mat_size);

    // there's an imprecision of Sturm count computation which makes an 
    // additional offset necessary
    float tolerance = 1.0e-5f + 5.0e-6f;

    if( CUTTrue == cutComparefe( reference, eigenvals, mat_size, tolerance)) {
      printf( "\nPASSED.\n");
    }
    else {
      printf( "FAILED.\n");
    }

    cutFree( ref_path);
    cutFree( reference);
  }

  freePtr( eigenvals);
  freePtr( lambda_mult);
  freePtr( pos_mult);
  freePtr( blocks_mult_sum); 
  freePtr( left_one); 
  freePtr( right_one); 
  freePtr( pos_one); 
}

