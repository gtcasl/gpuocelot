#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/CommandQueue.h>

opencl::CommandQueue::CommandQueue(cl_context context, cl_device_id device, cl_command_queue_properties properties, unsigned int stream)
	:_context(context), _device(device), _properties(properties), _stream(stream) {
}

const cl_context opencl::CommandQueue::context() const {
	return _context;
}

const cl_device_id opencl::CommandQueue::device() const {
	return _device;
}

const cl_command_queue_properties opencl::CommandQueue::properties() const {
	return _properties;
}

const unsigned int opencl::CommandQueue::stream() const {
	return _stream;
}
