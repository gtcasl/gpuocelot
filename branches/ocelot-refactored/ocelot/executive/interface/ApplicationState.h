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
#include <ocelot/ir/interface/Texture.h>

#if HAVE_CUDA_DRIVER_API == 1
#include <ocelot/cuda/include/cuda.h>
#endif

// forward declarations

namespace ir {
	class Kernel;
}

namespace executive {

	/*!
		\brief enumerated type describing device address space
	*/
	enum DeviceAddressSpace {
		Device_global,
		Device_constant,
		Device_shared,
		Device_local,
		Device_texture,
		Device_address_space_invalid
	};
	
	/*!
		\brief type of mempcy
	*/
	enum MemcpyKind {
		HostToHost,
		HostToDevice,
		DeviceToHost,
		DeviceToDevice,
		MemcpyKind_invalid
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
	public:
		size_t size() const {
			return (w + x + y + z) / 8;
		}
		size_t channels() const {
			size_t c = 0;
			if (w) ++c;
			if (x) ++c;
			if (y) ++c;
			if (z) ++c;
			return c;
		}
	};
	
	class Extent {
	public:
		size_t depth;
		size_t height;
		size_t width;
	};
	
	class PitchedPointer {
	public:
		size_t offset; // Offset from the base of the pointer for alignment
		size_t pitch;

		void *ptr;

		union {
			size_t xsize;
			size_t width;		// I prefer 'width' to 'xsize' as a member name
		};
		union {
			size_t ysize;
			size_t height;	// I prefer 'height' to 'ysize' as a member name
		};
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
		
		//! indicates Ocelot manages allocation
		bool internal;
	
#if HAVE_CUDA_DRIVER_API == 1
		//! array handle [if array allocated on GPU device]
		CUarray cudaArray;
#endif
	
	public:
	
		//! default allocation constructor
		MemoryAllocation();	
	
		//! gets void* to memory allocation
		void *get() const {
			return (char*)pointer.ptr + pointer.offset;
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
			return allocationSize;
		}

		std::string toString() const;
	};

	/*!
		Registered global variable	
	*/
	class GlobalVariable {
	public:

		/*!
			\brief each module may register its own pointers to global variables on both host and
				device
		*/
		class ModulePointer {
		public:
			
			//! \brief host pointer
			void *host;

			//! \brief device pointer
			void *device;

			//! \brief size of global in bytes
			size_t size;
		};

		typedef std::map< std::string, ModulePointer > ModulePointerMap;

	public:
		GlobalVariable();
		
	public:
	
		//! name of global variable
		std::string name;

		//! pointer to host variable
		void *host_pointer;

		//! maximum size of global
		size_t size;
		
		//! maps name of module(s) in which global is declared and pointer to variable in host and device memory
		ModulePointerMap modules;
		
		//! indicates state space of device in which global exists
		DeviceAddressSpace deviceAddressSpace;
	};

	/*!
		\brief texture representing the configuration and state of a bound texture
	*/
/*
	class Texture {
	public:
		
		enum Interpolation {
			Nearest,
			Linear
		};
		
		enum AddressMode {
			Wrap,
			Clamp
		};

	public:

		//! \brief channel format of texture
		ChannelFormatDesc format;

		//! \bref true if texture coordinates are normalized floats
		bool normalizedCoordinates;

		//! \brief true if texture sample should be normalized
		bool normalizedFloat;

		//! \brief data type of texture
		Type type;

		//! \brief pitched pointer includes dimensions and pointer to data
		PitchedPointer pointer;

		//! \brief interpolation mode
		Interpolation interpolation;

		//! \brief addressing mode for each dimension
		AddressMode addressMode[3];

	public:
		Texture();
	};
*/
			
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

