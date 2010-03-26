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

#define REPORT_BASE 1

namespace cuda
{
	CudaDriver::Interface::Interface() : _driver( 0 )
	{
	
	}

	CudaDriver::Interface::~Interface()
	{
		if( _driver )
		{
			report( "Closing cuda.so" );
			dlclose( _driver );
		}
	}
	
	void CudaDriver::Interface::load()
	{
		if( _driver != 0 ) return;
		
		report( "Loading cuda.so" );
		_driver = dlopen( "cuda.so", RTLD_LAZY );
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

	}

	bool CudaDriver::Interface::loaded() const
	{
		return _driver != 0;
	}

	CudaDriver::Interface CudaDriver::_interface;
	
	CudaDriver::Interface& CudaDriver::get()
	{
		_interface.load();
		return _interface;
	}

	CUresult CudaDriver::cuInit(unsigned int Flags)
	{
		if( !_interface.loaded() ) return CUDA_ERROR_NO_DEVICE;
		return (*get().cuInit)(Flags);
	}

	CUresult CudaDriver::cuDriverGetVersion(int *driverVersion)
	{
		return (*get().cuDriverGetVersion)(driverVersion);
	}

	CUresult CudaDriver::cuDeviceGet(CUdevice *device, int ordinal)
	{
		return (*get().cuDeviceGet)(device, ordinal);
	}

	CUresult CudaDriver::cuDeviceGetCount(int *count)
	{
		if( !_interface.loaded() )
		{
			*count = 0;
			return CUDA_SUCCESS;
		}
		return (*get().cuDeviceGetCount)(count);
	}

	CUresult CudaDriver::cuDeviceGetName(char *name, int len, CUdevice dev)
	{
		return (*get().cuDeviceGetName)(name, len, dev);
	}

	CUresult CudaDriver::cuDeviceComputeCapability(int *major, int *minor, CUdevice dev)
	{
		return (*get().cuDeviceComputeCapability)(major, minor, dev);
	}

	CUresult CudaDriver::cuDeviceTotalMem(unsigned int *bytes, CUdevice dev)
	{
		return (*get().cuDeviceTotalMem)(bytes, dev);
	}

	CUresult CudaDriver::cuDeviceGetProperties(CUdevprop *prop, CUdevice dev)
	{
		return (*get().cuDeviceGetProperties)(prop, dev);
	}

	CUresult CudaDriver::cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev)
	{
		return (*get().cuDeviceGetAttribute)(pi, attrib, dev);
	}


	CUresult CudaDriver::cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev )
	{
		return (*get().cuCtxCreate)(pctx, flags, dev);
	}

	CUresult CudaDriver::cuCtxDestroy( CUcontext ctx )
	{
		return (*get().cuCtxDestroy)(ctx);
	}

	CUresult CudaDriver::cuCtxAttach(CUcontext *pctx, unsigned int flags)
	{
		return (*get().cuCtxAttach)(pctx, flags);
	}

	CUresult CudaDriver::cuCtxDetach(CUcontext ctx)
	{
		return (*get().cuCtxDetach)(ctx);
	}

	CUresult CudaDriver::cuCtxPushCurrent( CUcontext ctx )
	{
		return (*get().cuCtxPushCurrent)(ctx);
	}

	CUresult CudaDriver::cuCtxPopCurrent( CUcontext *pctx )
	{
		return (*get().cuCtxPopCurrent)(pctx);
	}

	CUresult CudaDriver::cuCtxGetDevice(CUdevice *device)
	{
		return (*get().cuCtxGetDevice)(device);
	}

	CUresult CudaDriver::cuCtxSynchronize(void)
	{
		return (*get().cuCtxSynchronize)();
	}


	CUresult CudaDriver::cuModuleLoad(CUmodule *module, const char *fname)
	{
		return (*get().cuModuleLoad)(module, fname);
	}

	CUresult CudaDriver::cuModuleLoadData(CUmodule *module, const void *image)
	{
		return (*get().cuModuleLoadData)(module, image);
	}

	CUresult CudaDriver::cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues)
	{
		return (*get().cuModuleLoadDataEx)(module, image, numOptions, options, optionValues);
	}

	CUresult CudaDriver::cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin)
	{
		return (*get().cuModuleLoadFatBinary)(module, fatCubin);
	}

	CUresult CudaDriver::cuModuleUnload(CUmodule hmod)
	{
		return (*get().cuModuleUnload)(hmod);
	}

	CUresult CudaDriver::cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name)
	{
		return (*get().cuModuleGetFunction)(hfunc, hmod, name);
	}

	CUresult CudaDriver::cuModuleGetGlobal(CUdeviceptr *dptr, unsigned int *bytes, CUmodule hmod, const char *name)
	{
		return (*get().cuModuleGetGlobal)(dptr, bytes, hmod, name);
	}

	CUresult CudaDriver::cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name)
	{
		return (*get().cuModuleGetTexRef)(pTexRef, hmod, name);
	}


	CUresult CudaDriver::cuMemGetInfo(unsigned int *free, unsigned int *total)
	{
		return (*get().cuMemGetInfo)(free, total);
	}


	CUresult CudaDriver::cuMemAlloc( CUdeviceptr *dptr, unsigned int bytesize)
	{
		return (*get().cuMemAlloc)(dptr, bytesize);
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
		return (*get().cuMemAllocPitch)(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
	}

	CUresult CudaDriver::cuMemFree(CUdeviceptr dptr)
	{
		return (*get().cuMemFree)(dptr);
	}

	CUresult CudaDriver::cuMemGetAddressRange( CUdeviceptr *pbase, unsigned int *psize, CUdeviceptr dptr )
	{
		return (*get().cuMemGetAddressRange)(pbase, psize, dptr);
	}


	CUresult CudaDriver::cuMemAllocHost(void **pp, unsigned int bytesize)
	{
		return (*get().cuMemAllocHost)(pp, bytesize);
	}

	CUresult CudaDriver::cuMemFreeHost(void *p)
	{
		return (*get().cuMemFreeHost)(p);
	}


	CUresult CudaDriver::cuMemHostAlloc(void **pp, unsigned long long bytesize, unsigned int Flags )
	{
		return (*get().cuMemHostAlloc)(pp, bytesize, Flags);
	}


	CUresult CudaDriver::cuMemHostGetDevicePointer( CUdeviceptr *pdptr, void *p, unsigned int Flags )
	{
		return (*get().cuMemHostGetDevicePointer)(pdptr, p, Flags);
	}

	CUresult CudaDriver::cuMemHostGetFlags( unsigned int *pFlags, void *p )
	{
		return (*get().cuMemHostGetFlags)(pFlags, p);
	}


	CUresult CudaDriver::cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost, unsigned int ByteCount )
	{
		return (*get().cuMemcpyHtoD)(dstDevice, srcHost, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		return (*get().cuMemcpyDtoH)(dstHost, srcDevice, ByteCount);
	}


	CUresult CudaDriver::cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		return (*get().cuMemcpyDtoD)(dstDevice, srcDevice, ByteCount);
	}


	CUresult CudaDriver::cuMemcpyDtoA( CUarray dstArray, unsigned int dstIndex, CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		return (*get().cuMemcpyDtoA)(dstArray, dstIndex, srcDevice, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoD( CUdeviceptr dstDevice, CUarray hSrc, unsigned int SrcIndex, unsigned int ByteCount )
	{
		return (*get().cuMemcpyAtoD)(dstDevice, hSrc, SrcIndex, ByteCount);
	}


	CUresult CudaDriver::cuMemcpyHtoA( CUarray dstArray, unsigned int dstIndex, const void *pSrc, unsigned int ByteCount )
	{
		return (*get().cuMemcpyHtoA)(dstArray, dstIndex, pSrc, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoH( void *dstHost, CUarray srcArray, unsigned int srcIndex, unsigned int ByteCount )
	{
		return (*get().cuMemcpyAtoH)(dstHost, srcArray, srcIndex, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoA( CUarray dstArray, unsigned int dstIndex, CUarray srcArray, unsigned int srcIndex, unsigned int ByteCount )
	{
		return (*get().cuMemcpyAtoA)(dstArray, dstIndex, srcArray, srcIndex, ByteCount);
	}


	CUresult CudaDriver::cuMemcpy2D( const CUDA_MEMCPY2D *pCopy )
	{
		return (*get().cuMemcpy2D)(pCopy);
	}

	CUresult CudaDriver::cuMemcpy2DUnaligned( const CUDA_MEMCPY2D *pCopy )
	{
		return (*get().cuMemcpy2DUnaligned)(pCopy);
	}


	CUresult CudaDriver::cuMemcpy3D( const CUDA_MEMCPY3D *pCopy )
	{
		return (*get().cuMemcpy3D)(pCopy);
	}


	CUresult CudaDriver::cuMemcpyHtoDAsync (CUdeviceptr dstDevice, 
		const void *srcHost, unsigned int ByteCount, CUstream hStream )
	{
		return (*get().cuMemcpyHtoDAsync)(dstDevice, srcHost, ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyDtoHAsync (void *dstHost, 
	CUdeviceptr srcDevice, unsigned int ByteCount, CUstream hStream )
	{
		return (*get().cuMemcpyDtoHAsync)(dstHost, srcDevice, ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyHtoAAsync( CUarray dstArray, unsigned int dstIndex, 
		const void *pSrc, unsigned int ByteCount, CUstream hStream )
	{
		return (*get().cuMemcpyHtoAAsync)(dstArray, dstIndex, pSrc, ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyAtoHAsync( void *dstHost, CUarray srcArray, unsigned int srcIndex, 
		unsigned int ByteCount, CUstream hStream )
	{
		return (*get().cuMemcpyAtoHAsync)(dstHost, srcArray, srcIndex, ByteCount, hStream);
	}


	CUresult CudaDriver::cuMemcpy2DAsync( const CUDA_MEMCPY2D *pCopy, CUstream hStream )
	{
		return (*get().cuMemcpy2DAsync)(pCopy, hStream);
	}


	CUresult CudaDriver::cuMemcpy3DAsync( const CUDA_MEMCPY3D *pCopy, CUstream hStream )
	{
		return (*get().cuMemcpy3DAsync)(pCopy, hStream);
	}


	CUresult CudaDriver::cuMemsetD8( CUdeviceptr dstDevice, unsigned char uc, unsigned int N )
	{
		return (*get().cuMemsetD8)(dstDevice, uc, N);
	}

	CUresult CudaDriver::cuMemsetD16( CUdeviceptr dstDevice, unsigned short us, unsigned int N )
	{
		return (*get().cuMemsetD16)(dstDevice, us, N);
	}

	CUresult CudaDriver::cuMemsetD32( CUdeviceptr dstDevice, unsigned int ui, unsigned int N )
	{
		return (*get().cuMemsetD32)(dstDevice, ui, N);
	}


	CUresult CudaDriver::cuMemsetD2D8( CUdeviceptr dstDevice, unsigned int dstPitch, unsigned char uc, unsigned int Width, unsigned int Height )
	{
		return (*get().cuMemsetD2D8)(dstDevice, dstPitch, uc, Width, Height);
	}

	CUresult CudaDriver::cuMemsetD2D16( CUdeviceptr dstDevice, unsigned int dstPitch, unsigned short us, unsigned int Width, unsigned int Height )
	{
		return (*get().cuMemsetD2D16)(dstDevice, dstPitch, us, Width, Height);
	}

	CUresult CudaDriver::cuMemsetD2D32( CUdeviceptr dstDevice, unsigned int dstPitch, unsigned int ui, unsigned int Width, unsigned int Height )
	{
		return (*get().cuMemsetD2D32)(dstDevice, dstPitch, ui, Width, Height);
	}


	CUresult CudaDriver::cuFuncSetBlockShape(CUfunction hfunc, int x, int y, int z)
	{
		return (*get().cuFuncSetBlockShape)(hfunc, x, y, z);
	}

	CUresult CudaDriver::cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes)
	{
		return (*get().cuFuncSetSharedSize)(hfunc, bytes);
	}

	CUresult CudaDriver::cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc)
	{
		return (*get().cuFuncGetAttribute)(pi, attrib, hfunc);
	}


	CUresult CudaDriver::cuArrayCreate( CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray )
	{
		return (*get().cuArrayCreate)(pHandle, pAllocateArray);
	}

	CUresult CudaDriver::cuArrayGetDescriptor( CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray )
	{
		return (*get().cuArrayGetDescriptor)(pArrayDescriptor, hArray);
	}

	CUresult CudaDriver::cuArrayDestroy( CUarray hArray )
	{
		return (*get().cuArrayDestroy)(hArray);
	}


	CUresult CudaDriver::cuArray3DCreate( CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray )
	{
		return (*get().cuArray3DCreate)(pHandle, pAllocateArray);
	}

	CUresult CudaDriver::cuArray3DGetDescriptor( CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray )
	{
		return (*get().cuArray3DGetDescriptor)(pArrayDescriptor, hArray);
	}


	CUresult CudaDriver::cuTexRefCreate( CUtexref *pTexRef )
	{
		return (*get().cuTexRefCreate)(pTexRef);
	}

	CUresult CudaDriver::cuTexRefDestroy( CUtexref hTexRef )
	{
		return (*get().cuTexRefDestroy)(hTexRef);
	}


	CUresult CudaDriver::cuTexRefSetArray( CUtexref hTexRef, CUarray hArray, unsigned int Flags )
	{
		return (*get().cuTexRefSetArray)(hTexRef, hArray, Flags);
	}

	CUresult CudaDriver::cuTexRefSetAddress( unsigned int *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, unsigned int bytes )
	{
		return (*get().cuTexRefSetAddress)(ByteOffset, hTexRef, dptr, bytes);
	}

	CUresult CudaDriver::cuTexRefSetAddress2D( CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, unsigned int Pitch)
	{
		return (*get().cuTexRefSetAddress2D)(hTexRef, desc, dptr, Pitch);
	}

	CUresult CudaDriver::cuTexRefSetFormat( CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents )
	{
		return (*get().cuTexRefSetFormat)(hTexRef, fmt, NumPackedComponents);
	}

	CUresult CudaDriver::cuTexRefSetAddressMode( CUtexref hTexRef, int dim, CUaddress_mode am )
	{
		return (*get().cuTexRefSetAddressMode)(hTexRef, dim, am);
	}

	CUresult CudaDriver::cuTexRefSetFilterMode( CUtexref hTexRef, CUfilter_mode fm )
	{
		return (*get().cuTexRefSetFilterMode)(hTexRef, fm);
	}

	CUresult CudaDriver::cuTexRefSetFlags( CUtexref hTexRef, unsigned int Flags )
	{
		return (*get().cuTexRefSetFlags)(hTexRef, Flags);
	}


	CUresult CudaDriver::cuTexRefGetAddress( CUdeviceptr *pdptr, CUtexref hTexRef )
	{
		return (*get().cuTexRefGetAddress)(pdptr, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetArray( CUarray *phArray, CUtexref hTexRef )
	{
		return (*get().cuTexRefGetArray)(phArray, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetAddressMode( CUaddress_mode *pam, CUtexref hTexRef, int dim )
	{
		return (*get().cuTexRefGetAddressMode)(pam, hTexRef, dim);
	}

	CUresult CudaDriver::cuTexRefGetFilterMode( CUfilter_mode *pfm, CUtexref hTexRef )
	{
		return (*get().cuTexRefGetFilterMode)(pfm, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetFormat( CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef )
	{
		return (*get().cuTexRefGetFormat)(pFormat, pNumChannels, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetFlags( unsigned int *pFlags, CUtexref hTexRef )
	{
		return (*get().cuTexRefGetFlags)(pFlags, hTexRef);
	}


	CUresult CudaDriver::cuParamSetSize(CUfunction hfunc, unsigned int numbytes)
	{
		return (*get().cuParamSetSize)(hfunc, numbytes);
	}

	CUresult CudaDriver::cuParamSeti(CUfunction hfunc, int offset, unsigned int value)
	{
		return (*get().cuParamSeti)(hfunc, offset, value);
	}

	CUresult CudaDriver::cuParamSetf(CUfunction hfunc, int offset, float value)
	{
		return (*get().cuParamSetf)(hfunc, offset, value);
	}

	CUresult CudaDriver::cuParamSetv(CUfunction hfunc, int offset, void * ptr, unsigned int numbytes)
	{
		return (*get().cuParamSetv)(hfunc, offset, ptr, numbytes);
	}

	CUresult CudaDriver::cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef)
	{
		return (*get().cuParamSetTexRef)(hfunc, texunit, hTexRef);
	}


	CUresult CudaDriver::cuLaunch ( CUfunction f )
	{
		return (*get().cuLaunch)(f);
	}

	CUresult CudaDriver::cuLaunchGrid (CUfunction f, int grid_width, int grid_height)
	{
		return (*get().cuLaunchGrid)(f, grid_width, grid_height);
	}

	CUresult CudaDriver::cuLaunchGridAsync( CUfunction f, int grid_width, int grid_height, CUstream hStream )
	{
		return (*get().cuLaunchGridAsync)(f, grid_width, grid_height, hStream);
	}


	CUresult CudaDriver::cuEventCreate( CUevent *phEvent, unsigned int Flags )
	{
		return (*get().cuEventCreate)(phEvent, Flags);
	}

	CUresult CudaDriver::cuEventRecord( CUevent hEvent, CUstream hStream )
	{
		return (*get().cuEventRecord)(hEvent, hStream);
	}

	CUresult CudaDriver::cuEventQuery( CUevent hEvent )
	{
		return (*get().cuEventQuery)(hEvent);
	}

	CUresult CudaDriver::cuEventSynchronize( CUevent hEvent )
	{
		return (*get().cuEventSynchronize)(hEvent);
	}

	CUresult CudaDriver::cuEventDestroy( CUevent hEvent )
	{
		return (*get().cuEventDestroy)(hEvent);
	}

	CUresult CudaDriver::cuEventElapsedTime( float *pMilliseconds, CUevent hStart, CUevent hEnd )
	{
		return (*get().cuEventElapsedTime)(pMilliseconds, hStart, hEnd);
	}


	CUresult CudaDriver::cuStreamCreate( CUstream *phStream, unsigned int Flags )
	{
		return (*get().cuStreamCreate)(phStream, Flags);
	}

	CUresult CudaDriver::cuStreamQuery( CUstream hStream )
	{
		return (*get().cuStreamQuery)(hStream);
	}

	CUresult CudaDriver::cuStreamSynchronize( CUstream hStream )
	{
		return (*get().cuStreamSynchronize)(hStream);
	}

	CUresult CudaDriver::cuStreamDestroy( CUstream hStream )
	{
		return (*get().cuStreamDestroy)(hStream);
	}
	
	CUresult CudaDriver::cuGLInit(void)
	{
		return (*get().cuGLInit)();
	}
	
	CUresult CudaDriver::cuGLCtxCreate( CUcontext *pCtx, unsigned int Flags, CUdevice device )
	{
		return (*get().cuGLCtxCreate)(pCtx, Flags, device);
	}

	CUresult CudaDriver::cuGLRegisterBufferObject( GLuint bufferobj )
	{
		return (*get().cuGLRegisterBufferObject)(bufferobj);
	}

	CUresult CudaDriver::cuGLMapBufferObject( CUdeviceptr *dptr, unsigned int *size,  GLuint bufferobj )
	{
		return (*get().cuGLMapBufferObject)(dptr, size, bufferobj);
	}

	CUresult CudaDriver::cuGLUnmapBufferObject( GLuint bufferobj )
	{
		return (*get().cuGLUnmapBufferObject)(bufferobj);
	}

	CUresult CudaDriver::cuGLUnregisterBufferObject( GLuint bufferobj )
	{
		return (*get().cuGLUnregisterBufferObject)(bufferobj);
	}

	CUresult CudaDriver::cuGLSetBufferObjectMapFlags( GLuint bufferobj, unsigned int Flags )
	{
		return (*get().cuGLSetBufferObjectMapFlags)(bufferobj, Flags);
	}

	CUresult CudaDriver::cuGLMapBufferObjectAsync( CUdeviceptr *dptr, unsigned int *size,  GLuint bufferobj, CUstream hStream )
	{
		return (*get().cuGLMapBufferObjectAsync)(dptr, size, bufferobj, hStream);
	}
	
	CUresult CudaDriver::cuGLUnmapBufferObjectAsync( GLuint bufferobj, CUstream hStream )
	{
		return (*get().cuGLUnmapBufferObjectAsync)(bufferobj, hStream);
	}

}

#endif

