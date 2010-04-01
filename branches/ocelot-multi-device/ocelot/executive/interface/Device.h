/*! \file Device.h
	\author Andrew Kerr
	\date Jan 16, 2009
	\brief The header file for the Device class.
*/

#ifndef EXECUTIVE_DEVICE_H_INCLUDED
#define EXECUTIVE_DEVICE_H_INCLUDED

// C++ standard library includes
#include <fstream>
#include <string>
#include <vector>

// Ocelot includes

namespace executive 
{
	/*! Class for controlling an Ocelot device */
	class Device 
	{
		public:
			/*! \brief properties of a specific device */
			class Properties
			{
				public:
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

				public:
					/*! Write attributes of the device to an output stream */
					std::ostream& write(std::ostream &out) const;
			};

			/*! \brief An interface to a memory allocation */
			class MemoryAllocation
			{
				protected:
					/*! \brief Is this memory allocation a global variable? */
					bool global;
					/*! \brief Is this memory allocation a host allocation? */
					bool host;

				public:
					/*! \brief Generic constructor */
					MemoryAllocation(bool global = false, bool host = false);
					/*! \brief Virtual desructor */
					virtual ~MemoryAllocation();
			
				public:
					/*! \brief Is this a mapped host pointer? */
					virtual bool host() const;
					/*! \brief Is this a mapping for a global variable? */
					virtual bool global() const;
					/*! \brief Get a mapped pointer if this is a host allocation */
					virtual void* mappedPointer() = 0;
					/*! \brief Get a pointer to the base of the allocation */
					virtual void* pointer() = 0;
					/*! \brief The size of the allocation */
					virtual size_t size() const = 0;
					/*! \brief Copy from an external host pointer */
					virtual void copy(size_t offset, const void* host, 
						size_t size ) = 0;
					/*! \brief Copy to an external host pointer */
					virtual void copy(void* host, size_t size, 
						size_t offset) const = 0;
					/*! \brief Memset the allocation */
					virtual void memset(size_t offset, int value, size_t size);
					/*! \brief Copy to another allocation */
					virtual void copy(MemoryAllocation* allocation, 
						size_t size, size_t toOffset, 
						size_t fromOffset) const = 0;
			};

		protected:
			/*! \brief The properties of this device */
			Propertes _properties;
			/*! \brief The driver version */
			int _driverVersion;
			/*! \brief The runtime version */
			int _runtimeVersion;

		public:
			/*! \brief Check a memory access against all allocations */
			virtual bool checkMemoryAccess(void* pointer, 
				size_t size) const = 0;
			/*! \brief Get the allocation containing a pointer or 0 */
			virtual MemoryAllocation* getMemoryAllocation(void* address, 
				bool hostAllocation = false) = 0;
			/*! \brief Allocate some new dynamic memory on this device */
			virtual MemoryAllocation* allocate(size_t size) = 0;
			/*! \brief Make this a host memory allocation */
			virtual MemoryAllocation* allocateHost(size_t size) = 0;
			/*! \brief Free an existing non-global allocation */
			virtual void free(void* pointer) = 0;
		
		public:
			/*! \brief Registers an opengl buffer with a resource */
			virtual void* glRegisterBuffer(unsigned int buffer, 
				unsigned int flags) = 0;
			/*! \brief Registers an opengl image with a resource */
			virtual void* glRegisterImage(unsigned int image, 
				unsigned int target, unsigned int flags) = 0;
			/*! \brief Unregister a resource */
			virtual void unRegisterGraphicsResource(void* resource) = 0;
			/*! \brief Map a graphics resource for use with this device */
			virtual void mapGraphicsResource(void* resource, int count, 
				cudaStream_t stream) = 0;
			/*! \brief Get a pointer to a mapped resource along with its size */
			virtual void* getPointerToMappedGraphicsResource(size_t& size, 
				void* resource) const = 0;
			/*! \brief Change the flags of a mapped resource */
			virtual void setGraphicsResourceFlags(void* resource, 
				unsigned int flags) = 0;
			/*! \brief Unmap a mapped resource */
			virtual void unmapGraphicsResource(void* resource) = 0;

		public:
			/*! \brief Load a module */
			virtual void load(const std::string& name, 
				std::istream& stream) = 0;
			/*! \brief Unload a module */
			virtual void unload(const std::string& name) = 0;

		public:
			/*! \brief Get the device properties */
			const Properties& properties() const;

		public:
			/*! \brief Create a new event */
			virtual cudaEvent_t createEvent(int flags) = 0;
			/*! \brief Destroy an existing event */
			virtual void destroyEvent(cudaEvent_t event) = 0;
			/*! \brief Query to see if an event has been recorded (yes/no) */
			virtual bool queryEvent(cudaEvent_t event) const = 0;
			/*! \brief Record something happening on an event */
			virtual void recordEvent(cudaEvent_t event, 
				cudaStream_t stream) = 0;
			/*! \brief Synchronize on an event */
			virtual void synchronizeEvent(cudaEvent_t event) = 0;
			/*! \brief Get the elapsed time in ms between two recorded events */
			virtual float getEventTime(cudaEvent_t start, 
				cudaEvent_t end) const = 0;
		
		public:
			/*! \brief Create a new stream */
			virtual cudaStream_t createStream();
			/*! \brief Destroy an existing stream */
			virtual void destroyStream(cudaStream_t stream);
			/*! \brief Query the status of an existing stream (ready/not) */
			virtual bool queryStream(cudaStream_t stream) const;
			/*! \brief Synchronize a particular stream */
			virtual void synchronizeStream(cudaStream_t stream);
			/*! \brief Sets the current stream */
			virtual void setStream(cudaStream_t stream) = 0;
			
		public:
			/*! \brief Select this device as the current device. 
				Only one device is allowed to be selected at any time. */
			virtual void select() = 0;
			/*! \brief is this device selected? */
			virtual bool selected() const = 0;
			/*! \brief Deselect this device. */
			virtual void unselect() = 0;
			/*! \brief Set flags for this device */
			virtual void setDeviceFlags(unsigned int flags) = 0;
		
		public:
			/*! \brief Binds a texture to a memory allocation at a pointer */
			virtual void bindTexture(void* pointer, void* texture, 
				const cudaChannelFormatDesc& desc, size_t size) = 0;
			/*! \brief unbinds anything bound to a particular texture */
			virtual void unbindTexture(void* texture) = 0;
			/*! \brief Get a texture reference for a given symbol name */
			virtual void* getTextureReference(const std::string& name) = 0;
		
		public:
			/*! \brief Get the driver version */
			int driverVersion() const;
			/*! \brief Get the runtime version */
			int runtimeVersion() const;

		public:
			/*! \brief helper function for launching a kernel
				\param module module name
				\param kernel kernel name
				\param grid grid dimensions
				\param block block dimensions
				\param sharedMemory shared memory size
				\param parameterBlock array of bytes for parameter memory
				\param parameterBlockSize number of bytes in parameter memory
				\param traceGenerators vector of trace generators to add 
					and remove from kernel
				\param stream The stream to launch the kernel in
			*/
			virtual void launch(const std::string& module, 
				const std::string& kernel, dim3 grid, dim3 block, 
				size_t sharedMemory, void* parameterBlock, 
				size_t parameterBlockSize, 
				const trace::TraceGeneratorVector& 
				traceGenerators = trace::TraceGeneratorVector()) = 0;
			/*! \brief Get the function attributes of a specific kernel */
			virtual FunctionAttributes getAttributes(const std::string& module, 
				const std::string& kernel) const = 0;
			/*! \brief Get the last error from this device */
			virtual cudaError_t getLastError() const = 0;
			
		public:
			/*! \brief Sets the device properties */
			Device();
			/*! \brief Virtual destructor is required */
			virtual ~Device();

	};
	
	typedef std::vector< Device* > DeviceVector;
}

#endif
