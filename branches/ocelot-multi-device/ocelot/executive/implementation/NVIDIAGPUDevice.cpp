/*! \file NVIDIAGPUDevice.cpp
	\author Gregory Diamos
	\date April 7, 2010
	\brief The source file for the NVIDIAGPUDevice class.
*/

#ifndef NVIDIA_GPU_DEVICE_CPP_INCLUDED
#define NVIDIA_GPU_DEVICE_CPP_INCLUDED

// ocelot includes
#include <ocelot/executive/interface/NVIDIAGPUDevice.h>
#include <ocelot/cuda/interface/CudaDriver.h>

typedef cuda::CudaDriver driver;

#define checkError(x) if(x != CUDA_SUCCESS) { \
	throw hydrazine::Exception(driver::toString(x)); }
#define Exception(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s); }

namespace executive 
{
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation() : _flags(0), _size(0),
		_devicePointer(0), _hostPointer(0)
	{
		
	}
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(size_t size) _flags(0),
		_size(size), _hostPointer(0)
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
			g.statement.identifier));
		if(bytes != _size)
		{
			Exception("Global variable - " << g.statement.identifier 
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
			checkError(driver::cuMemcpyDtoD(_devicePointer, a._devicePointer));
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
			checkError(driver::cuMemcpyDtoD(_devicePointer, a._devicePointer));
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
		return _devicePointer;
	}

	size_t NVIDIAGPUDevice::MemoryAllocation::size() const
	{
		return _size;
	}

	void NVIDIAGPUDevice::MemoryAllocation::copy(size_t offset, 
		const void* src, size_t size)
	{
		assert(offset + s < size());
		if(host())
		{
			memcpy((char*)_hostPointer + offset, src, s);
		}
		else
		{
			checkError(driver::cuMemcpyHtoD((char*)_devicePointer + offset, 
				src, s));
		}
	}
	
	void NVIDIAGPUDevice::MemoryAllocation::copy(void* dst, 
		size_t offset, size_t s) const
	{
		assert(offset + s < size());
		if(host())
		{
			memcpy(dst, (char*)_hostPointer + offset, s);
		}
		else
		{
			checkError(driver::cuMemcpyDtoH(dst, 
				(char*)_devicePointer + offset, s));
		}
	}
	
	void NVIDIAGPUDevice::MemoryAllocation::memset(size_t offset, 
		int value, size_t s)
	{
		assert(s + offset < size());
		if(host())
		{
			memset((char*))_hostPointer + offset, value, size);
		}
		else
		{
			checkError(driver::cuMemsetD8((char*)_devicePointer + offset, 
				value, s));
		}
	}
	
	void NVIDIAGPUDevice::MemoryAllocation::copy(Device::MemoryAllocation* a, 
		size_t toOffset, size_t fromOffset, size_t s) const
	{
		MemoryAllocation* allocation = static_cast<MemoryAllocation*>(a);
		assert(fromOffset + s < size());
		assert(toOffset + s < allocation->size());
		
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
				CUdeviceptr dst = (char*)allocation->_devicePointer + toOffset;

				checkError(driver::cuMemcpyHtoD(dst, src, s));
			}
		}
		else
		{
			if(allocation->host())
			{
				CUdeviceptr src = (char*)_devicePointer + fromOffset;
				void* dst = (char*)allocation->_hostPointer + toOffset;

				checkError(driver::cuMemcpyDtoH(dst, src, s));
			}
			else
			{
				CUdeviceptr src = (char*)_devicePointer + fromOffset;
				CUdeviceptr dst = (char*)allocation->_devicePointer + toOffset;

				checkError(driver::cuMemcpyDtoD(dst, src, s));
			}
		}
	}

	NVIDIAGPUDevice::Module::Module(const ir::Module* m = 0)
	{
		
	}
	
	NVIDIAGPUDevice::Module::Module(const Module& m);
	NVIDIAGPUDevice::Module::~Module();
	
	void NVIDIAGPUDevice::Module::translate();
	bool NVIDIAGPUDevice::Module::translated() const;
	GPUExecutableKernel* NVIDIAGPUDevice::Module::getKernel(const std::string& name);

	NVIDIAGPUDevice::NVIDIAGPUDevice(int id = 0);
	NVIDIAGPUDevice::~NVIDIAGPUDevice();

	bool NVIDIAGPUDevice::checkMemoryAccess(const void* pointer, size_t size) const;
	NVIDIAGPUDevice::MemoryAllocation* NVIDIAGPUDevice::getMemoryAllocation(const void* address, 
		bool hostAllocation) const;
	NVIDIAGPUDevice::MemoryAllocation* NVIDIAGPUDevice::getGlobalAllocation(const std::string& module, 
		const std::string& name) const;
	NVIDIAGPUDevice::MemoryAllocation* NVIDIAGPUDevice::allocate(size_t size);
	NVIDIAGPUDevice::MemoryAllocation* NVIDIAGPUDevice::allocateHost(size_t size, unsigned int flags);
	void NVIDIAGPUDevice::free(void* pointer);
	Device::MemoryAllocationVector NVIDIAGPUDevice::getNearbyAllocations(void* pointer) const;
		

	void* NVIDIAGPUDevice::glRegisterBuffer(unsigned int buffer, 
		unsigned int flags) = 0;
	void* NVIDIAGPUDevice::glRegisterImage(unsigned int image, 
		unsigned int target, unsigned int flags) = 0;
	void NVIDIAGPUDevice::unRegisterGraphicsResource(void* resource) = 0;
	void NVIDIAGPUDevice::mapGraphicsResource(void* resource, int count, 
		unsigned int stream);
	void* NVIDIAGPUDevice::getPointerToMappedGraphicsResource(size_t& size, 
		void* resource) const;
	void NVIDIAGPUDevice::setGraphicsResourceFlags(void* resource, 
		unsigned int flags);
	void NVIDIAGPUDevice::unmapGraphicsResource(void* resource);

	void NVIDIAGPUDevice::load(const ir::Module* module);
	void NVIDIAGPUDevice::unload(const std::string& name);

	unsigned int NVIDIAGPUDevice::createEvent(int flags);
	void NVIDIAGPUDevice::destroyEvent(unsigned int event);
	bool NVIDIAGPUDevice::queryEvent(unsigned int event) const;
	void NVIDIAGPUDevice::recordEvent(unsigned int event, unsigned int stream);
	void NVIDIAGPUDevice::synchronizeEvent(unsigned int event);
	float NVIDIAGPUDevice::getEventTime(unsigned int start, unsigned int end) const;
		
	unsigned int NVIDIAGPUDevice::createStream();
	void NVIDIAGPUDevice::destroyStream(unsigned int stream);
	bool NVIDIAGPUDevice::queryStream(unsigned int stream) const;
	void NVIDIAGPUDevice::synchronizeStream(unsigned int stream);
	void NVIDIAGPUDevice::setStream(unsigned int stream);
			
	void NVIDIAGPUDevice::select();
	bool NVIDIAGPUDevice::selected() const;
	void NVIDIAGPUDevice::unselect();
	void NVIDIAGPUDevice::setDeviceFlags(unsigned int flags);
		
	void NVIDIAGPUDevice::bindTexture(void* pointer, void* texture, 
		const cudaChannelFormatDesc& desc, size_t size);
	void NVIDIAGPUDevice::unbindTexture(void* texture);
	void* NVIDIAGPUDevice::getTextureReference(const std::string& module, 
		const std::string& name);

	void NVIDIAGPUDevice::launch(const std::string& module, 
		const std::string& kernel, const ir::Dim3& grid, 
		const ir::Dim3& block, size_t sharedMemory, 
		void* parameterBlock, size_t parameterBlockSize, 
		const trace::TraceGeneratorVector& 
		traceGenerators = trace::TraceGeneratorVector());
	cudaFuncAttributes NVIDIAGPUDevice::getAttributes(const std::string& module, 
		const std::string& kernel) const;
	unsigned int NVIDIAGPUDevice::getLastError() const;
	void NVIDIAGPUDevice::synchronize();
			
	void NVIDIAGPUDevice::limitWorkerThreads(unsigned int threads);
}

#endif
