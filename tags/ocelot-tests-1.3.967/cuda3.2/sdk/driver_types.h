/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
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

#define cudaHostAllocDefault        0   /**< Default page-locked allocation flag */
#define cudaHostAllocPortable       1   /**< Pinned memory accessible by all CUDA contexts */
#define cudaHostAllocMapped         2   /**< Map allocation into device space */
#define cudaHostAllocWriteCombined  4   /**< Write-combined memory */

#define cudaEventDefault            0   /**< Default event flag */
#define cudaEventBlockingSync       1   /**< Event uses blocking synchronization */
#define cudaEventDisableTiming      2   /**< Event will not record timing data */

#define cudaDeviceScheduleAuto      0   /**< Device flag - Automatic scheduling */
#define cudaDeviceScheduleSpin      1   /**< Device flag - Spin default scheduling */
#define cudaDeviceScheduleYield     2   /**< Device flag - Yield default scheduling */
#define cudaDeviceBlockingSync      4   /**< Device flag - Use blocking synchronization */
#define cudaDeviceMapHost           8   /**< Device flag - Support mapped pinned allocations */
#define cudaDeviceLmemResizeToMax   16  /**< Device flag - Keep local memory allocation after launch */
#define cudaDeviceMask            0x1f  /**< Device flags mask */

#define cudaArrayDefault          0x00  /**< Default CUDA array allocation flag */
#define cudaArraySurfaceLoadStore 0x02  /**< Must be set in cudaMallocArray in order to bind surfaces to the CUDA array */


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
  /**
   * The API call returned with no errors. In the case of query calls, this
   * can also mean that the operation being queried is complete (see
   * ::cudaEventQuery() and ::cudaStreamQuery()).
   */
  cudaSuccess                           =      0,

  /**
   * The device function being invoked (usually via ::cudaLaunch()) was not
   * previously configured via the ::cudaConfigureCall() function.
   */
  cudaErrorMissingConfiguration         =      1,

  /**
   * The API call failed because it was unable to allocate enough memory to
   * perform the requested operation.
   */
  cudaErrorMemoryAllocation             =      2,

  /**
   * The API call failed because the CUDA driver and runtime could not be
   * initialized.
   */
  cudaErrorInitializationError          =      3,

  /**
   * An exception occurred on the device while executing a kernel. Common
   * causes include dereferencing an invalid device pointer and accessing
   * out of bounds shared memory. The device cannot be used until
   * ::cudaThreadExit() is called. All existing device memory allocations
   * are invalid and must be reconstructed if the program is to continue
   * using CUDA.
   */
  cudaErrorLaunchFailure                =      4,

  /**
   * This indicated that a previous kernel launch failed. This was previously
   * used for device emulation of kernel launches.
   * \deprecated
   * This error return is deprecated as of CUDA 3.1. Device emulation mode was
   * removed with the CUDA 3.1 release.
   */
  cudaErrorPriorLaunchFailure           =      5,

  /**
   * This indicates that the device kernel took too long to execute. This can
   * only occur if timeouts are enabled - see the device property
   * \ref ::cudaDeviceProp::kernelExecTimeoutEnabled "kernelExecTimeoutEnabled"
   * for more information. The device cannot be used until ::cudaThreadExit()
   * is called. All existing device memory allocations are invalid and must be
   * reconstructed if the program is to continue using CUDA.
   */
  cudaErrorLaunchTimeout                =      6,

  /**
   * This indicates that a launch did not occur because it did not have
   * appropriate resources. Although this error is similar to
   * ::cudaErrorInvalidConfiguration, this error usually indicates that the
   * user has attempted to pass too many arguments to the device kernel, or the
   * kernel launch specifies too many threads for the kernel's register count.
   */
  cudaErrorLaunchOutOfResources         =      7,

  /**
   * The requested device function does not exist or is not compiled for the
   * proper device architecture.
   */
  cudaErrorInvalidDeviceFunction        =      8,

  /**
   * This indicates that a kernel launch is requesting resources that can
   * never be satisfied by the current device. Requesting more shared memory
   * per block than the device supports will trigger this error, as will
   * requesting too many threads or blocks. See ::cudaDeviceProp for more
   * device limitations.
   */
  cudaErrorInvalidConfiguration         =      9,

  /**
   * This indicates that the device ordinal supplied by the user does not
   * correspond to a valid CUDA device.
   */
  cudaErrorInvalidDevice                =     10,

  /**
   * This indicates that one or more of the parameters passed to the API call
   * is not within an acceptable range of values.
   */
  cudaErrorInvalidValue                 =     11,

  /**
   * This indicates that one or more of the pitch-related parameters passed
   * to the API call is not within the acceptable range for pitch.
   */
  cudaErrorInvalidPitchValue            =     12,

  /**
   * This indicates that the symbol name/identifier passed to the API call
   * is not a valid name or identifier.
   */
  cudaErrorInvalidSymbol                =     13,

  /**
   * This indicates that the buffer object could not be mapped.
   */
  cudaErrorMapBufferObjectFailed        =     14,

  /**
   * This indicates that the buffer object could not be unmapped.
   */
  cudaErrorUnmapBufferObjectFailed      =     15,

  /**
   * This indicates that at least one host pointer passed to the API call is
   * not a valid host pointer.
   */
  cudaErrorInvalidHostPointer           =     16,

  /**
   * This indicates that at least one device pointer passed to the API call is
   * not a valid device pointer.
   */
  cudaErrorInvalidDevicePointer         =     17,

  /**
   * This indicates that the texture passed to the API call is not a valid
   * texture.
   */
  cudaErrorInvalidTexture               =     18,

  /**
   * This indicates that the texture binding is not valid. This occurs if you
   * call ::cudaGetTextureAlignmentOffset() with an unbound texture.
   */
  cudaErrorInvalidTextureBinding        =     19,

  /**
   * This indicates that the channel descriptor passed to the API call is not
   * valid. This occurs if the format is not one of the formats specified by
   * ::cudaChannelFormatKind, or if one of the dimensions is invalid.
   */
  cudaErrorInvalidChannelDescriptor     =     20,

  /**
   * This indicates that the direction of the memcpy passed to the API call is
   * not one of the types specified by ::cudaMemcpyKind.
   */
  cudaErrorInvalidMemcpyDirection       =     21,

  /**
   * This indicated that the user has taken the address of a constant variable,
   * which was forbidden up until the CUDA 3.1 release.
   * \deprecated
   * This error return is deprecated as of CUDA 3.1. Variables in constant
   * memory may now have their address taken by the runtime via
   * ::cudaGetSymbolAddress().
   */
  cudaErrorAddressOfConstant            =     22,

  /**
   * This indicated that a texture fetch was not able to be performed.
   * This was previously used for device emulation of texture operations.
   * \deprecated
   * This error return is deprecated as of CUDA 3.1. Device emulation mode was
   * removed with the CUDA 3.1 release.
   */
  cudaErrorTextureFetchFailed           =     23,

  /**
   * This indicated that a texture was not bound for access.
   * This was previously used for device emulation of texture operations.
   * \deprecated
   * This error return is deprecated as of CUDA 3.1. Device emulation mode was
   * removed with the CUDA 3.1 release.
   */
  cudaErrorTextureNotBound              =     24,

  /**
   * This indicated that a synchronization operation had failed.
   * This was previously used for some device emulation functions.
   * \deprecated
   * This error return is deprecated as of CUDA 3.1. Device emulation mode was
   * removed with the CUDA 3.1 release.
   */
  cudaErrorSynchronizationError         =     25,

  /**
   * This indicates that a non-float texture was being accessed with linear
   * filtering. This is not supported by CUDA.
   */
  cudaErrorInvalidFilterSetting         =     26,

  /**
   * This indicates that an attempt was made to read a non-float texture as a
   * normalized float. This is not supported by CUDA.
   */
  cudaErrorInvalidNormSetting           =     27,

  /**
   * Mixing of device and device emulation code was not allowed.
   * \deprecated
   * This error return is deprecated as of CUDA 3.1. Device emulation mode was
   * removed with the CUDA 3.1 release.
   */
  cudaErrorMixedDeviceExecution         =     28,

  /**
   * This indicated an issue with calling API functions during the unload
   * process of the CUDA runtime in prior releases.
   * \deprecated
   * This error return is deprecated as of CUDA 3.2.
   */
  cudaErrorCudartUnloading              =     29,

  /**
   * This indicates that an unknown internal error has occurred.
   */
  cudaErrorUnknown                      =     30,

  /**
   * This indicates that the API call is not yet implemented. Production
   * releases of CUDA will never return this error.
   */
  cudaErrorNotYetImplemented            =     31,

  /**
   * This indicated that an emulated device pointer exceeded the 32-bit address
   * range.
   * \deprecated
   * This error return is deprecated as of CUDA 3.1. Device emulation mode was
   * removed with the CUDA 3.1 release.
   */
  cudaErrorMemoryValueTooLarge          =     32,

  /**
   * This indicates that a resource handle passed to the API call was not
   * valid. Resource handles are opaque types like ::cudaStream_t and
   * ::cudaEvent_t.
   */
  cudaErrorInvalidResourceHandle        =     33,

  /**
   * This indicates that asynchronous operations issued previously have not
   * completed yet. This result is not actually an error, but must be indicated
   * differently than ::cudaSuccess (which indicates completion). Calls that
   * may return this value include ::cudaEventQuery() and ::cudaStreamQuery().
   */
  cudaErrorNotReady                     =     34,

  /**
   * This indicates that the installed NVIDIA CUDA driver is older than the
   * CUDA runtime library. This is not a supported configuration. Users should
   * install an updated NVIDIA display driver to allow the application to run.
   */
  cudaErrorInsufficientDriver           =     35,

  /**
   * This indicates that the user has called ::cudaSetDevice(),
   * ::cudaSetValidDevices(), ::cudaSetDeviceFlags(),
   * ::cudaD3D9SetDirect3DDevice(), ::cudaD3D10SetDirect3DDevice,
   * ::cudaD3D11SetDirect3DDevice(), * or ::cudaVDPAUSetVDPAUDevice() after
   * initializing the CUDA runtime by calling non-device management operations
   * (allocating memory and launching kernels are examples of non-device
   * management operations). This error can also be returned if using
   * runtime/driver interoperability and there is an existing ::CUcontext
   * active on the host thread.
   */
  cudaErrorSetOnActiveProcess           =     36,

  /**
   * This indicates that the surface passed to the API call is not a valid
   * surface.
   */
  cudaErrorInvalidSurface               =     37,

  /**
   * This indicates that no CUDA-capable devices were detected by the installed
   * CUDA driver.
   */
  cudaErrorNoDevice                     =     38,

  /**
   * This indicates that an uncorrectable ECC error was detected during
   * execution.
   */
  cudaErrorECCUncorrectable             =     39,

  /**
   * This indicates that a link to a shared object failed to resolve.
   */
  cudaErrorSharedObjectSymbolNotFound   =     40,

  /**
   * This indicates that initialization of a shared object failed.
   */
  cudaErrorSharedObjectInitFailed       =     41,

  /**
   * This indicates that the ::cudaLimit passed to the API call is not
   * supported by the active device.
   */
  cudaErrorUnsupportedLimit             =     42,

  /**
   * This indicates that multiple global or constant variables (across separate
   * CUDA source files in the application) share the same string name.
   */
  cudaErrorDuplicateVariableName        =     43,

  /**
   * This indicates that multiple textures (across separate CUDA source
   * files in the application) share the same string name.
   */
  cudaErrorDuplicateTextureName         =     44,

  /**
   * This indicates that multiple surfaces (across separate CUDA source
   * files in the application) share the same string name.
   */
  cudaErrorDuplicateSurfaceName         =     45,

  /**
   * This indicates that all CUDA devices are busy or unavailable at the current
   * time. Devices are often busy/unavailable due to use of
   * ::cudaComputeModeExclusive or ::cudaComputeModeProhibited. They can also
   * be unavailable due to memory constraints on a device that already has
   * active CUDA work being performed.
   */
  cudaErrorDevicesUnavailable           =     46,

  /**
   * This indicates that the device kernel image is invalid.
   */
  cudaErrorInvalidKernelImage           =     47,

  /**
   * This indicates that there is no kernel image available that is suitable
   * for the device. This can occur when a user specifies code generation
   * options for a particular CUDA source file that do not include the
   * corresponding device configuration.
   */
  cudaErrorNoKernelImageForDevice       =     48,

  /**
   * This indicates that the current context is not compatible with this
   * version of the CUDA Runtime. This can only occur if you are using CUDA
   * Runtime/Driver interoperability and have created an existing Driver
   * context using an older API. Please see \ref CUDART_DRIVER
   * "Interactions with the CUDA Driver API" for more information.
   */
  cudaErrorIncompatibleDriverContext    =     49,

  /**
   * This indicates an internal startup failure in the CUDA runtime.
   */
  cudaErrorStartupFailure               =   0x7f,

  /**
   * Any unhandled CUDA driver error is added to this value and returned via
   * the runtime. Production releases of CUDA should not return such errors.
   */
  cudaErrorApiFailureBase               =  10000
};

/**
 * Channel format kind
 */
/*DEVICE_BUILTIN*/
enum cudaChannelFormatKind
{
  cudaChannelFormatKindSigned           =   0,      /**< Signed channel format */
  cudaChannelFormatKindUnsigned         =   1,      /**< Unsigned channel format */
  cudaChannelFormatKindFloat            =   2,      /**< Float channel format */
  cudaChannelFormatKindNone             =   3       /**< No channel format */
};

/**
 * CUDA Channel format descriptor
 */
/*DEVICE_BUILTIN*/
struct cudaChannelFormatDesc
{
  int                        x; /**< x */
  int                        y; /**< y */
  int                        z; /**< z */
  int                        w; /**< w */
  enum cudaChannelFormatKind f; /**< Channel format kind */
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
  cudaMemcpyHostToHost          =   0,      /**< Host   -> Host */
  cudaMemcpyHostToDevice        =   1,      /**< Host   -> Device */
  cudaMemcpyDeviceToHost        =   2,      /**< Device -> Host */
  cudaMemcpyDeviceToDevice      =   3       /**< Device -> Device */
};

/**
 * CUDA Pitched memory pointer
 * \sa ::make_cudaPitchedPtr
 */
/*DEVICE_BUILTIN*/
struct cudaPitchedPtr
{
  void   *ptr;      /**< Pointer to allocated memory */
  size_t  pitch;    /**< Pitch of allocated memory in bytes */
  size_t  xsize;    /**< Logical width of allocation in elements */
  size_t  ysize;    /**< Logical height of allocation in elements */
};

/**
 * CUDA extent
 * \sa ::make_cudaExtent
 */
/*DEVICE_BUILTIN*/
struct cudaExtent
{
  size_t width;     /**< Width in elements when referring to array memory, in bytes when referring to linear memory */
  size_t height;    /**< Height in elements */
  size_t depth;     /**< Depth in elements */
};

/**
 * CUDA 3D position
 * \sa ::make_cudaPos
 */
/*DEVICE_BUILTIN*/
struct cudaPos
{
  size_t x;     /**< x */
  size_t y;     /**< y */
  size_t z;     /**< z */
};

/**
 * CUDA 3D memory copying parameters
 */
/*DEVICE_BUILTIN*/
struct cudaMemcpy3DParms
{
  struct cudaArray      *srcArray;  /**< Source memory address */
  struct cudaPos         srcPos;    /**< Source position offset */
  struct cudaPitchedPtr  srcPtr;    /**< Pitched source memory address */

  struct cudaArray      *dstArray;  /**< Destination memory address */
  struct cudaPos         dstPos;    /**< Destination position offset */
  struct cudaPitchedPtr  dstPtr;    /**< Pitched destination memory address */

  struct cudaExtent      extent;    /**< Requested memory copy size */
  enum cudaMemcpyKind    kind;      /**< Type of transfer */
};

/**
 * CUDA graphics interop resource
 */
/*DEVICE_BUILTIN*/
struct cudaGraphicsResource;

/**
 * CUDA graphics interop register flags
 */
/*DEVICE_BUILTIN*/
enum cudaGraphicsRegisterFlags
{
  cudaGraphicsRegisterFlagsNone  = 0   /**< Default */
};

/**
 * CUDA graphics interop map flags
 */
/*DEVICE_BUILTIN*/
enum cudaGraphicsMapFlags
{
  cudaGraphicsMapFlagsNone         = 0,  /**< Default; Assume resource can be read/written */
  cudaGraphicsMapFlagsReadOnly     = 1,  /**< CUDA will not write to this resource */
  cudaGraphicsMapFlagsWriteDiscard = 2   /**< CUDA will only write to and will not read from this resource */
};

/**
 * CUDA graphics interop array indices for cube maps
 */
/*DEVICE_BUILTIN*/
enum cudaGraphicsCubeFace {
  cudaGraphicsCubeFacePositiveX = 0x00, /**< Positive X face of cubemap */
  cudaGraphicsCubeFaceNegativeX = 0x01, /**< Negative X face of cubemap */
  cudaGraphicsCubeFacePositiveY = 0x02, /**< Positive Y face of cubemap */
  cudaGraphicsCubeFaceNegativeY = 0x03, /**< Negative Y face of cubemap */
  cudaGraphicsCubeFacePositiveZ = 0x04, /**< Positive Z face of cubemap */
  cudaGraphicsCubeFaceNegativeZ = 0x05  /**< Negative Z face of cubemap */
};

/**
 * CUDA function attributes
 */
/*DEVICE_BUILTIN*/
struct cudaFuncAttributes
{
   /**
    * The size in bytes of statically-allocated shared memory per block
    * required by this function. This does not include dynamically-allocated
    * shared memory requested by the user at runtime.
    */
   size_t sharedSizeBytes;

   /**
    * The size in bytes of user-allocated constant memory required by this
    * function.
    */
   size_t constSizeBytes;

   /**
    * The size in bytes of local memory used by each thread of this function.
    */
   size_t localSizeBytes;

   /**
    * The maximum number of threads per block, beyond which a launch of the
    * function would fail. This number depends on both the function and the
    * device on which the function is currently loaded.
    */
   int maxThreadsPerBlock;

   /**
    * The number of registers used by each thread of this function.
    */
   int numRegs;

   /**
    * The PTX virtual architecture version for which the function was
    * compiled. This value is the major PTX version * 10 + the minor PTX
    * version, so a PTX version 1.3 function would return the value 13.
    */
   int ptxVersion;

   /**
    * The binary architecture version for which the function was compiled.
    * This value is the major binary version * 10 + the minor binary version,
    * so a binary version 1.3 function would return the value 13.
    */
   int binaryVersion;

   int __cudaReserved[6];
};

/**
 * CUDA function cache configurations
 */
/*DEVICE_BUILTIN*/
enum cudaFuncCache
{
  cudaFuncCachePreferNone   = 0,    /**< Default function cache configuration, no preference */
  cudaFuncCachePreferShared = 1,    /**< Prefer larger shared memory and smaller L1 cache  */
  cudaFuncCachePreferL1     = 2     /**< Prefer larger L1 cache and smaller shared memory */
};

/**
 * CUDA device compute modes
 */
/*DEVICE_BUILTIN*/
enum cudaComputeMode
{
  cudaComputeModeDefault    =   0,  /**< Default compute mode (Multiple threads can use ::cudaSetDevice() with this device) */
  cudaComputeModeExclusive  =   1,  /**< Compute-exclusive mode (Only one thread will be able to use ::cudaSetDevice() with this device) */
  cudaComputeModeProhibited =   2   /**< Compute-prohibited mode (No threads can use ::cudaSetDevice() with this device) */
};

/**
 * CUDA Limits
 */
/*DEVICE_BUILTIN*/
enum cudaLimit
{
    cudaLimitStackSize      = 0x00, /**< GPU thread stack size */
    cudaLimitPrintfFifoSize = 0x01, /**< GPU printf FIFO size */
    cudaLimitMallocHeapSize = 0x02  /**< GPU malloc heap size */
};

/**
 * CUDA device properties
 */
/*DEVICE_BUILTIN*/
struct cudaDeviceProp
{
  char   name[256];                 /**< ASCII string identifying device */
  size_t totalGlobalMem;            /**< Global memory available on device in bytes */
  size_t sharedMemPerBlock;         /**< Shared memory available per block in bytes */
  int    regsPerBlock;              /**< 32-bit registers available per block */
  int    warpSize;                  /**< Warp size in threads */
  size_t memPitch;                  /**< Maximum pitch in bytes allowed by memory copies */
  int    maxThreadsPerBlock;        /**< Maximum number of threads per block */
  int    maxThreadsDim[3];          /**< Maximum size of each dimension of a block */
  int    maxGridSize[3];            /**< Maximum size of each dimension of a grid */
  int    clockRate;                 /**< Clock frequency in kilohertz */
  size_t totalConstMem;             /**< Constant memory available on device in bytes */
  int    major;                     /**< Major compute capability */
  int    minor;                     /**< Minor compute capability */
  size_t textureAlignment;          /**< Alignment requirement for textures */
  int    deviceOverlap;             /**< Device can concurrently copy memory and execute a kernel */
  int    multiProcessorCount;       /**< Number of multiprocessors on device */
  int    kernelExecTimeoutEnabled;  /**< Specified whether there is a run time limit on kernels */
  int    integrated;                /**< Device is integrated as opposed to discrete */
  int    canMapHostMemory;          /**< Device can map host memory with cudaHostAlloc/cudaHostGetDevicePointer */
  int    computeMode;               /**< Compute mode (See ::cudaComputeMode) */
  int    maxTexture1D;              /**< Maximum 1D texture size */
  int    maxTexture2D[2];           /**< Maximum 2D texture dimensions */
  int    maxTexture3D[3];           /**< Maximum 3D texture dimensions */
  int    maxTexture2DArray[3];      /**< Maximum 2D texture array dimensions */
  size_t surfaceAlignment;          /**< Alignment requirements for surfaces */
  int    concurrentKernels;         /**< Device can possibly execute multiple kernels concurrently */
  int    ECCEnabled;                /**< Device has ECC support enabled */
  int    pciBusID;                  /**< PCI bus ID of the device */
  int    pciDeviceID;               /**< PCI device ID of the device */
  int    tccDriver;                 /**< 1 if device is a Tesla device using TCC driver, 0 otherwise */
  int    __cudaReserved[21];
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
          0,         /* int    maxTexture1D             */ \
          {0, 0},    /* int    maxTexture2D[2]          */ \
          {0, 0, 0}, /* int    maxTexture3D[3]          */ \
          {0, 0, 0}, /* int    maxTexture2DArray[3]     */ \
          0,         /* size_t surfaceAlignment         */ \
          0,         /* int    concurrentKernels        */ \
          0,         /* int    ECCEnabled               */ \
          0,         /* int    pciBusID                 */ \
          0,         /* int    pciDeviceID              */ \
          0          /* int    tccDriver                */ \
        } /**< Empty device properties */

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
typedef struct CUstream_st *cudaStream_t;

/**
 * CUDA event types
 */
/*DEVICE_BUILTIN*/
typedef struct CUevent_st *cudaEvent_t;

/**
 * CUDA graphics resource types
 */
/*DEVICE_BUILTIN*/
typedef struct cudaGraphicsResource *cudaGraphicsResource_t;

/**
 * CUDA UUID types
 */
/*DEVICE_BUILTIN*/
typedef struct CUuuid_st cudaUUID_t;

/** @} */
/** @} */ /* END CUDART_TYPES */

#endif /* !__DRIVER_TYPES_H__ */
