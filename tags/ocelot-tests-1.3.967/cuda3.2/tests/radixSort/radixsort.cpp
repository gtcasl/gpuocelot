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
 
#include <map>
#include <cuda_runtime.h>
#include <assert.h>
#include <algorithm>
#include "radixsort.h"

namespace nvRadixSort
{

// Used for creating a mapping of kernel functions to the number of 
// CTAs to launch for each
typedef void* KernelPointer;
std::map<KernelPointer, int> numCTAsTable;

int getNumCTAs(KernelPointer kernel)
{
    return numCTAsTable[kernel];
}

void setNumCTAs(KernelPointer kernel, int numCTAs)
{
    numCTAsTable[kernel] = numCTAs;
}

// computes next highest multiple of f from x
inline size_t multiple(size_t x, size_t f)
{
    return ((x + (f-1)) / f);
}

// MS Excel-style CEIL() function
// Rounds x up to nearest multiple of f
inline size_t ceiling(size_t x, size_t f)
{
    return multiple(x, f) * f;
}

void computeNumCTAs(KernelPointer kernel, int smemDynamicBytes, bool bManualCoalesce)
{
    cudaDeviceProp devprop;
    int deviceID = -1;
    cudaError_t err = cudaGetDevice(&deviceID);
    assert(err == cudaSuccess);

    cudaGetDeviceProperties(&devprop, deviceID);

    int smVersion = devprop.major * 10 + devprop.minor;
    // Determine the maximum number of CTAs that can be run simultaneously for each kernel
    // This is equivalent to the calculation done in the CUDA Occupancy Calculator spreadsheet
    
    const unsigned int warpAllocationMultiple = 2;
    const unsigned int maxBlocksPerSM = 8;
    unsigned int maxThreadsPerSM = 768;
    unsigned int regAllocationUnit = 256;  // in registers
    unsigned int smemAllocationUnit = 512; // in bytes
    bool blockRegisterAllocation = true;   // otherwise warp granularity (sm_20)

    if (smVersion >= 20)
    {
        maxThreadsPerSM = 1536;
        regAllocationUnit = 64;
        blockRegisterAllocation = false;
        smemAllocationUnit = 128;
    }
    else if (smVersion >= 12)
    {
        maxThreadsPerSM = 1024;
        regAllocationUnit = 512;
    }
   
    cudaFuncAttributes attr;
    err = cudaFuncGetAttributes(&attr, (const char*)kernel);
    assert(err == cudaSuccess);

    // Number of warps (round up to nearest whole multiple of warp size)
    size_t numWarps = multiple(RadixSort::CTA_SIZE, devprop.warpSize);
    // Round up to warp allocation multiple
    numWarps = ceiling(numWarps, warpAllocationMultiple);

    size_t regsPerCTA = 0;

    if (blockRegisterAllocation)
    {
        // Number of regs is regs per thread times number of warps times warp size
        // rounded up to multiple of register allocation unit size
        regsPerCTA = ceiling(attr.numRegs * devprop.warpSize * numWarps, regAllocationUnit);
    }
    else
    {
        // warp register allocation
        // Number of regs is regs per thread times warp size, rounded up to multiple of 
        // register allocation unit size, times number of warps.
        regsPerCTA = ceiling(attr.numRegs * devprop.warpSize, regAllocationUnit) * numWarps;
    }

    size_t smemBytes = attr.sharedSizeBytes + smemDynamicBytes;
    size_t smemPerCTA = ceiling(smemBytes, smemAllocationUnit);

    size_t ctaLimitRegs    = regsPerCTA > 0 ? devprop.regsPerBlock           / regsPerCTA : maxBlocksPerSM;
    size_t ctaLimitSMem    = smemPerCTA > 0 ? devprop.sharedMemPerBlock      / smemPerCTA : maxBlocksPerSM;
    size_t ctaLimitThreads =                  maxThreadsPerSM                / RadixSort::CTA_SIZE;

    unsigned int numSMs = devprop.multiProcessorCount;
    int maxCTAs = numSMs * std::min<size_t>(ctaLimitRegs, std::min<size_t>(ctaLimitSMem, std::min<size_t>(ctaLimitThreads, maxBlocksPerSM)));
    setNumCTAs(kernel, maxCTAs);
}

} // namespace nvRadixSort

