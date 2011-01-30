/*
 * Copyright 1993-2009 NVIDIA Corporation.  All rights reserved.
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

#if !defined(__DRIVER_TYPES_H__)
#define __DRIVER_TYPES_H__

/**
 * \file
 * \name Data types used by CUDA Runtime
 * \author NVIDIA Corporation
 * \brief Data types used by CUDA Runtime
 */
/**
 * \defgroup CUDART_TYPES Data types used by CUDA Runtime
 * \ingroup CUDART
 *
 * @{
 */

/*******************************************************************************
*                                                                              *
*  TYPE DEFINITIONS USED BY RUNTIME API                                        *
*                                                                              *
*******************************************************************************/

#if !defined(__CUDA_INTERNAL_COMPILATION__)

#include <limits.h>
#include <stddef.h>

#define cudaHostAllocDefault        0   ///< Default page-locked allocation flag
#define cudaHostAllocPortable       1   ///< Pinned memory accessible by all CUDA contexts
#define cudaHostAllocMapped         2   ///< Map allocation into device space
#define cudaHostAllocWriteCombined  4   ///< Write-combined memory

#define cudaEventDefault            0   ///< Default event flag
#define cudaEventBlockingSync       1   ///< Event uses blocking synchronization

#define cudaDeviceScheduleAuto      0   ///< Device flag - Automatic scheduling
#define cudaDeviceScheduleSpin      1   ///< Device flag - Spin default scheduling
#define cudaDeviceScheduleYield     2   ///< Device flag - Yield default scheduling
#define cudaDeviceBlockingSync      4   ///< Device flag - Use blocking synchronization
#define cudaDeviceMapHost           8   ///< Device flag - Support mapped pinned allocations
#define cudaDeviceMask              0xf ///< Device flags mask


#endif /* !__CUDA_INTERNAL_COMPILATION__ */

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

/**
 * CUDA error types
 */
/*DEVICE_BUILTIN*/
enum cudaError
{
  cudaSuccess                           =      0,   ///< No errors
  cudaErrorMissingConfiguration         =      1,   ///< Missing configuration error
  cudaErrorMemoryAllocation             =      2,   ///< Memory allocation error
  cudaErrorInitializationError          =      3,   ///< Initialization error
  cudaErrorLaunchFailure                =      4,   ///< Launch failure
  cudaErrorPriorLaunchFailure           =      5,   ///< Prior launch failure
  cudaErrorLaunchTimeout                =      6,   ///< Launch timeout error
  cudaErrorLaunchOutOfResources         =      7,   ///< Launch out of resources error
  cudaErrorInvalidDeviceFunction        =      8,   ///< Invalid device function
  cudaErrorInvalidConfiguration         =      9,   ///< Invalid configuration
  cudaErrorInvalidDevice                =     10,   ///< Invalid device
  cudaErrorInvalidValue                 =     11,   ///< Invalid value
  cudaErrorInvalidPitchValue            =     12,   ///< Invalid pitch value
  cudaErrorInvalidSymbol                =     13,   ///< Invalid symbol
  cudaErrorMapBufferObjectFailed        =     14,   ///< Map buffer object failed
  cudaErrorUnmapBufferObjectFailed      =     15,   ///< Unmap buffer object failed
  cudaErrorInvalidHostPointer           =     16,   ///< Invalid host pointer
  cudaErrorInvalidDevicePointer         =     17,   ///< Invalid device pointer
  cudaErrorInvalidTexture               =     18,   ///< Invalid texture
  cudaErrorInvalidTextureBinding        =     19,   ///< Invalid texture binding
  cudaErrorInvalidChannelDescriptor     =     20,   ///< Invalid channel descriptor
  cudaErrorInvalidMemcpyDirection       =     21,   ///< Invalid memcpy direction
  cudaErrorAddressOfConstant            =     22,   ///< Address of constant error
  cudaErrorTextureFetchFailed           =     23,   ///< Texture fetch failed
  cudaErrorTextureNotBound              =     24,   ///< Texture not bound error
  cudaErrorSynchronizationError         =     25,   ///< Synchronization error
  cudaErrorInvalidFilterSetting         =     26,   ///< Invalid filter setting
  cudaErrorInvalidNormSetting           =     27,   ///< Invalid norm setting
  cudaErrorMixedDeviceExecution         =     28,   ///< Mixed device execution
  cudaErrorCudartUnloading              =     29,   ///< CUDA runtime unloading
  cudaErrorUnknown                      =     30,   ///< Unknown error condition
  cudaErrorNotYetImplemented            =     31,   ///< Function not yet implemented
  cudaErrorMemoryValueTooLarge          =     32,   ///< Memory value too large
  cudaErrorInvalidResourceHandle        =     33,   ///< Invalid resource handle
  cudaErrorNotReady                     =     34,   ///< Not ready error
  cudaErrorInsufficientDriver           =     35,   ///< CUDA runtime is newer than driver
  cudaErrorSetOnActiveProcess           =     36,   ///< Set on active process error
  cudaErrorNoDevice                     =     38,   ///< No available CUDA device
  cudaErrorStartupFailure               =   0x7f,   ///< Startup failure
  cudaErrorApiFailureBase               =  10000    ///< API failure base
};

/**
 * Channel format kind
 */
/*DEVICE_BUILTIN*/
enum cudaChannelFormatKind
{
  cudaChannelFormatKindSigned           =   0,      ///< Signed channel format
  cudaChannelFormatKindUnsigned         =   1,      ///< Unsigned channel format
  cudaChannelFormatKindFloat            =   2,      ///< Float channel format
  cudaChannelFormatKindNone             =   3       ///< No channel format
};

/**
 * CUDA Channel format descriptor
 */
/*DEVICE_BUILTIN*/
struct cudaChannelFormatDesc
{
  int                        x; ///< x
  int                        y; ///< y
  int                        z; ///< z
  int                        w; ///< w
  enum cudaChannelFormatKind f; ///< Channel format kind
};

/**
 * CUDA array
 */
/*DEVICE_BUILTIN*/
struct cudaArray;

/**
 * CUDA memory copy types
 */
/*DEVICE_BUILTIN*/
enum cudaMemcpyKind
{
  cudaMemcpyHostToHost          =   0,      ///< Host   -> Host
  cudaMemcpyHostToDevice        =   1,      ///< Host   -> Device
  cudaMemcpyDeviceToHost        =   2,      ///< Device -> Host
  cudaMemcpyDeviceToDevice      =   3       ///< Device -> Device
};

/**
 * CUDA Pitched memory pointer
 */
/*DEVICE_BUILTIN*/
struct cudaPitchedPtr
{
  void   *ptr;      ///< Pointer to allocated memory
  size_t  pitch;    ///< Pitch of allocated memory in bytes
  size_t  xsize;    ///< Logical width of allocation in bytes
  size_t  ysize;    ///< Logical height of allocation in bytes
};

/**
 * CUDA extent
 */
/*DEVICE_BUILTIN*/
struct cudaExtent
{
  size_t width;     ///< Width in bytes
  size_t height;    ///< Height in bytes
  size_t depth;     ///< Depth in bytes
};

/**
 * CUDA 3D position
 */
/*DEVICE_BUILTIN*/
struct cudaPos
{
  size_t x;     ///< x
  size_t y;     ///< y
  size_t z;     ///< z
};

/**
 * CUDA 3D memory copying parameters
 */
/*DEVICE_BUILTIN*/
struct cudaMemcpy3DParms
{
  struct cudaArray      *srcArray;  ///< Source memory address
  struct cudaPos         srcPos;    ///< Source position offset
  struct cudaPitchedPtr  srcPtr;    ///< Pitched source memory address

  struct cudaArray      *dstArray;  ///< Destination memory address
  struct cudaPos         dstPos;    ///< Destination position offset
  struct cudaPitchedPtr  dstPtr;    ///< Pitched destination memory address

  struct cudaExtent      extent;    ///< Requested memory copy size
  enum cudaMemcpyKind    kind;      ///< Type of transfer
};

/**
 * CUDA function attributes
 */
/*DEVICE_BUILTIN*/
struct cudaFuncAttributes
{
   size_t sharedSizeBytes;  ///< Size of shared memory in bytes
   size_t constSizeBytes;   ///< Size of constant memory in bytes
   size_t localSizeBytes;   ///< Size of local memory in bytes
   int maxThreadsPerBlock;  ///< Maximum number of threads per block
   int numRegs;             ///< Number of registers used
   int __cudaReserved[8];
};

/**
 * CUDA device compute modes
 */
/*DEVICE_BUILTIN*/
enum cudaComputeMode
{
  cudaComputeModeDefault    =   0,  ///< Default compute mode (Multiple threads can use ::cudaSetDevice() with this device)
  cudaComputeModeExclusive  =   1,  ///< Compute-exclusive mode (Only one thread will be able to use ::cudaSetDevice() with this device)
  cudaComputeModeProhibited =   2   ///< Compute-prohibited mode (No threads can use ::cudaSetDevice() with this device)
};


/**
 * CUDA device properties
 */
/*DEVICE_BUILTIN*/
struct cudaDeviceProp
{
  char   name[256];                 ///< ASCII string identifying device
  size_t totalGlobalMem;            ///< Global memory available on device in bytes
  size_t sharedMemPerBlock;         ///< Shared memory available per block in bytes
  int    regsPerBlock;              ///< 32-bit registers available per block
  int    warpSize;                  ///< Warp size in threads
  size_t memPitch;                  ///< Maximum pitch in bytes allowed by memory copies
  int    maxThreadsPerBlock;        ///< Maximum number of threads per block
  int    maxThreadsDim[3];          ///< Maximum size of each dimension of a block
  int    maxGridSize[3];            ///< Maximum size of each dimension of a grid
  int    clockRate;                 ///< Clock frequency in kilohertz
  size_t totalConstMem;             ///< Constant memory available on device in bytes
  int    major;                     ///< Major compute capability
  int    minor;                     ///< Minor compute capability
  size_t textureAlignment;          ///< Alignment requirement for textures
  int    deviceOverlap;             ///< Device can concurrently copy memory and execute a kernel
  int    multiProcessorCount;       ///< Number of multiprocessors on device
  int    kernelExecTimeoutEnabled;  ///< Specified whether there is a run time limit on kernels
  int    integrated;                ///< Device is integrated as opposed to discrete
  int    canMapHostMemory;          ///< Device can map host memory with cudaHostAlloc/cudaHostGetDevicePointer
  int    computeMode;               ///< Compute mode (See ::cudaComputeMode)
  int    __cudaReserved[36];
};

#define cudaDevicePropDontCare                             \
        {                                                  \
          {'\0'},    /* char   name[256];               */ \
          0,         /* size_t totalGlobalMem;          */ \
          0,         /* size_t sharedMemPerBlock;       */ \
          0,         /* int    regsPerBlock;            */ \
          0,         /* int    warpSize;                */ \
          0,         /* size_t memPitch;                */ \
          0,         /* int    maxThreadsPerBlock;      */ \
          {0, 0, 0}, /* int    maxThreadsDim[3];        */ \
          {0, 0, 0}, /* int    maxGridSize[3];          */ \
          0,         /* int    clockRate;               */ \
          0,         /* size_t totalConstMem;           */ \
          -1,        /* int    major;                   */ \
          -1,        /* int    minor;                   */ \
          0,         /* size_t textureAlignment;        */ \
          -1,        /* int    deviceOverlap;           */ \
          0,         /* int    multiProcessorCount;     */ \
          0,         /* int    kernelExecTimeoutEnabled */ \
          0,         /* int    integrated               */ \
          0,         /* int    canMapHostMemory         */ \
          0,         /* int    computeMode              */ \
        } ///< Empty device properties

/*******************************************************************************
*                                                                              *
*  SHORTHAND TYPE DEFINITION USED BY RUNTIME API                               *
*                                                                              *
*******************************************************************************/

/**
 * CUDA Error types
 */
/*DEVICE_BUILTIN*/
typedef enum cudaError cudaError_t;

/**
 * CUDA stream
 */
/*DEVICE_BUILTIN*/
typedef int cudaStream_t;

/**
 * CUDA event types
 */
/*DEVICE_BUILTIN*/
typedef int cudaEvent_t;

/** @} */
/** @} */ /* END CUDART_TYPES */

#endif /* !__DRIVER_TYPES_H__ */
