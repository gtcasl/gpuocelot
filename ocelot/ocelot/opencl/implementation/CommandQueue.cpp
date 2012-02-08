#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/CommandQueue.h>
#include <ocelot/opencl/interface/Object.h>

opencl::CommandQueue::CommandQueue(Context * context, 
	Device * device, 
	cl_command_queue_properties properties)
	:Object(OBJTYPE_COMMANDQUEUE),
	_context(context), _device(device), _properties(properties) {

	_context->retain();
	_device->retain();
}

opencl::CommandQueue::~CommandQueue() {
	if(_context->release())
		delete _context;

	if(_device->release())
		delete _device;
}

opencl::Context * opencl::CommandQueue::context() {
	return _context;
}

opencl::Device * opencl::CommandQueue::device() {
	return _device;
}

cl_command_queue_properties opencl::CommandQueue::properties() {
	return _properties;
}

