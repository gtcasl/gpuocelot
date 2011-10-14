#ifndef OCELOT_OPENCL_MEMORYOBJECT_H_INCLUDED
#define OCELOT_OPENCL_MEMROYOBJECT_H_INCLUDED

namespace opencl {
	/*! \brief class defining memory object in opencl */
	class MemoryObject {
	public:
		MemoryObject(cl_mem_object_type type);

	public:
		const cl_mem_object_type type() const;

	private:
		cl_mem_object_type _type;
	}

}

#endif
