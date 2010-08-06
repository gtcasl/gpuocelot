/*!
	\file cuda_runtime.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief wraps CUDA Runtime API with calls to CudaRuntimeInterface methods
	\date 14 Dec 2009
*/

// C stdlib includes
#include <assert.h>

// Ocelot includes
#include <ocelot/cuda/interface/cuda_runtime.h>
#include <ocelot/cuda/interface/CudaRuntimeInterface.h>

/************************************************************************************************/


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

void** CONVENTION __cudaRegisterFatBinary(void *fatCubin) {
	return cuda::CudaRuntimeInterface::get()->cudaRegisterFatBinary(fatCubin);
}

void CONVENTION __cudaUnregisterFatBinary(void **fatCubinHandle) {
	cuda::CudaRuntimeInterface::get()->cudaUnregisterFatBinary(fatCubinHandle);
}

void CONVENTION __cudaRegisterVar(void **fatCubinHandle, char *hostVar, char *deviceAddress, 
	const char *deviceName, int ext, int size, int constant, int global) {
	
	cuda::CudaRuntimeInterface::get()->cudaRegisterVar(fatCubinHandle, hostVar, deviceAddress,
		deviceName, ext, size, constant, global);
}

void CONVENTION __cudaRegisterTexture(
        void **fatCubinHandle,
  const struct textureReference *hostVar,
  const void **deviceAddress,
  const char *deviceName,
        int dim,
        int norm,
        int ext) {
	cuda::CudaRuntimeInterface::get()->cudaRegisterTexture(fatCubinHandle, hostVar, deviceAddress,
		deviceName, dim, norm, ext);
}

void CONVENTION __cudaRegisterShared(
  void **fatCubinHandle,
  void **devicePtr) {
	cuda::CudaRuntimeInterface::get()->cudaRegisterShared(fatCubinHandle, devicePtr);
}

void CONVENTION __cudaRegisterSharedVar(
  void **fatCubinHandle,
  void **devicePtr,
  size_t size,
  size_t alignment,
  int storage) {
  
	cuda::CudaRuntimeInterface::get()->cudaRegisterSharedVar(fatCubinHandle, devicePtr, size,
		alignment, storage);
}

void CONVENTION __cudaRegisterFunction(
        void **fatCubinHandle,
  const char *hostFun,
        char *deviceFun,
  const char *deviceName,
        int thread_limit,
        uint3 *tid,
        uint3 *bid,
        dim3 *bDim,
        dim3 *gDim,
        int *wSize) {
	cuda::CudaRuntimeInterface::get()->cudaRegisterFunction(fatCubinHandle, hostFun, deviceFun,	
		deviceName, thread_limit, tid, bid, bDim, gDim, wSize);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaMalloc3D(struct cudaPitchedPtr* pitchedDevPtr, struct cudaExtent extent) {
	return cuda::CudaRuntimeInterface::get()->cudaMalloc3D(pitchedDevPtr, extent);
}

cudaError_t CONVENTION  cudaMalloc3DArray(struct cudaArray** arrayPtr, const struct cudaChannelFormatDesc* desc, struct cudaExtent extent) {
	return cuda::CudaRuntimeInterface::get()->cudaMalloc3DArray(arrayPtr, desc, extent);
}

cudaError_t CONVENTION  cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent) {
	return cuda::CudaRuntimeInterface::get()->cudaMemset3D(pitchedDevPtr, value, extent);
}

cudaError_t CONVENTION  cudaMemcpy3D(const struct cudaMemcpy3DParms *p) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy3D(p);
}

cudaError_t CONVENTION  cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy3DAsync(p, stream);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaMalloc(void **devPtr, size_t size) {
	return cuda::CudaRuntimeInterface::get()->cudaMalloc(devPtr, size);
}

cudaError_t CONVENTION  cudaMallocHost(void **ptr, size_t size) {
	return cuda::CudaRuntimeInterface::get()->cudaMallocHost(ptr, size);
}

cudaError_t CONVENTION  cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height) {
	return cuda::CudaRuntimeInterface::get()->cudaMallocPitch(devPtr, pitch, width, height);
}

cudaError_t CONVENTION  cudaMallocArray(struct cudaArray **array, const struct cudaChannelFormatDesc *desc, size_t width, size_t height) {
	return cuda::CudaRuntimeInterface::get()->cudaMallocArray(array, desc, width, height);
}

cudaError_t CONVENTION  cudaFree(void *devPtr) {
	return cuda::CudaRuntimeInterface::get()->cudaFree(devPtr);
}

cudaError_t CONVENTION  cudaFreeHost(void *ptr) {
	return cuda::CudaRuntimeInterface::get()->cudaFreeHost(ptr);
}

cudaError_t CONVENTION  cudaFreeArray(struct cudaArray *array) {
	return cuda::CudaRuntimeInterface::get()->cudaFreeArray(array);
}


cudaError_t CONVENTION  cudaHostAlloc(void **pHost, size_t bytes, unsigned int flags) {
	return cuda::CudaRuntimeInterface::get()->cudaHostAlloc(pHost, bytes, flags);
}

cudaError_t CONVENTION  cudaHostGetDevicePointer(void **pDevice, void *pHost, unsigned int flags) {
	return cuda::CudaRuntimeInterface::get()->cudaHostGetDevicePointer(pDevice, pHost, flags);
}

cudaError_t CONVENTION  cudaHostGetFlags(unsigned int *pFlags, void *pHost) {
	return cuda::CudaRuntimeInterface::get()->cudaHostGetFlags(pFlags, pHost);
}



/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaMemcpy(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy(dst, src, count, kind);
}

cudaError_t CONVENTION  cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyToArray(dst, wOffset, hOffset, src, count, kind);
}

cudaError_t CONVENTION  cudaMemcpyFromArray(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyFromArray(dst, src, wOffset, hOffset, count, kind);
}

cudaError_t CONVENTION  cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyArrayToArray(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, count, kind);
}

cudaError_t CONVENTION  cudaMemcpy2D(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy2D(dst, dpitch, src, spitch, width, height, kind);
}

cudaError_t CONVENTION  cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy2DToArray(dst, wOffset, hOffset, src, spitch, width, height, kind);
}

cudaError_t CONVENTION  cudaMemcpy2DFromArray(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy2DFromArray(dst, dpitch, src, wOffset, hOffset, width, height, kind);
}

cudaError_t CONVENTION  cudaMemcpy2DArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy2DArrayToArray(dst, wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, width, height, kind);
}

cudaError_t CONVENTION  cudaMemcpyToSymbol(const char *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyToSymbol(symbol, src, count, offset, kind);
}

cudaError_t CONVENTION  cudaMemcpyFromSymbol(void *dst, const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyFromSymbol(dst, symbol, count, offset, kind);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaMemcpyAsync(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyAsync(dst, src, count, kind, stream);
}

cudaError_t CONVENTION  cudaMemcpyToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyToArrayAsync(dst, wOffset, hOffset, src, count, kind, stream);
}

cudaError_t CONVENTION  cudaMemcpyFromArrayAsync(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyFromArrayAsync(dst, src, wOffset, hOffset, count, kind, stream);
}

cudaError_t CONVENTION  cudaMemcpy2DAsync(void *dst, size_t dpitch, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy2DAsync(dst, dpitch, src, spitch, width, height, kind, stream);
}

cudaError_t CONVENTION  cudaMemcpy2DToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy2DToArrayAsync(dst, wOffset, hOffset, src, spitch, width, height, kind, stream);
}

cudaError_t CONVENTION  cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpy2DFromArrayAsync(dst, dpitch, src, wOffset, hOffset, width, height, kind, stream);
}

cudaError_t CONVENTION  cudaMemcpyToSymbolAsync(const char *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyToSymbolAsync(symbol, src, count, offset, kind, stream);
}

cudaError_t CONVENTION  cudaMemcpyFromSymbolAsync(void *dst, const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaMemcpyFromSymbolAsync(dst, symbol, count, offset, kind, stream);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaMemset(void *devPtr, int value, size_t count) {
	return cuda::CudaRuntimeInterface::get()->cudaMemset(devPtr, value, count);
}

cudaError_t CONVENTION  cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, size_t height) {
	return cuda::CudaRuntimeInterface::get()->cudaMemset2D(devPtr, pitch, value, width, height);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaGetSymbolAddress(void **devPtr, const char *symbol) {
	return cuda::CudaRuntimeInterface::get()->cudaGetSymbolAddress(devPtr, symbol);
}

cudaError_t CONVENTION  cudaGetSymbolSize(size_t *size, const char *symbol) {
	return cuda::CudaRuntimeInterface::get()->cudaGetSymbolSize(size, symbol);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaGetDeviceCount(int *count) {
	return cuda::CudaRuntimeInterface::get()->cudaGetDeviceCount(count);
}

cudaError_t CONVENTION  cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device) {
	return cuda::CudaRuntimeInterface::get()->cudaGetDeviceProperties(prop, device);
}

cudaError_t CONVENTION  cudaChooseDevice(int *device, const struct cudaDeviceProp *prop) {
	return cuda::CudaRuntimeInterface::get()->cudaChooseDevice(device, prop);
}

cudaError_t CONVENTION  cudaSetDevice(int device) {
	return cuda::CudaRuntimeInterface::get()->cudaSetDevice(device);
}

cudaError_t CONVENTION  cudaGetDevice(int *device) {
	return cuda::CudaRuntimeInterface::get()->cudaGetDevice(device);
}

cudaError_t CONVENTION  cudaSetValidDevices(int *device_arr, int len) {
	return cuda::CudaRuntimeInterface::get()->cudaSetValidDevices(device_arr, len);
}

cudaError_t CONVENTION  cudaSetDeviceFlags( int flags ) {
	return cuda::CudaRuntimeInterface::get()->cudaSetDeviceFlags(flags);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaBindTexture(size_t *offset, const struct textureReference *texref, const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size) {
	return cuda::CudaRuntimeInterface::get()->cudaBindTexture(offset, texref, devPtr, desc, size);
}

cudaError_t CONVENTION  cudaBindTexture2D(size_t *offset,const struct textureReference *texref,const void *devPtr, const struct cudaChannelFormatDesc *desc,size_t width, size_t height, size_t pitch) {
	return cuda::CudaRuntimeInterface::get()->cudaBindTexture2D(offset, texref, devPtr, desc, width, height, pitch);
}

cudaError_t CONVENTION  cudaBindTextureToArray(const struct textureReference *texref, const struct cudaArray *array, const struct cudaChannelFormatDesc *desc) {
	return cuda::CudaRuntimeInterface::get()->cudaBindTextureToArray(texref, array, desc);
}

cudaError_t CONVENTION  cudaUnbindTexture(const struct textureReference *texref) {
	return cuda::CudaRuntimeInterface::get()->cudaUnbindTexture(texref);
}

cudaError_t CONVENTION  cudaGetTextureAlignmentOffset(size_t *offset, const struct textureReference *texref) {
	return cuda::CudaRuntimeInterface::get()->cudaGetTextureAlignmentOffset(offset, texref);
}

cudaError_t CONVENTION  cudaGetTextureReference(const struct textureReference **texref, const char *symbol) {
	return cuda::CudaRuntimeInterface::get()->cudaGetTextureReference(texref, symbol);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, const struct cudaArray *array) {
	return cuda::CudaRuntimeInterface::get()->cudaGetChannelDesc(desc, array);
}

struct cudaChannelFormatDesc  CONVENTION cudaCreateChannelDesc(int x, int y, int z, int w, enum cudaChannelFormatKind f) {
	struct cudaChannelFormatDesc desc = {x, y, z, w, f};
	return desc;
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaGetLastError(void) {
	return cuda::CudaRuntimeInterface::get()->cudaGetLastError();
}

#define _CASE(x) case x: return #x;

const char*  CONVENTION cudaGetErrorString(cudaError_t error) {
	switch (error) {
	_CASE(cudaSuccess)
	_CASE(cudaErrorMissingConfiguration)
	_CASE(cudaErrorMemoryAllocation)
	_CASE(cudaErrorInitializationError)
	_CASE(cudaErrorLaunchFailure)
	_CASE(cudaErrorPriorLaunchFailure)
	_CASE(cudaErrorLaunchTimeout)
	_CASE(cudaErrorLaunchOutOfResources)
	_CASE(cudaErrorInvalidDeviceFunction)
	_CASE(cudaErrorInvalidConfiguration)
	_CASE(cudaErrorInvalidDevice)
	_CASE(cudaErrorInvalidValue)
	_CASE(cudaErrorInvalidPitchValue)
	_CASE(cudaErrorInvalidSymbol)
	_CASE(cudaErrorMapBufferObjectFailed)
	_CASE(cudaErrorUnmapBufferObjectFailed)
	_CASE(cudaErrorInvalidHostPointer)
	_CASE(cudaErrorInvalidDevicePointer)
	_CASE(cudaErrorInvalidTexture)
	_CASE(cudaErrorInvalidTextureBinding)
	_CASE(cudaErrorInvalidChannelDescriptor)
	_CASE(cudaErrorInvalidMemcpyDirection)
	_CASE(cudaErrorAddressOfConstant)
	_CASE(cudaErrorTextureFetchFailed)
	_CASE(cudaErrorTextureNotBound)
	_CASE(cudaErrorSynchronizationError)
	_CASE(cudaErrorInvalidFilterSetting)
	_CASE(cudaErrorInvalidNormSetting)
	_CASE(cudaErrorMixedDeviceExecution)
	_CASE(cudaErrorCudartUnloading)
	_CASE(cudaErrorUnknown)
	_CASE(cudaErrorNotYetImplemented)
	_CASE(cudaErrorMemoryValueTooLarge)
	_CASE(cudaErrorInvalidResourceHandle)
	_CASE(cudaErrorNotReady)
	_CASE(cudaErrorInsufficientDriver)
	_CASE(cudaErrorSetOnActiveProcess)
	_CASE(cudaErrorNoDevice)
	_CASE(cudaErrorStartupFailure)
	_CASE(cudaErrorApiFailureBase)
		default:
		break;
	}
	return "unimplemented";
}

#undef _CASE

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaConfigureCall(gridDim, blockDim, sharedMem, stream);
}

cudaError_t CONVENTION  cudaSetupArgument(const void *arg, size_t size, size_t offset) {
	return cuda::CudaRuntimeInterface::get()->cudaSetupArgument(arg, size, offset);
}

cudaError_t CONVENTION  cudaLaunch(const char *entry) {
	return cuda::CudaRuntimeInterface::get()->cudaLaunch(entry);
}

cudaError_t CONVENTION  cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const char *func) {
	return cuda::CudaRuntimeInterface::get()->cudaFuncGetAttributes(attr, func);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaStreamCreate(cudaStream_t *pStream) {
	return cuda::CudaRuntimeInterface::get()->cudaStreamCreate(pStream);
}

cudaError_t CONVENTION  cudaStreamDestroy(cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaStreamDestroy(stream);
}

cudaError_t CONVENTION  cudaStreamSynchronize(cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaStreamSynchronize(stream);
}

cudaError_t CONVENTION  cudaStreamQuery(cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaStreamQuery(stream);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaEventCreate(cudaEvent_t *event) {
	return cuda::CudaRuntimeInterface::get()->cudaEventCreate(event);
}

cudaError_t CONVENTION  cudaEventCreateWithFlags(cudaEvent_t *event, int flags) {
	return cuda::CudaRuntimeInterface::get()->cudaEventCreateWithFlags(event, flags);
}

cudaError_t CONVENTION  cudaEventRecord(cudaEvent_t event, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaEventRecord(event, stream);
}

cudaError_t CONVENTION  cudaEventQuery(cudaEvent_t event) {
	return cuda::CudaRuntimeInterface::get()->cudaEventQuery(event);
}

cudaError_t CONVENTION  cudaEventSynchronize(cudaEvent_t event) {
	return cuda::CudaRuntimeInterface::get()->cudaEventSynchronize(event);
}

cudaError_t CONVENTION  cudaEventDestroy(cudaEvent_t event) {
	return cuda::CudaRuntimeInterface::get()->cudaEventDestroy(event);
}

cudaError_t CONVENTION  cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end) {
	return cuda::CudaRuntimeInterface::get()->cudaEventElapsedTime(ms, start, end);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaSetDoubleForDevice(double *d) {
	return cuda::CudaRuntimeInterface::get()->cudaSetDoubleForDevice(d);
}

cudaError_t CONVENTION  cudaSetDoubleForHost(double *d) {
	return cuda::CudaRuntimeInterface::get()->cudaSetDoubleForHost(d);
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION cudaGLMapBufferObject(void **devPtr, GLuint bufObj) {
	return cuda::CudaRuntimeInterface::get()->cudaGLMapBufferObject(devPtr, bufObj);
}

cudaError_t CONVENTION cudaGLMapBufferObjectAsync(void **devPtr, GLuint bufObj, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaGLMapBufferObjectAsync(devPtr, bufObj, stream);
}

cudaError_t CONVENTION cudaGLRegisterBufferObject(GLuint bufObj) {
	return cuda::CudaRuntimeInterface::get()->cudaGLRegisterBufferObject(bufObj);
}

cudaError_t CONVENTION cudaGLSetBufferObjectMapFlags(GLuint bufObj, unsigned int flags) {
	return cuda::CudaRuntimeInterface::get()->cudaGLSetBufferObjectMapFlags(bufObj, flags);
}

cudaError_t CONVENTION cudaGLSetGLDevice(int device) {
	return cuda::CudaRuntimeInterface::get()->cudaGLSetGLDevice(device);
}

cudaError_t CONVENTION cudaGLUnmapBufferObject(GLuint bufObj) {
	return cuda::CudaRuntimeInterface::get()->cudaGLUnmapBufferObject(bufObj);
}

cudaError_t CONVENTION cudaGLUnmapBufferObjectAsync(GLuint bufObj, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaGLUnmapBufferObjectAsync(bufObj, stream);
}

cudaError_t CONVENTION cudaGLUnregisterBufferObject(GLuint bufObj) {
	return cuda::CudaRuntimeInterface::get()->cudaGLUnregisterBufferObject(bufObj);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION cudaGraphicsGLRegisterBuffer(struct cudaGraphicsResource **resource,
	GLuint buffer, unsigned int flags) {
	return cuda::CudaRuntimeInterface::get()->cudaGraphicsGLRegisterBuffer(
		resource, buffer, flags);
}

cudaError_t CONVENTION cudaGraphicsGLRegisterImage(struct cudaGraphicsResource **resource,
	GLuint image, int target, unsigned int flags) {
	return cuda::CudaRuntimeInterface::get()->cudaGraphicsGLRegisterImage(
		resource, image, target, flags);
}

cudaError_t CONVENTION cudaGraphicsUnregisterResource(
	struct cudaGraphicsResource *resource) {
	return cuda::CudaRuntimeInterface::get()->cudaGraphicsUnregisterResource(
		resource);
}

cudaError_t CONVENTION cudaGraphicsResourceSetMapFlags(
	struct cudaGraphicsResource *resource, unsigned int flags) {
	return cuda::CudaRuntimeInterface::get()->cudaGraphicsResourceSetMapFlags(
		resource, flags);
}

cudaError_t CONVENTION cudaGraphicsMapResources(int count, 
	struct cudaGraphicsResource **resources, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaGraphicsMapResources(
		count, resources, stream);
}

cudaError_t CONVENTION cudaGraphicsUnmapResources(int count, 
	struct cudaGraphicsResource **resources, cudaStream_t stream) {
	return cuda::CudaRuntimeInterface::get()->cudaGraphicsUnmapResources(
		count, resources, stream);
}

cudaError_t CONVENTION cudaGraphicsResourceGetMappedPointer(void **devPtr, 
	size_t *size, struct cudaGraphicsResource *resource) {
	return cuda::CudaRuntimeInterface::get(
		)->cudaGraphicsResourceGetMappedPointer(devPtr, size, resource);
}

cudaError_t CONVENTION cudaGraphicsSubResourceGetMappedArray(
	struct cudaArray **arrayPtr, struct cudaGraphicsResource *resource, 
	unsigned int arrayIndex, unsigned int mipLevel) {
	return cuda::CudaRuntimeInterface::get(
		)->cudaGraphicsSubResourceGetMappedArray(arrayPtr, 
		resource, arrayIndex, mipLevel);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaThreadExit(void) {
	return cuda::CudaRuntimeInterface::get()->cudaThreadExit();
}

cudaError_t CONVENTION  cudaThreadSynchronize(void) {
	return cuda::CudaRuntimeInterface::get()->cudaThreadSynchronize();
}


/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/

cudaError_t CONVENTION  cudaDriverGetVersion(int *driverVersion) {
	return cuda::CudaRuntimeInterface::get()->cudaDriverGetVersion(driverVersion);
}

cudaError_t CONVENTION  cudaRuntimeGetVersion(int *runtimeVersion) {
	return cuda::CudaRuntimeInterface::get()->cudaRuntimeGetVersion(runtimeVersion);
}

/*******************************************************************************
*                                                                              *
*                                                                              *
*                                                                              *
*******************************************************************************/
extern "C" {

void __cudaMutexOperation(int lock) {
	return cuda::CudaRuntimeInterface::get()->cudaMutexOperation(lock);
}

int __cudaSynchronizeThreads(void** one, void* two) {
	return cuda::CudaRuntimeInterface::get()->cudaSynchronizeThreads(one, two);
}

void __cudaTextureFetch(const void* tex, void* index, int integer, void* val) {
	return cuda::CudaRuntimeInterface::get()->cudaTextureFetch(tex, 
		index, integer, val);
}

}

