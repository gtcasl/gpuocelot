/*
 * Copyright 1993-2007 NVIDIA Corporation.  All rights reserved.
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
 * that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
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

* Device Code.
*/

#ifndef _DWTHAAR1D_KERNEL_H_
#define _DWTHAAR1D_KERNEL_H_

////////////////////////////////////////////////////////////////////////////////
//! Compute partial wavelet decomposition on the GPU using Haar basis
//! For each thread block the full decomposition is computed but these results 
//! have to be combined
//! Use one thread to perform the full decomposition
//! @param id  input data 
//! @param od  output data
//! @param approx_final  place to store the final approximation coefficient for
//!                      the subsignal
//! @param dlevels  number of decomposition levels for this transform
//! @param slength_step_half   half signal length for current decomposition 
//!                            level (offset for storing detail coefficients in
//!                            global memory
//! @param bdim  block dimension
////////////////////////////////////////////////////////////////////////////////
__global__ void 
dwtHaar1D( float* id, float* od, float* approx_final, 
          const unsigned int dlevels,
          const unsigned int slength_step_half,
          const int bdim ) 
{ 
    // shared memory for part of the signal
    extern __shared__ float shared[];  

    // thread runtime environment, 1D parametrization
    const int gdim = gridDim.x;
    // const int bdim = blockDim.x;
    const int bid = blockIdx.x;
    const int tid = threadIdx.x;  

    // global thread id (w.r.t. to total data set)
    const int tid_global = (bid * bdim) + tid;    
    unsigned int idata = (bid * (2 * bdim)) + tid;

    // read data from global memory
    shared[tid] = id[idata];
    shared[tid + bdim] = id[idata + bdim];
    __syncthreads();

    // this operation has a two way bank conflicts for all threads, this are two
    // additional cycles for each warp -- all alternatives to avoid this bank
    // conflict are more expensive than the one cycle introduced by serialization
    float data0 = shared[2*tid];
    float data1 = shared[(2*tid) + 1];
    __syncthreads();

    // detail coefficient, not further referenced so directly store in
    // global memory
    od[tid_global + slength_step_half] = (data0 - data1) * INV_SQRT_2;

    // offset to avoid bank conflicts
    // see the scan example for a more detailed description
    unsigned int atid = tid + (tid >> LOG_NUM_BANKS);

    // approximation coefficient
    // store in shared memory for further decomposition steps in this global step
    shared[atid] = (data0 + data1) * INV_SQRT_2;

    // all threads have to write approximation coefficient to shared memory before 
    // next steps can take place
    __syncthreads();

    // early out if possible
    // the compiler removes this part from the source because dlevels is 
    // a constant shader input
    // note: syncthreads in bodies of branches can lead to dead-locks unless the
    // the condition evaluates the same way for ALL threads of a block, as in 
    // this case
    if( dlevels > 1) 
    {
        // offset to second element in shared element which has to be used for the 
        // decomposition, effectively 2^(i - 1)
        unsigned int offset_neighbor = 1;
        // number of active threads per decomposition level
        // identiacal to the offset for the detail coefficients
        unsigned int num_threads = bdim >> 1;

        // index for the first element of the pair to process
        // the representation is still compact (and therefore still tid * 2) 
        // because the first step operated on registers and only the result has been
        // written to shared memory
        unsigned int idata0 = tid * 2;

        // offset levels to make the loop more efficient
        for( unsigned int i = 1; i < dlevels; ++i) 
        {
            // Non-coalesced writes occur if the number of active threads becomes 
            // less than 16 for a block because the start address for the first 
            // block is not always aligned with 64 byte which is necessary for 
            // coalesced access. However, the problem only occurs at high levels 
            // with only a small number of active threads so that the total number of 
            // non-coalesced access is rather small and does not justify the 
            // computations which are necessary to avoid these uncoalesced writes
            // (this has been tested and verified)
            if( tid < num_threads) 
            {
                // update stride, with each decomposition level the stride grows by a 
                // factor of 2
                unsigned int idata1 = idata0 + offset_neighbor;

                // position of write into global memory
                unsigned int g_wpos = (num_threads * gdim) + (bid * num_threads) + tid;

                // compute wavelet decomposition step

                // offset to avoid bank conflicts
                unsigned int c_idata0 = idata0 + (idata0 >> LOG_NUM_BANKS);
                unsigned int c_idata1 = idata1 + (idata1 >> LOG_NUM_BANKS);

                // detail coefficient, not further modified so directly store 
                // in global memory
                od[g_wpos] = (shared[c_idata0] - shared[c_idata1]) * INV_SQRT_2;

                // approximation coefficient
                // note that the representation in shared memory becomes rather sparse 
                // (with a lot of holes inbetween) but the storing scheme in global 
                // memory guarantees that the common representation (approx, detail_0, 
                // detail_1, ...)
                // is achieved
                shared[c_idata0] = (shared[c_idata0] + shared[c_idata1]) * INV_SQRT_2;

                // update storage offset for details
                num_threads = num_threads >> 1;   // div 2
                offset_neighbor <<= 1;   // mul 2 
                idata0 = idata0 << 1;   // mul 2     
            }

            // sync after each decomposition step
            __syncthreads();
        }

        // write the top most level element for the next decomposition steps
        // which are performed after an interblock syncronization on host side
        if( 0 == tid) 
        {
            approx_final[bid] = shared[0];
        }

    } // end early out if possible
}

#endif // #ifndef _DWTHAAR1D_KERNEL_H_
