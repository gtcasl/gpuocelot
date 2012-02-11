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

	if(!_context->isValidDevice(device))//Not found
		throw CL_INVALID_DEVICE;

	if(properties > (CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE |
					CL_QUEUE_PROFILING_ENABLE))
		throw CL_INVALID_VALUE;
	
	if((properties & CL_QUEUE_OUT_OF_ORDER_EXEC_MODE_ENABLE) 
		||(properties & CL_QUEUE_PROFILING_ENABLE)) {
		assertM(false, "unimplemented queue properties");
		throw CL_UNIMPLEMENTED;
	}
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

