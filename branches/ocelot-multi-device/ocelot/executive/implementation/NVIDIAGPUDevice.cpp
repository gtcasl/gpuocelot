/*! \file NVIDIAGPUDevice.cpp
	\author Gregory Diamos
	\date April 7, 2010
	\brief The source file for the NVIDIAGPUDevice class.
*/

#ifndef NVIDIA_GPU_DEVICE_CPP_INCLUDED
#define NVIDIA_GPU_DEVICE_CPP_INCLUDED

// ocelot includes
#include <ocelot/executive/interface/NVIDIAGPUDevice.h>
#include <ocelot/executive/interface/NVIDIAExecutableKernel.h>
#include <ocelot/cuda/interface/CudaDriver.h>
#include <ocelot/cuda/interface/cuda_runtime.h>

// hydrazine includes
#include <hydrazine/interface/Casts.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

// standard library includes
#include <cstring>

typedef cuda::CudaDriver driver;

#define checkError(x) if((_lastError = x) != CUDA_SUCCESS) { \
	throw hydrazine::Exception(driver::toString(_lastError)); }
#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str()); }

namespace executive 
{
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation() : _flags(0), _size(0),
		_devicePointer(0), _hostPointer(0)
	{
		
	}
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(size_t size) : 
		_flags(0), _size(size), _hostPointer(0)
	{
		checkError(driver::cuMemAlloc(&_devicePointer, size));
	}
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(size_t size, 
		unsigned int flags) : Device::MemoryAllocation(false, true), 
		_flags(flags), _size(size)
	{
		// making all memory portable eases context switching
		_flags |= CU_MEMHOSTALLOC_PORTABLE;
		
		checkError(driver::cuMemHostAlloc(&_hostPointer, size, _flags));
		checkError(driver::cuMemHostGetDevicePointer(&_devicePointer, 
			_hostPointer, 0));
	}
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(CUmodule module, 
		const ir::Global& g) : Device::MemoryAllocation(true, false), _flags(0),
		_size(g.statement.bytes()), _hostPointer(0)
	{
		unsigned int bytes;
		checkError(driver::cuModuleGetGlobal(&_devicePointer, &bytes, module, 
			g.statement.name.c_str()));
		if(bytes != _size)
		{
			Throw("Global variable - " << g.statement.name 
				<< " - declared with " << _size << " bytes in Ocelot, but " 
				<< bytes << " in the CUDA driver.");
		}
	}
	
	NVIDIAGPUDevice::MemoryAllocation::~MemoryAllocation()
	{
		if(host())
		{
			checkError(driver::cuMemFreeHost(_hostPointer));
		}
		else if(!global())
		{
			checkError(driver::cuMemFree(_devicePointer));
		}
	}

	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(
		const MemoryAllocation& a) : Device::MemoryAllocation(
		a.global(), a.host()), _flags(a.flags()), _size(a.size()), 
		_devicePointer(0), _hostPointer(0)
	{
		if(host())
		{
			checkError(driver::cuMemHostAlloc(&_hostPointer, _size, _flags));
			checkError(driver::cuMemHostGetDevicePointer(&_devicePointer, 
				_hostPointer, 0));
			memcpy(_hostPointer, a._hostPointer, _size);
		}
		else if(global())
		{
			_devicePointer = a._devicePointer;
		}
		else
		{
			checkError(driver::cuMemAlloc(&_devicePointer, _size));
			checkError(driver::cuMemcpyDtoD(_devicePointer, 
				a._devicePointer, _size));
		}
	}
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(MemoryAllocation&& a) :
		_flags(0), _size(0), _devicePointer(0), _hostPointer(0)
	{
		std::swap(_host, a._host);
		std::swap(_global, a._global);
		std::swap(_flags, a._flags);
		std::swap(_size, a._size);
		std::swap(_devicePointer, a._devicePointer);
		std::swap(_hostPointer, a._hostPointer);
	}

	NVIDIAGPUDevice::MemoryAllocation& 
		NVIDIAGPUDevice::MemoryAllocation::operator=(const MemoryAllocation& a)
	{
		if(this == &a) return *this;

		if(host())
		{
			checkError(driver::cuMemFreeHost(_hostPointer));
		}
		else if(!global())
		{
			checkError(driver::cuMemFree(_devicePointer));
		}
		
		_host = a._host;
		_global = a._global;
		_flags = a._flags;
		_size = a._size;
		_hostPointer = 0;
		_devicePointer = 0;
		
		if(host())
		{
			checkError(driver::cuMemHostAlloc(&_hostPointer, _size, _flags));
			checkError(driver::cuMemHostGetDevicePointer(&_devicePointer, 
				_hostPointer, 0));
			memcpy(_hostPointer, a._hostPointer, _size);
		}
		else if(global())
		{
			_devicePointer = a._devicePointer;
		}
		else
		{
			checkError(driver::cuMemAlloc(&_devicePointer, _size));
			checkError(driver::cuMemcpyDtoD(_devicePointer, 
				a._devicePointer, _size));
		}
		
		return *this;
	}
	
	NVIDIAGPUDevice::MemoryAllocation& 
		NVIDIAGPUDevice::MemoryAllocation::operator=(MemoryAllocation&& a)
	{
		if(this == &a) return *this;

		std::swap(_host, a._host);
		std::swap(_global, a._global);
		std::swap(_flags, a._flags);
		std::swap(_size, a._size);
		std::swap(_devicePointer, a._devicePointer);
		std::swap(_hostPointer, a._hostPointer);

		return *this;		
	}

	unsigned int NVIDIAGPUDevice::MemoryAllocation::flags() const
	{
		return _flags;
	}

	void* NVIDIAGPUDevice::MemoryAllocation::mappedPointer() const
	{
		return _hostPointer;
	}

	void* NVIDIAGPUDevice::MemoryAllocation::pointer() const
	{
		return (void*)_devicePointer;
	}

	size_t NVIDIAGPUDevice::MemoryAllocation::size() const
	{
		return _size;
	}

	void NVIDIAGPUDevice::MemoryAllocation::copy(size_t offset, 
		const void* src, size_t s)
	{
		assert(offset + s <= size());
		if(host())
		{
			memcpy((char*)_hostPointer + offset, src, s);
		}
		else
		{
			CUdeviceptr dst = _devicePointer + offset;
			checkError(driver::cuMemcpyHtoD(dst, src, s));
		}
	}
	
	void NVIDIAGPUDevice::MemoryAllocation::copy(void* dst, 
		size_t offset, size_t s) const
	{
		assert(offset + s <= size());
		if(host())
		{
			std::memcpy(dst, (char*)_hostPointer + offset, s);
		}
		else
		{
			CUdeviceptr src = _devicePointer + offset;
			checkError(driver::cuMemcpyDtoH(dst, src, s));
		}
	}
	
	void NVIDIAGPUDevice::MemoryAllocation::memset(size_t offset, 
		int value, size_t s)
	{
		assert(s + offset <= size());
		if(host())
		{
			std::memset((char*)_hostPointer + offset, value, s);
		}
		else
		{
			CUdeviceptr dst = _devicePointer + offset;
			checkError(driver::cuMemsetD8(dst, value, s));
		}
	}
	
	void NVIDIAGPUDevice::MemoryAllocation::copy(Device::MemoryAllocation* a, 
		size_t toOffset, size_t fromOffset, size_t s) const
	{
		MemoryAllocation* allocation = static_cast<MemoryAllocation*>(a);
		assert(fromOffset + s <= size());
		assert(toOffset + s <= allocation->size());
		
		if(host())
		{
			if(allocation->host())
			{
				void* src = (char*)_hostPointer + fromOffset;
				void* dst = (char*)allocation->_hostPointer + toOffset;
				
				memcpy(dst, src, s);
			}
			else
			{
				void* src = (char*)_hostPointer + fromOffset;
				CUdeviceptr dst = allocation->_devicePointer + toOffset;

				checkError(driver::cuMemcpyHtoD(dst, src, s));
			}
		}
		else
		{
			if(allocation->host())
			{
				CUdeviceptr src = _devicePointer + fromOffset;
				void* dst = (char*)allocation->_hostPointer + toOffset;

				checkError(driver::cuMemcpyDtoH(dst, src, s));
			}
			else
			{
				CUdeviceptr src = _devicePointer + fromOffset;
				CUdeviceptr dst = allocation->_devicePointer + toOffset;

				checkError(driver::cuMemcpyDtoD(dst, src, s));
			}
		}
	}

	NVIDIAGPUDevice::Module::Module(const ir::Module* m) : _handle(0), ir(m)
	{
	
	}
	
	NVIDIAGPUDevice::Module::Module(const Module& m) : _handle(0), ir(m.ir)
	{
		
	}
	
	NVIDIAGPUDevice::Module::~Module()
	{
		for(KernelMap::iterator kernel = kernels.begin(); 
			kernel != kernels.end(); ++kernel)
		{
			delete kernel->second;
		}
		
		if(_handle != 0)
		{
			checkError(driver::cuModuleUnload(_handle));
		}
	}
	
	void NVIDIAGPUDevice::Module::load()
	{
		assert(!loaded());
		std::stringstream stream;
		ir->write(stream);
		
		checkError(driver::cuModuleLoadData(&_handle, stream.str().c_str()));
	}

	bool NVIDIAGPUDevice::Module::loaded() const
	{
		return _handle != 0;	
	}	
	
	void NVIDIAGPUDevice::Module::translate()
	{
		if(!loaded()) load();
				
		for(ir::Module::KernelMap::const_iterator kernel = ir->kernels.begin(); 
			kernel != ir->kernels.end(); ++kernel)
		{
			CUfunction function;
			checkError(driver::cuModuleGetFunction(&function, _handle, 
				kernel->first.c_str()));
			kernels.insert(std::make_pair(kernel->first, 
				new NVIDIAExecutableKernel(*kernel->second, function)));
		}
	}
	
	NVIDIAGPUDevice::Module::AllocationVector 
		NVIDIAGPUDevice::Module::loadGlobals()
	{
		if(!loaded()) load();
		assert(globals.empty());
		
		AllocationVector allocations;
		
		for(ir::Module::GlobalMap::const_iterator global = ir->globals.begin(); 
			global != ir->globals.end(); ++global)
		{
			MemoryAllocation allocation(_handle, global->second);
			
			globals.insert(std::make_pair(global->first, allocation.pointer()));
			allocations.push_back(std::move(allocation));
		}
		
		return std::move(allocations);
	}
	
	bool NVIDIAGPUDevice::Module::translated() const
	{
		return _handle != 0;
	}
	
	NVIDIAExecutableKernel* NVIDIAGPUDevice::Module::getKernel(
		const std::string& name)
	{
		if(!translated()) translate();
		
		NVIDIAExecutableKernel* kernel = 0;
		KernelMap::iterator k = kernels.find(name);
		if(k != kernels.end())
		{
			kernel = k->second;
		}
		return kernel;
	}

	void* NVIDIAGPUDevice::Module::getTexture(const std::string& name)
	{
		if(!loaded()) load();
		
		CUtexref texture;
		checkError(driver::cuModuleGetTexRef(&texture, _handle, name.c_str()));
		return texture;
	}

	bool NVIDIAGPUDevice::_cudaDriverInitialized = false;

	CUresult NVIDIAGPUDevice::_lastError = CUDA_SUCCESS;

	DeviceVector NVIDIAGPUDevice::createDevices(unsigned int flags)
	{
		if(!_cudaDriverInitialized)
		{
			driver::cuInit(0);
			_cudaDriverInitialized = true;
		}

		DeviceVector devices;
		int count;
		checkError(driver::cuDeviceGetCount(&count));
		
		for(int i = 0; i != count; ++i)
		{
			devices.push_back(new NVIDIAGPUDevice(i, flags));
		}
		
		return std::move(devices);
	}

	NVIDIAGPUDevice::NVIDIAGPUDevice(int id, unsigned int flags) : 
		Device(id, flags), _selected(false), _next(0), _selectedStream(0), 
		_opengl(true)
	{
		if(!_cudaDriverInitialized)
		{
			checkError(driver::cuInit(0));
			_cudaDriverInitialized = true;
		}
		
		_runtimeVersion = 3000;
		checkError(driver::cuDriverGetVersion(&_driverVersion));
		
		CUdevice device;
		checkError(driver::cuDeviceGet(&device, id));
		
		if(driver::cuGLCtxCreate(&_context, flags, device) != CUDA_SUCCESS)
		{
			_opengl = false;
			checkError(driver::cuCtxCreate(&_context, flags, device));
		}

		checkError(driver::cuCtxPopCurrent(&_context));
		
		char name[256];
		checkError(driver::cuDeviceGetName(name, 255, device));
		_properties.name = name;
		
		unsigned int total;
		checkError(driver::cuDeviceTotalMem(&total, device));
		_properties.totalMemory = total;
		
		checkError(driver::cuDeviceGetAttribute(&_properties.multiprocessorCount, 
			CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.memcpyOverlap, 
			CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.maxThreadsPerBlock, 
			CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK, device));
		
		checkError(driver::cuDeviceGetAttribute(&_properties.maxThreadsDim[0], 
			CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.maxThreadsDim[1], 
			CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.maxThreadsDim[2], 
			CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z, device));
		
		checkError(driver::cuDeviceGetAttribute(&_properties.maxGridSize[0], 
			CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.maxGridSize[1], 
			CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.maxGridSize[2], 
			CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z, device));

		checkError(driver::cuDeviceGetAttribute(&_properties.sharedMemPerBlock, 
			CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, device));
		checkError(driver::cuDeviceGetAttribute(
			&_properties.totalConstantMemory, 
			CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.SIMDWidth, 
			CU_DEVICE_ATTRIBUTE_WARP_SIZE, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.memPitch, 
			CU_DEVICE_ATTRIBUTE_MAX_PITCH, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.regsPerBlock, 
			CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.clockRate, 
			CU_DEVICE_ATTRIBUTE_CLOCK_RATE, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.textureAlign, 
			CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT, device));
		checkError(driver::cuDeviceComputeCapability(&_properties.major, 
			&_properties.major, device));
	}

	NVIDIAGPUDevice::~NVIDIAGPUDevice()
	{
		assert(!selected());
		
		checkError(driver::cuCtxDestroy(_context));
	}
	
	Device::MemoryAllocation* NVIDIAGPUDevice::getMemoryAllocation(
		const void* address, bool hostAllocation) const
	{
		MemoryAllocation* allocation = 0;
		if(hostAllocation)
		{
			if(!_hostAllocations.empty())
			{
				AllocationMap::const_iterator alloc = 
					_hostAllocations.upper_bound((void*)address);
				if(alloc != _hostAllocations.begin()) --alloc;
				if(alloc != _hostAllocations.end())
				{
					if((char*)address >= (char*)alloc->second->mappedPointer())
					{
						allocation = alloc->second;
					}
				}
			}
		}
		else
		{
			if(!_allocations.empty())
			{
				AllocationMap::const_iterator alloc = _allocations.upper_bound(
					(void*)address);
				if(alloc != _allocations.begin()) --alloc;
				if(alloc != _allocations.end())
				{
					if((char*)address >= (char*)alloc->second->pointer())
					{
						allocation = alloc->second;
					}
				}
			}
		}

		return allocation;		
	}

	Device::MemoryAllocation* NVIDIAGPUDevice::getGlobalAllocation(
		const std::string& moduleName, const std::string& name)
	{
		ModuleMap::iterator module = _modules.find(moduleName);
		if(module == _modules.end()) return 0;
		
		if(module->second.globals.empty())
		{
			Module::AllocationVector allocations = std::move(
				module->second.loadGlobals());
			for(Module::AllocationVector::iterator 
				allocation = allocations.begin(); 
				allocation != allocations.end(); ++allocation)
			{
				_allocations.insert(std::make_pair(allocation->pointer(), 
					new MemoryAllocation(std::move(*allocation))));
			}
		}
		
		Module::GlobalMap::iterator global = module->second.globals.find(name);
		if(global == module->second.globals.end()) return 0;
		
		return getMemoryAllocation(global->second, false);
	}

	Device::MemoryAllocation* NVIDIAGPUDevice::allocate(size_t size)
	{
		MemoryAllocation* allocation = new MemoryAllocation(size);
		_allocations.insert(std::make_pair(allocation->pointer(), allocation));
		return allocation;
	}

	Device::MemoryAllocation* NVIDIAGPUDevice::allocateHost(
		size_t size, unsigned int flags)
	{
		MemoryAllocation* allocation = new MemoryAllocation(size, flags);
		_allocations.insert(std::make_pair(allocation->pointer(), allocation));
		return allocation;		
	}

	void NVIDIAGPUDevice::free(void* pointer)
	{
		if(pointer == 0) return;
		
		AllocationMap::iterator allocation = _allocations.find(pointer);
		if(allocation != _allocations.end())
		{
			if(allocation->second->global())
			{
				Throw("Cannot free global pointer - " << pointer);
			}
			delete allocation->second;
			_allocations.erase(allocation);
		}
		else
		{
			allocation = _hostAllocations.find(pointer);
			if(allocation != _allocations.end())
			{
				delete allocation->second;
				_hostAllocations.erase(allocation);
			}
			else
			{
				Throw("Tried to free invalid pointer - " << pointer);
			}
		}
	}
	
	Device::MemoryAllocationVector NVIDIAGPUDevice::getNearbyAllocations(
		void* pointer) const
	{
		MemoryAllocationVector allocations;
		for(AllocationMap::const_iterator allocation = _allocations.begin(); 
			allocation != _allocations.end(); ++allocation)
		{
			allocations.push_back(allocation->second);
		}
		return std::move(allocations);
	}
		
	void* NVIDIAGPUDevice::glRegisterBuffer(unsigned int buffer, 
		unsigned int flags)
	{
		CUgraphicsResource resource;
		checkError(driver::cuGraphicsGLRegisterBuffer(&resource, 
			buffer, flags));
		return hydrazine::bit_cast<void*>(resource);
	}
	
	void* NVIDIAGPUDevice::glRegisterImage(unsigned int image, 
		unsigned int target, unsigned int flags)
	{
		CUgraphicsResource resource;
		checkError(driver::cuGraphicsGLRegisterImage(&resource, image, 
			target, flags));
		return resource;
	}
	
	void NVIDIAGPUDevice::unRegisterGraphicsResource(void* resource)
	{
		checkError(driver::cuGraphicsUnregisterResource(
			hydrazine::bit_cast<CUgraphicsResource>(resource)));
	}

	void NVIDIAGPUDevice::mapGraphicsResource(void* resource, int count, 
		unsigned int streamId)
	{
		StreamMap::iterator stream = _streams.find(streamId);

		if(stream == _streams.end())
		{
			Throw("Invalid stream - " << streamId);
		}

		checkError(driver::cuGraphicsMapResources(1, 
			(CUgraphicsResource*)resource, stream->second));
	}
	
	void* NVIDIAGPUDevice::getPointerToMappedGraphicsResource(size_t& size, 
		void* resource) const
	{
		CUdeviceptr pointer;
		unsigned int bytes = 0;
		checkError(driver::cuGraphicsResourceGetMappedPointer(&pointer, &bytes, 
			(CUgraphicsResource)resource));
		size = bytes;
		return hydrazine::bit_cast<void*>(pointer);
	}

	void NVIDIAGPUDevice::setGraphicsResourceFlags(void* resource, 
		unsigned int flags)
	{
		checkError(driver::cuGraphicsResourceSetMapFlags(
			(CUgraphicsResource)resource, flags));
	}

	void NVIDIAGPUDevice::unmapGraphicsResource(void* resource)
	{
		StreamMap::iterator stream = _streams.find(_selectedStream);
		assert(stream != _streams.end());
		
		checkError(driver::cuGraphicsUnmapResources(1, 
			(CUgraphicsResource*)resource, stream->second));
	}

	void NVIDIAGPUDevice::load(const ir::Module* module)
	{
		if(_modules.count(module->modulePath) != 0)
		{
			Throw("Duplicate module - " << module->modulePath);
		}
		_modules.insert(std::make_pair(module->modulePath, 
			Module(module)));
	}
	
	void NVIDIAGPUDevice::unload(const std::string& name)
	{
		ModuleMap::iterator module = _modules.find(name);
		if(module == _modules.end())
		{
			Throw("Cannot unload unknown module - " << name);
		}
		
		for(Module::GlobalMap::iterator global = module->second.globals.begin();
			global != module->second.globals.end(); ++global)
		{
			AllocationMap::iterator allocation = 
				_allocations.find(global->second);
			assert(allocation != _allocations.end());
			delete allocation->second;
			_allocations.erase(allocation);
		}
	}

	unsigned int NVIDIAGPUDevice::createEvent(int flags)
	{
		CUevent event;
		checkError(driver::cuEventCreate(&event, flags));
		
		unsigned int handle = _next++;
		_events.insert(std::make_pair(handle, event));
		
		return handle;
	}

	void NVIDIAGPUDevice::destroyEvent(unsigned int handle)
	{
		EventMap::iterator event = _events.find(handle);
		if(event == _events.end())
		{
			Throw("Invalid event - " << handle);
		}
		
		checkError(driver::cuEventDestroy(event->second));
		_events.erase(event);
	}

	bool NVIDIAGPUDevice::queryEvent(unsigned int handle) const
	{
		EventMap::const_iterator event = _events.find(handle);
		if(event == _events.end())
		{
			Throw("Invalid event - " << handle);
		}

		CUresult result = driver::cuEventQuery(event->second);
		if(result == CUDA_SUCCESS) return true;
		return false;
	}
	
	void NVIDIAGPUDevice::recordEvent(unsigned int handle, unsigned int sHandle)
	{
		EventMap::const_iterator event = _events.find(handle);
		if(event == _events.end())
		{
			Throw("Invalid event - " << handle);
		}

		StreamMap::const_iterator stream = _streams.find(sHandle);
		if(stream == _streams.end())
		{
			Throw("Invalid stream - " << sHandle);
		}

		checkError(driver::cuEventRecord(event->second, stream->second));				
	}

	void NVIDIAGPUDevice::synchronizeEvent(unsigned int handle)
	{
		EventMap::const_iterator event = _events.find(handle);
		if(event == _events.end())
		{
			Throw("Invalid event - " << handle);
		}

		checkError(driver::cuEventSynchronize(event->second));		
	}

	float NVIDIAGPUDevice::getEventTime(unsigned int startHandle, 
		unsigned int endHandle) const
	{
		EventMap::const_iterator start = _events.find(startHandle);
		if(start == _events.end())
		{
			Throw("Invalid start event - " << startHandle);
		}
		
		EventMap::const_iterator end = _events.find(endHandle);
		if(end == _events.end())
		{
			Throw("Invalid end event - " << endHandle);
		}
		
		float time = 0.0f;
		
		checkError(driver::cuEventElapsedTime(&time, 
			start->second, end->second));
		
		return time;
	}
		
	unsigned int NVIDIAGPUDevice::createStream()
	{
		CUstream stream;
		checkError(driver::cuStreamCreate(&stream, 0));
		
		unsigned int handle = _next++;
		_streams.insert(std::make_pair(handle, stream));
		
		return handle;
	}
	
	void NVIDIAGPUDevice::destroyStream(unsigned int handle)
	{
		StreamMap::iterator stream = _streams.find(handle);
		if(stream == _streams.end())
		{
			Throw("Invalid stream - " << handle);
		}
		
		checkError(driver::cuStreamDestroy(stream->second));
		_streams.erase(stream);
	}
	
	bool NVIDIAGPUDevice::queryStream(unsigned int handle) const
	{
		StreamMap::const_iterator stream = _streams.find(handle);
		if(stream == _streams.end())
		{
			Throw("Invalid stream - " << handle);
		}
	
		CUresult result = driver::cuStreamQuery(stream->second);
		if(result == CUDA_SUCCESS) return true;
		return false;
	}

	void NVIDIAGPUDevice::synchronizeStream(unsigned int handle)
	{
		StreamMap::iterator stream = _streams.find(handle);
		if(stream == _streams.end())
		{
			Throw("Invalid stream - " << handle);
		}
		
		checkError(driver::cuStreamSynchronize(stream->second));
	}

	void NVIDIAGPUDevice::setStream(unsigned int stream)
	{
		_selectedStream = stream;
	}
			
	void NVIDIAGPUDevice::select()
	{
		assert(!selected());
		_selected = true;
		checkError(driver::cuCtxPushCurrent(_context));
	}
	
	bool NVIDIAGPUDevice::selected() const
	{
		return _selected;
	}

	void NVIDIAGPUDevice::unselect()
	{
		assert(selected());
		_selected = false;
		checkError(driver::cuCtxPopCurrent(&_context));
	}
		
	void NVIDIAGPUDevice::bindTexture(void* pointer, 
		const std::string& moduleName, const std::string& textureName, 
		const textureReference& texref, const cudaChannelFormatDesc& desc, 
		const ir::Dim3& size)
	{
		ModuleMap::iterator module = _modules.find(moduleName);
		if(module == _modules.end())
		{
			Throw("Invalid Module - " << moduleName);
		}
		
		void* tex = module->second.getTexture(textureName);
		if(tex == 0)
		{
			Throw("Invalid Texture - " << textureName 
				<< " in Module - " << moduleName);
		}

		CUtexref ref = hydrazine::bit_cast<CUtexref>(tex);
		CUdeviceptr ptr = hydrazine::bit_cast<CUdeviceptr>(pointer);
		unsigned int offset = 0;
		checkError(driver::cuTexRefSetAddress(&offset, ref, ptr, 0));
		// TODO do the texture mapping
	}
	
	void NVIDIAGPUDevice::unbindTexture(const std::string& moduleName, 
		const std::string& textureName)
	{
		// this is a nop, textures cannot be unbound
		ModuleMap::iterator module = _modules.find(moduleName);
		if(module == _modules.end())
		{
			Throw("Invalid Module - " << moduleName);
		}
		
		void* tex = module->second.getTexture(textureName);
		if(tex == 0)
		{
			Throw("Invalid Texture - " << textureName 
				<< " in Module - " << moduleName);
		}
	}
	
	void* NVIDIAGPUDevice::getTextureReference(const std::string& moduleName, 
		const std::string& textureName)
	{
		ModuleMap::iterator module = _modules.find(moduleName);
		if(module == _modules.end()) return 0;
		
		return module->second.getTexture(textureName);
	}

	void NVIDIAGPUDevice::launch(const std::string& moduleName, 
		const std::string& kernelName, const ir::Dim3& grid, 
		const ir::Dim3& block, size_t sharedMemory, 
		const void* parameterBlock, size_t parameterBlockSize, 
		const trace::TraceGeneratorVector& traceGenerators)
	{
		ModuleMap::iterator module = _modules.find(moduleName);
		
		if(module == _modules.end())
		{
			Throw("Unknown module - " << moduleName);
		}
		
		NVIDIAExecutableKernel* kernel = module->second.getKernel(kernelName);
		
		if(kernel == 0)
		{
			Throw("Unknown kernel - " << kernelName 
				<< " in module " << moduleName);
		}
		
		if(kernel->sharedMemorySize() + sharedMemory > 
			(size_t)properties().sharedMemPerBlock)
		{
			Throw("Out of shared memory for kernel \""
				<< kernel->name << "\" : \n\tpreallocated "
				<< kernel->sharedMemorySize() << " + requested " 
				<< sharedMemory << " is greater than available " 
				<< properties().sharedMemPerBlock << " for device " 
				<< properties().name);
		}
		
		if(kernel->constMemorySize() > (size_t)properties().totalConstantMemory)
		{
			Throw("Out of shared memory for kernel \""
				<< kernel->name << "\" : \n\tpreallocated "
				<< kernel->constMemorySize() << " is greater than available " 
				<< properties().totalConstantMemory << " for device " 
				<< properties().name);
		}
		
		kernel->setKernelShape(block.x, block.y, block.z);
		kernel->setParameterBlock((const unsigned char*)parameterBlock, 
			parameterBlockSize);
		kernel->updateParameterMemory();
		kernel->updateMemory();
		kernel->setExternSharedMemorySize(sharedMemory);
		
		kernel->launchGrid(grid.x, grid.y);
		synchronize();
	}

	cudaFuncAttributes NVIDIAGPUDevice::getAttributes(const std::string& path, 
		const std::string& kernelName)
	{
		ModuleMap::iterator module = _modules.find(path);
		
		if(module == _modules.end())
		{
			Throw("Unknown module - " << path);
		}
		
		NVIDIAExecutableKernel* kernel = module->second.getKernel(kernelName);
		
		if(kernel == 0)
		{
			Throw("Unknown kernel - " << kernelName 
				<< " in module " << path);
		}
		
		cudaFuncAttributes attributes;

		memset(&attributes, 0, sizeof(cudaFuncAttributes));
		attributes.sharedSizeBytes = kernel->sharedMemorySize();
		attributes.constSizeBytes = kernel->constMemorySize();
		attributes.localSizeBytes = kernel->localMemorySize();
		attributes.maxThreadsPerBlock = kernel->maxThreadsPerBlock();
		attributes.numRegs = kernel->registerCount();
		
		return std::move(attributes);
	}

	static unsigned int translateError(CUresult error)
	{
		switch(error)
		{	
			case CUDA_SUCCESS: return cudaSuccess;
			case CUDA_ERROR_INVALID_VALUE: return cudaErrorInvalidValue;
			case CUDA_ERROR_OUT_OF_MEMORY: return cudaErrorMemoryAllocation;
			case CUDA_ERROR_NOT_INITIALIZED: 
				return cudaErrorInitializationError;
			case CUDA_ERROR_DEINITIALIZED: return cudaErrorInitializationError;
			case CUDA_ERROR_NO_DEVICE: return cudaErrorNoDevice;
			case CUDA_ERROR_INVALID_DEVICE: return cudaErrorInvalidDevice;
			case CUDA_ERROR_INVALID_IMAGE: 
				return cudaErrorInvalidDeviceFunction;
			case CUDA_ERROR_INVALID_CONTEXT: return cudaErrorApiFailureBase;
			case CUDA_ERROR_CONTEXT_ALREADY_CURRENT: 
				return cudaErrorApiFailureBase;
			case CUDA_ERROR_MAP_FAILED: return cudaErrorMapBufferObjectFailed;
			case CUDA_ERROR_UNMAP_FAILED: 
				return cudaErrorUnmapBufferObjectFailed;
			case CUDA_ERROR_ARRAY_IS_MAPPED: 
				return cudaErrorMapBufferObjectFailed;
			case CUDA_ERROR_ALREADY_MAPPED: 
				return cudaErrorMapBufferObjectFailed;
			case CUDA_ERROR_NO_BINARY_FOR_GPU: 
				return cudaErrorInvalidDeviceFunction;
			case CUDA_ERROR_ALREADY_ACQUIRED: 
				return cudaErrorSetOnActiveProcess;
			case CUDA_ERROR_NOT_MAPPED: return cudaErrorUnmapBufferObjectFailed;
			case CUDA_ERROR_INVALID_SOURCE: return cudaErrorInvalidValue;
			case CUDA_ERROR_FILE_NOT_FOUND: return cudaErrorInvalidValue;
			case CUDA_ERROR_INVALID_HANDLE: return cudaErrorInvalidValue;
			case CUDA_ERROR_NOT_FOUND: return cudaErrorInvalidValue;
			case CUDA_ERROR_NOT_READY: return cudaErrorNotReady;
			case CUDA_ERROR_LAUNCH_FAILED: return cudaErrorLaunchFailure;
			case CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES: 
				return cudaErrorLaunchOutOfResources;
			case CUDA_ERROR_LAUNCH_TIMEOUT: return cudaErrorLaunchTimeout;
			case CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING: 
				return cudaErrorInvalidTexture;
			case CUDA_ERROR_UNKNOWN: return cudaErrorUnknown;
			default: break;
		}
		return cudaErrorUnknown;
	}

	unsigned int NVIDIAGPUDevice::getLastError() const
	{
		return translateError(_lastError);
	}
	
	void NVIDIAGPUDevice::synchronize()
	{
		checkError(driver::cuCtxSynchronize());
	}
			
	void NVIDIAGPUDevice::limitWorkerThreads(unsigned int threads)
	{
		// this is a nop here
	}
}

#endif
