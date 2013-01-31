//Ocelot includes
#include <ocelot/opencl/interface/LCLRuntime.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

lcl::LCLRuntime * lcl::LCLRuntime::instance = 0;

static void destroyInstance() {
	if(lcl::LCLRuntime::instance) {
		delete lcl::LCLRuntime::instance;
		lcl::LCLRuntime::instance = 0;
	}
}

lcl::LCLRuntime * lcl::LCLRuntime::get() {

	if(!lcl::LCLRuntime::instance) {
		lcl::LCLRuntime::instance = new LCLRuntime;

		std::atexit(destroyInstance);
	}

	return lcl::LCLRuntime::instance;
}

lcl::LCLRuntime::LCLRuntime() {
}

lcl::LCLRuntime::~LCLRuntime() {
}

lcl_vbuf lcl::LCLRuntime::lclCreateVirtualBuffer(lcl_context context,
	size_t size,
	lcl_int * errcode_ret) {

	VirtualBuffer * vBuffer = NULL;

	lcl_int err = CL_SUCCESS;

	try {
		vBuffer = new VirtualBuffer(context, size);
	}
	catch(lcl_int exception) {
		err = exception;
	}
	catch(...) {
		err = CL_OUT_OF_HOST_MEMORY;
	}

	if(errcode_ret)
		*errcode_ret = err;

	return (lcl_vbuf)vBuffer;
}
