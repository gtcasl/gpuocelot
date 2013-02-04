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
		_vBuffers.push_back(vBuffer);
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

lcl_int lcl::LCLRuntime::lclEnqueueReadVirtualBuffer(lcl_command_queue command_queue,
				lcl_vbuf virtual_buffer,
				lcl_bool blocking_write,
				size_t offset,
				size_t size,
				void * ptr,
				lcl_uint num_events_in_wait_list,
				const lcl_event * event_wait_list,
				lcl_event * event) {


	lcl_int result = CL_SUCCESS;

	try {
		VirtualBuffer * vBuf = (VirtualBuffer *)virtual_buffer;
	
		if(!isValidVirtualBuffer(vBuf))
			throw LCL_INVALID_VIRTUAL_BUFFER;

		vBuf->read(command_queue, blocking_write, 
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

lcl_int lcl::LCLRuntime::lclEnqueueWriteVirtualBuffer(lcl_command_queue command_queue,
				lcl_vbuf virtual_buffer,
				lcl_bool blocking_write,
				size_t offset,
				size_t size,
				const void * ptr,
				lcl_uint num_events_in_wait_list,
				const lcl_event * event_wait_list,
				lcl_event * event) {


	lcl_int result = CL_SUCCESS;

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

lcl_int lcl::LCLRuntime::lclSetKernelArg(lcl_kernel kernel,
					lcl_uint arg_index,
					size_t arg_size,
					const void * arg_value) {

	lcl_int result = CL_SUCCESS;

	try {

		if(arg_size == sizeof(lcl_vbuf)) {//a possible virtual buffer

			VirtualBuffer * vBuf = (VirtualBuffer *)(*((lcl_vbuf *)arg_value));
			if(isValidVirtualBuffer(vBuf)) {//Yes, it is virtual buffer!
				report("Find virtual buffer for kernel argument");

				vBuf->setToKernelArg(kernel, arg_index);
			}
			else { // call regular clSetKernelArg
				result = clSetKernelArg(kernel, arg_index, arg_size, arg_value);
			}
		}
		else { //call regular clSetKernelArg
			result = clSetKernelArg(kernel, arg_index, arg_size, arg_value);
		}

	}
	catch(lcl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	return result;
}

lcl_int lcl::LCLRuntime::lclEnqueueNDRangeKernel(lcl_command_queue command_queue,
					lcl_kernel kernel,
					lcl_uint work_dim,
					const size_t * global_work_offset,
					const size_t * global_work_size,
					const size_t * local_work_size,
					lcl_uint num_events_in_wait_list,
					const lcl_event * event_wait_list,
					lcl_event * event) {

	lcl_int result = CL_SUCCESS;

	try {
		result = clEnqueueNDRangeKernel(command_queue, kernel, work_dim,
					global_work_offset, global_work_size, local_work_size,
					num_events_in_wait_list, event_wait_list, event);
	}
	catch(lcl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	return result;

}

lcl_int lcl::LCLRuntime::lclFinish(lcl_command_queue command_queue) {

	lcl_int result = CL_SUCCESS;

	try {
		result = clFinish(command_queue);
	}
	catch(lcl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	return result;
}

lcl_int lcl::LCLRuntime::lclReleaseVirtualBuffer(lcl_vbuf virtual_buffer) {
	lcl_int result = CL_SUCCESS;

	try {
		VirtualBuffer * vBuffer = (VirtualBuffer *)virtual_buffer;
		if(!isValidVirtualBuffer(vBuffer))
			throw LCL_INVALID_VIRTUAL_BUFFER;

		vBuffer->release();

		_vBuffers.remove(vBuffer);

		delete vBuffer;
	}
	catch(lcl_int exception) {
		result = exception;
	}
	catch(...) {
		result = CL_OUT_OF_HOST_MEMORY;
	}

	return result;
}
