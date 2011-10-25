#ifndef OCELOT_OPENCL_COMMANDQUEUE_H_INCLUDED
#define OCELOT_OPENCL_COMMANDQUEUE_H_INCLUDED

namespace opencl {
	/*! \brief class defining command queue in opencl */
	class CommandQueue {
	public:
		CommandQueue(cl_context context, cl_device_id device, cl_command_queue_properties properties, unsigned int stream);

	public:
		const cl_context context() const;
		const cl_device_id device() const;
		const cl_command_queue_properties properties() const;
		const unsigned int stream() const;

	private:
		cl_context _context;
		cl_device_id _device;
		cl_command_queue_properties _properties;
		unsigned int _stream;
	};

}

#endif
