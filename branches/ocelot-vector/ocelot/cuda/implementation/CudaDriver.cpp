/*! \file CudaDriver.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Friday March 26, 2010
	\brief The source file for the CudaDriver class.
*/
#ifndef CUDA_DRIVER_CPP_INCLUDED
#define CUDA_DRIVER_CPP_INCLUDED

// Ocelot includes
#include <ocelot/cuda/interface/CudaDriver.h>

// hydrazine includes
#include <hydrazine/interface/Casts.h>
#include <hydrazine/implementation/debug.h>

// Linux system headers
#include <dlfcn.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace cuda
{
	CudaDriver::Interface::Interface() : _driver( 0 )
	{
	
	}

	CudaDriver::Interface::~Interface()
	{
		if( _driver )
		{
			report( "Closing libcuda.so" );
			dlclose( _driver );
		}
	}
	
	void CudaDriver::Interface::load()
	{
		if( _driver != 0 ) return;
		
		report( "Loading libcuda.so" );
		_driver = dlopen( "libcuda.so", RTLD_LAZY );
		if( _driver == 0 )
		{
			report( "Failed to load cuda driver." );
			report( "  " << dlerror() );
			return;
		}
		
		hydrazine::bit_cast( cuInit, dlsym( _driver, "cuInit" ) );
		hydrazine::bit_cast( cuDriverGetVersion, dlsym( _driver, "cuDriverGetVersion" ) );
		hydrazine::bit_cast( cuDeviceGet, dlsym( _driver, "cuDeviceGet" ) );
		hydrazine::bit_cast( cuDeviceGetCount, dlsym( _driver, "cuDeviceGetCount" ) );
		hydrazine::bit_cast( cuDeviceGetName, dlsym( _driver, "cuDeviceGetName" ) );
		hydrazine::bit_cast( cuDeviceComputeCapability, dlsym( _driver, "cuDeviceComputeCapability" ) );
		hydrazine::bit_cast( cuDeviceTotalMem, dlsym( _driver, "cuDeviceTotalMem" ) );
		hydrazine::bit_cast( cuDeviceGetProperties, dlsym( _driver, "cuDeviceGetProperties" ) );
		hydrazine::bit_cast( cuDeviceGetAttribute, dlsym( _driver, "cuDeviceGetAttribute" ) );
		hydrazine::bit_cast( cuCtxCreate, dlsym( _driver, "cuCtxCreate" ) );
		hydrazine::bit_cast( cuCtxDestroy, dlsym( _driver, "cuCtxDestroy" ) );
		hydrazine::bit_cast( cuCtxAttach, dlsym( _driver, "cuCtxAttach" ) );
		hydrazine::bit_cast( cuCtxDetach, dlsym( _driver, "cuCtxDetach" ) );
		hydrazine::bit_cast( cuCtxPushCurrent, dlsym( _driver, "cuCtxPushCurrent" ) );
		hydrazine::bit_cast( cuCtxPopCurrent, dlsym( _driver, "cuCtxPopCurrent" ) );
		hydrazine::bit_cast( cuCtxGetDevice, dlsym( _driver, "cuCtxGetDevice" ) );
		hydrazine::bit_cast( cuCtxSynchronize, dlsym( _driver, "cuCtxSynchronize" ) );
		hydrazine::bit_cast( cuModuleLoad, dlsym( _driver, "cuModuleLoad" ) );
		hydrazine::bit_cast( cuModuleLoadData, dlsym( _driver, "cuModuleLoadData" ) );
		hydrazine::bit_cast( cuModuleLoadDataEx, dlsym( _driver, "cuModuleLoadDataEx" ) );
		hydrazine::bit_cast( cuModuleLoadFatBinary, dlsym( _driver, "cuModuleLoadFatBinary" ) );
		hydrazine::bit_cast( cuModuleUnload, dlsym( _driver, "cuModuleUnload" ) );
		hydrazine::bit_cast( cuModuleGetFunction, dlsym( _driver, "cuModuleGetFunction" ) );
		hydrazine::bit_cast( cuModuleGetGlobal, dlsym( _driver, "cuModuleGetGlobal" ) );
		hydrazine::bit_cast( cuModuleGetTexRef, dlsym( _driver, "cuModuleGetTexRef" ) );
		hydrazine::bit_cast( cuMemGetInfo, dlsym( _driver, "cuMemGetInfo" ) );
		hydrazine::bit_cast( cuMemAlloc, dlsym( _driver, "cuMemAlloc" ) );
		hydrazine::bit_cast( cuMemAllocPitch, dlsym( _driver, "cuMemAllocPitch" ) );
		hydrazine::bit_cast( cuMemFree, dlsym( _driver, "cuMemFree" ) );
		hydrazine::bit_cast( cuMemGetAddressRange, dlsym( _driver, "cuMemGetAddressRange" ) );
		hydrazine::bit_cast( cuMemAllocHost, dlsym( _driver, "cuMemAllocHost" ) );
		hydrazine::bit_cast( cuMemFreeHost, dlsym( _driver, "cuMemFreeHost" ) );
		hydrazine::bit_cast( cuMemHostAlloc, dlsym( _driver, "cuMemHostAlloc" ) );
		hydrazine::bit_cast( cuMemHostGetDevicePointer, dlsym( _driver, "cuMemHostGetDevicePointer" ) );
		hydrazine::bit_cast( cuMemHostGetFlags, dlsym( _driver, "cuMemHostGetFlags" ) );
		hydrazine::bit_cast( cuMemcpyHtoD, dlsym( _driver, "cuMemcpyHtoD" ) );
		hydrazine::bit_cast( cuMemcpyDtoH, dlsym( _driver, "cuMemcpyDtoH" ) );
		hydrazine::bit_cast( cuMemcpyDtoD, dlsym( _driver, "cuMemcpyDtoD" ) );
		hydrazine::bit_cast( cuMemcpyDtoA, dlsym( _driver, "cuMemcpyDtoA" ) );
		hydrazine::bit_cast( cuMemcpyAtoD, dlsym( _driver, "cuMemcpyAtoD" ) );
		hydrazine::bit_cast( cuMemcpyHtoA, dlsym( _driver, "cuMemcpyHtoA" ) );
		hydrazine::bit_cast( cuMemcpyAtoH, dlsym( _driver, "cuMemcpyAtoH" ) );
		hydrazine::bit_cast( cuMemcpyAtoA, dlsym( _driver, "cuMemcpyAtoA" ) );
		hydrazine::bit_cast( cuMemcpy2D, dlsym( _driver, "cuMemcpy2D" ) );
		hydrazine::bit_cast( cuMemcpy2DUnaligned, dlsym( _driver, "cuMemcpy2DUnaligned" ) );
		hydrazine::bit_cast( cuMemcpy3D, dlsym( _driver, "cuMemcpy3D" ) );
		hydrazine::bit_cast( cuMemcpyHtoDAsync, dlsym( _driver, "cuMemcpyHtoDAsync" ) );
		hydrazine::bit_cast( cuMemcpyDtoHAsync, dlsym( _driver, "cuMemcpyDtoHAsync" ) );
		hydrazine::bit_cast( cuMemcpyHtoAAsync, dlsym( _driver, "cuMemcpyHtoAAsync" ) );
		hydrazine::bit_cast( cuMemcpyAtoHAsync, dlsym( _driver, "cuMemcpyAtoHAsync" ) );
		hydrazine::bit_cast( cuMemcpy2DAsync, dlsym( _driver, "cuMemcpy2DAsync" ) );
		hydrazine::bit_cast( cuMemcpy3DAsync, dlsym( _driver, "cuMemcpy3DAsync" ) );
		hydrazine::bit_cast( cuMemsetD8, dlsym( _driver, "cuMemsetD8" ) );
		hydrazine::bit_cast( cuMemsetD16, dlsym( _driver, "cuMemsetD16" ) );
		hydrazine::bit_cast( cuMemsetD32, dlsym( _driver, "cuMemsetD32" ) );
		hydrazine::bit_cast( cuMemsetD2D8, dlsym( _driver, "cuMemsetD2D8" ) );
		hydrazine::bit_cast( cuMemsetD2D16, dlsym( _driver, "cuMemsetD2D16" ) );
		hydrazine::bit_cast( cuMemsetD2D32, dlsym( _driver, "cuMemsetD2D32" ) );
		hydrazine::bit_cast( cuFuncSetBlockShape, dlsym( _driver, "cuFuncSetBlockShape" ) );
		hydrazine::bit_cast( cuFuncSetSharedSize, dlsym( _driver, "cuFuncSetSharedSize" ) );
		hydrazine::bit_cast( cuFuncGetAttribute, dlsym( _driver, "cuFuncGetAttribute" ) );
		hydrazine::bit_cast( cuArrayCreate, dlsym( _driver, "cuArrayCreate" ) );
		hydrazine::bit_cast( cuArrayGetDescriptor, dlsym( _driver, "cuArrayGetDescriptor" ) );
		hydrazine::bit_cast( cuArrayDestroy, dlsym( _driver, "cuArrayDestroy" ) );
		hydrazine::bit_cast( cuArray3DCreate, dlsym( _driver, "cuArray3DCreate" ) );
		hydrazine::bit_cast( cuArray3DGetDescriptor, dlsym( _driver, "cuArray3DGetDescriptor" ) );
		hydrazine::bit_cast( cuTexRefCreate, dlsym( _driver, "cuTexRefCreate" ) );
		hydrazine::bit_cast( cuTexRefDestroy, dlsym( _driver, "cuTexRefDestroy" ) );
		hydrazine::bit_cast( cuTexRefSetArray, dlsym( _driver, "cuTexRefSetArray" ) );
		hydrazine::bit_cast( cuTexRefSetAddress, dlsym( _driver, "cuTexRefSetAddress" ) );
		hydrazine::bit_cast( cuTexRefSetAddress2D, dlsym( _driver, "cuTexRefSetAddress2D" ) );
		hydrazine::bit_cast( cuTexRefSetFormat, dlsym( _driver, "cuTexRefSetFormat" ) );
		hydrazine::bit_cast( cuTexRefSetAddressMode, dlsym( _driver, "cuTexRefSetAddressMode" ) );
		hydrazine::bit_cast( cuTexRefSetFilterMode, dlsym( _driver, "cuTexRefSetFilterMode" ) );
		hydrazine::bit_cast( cuTexRefSetFlags, dlsym( _driver, "cuTexRefSetFlags" ) );
		hydrazine::bit_cast( cuTexRefGetAddress, dlsym( _driver, "cuTexRefGetAddress" ) );
		hydrazine::bit_cast( cuTexRefGetArray, dlsym( _driver, "cuTexRefGetArray" ) );
		hydrazine::bit_cast( cuTexRefGetAddressMode, dlsym( _driver, "cuTexRefGetAddressMode" ) );
		hydrazine::bit_cast( cuTexRefGetFilterMode, dlsym( _driver, "cuTexRefGetFilterMode" ) );
		hydrazine::bit_cast( cuTexRefGetFormat, dlsym( _driver, "cuTexRefGetFormat" ) );
		hydrazine::bit_cast( cuTexRefGetFlags, dlsym( _driver, "cuTexRefGetFlags" ) );
		hydrazine::bit_cast( cuParamSetSize, dlsym( _driver, "cuParamSetSize" ) );
		hydrazine::bit_cast( cuParamSeti, dlsym( _driver, "cuParamSeti" ) );
		hydrazine::bit_cast( cuParamSetf, dlsym( _driver, "cuParamSetf" ) );
		hydrazine::bit_cast( cuParamSetv, dlsym( _driver, "cuParamSetv" ) );
		hydrazine::bit_cast( cuParamSetTexRef, dlsym( _driver, "cuParamSetTexRef" ) );
		hydrazine::bit_cast( cuLaunch, dlsym( _driver, "cuLaunch" ) );
		hydrazine::bit_cast( cuLaunchGrid, dlsym( _driver, "cuLaunchGrid" ) );
		hydrazine::bit_cast( cuLaunchGridAsync, dlsym( _driver, "cuLaunchGridAsync" ) );
		hydrazine::bit_cast( cuEventCreate, dlsym( _driver, "cuEventCreate" ) );
		hydrazine::bit_cast( cuEventRecord, dlsym( _driver, "cuEventRecord" ) );
		hydrazine::bit_cast( cuEventQuery, dlsym( _driver, "cuEventQuery" ) );
		hydrazine::bit_cast( cuEventSynchronize, dlsym( _driver, "cuEventSynchronize" ) );
		hydrazine::bit_cast( cuEventDestroy, dlsym( _driver, "cuEventDestroy" ) );
		hydrazine::bit_cast( cuEventElapsedTime, dlsym( _driver, "cuEventElapsedTime" ) );
		hydrazine::bit_cast( cuStreamCreate, dlsym( _driver, "cuStreamCreate" ) );
		hydrazine::bit_cast( cuStreamQuery, dlsym( _driver, "cuStreamQuery" ) );
		hydrazine::bit_cast( cuStreamSynchronize, dlsym( _driver, "cuStreamSynchronize" ) );
		hydrazine::bit_cast( cuStreamDestroy, dlsym( _driver, "cuStreamDestroy" ) );

		hydrazine::bit_cast( cuGLInit, dlsym( _driver, "cuGLInit" ) );
		hydrazine::bit_cast( cuGLCtxCreate, dlsym( _driver, "cuGLCtxCreate" ) );
		hydrazine::bit_cast( cuGLRegisterBufferObject, dlsym( _driver, "cuGLRegisterBufferObject" ) );
		hydrazine::bit_cast( cuGLMapBufferObject, dlsym( _driver, "cuGLMapBufferObject" ) );
		hydrazine::bit_cast( cuGLUnmapBufferObject, dlsym( _driver, "cuGLUnmapBufferObject" ) );
		hydrazine::bit_cast( cuGLUnregisterBufferObject, dlsym( _driver, "cuGLUnregisterBufferObject" ) );
		hydrazine::bit_cast( cuGLSetBufferObjectMapFlags, dlsym( _driver, "cuGLSetBufferObjectMapFlags" ) );
		hydrazine::bit_cast( cuGLMapBufferObjectAsync, dlsym( _driver, "cuGLMapBufferObjectAsync" ) );
		hydrazine::bit_cast( cuGLUnmapBufferObjectAsync, dlsym( _driver, "cuGLUnmapBufferObjectAsync" ) );

		(*cuDriverGetVersion)(&_version);

		report(" Driver version is: " << _version);

	}

	bool CudaDriver::Interface::loaded() const
	{
		return _driver != 0;
	}

	CudaDriver::Interface CudaDriver::_interface;

	CUresult CudaDriver::cuInit(unsigned int Flags)
	{
		_interface.load();
		if( !_interface.loaded() ) return CUDA_ERROR_NO_DEVICE;
		return (*_interface.cuInit)(Flags);
	}

	CUresult CudaDriver::cuDriverGetVersion(int *driverVersion)
	{
		assertM( _interface.loaded(), 
			"cuDriverGetVersion called without loading CUDA driver.");
		return (*_interface.cuDriverGetVersion)(driverVersion);
	}

	CUresult CudaDriver::cuDeviceGet(CUdevice *device, int ordinal)
	{
		assertM( _interface.loaded(), 
			"cuDeviceGet called without loading CUDA driver.");
		return (*_interface.cuDeviceGet)(device, ordinal);
	}

	CUresult CudaDriver::cuDeviceGetCount(int *count)
	{
		if( !_interface.loaded() )
		{
			*count = 0;
			return CUDA_SUCCESS;
		}
		return (*_interface.cuDeviceGetCount)(count);
	}

	CUresult CudaDriver::cuDeviceGetName(char *name, int len, CUdevice dev)
	{
		assertM( _interface.loaded(), 
			"cuDeviceGetName called without loading CUDA driver.");
		return (*_interface.cuDeviceGetName)(name, len, dev);
	}

	CUresult CudaDriver::cuDeviceComputeCapability(int *major, int *minor, CUdevice dev)
	{
		assertM( _interface.loaded(), 
			"cuDeviceComputeCapability called without loading CUDA driver.");
		return (*_interface.cuDeviceComputeCapability)(major, minor, dev);
	}

	CUresult CudaDriver::cuDeviceTotalMem(unsigned int *bytes, CUdevice dev)
	{
		assertM( _interface.loaded(), 
			"cuDeviceTotalMem called without loading CUDA driver.");
		return (*_interface.cuDeviceTotalMem)(bytes, dev);
	}

	CUresult CudaDriver::cuDeviceGetProperties(CUdevprop *prop, CUdevice dev)
	{
		assertM( _interface.loaded(), 
			"cuDeviceGetProperties called without loading CUDA driver.");
		return (*_interface.cuDeviceGetProperties)(prop, dev);
	}

	CUresult CudaDriver::cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev)
	{
		assertM( _interface.loaded(), 
			"cuDeviceGetAttribute called without loading CUDA driver.");
		return (*_interface.cuDeviceGetAttribute)(pi, attrib, dev);
	}

	CUresult CudaDriver::cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev )
	{
		assertM( _interface.loaded(), 
			"cuCtxCreate called without loading CUDA driver.");
		return (*_interface.cuCtxCreate)(pctx, flags, dev);
	}

	CUresult CudaDriver::cuCtxDestroy( CUcontext ctx )
	{
		assertM( _interface.loaded(), 
			"cuCtxDestroy called without loading CUDA driver.");
		return (*_interface.cuCtxDestroy)(ctx);
	}

	CUresult CudaDriver::cuCtxAttach(CUcontext *pctx, unsigned int flags)
	{
		assertM( _interface.loaded(), 
			"cuCtxAttach called without loading CUDA driver.");
		return (*_interface.cuCtxAttach)(pctx, flags);
	}

	CUresult CudaDriver::cuCtxDetach(CUcontext ctx)
	{
		assertM( _interface.loaded(), 
			"cuCtxDetach called without loading CUDA driver.");
		return (*_interface.cuCtxDetach)(ctx);
	}

	CUresult CudaDriver::cuCtxPushCurrent( CUcontext ctx )
	{
		assertM( _interface.loaded(), 
			"cuCtxPushCurrent called without loading CUDA driver.");
		return (*_interface.cuCtxPushCurrent)(ctx);
	}

	CUresult CudaDriver::cuCtxPopCurrent( CUcontext *pctx )
	{
		assertM( _interface.loaded(), 
			"cuCtxPopCurrent called without loading CUDA driver.");
		return (*_interface.cuCtxPopCurrent)(pctx);
	}

	CUresult CudaDriver::cuCtxGetDevice(CUdevice *device)
	{
		assertM( _interface.loaded(), 
			"cuCtxGetDevice called without loading CUDA driver.");
		return (*_interface.cuCtxGetDevice)(device);
	}

	CUresult CudaDriver::cuCtxSynchronize(void)
	{
		assertM( _interface.loaded(), 
			"cuCtxSynchronize called without loading CUDA driver.");
		return (*_interface.cuCtxSynchronize)();
	}

	CUresult CudaDriver::cuModuleLoad(CUmodule *module, const char *fname)
	{
		assertM( _interface.loaded(), 
			"cuModuleLoad called without loading CUDA driver.");
		return (*_interface.cuModuleLoad)(module, fname);
	}

	CUresult CudaDriver::cuModuleLoadData(CUmodule *module, const void *image)
	{
		assertM( _interface.loaded(), 
			"cuModuleLoadData called without loading CUDA driver.");
		return (*_interface.cuModuleLoadData)(module, image);
	}

	CUresult CudaDriver::cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues)
	{
		assertM( _interface.loaded(), 
			"cuModuleLoadDataEx called without loading CUDA driver.");
		return (*_interface.cuModuleLoadDataEx)(module, image, numOptions, options, optionValues);
	}

	CUresult CudaDriver::cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin)
	{
		assertM( _interface.loaded(), 
			"cuModuleLoadFatBinary called without loading CUDA driver.");
		return (*_interface.cuModuleLoadFatBinary)(module, fatCubin);
	}

	CUresult CudaDriver::cuModuleUnload(CUmodule hmod)
	{
		assertM( _interface.loaded(), 
			"cuModuleUnload called without loading CUDA driver.");
		return (*_interface.cuModuleUnload)(hmod);
	}

	CUresult CudaDriver::cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name)
	{
		assertM( _interface.loaded(), 
			"cuModuleGetFunction called without loading CUDA driver.");
		return (*_interface.cuModuleGetFunction)(hfunc, hmod, name);
	}

	CUresult CudaDriver::cuModuleGetGlobal(CUdeviceptr *dptr, unsigned int *bytes, CUmodule hmod, const char *name)
	{
		assertM( _interface.loaded(), 
			"cuModuleGetGlobal called without loading CUDA driver.");
		return (*_interface.cuModuleGetGlobal)(dptr, bytes, hmod, name);
	}

	CUresult CudaDriver::cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name)
	{
		assertM( _interface.loaded(), 
			"cuModuleGetTexRef called without loading CUDA driver.");
		return (*_interface.cuModuleGetTexRef)(pTexRef, hmod, name);
	}


	CUresult CudaDriver::cuMemGetInfo(unsigned int *free, unsigned int *total)
	{
		assertM( _interface.loaded(), 
			"cuMemGetInfo called without loading CUDA driver.");
		return (*_interface.cuMemGetInfo)(free, total);
	}


	CUresult CudaDriver::cuMemAlloc( CUdeviceptr *dptr, unsigned int bytesize)
	{
		assertM( _interface.loaded(), 
			"cuMemAlloc called without loading CUDA driver.");
		return (*_interface.cuMemAlloc)(dptr, bytesize);
	}

	CUresult CudaDriver::cuMemAllocPitch( CUdeviceptr *dptr, 
				          unsigned int *pPitch,
				          unsigned int WidthInBytes, 
				          unsigned int Height, 
				          // size of biggest r/w to be performed by kernels on this memory
				          // 4, 8 or 16 bytes
				          unsigned int ElementSizeBytes
				         )
	{
		assertM( _interface.loaded(), 
			"cuMemAllocPitch called without loading CUDA driver.");
		return (*_interface.cuMemAllocPitch)(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
	}

	CUresult CudaDriver::cuMemFree(CUdeviceptr dptr)
	{
		assertM( _interface.loaded(), 
			"cuMemFree called without loading CUDA driver.");
		return (*_interface.cuMemFree)(dptr);
	}

	CUresult CudaDriver::cuMemGetAddressRange( CUdeviceptr *pbase, unsigned int *psize, CUdeviceptr dptr )
	{
		assertM( _interface.loaded(), 
			"cuMemGetAddressRange called without loading CUDA driver.");
		return (*_interface.cuMemGetAddressRange)(pbase, psize, dptr);
	}

	CUresult CudaDriver::cuMemAllocHost(void **pp, unsigned int bytesize)
	{
		assertM( _interface.loaded(), 
			"cuMemAllocHost called without loading CUDA driver.");
		return (*_interface.cuMemAllocHost)(pp, bytesize);
	}

	CUresult CudaDriver::cuMemFreeHost(void *p)
	{
		assertM( _interface.loaded(), 
			"cuMemFreeHost called without loading CUDA driver.");
		return (*_interface.cuMemFreeHost)(p);
	}

	CUresult CudaDriver::cuMemHostAlloc(void **pp, unsigned long long bytesize, unsigned int Flags )
	{
		assertM( _interface.loaded(), 
			"cuMemHostAlloc called without loading CUDA driver.");
		return (*_interface.cuMemHostAlloc)(pp, bytesize, Flags);
	}

	CUresult CudaDriver::cuMemHostGetDevicePointer( CUdeviceptr *pdptr, void *p, unsigned int Flags )
	{
		assertM( _interface.loaded(), 
			"cuMemHostGetDevicePointer called without loading CUDA driver.");
		return (*_interface.cuMemHostGetDevicePointer)(pdptr, p, Flags);
	}

	CUresult CudaDriver::cuMemHostGetFlags( unsigned int *pFlags, void *p )
	{
		assertM( _interface.loaded(), 
			"cuMemHostGetFlags called without loading CUDA driver.");
		return (*_interface.cuMemHostGetFlags)(pFlags, p);
	}

	CUresult CudaDriver::cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyHtoD called without loading CUDA driver.");
		return (*_interface.cuMemcpyHtoD)(dstDevice, srcHost, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyDtoH called without loading CUDA driver.");
		return (*_interface.cuMemcpyDtoH)(dstHost, srcDevice, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyDtoD called without loading CUDA driver.");
		return (*_interface.cuMemcpyDtoD)(dstDevice, srcDevice, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyDtoA( CUarray dstArray, unsigned int dstIndex, CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyDtoA called without loading CUDA driver.");
		return (*_interface.cuMemcpyDtoA)(dstArray, dstIndex, srcDevice, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoD( CUdeviceptr dstDevice, CUarray hSrc, unsigned int SrcIndex, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyAtoD called without loading CUDA driver.");
		return (*_interface.cuMemcpyAtoD)(dstDevice, hSrc, SrcIndex, ByteCount);
	}


	CUresult CudaDriver::cuMemcpyHtoA( CUarray dstArray, unsigned int dstIndex, const void *pSrc, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyHtoA called without loading CUDA driver.");
		return (*_interface.cuMemcpyHtoA)(dstArray, dstIndex, pSrc, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoH( void *dstHost, CUarray srcArray, unsigned int srcIndex, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyAtoH called without loading CUDA driver.");
		return (*_interface.cuMemcpyAtoH)(dstHost, srcArray, srcIndex, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoA( CUarray dstArray, unsigned int dstIndex, CUarray srcArray, unsigned int srcIndex, unsigned int ByteCount )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyAtoA called without loading CUDA driver.");
		return (*_interface.cuMemcpyAtoA)(dstArray, dstIndex, srcArray, srcIndex, ByteCount);
	}

	CUresult CudaDriver::cuMemcpy2D( const CUDA_MEMCPY2D *pCopy )
	{
		assertM( _interface.loaded(), 
			"cuMemcpy2D called without loading CUDA driver.");
		return (*_interface.cuMemcpy2D)(pCopy);
	}

	CUresult CudaDriver::cuMemcpy2DUnaligned( const CUDA_MEMCPY2D *pCopy )
	{
		assertM( _interface.loaded(), 
			"cuMemcpy2DUnaligned called without loading CUDA driver.");
		return (*_interface.cuMemcpy2DUnaligned)(pCopy);
	}

	CUresult CudaDriver::cuMemcpy3D( const CUDA_MEMCPY3D *pCopy )
	{
		assertM( _interface.loaded(), 
			"cuMemcpy3 called without loading CUDA driver.");
		return (*_interface.cuMemcpy3D)(pCopy);
	}
	
	CUresult CudaDriver::cuMemcpyHtoDAsync (CUdeviceptr dstDevice, 
		const void *srcHost, unsigned int ByteCount, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyHtoDAsync called without loading CUDA driver.");
		return (*_interface.cuMemcpyHtoDAsync)(dstDevice, srcHost, ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyDtoHAsync (void *dstHost, 
	CUdeviceptr srcDevice, unsigned int ByteCount, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyDtoHAsync called without loading CUDA driver.");
		return (*_interface.cuMemcpyDtoHAsync)(dstHost, srcDevice, ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyHtoAAsync( CUarray dstArray, unsigned int dstIndex, 
		const void *pSrc, unsigned int ByteCount, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyHtoAAsync called without loading CUDA driver.");
		return (*_interface.cuMemcpyHtoAAsync)(dstArray, dstIndex, pSrc, ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyAtoHAsync( void *dstHost, CUarray srcArray, unsigned int srcIndex, 
		unsigned int ByteCount, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuMemcpyAtoHAsync called without loading CUDA driver.");
		return (*_interface.cuMemcpyAtoHAsync)(dstHost, srcArray, srcIndex, ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpy2DAsync( const CUDA_MEMCPY2D *pCopy, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuMemcpy2DAsync called without loading CUDA driver.");
		return (*_interface.cuMemcpy2DAsync)(pCopy, hStream);
	}

	CUresult CudaDriver::cuMemcpy3DAsync( const CUDA_MEMCPY3D *pCopy, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuMemcpy3DAsync called without loading CUDA driver.");
		return (*_interface.cuMemcpy3DAsync)(pCopy, hStream);
	}

	CUresult CudaDriver::cuMemsetD8( CUdeviceptr dstDevice, unsigned char uc, unsigned int N )
	{
		assertM( _interface.loaded(), 
			"cuMemsetD8 called without loading CUDA driver.");
		return (*_interface.cuMemsetD8)(dstDevice, uc, N);
	}

	CUresult CudaDriver::cuMemsetD16( CUdeviceptr dstDevice, unsigned short us, unsigned int N )
	{
		assertM( _interface.loaded(), 
			"cuMemsetD16 called without loading CUDA driver.");
		return (*_interface.cuMemsetD16)(dstDevice, us, N);
	}

	CUresult CudaDriver::cuMemsetD32( CUdeviceptr dstDevice, unsigned int ui, unsigned int N )
	{
		assertM( _interface.loaded(), 
			"cuMemsetD32 called without loading CUDA driver.");
		return (*_interface.cuMemsetD32)(dstDevice, ui, N);
	}

	CUresult CudaDriver::cuMemsetD2D8( CUdeviceptr dstDevice, unsigned int dstPitch, unsigned char uc, unsigned int Width, unsigned int Height )
	{
		assertM( _interface.loaded(), 
			"cuMemsetD2D8 called without loading CUDA driver.");
		return (*_interface.cuMemsetD2D8)(dstDevice, dstPitch, uc, Width, Height);
	}

	CUresult CudaDriver::cuMemsetD2D16( CUdeviceptr dstDevice, unsigned int dstPitch, unsigned short us, unsigned int Width, unsigned int Height )
	{
		assertM( _interface.loaded(), 
			"cuMemsetD2D16 called without loading CUDA driver.");
		return (*_interface.cuMemsetD2D16)(dstDevice, dstPitch, us, Width, Height);
	}

	CUresult CudaDriver::cuMemsetD2D32( CUdeviceptr dstDevice, unsigned int dstPitch, unsigned int ui, unsigned int Width, unsigned int Height )
	{
		assertM( _interface.loaded(), 
			"cuMemsetD2D32 called without loading CUDA driver.");
		return (*_interface.cuMemsetD2D32)(dstDevice, dstPitch, ui, Width, Height);
	}


	CUresult CudaDriver::cuFuncSetBlockShape(CUfunction hfunc, int x, int y, int z)
	{
		assertM( _interface.loaded(), 
			"cuFuncSetBlockShape called without loading CUDA driver.");
		return (*_interface.cuFuncSetBlockShape)(hfunc, x, y, z);
	}

	CUresult CudaDriver::cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes)
	{
		assertM( _interface.loaded(), 
			"cuFuncSetSharedSize called without loading CUDA driver.");
		return (*_interface.cuFuncSetSharedSize)(hfunc, bytes);
	}

	CUresult CudaDriver::cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc)
	{
		assertM( _interface.loaded(), 
			"cuFuncGetAttribute called without loading CUDA driver.");
		return (*_interface.cuFuncGetAttribute)(pi, attrib, hfunc);
	}

	CUresult CudaDriver::cuArrayCreate( CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray )
	{
		assertM( _interface.loaded(), 
			"cuArrayCreate called without loading CUDA driver.");
		return (*_interface.cuArrayCreate)(pHandle, pAllocateArray);
	}

	CUresult CudaDriver::cuArrayGetDescriptor( CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray )
	{
		assertM( _interface.loaded(), 
			"cuArrayGetDescriptor called without loading CUDA driver.");
		return (*_interface.cuArrayGetDescriptor)(pArrayDescriptor, hArray);
	}

	CUresult CudaDriver::cuArrayDestroy( CUarray hArray )
	{
		assertM( _interface.loaded(), 
			"cuArrayDestroy called without loading CUDA driver.");
		return (*_interface.cuArrayDestroy)(hArray);
	}

	CUresult CudaDriver::cuArray3DCreate( CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray )
	{
		assertM( _interface.loaded(), 
			"cuArray3DCreate called without loading CUDA driver.");
		return (*_interface.cuArray3DCreate)(pHandle, pAllocateArray);
	}

	CUresult CudaDriver::cuArray3DGetDescriptor( CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray )
	{
		assertM( _interface.loaded(), 
			"cuArray3DGetDescriptor called without loading CUDA driver.");
		return (*_interface.cuArray3DGetDescriptor)(pArrayDescriptor, hArray);
	}

	CUresult CudaDriver::cuTexRefCreate( CUtexref *pTexRef )
	{
		assertM( _interface.loaded(), 
			"cuTexRefCreate called without loading CUDA driver.");
		return (*_interface.cuTexRefCreate)(pTexRef);
	}

	CUresult CudaDriver::cuTexRefDestroy( CUtexref hTexRef )
	{
		assertM( _interface.loaded(), 
			"cuTexRefDestroy called without loading CUDA driver.");
		return (*_interface.cuTexRefDestroy)(hTexRef);
	}

	CUresult CudaDriver::cuTexRefSetArray( CUtexref hTexRef, CUarray hArray, unsigned int Flags )
	{
		assertM( _interface.loaded(), 
			"cuTexRefSetArray called without loading CUDA driver.");
		return (*_interface.cuTexRefSetArray)(hTexRef, hArray, Flags);
	}

	CUresult CudaDriver::cuTexRefSetAddress( unsigned int *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, unsigned int bytes )
	{
		assertM( _interface.loaded(), 
			"cuTexRefSetAddress called without loading CUDA driver.");
		return (*_interface.cuTexRefSetAddress)(ByteOffset, hTexRef, dptr, bytes);
	}

	CUresult CudaDriver::cuTexRefSetAddress2D( CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, unsigned int Pitch)
	{
		assertM( _interface.loaded(), 
			"cuTexRefSetAddress2D called without loading CUDA driver.");
		return (*_interface.cuTexRefSetAddress2D)(hTexRef, desc, dptr, Pitch);
	}

	CUresult CudaDriver::cuTexRefSetFormat( CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents )
	{
		assertM( _interface.loaded(), 
			"cuTexRefSetFormat called without loading CUDA driver.");
		return (*_interface.cuTexRefSetFormat)(hTexRef, fmt, NumPackedComponents);
	}

	CUresult CudaDriver::cuTexRefSetAddressMode( CUtexref hTexRef, int dim, CUaddress_mode am )
	{
		assertM( _interface.loaded(), 
			"cuTexRefSetAddressMode called without loading CUDA driver.");
		return (*_interface.cuTexRefSetAddressMode)(hTexRef, dim, am);
	}

	CUresult CudaDriver::cuTexRefSetFilterMode( CUtexref hTexRef, CUfilter_mode fm )
	{
		assertM( _interface.loaded(), 
			"cuTexRefSetFilterMode called without loading CUDA driver.");
		return (*_interface.cuTexRefSetFilterMode)(hTexRef, fm);
	}

	CUresult CudaDriver::cuTexRefSetFlags( CUtexref hTexRef, unsigned int Flags )
	{
		assertM( _interface.loaded(), 
			"cuTexRefSetFlags called without loading CUDA driver.");
		return (*_interface.cuTexRefSetFlags)(hTexRef, Flags);
	}


	CUresult CudaDriver::cuTexRefGetAddress( CUdeviceptr *pdptr, CUtexref hTexRef )
	{
		assertM( _interface.loaded(), 
			"cuTexRefGetAddress called without loading CUDA driver.");
		return (*_interface.cuTexRefGetAddress)(pdptr, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetArray( CUarray *phArray, CUtexref hTexRef )
	{
		assertM( _interface.loaded(), 
			"cuTexRefGetArray called without loading CUDA driver.");
		return (*_interface.cuTexRefGetArray)(phArray, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetAddressMode( CUaddress_mode *pam, CUtexref hTexRef, int dim )
	{
		assertM( _interface.loaded(), 
			"cuTexRefGetAddressMode called without loading CUDA driver.");
		return (*_interface.cuTexRefGetAddressMode)(pam, hTexRef, dim);
	}

	CUresult CudaDriver::cuTexRefGetFilterMode( CUfilter_mode *pfm, CUtexref hTexRef )
	{
		assertM( _interface.loaded(), 
			"cuTexRefGetFilterMode called without loading CUDA driver.");
		return (*_interface.cuTexRefGetFilterMode)(pfm, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetFormat( CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef )
	{
		assertM( _interface.loaded(), 
			"cuTexRefGetFormat called without loading CUDA driver.");
		return (*_interface.cuTexRefGetFormat)(pFormat, pNumChannels, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetFlags( unsigned int *pFlags, CUtexref hTexRef )
	{
		assertM( _interface.loaded(), 
			"cuTexRefGetFlags called without loading CUDA driver.");
		return (*_interface.cuTexRefGetFlags)(pFlags, hTexRef);
	}


	CUresult CudaDriver::cuParamSetSize(CUfunction hfunc, unsigned int numbytes)
	{
		assertM( _interface.loaded(), 
			"cuParamSetSize called without loading CUDA driver.");
		return (*_interface.cuParamSetSize)(hfunc, numbytes);
	}

	CUresult CudaDriver::cuParamSeti(CUfunction hfunc, int offset, unsigned int value)
	{
		assertM( _interface.loaded(), 
			"cuParamSeti called without loading CUDA driver.");
		return (*_interface.cuParamSeti)(hfunc, offset, value);
	}

	CUresult CudaDriver::cuParamSetf(CUfunction hfunc, int offset, float value)
	{
		assertM( _interface.loaded(), 
			"cuParamSetf called without loading CUDA driver.");
		return (*_interface.cuParamSetf)(hfunc, offset, value);
	}

	CUresult CudaDriver::cuParamSetv(CUfunction hfunc, int offset, void * ptr, unsigned int numbytes)
	{
		assertM( _interface.loaded(), 
			"cuParamSetv called without loading CUDA driver.");
		return (*_interface.cuParamSetv)(hfunc, offset, ptr, numbytes);
	}

	CUresult CudaDriver::cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef)
	{
		assertM( _interface.loaded(), 
			"cuParamSetTexRef called without loading CUDA driver.");
		return (*_interface.cuParamSetTexRef)(hfunc, texunit, hTexRef);
	}


	CUresult CudaDriver::cuLaunch ( CUfunction f )
	{
		assertM( _interface.loaded(), 
			"cuLaunch called without loading CUDA driver.");
		return (*_interface.cuLaunch)(f);
	}

	CUresult CudaDriver::cuLaunchGrid (CUfunction f, int grid_width, int grid_height)
	{
		assertM( _interface.loaded(), 
			"cuLaunchGrid called without loading CUDA driver.");
		return (*_interface.cuLaunchGrid)(f, grid_width, grid_height);
	}

	CUresult CudaDriver::cuLaunchGridAsync( CUfunction f, int grid_width, int grid_height, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuLaunchGridAsync called without loading CUDA driver.");
		return (*_interface.cuLaunchGridAsync)(f, grid_width, grid_height, hStream);
	}


	CUresult CudaDriver::cuEventCreate( CUevent *phEvent, unsigned int Flags )
	{
		assertM( _interface.loaded(), 
			"cuEventCreate called without loading CUDA driver.");
		return (*_interface.cuEventCreate)(phEvent, Flags);
	}

	CUresult CudaDriver::cuEventRecord( CUevent hEvent, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuEventRecord called without loading CUDA driver.");
		return (*_interface.cuEventRecord)(hEvent, hStream);
	}

	CUresult CudaDriver::cuEventQuery( CUevent hEvent )
	{
		assertM( _interface.loaded(), 
			"cuEventQuery called without loading CUDA driver.");
		return (*_interface.cuEventQuery)(hEvent);
	}

	CUresult CudaDriver::cuEventSynchronize( CUevent hEvent )
	{
		assertM( _interface.loaded(), 
			"cuEventSynchronize called without loading CUDA driver.");
		return (*_interface.cuEventSynchronize)(hEvent);
	}

	CUresult CudaDriver::cuEventDestroy( CUevent hEvent )
	{
		assertM( _interface.loaded(), 
			"cuEventDestroy called without loading CUDA driver.");
		return (*_interface.cuEventDestroy)(hEvent);
	}

	CUresult CudaDriver::cuEventElapsedTime( float *pMilliseconds, CUevent hStart, CUevent hEnd )
	{
		assertM( _interface.loaded(), 
			"cuEventElapsedTime called without loading CUDA driver.");
		return (*_interface.cuEventElapsedTime)(pMilliseconds, hStart, hEnd);
	}


	CUresult CudaDriver::cuStreamCreate( CUstream *phStream, unsigned int Flags )
	{
		assertM( _interface.loaded(), 
			"cuStreamCreate called without loading CUDA driver.");
		return (*_interface.cuStreamCreate)(phStream, Flags);
	}

	CUresult CudaDriver::cuStreamQuery( CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuStreamQuery called without loading CUDA driver.");
		return (*_interface.cuStreamQuery)(hStream);
	}

	CUresult CudaDriver::cuStreamSynchronize( CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuStreamSynchronize called without loading CUDA driver.");
		return (*_interface.cuStreamSynchronize)(hStream);
	}

	CUresult CudaDriver::cuStreamDestroy( CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuStreamDestroy called without loading CUDA driver.");
		return (*_interface.cuStreamDestroy)(hStream);
	}
	
	CUresult CudaDriver::cuGLInit(void)
	{
		assertM( _interface.loaded(), 
			"cuGLInit called without loading CUDA driver.");
		return (*_interface.cuGLInit)();
	}
	
	CUresult CudaDriver::cuGLCtxCreate( CUcontext *pCtx, unsigned int Flags, CUdevice device )
	{
		assertM( _interface.loaded(), 
			"cuGLCtxCreate called without loading CUDA driver.");
		return (*_interface.cuGLCtxCreate)(pCtx, Flags, device);
	}

	CUresult CudaDriver::cuGLRegisterBufferObject( GLuint bufferobj )
	{
		assertM( _interface.loaded(), 
			"cuGLRegisterBufferObject called without loading CUDA driver.");
		return (*_interface.cuGLRegisterBufferObject)(bufferobj);
	}

	CUresult CudaDriver::cuGLMapBufferObject( CUdeviceptr *dptr, unsigned int *size,  GLuint bufferobj )
	{
		assertM( _interface.loaded(), 
			"cuGLMapBufferObject called without loading CUDA driver.");
		return (*_interface.cuGLMapBufferObject)(dptr, size, bufferobj);
	}

	CUresult CudaDriver::cuGLUnmapBufferObject( GLuint bufferobj )
	{
		assertM( _interface.loaded(), 
			"cuGLUnmapBufferObject called without loading CUDA driver.");
		return (*_interface.cuGLUnmapBufferObject)(bufferobj);
	}

	CUresult CudaDriver::cuGLUnregisterBufferObject( GLuint bufferobj )
	{
		assertM( _interface.loaded(), 
			"cuGLUnregisterBufferObject called without loading CUDA driver.");
		return (*_interface.cuGLUnregisterBufferObject)(bufferobj);
	}

	CUresult CudaDriver::cuGLSetBufferObjectMapFlags( GLuint bufferobj, unsigned int Flags )
	{
		assertM( _interface.loaded(), 
			"cuGLSetBufferObjectMapFlags called without loading CUDA driver.");
		return (*_interface.cuGLSetBufferObjectMapFlags)(bufferobj, Flags);
	}

	CUresult CudaDriver::cuGLMapBufferObjectAsync( CUdeviceptr *dptr, unsigned int *size,  GLuint bufferobj, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuGLMapBufferObjectAsync called without loading CUDA driver.");
		return (*_interface.cuGLMapBufferObjectAsync)(dptr, size, bufferobj, hStream);
	}
	
	CUresult CudaDriver::cuGLUnmapBufferObjectAsync( GLuint bufferobj, CUstream hStream )
	{
		assertM( _interface.loaded(), 
			"cuGLUnmapBufferObjectAsync called without loading CUDA driver.");
		return (*_interface.cuGLUnmapBufferObjectAsync)(bufferobj, hStream);
	}

}

#endif

