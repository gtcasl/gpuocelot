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
* 1D DWT for Haar wavelet and signals with a length which is a power of 2.
* The code reduces bank conflicts and non-coalesced reads / writes as 
* appropriate but does not fully remove them because the computational 
* overhead to achieve this would outweighs the benefit (see inline comments
* for more details).
* Large signals are subdivided into sub-signals with 512 elements and the 
* wavelet transform for these is computed with one block over 10 decomposition 
* levels. The resulting signal consisting of the approximation coefficients at
* level X is then processed in a subsequent step on the device. This requires 
* interblock syncronization which is only possible on host side.
* Detail coefficients which have been computed are not further referenced 
* during the decomposition so that they can be stored directly in their final  
* position in global memory. The transform and its storing scheme preserve  
* locality in the coefficients so that these writes are coalesced. 
* Approximation coefficients are stored in shared memory because they are 
* needed to compute the subsequent decomposition step. The top most 
* approximation coefficient for a sub-signal processed by one block is stored 
* in a special global memory location to simplify the processing after the 
* interblock synchronization. 
* Most books on wavelets explain the Haar wavelet decompositon. A good freely
* available resource is the Wavelet primer by Stollnitz et al.
* http://grail.cs.washington.edu/projects/wavelets/article/wavelet1.pdf
* http://grail.cs.washington.edu/projects/wavelets/article/wavelet2.pdf
* The basic of all Wavelet transforms is to decompose a signal into 
* approximation (a) and detail (d) coefficients where the detail tends to be 
* small or zero which allows / simplifies compression. The following "graphs" 
* demonstrate the transform for a signal
* of length eight. The index always describes the decomposition level where
* a coefficient arises. The input signal is interpreted as approximation signal
* at level 0. The coefficients computed on the device are stored in the same 
* scheme as in the example. This data strucure is particularly well suited for 
* compression and also preserves the hierachical strucure of the decomposition.

-------------------------------------------------
| a_0 | a_0 | a_0 | a_0 | a_0 | a_0 | a_0 | a_0 |
-------------------------------------------------

-------------------------------------------------
| a_1 | a_1 | a_1 | a_1 | d_1 | d_1 | d_1 | d_1 |
-------------------------------------------------

-------------------------------------------------
| a_2 | a_2 | d_2 | d_2 | d_1 | d_1 | d_1 | d_1 |
-------------------------------------------------

-------------------------------------------------
| a_3 | d_3 | d_2 | d_2 | d_1 | d_1 | d_1 | d_1 |
-------------------------------------------------

* Host code.
*/

#ifdef _WIN32
#  define NOMINMAX 
#endif

// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// includes, project
//#include <cutil_inline.h>
#include <cutil_inline.h>

// constants which are used in host and device code
#define             INV_SQRT_2      0.70710678118654752440f;
const unsigned int  LOG_NUM_BANKS = 4;
const unsigned int  NUM_BANKS     = 16;

////////////////////////////////////////////////////////////////////////////////
// includes, kernels
#include <dwtHaar1D_kernel.cu>

////////////////////////////////////////////////////////////////////////////////
// declaration, forward
void runTest( int argc, char** argv);
CUTBoolean  getLevels( unsigned int len, unsigned int* levels);

////////////////////////////////////////////////////////////////////////////////
// Program main
////////////////////////////////////////////////////////////////////////////////
int 
main( int argc, char** argv) 
{
    // run test
    runTest( argc, argv);

    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Perform the wavelet decomposition
////////////////////////////////////////////////////////////////////////////////
void
runTest( int argc, char** argv) 
{
    char* s_fname;
    char* r_fname;
    char* r_gold_fname;
    const char usage[] = 
    {
        "\nUsage:\n"
        "  dwtHaar1D --signal=<signal_file> --result=<result_file> --gold=<gold_file>\n\n"
        "  <signal_file> Input file containing the signal\n"
        "  <result_file> Output file storing the result of the wavelet decomposition\n"
        "  <gold_file>   Input file containing the reference result of the wavelet decomposition\n"
        "\nExample:\n"
        "  bin\\win32\\release\\dwtHaar1D\n"
        "       --signal=projects\\dwtHaar1D\\data\\signal.dat\n"
        "       --result=projects\\dwtHaar1D\\data\\regression.dat\n"
        "       --gold=projects\\dwtHaar1D\\data\\regression.gold.dat\n"
    };

    // use command-line specified CUDA device, otherwise use device with highest Gflops/s
    if( cutCheckCmdLineFlag(argc, (const char**)argv, "device") )
        cutilDeviceInit(argc, argv);
    else
        cudaSetDevice( cutGetMaxGflopsDeviceId() );

    // file names, either specified as cmd line args or use default
    if( argc == 4) 
    {
        if ((cutGetCmdLineArgumentstr(argc, (const char**)argv, "signal", &s_fname) != CUTTrue) ||
            (cutGetCmdLineArgumentstr(argc, (const char**)argv, "result", &r_fname) != CUTTrue) ||
            (cutGetCmdLineArgumentstr(argc, (const char**)argv, "gold", &r_gold_fname) != CUTTrue)) 
        {
            fprintf(stderr, "Invalid input syntax.\n%s", usage);
            cudaThreadExit();
            exit(1);
        }
    }
    else 
    {
        s_fname = cutFindFilePath("signal.dat", argv[0]);
        r_fname = cutFindFilePath("regression.dat", argv[0]);
        r_gold_fname = cutFindFilePath("regression.gold.dat", argv[0]);
    }

    // read in signal
    unsigned int slength = 0;
    float* signal = NULL;
    if (s_fname == 0)
    {
        fprintf(stderr, "Cannot find the file containing the signal.\n%s", usage);
        cudaThreadExit();
        exit(1);
    }
    if (cutReadFilef( s_fname, &signal, &slength) == CUTTrue) {
        printf("Reading signal from %s\n", s_fname);
    } else {
        cudaThreadExit();
        exit(1);
    }

    // get the number of decompositions necessary to perform a full decomposition
    unsigned int dlevels_complete = 0;
    if( CUTTrue != getLevels( slength, &dlevels_complete)) 
    {
        // error message
        fprintf( stderr, "Signal length not supported.\n");
        // cleanup and abort
        cutFree( signal);
        return;
    }

    // device in data
    float* d_idata = NULL;
    // device out data
    float* d_odata = NULL;
    // device approx_final data
    float* approx_final = NULL;
    // The very final approximation coefficient has to be written to the output
    // data, all others are reused as input data in the next global step and 
    // therefore have to be written to the input data again.
    // The following flag indicates where to copy approx_final data
    //   - 0 is input, 1 is output
    int approx_is_input;

    // allocate device mem
    const unsigned int smem_size = sizeof(float) * slength;
    cutilSafeCall( cudaMalloc( (void**) &d_idata, smem_size));
    cutilSafeCall( cudaMalloc( (void**) &d_odata, smem_size));
    cutilSafeCall( cudaMalloc( (void**) &approx_final, smem_size));
    // copy input data to device
    cutilSafeCall( cudaMemcpy( d_idata, signal, smem_size, 
        cudaMemcpyHostToDevice) ); 

    // clear result memory
    float* tmp = (float*) malloc( smem_size);
    for( unsigned int i = 0; i < slength; ++i) 
    {
        tmp[i] = 0.0;
    }
    cutilSafeCall( cudaMemcpy( d_odata, tmp, smem_size, 
                                cudaMemcpyHostToDevice) ); 
    free( tmp);

    // total number of threads
    // in the first decomposition step always one thread computes the average and
    // detail signal for one pair of adjacent values
    unsigned int num_threads_total_left = slength / 2;
    // decomposition levels performed in the current / next step
    unsigned int  dlevels_step = dlevels_complete;

    // 1D signal so the arrangement of elements is also 1D
    dim3  block_size;
    dim3  grid_size;  

    // number of decomposition levels left after one iteration on the device
    unsigned int dlevels_left = dlevels_complete;

    // if less or equal 1k elements, then the data can be processed in one block,
    // this avoids the Wait-For-Idle (WFI) on host side which is necessary if the 
    // computation is split accross multiple SM's if enough input data
    if( dlevels_complete <= 10) 
    {
        // decomposition can be performed at once
        block_size.x = num_threads_total_left;   
        approx_is_input = 0;
}
    else 
    {
        // 512 threads per block
        grid_size.x = (num_threads_total_left / 512);
        block_size.x = 512;

        // 512 threads corresponds to 10 decomposition steps
        dlevels_step = 10;
        dlevels_left -= 10;

        approx_is_input = 1;
    }

    // do until full decomposition is accomplished
    while( 0 != num_threads_total_left) 
    {
        // double the number of threads as bytes
        unsigned int mem_shared = (2 * block_size.x) * sizeof( float);
        // extra memory requirements to avoid bank conflicts
        mem_shared += ((2 * block_size.x) / NUM_BANKS) * sizeof( float);

        // run kernel
        dwtHaar1D<<<grid_size, block_size, mem_shared >>>( d_idata, d_odata,
                                                           approx_final,
                                                           dlevels_step,
                                                           num_threads_total_left,
                                                           block_size.x );

	// Copy approx_final to appropriate location
        if (approx_is_input)
          {
            cutilSafeCall (cudaMemcpy (d_idata, approx_final, grid_size.x * 4,
                                        cudaMemcpyDeviceToDevice) );
          }
        else
          {
            cutilSafeCall (cudaMemcpy (d_odata, approx_final, grid_size.x * 4,
                                        cudaMemcpyDeviceToDevice) );
          }

        // update level variables
        if( dlevels_left < 10) 
          {
            // approx_final = d_odata;
            approx_is_input = 0;
          }

        // more global steps necessary
        dlevels_step = (dlevels_left > 10) ? dlevels_left - 10 : dlevels_left;
        dlevels_left -= 10;

        // after each step only half the threads are used any longer
        // therefore after 10 steps 2^10 less threads
        num_threads_total_left = num_threads_total_left >> 10;

        // update block and grid size
        grid_size.x = (num_threads_total_left / 512) 
                       + (0 != (num_threads_total_left % 512)) ? 1 : 0;
        if( grid_size.x <= 1) 
        {
            block_size.x = num_threads_total_left;
        }
    }

    // get the result back from the server
    // allocate mem for the result
    float* odata = (float*) malloc( smem_size);
    cutilSafeCall( cudaMemcpy( odata, d_odata, smem_size, 
                                cudaMemcpyDeviceToHost));

    // post processing
    if( cutCheckCmdLineFlag( argc, (const char**) argv, "regression")) 
    {
        // write file for regression test
        if (r_fname == 0) {
            fprintf(stderr, "Cannot write the output file storing the result of the wavelet decomposition.\n%s", usage);
            cudaThreadExit();
            exit(1);
        }
        if (cutWriteFilef( r_fname, odata, slength, 0.001f, false) == CUTTrue) 
            printf("Writing result to %s\n", r_fname);
        else {
            cudaThreadExit();
            exit(1);
        }
    }
    else 
    {
        // load the reference solution
        unsigned int len_reference = 0;
        float* reference = NULL;
        if (r_gold_fname == 0)
        {
            fprintf(stderr, "Cannot read the file containing the reference result of the wavelet decomposition.\n%s", usage);
            cudaThreadExit();
            exit(1);
        }
        if (cutReadFilef( r_gold_fname, &reference, &len_reference) == CUTTrue) 
            printf("Reading reference result from %s\n", r_gold_fname);
        else {
            cudaThreadExit();
            exit(1);
        }
        cutilCondition( slength == len_reference);

        // compare the computed solution and the reference
        CUTBoolean res = cutComparefe( reference, odata, slength, 0.001f);
        printf( "%s\n", (1 == res) ? "PASSED" : "FAILED");
        cutFree( reference);
    }

    // free allocated host and device memory
    cutilSafeCall(cudaFree(d_odata));
    cutilSafeCall(cudaFree(d_idata));
    cutilSafeCall(cudaFree(approx_final));

    cutFree( signal);
    free( odata);
    cutFree( s_fname); 
    cutFree( r_fname);  
    cutFree( r_gold_fname);   

    cudaThreadExit();

    cutilExit(argc, argv);
}

////////////////////////////////////////////////////////////////////////////////
//! Get number of decomposition levels to perform a full decomposition
//! Also check if the input signal size is suitable
//! @return  CUTTrue if the number of decomposition levels could be determined
//!          and the signal length is supported by the implementation,
//!          otherwise CUTFalse
//! @param   len  length of input signal
//! @param   levels  number of decomposition levels necessary to perform a full 
//!           decomposition
////////////////////////////////////////////////////////////////////////////////
CUTBoolean
getLevels( unsigned int len, unsigned int* levels) 
{
    CUTBoolean retval = CUTFalse;

    // currently signals up to a length of 2^20 supported
    for( unsigned int i = 0; i < 20; ++i) 
    {
        if( len == (1 << i)) 
        {
            *levels = i;
            retval = CUTTrue;
            break;
        }
    }

    return retval;
}
