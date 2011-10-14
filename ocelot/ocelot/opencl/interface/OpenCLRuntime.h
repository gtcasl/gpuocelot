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
#include <ocelot/opencl/interface/MemoryObject.h>
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
	
	typedef std::vector< int > IndexVector;
	typedef std::vector< unsigned int > SizeVector;

	typedef std::set< int > IndexSet;

	//! references a kernel registered to OpenCL runtime
	class RegisteredKernel {
	public:
		RegisteredKernel(const std::string& kernel, const int program, const void * context);

	public:
		//! name of kernel
		const std::string kernel;

		//! associated program
		const int program;

		//! associated context
		const void * context;
	};
	
	typedef std::vector< RegisteredKernel * > RegisteredKernelVector;

	//! programs created in OpenCL runtime	
	class Program {
	private:
		//! program id
		static unsigned int _id;

	public:
		Program(const std::string & source, const void * context);

	public:
		std::string name;
	
		//! ptx modules associated with device id	
		std::map <int, std::string> ptxModule;

		//! ptx code associated with device id
		std::map <int, std::string> ptxCode;
		
		//! source code of program
		std::string source;

		//! kernels
		IndexSet kernels;

		//! get build status
		bool built;

		//! associated context
		const void * context;

	};
	
	typedef std::vector< Program * > ProgramVector;
	
	/*! Host thread OpenCL context consists of these */
	class HostThreadContext {	
	public:
		//! index of selected device
		executive::Device * selectedDevice;
		
		//! set of valid device indices
		IndexSet validDevices;

		//! set of valid programs
		IndexSet validPrograms;

		//! set of valid buffer objects
		IndexSet validBuffers;
	
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
	
	typedef std::map<boost::thread::id, HostThreadContext *> HostThreadContextMap;

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


	typedef std::vector< BufferObject * > BufferObjectVector;
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
		//! \brief create program binary
		Program & _createProgramSource(const std::string & source);
		//! \brief create program binary
		Program & _createProgramBinary(const std::string & binary);
		// Load module and register it with devices
		void _registerModule(ModuleMap::iterator module, int device);
		// Load module and register it with devices
		void _registerModule(const std::string& name, int device);
		// Load all modules and register them with all devices
		void _registerAllModules(int device);

	private:
		//! locking object for opencl runtime
		boost::mutex _mutex;
		
		//! There is a thread in execute
		bool _inExecute;
		
		//! locking object for access to the runtime from worker threads
		boost::mutex _executingMutex;
		
		//! Registered modules
		ModuleMap _modules;

		//! created programs
		ProgramVector _programs;
		
		//! map of pthreads to thread contexts
		HostThreadContextMap _threads;
		
		//! vectors of kernels
		RegisteredKernelVector _kernels;

		//! vectors of buffer objects
		BufferObjectVector _buffers;
		
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
		executive::Device * _selectedDevice;
		
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
		virtual cl_int clGetPlatformInfo(cl_platform_id platform, 
                  cl_platform_info param_name,
                  size_t param_value_size, 
                  void * param_value,
                  size_t * param_value_size_ret);
		virtual cl_int clGetDeviceIDs(cl_platform_id platform,
					cl_device_type device_type,
					cl_uint num_entries,
					cl_device_id * devices,
					cl_uint * num_devices);
		virtual cl_int clGetDeviceInfo(cl_device_id device,
			    	cl_device_info param_name,
				    size_t param_value_size,
					void * param_value,
				    size_t * param_value_size_ret);
		virtual cl_context clCreateContext(const cl_context_properties * properties,
				    cl_uint num_devices,
				    const cl_device_id * devices,
				    void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
				    void * user_data,
				    cl_int * errcode_ret);
		virtual cl_command_queue clCreateCommandQueue(cl_context context, 
				    cl_device_id device, 
				    cl_command_queue_properties properties,
				    cl_int * errcode_ret);
		virtual cl_program clCreateProgramWithSource(cl_context context,
					cl_uint count,
					const char ** strings,
					const size_t * lengths,
					cl_int * errcode_ret);
		virtual cl_int clBuildProgram(cl_program program,
					cl_uint num_devices,
					const cl_device_id * device_list,
					const char * options, 
					void (CL_CALLBACK * pfn_notify)(cl_program, void *),
					void * user_data);
		virtual cl_int clGetProgramInfo(cl_program program,
					cl_program_info param_name,
					size_t param_value_size,
					void * param_value,
					size_t * param_value_size_ret);
		virtual cl_kernel clCreateKernel(cl_program program,
					const char * kernel_name,
					cl_int * errcode_ret);
		virtual cl_mem clCreateBuffer(cl_context context,
					cl_mem_flags flags,
					size_t size,
					void * host_ptr,
					cl_int * errcode_ret);
		virtual cl_int clEnqueueReadBuffer(cl_command_queue command_queue,
					cl_mem buffer,
					cl_bool blocking_read,
					size_t offset,
					size_t cb, 
					void * ptr,
					cl_uint num_events_in_wait_list,
					const cl_event * event_wait_list,
					cl_event * event);
		virtual cl_int clEnqueueWriteBuffer(cl_command_queue command_queue,
					cl_mem buffer,
					cl_bool blocking_write,
					size_t offset,
					size_t cb, 
					const void * ptr,
					cl_uint num_events_in_wait_list,
					const cl_event * event_wait_list,
					cl_event * event);




	};

}


#endif

