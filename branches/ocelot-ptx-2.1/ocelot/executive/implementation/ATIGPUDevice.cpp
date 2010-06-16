/*! \file ATIGPUDevice.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 7, 2010
 *  \brief The source file for the ATI GPU Device class.
 */

// C standard library includes
#include <string.h>

// Ocelot includes
#include <ocelot/executive/interface/ATIGPUDevice.h>
#include <ocelot/executive/interface/ATIExecutableKernel.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

// TODO Temporarily. Shouldn't be here
#include <ocelot/cuda/interface/cuda_runtime.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str()); }

namespace executive
{
    ATIGPUDevice::ATIGPUDevice() 
		: 
			_uav0Allocations(),
			_uav0AllocPtr(Uav0BaseAddr),
			_uav0Resource(0),
			_cb0Resource(0),
			_cb1Resource(0),
			_device(0), 
			_status(),
			_attribs(),
			_context(0), 
			_event(0),
			_selected(false)
    {
		report("Creating new ATIGPUDevice");

		CalDriver()->calDeviceOpen(&_device, 0);

		_attribs.struct_size = sizeof(CALdeviceattribs);
		CalDriver()->calDeviceGetAttribs(&_attribs, 0);

		_status.struct_size = sizeof(CALdevicestatus);
		CalDriver()->calDeviceGetStatus(&_status, _device);

		_properties.ISA = ir::Instruction::CAL;
		_properties.name = "CAL Device";
		_properties.multiprocessorCount = _attribs.numberOfShaderEngines;
		_properties.major = 1;

        // Multiple contexts per device is not supported yet
        // only one context per device so we can create it in the constructor
		CalDriver()->calCtxCreate(&_context, _device);

		// Allocate uav0 resource
		// TODO Define max resource allocation size
		CALuint width = 400000;
		CALuint flags = CAL_RESALLOC_GLOBAL_BUFFER;
		CalDriver()->calResAllocLocal1D(
				&_uav0Resource, 
				_device, 
				width,
				CAL_FORMAT_UNSIGNED_INT8_4,
				flags);

		// Allocate cb0 resource
		flags = 0;
		CalDriver()->calResAllocLocal1D(
				&_cb0Resource, 
				_device, 
				cbMaxSize,
				CAL_FORMAT_INT_4,
				flags);

		// Allocate cb1 resource
		flags = 0;
		CalDriver()->calResAllocLocal1D(
				&_cb1Resource, 
				_device, 
				cbMaxSize,
				CAL_FORMAT_INT_1,
				flags);
    }

    ATIGPUDevice::~ATIGPUDevice() 
    {
		_modules.clear();

		CalDriver()->calResFree(_uav0Resource);
		CalDriver()->calResFree(_cb0Resource);
		CalDriver()->calResFree(_cb1Resource);

        CalDriver()->calCtxDestroy(_context);
        CalDriver()->calDeviceClose(_device);
    }

	DeviceVector ATIGPUDevice::createDevices(unsigned int flags)
	{
		DeviceVector devices;

		try {
			// Multiple devices is not supported yet
			devices.push_back(new ATIGPUDevice());
		} catch (hydrazine::Exception he) {
			// Swallow the exception and return empty device vector
			report(he.what());
		}

		return std::move(devices);
	}
	
	unsigned int ATIGPUDevice::deviceCount()
	{
		CALuint count = 0;

		try {
			CalDriver()->calDeviceGetCount(&count);

			// Multiple devices is not supported yet
			if (count > 1) {
				assertM(false, "Multiple devices is not supported yet");
			}
		} catch (hydrazine::Exception he) {
			// Swallow the exception and return 0 devices
			report(he.what());
		}

		return count;
	}	

    void ATIGPUDevice::load(const ir::Module *irModule)
    {
		report("Loading Module...");

		if (_modules.count(irModule->path()) != 0)
		{
			Throw("Duplicate module - " << irModule->path());
		}
		_modules.insert(std::make_pair(irModule->path(), irModule));
    }

    void ATIGPUDevice::unload(const std::string& name)
    {
		ModuleMap::iterator module = _modules.find(name);
		if (module == _modules.end())
		{
			Throw("Cannot unload unknown module - " << name);
		}

		_modules.erase(module);
    }

    void ATIGPUDevice::select()
    {
		// Multiple devices is not supported yet
		assert(!selected());
		_selected = true;
    }

    bool ATIGPUDevice::selected() const
    {
		// Multiple devices is not supported yet
        return _selected;
    }

    void ATIGPUDevice::unselect()
    {
		// Multiple devices is not supported yet
		assert(selected());
		_selected = false;
    }

	Device::MemoryAllocation *ATIGPUDevice::getMemoryAllocation(
			const void *address, bool hostAllocation) const
	{
		MemoryAllocation *allocation = 0;

		if (hostAllocation) {
			assertM(false, "Not implemented yet");
		} else {
			if (!_uav0Allocations.empty()) {
				// Device pointer arithmetic is not supported yet
				const AllocationMap::const_iterator alloc = 
					_uav0Allocations.find((void *)address);
				if (alloc != _uav0Allocations.end()) {
					allocation = alloc->second;
				} else {
					Throw("No allocation found for this pointer - " << address);
				}
			}
		}

		return allocation;
	}
	
	Device::MemoryAllocation *ATIGPUDevice::getGlobalAllocation(
			const std::string &moduleName, const std::string &name)
	{
		assertM(false, "Not implemented yet");
	}

	Device::MemoryAllocation *ATIGPUDevice::allocate(size_t size)
	{
		// TODO Check uav0 size limits
		MemoryAllocation *allocation = 
			new MemoryAllocation(&_uav0Resource, _uav0AllocPtr, size);
		_uav0Allocations.insert(
				std::make_pair(allocation->pointer(), allocation));
		_uav0AllocPtr += size;
		return allocation;
	}

	Device::MemoryAllocation *ATIGPUDevice::allocateHost(size_t size, 
			unsigned int flags)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::free(void *pointer)
	{
		if (pointer == 0) return;

		AllocationMap::iterator allocation = _uav0Allocations.find(pointer);
		if (allocation != _uav0Allocations.end()) {
			_uav0Allocations.erase(allocation);
			delete allocation->second;
		} else {
			Throw("Tried to free invalid pointer - " << pointer);
		}
	}

	Device::MemoryAllocationVector ATIGPUDevice::getNearbyAllocations(
		void *pointer) const
	{
		assertM(false, "Not implemented yet");
	}

	Device::MemoryAllocationVector ATIGPUDevice::getAllAllocations() const
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::clearMemory()
	{
		assertM(false, "Not implemented yet");
	}

	void *ATIGPUDevice::glRegisterBuffer(unsigned int buffer, 
			unsigned int flags)
	{
		assertM(false, "Not implemented yet");
	}

	void *ATIGPUDevice::glRegisterImage(unsigned int image, unsigned int target, 
			unsigned int flags)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::unRegisterGraphicsResource(void* resource)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::mapGraphicsResource(void* resource, int count, 
			unsigned int stream)
	{
		assertM(false, "Not implemented yet");
	}

	void *ATIGPUDevice::getPointerToMappedGraphicsResource(size_t& size, 
			void* resource)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::setGraphicsResourceFlags(void* resource, 
		unsigned int flags)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::unmapGraphicsResource(void* resource)
	{
		assertM(false, "Not implemented yet");
	}

	unsigned int ATIGPUDevice::createEvent(int flags)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::destroyEvent(unsigned int event)
	{
		assertM(false, "Not implemented yet");
	}

	bool ATIGPUDevice::queryEvent(unsigned int event) const
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::recordEvent(unsigned int event, unsigned int stream)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::synchronizeEvent(unsigned int event)
	{
		assertM(false, "Not implemented yet");
	}

	float ATIGPUDevice::getEventTime(unsigned int start, unsigned int end) const
	{
		assertM(false, "Not implemented yet");
	}

	unsigned int ATIGPUDevice::createStream()
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::destroyStream(unsigned int stream)
	{
		assertM(false, "Not implemented yet");
	}

	bool ATIGPUDevice::queryStream(unsigned int stream) const
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::synchronizeStream(unsigned int stream)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::setStream(unsigned int stream)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::bindTexture(void* pointer, const std::string& moduleName, 
		const std::string& textureName, const textureReference& ref, 
		const cudaChannelFormatDesc& desc, const ir::Dim3& size)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::unbindTexture(const std::string& moduleName, 
		const std::string& textureName)
	{
		assertM(false, "Not implemented yet");
	}

	void* ATIGPUDevice::getTextureReference(const std::string& moduleName, 
		const std::string& textureName)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::launch(
			const std::string& moduleName,
			const std::string& kernelName, 
			const ir::Dim3& grid, 
			const ir::Dim3& block, 
			size_t sharedMemory, 
			const void *parameterBlock, 
			size_t parameterBlockSize, 
			const trace::TraceGeneratorVector& traceGenerators)
	{
		ModuleMap::iterator module = _modules.find(moduleName);

		if (module == _modules.end())
		{
			Throw("Unknown module - " << moduleName);
		}

		ir::Module::KernelMap::const_iterator irKernel = 
			module->second->kernels().find(kernelName);

		if (irKernel == module->second->kernels().end())
		{
			Throw("Unknown kernel - " << kernelName
					<< " in module " << moduleName);
		}

		ATIExecutableKernel kernel(*irKernel->second, &_context, &_event, 
				&_uav0Resource, &_cb0Resource, &_cb1Resource);

		kernel.setKernelShape(block.x, block.y, block.z);
		kernel.setParameterBlock((const unsigned char *)parameterBlock, 
				parameterBlockSize);
		kernel.updateParameterMemory();
		kernel.launchGrid(grid.x, grid.y);
		synchronize();
	}

	cudaFuncAttributes ATIGPUDevice::getAttributes(const std::string& module, 
			const std::string& kernel)
	{
		assertM(false, "Not implemented yet");
	}

	unsigned int ATIGPUDevice::getLastError() const
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::synchronize()
	{
		while(_event && !CalDriver()->calCtxIsEventDone(_context, _event));
	}

	void ATIGPUDevice::limitWorkerThreads(unsigned int threads)
	{
		assertM(false, "Not implemented yet");
	}		

	void ATIGPUDevice::setOptimizationLevel(
			translator::Translator::OptimizationLevel l)
	{
		assertM(false, "Not implemented yet");
	}		

	inline const cal::CalDriver *ATIGPUDevice::CalDriver()
	{
		return cal::CalDriver::Instance();
	}

	ATIGPUDevice::MemoryAllocation::MemoryAllocation(CALresource *resource, 
			const CALdeviceptr basePtr, size_t size) 
		: _resource(resource), _basePtr(basePtr), _size(size)
	{
		assertM(resource, "Invalid resource");
		assertM(basePtr, "Invalid device pointer");
		assertM(size, "Invalid size");
	}

	unsigned int ATIGPUDevice::MemoryAllocation::flags() const
	{
		assertM(false, "Not implemented yet");
	}

	void *ATIGPUDevice::MemoryAllocation::mappedPointer() const
	{
		assertM(false, "Not implemented yet");
	}

	void *ATIGPUDevice::MemoryAllocation::pointer() const
	{
		return (void *)_basePtr;
	}

	size_t ATIGPUDevice::MemoryAllocation::size() const
	{
		return _size;
	}

	/*! \brief Copy from an external host pointer */
	void ATIGPUDevice::MemoryAllocation::copy(size_t offset, const void *host, 
			size_t size)
	{
		assertM(host != 0, "Invalid host pointer");
		assertM(offset + size <= _size, "Invalid copy size");
		
		CALvoid *data = NULL;
		CALuint pitch = 0;
		CALuint flags = 0;

		CalDriver()->calResMap(&data, &pitch, *_resource, flags);

		CALdeviceptr addr = (_basePtr - ATIGPUDevice::Uav0BaseAddr) + offset;
		std::memcpy((char *)data + addr, host, size);

		report("MemoryAllocation::copy("
				<< "offset = " << std::dec << offset
				<< ", host = " << std::hex << std::showbase << host
				<< ", size = " << std::dec << size
				<< ")");
		
		CalDriver()->calResUnmap(*_resource);
	}

	/*! \brief Copy to an external host pointer */
	void ATIGPUDevice::MemoryAllocation::copy(void *host, size_t offset, 
			size_t size) const
	{
		assertM(host != 0, "Invalid host pointer");
		assertM(offset + size <= _size, "Invalid copy size");

		CALvoid *data = NULL;
		CALuint pitch = 0;
		CALuint flags = 0;

		CalDriver()->calResMap(&data, &pitch, *_resource, flags);

		CALdeviceptr addr = (_basePtr - ATIGPUDevice::Uav0BaseAddr) + offset;
		std::memcpy(host, (char *)data + addr, size);
		report("MemoryAllocation::copy("
				<< "host = " << std::hex << std::showbase << host
				<< ", offset = " << std::dec << offset
				<< ", size = " << std::dec << size
				<< ")");
		
		CalDriver()->calResUnmap(*_resource);
	}

	void ATIGPUDevice::MemoryAllocation::memset(size_t offset, int value, 
			size_t size)
	{
		assertM(offset + size <= _size, "Invalid memset size");
		
		CALvoid *data = NULL;
		CALuint pitch = 0;
		CALuint flags = 0;

		CalDriver()->calResMap(&data, &pitch, *_resource, flags);

		CALdeviceptr addr = (_basePtr - ATIGPUDevice::Uav0BaseAddr) + offset;
		std::memset((char *)data + addr, value, size);

		report("MemoryAllocation::memset("
				<< "offset = " << std::dec << offset
				<< ", value = " << std::dec << value
				<< ", size = " << std::dec << size
				<< ")");
		
		CalDriver()->calResUnmap(*_resource);
	}

	void ATIGPUDevice::MemoryAllocation::copy(Device::MemoryAllocation *allocation,
			size_t toOffset, size_t fromOffset, size_t size) const
	{
		assertM(false, "Not implemented yet");
	}
}
