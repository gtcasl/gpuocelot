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

// Macros
#define CHECK() {assertM(_interface.loaded(), __FUNCTION__ \
	<< " called without loading the driver.");\
	reportE(REPORT_ALL_CALLS, __FUNCTION__);}

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_ALL_CALLS 0

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
		hydrazine::bit_cast( cuDriverGetVersion, dlsym( _driver, 
			"cuDriverGetVersion" ) );
		hydrazine::bit_cast( cuDeviceGet, dlsym( _driver, "cuDeviceGet" ) );
		hydrazine::bit_cast( cuDeviceGetCount, dlsym( _driver, 
			"cuDeviceGetCount" ) );
		hydrazine::bit_cast( cuDeviceGetName, dlsym( _driver, 
			"cuDeviceGetName" ) );
		hydrazine::bit_cast( cuDeviceComputeCapability, dlsym( _driver, 
			"cuDeviceComputeCapability" ) );
		hydrazine::bit_cast( cuDeviceTotalMem, dlsym( _driver, 
			"cuDeviceTotalMem" ) );
		hydrazine::bit_cast( cuDeviceGetProperties, dlsym( _driver, 
			"cuDeviceGetProperties" ) );
		hydrazine::bit_cast( cuDeviceGetAttribute, dlsym( _driver, 
			"cuDeviceGetAttribute" ) );
		hydrazine::bit_cast( cuCtxGetLimit, dlsym( _driver, "cuCtxGetLimit" ) );	
		hydrazine::bit_cast( cuCtxCreate, dlsym( _driver, "cuCtxCreate" ) );
		hydrazine::bit_cast( cuCtxDestroy, dlsym( _driver, "cuCtxDestroy" ) );
		hydrazine::bit_cast( cuCtxAttach, dlsym( _driver, "cuCtxAttach" ) );
		hydrazine::bit_cast( cuCtxDetach, dlsym( _driver, "cuCtxDetach" ) );
		hydrazine::bit_cast( cuCtxPushCurrent, dlsym( _driver, 
			"cuCtxPushCurrent" ) );
		hydrazine::bit_cast( cuCtxPopCurrent, dlsym( _driver, 
			"cuCtxPopCurrent" ) );
		hydrazine::bit_cast( cuCtxGetDevice, dlsym( _driver, 
			"cuCtxGetDevice" ) );
		hydrazine::bit_cast( cuCtxSynchronize, dlsym( _driver, 
			"cuCtxSynchronize" ) );
		hydrazine::bit_cast( cuModuleLoad, dlsym( _driver, "cuModuleLoad" ) );
		hydrazine::bit_cast( cuModuleLoadData, dlsym( _driver, 
			"cuModuleLoadData" ) );
		hydrazine::bit_cast( cuModuleLoadDataEx, dlsym( _driver, 
			"cuModuleLoadDataEx" ) );
		hydrazine::bit_cast( cuModuleLoadFatBinary, dlsym( _driver, 
			"cuModuleLoadFatBinary" ) );
		hydrazine::bit_cast( cuModuleUnload, dlsym( _driver, 
			"cuModuleUnload" ) );
		hydrazine::bit_cast( cuModuleGetFunction, dlsym( _driver, 
			"cuModuleGetFunction" ) );
		hydrazine::bit_cast( cuModuleGetGlobal, dlsym( _driver, 
			"cuModuleGetGlobal" ) );
		hydrazine::bit_cast( cuModuleGetTexRef, dlsym( _driver, 
			"cuModuleGetTexRef" ) );
		hydrazine::bit_cast( cuMemGetInfo, dlsym( _driver, "cuMemGetInfo" ) );
		hydrazine::bit_cast( cuMemAlloc, dlsym( _driver, "cuMemAlloc" ) );
		hydrazine::bit_cast( cuMemAllocPitch, dlsym( _driver, 
			"cuMemAllocPitch" ) );
		hydrazine::bit_cast( cuMemFree, dlsym( _driver, "cuMemFree" ) );
		hydrazine::bit_cast( cuMemGetAddressRange, dlsym( _driver, 
			"cuMemGetAddressRange" ) );
		hydrazine::bit_cast( cuMemAllocHost, dlsym( _driver, 
			"cuMemAllocHost" ) );
		hydrazine::bit_cast( cuMemFreeHost, dlsym( _driver, "cuMemFreeHost" ) );
		hydrazine::bit_cast( cuMemHostAlloc, dlsym( _driver, 
			"cuMemHostAlloc" ) );
		hydrazine::bit_cast( cuMemHostGetDevicePointer, dlsym( _driver, 
			"cuMemHostGetDevicePointer" ) );
		hydrazine::bit_cast( cuMemHostGetFlags, dlsym( _driver, 
			"cuMemHostGetFlags" ) );
		hydrazine::bit_cast( cuMemcpyHtoD, dlsym( _driver, "cuMemcpyHtoD" ) );
		hydrazine::bit_cast( cuMemcpyDtoH, dlsym( _driver, "cuMemcpyDtoH" ) );
		hydrazine::bit_cast( cuMemcpyDtoD, dlsym( _driver, "cuMemcpyDtoD" ) );
		hydrazine::bit_cast( cuMemcpyDtoA, dlsym( _driver, "cuMemcpyDtoA" ) );
		hydrazine::bit_cast( cuMemcpyAtoD, dlsym( _driver, "cuMemcpyAtoD" ) );
		hydrazine::bit_cast( cuMemcpyHtoA, dlsym( _driver, "cuMemcpyHtoA" ) );
		hydrazine::bit_cast( cuMemcpyAtoH, dlsym( _driver, "cuMemcpyAtoH" ) );
		hydrazine::bit_cast( cuMemcpyAtoA, dlsym( _driver, "cuMemcpyAtoA" ) );
		hydrazine::bit_cast( cuMemcpy2D, dlsym( _driver, "cuMemcpy2D" ) );
		hydrazine::bit_cast( cuMemcpy2DUnaligned, dlsym( _driver, 
			"cuMemcpy2DUnaligned" ) );
		hydrazine::bit_cast( cuMemcpy3D, dlsym( _driver, "cuMemcpy3D" ) );
		hydrazine::bit_cast( cuMemcpyHtoDAsync, dlsym( _driver, 
			"cuMemcpyHtoDAsync" ) );
		hydrazine::bit_cast( cuMemcpyDtoHAsync, dlsym( _driver, 
			"cuMemcpyDtoHAsync" ) );
		hydrazine::bit_cast( cuMemcpyHtoAAsync, dlsym( _driver, 
			"cuMemcpyHtoAAsync" ) );
		hydrazine::bit_cast( cuMemcpyAtoHAsync, dlsym( _driver, 
			"cuMemcpyAtoHAsync" ) );
		hydrazine::bit_cast( cuMemcpy2DAsync, dlsym( _driver, 
			"cuMemcpy2DAsync" ) );
		hydrazine::bit_cast( cuMemcpy3DAsync, dlsym( _driver, 
			"cuMemcpy3DAsync" ) );
		hydrazine::bit_cast( cuMemsetD8, dlsym( _driver, "cuMemsetD8" ) );
		hydrazine::bit_cast( cuMemsetD16, dlsym( _driver, "cuMemsetD16" ) );
		hydrazine::bit_cast( cuMemsetD32, dlsym( _driver, "cuMemsetD32" ) );
		hydrazine::bit_cast( cuMemsetD2D8, dlsym( _driver, "cuMemsetD2D8" ) );
		hydrazine::bit_cast( cuMemsetD2D16, dlsym( _driver, "cuMemsetD2D16" ) );
		hydrazine::bit_cast( cuMemsetD2D32, dlsym( _driver, "cuMemsetD2D32" ) );
		hydrazine::bit_cast( cuFuncSetBlockShape, dlsym( _driver, 
			"cuFuncSetBlockShape" ) );
		hydrazine::bit_cast( cuFuncSetSharedSize, dlsym( _driver, 
			"cuFuncSetSharedSize" ) );
		hydrazine::bit_cast( cuFuncGetAttribute, dlsym( _driver, 
			"cuFuncGetAttribute" ) );
		hydrazine::bit_cast( cuArrayCreate, dlsym( _driver, "cuArrayCreate" ) );
		hydrazine::bit_cast( cuArrayGetDescriptor, dlsym( _driver, 
			"cuArrayGetDescriptor" ) );
		hydrazine::bit_cast( cuArrayDestroy, dlsym( _driver, 
			"cuArrayDestroy" ) );
		hydrazine::bit_cast( cuArray3DCreate, dlsym( _driver, 
			"cuArray3DCreate" ) );
		hydrazine::bit_cast( cuArray3DGetDescriptor, dlsym( _driver, 
			"cuArray3DGetDescriptor" ) );
		hydrazine::bit_cast( cuTexRefCreate, dlsym( _driver, 
			"cuTexRefCreate" ) );
		hydrazine::bit_cast( cuTexRefDestroy, dlsym( _driver, 
			"cuTexRefDestroy" ) );
		hydrazine::bit_cast( cuTexRefSetArray, dlsym( _driver, 
			"cuTexRefSetArray" ) );
		hydrazine::bit_cast( cuTexRefSetAddress, dlsym( _driver, 
			"cuTexRefSetAddress" ) );
		hydrazine::bit_cast( cuTexRefSetAddress2D, dlsym( _driver, 
			"cuTexRefSetAddress2D" ) );
		hydrazine::bit_cast( cuTexRefSetFormat, dlsym( _driver, 
			"cuTexRefSetFormat" ) );
		hydrazine::bit_cast( cuTexRefSetAddressMode, dlsym( _driver, 
			"cuTexRefSetAddressMode" ) );
		hydrazine::bit_cast( cuTexRefSetFilterMode, dlsym( _driver, 
			"cuTexRefSetFilterMode" ) );
		hydrazine::bit_cast( cuTexRefSetFlags, dlsym( _driver, 
			"cuTexRefSetFlags" ) );
		hydrazine::bit_cast( cuTexRefGetAddress, dlsym( _driver, 
			"cuTexRefGetAddress" ) );
		hydrazine::bit_cast( cuTexRefGetArray, dlsym( _driver, 
			"cuTexRefGetArray" ) );
		hydrazine::bit_cast( cuTexRefGetAddressMode, dlsym( _driver, 
			"cuTexRefGetAddressMode" ) );
		hydrazine::bit_cast( cuTexRefGetFilterMode, dlsym( _driver, 
			"cuTexRefGetFilterMode" ) );
		hydrazine::bit_cast( cuTexRefGetFormat, dlsym( _driver, 
			"cuTexRefGetFormat" ) );
		hydrazine::bit_cast( cuTexRefGetFlags, dlsym( _driver, 
			"cuTexRefGetFlags" ) );
		hydrazine::bit_cast( cuParamSetSize, dlsym( _driver, 
			"cuParamSetSize" ) );
		hydrazine::bit_cast( cuParamSeti, dlsym( _driver, "cuParamSeti" ) );
		hydrazine::bit_cast( cuParamSetf, dlsym( _driver, "cuParamSetf" ) );
		hydrazine::bit_cast( cuParamSetv, dlsym( _driver, "cuParamSetv" ) );
		hydrazine::bit_cast( cuParamSetTexRef, dlsym( _driver, 
			"cuParamSetTexRef" ) );
		hydrazine::bit_cast( cuLaunch, dlsym( _driver, "cuLaunch" ) );
		hydrazine::bit_cast( cuLaunchGrid, dlsym( _driver, "cuLaunchGrid" ) );
		hydrazine::bit_cast( cuLaunchGridAsync, dlsym( _driver, 
			"cuLaunchGridAsync" ) );
		hydrazine::bit_cast( cuEventCreate, dlsym( _driver, 
			"cuEventCreate" ) );
		hydrazine::bit_cast( cuEventRecord, dlsym( _driver, 
			"cuEventRecord" ) );
		hydrazine::bit_cast( cuEventQuery, dlsym( _driver, "cuEventQuery" ) );
		hydrazine::bit_cast( cuEventSynchronize, dlsym( _driver, 
			"cuEventSynchronize" ) );
		hydrazine::bit_cast( cuEventDestroy, dlsym( _driver, 
			"cuEventDestroy" ) );
		hydrazine::bit_cast( cuEventElapsedTime, dlsym( _driver, 
			"cuEventElapsedTime" ) );
		hydrazine::bit_cast( cuStreamCreate, dlsym( _driver, 
			"cuStreamCreate" ) );
		hydrazine::bit_cast( cuStreamQuery, dlsym( _driver, 
			"cuStreamQuery" ) );
		hydrazine::bit_cast( cuStreamSynchronize, dlsym( _driver, 
			"cuStreamSynchronize" ) );
		hydrazine::bit_cast( cuStreamDestroy, dlsym( _driver, 
			"cuStreamDestroy" ) );

		hydrazine::bit_cast( cuGraphicsUnregisterResource, dlsym( _driver,
			"cuGraphicsUnregisterResource" ) ); 
		hydrazine::bit_cast( cuGraphicsSubResourceGetMappedArray, 
			dlsym( _driver, "cuGraphicsSubResourceGetMappedArray" ) );
		hydrazine::bit_cast( cuGraphicsResourceGetMappedPointer, dlsym( _driver,
			"cuGraphicsResourceGetMappedPointer" ) );
		hydrazine::bit_cast( cuGraphicsResourceSetMapFlags, dlsym( _driver,
			"cuGraphicsResourceSetMapFlags" ) );
		hydrazine::bit_cast( cuGraphicsMapResources, dlsym( _driver,
			"cuGraphicsMapResources" ) );
		hydrazine::bit_cast( cuGraphicsUnmapResources, dlsym( _driver,
			"cuGraphicsUnmapResources" ) );

		hydrazine::bit_cast( cuGLInit, dlsym( _driver, "cuGLInit" ) );
		hydrazine::bit_cast( cuGLCtxCreate, dlsym( _driver,	"cuGLCtxCreate" ) );
		hydrazine::bit_cast( cuGraphicsGLRegisterBuffer, dlsym( _driver,
			"cuGraphicsGLRegisterBuffer" ) );
		hydrazine::bit_cast( cuGraphicsGLRegisterImage, dlsym( _driver,
			"cuGraphicsGLRegisterImage" ) );

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
		report("cuInit");
		return (*_interface.cuInit)(Flags);
	}

	CUresult CudaDriver::cuDriverGetVersion(int *driverVersion)
	{
		CHECK();
		return (*_interface.cuDriverGetVersion)(driverVersion);
	}

	CUresult CudaDriver::cuDeviceGet(CUdevice *device, int ordinal)
	{
		CHECK();
		return (*_interface.cuDeviceGet)(device, ordinal);
	}

	CUresult CudaDriver::cuDeviceGetCount(int *count)
	{
		if( !_interface.loaded() )
		{
			*count = 0;
			return CUDA_SUCCESS;
		}
		
		CUresult result= (*_interface.cuDeviceGetCount)(count);
		
		if(result != CUDA_SUCCESS)
		{
			*count = 0;
			return CUDA_SUCCESS;
		}
		
		return result;
	}

	CUresult CudaDriver::cuDeviceGetName(char *name, int len, CUdevice dev)
	{
		CHECK();
		return (*_interface.cuDeviceGetName)(name, len, dev);
	}

	CUresult CudaDriver::cuDeviceComputeCapability(int *major, int *minor, 
		CUdevice dev)
	{
		CHECK();
		return (*_interface.cuDeviceComputeCapability)(major, minor, dev);
	}

	CUresult CudaDriver::cuDeviceTotalMem(unsigned int *bytes, CUdevice dev)
	{
		CHECK();
		return (*_interface.cuDeviceTotalMem)(bytes, dev);
	}

	CUresult CudaDriver::cuDeviceGetProperties(CUdevprop *prop, CUdevice dev)
	{
		CHECK();
		return (*_interface.cuDeviceGetProperties)(prop, dev);
	}

	CUresult CudaDriver::cuDeviceGetAttribute(int *pi, 
		CUdevice_attribute attrib, CUdevice dev)
	{
		CHECK();
		return (*_interface.cuDeviceGetAttribute)(pi, attrib, dev);
	}

	CUresult CudaDriver::cuCtxCreate(CUcontext *pctx, unsigned int flags, 
		CUdevice dev )
	{
		CHECK();
		return (*_interface.cuCtxCreate)(pctx, flags, dev);
	}
	
	CUresult CudaDriver::cuCtxGetLimit(size_t *pval, CUlimit limit) 
	{
		CHECK();
		return (*_interface.cuCtxGetLimit)(pval, limit);
	}

	CUresult CudaDriver::cuCtxDestroy( CUcontext ctx )
	{
		CHECK();
		return (*_interface.cuCtxDestroy)(ctx);
	}

	CUresult CudaDriver::cuCtxAttach(CUcontext *pctx, unsigned int flags)
	{
		CHECK();
		return (*_interface.cuCtxAttach)(pctx, flags);
	}

	CUresult CudaDriver::cuCtxDetach(CUcontext ctx)
	{
		CHECK();
		return (*_interface.cuCtxDetach)(ctx);
	}

	CUresult CudaDriver::cuCtxPushCurrent( CUcontext ctx )
	{
		CHECK();
		return (*_interface.cuCtxPushCurrent)(ctx);
	}

	CUresult CudaDriver::cuCtxPopCurrent( CUcontext *pctx )
	{
		CHECK();
		return (*_interface.cuCtxPopCurrent)(pctx);
	}

	CUresult CudaDriver::cuCtxGetDevice(CUdevice *device)
	{
		CHECK();
		return (*_interface.cuCtxGetDevice)(device);
	}

	CUresult CudaDriver::cuCtxSynchronize(void)
	{
		CHECK();
		return (*_interface.cuCtxSynchronize)();
	}

	CUresult CudaDriver::cuModuleLoad(CUmodule *module, const char *fname)
	{
		CHECK();
		return (*_interface.cuModuleLoad)(module, fname);
	}

	CUresult CudaDriver::cuModuleLoadData(CUmodule *module, const void *image)
	{
		CHECK();
		return (*_interface.cuModuleLoadData)(module, image);
	}

	CUresult CudaDriver::cuModuleLoadDataEx(CUmodule *module, 
		const void *image, unsigned int numOptions, CUjit_option *options, 
		void **optionValues)
	{
		CHECK();
		return (*_interface.cuModuleLoadDataEx)(module, image, 
			numOptions, options, optionValues);
	}

	CUresult CudaDriver::cuModuleLoadFatBinary(CUmodule *module, 
		const void *fatCubin)
	{
		CHECK();
		return (*_interface.cuModuleLoadFatBinary)(module, fatCubin);
	}

	CUresult CudaDriver::cuModuleUnload(CUmodule hmod)
	{
		CHECK();
		return (*_interface.cuModuleUnload)(hmod);
	}

	CUresult CudaDriver::cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, 
		const char *name)
	{
		CHECK();
		return (*_interface.cuModuleGetFunction)(hfunc, hmod, name);
	}

	CUresult CudaDriver::cuModuleGetGlobal(CUdeviceptr *dptr, 
		unsigned int *bytes, CUmodule hmod, const char *name)
	{
		CHECK();
		return (*_interface.cuModuleGetGlobal)(dptr, bytes, hmod, name);
	}

	CUresult CudaDriver::cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, 
		const char *name)
	{
		CHECK();
		return (*_interface.cuModuleGetTexRef)(pTexRef, hmod, name);
	}


	CUresult CudaDriver::cuMemGetInfo(unsigned int *free, unsigned int *total)
	{
		CHECK();
		return (*_interface.cuMemGetInfo)(free, total);
	}


	CUresult CudaDriver::cuMemAlloc( CUdeviceptr *dptr, unsigned int bytesize)
	{
		CHECK();
		return (*_interface.cuMemAlloc)(dptr, bytesize);
	}

	CUresult CudaDriver::cuMemAllocPitch( CUdeviceptr *dptr, 
				          unsigned int *pPitch,
				          unsigned int WidthInBytes, 
				          unsigned int Height, 
				          unsigned int ElementSizeBytes
				         )
	{
		CHECK();
		return (*_interface.cuMemAllocPitch)(dptr, pPitch, WidthInBytes, 
			Height, ElementSizeBytes);
	}

	CUresult CudaDriver::cuMemFree(CUdeviceptr dptr)
	{
		CHECK();
		return (*_interface.cuMemFree)(dptr);
	}

	CUresult CudaDriver::cuMemGetAddressRange( CUdeviceptr *pbase, 
		unsigned int *psize, CUdeviceptr dptr )
	{
		CHECK();
		return (*_interface.cuMemGetAddressRange)(pbase, psize, dptr);
	}

	CUresult CudaDriver::cuMemAllocHost(void **pp, unsigned int bytesize)
	{
		CHECK();
		return (*_interface.cuMemAllocHost)(pp, bytesize);
	}

	CUresult CudaDriver::cuMemFreeHost(void *p)
	{
		CHECK();
		return (*_interface.cuMemFreeHost)(p);
	}

	CUresult CudaDriver::cuMemHostAlloc(void **pp, 
		unsigned long long bytesize, unsigned int Flags )
	{
		CHECK();
		return (*_interface.cuMemHostAlloc)(pp, bytesize, Flags);
	}

	CUresult CudaDriver::cuMemHostGetDevicePointer( CUdeviceptr *pdptr, 
		void *p, unsigned int Flags )
	{
		CHECK();
		return (*_interface.cuMemHostGetDevicePointer)(pdptr, p, Flags);
	}

	CUresult CudaDriver::cuMemHostGetFlags( unsigned int *pFlags, void *p )
	{
		CHECK();
		return (*_interface.cuMemHostGetFlags)(pFlags, p);
	}

	CUresult CudaDriver::cuMemcpyHtoD(CUdeviceptr dstDevice, 
		const void *srcHost, unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyHtoD)(dstDevice, srcHost, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, 
		unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyDtoH)(dstHost, srcDevice, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyDtoD(CUdeviceptr dstDevice, 
		CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyDtoD)(dstDevice, srcDevice, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyDtoA( CUarray dstArray, 
		unsigned int dstIndex, CUdeviceptr srcDevice, unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyDtoA)(dstArray, dstIndex, srcDevice, 
			ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoD( CUdeviceptr dstDevice, CUarray hSrc, 
		unsigned int SrcIndex, unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyAtoD)(dstDevice, hSrc, SrcIndex, 
			ByteCount);
	}

	CUresult CudaDriver::cuMemcpyHtoA( CUarray dstArray, 
		unsigned int dstIndex, const void *pSrc, unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyHtoA)(dstArray, dstIndex, pSrc, ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoH( void *dstHost, CUarray srcArray, 
		unsigned int srcIndex, unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyAtoH)(dstHost, srcArray, srcIndex, 
			ByteCount);
	}

	CUresult CudaDriver::cuMemcpyAtoA( CUarray dstArray, 
		unsigned int dstIndex, CUarray srcArray, unsigned int srcIndex, 
		unsigned int ByteCount )
	{
		CHECK();
		return (*_interface.cuMemcpyAtoA)(dstArray, dstIndex, srcArray, 
			srcIndex, ByteCount);
	}

	CUresult CudaDriver::cuMemcpy2D( const CUDA_MEMCPY2D *pCopy )
	{
		CHECK();
		return (*_interface.cuMemcpy2D)(pCopy);
	}

	CUresult CudaDriver::cuMemcpy2DUnaligned( const CUDA_MEMCPY2D *pCopy )
	{
		CHECK();
		return (*_interface.cuMemcpy2DUnaligned)(pCopy);
	}

	CUresult CudaDriver::cuMemcpy3D( const CUDA_MEMCPY3D *pCopy )
	{
		CHECK();
		return (*_interface.cuMemcpy3D)(pCopy);
	}
	
	CUresult CudaDriver::cuMemcpyHtoDAsync (CUdeviceptr dstDevice, 
		const void *srcHost, unsigned int ByteCount, CUstream hStream )
	{
		CHECK();
		return (*_interface.cuMemcpyHtoDAsync)(dstDevice, srcHost, 
			ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyDtoHAsync (void *dstHost, 
	CUdeviceptr srcDevice, unsigned int ByteCount, CUstream hStream )
	{
		CHECK();
		return (*_interface.cuMemcpyDtoHAsync)(dstHost, srcDevice, 
			ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyHtoAAsync( CUarray dstArray, 
		unsigned int dstIndex, const void *pSrc, unsigned int ByteCount, 
		CUstream hStream )
	{
		CHECK();
		return (*_interface.cuMemcpyHtoAAsync)(dstArray, dstIndex, pSrc, 
			ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpyAtoHAsync( void *dstHost, CUarray srcArray, 
		unsigned int srcIndex, unsigned int ByteCount, CUstream hStream )
	{
		CHECK();
		return (*_interface.cuMemcpyAtoHAsync)(dstHost, srcArray, srcIndex, 
			ByteCount, hStream);
	}

	CUresult CudaDriver::cuMemcpy2DAsync( const CUDA_MEMCPY2D *pCopy, 
		CUstream hStream )
	{
		CHECK();
		return (*_interface.cuMemcpy2DAsync)(pCopy, hStream);
	}

	CUresult CudaDriver::cuMemcpy3DAsync( const CUDA_MEMCPY3D *pCopy, 
		CUstream hStream )
	{
		CHECK();
		return (*_interface.cuMemcpy3DAsync)(pCopy, hStream);
	}

	CUresult CudaDriver::cuMemsetD8( CUdeviceptr dstDevice, unsigned char uc, 
		unsigned int N )
	{
		CHECK();
		return (*_interface.cuMemsetD8)(dstDevice, uc, N);
	}

	CUresult CudaDriver::cuMemsetD16( CUdeviceptr dstDevice, 
		unsigned short us, unsigned int N )
	{
		CHECK();
		return (*_interface.cuMemsetD16)(dstDevice, us, N);
	}

	CUresult CudaDriver::cuMemsetD32( CUdeviceptr dstDevice, unsigned int ui, 
		unsigned int N )
	{
		CHECK();
		return (*_interface.cuMemsetD32)(dstDevice, ui, N);
	}

	CUresult CudaDriver::cuMemsetD2D8( CUdeviceptr dstDevice, 
		unsigned int dstPitch, unsigned char uc, unsigned int Width, 
		unsigned int Height )
	{
		CHECK();
		return (*_interface.cuMemsetD2D8)(dstDevice, dstPitch, uc, 
			Width, Height);
	}

	CUresult CudaDriver::cuMemsetD2D16( CUdeviceptr dstDevice, 
		unsigned int dstPitch, unsigned short us, unsigned int Width, 
		unsigned int Height )
	{
		CHECK();
		return (*_interface.cuMemsetD2D16)(dstDevice, dstPitch, us, 
			Width, Height);
	}

	CUresult CudaDriver::cuMemsetD2D32( CUdeviceptr dstDevice, 
		unsigned int dstPitch, unsigned int ui, unsigned int Width, 
		unsigned int Height )
	{
		CHECK();
		return (*_interface.cuMemsetD2D32)(dstDevice, dstPitch, ui, 
			Width, Height);
	}


	CUresult CudaDriver::cuFuncSetBlockShape(CUfunction hfunc, int x, int y, 
		int z)
	{
		CHECK();
		return (*_interface.cuFuncSetBlockShape)(hfunc, x, y, z);
	}

	CUresult CudaDriver::cuFuncSetSharedSize(CUfunction hfunc, 
		unsigned int bytes)
	{
		CHECK();
		return (*_interface.cuFuncSetSharedSize)(hfunc, bytes);
	}

	CUresult CudaDriver::cuFuncGetAttribute(int *pi, 
		CUfunction_attribute attrib, CUfunction hfunc)
	{
		CHECK();
		return (*_interface.cuFuncGetAttribute)(pi, attrib, hfunc);
	}

	CUresult CudaDriver::cuArrayCreate( CUarray *pHandle, 
		const CUDA_ARRAY_DESCRIPTOR *pAllocateArray )
	{
		CHECK();
		return (*_interface.cuArrayCreate)(pHandle, pAllocateArray);
	}

	CUresult CudaDriver::cuArrayGetDescriptor( 
		CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray )
	{
		CHECK();
		return (*_interface.cuArrayGetDescriptor)(pArrayDescriptor, hArray);
	}

	CUresult CudaDriver::cuArrayDestroy( CUarray hArray )
	{
		CHECK();
		return (*_interface.cuArrayDestroy)(hArray);
	}

	CUresult CudaDriver::cuArray3DCreate( CUarray *pHandle, 
		const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray )
	{
		CHECK();
		return (*_interface.cuArray3DCreate)(pHandle, pAllocateArray);
	}

	CUresult CudaDriver::cuArray3DGetDescriptor( 
		CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray )
	{
		CHECK();
		return (*_interface.cuArray3DGetDescriptor)(pArrayDescriptor, hArray);
	}

	CUresult CudaDriver::cuTexRefCreate( CUtexref *pTexRef )
	{
		CHECK();
		return (*_interface.cuTexRefCreate)(pTexRef);
	}

	CUresult CudaDriver::cuTexRefDestroy( CUtexref hTexRef )
	{
		CHECK();
		return (*_interface.cuTexRefDestroy)(hTexRef);
	}

	CUresult CudaDriver::cuTexRefSetArray( CUtexref hTexRef, CUarray hArray, 
		unsigned int Flags )
	{
		CHECK();
		return (*_interface.cuTexRefSetArray)(hTexRef, hArray, Flags);
	}

	CUresult CudaDriver::cuTexRefSetAddress( unsigned int *ByteOffset, 
		CUtexref hTexRef, CUdeviceptr dptr, unsigned int bytes )
	{
		CHECK();
		return (*_interface.cuTexRefSetAddress)(ByteOffset, hTexRef, 
			dptr, bytes);
	}

	CUresult CudaDriver::cuTexRefSetAddress2D( CUtexref hTexRef, 
		const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, 
		unsigned int Pitch)
	{
		CHECK();
		return (*_interface.cuTexRefSetAddress2D)(hTexRef, desc, dptr, Pitch);
	}

	CUresult CudaDriver::cuTexRefSetFormat( CUtexref hTexRef, 
		CUarray_format fmt, int NumPackedComponents )
	{
		CHECK();
		return (*_interface.cuTexRefSetFormat)(hTexRef, fmt, 
			NumPackedComponents);
	}

	CUresult CudaDriver::cuTexRefSetAddressMode( CUtexref hTexRef, int dim, 
		CUaddress_mode am )
	{
		CHECK();
		return (*_interface.cuTexRefSetAddressMode)(hTexRef, dim, am);
	}

	CUresult CudaDriver::cuTexRefSetFilterMode( CUtexref hTexRef, 
		CUfilter_mode fm )
	{
		CHECK();
		return (*_interface.cuTexRefSetFilterMode)(hTexRef, fm);
	}

	CUresult CudaDriver::cuTexRefSetFlags( CUtexref hTexRef, 
		unsigned int Flags )
	{
		CHECK();
		return (*_interface.cuTexRefSetFlags)(hTexRef, Flags);
	}


	CUresult CudaDriver::cuTexRefGetAddress( CUdeviceptr *pdptr, 
		CUtexref hTexRef )
	{
		CHECK();
		return (*_interface.cuTexRefGetAddress)(pdptr, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetArray( CUarray *phArray, CUtexref hTexRef )
	{
		CHECK();
		return (*_interface.cuTexRefGetArray)(phArray, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetAddressMode( CUaddress_mode *pam, 
		CUtexref hTexRef, int dim )
	{
		CHECK();
		return (*_interface.cuTexRefGetAddressMode)(pam, hTexRef, dim);
	}

	CUresult CudaDriver::cuTexRefGetFilterMode( CUfilter_mode *pfm, 
		CUtexref hTexRef )
	{
		CHECK();
		return (*_interface.cuTexRefGetFilterMode)(pfm, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetFormat( CUarray_format *pFormat, 
		int *pNumChannels, CUtexref hTexRef )
	{
		CHECK();
		return (*_interface.cuTexRefGetFormat)(pFormat, pNumChannels, hTexRef);
	}

	CUresult CudaDriver::cuTexRefGetFlags( unsigned int *pFlags, 
		CUtexref hTexRef )
	{
		CHECK();
		return (*_interface.cuTexRefGetFlags)(pFlags, hTexRef);
	}


	CUresult CudaDriver::cuParamSetSize(CUfunction hfunc, 
		unsigned int numbytes)
	{
		CHECK();
		return (*_interface.cuParamSetSize)(hfunc, numbytes);
	}

	CUresult CudaDriver::cuParamSeti(CUfunction hfunc, int offset, 
		unsigned int value)
	{
		CHECK();
		return (*_interface.cuParamSeti)(hfunc, offset, value);
	}

	CUresult CudaDriver::cuParamSetf(CUfunction hfunc, int offset, float value)
	{
		CHECK();
		return (*_interface.cuParamSetf)(hfunc, offset, value);
	}

	CUresult CudaDriver::cuParamSetv(CUfunction hfunc, int offset, 
		void * ptr, unsigned int numbytes)
	{
		CHECK();
		return (*_interface.cuParamSetv)(hfunc, offset, ptr, numbytes);
	}

	CUresult CudaDriver::cuParamSetTexRef(CUfunction hfunc, int texunit, 
		CUtexref hTexRef)
	{
		CHECK();
		return (*_interface.cuParamSetTexRef)(hfunc, texunit, hTexRef);
	}


	CUresult CudaDriver::cuLaunch ( CUfunction f )
	{
		CHECK();
		return (*_interface.cuLaunch)(f);
	}

	CUresult CudaDriver::cuLaunchGrid (CUfunction f, int grid_width, 
		int grid_height)
	{
		CHECK();
		return (*_interface.cuLaunchGrid)(f, grid_width, grid_height);
	}

	CUresult CudaDriver::cuLaunchGridAsync( CUfunction f, int grid_width, 
		int grid_height, CUstream hStream )
	{
		CHECK();
		return (*_interface.cuLaunchGridAsync)(f, grid_width, grid_height, 
			hStream);
	}


	CUresult CudaDriver::cuEventCreate( CUevent *phEvent, unsigned int Flags )
	{
		CHECK();
		return (*_interface.cuEventCreate)(phEvent, Flags);
	}

	CUresult CudaDriver::cuEventRecord( CUevent hEvent, CUstream hStream )
	{
		CHECK();
		return (*_interface.cuEventRecord)(hEvent, hStream);
	}

	CUresult CudaDriver::cuEventQuery( CUevent hEvent )
	{
		CHECK();
		return (*_interface.cuEventQuery)(hEvent);
	}

	CUresult CudaDriver::cuEventSynchronize( CUevent hEvent )
	{
		CHECK();
		return (*_interface.cuEventSynchronize)(hEvent);
	}

	CUresult CudaDriver::cuEventDestroy( CUevent hEvent )
	{
		CHECK();
		return (*_interface.cuEventDestroy)(hEvent);
	}

	CUresult CudaDriver::cuEventElapsedTime( float *pMilliseconds, 
		CUevent hStart, CUevent hEnd )
	{
		CHECK();
		return (*_interface.cuEventElapsedTime)(pMilliseconds, hStart, hEnd);
	}


	CUresult CudaDriver::cuStreamCreate( CUstream *phStream, 
		unsigned int Flags )
	{
		CHECK();
		return (*_interface.cuStreamCreate)(phStream, Flags);
	}

	CUresult CudaDriver::cuStreamQuery( CUstream hStream )
	{
		CHECK();
		return (*_interface.cuStreamQuery)(hStream);
	}

	CUresult CudaDriver::cuStreamSynchronize( CUstream hStream )
	{
		CHECK();
		return (*_interface.cuStreamSynchronize)(hStream);
	}

	CUresult CudaDriver::cuStreamDestroy( CUstream hStream )
	{
		CHECK();
		return (*_interface.cuStreamDestroy)(hStream);
	}
	
	CUresult CudaDriver::cuGraphicsUnregisterResource(
		CUgraphicsResource resource)
	{
		CHECK();
		return (*_interface.cuGraphicsUnregisterResource)(resource);
	}
	
	CUresult CudaDriver::cuGraphicsSubResourceGetMappedArray(
		CUarray *pArray, CUgraphicsResource resource, 
		unsigned int arrayIndex, unsigned int mipLevel )
	{
		CHECK();
		return (*_interface.cuGraphicsSubResourceGetMappedArray)(pArray, 
			resource, arrayIndex, mipLevel);
	}

	CUresult CudaDriver::cuGraphicsResourceGetMappedPointer(
		CUdeviceptr *pDevPtr, unsigned int *pSize, 
		CUgraphicsResource resource)
	{
		CHECK();
		return (*_interface.cuGraphicsResourceGetMappedPointer)(pDevPtr, 
			pSize, resource);
	}
		
	CUresult CudaDriver::cuGraphicsResourceSetMapFlags(
		CUgraphicsResource resource, unsigned int flags ) 
	{
		CHECK();
		return (*_interface.cuGraphicsResourceSetMapFlags)(resource, flags);
	}

	CUresult CudaDriver::cuGraphicsMapResources(unsigned int count, 
		CUgraphicsResource *resources, CUstream hStream)
	{
		CHECK();
		return (*_interface.cuGraphicsMapResources)(count, resources, hStream);
	}

	CUresult CudaDriver::cuGraphicsUnmapResources(unsigned int count, 
		CUgraphicsResource *resources, CUstream hStream)
	{
		CHECK();
		return (*_interface.cuGraphicsUnmapResources)(count, 
			resources, hStream);
	}

	CUresult CudaDriver::cuGLInit()
	{
		CHECK();
		return (*_interface.cuGLInit)();
	}

	CUresult CudaDriver::cuGLCtxCreate(CUcontext *pCtx, 
		unsigned int Flags, CUdevice device)
	{
		CHECK();
		return (*_interface.cuGLCtxCreate)(pCtx, Flags, device);
	}

	CUresult CudaDriver::cuGraphicsGLRegisterBuffer( 
		CUgraphicsResource *pCudaResource, unsigned int buffer, 
		unsigned int Flags )
	{
		CHECK();
		return (*_interface.cuGraphicsGLRegisterBuffer)(pCudaResource, 
			buffer, Flags);
	}

	CUresult CudaDriver::cuGraphicsGLRegisterImage( 
		CUgraphicsResource *pCudaResource, unsigned int image, 
		int target, unsigned int Flags)
	{
		CHECK();
		return (*_interface.cuGraphicsGLRegisterImage)(pCudaResource, image, 
			target, Flags);
	}

	std::string CudaDriver::toString(CUresult r)
	{
		switch( r )
		{
			case CUDA_SUCCESS: return "CUDA DRIVER - no errors";
			case CUDA_ERROR_INVALID_VALUE: return "CUDA DRIVER - invalid value";
			case CUDA_ERROR_OUT_OF_MEMORY: return "CUDA DRIVER - out of memory";
			case CUDA_ERROR_NOT_INITIALIZED:
				return "CUDA DRIVER - driver not initialized";
			case CUDA_ERROR_DEINITIALIZED: return "CUDA DRIVER - deinitialized";
			case CUDA_ERROR_NO_DEVICE: return "CUDA DRIVER - no device";
			case CUDA_ERROR_INVALID_DEVICE:
				return "CUDA DRIVER - invalid device";
			case CUDA_ERROR_INVALID_IMAGE:
				return "CUDA DRIVER - invalid kernel image";
			case CUDA_ERROR_INVALID_CONTEXT:
				return "CUDA DRIVER - invalid context";
			case CUDA_ERROR_CONTEXT_ALREADY_CURRENT: 
				return "CUDA DRIVER - context already current";
			case CUDA_ERROR_MAP_FAILED: return "CUDA DRIVER - map failed";
			case CUDA_ERROR_UNMAP_FAILED: return "CUDA DRIVER - unmap failed";
			case CUDA_ERROR_ARRAY_IS_MAPPED:
				return "CUDA DRIVER - array is mapped";
			case CUDA_ERROR_ALREADY_MAPPED:
				return "CUDA DRIVER - already mapped";
			case CUDA_ERROR_NO_BINARY_FOR_GPU:
				return "CUDA DRIVER - no gpu binary";
			case CUDA_ERROR_ALREADY_ACQUIRED:
				return "CUDA DRIVER - already aquired";
			case CUDA_ERROR_NOT_MAPPED: return "CUDA DRIVER - not mapped";
			case CUDA_ERROR_INVALID_SOURCE:
				return "CUDA DRIVER - invalid source";
			case CUDA_ERROR_FILE_NOT_FOUND:
				return "CUDA DRIVER - file not found";
			case CUDA_ERROR_INVALID_HANDLE:
				return "CUDA DRIVER - invalid handle";
			case CUDA_ERROR_NOT_FOUND: return "CUDA DRIVER - not found";
			case CUDA_ERROR_NOT_READY: return "CUDA DRIVER - not ready";
			case CUDA_ERROR_LAUNCH_FAILED: return "CUDA DRIVER - launch failed";
			case CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES:
				return "CUDA DRIVER - out of resources";
			case CUDA_ERROR_LAUNCH_TIMEOUT:
				return "CUDA DRIVER - launch timeout";
			case CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING: 
				return "CUDA DRIVER - incompatible texturing";
			case CUDA_ERROR_UNKNOWN: return "CUDA DRIVER - unknown error";
			default: break;
		}
		return "invalid_error";
	}
	
}

#endif

