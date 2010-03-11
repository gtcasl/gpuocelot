/*! \file Executive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements Ocelot's executive manager
*/

#ifndef OCELOT_EXECUTIVE_H_INCLUDED
#define OCELOT_EXECUTIVE_H_INCLUDED

// C++ includes
#include <map>
#include <set>

// Ocelot includes
#include <ocelot/executive/interface/ApplicationState.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/ir/interface/Instruction.h>
#include <ocelot/ir/interface/Texture.h>
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/translator/interface/Translator.h>

#if HAVE_CUDA_DRIVER_API == 1
#include <ocelot/cuda/include/cuda.h>
#endif

struct cudaArray;

// forward declared classes
namespace ir {
	class Kernel;
	class Module;
}

// Executive class
namespace executive {

	//! identical to cuda_runtime.h's dim3 structure
	struct dim3 {
		int x, y, z;
	};

	//! maps module name => ir::Modile
	typedef std::map< std::string, ir::Module * > ModuleMap;
	
	//! maps device => address space - 0 is always host
	typedef std::map< int, int > AddressSpaceMap;
	
	typedef std::map< void *, MemoryAllocation > MemoryAllocationMap;
	
	//! maps (address space, ptr) => allocation
	typedef std::map< int, MemoryAllocationMap > DeviceMemoryAllocationMap;

	typedef std::map< std::string, ir::Texture > TextureMap;
	
	typedef std::vector< std::string > StringVector;

	/*!
		\brief specifies the Ocelot execution model
	*/
	class Executive {
	public:
	
	public:
	
		int selectedDevice;
	
		// textures
		TextureMap textures;
		
		// global variables
		GlobalMap globals;
		
		// memory allocations
		DeviceMemoryAllocationMap memoryAllocations;

		//! maps device => address space - 0 is always host address space
		AddressSpaceMap addressSpaces;
		
		// modules + kernels
		ModuleMap modules;
		
		//! vector of available Ocelot devices
		DeviceVector devices;
	
		//! optimization level used by translator
		translator::Translator::OptimizationLevel optimizationLevel;

		//! \brief number of threads used for host processing
		int hostWorkerThreads;
		
	public:
	
		Executive();
		~Executive();
	
	public:
	
		//
		// registration functions
		//
		
		/*!
			\brief loads a module with a given name and PTX representation
		*/
		bool loadModule(std::string name, bool translateOnLoad, std::istream & ptx);

		/*!
			\brief loads a module with a given name from a file
		*/
		bool loadModule(std::string filename, bool translateOnLoad=false);
		
		/*!
			\brief registers a global variable
			\param module module name
			\param name string naming global variable
			\param hostPtr pointer in host memory - identifies the global
			\param devicePtr pointer in device memory
			\param size size of global in bytes
			\param addrSpace indicates which address space the global resides in on the device
		*/
		void registerGlobalVariable(const std::string & module, const  std::string varName, 
			void *hostPtr, void *devicePtr, size_t size, DeviceAddressSpace addrSpace);
		
		/*!
			\brief registers a texture defined in a particular module
			\param module name of module
			\param name name of texture
			\param number of dimensions (1, 2, or 3)
			\param if 1, texture coordinates are normalized
		*/
		void registerTexture(const char *module, const char *name, int dimensions, int normalized);
		
		/*!
			Registers an external memory allocation
			\param ptr pointer to allocation
			\param bytes size of the allocation in bytes
			\param addressSpace address space of the allocation
		*/
		void registerExternal(void *ptr, size_t bytes, int addressSpace=-1);

		void unregisterExternal(void *ptr, int addressSpace=-1);
		
		/*!
			Returns a vector with the names of all kernels in a module
			\param module The name of the loaded module to enumerate
			\return A vector of strings each corresponding to a kernel in the module
		*/
		StringVector enumerateKernels(const std::string& module) const;
		
	public:
	
		//
		// memory allocation functions
		//
		
		/*
			Memory - linear
		*/

		/*!
			\brief allocate memory on the selected device's address space
			\param devPtr places resulting pointer
			\param size number of bytes to allocate
			\return true if successful
		*/
		bool malloc(void **devPtr, size_t size);

		/*!
			\brief performs host allocation of page-locked memory
			\param ptr places resulting pointer
			\param size number of bytes
			\param portable allocation will be considered pinned memory shared for all CUDA contexts
			\param mapped	maps allocation to device context
			\param writeCombined optimize for writes by CPU, reads from device
		*/
		bool mallocHost(void **ptr, size_t size, bool portable = false, bool mapped = false, 
			bool writeCombined = false);
		
		/*!
			\brief allocates memory on the selected device and returns pitch
			\param devPtr places resulting pointer
			\param pitch [out] pointer to variable containing pitch of resulting allocation
			\param width width in bytes of allocation
			\parma height height in bytes of allocation
			\return true if successful
		*/
		bool mallocPitch(void **devPtr, size_t *pitch, size_t width, size_t height);

		/*!
			\brief allocates memory on the selected device given an extent - output in pitched pointer
			\param pitchedPtr pointer to pitched memory allocation
			\param extent extent of region - at least extent.width*height*depth bytes are allocated
		*/
		bool mallocPitch(PitchedPointer * pitchedPtr, Extent extent);

		/*!
			\brief allocates a pitched memory allocation as an array
			\param arrayPtr pointer to allocation
			\param desc channel format
			\param extent region - at least extent.width*height*depth*desc.size() bytes are allocated
		*/
		bool mallocPitchArray(PitchedPointer * pitchedPtr, const ChannelFormatDesc &desc, 
			Extent extent);
		
		/*!
			\brief allocates an array of memory on the selected device
			\param array places resulting pointer here
			\param desc
			\param desc
			\param width
			\param height
			\return true if successful
		*/
		bool mallocArray(struct cudaArray **array, const ChannelFormatDesc & desc, 
			size_t width, size_t height);

		/*!
			\brief frees an allocation
			\param devPtr device pointer
		*/
		bool free(void *devPtr);
		
		/*!
			\brief frees host-allocated memory
		*/
		bool freeHost(void *ptr);
		
		/*!
			\brief frees an array
		*/
		bool freeArray(struct cudaArray *array);

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
			\brief prints all memory allocations to an output stream
		*/
		std::ostream & printMemoryAllocations(std::ostream &out) const;

		/*!
			Given a pointer, determine the allocated block and 
			corresponding MemoryAllocation record to which it belongs.

			\param device GUID of device
			\param ptr pointer to some byte
			\return record of memory allocation; if nothing could be found, 
				the record's ISA is Unknown
		*/
		MemoryAllocation getMemoryAllocation(const void *ptr) const;
		
		/*!
			Gets a string representation of memory allocations
		*/
		static std::string nearbyAllocationsToString( const Executive& executive, const void* pointer, 
			unsigned int above = 5, unsigned int below = 5 );
		
	public:
	
		/*!
			\brief copies to or from the selected device - will check whether device pointers are valid
	
			\param dest pointer to destination
			\param src pointer to source
			\param size number of bytes to transfer
			\param indicates the kind of transfer
			\return true on success
		*/
		bool deviceMemcpy(void *dest, const void *src, size_t size, MemcpyKind kind);
		
		/*!
			\brief copies to a symbol on the device
			\param symbol name of symbol
			\param src pointer to source data
			\param count number of bytes to copy
			\param offset offset to add to destination
			\param kind indicates direction to copy - src must be Device
		*/
		bool deviceMemcpyToSymbol(const char *symbol, const void *src, size_t count, size_t offset, 
			MemcpyKind kind);

		/*!
			\brief copies to a symbol on the device
			\param symbol name of symbol
			\param src pointer to source data
			\param count number of bytes to copy
			\param offset offset to add to destination
			\param kind indicates direction to copy - src must be Device
		*/
		bool deviceMemcpyFromSymbol(const char *symbol, void *dst, size_t count, size_t offset, 
			MemcpyKind kind);

		/*!
			\brief returns a symbol as a global variable
		*/
		GlobalVariable & getGlobalVariable(const char *symbol);
		
		/*!
			\brief copies a dense host buffer to a device array
			\param host
			\param array
			\param wOffset
			\param hOffset
			\param bytes
			\param kind
		*/
		bool deviceMemcpyToArray(struct cudaArray *array, void *host, size_t wOffset, 
			size_t hOffset, size_t bytes, MemcpyKind kind);

		/*!
			\brief copies a dense host buffer from a device array
			\param host
			\param array
			\param wOffset
			\param hOffset
			\param bytes
			\param kind
		*/
		bool deviceMemcpyFromArray(struct cudaArray *array, void *host, size_t wOffset, 
			size_t hOffset, size_t bytes, MemcpyKind kind);
		
		/*!
			\brief copies a dense buffer from a device array to a device array
		*/	
		bool deviceMemcpyArrayToArray(struct cudaArray *dst, size_t dstWOffset, size_t dstHOffset,
			const struct cudaArray *src, size_t srcWOffset, size_t srcHOFfset, size_t count,
			MemcpyKind kind);

		/*!
			\brief performs memcpy 
		*/
		bool deviceMemcpy2D(void *dst, size_t dstPitch, const void *src, size_t srcPitch, 
			size_t width, size_t height, MemcpyKind kind);

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
		bool deviceMemcpy2DtoArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, 
			const void *src, size_t spitch, size_t width, size_t height, MemcpyKind kind);

		bool deviceMemcpy2DfromArray(void *dst, size_t dpitch, const struct cudaArray *srcArray,
			size_t wOffset, size_t hOffset, size_t width, size_t height, MemcpyKind kind);

		/*!
			\brief performs a 3D memcpy to a destination 
			\param dst - pointer to either a CUDA array or a pitched allocation (.ptr field specifies a memory allocation which informs Executive)
			\param dstPos - offset into destination block
			\param extent - width, height, and depth to copy
			\param kind - indicates whether source and destination are device or host
			\param src - pointer to either CUDA array or pitched allocation  (.ptr field specifies a memory allocation which informs Executive)
			\param srcPos - offset into source block
		*/
		bool deviceMemcpy3D(PitchedPointer dst, dim3 dstPos, Extent extent, MemcpyKind kind, 
			PitchedPointer src,	dim3 srcPos);

	public:
	
		//
		// texture binding functions
		//
		
		/*!
			\brief binds a texture by name to a pointer to a device memory allocation
			\param offset [out] offset that must be added to fetches to achieved desired pixel
			\param texture name of texture
			\param devPtr device memory allocation
			\param format channel description
			\param size bytes in texture
			\return true on success
		*/
		bool bindTexture(size_t *offset, const std::string & texture, const void *devPtr, 
			const ChannelFormatDesc &format, size_t size, ir::Texture::AddressMode *addrMode, 
			ir::Texture::Interpolation filter, bool normalized);
		
		/*!
			\brief binds a 2D texture by name to a device pointer with a given width, height, and pitch
			\param offset [out] offset that must be added to fetches to achieved desired pixel
			\param texture name of texture
			\param devPtr device memory allocation
			\param format channel description
			\param width width of texture in texels
			\param height height of texture in texels
			\param pitch number of bytes between texels of the same column in consecutive rows
			\return true on success
		*/
		bool bindTexture2D(size_t *offset, const std::string & texture, const void *devPtr,
			const ChannelFormatDesc &format, size_t width, size_t height, size_t pitch,
			ir::Texture::AddressMode *addrMode, ir::Texture::Interpolation filter, bool normalized);
		
		/*!
			\brief binds a texture to an array
		*/
		bool bindTextureToArray(const std::string & texture, void *array, 
			const ChannelFormatDesc &desc,  ir::Texture::AddressMode *addrMode, 
			ir::Texture::Interpolation filter, bool normalized);
		
		/*!
			\brief unbinds a previously bound texture
		*/
		void unbindTexture(const std::string & texture);
		
		/*!
			gets alignment of a named texture
		*/
		size_t getTextureAlignmentOffset(const std::string & texture);
		
	public:
	
		//
		// kernel launch and synchronization functions
		//
		
		/*!
			Gets a kernel by ISA, module, kernel name.

			\param isa instruction set of desired kernel
			\param module name of module from which kernel is to be selected
			\param kernelName name of kernel

			\return instance of kernel with requested ISA or 0 on failure.
		*/
		ir::Kernel *getKernel(ir::Instruction::Architecture isa, const std::string& module, 
			const std::string& kernel);	
		
		/*!
			\brief translates a kernel to the given ISA overwriting potentially existing translations
			\param isa ISA to translate to
			\param module name of module to which kernel belongs
			\param kernel name of kernel
			\return translated kernel or NULL on translation failure
		*/
		ir::Kernel *translateToISA(ir::Instruction::Architecture isa, const std::string &module,
			const std::string &kernel);
		
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
		void launch(const std::string & module, const std::string & kernel, dim3 grid, dim3 block,
			size_t sharedMemory, unsigned char *parameterBlock, size_t parameterBlockSize);

		/*!
			\brief helper function for launching a kernel
			\param module module name
			\param kernel kernel name
			\param grid grid dimensions
			\param block block dimensions
			\param sharedMemory shared memory size
			\param parameterBlock array of bytes for parameter memory
			\param parameterBlockSize number of bytes in parameter memory
			\param traceGenerators vector of trace generators to add and remove from kernel
		*/
		void launch(const std::string & module, const std::string & kernel, dim3 grid, dim3 block,
			size_t sharedMemory, unsigned char *parameterBlock, size_t parameterBlockSize,
			const trace::TraceGeneratorVector & traceGenerators);
			
		/*!
			\brief determines whether kernel exceeds memory bounds through static analysis
			\param exeKernel executable kernel under test
			\param sharedMemory size of dynamic shared memory
			\param paramSize size of parameter memory
			\return true if kernel meets memory capacity
		*/
		bool verifyKernelMemoryBounds(ir::ExecutableKernel *exeKernel, size_t sharedMemory, 
			size_t paramSize);

		/*!
			\brief block on kernel executing on selected device
		*/
		void synchronize();
		
	public:
		//
		// device management functions
		//
		
		/*!
			inserts devices into device vector
			\return number of devices in vector
		*/
		size_t enumerateDevices();

		/*!
			\return constant vector of available devices
		*/
		const DeviceVector & getDevices() const {
			return devices;
		}

		/*! 
			selects a device [ this is intended to be a low-cost operation called at every CUDA runtime 
			API call]
		*/
		bool selectDevice(int device);
		
		/*! 
			gets selected device identifier
		*/
		int getSelectedDevice() const;
		
		/*!
			gets selected device identifier
		*/
		int getSelected() const {
			return getSelectedDevice();
		}
		
		/*!
			gets the ISA of the selected device
		*/
		ir::Instruction::Architecture getSelectedISA() const;
		
		/*!
			indicates preferred ISA [device will be chosen if available]
		*/
		void setPreferredISA(ir::Instruction::Architecture isa);
		
		/*!
			\brief selects the first device with the given ISA
		*/
		bool selectDeviceByISA(ir::Instruction::Architecture isa);
		
		/*! 
			\brief only listed devices may be selected
		*/
		void filterDevices(std::vector<int> & devices);
		
		/*!
			\brief only devices with listed ISAs may be selected
		*/
		void filterISAs(std::vector<int> & ISAs);
		
		/*!
			\brief returns the address space of the selected device
		*/
		int getDeviceAddressSpace() const;
		
	public:
		//
		// translation settings
		//

		/*!
			\brief This sets the optimization level 
		
			\param l The new optimization level.
		*/
		void setOptimizationLevel(translator::Translator::OptimizationLevel l);

		/*!
			\brief limits the number of working threads available
		*/
		void setWorkerThreadLimit(int limit);
		
		/*!
			\brief ensures that all kernels have an executable translation for the indicated ISA
			\param isa target ISA to translate to
			\param retranslate if true, all kernels are translated even those for which a translation exists
		*/
		void translateAllToISA(ir::Instruction::Architecture isa, bool retranslate=true);
		
		void translateModuleToISA(std::string moduleName, ir::Instruction::Architecture isa, bool retranslate=true);
		
	public:
		//
		// Ocelot native interface functions
		//
		
		
	protected:
	
		/*!
			\brief global variable values are buffered and then initialized prior to kernel launch
		*/
		void fenceGlobalVariables();
		
	};

}

#endif

