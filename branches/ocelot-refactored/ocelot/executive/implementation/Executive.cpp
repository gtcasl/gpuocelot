/*! \file Executive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements Ocelot's executive manager
*/

// C stdlib includes
#include <assert.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

// C++ stdlib includes
#include <fstream>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/Executive.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/GPUExecutableKernel.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>
#include <ocelot/executive/interface/RuntimeException.h>

#if HAVE_CUDA_DRIVER_API == 1
#include <ocelot/cuda/include/cuda.h>

#define CUDA_OPENGL_INTEROPERABILITY 0

#include <ocelot/cuda/include/cudaGL.h>
#endif

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/interface/Casts.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Helper functions
//
static size_t getOffset(void* pointer) {
	size_t address = (size_t)pointer;
	size_t remainder = address % 16;
	size_t offset = remainder == 0 ? 0 : 16 - remainder;
	return offset;
}
//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot executive construction/destruction
//

executive::Executive::Executive() {

	// translator initialization
	hostWorkerThreads = api::OcelotConfiguration::getExecutive().workerThreadLimit;
	optimizationLevel = 
		(translator::Translator::OptimizationLevel)
			api::OcelotConfiguration::getExecutive().optimizationLevel;
	enumerateDevices();
}

executive::Executive::~Executive() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Linear memory allocation functions
//
// note: each address space may require special handling
//

/*!
	Registers an external memory allocation
	\param ptr pointer to allocation
	\param bytes size of the allocation in bytes
	\param addressSpace address space of the allocation
*/
void executive::Executive::registerExternal(void *ptr, size_t bytes, int addressSpace) {
	MemoryAllocation memory;

	if (addressSpace < 0) {
		addressSpace = getDeviceAddressSpace();
	}
	
	memory.structure = MemoryAllocation::Struct_linear;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.addressSpace = addressSpace;
	memory.dimension = MemoryAllocation::Dim_1D;

	memory.pointer.ptr = ptr;
	memory.pointer.offset = 0;
	memory.pointer.xsize = bytes;
	memory.pointer.pitch = bytes;
	memory.pointer.ysize = 1;

	memory.extent.width = bytes;
	memory.extent.height = 1;
	memory.extent.depth = 1;

	memory.allocationSize = bytes;
	memory.flags = 0;

	memory.internal = false;
	
	memoryAllocations[memory.addressSpace][memory.get()] = memory;

	report("  Executive::registerExternal(addrspace: " << memory.addressSpace << ") - ptr: " 
		<< (void *)memory.get() << ", " << memory.allocationSize << " bytes");
}

void executive::Executive::unregisterExternal(void *ptr, int addressSpace) {
	if (addressSpace < 0) {
		addressSpace = getDeviceAddressSpace();
	}

	MemoryAllocationMap::iterator alloc_it = memoryAllocations[addressSpace].find(ptr);
	if (alloc_it != memoryAllocations[addressSpace].end()) {
		memoryAllocations[addressSpace].erase(alloc_it);
	}
}

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
	memory.extent.width = size;
	memory.extent.height = 1;
	memory.extent.depth = 1;
	
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = size;
			memory.pointer.ptr = (void *)::malloc(size + 16);
			memory.pointer.offset = getOffset(memory.pointer.ptr);
		}
		break;
		
	default:
		// device is in GPU memory somewhere
		if (getSelectedISA() == ir::Instruction::GPU) {
			assert(0 && "unimplemented");
			break;
		}
		assert(0 && "unimplemented");
		break;
	}
	
	*devPtr = memory.get();
	memoryAllocations[memory.addressSpace][*devPtr] = memory;
	
	return result;
}

/*!
	\brief performs host allocation of page-locked memory
	\param ptr places resulting pointer
	\param size number of bytes
	\param portable allocation will be considered pinned memory shared for all CUDA contexts
	\param mapped	maps allocation to device context
	\param writeCombined optimize for writes by CPU, reads from device
*/
bool executive::Executive::mallocHost(void **ptr, size_t size, bool portable, bool mapped, 
	bool writeCombined) {

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
			memory.pointer.ptr = (void *)::malloc(size + 16);
			memory.pointer.offset = getOffset(memory.pointer.ptr);
			memory.extent.width = size;
			memory.extent.height = 1;
			memory.extent.depth = 1;
		}
		break;
	default:
		// maybe use cuHostMalloc() instead
		assert(0 && "unimplemented");
	break;
	}
	
	*ptr = memory.get();
	memoryAllocations[memory.addressSpace][*ptr] = memory;
	
	report("Executive::mallocHost(" << *ptr << ")");
	
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
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize + 16);
			memory.pointer.offset = getOffset(memory.pointer.ptr);
			memory.pointer.pitch = width;
			memory.extent.width = width;
			memory.extent.height = height;
			memory.extent.depth = 1;
		}
		break;
	default:
		// device is in GPU memory somewhere
		assert(0 && "unimplemented");		
		break;
	}
	
	*devPtr = memory.get();
	*pitch = memory.pointer.pitch;
	
	memoryAllocations[memory.addressSpace][*devPtr] = memory;
	
	return result;
}

/*!
	\brief allocates memory on the selected device given an extent - output in pitched pointer
	\param pitchedPtr pointer to pitched memory allocation
	\param extent extent of region - at least extent.width*height*depth bytes are allocated
*/
bool executive::Executive::mallocPitch(PitchedPointer * pitchedPointer, Extent extent) {

	bool result = true;
	
	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_pitch;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.extent = extent;

	if (extent.depth > 1) {
		memory.dimension = MemoryAllocation::Dim_3D;
	}
	else if (extent.height > 1) {
		memory.dimension = MemoryAllocation::Dim_2D;
	}
	else if (extent.width >= 1) {
		memory.dimension = MemoryAllocation::Dim_1D;
	}
	else {
		Ocelot_Exception("Executive::mallocPitch() - invalid extent");
	}
		
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = extent.width * extent.height * extent.depth;
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize + 16);
			memory.pointer.offset = getOffset(memory.pointer.ptr);
			memory.pointer.pitch = extent.width;
			memory.pointer.width = extent.width;
			memory.pointer.height = extent.height;

			report("mallocPitch() - allocated " << memory.allocationSize << " bytes - dimensions: "
				<< memory.extent.width << " x " << memory.extent.height << " x " << memory.extent.depth 
				<< " - ptr = " << (void *)memory.pointer.ptr);
		}
		break;
	default:
		// device is in GPU memory somewhere
		assert(0 && "unimplemented");		
		break;
	}

	*pitchedPointer = memory.pointer;
	
	memoryAllocations[memory.addressSpace][memory.get()] = memory;
	
	return result;
}

void convert(CUDA_ARRAY_DESCRIPTOR &descriptor, const executive::ChannelFormatDesc &desc) {
	descriptor.NumChannels = desc.channels();
	unsigned int bits = (desc.size() / desc.channels());
	if (bits > 2) bits = 3;
	
	switch (desc.kind) {
	case executive::ChannelFormatDesc::Kind_unsigned:
		descriptor.Format = (CUarray_format)bits;
		break;
	case executive::ChannelFormatDesc::Kind_signed:
		descriptor.Format = (CUarray_format)(7 + bits);
		break;
	case executive::ChannelFormatDesc::Kind_float:
		descriptor.Format = (CUarray_format)(bits == 2 ? 0x10 : 0x20);
		break;
	default:
		report("unknown ChannelFormatDesc::Kind");
	}
}

bool executive::Executive::mallocArray(struct cudaArray **array, 
	const ChannelFormatDesc & desc, size_t width, size_t height) {
	bool result = false;

	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_array;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.pointer.xsize = width;
	memory.pointer.ysize = height;
	memory.extent.width = width;
	memory.extent.height = height;
	memory.desc = desc;

	memory.dimension = MemoryAllocation::Dim_2D;
	memory.pointer.pitch = width * desc.size();
	memory.allocationSize = height * memory.pointer.pitch;
	
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize + 16);
			memory.pointer.offset = getOffset(memory.pointer.ptr);
			if (memory.pointer.ptr) {
				result = true;
			}
		}
		break;
	default:
		if (getSelectedISA() == ir::Instruction::GPU) {
			CUDA_ARRAY_DESCRIPTOR descriptor = {0};
			convert(descriptor, desc);
			descriptor.Width = width;
			descriptor.Height = height;
			if (cuArrayCreate(&memory.cudaArray, &descriptor) != CUDA_SUCCESS) {
				report("Executive::mallocArray() - failed to allocate CUDA array on GPU");
				result = false;
			}
			else {
				result = true;
				memory.pointer.ptr = (void *)memory.cudaArray;
				memory.pointer.offset = 0;
				
				report("Executive::mallocArray() - successfully allocated array of size " <<
					memory.allocationSize << " to address " << memory.pointer.ptr 
					<< " - (w: " << width << ", h: " << height << ")");
			}
			break;
		}
		assert(0 && "unimplemented");
	}
	
	if (result) {
		*array = (struct cudaArray *)memory.get();
		memoryAllocations[memory.addressSpace][memory.get()] = memory;
	}
	
	return result;
}

/*!
	\brief allocates a pitched memory allocation as an array
	\param arrayPtr pointer to allocation
	\param desc channel format
	\param extent region - at least extent.width*height*depth*desc.size() bytes are allocated
*/
bool executive::Executive::mallocPitchArray(PitchedPointer * pitchedPtr, 
	const ChannelFormatDesc &desc, Extent extent) {

	MemoryAllocation memory;

	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_array;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.desc = desc;
	memory.extent = extent;

	if (extent.depth > 1) {
		memory.dimension = MemoryAllocation::Dim_3D;
	}
	else if (extent.height > 1) {
		memory.dimension = MemoryAllocation::Dim_2D;
	}
	else if (extent.width >= 1) {
		memory.dimension = MemoryAllocation::Dim_1D;
	}
	else {
		Ocelot_Exception("Executive::mallocPitch() - invalid extent");
	}
	
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.pointer.pitch = extent.width * desc.size();
			memory.allocationSize = extent.height * memory.pointer.pitch * extent.depth;
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize + 16);
			memory.pointer.offset = getOffset(memory.pointer.ptr);
			memory.pointer.width = extent.width;
			memory.pointer.height = extent.height;
		}
		break;
	default:
		assert(0 && "unimplemented");
		break;
	}
	
	if (memory.get()) {
		*pitchedPtr = memory.pointer;
		memoryAllocations[memory.addressSpace][memory.get()] = memory;
	}

	return (memory.get() ? true : false);
}

/*!
	\brief frees an allocation - make sure you weren't calling ::free()
*/
bool executive::Executive::free(void *ptr) {
	bool result = true;

	report("Executive::free(" << ptr << ")");

	MemoryAllocationMap & allocations = memoryAllocations[getDeviceAddressSpace()];
	MemoryAllocationMap::iterator it = allocations.find(ptr);
	if (it == allocations.end()) {
		// not found
		report("Executive::free(" << ptr << ")");
		
		assert(0 && "unimplemented");
		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			if (getSelectedISA() == ir::Instruction::GPU) {
				assert(0 && "unimplemented");
			}
			else {
				assert(0 && "unimplemented");
			}
		}
		else {
			if (it->second.internal) {
				::free(it->second.pointer.ptr);
			}
		}
		allocations.erase(it);
	}
	
	return result;
}

bool executive::Executive::freeHost(void *ptr) {
	bool result = true;

	report("Executive::freeHost(" << ptr << ")");

	MemoryAllocationMap & allocations = memoryAllocations[getDeviceAddressSpace()];
	MemoryAllocationMap::iterator it = allocations.find(ptr);
	if (it == allocations.end()) {
		// not found
		report("Executive::freeHost(" << ptr << ")");
		
		assert(0 && "unimplemented");
		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			if (it->second.internal) {
				::free(it->second.pointer.ptr);
			}
		}
		allocations.erase(it);
	}
	
	return result;
}

bool executive::Executive::freeArray(struct cudaArray *array) {
	bool result = true;


	report("Executive::freeArray(" << (void *)array << ")");

	MemoryAllocationMap & allocations = memoryAllocations[getDeviceAddressSpace()];
	MemoryAllocationMap::iterator it = allocations.find((void *)array);
	if (it == allocations.end()) {
		// not found
		Ocelot_Exception("Executive::freeArray() - array = " << (void *)array 
			<< " was not found in the allocation table.");
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			if (it->second.internal) {
				if (it->second.get()) {
					::free(it->second.pointer.ptr);
				}
				it->second.pointer.ptr = 0;
			}
		}
		allocations.erase(it);
	}
	return result;
}

bool executive::Executive::checkMemoryAccess(int device, const void* base, size_t size) const {

	MemoryAllocation allocation = getMemoryAllocation(base);

	// least address in region must be greater than or equal to this
	const char *region_base_ptr = (const char *)allocation.get();	

	// greatest address in region must be less than this
	const char *region_end_ptr = region_base_ptr + allocation.size();

	bool valid = (region_base_ptr && region_end_ptr >= (const char *)base + size);
	return valid;
}

/*!
	\brief prints all memory allocations to an output stream
*/
std::ostream & executive::Executive::printMemoryAllocations(std::ostream &out) const {

	int addrSpace = getDeviceAddressSpace();
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(addrSpace);
	MemoryAllocationMap::const_iterator alloc_it = memoryMap_it->second.begin();

	out << "===== Ocelot global memory allocations =====\n";
	for (; alloc_it != memoryMap_it->second.end(); ++alloc_it) {
		const MemoryAllocation & memory = alloc_it->second;

		out << "=== allocation ===\n";
		out << memory.toString() << "\n";
	}
	out << "============================================\n";
	return out;
}

/*!
	Given a pointer, determine the allocated block and 
	corresponding MemoryAllocation record to which it belongs.

	\param ptr pointer to some byte
	\return record of memory allocation; if nothing could be found, 
		the record's ISA is Unknown
*/
executive::MemoryAllocation executive::Executive::getMemoryAllocation(const void *ptr) const {
	
	MemoryAllocation allocation;
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(getDeviceAddressSpace());
	const MemoryAllocationMap & memoryMap = memoryMap_it->second;
	MemoryAllocationMap::const_iterator alloc_it = memoryMap.find((void *)ptr);
	if (alloc_it == memoryMap.end()) {
		// find nearest
		bool found = false;
		MemoryAllocationMap::const_iterator bound = memoryMap.upper_bound((void *)ptr);
		if (bound != memoryMap.begin()) {
			--bound;

			const char *base_ptr = (const char *)bound->second.get();
			const char *end_ptr = base_ptr + bound->second.size();

			if ((const char *)ptr >= base_ptr && ptr <= end_ptr) {
				allocation = bound->second;
				found = true;
			}
		}
	}
	else {
		allocation = alloc_it->second;
	}
	
	return allocation;
}

std::string executive::Executive::nearbyAllocationsToString( 
	const Executive& executive, const void* pointer, 
	unsigned int above, unsigned int below) {

		// throw an exception

	std::stringstream ss;
	ss << "device memory fault - device pointer " << std::hex << pointer 
		<< " does not point to an allocation on device " << std::dec 
		<< executive.devices[executive.getSelectedDevice()].name 
		<< "\n";

	ss << "\nAll allocations:\n";
	executive.printMemoryAllocations(ss);
	
	return ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Memcpy functions

/*!
	\brief copies to or from the selected device - will check whether device pointers are allocated
	
	\param dest pointer to destination
	\param src pointer to source
	\param size number of bytes to transfer
	\param indicates the kind of transfer
	\return true on success
*/
bool executive::Executive::deviceMemcpy(void *dest, const void *src, size_t size, 
	executive::MemcpyKind kind) {

	int selectedDevice = getSelectedDevice();
	int deviceAddrSpace = getDeviceAddressSpace();
	
	report("deviceMemcpy(" << std::hex << dest << ", " << src << std::dec << ", " << size << " bytes)");
	
	switch (kind) {
	case HostToHost:
	{
		::memcpy(dest, src, size);
		return true;
	}
	break;
	
	case HostToDevice:
	{
		if (checkMemoryAccess(selectedDevice, dest, size)) {
		
			switch (deviceAddrSpace) {
			case 0:
				{
					report("deviceMemcpy() - host to device");
					::memcpy(dest, src, size);
					return true;
				}
			break;
			default:
				{
					assert(0 && "address space not supported");
				}
			}
		}
		else {
			report("failed to check memory access");
			throw hydrazine::Exception("device memory fault");
		}
	}
	break;
	
	case DeviceToHost:
	{
		if (checkMemoryAccess(selectedDevice, src, size)) {
		
			switch (deviceAddrSpace) {
			case 0:
				{
					::memcpy(dest, src, size);
					return true;
				}
			break;
			default:
				{
					assert(0 && "address space not supported");
				}
			}
		}
		else {
			throw hydrazine::Exception("device memory fault");
		}
	}
	break;
	
	case DeviceToDevice:
	{
		if (checkMemoryAccess(selectedDevice, src, size) && 
			checkMemoryAccess(selectedDevice, dest, size)) {
			
			switch (deviceAddrSpace) {
			case 0:
				{
					::memcpy(dest, src, size);
					return true;
				}
			break;
			default:
				{
					assert(0 && "address space not supported");
				}
			}
		}
		else {
			throw hydrazine::Exception("device memory fault");
		}
	}
	break;
	
	default:
		throw hydrazine::Exception("device memory fault - kind invalid");
	}
	
	return false;
}

/*!
	\brief returns a symbol as a global variable
*/
executive::GlobalVariable & executive::Executive::getGlobalVariable(const char *symbol) {
	return globals[std::string(symbol)];
}

/*!
	\brief copies to a symbol on the device
	\param symbol name of symbol
	\param src pointer to source data
	\param count number of bytes to copy
	\param offset offset to add to destination
	\param kind indicates direction to copy - src must be Device
*/
bool executive::Executive::deviceMemcpyToSymbol(const char *symbol, const void *src, size_t count, 
	size_t offset, MemcpyKind kind) {

	GlobalMap::iterator glb_it = globals.find(std::string(symbol));
	if (glb_it != globals.end()) {
		GlobalVariable & globalVar = glb_it->second;
		if (count + offset <= globalVar.size) {
			char *dstPtr = (char *)globalVar.host_pointer + offset;
			report("deviceMemcpyToSymbol('" << symbol << "') - dstPtr: " << (void *)dstPtr);
			::memcpy(dstPtr, src, count);\
		}
	}
	else {
		Ocelot_Exception("Attempted memcpy to unregistered global variable '" << symbol << "'");
	}
	
	return true;
}

/*!
	\brief copies to a symbol on the device
	\param symbol name of symbol
	\param src pointer to source data
	\param count number of bytes to copy
	\param offset offset to add to destination
	\param kind indicates direction to copy - src must be Device
*/
bool executive::Executive::deviceMemcpyFromSymbol(const char *symbol, void *dst, 
	size_t count, size_t offset, 	MemcpyKind kind) {
	
	GlobalMap::iterator glb_it = globals.find(std::string(symbol));
	if (glb_it != globals.end()) {
		GlobalVariable & globalVar = glb_it->second;

		if (count + offset <= globalVar.size) {
			char *srcPtr = (char *)globalVar.host_pointer + offset;
			report("deviceMemcpyFromSymbol('" << symbol << "') - srcPtr: " << (void *)srcPtr);
			::memcpy(dst, srcPtr, count);
		}
	}
	else {
		Ocelot_Exception("Attempted memcpy from unregistered global variable '" << symbol << "'");
	}
	
	return true;
}

/*!
	\brief copies a dense host buffer to a device array
*/
bool executive::Executive::deviceMemcpyToArray(struct cudaArray *array, void *host, 
	size_t wOffset, size_t hOffset, size_t bytes, MemcpyKind kind) {

	int addrSpace = getDeviceAddressSpace();
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(addrSpace);
	const MemoryAllocationMap & memoryMap = memoryMap_it->second;
	MemoryAllocationMap::const_iterator alloc_it = memoryMap.find((void *)array);
	if (alloc_it != memoryMap.end()) {
		const MemoryAllocation & memory = alloc_it->second;
		bool result = false;
		
		switch (addrSpace) {
		case 0:
			{
				char *ptr = (char *)memory.get() + memory.pointer.pitch * hOffset + wOffset;
				::memcpy(ptr, host, bytes);
				result = true;
			}
			break;

		default:
			if (getSelectedISA() == ir::Instruction::GPU) {
			
				CUDA_MEMCPY2D copy = {0};
				copy.srcXInBytes = 0;
				copy.srcMemoryType = CU_MEMORYTYPE_HOST;
				copy.srcY = 0;
				copy.srcHost = host;
				copy.srcPitch = memory.pointer.pitch;
				
				copy.dstArray = memory.cudaArray;
				copy.dstXInBytes = wOffset;
				copy.dstY = hOffset;
				copy.dstMemoryType = CU_MEMORYTYPE_ARRAY;

				size_t widthInBytes = memory.desc.size() * memory.extent.width - wOffset;
				if (widthInBytes > bytes) {
					copy.WidthInBytes = bytes;
					copy.Height = 1;
				}
				else {
					copy.WidthInBytes = widthInBytes;
					copy.Height = bytes / copy.WidthInBytes;
				}
				
				CUresult cuda = cuMemcpy2D(&copy);
				if (cuda == CUDA_SUCCESS) {
					result = true;
				}
				else {
					result = false;
					report("cuMemcpy2D() failed");
				}
				break;
			}
			assert(0 && "address space not supported");
		}
		
		return result;
	}

	return false;
}

/*!
	\brief copies a dense host buffer to a device array
*/
bool executive::Executive::deviceMemcpyFromArray(struct cudaArray *array, void *host, 
	size_t wOffset, size_t hOffset, size_t bytes, MemcpyKind kind) {

//	report("deviceMemcpyFromArray(w: " << wOffset << ", h: " << hOffset << ", " << bytes << " bytes");

	int addrSpace = getDeviceAddressSpace();
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(addrSpace);
	const MemoryAllocationMap & memoryMap = memoryMap_it->second;
	MemoryAllocationMap::const_iterator alloc_it = memoryMap.find((void *)array);
	if (alloc_it != memoryMap.end()) {
		const MemoryAllocation & memory = alloc_it->second;
		bool result = false;
		switch (addrSpace) {
		case 0:
			{
				char *ptr = (char *)memory.get() + memory.pointer.pitch * hOffset + wOffset;
				::memcpy(host, ptr, bytes);
				result = true;
			}
			break;

		default:
		
			if (getSelectedISA() == ir::Instruction::GPU) {
			
				CUDA_MEMCPY2D copy = {0};
				copy.dstXInBytes = 0;
				copy.dstMemoryType = CU_MEMORYTYPE_HOST;
				copy.dstY = 0;
				copy.dstHost = host;
				copy.dstPitch = memory.pointer.pitch;
				
				copy.srcArray = memory.cudaArray;
				copy.srcXInBytes = wOffset;
				copy.srcY = hOffset;
				copy.srcMemoryType = CU_MEMORYTYPE_ARRAY;

				size_t widthInBytes = memory.desc.size() * memory.extent.width - wOffset;
				if (widthInBytes > bytes) {
					copy.WidthInBytes = bytes;
					copy.Height = 1;
				}
				else {
					copy.WidthInBytes = widthInBytes;
					copy.Height = bytes / copy.WidthInBytes;
				}
				
				CUresult cuda = cuMemcpy2D(&copy);
				if (cuda == CUDA_SUCCESS) {
					result = true;
				}
				else {
					result = false;
					report("cuMemcpy2D() failed");
				}
				break;
			}
			assert(0 && "address space not supported");
			break;
		}
		
		return result;
	}

	return false;
}

/*!
	\brief copies a dense buffer from a device array to a device array
*/	
bool executive::Executive::deviceMemcpyArrayToArray(struct cudaArray *dst, size_t dstWOffset, 
	size_t dstHOffset, const struct cudaArray *src, size_t srcWOffset, size_t srcHOffset, 
	size_t count, MemcpyKind kind) {
	
	int addrSpace = getDeviceAddressSpace();
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(addrSpace);
	const MemoryAllocationMap & memoryMap = memoryMap_it->second;
	MemoryAllocationMap::const_iterator dstAlloc_it = memoryMap.find((void *)dst);
	MemoryAllocationMap::const_iterator srcAlloc_it = memoryMap.find((void *)src);
	if (dstAlloc_it != memoryMap.end() && srcAlloc_it != memoryMap.end()) {
		const MemoryAllocation & dstMemory = dstAlloc_it->second;
		const MemoryAllocation & srcMemory = srcAlloc_it->second;
		bool result = false;
					
		switch (addrSpace) {
		case 0:
			{
				char *srcPtr = (char *)srcMemory.get() + srcMemory.pointer.pitch * srcHOffset + 
					srcWOffset;
				char *dstPtr = (char *)dstMemory.get() + dstMemory.pointer.pitch * dstHOffset + 
					dstWOffset;
				::memcpy(dstPtr, srcPtr, count);
				result = true;	
			}
			break;

		default:
			if (getSelectedISA() == ir::Instruction::GPU) {
				
				report("Executive::deviceMemcpyArrayToArray()");
				report("  count: " << count << " bytes\n  dstWOff: " << dstWOffset 
					<< "\n  dstHOff: " << dstHOffset << "\n  srcWOff: " << srcWOffset
					<< "\n  srcHOff: " << srcHOffset);
				
				CUDA_MEMCPY2D copy = {0};
				copy.dstXInBytes = dstWOffset;
				copy.dstMemoryType = CU_MEMORYTYPE_ARRAY;
				copy.dstY = dstHOffset;
				copy.dstArray = dstMemory.cudaArray;
				
				copy.srcArray = srcMemory.cudaArray;
				copy.srcXInBytes = srcWOffset;
				copy.srcY = srcHOffset;
				copy.srcMemoryType = CU_MEMORYTYPE_ARRAY;

				copy.WidthInBytes = srcMemory.desc.size() * srcMemory.extent.width - srcWOffset;
				copy.Height = 1 + (count - 1) / copy.WidthInBytes;
				
				report("copy: " << copy.WidthInBytes << ", " << copy.Height);
				
				CUresult cuda = cuMemcpy2D(&copy);
				if (cuda == CUDA_SUCCESS) {
					result = true;
				}
				else {
					report("cuMemcpy2D() failed");
				}
				break;
			}

			assert(0 && "address space not supported");
			break;
		}
		
		return result;
	}

	return false;
}

/*!
	\brief copies from a dense buffer to a 2D buffer
*/
bool executive::Executive::deviceMemcpy2D(void *dst, size_t dstPitch, const void *src, 
	size_t srcPitch, size_t width, size_t height, MemcpyKind kind) {
	
	int addrSpace = getDeviceAddressSpace();
	
	switch (kind) {
		case HostToHost:
		{
			for (size_t row = 0; row < height; row++) {
				char *dstPtr = (char *)dst + dstPitch * row;
				char *srcPtr = (char *)src + srcPitch * row;
				::memcpy(dstPtr, srcPtr, width);
			}
		}
			break;
		case DeviceToHost:
		{
			MemoryAllocation srcAlloc = getMemoryAllocation(src);
			
			switch (addrSpace) {
				case 0:
				{
					for (size_t row = 0; row < height; row++) {
						char *dstPtr = (char *)dst + dstPitch * row;
						char *srcPtr = (char *)src + srcPitch * row;
						::memcpy(dstPtr, srcPtr, width);
					}
					return true;
				}
					break;
				default:
					assert(0 && "unimplemented");
					break;
			}
		}
			break;
		
		case HostToDevice:
		{
			MemoryAllocation dstAlloc = getMemoryAllocation(dst);
			switch (addrSpace) {
				case 0:
				{
					for (size_t row = 0; row < height; row++) {
						char *dstPtr = (char *)dst + dstPitch * row;
						char *srcPtr = (char *)src + srcPitch * row;
						::memcpy(dstPtr, srcPtr, width);
					}
					return true;
				}
					break;
				default:
					assert(0 && "unimplemented");
					break;
			}
		}
			break;
		case DeviceToDevice:
		{
			MemoryAllocation srcAlloc = getMemoryAllocation(src);
			MemoryAllocation dstAlloc = getMemoryAllocation(dst);
			switch (addrSpace) {
				case 0:
				{
					for (size_t row = 0; row < height; row++) {
						char *dstPtr = (char *)dst + dstPitch * row;
						char *srcPtr = (char *)src + srcPitch * row;
						::memcpy(dstPtr, srcPtr, width);
					}
					return true;
				}
					break;
				default:
					assert(0 && "unimplemented");
					break;
			}
	
		}
			break;
		
		default:
			return false;
	}

	return false;
}

/*!
	\brief memcpy from 2D block to array
	\param dst destinatino array
	\param wOffset destination x offset (bytes)
	\param hOffset destination y offset (rows)
	\param src source buffer
	\param spitch source block pitch (bytes)
	\param width source block width (bytes)
	\param height source block height (rows)
	\param kind kind of memcpy
	\return true if memcpy was sucessful
*/
bool executive::Executive::deviceMemcpy2DtoArray(struct cudaArray *dstArray, size_t wOffset, 
	size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, MemcpyKind kind) {

	int addrSpace = getDeviceAddressSpace();

	MemoryAllocation dstMemory = getMemoryAllocation((void *)dstArray);
	
	char *srcMemory_ptr = 0;
	switch (kind) {
		case HostToDevice:
		case HostToHost:
			srcMemory_ptr = (char *)src;
			break;
		case DeviceToDevice:
		{
			MemoryAllocation srcMemory = getMemoryAllocation(src);
			srcMemory_ptr = (char *)srcMemory.get();
		}
			break;
		default:
			assert(0 && "unimplemented");
			break;
	}

	switch (addrSpace) {
		case 0:
		{
			for (size_t row = 0; row < height; row++) {
				char *dstPtr = (char *)dstMemory.get() + dstMemory.pointer.pitch * row;
				char *srcPtr = (char *)srcMemory_ptr + spitch * row;
				::memcpy(dstPtr, srcPtr, width);
			}
			return true;
		}
			break;

	default:
		assert(0 && "unimplemented");
		return false;
	}

	return false;
}

bool executive::Executive::deviceMemcpy2DfromArray(void *dst, size_t dpitch, 
	const struct cudaArray *srcArray, size_t wOffset, size_t hOffset, size_t width, size_t height, 
	MemcpyKind kind) {

	int addrSpace = getDeviceAddressSpace();

	MemoryAllocation srcMemory = getMemoryAllocation((void *)srcArray);
	char *dstMemory_ptr = 0;
	switch (kind) {
		case DeviceToHost:
		case HostToHost:
			dstMemory_ptr = (char *)dst;
			break;
		case DeviceToDevice:
		{
			MemoryAllocation dstMemory = getMemoryAllocation(dst);
			dstMemory_ptr = (char *)dstMemory.get();
		}
			break;
		default:
			assert(0 && "unimplemented");
			break;
	}
	
	switch (addrSpace) {
		case 0:
		{
			for (size_t row = 0; row < height; row++) {
				char *dstPtr = (char *)dstMemory_ptr + dpitch * row;
				char *srcPtr = (char *)srcMemory.get() + srcMemory.pointer.pitch * row;
				::memcpy(dstPtr, srcPtr, width);
			}
			return true;
		}
			break;

	default:
		assert(0 && "unimplemented");
		return false;
	}

	return false;
}


/*!
	\brief performs a 3D memcpy to a destination 
	\param dst - pointer to either a CUDA array or a pitched allocation (.ptr field specifies a 
		memory allocation which informs Executive)
	\param dstPos - offset into destination block
	\param extent - width, height, and depth to copy
	\param kind - indicates whether source and destination are device or host
	\param src - pointer to either CUDA array or pitched allocation  (.ptr field specifies a memory 
		allocation which informs Executive)
	\param srcPos - offset into source block
*/
bool executive::Executive::deviceMemcpy3D(PitchedPointer dst, dim3 dstPos, Extent extent, 
	MemcpyKind kind, PitchedPointer src,	dim3 srcPos) {

	int addrSpace = getDeviceAddressSpace();

	report("deviceMemcpy3D() - extent: " << extent.width << ", " << extent.height << ", " 
		<< extent.depth << " - kind: " << kind);

	switch (kind) {
	case HostToHost:
	{
	}
		break;

	case HostToDevice:
	{
		MemoryAllocation memory = getMemoryAllocation(dst.ptr);
		dst = memory.pointer;
	}
		break;

	case DeviceToHost:
	{
		MemoryAllocation memory = getMemoryAllocation(src.ptr);
		src = memory.pointer;
	}
		break;

	case DeviceToDevice:
	{
		MemoryAllocation srcMemory = getMemoryAllocation(src.ptr);
		MemoryAllocation dstMemory = getMemoryAllocation(dst.ptr);
		dst = dstMemory.pointer;
		src = srcMemory.pointer;
	}
		break;
	
	default:
		return false;
	}

	report("  dst = (ptr: " << dst.ptr << ", pitch: " << dst.pitch << ", xsize: " 
		<< dst.xsize << ", ysize: " << dst.ysize << ")");

	report("  src = (ptr: " << src.ptr << ", pitch: " << src.pitch << ", xsize: " 
		<< src.xsize << ", ysize: " << src.ysize << ")");
	
	switch (addrSpace) {
	case 0:
	{
		// not arrays
		for (size_t z = 0; z < extent.depth; z++) {
			for (size_t y = 0; y < extent.height; y++) {
				char *dstPtr = (char *)dst.ptr + dstPos.x + dst.pitch * (
					(dstPos.y+y) + (z+dstPos.z) * dst.height);
				char *srcPtr = (char *)src.ptr + srcPos.x + src.pitch * (
					(srcPos.y+y) + (z+srcPos.z) * src.height);

				::memcpy(dstPtr, srcPtr, extent.width);
			}
		}
		return true;
	}
		break;
	default:
	{
	assert(0 && "unimplemented");
	}
		break;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// register functions

/*!
	\brief loads a PTX module
	\param path name of module
	\param ptx std::istream defining PTX module
*/
bool executive::Executive::loadModule(std::string path, bool translateOnLoad, std::istream & ptx) {

	//
	// parse PTX into a module with PTX kernels then translate to available devices
	//

	report("Loading module " << path << (translateOnLoad ? " translate on load" : ""));
	
	ir::Module *module = new ir::Module(path);
	module->load(ptx);
	module->modulePath = path;
	
	ModuleMap::iterator mod_it = modules.find(path);
	if (mod_it != modules.end()) {
		delete mod_it->second;
		modules.erase(mod_it);
	}
	
	modules.insert(std::make_pair(path, module));

	if (translateOnLoad) {
		translateModuleToISA(path, getSelectedISA(), true);
	}

	return true;
}

/*!
	\brief loads a module with a given name from a file
*/
bool executive::Executive::loadModule(std::string filename, bool translateOnLoad) {
	std::ifstream file(filename.c_str());
	return loadModule(filename, translateOnLoad, file);
}

void executive::Executive::registerGlobalVariable(const std::string & module, 
	const  std::string varName, void *hostPtr, void *devicePtr, size_t size, 
	DeviceAddressSpace addrSpace) {
	
	//
	// register global variables and allocate [if necessary] on available address spaces
	//

	report("Executive::registerGlobalVariable() - mod: '" << module 
		<< "', varName: '" << varName << "'");
	
	GlobalMap::iterator g_it = globals.find(varName);
	if (g_it == globals.end()) {
		GlobalVariable globalVar;
		globalVar.host_pointer = hostPtr;
		globalVar.size = size;
		globalVar.name = varName;
		globals[varName] = globalVar;
	}
	else {
		if (g_it->second.deviceAddressSpace != addrSpace) {
			Ocelot_Exception("previously registered global variable '" << varName 
				<< "' - in device address space " << g_it->second.deviceAddressSpace
				<< " - attempting to register with addr space " << addrSpace);
		}
	}

	GlobalVariable &globalVar = globals[varName];
	globalVar.modules[module].host = hostPtr;
	globalVar.modules[module].device = devicePtr;
	globalVar.modules[module].size = size;
	globalVar.deviceAddressSpace = addrSpace;

	if (size > globalVar.size) {
		globalVar.size = size;
		globalVar.host_pointer = hostPtr;
	}

	registerExternal(hostPtr, size, addrSpace);
}

void executive::Executive::registerTexture(const char *module, const char *name, int dimensions,
	int normalized) {

	//
	// register global variables and allocate [if necessary] on available address spaces
	//

	report("registerTexture() '" << module << "' - '" << name << "' - dimensions: " << dimensions 
		<< ", normalize: " << (bool)normalized);
	
	ir::Texture texture;
	texture.normalizedFloat = (bool)normalized;

	textures[name] = texture;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot kernel execution
//

/*!
	Gets a kernel by ISA, module, kernel name.

	\param isa instruction set of desired kernel
	\param moduleName name of module from which kernel is to be selected
	\param kernelName name of kernel

	\return instance of kernel with requested ISA or 0 on failure.
*/
ir::Kernel * executive::Executive::getKernel(ir::Instruction::Architecture isa, 
	const std::string& moduleName, const std::string& kernelName) {
	
	ir::Kernel * kernel	= 0;
	
	ModuleMap::iterator mod_it = modules.find(moduleName);
	if (mod_it != modules.end()) {
		kernel = mod_it->second->getKernel(isa, kernelName);
		if (!kernel) {
			translateModuleToISA(moduleName, isa, false);
			mod_it = modules.find(moduleName);
			if (mod_it != modules.end()) {
				kernel = mod_it->second->getKernel(isa, kernelName);
			}
		}
	}
	
	return kernel;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot device management

/*!
	inserts devices into device vector
*/
size_t executive::Executive::enumerateDevices() {
#if HAVE_CUDA_DRIVER_API == 1
	if (api::OcelotConfiguration::getExecutive().enableGPU) {

		if (cuInit(0) != CUDA_SUCCESS) {
			Ocelot_Exception("Executive::enumerateDevices() - failed to initialize CUDA driver ");
		}

		int gpus = 0;
		if (cuDeviceGetCount(&gpus) == CUDA_SUCCESS) {
			report("There are " << gpus << " gpus in system");
			for (int gpu = 0; gpu < gpus; gpu++) {
				CUdevprop_st devProp = {0};
				Device device;

				device.guid = gpu;
				device.ISA = ir::Instruction::GPU;
				device.addressSpace = 1 + gpu;

				if (cuDeviceGetProperties(&devProp, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception("Executive::enumerateDevices() - failed to get properties for GPU "
						<< gpu);
				}

				char deviceName[256] = {0};
				if (cuDeviceGetName(deviceName, 255, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception("Executive::enumerateDevices() - failed to get name for GPU " << gpu);
				}
				device.name = std::string(deviceName);
				unsigned int totalMemory = 0;
				if (cuDeviceTotalMem(&totalMemory, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception("Executive::enumerateDevices() - failed to get totalMemory for GPU " 
						<< gpu);
				}
				device.totalMemory = (size_t)totalMemory;

				if (cuDeviceGetAttribute(&device.multiprocessorCount,
					CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get multiprocessorCount for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.memcpyOverlap,
					CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get memcpyOverlap for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.maxThreadsPerBlock,
					CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get maxThreadsPerBlock for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.maxThreadsDim[0],
					CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get maxThreadsDim.x for GPU " 
						<< gpu);
				}
				if (cuDeviceGetAttribute(&device.maxThreadsDim[1],
					CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get maxThreadsDim.y for GPU " 
						<< gpu);
				}
				if (cuDeviceGetAttribute(&device.maxThreadsDim[2],
					CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get maxThreadsDim.z for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.maxGridSize[0],
					CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get maxGridSize.x for GPU " 
						<< gpu);
				}
				if (cuDeviceGetAttribute(&device.maxGridSize[1],
					CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get maxGridSize.y for GPU " 
						<< gpu);
				}
				if (cuDeviceGetAttribute(&device.maxGridSize[2],
					CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get maxGridSize.z for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.sharedMemPerBlock,
					CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get sharedMemPerBlock for GPU " 
						<< gpu);
				}
				if (cuDeviceGetAttribute(&device.totalConstantMemory,
					CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get totalConstantMemory for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.SIMDWidth,
					CU_DEVICE_ATTRIBUTE_WARP_SIZE, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get SIMDWidth for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.memPitch,
					CU_DEVICE_ATTRIBUTE_MAX_PITCH, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get memPitch for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.regsPerBlock,
					CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get regsPerBlock for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.clockRate,
					CU_DEVICE_ATTRIBUTE_CLOCK_RATE, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get clockRate for GPU " 
						<< gpu);
				}

				if (cuDeviceGetAttribute(&device.textureAlign,
					CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get textureAlign for GPU " 
						<< gpu);
				}

				if (cuDeviceComputeCapability(&device.major, &device.minor, gpu) != CUDA_SUCCESS) {
					Ocelot_Exception(
						"Executive::enumerateDevices() - failed to get compute capability for GPU " 
						<< gpu);
				}

				devices.push_back(device);
			}
		}
	}
#endif

	if (api::OcelotConfiguration::getExecutive().enableEmulated) {
		// emulator
		Device device;
		device.ISA = ir::Instruction::Emulated;
		device.name = "Ocelot PTX Emulator";
		device.guid = 8803;
		device.totalMemory = get_avphys_pages() * getpagesize();
		device.multiprocessorCount = sysconf(_SC_NPROCESSORS_ONLN);
		device.memcpyOverlap = 0;
		device.maxThreadsPerBlock = 512;
		device.maxThreadsDim[0] = 512;
		device.maxThreadsDim[1] = 512;
		device.maxThreadsDim[2] = 64;
		device.maxGridSize[0] = 65535;
		device.maxGridSize[1] = 65535;
		device.maxGridSize[2] = 1;
		device.sharedMemPerBlock = 16384;
		device.totalConstantMemory = 65536;
		device.SIMDWidth = device.maxThreadsPerBlock;
		device.memPitch = device.totalMemory;
		device.regsPerBlock = MIN( INT_MAX, device.totalMemory );
		device.clockRate = 2000000;
		device.textureAlign = 1;
		device.major = 1;
		device.minor = 3;

		devices.push_back(device);
		
		if (devices.size() == 1 || 
			api::OcelotConfiguration::getExecutive().preferredISA == device.ISA) {

			selectDevice((int)devices.size() - 1);
		}
	}

#ifdef HAVE_LLVM 
	if (api::OcelotConfiguration::getExecutive().enableLLVM) {
		// multicore
		Device device;
		device.ISA = ir::Instruction::LLVM;
		device.name = "Ocelot LLVM JIT-Compiler";
		device.guid = 8833;
		device.totalMemory = get_avphys_pages() * getpagesize();
		device.multiprocessorCount = sysconf(_SC_NPROCESSORS_ONLN);
		device.memcpyOverlap = 0;
		device.maxThreadsPerBlock = 512;
		device.maxThreadsDim[0] = 512;
		device.maxThreadsDim[1] = 512;
		device.maxThreadsDim[2] = 64;
		device.maxGridSize[0] = 65535;
		device.maxGridSize[1] = 65535;
		device.maxGridSize[2] = 1;
		device.sharedMemPerBlock = 16384;
		device.totalConstantMemory = 65536;
		device.SIMDWidth = 1;
		device.memPitch = device.totalMemory;
		device.regsPerBlock = MIN( INT_MAX, device.totalMemory );
		device.clockRate = 2000000;
		device.textureAlign = 1;
		device.major = 1;
		device.minor = 3;
		report( " Initialized PTX-To-LLVM JIT." );

		devices.push_back(device);

		if (api::OcelotConfiguration::getExecutive().preferredISA == device.ISA) {
			selectDevice((int)devices.size() - 1);
		}
	}#endif

	return devices.size();
}

/*! 
	selects a device [ this is intended to be a low-cost operation called at every CUDA runtime 
	API call]
*/
bool executive::Executive::selectDevice(int device) {
	if (device != selectedDevice && device >= 0 && device < (int)devices.size()) {
		selectedDevice = device;
		report("Executive::selectDevice(" << device << ") - " << devices[selectedDevice].name);

		if (devices[selectedDevice].ISA == ir::Instruction::GPU) {
			Device & device = devices[selectedDevice];
#if HAVE_CUDA_DRIVER_API == 1
#if CUDA_OPENGL_INTEROPERABILITY == 1
			if (cuGLCtxCreate(&device.cudaContext, CU_CTX_MAP_HOST, device.guid) != CUDA_SUCCESS) {
				Ocelot_Exception("Executive::selectDevice() - failed to create GL context on device " 
					<< device.name);
			}
			if (cuGLInit() != CUDA_SUCCESS) {
				Ocelot_Exception("Executive::selectDevice() - failed to initialize GL interoperability on device "
					<< device.name);
			}
			report(" created CUDA GL context");
#else
			if (cuCtxCreate(&device.cudaContext, CU_CTX_MAP_HOST, device.guid) != CUDA_SUCCESS) {
				Ocelot_Exception("Executive::selectDevice() - failed to crete context on device " 
					<< device.name);
			}
			report(" created CUDA context without OpenGL support");
#endif

#else
			return false;
#endif			
		}
	}
	return true;
}

/*! 
	gets selected device identifier
*/
int executive::Executive::getSelectedDevice() const {
	return selectedDevice;
}

/*!
	gets the ISA of the selected device
*/
ir::Instruction::Architecture executive::Executive::getSelectedISA() const {
	return devices[selectedDevice].ISA;
}

/*!
	indicates preferred ISA [device will be chosen if available]
*/
void executive::Executive::setPreferredISA(ir::Instruction::Architecture isa) {
	assert(0 && "unimplemented");
}

bool executive::Executive::selectDeviceByISA(ir::Instruction::Architecture isa) {
	size_t n = 0;
	for (; n < devices.size(); n++) {
		if (devices[n].ISA == isa) {
			return selectDevice((int)n);
		}
	}
	return false;
}

/*! 
	\brief only listed devices may be selected
*/
void executive::Executive::filterDevices(std::vector<int> & devices) {
	assert(0 && "unimplemented");
}

/*!
	\brief only devices with listed ISAs may be selected
*/
void executive::Executive::filterISAs(std::vector<int> & ISAs) {
	assert(0 && "unimplemented");
}

/*!
	\brief returns the address space of the selected device
*/
int executive::Executive::getDeviceAddressSpace() const {
	return devices[selectedDevice].addressSpace;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot translation settings
//

/*!
	\brief This sets the optimization level 

	\param l The new optimization level.
*/
void executive::Executive::setOptimizationLevel(translator::Translator::OptimizationLevel l) {

}

/*!
	\brief ensures that all kernels have an executable translation for the indicated ISA	
*/
void executive::Executive::translateAllToISA(ir::Instruction::Architecture isa, bool retranslate) {
	ModuleMap::iterator mod_it = modules.begin();
	for (; mod_it != modules.end(); ++mod_it) {
		if (mod_it->second->kernels.find(ir::Instruction::PTX) != mod_it->second->kernels.end()) {
			ir::Module::KernelMap & target = mod_it->second->kernels[ir::Instruction::PTX];
			for (ir::Module::KernelMap::iterator k_it = target.begin(); k_it != target.end(); 
				++k_it) {
				
				if (retranslate || mod_it->second->kernels[isa].find(k_it->second->name) ==
					mod_it->second->kernels[isa].end()) {
					translateToISA(isa, mod_it->first, k_it->second->name);
				}
			}
		}
	}
}

/*!

*/
void executive::Executive::translateModuleToISA(std::string moduleName, 
	ir::Instruction::Architecture isa, bool retranslate) {
	
	ModuleMap::iterator mod_it = modules.find(moduleName);
	if (mod_it != modules.end()) {
		if (mod_it->second->kernels.find(ir::Instruction::PTX) != mod_it->second->kernels.end()) {
			ir::Module::KernelMap & target = mod_it->second->kernels[ir::Instruction::PTX];
			for (ir::Module::KernelMap::iterator k_it = target.begin(); k_it != target.end(); 
				++k_it) {
				
				if (retranslate || mod_it->second->kernels[isa].find(k_it->second->name) ==
					mod_it->second->kernels[isa].end()) {
					translateToISA(isa, mod_it->first, k_it->second->name);
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot kernel launch and synchronization functions
//

/*!
	\brief translates a kernel to the given ISA and inserts it into the module map
	\param isa ISA to translate to
	\param module name of module to which kernel belongs
	\param kernel name of kernel
	\return translated kernel or NULL on translation failure
*/
ir::Kernel *executive::Executive::translateToISA(ir::Instruction::Architecture isa, 
	const std::string &moduleName, const std::string &kernelName) {
	
	report("Executive::translateToISA(" << isa << ", module: " << moduleName 
		<< ", kernel: " << kernelName);
	
	ModuleMap::iterator mod_it = modules.find(moduleName);
	if (mod_it == modules.end()) {
		report("failed to find named module");
		throw hydrazine::Exception("failed to find module registerd with Ocelot");
	}
	
	ir::Kernel *translated = 0;
	ir::Kernel *kernel = mod_it->second->getKernel(ir::Instruction::PTX, kernelName);

	// translate
	switch (isa) {
		case ir::Instruction::Emulated:
		{
			EmulatedKernel *emuKernel = new EmulatedKernel(kernel, this);
			translated = emuKernel;
		}
		break;
	
		case ir::Instruction::LLVM:
		{
			LLVMExecutableKernel* llvmKernel = new LLVMExecutableKernel(*kernel, this, 
				optimizationLevel);

			llvmKernel->setDevice(&devices[getSelected()], hostWorkerThreads);
			//
			// ...
			//
			translated = llvmKernel;
		}
		break;
	
		case ir::Instruction::GPU:
		{
			//
			//
			assert(0 && "unimplemented");
		}
		break;
	
		default:
			break;
	}
	
	// insert kernel
	if (translated) {
		mod_it->second->kernels[isa][translated->name] = translated;
	}
	
	return translated;
}


/*!
	\brief limits the number of working threads available
*/
void executive::Executive::setWorkerThreadLimit(int limit) {
	hostWorkerThreads = limit;
}

/*!
	\brief determines whether kernel exceeds memory bounds through static analysis
	\param exeKernel executable kernel under test
	\param sharedMemory size of dynamic shared memory
	\param paramSize size of parameter memory
	\return true if kernel meets memory capacity
*/
bool executive::Executive::verifyKernelMemoryBounds(ir::ExecutableKernel *exeKernel, 
	size_t sharedMemory, size_t paramSize) {

	const executive::Device & device = devices[getSelected()];

	//
	// Ensure enough shared memory is available
	//
	size_t dynamicSharedSize = exeKernel->sharedMemorySize() + sharedMemory;
	if(dynamicSharedSize > (size_t)device.sharedMemPerBlock) {
#if CUDA_VERBOSE == 1
		std::cerr << "==Ocelot== Out of shared memory for kernel \""
			<< kernel->name 
			<< "\" : \n==Ocelot==\tpreallocated ";
		std::cerr << exeKernel->sharedMemorySize() << " + requested " 
			<< sharedMemory
			<< " is greater than available " 
			<< device.sharedMemPerBlock 
			<< " for device " << device.name 
			<< "\n" << std::flush;
#endif
		return false;
	}

	if((size_t)exeKernel->constMemorySize() > (size_t)device.totalConstantMemory) {
#if CUDA_VERBOSE == 1
		std::cerr << "==Ocelot== Out of const memory for kernel \"" 
			<< exeKernel->name 
			<< "\" : \n==Ocelot==\tpreallocated ";
		std::cerr << exeKernel->constMemorySize() 
			<< " is greater than available " 
			<< device.totalConstantMemory 
			<< " for device " << device.name << "\n" << std::flush;
#endif
		return false;
	}

	return true;
}

/*!
	\brief helper function for launching a kernel
	\param module module name
	\param kernel kernel name
	\param grid grid dimensions
	\param block block dimensions
	\param sharedMemory shared memory size
	\param parameterBlock array of bytes for parameter memory
	\param parameterBlockSize number of bytes in parameter memory
*/
void executive::Executive::launch(const std::string & moduleName, const std::string & kernelName,
	dim3 grid, dim3 block, size_t sharedMemory, unsigned char *parameterBlock,
	size_t parameterBlockSize) {
	// launch with no trace generators
	launch(moduleName, kernelName, grid, block, sharedMemory, parameterBlock, 
		parameterBlockSize, trace::TraceGeneratorVector());
}

/*!
	\brief helper function for launching a kernel
	\param module module name
	\param kernel kernel name
	\param grid grid dimensions
	\param block block dimensions
	\param sharedMemory shared memory size
	\param parameterBlock array of bytes for parameter memory
	\param parameterBlockSize number of bytes in parameter memory
	\param traceGenerators vector of trace generators to run on kernel
*/
void executive::Executive::launch(const std::string & moduleName, const std::string & kernelName,
	dim3 grid, dim3 block, size_t sharedMemory, unsigned char *parameterBlock,
	size_t parameterBlockSize, const trace::TraceGeneratorVector & traceGenerators) {
	
	report("launch('" << moduleName << "', '" << kernelName << "')");
	report("   grid: " << grid.x << ", " << grid.y << ", " << grid.z);
	report("  block: " << block.x << ", " << block.y << ", " << block.z);
	report("  shmem: " << sharedMemory);
	report("  param block size: " << parameterBlockSize << " bytes");

	ir::Instruction::Architecture isa = getSelectedISA();
	ir::Kernel *kernel = getKernel(isa, moduleName, kernelName);
	if (!kernel) {
		kernel = translateToISA(isa, moduleName, kernelName);
	}
	ir::ExecutableKernel *exeKernel = static_cast<ir::ExecutableKernel *>(kernel);	
	
	fenceGlobalVariables();

	if (!verifyKernelMemoryBounds(exeKernel, sharedMemory, parameterBlockSize)) {
		return;
	}

	if (isa == ir::Instruction::Emulated && api::OcelotConfiguration::getTrace().enabled) {
		for( trace::TraceGeneratorVector::const_iterator gen = traceGenerators.begin(); 
			gen != traceGenerators.end(); ++gen) {
			exeKernel->addTraceGenerator( *gen );
		}
	}

	exeKernel->setKernelShape(block.x, block.y, block.z);

	if (parameterBlockSize) {
		exeKernel->setParameterBlock(parameterBlock, parameterBlockSize);
	}

	exeKernel->updateParameterMemory();
	exeKernel->updateMemory();
	if (sharedMemory) {
		exeKernel->setExternSharedMemorySize(sharedMemory);
	}
	
	try {
		exeKernel->launchGrid(grid.x, grid.y);
	}
	catch (executive::RuntimeException &exp) {
		report("Runtime exception: " << exp.toString());
		throw;
	}

	if (isa == ir::Instruction::Emulated && api::OcelotConfiguration::getTrace().enabled) {
		// remove trace generators
		if (api::OcelotConfiguration::get().trace.enabled) {
			for( trace::TraceGeneratorVector::const_iterator gen = traceGenerators.begin(); 
				gen != traceGenerators.end(); ++gen) {
				exeKernel->removeTraceGenerator( *gen );
			}
		}
	}
}
	
/*!
	\brief block on kernel executing on selected device
*/
void executive::Executive::synchronize() {
	ir::Instruction::Architecture isa = getSelectedISA();
	switch (isa) {
		case ir::Instruction::Emulated:	// fall through
		case ir::Instruction::LLVM:
			break;
		case ir::Instruction::GPU:
			break;
		default:
			break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Global variable synchronization
//

void executive::Executive::fenceGlobalVariables() {
	if (getDeviceAddressSpace()) {
		assert(0 && "devices with non-system address spaces not yet supported");
		for (GlobalMap::iterator glb_it = globals.begin(); glb_it != globals.end(); ++glb_it) {
			// do something
		}
	}
	else {
		//
		// do something else entirely
		//
		MemoryAllocationMap &memoryMap = memoryAllocations[getDeviceAddressSpace()];

		report("Executive::fenceGlobalVariables()");

		for (GlobalMap::iterator glb_it = globals.begin(); glb_it != globals.end(); ++glb_it) {
			// do something about each module

			report("  global: " << glb_it->first);			

			if (glb_it->second.deviceAddressSpace != Device_shared) {
				GlobalVariable::ModulePointerMap::iterator mod_it = glb_it->second.modules.begin();
				for (; mod_it != glb_it->second.modules.end(); ++mod_it) {

					ir::Global & global = modules[mod_it->first]->globals[glb_it->first];

					if (global.pointer && !global.local) {
						::memcpy(global.pointer, glb_it->second.host_pointer, glb_it->second.size);
					}
					else if (!global.pointer) {
						global.pointer = (char *)glb_it->second.host_pointer;
						global.registered = true;
						global.local = true;
					}

					if (memoryMap.find(global.pointer) == memoryMap.end()) {
						registerExternal(global.pointer, glb_it->second.size);
					}
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Texture binding and unbinding functions

/*!
	\brief binds a texture by name to a pointer to a device memory allocation
	\param offset [out] offset that must be added to fetches to achieved desired pixel
	\param texture name of texture
	\param devPtr device memory allocation
	\param format channel description
	\param size bytes in texture
	\return true on success
*/
bool  executive::Executive::bindTexture(size_t *offset, const std::string & textureName, 
	const void *devPtr, const ChannelFormatDesc &format, size_t size, 
	ir::Texture::AddressMode *addrMode, ir::Texture::Interpolation filter, bool normalized) {

	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {
		ir::Texture &texture = tex_it->second;

		texture.x = format.x;
		texture.y = format.y;
		texture.z = format.z;
		texture.w = format.w;

		report("Executive::bindTexture() - texture.xyzq = " << texture.x << ", " << texture.y 
			<< ", " << texture.z << ", " << texture.w);

		switch (format.kind) {
			case ChannelFormatDesc::Kind_signed:
				report("Executive::bindTexture() - format.type signed");
				texture.type = ir::Texture::Signed;
				break;
			case ChannelFormatDesc::Kind_unsigned:
				report("Executive::bindTexture() - format.type unsigned");
				texture.type = ir::Texture::Unsigned;
				break;
			case ChannelFormatDesc::Kind_float:
				report("Executive::bindTexture() - format.type float");
				texture.type = ir::Texture::Float;
				break;
			default:
				report("Executive::bindTexture() - format.type == Kind_invalid");
				texture.type = ir::Texture::Invalid;
				break;
		}

		texture.size.x = size;
		texture.size.y = 0;
		texture.data = (void *)devPtr;

		texture.interpolation = filter;
		texture.normalize = normalized;

		for (unsigned int i = 0; i < 3; i++) {
			texture.addressMode[i] = addrMode[i];
		}

		if (offset) {
			*offset = (size_t)devPtr % 16;
		}

		report("Executive::bindTexture() '" << textureName << "'.data = " << texture.data 
			<< " - filter: " << filter);
	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
		return false;
	}

	return true;
}

/*!
	\brief binds a 2D texture by name to a device pointer with a given width, height, and pitch
	\param offset [out] offset that must be added to fetches to achieved desired pixel
	\param textureName name of texture
	\param devPtr device memory allocation
	\param format channel description
	\param width width of texture in texels
	\param height height of texture in texels
	\param pitch number of bytes between texels of the same column in consecutive rows
	\return true on success
*/
bool executive::Executive::bindTexture2D(size_t *offset, const std::string & textureName, 
	const void *devPtr, const ChannelFormatDesc &format, size_t width, size_t height, size_t pitch,
	ir::Texture::AddressMode *addrMode, ir::Texture::Interpolation filter, bool normalized) {

	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {
		ir::Texture &texture = tex_it->second;

		texture.x = format.x;
		texture.y = format.y;
		texture.z = format.z;
		texture.w = format.w;

		report("Executive::bindTexture2D() - texture.xyzq = " << texture.x << ", " << texture.y 
			<< ", " << texture.z << ", " << texture.w);

		switch (format.kind) {
			case ChannelFormatDesc::Kind_signed:
				report("Executive::bindTexture2D() - format.type signed");
				texture.type = ir::Texture::Signed;
				break;
			case ChannelFormatDesc::Kind_unsigned:
				report("Executive::bindTexture2D() - format.type unsigned");
				texture.type = ir::Texture::Unsigned;
				break;
			case ChannelFormatDesc::Kind_float:
				report("Executive::bindTexture2D() - format.type float");
				texture.type = ir::Texture::Float;
				break;
			default:
				report("Executive::bindTexture2D() - format.type == Kind_invalid");
				texture.type = ir::Texture::Invalid;
				break;
		}

		texture.size.x = width;
		texture.size.y = height;
		texture.data = (void *)devPtr;

		texture.interpolation = filter;
		texture.normalize = normalized;

		for (unsigned int i = 0; i < 3; i++) {
			texture.addressMode[i] = addrMode[i];
		}

		if (offset) {
			*offset = (size_t)devPtr % 16;
		}

		report("Executive::bindTexture2D() '" << textureName << "'.data = " << texture.data 
			<< " - filter: " << filter);
	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
		return false;
	}

	return true;
}

/*!
	\brief binds a texture to an array
*/
bool executive::Executive::bindTextureToArray(const std::string & textureName, void *array, 
	const ChannelFormatDesc &format, ir::Texture::AddressMode *addrMode, 
	ir::Texture::Interpolation filter, bool normalized) {
	
	// lookup the array
	int addrSpace = getDeviceAddressSpace();
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(addrSpace);
	const MemoryAllocationMap & memoryMap = memoryMap_it->second;
	MemoryAllocationMap::const_iterator alloc_it = memoryMap.find((void *)array);
	
	const MemoryAllocation & memory = alloc_it->second;

	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {
		ir::Texture &texture = tex_it->second;

		texture.x = format.x;
		texture.y = format.y;
		texture.z = format.z;
		texture.w = format.w;

		report("Executive::bindTextureToArray() - texture.xyzw = " << texture.x << ", " << texture.y 
			<< ", " << texture.z << ", " << texture.w);

		switch (format.kind) {
			case ChannelFormatDesc::Kind_signed:
				report(" - format.type signed");
				texture.type = ir::Texture::Signed;
				break;
			case ChannelFormatDesc::Kind_unsigned:
				report(" - format.type unsigned");
				texture.type = ir::Texture::Unsigned;
				break;
			case ChannelFormatDesc::Kind_float:
				report(" - format.type float");
				texture.type = ir::Texture::Float;
				break;
			default:
				report(" - format.type == Kind_invalid");
				texture.type = ir::Texture::Invalid;
				break;
		}

		texture.size.x = memory.pointer.xsize;
		texture.size.y = memory.pointer.ysize;
		texture.size.z = memory.extent.depth;
		texture.data = (void *)memory.get();

		texture.interpolation = filter;
		texture.normalize = normalized;

		for (unsigned int i = 0; i < 3; i++) {
			texture.addressMode[i] = addrMode[i];
		}

		report(" - '" << textureName << "'.data = " << texture.data << " - filter: " << filter);
	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
		return false;
	}

	return true;
}

/*!
	\brief unbinds a previously bound texture
*/
void executive::Executive::unbindTexture(const std::string & textureName) {
	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {
		ir::Texture &texture = tex_it->second;
		texture.data = 0;
	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
	}
}

/*!
	gets alignment of a named texture
*/
size_t executive::Executive::getTextureAlignmentOffset(const std::string & textureName) {
	size_t offset = 0;
	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {

	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
	}
	return offset;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// end

