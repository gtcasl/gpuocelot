#include <ocelot/opencl/interface/OpenCLRuntime.h>
#include <ocelot/opencl/interface/Event.h>

#undef REPORT_BASE
#define REPORT_BASE 0

opencl::Event::Event(cl_command_type type, 
	CommandQueue * commandQueue, 
	Context * context,
    cl_uint num_events_in_wait_list,
    const cl_event * event_wait_list,
    cl_event * event): Object(OBJTYPE_EVENT),
	_type(type), _commandQueue(commandQueue), _context(context) {

	report("Creating Event " << this);
	if(event_wait_list == NULL && num_events_in_wait_list > 0)
		throw CL_INVALID_EVENT_WAIT_LIST;

	if(event_wait_list && num_events_in_wait_list == 0)
		throw CL_INVALID_EVENT_WAIT_LIST;

	for(cl_uint i = 0; i < num_events_in_wait_list; i++) {
		if(!event_wait_list[i]->isValidObject(Object::OBJTYPE_EVENT)) {
			_waitList.clear();
			throw CL_INVALID_EVENT_WAIT_LIST;
		}
		event_wait_list[i]->retain();
		_waitList.push_back(event_wait_list[i]);
	}

	if(_commandQueue) //user event does not have commandQueue
		_commandQueue->retain();

	_context->retain();

	if(event) {
		this->retain();
		*event = (cl_event)this;
	}
}

opencl::Event::~Event() {

	report("Delete event " << this);

	if(_commandQueue)
		_commandQueue->release();

	_context->release();

	for(EventList::iterator event = _waitList.begin(); 
		event != _waitList.end(); event++) {
		(*event)->release();
	}
}

void opencl::Event::release() {
	if(Object::release())
		delete this;
}

cl_command_type opencl::Event::type() {
	return _type;
}

bool opencl::Event::isCompleted() {
	return ((_status == CL_COMPLETE) ||
		(_status < 0));
}

bool opencl::Event::hasStatus(cl_int status) {
	return (_status == status);
}

void opencl::Event::setStatus(cl_int status) {
	_status = status;
}

void opencl::Event::getInfo(cl_event_info    param_name,
		size_t           param_value_size,
		void *           param_value,
		size_t *         param_value_size_ret) {

	union infoUnion {
		cl_command_queue cl_command_queue_var;
		cl_context cl_context_var;
		cl_command_type cl_command_type_var;
		cl_int cl_int_var;
	};

	infoUnion info;
	const void * ptr = &info;
	size_t infoLen = 0;

#ifndef ASSIGN_INFO
#define ASSIGN_INFO(field, value) \
do { \
	info.field##_var = value; \
	infoLen = sizeof(field); \
} while(0)
#endif

	switch(param_name) {
		case CL_EVENT_COMMAND_QUEUE:
			ASSIGN_INFO(cl_command_queue, (cl_command_queue)_commandQueue);
			break;

		case CL_EVENT_CONTEXT:
			ASSIGN_INFO(cl_context, (cl_context)_context);
			break;

		case CL_EVENT_COMMAND_TYPE:
			ASSIGN_INFO(cl_command_type, _type);
			break;

		case CL_EVENT_COMMAND_EXECUTION_STATUS:
			ASSIGN_INFO(cl_int, _status);
			break;

		default:
			throw CL_INVALID_VALUE;
			break;
			
	}

	if(param_value && param_value_size < infoLen)
		throw CL_INVALID_VALUE;
	
	if(param_value != 0)
		std::memcpy(param_value, ptr, infoLen);

	if(param_value_size_ret !=0 )
		*param_value_size_ret = infoLen;

}



opencl::ReadWriteBufferEvent::ReadWriteBufferEvent(cl_command_type type,
	CommandQueue * commandQueue,
	BufferObject * buffer,
	cl_bool blocking,
	size_t offset, size_t cb, void * ptr,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) :
	Event(type, commandQueue, 
	commandQueue->context(), num_events_in_wait_list,
	event_wait_list, event),
	_buffer(buffer), _offset(offset),
	_cb(cb), _ptr(ptr) {

	if(offset >= buffer->size() || cb + offset > buffer->size())
		throw CL_INVALID_VALUE;
	
	if(ptr == NULL)
		throw CL_INVALID_VALUE;

	if(!buffer->isAllocatedOnDevice(commandQueue->device()))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	buffer->retain();

	commandQueue->queueEvent(this, blocking);
}

opencl::ReadWriteBufferEvent::~ReadWriteBufferEvent() {

	_buffer->release();
}

void opencl::ReadWriteBufferEvent::execute(Device * device) {
	assertM(device == _commandQueue->device(), "invalid device");

	if(_type == CL_COMMAND_READ_BUFFER)
		_buffer->readOnDevice(device, _offset, _cb, _ptr);
	else  if(_type == CL_COMMAND_WRITE_BUFFER)
		_buffer->writeOnDevice(device, _offset, _cb, _ptr);
	else
		assertM(false, "Invalid read/write buffer command");

}

opencl::KernelEvent::KernelEvent(cl_command_type type,
	CommandQueue * commandQueue,
	Kernel * kernel,
	cl_uint work_dim,
	const size_t *global_work_offset,
	const size_t *   global_work_size,
	const size_t *   local_work_size,
	cl_uint          num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event *       event) :
	Event(type, commandQueue, 
	commandQueue->context(), num_events_in_wait_list,
	event_wait_list, event), _kernel(kernel) {

	kernel->mapParametersOnDevice(commandQueue->device());
	kernel->setConfiguration(work_dim, global_work_offset, global_work_size, local_work_size);
	kernel->retain();

	commandQueue->queueEvent(this, false);	
}

opencl::KernelEvent::~KernelEvent() {

	_kernel->release();

}

void opencl::KernelEvent::execute(Device * device) {
	assertM(device == _commandQueue->device(), "invalid device");
	_kernel->launchOnDevice(device);
}


