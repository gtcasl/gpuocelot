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
#include <hydrazine/implementation/string.h>

// opengl includes
#include <GL/glx.h>

// standard library includes
#include <cstring>

/////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define checkError(x) if((_lastError = x) != CUDA_SUCCESS) { \
	throw hydrazine::Exception("Cuda Driver Error - " #x + \
		driver::toString(_lastError)); }
#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str()); }

// Turn on report messages
#define REPORT_BASE 0

// Print out the full ptx for each module as it is loaded
#define REPORT_PTX 1

/////////////////////////////////////////////////////////////////////////////////////////////////

typedef cuda::CudaDriver driver;

namespace executive 
{
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation() : _flags(0), _size(0),
		_devicePointer(0), _hostPointer(0), _external(false)
	{
		
	}

	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(size_t size) : 
		_flags(0), _size(size), _hostPointer(0), _external(false)
	{
		checkError(driver::cuMemAlloc(&_devicePointer, size));
	}
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(size_t size, 
		unsigned int flags) : Device::MemoryAllocation(false, true), 
		_flags(flags), _size(size), _external(false)
	{
		// making all memory portable eases context switching
		_flags |= CU_MEMHOSTALLOC_PORTABLE;
		
		checkError(driver::cuMemHostAlloc(&_hostPointer, size, _flags));
		checkError(driver::cuMemHostGetDevicePointer(&_devicePointer, 
			_hostPointer, 0));
	}
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(CUmodule module, 
		const ir::Global& g) : Device::MemoryAllocation(true, false), _flags(0),
		_size(g.statement.bytes()), _hostPointer(0), _external(false)
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
	
	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(
		void* pointer, size_t size) : Device::MemoryAllocation(false, false), 
		_flags(0), _size(size), 
		_devicePointer(hydrazine::bit_cast<CUdeviceptr>(pointer)), 
		_hostPointer(0), _external(true)
	{
	
	}
	
	NVIDIAGPUDevice::MemoryAllocation::~MemoryAllocation()
	{
		if(!_external)
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
	}

	NVIDIAGPUDevice::MemoryAllocation::MemoryAllocation(
		const MemoryAllocation& a) : Device::MemoryAllocation(
		a.global(), a.host()), _flags(a.flags()), _size(a.size()), 
		_devicePointer(0), _hostPointer(0), _external(a._external)
	{
		if(host())
		{
			checkError(driver::cuMemHostAlloc(&_hostPointer, _size, _flags));
			checkError(driver::cuMemHostGetDevicePointer(&_devicePointer, 
				_hostPointer, 0));
			memcpy(_hostPointer, a._hostPointer, _size);
		}
		else if(global() || _external)
		{
			_devicePointer = a._devicePointer;
		}
		else if(!_external)
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
		std::swap(_external, a._external);
	}

	NVIDIAGPUDevice::MemoryAllocation& 
		NVIDIAGPUDevice::MemoryAllocation::operator=(const MemoryAllocation& a)
	{
		if(this == &a) return *this;

		if(host())
		{
			checkError(driver::cuMemFreeHost(_hostPointer));
		}
		else if(!global() && !_external)
		{
			checkError(driver::cuMemFree(_devicePointer));
		}
		
		_host = a._host;
		_global = a._global;
		_flags = a._flags;
		_size = a._size;
		_hostPointer = 0;
		_devicePointer = 0;
		_external = a._external;
		
		if(host())
		{
			checkError(driver::cuMemHostAlloc(&_hostPointer, _size, _flags));
			checkError(driver::cuMemHostGetDevicePointer(&_devicePointer, 
				_hostPointer, 0));
			memcpy(_hostPointer, a._hostPointer, _size);
		}
		else if(global() || _external)
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
		std::swap(_external, a._external);

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
		report("Loading module - " << ir->path() << " on NVIDIA GPU.");
		assert(!loaded());
		std::stringstream stream;
		
		ir->writeIR(stream);
		
		reportE(REPORT_PTX, " Binary is:\n" 
			<< hydrazine::addLineNumbers(stream.str()));
		
		CUjit_option options[] = {CU_JIT_ERROR_LOG_BUFFER, 
			CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES};
		const int errorLogSize = 2048;
		int errorLogActualSize = errorLogSize;
		char errorLogBuffer[errorLogSize];
		memset(errorLogBuffer, 0, errorLogSize);

		void* optionValues[2] = {(void*)errorLogBuffer, 
			(void*)errorLogActualSize};
		CUresult result = driver::cuModuleLoadDataEx(&_handle, 
			stream.str().c_str(), 2, options, optionValues);
		
		if(result != CUDA_SUCCESS)
		{
			Throw("Failed to JIT module - " << ir->path() 
				<< " using NVIDIA JIT with error:\n" << errorLogBuffer);
		}
		
		report(" Module loaded successfully.");
		
		for(ir::Module::TextureMap::const_iterator 
			texture = ir->textures().begin(); 
			texture != ir->textures().end(); ++texture)
		{
			unsigned int flags = texture->second.normalizedFloat 
				? 0 : CU_TRSF_READ_AS_INTEGER;
			CUtexref reference;
			checkError(driver::cuModuleGetTexRef(&reference, _handle, 
				texture->first.c_str()));
			checkError(driver::cuTexRefSetFlags(reference, flags));
		}
	}

	bool NVIDIAGPUDevice::Module::loaded() const
	{
		return _handle != 0;	
	}	
	
	void NVIDIAGPUDevice::Module::translate()
	{
		if(!loaded()) load();
		
		report("Creating NVIDIA kernels for module - " << ir->path());
		for(ir::Module::KernelMap::const_iterator 
			kernel = ir->kernels().begin(); 
			kernel != ir->kernels().end(); ++kernel)
		{
			CUfunction function;
			checkError(driver::cuModuleGetFunction(&function, _handle, 
				kernel->first.c_str()));
			kernels.insert(std::make_pair(kernel->first, 
				new NVIDIAExecutableKernel(*kernel->second, function)));
			report(" - " << kernel->first);
		}
	}
	
	NVIDIAGPUDevice::Module::AllocationVector 
		NVIDIAGPUDevice::Module::loadGlobals()
	{
		if(!loaded()) load();
		assert(globals.empty());
		
		AllocationVector allocations;
		report("Loading globals in module - " << ir->path());
		for(ir::Module::GlobalMap::const_iterator 
			global = ir->globals().begin(); 
			global != ir->globals().end(); ++global)
		{
			if(global->second.statement.directive 
				== ir::PTXStatement::Shared) continue;
			report(" " << global->first);
			MemoryAllocation* allocation = new MemoryAllocation(_handle, 
				global->second);
			report("  pointer - " << allocation->pointer());
			
			globals.insert(std::make_pair(global->first, 
				allocation->pointer()));
			allocations.push_back(allocation);
		}
		
		return allocations;
	}
	
	bool NVIDIAGPUDevice::Module::translated() const
	{
		return kernels.size() == ir->kernels().size();
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

	static unsigned int channels(const cudaChannelFormatDesc& desc)
	{
		unsigned int channels = 0;
		
		channels = (desc.x > 0) ? channels + 1 : channels;
		channels = (desc.y > 0) ? channels + 1 : channels;
		channels = (desc.z > 0) ? channels + 1 : channels;
		channels = (desc.w > 0) ? channels + 1 : channels;
	
		return channels;
	}
	
	static CUarray_format_enum format(const cudaChannelFormatDesc& desc)
	{
		switch(desc.f)
		{
			case cudaChannelFormatKindSigned:
			{
				if(desc.x == 8)
				{
					return CU_AD_FORMAT_SIGNED_INT8;
				}
				else if(desc.y == 16)
				{
					return CU_AD_FORMAT_SIGNED_INT16;
				}
				else
				{
					return CU_AD_FORMAT_SIGNED_INT32;
				}			
			}
			case cudaChannelFormatKindUnsigned:
			{
				if(desc.x == 8)
				{
					return CU_AD_FORMAT_UNSIGNED_INT8;
				}
				else if(desc.y == 16)
				{
					return CU_AD_FORMAT_UNSIGNED_INT16;
				}
				else
				{
					return CU_AD_FORMAT_UNSIGNED_INT32;
				}
			}
			case cudaChannelFormatKindFloat:
			{
				if(desc.x == 16)
				{
					return CU_AD_FORMAT_HALF;
				}
				else
				{
					return CU_AD_FORMAT_FLOAT;
				}
			}
			case cudaChannelFormatKindNone: break;
		}
		return CU_AD_FORMAT_UNSIGNED_INT8;
	}
	
	static CUaddress_mode_enum convert(cudaTextureAddressMode mode)
	{
		// Note that the cuda runtime does not expose CU_TR_ADDRESS_MODE_MIRROR 
		if(mode == cudaAddressModeWrap) return CU_TR_ADDRESS_MODE_WRAP;
		return CU_TR_ADDRESS_MODE_CLAMP;
	}

	NVIDIAGPUDevice::Array3D::Array3D(const cudaChannelFormatDesc& desc, 
		const ir::Dim3& size, CUdeviceptr d) : ptr(d), size(size)
	{
		CUDA_ARRAY3D_DESCRIPTOR descriptor;
		descriptor.Width = size.x;
		descriptor.Height = size.y;
		descriptor.Depth = size.z;
		descriptor.NumChannels = channels(desc);
		descriptor.Format = format(desc);
		descriptor.Flags = 0;
		
		bytesPerElement = ((desc.x + desc.y + desc.z + desc.w) / 8);
		
		checkError(driver::cuArray3DCreate(&array, &descriptor));
	}

	NVIDIAGPUDevice::Array3D::Array3D() : array(0)
	{
		
	}

	NVIDIAGPUDevice::Array3D::~Array3D()
	{
		checkError(driver::cuArrayDestroy(array));
	}

	void NVIDIAGPUDevice::Array3D::update()
	{
		report("Updating texture.");
	
		CUDA_MEMCPY3D memcpy;
		
		memcpy.srcLOD = 0;
		memcpy.dstLOD = 0;
		
		memcpy.WidthInBytes = bytesPerElement * size.x;
		memcpy.Height = size.y;
		memcpy.Depth = size.z;
		
		memcpy.srcMemoryType = CU_MEMORYTYPE_DEVICE;
		memcpy.srcDevice = ptr;
		memcpy.srcPitch = 0;
		memcpy.srcHeight = 0;
		
		memcpy.dstMemoryType = CU_MEMORYTYPE_ARRAY;
		memcpy.dstArray = array;
		
		memcpy.srcXInBytes = 0;
		memcpy.srcY = 0;
		memcpy.srcZ = 0;
		
		memcpy.dstXInBytes = 0;
		memcpy.dstY = 0;
		memcpy.dstZ = 0;
		
		checkError(driver::cuMemcpy3D(&memcpy));
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
		
		return devices;
	}

	unsigned int NVIDIAGPUDevice::deviceCount()
	{
		if(!_cudaDriverInitialized)
		{
			driver::cuInit(0);
			_cudaDriverInitialized = true;
		}
		
		int count;
		checkError(driver::cuDeviceGetCount(&count));
		
		return count;
	}

	NVIDIAGPUDevice::NVIDIAGPUDevice(int id, unsigned int flags) : 
		Device(flags), _selected(false), _next(0), _selectedStream(0), 
		_opengl(false)
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
		
		GLXContext openglContext = glXGetCurrentContext();
		if(openglContext != 0)
		{
			checkError(driver::cuGLCtxCreate(&_context, flags, device));
			_opengl = true;
		}
		else
		{
			checkError(driver::cuCtxCreate(&_context, flags, device));
		}
		
		checkError(driver::cuCtxPopCurrent(&_context));
		
		char name[256];
		checkError(driver::cuDeviceGetName(name, 255, device));
		_properties.name = name;
		
		unsigned int total;
		checkError(driver::cuDeviceTotalMem(&total, device));
		_properties.totalMemory = total;
		
		checkError(driver::cuDeviceGetAttribute(
			(int*)&_properties.multiprocessorCount,
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
		
		checkError(driver::cuDeviceGetAttribute(&_properties.integrated, 
			CU_DEVICE_ATTRIBUTE_INTEGRATED, device));
		checkError(driver::cuDeviceGetAttribute(&_properties.concurrentKernels, 
			CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS, device));
		checkError(driver::cuDeviceComputeCapability(&_properties.major, 
			&_properties.minor, device));
	}

	NVIDIAGPUDevice::~NVIDIAGPUDevice()
	{
		assert(!selected());
		select();
		_modules.clear();
		checkError(driver::cuCtxDestroy(_context));
	}
	
	Device::MemoryAllocation* NVIDIAGPUDevice::getMemoryAllocation(
		const void* address, AllocationType type) const
	{
		MemoryAllocation* allocation = 0;
		
		if(type == DeviceAllocation || type == AnyAllocation)
		{
			if(!_allocations.empty())
			{
				AllocationMap::const_iterator alloc = _allocations.upper_bound(
					(void*)address);
				if(alloc != _allocations.begin()) --alloc;
				if(alloc != _allocations.end())
				{
					if(!alloc->second->host()
					 	&& (char*)address >= (char*)alloc->second->pointer())
					{
						allocation = alloc->second;
						return allocation;
					}
				}
			}
		}

		if(type == HostAllocation || type == AnyAllocation)
		{
			for(AllocationMap::const_iterator alloc = _allocations.begin(); 
				alloc != _allocations.end(); ++alloc)
			{
				if(alloc->second->host())
				{
					if((char*)address >= alloc->second->mappedPointer() 
						&& (char*)address < 
						(char*)alloc->second->mappedPointer()
						+ alloc->second->size())
					{
						allocation = alloc->second;
						break;
					}
				}
			}
		}
		
		return allocation;		
	}

	Device::MemoryAllocation* NVIDIAGPUDevice::getGlobalAllocation(
		const std::string& moduleName, const std::string& name)
	{
		if(moduleName.empty())
		{
			// try a brute force search over all modules
			for(ModuleMap::iterator module = _modules.begin(); 
				module != _modules.end(); ++module)
			{
				if(module->second.globals.empty())
				{
					Module::AllocationVector allocations = std::move(
						module->second.loadGlobals());
					for(Module::AllocationVector::iterator 
						allocation = allocations.begin(); 
						allocation != allocations.end(); ++allocation)
					{
						_allocations.insert(std::make_pair(
							(*allocation)->pointer(), *allocation));
					}
				}

				Module::GlobalMap::iterator global = 
					module->second.globals.find(name);
				if(global != module->second.globals.end())
				{
					return getMemoryAllocation(global->second, 
						DeviceAllocation);
				}
			}
			return 0;
		}

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
				_allocations.insert(std::make_pair((*allocation)->pointer(), 
					*allocation));
			}
		}
		
		Module::GlobalMap::iterator global = module->second.globals.find(name);
		if(global == module->second.globals.end()) return 0;
		
		return getMemoryAllocation(global->second, DeviceAllocation);
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
		_hostAllocations.insert(std::make_pair(allocation->pointer(), 
			allocation));
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

	Device::MemoryAllocationVector NVIDIAGPUDevice::getAllAllocations() const
	{
		MemoryAllocationVector allocations;
		for(AllocationMap::const_iterator allocation = _allocations.begin(); 
			allocation != _allocations.end(); ++allocation)
		{
			allocations.push_back(allocation->second);
		}
		
		for(AllocationMap::const_iterator allocation = _hostAllocations.begin();
			allocation != _hostAllocations.end(); ++allocation)
		{
			allocations.push_back(allocation->second);
		}

		return allocations;
	}

	void NVIDIAGPUDevice::clearMemory()
	{
		for(AllocationMap::iterator allocation = _allocations.begin(); 
			allocation != _allocations.end();)
		{
			if(allocation->second->global())
			{
				++allocation;		
			}
			else
			{
				delete allocation->second;
				_allocations.erase(allocation++);
			}
		}
		
		for(AllocationMap::iterator allocation = _hostAllocations.begin();
			allocation != _hostAllocations.end(); ++allocation)
		{
			delete allocation->second;
		}

		_hostAllocations.clear();
	}

	void* NVIDIAGPUDevice::glRegisterBuffer(unsigned int buffer, 
		unsigned int flags)
	{
		report("Regstering open gl buffer " << buffer);

		if(!_opengl) Throw("No active opengl contexts.");

		CUgraphicsResource resource;
		checkError(driver::cuGraphicsGLRegisterBuffer(&resource,
			buffer, CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE));

		report(" to resource - " << resource);
		return hydrazine::bit_cast<void*>(resource);
	}
	
	void* NVIDIAGPUDevice::glRegisterImage(unsigned int image, 
		unsigned int target, unsigned int flags)
	{
		report("Regstering open gl image " << image << ", target " << target);

		if(!_opengl) Throw("No active opengl contexts.");

		CUgraphicsResource resource;
		checkError(driver::cuGraphicsGLRegisterImage(&resource, image, 
			target, flags));
		report(" to resource " << resource);
		return resource;
	}
	
	void NVIDIAGPUDevice::unRegisterGraphicsResource(void* resource)
	{
		report("Unregistering graphics resource - " << resource);

		if(!_opengl) Throw("No active opengl contexts.");

		checkError(driver::cuGraphicsUnregisterResource(
			hydrazine::bit_cast<CUgraphicsResource>(resource)));
	}

	void NVIDIAGPUDevice::mapGraphicsResource(void* resource, int count, 
		unsigned int streamId)
	{
		CUstream id = 0;
		if(streamId != 0)
		{
			StreamMap::iterator stream = _streams.find(streamId);

			if(stream == _streams.end())
			{
				Throw("Invalid stream - " << streamId);
			}

			id = stream->second;
		}
		report("Mapping graphics resource " << resource 
			<< " on stream " << streamId);

		if(!_opengl) Throw("No active opengl contexts.");

		checkError(driver::cuGraphicsMapResources(count,
			(CUgraphicsResource*)&resource, id));
		
		CUdeviceptr pointer;
		unsigned int bytes = 0;
		checkError(driver::cuGraphicsResourceGetMappedPointer(&pointer, &bytes, 
			(CUgraphicsResource)resource));
		
		void* p = (void*)pointer;
		
		_allocations.insert(std::make_pair(p, new MemoryAllocation(p, bytes)));
	}
	
	void* NVIDIAGPUDevice::getPointerToMappedGraphicsResource(size_t& size, 
		void* resource)
	{
		CUdeviceptr pointer;
		unsigned int bytes = 0;
		report("Getting pointer to mapped resource " << resource);

		if(!_opengl) Throw("No active opengl contexts.");

		checkError(driver::cuGraphicsResourceGetMappedPointer(&pointer, &bytes, 
			(CUgraphicsResource)resource));

		size = bytes;
		report(" size - " << size << ", pointer - " << pointer);
		return hydrazine::bit_cast<void*>(pointer);
	}

	void NVIDIAGPUDevice::setGraphicsResourceFlags(void* resource, 
		unsigned int flags)
	{
		report("Setting flags to " << flags 
			<< " for graphics resource " << resource);

		if(!_opengl) Throw("No active opengl contexts.");

		checkError(driver::cuGraphicsResourceSetMapFlags(
			(CUgraphicsResource)resource, flags));
	}

	void NVIDIAGPUDevice::unmapGraphicsResource(void* resource)
	{
		CUstream id = 0;
		
		if(_selectedStream != 0)
		{
			StreamMap::iterator stream = _streams.find(_selectedStream);
			assert(stream != _streams.end());
			id = stream->second;
		}
				
		report("Unmapping graphics resource " << resource);

		if(!_opengl) Throw("No active opengl contexts.");

		CUdeviceptr pointer;
		unsigned int bytes = 0;

		checkError(driver::cuGraphicsResourceGetMappedPointer(&pointer, &bytes, 
			(CUgraphicsResource)resource));

		AllocationMap::iterator allocation = _allocations.find(
			hydrazine::bit_cast<void*>(pointer));
		assert(allocation != _allocations.end());
		
		delete allocation->second;
		_allocations.erase(allocation);

		checkError(driver::cuGraphicsUnmapResources(1, 
			(CUgraphicsResource*)&resource, id));
	}

	void NVIDIAGPUDevice::load(const ir::Module* module)
	{
		if(_modules.count(module->path()) != 0)
		{
			Throw("Duplicate module - " << module->path());
		}
		_modules.insert(std::make_pair(module->path(), 
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
		
		_modules.erase(module);
	}

	ExecutableKernel* NVIDIAGPUDevice::getKernel(const std::string& moduleName, 
		const std::string& kernelName)
	{
		ModuleMap::iterator module = _modules.find(moduleName);
		
		if(module == _modules.end()) return 0;
		
		return module->second.getKernel(kernelName);	
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

		if(sHandle != 0)
		{
			StreamMap::const_iterator stream = _streams.find(sHandle);
			if(stream == _streams.end())
			{
				Throw("Invalid stream - " << sHandle);
			}
			checkError(driver::cuEventRecord(event->second, stream->second));
		}
		else
		{
			checkError(driver::cuEventRecord(event->second, 0));
		}
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

		if(_arrays.count(textureName) != 0)
		{
			unbindTexture(moduleName, textureName);
		}

		report("Binding texture " << textureName << " in module " << moduleName
			<< " to pointer " << pointer << " with dimensions (" << size.x
			<< "," << size.y << "," << size.z << ")");

		CUtexref ref = hydrazine::bit_cast<CUtexref>(tex);
		CUdeviceptr ptr = hydrazine::bit_cast<CUdeviceptr>(pointer);
		unsigned int offset = 0;
		unsigned int bytesPerElement = ((desc.x + desc.y 
			+ desc.z + desc.w) / 8);
		unsigned int pitch = bytesPerElement * size.x;
		
		if(size.z > 1)
		{
			Array3D* array = new Array3D(desc, size, ptr);
			_arrays[textureName] = array;
			
			checkError(driver::cuTexRefSetArray(ref,
				array->array, CU_TRSA_OVERRIDE_FORMAT));
		}
		else if(size.y > 1)
		{
			CUDA_ARRAY_DESCRIPTOR descriptor;
			descriptor.Width = size.x;
			descriptor.Height = size.y;
			descriptor.NumChannels = channels(desc);
			descriptor.Format = format(desc);
			
			checkError(driver::cuTexRefSetAddress2D(ref, &descriptor, 
				ptr, pitch));

			_arrays[textureName] = 0;
		}
		else
		{
			checkError(driver::cuTexRefSetAddress(&offset, ref, ptr, pitch));
			_arrays[textureName] = 0;
		}
		
		if(texref.filterMode == cudaFilterModeLinear)
		{
			checkError(driver::cuTexRefSetFilterMode(ref, 
				CU_TR_FILTER_MODE_LINEAR));
		}
		else
		{
			checkError(driver::cuTexRefSetFilterMode(ref, 
				CU_TR_FILTER_MODE_POINT));
		}

		checkError(driver::cuTexRefSetAddressMode(ref, 0,
			convert(texref.addressMode[0])));
		checkError(driver::cuTexRefSetAddressMode(ref, 1,
			convert(texref.addressMode[1])));
		checkError(driver::cuTexRefSetAddressMode(ref, 2,
			convert(texref.addressMode[2])));
		
		unsigned int flags = 0;
		checkError(driver::cuTexRefGetFlags(&flags, ref));
		flags &= CU_TRSF_READ_AS_INTEGER;
		flags |= (texref.normalized) ? CU_TRSF_NORMALIZED_COORDINATES : 0;		
		checkError(driver::cuTexRefSetFlags(ref, flags));
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
		
		report("Unbinding texture " << textureName 
			<< " in module " << moduleName);
		
		ArrayMap::iterator array = _arrays.find(textureName);
		assert(array != _arrays.end());
		delete array->second;
		_arrays.erase(array);		
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
			Throw("Out of constant memory for kernel \""
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
		
		for(ArrayMap::iterator array = _arrays.begin(); 
			array != _arrays.end(); ++array)
		{
			if(array->second != 0) array->second->update();
		}
		
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

	void NVIDIAGPUDevice::setOptimizationLevel(
		translator::Translator::OptimizationLevel level)
	{
		// TODO work in something with the PTX JIT optimization level here
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif
