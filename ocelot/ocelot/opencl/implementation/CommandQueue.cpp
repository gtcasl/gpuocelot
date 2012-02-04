#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/CommandQueue.h>

opencl::CommandQueue::CommandQueue(Context * context, 
	executive::Device * device, 
	cl_command_queue_properties properties, 
	unsigned int stream)
	:_context(context), _device(device), _properties(properties), _stream(stream) {
}

opencl::Context * opencl::CommandQueue::context() {
	return _context;
}

executive::Device * opencl::CommandQueue::device() {
	return _device;
}

cl_command_queue_properties opencl::CommandQueue::properties() {
	return _properties;
}

unsigned int opencl::CommandQueue::stream() {
	return _stream;
}
