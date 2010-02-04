/*! \file Executive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 16, 2009
	\brief class definition for loading modules, enumerating devices,
		and executing kernels on the selected device
*/

#ifndef EXECUTIVE_EXECUTIVE_H_INCLUDED
#define EXECUTIVE_EXECUTIVE_H_INCLUDED

#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/ir/interface/Texture.h>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/translator/interface/Translator.h>
#include <ocelot/cuda/include/cuda.h>

/*! \brief A namespace for classes that help execute programs */
namespace executive {

	class ExternalKernel;

	/*! Class wrapping the execution layer */
	class Executive {
	public:

		/*! \brief basic type used for allocation */
		class AllocationType{ char data[16]; };
		
		/*!	Vector of devices */
		typedef std::vector<Device> DeviceVector;

		/*! Memory copy types. Should be self explanatory */
		enum MemoryCopy
		{
			HostToDevice,
			DeviceToHost,
			HostToHost,
			DeviceToDevice
		};

		/*!
			The executive keeps a list of allocations for each device. This 
			record indicates which device the allocation belongs to, its ISA, 
			its size, and a pointer to the first usable byte. 
			
			This assumes that the address space is global device memory.
		*/
		class MemoryAllocation {
		public:
			ir::Instruction::Architecture isa;
			int device; /*! \brief The device associated with the allocation */
			ir::PTXU64 size; /*! \brief The size of the allocation in bytes */
			void *ptr; /*! \brief A pointer to the base of the allocation */
			bool external; /*! \brief Is the memory owned by the exective? */
			unsigned int offset; /*! \brief Offset from the allocated 
				based for alignment */			
						
		public:
			MemoryAllocation(ir::Instruction::Architecture, int, ir::PTXU64, 
				void *);

			MemoryAllocation();
			~MemoryAllocation();
		
		};
		
		/*! \brief Set of strings */
		typedef std::unordered_set< std::string > StringSet;
		
		/*! \brief A global allocation valid on all devices. */
		class GlobalMemoryAllocation {
		public:
			ir::PTXU64 size; /*! \brief The size of the allocation in bytes */
			void *ptr; /*! \brief A pointer to the base of the allocation */
			std::string identifier;
			StringSet modules;
			ir::PTXInstruction::AddressSpace space;
		};
		
		/*!	\brief Map from pointer to memory allocation
			
			Note that this is supposed to be ordered to ease memory protection 
				violation detections
		*/
		typedef std::map< char*, MemoryAllocation > AllocationMap;
		
		/* \brief Map from device to allocation map */
		typedef std::unordered_map< int, AllocationMap > DeviceAllocationMap;

		/*!	\brief Map from module name to object */
		typedef std::unordered_map<std::string, ir::Module *> ModuleMap;
		
		/*! \brief Map from pointer to global allocations */
		typedef std::map< char*, GlobalMemoryAllocation > GlobalAllocationMap;

		/*!
			\brief maps a named kernel to override application kernels
		*/
		class ExternalKernelEntry {
		public:
	
			//! \brief source file for kernel
			std::string sourcePath;

			//! \brief indicates the type of external kernel to load
			int loadingType;

			//! \brief ptr to external kernel
			executive::ExternalKernel *kernel;
		};	

		//! \brief maps a kernel name onto an ExternalKernelEntry object
		typedef std::map< std::string, ExternalKernelEntry > ExternalKernelMap;	

	public:
		/*! \brief Return a string of the memory allocations around a pointer */
		static std::string nearbyAllocationsToString( 
			const Executive& executive, const void* pointer, 
			unsigned int above = 5, unsigned int below = 5 );
		
		/*! \brief Return a string of the global variables around a pointer */
		static std::string nearbyGlobalsToString( 
			const Executive& executive, const void* pointer, 
			unsigned int above = 5, unsigned int below = 5 );
	
	private:
		/*! \brief Translate the kernels of a module to the selected ISA */
		void _translateToSelected(ir::Module& m);		
		void _translateToGPUExecutable(ir::Module &m);
		
	public:
		Executive();
		~Executive();
		
		/*! set of available devices enumerated by the executive, 
			these present a filtered view into the total set of devices 
			in the system */
		DeviceVector devices;
	
		/*!
			Selects a device from the enumerated set.
	
			\param select guid of device
			\return true if successfully selected
		*/
		bool select(int select);

		/*!
			Selects a device given an ISA.

			\return true if selected
		*/
		bool selectDeviceByISA(ir::Instruction::Architecture ISA);
	
		/*! \brief Reorders devices such that devices with this ISA appear first
		*/
		void setPreferredISA(ir::Instruction::Architecture ISA);
		
		/*! \brief Removes devices of the specific ISA from the filtered 
			device list
		*/
		void filterDevicesByISA(ir::Instruction::Architecture ISA);
		
		/*! \brief Restores the filtered list of devices 
			to reflect all devices */
		void restoreFilteredDevices();
		
		/*!
			Returns the guid of the selected device or -1 if no device 
				is selected
	
			\return guid of selected device or -1 if no device is selected
		*/
		int getSelected() const;
		
		/*!
			Returns the ISA of the selected device or PTX if no 
				device is selected
		*/
		ir::Instruction::Architecture getSelectedISA() const;
	
		/*!
			Loads a module from a PTX source file. If the module is succesfully
			loaded, it may be obtained by indexing the modules[] map with the
			path name provided.
			
			\param path name of PTX source file
			\param translateToSelected after successful load, indicates whether 
				module should be translated to selected device's ISA
			\param stream Stream to read from instead of trying to open the path
			\return true if module loaded
		*/
		bool loadModule(const std::string& path, bool translateToSelected=true, 
			std::istream* stream = 0);
				
		/*!	Unloads a module */
		bool unloadModule(const std::string& path);
		
		/*! Blocks until all possibly executing kernels have completed. */
		void synchronize();

		/*!	Allocate <bytes> of memory on the device

			\return pointer to allocated memory block or NULL on error
		*/
		void *malloc(size_t bytes);

		/*!
			\brief Registers a reference to a memory segment allocated 
			externally from the Executive module.
			
			\param bytes Size of the external segment
			\param pointer Pointer to the segment
			
			Note that this can be deallocated via free
		*/
		void registerExternal(void* pointer, size_t bytes);

		/*!
			Makes a static array visible to the Executive class

			\param ptr Pointer to the start of the memory
			\param bytes Size of memory in bytes
			\param name Identifier of the variable
			\param module Path to the module with the variable
			\param space The address space it should exist in
			\param normalize If the global is a texture, 
				should it be normalized?
		*/
		void registerGlobal(void *ptr, size_t bytes, const std::string& name, 
			ir::PTXInstruction::AddressSpace space, const std::string& module);

		/*!
			Makes a texture array visible to the Executive class

			\param t The texture being registered
			\param name Identifier of the variable
			\param module Path to the module with the variable
		*/
		void registerTexture(const ir::Texture& t, const std::string& name, 
			const std::string& module);

		/*!
			\brief Bind a texture to another memory allocation
			\param target Pointer to the variable to bind the texture to
			\param texture Name of the texture variable
			\param module The module containing the texture
			\param width The width dimension in bytes
			\param height The height dimension in bytes
			\param length The length dimension in bytes
		*/
		void rebind(const std::string& module, const std::string& texture, 
			void* target, unsigned int width, unsigned int height, 
			unsigned int length, const ir::Texture& t);

		/*!
			Free a memory block allocated to this device.

			\param ptr pointer to allocated memory block
		*/
		void free(void *ptr);

		/*!
			\brief Free a static array
			
			\param name The name of the variable being freed
			\param module The path of the module to free from
		*/
		void freeGlobal(const std::string& name, const std::string& module);
		
		/*!
			Copy a block of data 
			
			\param dest Pointer to start of destination block
			\param src Pointer to start of source block
			\param bytes Number of bytes to copy
			\param type Type of memory operation
		
		*/
		void memcpy(void* dest, const void* src, size_t bytes, 
			MemoryCopy type);

		/*!
			Set a block of data 
			
			\param dest Pointer to start of destination block
			\param bytes Number of bytes to set
			\param value Value to set to
		
		*/
		void memset(void* dest, int value, size_t bytes);

		/*! 
			\brief Determine if a memory access is valid 
		
			This should search device specific allocations as well as 
			global allocations.
		
			\param device The device doing the access
			\param base Pointer to the base of the access
			\param size The size of the access
		*/
		bool checkMemoryAccess(int device, const void* base, size_t size) const;

		/*!
			Given a pointer, determine the allocated block and 
			corresponding MemoryAllocation record to which it belongs.

			\param device GUID of device
			\param ptr pointer to some byte
			\return record of memory allocation; if nothing could be found, 
				the record's ISA is Unknown
		*/
		MemoryAllocation getMemoryAllocation(int device, const void *ptr) const;

		/*!
			Given a pointer, determine the allocated block and 
			corresponding GlobalMemoryAllocation record to which it belongs.

			\param ptr pointer to some byte
			\return record of memory allocation; if nothing could be found, 
				the record's address space is invalid
		*/
		GlobalMemoryAllocation getGlobalMemoryAllocation(const void *ptr) const;

		/*!
			Gets a kernel by ISA, module, kernel name.

			\param isa instruction set of desired kernel
			\param module name of module from which kernel is to be selected
			\param kernelName name of kernel

			\return instance of kernel with requested ISA or 0 on failure.
		*/
		ir::Kernel *getKernel(ir::Instruction::Architecture isa, 
			const std::string& module, const std::string& kernelName);	

		/*!
			\brief This sets the optimization level 
		
			\param l The new optimization level.
		*/
		void setOptimizationLevel(translator::Translator::OptimizationLevel l);

		/*!
			\brief get the optimization level of the translator
		*/
		translator::Translator::OptimizationLevel getOptimizationLevel() const {
			return optimizationLevel;
		}

		/*!
			called to update global variables across all address spaces

			\param copyType specifies direction data should be copied to update globals
		*/
		void fenceGlobalVariables(MemoryCopy copyType = HostToDevice);

		/*!
			idempotent - called to init GL interoperability
		*/

		bool useGLInteroperability();
		
		/*! \brief Limit the number of threads launched per kernel */
		void limitWorkerThreads(unsigned int limit);

		/*! \brief This creates the set of devices available in the system */
		void enumerateDevices();

		/*! */
		void initializeExternalKernelMap(std::string directoryPath, int type);

		/*! 
			\brief override an executable kernel if configured, otherwise return source kernel
		*/
		ir::ExecutableKernel *getExternalOverride(ir::ExecutableKernel *kernel);

	public:

		/*! Set of loaded PTX modules indexed by the module's filename */
		ModuleMap modules;

		/*!
			A map indexable by device GUID of memory allocations on that 
			device. For a given device, these are assumed to be non-overlapping.
		*/
		DeviceAllocationMap memoryAllocations;
		
		/*! \brief A map of registered global memory allocations */
		GlobalAllocationMap globalAllocations;

	public:

		/*!
			\brief map of kernel names and external kernel entries - overrides kernels in application
				fat binaries
		*/
		ExternalKernelMap externalKernels;

		/*!
			\brief specifies the preferred type of external kernel to load - or invalid to avoid overriding
		*/
		int externalKernelLoadingType;

	protected:
		
		/*! \brief This is the selected device */
		int selectedDevice;

		/*! \brief Has the CUDA driver API been initialized? */
		static bool cudaInitialized;

		/*! \brief The optimization level to use when translating kernels */
		translator::Translator::OptimizationLevel optimizationLevel;
		
		/*! \brief Cuda specific state */
		CUdevice cudaDevice;
		CUcontext cudaContext;
		bool cudaGLInitialized;		
		/*! \brief The actual set of devices */
		DeviceVector allDevices;
		
		/*! \brief The limit on CPU threads launched per kernel */
		unsigned int threadLimit;
	};
	
}

#endif
