/*!
	\file CudaDriverApi.cpp

	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements CUDA Driver API functions which call through to the implementation of the
		appropriate CUDA Driver API front-end implementation
	\date Sept 16 2010
	\location somewhere over western Europe
*/

// C++ includes
#include <string>

// Ocelot includes
#include <ocelot/cuda/interface/cuda.h>
#include <ocelot/cuda/interface/CudaDriverFrontend.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>


#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////


// whether CUDA runtime catches exceptions thrown by Ocelot
#define CATCH_RUNTIME_EXCEPTIONS 0

// whether verbose error messages are printed
#define CUDA_VERBOSE 1

// whether debugging messages are printed
#define REPORT_BASE 1

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Error handling macros

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

///////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

// use this to define either a pass-through driver API implementation for testing linkage with the
// shared object or to invoke Ocelot's Driver API frontend
typedef cuda::CudaDriverFrontend CudaApi;

/*********************************
** Initialization
*********************************/
CUresult cuInit(unsigned int Flags) {
	report("CudaDriverApi.cpp - cuInit()");
	return CudaApi::get()->cuInit(Flags);;
}


/*********************************
** Driver Version Query
*********************************/
CUresult cuDriverGetVersion(int *driverVersion) {
	return CudaApi::get()->cuDriverGetVersion(driverVersion);
}


/************************************
**
**    Device management
**
***********************************/

CUresult cuDeviceGet(CUdevice *device, int ordinal) {
	return CudaApi::get()->cuDeviceGet(device, ordinal);
}

CUresult cuDeviceGetCount(int *count) {
	return CudaApi::get()->cuDeviceGetCount(count);
}

CUresult cuDeviceGetName(char *name, int len, CUdevice dev) {
	return CudaApi::get()->cuDeviceGetName(name, len, dev);
}

CUresult cuDeviceComputeCapability(int *major, int *minor, 
	CUdevice dev) {
	return CudaApi::get()->cuDeviceComputeCapability(major, minor, dev);
}

CUresult cuDeviceTotalMem(unsigned int *bytes, CUdevice dev) {
	return CudaApi::get()->cuDeviceTotalMem(bytes, dev);
}

CUresult cuDeviceGetProperties(CUdevprop *prop, 
	CUdevice dev) {
	return CudaApi::get()->cuDeviceGetProperties(prop, dev);
}

CUresult cuDeviceGetAttribute(int *pi, 
	CUdevice_attribute attrib, CUdevice dev) {
	return CudaApi::get()->cuDeviceGetAttribute(pi, attrib, dev);
}


/************************************
**
**    Context management
**
***********************************/

CUresult cuCtxCreate(CUcontext *pctx, unsigned int flags, 
	CUdevice dev ) {
	return CudaApi::get()->cuCtxCreate(pctx, flags, dev);
}

CUresult cuCtxDestroy( CUcontext ctx ) {
	return CudaApi::get()->cuCtxDestroy(ctx);
}

CUresult cuCtxAttach(CUcontext *pctx, unsigned int flags) {
	return CudaApi::get()->cuCtxAttach(pctx, flags);
}

CUresult cuCtxDetach(CUcontext ctx) {
	return CudaApi::get()->cuCtxDetach(ctx);
}

CUresult cuCtxPushCurrent( CUcontext ctx ) {
	return CudaApi::get()->cuCtxPushCurrent(ctx);
}

CUresult cuCtxPopCurrent( CUcontext *pctx ) {
	return CudaApi::get()->cuCtxPopCurrent(pctx);
}

CUresult cuCtxGetDevice(CUdevice *device) {
	return CudaApi::get()->cuCtxGetDevice(device);
}

CUresult cuCtxSynchronize(void) {
	return CudaApi::get()->cuCtxSynchronize();
}


/************************************
**
**    Module management
**
***********************************/

CUresult cuModuleLoad(CUmodule *module, const char *fname) {
	return CudaApi::get()->cuModuleLoad(module, fname);
}

CUresult cuModuleLoadData(CUmodule *module, 
	const void *image) {
	return CudaApi::get()->cuModuleLoadData(module, image);
}

CUresult cuModuleLoadDataEx(CUmodule *module, 
	const void *image, unsigned int numOptions, 
	CUjit_option *options, void **optionValues) {
	return CudaApi::get()->cuModuleLoadDataEx(module, image, numOptions, options, optionValues);
}

CUresult cuModuleLoadFatBinary(CUmodule *module, 
	const void *fatCubin) {
	return CudaApi::get()->cuModuleLoadFatBinary(module, fatCubin);
}

CUresult cuModuleUnload(CUmodule hmod) {
	return CudaApi::get()->cuModuleUnload(hmod);
}

CUresult cuModuleGetFunction(CUfunction *hfunc, 
	CUmodule hmod, const char *name) {
	return CudaApi::get()->cuModuleGetFunction(hfunc, hmod, name);
}

CUresult cuModuleGetGlobal(CUdeviceptr *dptr, 
	unsigned int *bytes, CUmodule hmod, const char *name) {
	return CudaApi::get()->cuModuleGetGlobal(dptr, bytes, hmod, name);
}

CUresult cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, 
	const char *name) {
	return CudaApi::get()->cuModuleGetTexRef(pTexRef, hmod, name);
}


/************************************
**
**    Memory management
**
***********************************/

CUresult cuMemGetInfo(unsigned int *free, 
	unsigned int *total) {
	return CudaApi::get()->cuMemGetInfo(free, total);
}


CUresult cuMemAlloc( CUdeviceptr *dptr, 
	unsigned int bytesize) {
	return CudaApi::get()->cuMemAlloc(dptr, bytesize);
}

CUresult cuMemAllocPitch( CUdeviceptr *dptr, 
			          unsigned int *pPitch,
			          unsigned int WidthInBytes, 
			          unsigned int Height, 
			          unsigned int ElementSizeBytes
			         ) {
	return CudaApi::get()->cuMemAllocPitch(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
}

CUresult cuMemFree(CUdeviceptr dptr) {
	return CudaApi::get()->cuMemFree(dptr);
}

CUresult cuMemGetAddressRange( CUdeviceptr *pbase, 
	unsigned int *psize, CUdeviceptr dptr ) {
	return CudaApi::get()->cuMemGetAddressRange(pbase, psize, dptr);
}


CUresult cuMemAllocHost(void **pp, unsigned int bytesize) {
	return CudaApi::get()->cuMemAllocHost(pp, bytesize);
}

CUresult cuMemFreeHost(void *p) {
	return CudaApi::get()->cuMemFreeHost(p);
}


CUresult cuMemHostAlloc(void **pp, 
	unsigned long long bytesize, unsigned int Flags ) {
	return CudaApi::get()->cuMemHostAlloc(pp, bytesize, Flags);
}


CUresult cuMemHostGetDevicePointer( CUdeviceptr *pdptr, 
	void *p, unsigned int Flags ) {
	return CudaApi::get()->cuMemHostGetDevicePointer(pdptr, p, Flags);
}

CUresult cuMemHostGetFlags( unsigned int *pFlags, void *p ) {
	return CudaApi::get()->cuMemHostGetFlags(pFlags, p);
}


/************************************
**
**    Synchronous Memcpy
**
** Intra-device memcpy's done with these functions may execute 
**	in parallel with the CPU,
** but if host memory is involved, they wait until the copy is 
**	done before returning.
**
***********************************/

// 1D functions
// system <-> device memory
CUresult cuMemcpyHtoD (CUdeviceptr dstDevice, 
	const void *srcHost, unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyHtoD(dstDevice, srcHost, ByteCount);
}

CUresult cuMemcpyDtoH (void *dstHost, CUdeviceptr srcDevice, 
	unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyDtoH(dstHost, srcDevice, ByteCount);
}


// device <-> device memory
CUresult cuMemcpyDtoD (CUdeviceptr dstDevice, 
	CUdeviceptr srcDevice, unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyDtoD(dstDevice, srcDevice, ByteCount);
}


// device <-> array memory
CUresult cuMemcpyDtoA ( CUarray dstArray, 
	unsigned int dstIndex, CUdeviceptr srcDevice, 
	unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyDtoA(dstArray, dstIndex, srcDevice, ByteCount);
}

CUresult cuMemcpyAtoD ( CUdeviceptr dstDevice, 
	CUarray hSrc, unsigned int SrcIndex, unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyAtoD(dstDevice, hSrc, SrcIndex, ByteCount);
}


// system <-> array memory
CUresult cuMemcpyHtoA( CUarray dstArray, 
	unsigned int dstIndex, const void *pSrc, 
	unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyHtoA(dstArray, dstIndex, pSrc, ByteCount);
}

CUresult cuMemcpyAtoH( void *dstHost, CUarray srcArray, 
	unsigned int srcIndex, unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyAtoH(dstHost, srcArray, srcIndex, ByteCount);
}


// array <-> array memory
CUresult cuMemcpyAtoA( CUarray dstArray, 
	unsigned int dstIndex, CUarray srcArray, unsigned int srcIndex, 
	unsigned int ByteCount ) {
	return CudaApi::get()->cuMemcpyAtoA(dstArray, dstIndex, srcArray, srcIndex, ByteCount);
}


// 2D memcpy

CUresult cuMemcpy2D( const CUDA_MEMCPY2D *pCopy ) {
	return CudaApi::get()->cuMemcpy2D(pCopy);
}

CUresult cuMemcpy2DUnaligned( const CUDA_MEMCPY2D *pCopy ) {
	return CudaApi::get()->cuMemcpy2DUnaligned(pCopy);
}


// 3D memcpy

CUresult cuMemcpy3D( const CUDA_MEMCPY3D *pCopy ) {
	return CudaApi::get()->cuMemcpy3D(pCopy);
}


/************************************
**
**    Asynchronous Memcpy
**
** Any host memory involved must be DMA'able (e.g., 
** allocated with cuMemAllocHost).
** memcpy's done with these functions execute in parallel with 
** the CPU and, if
** the hardware is available, may execute in parallel with the GPU.
** Asynchronous memcpy must be accompanied by appropriate stream 
** synchronization.
**
***********************************/

// 1D functions
// system <-> device memory
CUresult cuMemcpyHtoDAsync (CUdeviceptr dstDevice, 
	const void *srcHost, unsigned int ByteCount, CUstream hStream ) {
	return CudaApi::get()->cuMemcpyHtoDAsync(dstDevice, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyDtoHAsync (void *dstHost, 
	CUdeviceptr srcDevice, unsigned int ByteCount, CUstream hStream ) {
	return CudaApi::get()->cuMemcpyDtoHAsync(dstHost, srcDevice, ByteCount, hStream);
}


// system <-> array memory
CUresult cuMemcpyHtoAAsync( CUarray dstArray, 
	unsigned int dstIndex, const void *pSrc, 
	unsigned int ByteCount, CUstream hStream ) {
	return CudaApi::get()->cuMemcpyHtoAAsync(dstArray, dstIndex, pSrc, ByteCount, hStream);
}

CUresult cuMemcpyAtoHAsync( void *dstHost, CUarray srcArray, 
	unsigned int srcIndex, unsigned int ByteCount, 
	CUstream hStream ) {
	return CudaApi::get()->cuMemcpyAtoHAsync(dstHost, srcArray, srcIndex, ByteCount, hStream);
}

// 2D memcpy
CUresult cuMemcpy2DAsync( const CUDA_MEMCPY2D *pCopy, 
	CUstream hStream ) {
	return CudaApi::get()->cuMemcpy2DAsync(pCopy, hStream);
}


// 3D memcpy
CUresult cuMemcpy3DAsync( const CUDA_MEMCPY3D *pCopy, 
	CUstream hStream ) {
	return CudaApi::get()->cuMemcpy3DAsync(pCopy, hStream);
}


/************************************
**
**    Memset
**
***********************************/
CUresult cuMemsetD8( CUdeviceptr dstDevice, 
	unsigned char uc, unsigned int N ) {
	return CudaApi::get()->cuMemsetD8(dstDevice, uc, N);
}

CUresult cuMemsetD16( CUdeviceptr dstDevice, 
	unsigned short us, unsigned int N ) {
	return CudaApi::get()->cuMemsetD16(dstDevice, us, N);
}

CUresult cuMemsetD32( CUdeviceptr dstDevice, 
	unsigned int ui, unsigned int N ) {
	return CudaApi::get()->cuMemsetD32(dstDevice, ui, N);
}


CUresult cuMemsetD2D8( CUdeviceptr dstDevice,
	unsigned int dstPitch, unsigned char uc, unsigned int Width, 
	unsigned int Height ) {
	return CudaApi::get()->cuMemsetD2D8(dstDevice, dstPitch, uc, Width, Height);
}

CUresult cuMemsetD2D16( CUdeviceptr dstDevice, 
	unsigned int dstPitch, unsigned short us, unsigned int Width, 
	unsigned int Height ) {
	return CudaApi::get()->cuMemsetD2D16(dstDevice, dstPitch, us, Width, Height);
}

CUresult cuMemsetD2D32( CUdeviceptr dstDevice, 
	unsigned int dstPitch, unsigned int ui, unsigned int Width, 
	unsigned int Height ) {
	return CudaApi::get()->cuMemsetD2D32(dstDevice, dstPitch, ui, Width, Height);
}


/************************************
**
**    Function management
**
***********************************/


CUresult cuFuncSetBlockShape (CUfunction hfunc, int x, 
	int y, int z) {
	return CudaApi::get()->cuFuncSetBlockShape(hfunc, x, y, z);
}

CUresult cuFuncSetSharedSize (CUfunction hfunc, 
	unsigned int bytes) {
	return CudaApi::get()->cuFuncSetSharedSize(hfunc, bytes);
}

CUresult cuFuncGetAttribute (int *pi, 
	CUfunction_attribute attrib, CUfunction hfunc) {
	return CudaApi::get()->cuFuncGetAttribute(pi, attrib, hfunc);
}


/************************************
**
**    Array management 
**
***********************************/

CUresult cuArrayCreate( CUarray *pHandle, 
	const CUDA_ARRAY_DESCRIPTOR *pAllocateArray ) {
	return CudaApi::get()->cuArrayCreate(pHandle, pAllocateArray);
}

CUresult cuArrayGetDescriptor( 
	CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray ) {
	return CudaApi::get()->cuArrayGetDescriptor(pArrayDescriptor, hArray);
}

CUresult cuArrayDestroy( CUarray hArray ) {
	return CudaApi::get()->cuArrayDestroy(hArray);
}


CUresult cuArray3DCreate( CUarray *pHandle, 
	const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray ) {
	return CudaApi::get()->cuArray3DCreate(pHandle, pAllocateArray);
}

CUresult cuArray3DGetDescriptor( 
	CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray ) {
	return CudaApi::get()->cuArray3DGetDescriptor(pArrayDescriptor, hArray);
}



/************************************
**
**    Texture reference management
**
***********************************/
CUresult cuTexRefCreate( CUtexref *pTexRef ) {
	return CudaApi::get()->cuTexRefCreate(pTexRef);
}

CUresult cuTexRefDestroy( CUtexref hTexRef ) {
	return CudaApi::get()->cuTexRefDestroy(hTexRef);
}


CUresult cuTexRefSetArray( CUtexref hTexRef, CUarray hArray, 
	unsigned int Flags ) {
	return CudaApi::get()->cuTexRefSetArray(hTexRef, hArray, Flags);
}

CUresult cuTexRefSetAddress( unsigned int *ByteOffset, 
	CUtexref hTexRef, CUdeviceptr dptr, unsigned int bytes ) {
	return CudaApi::get()->cuTexRefSetAddress(ByteOffset, hTexRef, dptr, bytes);
}

CUresult cuTexRefSetAddress2D( CUtexref hTexRef, 
	const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, 
	unsigned int Pitch) {
	return CudaApi::get()->cuTexRefSetAddress2D(hTexRef, desc, dptr, Pitch);
}

CUresult cuTexRefSetFormat( CUtexref hTexRef, 
	CUarray_format fmt, int NumPackedComponents ) {
	return CudaApi::get()->cuTexRefSetFormat(hTexRef, fmt, NumPackedComponents);
}

CUresult cuTexRefSetAddressMode( CUtexref hTexRef, int dim, 
	CUaddress_mode am ) {
	return CudaApi::get()->cuTexRefSetAddressMode(hTexRef, dim, am);
}

CUresult cuTexRefSetFilterMode( CUtexref hTexRef, 
	CUfilter_mode fm ) {
	return CudaApi::get()->cuTexRefSetFilterMode(hTexRef, fm);
}

CUresult cuTexRefSetFlags( CUtexref hTexRef, 
	unsigned int Flags ) {
	return CudaApi::get()->cuTexRefSetFlags(hTexRef, Flags);
}


CUresult cuTexRefGetAddress( CUdeviceptr *pdptr, 
	CUtexref hTexRef ) {
	return CudaApi::get()->cuTexRefGetAddress(pdptr, hTexRef);
}

CUresult cuTexRefGetArray( CUarray *phArray, 
	CUtexref hTexRef ) {
	return CudaApi::get()->cuTexRefGetArray(phArray, hTexRef);
}

CUresult cuTexRefGetAddressMode( CUaddress_mode *pam, 
	CUtexref hTexRef, int dim ) {
	return CudaApi::get()->cuTexRefGetAddressMode(pam, hTexRef, dim);
}

CUresult cuTexRefGetFilterMode( CUfilter_mode *pfm, 
	CUtexref hTexRef ) {
	return CudaApi::get()->cuTexRefGetFilterMode(pfm, hTexRef);
}

CUresult cuTexRefGetFormat( CUarray_format *pFormat, 
	int *pNumChannels, CUtexref hTexRef ) {
	return CudaApi::get()->cuTexRefGetFormat(pFormat, pNumChannels, hTexRef);
}

CUresult cuTexRefGetFlags( unsigned int *pFlags, 
	CUtexref hTexRef ) {
	return CudaApi::get()->cuTexRefGetFlags(pFlags, hTexRef);
}


/************************************
**
**    Parameter management
**
***********************************/

CUresult cuParamSetSize (CUfunction hfunc, 
	unsigned int numbytes) {
	return CudaApi::get()->cuParamSetSize(hfunc, numbytes);
}

CUresult cuParamSeti    (CUfunction hfunc, int offset, 
	unsigned int value) {
	return CudaApi::get()->cuParamSeti(hfunc, offset, value);
}

CUresult cuParamSetf    (CUfunction hfunc, int offset, 
	float value) {
	return CudaApi::get()->cuParamSetf(hfunc, offset, value);
}

CUresult cuParamSetv    (CUfunction hfunc, int offset, 
	void * ptr, unsigned int numbytes) {
	return CudaApi::get()->cuParamSetv(hfunc, offset, ptr, numbytes);
}

CUresult cuParamSetTexRef(CUfunction hfunc, int texunit, 
	CUtexref hTexRef) {
	return CudaApi::get()->cuParamSetTexRef(hfunc, texunit, hTexRef);
}


/************************************
**
**    Launch functions
**
***********************************/

CUresult cuLaunch ( CUfunction f ) {
	return CudaApi::get()->cuLaunch(f);
}

CUresult cuLaunchGrid (CUfunction f, int grid_width, 
	int grid_height) {
	return CudaApi::get()->cuLaunchGrid(f, grid_width, grid_height);
}

CUresult cuLaunchGridAsync( CUfunction f, int grid_width, 
	int grid_height, CUstream hStream ) {
	return CudaApi::get()->cuLaunchGridAsync(f, grid_width, grid_height, hStream);
}


/************************************
**
**    Events
**
***********************************/
CUresult cuEventCreate( CUevent *phEvent, 
	unsigned int Flags ) {
	return CudaApi::get()->cuEventCreate(phEvent, Flags);
}

CUresult cuEventRecord( CUevent hEvent, CUstream hStream ) {
	return CudaApi::get()->cuEventRecord(hEvent, hStream);
}

CUresult cuEventQuery( CUevent hEvent ) {
	return CudaApi::get()->cuEventQuery(hEvent);
}

CUresult cuEventSynchronize( CUevent hEvent ) {
	return CudaApi::get()->cuEventSynchronize(hEvent);
}

CUresult cuEventDestroy( CUevent hEvent ) {
	return CudaApi::get()->cuEventDestroy(hEvent);
}

CUresult cuEventElapsedTime( float *pMilliseconds, 
	CUevent hStart, CUevent hEnd ) {
	return CudaApi::get()->cuEventElapsedTime(pMilliseconds, hStart, hEnd);
}


/************************************
**
**    Streams
**
***********************************/
CUresult cuStreamCreate( CUstream *phStream, 
	unsigned int Flags ) {
	return CudaApi::get()->cuStreamCreate(phStream, Flags);
}

CUresult cuStreamQuery( CUstream hStream ) {
	return CudaApi::get()->cuStreamQuery(hStream);
}

CUresult cuStreamSynchronize( CUstream hStream ) {
	return CudaApi::get()->cuStreamSynchronize(hStream);
}

CUresult cuStreamDestroy( CUstream hStream ) {
	return CudaApi::get()->cuStreamDestroy(hStream);
}


/************************************
**
**    Graphics
**
***********************************/
CUresult cuGraphicsUnregisterResource(
	CUgraphicsResource resource) {
	return CudaApi::get()->cuGraphicsUnregisterResource(resource);
}

CUresult cuGraphicsSubResourceGetMappedArray(
	CUarray *pArray, CUgraphicsResource resource, 
	unsigned int arrayIndex, unsigned int mipLevel ) {
	return CudaApi::get()->cuGraphicsSubResourceGetMappedArray(pArray, resource, arrayIndex, mipLevel);
}

CUresult cuGraphicsResourceGetMappedPointer(
	CUdeviceptr *pDevPtr, unsigned int *pSize, 
	CUgraphicsResource resource ) {
	return CudaApi::get()->cuGraphicsResourceGetMappedPointer(pDevPtr, pSize, resource);
}

CUresult cuGraphicsResourceSetMapFlags(
	CUgraphicsResource resource, unsigned int flags ) {
	return CudaApi::get()->cuGraphicsResourceSetMapFlags(resource, flags);
}
 
CUresult cuGraphicsMapResources(unsigned int count, 
	CUgraphicsResource *resources, CUstream hStream ) {
	return CudaApi::get()->cuGraphicsMapResources(count, resources, hStream);
}

CUresult cuGraphicsUnmapResources(unsigned int count, 
	CUgraphicsResource *resources, CUstream hStream ) {
	return CudaApi::get()->cuGraphicsUnmapResources(count, resources, hStream);
}


/************************************
**
**    OpenGL
**
***********************************/
CUresult cuGLInit() {
	return CudaApi::get()->cuGLInit();
}

CUresult cuGLCtxCreate(CUcontext *pCtx, 
	unsigned int Flags, CUdevice device) {
	return CudaApi::get()->cuGLCtxCreate(pCtx, Flags, device);
}

CUresult cuGraphicsGLRegisterBuffer( 
	CUgraphicsResource *pCudaResource, unsigned int buffer, 
	unsigned int Flags ) {
	return CudaApi::get()->cuGraphicsGLRegisterBuffer(pCudaResource, buffer, Flags);
}

CUresult cuGraphicsGLRegisterImage( 
	CUgraphicsResource *pCudaResource, unsigned int image, 
	int target, unsigned int Flags) {
	return CudaApi::get()->cuGraphicsGLRegisterImage(pCudaResource, image, target, Flags);
}


////////////////////////////////////////////////////////////////////////////////////////////////////

