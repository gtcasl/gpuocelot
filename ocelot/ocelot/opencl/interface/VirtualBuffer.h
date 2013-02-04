#ifndef OCELOT_LCL_VIRTUALBUFFER_H_INCLUDED
#define OCELOT_LCL_VIRTUALBUFFER_H_INCLUDED

//Ocelob lib
#include <ocelot/opencl/interface/lcl_runtime.h>

//C++ lib
#include <list>

namespace lcl {

	class VirtualBuffer {
	public:

		typedef std::list< VirtualBuffer * > VirtualBufferList;

		typedef struct {
			cl_kernel * kernel;
			size_t memAccessSize;
		} KernelMemInfo;

	public:
		//! Constructor
		VirtualBuffer(lcl_context context, size_t size);

		//! Destructor
		~VirtualBuffer();

		//! Write virtual buffer
		void write(lcl_command_queue, lcl_bool blocking_write,
				size_t offset, size_t size, const void * ptr,
				lcl_uint num_events_in_wait_list,
				const lcl_event * event_wait_list,
				lcl_event * event);

		//! Read virtual buffer
		void read(lcl_command_queue, lcl_bool blocking_write,
				size_t offset, size_t size, void * ptr,
				lcl_uint num_events_in_wait_list,
				const lcl_event * event_wait_list,
				lcl_event * event);


		void setToKernelArg(lcl_kernel kernel, lcl_uint arg_index);

		void release();

		//! Get physical buffer object
		cl_mem & getPhysicalBuffer();

		//! Evaluate the placemet of the buffer
		void evaluatePlacement();

		//! Kernel Memory Access Information List
		std::list<KernelMemInfo> KernelMemInfoList;

		//! Host Mapping Access Information
		size_t hostMemAccessSize;

	private:
		//! Physical Buffer
		cl_mem _phyBuffer;

		//! Current Memory flag
		cl_mem_flags _curMemFlag;

		//! Buffer Size
		size_t _size;
	};
}

#endif
