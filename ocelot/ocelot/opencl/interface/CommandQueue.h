#ifndef OCELOT_OPENCL_COMMANDQUEUE_H_INCLUDED
#define OCELOT_OPENCL_COMMANDQUEUE_H_INCLUDED

//C++ lib
#include <map>


//Ocelot lib
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Object.h>


namespace opencl {
	class Context;

	/*! \brief class defining command queue in opencl */
	class CommandQueue : public Object {
	public:
		CommandQueue(Context * context, 
			Device * device, 
			cl_command_queue_properties properties);

		~CommandQueue();	

	public:
		Context * context() ;
		Device * device() ;
		cl_command_queue_properties properties() ;

	private:
		Context * _context;
		Device * _device;
		cl_command_queue_properties _properties;
	};

}

#endif
