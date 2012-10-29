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
			cl_mem_flags flags, void * host_ptr, bool isSubBuffer = false);
		virtual ~MemoryObject();

	public:
		virtual void release();

		//! get associated context
		Context * getContext() const;

		//! get flags
		cl_mem_flags getFlags() const;

		//! get host ptr
		void * getHostPtr() const;

		//! get allocation size
		const virtual size_t size() const = 0;

		//! allocate resouces on devices
		void allocate();

		//! copy from allocatoin of another memory object
		void allocate(MemoryObject * memObj);

		//! check if allocated on device
		bool isAllocatedOnDevice(Device * device);

		//! get allocated ptr on device
		void * getPtrOnDevice(Device * device);

		//! check if valid memory obejct
		bool isValidMemoryObject(cl_mem_object_type type);

		//! check if is sub buffer
		bool isSubBufferObject();

		//! check if valid context
		bool isValidContext(Context * context);

		//! check if memory offset is aligned
		bool isOffsetAligned(size_t offset);

	protected:
		typedef struct {
			size_t offset;
			size_t size;
		}mapPtrInfo;

		Context * _context;
		const cl_mem_object_type _type;
		cl_mem_flags _flags;
		void * _hostPtr;
		bool _isSubBuffer;
		std::unordered_map<void *, mapPtrInfo> _mappedPtrs;

	private:
		std::map< Device *, void * > _allocations; //allocations on device

	};

	/*! \breif class defining buffer object in opencl */
	class BufferObject: public MemoryObject {
	public:
		BufferObject(Context * context, const cl_mem_flags flags, void * host_ptr, size_t size);
		virtual ~BufferObject();

	public:
		//! get allocation size
		const size_t size() const;

		//! read on device
		void readOnDevice(Device * device,
        	size_t offset, size_t cb, void * ptr);

		//! write on device
		void writeOnDevice(Device * device,
        	size_t offset, size_t cb, const void * ptr);

		//! copy to another buffer on device
		void copyFromBufferOnDevice(Device * device,
			size_t srcOffset, size_t dstOffset, size_t size, BufferObject * srcBuffer);

		//! create new mapping pointer
		void * createNewMapPtr(size_t offset, size_t size);

		//! map pointer
		void mapPtr(Device * device, void * ptr);

		//! unmap pointer
		void unmapPtr(Device * device, void * ptr);


	private:
		size_t _size;	
	};

	/*! \brief class defining sub buffer object in opencl */
	class SubBufferObject: public MemoryObject {
	public:
		SubBufferObject(BufferObject * buffer, 
			const cl_mem_flags flags,
			cl_buffer_create_type buffer_create_type,
			const void *buffer_create_info);
		~SubBufferObject();

	public:
		//! get effective size
		const size_t size() const;

		//! get associated buffer object
		BufferObject * getAssociatedBuffer() const;

		//! get offset of associated buffer object
		const size_t offset() const;

		//! release, overload MemoryObject release()
		virtual void release();


	private:
		//! associated buffer object
		BufferObject * _buffer;

		//! offset of associated buffer object
		size_t _origin;

		//! size of subbuffer
		size_t _size;
	};

}

#endif
