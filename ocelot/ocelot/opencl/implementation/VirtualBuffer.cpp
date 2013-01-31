//Ocelot includes
#include <ocelot/opencl/interface/VirtualBuffer.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

lcl::VirtualBuffer::VirtualBuffer(lcl_context context, size_t size) :
	_size(size) {

	report("Create Virtual Buffer using default memory flag \
CL_MEM_READ_WRITE, size = " << size);

	cl_int status;

	_phyBuffer = clCreateBuffer(context, CL_MEM_READ_WRITE, size, NULL, &status);

	if(status != CL_SUCCESS)
		throw status;

	_size = size;
}

lcl::VirtualBuffer::~VirtualBuffer() {
}

void lcl::VirtualBuffer::write(lcl_command_queue command_queue,
							lcl_bool blocking,
							size_t offset,
							size_t size,
							const void * ptr,
							lcl_uint num_events_in_wait_list,
							const lcl_event * event_wait_list,
							lcl_event * event) {

	cl_int status = clEnqueueWriteBuffer(command_queue, _phyBuffer,
						blocking, offset, size, ptr, 
						num_events_in_wait_list,
						event_wait_list,
						event);

	if(status != CL_SUCCESS)
		throw status;
}
