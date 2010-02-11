/*!
	\file cuda_runtime.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements an up-to-date CUDA Runtime API
	\date 11 Dec 2009
*/

#ifndef CUDA_RUNTIME_H_INCLUDED
#define CUDA_RUNTIME_H_INCLUDED

#include <cstring>

#include <limits.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#define __dv(x) =x
#else
#define __dv(x)
#endif

#define __host__
#define CUDARTAPI

struct cudaArray;
struct cudaMemcpy3DParms;
struct textureReference;

typedef int cudaEvent_t;
typedef int cudaStream_t;
typedef unsigned int GLuint;

enum cudaMemcpyKind {
	cudaMemcpyHostToHost,
	cudaMemcpyHostToDevice,
	cudaMemcpyDeviceToHost,
	cudaMemcpyDeviceToDevice
};

enum cudaChannelFormatKind {
	cudaChannelFormatKindSigned,
	cudaChannelFormatKindUnsigned,
	cudaChannelFormatKindFloat,
	cudaChannelFormatKindNone
};

enum cudaComputeMode {
	cudaComputeModeDefault,
	cudaComputeModeExclusive,
	cudaComputeModeProhibited
};

enum cudaError_t {
	cudaSuccess,
	cudaErrorMissingConfiguration,
	cudaErrorMemoryAllocation,
	cudaErrorInitializationError,
	cudaErrorLaunchFailure,
	cudaErrorPriorLaunchFailure,
	cudaErrorLaunchTimeout,
	cudaErrorLaunchOutOfResources,
	cudaErrorInvalidDeviceFunction,
	cudaErrorInvalidConfiguration,
	cudaErrorInvalidDevice,
	cudaErrorInvalidValue,
	cudaErrorInvalidPitchValue,
	cudaErrorInvalidSymbol,
	cudaErrorMapBufferObjectFailed,
	cudaErrorUnmapBufferObjectFailed,
	cudaErrorInvalidHostPointer,
	cudaErrorInvalidDevicePointer,
	cudaErrorInvalidTexture,
	cudaErrorInvalidTextureBinding,
	cudaErrorInvalidChannelDescriptor,
	cudaErrorInvalidMemcpyDirection,
	cudaErrorAddressOfConstant,
	cudaErrorTextureFetchFailed,
	cudaErrorTextureNotBound,
	cudaErrorSynchronizationError,
	cudaErrorInvalidFilterSetting,
	cudaErrorInvalidNormSetting,
	cudaErrorMixedDeviceExecution,
	cudaErrorCudartUnloading,
	cudaErrorUnknown,
	cudaErrorNotYetImplemented,
	cudaErrorMemoryValueTooLarge,
	cudaErrorInvalidResourceHandle,
	cudaErrorNotReady,
	cudaErrorInsufficientDriver,
	cudaErrorSetOnActiveProcess,
	cudaErrorNoDevice,
	cudaErrorStartupFailure,
	cudaErrorApiFailureBase
};

struct dim3 {
	int x, y, z;
};

struct uint3 {
	unsigned int x, y, z;
};

struct cudaExtent {
	size_t depth;
	size_t height;
	size_t width;
};

struct cudaDeviceProp {
	int canMapHostMemory;
	int clockRate;
	int computeMode;
	int deviceOverlap;
	int integrated;
	int kernelExecTimeoutEnabled;
	int major;
	int maxGridSize[3];
	int maxThreadsDim[3];
	int maxThreadsPerBlock;
	size_t memPitch;
	int minor;
	int multiProcessorCount;
	char name[256];
	int regsPerBlock;
	size_t sharedMemPerBlock;
	size_t textureAlignment;
	size_t totalConstMem;
	size_t totalGlobalMem;
	int warpSize;
};

struct cudaChannelFormatDesc {
	enum cudaChannelFormatKind f;
	int w;
	int x;
	int y;
	int z;
};

struct cudaFuncAttributes {
	size_t constSizeBytes;
	size_t localSizeBytes;
	int maxThreadsPerBlock;
	int numRegs;
	size_t sharedSizeBytes;
};

struct cudaPitchedPtr {
	size_t pitch;
	void *ptr;
	size_t xsize;
	size_t ysize;
};

struct cudaPos {
	size_t x;
	size_t y;
	size_t z;
};

struct cudaMemcpy3DParms {
	struct cudaArray *dstArray;
	struct cudaPos dstPos;
	struct cudaPitchedPtr dstPtr;
	struct cudaExtent extent;
	enum cudaMemcpyKind kind;
	struct cudaArray *srcArray;
	struct cudaPos srcPos;
	struct cudaPitchedPtr srcPtr;
};

struct textureReference {
  int normalized;
  int filterMode;
  int addressMode[3];
  cudaChannelFormatDesc channelDesc;
  int __cudaReserved[16];
};

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern void** __cudaRegisterFatBinary(void *fatCubin);

extern void __cudaUnregisterFatBinary(void **fatCubinHandle);

extern void __cudaRegisterVar(void **fatCubinHandle, char *hostVar, char *deviceAddress, const char *deviceName, int ext, int size, int constant, int global);

extern void __cudaRegisterTexture(
        void **fatCubinHandle,
  const struct textureReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
        int norm,
        int ext
);

extern void __cudaRegisterShared(
  void **fatCubinHandle,
  void **devicePtr
);

extern void __cudaRegisterSharedVar(
  void **fatCubinHandle,
  void **devicePtr,
  size_t size,
  size_t alignment,
  int storage
);

extern void __cudaRegisterFunction(
        void **fatCubinHandle,
  const char *hostFun,
        char *deviceFun,
  const char *deviceName,
        int thread_limit,
        uint3 *tid,
        uint3 *bid,
        dim3 *bDim,
        dim3 *gDim,
        int *wSize
);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaMalloc3D(struct cudaPitchedPtr* pitchedDevPtr, struct cudaExtent extent);
extern __host__ cudaError_t CUDARTAPI cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent);
extern __host__ cudaError_t CUDARTAPI cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy3D(const struct cudaMemcpy3DParms *p);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream);


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaMalloc(void **devPtr, size_t size);
extern __host__ cudaError_t CUDARTAPI cudaMallocHost(void **ptr, size_t size);
extern __host__ cudaError_t CUDARTAPI cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);
extern __host__ cudaError_t CUDARTAPI cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height __dv(1));
extern __host__ cudaError_t CUDARTAPI cudaFree(void *devPtr);
extern __host__ cudaError_t CUDARTAPI cudaFreeHost(void *ptr);
extern __host__ cudaError_t CUDARTAPI cudaFreeArray(struct cudaArray *array);

extern __host__ cudaError_t CUDARTAPI cudaHostAlloc(void **pHost, size_t bytes, unsigned int flags);
extern __host__ cudaError_t CUDARTAPI cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags);
extern __host__ cudaError_t CUDARTAPI cudaHostGetFlags(unsigned int *pFlags, void *pHost);


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaMemcpy(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind);
extern __host__ cudaError_t CUDARTAPI cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind);
extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromArray(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind);
extern __host__ cudaError_t CUDARTAPI cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToDevice));
extern __host__ cudaError_t CUDARTAPI cudaMemcpy2D(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArray(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToDevice));
extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbol(const char *symbol, const void *src, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyHostToDevice));
extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbol(void *dst, const char *symbol, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToHost));

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaMemcpyAsync(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaMemcpyToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromArrayAsync(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DAsync(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbolAsync(const char *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbolAsync(void *dst, const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaMemset(void *devPtr, int value, size_t count);
extern __host__ cudaError_t CUDARTAPI cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, size_t height);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaGetSymbolAddress(void **devPtr, const char *symbol);
extern __host__ cudaError_t CUDARTAPI cudaGetSymbolSize(size_t *size, const char *symbol);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaGetDeviceCount(int *count);
extern __host__ cudaError_t CUDARTAPI cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);
extern __host__ cudaError_t CUDARTAPI cudaChooseDevice(int *device, const struct cudaDeviceProp *prop);
extern __host__ cudaError_t CUDARTAPI cudaSetDevice(int device);
extern __host__ cudaError_t CUDARTAPI cudaGetDevice(int *device);
extern __host__ cudaError_t CUDARTAPI cudaSetValidDevices(int *device_arr, int len);
extern __host__ cudaError_t CUDARTAPI cudaSetDeviceFlags( int flags );

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaBindTexture(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size __dv(UINT_MAX));
extern __host__ cudaError_t CUDARTAPI cudaBindTexture2D(size_t *offset,const struct textureReference *texref,const void *devPtr, const struct cudaChannelFormatDesc *desc,size_t width, size_t height, size_t pitch);
extern __host__ cudaError_t CUDARTAPI cudaBindTextureToArray(const struct textureReference *texref, const struct cudaArray *array, const struct cudaChannelFormatDesc *desc);
extern __host__ cudaError_t CUDARTAPI cudaUnbindTexture(const struct textureReference *texref);
extern __host__ cudaError_t CUDARTAPI cudaGetTextureAlignmentOffset(size_t *offset, const struct textureReference *texref);
extern __host__ cudaError_t CUDARTAPI cudaGetTextureReference(const struct textureReference **texref, const char *symbol);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, const struct cudaArray *array);
extern __host__ struct cudaChannelFormatDesc CUDARTAPI cudaCreateChannelDesc(int x, int y, int z, int w, enum cudaChannelFormatKind f);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaGetLastError(void);
extern __host__ const char* CUDARTAPI cudaGetErrorString(cudaError_t error);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem __dv(0), cudaStream_t stream __dv(0));
extern __host__ cudaError_t CUDARTAPI cudaSetupArgument(const void *arg, size_t size, size_t offset);
extern __host__ cudaError_t CUDARTAPI cudaLaunch(const char *entry);
extern __host__ cudaError_t CUDARTAPI cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const char *func);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaStreamCreate(cudaStream_t *pStream);
extern __host__ cudaError_t CUDARTAPI cudaStreamDestroy(cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaStreamSynchronize(cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaStreamQuery(cudaStream_t stream);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaEventCreate(cudaEvent_t *event);
extern __host__ cudaError_t CUDARTAPI cudaEventCreateWithFlags(cudaEvent_t *event, int flags);
extern __host__ cudaError_t CUDARTAPI cudaEventRecord(cudaEvent_t event, cudaStream_t stream);
extern __host__ cudaError_t CUDARTAPI cudaEventQuery(cudaEvent_t event);
extern __host__ cudaError_t CUDARTAPI cudaEventSynchronize(cudaEvent_t event);
extern __host__ cudaError_t CUDARTAPI cudaEventDestroy(cudaEvent_t event);
extern __host__ cudaError_t CUDARTAPI cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end);


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t cudaGLMapBufferObject(void **devPtr, GLuint bufObj);
extern __host__ cudaError_t cudaGLMapBufferObjectAsync(void **devPtr, GLuint bufObj, cudaStream_t stream);
extern __host__ cudaError_t cudaGLRegisterBufferObject(GLuint bufObj);
extern __host__ cudaError_t cudaGLSetBufferObjectMapFlags(GLuint bufObj, unsigned int flags);
extern __host__ cudaError_t cudaGLSetGLDevice(int device);
extern __host__ cudaError_t cudaGLUnmapBufferObject(GLuint bufObj);
extern __host__ cudaError_t cudaGLUnmapBufferObjectAsync(GLuint bufObj, cudaStream_t stream);
extern __host__ cudaError_t cudaGLUnregisterBufferObject(GLuint bufObj);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaSetDoubleForDevice(double *d);
extern __host__ cudaError_t CUDARTAPI cudaSetDoubleForHost(double *d);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaThreadExit(void);
extern __host__ cudaError_t CUDARTAPI cudaThreadSynchronize(void);

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

extern __host__ cudaError_t CUDARTAPI cudaDriverGetVersion(int *driverVersion);
extern __host__ cudaError_t CUDARTAPI cudaRuntimeGetVersion(int *runtimeVersion);

#ifdef __cplusplus
}
#endif

#endif

