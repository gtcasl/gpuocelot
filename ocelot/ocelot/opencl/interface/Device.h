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
	
		typedef api::OcelotConfiguration config;

		typedef std::list< Device * > DeviceList;	

		typedef enum {
			DEVICE_NVIDIA_GPU,
			DEVICE_EMULATED,
			DEVICE_MULTICORE_CPU,
			DEVICE_AMD_GPU,
			DEVICE_REMOTE
		}deviceT;

	public:
		Device(executive::Device * device, cl_device_type type, 
			Platform *p, std::string & vendor, 
			Device * parentDevice, const cl_device_partition_property * partitionProp);
		~Device();

	public:
		//Get devices of one specific type
		static void getDevices(cl_platform_id platform, cl_device_type type, cl_uint num_entries,
		    cl_device_id * devices, cl_uint * num_devices);

		//Set limit worker thread
		static void limitWorkerThreadForAll(unsigned int limit);

		//Unregister modules
		static void unregisterModuleForAll(const std::string &name);

		//Set Optimization level for all devices
		static void setOptimizationLevelForAll(translator::Translator::OptimizationLevel l);

	public:
		void release();

		//Get info
		void getInfo(cl_device_info param_name,
		    size_t param_value_size,
		    void * param_value,
		    size_t * param_value_size_ret);

		//Get name
		const char * name();

		//Get register file size per block
		const size_t regSize();

		//Compare device type
		const bool isType(cl_device_type type) const;

		//Load module
		void load(ir::Module * module);

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

		//create sub devices
		void createSubDevices(const cl_device_partition_property * properties,
			cl_uint num_devices, cl_device_id * out_devices, cl_uint * num_devices_ret);

	private:

		//Avaialbe device list
		static DeviceList _deviceList;

		//Device loaded flag
		static bool _loaded;
	
		//! The minimum supoported compute capability
		static int _computeCapability;
		
		//! The device flags
		static unsigned int _flags;
		
		//Device count
		static cl_uint _deviceCount;

		//Executive device
		executive::Device * _exeDevice;

		//Device type
		cl_device_type _type;

		//vendor id, use device count id instead
		cl_uint _vendorId;

		//vendor name
		std::string _vendor;
		
		//Associated platform
		Platform * _platform;

		//A semi-colon separated list of built-in kernels
		std::string _builtInKernels;

		//Parent device for a subdevice
		Device * _parentDevice;

		//device partition properties
		cl_device_partition_property * _partitionProp;

		//device parition properties size (including terminator 0)
		size_t _partitionPropSize;

		//Compare Platform
		const inline bool _hasPlatform(cl_platform_id platform) const;

		//If valid device type
		static inline const bool _isValidType(const cl_device_type type);

		//enumerate available devices
		static void _enumerateDevices(cl_platform_id platform);

	};

}

#endif
