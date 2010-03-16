/*!
	\file ApplicationState.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief defines constructors and accessors for Ocelot application state objects
*/


// C++ includes
#include <sstream>
#include <cstring>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/interface/Casts.h>

// CUDA driver API includes
#if (HAVE_CUDA_DRIVER_API == 1)
#include <ocelot/cuda/include/cuda.h>
#endif

// Ocelot includes
#include <ocelot/executive/interface/ApplicationState.h>

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

#if (HAVE_CUDA_DRIVER_API == 1)

static void convert(CUDA_ARRAY_DESCRIPTOR *descriptor, const executive::ChannelFormatDesc &desc) {

	descriptor->NumChannels = desc.channels();
	unsigned int bits = (desc.size() / desc.channels());
	if (bits > 2) bits = 3;
	
	switch (desc.kind) {
	case executive::ChannelFormatDesc::Kind_unsigned:
		descriptor->Format = (CUarray_format)bits;
		break;
	case executive::ChannelFormatDesc::Kind_signed:
		descriptor->Format = (CUarray_format)(7 + bits);
		break;
	case executive::ChannelFormatDesc::Kind_float:
		descriptor->Format = (CUarray_format)(bits == 2 ? 0x10 : 0x20);
		break;
	default:
		report("unknown ChannelFormatDesc::Kind");
	}
}
#endif

static size_t getOffset(void* pointer) {
	size_t address = (size_t)pointer;
	size_t remainder = address % 16;
	size_t offset = remainder == 0 ? 0 : 16 - remainder;
	return offset;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
executive::MemoryAllocation::MemoryAllocation(int space, void *ptr, size_t bytes):
	structure(Struct_linear),
	dimension(Dim_1D),
	affinity(Affinity_device),
	addressSpace(space),
	allocationSize(bytes),
	flags(0),
	internal(false) {

	pointer.ptr = ptr;
	pointer.offset = 0;
	pointer.xsize = bytes;
	pointer.pitch = bytes;
	pointer.ysize = 1;

	extent.width = bytes;
	extent.height = 1;
	extent.depth = 1;
}

executive::MemoryAllocation::MemoryAllocation(int space, size_t size):
	structure(Struct_linear),
	dimension(Dim_1D),
	affinity(Affinity_device),
	addressSpace(space),
	allocationSize(size),
	flags(0),
	internal(true) {
	
	pointer.xsize = size;
	pointer.pitch = size;
	pointer.ysize = 1;
	
	extent.width = size;
	extent.height = 1;
	extent.depth = 1;
	
	switch (addressSpace) {
	case 0:
		{
			pointer.ptr = (void *)::malloc(size + 16);
			pointer.offset = getOffset(pointer.ptr);
		}
		break;
		
	default:
#if HAVE_CUDA_DRIVER_API == 1
		CUdeviceptr ptr = 0;
		CUresult cuda  = cuMemAlloc(&ptr, size);
		if (cuda == CUDA_SUCCESS) {
			pointer.ptr = reinterpret_cast<void *>(ptr);
		}
		else {
			pointer.ptr = 0;
		}
		pointer.offset = 0;
#else		
		assert(0 && "no support for gpu devices");
#endif
		break;
	}
}

executive::MemoryAllocation::MemoryAllocation(size_t size, 
	bool portable, bool mapped, bool writeCombined):
	structure(Struct_linear),
	dimension(Dim_1D),
	affinity(Affinity_host),
	addressSpace(0),
	allocationSize(size),
	flags(0),
	internal(true) {
	
	pointer.xsize = size;
	pointer.pitch = size;
	pointer.ysize = 1;
	
	pointer.ptr = (void *)::malloc(size + 16);
	pointer.offset = getOffset(pointer.ptr);
	extent.width = size;
	extent.height = 1;
	extent.depth = 1;
}


executive::MemoryAllocation::MemoryAllocation(int space, size_t width, size_t height):
	structure(Struct_pitch),
	dimension(Dim_2D),
	affinity(Affinity_device),
	addressSpace(space),
	allocationSize(width * height),
	flags(0),
	internal(true) {

	switch (addressSpace) {
	case 0:
		{
			pointer.ptr = (void *)::malloc(allocationSize + 16);
			pointer.offset = getOffset(pointer.ptr);
			pointer.pitch = width;
			extent.width = width;
			extent.height = height;
			extent.depth = 1;
		}
		break;
	default:
		{
		// device is in GPU memory somewhere
#if HAVE_CUDA_DRIVER_API == 1
			CUdeviceptr devPtr = 0;
			unsigned int devPitch = 0;
			CUresult result = cuMemAllocPitch(&devPtr, &devPitch, width, height, 16);
			if (result == CUDA_SUCCESS){
				pointer.ptr = (void *)devPtr;
				pointer.offset = 0;
				pointer.pitch = (size_t)devPitch;
				extent.width = width;
				extent.height = height;
				extent.depth = 1;
			}
			else {
				report("MemoryAllocation(width, height) - cuMemAllocPitch() failed with error "
					<< result);
				pointer.ptr = 0;
			}
#else
			assert(0 && "unimplemented");
#endif
		}
		break;
	}
}

executive::MemoryAllocation::MemoryAllocation(int space, const Extent& e):
	structure(Struct_pitch),
	dimension(Dim_1D),
	affinity(Affinity_device),
	addressSpace(space),
	extent(e),
	allocationSize(extent.width * extent.height * extent.depth),
	flags(0),
	internal(true) {

	if (extent.depth > 1) {
		dimension = MemoryAllocation::Dim_3D;
	}
	else if (extent.height > 1) {
		dimension = MemoryAllocation::Dim_2D;
	}
	else if (extent.width >= 1) {
		dimension = MemoryAllocation::Dim_1D;
	}
	else {
		Ocelot_Exception("Executive::mallocPitch() - invalid extent");
	}
		
	switch (addressSpace) {
	case 0:
		{
			pointer.ptr = (void *)::malloc(allocationSize + 16);
			pointer.offset = getOffset(pointer.ptr);
			pointer.pitch = extent.width;
			pointer.width = extent.width;
			pointer.height = extent.height;
		}
		break;
	default:
		// device is in GPU memory somewhere
		assert(0 && "unimplemented");		
		break;
	}
}

executive::MemoryAllocation::MemoryAllocation(int space, 
	const ChannelFormatDesc& d, size_t width, size_t height):
	structure(Struct_array),
	dimension(Dim_2D),
	affinity(Affinity_device),
	addressSpace(space),
	desc(d),
	allocationSize(width * desc.size() * height),
	flags(0),
	internal(true) 
{

	pointer.xsize = width;
	pointer.ysize = height;
	pointer.pitch = width * desc.size();
	extent.width = width;
	extent.height = height;
	
	switch (addressSpace) {
	case 0:
		{
			// device is in host memory
			pointer.ptr = (void *)::malloc(allocationSize + 16);
			pointer.offset = getOffset(pointer.ptr);
		}
		break;
	default:
#if HAVE_CUDA_DRIVER_API == 1
		CUDA_ARRAY_DESCRIPTOR descriptor = {0};
		convert(&descriptor, desc);
		descriptor.Width = width;
		descriptor.Height = height;
		pointer.offset = 0;
		CUresult result = cuArrayCreate(&cudaArray, &descriptor);
		if (result != CUDA_SUCCESS) {
			report("failed to allocate CUDA array on GPU with error " << result);
			pointer.ptr = 0;
		}
		else {
			pointer.ptr = (void *)cudaArray;
			report("successfully allocated array of size " <<
				allocationSize << " to address " << pointer.ptr 
				<< " - (w: " << width << ", h: " << height << ")");
		}
#else
		assert(0 && "unimplemented");
#endif
	}
}

executive::MemoryAllocation::MemoryAllocation(int space, 
	const ChannelFormatDesc &d, const Extent& e):
	structure(Struct_array),
	dimension(Dim_2D),
	affinity(Affinity_device),
	addressSpace(space),
	extent(e),
	desc(d),
	allocationSize(extent.width * extent.height * desc.size() * extent.depth),
	flags(0),
	internal(true) {

	if (extent.depth > 1) {
		dimension = MemoryAllocation::Dim_3D;
	}
	else if (extent.height > 1) {
		dimension = MemoryAllocation::Dim_2D;
	}
	else if (extent.width >= 1) {
		dimension = MemoryAllocation::Dim_1D;
	}
	else {
		Ocelot_Exception("Executive::mallocPitch() - invalid extent");
	}
	
	switch (addressSpace) {
	case 0:
		{
			pointer.pitch = extent.width * desc.size();
			pointer.ptr = (void *)::malloc(allocationSize + 16);
			pointer.offset = getOffset(pointer.ptr);
			pointer.width = extent.width;
			pointer.height = extent.height;
		}
		break;
	default:
		assert(0 && "unimplemented");
		break;
	}
}

executive::MemoryAllocation::MemoryAllocation():
	structure(Struct_linear),
	dimension(Dim_1D),
	affinity(Affinity_host),
	addressSpace(0),
	allocationSize(0),
	flags(0),
	internal(true) {

	pointer.offset = 0;
	pointer.ptr = 0;
	pointer.xsize = pointer.ysize = pointer.pitch = 0;
	extent.width = extent.height = extent.depth = 0;
}

executive::MemoryAllocation::MemoryAllocation(const MemoryAllocation& m):
	structure(m.structure),
	dimension(m.dimension),
	affinity(m.affinity),
	addressSpace(m.addressSpace),
	pointer(m.pointer),
	extent(m.extent),
	desc(m.desc),
	allocationSize(m.size()),
	flags(m.flags),
	internal(m.internal) {
	if (m.size() == 0) return;
	if (internal) {
		if (addressSpace) {
#if HAVE_CUDA_DRIVER_API == 1
			CUdeviceptr ptr = 0;
			CUresult cuda  = cuMemAlloc(&ptr, size());
			if (cuda == CUDA_SUCCESS) {
				pointer.ptr = reinterpret_cast<void *>(ptr);
			}
			else {
				assert( 0 && "cuMemAlloc failed!");
			}
			cuda = cuMemcpyDtoD(ptr, hydrazine::bit_cast<CUdeviceptr, void*>(
				m.get()), size());
			if (cuda != CUDA_SUCCESS) {
				assert( 0 && "cuMemcpyDtoD failed!");
			}
#else
			assert( 0 && "No GPU support." );
#endif
		}
		else {
			pointer.ptr = (void*)::malloc(allocationSize + 16);
			pointer.offset = getOffset(pointer.ptr);
			::memcpy(get(), m.get(), size() );
		}
	}
}

executive::MemoryAllocation::MemoryAllocation(MemoryAllocation&& m):
	structure(m.structure),
	dimension(m.dimension),
	affinity(m.affinity),
	addressSpace(m.addressSpace),
	pointer(m.pointer),
	extent(m.extent),
	desc(m.desc),
	allocationSize(m.size()),
	flags(m.flags),
	internal(m.internal) {

	m.structure = Struct_linear;
	m.dimension = Dim_1D;
	m.affinity = Affinity_host;
	m.addressSpace = 0;
	m.allocationSize = 0;
	m.flags = 0;
	m.internal = true;

	m.pointer.offset = 0;
	m.pointer.ptr = 0;
	m.pointer.xsize = m.pointer.ysize = m.pointer.pitch = 0;
	m.extent.width = m.extent.height = m.extent.depth = 0;
}

executive::MemoryAllocation& executive::MemoryAllocation::operator=(
	const MemoryAllocation& m) {
	if(this == &m) return *this;
	
	if (internal) {
		if (addressSpace) {
#if HAVE_CUDA_DRIVER_API == 1
			cuMemFree(hydrazine::bit_cast<CUdeviceptr, void *>(
				pointer.ptr));
#else
			assert( 0 && "No GPU support." );
#endif
		}
		else {
			::free(pointer.ptr);
		}
	}

	structure = m.structure;
	dimension = m.dimension;
	affinity = m.affinity;
	addressSpace = m.addressSpace;
	pointer = m.pointer;
	extent = m.extent;
	desc = m.desc;
	allocationSize = m.size();
	flags = m.flags;
	internal = m.internal;

	if (m.size() == 0) return *this;

	if (internal) {
		if (addressSpace) {
#if HAVE_CUDA_DRIVER_API == 1
			CUdeviceptr ptr = 0;
			CUresult cuda  = cuMemAlloc(&ptr, size());
			if (cuda == CUDA_SUCCESS) {
				pointer.ptr = reinterpret_cast<void *>(ptr);
			}
			else {
				assert( 0 && "cuMemAlloc failed!");
			}
			cuda = cuMemcpyDtoD(ptr, hydrazine::bit_cast<CUdeviceptr, void*>(
				m.get()), size());
			if (cuda != CUDA_SUCCESS) {
				assert( 0 && "cuMemcpyDtoD failed!");
			}
#else
			assert( 0 && "No GPU support." );
#endif
		}
		else {
			pointer.ptr = (void*)::malloc(allocationSize + 16);
			pointer.offset = getOffset(pointer.ptr);
			::memcpy(get(), m.get(), size() );
		}
	}
	
	return *this;
}

executive::MemoryAllocation& executive::MemoryAllocation::operator=(MemoryAllocation&& m) {
	if(this == &m) return m;
	std::swap(structure, m.structure);
	std::swap(dimension, m.dimension);
	std::swap(affinity, m.affinity);
	std::swap(addressSpace, m.addressSpace);
	std::swap(pointer, m.pointer);
	std::swap(extent, m.extent);
	std::swap(desc, m.desc);
	std::swap(allocationSize, m.allocationSize);
	std::swap(flags, m.flags);
	std::swap(internal, m.internal);
#if HAVE_CUDA_DRIVER_API == 1
	std::swap(cudaArray, m.cudaArray);
#endif
	return *this;
}


executive::MemoryAllocation::~MemoryAllocation() {
	if (internal) {
		if (addressSpace) {
#if HAVE_CUDA_DRIVER_API == 1
			cuMemFree(hydrazine::bit_cast<CUdeviceptr, void *>(
				pointer.ptr));
#else
			assert( 0 && "No GPU support." );
#endif
		}
		else {
			::free(pointer.ptr);
		}
	}
}

std::string executive::MemoryAllocation::toString() const {
	std::stringstream ss;

	ss << "= " << (void *)pointer.ptr << " - " 
		<< (void *)((char*)pointer.ptr + allocationSize - 1) << "\n";

	ss << "= pointer: " << (void*)pointer.ptr << "\n";
	ss << "= " << allocationSize << " bytes\n";
	ss << "= device address space: " << addressSpace << "\n";
	switch (structure) {
		case Struct_linear:
			ss << "= linear structure, " << (int)dimension + 1 << "D\n";
			break;
		case Struct_array:
			ss << "= array structure, " << (int)dimension + 1 << "D\n";
			break;
		case Struct_pitch:
			ss << "= pitched structure, " << (int)dimension + 1 << "D\n";
			break;
		case Struct_invalid:
		default:
			ss << "= unknown structure\n";
	}

	ss << "= pitch: " << pointer.pitch << "\n";
	ss << "= width: " << pointer.width << "\n";
	ss << "= height: " << pointer.height << "\n";

	return ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

executive::GlobalVariable::GlobalVariable():
	name("untitled") {

}

//////////////////////////////////////////////////////////////////////////////////////////////////
/*
executive::Texture::Texture():
	name(""),
	module(""),
	normalized(false),
	bound(false),
	offset(0),
	texRef(0),
	size(0) {

	device_pointer.ptr = 0;
	device_pointer.xsize = device_pointer.ysize = device_pointer.pitch = 0;
	
	desc.x = desc.y = desc.z = desc.w = 0;	
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////



