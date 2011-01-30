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
 
#ifndef   __RADIXSORT_H__
#define   __RADIXSORT_H__

// -----------------------------------------------------------------------
// Fast CUDA Radix Sort Class
//
// The parallel radix sort algorithm implemented by this code is described
// in the following paper.
//
// Satish, N., Harris, M., and Garland, M. "Designing Efficient Sorting 
// Algorithms for Manycore GPUs". In Proceedings of IEEE International
// Parallel & Distributed Processing Symposium 2009 (IPDPS 2009).
//
// -----------------------------------------------------------------------

#include "cuda_runtime_api.h"
#include "cudpp/cudpp.h"

namespace nvRadixSort
{

void checkCudaError(const char *msg);
void initDeviceParameters(bool keysOnly);

void radixSort(unsigned int *keys, 
               unsigned int *values, 
               unsigned int *tempKeys, 
               unsigned int *tempValues,
               unsigned int *counters,
               unsigned int *countersSum,
               unsigned int *blockOffsets,
               CUDPPHandle scanPlan,
               unsigned int numElements, 
               unsigned int keyBits,
               bool         flipBits);

void radixSortFloatKeys(float        *keys, 
                        unsigned int *values, 
                        float        *tempKeys, 
                        unsigned int *tempValues,
                        unsigned int *counters,
                        unsigned int *countersSum,
                        unsigned int *blockOffsets,
                        CUDPPHandle  scanPlan,
                        unsigned int numElements, 
                        unsigned int keyBits,
                        bool         negativeKeys);

void radixSortKeysOnly(unsigned int *keys, 
                       unsigned int *tempKeys, 
                       unsigned int *counters,
                       unsigned int *countersSum,
                       unsigned int *blockOffsets,
                       CUDPPHandle scanPlan,
                       unsigned int numElements, 
                       unsigned int keyBits,
                       bool         flipBits);

void radixSortFloatKeysOnly(float        *keys, 
                            float        *tempKeys, 
                            unsigned int *counters,
                            unsigned int *countersSum,
                            unsigned int *blockOffsets,
                            CUDPPHandle  scanPlan,
                            unsigned int numElements, 
                            unsigned int keyBits,
                            bool         negativeKeys);

//-----------------------------------------------------------------------------
// CUDA Radix Sort class 
//
// This class can be used to sort arrays of keys and values (or only keys) 
// keys and values are both 32-bits in length, though the keyBits argument
// can be used to sort by only the keyBits least significant bits. Values
// are unsigned integers (common case is assumed to be pointers or array indices).
// 
// Use the RadixSort class from host code.  The constructor takes the maximum 
// number of elements, M, to be sorted, and a boolean flag for whether the sort 
// is only on keys or on key-value pairs (the default). Invoke the sort on an 
// array of N <= M elements by calling sort(), passing:
//  a.) CUDA device pointers to an array of N keys and an (optional) array of 
//      N values,
//  b.) The number of elements N to sort, and 
//  c.) The number of bits to sort in the keys (must be a multiple of 4 bits). 
//
// Note there are two sort() functions: one for unsigned integer keys and one
// for float keys
//
// initialize() (called by the constructor) allocates temporary storage for the 
// sort and the prefix sum that it uses.  Temporary storage is 
// (2*M + 3*8*M/CTA_SIZE) unsigned ints, with a default CTA_SIZE of 256 threads.  
// So for example, sorting 128K key/value pairs (1MB) requires 1MB+48KB of 
// temporary storage, in addition to the 1MB for the original arrays.
//
// Depends on CUDPP library: http://www.gpgpu.org/developer/cudpp
// (A pre-compiled CUDPP.lib is included with the NVIDIA CUDA SDK
// 
//-----------------------------------------------------------------------------
class RadixSort
{
public: // methods
    
    //------------------------------------------------------------------------
    // Constructor
    // @param maxElements   Maximum number of elements to be sorted. 
    // @param keysOnly true if only keys are to be sorted, false if keys and values
    //                      
    // Allocates maxElements * (2 + 3*8/CTA_SIZE) unsigned ints of temp storage.
    //------------------------------------------------------------------------
    RadixSort(unsigned int maxElements, bool keysOnly = false)
      : mScanPlan(0),
        mNumElements(0),
        mTempKeys(0),
        mTempValues(0),
        mCounters(0),
        mCountersSum(0),
        mBlockOffsets(0)
    {
        // Allocate temporary storage
        initialize(maxElements, keysOnly);
    }

    //------------------------------------------------------------------------
    // Destructor
    //------------------------------------------------------------------------
    ~RadixSort()
    {
        finalize();
    }
    
    //------------------------------------------------------------------------
    // Sorts input arrays of unsigned integer keys and (optional) values
    // 
    // @param keys        Array of keys for data to be sorted
    // @param values      Array of values to be sorted
    // @param numElements Number of elements to be sorted.  Must be <= 
    //                    maxElements passed to the constructor
    // @param keyBits     The number of bits in each key to use for ordering
    //------------------------------------------------------------------------
    void sort(unsigned int *keys, 
              unsigned int *values, 
              unsigned int  numElements,
              unsigned int  keyBits)
    {
        if (values == 0)
        {
            radixSortKeysOnly(keys, mTempKeys, 
                              mCounters, mCountersSum, mBlockOffsets,
                              mScanPlan, numElements, keyBits, false);
        }
        else
        {
            radixSort(keys, values, mTempKeys, mTempValues,
                      mCounters, mCountersSum, mBlockOffsets,
                      mScanPlan, numElements, keyBits, false);
        }
    }

    //------------------------------------------------------------------------
    // Sorts input arrays of float keys and (optional) unsigned integer values
    // 
    // @param keys         Array of keys for data to be sorted
    // @param values       Array of values to be sorted
    // @param numElements  Number of elements to be sorted.  Must be <= 
    //                     maxElements passed to the constructor
    // @param keyBits      The number of bits in each key to use for ordering
    // @param negativeKeys False if unsigned float keys, true if signed
    //------------------------------------------------------------------------
    void sort(float        *keys, 
              unsigned int *values, 
              unsigned int  numElements,
              unsigned int  keyBits,
              bool          negativeKeys)
    {
        if (values == 0)
        {
            radixSortFloatKeysOnly(keys, (float*)mTempKeys, 
                                   mCounters, mCountersSum, mBlockOffsets,
                                   mScanPlan, numElements, keyBits, negativeKeys);
        }
        else
        {
            radixSortFloatKeys(keys, values, (float*)mTempKeys, mTempValues,
                               mCounters, mCountersSum, mBlockOffsets,
                               mScanPlan, numElements, keyBits, negativeKeys);
        }
    }

public: // constants
    static const unsigned int CTA_SIZE = 256; // Number of threads per block
    static const unsigned int WARP_SIZE = 32;
    
    // These are static so that extern "C" functions in the .cu file can access them
    /*static unsigned int numCTAs[SORT_KERNEL_COUNT];
    static unsigned int persistentCTAThreshold[2];
    static unsigned int persistentCTAThresholdFullBlocks[2];*/

protected: // data
   
    CUDPPHandle   mScanPlan;        // CUDPP plan handle for prefix sum
    
    unsigned int  mNumElements;     // Number of elements of temp storage allocated
    unsigned int *mTempKeys;        // Intermediate storage for keys
    unsigned int *mTempValues;      // Intermediate storage for values
    unsigned int *mCounters;        // Counter for each radix
    unsigned int *mCountersSum;     // Prefix sum of radix counters
    unsigned int *mBlockOffsets;    // Global offsets of each radix in each block

protected: // methods

    //------------------------------------------------------------------------
    // Initialization.  Allocates temporary storage and CUDPP scan plan.
    // @param numElements   Maximum number of elements to be sorted. 
    //                      
    // Allocates numElements * (2 + 3*8/CTA_SIZE) unsigned ints of temp storage.
    // Note, the scan plan allocates an additional (numElements * 8/CTA_SIZE)/512
    // elements of temp storage, but for a 1M element array to be sorted, this 
    // amounts to only 256 bytes extra.
    //------------------------------------------------------------------------
    void initialize(unsigned int numElements, bool keysOnly)
    {
        // initialize parameters based on present CUDA device
        initDeviceParameters(keysOnly);

        // Allocate temporary storage
        mNumElements = numElements;

        unsigned int numBlocks = ((numElements % (CTA_SIZE * 4)) == 0) ? 
            (numElements / (CTA_SIZE * 4)) : (numElements / (CTA_SIZE * 4) + 1);
        unsigned int numBlocks2 = ((numElements % (CTA_SIZE * 2)) == 0) ?
            (numElements / (CTA_SIZE * 2)) : (numElements / (CTA_SIZE * 2) + 1);

        // Initialize scan
        CUDPPConfiguration scanConfig;
        scanConfig.algorithm = CUDPP_SCAN;
        scanConfig.datatype  = CUDPP_UINT;
        scanConfig.op        = CUDPP_ADD;
        scanConfig.options   = CUDPP_OPTION_EXCLUSIVE | CUDPP_OPTION_FORWARD;
        cudppPlan(&mScanPlan, scanConfig, 16 * numBlocks2, 1, 0);

        cudaMalloc((void **)&mTempKeys,     numElements * sizeof(unsigned int));
        if (!keysOnly)
            cudaMalloc((void **)&mTempValues,   numElements * sizeof(unsigned int));
        cudaMalloc((void **)&mCounters,     WARP_SIZE * numBlocks * sizeof(unsigned int));
        cudaMalloc((void **)&mCountersSum,  WARP_SIZE * numBlocks * sizeof(unsigned int));
        cudaMalloc((void **)&mBlockOffsets, WARP_SIZE * numBlocks * sizeof(unsigned int));

        checkCudaError("RadixSort::initialize()");
    }

    //------------------------------------------------------------------------
    // Deallocate all temporary storage and destroy CUDPP scan plan.
    //------------------------------------------------------------------------
    void finalize()
    {
        cudaFree(mTempKeys);
        cudaFree(mTempValues);
        cudaFree(mCounters);
        cudaFree(mCountersSum);
        cudaFree(mBlockOffsets);
        mCounters = mCountersSum = mBlockOffsets = 0;

        checkCudaError("RadixSort::finalize()");

        cudppDestroyPlan(mScanPlan);
    }
};

} // namespace nvRadixSort
#endif // __RADIXSORT_H__
