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

//	public:
		//! \brief gets the Ocelot runtime object
//		const ocelot::OcelotRuntime & ocelot() const;

//	protected:
		//! \brief Ocelot runtime object containing state related to Ocelot
//		ocelot::OcelotRuntime ocelotRuntime;
		
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

