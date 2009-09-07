/*!
	\file OcelotRuntimeApi.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday March 10, 2009
	\brief The source file for the Ocelot implementation of the CUDA runtime
		API 2.3
*/

#ifndef CUDA_RUNTIME_API_CPP_INCLUDED
#define CUDA_RUNTIME_API_CPP_INCLUDED

#include <ocelot/cuda/interface/CudaRuntimeInterface.h>

typedef cuda::CudaRuntimeInterface Api;

cudaError_t CUDARTAPI cudaMalloc3D( struct cudaPitchedPtr* pitchDevPtr, 
	struct cudaExtent extent )
{
	return Api::entryPoint.runtime()->cudaMalloc3D( pitchDevPtr, extent );
}

cudaError_t CUDARTAPI cudaMalloc3DArray( struct cudaArray** arrayPtr, 
	const struct cudaChannelFormatDesc* desc, struct cudaExtent extent )
{
	return Api::entryPoint.runtime()->cudaMalloc3DArray( arrayPtr, 
		desc, extent );
}

cudaError_t CUDARTAPI cudaMemset3D( struct cudaPitchedPtr pitchDevPtr, 
	int value, struct cudaExtent extent )
{
	return Api::entryPoint.runtime()->cudaMemset3D( pitchDevPtr, 
		value, extent );
}

cudaError_t CUDARTAPI cudaMemcpy3D( const struct cudaMemcpy3DParms* p )
{
	return Api::entryPoint.runtime()->cudaMemcpy3D( p );
}

cudaError_t CUDARTAPI cudaMemcpy3DAsync( const struct cudaMemcpy3DParms* p, 
	cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpy3DAsync( p, stream );
}


cudaError_t CUDARTAPI cudaMalloc( void** devPtr, size_t size )
{
	return Api::entryPoint.runtime()->cudaMalloc( devPtr, size );
}

cudaError_t CUDARTAPI cudaMallocHost( void** ptr, size_t size )
{
	return Api::entryPoint.runtime()->cudaMallocHost( ptr, size );
}

cudaError_t CUDARTAPI cudaMallocPitch( void** devPtr, size_t* pitch, 
	size_t width, size_t height )
{
	return Api::entryPoint.runtime()->cudaMallocPitch( devPtr, 
		pitch, width, height );
}

cudaError_t CUDARTAPI cudaMallocArray( struct cudaArray** array, 
	const struct cudaChannelFormatDesc* desc, size_t width, size_t height )
{
	return Api::entryPoint.runtime()->cudaMallocArray( array, 
		desc, width, height );
}

cudaError_t CUDARTAPI cudaFree( void* devPtr )
{
	return Api::entryPoint.runtime()->cudaFree( devPtr );
}

cudaError_t CUDARTAPI cudaFreeHost( void* ptr )
{
	return Api::entryPoint.runtime()->cudaFreeHost( ptr );
}

cudaError_t CUDARTAPI cudaFreeArray( struct cudaArray* array )
{
	return Api::entryPoint.runtime()->cudaFreeArray( array );
}

cudaError_t CUDARTAPI cudaHostAlloc( void** pHost, size_t bytes, 
	unsigned int flags )
{
	return Api::entryPoint.runtime()->cudaHostAlloc( pHost, bytes, flags );
}

cudaError_t CUDARTAPI cudaHostGetDevicePointer( void** pDevice, void* pHost, 
	unsigned int flags )
{
	return Api::entryPoint.runtime()->cudaHostGetDevicePointer( pDevice, 
		pHost, flags );
}

cudaError_t CUDARTAPI cudaMemcpy( void* dst, const void* src, 
	size_t count, enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpy( dst, src, count, kind );
}

cudaError_t CUDARTAPI cudaMemcpyToArray( struct cudaArray* dst, size_t wOffset, 
	size_t hOffset, const void* src, size_t count, enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpyToArray( dst, wOffset, 
		hOffset, src, count, kind );
}

cudaError_t CUDARTAPI cudaMemcpyFromArray( void* dst, 
	const struct cudaArray* src, size_t wOffset, size_t hOffset, size_t count, 
	enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpyFromArray( dst, src, 
		wOffset, hOffset, count, kind );
}

cudaError_t CUDARTAPI cudaMemcpyArrayToArray( struct cudaArray* dst, 
	size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray* src, 
	size_t wOffsetSrc, size_t hOffsetSrc, size_t count, 
	enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpyArrayToArray( dst, wOffsetDst, 
		hOffsetDst, src, wOffsetSrc, hOffsetSrc, count, kind );
}

cudaError_t CUDARTAPI cudaMemcpy2D( void* dst, size_t dpitch, const void* src, 
	size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpy2D( dst, dpitch, src, 
		spitch, width, height, kind );
}

cudaError_t CUDARTAPI cudaMemcpy2DToArray( struct cudaArray* dst, 
	size_t wOffset, size_t hOffset, const void* src, size_t spitch, 
	size_t width, size_t height, enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpy2DToArray( dst, wOffset, 
		hOffset, src, spitch, width, height, kind );
}

cudaError_t CUDARTAPI cudaMemcpy2DFromArray( void* dst, size_t dpitch, 
	const struct cudaArray* src, size_t wOffset, size_t hOffset, size_t width, 
	size_t height, enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpy2DFromArray( dst, dpitch, 
		src, wOffset, hOffset, width, height, kind );
}

cudaError_t CUDARTAPI cudaMemcpy2DArrayToArray( struct cudaArray* dst, 
	size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray* src, 
	size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, 
	enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpy2DArrayToArray( dst, 
		wOffsetDst, hOffsetDst, src, wOffsetSrc, hOffsetSrc, width, 
		height, kind );
}

cudaError_t CUDARTAPI cudaMemcpyToSymbol( const char* symbol, const void* src, 
	size_t count, size_t offset, enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpyToSymbol( symbol, 
		src, count, offset, kind );
}

cudaError_t CUDARTAPI cudaMemcpyFromSymbol( void* dst, const char* symbol, 
	size_t count, size_t offset, enum cudaMemcpyKind kind )
{
	return Api::entryPoint.runtime()->cudaMemcpyFromSymbol( dst, symbol, 
		count, offset, kind );
}


cudaError_t CUDARTAPI cudaMemcpyAsync( void* dst, const void* src, size_t count, 
	enum cudaMemcpyKind kind, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpyAsync( dst, src, count, 
		kind, stream );
}

cudaError_t CUDARTAPI cudaMemcpyToArrayAsync( struct cudaArray* dst, 
	size_t wOffset, size_t hOffset, const void* src, size_t count, 
	enum cudaMemcpyKind kind, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpyToArrayAsync( dst, wOffset, 
		hOffset, src, count, kind, stream );
}

cudaError_t CUDARTAPI cudaMemcpyFromArrayAsync( void* dst, 
	const struct cudaArray* src, size_t wOffset, size_t hOffset, size_t count, 
	enum cudaMemcpyKind kind, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpyFromArrayAsync( dst, src, 
		wOffset, hOffset, count, kind, stream );
}

cudaError_t CUDARTAPI cudaMemcpy2DAsync( void* dst, size_t dpitch, 
	const void* src, size_t spitch, size_t width, size_t height, 
	enum cudaMemcpyKind kind, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpy2DAsync( dst, dpitch, src, 
		spitch, width, height, kind, stream );
}

cudaError_t CUDARTAPI cudaMemcpy2DToArrayAsync( struct cudaArray* dst, 
	size_t wOffset, size_t hOffset, const void* src, size_t spitch, 
	size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpy2DToArrayAsync( dst, wOffset, 
		hOffset, src, spitch, width, height, kind, stream );
}

cudaError_t CUDARTAPI cudaMemcpy2DFromArrayAsync( void* dst, size_t dpitch, 
	const struct cudaArray* src, size_t wOffset, size_t hOffset, size_t width, 
	size_t height, enum cudaMemcpyKind kind, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpy2DFromArrayAsync( dst, dpitch, 
		src, wOffset, hOffset, width, height, kind, stream );
}

cudaError_t CUDARTAPI cudaMemcpyToSymbolAsync( const char* symbol, 
	const void* src, size_t count, size_t offset, enum cudaMemcpyKind kind, 
	cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpyToSymbolAsync( symbol, src, 
		count, offset, kind, stream );
}

cudaError_t CUDARTAPI cudaMemcpyFromSymbolAsync( void* dst, const char* symbol, 
	size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaMemcpyFromSymbolAsync( dst, symbol, 
		count, offset, kind, stream );
}

cudaError_t CUDARTAPI cudaMemset( void* mem, int c, size_t count )
{
	return Api::entryPoint.runtime()->cudaMemset( mem, c, count );
}

cudaError_t CUDARTAPI cudaMemset2D( void* mem, size_t pitch, int c, 
	size_t width, size_t height )
{
	return Api::entryPoint.runtime()->cudaMemset2D( mem, pitch, 
		c, width, height );
}

cudaError_t CUDARTAPI cudaGetSymbolAddress( void** devPtr, const char* symbol )
{
	return Api::entryPoint.runtime()->cudaGetSymbolAddress(  devPtr, symbol );
}

cudaError_t CUDARTAPI cudaGetSymbolSize( size_t* size, const char* symbol )
{
	return Api::entryPoint.runtime()->cudaGetSymbolSize( size, symbol );
}


cudaError_t CUDARTAPI cudaGetDeviceCount( int* count )
{
	return Api::entryPoint.runtime()->cudaGetDeviceCount( count );
}

cudaError_t CUDARTAPI cudaGetDeviceProperties( struct cudaDeviceProp* prop, 
	int device )
{
	return Api::entryPoint.runtime()->cudaGetDeviceProperties( prop, device );
}

cudaError_t CUDARTAPI cudaChooseDevice( int* device, 
	const struct cudaDeviceProp* prop )
{
	return Api::entryPoint.runtime()->cudaChooseDevice( device, prop );
}

cudaError_t CUDARTAPI cudaSetDevice( int device )
{
	return Api::entryPoint.runtime()->cudaSetDevice( device );
}

cudaError_t CUDARTAPI cudaGetDevice( int* device )
{
	return Api::entryPoint.runtime()->cudaGetDevice( device );
}

cudaError_t CUDARTAPI cudaSetValidDevices( int* device_arr, int len )
{
	return Api::entryPoint.runtime()->cudaSetValidDevices( device_arr, len );
}

cudaError_t CUDARTAPI cudaSetDeviceFlags( int flags )
{
	return Api::entryPoint.runtime()->cudaSetDeviceFlags( flags );
}

cudaError_t CUDARTAPI cudaBindTexture( size_t* offset, 
	const struct textureReference* texref, const void* devPtr, 
	const struct cudaChannelFormatDesc* desc, size_t size )
{
	return Api::entryPoint.runtime()->cudaBindTexture( offset, texref, 
		devPtr, desc, size );
}

cudaError_t CUDARTAPI cudaBindTextureToArray(
	const struct textureReference* texref, const struct cudaArray* array, 
	const struct cudaChannelFormatDesc* desc )
{
	return Api::entryPoint.runtime()->cudaBindTextureToArray( texref, array,
		desc );
}

cudaError_t CUDARTAPI cudaUnbindTexture( const struct textureReference* texref )
{
	return Api::entryPoint.runtime()->cudaUnbindTexture( texref );
}

cudaError_t CUDARTAPI cudaGetTextureAlignmentOffset( size_t* offset, 
	const struct textureReference* texref )
{
	return Api::entryPoint.runtime()->cudaGetTextureAlignmentOffset( 
		offset, texref );
}

cudaError_t CUDARTAPI cudaGetTextureReference(
	const struct textureReference** texref, const char* symbol )
{
	return Api::entryPoint.runtime()->cudaGetTextureReference( texref, symbol );
}

cudaError_t CUDARTAPI cudaGetChannelDesc(struct cudaChannelFormatDesc* desc, 
	const struct cudaArray* array)
{
	return Api::entryPoint.runtime()->cudaGetChannelDesc( desc, array );
}

struct cudaChannelFormatDesc CUDARTAPI cudaCreateChannelDesc(int x, int y, 
	int z, int w, enum cudaChannelFormatKind f)
{
	return Api::entryPoint.runtime()->cudaCreateChannelDesc( x, y, z, w, f );
}

cudaError_t CUDARTAPI cudaGetLastError(void)
{
	return Api::entryPoint.runtime()->cudaGetLastError( );
}

const char* CUDARTAPI cudaGetErrorString( cudaError_t error )
{
	return Api::entryPoint.runtime()->cudaGetErrorString( error );
}

cudaError_t CUDARTAPI cudaConfigureCall( dim3 gridDim, dim3 blockDim, 
	size_t sharedMem, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaConfigureCall( gridDim, blockDim, 
		sharedMem, stream );
}

cudaError_t CUDARTAPI cudaSetupArgument(const void* arg, size_t size, 
	size_t offset)
{
	return Api::entryPoint.runtime()->cudaSetupArgument( arg, size, offset );
}

cudaError_t CUDARTAPI cudaLaunch( const char* symbol )
{
	return Api::entryPoint.runtime()->cudaLaunch( symbol );
}

cudaError_t CUDARTAPI cudaFuncGetAttributes( struct cudaFuncAttributes* attr, 
	const char* func )
{
	return Api::entryPoint.runtime()->cudaFuncGetAttributes( attr, func );
}

cudaError_t CUDARTAPI cudaStreamCreate( cudaStream_t* stream )
{
	return Api::entryPoint.runtime()->cudaStreamCreate( stream );
}

cudaError_t CUDARTAPI cudaStreamDestroy( cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaStreamDestroy( stream );
}

cudaError_t CUDARTAPI cudaStreamSynchronize( cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaStreamSynchronize( stream );
}

cudaError_t CUDARTAPI cudaStreamQuery( cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaStreamQuery( stream );
}


cudaError_t CUDARTAPI cudaEventCreate( cudaEvent_t* event )
{
	return Api::entryPoint.runtime()->cudaEventCreate( event );
}

cudaError_t CUDARTAPI cudaEventRecord( cudaEvent_t event, cudaStream_t stream )
{
	return Api::entryPoint.runtime()->cudaEventRecord( event, stream );
}

cudaError_t CUDARTAPI cudaEventQuery( cudaEvent_t event )
{
	return Api::entryPoint.runtime()->cudaEventQuery( event );
}

cudaError_t CUDARTAPI cudaEventSynchronize( cudaEvent_t event )
{
	return Api::entryPoint.runtime()->cudaEventSynchronize( event );
}

cudaError_t CUDARTAPI cudaEventDestroy( cudaEvent_t event )
{
	return Api::entryPoint.runtime()->cudaEventDestroy( event );
}

cudaError_t CUDARTAPI cudaEventElapsedTime( float* ms, cudaEvent_t start, 
	cudaEvent_t end )
{
	return Api::entryPoint.runtime()->cudaEventElapsedTime( ms, start, end );
}


cudaError_t CUDARTAPI cudaSetDoubleForDevice( double* d )
{
	return Api::entryPoint.runtime()->cudaSetDoubleForDevice( d );
}

cudaError_t CUDARTAPI cudaSetDoubleForHost( double* d )
{
	return Api::entryPoint.runtime()->cudaSetDoubleForHost( d );
}

cudaError_t CUDARTAPI cudaThreadExit(void)
{
	return Api::entryPoint.runtime()->cudaThreadExit( );
}

cudaError_t CUDARTAPI cudaThreadSynchronize(void)
{
	return Api::entryPoint.runtime()->cudaThreadSynchronize( );
}

cudaError_t CUDARTAPI cudaDriverGetVersion( int* driverVersion )
{
	return Api::entryPoint.runtime()->cudaDriverGetVersion( driverVersion );
}

cudaError_t CUDARTAPI cudaRuntimeGetVersion( int* runtimeVersion )
{
	return Api::entryPoint.runtime()->cudaRuntimeGetVersion( runtimeVersion );
}

extern "C"
{
typedef unsigned int GLuint;

cudaError_t CUDARTAPI cudaGLSetGLDevice( int device )
{
	return Api::entryPoint.runtime()->cudaGLSetGLDevice( device );
}

cudaError_t CUDARTAPI cudaGLRegisterBufferObject( GLuint bufObj )
{
	return Api::entryPoint.runtime()->cudaGLRegisterBufferObject( bufObj );
}

cudaError_t CUDARTAPI cudaGLMapBufferObject( void** devPtr, GLuint bufObj )
{
	return Api::entryPoint.runtime()->cudaGLMapBufferObject( devPtr, bufObj );
}

cudaError_t CUDARTAPI cudaGLUnmapBufferObject( GLuint bufObj )
{
	return Api::entryPoint.runtime()->cudaGLUnmapBufferObject( bufObj );
}

cudaError_t CUDARTAPI cudaGLUnregisterBufferObject( GLuint bufObj )
{
	return Api::entryPoint.runtime()->cudaGLUnregisterBufferObject( bufObj );
}
}

extern "C"
{
void __cudaTextureFetch( const void* tex, void* index, int integer, void* val )
{
	return Api::entryPoint.runtime()->cudaTextureFetch( tex, 
		index, integer, val );
}

void** __cudaRegisterFatBinary( void* fatCubin )
{
	return Api::entryPoint.runtime()->cudaRegisterFatBinary( fatCubin );
}

void __cudaUnregisterFatBinary( void** fatCubinHandle )
{
	return Api::entryPoint.runtime()->cudaUnregisterFatBinary( fatCubinHandle );
}

void __cudaRegisterVar( void** fatCubinHandle, char* hostVar, 
	char* deviceAddress, const char* deviceName, int ext, int size, 
	int constant, int global )
{
	return Api::entryPoint.runtime()->cudaRegisterVar( fatCubinHandle,
		hostVar, deviceAddress, deviceName, ext, size, constant, global );
}

void __cudaRegisterTexture( void** fatCubinHandle, 
	const struct textureReference* hostVar, const void** deviceAddress, 
	const char* deviceName, int dim, int norm, int ext )
{
	return Api::entryPoint.runtime()->cudaRegisterTexture( fatCubinHandle, 
		hostVar, deviceAddress, deviceName, dim, norm, ext );
}

void __cudaRegisterShared( void** fatCubinHandle, void** devicePtr )
{
	return Api::entryPoint.runtime()->cudaRegisterShared( fatCubinHandle, 
		devicePtr );
}

void __cudaRegisterSharedVar( void** fatCubinHandle, void** devicePtr, 
	size_t size, size_t alignment, int storage )
{
	return Api::entryPoint.runtime()->cudaRegisterSharedVar( fatCubinHandle,
		devicePtr, size, alignment, storage );
}

void __cudaRegisterFunction( void** fatCubinHandle, const char* hostFun, 
	char* deviceFun, const char* deviceName, int thread_limit, uint3* tid, 
	uint3* bid, dim3* bDim, dim3* gDim, int* wSize )
{
	return Api::entryPoint.runtime()->cudaRegisterFunction( fatCubinHandle,
		hostFun, deviceFun, deviceName, thread_limit, tid, bid, bDim, 
		gDim, wSize );
}

void CUDARTAPI __cudaMutexOperation( int lock )
{
	return Api::entryPoint.runtime()->cudaMutexOperation( lock );
}

int CUDARTAPI __cudaSynchronizeThreads( void** one, void* two )
{
	return Api::entryPoint.runtime()->cudaSynchronizeThreads( one, two );
}

}

#endif

