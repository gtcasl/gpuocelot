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
#include <map>
#include <vector>

// Ocelot includes
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/ir/interface/Texture.h>
#include <ocelot/ir/interface/PTXOperand.h>

// Hydrazine includes

namespace util {

	typedef std::vector< char > ByteVector;

	class ExtractedDeviceState {
	public:
	
		class MemoryAllocation {
		public:
			MemoryAllocation(void *ptr, size_t size, ir::PTXOperand::DataType dt = ir::PTXOperand::u32, char c = 0);
			MemoryAllocation();
			~MemoryAllocation();
			
			void serialize(std::ostream &out, const std::string & prefix = "") const;
			
			//!
			void resize(size_t _size, char c = 0);
			
		public:
		
			//! \brief references the allocation on the device
			void *devicePointer;
		
			//! \brief type of data
			ir::PTXOperand::DataType dataType;
		
			//! \brief binary representation of data
			ByteVector data;
		};
		
		typedef std::map< std::string, ir::Texture *> TextureMap;
		typedef std::map< std::string, MemoryAllocation *> GlobalVariableMap;
		typedef std::map< void *, MemoryAllocation *> GlobalAllocationMap;
		
		/*!
		
		*/
		class Module {
		public:
		
			Module();
			
			~Module();
		
			void clear();
			
			void serialize(std::ostream &out, const std::string & prefix = "") const;
			
			void serializeTexture(ir::Texture &texture, std::ostream &out, const std::string & prefix = "") const;
		
		public:
			//! \brief module loaded into this name
			std::string name;
			
			//! \brief file to which PTX representation of module is written
			std::string ptxFile;
			
			//! \brief 
			GlobalVariableMap globalVariables;
			
			//! \brief textures contained in the module
			TextureMap textures;
		};
		
		class KernelLaunch {
		public:
		
			void serialize(std::ostream &out) const;

		public:
			//! \brief name of module owning kernel
			std::string moduleName;
			
			//! \brief name of kernel
			std::string kernelName;
		
			//! \brief dimensions of CTAs
			ir::Dim3 blockDim;
			
			//! \brief dimensions of grid
			ir::Dim3 gridDim;
			
			//! \brief shared memory size
			size_t sharedMemorySize;
			
			//! \brief block of memory denoting parameter memory
			ByteVector parameterMemory;
		};
		
		class Application {
		public:
		
			Application();
		
			void serialize(std::ostream &out) const;
		
		public:
			//! \brief name of application
			std::string name;
			
			//! \brief name of target CUDA device
			std::string cudaDevice;
			
		};
	
		typedef std::map< std::string, Module > ModuleMap;
	
	public:
	
		ExtractedDeviceState(std::istream &in);
		ExtractedDeviceState();
		~ExtractedDeviceState();
		
		void serialize(std::ostream &out) const;
		void deserialize(std::istream &in);
		
		void clear();
		
	public:
	
		//! \brief data specific to an application
		Application application;
	
		//! \brief maps module names onto structure capturing module state
		ModuleMap modules;
		
		//! \brief values of global allocations before kernel launch
		GlobalAllocationMap globalAllocations;
				
		//! \brief parameters of CUDA launch
		KernelLaunch launch;
	};

}

#endif

