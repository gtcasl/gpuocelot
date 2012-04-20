#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>
#include <ocelot/opencl/interface/MemoryObject.h>

opencl::MemoryObject::MemoryObject(Context * context, cl_mem_object_type type, 
	cl_mem_flags flags, void * host_ptr, bool isSubBuffer)
	:Object(OBJTYPE_MEMORY),
	_context(context), _type(type), _flags(flags), 
	_hostPtr(host_ptr), _isSubBuffer(isSubBuffer) {
	_context->retain();

	if((flags & CL_MEM_READ_ONLY) 
		&& ((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_WRITE_ONLY)))
		throw CL_INVALID_VALUE;
	if((flags & CL_MEM_WRITE_ONLY) 
		&& ((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_READ_ONLY)))
		throw CL_INVALID_VALUE;

	if((flags & CL_MEM_ALLOC_HOST_PTR) && (flags & CL_MEM_USE_HOST_PTR))
		throw CL_INVALID_VALUE;

	if((flags & CL_MEM_COPY_HOST_PTR) && (flags & CL_MEM_USE_HOST_PTR))
		throw CL_INVALID_VALUE;

	if((!host_ptr && ((flags & CL_MEM_USE_HOST_PTR) || (flags & CL_MEM_COPY_HOST_PTR)))
		|| (host_ptr && !(flags & CL_MEM_USE_HOST_PTR) && !(flags & CL_MEM_COPY_HOST_PTR)))
		throw CL_INVALID_HOST_PTR;
}

opencl::MemoryObject::~MemoryObject() {
	_context->release();
}

void opencl::MemoryObject::release() {
	if(Object::release())
		delete this;
}

opencl::Context * opencl::MemoryObject::getContext() const {
	return _context;
}

cl_mem_flags opencl::MemoryObject::getFlags() const {
	return _flags;
}

void * opencl::MemoryObject::getHostPtr() const {
	return _hostPtr;
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

		//Cache content of host_ptr to device ptr
		if(_hostPtr) {
			report("cache host_ptr of buffer object on device ");
			(*device)->write(ptr, _hostPtr, 0, size());
		}
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

bool opencl::MemoryObject::isSubBufferObject() {
	return (isValidMemoryObject(CL_MEM_OBJECT_BUFFER) && _isSubBuffer);
}

bool opencl::MemoryObject::isValidContext(Context * context) {
	return context == _context;
}

bool opencl::MemoryObject::isOffsetAligned(size_t offset) {
	Device::DeviceList & validDevices = _context->getValidDevices();
	
	for(Device::DeviceList::iterator device = validDevices.begin();
		device != validDevices.end(); device++) {

		cl_uint memBaseAlign;

		(*device)->getInfo(CL_DEVICE_MEM_BASE_ADDR_ALIGN, sizeof(cl_uint),
			&memBaseAlign, NULL);

		if(offset % (size_t)(memBaseAlign/8) != 0)
			return false;

	}

	return true;
}

opencl::BufferObject::BufferObject(Context * context, cl_mem_flags flags, 
	void * host_ptr, size_t size)
	:MemoryObject(context, CL_MEM_OBJECT_BUFFER, flags, host_ptr), _size(size) {

	if(size == 0)
		throw CL_INVALID_BUFFER_SIZE;

	allocate();

}

const size_t opencl::BufferObject::size() const {
	return _size;
}

void opencl::BufferObject::readOnDevice(Device * device, 
	size_t offset, size_t cb, void * ptr) {

	void * devicePtr = getPtrOnDevice(device);
	if(!device->read(devicePtr, ptr, offset, cb))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	//Copy device ptr to host ptr
	if(_hostPtr)
		if(!device->read(devicePtr, _hostPtr, offset, cb))
			throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

}

void opencl::BufferObject::writeOnDevice(Device * device, 
	size_t offset, size_t cb, const void * ptr) {

	void * devicePtr = getPtrOnDevice(device);
	if(!device->write(devicePtr, ptr, offset, cb))
		throw CL_MEM_OBJECT_ALLOCATION_FAILURE;

	//Copy ptr to host ptr
	if(_hostPtr)
		std::memcpy(((uint8_t *)_hostPtr) + offset, ptr, cb);
}

opencl::SubBufferObject::SubBufferObject(BufferObject * buffer, 
	const cl_mem_flags flags,
	cl_buffer_create_type buffer_create_type,
	const void *buffer_create_info) :
	MemoryObject(buffer->getContext(), CL_MEM_OBJECT_BUFFER, buffer->getFlags(), 
		buffer->getHostPtr(), true), _buffer(buffer) {
		
	if((_flags & CL_MEM_WRITE_ONLY) && 
		((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_READ_ONLY)))
		throw CL_INVALID_VALUE;

	if((_flags & CL_MEM_READ_ONLY) &&
		((flags & CL_MEM_READ_WRITE) || (flags & CL_MEM_WRITE_ONLY)))
		throw CL_INVALID_VALUE;

	if((flags & CL_MEM_USE_HOST_PTR) || (flags & CL_MEM_ALLOC_HOST_PTR)
		|| (flags & CL_MEM_COPY_HOST_PTR))
		throw CL_INVALID_VALUE;

	if((_flags & CL_MEM_HOST_WRITE_ONLY) && (flags & CL_MEM_HOST_READ_ONLY))
		throw CL_INVALID_VALUE;

	if((_flags & CL_MEM_HOST_READ_ONLY) && (flags & CL_MEM_HOST_WRITE_ONLY))
		throw CL_INVALID_VALUE;

	if((_flags & CL_MEM_HOST_NO_ACCESS) && 
		((flags & CL_MEM_HOST_READ_ONLY) || (flags & CL_MEM_HOST_WRITE_ONLY)))
		throw CL_INVALID_VALUE;

	if(buffer_create_type != CL_BUFFER_CREATE_TYPE_REGION)
		throw CL_INVALID_VALUE;

	if(!buffer_create_info)
		throw CL_INVALID_VALUE;


	size_t regionOrigin = ((cl_buffer_region *)buffer_create_info)->origin;
	size_t regionSize = ((cl_buffer_region *)buffer_create_info)->size;

	if(regionOrigin + regionSize < 0 || regionOrigin + regionSize >= buffer->size())
		throw CL_INVALID_VALUE;

	if(regionSize == 0)
		throw CL_INVALID_BUFFER_SIZE;

	if(!isOffsetAligned(regionOrigin))
		throw CL_MISALIGNED_SUB_BUFFER_OFFSET;


	_flags &= ~(CL_MEM_WRITE_ONLY | CL_MEM_READ_ONLY | CL_MEM_READ_WRITE
		| CL_MEM_HOST_WRITE_ONLY | CL_MEM_HOST_READ_ONLY | CL_MEM_HOST_NO_ACCESS); 
	_flags |= flags;


	_origin = regionOrigin;
	_size = regionSize;


	if(_flags & CL_MEM_USE_HOST_PTR)
		_hostPtr = (uint8_t *)_hostPtr + _origin;

	buffer->retain();
	
}


opencl::SubBufferObject::~SubBufferObject() {
	_buffer->release();
}

const size_t opencl::SubBufferObject::size() const {
	return _size;
}
