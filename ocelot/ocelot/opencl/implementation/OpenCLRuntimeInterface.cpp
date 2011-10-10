// C std lib includes
#include <assert.h>

// C++ std lib includes

// Ocelot includes
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/OpenCLRuntime.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0


////////////////////////////////////////////////////////////////////////////////

opencl::OpenCLRuntimeInterface * opencl::OpenCLRuntimeInterface::instance = 0;

static void destroyInstance() {
	if (opencl::OpenCLRuntimeInterface::instance) {
		delete opencl::OpenCLRuntimeInterface::instance;
		opencl::OpenCLRuntimeInterface::instance = 0;
	}
}

////////////////////////////////////////////////////////////////////////////////

opencl::OpenCLRuntimeInterface * opencl::OpenCLRuntimeInterface::get() {
	if (!opencl::OpenCLRuntimeInterface::instance) {
		if (api::OcelotConfiguration::get().opencl.implementation
			== "OpenCLRuntime") {
			opencl::OpenCLRuntimeInterface::instance = new OpenCLRuntime;

			//Handle configuration later, now don't bother
			opencl::OpenCLRuntimeInterface::instance->ocelotRuntime.configure(
				api::OcelotConfiguration::get());
			std::atexit(destroyInstance);
		}
		else {
			assertM(false,"no OpenCL runtime implementation "
				"matches what is requested");
		}
	}
	return opencl::OpenCLRuntimeInterface::instance;
}

opencl::OpenCLRuntimeInterface::OpenCLRuntimeInterface() {

}

opencl::OpenCLRuntimeInterface::~OpenCLRuntimeInterface() {

}

////////////////////////////////////////////////////////////////////////////////

cl_int opencl::OpenCLRuntimeInterface::clGetPlatformIDs(cl_uint num_entries, 
	cl_platform_id * platforms, 
	cl_uint * num_platforms) {
	assertM(false , "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetPlatformInfo(cl_platform_id platform, 
                  cl_platform_info param_name,
                  size_t param_value_size, 
                  void * param_value,
                  size_t * param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetDeviceIDs(cl_platform_id platform, 
	cl_device_type device_type, 
	cl_uint num_entries,
	cl_device_id * devices,
	cl_uint * num_devices) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}
			
cl_int opencl::OpenCLRuntimeInterface::clGetDeviceInfo(cl_device_id device,
	cl_device_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_context opencl::OpenCLRuntimeInterface::clCreateContext(const cl_context_properties * properties,
	cl_uint num_devices,
	const cl_device_id * devices,
	void (CL_CALLBACK * pfn_notify)(const char *, const void *, size_t, void *),
	void * user_data,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	*errcode_ret = CL_UNIMPLEMENTED;
	return NULL;
}

cl_command_queue opencl::OpenCLRuntimeInterface::clCreateCommandQueue(cl_context context, 
	cl_device_id device, 
	cl_command_queue_properties properties,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	*errcode_ret = CL_UNIMPLEMENTED;
	return NULL;
}

cl_program opencl::OpenCLRuntimeInterface::clCreateProgramWithSource(cl_context context,
	cl_uint count,
	const char ** strings,
	const size_t * lengths,
	cl_int * errcode_ret) {
	assertM(false, "unimplemented");
	*errcode_ret = CL_UNIMPLEMENTED;
	return NULL;
}

cl_int opencl::OpenCLRuntimeInterface::clBuildProgram(cl_program program,
	cl_uint num_devices,
	const cl_device_id * device_list,
	const char * options, 
	void (CL_CALLBACK * pfn_notify)(cl_program, void *),
	void * user_data) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}


