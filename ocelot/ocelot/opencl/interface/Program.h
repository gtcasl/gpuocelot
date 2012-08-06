#ifndef OCELOT_OPENCL_PROGRAM_H_INCLUDED
#define OCELOT_OPENCL_PROGRAM_H_INCLUDED

// C++ libs
#include <string>
#include <set>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Kernel.h>
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/Object.h>

namespace opencl {

	class Kernel;

	//! programs created in OpenCL runtime	
	class Program : public Object {

	public:
		typedef enum {
			PROGRAM_SOURCE,
			PROGRAM_BINARY,
			PROGRAM_BUILTIN
		}programT;

		typedef std::list < Program * > ProgramList;
		typedef std::list < Kernel * > KernelList;

	public:
		Program(Context * context, cl_uint count, const char ** strings, 
			const size_t * lengths, programT type);

		Program(Context * context, 
		    cl_uint num_devices, 
		    const cl_device_id * device_list,
		    const size_t * lengths, 
		    const unsigned char ** binaries, 
		    cl_int * binary_status, 
		    programT type);

		Program(Context * context, 
				cl_uint num_devices,
				const cl_device_id * device_list,
				const char * kernel_names);

		~Program();	

	public:

		void release();

		//!validate context
		bool isValidContext(Context * context);

		//! get context
		Context * getContext();

		//! check if devices are valid
		bool setupDevices(cl_uint num_devices, const cl_device_id * device_list);

		//! build program
		void build(const char * options,
			void (CL_CALLBACK * pfn_notify)(cl_program, void *),
			void * user_data);

		//! get info
		void getInfo(cl_program_info param_name,
			size_t param_value_size,
			void * param_value,
			size_t * param_value_size_ret);
	
		//! create kernels
		Kernel * createKernel(const char * kernelName);	
		
		//! create all kernels in the program
		void createAllKernels(cl_uint num_kernels,
		        cl_kernel * kernels,
		        cl_uint * num_kernels_ret);

		//! remove kernel
		void removeKernel(Kernel * kernel);

	private:
		//! program id
		static unsigned int _id;


	private:
		typedef enum {
			STATUS_UNBUILT,
			STATUS_COMPILED,
			STATUS_EXECUTABLE
		}statusT;


		typedef struct {
			//program build status
			statusT _status;

			//binary code, could be compiled, library, or executable
			std::string _binary;

			//module name used by ocelot
			std::string _moduleName;

			//ir module used by ocelot
			ir::Module * _module;
		}deviceBuiltInfoT;


		//type
		programT _type;

		//name		
		std::string _name;

		//! associated context
		Context * _context;

		//! setup devices
		Device::DeviceList _buildDevices;

		//! source code of program
		std::string _source;

		//! kernels
		KernelList _kernels;

		//!built information for devices
		std::map <Device *, deviceBuiltInfoT> _deviceBuiltInfo;

	private:
		//! load ptx through backdoor
		std::string _loadBackDoor();

		//! check if built for a device
		bool _isBuiltOnDevice(Device * device);

		//! check if built for a device
		bool _isAllBuilt();

		//! check if module is declared on a device
		bool _hasModuleOnDevice(Device * device, std::string moduleName);

		//! check if binary is loaded on a device
		bool _hasBinaryOnDevice(Device * device);

		//! load binary on device
		void _loadBinaryOnDevice(Device * device, const size_t length, 
								const char * binary);

		//! build program on a device
		void _buildOnDevice(Device * device, std::string backdoorBinary = "");

		//! get binary sizes
		char * _getBinarySizes(size_t & bufferLen);

		//! get binaries
		char * _getBinaries(size_t & bufferLen);

		//! check if all module has the kernel
		bool _hasKernelAll(const char * kernelName);

	};

}

#endif 
