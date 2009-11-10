/*! \file CudaRuntimeInterface.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Saturday September 5, 2009
	\brief The header file for the CudaRuntimeInterface class.
*/

#ifndef CUDA_RUNTIME_INTERFACE_H_INCLUDED
#define CUDA_RUNTIME_INTERFACE_H_INCLUDED

#include <hydrazine/interface/Configurable.h>
#include <cuda_runtime_api.h>
#include <ocelot/trace/interface/TraceGenerator.h>

/*! \brief A namespace for the ocelot implementation of the CUDA API */
namespace cuda
{
	/*! \brief A class with virtual equivalents of all of the CUDA API calls */
	class CudaRuntimeInterface
	{
		public:
			/*! \brief A class for managing the entry point to the runtime */
			class EntryPoint : private hydrazine::Configurable
			{
				private:
					CudaRuntimeInterface* _runtime;
					
				public:
					/*! \brief Select a runtime implementation */
					EntryPoint();
					/*! \brief Tear down the runtime */
					~EntryPoint();
					/*! \brief Get a pointer to the runtime */
					CudaRuntimeInterface* runtime();
				
				public:
					void configure( const Configuration& configuration );
			};
		
		public:
			/*! \brief OpenGL unsigned int */
			typedef unsigned int GLuint;
	
		public:
			/*! \brief This is the entry point to all cuda calls */
			static EntryPoint entryPoint;
	
		public:
			/*! \brief Virtual destructor */
			virtual ~CudaRuntimeInterface();
	
		public:
			virtual cudaError_t cudaMalloc3D( cudaPitchedPtr* pitchedDevPtr, 
				cudaExtent extent ) = 0;
			virtual cudaError_t cudaMalloc3DArray( cudaArray** arrayPtr, 
				const cudaChannelFormatDesc* desc, cudaExtent extent ) = 0;
			virtual cudaError_t cudaMemset3D( cudaPitchedPtr pitchedDevPtr, 
				int value, cudaExtent extent ) = 0;
			virtual cudaError_t cudaMemcpy3D( const cudaMemcpy3DParms* p ) = 0;
			virtual cudaError_t cudaMemcpy3DAsync( const cudaMemcpy3DParms* p, 
				cudaStream_t stream ) = 0;

		public:
			virtual cudaError_t cudaMalloc( void** devPtr, size_t size ) = 0;
			virtual cudaError_t cudaMallocHost( void** ptr, size_t size ) = 0;
			virtual cudaError_t cudaMallocPitch( void** devPtr, 
				size_t* pitch, size_t width, size_t height ) = 0;
			virtual cudaError_t cudaMallocArray( cudaArray** array, 
				const cudaChannelFormatDesc* desc, size_t width, 
				size_t height = 1 ) = 0;
			virtual cudaError_t cudaFree( void* devPtr ) = 0;
			virtual cudaError_t cudaFreeHost( void* ptr ) = 0;
			virtual cudaError_t cudaFreeArray( cudaArray* array ) = 0;

			virtual cudaError_t cudaHostAlloc( void** pHost, size_t bytes, 
				unsigned int flags ) = 0;
			virtual cudaError_t cudaHostGetDevicePointer( void** pDevice, 
				void* pHost, unsigned int flags ) = 0;


		public:
			virtual cudaError_t cudaMemcpy( void* dst, const void* src, 
				size_t count, cudaMemcpyKind kind ) = 0;
			virtual cudaError_t cudaMemcpyToArray( cudaArray* dst, 
				size_t wOffset, size_t hOffset, const void* src, 
				size_t count, cudaMemcpyKind kind ) = 0;
			virtual cudaError_t cudaMemcpyFromArray( void* dst, 
				const cudaArray* src, size_t wOffset, size_t hOffset, 
				size_t count, cudaMemcpyKind kind ) = 0;
			virtual cudaError_t cudaMemcpyArrayToArray( cudaArray* dst, 
				size_t wOffsetDst, size_t hOffsetDst, 
				const cudaArray* src, size_t wOffsetSrc, 
				size_t hOffsetSrc, size_t count, 
					cudaMemcpyKind kind = cudaMemcpyDeviceToDevice ) = 0;
			virtual cudaError_t cudaMemcpy2D( void* dst, size_t dpitch, 
				const void* src, size_t spitch, size_t width, size_t height, 
				cudaMemcpyKind kind ) = 0;
			virtual cudaError_t cudaMemcpy2DToArray( cudaArray* dst, 
				size_t wOffset, size_t hOffset, const void* src, 
				size_t spitch, size_t width, size_t height, 
				cudaMemcpyKind kind ) = 0;
			virtual cudaError_t cudaMemcpy2DFromArray( void* dst, 
				size_t dpitch, const cudaArray* src, size_t wOffset, 
				size_t hOffset, size_t width, size_t height, 
				cudaMemcpyKind kind ) = 0;
			virtual cudaError_t cudaMemcpy2DArrayToArray( cudaArray* dst, 
				size_t wOffsetDst, size_t hOffsetDst, const cudaArray* src, 
				size_t wOffsetSrc, size_t hOffsetSrc, size_t width, 
				size_t height, 
				cudaMemcpyKind kind = cudaMemcpyDeviceToDevice ) = 0;
			virtual cudaError_t cudaMemcpyToSymbol( const char* symbol, 
				const void* src, size_t count, size_t offset = 0 , 
				cudaMemcpyKind kind = cudaMemcpyHostToDevice ) = 0;
			virtual cudaError_t cudaMemcpyFromSymbol( void* dst, 
				const char* symbol, size_t count, size_t offset = 0, 
				cudaMemcpyKind kind = cudaMemcpyDeviceToHost ) = 0;

		public:
			virtual cudaError_t cudaMemcpyAsync( void* dst, const void* src, 
				size_t count, cudaMemcpyKind kind, cudaStream_t stream ) = 0;
			virtual cudaError_t cudaMemcpyToArrayAsync( cudaArray* dst, 
				size_t wOffset, size_t hOffset, const void* src, size_t count, 
				cudaMemcpyKind kind, cudaStream_t stream ) = 0;
			virtual cudaError_t cudaMemcpyFromArrayAsync( void* dst, 
				const cudaArray* src, size_t wOffset, size_t hOffset, 
				size_t count, cudaMemcpyKind kind, cudaStream_t stream ) = 0;
			virtual cudaError_t cudaMemcpy2DAsync( void* dst, size_t dpitch, 
				const void* src, size_t spitch, size_t width, size_t height, 
				cudaMemcpyKind kind, cudaStream_t stream ) = 0;
			virtual cudaError_t cudaMemcpy2DToArrayAsync( cudaArray* dst, 
				size_t wOffset, size_t hOffset, const void* src, 
				size_t spitch, size_t width, size_t height, 
				cudaMemcpyKind kind, cudaStream_t stream ) = 0;
			virtual cudaError_t cudaMemcpy2DFromArrayAsync( void* dst, 
				size_t dpitch, const cudaArray* src, size_t wOffset, 
				size_t hOffset, size_t width, size_t height, 
				cudaMemcpyKind kind, cudaStream_t stream ) = 0;
			virtual cudaError_t cudaMemcpyToSymbolAsync( const char* symbol, 
				const void* src, size_t count, size_t offset, 
				cudaMemcpyKind kind, cudaStream_t stream ) = 0;
			virtual cudaError_t cudaMemcpyFromSymbolAsync( void* dst, 
				const char* symbol, size_t count, size_t offset, 
				cudaMemcpyKind kind, cudaStream_t stream ) = 0;

		public:
			virtual cudaError_t cudaMemset( void* devPtr, int value, 
				size_t count ) = 0;
			virtual cudaError_t cudaMemset2D( void* devPtr, size_t pitch, 
				int value, size_t width, size_t height ) = 0;

		public:
			virtual cudaError_t cudaGetSymbolAddress( void** devPtr, 
				const char* symbol ) = 0;
			virtual cudaError_t cudaGetSymbolSize( size_t* size, 
				const char* symbol ) = 0;

		public:
			virtual cudaError_t cudaGetDeviceCount( int* count ) = 0;
			virtual cudaError_t cudaGetDeviceProperties( cudaDeviceProp* prop, 
				int device ) = 0;
			virtual cudaError_t cudaChooseDevice( int* device, 
				const cudaDeviceProp* prop ) = 0;
			virtual cudaError_t cudaSetDevice( int device ) = 0;
			virtual cudaError_t cudaGetDevice( int* device ) = 0;
			virtual cudaError_t cudaSetValidDevices( int* device_arr, 
				int len ) = 0;
			virtual cudaError_t cudaSetDeviceFlags(  int flags  ) = 0;

		public:
			virtual cudaError_t cudaBindTexture( size_t* offset, 
				const textureReference* texref, const void* devPtr, 
				const cudaChannelFormatDesc* desc, size_t size = UINT_MAX ) = 0;
			virtual cudaError_t cudaBindTexture2D( size_t* offset, 
				const textureReference* texref, const void* devPtr, 
				const cudaChannelFormatDesc* desc, size_t width, 
				size_t height, size_t pitch ) = 0;
			virtual cudaError_t cudaBindTextureToArray( 
				const textureReference* texref, const cudaArray* array, 
				const cudaChannelFormatDesc* desc ) = 0;
			virtual cudaError_t cudaUnbindTexture( 
				const textureReference* texref ) = 0;
			virtual cudaError_t cudaGetTextureAlignmentOffset( size_t* offset, 
				const textureReference* texref ) = 0;
			virtual cudaError_t cudaGetTextureReference( 
				const textureReference** texref, const char* symbol ) = 0;

		public:
			virtual cudaError_t cudaGetChannelDesc( 
				cudaChannelFormatDesc* desc, 
				const cudaArray* array ) = 0;
			virtual cudaChannelFormatDesc cudaCreateChannelDesc( 
				int x, int y, int z, int w, cudaChannelFormatKind f ) = 0;

		public:
			virtual cudaError_t cudaGetLastError( void ) = 0;
			virtual const char* cudaGetErrorString( cudaError_t error ) = 0;

		public:
			virtual cudaError_t cudaConfigureCall( dim3 gridDim, dim3 blockDim, 
				size_t sharedMem = 0, cudaStream_t stream = 0 ) = 0;
			virtual cudaError_t cudaSetupArgument( const void* arg, 
				size_t size, size_t offset ) = 0;
			virtual cudaError_t cudaLaunch( const char* entry ) = 0;
			virtual cudaError_t cudaFuncGetAttributes( 
				cudaFuncAttributes* attr, const char* func ) = 0;

		public:
			virtual cudaError_t cudaStreamCreate( cudaStream_t* pStream ) = 0;
			virtual cudaError_t cudaStreamDestroy( cudaStream_t stream ) = 0;
			virtual cudaError_t cudaStreamSynchronize( 
				cudaStream_t stream ) = 0;
			virtual cudaError_t cudaStreamQuery( cudaStream_t stream ) = 0;

		public:
			virtual cudaError_t cudaEventCreate( cudaEvent_t* event ) = 0;
			virtual cudaError_t cudaEventCreateWithFlags( 
				cudaEvent_t* event, int flags ) = 0;
			virtual cudaError_t cudaEventRecord( cudaEvent_t event, 
				cudaStream_t stream ) = 0;
			virtual cudaError_t cudaEventQuery( cudaEvent_t event ) = 0;
			virtual cudaError_t cudaEventSynchronize( cudaEvent_t event ) = 0;
			virtual cudaError_t cudaEventDestroy( cudaEvent_t event ) = 0;
			virtual cudaError_t cudaEventElapsedTime( float* ms, 
				cudaEvent_t start, cudaEvent_t end ) = 0;

		public:
			virtual cudaError_t cudaSetDoubleForDevice( double* d ) = 0;
			virtual cudaError_t cudaSetDoubleForHost( double* d ) = 0;

		public:
			virtual cudaError_t cudaThreadExit( void ) = 0;
			virtual cudaError_t cudaThreadSynchronize( void ) = 0;

		public:
			virtual cudaError_t cudaDriverGetVersion( int* driverVersion ) = 0;
			virtual cudaError_t cudaRuntimeGetVersion( 
				int* runtimeVersion ) = 0;
		
		public:
			virtual cudaError_t cudaGLSetGLDevice( int device ) = 0;
			virtual cudaError_t cudaGLRegisterBufferObject( GLuint bufObj ) = 0;
			virtual cudaError_t cudaGLMapBufferObject( void **devPtr, 
				GLuint bufObj ) = 0;
			virtual cudaError_t cudaGLUnmapBufferObject( GLuint bufObj ) = 0;
			virtual cudaError_t cudaGLUnregisterBufferObject( 
				GLuint bufObj ) = 0;
			virtual void cudaTextureFetch( const void *tex, void *index, 
				int integer, void *val ) = 0;

		public:
			virtual void** cudaRegisterFatBinary( void* fatCubin ) = 0;
			virtual void cudaUnregisterFatBinary( void** fatCubinHandle ) = 0;
			virtual void cudaRegisterVar( void** fatCubinHandle, char* hostVar, 
				char* deviceAddress, const char* deviceName, int ext, int size, 
				int constant, int global ) = 0;
			virtual void cudaRegisterTexture( void** fatCubinHandle, 
				const struct textureReference* hostVar, 
				const void** deviceAddress, const char* deviceName, int dim, 
				int norm, int ext ) = 0;
			virtual void cudaRegisterShared( void** fatCubinHandle, 
				void** devicePtr ) = 0;
			virtual void cudaRegisterSharedVar( void** fatCubinHandle, 
				void** devicePtr, size_t size, size_t alignment, 
				int storage ) = 0;
			virtual void cudaRegisterFunction( void** fatCubinHandle, 
				const char* hostFun, char* deviceFun, const char* deviceName, 
				int thread_limit, uint3* tid, uint3* bid, dim3* bDim, 
				dim3* gDim, int* wSize ) = 0;
			virtual void cudaMutexOperation( int lock ) = 0;
			virtual int cudaSynchronizeThreads( void**, void* ) = 0;
			
		public:
			virtual void addTraceGenerator( trace::TraceGenerator& gen, 
				bool persistent, bool safe ) = 0;
			virtual void clearTraceGenerators( bool safe ) = 0;
			virtual void limitWorkerThreads( unsigned int limit ) = 0;
			virtual void registerPTXModule(std::istream& stream, 
				const std::string& name) = 0;
			virtual const char* getKernelPointer(const std::string& name, 
				const std::string& module) = 0;
	
	};

}

#endif

