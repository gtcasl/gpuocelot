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
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Kernel.h>
#include <ocelot/opencl/interface/MemoryObject.h>
#include <ocelot/opencl/interface/CommandQueue.h>
#include <ocelot/opencl/interface/Program.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/Platform.h>
#include <ocelot/opencl/interface/Object.h>
#include <ocelot/ir/interface/ExternalFunctionSet.h>

// Hydrazine includes
#include <hydrazine/implementation/Timer.h>

// Forward Declarations

struct _cl_platform_id : public opencl::Platform {
};

struct _cl_context : public opencl::Context {
};

struct _cl_program : public opencl::Program {
};

struct _cl_command_queue : public opencl::CommandQueue {
};

struct _cl_kernel : public opencl::Kernel {
};

struct _cl_mem : public opencl::MemoryObject {
};

struct _cl_device_id : public opencl::Device {
};

namespace transforms { class Pass; }

namespace opencl {

	/*!	\brief Set of thread ids */

//	typedef std::map< unsigned int, char * > PointerMap;
//	typedef std::map< unsigned int, size_t > SizeMap;

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


//	typedef std::vector< FatBinaryContext > FatBinaryVector;
//	typedef std::map< void*, RegisteredGlobal > RegisteredGlobalMap;
//	typedef std::map< void*, RegisteredTexture > RegisteredTextureMap;
//	typedef std::map< void*, Dimension > DimensionMap;
//	typedef std::map< std::string, ir::Module > ModuleMap;
//	typedef std::unordered_map<unsigned int, void*> GLBufferMap;

	////////////////////////////////////////////////////////////////////////////
	/*! OpenCL runtime context */
	class OpenCLRuntime: public OpenCLRuntimeInterface {


	private:
		typedef Device::DeviceList DeviceList;

		/*! \brief Memory copy */
		//void _memcpy(void* dst, const void* src, size_t count, 
		//	enum openclMemcpyKind kind);
		/*! \brief Report a memory error and throw an exception */
		//void _memoryError(const void* address, size_t count, 
		//	const std::string& function = "");		
		/*! \brief Create platform */
		void _enumeratePlatforms(cl_uint num_entries, 
			    cl_platform_id * platforms, 
			    cl_uint * num_platforms);
		/*! \brief Create devices if they do not already exist */
		void _enumerateDevices(cl_platform_id platform,    
			cl_device_type device_type, 
		    cl_uint num_entries,
	    	cl_device_id * devices,
    		cl_uint * num_devices);
		//! \brief acquires mutex and locks the runtime
		void _lock();
		//! \brief releases mutex
		void _unlock();
		//! \brief sets the last error state for the OpenCLRuntime object
		//cl_int _setLastError(cl_int result);
		//! \brief Bind the current thread to a device context
		//Context& _bind();
		//! \brief Unbind the current thread
		//void _unbind();
		//! \brief Lock the mutex and bind the the thread
		//void _acquire();
		/*! \brief Unbind the thread and unlock the mutex */
		//void _release();
		//! \brief gets the current device for the current thread
		//executive::Device& _getDevice();
		//! \brief returns an Ocelot-formatted error message
		//std::string _formatError(const std::string & message);
		// Get the current thread, create it if it doesn't exist
		Context * _createContext(Platform *, cl_uint, const cl_device_id *);
		// Load module and register it with devices
		//void _registerModule(ModuleMap::iterator module, Device *);
		// Load module and register it with devices
		//void _registerModule(const std::string& name, Device *);
		// Load all modules and register them with all devices
		//void _registerAllModules(Device *);
		// Map kernel parameters for device
		//void _mapKernelParameters(Kernel & kernel, Device *);

	private:
		//! locking object for opencl runtime
		boost::mutex _mutex;
		
		//! There is a thread in execute
		//bool _inExecute;
		
		//! locking object for access to the runtime from worker threads
		//boost::mutex _executingMutex;
		
		//! Registered modules
		//ModuleMap _modules;

		//! List of contexts
		//ContextList _contexts;
		
		//! List of kernels
		//KernelList _kernels;

		//! List of Memory objects
		//MemoryObjectList _memories;

		//! List of command queues;
		//CommandQueueList _queues;
		
		//! maps texture symbols to module-textures
		//RegisteredTextureMap _textures;

		//! maps symbol pointers onto their device names
		//RegisteredGlobalMap _globals;
		
		//! The dimensions for multi-dimensional allocations
		//DimensionMap _dimensions;
		
		//! Registered opengl buffers and mapping to graphics resources
		//GLBufferMap _buffers;
		
		//! Have the devices been loaded?
		bool _devicesLoaded;
		
		//! the next symbol for dynamically registered kernels
		//int _nextSymbol;
		
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
//		virtual void limitWorkerThreads( unsigned int limit = 1024 );
//		virtual void registerPTXModule(std::istream& stream, 
//			const std::string& name);
//		virtual void registerTexture(const void* texref,
//			const std::string& moduleName,
//			const std::string& textureName, bool normalize);
//		virtual void clearErrors();
//		virtual void reset();
//		virtual ocelot::PointerMap contextSwitch( 
//			unsigned int destinationDevice, unsigned int sourceDevice);
//		virtual void unregisterModule(const std::string& name);
//		virtual void launch(const std::string& moduleName, 
//			const std::string& kernelName);
//		virtual void setOptimizationLevel(
//			translator::Translator::OptimizationLevel l);
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
		virtual cl_int clSetKernelArg(cl_kernel kernel,
					cl_uint arg_index,
					size_t arg_size,
					const void * arg_value);
		virtual cl_int clEnqueueNDRangeKernel(cl_command_queue command_queue,
					cl_kernel kernel,
					cl_uint work_dim,
					const size_t * global_work_offset,
					const size_t * global_work_size,
					const size_t * local_work_size,
					cl_uint num_events_in_wait_list,
					const cl_event * event_wait_list,
					cl_event * event);



	};

}


#endif

