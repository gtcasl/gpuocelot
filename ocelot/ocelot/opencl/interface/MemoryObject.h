#ifndef OCELOT_OPENCL_MEMORYOBJECT_H_INCLUDED
#define OCELOT_OPENCL_MEMORYOBJECT_H_INCLUDED

//C++ lib
#include <map>


//Ocelot lib
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/Context.h>
#include <ocelot/opencl/interface/Device.h>
#include <ocelot/opencl/interface/Object.h>

namespace opencl {

	class Context;

	/*! \brief class defining memory object in opencl */
	class MemoryObject : public Object{
	public:
		typedef std::list< MemoryObject * > MemoryObjectList;

	public:
		MemoryObject(Context * context, cl_mem_object_type type, 
			cl_mem_flags flags, void * host_ptr);
		~MemoryObject();

	public:
		//! get allocation size
		const virtual size_t size() const = 0;

		//! allocate resouces on devices
		void allocate();

		//! check if allocated on device
		bool isAllocatedOnDevice(Device * device);

		//! get allocated ptr on device
		void * getPtrOnDevice(Device * device);

		//! check if valid memory obejct
		bool isValidMemoryObject(cl_mem_object_type type);

		//! check if valid context
		bool isValidContext(Context * context);

	protected:
		Context * _context;
		const cl_mem_object_type _type;
		const cl_mem_flags _flags;
		void * _hostPtr;

	private:
		std::map< Device *, void * > _allocations; //allocations on device

	};

	/*! \breif class defining buffer object in opencl */
	class BufferObject: public MemoryObject {
	public:
		BufferObject(Context * context, const cl_mem_flags flags, void * host_ptr, size_t size);

	public:
		//! get allocation size
		const size_t size() const;

		//! read on device
		void readOnDevice(Device * device,
        	size_t offset, size_t cb, void * ptr);

		//! write on device
		void writeOnDevice(Device * device, cl_bool blockingWrite,
        	size_t offset, size_t cb, const void * ptr);

	private:
		size_t _size;	
	};
}

#endif
