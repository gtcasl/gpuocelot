/*!
	\file ExtractedDeviceState.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 31 Jan 2011
	\brief Data structure describing device state with serialization and deserialization procedures
*/

#ifndef OCELOT_UTIL_EXTRACTEDDEVICESTATE_H_INCLUDED
#define OCELOT_UTIL_EXTRACTEDDEVICESTATE_H_INCLUDED

// C++ includes
#include <fstream>

// Ocelot includes
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/cuda/interface/cuda.h>

// Hydrazine includes

namespace util {

	typedef std::vector< char > ByteVector;

	class ExtractedDeviceState {
	public:
	
		class MemoryAllocation {
		public:
			MemoryAllocation(size_t size);
			~MemoryAllocation();
			
			//!
			void resize(size_t _size, char c = 0);
			
		public:
			//! \brief base pointer to allocation
			char *base;
			
			//! \brief size in bytes of allocation
			size_t size;
			
			//! \brief contents of memory allocation
			char *image;
		};
		
		typedef std::map< std::string, MemoryAllocation *> GlobalVariableMap;
		typedef std::map< char *, MemoryAllocation *> GlobalAllocationMap;
		
		class Module {
		public:
		
		public:
			//! \brief module loaded into this name
			std::string name;
			
			//! \brief PTX representation of module
			std::string ptx;
			
			//! \brief 
			GlobalVariableMap globalVariablesBefore;
			
			//! \brief 
			GlobalVariableMap globalVariablesAfter;
		};
		
		class KernelLaunch {
		public:
		
		public:
			//! \brief name of module owning kernel
			std::string moduleName;
			
			//! \brief name of kernel
			std::string kernelName;
		
			//! \brief dimensions of CTAs
			ir::Dim3 blockDim;
			
			//! \brief dimensions of grid
			ir::Dim3 gridDim;
			
			//! \brief parameter memory size
			size_t parameterMemorySize;
			
			//! \brief shared memory size
			size_t sharedMemorySize;
			
			//! \brief contains parameter memory
			char *parameterMemory
		};
	
		typedef std::map< CUfunction, std::pair< std::string, std::string > > FunctionModuleMap;
		typedef std::map< std::string, Module > ModuleMap;
	
	public:
	
		ExtractedDeviceState(std::istream &in);
		ExtractedDeviceState();
		~ExtractedDeviceState();
		
		void serialize(std::ostream &out);
		void deserialize(std::istream &in);
		
		void clear();
		
	public:
		//! \brief maps module names onto structure capturing module state
		ModuleMap modules;
		
		//! \brief values of global allocations before kernel launch
		GlobalAllocationMap globalAllocationsBefore;
		
		//! \brief values of global allocations after kernel launch
		GlobalAllocationMap globalAllocationsAfter;
		
		//! \brief maps CUfunction onto (module-name, kernel-name) tuple
		FunctionModuleMap functionMap;
		
		//! \brief 
		KernelLaunch launch;
	};

}

#endif

