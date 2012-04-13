#ifndef OCELOT_OPENCL_EVENT_H_INCLUDED
#define OCELOT_OPENCL_EVENT_H_INCLUDED

//Ocelot lib
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/CommandQueue.h>
#include <ocelot/opencl/interface/MemoryObject.h>

namespace opencl {
	class Context;
	class CommandQueue;
	class BufferObject;

	/*! \brief opencl event object */
	class Event : public Object {
	public:
		typedef std::list< Event * > EventList;

	public:
		Event(cl_command_type type, 
			CommandQueue * commandQueue, 
			Context * context,
			cl_uint num_events_in_wait_list,
			const cl_event * event_wait_list,
    		cl_event * event);
		~Event();

	public:
		virtual void release() = 0;

		//! get type
		cl_command_type type();
		
		//! execute event
		virtual void execute(Device * device) = 0;

		//! check if completed
		bool isCompleted();

		//! check status
		bool hasStatus(cl_int status);

		//! set status
		void setStatus(cl_int status);

	protected:
		cl_command_type _type;
		CommandQueue * _commandQueue;
		Context * _context;
		cl_int _status;
		EventList _waitList;
		

	};

	/*! \brief Event for Read/Write Buffer */
	class ReadWriteBufferEvent : public Event {
	public:
		ReadWriteBufferEvent(cl_command_type type,
			CommandQueue * commandQueue, 
			BufferObject * buffer, 
			cl_bool blocking,
			size_t offset, size_t cb, void * ptr,
			cl_uint num_events_in_wait_list,
			const cl_event * event_wait_list,
			cl_event * event);
		~ReadWriteBufferEvent();

	public:
		void release();
		void execute(Device * device);


	protected:
		BufferObject * _buffer;
		size_t _offset;
		size_t _cb;
		void * _ptr;
	};

}

#endif
