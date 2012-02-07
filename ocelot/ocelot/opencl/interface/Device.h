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
		Device(executive::Device * device, 
			cl_device_type type, Platform *p);
		~Device();

		//Get info
		cl_int getInfo(cl_device_info param_name,
		    size_t param_value_size,
		    void * param_value,
		    size_t * param_value_size_ret);

		//Get Platform
		Platform * platform();

		//Get device type
		const cl_device_type type() const;

		//Executive device
		executive::Device * exeDevice;

	private:

		//Device count
		static cl_uint _deviceCount;

		//Device type
		cl_device_type _type;

		//vendor id, use device count id instead
		cl_uint _vendorId;
		
		//Associated platform
		Platform * _platform;

		//A semi-colon separated list of built-in kernels
		std::string _builtInKernels;

	};
}


#endif
