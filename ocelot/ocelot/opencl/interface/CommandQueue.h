#ifndef OCELOT_OPENCL_COMMANDQUEUE_H_INCLUDED
#define OCELOT_OPENCL_COMMANDQUEUE_H_INCLUDED

//C++ lib
#include <map>


//Ocelot lib
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Object.h>
#include <ocelot/opencl/interface/Event.h>

//Hydrazine lib
#include <hydrazine/interface/Thread.h>

namespace opencl {
	class Context;
	class CommandQueue;
	class Event;

	/*! \brief work thread for each command queue */
	class QueueThread : public hydrazine::Thread {
	
	public:
		QueueThread(CommandQueue * commandQueue, Device * device);
		~QueueThread();

	public:
		//! send event to the thread
		void sendEvent(Event * event);

		//! kill queue thread
		void kill();

		//! entry point
		void execute();

	private:
		//! queue message
		class QueueMessage {
		public:
			enum Type {
				Kill,
				Event,
				Invalid
			};

		public:
			QueueMessage(Type t = Invalid, void * d = NULL);

		public:	
			Type type;
			void * data;	
		};

	
	private:
		CommandQueue * _commandQueue;
		Device * _device;

	private:
		void _executeEvent(Event * event);
	};

	/*! \brief class defining command queue in opencl */
	class CommandQueue : public Object {
	public:
		typedef std::list< CommandQueue *> QueueList;
		typedef std::list< Event * > EventList;
		
	public:
		CommandQueue(Context * context, 
			Device * device, 
			cl_command_queue_properties properties);

		~CommandQueue();	

	public:
		//Kill all alive queue thread
		static void killAllQueueThreads();

		Context * context();
		Device * device();

		//! enqueue event
		void queueEvent(Event * event, cl_bool blocking);

		//! submit ready events
		void submitEvents();

		//! kill queue thread
		void killThread();

	private:
		Context * _context;
		Device * _device;
		cl_command_queue_properties _properties;
		QueueThread * _thread;
		EventList _eventsQueue;
	};

}

#endif
