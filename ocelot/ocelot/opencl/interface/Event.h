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
	class MemoryObject;
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

		//! execute call back function
		void callBack();

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
			size_t offset, size_t size, void * ptr,
			cl_uint num_events_in_wait_list,
			const cl_event * event_wait_list,
			cl_event * event);
		~ReadWriteBufferEvent();

	public:
		virtual void execute(Device * device);


	protected:
		BufferObject * _buffer;
		size_t _offset;
		size_t _size;
		void * _ptr;
	};

	/*! \brief Event for Read/Write Rectangular Buffer */
	class ReadWriteBufferRectEvent : public Event {
	public:
		ReadWriteBufferRectEvent(cl_command_type type,
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
			cl_event * event);
		~ReadWriteBufferRectEvent();

	public:
		virtual void execute(Device * device);


	protected:
		BufferObject * _buffer;
		const size_t * _origin;
		const size_t * _hostOrigin;
		const size_t * _region;
		size_t         _rowPitch;
		size_t         _slicePitch;
		size_t         _hostRowPitch;
		size_t         _hostSlicePitch;
		void *         _ptr;
	};

	/*! \brief Event for buffer filling */
	class FillBufferEvent : public Event {
	public:
		FillBufferEvent(CommandQueue * commandQueue,
			BufferObject * buffer,
			const void * pattern,
			size_t             pattern_size,
			size_t             offset,
			size_t             size,
			cl_uint            num_events_in_wait_list,
			const cl_event *   event_wait_list,
			cl_event *         event);
		~FillBufferEvent();

	public:
		virtual void execute(Device * device);

	protected:
		BufferObject * _buffer;
		const void * _pattern;
		size_t _patternSize;
		size_t _size;
	};

	class CopyBufferEvent : public Event {
	public:
		CopyBufferEvent(CommandQueue * commandQueue,
			BufferObject * src_buffer,
			BufferObject * dst_buffer,
			size_t              src_offset,
			size_t              dst_offset,
			size_t              size, 
			cl_uint             num_events_in_wait_list,
			const cl_event *    event_wait_list,
			cl_event *          event);
		~CopyBufferEvent();

	public:
		virtual void execute(Device * device);

	protected:
		BufferObject * _src;
		BufferObject * _dst;
		size_t _srcOffset;
		size_t _dstOffset;
		size_t _size;

	};

	/*! \brief Event for copy buffer rectangular */
	class CopyBufferRectEvent : public Event {
	public:
		CopyBufferRectEvent(CommandQueue * commandQueue,
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
			cl_event *           event);
		~CopyBufferRectEvent();

	public:
		virtual void execute(Device * device);

	protected:
		BufferObject * _src;
		BufferObject * _dst;
		const size_t * _srcOrigin;
		const size_t * _dstOrigin;
		const size_t * _region;
		size_t _srcRowPitch;
		size_t _srcSlicePitch;
		size_t _dstRowPitch;
		size_t _dstSlicePitch;

	};
	
	/*! \brief Event for mapping buffer */
	class MapBufferEvent : public Event {
	public:
		MapBufferEvent(CommandQueue * commandQueue,
			BufferObject * buffer,
			cl_bool blocking,
			cl_map_flags map_flags,
			void ** mappedPtr,
			size_t            offset,
			size_t            size,
			cl_uint           num_events_in_wait_list,
			const cl_event *  event_wait_list,
			cl_event *        event);

		~MapBufferEvent();

	public:
		virtual void execute(Device * device);


	protected:
		BufferObject * _buffer;
		cl_map_flags _flags;
		//mapped ptr;
		void * _ptr;
		size_t _offset;
		size_t _size;

	};

	class UnmapMemObjectEvent : public Event {
	public:
		UnmapMemObjectEvent(CommandQueue * commandQueue,
			MemoryObject * memobj,
			void * mappedPtr,
			cl_uint num_events_in_wait_list,
			const cl_event * event_wait_list,
			cl_event * event);
		~UnmapMemObjectEvent();

	public:
		virtual void execute(Device * device);

	protected:
		MemoryObject * _memobj;
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
		virtual void execute(Device * device);

	protected:
		Kernel * _kernel;
	
			
	};

	/*! \brief Marker/Barrier Event */
	class MarkerBarrierEvent : public Event {
	public:
		MarkerBarrierEvent(cl_command_type type,
			CommandQueue * commandQueue,
			cl_uint num_events_in_wait_list,
			const cl_event * event_wait_list,
			cl_event * event);
		~MarkerBarrierEvent();

	public:
		virtual void execute(Device * device);
	
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
