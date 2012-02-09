#ifndef OCELOT_OPENCL_DEVICE_H_INCLUDED
#define OCELOT_OPENCL_DEVICE_H_INCLUDED

// C++ libs

// Ocelot libs
#include <ocelot/executive/interface/Device.h>
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Platform.h>
#include <ocelot/opencl/interface/Object.h>

namespace opencl {


	class Device : public Object{
	public:
	
		typedef std::list< Device * > DeviceList;	

		typedef enum {
			DEVICE_NVIDIA_GPU,
			DEVICE_EMULATED,
			DEVICE_MULTICORE_CPU,
			DEVICE_AMD_GPU,
			DEVICE_REMOTE
		}deviceT;

	public:
		Device(executive::Device * device, 
			cl_device_type type, Platform *p);
		~Device();

	public:
		//Create a specific device
		static void createDevices(Platform * platform, deviceT device, 
			unsigned int flags, int compuateCapability, int workerThreadLimit = 0);

		//Get devices of one specific type
		static cl_uint getDevices(cl_platform_id platform, cl_device_type type, cl_uint num_entries,
		    cl_device_id * devices, cl_uint * num_devices);

		//Set limit worker thread
		static void limitWorkerThreadForAll(unsigned int limit);

		//Unregister modules
		static void unregisterModuleForAll(const std::string &name);

		//Set Optimization level for all devices
		static void setOptimizationLevelForAll(translator::Translator::OptimizationLevel l);

	public:
		//Get info
		cl_int getInfo(cl_device_info param_name,
		    size_t param_value_size,
		    void * param_value,
		    size_t * param_value_size_ret);

		//Get name
		const char * name();

		//Load module
		void load(const ir::Module * module);

		//Unload module
		void unload(const std::string & name); 	
		
		//Launch kernel
		void launch(const std::string& module, 
				const std::string& kernel, const ir::Dim3& grid, 
				const ir::Dim3& block, size_t sharedMemory, 
				const void* argumentBlock, size_t argumentBlockSize, 
				const trace::TraceGeneratorVector& 
				traceGenerators = trace::TraceGeneratorVector(),
				const ir::ExternalFunctionSet* externals = 0);

		//Set optimization level
		void setOptimizationLevel(
				translator::Translator::OptimizationLevel level);
			
		//Allocate memory
		void * allocate(size_t size);

		//Read memory
		bool read(const void * src, void * host, size_t offset, size_t size);

		//Write memory
		bool write(void * dest, const void * host, size_t offset, size_t size);

	private:

		//Avaialbe device list
		static DeviceList _deviceList;

		//Device loaded flag
		static bool _loaded;

		//Device count
		static cl_uint _deviceCount;

		//Executive device
		executive::Device * _exeDevice;

		//Device type
		cl_device_type _type;

		//vendor id, use device count id instead
		cl_uint _vendorId;
		
		//Associated platform
		Platform * _platform;

		//A semi-colon separated list of built-in kernels
		std::string _builtInKernels;

		//Compare Platform
		const bool _hasPlatform(cl_platform_id platform) const;

		//Compare device type
		const bool _isType(const cl_device_type type) const;



	};
}


#endif
