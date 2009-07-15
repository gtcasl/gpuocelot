/*!

	\file OcelotRuntimeApi.cpp
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday March 10, 2009

	\brief The source file for the Ocelot implementation of the CUDA runtime
		API 2.1

*/

#ifndef OCELOT_RUNTIME_API_CPP_INCLUDED
#define OCELOT_RUNTIME_API_CPP_INCLUDED

#include <hydrazine/implementation/Exception.h>
#include <ocelot/cuda/interface/CudaRuntime.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_MEMORY 1

namespace cuda
{
	CudaRuntime runtime;
}

cudaError_t CUDARTAPI cudaMalloc3D(struct cudaPitchedPtr* pitchDevPtr, 
	struct cudaExtent extent)
{
	pitchDevPtr->pitch = 0;
	pitchDevPtr->xsize = extent.width;
	pitchDevPtr->ysize = extent.height;
	return cudaMalloc( &pitchDevPtr->ptr, 
		extent.width * extent.height * extent.depth );
}

cudaError_t CUDARTAPI cudaMalloc3DArray(struct cudaArray** arrayPtr, 
	const struct cudaChannelFormatDesc* desc, struct cudaExtent extent)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	*arrayPtr = cuda::runtime.allocateArray( *desc, extent.width, 
		extent.height, extent.depth );
	
	reportE( REPORT_MEMORY, "Allocated device 3D array width " << extent.width 
		<< " height " << extent.height << " length " << extent.depth 
		<<  " to pointer " << *arrayPtr << "." );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaMemset3D(struct cudaPitchedPtr pitchDevPtr, 
	int value, struct cudaExtent extent)
{
	return cudaMemset( pitchDevPtr.ptr, value, 
		extent.height * extent.depth * extent.width );
}

cudaError_t CUDARTAPI cudaMemcpy3D(const struct cudaMemcpy3DParms *p)
{
	if(p->srcArray != 0)
	{	
		if(p->dstArray != 0)
		{
			return cudaMemcpyArrayToArray(p->dstArray, p->dstPos.x, p->dstPos.y, 
				p->srcArray, p->srcPos.x, p->srcPos.y, 
				p->extent.width * p->extent.height * p->extent.depth, p->kind );
		}
		else
		{
			unsigned int doffset = p->dstPos.x + p->dstPos.y * p->dstPtr.xsize 
			+ p->dstPos.y * p->dstPtr.xsize * p->dstPtr.ysize;
			return cudaMemcpyFromArray((char*)p->dstPtr.ptr + doffset, 
				p->srcArray, p->srcPos.x, p->srcPos.y, 
				p->extent.width * p->extent.height * p->extent.depth, p->kind );
		}
	}
	else
	{
		if(p->dstPtr.ptr != 0)
		{
			unsigned int soffset = p->srcPos.x + p->srcPos.y * p->srcPtr.xsize 
				+ p->srcPos.y * p->srcPtr.xsize * p->srcPtr.ysize;
			unsigned int doffset = p->dstPos.x + p->dstPos.y * p->dstPtr.xsize 
				+ p->dstPos.y * p->dstPtr.xsize * p->dstPtr.ysize;
			return cudaMemcpy((char*)p->dstPtr.ptr + doffset, 
				(char*)p->srcPtr.ptr + soffset, 
				p->extent.width * p->extent.height * p->extent.depth, p->kind);
		}
		else
		{
			assert(p->dstArray != 0);
			unsigned int soffset = p->srcPos.x + p->srcPos.y * p->srcPtr.xsize 
				+ p->srcPos.y * p->srcPtr.xsize * p->srcPtr.ysize;
			return cudaMemcpyToArray(p->dstArray, p->dstPos.x, p->dstPos.y, 
				(char*)p->srcPtr.ptr + soffset, 
				p->extent.width * p->extent.height * p->extent.depth, p->kind);			
		}
	}
	
}

cudaError_t CUDARTAPI cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, 
	cudaStream_t stream)
{
	if(!cuda::runtime.streamValid(stream))
	{
		return cudaErrorInvalidResourceHandle;	
	}

	return cudaMemcpy3D(p);
}


cudaError_t CUDARTAPI cudaMalloc(void **devPtr, size_t size)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	*devPtr = cuda::runtime.context.malloc( size );
	
	reportE( REPORT_MEMORY, "Allocated " << size 
		<< " bytes on CUDA device to pointer " << *devPtr << "." );
		
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaMallocHost(void **ptr, size_t size)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	*ptr = cuda::runtime.allocate( size );
	
	reportE( REPORT_MEMORY, "Allocated " << size 
		<< " bytes on HOST pinned memory to pointer " << *ptr << "." );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaMallocPitch(void **devPtr, size_t *pitch, 
	size_t width, size_t height)
{
	*pitch = width;
	return cudaMalloc( devPtr, width * height);
}

cudaError_t CUDARTAPI cudaMallocArray(struct cudaArray **array, 
	const struct cudaChannelFormatDesc *desc, size_t width, size_t height )
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	*array = cuda::runtime.allocateArray( *desc, width, height );
	
	reportE( REPORT_MEMORY, "Allocated device 2D array width " << width 
		<< " height " << height << " to pointer " << *array << "." );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaFree(void *devPtr)
{
	if( devPtr == 0 ) 
	{
		return cudaSuccess;
	}

	cuda::runtime.lock();
	cuda::runtime.setContext();

	reportE( REPORT_MEMORY, "Freeing memory " << devPtr << " on CUDA device." );
	
	cuda::runtime.context.free( devPtr );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaFreeHost(void *ptr)
{
	if( ptr == 0 ) 
	{
		return cudaSuccess;
	}

	cuda::runtime.lock();
	cuda::runtime.setContext();

	reportE( REPORT_MEMORY, "Freeing HOST pinned memory " << ptr << "." );
	
	cuda::runtime.free( ptr );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaFreeArray(struct cudaArray *array)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();

	reportE( REPORT_MEMORY, "Freeing device array " << array << "." );
	
	cuda::runtime.freeArray( array );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaHostAlloc(void **pHost, size_t bytes, 
	unsigned int flags)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	*pHost = cuda::runtime.allocate( bytes, flags & cudaHostAllocPortable, 
		flags & cudaHostAllocMapped );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;

}

cudaError_t CUDARTAPI cudaHostGetDevicePointer(void **pDevice, void *pHost, 
	unsigned int flags)
{
	if( flags != 0 )
	{
		return cudaErrorInvalidValue;
	}

	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	try
	{
		*pDevice = cuda::runtime.lookupMappedMemory( pHost );
	}
	catch( hydrazine::Exception& e )
	{
		cuda::runtime.unlock();
		if( e.code == cudaErrorInvalidValue )
		{
			return cudaErrorInvalidValue;
		}
		else
		{
			throw;
		}
	}
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaMemcpy(void *dst, const void *src, 
	size_t count, enum cudaMemcpyKind kind)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	switch( kind )
	{
		case cudaMemcpyHostToHost:
		{
			reportE( REPORT_MEMORY, "Copying " << count << " bytes from host " 
				<< src << " to host " << dst );
			cuda::runtime.context.memcpy( dst, src, count, 
				executive::Executive::HostToHost );
			break;
		}

		case cudaMemcpyHostToDevice:
		{
			reportE( REPORT_MEMORY, "Copying " << count << " bytes from host " 
				<< src << " to device " << dst );
			cuda::runtime.context.memcpy( dst, src, count, 
				executive::Executive::HostToDevice );
			break;
		}

		case cudaMemcpyDeviceToHost:
		{
			reportE( REPORT_MEMORY,"Copying " << count << " bytes from device " 
				<< src << " to host " << dst );
			cuda::runtime.context.memcpy( dst, src, count, 
				executive::Executive::DeviceToHost );
			break;
		}

		case cudaMemcpyDeviceToDevice:
		{
			reportE( REPORT_MEMORY, "Copying " << count 
				<< " bytes from device " << src << " to device " << dst );
			cuda::runtime.context.memcpy( dst, src, count, 
				executive::Executive::DeviceToDevice );
			break;
		}
	}
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, 
	size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind)
{
	cudaError_t error = cudaSuccess;
	
	try
	{
		cuda::runtime.lock();
		unsigned int offset = cuda::runtime.offset( dst, wOffset, hOffset );
		cuda::runtime.unlock();
		cudaMemcpy( (char*)dst + offset, src, count, kind );
	}
	catch( const hydrazine::Exception& e )
	{
		if( e.code == cudaErrorInvalidValue )
		{
			cuda::runtime.unlock();
			error = cudaErrorInvalidValue;
		}
		else
		{
			throw;
		}
	}
	return error;
}

cudaError_t CUDARTAPI cudaMemcpyFromArray(void *dst, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, 
	enum cudaMemcpyKind kind)
{
	cudaError_t error = cudaSuccess;
	
	try
	{
		cuda::runtime.lock();
		unsigned int offset = cuda::runtime.offset( src, wOffset, hOffset );
		cuda::runtime.unlock();
		cudaMemcpy( dst, (char*)src + offset, count, kind );
	}
	catch( const hydrazine::Exception& e )
	{
		if( e.code == cudaErrorInvalidValue )
		{
			cuda::runtime.unlock();
			error = cudaErrorInvalidValue;
		}
		else
		{
			throw;
		}
	}
	return error;
}

cudaError_t CUDARTAPI cudaMemcpyArrayToArray(struct cudaArray *dst, 
	size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, 
	size_t wOffsetSrc, size_t hOffsetSrc, size_t count, 
	enum cudaMemcpyKind kind )
{
	cudaError_t error = cudaSuccess;
	
	try
	{
		cuda::runtime.lock();
		unsigned int sourceOffset = cuda::runtime.offset( src, wOffsetDst, 
			hOffsetDst );
		unsigned int destinationOffset = cuda::runtime.offset( dst, wOffsetSrc, 
			hOffsetSrc );
		cuda::runtime.unlock();
		cudaMemcpy( (char*)dst + sourceOffset, (char*)src + destinationOffset, 
			count, kind );
	}
	catch( const hydrazine::Exception& e )
	{
		if( e.code == cudaErrorInvalidValue )
		{
			cuda::runtime.unlock();
			error = cudaErrorInvalidValue;
		}
		else
		{
			throw;
		}
	}
	return error;
}

cudaError_t CUDARTAPI cudaMemcpy2D(void *dst, size_t dpitch, const void *src, 
	size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind)
{
	return cudaMemcpy( dst, src, width * height, kind );
}

cudaError_t CUDARTAPI cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset,
	size_t hOffset, const void *src, size_t spitch, size_t width, size_t height,
	enum cudaMemcpyKind kind)
{
	return cudaMemcpyToArray( dst, wOffset, hOffset, src, 
		width * height, kind );
}

cudaError_t CUDARTAPI cudaMemcpy2DFromArray(void *dst, size_t dpitch, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, 
	size_t height, enum cudaMemcpyKind kind)
{
	return cudaMemcpyFromArray( dst, src, wOffset, hOffset, 
		width*height, kind );
}

cudaError_t CUDARTAPI cudaMemcpy2DArrayToArray(struct cudaArray *dst, 
	size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, 
	size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, 
	enum cudaMemcpyKind kind )
{
	return cudaMemcpyArrayToArray( dst, wOffsetDst, hOffsetDst, src, 
		wOffsetSrc, hOffsetSrc, width * height, kind );
}

cudaError_t CUDARTAPI cudaMemcpyToSymbol(const char *symbol, const void *src, 
	size_t count, size_t offset, enum cudaMemcpyKind kind )
{
	try
	{
		return cudaMemcpy( (char*)cuda::runtime.getSymbol( symbol ) + offset, 
			src, count, kind );
	}
	catch( const hydrazine::Exception& e )
	{
		if(e.code == cudaErrorInvalidSymbol)
		{
			if( cuda::runtime.isGlobal( symbol ) )
			{
				return cudaMemcpy( (char*)symbol + offset, src, count, kind );
			}			
			return cudaErrorInvalidSymbol;
		}
		else
		{
			throw;
		}
	}
}

cudaError_t CUDARTAPI cudaMemcpyFromSymbol(void *dst, const char *symbol, 
	size_t count, size_t offset, enum cudaMemcpyKind kind )
{
	try
	{
		return cudaMemcpy( dst, 
			(char*)cuda::runtime.getSymbol( symbol ) + offset, count, kind );
	}
	catch( const hydrazine::Exception& e )
	{
		if(e.code == cudaErrorInvalidSymbol)
		{			
			if( cuda::runtime.isGlobal( symbol ) )
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
}


cudaError_t CUDARTAPI cudaMemcpyAsync(void *dst, const void *src, size_t count, 
	enum cudaMemcpyKind kind, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpy( dst, src, count, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemcpyToArrayAsync(struct cudaArray *dst, 
	size_t wOffset, size_t hOffset, const void *src, size_t count, 
	enum cudaMemcpyKind kind, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpyToArray( dst, wOffset, hOffset, src, count, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemcpyFromArrayAsync(void *dst, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, 
	enum cudaMemcpyKind kind, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpyFromArray( dst, src, wOffset, hOffset, count, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemcpy2DAsync(void *dst, size_t dpitch, 
	const void *src, size_t spitch, size_t width, size_t height, 
	enum cudaMemcpyKind kind, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpy2D( dst, dpitch, src, spitch, width, height, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemcpy2DToArrayAsync(struct cudaArray *dst, 
	size_t wOffset, size_t hOffset, const void *src, size_t spitch, 
	size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpy2DToArray( dst, wOffset, hOffset, src, spitch, width, 
			height, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, 
	size_t height, enum cudaMemcpyKind kind, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpy2DFromArray( dst, dpitch, src, wOffset, hOffset, 
			width, height, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemcpyToSymbolAsync(const char *symbol, 
	const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, 
	cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpyToSymbol( symbol, src, count, offset, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemcpyFromSymbolAsync(void *dst, const char *symbol, 
	size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		cuda::runtime.unlock();	
		return cudaMemcpyFromSymbol( dst, symbol, count, offset, kind );
	}
	else
	{
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaMemset(void *mem, int c, size_t count)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	reportE( REPORT_MEMORY, "Memsetting " << count 
		<< " bytes on CUDA device to " << c << " at " << mem );
	cuda::runtime.context.memset( mem, c, count );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaMemset2D(void *mem, size_t pitch, int c, 
	size_t width, size_t height)
{
	throw hydrazine::Exception( "cudaMemset2D not implemented." );
}

cudaError_t CUDARTAPI cudaGetSymbolAddress(void **devPtr, const char *symbol)
{
	throw hydrazine::Exception( "cudaGetSymbolAddress not implemented." );
}

cudaError_t CUDARTAPI cudaGetSymbolSize(size_t *size, const char *symbol)
{
	throw hydrazine::Exception( "cudaGetSymbolSize not implemented." );
}


cudaError_t CUDARTAPI cudaGetDeviceCount(int *count)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	*count = cuda::runtime.context.devices.size();
	
	cuda::runtime.unlock();
	
	report( "There are " << *count << " CUDA devices in the system" );
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaGetDeviceProperties(struct cudaDeviceProp *prop, 
	int device)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	report( "Getting device properties." );
	
	if( ( unsigned int ) device > cuda::runtime.context.devices.size() )
	{
		cuda::runtime.unlock();
	
		return cudaErrorInvalidDevice;
	}
	
	*prop = cuda::CudaRuntime::convert( cuda::runtime.context.devices[0] );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaChooseDevice(int *device, 
	const struct cudaDeviceProp *prop)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	*device = cuda::runtime.bestDevice( prop );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaSetDevice(int device)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();

	report( "Setting CUDA device to " << device );
	cudaError_t result = cudaSuccess;

	try 
	{ 
		cuda::runtime.setDevice( device );	
	}
	catch( const hydrazine::Exception& e )
	{
		if( e.code == cudaErrorInvalidDevice )
		{
			result = cudaErrorInvalidDevice;
		}
		else
		{
			cuda::runtime.unlock();
			throw;
		}
	}
	
	cuda::runtime.unlock();
	
	return result;
}

cudaError_t CUDARTAPI cudaGetDevice(int *device)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();

	*device = cuda::runtime.context.getSelected();
	
	report( "Current CUDA device is " << *device );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaSetValidDevices(int *device_arr, int len)
{
	throw hydrazine::Exception( "cudaSetValidDevices not implemented." );
}

cudaError_t CUDARTAPI cudaSetDeviceFlags( int flags )
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cuda::runtime.setFlags( flags );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaBindTexture(size_t *offset, 
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t size )
{
	cuda::runtime.lock();
	cuda::runtime.setContext();

	report( "Binding texture " << texref << " to " << devPtr );
	cudaError_t result = cudaSuccess;
	
	try 
	{ 
		cuda::runtime.rebind( texref, devPtr, desc, size );
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
			cuda::runtime.unlock();
			throw;
		}
	}
	
	cuda::runtime.unlock();
		
	return result;
}

cudaError_t CUDARTAPI cudaBindTextureToArray(
	const struct textureReference *texref, const struct cudaArray *array, 
	const struct cudaChannelFormatDesc *desc)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();

	report( "Binding texture " << texref << " to array " << array );
	cudaError_t result = cudaSuccess;
	
	try 
	{ 
		cuda::runtime.rebind( texref, array, desc );
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
			cuda::runtime.unlock();
			throw;
		}
	}
	
	cuda::runtime.unlock();
		
	return result;
}

cudaError_t CUDARTAPI cudaUnbindTexture(const struct textureReference *texref)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();

	report( "Unbinding texture " << texref );
	cudaError_t result = cudaSuccess;
	
	try 
	{ 
		cuda::runtime.unbind( texref );
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
			cuda::runtime.unlock();
			throw;
		}
	}
	
	cuda::runtime.unlock();
		
	return result;
}

cudaError_t CUDARTAPI cudaGetTextureAlignmentOffset(size_t *offset, 
	const struct textureReference *texref)
{
	if( offset != 0 )
	{
		*offset = 0;
	}
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaGetTextureReference(
	const struct textureReference **texref, const char *symbol)
{
	cudaError_t error = cudaSuccess;
	
	try
	{
		cuda::runtime.lock();
		*texref = cuda::runtime.getTexture( symbol );
		cuda::runtime.unlock();
	}
	catch( const hydrazine::Exception& e )
	{
		if( e.code == cudaErrorInvalidTexture )
		{
			cuda::runtime.unlock();
			error = cudaErrorInvalidTexture;
		}
		else
		{
			throw;
		}
	}
	return error;
}

cudaError_t CUDARTAPI cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, 
	const struct cudaArray *array)
{
	cudaError_t error = cudaSuccess;
	
	try
	{
		cuda::runtime.lock();
		*desc = cuda::runtime.getChannel( array );
		cuda::runtime.unlock();
	}
	catch( const hydrazine::Exception& e )
	{
		if( e.code == cudaErrorInvalidValue )
		{
			cuda::runtime.unlock();
			error = cudaErrorInvalidValue;
		}
		else
		{
			throw;
		}
	}
	return error;
}

struct cudaChannelFormatDesc CUDARTAPI cudaCreateChannelDesc(int x, int y, 
	int z, int w, enum cudaChannelFormatKind f)
{
	cudaChannelFormatDesc format = { x, y, z, w, f };
	return format;
}

cudaError_t CUDARTAPI cudaGetLastError(void)
{
	cuda::runtime.lock();
	cudaError_t error = cuda::runtime.lastError();
	cuda::runtime.unlock();
	
	return error;
}

const char* CUDARTAPI cudaGetErrorString(cudaError_t error)
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
		case cudaErrorLaunchFailure: return "Kernel launch failure."; break;
		case cudaErrorPriorLaunchFailure: return "Prior launch failure."; break;
		case cudaErrorLaunchTimeout: return "Kernel launch timed out."; break;
		case cudaErrorLaunchOutOfResources: return "Launch out of resources."; 
			break;
		case cudaErrorInvalidDeviceFunction: return "Invalid device function."; 
			break;
		case cudaErrorInvalidConfiguration: return "Invalid configuration."; 
			break;
		case cudaErrorInvalidDevice: return "Invalid device."; break;
		case cudaErrorInvalidValue: return "Invalid value."; break;
		case cudaErrorInvalidPitchValue: return "Invalid memory pitch."; break;
		case cudaErrorInvalidSymbol: return "Invalid symbol."; break;
		case cudaErrorMapBufferObjectFailed: 
			return "Map buffer object failed."; break;
		case cudaErrorUnmapBufferObjectFailed: 
			return "Unmap buffer object failed."; break;
		case cudaErrorInvalidHostPointer: return "Invalid host pointer."; break;
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
		case cudaErrorTextureFetchFailed: return "Texture fetch failed."; break;
		case cudaErrorTextureNotBound: return "Texture not bound."; break;
		case cudaErrorSynchronizationError: return "Synchornization error."; 
			break;
		case cudaErrorInvalidFilterSetting: return "Invalid filter setting."; 
			break;
		case cudaErrorInvalidNormSetting: return "Invalid norm setting."; break;
		case cudaErrorMixedDeviceExecution: return "Mixed device execution."; 
			break;
		case cudaErrorCudartUnloading: 
			return "Cuda runtime currently unloading."; break;
		case cudaErrorNotYetImplemented: 
			return "Feature not yet implemented."; break;
		case cudaErrorMemoryValueTooLarge: return "Memory value too large."; 
			break;
		case cudaErrorInvalidResourceHandle: return "Invalid resource handle."; 
			break;
		case cudaErrorNotReady: return "Not ready."; break;
		case cudaErrorStartupFailure: return "Startup failed."; break;
		case cudaErrorApiFailureBase: return "API failure base."; break;
		case cudaErrorSetOnActiveProcess: 
			return "Device already set for this context."; break;
		default: return "Unknown error."; break;
	}
}

cudaError_t CUDARTAPI cudaConfigureCall(dim3 gridDim, dim3 blockDim, 
	size_t sharedMem, cudaStream_t stream )
{
	report( "Configuring call" );
	cuda::runtime.lock();

	cuda::runtime.configureCall( gridDim, blockDim, sharedMem );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaSetupArgument(const void *arg, size_t size, 
	size_t offset)
{
	report( "Setting up argument" );
	cuda::runtime.lock();

	cuda::runtime.setupArgument( arg, size, offset );
	
	cuda::runtime.unlock();
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaLaunch(const char *symbol)
{
	report( "Launching kernel" );
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cuda::runtime.launch( symbol );
	
	cuda::runtime.unlock();	
	
	return cudaGetLastError();
}

cudaError_t CUDARTAPI cudaFuncGetAttributes(struct cudaFuncAttributes *attr, 
	const char *func)
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cudaError_t error = cudaSuccess;
	
	try
	{
		cuda::runtime.getAttributes( attr, func );
		report( "Got attributes (constant " << attr->constSizeBytes 
			<< ")(local" << attr->localSizeBytes << ")(threads " 
			<< attr->maxThreadsPerBlock << ")(regs" << attr->numRegs 
			<< ")(" << attr->sharedSizeBytes << ")" );
	}
	catch( const hydrazine::Exception& e )
	{
		if( e.code == cudaErrorInvalidDeviceFunction )
		{
			error = cudaErrorInvalidDeviceFunction;
		}
		else
		{
			cuda::runtime.unlock();
			throw;
		}
	}
	
	cuda::runtime.unlock();
	
	return error;
}

cudaError_t CUDARTAPI cudaStreamCreate(cudaStream_t *stream)
{
	cuda::runtime.lock();

	*stream = cuda::runtime.createStream( );
	report( "Created stream " << *stream );

	cuda::runtime.unlock();	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaStreamDestroy(cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		report( "Destroyed stream " << stream );
		cuda::runtime.destroyStream( stream );
		cuda::runtime.unlock();	
		return cudaSuccess;
	}
	else
	{
		report( "Stream " << stream << " is invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaStreamSynchronize(cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		report( "Stream " << stream << " is synchronized" );
		cuda::runtime.unlock();	
		return cudaSuccess;
	}
	else
	{
		report( "Stream " << stream << " is invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaStreamQuery(cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.streamValid( stream ) )
	{
		report( "Stream " << stream << " is queried" );
		cuda::runtime.unlock();
		return cudaSuccess;
	}
	else
	{
		report( "Stream " << stream << " is invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}


cudaError_t CUDARTAPI cudaEventCreate(cudaEvent_t *event)
{
	cuda::runtime.lock();

	*event = cuda::runtime.createEvent( );
	report( "Event " << *event << " created" );

	cuda::runtime.unlock();	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaEventRecord(cudaEvent_t event, cudaStream_t stream)
{
	cuda::runtime.lock();

	if( cuda::runtime.eventValid( event ) )
	{
		report( "Recorded event " << event << " on stream " << stream );
		cuda::runtime.eventRecord( event, stream );
		cuda::runtime.unlock();	
		return cudaSuccess;
	}
	else
	{
		report( "Event " << event << " invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaEventQuery(cudaEvent_t event)
{
	cuda::runtime.lock();

	if( cuda::runtime.eventValid( event ) )
	{
		report( "Event " << event << " queried" );
		cuda::runtime.unlock();	
		return cudaSuccess;
	}
	else
	{
		report( "Event " << event << " invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaEventSynchronize(cudaEvent_t event)
{
	cuda::runtime.lock();

	if( cuda::runtime.eventValid( event ) )
	{
		report( "Event " << event << " synchronized" );
		cuda::runtime.unlock();	
		return cudaSuccess;
	}
	else
	{
		report( "Event " << event << " invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaEventDestroy(cudaEvent_t event)
{
	cuda::runtime.lock();

	if( cuda::runtime.eventValid( event ) )
	{
		report( "Event " << event << " destroyed" );
		cuda::runtime.destroyEvent( event );
		cuda::runtime.unlock();	
		return cudaSuccess;
	}
	else
	{
		report( "Event " << event << " invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}

cudaError_t CUDARTAPI cudaEventElapsedTime(float *ms, cudaEvent_t start, 
	cudaEvent_t end)
{
	cuda::runtime.lock();

	if( cuda::runtime.eventValid( start ) && cuda::runtime.eventValid( end ) )
	{
		*ms = cuda::runtime.eventTime( start, end );
		report( "Elapsed time between " << start << " and " << end 
			<< " was " << *ms );
		cuda::runtime.unlock();	
		return cudaSuccess;
	}
	else
	{
		report( "Event " << start << " or " << end << " invalid" );
		cuda::runtime.unlock();	
		return cudaErrorInvalidResourceHandle;
	}
}


cudaError_t CUDARTAPI cudaSetDoubleForDevice(double *d)
{
	throw hydrazine::Exception( "cudaSetDoubleForDevice not implemented." );
}

cudaError_t CUDARTAPI cudaSetDoubleForHost(double *d)
{
	throw hydrazine::Exception( "cudaSetDoubleForHost not implemented." );
}

cudaError_t CUDARTAPI cudaThreadExit(void)
{
	report( "Destroying thread" );
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cuda::runtime.destroyContext();
	
	cuda::runtime.unlock();	
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaThreadSynchronize(void)
{
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaDriverGetVersion(int *driverVersion)
{
	throw hydrazine::Exception( "cudaDriverGetVersion not implemented" );
}

cudaError_t CUDARTAPI cudaRuntimeGetVersion(int *runtimeVersion)
{
	throw hydrazine::Exception( "cudaRuntimeGetVersion not implemented" );
}

extern "C"
{
typedef unsigned int GLuint;

cudaError_t CUDARTAPI cudaGLSetGLDevice(int device)
{
	return cudaSetDevice( device );
}

cudaError_t CUDARTAPI cudaGLRegisterBufferObject(GLuint bufObj)
{
	report( "Resgistering buffer object " << bufObj );
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cuda::runtime.registerOpenGLBuffer( bufObj );
	
	cuda::runtime.unlock();	
	
	return cudaSuccess;
}

cudaError_t CUDARTAPI cudaGLMapBufferObject(void **devPtr, GLuint bufObj)
{
	report( "Mapping buffer object " << bufObj );
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cudaError_t result = cudaSuccess;
	
	try
	{
		*devPtr = cuda::runtime.mapOpenGLBuffer( bufObj );
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
	
	cuda::runtime.unlock();
	
	report( " Mapped to " << *devPtr );
	
	return result;
	
}

cudaError_t CUDARTAPI cudaGLUnmapBufferObject(GLuint bufObj)
{
	report( "Unmapping buffer object " << bufObj );
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cudaError_t result = cudaSuccess;
	
	try
	{
		cuda::runtime.unmapOpenGLBuffer( bufObj );
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
	 
	cuda::runtime.unlock();	
	
	return result;
}

cudaError_t CUDARTAPI cudaGLUnregisterBufferObject(GLuint bufObj)
{
	report( "Unregistering buffer object " << bufObj );
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cuda::runtime.unregisterOpenGLBuffer( bufObj );
	
	cuda::runtime.unlock();	
	
	return cudaSuccess;
}
}

extern "C"
{
void __cudaTextureFetch(const void *tex, void *index, int integer, void *val)
{
	throw hydrazine::Exception( "__cudaTextureFetch not implemented." );
}

void** __cudaRegisterFatBinary( void *fatCubin )
{
	__cudaFatCudaBinaryRec* fatbinary = 
		static_cast< __cudaFatCudaBinaryRec* >( fatCubin );

	cuda::runtime.lock();
	
	unsigned int handle = cuda::runtime.registerFatBinary( *fatbinary );
	report( "Registered Fat Binary " << fatbinary->ident 
		<< " to handle " << handle );
		
	cuda::runtime.unlock();
	
	return (void**) handle;
}

void __cudaUnregisterFatBinary( void **fatCubinHandle )
{
	cuda::runtime.lock();
	
	report( "Unregistering Fat Binary with handle "
		<< ( long long int ) fatCubinHandle );
	cuda::runtime.unregisterFatBinary( ( long long int ) fatCubinHandle );
	
	cuda::runtime.unlock();
}

void __cudaRegisterVar( void **fatCubinHandle, char *hostVar, 
	char *deviceAddress, const char *deviceName, int ext, int size, 
	int constant, int global )
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	if( !ext ) 
	{
		if( constant ) 
		{
			report( "Registering constant variable " << (void*) hostVar 
				<< " (device " << deviceAddress 
				<< ") (name " << deviceName << ") (size " << size << ")." );
			cuda::runtime.registerGlobal( hostVar, size, deviceName, 
				ir::PTXInstruction::Const, ( long long int ) fatCubinHandle );
		}
		else
		{
			report( "Registering global variable " << (void*) hostVar 
				<< " (device " << deviceAddress 
				<< ") (name " << deviceName << ") (size " << size << ")." );
			cuda::runtime.registerGlobal( hostVar, size, deviceName, 
				ir::PTXInstruction::Global, ( long long int ) fatCubinHandle );
		}
	}

	cuda::runtime.unlock();
}

void __cudaRegisterTexture( void **fatCubinHandle, 
	const struct textureReference *hostVar, const void **deviceAddress, 
	const char *deviceName, int dim, int norm, int ext )
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
				
	if( !ext )
	{
		report( "Registering texture variable " << (void*) hostVar 
			<< " (device " << deviceAddress 
			<< ") (name " << deviceName << ") (dimensions " << dim << ")" 
			<< "(normalized " << norm << ")." );
		cuda::runtime.registerTexture( hostVar, dim, deviceName,
			( long long int ) fatCubinHandle, norm );
	}

	cuda::runtime.unlock();
}

void __cudaRegisterShared( void **fatCubinHandle, void **devicePtr )
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	report( "Registering shared variable " << (void**) devicePtr 
		<< " ( device 0x0) ( name " << (const char*)devicePtr << " )." );
			
	cuda::runtime.registerGlobal( devicePtr, 0, (const char*)devicePtr, 
		ir::PTXInstruction::Shared, ( long long int ) fatCubinHandle );

	cuda::runtime.unlock();
}

void __cudaRegisterSharedVar( void **fatCubinHandle, void **devicePtr, 
	size_t size, size_t alignment, int storage )
{
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	report( "Registering shared variable " << (void**) devicePtr 
		<< " ( device 0x0) ( name " << (const char*)devicePtr << " )." );
			
	cuda::runtime.registerGlobal( devicePtr, size, (const char*)devicePtr, 
		ir::PTXInstruction::Shared, ( long long int ) fatCubinHandle );

	cuda::runtime.unlock();
}

void __cudaRegisterFunction( void **fatCubinHandle, const char *hostFun, 
	char *deviceFun, const char *deviceName, int thread_limit, uint3 *tid, 
	uint3 *bid, dim3 *bDim, dim3 *gDim, int *wSize )
{
	report( "Called cuda register function with handle " 
		<< ( (long long int) fatCubinHandle ) << " for device function " 
		<< deviceFun  );
		
	cuda::runtime.lock();
	cuda::runtime.setContext();
	
	cuda::runtime.registerFunction( hostFun, deviceFun, 
		( (long long int) fatCubinHandle ) );
	
	cuda::runtime.unlock();	
}

void CUDARTAPI __cudaMutexOperation(int lock)
{
	throw hydrazine::Exception( "__cudaMutexOperation not implemented." );
}

int CUDARTAPI __cudaSynchronizeThreads(void**, void*)
{
	throw hydrazine::Exception( "__cudaSynchronizeThreads not implemented." );
}

}

#endif

