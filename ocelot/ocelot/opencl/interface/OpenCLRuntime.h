#ifndef OCELOT_OPENCL_RUNTIME_H_INCLUDED
#define OCELOT_OPENCL_RUNTIME_H_INCLUDED

// C++ libs
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

// Boost libs
#include <boost/thread/thread.hpp>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/executive/interface/Device.h>
//#include <ocelot/opencl/interface/FatBinaryContext.h>
#include <ocelot/ir/interface/ExternalFunctionSet.h>

// Hydrazine includes
#include <hydrazine/implementation/Timer.h>

// Forward Declarations

namespace transforms { class Pass; }

namespace opencl {

	/***************************************************************/
	/*!	configuration of kernel launch */
	class KernelLaunchConfiguration {
	public:
		KernelLaunchConfiguration(cl_uint dim, size_t * gWorkOffset,
			size_t * gWorkSize, size_t * lWorkSize, cl_command_queue q): 
			workDim(dim), globalWorkOffset(gWorkOffset), 
			globalWorkSize(gWorkSize), localWorkSize(lWorkSize), commandQueue(q) { 
		}
			
	public:
		//! number of dimensions for work-items
		cl_uint workDim;
		
		//! global ID offset for work-items
		size_t * globalWorkOffset;

		//! global dimensions of work-items
		size_t * globalWorkSize;

		//! local dimensions of work-items in work-group
		size_t * localWorkSize;
		
		//! command queue to which kernel launch is to be queued
		cl_command_queue commandQueue;
	
	};

	typedef std::list< KernelLaunchConfiguration > KernelLaunchStack;
	
	/*!	\brief Set of thread ids */
	typedef std::set< boost::thread::id > ThreadSet;	
	
	typedef std::vector< unsigned int > IndexVector;
	typedef std::vector< unsigned int > SizeVector;
	
	/*! Host thread OpenCL context consists of these */
	class HostThreadContext {	
	public:
		//! index of selected device
		int selectedDevice;
		
		//! array of valid device indices
		std::vector< int > validDevices;
	
		//! stack of launch configurations
		KernelLaunchStack launchConfigurations;
	
		//! last result returned by a OpenCL call
		cl_int lastError;
		
		//! parameter memory
		unsigned char *parameterBlock;
		
		//! size of parameter memory
		size_t parameterBlockSize;

		//! Offsets for individual parameters
		IndexVector parameterIndices;
		
		//! Sizes for individual parameters
		SizeVector parameterSizes;
		
		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector persistentTraceGenerators;

		//! set of trace generators to be inserted into emulated kernels
		trace::TraceGeneratorVector nextTraceGenerators;
			
	public:
		HostThreadContext();
		~HostThreadContext();

		HostThreadContext(const HostThreadContext& c);	
		HostThreadContext& operator=(const HostThreadContext& c);

		HostThreadContext(HostThreadContext&& c);	
		HostThreadContext& operator=(HostThreadContext&& c);

		void clearParameters();
		void clear();
		unsigned int mapParameters(const ir::Kernel* kernel);
	};
	
	typedef std::map<boost::thread::id, HostThreadContext> HostThreadContextMap;
	
	//! references a kernel registered to OpenCL runtime
	class RegisteredKernel {
	public:
		RegisteredKernel(size_t handle = 0, const std::string& module = "", 
			const std::string& kernel = "");

	public:
		//! binary handle
		size_t handle;
		
		//! name of module
		std::string module;
		
		//! name of kernel
		std::string kernel;
	};
	
	typedef std::map< void*, RegisteredKernel > RegisteredKernelMap;
//
//	class RegisteredTexture
//	{
//		public:
//			RegisteredTexture(const std::string& module = "", 
//				const std::string& texture = "", bool norm = false);
//	
//		public:
//			/*! \brief The module that the texture is declared in */
//			std::string module;
//			/*! \brief The name of the texture */
//			std::string texture;
//			// Should the texture be normalized?
//			bool norm;
//	};
//	
//	class RegisteredGlobal
//	{
//		public:
//			RegisteredGlobal(const std::string& module = "", 
//				const std::string& global = "");
//	
//		public:
//			/*! \brief The module that the global is declared in */
//			std::string module;
//			/*! \brief The name of the global */
//			std::string global;
//	};
//	
//	class Dimension
//	{
//		public:
//			/*! \brief Initializing constructor */
//			Dimension(int x = 0, int y = 0, int z = 0, 
//				const openclChannelFormatDesc& f = 
//				openclCreateChannelDesc(8,0,0,0,openclChannelFormatKindNone));
//	
//			/*! \brief Get the pitch of the array */
//			size_t pitch() const;
//	
//		public:
//			/*! \brief X dimension */
//			int x;
//			/*! \brief Y dimension */
//			int y;
//			/*! \brief Z dimension */
//			int z;
//			/*! \brief Format */
//			openclChannelFormatDesc format;
//	};
//	
//	/*! \brief Set of PTX passes */
//	typedef std::set< transforms::Pass* > PassSet;
//
//	typedef std::vector< FatBinaryContext > FatBinaryVector;
//	typedef std::map< void*, RegisteredGlobal > RegisteredGlobalMap;
//	typedef std::map< void*, RegisteredTexture > RegisteredTextureMap;
//	typedef std::map< void*, Dimension > DimensionMap;
	typedef std::map< std::string, ir::Module > ModuleMap;
//	typedef std::unordered_map<unsigned int, void*> GLBufferMap;
	typedef executive::DeviceVector DeviceVector;

	////////////////////////////////////////////////////////////////////////////
	/*! OpenCL runtime context */
	class OpenCLRuntime: public OpenCLRuntimeInterface {
	private:
		/*! \brief Memory copy */
		//void _memcpy(void* dst, const void* src, size_t count, 
		//	enum openclMemcpyKind kind);
		/*! \brief Report a memory error and throw an exception */
		void _memoryError(const void* address, size_t count, 
			const std::string& function = "");		
		/*! \brief Create devices if they do not already exist */
		void _enumerateDevices();
		//! \brief acquires mutex and locks the runtime
		void _lock();
		//! \brief releases mutex
		void _unlock();
		//! \brief sets the last error state for the OpenCLRuntime object
		cl_int _setLastError(cl_int result);
		//! \brief Bind the current thread to a device context
		HostThreadContext& _bind();
		//! \brief Unbind the current thread
		void _unbind();
		//! \brief Lock the mutex and bind the the thread
		void _acquire();
		/*! \brief Unbind the thread and unlock the mutex */
		void _release();
		//! \brief gets the current device for the current thread
		executive::Device& _getDevice();
		//! \brief returns an Ocelot-formatted error message
		std::string _formatError(const std::string & message);
		// Get the current thread, create it if it doesn't exist
		HostThreadContext& _getCurrentThread();
		// Load module and register it with all devices
		void _registerModule(ModuleMap::iterator module);
		// Load module and register it with all devices
		void _registerModule(const std::string& name);
		// Load all modules and register them with all devices
		void _registerAllModules();

	private:
		//! locking object for opencl runtime
		boost::mutex _mutex;
		
		//! There is a thread in execute
		bool _inExecute;
		
		//! locking object for access to the runtime from worker threads
		boost::mutex _executingMutex;
		
		//! Registered modules
		ModuleMap _modules;
		
		//! map of pthreads to thread contexts
		HostThreadContextMap _threads;
		
		//! map of kernels
		RegisteredKernelMap _kernels;
		
		//! maps texture symbols to module-textures
		//RegisteredTextureMap _textures;

		//! maps symbol pointers onto their device names
		//RegisteredGlobalMap _globals;
		
		//! The dimensions for multi-dimensional allocations
		//DimensionMap _dimensions;
		
		//! Registered opengl buffers and mapping to graphics resources
		//GLBufferMap _buffers;
		
		//! The total number of enabled devices in the system
		unsigned int _deviceCount;
		
		//! Device vector
		DeviceVector _devices;
		
		//! Have the devices been loaded?
		bool _devicesLoaded;
		
		//! Currently selected device
		int _selectedDevice;
		
		//! the next symbol for dynamically registered kernels
		int _nextSymbol;
		
		//! The minimum supoported compute capability
		int _computeCapability;
		
		//! The device flags
		unsigned int _flags;
		
		//! fatbinaries
	//	FatBinaryVector _fatBinaries;
		
		//! optimization level
		translator::Translator::OptimizationLevel _optimization;
	
		//! external functions
	//	ir::ExternalFunctionSet _externals;
		
		//! PTX passes
	//	PassSet _passes;
	
	private:
		cl_int _launchKernel(const std::string& module, 
			const std::string& kernel);
		
	public:
		OpenCLRuntime();
		~OpenCLRuntime();

	public:
		//
		// FatBinary, function, variable, and texture register functions
		//
		//virtual void** openclRegistierFatBinary(void *fatCubin);

		//virtual void openclUnregisterFatBinary(void **fatCubinHandle);

		//virtual void openclRegisterVar(void **fatCubinHandle, char *hostVar, 
		//	char *deviceAddress, const char *deviceName, int ext, int size, 
		//	int constant, int global);

		/*virtual void openclRegisterTexture(
			void **fatCubinHandle,
			const struct textureReference *hostVar,
			const void **deviceAddress,
			const char *deviceName,
			int dim,
			int norm,
			int ext
		);*/

		/*virtual void openclRegisterShared(
			void **fatCubinHandle,
			void **devicePtr
		);*/

		/*virtual void openclRegisterSharedVar(
			void **fatCubinHandle,
			void **devicePtr,
			size_t size,
			size_t alignment,
			int storage
		);*/

		/*virtual void openclRegisterFunction(
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
		);*/
		
		/*virtual openclError_t openclGetExportTable(const void **ppExportTable,
			const openclUUID_t *pExportTableId);*/

	public:

//		virtual void addTraceGenerator( trace::TraceGenerator& gen, 
//			bool persistent = false );
//		virtual void clearTraceGenerators();

//		virtual void addPTXPass(transforms::Pass &pass);
//		virtual void removePTXPass(transforms::Pass &pass);
//		virtual void clearPTXPasses();
		virtual void limitWorkerThreads( unsigned int limit = 1024 );
		virtual void registerPTXModule(std::istream& stream, 
			const std::string& name);
//		virtual void registerTexture(const void* texref,
//			const std::string& moduleName,
//			const std::string& textureName, bool normalize);
		virtual void clearErrors();
		virtual void reset();
		virtual ocelot::PointerMap contextSwitch( 
			unsigned int destinationDevice, unsigned int sourceDevice);
		virtual void unregisterModule(const std::string& name);
		virtual void launch(const std::string& moduleName, 
			const std::string& kernelName);
		virtual void setOptimizationLevel(
			translator::Translator::OptimizationLevel l);
//		virtual void registerExternalFunction(const std::string& name,
//			void* function);
//		virtual void removeExternalFunction(const std::string& name);


	public:
		virtual cl_int clGetPlatformIDs(cl_uint num_entries, 
										cl_platform_id * platforms, 
										cl_uint * num_platforms);
	};

}


#endif

