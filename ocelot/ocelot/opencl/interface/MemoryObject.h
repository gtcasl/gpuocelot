#ifndef OCELOT_OPENCL_MEMORYOBJECT_H_INCLUDED
#define OCELOT_OPENCL_MEMORYOBJECT_H_INCLUDED

namespace opencl {
	/*! \brief class defining memory object in opencl */
	class MemoryObject {
	public:
		MemoryObject(std::map< int, void * > & addrs, void * context, cl_mem_object_type type, cl_mem_flags flags);

	public:
		const void * context() const;
		const cl_mem_object_type type() const;
		const cl_mem_flags flags() const;
		const virtual size_t size() const = 0;
		std::map< int, void * > addrs; //addresses on device

	private:
		void * _context;
		cl_mem_object_type _type;
		cl_mem_flags _flags;
	};

	/*! \breif class defining buffer object in opencl */
	class BufferObject: public MemoryObject {
	public:
		BufferObject(std::map< int, void * > & addrs, void * context, cl_mem_flags flags, size_t size);

	public:
		const size_t size() const;

	private:
		size_t _size;	
	};
}

#endif
