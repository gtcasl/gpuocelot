/*!
	\file CudaRuntime.h
	\date Thursday March 19, 2009
	\author Gregory Diamos
	\brief The header file for the CudaRuntime class.	
*/

#ifndef CUDA_RUNTIME_H_INCLUDED
#define CUDA_RUNTIME_H_INCLUDED

#include <cuda_runtime_api.h>
#include <__cudaFatFormat.h>
#include <ocelot/executive/interface/Executive.h>
#include <unordered_map>
#include <unordered_set>
#include <pthread.h>
#include <hydrazine/implementation/Timer.h>
#include <hydrazine/interface/Configurable.h>
#include <ocelot/api/interface/OcelotRuntime.h>
#include <GL/glew.h>

#define CUDA_VERBOSE 1


#if HAVE_CUDA_DRIVER_API == 1
typedef struct CUstream_st *CUstream;
#endif

namespace cuda
{

	/*!	\brief Fat Binary shorthand */
	typedef __cudaFatCudaBinaryRec FatBinary;

	/*!	
		\brief Thread safe class that contains the ocelot executive classes for
			each context.	
	*/
	class CudaRuntime : public hydrazine::Configurable
	{
		public:
			class Memory
			{
				public:
					char* base;
					char *device;
					size_t size;
					bool portable;
					bool mapped;
					pthread_t owner;
			};
			
			/*!	\brief Allocated memory	*/
			typedef std::unordered_map< char*, Memory > MemoryMap;
			
			/*!	\brief GLobal variables	*/
			typedef std::unordered_map< std::string, char* > GlobalMap;
						
			/*!	\brief Map from architecture type to kernel. */
			typedef std::unordered_map< unsigned int,
				ir::Kernel* > ArchitectureMap;
			
			/*!	\brief A map from kernel name to architecture implementations */
			typedef std::unordered_map< std::string, 
				ArchitectureMap > KernelMap;
			
			/*!	\brief Set of thread ids */
			typedef std::unordered_set< pthread_t > ThreadSet;
			
			class Texture
			{
				public:
					std::string name;
					std::string module;
					bool bound;
			};
			
			/*!	\brief Map from pointer to texture name and module */
			typedef std::unordered_map< const textureReference*, 
				Texture > TextureMap;
			
			/*! \brief A set of textures owned by a fat binary */
			typedef std::vector< const textureReference* > TextureVector;
			
			/*!	\brief Class allowing sharing of a fat binary among threads	*/
			class FatBinaryContext
			{
				public:
					std::string name; //! The fat binary name
					ThreadSet threads; //! Registered threads
					KernelMap kernels; //! Translated kernels
					GlobalMap globals; //! Global variables
					TextureVector textures; //! Texture variables
			};
			
			/*!	\brief Kernel name and handle pair */
			class HandleAndKernel
			{
				public:
					std::string kernel;
					unsigned int handle;
			};
			
			/*!	\brief Stream class	*/
			class Stream
			{
				public:
					cudaStream_t handle;
#if HAVE_CUDA_DRIVER_API == 1
					CUstream cuStream;
#endif
			};
			
			/*! \brief Event class */
			class Event
			{
				public:
					cudaEvent_t handle;
					hydrazine::Timer timer;
#if HAVE_CUDA_DRIVER_API == 1
					CUevent cuEvent;
#endif
			};
			
			/*! \brief Stream map */
			typedef std::unordered_map< cudaStream_t, Stream > StreamMap;

			/*! \brief Event map */
			typedef std::unordered_map< cudaEvent_t, Event > EventMap;
			
			/*! \brief A vector of trace generator pointers */
			typedef std::vector< trace::TraceGenerator* > TraceGeneratorVector;

			/*!	\brief Thread context */
			class ThreadContext
			{
				public:
					typedef std::vector< char > Parameter;
					typedef std::map< unsigned int, Parameter > ParameterMap;
			
				public:
					int guid;
					dim3 ctaDimensions;
					dim3 kernelDimensions;
					unsigned int shared;
					ParameterMap parameters;
					int flags;
					
				public:
					StreamMap streams;
					EventMap events;
					cudaStream_t nextStream;
					cudaEvent_t nextEvent;

				public:
					cudaError_t lastError;

				public:
					TraceGeneratorVector nextTraceGenerators;
					TraceGeneratorVector persistentTraceGenerators;
					
				public:
					ThreadContext();				
			};
			
			/*!	\brief Map from pthreads to ocelot contexts. */
			typedef std::unordered_map< pthread_t, ThreadContext > ThreadMap;

			
			typedef std::unordered_map< const char*, HandleAndKernel > 
				SymbolMap;

			/*!	\brief A map of registered fat binaries. */
			typedef std::unordered_map< unsigned int, FatBinaryContext > 
				FatBinaryMap;

			/*!	\brief Map from string to handle */
			typedef std::unordered_map< std::string, unsigned int > StringMap;
			
			/*!	\brief Class for allocated CUDA arrays */
			class Array
			{
				public:
					cudaArray* array;
					unsigned int width;
					unsigned int height;
					unsigned int length;
					cudaChannelFormatDesc channel;
				public:
					unsigned int bytes() const;						
			};
			
			/*!	\brief A map of cudaArray pointers to Array objects */
			typedef std::unordered_map< cudaArray*, Array > ArrayMap;

		public:
			/*!	\brief OpenGL Buffers */
			typedef void* OpenGLBuffer;

		private:
			/*!	\brief Set of OpenGL Buffers */
			typedef std::unordered_map< GLuint, OpenGLBuffer > OpenGLBufferMap;
			
		private:
		
			/*! \brief A copy of the Ocelot runtime */
			ocelot::OcelotRuntime _ocelotRuntime;
		
			/*!	\brief Mutex to control access to the executive class. */
			pthread_mutex_t _mutex;

			/*!	\brief Map from all active threads to associated devices. */
			ThreadMap _threads;
	
			/*!	\brief Next fat binary handlem */
			unsigned int _handle;
			
			/*!	\brief All registered fat binaries */
			FatBinaryMap _binaries;
			
			/*!	\brief Names of registered FatBinaries */
			StringMap _binaryNames;
			
			/*!	\brief Host pinned memory */
			MemoryMap _memory;
			
			/*!	\brief Registered buffers.*/
			OpenGLBufferMap _openGLBuffers;
			
			/*!	\brief Allocated arrays	*/
			ArrayMap _arrays;
		
			/*!	\brief Registered Textures */
			TextureMap _textures;
			
			/*!	\brief Registered Symbols */
			SymbolMap _symbols;
			
			/*! \brief Default device index */
			unsigned int _defaultDevice;
						
		private:
			/*!
				\brief Get an iterator to a translated kernel
				\param kernel An iterator to the kernel name and handle.
			*/
			ArchitectureMap::iterator _getTranslatedKernel( 
				SymbolMap::iterator kernel );
			
			/*! \brief Copy parameter values from thread values to a kernel */
			void _setParameters( ir::Kernel& k, ThreadMap::iterator thread );

			/*! \brief Launch an emulated kernel
				\param thread An iterator to the current thread
				\param translatedKernel The kernel being launched */
			void _launchKernel( ThreadMap::iterator thread, 
				ArchitectureMap::iterator translatedKernel );
		
		public:
			/*!	\brief Ocelot state for all contexts.*/
			executive::Executive context;
						
		public:
			/*!	\brief Convert an ocelot device to a cuda equivalent */
			static cudaDeviceProp convert( const executive::Device& device );
			
			/*!	\brief Convert an ocelot texture to a cuda equivalent */
			static cudaChannelFormatDesc convert( const ir::Texture& texture);

			/*!	\brief Convert a cuda channel description to a ocelot texture */
			static ir::Texture convert( const cudaChannelFormatDesc& texture);

			/*! \brief Convert a cudaTextureAddressMode to a texture */
			static ir::Texture::AddressMode convert(cudaTextureAddressMode);

			/*!	\brief Convert a cudaTextureFilterMode to texture equivalent */
			static ir::Texture::Interpolation convert(cudaTextureFilterMode);

			/*!
				\brief Determine the number of bytes needed to store a 
					single element of a cudaChannelFormatDesc
				\param A reference to a cudaChannelFormatDesc
				\return The bytes per element of desc
			*/
			static unsigned int bytes( const cudaChannelFormatDesc& desc );
			
			/*! \brief Convert an error message to an ocelot error message */
			static std::string formatError( const std::string& message );
			
		public:
			/*!	\brief Constructor for the mutex */
			CudaRuntime();
			
			/*!	\brief Destructor to destroy the mutex */
			~CudaRuntime();
			
			/*!	\brief Lock the mutex */
			void lock();
			
			/*!	\brief Unlock the mutex */
			void unlock();
			
			/*!	\brief Switch to the context of the calling thread.	*/
			void setContext();

			/*!	\brief Destroy the context of the calling thread. */
			void destroyContext();
						
			/*!	\brief Last error code from cuda launch	*/
			cudaError_t lastError() const;
			
			/*!
				\brief Change the device of the calling thread.
			
				\param device The guid of the device to select
				\return True on success
			*/
			void setDevice( int device );
			
			/*!	\brief Find the device that most closly matches the specified
					characteristics
			*/
			int bestDevice( const struct cudaDeviceProp *prop ) const;
			
			/*!	\brief Set the flags on the current context	*/
			void setFlags( int flags );
	
			/*!
				\brief Register a new FatBinary
			
				\param binary The FatBinary being registered.
				\return A handle to the regietered binary
			*/
			unsigned int registerFatBinary( const FatBinary& binary );

			/*! \brief Get a handle to a fat binary by name 
				\param name The name of the fat binary being searched for
				\return A handle to the specified binary
			*/
			unsigned int getFatBinaryHandle( const std::string& name );

			/*! \brief unRegister a FatBinary
			
				\param handle The FatBinary being unregistered.
			*/
			void unregisterFatBinary( unsigned int handle );
			
			/*!
				\brief Set up launch parameters.
			
				\param kernel Kernel dimensions
				\param cta CTA dimensions
				\param memory Shared memory
			*/
			void configureCall( dim3 kernel, dim3 cta, unsigned int memory );

			/*!
				\brief Set up kernel arguments.
			
				\param arg The argument data
				\param size Bytes used by the argument data
				\param offset Where to store the data in parameter memory
			*/
			void setupArgument( const void *arg, unsigned int size, 
				unsigned int offset );
				
			/*!
				\brief Gte attributes associated with a function.
				
				\param attributes The attributes to fill int.
				\param name The symbol of the function being looked up.	
			*/
			void getAttributes( cudaFuncAttributes* attributes, 
				const char* symbol );
			
			/*!
				\brief Register function names
			
				\param Pointer to the equivalent host function
				\param PTX Kernel name
				\param handle Handle to the fat binary associated with this 
					kernel
			*/
			void registerFunction( const char* symbol, 
				const std::string& name, unsigned int handle );

			/*!
				\brief Register global variables			
				\param pointer Pointer to memory region
				\param PTX Kernel name
				\param handle Handle to the fat binary associated with this 
					variable
				\param space Address space
			*/
			void registerGlobal( void* pointer, unsigned int size, 
				const std::string& name, ir::PTXInstruction::AddressSpace, 
				unsigned int handle );

			/*! \brief Register texture variables			
				\param pointer Pointer to texture
				\param PTX Kernel name
				\param handle Handle to the fat binary associated with this 
					variable
				\param normalize Should the normalize parameter be set for this
					texture
			*/
			void registerTexture( const textureReference* hostVar, 
				unsigned int size, const std::string& name, 
				unsigned int handle, bool normalize );
				
			/*! \brief Determine if a pointer is to a global variable
				\param pointer Pointer being evaluated
				\return True if pointer is to a gloabl
			*/
			bool isGlobal( const void* pointer ) const;


			bool memcpyToSymbol( const char* symbol, const void* src, 
				size_t count, size_t offset);

			bool memcpyFromSymbol( void* dst, const char* symbol, 
				size_t count, size_t offset);

			/*! \brief Launch a cuda kernel			
				\param Pointer to the equivalent host function
			*/
			void launch( const char* symbol );
		
		public:
			/*! \brief Allocate some host pinned memory
				\param size The number of bytes to allocate
				\return a pointer to newly allocated memory on the host
			*/
			void* allocate( unsigned int size, bool portable = false, 
				bool mappable = false );

			/*! \brief Look up allocated and mapped memory on the cuda device
				\param pointer A pointer to mapped host memory
				\return A pointer to the equiavlent device memory
			*/
			void* lookupMappedMemory( void* pointer );

			/*! \brief Free some host pinned memory			
				\param pointer The memory to free
			*/
			void free( void* pointer );

			/*! \brief Free some host-mapped memory			
				\param pointer The memory to free
			*/
			void freeHost( void* pointer );

			/*! \brief Allocate a device array
				\param desc The channel description of the array
				\param width Number of elements wide
				\param height Number of elements high
				\param length Number of elements long
				\return Pointer to a newly allocated array
			*/
			cudaArray * allocateArray( const cudaChannelFormatDesc& desc,
				unsigned int width, unsigned int height, 
				unsigned int length = 1 );

			/*! \brief Free some host pinned memory			
				\param pointer The memory to free
			*/
			void freeArray( cudaArray * pointer );
			
			/*! \brief Get a byte offset from an array given the width, 
					height, and length indices
				
				\param array The array to get the offset from
				\param height The height index
				\param length The length index
				\param width The width index
				\return The offset in bytes
			*/
			unsigned int offset( const cudaArray* array, unsigned int width, 
				unsigned int height, unsigned int length = 0 ) const;
				
			/*! \brief Get a reference to the channel description of an array
				\param array The array for which to get the description
				\return The description
			*/
			const cudaChannelFormatDesc& getChannel( 
				const cudaArray* array ) const;
				
			/*! \brief Get a reference to a global texture symbol
				\return The refernce
				\param name The name of the global texture variable
			*/
			const textureReference* getTexture( 
				const std::string& name ) const;
				
			/*! \brief Rebinds a texture to another allocated device memory
					region
			*/
			void rebind( const textureReference *texref, 
				const void *devPtr, const cudaChannelFormatDesc *desc, 
				size_t size );
				
			/*! \brief Rebinds a texture to another allocated device memory
					region
			*/
			void rebind( const textureReference *texref, 
				const cudaArray* array, const cudaChannelFormatDesc *desc );

			/*! \brief Unbinds a texture */
			void unbind( const textureReference *texref );
				
			/*!
				\brief Get a pointer to a global variable by name
				\param name The name of the symbol
				\return A pointer to the variable
			*/
			void* getSymbol(const std::string& name);
			
		public:
			/*!	\brief Create a new Stream in this context
				\return A handle to the newly created Stream
			*/
			cudaStream_t createStream();

			/*! \brief Destroy a Stream in this context
				\param stream A handle to the Stream being destroyed
			*/
			void destroyStream( cudaStream_t stream );

			/*! \brief Determine if a Stream handle is valid
				
				\param stream The Stream handle
				\return True if valid in this context
			*/
			bool streamValid( cudaStream_t stream ) const;

			/*! \brief Create a new Event in this context
				\return A handle to the newly created Event
			*/
			cudaEvent_t createEvent();

			/*! \brief Destroy an Event in this context
				\param stream A handle to the Event being destroyed
			*/
			void destroyEvent( cudaEvent_t event );
		
			/*! \brief Determine if an Event handle is valid
				
				\param event The Event handle
				\return True if valid in this context
			*/
			bool eventValid( cudaEvent_t event ) const;

			/*! \brief Determine if an Event handle exists
				
				\param event The Event handle
				\return True if valid in this context
			*/
			bool eventExists( cudaEvent_t handle ) const;

			bool eventSynchronize(cudaEvent_t handle);

			/*! \brief Record that an event occured on a specific stream
				
				\param stream The stream handle
				\param event The Event handle
				\return True if valid in this context
			*/
			void eventRecord( cudaEvent_t event, cudaStream_t stream );
			
			/*! \brief Get the elapsed time in ms between two events
				
				\param start Start event
				\param end End event
				\return The elapsed time in ms
			*/
			double eventTime( cudaEvent_t start, cudaEvent_t end );

			bool threadSynchronize();
			
			/*! \brief Clear all errors */
			void clearErrors();
			
		public:
			/*!	\brief Registers an openGL buffer */
			void registerOpenGLBuffer( GLuint buffer );

			/*!	\brief Unregisters an openGL buffer	*/
			void unregisterOpenGLBuffer( GLuint buffer );

			/*!	\brief Maps an openGL buffer */
			OpenGLBuffer mapOpenGLBuffer( GLuint buffer );

			/*!	\brief Unmaps an openGL buffer */
			void unmapOpenGLBuffer( GLuint buffer );
		
		public:
			/*! \brief Adds a trace generator for the next kernel launch 
				\param gen The trace generator being added 
				\param persistent Should the trace generator be used for 
					all subsequent kernel launches?				
				(note that the external program owns the generator)
			*/
			void addTraceGenerator( trace::TraceGenerator& gen, 
				bool persistent );
				
			/*! \brief Clear all trace generators */
			void clearTraceGenerators();
			
		public:
			/*!	\brief Read config file	*/
			void configure( const Configuration& );
	};

}

#endif

