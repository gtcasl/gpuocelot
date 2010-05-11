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
#include <ocelot/translator/interface/PTXToILTranslator.h>

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
			_uav0Mem(0),
			_uav0Name(0),
			_cb0Resource(0),
			_cb0Mem(0),
			_cb0Name(0),
			_cb1Resource(0),
			_cb1Mem(0),
			_cb1Name(0),
			_device(0), 
			_info(),
			_context(0), 
			_object(0), 
			_image(0), 
			_module(0), 
			_ir(0),
			_selected(false)
    {
		CalDriver()->calDeviceOpen(&_device, 0);
		CalDriver()->calDeviceGetInfo(&_info, 0);

		_properties.name = "CAL Device";

        // Multiple contexts per device is not supported yet
        // only one context per device so we can create it in the constructor
		CalDriver()->calCtxCreate(&_context, _device);

		// Allocate uav0 resource
		CALuint width = _info.maxResource1DWidth;
		CALuint flags = CAL_RESALLOC_GLOBAL_BUFFER;
		CalDriver()->calResAllocLocal1D(
				&_uav0Resource, 
				_device, 
				width,
				CAL_FORMAT_INT_1,
				flags);

		// Get uav0 memory handle
		CalDriver()->calCtxGetMem(
					&_uav0Mem,
					_context,
					_uav0Resource);

		// Allocate cb0 resource
		flags = 0;
		CalDriver()->calResAllocLocal1D(
				&_cb0Resource, 
				_device, 
				cbMaxSize,
				CAL_FORMAT_INT_1,
				flags);

		// Get cb0 memory handle
		CalDriver()->calCtxGetMem(
					&_cb0Mem,
					_context,
					_cb0Resource);

		// Allocate cb1 resource
		flags = 0;
		CalDriver()->calResAllocLocal1D(
				&_cb1Resource, 
				_device, 
				cbMaxSize,
				CAL_FORMAT_INT_1,
				flags);

		// Get cb1 memory handle
		CalDriver()->calCtxGetMem(
					&_cb1Mem,
					_context,
					_cb1Resource);

    }

    ATIGPUDevice::~ATIGPUDevice() 
    {
		CalDriver()->calCtxReleaseMem(_context, _uav0Mem);
		CalDriver()->calCtxReleaseMem(_context, _cb0Mem);
		CalDriver()->calCtxReleaseMem(_context, _cb1Mem);

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
		if (_module != 0) assertM(false, "Multiple modules not supported yet");

		_ir = irModule;

		report("Running IL Translator");
		translator::PTXToILTranslator translator;

		std::string ILModule = translator.translate(irModule);

		CalDriver()->calclCompile(
					&_object, 
					CAL_LANGUAGE_IL, 
					ILModule.c_str(), 
					_info.target);

		CalDriver()->calclLink(&_image, &_object, 1);
		CalDriver()->calModuleLoad(&_module, _context, _image);

		// Get uav0 name
		CalDriver()->calModuleGetName(
					&_uav0Name, 
					_context, 
					_module,
					"uav0");

		// Bind uav0 memory handle to module name
		CalDriver()->calCtxSetMem(
					_context,
					_uav0Name,
					_uav0Mem);

		// Get cb0 name
		CalDriver()->calModuleGetName(
					&_cb0Name, 
					_context, 
					_module,
					"cb0");

		// Bind cb0 memory handle to module name
		CalDriver()->calCtxSetMem(
					_context,
					_cb0Name,
					_cb0Mem);

		// Get cb1 name
		CalDriver()->calModuleGetName(
					&_cb1Name, 
					_context, 
					_module,
					"cb1");

		// Bind cb1 memory handle to module name
		CalDriver()->calCtxSetMem(
					_context,
					_cb1Name,
					_cb1Mem);
    }

    void ATIGPUDevice::unload(const std::string& name)
    {
		CalDriver()->calModuleUnload(_context, _module);
		CalDriver()->calclFreeImage(_image);
		CalDriver()->calclFreeObject(_object);
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
		assertM(_ir->kernels.size() == 1, "Multiple kernels not supported yet");
		ATIExecutableKernel kernel(*_ir->kernels.begin()->second, 
				&_cb0Resource, &_cb1Resource);

		//kernel.setKernelShape(block.x, block.y, block.z);
		kernel.setParameterBlock((const unsigned char *)parameterBlock,
				parameterBlockSize);
		kernel.updateParameterMemory();

		// Get module entry
		CALfunc func = 0;
		CalDriver()->calModuleGetEntry(
					&func,
					_context,
					_module,
					"main");

		// Invoke kernel
		CALevent event = 0;
		CALprogramGrid pg;
		pg.func             = func;
		pg.flags            = 0;
		pg.gridBlock.width  = block.x;
		pg.gridBlock.height = block.y;
		pg.gridBlock.depth  = block.z;
		pg.gridSize.width   = grid.x;
		pg.gridSize.height  = grid.y;
		pg.gridSize.depth   = grid.z;

		CalDriver()->calCtxRunProgramGrid(
					&event, 
					_context, 
					&pg);

		while(!CalDriver()->calCtxIsEventDone(_context, event));
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
		assertM(false, "Not implemented yet");
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
				<< ", size = " << size
				<< ")");
		
		CalDriver()->calResUnmap(*_resource);
	}

	void ATIGPUDevice::MemoryAllocation::memset(size_t offset, int value, 
			size_t size)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::MemoryAllocation::copy(Device::MemoryAllocation *allocation,
			size_t toOffset, size_t fromOffset, size_t size) const
	{
		assertM(false, "Not implemented yet");
	}
}
