/*! \file ATIGPUDevice.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 7, 2010
 *  \brief The source file for the ATI GPU Device class.
 */

// C standard library includes
#include <string.h>

// Ocelot includes
#include <ocelot/executive/interface/ATIGPUDevice.h>

// Hydrazine includes
#include <hydrazine/interface/Casts.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

// TODO Temporarily. Shouldn't be here
#include <ocelot/cuda/interface/cuda_runtime.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define checkError(x) if(x != CAL_RESULT_OK) { \
	throw hydrazine::Exception(CalDriver()->calGetErrorString()); }
#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str()); }

namespace executive
{
    ATIGPUDevice::ATIGPUDevice() 
		: _device(0), 
		  _context(0), 
		  _object(0), 
		  _image(0), 
		  _module(0),
		  _selected(false)
    {
        checkError(CalDriver()->calDeviceOpen(&_device, 0));
		report("calDeviceOpen");

        checkError(CalDriver()->calDeviceGetInfo(&_info, 0));
		report("calDeviceGetInfo");

        // multiple contexts per device is not supported yet
        // only one context per device so we can create it in the constructor
        checkError(CalDriver()->calCtxCreate(&_context, _device));
		report("calCtxCreate");

		_properties.name = "CAL Device";
    }

    ATIGPUDevice::~ATIGPUDevice() 
    {
        checkError(CalDriver()->calCtxDestroy(_context));
		report("calCtxDestroy");

        checkError(CalDriver()->calDeviceClose(_device));
		report("calDeviceClose");
    }

	DeviceVector ATIGPUDevice::createDevices(unsigned int flags)
	{
		DeviceVector devices;

		// multiple devices is not supported yet
		devices.push_back(new ATIGPUDevice());

		return std::move(devices);
	}

    void ATIGPUDevice::load(const ir::Module *irModule)
    {
		// Use a fixed ILKernel for now (no PTX-to-IL translation yet)
		const CALchar *ILKernel = 
			"il_cs_2_0\n"
			"dcl_num_thread_per_group 10\n"
			"dcl_raw_uav_id(0)\n"
			"dcl_raw_uav_id(1)\n"
			"dcl_literal l0, 4, 4, 4, 4\n"
			"dcl_literal l1, 2, 2, 2, 2\n"
			"mov r0.x, vAbsTidFlat.x\n"
			"ishl r0.x, r0.x, l0.x\n"
			"uav_raw_load_id(0) r1, r0.x\n"
			"imul r1, r1, l1\n"
			"uav_raw_store_id(1) mem.xyzw, r0.x, r1\n"
			"end\n";

		checkError(CalDriver()->calclCompile(&_object, CAL_LANGUAGE_IL, ILKernel, _info.target));
		report("calclCompile");

		checkError(CalDriver()->calclLink(&_image, &_object, 1));
		report("calclLink");
		
		checkError(CalDriver()->calModuleLoad(&_module, _context, _image));
		report("calModuleLoad");
    }

    void ATIGPUDevice::unload(const std::string& name)
    {
		checkError(CalDriver()->calModuleUnload(_context, _module));
		report("calModuleUnload");

		checkError(CalDriver()->calclFreeImage(_image));
		report("calclFreeImage");

		checkError(CalDriver()->calclFreeObject(_object));
		report("calclFreeObject");
    }

    void ATIGPUDevice::select()
    {
		// multiple devices is not supported yet
		assert(!selected());
		_selected = true;
    }

    bool ATIGPUDevice::selected() const
    {
		// multiple devices is not supported yet
        return _selected;
    }

    void ATIGPUDevice::unselect()
    {
		// multiple devices is not supported yet
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
			if (!_allocations.empty()) {
				// Device pointer arithmetic is not supported yet
				const AllocationMap::const_iterator alloc = _allocations.find((void *)address);
				if (alloc != _allocations.end()) {
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
		MemoryAllocation *allocation = new MemoryAllocation(
				_device, _context, _module, (unsigned int)_allocations.size(), size);
		_allocations.insert(std::make_pair(allocation->pointer(), allocation));
		return allocation;
	}

	Device::MemoryAllocation *ATIGPUDevice::allocateHost(size_t size, unsigned int flags)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::free(void *pointer)
	{
		if (pointer == 0) return;

		AllocationMap::iterator allocation = _allocations.find(pointer);
		if (allocation != _allocations.end()) {
			_allocations.erase(allocation);
			delete allocation->second;
		} else {
			Throw("Tried to free invalid pointer - " << pointer);
		}
	}

	Device::MemoryAllocationVector ATIGPUDevice::getNearbyAllocations(void *pointer) const
	{
		assertM(false, "Not implemented yet");
	}

	void *ATIGPUDevice::glRegisterBuffer(unsigned int buffer, unsigned int flags)
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
			void* resource) const
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::setGraphicsResourceFlags(void* resource, unsigned int flags)
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
		// Get module entry
		CALfunc func = 0;
		checkError(CalDriver()->calModuleGetEntry(
					&func,
					_context,
					_module,
					"main"));
		report("calModuleGetEntry");

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

		checkError(CalDriver()->calCtxRunProgramGrid(
					&event, 
					_context, 
					&pg));
		report("calCtxRunProgramGrid");

		while(CalDriver()->calCtxIsEventDone(_context, event) == CAL_RESULT_PENDING);
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

	inline cal::CalDriver *ATIGPUDevice::CalDriver()
	{
		return cal::CalDriver::Instance();
	}

	ATIGPUDevice::MemoryAllocation::MemoryAllocation(CALdevice device, CALcontext context, 
			CALmodule module, unsigned int uav, size_t size) : _context(context), _size(size)
	{
		// Allocate resource
		// Only CAL_FORMAT_SIGNED_INT32_1 is supported for now
		CALuint width = size / sizeof(int);

		checkError(CalDriver()->calResAllocLocal1D(
				&_resource, 
				device, 
				width,	
				CAL_FORMAT_SIGNED_INT32_1,
				CAL_RESALLOC_GLOBAL_BUFFER));
		report("calResAllocLocal1D");

		// Get memory handle
		checkError(CalDriver()->calCtxGetMem(
					&_mem,
					_context,
					_resource));
		report("calCtxGetMem");

		// Get module name
		std::stringstream s;
		s << "uav" << uav;
		checkError(CalDriver()->calModuleGetName(
					&_name, 
					_context, 
					module,
					s.str().c_str()));
		report("calModuleGetName");

		// Bind memory handle to module name
		checkError(CalDriver()->calCtxSetMem(
					_context,
					_name,
					_mem));
		report("calCtxSetMem");
	}

	ATIGPUDevice::MemoryAllocation::~MemoryAllocation()
	{
		checkError(CalDriver()->calCtxReleaseMem(_context, _mem));
		report("calCtxReleaseMem");

		checkError(CalDriver()->calResFree(_resource));
		report("calResFree");
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
		return (void *)_resource;
	}

	size_t ATIGPUDevice::MemoryAllocation::size() const
	{
		return _size;
	}

	void ATIGPUDevice::MemoryAllocation::copy(size_t offset, const void *host, size_t size)
	{
		CALvoid *data = NULL;
		CALuint pitch = 0;
		CALuint flags = 0;

		checkError(CalDriver()->calResMap(&data, &pitch, _resource, flags));
		report("calResMap");

		memcpy(data, host, size);

		checkError(CalDriver()->calResUnmap(_resource));
		report("calResUnmap");
	}

	void ATIGPUDevice::MemoryAllocation::copy(void *host, size_t offset, size_t size) const
	{
		CALvoid *data = NULL;
		CALuint pitch = 0;
		CALuint flags = 0;

		checkError(CalDriver()->calResMap(&data, &pitch, _resource, flags));
		report("calResMap");

		memcpy(host, data, size);

		checkError(CalDriver()->calResUnmap(_resource));
		report("calResUnmap");
	}

	void ATIGPUDevice::MemoryAllocation::memset(size_t offset, int value, size_t size)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIGPUDevice::MemoryAllocation::copy(Device::MemoryAllocation *allocation,
			size_t toOffset, size_t fromOffset, size_t size) const
	{
		assertM(false, "Not implemented yet");
	}
}
