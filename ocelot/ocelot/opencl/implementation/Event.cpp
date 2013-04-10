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
	_type(type), _commandQueue(commandQueue), _context(context), 
	_eventNotify(NULL), _userData(NULL) {

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

}

void opencl::Event::release() {
	if(Object::release()) {
		if(_commandQueue)
			_commandQueue->release();

		_context->release();

		for(EventList::iterator event = _waitList.begin(); 
			event != _waitList.end(); event++) {
			(*event)->release();
		}

		delete this;
	}
}

void opencl::Event::lockEvent() {
	_complete.lock();
}

void opencl::Event::unlockEvent() {
	_complete.unlock();
}

void opencl::Event::waitToComplete() {
	lockEvent();
	assert(isCompleted());
	unlockEvent();
}

cl_command_type opencl::Event::type() {
	return _type;
}

bool opencl::Event::isUserEvent() {
	return (_type == CL_COMMAND_USER);
}

void opencl::Event::setCallBack(void (CL_CALLBACK * pfn_notify)(cl_event, cl_int, void *),
                void * user_data) {
	_eventNotify = pfn_notify;
	_userData = user_data;
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

bool opencl::Event::hasError() {
	return (_status < 0);
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
		cl_uint cl_uint_var;
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

		case CL_EVENT_REFERENCE_COUNT:
			ASSIGN_INFO(cl_uint, _references);
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

void opencl::Event::setProfilingInfo(cl_int status) {
	if(!_commandQueue->isProfileEnabled())
		return;

	OpenCLRuntime * runtime = dynamic_cast<OpenCLRuntime *>(OpenCLRuntimeInterface::get());
	cl_ulong currentTime = runtime->getCurrentTime();

	report("Set profiling info for event " << this << " at time point " << currentTime);

	switch(status) {
		case CL_QUEUED:
			_profileQueued = currentTime;
			break;
		case CL_SUBMITTED:
			_profileSubmit = currentTime;
			break;
		case CL_RUNNING:
			_profileStart = currentTime;
			break;
		default: {
			if(isCompleted())
				_profileEnd = currentTime;
			else
				assertM(false, "Unknown event status");
			}
			break;
	}
}

void opencl::Event::getProfilingInfo(cl_profiling_info param_name,
		size_t param_value_size,
		void * param_value,
		size_t * param_value_size_ret) {
	if(!_commandQueue->isProfileEnabled())
		throw CL_PROFILING_INFO_NOT_AVAILABLE;
	if(isUserEvent())
		throw CL_PROFILING_INFO_NOT_AVAILABLE;
	if(!hasStatus(CL_COMPLETE))
		throw CL_PROFILING_INFO_NOT_AVAILABLE;

	cl_ulong profile;
	size_t infoLen = sizeof(cl_ulong);
	void * ptr = &profile;

	switch(param_name) {
		case CL_PROFILING_COMMAND_QUEUED:
			profile = _profileQueued;
			break;

		case CL_PROFILING_COMMAND_SUBMIT:
			profile = _profileSubmit;
			break;

		case CL_PROFILING_COMMAND_START:
			profile = _profileStart;
			break;

		case CL_PROFILING_COMMAND_END:
			profile = _profileEnd;
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


void opencl::Event::callBack() {
	if(_eventNotify)
		_eventNotify((cl_event)this, _status, _userData);
}

void opencl::Event::waitForEvents(cl_uint num_events,
		const cl_event * event_list) {


	// check if is valid event objects
	for(cl_uint i = 0; i < num_events; i++) {
		if(!event_list[i]->isValidObject(Object::OBJTYPE_EVENT))
			throw CL_INVALID_EVENT;
	}

	// check if belong to the same context
	Context * context = event_list[0]->_context;
	for(cl_uint i = 0; i < num_events; i++) {
		if((Context *)(event_list[i]->_context) != context)
			throw CL_INVALID_CONTEXT;
	}

	// flush command queues associated with events
	for(cl_uint i = 0; i < num_events; i++) {
		((CommandQueue *)(event_list[i]->_commandQueue))->flushEvents();
	}

	report("Wait for " << num_events << " events");
	// wait for events
	for(cl_uint i = 0; i < num_events; i++) {
		event_list[i]->waitToComplete();
		if(event_list[i]->hasError()) // error
			throw CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST;
	}
}



opencl::ReadWriteBufferEvent::ReadWriteBufferEvent(cl_command_type type,
	CommandQueue * commandQueue,
	BufferObject * buffer,
	cl_bool blocking,
	size_t offset, size_t size, void * ptr,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) :
	Event(type, commandQueue, 
	commandQueue->context(), num_events_in_wait_list,
	event_wait_list, event),
	_buffer(buffer), _offset(offset),
	_size(size), _ptr(NULL) {

	if(offset >= buffer->size() || size + offset > buffer->size())
		throw CL_INVALID_VALUE;
	
	if(ptr == NULL)
		throw CL_INVALID_VALUE;

	if(!buffer->isAllocatedOnDevice(commandQueue->device()))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	if(_type == CL_COMMAND_WRITE_BUFFER) {
		_ptr = new uint8_t[size];
		std::memcpy(_ptr, ptr, size);
	}
	else
		_ptr = ptr;

	buffer->retain();

	commandQueue->queueEvent(this, blocking);
}

opencl::ReadWriteBufferEvent::~ReadWriteBufferEvent() {
	if(_type == CL_COMMAND_WRITE_BUFFER && _ptr) {
		delete (uint8_t *)_ptr;
		_ptr = NULL;
	}
}

void opencl::ReadWriteBufferEvent::execute(Device * device) {
	assertM(device == _commandQueue->device(), "invalid device");

	if(_type == CL_COMMAND_READ_BUFFER)
		_buffer->readOnDevice(device, _offset, _size, _ptr);
	else  if(_type == CL_COMMAND_WRITE_BUFFER)
		_buffer->writeOnDevice(device, _offset, _size, _ptr);
	else
		assertM(false, "Invalid read/write buffer command");

}

void opencl::ReadWriteBufferEvent::release() {
	if(_references == 1) {
		_buffer->release();
	}
	Event::release();
}

opencl::ReadWriteBufferRectEvent::ReadWriteBufferRectEvent(cl_command_type type,
			CommandQueue * commandQueue,
            BufferObject * buffer,
            cl_bool blocking,
            const size_t *      buffer_origin,
            const size_t *      host_origin,
            const size_t *      region,
            size_t              buffer_row_pitch,
            size_t              buffer_slice_pitch,
            size_t              host_row_pitch,
            size_t              host_slice_pitch,                        
            void *              ptr,
            cl_uint num_events_in_wait_list,
            const cl_event * event_wait_list,
            cl_event * event) :
	Event(type, commandQueue, 
	commandQueue->context(), num_events_in_wait_list,
	event_wait_list, event),
	_buffer(buffer), _origin(buffer_origin), _hostOrigin(host_origin),
	_region(region), _rowPitch(buffer_row_pitch), _slicePitch(buffer_slice_pitch),
	_hostRowPitch(host_row_pitch), _hostSlicePitch(host_slice_pitch), _ptr(ptr) {

	if(ptr == NULL)
		throw CL_INVALID_VALUE;
	
	//TO DO: check boundary
	if(region[0] == 0 || region[1] == 0 || region[2] == 0)
		throw CL_INVALID_VALUE;

	if(buffer_row_pitch > 0 && buffer_row_pitch < region[0])
		throw CL_INVALID_VALUE;
	
	size_t offset = _origin[2] * _slicePitch + _origin[1] * _rowPitch + _origin[0];

	if(offset >= buffer->size())
		throw CL_INVALID_VALUE;


	if(!buffer->isAllocatedOnDevice(commandQueue->device()))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	buffer->retain();

	commandQueue->queueEvent(this, blocking);
}

opencl::ReadWriteBufferRectEvent::~ReadWriteBufferRectEvent() {

}

void opencl::ReadWriteBufferRectEvent::execute(Device * device) {
	assertM(device == _commandQueue->device(), "invalid device");

	assertM(false, "Unimplemented rectangulary read/write");

}

void opencl::ReadWriteBufferRectEvent::release() {
	if(_references == 1) {
		_buffer->release();
	}
	Event::release();
}

opencl::FillBufferEvent::FillBufferEvent(CommandQueue * commandQueue,
	BufferObject * buffer,
	const void * pattern,
	size_t             pattern_size,
	size_t             offset,
	size_t             size,
	cl_uint            num_events_in_wait_list,
	const cl_event *   event_wait_list,
	cl_event *         event) :
	Event(CL_COMMAND_FILL_BUFFER, commandQueue,
		commandQueue->context(), num_events_in_wait_list,
		event_wait_list, event),
	_buffer(buffer), _pattern(pattern), 
	_patternSize(pattern_size), _size(size) {


	//To do: boundary check

	_buffer->retain();

	commandQueue->queueEvent(this, false);
}

opencl::FillBufferEvent::~FillBufferEvent() {
}

void opencl::FillBufferEvent::execute(Device * device) {
	//To do
}

void opencl::FillBufferEvent::release() {
	if(_references == 1) {
		_buffer->release();
	}
	Event::release();
}

opencl::CopyBufferEvent::CopyBufferEvent(CommandQueue * commandQueue,
            BufferObject * src_buffer,
            BufferObject * dst_buffer,
            size_t              src_offset,
            size_t              dst_offset,
            size_t              size,   
            cl_uint             num_events_in_wait_list,
            const cl_event *    event_wait_list,
            cl_event *          event) :
	Event(CL_COMMAND_COPY_BUFFER, commandQueue,
		commandQueue->context(), num_events_in_wait_list,
		event_wait_list, event),
	_src(src_buffer), _dst(dst_buffer), 
	_srcOffset(src_offset), _dstOffset(dst_offset),
	_size(size) {

	//To do: boundary check

	_src->retain();
	_dst->retain();

	commandQueue->queueEvent(this, false);

}

opencl::CopyBufferEvent::~CopyBufferEvent() {
}

void opencl::CopyBufferEvent::execute(Device * device) {
	_dst->copyFromBufferOnDevice(device, _srcOffset,
		_dstOffset, _size, _src);
}

void opencl::CopyBufferEvent::release() {
	if(_references == 1) {
		_src->release();
		_dst->release();
	}
	Event::release();
}

opencl::CopyBufferRectEvent::CopyBufferRectEvent(CommandQueue * commandQueue,
	BufferObject * src_buffer,
	BufferObject * dst_buffer,
	const size_t *       src_origin,
	const size_t *       dst_origin,
	const size_t *       region,
	size_t               src_row_pitch,
	size_t               src_slice_pitch,
	size_t               dst_row_pitch,
	size_t               dst_slice_pitch,
	cl_uint              num_events_in_wait_list,
	const cl_event *     event_wait_list,
	cl_event *           event) :
	Event(CL_COMMAND_COPY_BUFFER_RECT, commandQueue,
        commandQueue->context(), num_events_in_wait_list,
        event_wait_list, event),
	_src(src_buffer), _dst(dst_buffer),
	_srcOrigin(src_origin), _dstOrigin(dst_origin), _region(region),
	_srcRowPitch(src_row_pitch), _srcSlicePitch(src_slice_pitch),
	_dstRowPitch(dst_row_pitch), _dstSlicePitch(dst_slice_pitch) {
	
	//To do: boundary check

	_src->retain();
	_dst->retain();

	commandQueue->queueEvent(this, false);
}

opencl::CopyBufferRectEvent::~CopyBufferRectEvent() {
}

void opencl::CopyBufferRectEvent::execute(Device * device) {
	//To do
}

void opencl::CopyBufferRectEvent::release() {
	if(_references == 1) {
		_src->release();
		_dst->release();
	}
	Event::release();
}

opencl::MapBufferEvent::MapBufferEvent(CommandQueue * commandQueue,
	BufferObject * buffer,
    cl_bool blocking,
    cl_map_flags map_flags,
	void ** 			  mappedPtr,
    size_t            offset,
    size_t            size,
    cl_uint           num_events_in_wait_list,
    const cl_event *  event_wait_list,
    cl_event *        event):
	Event(CL_COMMAND_MAP_BUFFER, commandQueue, 
	commandQueue->context(), num_events_in_wait_list,
	event_wait_list, event),
	_buffer(buffer),_flags(map_flags), _offset(offset), _size(size) {

	if(size == 0 || size + offset > buffer->size())
		throw CL_INVALID_VALUE;

	if(!buffer->isAllocatedOnDevice(commandQueue->device()))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	buffer->retain();

	_ptr = buffer->createNewMapPtr(offset, size);

	commandQueue->queueEvent(this, blocking);

	*mappedPtr = _ptr;

}

opencl::MapBufferEvent::~MapBufferEvent() {
}

void opencl::MapBufferEvent::execute(Device * device) {
	assertM(device == _commandQueue->device(), "invalid device");
	_buffer->mapPtr(device, _ptr);
}

void opencl::MapBufferEvent::release() {
	if(_references == 1) {
		_buffer->release();
	}
	Event::release();
}

opencl::UnmapMemObjectEvent::UnmapMemObjectEvent(CommandQueue * commandQueue,
	MemoryObject * memobj,
	void * mappedPtr,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event):
	Event(CL_COMMAND_UNMAP_MEM_OBJECT, commandQueue,
    commandQueue->context(), num_events_in_wait_list,
    event_wait_list, event), 
	_memobj(memobj), _ptr(mappedPtr) {

	if(!memobj->isValidMemoryObject(CL_MEM_OBJECT_BUFFER)) //not buffer object
		assertM(false, "Unimplemented unmapping for non-buffer object\n");

	memobj->retain();

	commandQueue->queueEvent(this, false);
	
}

opencl::UnmapMemObjectEvent::~UnmapMemObjectEvent() {
}

void opencl::UnmapMemObjectEvent::execute(Device * device) {

	if(!_memobj->isValidMemoryObject(CL_MEM_OBJECT_BUFFER)) //not buffer object
		assertM(false, "Unimplemented unmapping for non-buffer object\n");

	((BufferObject *)_memobj)->unmapPtr(device, _ptr);
}

void opencl::UnmapMemObjectEvent::release() {
	if(_references == 1) {
		_memobj->release();
	}
	Event::release();
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

	report("Create Kernel Event");

	kernel->mapParametersOnDevice(commandQueue->device());
	kernel->setConfiguration(work_dim, global_work_offset, global_work_size, local_work_size);
	kernel->retain();

	commandQueue->queueEvent(this, false);	
}

opencl::KernelEvent::~KernelEvent() {


}

void opencl::KernelEvent::execute(Device * device) {
	assertM(device == _commandQueue->device(), "invalid device");
	_kernel->launchOnDevice(device);
}

void opencl::KernelEvent::release() {
	if(_references == 1) {
		_kernel->release();
	}
	Event::release();
}

opencl::MarkerBarrierEvent::MarkerBarrierEvent(cl_command_type type,
	CommandQueue * commandQueue,
	cl_uint num_events_in_wait_list,
	const cl_event * event_wait_list,
	cl_event * event) :
	Event(type, commandQueue,
    commandQueue->context(), num_events_in_wait_list,
    event_wait_list, event) {

	commandQueue->queueEvent(this, false);
}

opencl::MarkerBarrierEvent::~MarkerBarrierEvent() {
}

void opencl::MarkerBarrierEvent::execute(Device * device) {
}

opencl::UserEvent::UserEvent(Context * context) :
	Event(CL_COMMAND_USER, NULL, context, 0, NULL, NULL),
	_prevChanged(false) {
	_status = CL_SUBMITTED;
}

opencl::UserEvent::~UserEvent() {
}

void opencl::UserEvent::execute(Device * device) {
}

void opencl::UserEvent::setUserStatus(cl_int status) {
	if(_prevChanged)
		throw CL_INVALID_OPERATION;

	_prevChanged = true;
	setStatus(status);
}
