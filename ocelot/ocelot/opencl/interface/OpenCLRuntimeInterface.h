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




	};
}
#endif

