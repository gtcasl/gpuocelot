/*!
	\file PassThroughDevice.h
	\author Andrew Kerr
	\date 15 February 2011
	\brief Defines a wrapper for Ocelot devices enabling monitoring, serialization, and decoupling
*/

#ifndef OCELOT_PASSTHROUGHDEVICE_H_INCLUDED
#define OCELOT_PASSTHROUGHDEVICE_H_INCLUDED

// Ocelot includes
#include <ocelot/executive/interface/Device.h>

namespace executive
{
	class ExecutableKernel;
}

namespace executive 
{
	/*! Interface for controlling an Ocelot device */
	class PassThroughDevice: public Device 
	{
		protected:
					
			/*! \brief function calls target this device*/
			Device *_target;

		public:
			/*! \brief Check a memory access against all allocations */
			virtual bool checkMemoryAccess(const void* pointer, 
				size_t size) const;
			/*! \brief Get the allocation containing a pointer or 0 */
			virtual Device::MemoryAllocation* getMemoryAllocation(const void* address, 
				AllocationType type = DeviceAllocation) const;
			/*! \brief Get the address of a global by name */
			virtual Device::MemoryAllocation* getGlobalAllocation(
				const std::string& module, const std::string& name);
			/*! \brief Allocate some new dynamic memory on this device */
			virtual Device::MemoryAllocation* allocate(size_t size);
			/*! \brief Make this a host memory allocation */
			virtual Device::MemoryAllocation* allocateHost(size_t size, 
				unsigned int flags = 0);
			/*! \brief Free an existing non-global allocation */
			virtual void free(void* pointer);
			/*! \brief Get nearby allocations to a pointer */
			virtual Device::MemoryAllocationVector getNearbyAllocations(
				void* pointer) const;
			/*! \brief Get all allocations, host, global, and device */
			virtual Device::MemoryAllocationVector getAllAllocations() const;
			/*! \brief Get a string representation of nearby allocations */
			virtual std::string nearbyAllocationsToString(void* pointer) const;
			/*! \brief Wipe all memory allocations, but keep modules */
			virtual void clearMemory();
		
		public:
			/*! \brief Registers an opengl buffer with a resource */
			virtual void* glRegisterBuffer(unsigned int buffer, 
				unsigned int flags);
			/*! \brief Registers an opengl image with a resource */
			virtual void* glRegisterImage(unsigned int image, 
				unsigned int target, unsigned int flags);
			/*! \brief Unregister a resource */
			virtual void unRegisterGraphicsResource(void* resource);
			/*! \brief Map a graphics resource for use with this device */
			virtual void mapGraphicsResource(void** resource, int count, 
				unsigned int stream);
			/*! \brief Get a pointer to a mapped resource along with its size */
			virtual void* getPointerToMappedGraphicsResource(size_t& size, 
				void* resource);
			/*! \brief Change the flags of a mapped resource */
			virtual void setGraphicsResourceFlags(void* resource, 
				unsigned int flags);
			/*! \brief Unmap a mapped resource */
			virtual void unmapGraphicsResource(void** resource, int count,
				unsigned int stream);

		public:
			/*! \brief Load a module, must have a unique name */
			virtual void load(const ir::Module* module);
			/*! \brief Unload a module by name */
			virtual void unload(const std::string& name);
			/*! \brief Get a translated kernel from the device */
			virtual ExecutableKernel* getKernel(const std::string& module, 
				const std::string& kernel);

		public:
			/*! \brief Get the device properties */
			const Properties& properties() const;

		public:
			/*! \brief Create a new event */
			virtual unsigned int createEvent(int flags);
			/*! \brief Destroy an existing event */
			virtual void destroyEvent(unsigned int event);
			/*! \brief Query to see if an event has been recorded (yes/no) */
			virtual bool queryEvent(unsigned int event);
			/*! \brief Record something happening on an event */
			virtual void recordEvent(unsigned int event, 
				unsigned int stream);
			/*! \brief Synchronize on an event */
			virtual void synchronizeEvent(unsigned int event);
			/*! \brief Get the elapsed time in ms between two recorded events */
			virtual float getEventTime(unsigned int start, 
				unsigned int end);
		
		public:
			/*! \brief Create a new stream */
			virtual unsigned int createStream();
			/*! \brief Destroy an existing stream */
			virtual void destroyStream(unsigned int stream);
			/*! \brief Query the status of an existing stream (ready/not) */
			virtual bool queryStream(unsigned int stream);
			/*! \brief Synchronize a particular stream */
			virtual void synchronizeStream(unsigned int stream);
			/*! \brief Sets the current stream */
			virtual void setStream(unsigned int stream);
			
		public:
			/*! \brief Select this device as the current device. 
				Only one device is allowed to be selected at any time. */
			virtual void select();
			/*! \brief is this device selected? */
			virtual bool selected() const;
			/*! \brief Deselect this device. */
			virtual void unselect();
		
		public:
			/*! \brief Binds a texture to a memory allocation at a pointer */
			virtual void bindTexture(void* pointer, 
				const std::string& moduleName, const std::string& textureName,
				const textureReference& ref, const cudaChannelFormatDesc& desc, 
				const ir::Dim3& size);
			/*! \brief unbinds anything bound to a particular texture */
			virtual void unbindTexture(const std::string& moduleName, 
				const std::string& textureName);
			/*! \brief Get's a reference to an internal texture */
			virtual void* getTextureReference(const std::string& moduleName, 
				const std::string& textureName);
		
		public:
			/*! \brief helper function for launching a kernel
				\param module module name
				\param kernel kernel name
				\param grid grid dimensions
				\param block block dimensions
				\param sharedMemory shared memory size
				\param argumentBlock array of bytes for argument memory
				\param argumentBlockSize number of bytes in argument memory
				\param traceGenerators vector of trace generators to add 
					and remove from kernel
			*/
			virtual void launch(const std::string& module, 
				const std::string& kernel, const ir::Dim3& grid, 
				const ir::Dim3& block, size_t sharedMemory, 
				const void* argumentBlock, size_t argumentBlockSize, 
				const trace::TraceGeneratorVector& 
				traceGenerators = trace::TraceGeneratorVector());
			/*! \brief Get the function attributes of a specific kernel */
			virtual cudaFuncAttributes getAttributes(const std::string& module, 
				const std::string& kernel);
			/*! \brief Get the last error from this device */
			virtual unsigned int getLastError();
			/*! \brief Wait until all asynchronous operations have completed */
			virtual void synchronize();
			
		public:
			virtual void limitWorkerThreads(unsigned int threads);
			virtual void setOptimizationLevel(
				translator::Translator::OptimizationLevel level);
			
		public:
			PassThroughDevice(Device *target, unsigned int flags = 0);
			virtual ~PassThroughDevice();
			
	};
}

#endif

