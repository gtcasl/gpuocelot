/*! \file ATIGPUDevice.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \cate April 7, 2010
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

#define checkError(x) if(x != CAL_RESULT_OK) { \
	throw hydrazine::Exception(cal::CalDriver::Instance()->calGetErrorString()); }
#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str()); }

namespace executive
{
    ATIGPUDevice::ATIGPUDevice() 
		: _device(0), 
		  _context(0), 
		  _object(0), 
		  _image(0), 
		  _module(0)  
    {
        checkError(cal::CalDriver::Instance()->calDeviceOpen(&_device, 0));
        checkError(cal::CalDriver::Instance()->calDeviceGetInfo(&_info, 0));

        // multiple contexts per device is not supported yet
        // only one context per device so we can create it in the constructor
        checkError(cal::CalDriver::Instance()->calCtxCreate(&_context, _device));
    }

    ATIGPUDevice::~ATIGPUDevice() 
    {
        checkError(cal::CalDriver::Instance()->calCtxDestroy(_context));
        checkError(cal::CalDriver::Instance()->calDeviceClose(_device));
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

		checkError(cal::CalDriver::Instance()->calclCompile(&_object, CAL_LANGUAGE_IL, ILKernel, _info.target));
		checkError(cal::CalDriver::Instance()->calclLink(&_image, &_object, 1));
		checkError(cal::CalDriver::Instance()->calModuleLoad(&_module, _context, _image));
    }

    void ATIGPUDevice::unload(const std::string& name)
    {
		checkError(cal::CalDriver::Instance()->calModuleUnload(_context, _module));
		checkError(cal::CalDriver::Instance()->calclFreeImage(_image));
		checkError(cal::CalDriver::Instance()->calclFreeObject(_object));
    }

    void ATIGPUDevice::select()
    {
        // multiple devices is not supported yet
    }

    bool ATIGPUDevice::selected() const
    {
        // multiple devices is not supported yet
        return true;
    }

    void ATIGPUDevice::unselect()
    {
        // multiple devices is not supported yet
    }

	ATIGPUDevice::MemoryAllocation *ATIGPUDevice::getMemoryAllocation(
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

	ATIGPUDevice::MemoryAllocation *ATIGPUDevice::allocate(size_t size)
	{
		MemoryAllocation *allocation = new MemoryAllocation(_device, size);
		_allocations.insert(std::make_pair(allocation->pointer(), allocation));
		return allocation;
	}

	void ATIGPUDevice::free(void *pointer)
	{
		if (pointer == 0) return;

		AllocationMap::iterator allocation = _allocations.find(pointer);
		if (allocation != _allocations.end()) {
			delete allocation->second;
			_allocations.erase(allocation);
		} else {
			Throw("Tried to free invalid pointer - " << pointer);
		}
	}

	ATIGPUDevice::MemoryAllocation::MemoryAllocation(CALdevice device, size_t size) : _size(size) 
	{
		// Only CAL_FORMAT_SIGNED_INT32_1 is supported for now
		CALuint width = size / sizeof(int);
		checkError(cal::CalDriver::Instance()->calResAllocLocal1D(
				&_resource, 
				device, 
				width,	
				CAL_FORMAT_SIGNED_INT32_1,
				CAL_RESALLOC_GLOBAL_BUFFER));
	}

	ATIGPUDevice::MemoryAllocation::~MemoryAllocation()
	{
		checkError(cal::CalDriver::Instance()->calResFree(_resource));
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
		return hydrazine::bit_cast<void*>(_resource);
	}

	size_t ATIGPUDevice::MemoryAllocation::size() const
	{
		return _size;
	}

	void ATIGPUDevice::MemoryAllocation::copy(size_t offset, const void* host, size_t size)
	{
		CALvoid *data = NULL;
		CALuint pitch = 0;
		CALuint flags = 0;

		checkError(cal::CalDriver::Instance()->calResMap(&data, &pitch, _resource, flags));
		memcpy(data, host, size);
		checkError(cal::CalDriver::Instance()->calResUnmap(_resource));
	}

	void ATIGPUDevice::MemoryAllocation::copy(void *host, size_t offset, size_t size) const
	{
		assertM(false, "Not implemented yet");
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
