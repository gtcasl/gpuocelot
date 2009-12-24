/*!
	\file Executive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements Ocelot's executive manager
*/

#include <assert.h>
#include <stdlib.h>

#include <ocelot/executive/interface/Executive.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot executive construction/destruction
//

executive::Executive::Executive() {

}

executive::Executive::~Executive() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Linear memory allocation functions
//
// note: each address space may require special handling
//

bool executive::Executive::malloc(void **devPtr, size_t size) {
	bool result = true;
	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_linear;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.pointer.xsize = size;
	memory.pointer.pitch = size;
	memory.pointer.ysize = 1;
	memory.dimension = MemoryAllocation::Dim_1D;
		
		
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = size;
			memory.pointer.ptr = (void *)::malloc(size);
		}
		break;
		
	default:
		// device is in GPU memory somewhere
		assert(0 && "unimplemented");
		break;
	}
	
	*devPtr = memory.pointer.ptr;
	
	memoryAllocations[memory.addressSpace][memory.pointer.ptr] = memory;
	
	return result;
}

bool executive::Executive::mallocHost(void **ptr, size_t size) {
	bool result = true;
	MemoryAllocation memory;
	
	memory.addressSpace = 0;
	memory.structure = MemoryAllocation::Struct_linear;
	memory.affinity = MemoryAllocation::Affinity_host;
	memory.pointer.xsize = size;
	memory.pointer.pitch = size;
	memory.pointer.ysize = 1;
	memory.dimension = MemoryAllocation::Dim_1D;
	
	switch (getDeviceAddressSpace()) {
	case 0:
		{
			memory.allocationSize = size;
			memory.pointer.ptr = (void *)::malloc(size);
		}
		break;
	default:
		// maybe use cuHostMalloc() instead
		assert(0 && "unimplemented");
	break;
	}
	
	*ptr = memory.pointer.ptr;
	
	memoryAllocations[memory.addressSpace][memory.pointer.ptr] = memory;
	
	return result;
}

bool executive::Executive::mallocPitch(void **devPtr, size_t *pitch, size_t width, 
	size_t height) {
	bool result = true;
	
	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_pitch;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.pointer.xsize = width;
	memory.pointer.ysize = height;

	memory.dimension = MemoryAllocation::Dim_2D;
		
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = width * height;
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize);
			memory.pointer.pitch = width;
		}
		break;
	default:
		// device is in GPU memory somewhere
		assert(0 && "unimplemented");		
		break;
	}
	
	*devPtr = memory.pointer.ptr;
	*pitch = memory.pointer.pitch;
	
	memoryAllocations[memory.addressSpace][memory.pointer.ptr] = memory;
	
	return result;
}

bool executive::Executive::mallocArray(struct cudaArray **array, 
	const ChannelFormatDesc & desc, size_t width, size_t height) {
	bool result = true;

	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_array;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.pointer.xsize = width;
	memory.pointer.ysize = height;
	memory.desc = desc;

	memory.dimension = MemoryAllocation::Dim_2D;
	
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = width * height;
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize);
			memory.pointer.pitch = width;
		}
		break;
	default:
		assert(0 && "unimplemented");
		break;
	}
	
	*array = (struct cudaArray *)memory.pointer.ptr;
	memoryAllocations[memory.addressSpace][memory.pointer.ptr] = memory;
	
	return result;
}

bool executive::Executive::free(void *devPtr) {
	bool result = true;
	
	MemoryAllocationMap::iterator it = memoryAllocations[getDeviceAddressSpace()].find(devPtr);
	if (it == memoryAllocations[getDeviceAddressSpace()].end()) {
		// not found
		assert(0 && "unimplemented");		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			free(it->second.pointer.ptr);
		}
		memoryAllocations[getDeviceAddressSpace()].erase(it);
	}
	return result;
}

bool executive::Executive::freeHost(void *ptr) {
	bool result = true;

	MemoryAllocationMap::iterator it = memoryAllocations[getDeviceAddressSpace()].find(ptr);
	if (it == memoryAllocations[getDeviceAddressSpace()].end()) {
		// not found
		assert(0 && "unimplemented");		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			free(it->second.pointer.ptr);
		}
		memoryAllocations[getDeviceAddressSpace()].erase(it);
	}
	
	return result;
}

bool executive::Executive::freeArray(struct cudaArray *array) {
	bool result = true;
	MemoryAllocationMap::iterator it = memoryAllocations[getDeviceAddressSpace()].find((void *)array);
	if (it == memoryAllocations[getDeviceAddressSpace()].end()) {
		// not found
		assert(0 && "unimplemented");		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			free(it->second.pointer.ptr);
		}
		memoryAllocations[getDeviceAddressSpace()].erase(it);
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// register functions

/*!
	loads a PTX module
*/
void executive::Executive::loadModule(std::string name, bool, std::istream & ptx) {

	//
	// parse PTX into a module with PTX kernels then translate to available devices
	//
	
	assert(0 && "unimplemented");
}

void executive::Executive::registerGlobalVariable(const char *module, const char *name, 
	void *hostPtr, void *devicePtr, size_t size, DeviceAddressSpace addrSpace) {
	
	//
	// register global variables and allocate [if necessary] on available address spaces
	//
	
	assert(0 && "unimplemented");
}

void executive::Executive::registerTexture(const char *module, const char *name, int dimensions,
	int normalized) {

	//
	// register global variables and allocate [if necessary] on available address spaces
	//
	
	assert(0 && "unimplemented");
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot device management

//! returns the address space of the selected device
int executive::Executive::getDeviceAddressSpace() const {
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

