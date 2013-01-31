//Ocelot includes
#include <ocelot/opencl/interface/VirtualBuffer.h>

// Hydrazine includes
#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

lcl::VirtualBuffer::VirtualBuffer(lcl_context context, size_t size) :
	_size(size) {

	report("Create Virtual Buffer using default memory flag \
		CL_MEM_READ_WRITE");

	cl_int status;

	_phyBuffer = clCreateBuffer(context, CL_MEM_READ_WRITE, size, NULL, &status);

	if(status != CL_SUCCESS)
		throw status;

	_size = size;
}

lcl::VirtualBuffer::~VirtualBuffer() {
	clReleaseMemObject(_phyBuffer);
}
