#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/MemoryObject.h>


opencl::MemoryObject::MemoryObject(std::map < int, void * > & a, void * context, cl_mem_object_type type, cl_mem_flags flags)
	:addrs(a), _context(context), _type(type), _flags(flags) {
}

const void * opencl::MemoryObject::context() const {
	return _context;
}

const cl_mem_object_type opencl::MemoryObject::type() const {
	return _type;
}

const cl_mem_flags opencl::MemoryObject::flags() const {
	return _flags;
}

opencl::BufferObject::BufferObject(std::map< int, void * > & addrs, void * context, cl_mem_flags flags, size_t size)
	:MemoryObject(addrs, context, CL_MEM_OBJECT_BUFFER, flags), _size(size) {
}

const size_t opencl::BufferObject::size() const {
	return _size;
}
