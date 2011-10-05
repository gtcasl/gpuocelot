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
	std::cout << "I am OpenCL" << std::endl;
	if (!opencl::OpenCLRuntimeInterface::instance) {
		if (api::OcelotConfiguration::get().opencl.implementation
			== "OpenCLRuntime") {
			opencl::OpenCLRuntimeInterface::instance = new OpenCLRuntime;

			//Handle configuration later, now don't bother
//			opencl::OpenCLRuntimeInterface::instance->ocelotRuntime.configure(
//				api::OcelotConfiguration::get());
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

cl_int opencl::OpenCLRuntimeInterface::clGetPlatformIDs(
	cl_uint num_entries, 
	cl_platform_id * platforms, 
	cl_uint * num_platforms) {
	assertM(false , "unimplemented");
	return CL_UNIMPLEMENTED;
}

cl_int opencl::OpenCLRuntimeInterface::clGetDeviceIDs(
	cl_platform_id platform, 
	cl_device_type device_type, 
	cl_uint num_entries,
	cl_device_id * devices,
	cl_uint * num_devices) {
	assertM(false, "unimplemented");
	return CL_UNIMPLEMENTED;
}
			


