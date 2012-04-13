#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/MemoryObject.h>

opencl::MemoryObject::MemoryObject(Context * context, cl_mem_object_type type, 
	cl_mem_flags flags, void * host_ptr)
	:Object(OBJTYPE_MEMORY),
	_context(context), _type(type), _flags(flags), _hostPtr(host_ptr) {
	_context->retain();

	if((flags & CL_MEM_READ_ONLY) 
		&& ((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_WRITE_ONLY)))
		throw CL_INVALID_VALUE;
	if((flags & CL_MEM_WRITE_ONLY) 
		&& ((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_READ_ONLY)))
		throw CL_INVALID_VALUE;

	if((flags & CL_MEM_ALLOC_HOST_PTR) && (flags & CL_MEM_COPY_HOST_PTR))
		throw CL_INVALID_VALUE;

	if((!host_ptr && ((flags & CL_MEM_USE_HOST_PTR) || (flags & CL_MEM_COPY_HOST_PTR)))
		|| (host_ptr && !(flags & CL_MEM_USE_HOST_PTR) && !(flags & CL_MEM_COPY_HOST_PTR)))
		throw CL_INVALID_HOST_PTR;

	if(host_ptr) {
		assertM(false, "unsuported host_ptr");
		throw CL_UNIMPLEMENTED;
	}
	
}

opencl::MemoryObject::~MemoryObject() {
	_context->release();
}

void opencl::MemoryObject::release() {
	if(Object::release())
		delete this;
}

void opencl::MemoryObject::allocate() {

	Device::DeviceList & validDevices = _context->getValidDevices();
	
	for(Device::DeviceList::iterator device = validDevices.begin();
		device != validDevices.end(); device++) {

		if(isAllocatedOnDevice(*device))
			continue;

		void * ptr =  (*device)->allocate(size());
		if(ptr == NULL)
			throw CL_OUT_OF_RESOURCES;

		_allocations.insert(std::make_pair(*device, ptr));
		report("memory object allocate on Device " << *device 
			<< ", address = " <<  ptr << ", size = " << size());
	}
}

bool opencl::MemoryObject::isAllocatedOnDevice(Device * device) {
	if(_allocations.find(device) != _allocations.end() && _allocations[device] != NULL)
		return true;

	return false;
}

void * opencl::MemoryObject::getPtrOnDevice(Device * device) {
	if(!isAllocatedOnDevice(device))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	return _allocations[device];
} 

bool opencl::MemoryObject::isValidMemoryObject(cl_mem_object_type type) {
	return (isValidObject(Object::OBJTYPE_MEMORY) && (_type == type));
}

bool opencl::MemoryObject::isValidContext(Context * context) {
	return context == _context;
}

opencl::BufferObject::BufferObject(Context * context, cl_mem_flags flags, 
	void * host_ptr, size_t size)
	:MemoryObject(context, CL_MEM_OBJECT_BUFFER, flags, host_ptr), _size(size) {

	if(size == 0)
		throw CL_INVALID_BUFFER_SIZE;

}

const size_t opencl::BufferObject::size() const {
	return _size;
}

void opencl::BufferObject::readOnDevice(Device * device, 
	size_t offset, size_t cb, void * ptr) {

	void * devicePtr = getPtrOnDevice(device);
	if(!device->read(devicePtr, ptr, offset, cb))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;
}

void opencl::BufferObject::writeOnDevice(Device * device, 
	size_t offset, size_t cb, const void * ptr) {

	void * devicePtr = getPtrOnDevice(device);
	if(!device->write(devicePtr, ptr, offset, cb))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;
}

