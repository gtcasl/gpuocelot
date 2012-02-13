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
		e->release();
		return;
	}
	catch(...) {
		report("  event '" << e << "' failed.");
		e->setStatus(CL_OUT_OF_RESOURCES);
		e->release();
		return;
	}

	report("  event '" << e << "' finished.");

	e->setStatus(CL_COMPLETE);
	e->release();

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

	if(_context->release())
		delete _context;

	if(_device->release())
		delete _device;
}

void opencl::CommandQueue::killAllQueueThreads() {
	report("Kill all queue threads");

	for(std::list< Object * >::iterator it = _objList.begin();
		it != _objList.end(); it++) {
		if((*it)->isValidObject(OBJTYPE_COMMANDQUEUE))
			((CommandQueue *)(*it))->killThread();
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

	submitEvents();

	if(blocking) {
		report(" Blocking event " << event);
		while(!event->hasStatus(CL_SUBMITTED))
			submitEvents();

		while(!event->isCompleted());

		report(" Blocking event " << event << " end ");
	}
}

void opencl::CommandQueue::submitEvents() {

	//now in-order only
	Event * e = _eventsQueue.front();
	report("Submit event " << e << " in queue " << this);

	e->setStatus(CL_SUBMITTED);
	_thread->sendEvent(e);

	_eventsQueue.pop_front();
}

void opencl::CommandQueue::killThread() {
	if(_thread) {
		delete _thread;
		_thread = NULL;
	}
}
