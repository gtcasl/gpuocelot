/*!
	\file ApplicationState.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief structures for application state
*/

#ifndef OCELOT_CUDA_APPLICATION_STATE_H_INCLUDED
#define OCELOT_CUDA_APPLICATION_STATE_H_INCLUDED

// C++ libs
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>

// UNIX libs
#include <pthread.h>

// Ocelot includes

// forward declarations

namespace ir {
	class Kernel;
}

namespace executive {

	enum DeviceAddressSpace {
		Device_global,
		Device_constant,
		Device_shared,
		Device_local,
		Device_texture,
		Device_address_space_invalid
	};

	class ChannelFormatDesc {
	public:
		enum Kind {
			Kind_signed,
			Kind_unsigned,
			Kind_float,
			Kind_none
		};
	public:
		Kind kind;
		int w, x, y, z;
	};
	
	class Extent {
	public:
		size_t depth;
		size_t height;
		size_t width;
	};
	
	class PitchedPointer {
	public:
		size_t pitch;
		void *ptr;
		size_t xsize;
		size_t ysize;
	};

	/*!
		describes memory allocations
	*/
	class MemoryAllocation {
	public:
	
		enum Dimension {
			Dim_1D,
			Dim_2D,
			Dim_3D,
			Dim_invalid
		};
		
		enum Structure {
			Struct_linear,
			Struct_array,
			Struct_pitch,
			Struct_invalid
		};
		
		enum Affinity {
			Affinity_host,
			Affinity_device,
			Affinity_invalid
		};
		
	public:
	
		//! indicates structure of memory allocation
		Structure structure;
		
		//! indicates number of used dimensions of allocation
		Dimension dimension;
		
		//! indicates whether allocation references a device or host memory
		Affinity affinity;
		
		//! index of address space - 0 is always host
		int addressSpace;
		
		//! pointer to allocation with pitch information
		PitchedPointer pointer;
		
		//! dimensions of allocation
		Extent extent;
		
		//! number of bytes allocate
		size_t allocationSize;
		
		//! channel format description
		ChannelFormatDesc desc;
		
		//! allocation flags
		unsigned int flags;
	
	public:
	
		//! default allocation constructor
		MemoryAllocation();	
	
		//! gets void* to memory allocation
		void *get() const {
			return pointer.ptr;		
		}
		
		//! true if memory is portable and affinity = host
		bool portable() const {
			return flags & 1;
		}
		
		//! true if memory is mapped and affinity = host
		bool mapped() const {
			return flags & 2;
		}
		
		//! total size of allocation in bytes
		size_t size() const {
			return 0;
		}
	};

	/*!
		Registered global variable	
	*/
	class GlobalVariable {
	public:
		GlobalVariable();
		
	public:
	
		//! name of global variable
		std::string name;
		
		//! name of module in which global is declared
		std::string module;
		
		//! size (in bytes) of global variable
		size_t size;
		
		//! pointer in device memory
		void *device_pointer;
		
		//! backing in host memory
		void *host_pointer;
	};

	/*!
		Registered texture	
	*/
	class Texture {
	public:
		Texture();
		
	public:
	
		//! name of texture reference symbol
		std::string name;
	
		//! name of module in which texture exists
		std::string module;
	
		//! indicates texture is bound and remaining data members are valid
		bool bound;
	
		//! offset that must be added to texture addresses for sampling to succeed
		size_t offset;
	
		//! opaque pointer to texture reference
		struct textureReference *texRef;
	
		//! pointer to allocated memory on the device
		PitchedPointer device_pointer;
		
		//! channel format description
		ChannelFormatDesc desc;
		
		//! size (in bytes) of memory region pointed to by device_pointer
		size_t size;
	};
			
	/*!	\brief Allocated memory	*/
	typedef std::map< void*, MemoryAllocation > MemoryAllocationMap;
			
	/*!	\brief GLobal variables	*/
	typedef std::map<std::string, GlobalVariable > GlobalMap;
						
	/*!	\brief Map from architecture type to kernel. */
	typedef std::map< unsigned int, ir::Kernel * > ArchitectureMap;
			
	/*!	\brief A map from kernel name to architecture implementations */
	typedef std::map< std::string, ArchitectureMap > KernelMap;

}

#endif

