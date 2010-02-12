/*! \file CudaRuntimeBase.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Saturday September 5, 2009
	\brief The source file for the CudaRuntimeBase class.
*/

#ifndef CUDA_RUNTIME_BASE_CPP_INCLUDED
#define CUDA_RUNTIME_BASE_CPP_INCLUDED

#include <ocelot/cuda/interface/CudaRuntimeBase.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_MEMORY 0

namespace cuda
{
	cudaError_t CudaRuntimeBase::cudaMalloc3D( cudaPitchedPtr* pitchedDevPtr, 
		cudaExtent extent )
	{
		pitchedDevPtr->pitch = 0;
		pitchedDevPtr->xsize = extent.width;
		pitchedDevPtr->ysize = extent.height;
		return cudaMalloc( &pitchedDevPtr->ptr, 
			extent.width * extent.height * extent.depth );	
	}

	cudaError_t CudaRuntimeBase::cudaMalloc3DArray( cudaArray** arrayPtr, 
		const cudaChannelFormatDesc* desc, cudaExtent extent )
	{
		_runtime.lock();
		_runtime.setContext();
	
		*arrayPtr = _runtime.allocateArray( *desc, extent.width, 
			extent.height, extent.depth );
	
		reportE( REPORT_MEMORY, "Allocated device 3D array width " 
			<< extent.width 
			<< " height " << extent.height << " length " << extent.depth 
			<<  " to pointer " << *arrayPtr << "." );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaMemset3D( cudaPitchedPtr pitchedDevPtr, 
		int value, cudaExtent extent )
	{
		return cudaMemset( pitchedDevPtr.ptr, value, 
			extent.height * extent.depth * extent.width );	
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy3D( const cudaMemcpy3DParms* p )
	{
		if(p->srcArray != 0)
		{	
			if(p->dstArray != 0)
			{
				return cudaMemcpyArrayToArray(p->dstArray, p->dstPos.x, 
					p->dstPos.y, p->srcArray, p->srcPos.x, p->srcPos.y, 
					p->extent.width * p->extent.height * p->extent.depth, p->kind );
			}
			else
			{
				unsigned int doffset = p->dstPos.x + p->dstPos.y 
					* p->dstPtr.xsize + p->dstPos.y * p->dstPtr.xsize 
					* p->dstPtr.ysize;
				return cudaMemcpyFromArray((char*)p->dstPtr.ptr + doffset, 
					p->srcArray, p->srcPos.x, p->srcPos.y, 
					p->extent.width * p->extent.height * p->extent.depth, 
					p->kind );
			}
		}
		else
		{
			if(p->dstPtr.ptr != 0)
			{
				unsigned int soffset = p->srcPos.x + p->srcPos.y 
					* p->srcPtr.xsize + p->srcPos.y * p->srcPtr.xsize 
					* p->srcPtr.ysize;
				unsigned int doffset = p->dstPos.x + p->dstPos.y 
					* p->dstPtr.xsize + p->dstPos.y * p->dstPtr.xsize 
					* p->dstPtr.ysize;
				return cudaMemcpy((char*)p->dstPtr.ptr + doffset, 
					(char*)p->srcPtr.ptr + soffset, 
					p->extent.width * p->extent.height * p->extent.depth, 
					p->kind);
			}
			else
			{
				assert(p->dstArray != 0);
				unsigned int soffset = p->srcPos.x + p->srcPos.y 
					* p->srcPtr.xsize + p->srcPos.y * p->srcPtr.xsize 
					* p->srcPtr.ysize;
				return cudaMemcpyToArray(p->dstArray, p->dstPos.x, p->dstPos.y, 
					(char*)p->srcPtr.ptr + soffset, 
					p->extent.width * p->extent.height * p->extent.depth, 
					p->kind);			
			}
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy3DAsync( const cudaMemcpy3DParms* p, 
		cudaStream_t stream )
	{
		if( !_runtime.streamValid( stream ) )
		{
			return cudaErrorInvalidResourceHandle;	
		}

		return cudaMemcpy3D(p);	
	}

	cudaError_t CudaRuntimeBase::cudaMalloc( void** devPtr, size_t size )
	{
		_runtime.lock();
		_runtime.setContext();
	
		*devPtr = _runtime.context.malloc( size );
	
		reportE( REPORT_MEMORY, "Allocated " << size 
			<< " bytes on CUDA device to pointer " << *devPtr << "." );
		
		_runtime.unlock();
	
		return cudaSuccess;	
	}

	cudaError_t CudaRuntimeBase::cudaMallocHost( void** ptr, size_t size )
	{
		_runtime.lock();
		_runtime.setContext();
	
		*ptr = _runtime.allocate( size );
	
		reportE( REPORT_MEMORY, "Allocated " << size 
			<< " bytes on HOST pinned memory to pointer " << *ptr << "." );
	
		_runtime.unlock();
	
		return cudaSuccess;	
	}

	cudaError_t CudaRuntimeBase::cudaMallocPitch( void** devPtr, 
		size_t* pitch, size_t width, size_t height )
	{
		*pitch = width;
		return cudaMalloc( devPtr, width * height);	
	}

	cudaError_t CudaRuntimeBase::cudaMallocArray( cudaArray** array, 
		const cudaChannelFormatDesc* desc, size_t width, size_t height )
	{
		_runtime.lock();
		_runtime.setContext();
	
		*array = _runtime.allocateArray( *desc, width, height );
	
		reportE( REPORT_MEMORY, "Allocated device 2D array width " << width 
			<< " height " << height << " to pointer " << *array << "." );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaFree( void* devPtr )
	{
		if( devPtr == 0 ) 
		{
			return cudaSuccess;
		}

		_runtime.lock();
		_runtime.setContext();

		reportE( REPORT_MEMORY, "Freeing memory " << devPtr << " on CUDA device." );
	
		_runtime.context.free( devPtr );
	
		_runtime.unlock();
	
		return cudaSuccess;	
	}

	cudaError_t CudaRuntimeBase::cudaFreeHost( void* ptr )
	{
		if( ptr == 0 ) 
		{
			return cudaSuccess;
		}

		_runtime.lock();
		_runtime.setContext();

		reportE( REPORT_MEMORY, "Freeing HOST pinned memory " << ptr << "." );
	
//		_runtime.free( ptr );
		_runtime.freeHost( ptr );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaFreeArray( cudaArray* array )
	{
		_runtime.lock();
		_runtime.setContext();

		reportE( REPORT_MEMORY, "Freeing device array " << array << "." );
	
		_runtime.freeArray( array );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}


	cudaError_t CudaRuntimeBase::cudaHostAlloc( void** pHost, size_t bytes, 
		unsigned int flags )
	{
		_runtime.lock();
		_runtime.setContext();
	
		*pHost = _runtime.allocate( bytes, flags & cudaHostAllocPortable, 
			flags & cudaHostAllocMapped );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaHostGetDevicePointer( void** pDevice, 
		void* pHost, unsigned int flags )
	{
		if( flags != 0 )
		{
			return cudaErrorInvalidValue;
		}

		_runtime.lock();
		_runtime.setContext();
	
		try
		{
			*pDevice = _runtime.lookupMappedMemory( pHost );
		}
		catch( hydrazine::Exception& e )
		{
			_runtime.unlock();
			if( e.code == cudaErrorInvalidValue )
			{
				return cudaErrorInvalidValue;
			}
			else
			{
				throw;
			}
		}
	
		_runtime.unlock();
	
		return cudaSuccess;
	}


	cudaError_t CudaRuntimeBase::cudaMemcpy( void* dst, const void* src, 
		size_t count, cudaMemcpyKind kind )
	{
		_runtime.lock();
		_runtime.setContext();
	
		switch( kind )
		{
			case cudaMemcpyHostToHost:
			{
				reportE( REPORT_MEMORY, "Copying " << count 
					<< " bytes from host " << src << " to host " << dst );
				_runtime.context.memcpy( dst, src, count, 
					executive::Executive::HostToHost );
				break;
			}

			case cudaMemcpyHostToDevice:
			{
				reportE( REPORT_MEMORY, "Copying " << count 
					<< " bytes from host " << src << " to device " << dst );
				_runtime.context.memcpy( dst, src, count, 
					executive::Executive::HostToDevice );
				break;
			}

			case cudaMemcpyDeviceToHost:
			{
				reportE( REPORT_MEMORY,"Copying " << count 
					<< " bytes from device " << src << " to host " << dst );
				_runtime.context.memcpy( dst, src, count, 
					executive::Executive::DeviceToHost );
				break;
			}

			case cudaMemcpyDeviceToDevice:
			{
				reportE( REPORT_MEMORY, "Copying " << count 
					<< " bytes from device " << src << " to device " << dst );
				_runtime.context.memcpy( dst, src, count, 
					executive::Executive::DeviceToDevice );
				break;
			}
		}
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyToArray( cudaArray* dst, 
		size_t wOffset, size_t hOffset, const void* src, 
		size_t count, cudaMemcpyKind kind )
	{
		cudaError_t error = cudaSuccess;
	
		try
		{
			_runtime.lock();
			unsigned int offset = _runtime.offset( dst, wOffset, hOffset );
			_runtime.unlock();
			cudaMemcpy( (char*)dst + offset, src, count, kind );
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidValue )
			{
				_runtime.unlock();
				error = cudaErrorInvalidValue;
			}
			else
			{
				throw;
			}
		}
		return error;
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyFromArray( void* dst, 
		const cudaArray* src, size_t wOffset, size_t hOffset, 
		size_t count, cudaMemcpyKind kind )
	{
		cudaError_t error = cudaSuccess;
	
		try
		{
			_runtime.lock();
			unsigned int offset = _runtime.offset( src, wOffset, hOffset );
			_runtime.unlock();
			cudaMemcpy( dst, (char*)src + offset, count, kind );
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidValue )
			{
				_runtime.unlock();
				error = cudaErrorInvalidValue;
			}
			else
			{
				throw;
			}
		}
		return error;
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyArrayToArray( cudaArray* dst, 
		size_t wOffsetDst, size_t hOffsetDst, const cudaArray* src, 
		size_t wOffsetSrc, size_t hOffsetSrc, size_t count, 
		cudaMemcpyKind kind )
	{
		cudaError_t error = cudaSuccess;
	
		try
		{
			_runtime.lock();
			unsigned int sourceOffset = _runtime.offset( src, wOffsetDst, 
				hOffsetDst );
			unsigned int destinationOffset = _runtime.offset( dst, 
				wOffsetSrc, hOffsetSrc );
			_runtime.unlock();
			cudaMemcpy( (char*)dst + sourceOffset, 
				(char*)src + destinationOffset, count, kind );
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidValue )
			{
				_runtime.unlock();
				error = cudaErrorInvalidValue;
			}
			else
			{
				throw;
			}
		}
		return error;
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy2D( void* dst, size_t dpitch, 
		const void* src, size_t spitch, size_t width, size_t height, 
		cudaMemcpyKind kind )
	{
		return cudaMemcpy( dst, src, width * height, kind );
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy2DToArray( cudaArray* dst, 
		size_t wOffset, size_t hOffset, const void* src, 
		size_t spitch, size_t width, size_t height, 
		cudaMemcpyKind kind )
	{
		return cudaMemcpyToArray( dst, wOffset, hOffset, src, 
			width * height, kind );
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy2DFromArray( void* dst, 
		size_t dpitch, const cudaArray* src, size_t wOffset, 
		size_t hOffset, size_t width, size_t height, 
		cudaMemcpyKind kind )
	{
		return cudaMemcpyFromArray( dst, src, wOffset, hOffset, 
            width * height, kind );
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy2DArrayToArray( cudaArray* dst, 
		size_t wOffsetDst, size_t hOffsetDst, const cudaArray* src, 
		size_t wOffsetSrc, size_t hOffsetSrc, size_t width, 
		size_t height, cudaMemcpyKind kind )
	{
		return cudaMemcpyArrayToArray( dst, wOffsetDst, hOffsetDst, src, 
			wOffsetSrc, hOffsetSrc, width * height, kind );
	}	
	
	cudaError_t CudaRuntimeBase::cudaMemcpyToSymbol( const char* symbol, 
		const void* src, size_t count, size_t offset, cudaMemcpyKind kind )
	{
/*
		try
		{
			return cudaMemcpy( 
				( char* ) _runtime.getSymbol( symbol ) + offset, 
				src, count, cudaMemcpyHostToHost );	// changed from kind
		}
		catch( const hydrazine::Exception& e )
		{
			if(e.code == cudaErrorInvalidSymbol)
			{
				if( _runtime.isGlobal( symbol ) )
				{
					return cudaMemcpy( ( char* ) symbol + offset, 
						src, count, kind );
				}
				return cudaErrorInvalidSymbol;
			}
			else
			{
				throw;
			}
		}
*/
		return (_runtime.memcpyToSymbol(symbol, src, count, offset) ? cudaSuccess : cudaErrorInvalidSymbol);	
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyFromSymbol( void* dst, 
		const char* symbol, size_t count, size_t offset, cudaMemcpyKind kind )
	{
/*
		try
		{
			return cudaMemcpy( dst, 
				( char* ) _runtime.getSymbol( symbol ) + offset, 
				count, cudaMemcpyHostToHost );	// changed from kind
		}
		catch( const hydrazine::Exception& e )
		{
			if(e.code == cudaErrorInvalidSymbol)
			{			
				if( _runtime.isGlobal( symbol ) )
				{
					return cudaMemcpy( dst, symbol + offset, count, kind );
				}
				return cudaErrorInvalidSymbol;
			}
			else
			{
				throw;
			}
		}
*/
		return (_runtime.memcpyFromSymbol(dst, symbol, count, offset) ? cudaSuccess : cudaErrorInvalidSymbol);		
	}


	cudaError_t CudaRuntimeBase::cudaMemcpyAsync( void* dst, const void* src, 
		size_t count, cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpy( dst, src, count, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyToArrayAsync( cudaArray* dst, 
		size_t wOffset, size_t hOffset, const void* src, size_t count, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpyToArray( dst, wOffset, hOffset, src, count, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyFromArrayAsync( void* dst, 
		const cudaArray* src, size_t wOffset, size_t hOffset, 
		size_t count, cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpyFromArray( dst, src, wOffset, 
				hOffset, count, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy2DAsync( void* dst, size_t dpitch, 
		const void* src, size_t spitch, size_t width, size_t height, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpy2D( dst, dpitch, src, spitch, width, height, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy2DToArrayAsync( cudaArray* dst, 
		size_t wOffset, size_t hOffset, const void* src, 
		size_t spitch, size_t width, size_t height, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpy2DToArray( dst, wOffset, hOffset, src, spitch, width, 
				height, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpy2DFromArrayAsync( void* dst, 
		size_t dpitch, const cudaArray* src, size_t wOffset, 
		size_t hOffset, size_t width, size_t height, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpy2DFromArray( dst, dpitch, src, wOffset, hOffset, 
				width, height, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyToSymbolAsync( const char* symbol, 
		const void* src, size_t count, size_t offset, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpyToSymbol( symbol, src, count, offset, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaMemcpyFromSymbolAsync( void* dst, 
		const char* symbol, size_t count, size_t offset, 
		cudaMemcpyKind kind, cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			_runtime.unlock();	
			return cudaMemcpyFromSymbol( dst, symbol, count, offset, kind );
		}
		else
		{
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}


	cudaError_t CudaRuntimeBase::cudaMemset( void* devPtr, int value, 
		size_t count )
	{
		_runtime.lock();
		_runtime.setContext();
	
		reportE( REPORT_MEMORY, "Memsetting " << count 
			<< " bytes on CUDA device to " << value << " at " << devPtr );
		_runtime.context.memset( devPtr, value, count );
	
		_runtime.unlock();
	
		return cudaSuccess;	
	}

	cudaError_t CudaRuntimeBase::cudaMemset2D( void* devPtr, size_t pitch, 
		int value, size_t width, size_t height )
	{
		_runtime.lock();
		_runtime.setContext();
	
		size_t count = width * height;
		reportE( REPORT_MEMORY, "Memsetting " << count 
			<< " bytes on CUDA device to " << value << " at " << devPtr );
		_runtime.context.memset( devPtr, value, count );
	
		_runtime.unlock();
	
		return cudaSuccess;	
	}


	cudaError_t CudaRuntimeBase::cudaGetSymbolAddress( void** devPtr, 
		const char* symbol )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaGetSymbolAddress not implemented." );	
	}

	cudaError_t CudaRuntimeBase::cudaGetSymbolSize( size_t* size, 
		const char* symbol )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaGetSymbolSize not implemented." );	
	}


	cudaError_t CudaRuntimeBase::cudaGetDeviceCount( int* count )
	{
		_runtime.lock();
		_runtime.setContext();
	
		*count = _runtime.context.devices.size();
	
		_runtime.unlock();
	
		report( "There are " << *count << " CUDA devices in the system" );
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaGetDeviceProperties( cudaDeviceProp* prop, 
		int device )
	{
		_runtime.lock();
		_runtime.setContext();
	
		report( "Getting device properties." );
	
		if( ( unsigned int ) device > _runtime.context.devices.size() )
		{
			_runtime.unlock();
	
			return cudaErrorInvalidDevice;
		}
	
		*prop = cuda::CudaRuntime::convert( 
			_runtime.context.devices[ device ] );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaChooseDevice( int* device, 
		const cudaDeviceProp* prop )
	{
		_runtime.lock();
		_runtime.setContext();
	
		*device = _runtime.bestDevice( prop );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaSetDevice( int device )
	{
		_runtime.lock();
		_runtime.setContext();

		report( "Setting CUDA device to " << device );
		cudaError_t result = cudaSuccess;

		try 
		{ 
			_runtime.setDevice( device );	
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidDevice )
			{
				result = cudaErrorInvalidDevice;
			}
			else
			{
				_runtime.unlock();
				throw;
			}
		}
	
		_runtime.unlock();
	
		return result;
	}

	cudaError_t CudaRuntimeBase::cudaGetDevice( int* device )
	{
		_runtime.lock();
		_runtime.setContext();

		*device = _runtime.context.getSelected();
	
		report( "Current CUDA device is " << *device );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaSetValidDevices( int* device_arr, int len )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaSetValidDevices not implemented." );
	}

	cudaError_t CudaRuntimeBase::cudaSetDeviceFlags( int flags )
	{
		_runtime.lock();
		_runtime.setContext();
	
		_runtime.setFlags( flags );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}


	cudaError_t CudaRuntimeBase::cudaBindTexture( size_t* offset, 
		const textureReference* texref, const void* devPtr, 
		const cudaChannelFormatDesc* desc, size_t size )
	{
		_runtime.lock();
		_runtime.setContext();

		report( "Binding texture " << texref << " to " << devPtr );
		cudaError_t result = cudaSuccess;
	
		try 
		{ 
			_runtime.rebind( texref, devPtr, desc, size );
			if( offset != 0 )
			{
				*offset = 0;
			}
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidDevicePointer )
			{
				result = cudaErrorInvalidDevicePointer;
			}
			else if( e.code == cudaErrorInvalidTexture )
			{
				result = cudaErrorInvalidTexture;
			}
			else
			{
				_runtime.unlock();
				throw;
			}
		}
	
		_runtime.unlock();
		
		return result;
	}

	cudaError_t CudaRuntimeBase::cudaBindTexture2D( size_t* offset, 
		const textureReference* texref, const void* devPtr, 
		const cudaChannelFormatDesc* desc, size_t width, 
		size_t height, size_t pitch )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaBindTexture2D not implemented." );
	}

	cudaError_t CudaRuntimeBase::cudaBindTextureToArray( 
		const textureReference* texref, const cudaArray* array, 
		const cudaChannelFormatDesc* desc )
	{
		_runtime.lock();
		_runtime.setContext();

		report( "Binding texture " << texref << " to array " << array );
		cudaError_t result = cudaSuccess;
	
		try 
		{ 
			_runtime.rebind( texref, array, desc );
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidDevicePointer )
			{
				result = cudaErrorInvalidDevicePointer;
			}
			else if( e.code == cudaErrorInvalidTexture )
			{
				result = cudaErrorInvalidTexture;
			}
			else
			{
				_runtime.unlock();
				throw;
			}
		}
	
		_runtime.unlock();
		
		return result;
	}

	cudaError_t CudaRuntimeBase::cudaUnbindTexture( 
		const textureReference* texref )
	{
		_runtime.lock();
		_runtime.setContext();

		report( "Unbinding texture " << texref );
		cudaError_t result = cudaSuccess;
	
		try 
		{ 
			_runtime.unbind( texref );
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidDevicePointer )
			{
				result = cudaErrorInvalidDevicePointer;
			}
			else if( e.code == cudaErrorInvalidTexture )
			{
				result = cudaErrorInvalidTexture;
			}
			else
			{
				_runtime.unlock();
				throw;
			}
		}
	
		_runtime.unlock();
		
		return result;
	}

	cudaError_t CudaRuntimeBase::cudaGetTextureAlignmentOffset( size_t* offset, 
		const textureReference* texref )
	{
		if( offset != 0 )
		{
			*offset = 0;
		}
		return cudaSuccess;	
	}

	cudaError_t CudaRuntimeBase::cudaGetTextureReference( 
		const textureReference** texref, const char* symbol )
	{
		cudaError_t error = cudaSuccess;
	
		try
		{
			_runtime.lock();
			*texref = _runtime.getTexture( symbol );
			_runtime.unlock();
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidTexture )
			{
				_runtime.unlock();
				error = cudaErrorInvalidTexture;
			}
			else
			{
				throw;
			}
		}
		return error;
	}


	cudaError_t CudaRuntimeBase::cudaGetChannelDesc( 
		cudaChannelFormatDesc* desc, const cudaArray* array )
	{
		cudaError_t error = cudaSuccess;
	
		try
		{
			_runtime.lock();
			*desc = _runtime.getChannel( array );
			_runtime.unlock();
		}
		catch( const hydrazine::Exception& e )
		{
			if( e.code == cudaErrorInvalidValue )
			{
				_runtime.unlock();
				error = cudaErrorInvalidValue;
			}
			else
			{
				throw;
			}
		}
		return error;
	}

	cudaChannelFormatDesc CudaRuntimeBase::cudaCreateChannelDesc( 
		int x, int y, int z, int w, cudaChannelFormatKind f )
	{
		cudaChannelFormatDesc format = { x, y, z, w, f };
		return format;
	}


	cudaError_t CudaRuntimeBase::cudaGetLastError( void )
	{
		_runtime.lock();
		cudaError_t error = _runtime.lastError();
		if (error != cudaSuccess) {
			report("\nCUDA ERROR: cudaGetLastError() - " << error << "\n");
		}
		_runtime.unlock();
	
		return error;
	}

	const char* CudaRuntimeBase::cudaGetErrorString( cudaError_t error )
	{
		switch( error )
		{
			case cudaSuccess: return "Success."; break;
			case cudaErrorMissingConfiguration: return "Missing configuration."; 
				break;
			case cudaErrorMemoryAllocation: return "Memory allocation error."; 
				break;
			case cudaErrorInitializationError: return "Initialization error."; 
				break;
			case cudaErrorLaunchFailure: return "Kernel launch failure."; 
				break;
			case cudaErrorPriorLaunchFailure: return "Prior launch failure."; 
				break;
			case cudaErrorLaunchTimeout: return "Kernel launch timed out."; 
				break;
			case cudaErrorLaunchOutOfResources: 
				return "Launch out of resources."; break;
			case cudaErrorInvalidDeviceFunction: 
				return "Invalid device function."; break;
			case cudaErrorInvalidConfiguration: 
				return "Invalid configuration."; break;
			case cudaErrorInvalidDevice: return "Invalid device."; break;
			case cudaErrorInvalidValue: return "Invalid value."; break;
			case cudaErrorInvalidPitchValue: return "Invalid memory pitch."; 
				break;
			case cudaErrorInvalidSymbol: return "Invalid symbol."; break;
			case cudaErrorMapBufferObjectFailed: 
				return "Map buffer object failed."; break;
			case cudaErrorUnmapBufferObjectFailed: 
				return "Unmap buffer object failed."; break;
			case cudaErrorInvalidHostPointer: return "Invalid host pointer."; 
				break;
			case cudaErrorInvalidDevicePointer: 
				return "Invalid device pointer."; break;
			case cudaErrorInvalidTexture: return "Invalid texture."; break;
			case cudaErrorInvalidTextureBinding: 
				return "Invalid texture binding."; break;
			case cudaErrorInvalidChannelDescriptor: 
				return "Invalid channel description."; break;
			case cudaErrorInvalidMemcpyDirection: 
				return "Memory direction invalid."; break;
			case cudaErrorAddressOfConstant: 
				return "Tried to take address of constant."; break;
			case cudaErrorTextureFetchFailed: return "Texture fetch failed."; 
				break;
			case cudaErrorTextureNotBound: return "Texture not bound."; break;
			case cudaErrorSynchronizationError: return "Synchornization error."; 
				break;
			case cudaErrorInvalidFilterSetting: 
				return "Invalid filter setting."; break;
			case cudaErrorInvalidNormSetting: return "Invalid norm setting."; 
				break;
			case cudaErrorMixedDeviceExecution: return "Mixed device execution."; 
				break;
			case cudaErrorCudartUnloading: 
				return "Cuda runtime currently unloading."; break;
			case cudaErrorNotYetImplemented: 
				return "Feature not yet implemented."; break;
			case cudaErrorMemoryValueTooLarge: return "Memory value too large."; 
				break;
			case cudaErrorInvalidResourceHandle: 
				return "Invalid resource handle."; break;
			case cudaErrorNotReady: return "Not ready."; break;
			case cudaErrorStartupFailure: return "Startup failed."; break;
			case cudaErrorApiFailureBase: return "API failure base."; break;
			case cudaErrorSetOnActiveProcess: 
				return "Device already set for this context."; break;
			default: return "Unknown error."; break;
		}
	}


	cudaError_t CudaRuntimeBase::cudaConfigureCall( dim3 gridDim, dim3 blockDim, 
		size_t sharedMem, cudaStream_t stream )
	{
		report( "Configuring call" );
		_runtime.lock();
		_runtime.setContext();
	
		_runtime.configureCall( gridDim, blockDim, sharedMem );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaSetupArgument( const void* arg, 
		size_t size, size_t offset )
	{
		report( "Setting up argument" );
		_runtime.lock();
		_runtime.setContext();
	
		_runtime.setupArgument( arg, size, offset );
	
		_runtime.unlock();
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaLaunch( const char* entry )
	{
		report( "Launching kernel" );
		_runtime.lock();
		_runtime.setContext();
	
		try
		{
			_runtime.launch( entry );
		}
		catch( executive::RuntimeException& e )
		{
			_runtime.unlock();	
			throw e;
		}
		
		_runtime.unlock();	
		return cudaGetLastError();
	}

	cudaError_t CudaRuntimeBase::cudaFuncGetAttributes( 
		cudaFuncAttributes* attr, const char* func )
	{
		_runtime.lock();
		_runtime.setContext();
	
		cudaError_t error = cudaSuccess;
	
		try
		{
			_runtime.getAttributes( attr, func );
			report( "Got attributes (constant " << attr->constSizeBytes 
				<< ")(local" << attr->localSizeBytes << ")(threads " 
				<< attr->maxThreadsPerBlock << ")(regs" << attr->numRegs 
				<< ")(" << attr->sharedSizeBytes << ")" );
		}
		catch( const hydrazine::Exception& e )
		{
			report("CudaRuntimeBase::cudaFuncGetAttributes() - threw an exception that will be rethrown");
			report("  sought attributes for function '" << func << "'");
			if( e.code == cudaErrorInvalidDeviceFunction )
			{
				error = cudaErrorInvalidDeviceFunction;
			}
			else
			{
				_runtime.unlock();
				throw;
			}
		}
	
		_runtime.unlock();
	
		return error;
	}


	cudaError_t CudaRuntimeBase::cudaStreamCreate( cudaStream_t* stream )
	{
		_runtime.lock();

		*stream = _runtime.createStream( );
		report( "Created stream " << *stream );

		_runtime.unlock();	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaStreamDestroy( cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			report( "Destroyed stream " << stream );
			_runtime.destroyStream( stream );
			_runtime.unlock();	
			return cudaSuccess;
		}
		else
		{
			report( "Stream " << stream << " is invalid" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaStreamSynchronize( cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			report( "Stream " << stream << " is synchronized" );
			_runtime.unlock();	
			return cudaSuccess;
		}
		else
		{
			report( "Stream " << stream << " is invalid" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaStreamQuery( cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.streamValid( stream ) )
		{
			report( "Stream " << stream << " is queried" );
			_runtime.unlock();
			return cudaSuccess;
		}
		else
		{
			report( "Stream " << stream << " is invalid" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}


	cudaError_t CudaRuntimeBase::cudaEventCreate( cudaEvent_t* event )
	{
		_runtime.lock();

		*event = _runtime.createEvent( );
		report( "Event " << *event << " created" );

		_runtime.unlock();	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaEventCreateWithFlags( 
		cudaEvent_t* event, int flags )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaEventCreateWithFlags not implemented." );
	}

	cudaError_t CudaRuntimeBase::cudaEventRecord( cudaEvent_t event, 
		cudaStream_t stream )
	{
		_runtime.lock();

		if( _runtime.eventExists( event ) )
		{
			report( "Recorded event " << event << " on stream " << stream );
			_runtime.eventRecord( event, stream );
			_runtime.unlock();	
			return cudaSuccess;
		}
		else
		{
			report( "Event " << event << " invalid" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaEventQuery( cudaEvent_t event )
	{
		_runtime.lock();

		if( _runtime.eventValid( event ) )
		{
			report( "Event " << event << " queried" );
			_runtime.unlock();	
			return cudaSuccess;
		}
		else
		{
			report( "Event " << event << " invalid" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaEventSynchronize( cudaEvent_t event )
	{
		_runtime.lock();

		if( _runtime.eventExists( event ) )
		{
			report( "Event " << event << " synchronized" );
			_runtime.eventSynchronize(event);
			_runtime.unlock();
			return cudaSuccess;
		}
		else
		{
			report( "Event " << event << " invalid" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaEventDestroy( cudaEvent_t event )
	{
		_runtime.lock();

		if( _runtime.eventExists( event ) )
		{
			report( "Event " << event << " destroyed" );
			_runtime.destroyEvent( event );
			_runtime.unlock();	
			return cudaSuccess;
		}
		else
		{
			report( "Event " << event << " invalid" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}

	cudaError_t CudaRuntimeBase::cudaEventElapsedTime( float* ms, 
		cudaEvent_t start, cudaEvent_t end )
	{
		_runtime.lock();

		if( _runtime.eventExists( start ) 
			&& _runtime.eventExists( end ) )
		{
			*ms = _runtime.eventTime( start, end );
			report( "Elapsed time between " << start << " and " << end 
				<< " was " << *ms );
			_runtime.unlock();	
			return cudaSuccess;
		}
		else
		{
			report( "Event " << start << " or " << end << " does not exist" );
			_runtime.unlock();	
			return cudaErrorInvalidResourceHandle;
		}
	}


	cudaError_t CudaRuntimeBase::cudaSetDoubleForDevice( double* d )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaSetDoubleForDevice not implemented." );	
	}

	cudaError_t CudaRuntimeBase::cudaSetDoubleForHost( double* d )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaSetDoubleForHost not implemented." );
	}


	cudaError_t CudaRuntimeBase::cudaThreadExit( void )
	{
		report( "Destroying thread" );
		_runtime.lock();
		_runtime.setContext();
	
		_runtime.destroyContext();
	
		_runtime.unlock();	
	
		return cudaSuccess;	
	}

	cudaError_t CudaRuntimeBase::cudaThreadSynchronize( void )
	{
		bool result = _runtime.threadSynchronize();
		report("cudaThreadSynchronize() - returning " << (result ? "cudaSuccess" : "cudaErrorUnknown"));
		return result ? cudaSuccess : cudaErrorUnknown;	
	}


	cudaError_t CudaRuntimeBase::cudaDriverGetVersion( int* driverVersion )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaDriverGetVersion not implemented" );	
	}

	cudaError_t CudaRuntimeBase::cudaRuntimeGetVersion( int* runtimeVersion )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaRuntimeGetVersion not implemented" );	
	}

	cudaError_t CudaRuntimeBase::cudaGLSetGLDevice( int device )
	{
		report("cudaGLSetGLDevice()");
		cudaError_t result = cudaSetDevice(device);
		if (result == cudaSuccess) {
			_runtime.context.useGLInteroperability();
		}
		return result;
	}

	cudaError_t CudaRuntimeBase::cudaGLRegisterBufferObject( GLuint bufObj )
	{
		report( "Resgistering buffer object " << bufObj );
		_runtime.lock();
		_runtime.setContext();
	
		_runtime.registerOpenGLBuffer( bufObj );
	
		_runtime.unlock();	
	
		return cudaSuccess;
	}

	cudaError_t CudaRuntimeBase::cudaGLMapBufferObject( void **devPtr, 
		GLuint bufObj )
	{
		report( "Mapping buffer object " << bufObj );
		_runtime.lock();
		_runtime.setContext();
	
		cudaError_t result = cudaSuccess;
	
		try
		{
			*devPtr = _runtime.mapOpenGLBuffer( bufObj );
		}
		catch( const hydrazine::Exception& e )
		{	
			if( e.code == cudaErrorMapBufferObjectFailed )
			{
				result = cudaErrorMapBufferObjectFailed;
			}
			else
			{
				throw;
			}	
		}
	
		_runtime.unlock();
	
		report( " Mapped to " << *devPtr );
	
		return result;
	}

	cudaError_t CudaRuntimeBase::cudaGLUnmapBufferObject( GLuint bufObj )
	{
		report( "Unmapping buffer object " << bufObj );
		_runtime.lock();
		_runtime.setContext();
	
		cudaError_t result = cudaSuccess;
	
		try
		{
			_runtime.unmapOpenGLBuffer( bufObj );
		}
		catch( const hydrazine::Exception& e )
		{	
			if( e.code == cudaErrorInvalidDevicePointer )
			{
				result = cudaErrorInvalidDevicePointer;
			}
			else
			{
				throw;
			}	
		}
		 
		_runtime.unlock();	
	
		return result;
	}

	cudaError_t CudaRuntimeBase::cudaGLUnregisterBufferObject( GLuint bufObj )
	{
		report( "Unregistering buffer object " << bufObj );
		_runtime.lock();
		_runtime.setContext();
	
		_runtime.unregisterOpenGLBuffer( bufObj );
	
		_runtime.unlock();	
	
		return cudaSuccess;
	}

	void CudaRuntimeBase::cudaTextureFetch( const void *tex, void *index, 
		int integer, void *val )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaTextureFetch not implemented." );
	}

	void** CudaRuntimeBase::cudaRegisterFatBinary( void* fatCubin )
	{
		__cudaFatCudaBinaryRec* fatbinary = 
			static_cast< __cudaFatCudaBinaryRec* >( fatCubin );

		_runtime.lock();
	
		unsigned int handle = _runtime.registerFatBinary( *fatbinary );
		report( "Registered Fat Binary " << fatbinary->ident 
			<< " to handle " << handle );
		
		_runtime.unlock();
	
		return (void**) handle;
	}

	void CudaRuntimeBase::cudaUnregisterFatBinary( void** fatCubinHandle )
	{
		_runtime.lock();
	
		report( "Unregistering Fat Binary with handle "
			<< ( long long int ) fatCubinHandle );
		_runtime.unregisterFatBinary( ( long long int ) fatCubinHandle );
	
		_runtime.unlock();
	}

	void CudaRuntimeBase::cudaRegisterVar( void** fatCubinHandle, char* hostVar, 
		char* deviceAddress, const char* deviceName, int ext, int size, 
		int constant, int global )
	{
		_runtime.lock();
		_runtime.setContext();
	
		if( !ext ) 
		{
			if( constant ) 
			{
				report( "Registering constant variable " << (void*) hostVar 
					<< " (device " << deviceAddress 
					<< ") (name " << deviceName << ") (size " << size << ")." );
				_runtime.registerGlobal( hostVar, size, deviceName, 
					ir::PTXInstruction::Const, 
					( long long int ) fatCubinHandle );
			}
			else
			{
				report( "Registering global variable " << (void*) hostVar 
					<< " (device " << deviceAddress 
					<< ") (name " << deviceName << ") (size " << size << ")." );
				_runtime.registerGlobal( hostVar, size, deviceName, 
					ir::PTXInstruction::Global, 
					( long long int ) fatCubinHandle );
			}
		}

		_runtime.unlock();
	}

	void CudaRuntimeBase::cudaRegisterTexture( void** fatCubinHandle, 
		const struct textureReference* hostVar, const void** deviceAddress, 
		const char* deviceName, int dim, int norm, int ext )
	{
		_runtime.lock();
		_runtime.setContext();
				
		if( !ext )
		{
			report( "Registering texture variable " << (void*) hostVar 
				<< " (device " << deviceAddress 
				<< ") (name " << deviceName << ") (dimensions " << dim << ")" 
				<< "(normalized " << norm << ")." );
			_runtime.registerTexture( hostVar, dim, deviceName,
				( long long int ) fatCubinHandle, norm );
		}

		_runtime.unlock();
	}

	void CudaRuntimeBase::cudaRegisterShared( void** fatCubinHandle, 
		void** devicePtr )
	{
		_runtime.lock();
		_runtime.setContext();
	
		report( "Registering shared variable " << (void**) devicePtr 
			<< " ( device 0x0) ( name " << (const char*)devicePtr << " )." );
			
		_runtime.registerGlobal( devicePtr, 0, (const char*)devicePtr, 
			ir::PTXInstruction::Shared, ( long long int ) fatCubinHandle );

		_runtime.unlock();
	}

	void CudaRuntimeBase::cudaRegisterSharedVar( void** fatCubinHandle, 
		void** devicePtr, size_t size, size_t alignment, int storage )
	{
		_runtime.lock();
		_runtime.setContext();
	
		report( "Registering shared variable " << (void**) devicePtr 
			<< " ( device 0x0) ( name " << (const char*)devicePtr << " )." );
			
		_runtime.registerGlobal( devicePtr, size, (const char*)devicePtr, 
			ir::PTXInstruction::Shared, ( long long int ) fatCubinHandle );

		_runtime.unlock();
	}

	void CudaRuntimeBase::cudaRegisterFunction( void** fatCubinHandle, 
		const char* hostFun, char* deviceFun, const char* deviceName, 
		int thread_limit, uint3* tid, uint3* bid, dim3* bDim, dim3* gDim, 
		int* wSize )
	{
		report( "Called cuda register function with handle " 
			<< ( (long long int) fatCubinHandle ) << " for device function " 
			<< deviceFun  );
		
		_runtime.lock();
		_runtime.setContext();
	
		_runtime.registerFunction( hostFun, deviceFun, 
			( (long long int) fatCubinHandle ) );
	
		_runtime.unlock();	
	}

	void CudaRuntimeBase::cudaMutexOperation( int lock )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaMutexOperation not implemented." );
	}

	int CudaRuntimeBase::cudaSynchronizeThreads( void**, void* )
	{
		throw hydrazine::Exception( 
			"CudaRuntimeBase::cudaSynchronizeThreads not implemented." );
	}

	void CudaRuntimeBase::addTraceGenerator( 
		trace::TraceGenerator& gen, bool persistent, bool safe )
	{
		if( safe )
		{
			_runtime.lock();
			_runtime.setContext();		
			_runtime.addTraceGenerator( gen, persistent );
			_runtime.unlock();
		}
		else
		{
			_runtime.addTraceGenerator( gen, persistent );
		}	
	}
	
	void CudaRuntimeBase::clearTraceGenerators( bool safe )
	{
		if( safe )
		{
			_runtime.lock();
			_runtime.setContext();		
			_runtime.clearTraceGenerators();		
			_runtime.unlock();
		}
		else
		{
			_runtime.clearTraceGenerators();
		}	
	}

	void CudaRuntimeBase::limitWorkerThreads( unsigned int limit )
	{
		_runtime.context.limitWorkerThreads( limit );
	}
	
	void CudaRuntimeBase::registerPTXModule(std::istream& stream, 
		const std::string& name)
	{
		std::string module;
		unsigned int length = 0;
		
		stream.seekg( 0, std::ios::end );
		length = stream.tellg();
		stream.seekg( 0, std::ios::beg );
		
		module.resize( length );
		stream.read( const_cast< char* >( module.c_str() ), length );
		
		__cudaFatCudaBinaryRec fatbin;
		__cudaFatPtxEntry ptx;
		
		ptx.ptx = const_cast< char* >( module.c_str() );
		
		fatbin.ident = const_cast< char* >( name.c_str() );
		fatbin.ptx = &ptx;
		
		unsigned int handle = _runtime.registerFatBinary( fatbin );
		
		executive::Executive::ModuleMap::iterator 
			mi = _runtime.context.modules.find(name);
		assert( mi != _runtime.context.modules.end() );
			
		ir::Module::KernelArchitectureMap::iterator kernels = mi->second->kernels.find( 
			ir::Instruction::PTX );
		assert( kernels != mi->second->kernels.end() );
		
		for( ir::Module::KernelMap::iterator 
			kernel = kernels->second.begin(); 
			kernel != kernels->second.end(); ++kernel )
		{
			std::hash<std::string> hash;
			_runtime.registerFunction( reinterpret_cast<const char*>( 
				hash( (kernel->second)->name ) ), (kernel->second)->name, handle );
		}		
	}
		
	const char* CudaRuntimeBase::getKernelPointer(const std::string& name, 
		const std::string& module)
	{
		executive::Executive::ModuleMap::iterator 
			mi = _runtime.context.modules.find(module);
		assert( mi != _runtime.context.modules.end() );
			
		ir::Module::KernelArchitectureMap::iterator kernels = mi->second->kernels.find( 
			ir::Instruction::PTX );
		assert( kernels != mi->second->kernels.end() );
		
		for( ir::Module::KernelMap::iterator 
			kernel = kernels->second.begin(); 
			kernel != kernels->second.end(); ++kernel )
		{
			if( (kernel->second)->name == name )
			{
				std::hash<std::string> hash;
				return reinterpret_cast<const char*>( hash( (kernel->second)->name ) );
			}
		}
		
		throw hydrazine::Exception( "Could not find kernel " + name 
			+ " in module " + module );		
	}
	
	void** CudaRuntimeBase::getFatBinaryHandle(const std::string& name)
	{
		unsigned int handle = _runtime.getFatBinaryHandle( name );
		return (void**) handle;
	}
	
	void CudaRuntimeBase::clearErrors()
	{
		_runtime.lock();
		_runtime.setContext();
		_runtime.clearErrors();
		_runtime.unlock();
	}
	
	executive::Executive& CudaRuntimeBase::executive()
	{
		return _runtime.context;
	}
}

#endif

