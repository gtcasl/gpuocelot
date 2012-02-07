#ifndef OCELOT_OPENCL_MEMORYOBJECT_H_INCLUDED
#define OCELOT_OPENCL_MEMORYOBJECT_H_INCLUDED

//C++ lib
#include <map>


//Ocelot lib
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Object.h>

namespace opencl {

	class Context;

	/*! \brief class defining memory object in opencl */
	class MemoryObject : public Object{
	public:
		MemoryObject(std::map< Device *, executive::Device::MemoryAllocation * > & addrs, 
			Context * context, cl_mem_object_type type, cl_mem_flags flags);
		~MemoryObject();

	public:
		Context * context() const;
		const cl_mem_object_type type() const;
		const cl_mem_flags flags() const;
		const virtual size_t size() const = 0;
		std::map< Device *, executive::Device::MemoryAllocation * > allocations; //allocations on device

	private:
		Context * _context;
		const cl_mem_object_type _type;
		const cl_mem_flags _flags;
	};

	/*! \breif class defining buffer object in opencl */
	class BufferObject: public MemoryObject {
	public:
		BufferObject(std::map< Device *, executive::Device::MemoryAllocation * > & addrs, 
			Context * context, const cl_mem_flags flags, size_t size);

	public:
		const size_t size() const;

	private:
		size_t _size;	
	};
}

#endif
