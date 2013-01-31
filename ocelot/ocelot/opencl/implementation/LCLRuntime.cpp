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

		
bool lcl::LCLRuntime::isValidVirtualBuffer(VirtualBuffer * vBuf) {
	if(std::find(_vBuffers.begin(), _vBuffers.end(), vBuf) != _vBuffers.end())
		return true;
	else
		return false;
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

lcl_int lcl::LCLRuntime::lclWriteVirtualBuffer(lcl_command_queue command_queue,
				lcl_vbuf virtual_buffer,
				lcl_bool blocking_write,
				size_t offset,
				size_t size,
				const void * ptr,
				lcl_uint num_events_in_wait_list,
				const lcl_event * event_wait_list,
				lcl_event * event) {


	cl_int result = CL_SUCCESS;

	try {
		VirtualBuffer * vBuf = (VirtualBuffer *)virtual_buffer;
	
		if(!isValidVirtualBuffer(vBuf))
			throw LCL_INVALID_VIRTUAL_BUFFER;

		vBuf->write(command_queue, blocking_write, 
					offset, size, ptr,
					num_events_in_wait_list,
					event_wait_list, event);

	}
	catch(lcl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	return result;
}


