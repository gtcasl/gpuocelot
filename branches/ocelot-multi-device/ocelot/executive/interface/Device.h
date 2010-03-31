/*!
	\file Device.h
	
	\author Andrew Kerr
	
	\date Jan 16, 2009
	
	\brief class for identifying and reporting properties of devices targeted
		by the executive
*/

#ifndef EXECUTIVE_DEVICE_H_INCLUDED
#define EXECUTIVE_DEVICE_H_INCLUDED

// C++ standard library includes
#include <fstream>
#include <string>
#include <vector>

// Ocelot includes
#include <ocelot/executive/interface/ApplicationState.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/cuda/interface/CudaDriver.h>

namespace executive {

	typedef ir::Module::KernelMap KernelMap;

	typedef std::map< std::string, CUtexref > DriverTextureMap;

	typedef std::map< std::string, CUmodule > DriverModuleMap;

	/*! Class for reporting properties of a device */
	class Device {
	public:
		Device();
		~Device();

		/*! Write attributes of the device to an output stream */
		std::ostream & write(std::ostream &out) const;
		
		/*! "native" ISA of the device */
		ir::Instruction::Architecture ISA;
		
		/*! identifies the device's address space */
		int addressSpace;
	
		/*! human-readable device name */
		std::string name;
		
		/*! unique identifier for referencing the device within the
			framework */
		int guid;
		
		/*! number of bytes of global memory available to the device */
		size_t totalMemory;
	
		/*! gets the number of multiprocessors/cores on the device */
		int multiprocessorCount;
		
		/*! true if the device can simultaneously execute a kernel while 
			performing data transfer */
		int memcpyOverlap;
	
		/*! maximum number of threads per block */
		int maxThreadsPerBlock;
	
		/*! maximum size of each dimension of a block */
		int maxThreadsDim[3];
	
		/*! maximum size of each dimension of a grid */
		int maxGridSize[3];
	
		/*! total amount of shared memory available per block in bytes */
		int sharedMemPerBlock;
	
		/*! total amount of constant memory on the device */
		int totalConstantMemory;
	
		/*! warp size */
		int SIMDWidth;
	
		/*! maximum pitch allowed by memory copy functions */
		int memPitch;
		
		/*! total registers allowed per block */
		int regsPerBlock;
		
		/*! clock frequency in kHz */
		int clockRate;
		
		/*! alignment requirement for textures */
		int textureAlign;
		
		/*! major shader module revision */
		int major;
		
		/*! minor shader model revision */
		int minor;

		/*! \brief CUDA device context */
		CUcontext cudaContext;
		
		/*! \brief Kernels that have been translated to this device */
		KernelMap kernels;
		
		/*! \brief Copies of textures on this device */
		DriverTextureMap textures;
		
		/*! \brief Set of modules that have been loaded on this device */
		DriverModuleMap modules;
		
		/*! \brief Global variables that have been bound to this device */
		GlobalMap globals;
	};
	
	typedef std::vector< Device > DeviceVector;
}

#endif
