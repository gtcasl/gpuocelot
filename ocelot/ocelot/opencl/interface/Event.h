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
	class Kernel;

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
		static void waitForEvents(cl_uint num_events,
			const cl_event * event_list);

		void release();

		//! get type
		cl_command_type type();

		//! is user event
		bool isUserEvent();
		
		//! execute event
		virtual void execute(Device * device) = 0;

		//! set call back function
		void setCallBack(void (CL_CALLBACK * pfn_notify)(cl_event, cl_int, void *),
				void * user_data);

		//! check if completed
		bool isCompleted();

		//! check status
		bool hasStatus(cl_int status);

		//! set status
		void setStatus(cl_int status);
		
		//! check if error
		bool hasError();

		//! get event info
		void getInfo(cl_event_info    param_name,
				size_t           param_value_size,
				void *           param_value,
				size_t *         param_value_size_ret);

	protected:
		cl_command_type _type;
		CommandQueue * _commandQueue;
		Context * _context;
		cl_int _status;
		EventList _waitList;
		void (CL_CALLBACK *_eventNotify)(cl_event event,
						cl_int event_command_exec_status,
						void * user_data);
		void * _userData;		

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
		//virtual void release();
		virtual void execute(Device * device);


	protected:
		BufferObject * _buffer;
		size_t _offset;
		size_t _cb;
		void * _ptr;
	};

	/*! \brief Event for Kernel Launch */
	class KernelEvent : public Event {
	public:
		KernelEvent(cl_command_type type,
			CommandQueue * commandQueue,
			Kernel * kernel,
			cl_uint work_dim,
			const size_t *global_work_offset,
			const size_t *   global_work_size,
			const size_t *   local_work_size,
			cl_uint          num_events_in_wait_list,
			const cl_event * event_wait_list,
			cl_event *       event);
		~KernelEvent();

	public:
		//virtual void release();
		virtual void execute(Device * device);

	protected:
		Kernel * _kernel;
	
			
	};

	/*! \brief User event */
	class UserEvent : public Event {
	public:
		UserEvent(Context * context);
		~UserEvent();

	public:
		virtual void execute(Device * device);

		// set user event status
		void setUserStatus(cl_int status);

	private:

		//! if the status if previous changed
		bool _prevChanged;
	};

}

#endif
