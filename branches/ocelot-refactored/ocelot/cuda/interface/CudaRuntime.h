/*!
	\file CudaRuntime.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements the CUDA Runtime API for Ocelot
*/

#ifndef OCELOT_CUDA_RUNTIME_H_INCLUDED
#define OCELOT_CUDA_RUNTIME_H_INCLUDED

// C++ libs
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

// UNIX libs
#include <pthread.h>

// Ocelot libs
#include <ocelot/cuda/interface/CudaRuntimeInterface.h>
#include <ocelot/executive/interface/ApplicationState.h>
#include <ocelot/executive/interface/Executive.h>

// Hydrazine includes
#include <hydrazine/implementation/Timer.h>

struct CUcontext;

namespace cuda {

	/*!
		CUDA event
	*/
	class Event {
	public:
	
		//! timer 
		hydrazine::Timer timer;
	
		//! CUDA reference to event
		cudaEvent_t handle;
		
		//! event creation flags
		unsigned int flags;	
	};

	/*! 
		CUDA stream
	*/
	class Stream {
	public:
	
		cudaStream_t handle;
	
		std::list< cudaEvent_t > events;
		
	};
	
	typedef std::map< cudaStream_t, Stream > StreamMap;
	typedef std::map< cudaEvent_t, Event > EventMap;
		
	/***************************************************************/

	/*!
		configuration of kernel launch
	*/
	class KernelLaunchConfiguration {
	public:
		KernelLaunchConfiguration(dim3 grid, dim3 block, size_t shared, cudaStream_t s): 
			gridDim(grid), blockDim(block), sharedMemory(shared), stream(s) { }
			
	public:
		
		//! dimensions of grid
		dim3 gridDim;
		
		//! dimensions of each block
		dim3 blockDim;
		
		//! number of bytes of dynamically allocated shared memory
		size_t sharedMemory;
		
		//! stream to which kernel launch is to be recorded
		cudaStream_t stream;
	};

	typedef std::list< KernelLaunchConfiguration > KernelLaunchStack;
	
	//! maps selected device to CUDA contexts
	class CudaContext {
	public:
	
		//! mapped host thread to context
		pthread_t thread;
	
		//! pointer to CUDA driver API context
		struct CUcontext * context;		
		
	public:
	
		CudaContext();
		
	};
	
	typedef std::map< int, CudaContext > CudaContextMap;
	
	
	/*!	\brief Set of thread ids */
	typedef std::set< pthread_t > ThreadSet;
			
	/*!	\brief Map from pointer to texture name and module */
	typedef std::map< const textureReference*, ir::Texture > TextureMap;
			
	/*! \brief A set of textures owned by a fat binary */
	typedef std::vector< const textureReference* > TextureVector;
	
	////////////////////////////////////////////////////////////////////////////////////////////////
	
	/*! \brief Registered OpenGL buffer */
	class RegisteredGLBuffer {
	public:
	
		//! constructor
		RegisteredGLBuffer();
		
	public:
	
		//! \brief flags set when the buffer is mapped
		int flags;
		
		//! \brief pointer to mapped buffer
		void *ptr;
		
		//! \brief true if buffer is mapped
		bool mapped;
	};
	
	typedef std::map< int, RegisteredGLBuffer > RegisteredGLBufferMap;
	
	/*! 
		Host thread CUDA context consists of these
	*/
	class HostThreadContext {	
	public:
	
		//! index of selected device
		int selectedDevice;
		
		//! array of valid device indices
		std::vector< int > validDevices;
	
		//! stack of launch configurations
		KernelLaunchStack launchConfigurations;
	
		//! existing streams
		StreamMap streams;
		
		//! existing maps
		EventMap events;
		
		//! next stream
		cudaStream_t nextStream;
		
		//! next event
		cudaEvent_t nextEvent;
	
		//! last result returned by a CUDA call
		cudaError_t lastError;
		
		//! parameter memory
		unsigned char *parameterBlock;
		
		//! size of parameter memory
		size_t parameterBlockSize;
		
		//! cuda context
		
		//! mapped GL buffers
		RegisteredGLBufferMap registeredGLbuffers;

		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector persistentTraceGenerators;

		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector nextTraceGenerators;
	
	public:
	
		HostThreadContext();	
	};
	
	typedef std::map< pthread_t, HostThreadContext > HostThreadContextMap;
	
	//! references a texture registered to CUDA runtime
	class RegisteredTexture {
	public:
	
		//! fat binary cubin handle
		size_t handle;
		
		//! host-side data structure pointer
		void *pointer;
		
		//! name of module
		const char *module;
		
		//! name of texture
		const char *texture;
	};
	
	//! maps name onto textures
	typedef std::map< std::string , RegisteredTexture > RegisteredTextureMap;

	typedef std::map< const void *, std::string> TextureReferenceMap;

	//! references a kernel registered to CUDA runtime
	class RegisteredKernel {
	public:
	
		//! cubin handle
		size_t handle;
		
		//! host-side function pointer
		void *pointer;
		
		//! name of module
		const char *module;
		
		//! name of kernel
		const char *kernel;
	};
	
	typedef std::map< void *, RegisteredKernel > RegisteredKernelMap;

		
	/*!	\brief Class allowing sharing of a fat binary among threads	*/
	class FatBinaryContext {
	public:
		
		//! pointer to CUBIN structure
		void *cubin_ptr;
		
	public:
	
		const char *name() const;
		
		const char *ptx() const;
	};
	
	typedef std::vector< FatBinaryContext > FatBinaryVector;

	////////////////////////////////////////////////////////////////////////////////////////////////

	/*!
		Cuda runtime context
	*/
	class CudaRuntime: public CudaRuntimeInterface {
	public:
	
	public:
	
		//! locking object for cuda runtime
		pthread_mutex_t mutex;
		
		//! maps selected devices onto pthreads and attached CUDA contexts
		CudaContextMap cudaContexts;
		
		//! map of pthreads to thread contexts
		HostThreadContextMap threads;
		
		//! execution context
		executive::Executive context;
		
		//! maps kernel symbols to module-kernels
		RegisteredKernelMap kernels;
		
		//! maps texture symbols to module-textures
		RegisteredTextureMap textures;

		//! maps textureReference* onto texture names
		TextureReferenceMap textureReferences;

		//! maps symbol pointers onto their device names
		std::map< void *, std::string > globalSymbolMap;
		
		// fatbinaries
		FatBinaryVector fatBinaries;
		
	public:
	
		CudaRuntime();
		
		~CudaRuntime();
	
	public:
	
		//! \brief acquires mutex and locks the runtime
		void lock();
		
		//! \brief releases mutex
		void unlock();
		
		//! \brief sets the last error state for the CudaRuntime object
		cudaError_t setLastError(cudaError_t result);

		//! \brief sets the last error state for the CudaRuntime object
		cudaError_t setLastErrorAndUnlock(HostThreadContext &thread, cudaError_t result);
		
		//! \brief gets current thread context
		HostThreadContext & getHostThreadContext();

		//! \brief returns an Ocelot-formatted error message
		std::string formatError(const std::string & message);

	public:
		//
		// FatBinary, function, variable, and texture register functions
		//

		virtual void** cudaRegisterFatBinary(void *fatCubin);

		virtual void cudaUnregisterFatBinary(void **fatCubinHandle);

		virtual void cudaRegisterVar(void **fatCubinHandle, char *hostVar, char *deviceAddress, 
			const char *deviceName, int ext, int size, int constant, int global);

		virtual void cudaRegisterTexture(
			void **fatCubinHandle,
			const struct textureReference *hostVar,
			const void **deviceAddress,
			const char *deviceName,
			int dim,
			int norm,
			int ext
		);

		virtual void cudaRegisterShared(
			void **fatCubinHandle,
			void **devicePtr
		);

		virtual void cudaRegisterSharedVar(
			void **fatCubinHandle,
			void **devicePtr,
			size_t size,
			size_t alignment,
			int storage
		);

		virtual void cudaRegisterFunction(
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

	public:
		
		//
		// Memory - linear
		//

		virtual cudaError_t  cudaMalloc(void **devPtr, size_t size);
		virtual cudaError_t  cudaMallocHost(void **ptr, size_t size);
		virtual cudaError_t  cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, 
			size_t height);
		virtual cudaError_t  cudaMallocArray(struct cudaArray **array, 
			const struct cudaChannelFormatDesc *desc, size_t width, size_t height __dv(1));
		virtual cudaError_t  cudaFree(void *devPtr);
		virtual cudaError_t  cudaFreeHost(void *ptr);
		virtual cudaError_t  cudaFreeArray(struct cudaArray *array);
	
	public:
	
		virtual cudaError_t cudaMemcpy(void *dst, const void *src, size_t count, 
			enum cudaMemcpyKind kind);
		virtual cudaError_t cudaMemcpyToSymbol(const char *symbol, const void *src, size_t count, 
			size_t offset, enum cudaMemcpyKind kind = cudaMemcpyHostToDevice);
		virtual cudaError_t  cudaMemcpyFromSymbol(void *dst, const char *symbol, size_t count, 
			size_t offset = 0, enum cudaMemcpyKind kind = cudaMemcpyDeviceToHost);
		virtual cudaError_t  cudaMemcpyAsync(void *dst, const void *src, size_t count, 
			enum cudaMemcpyKind kind, cudaStream_t stream);

		virtual cudaError_t  cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, 
			const void *src, size_t count, enum cudaMemcpyKind kind);
		virtual cudaError_t  cudaMemcpyFromArray(void *dst, const struct cudaArray *src, 
			size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind);
		virtual cudaError_t  cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, 
			size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, 
			size_t count, enum cudaMemcpyKind kind);

		virtual cudaError_t  cudaMemcpy2D(void *dst, size_t dpitch, const void *src, size_t spitch, 
			size_t width, size_t height, enum cudaMemcpyKind kind);
		virtual cudaError_t  cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, 
			size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, 
			enum cudaMemcpyKind kind);
		virtual cudaError_t  cudaMemcpy2DFromArray(void *dst, size_t dpitch, 
			const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, 
			enum cudaMemcpyKind kind);
		

	public:
		//
		// Memset
		//
		
		virtual cudaError_t  cudaMemset(void *devPtr, int value, size_t count);
		virtual cudaError_t  cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, size_t height);
		virtual cudaError_t  cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, struct cudaExtent extent);
		
	public:
		//
		// global variable accessors
		//
		
		virtual cudaError_t cudaGetSymbolAddress(void **devPtr, const char *symbol);
		virtual cudaError_t cudaGetSymbolSize(size_t *size, const char *symbol);
	
	public:
		//
		// CUDA device management
		//
		
		virtual cudaError_t cudaGetDeviceCount(int *count);
		virtual cudaError_t cudaGetDeviceProperties(struct cudaDeviceProp *prop, int device);
		virtual cudaError_t cudaChooseDevice(int *device, const struct cudaDeviceProp *prop);
		virtual cudaError_t cudaSetDevice(int device);
		virtual cudaError_t cudaGetDevice(int *device);
		virtual cudaError_t cudaSetValidDevices(int *device_arr, int len);
		virtual cudaError_t cudaSetDeviceFlags( int flags );
		
	public:
		//
		// texture binding
		//
		
		virtual cudaError_t cudaBindTexture(size_t *offset, const struct textureReference *texref, 
			const void *devPtr, const struct cudaChannelFormatDesc *desc, size_t size = UINT_MAX);
		virtual cudaError_t cudaBindTexture2D(size_t *offset,const struct textureReference *texref,
			const void *devPtr, const struct cudaChannelFormatDesc *desc,size_t width, size_t height, 
			size_t pitch);
		virtual cudaError_t cudaBindTextureToArray(const struct textureReference *texref, 
			const struct cudaArray *array, const struct cudaChannelFormatDesc *desc);
		virtual cudaError_t cudaUnbindTexture(const struct textureReference *texref);
		virtual cudaError_t cudaGetTextureAlignmentOffset(size_t *offset, 
			const struct textureReference *texref);
		virtual cudaError_t cudaGetTextureReference(const struct textureReference **texref, 
			const char *symbol);
	
	public:
		//
		// channel creation
		//

		virtual cudaError_t  cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, const struct cudaArray *array);
		virtual struct cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, enum cudaChannelFormatKind f);

	public:
	
		virtual cudaError_t cudaGetLastError(void);

	public:
		//
		// kernel configuration and launch procedures
		//
		
		virtual cudaError_t cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem = 0, 
			cudaStream_t stream = 0);
		virtual cudaError_t cudaSetupArgument(const void *arg, size_t size, size_t offset);
		virtual cudaError_t cudaLaunch(const char *entry);
		virtual cudaError_t cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const char *func);	
	
	public:
		//
		// event creation
		//
		
		virtual cudaError_t  cudaEventCreate(cudaEvent_t *event);
		virtual cudaError_t  cudaEventCreateWithFlags(cudaEvent_t *event, int flags);
		virtual cudaError_t  cudaEventRecord(cudaEvent_t event, cudaStream_t stream);
		virtual cudaError_t  cudaEventQuery(cudaEvent_t event);
		virtual cudaError_t  cudaEventSynchronize(cudaEvent_t event);
		virtual cudaError_t  cudaEventDestroy(cudaEvent_t event);
		virtual cudaError_t  cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end);
	
	public:
		//
		// stream creation
		//
	
		virtual cudaError_t  cudaStreamCreate(cudaStream_t *pStream);
		virtual cudaError_t  cudaStreamDestroy(cudaStream_t stream);
		virtual cudaError_t  cudaStreamSynchronize(cudaStream_t stream);
		virtual cudaError_t  cudaStreamQuery(cudaStream_t stream);
	
	public:
		//
		// kernel thread synchronization
		//
		
		virtual cudaError_t cudaThreadExit(void);
		virtual cudaError_t cudaThreadSynchronize(void);
		
	public:
		//
		// OpenGL interoperability
		//
		
		virtual cudaError_t cudaGLMapBufferObject(void **devPtr, GLuint bufObj);
		virtual cudaError_t cudaGLMapBufferObjectAsync(void **devPtr, GLuint bufObj, cudaStream_t stream);
		virtual cudaError_t cudaGLRegisterBufferObject(GLuint bufObj);
		virtual cudaError_t cudaGLSetBufferObjectMapFlags(GLuint bufObj, unsigned int flags);
		virtual cudaError_t cudaGLSetGLDevice(int device);
		virtual cudaError_t cudaGLUnmapBufferObject(GLuint bufObj);
		virtual cudaError_t cudaGLUnmapBufferObjectAsync(GLuint bufObj, cudaStream_t stream);
		virtual cudaError_t cudaGLUnregisterBufferObject(GLuint bufObj);
		
	public:

		virtual void addTraceGenerator( trace::TraceGenerator& gen, bool persistent = false, 
			bool safe = true );
		virtual void clearTraceGenerators( bool safe = true );
		virtual void limitWorkerThreads( unsigned int limit = 1024 );

	};

}

#endif

