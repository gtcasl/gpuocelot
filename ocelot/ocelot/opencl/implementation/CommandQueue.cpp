#include <ocelot/opencl/interface/CommandQueue.h>

#undef REPORT_BASE
#define REPORT_BASE 0

opencl::QueueThread::QueueMessage::QueueMessage(Type t, void * d):
	type(t), data(d) {
}

void opencl::QueueThread::_executeEvent(Event * e) {
	assert(_device != 0);

	report(" Executing event '" << e << "' now.");
	e->setStatus(CL_RUNNING);

	try {
		e->execute(_device);
	}
	catch(cl_int exception) {

		report("  event '" << e << "' failed.");
		e->setStatus(exception);
		return;
	}
	catch(...) {
		report("  event '" << e << "' failed.");
		e->setStatus(CL_OUT_OF_RESOURCES);
		return;
	}

	report("  event '" << e << "' finished.");

	e->setStatus(CL_COMPLETE);
	e->callBack();

}

opencl::QueueThread::QueueThread(CommandQueue * commandQueue, Device * device):
	_commandQueue(commandQueue), _device(device) {
}

opencl::QueueThread::~QueueThread() {
	kill();	
	report("Tearing down Queue Thread for command queue " << _commandQueue);
}

void opencl::QueueThread::sendEvent(Event * event) {

	assert(started());

	QueueMessage * message = new QueueMessage(QueueMessage::Event, (void *)event);

	report("Command queue " << _commandQueue << " sending message " 
		<< message << " for event " << event);
	send(message);	
}

void opencl::QueueThread::kill() {

	report("Command queue " << _commandQueue << " kill thread ");
	if(!started())
		return;

	QueueMessage message(QueueMessage::Kill, NULL);

	send(&message);	
	
	QueueMessage * reply;
	receive(reply);
	assert(reply == &message);

	join();
}

void opencl::QueueThread::execute() {

	QueueMessage * message = 0;
	
	report("Queue Thread for command queue " << _commandQueue 
		<< " is alive, waiting for command.");

	threadReceive(message);
	
	while(message->type != QueueMessage::Kill) {
		report("Queue Thread for command queue " << _commandQueue
			<< " received message " << message << ", type " << message->type);

		switch(message->type) {

			case QueueMessage::Event: {
				report(" Receive event message.");

				Event * e = (Event *)message->data;
				delete message;
				
				_executeEvent(e);

				break;
				
			}

			default: 
				assertM(false, "Invalid message type.");
		}

		threadReceive(message);
	}

	report("Queue Thread for command queue " << _commandQueue 
		<< " Received kill command, joining.");
	threadSend(message);
}

void opencl::CommandQueue::_submitEvents() {

	for(EventList::iterator e = _eventsQueue.begin();
		e != _eventsQueue.end(); e++) {
		//Temporary submit strategy: Get first queued but not submitted event
		if((*e)->hasStatus(CL_QUEUED)) {
			report("Submit event " << (*e) << " in queue " << this);

			(*e)->setStatus(CL_SUBMITTED);
			_thread->sendEvent(*e);

			break;
		}
	}
}

void opencl::CommandQueue::_clearEvent(Event * event) {
	assert(event->isCompleted());
	EventList::iterator e = find(_eventsQueue.begin(),
		_eventsQueue.end(), event);
	assert(e != _eventsQueue.end());
	_eventsQueue.erase(e);
	event->release();
}

void opencl::CommandQueue::_clearCompletedEvents() {
	for(EventList::iterator e = _eventsQueue.begin();
		e != _eventsQueue.end(); e++) {
		//clear completed events
		if((*e)->isCompleted()) { 
			(*e)->release();
			e = (--_eventsQueue.erase(e));
		}
	}
}

bool opencl::CommandQueue::_isAllSubmitted() {
	for(EventList::iterator e = _eventsQueue.begin();
		e != _eventsQueue.end(); e++) {
		if((*e)->hasStatus(CL_QUEUED))
			return false;
	}
	return true;
}

bool opencl::CommandQueue::_isAllCompleted() {
	for(EventList::iterator e = _eventsQueue.begin();
		e != _eventsQueue.end(); e++) {
		if(!(*e)->isCompleted())
			return false;
	}
	return true;
}

void opencl::CommandQueue::_killThread() {
	if(_thread) {
		delete _thread;
		_thread = NULL;
	}
}
opencl::CommandQueue::CommandQueue(Context * context, 
	Device * device, 
	cl_command_queue_properties properties)
	:Object(OBJTYPE_COMMANDQUEUE),
	_context(context), _device(device), 
	_properties(properties), _thread(NULL) {

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
	
	_context->retain();
	_device->retain();

	_thread = new QueueThread(this, _device);
	_thread->start();

}

opencl::CommandQueue::~CommandQueue() {
	report("Delete command queue " << this);
	if(_thread)
		delete _thread;

	_context->release();

	_device->release();
}

void opencl::CommandQueue::release() {
	if(Object::release())
		delete this;
}

void opencl::CommandQueue::killAllQueueThreads() {
	report("Kill all queue threads");

	for(std::list< Object * >::iterator it = _objList.begin();
		it != _objList.end(); it++) {
		if((*it)->isValidObject(OBJTYPE_COMMANDQUEUE))
			((CommandQueue *)(*it))->_killThread();
	}
}


opencl::Context * opencl::CommandQueue::context() {
	return _context;
}

opencl::Device * opencl::CommandQueue::device() {
	return _device;
}

void opencl::CommandQueue::queueEvent(Event * event, cl_bool blocking) {

	report("Enqueue event " << event << " in queue " << this);
	_eventsQueue.push_back(event);
	event->setStatus(CL_QUEUED);

	_clearCompletedEvents();
	_submitEvents();

	if(blocking) {
		report(" Blocking event " << event);
		flushEvents();

		while(!event->isCompleted());

		_clearEvent(event);

		report(" Blocking event " << event << " end ");
	}
}

void opencl::CommandQueue::flushEvents() {

	//submit all events in the queue
	report("Flush events for command queue " << this);

	_clearCompletedEvents();

	while(!_isAllSubmitted())
		_submitEvents();
}

void opencl::CommandQueue::finishEvents() {

	report("Finish events for command queue " << this);

	flushEvents();

	while(!_isAllCompleted());

	_clearCompletedEvents();
}

void opencl::CommandQueue::getInfo(cl_command_queue_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {

	union infoUnion {
		cl_context cl_context_var;
		cl_device_id cl_device_id_var;
		cl_uint cl_uint_var;
		cl_command_queue_properties cl_command_queue_properties_var;
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
		case CL_QUEUE_CONTEXT:
			ASSIGN_INFO(cl_context, (cl_context)_context);
			break;

		case CL_QUEUE_DEVICE:
			ASSIGN_INFO(cl_device_id, (cl_device_id)_device);
			break;

		case CL_QUEUE_REFERENCE_COUNT:
			ASSIGN_INFO(cl_uint, _references);
			break;

		case CL_QUEUE_PROPERTIES:
			ASSIGN_INFO(cl_command_queue_properties, _properties);
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

