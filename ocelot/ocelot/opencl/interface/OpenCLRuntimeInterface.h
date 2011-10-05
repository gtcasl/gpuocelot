#ifndef OCELOT_OPENCL_RUNTIME_INTERFACE_H_INCLUDED
#define OCELOT_OPENCL_RUNTIME_INTERFACE_H_INCLUDED

#include <ocelot/api/interface/ocelot.h>

#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/api/interface/OcelotRuntime.h>

#include <ocelot/opencl/interface/opencl_runtime.h>
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/translator/interface/Translator.h>
namespace opencl {
	/*!
		Singleton object called directly by OpenCL Runtime API wrapper 
			- on instantiation, selects appropriate OpenCL Runtime 
			implementation and dispatches calls
	*/
	class OpenCLRuntimeInterface {
	public:
		/* singleton accessors */
		static OpenCLRuntimeInterface *instance;
		
		static OpenCLRuntimeInterface *get();
		
		OpenCLRuntimeInterface();
		
		virtual ~OpenCLRuntimeInterface();

	public:
		//! \brief gets the Ocelot runtime object
		const ocelot::OcelotRuntime & ocelot() const;

	protected:
		//! \brief Ocelot runtime object containing state related to Ocelot
		ocelot::OcelotRuntime ocelotRuntime;
		
	public:
		//! \brief Now just for test
		virtual cl_int clGetPlatformIDs(cl_uint num_entries, 
										cl_platform_id * platforms, 
										cl_uint * num_platforms);
		virtual cl_int clGetDeviceIDs(cl_platform_id platform,
							  cl_device_type device_type,
							  cl_uint num_entries,
							  cl_device_id * devices,
							  cl_uint * num_devices);

	};
}
#endif

