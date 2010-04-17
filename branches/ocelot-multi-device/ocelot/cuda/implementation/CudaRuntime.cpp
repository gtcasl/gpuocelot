/*! \file CudaRuntime.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements the CUDA Runtime API for Ocelot
*/

// C standard library includes
#include <assert.h>

// C++ standard library includes
#include <sstream>
#include <algorithm>

// Ocelot includes
#include <ocelot/cuda/interface/CudaRuntime.h>
#include <ocelot/cuda/interface/CudaDriver.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/executive/interface/RuntimeException.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

// GL includes
#include <GL/glew.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////


// whether CUDA runtime catches exceptions thrown by Ocelot
#define CATCH_RUNTIME_EXCEPTIONS 0

// whether verbose error messages are printed
#define CUDA_VERBOSE 1

// whether debugging messages are printed
#define REPORT_BASE 1

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Error handling macros

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

//////////////////////////////////////////////////////////////////////////////////////////////////

const char *cuda::FatBinaryContext::name() const {
	if (!cubin_ptr) return "";
	__cudaFatCudaBinary *binary = (__cudaFatCudaBinary *)cubin_ptr;
	return binary->ident;
}	

const char *cuda::FatBinaryContext::ptx() const {
	if (!cubin_ptr) return "";
	__cudaFatCudaBinary *binary = (__cudaFatCudaBinary *)cubin_ptr;
	return binary->ptx->ptx;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cuda::HostThreadContext::HostThreadContext(): selectedDevice(0), 
	parameterBlock(0), parameterBlockSize(1<<13) {
	parameterBlock = (unsigned char *)malloc(parameterBlockSize);
}

cuda::HostThreadContext::~HostThreadContext() {
	::free(parameterBlock);
}

cuda::HostThreadContext::HostThreadContext(const HostThreadContext& c): 
	selectedDevice(c.selectedDevice),
	validDevices(c.validDevices),
	launchConfigurations(c.launchConfigurations),
	lastError(c.lastError),
	parameterBlock((unsigned char *)malloc(c.parameterBlockSize)),
	parameterBlockSize(c.parameterBlockSize),
	parameterIndices(c.parameterIndices),
	parameterSizes(c.parameterSizes),
	persistentTraceGenerators(c.persistentTraceGenerators),
	nextTraceGenerators(c.nextTraceGenerators) {
	memcpy(parameterBlock, c.parameterBlock, parameterBlockSize);
}

cuda::HostThreadContext& cuda::HostThreadContext::operator=(const HostThreadContext& c) {
	if(&c == this) return *this;
	selectedDevice = c.selectedDevice;
	validDevices = c.validDevices;
	lastError = c.lastError;
	launchConfigurations = c.launchConfigurations;
	parameterIndices = c.parameterIndices;
	parameterSizes = c.parameterSizes;
	persistentTraceGenerators = c.persistentTraceGenerators;
	nextTraceGenerators = c.nextTraceGenerators;
	memcpy(parameterBlock, c.parameterBlock, parameterBlockSize);
	return *this;
}

cuda::HostThreadContext::HostThreadContext(HostThreadContext&& c): 
	selectedDevice(0), parameterBlock(0), parameterBlockSize(1<<13) {
	*this = std::move(c);
}

cuda::HostThreadContext& cuda::HostThreadContext::operator=(HostThreadContext&& c) {
	if (this == &c) return *this;
	std::swap(selectedDevice, c.selectedDevice);
	std::swap(validDevices, c.validDevices);
	std::swap(lastError, c.lastError);
	std::swap(parameterBlock, c.parameterBlock);
	std::swap(launchConfigurations, c.launchConfigurations);
	std::swap(parameterIndices, c.parameterIndices);
	std::swap(parameterSizes, c.parameterSizes);
	std::swap(persistentTraceGenerators, c.persistentTraceGenerators);
	std::swap(nextTraceGenerators, c.nextTraceGenerators);
	return *this;
}

void cuda::HostThreadContext::clearParameters() {
	parameterIndices.clear();
	parameterSizes.clear();
}

void cuda::HostThreadContext::clear() {
	validDevices.clear();
	launchConfigurations.clear();
	clearParameters();
	persistentTraceGenerators.clear();
	nextTraceGenerators.clear();
}

void cuda::HostThreadContext::mapParameters(const ir::Kernel* kernel) {
	
	assert(kernel->parameters.size() == parameterIndices.size());
	IndexVector::iterator offset = parameterIndices.begin();
	SizeVector::iterator size = parameterSizes.begin();
	unsigned int dst = 0;
	unsigned char* temp = (unsigned char*)malloc(parameterBlockSize);
	for (ir::Kernel::ParameterVector::const_iterator 
		parameter = kernel->parameters.begin(); 
		parameter != kernel->parameters.end(); ++parameter, ++offset, ++size) {
		unsigned int misalignment = dst % parameter->getAlignment();
		unsigned int alignmentOffset = misalignment == 0 
			? 0 : parameter->getAlignment() - misalignment;
		dst += alignmentOffset;
		
		memset(temp + dst, 0, parameter->getSize());
		memcpy(temp + dst, parameterBlock + *offset, *size);
		report( "Mapping parameter at offset " << *offset << " of size " 
			<< *size << " to offset " << dst << " of size " 
			<< parameter->getSize() << " data = " 
			<< hydrazine::dataToString(temp + dst, parameter->getSize()));
		dst += parameter->getSize();
	}
	free(parameterBlock);
	parameterBlock = temp;
	clearParameters();
}

//////////////////////////////////////////////////////////////////////////////////////////////////
cuda::RegisteredKernel::RegisteredKernel(size_t h, const std::string& m, 
	const std::string& k) : handle(h), module(m), kernel(k) {
}

cuda::RegisteredTexture::RegisteredTexture(const std::string& m, 
	const std::string& t) : module(m), texture(t) {
	
}

cuda::RegisteredGlobal::RegisteredGlobal(const std::string& m, 
	const std::string& g) : module(m), global(g) {

}

cuda::Dimension::Dimension(int _x, int _y, int _z, 
	const cudaChannelFormatDesc& _f) : x(_x), y(_y), z(_z), format(_f) {

}

size_t cuda::Dimension::pitch() const {
	return ((format.x + format.y + format.z + format.w) / 8) * x;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void cuda::CudaRuntime::_memcpy(void* dst, const void* src, size_t count, 
	enum cudaMemcpyKind kind) {
	switch(kind) {
		case cudaMemcpyHostToHost: {
			memcpy(dst, src, count);
		}
		break;
		case cudaMemcpyDeviceToHost: {
			if (!_getDevice().checkMemoryAccess(src, count)) {
				_release();
				_memoryError(src, count, "cudaMemcpy");
			}
			
			executive::Device::MemoryAllocation* allocation = 
				_getDevice().getMemoryAllocation(src);
			size_t offset = (char*)src - (char*)allocation->pointer();
			allocation->copy(dst, offset, count);
		}
		break;
		case cudaMemcpyDeviceToDevice: {
			if (!_getDevice().checkMemoryAccess(src, count)) {
				_release();
				_memoryError(src, count, "cudaMemcpy");
			}
			if (!_getDevice().checkMemoryAccess(dst, count)) {
				_release();
				_memoryError(dst, count, "cudaMemcpy");
			}
				
			executive::Device::MemoryAllocation* fromAllocation = 
				_getDevice().getMemoryAllocation(src);
			executive::Device::MemoryAllocation* toAllocation =
				_getDevice().getMemoryAllocation(dst);
			size_t fromOffset = (char*)src 
				- (char*)fromAllocation->pointer();
			size_t toOffset = (char*)dst - (char*)toAllocation->pointer();
			fromAllocation->copy(toAllocation, toOffset, fromOffset, count);
		}
		break;
		case cudaMemcpyHostToDevice: {
			if (!_getDevice().checkMemoryAccess(dst, count)) {
				_release();
				_memoryError(dst, count, "cudaMemcpy");
			}
			
			executive::Device::MemoryAllocation* allocation = 
				_getDevice().getMemoryAllocation(dst);
			size_t offset = (char*)dst - (char*)allocation->pointer();
			allocation->copy(offset, src, count);
		}
		break;
	}
}

void cuda::CudaRuntime::_memoryError(const void* address, size_t count, 
	const std::string& function) {
	std::stringstream stream;
	stream << "In function - " << function << " - invalid memory access at " 
		<< address << "(" << count << " bytes)"; 
	throw hydrazine::Exception(stream.str());
}

void cuda::CudaRuntime::_enumerateDevices() {
	if(_devicesLoaded) return;
	report("Creating devices.");
	if(api::OcelotConfiguration::get().executive.enableNVIDIA) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::SASS, _flags);
		report(" - Added " << d.size() << " nvidia gpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(api::OcelotConfiguration::get().executive.enableEmulated) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::Emulated, _flags);
		report(" - Added " << d.size() << " emulator devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	_devicesLoaded = true;
	
	if(_devices.empty())
	{
		std::cerr << "==Ocelot== WARNING - No CUDA devices found or all " 
			<< "devices disabled!\n";
		std::cerr << "==Ocelot==  Consider enabling the emulator in " 
			<< "configure.ocelot.\n";
	}
	
	// register modules
	for(ModuleMap::const_iterator module = _modules.begin(); 
		module != _modules.end(); ++module) {
		for(DeviceVector::iterator device = _devices.begin(); 
			device != _devices.end(); ++device) {
			(*device)->load(&module->second);
		}
	}
}

//! acquires mutex and locks the runtime
void cuda::CudaRuntime::_lock() {
	pthread_mutex_lock(&_mutex);
}

//! releases mutex
void cuda::CudaRuntime::_unlock() {
	pthread_mutex_unlock(&_mutex);
}


//! sets the last error state for the CudaRuntime object
cudaError_t cuda::CudaRuntime::_setLastError(cudaError_t result) {
	HostThreadContext& thread = _threads[pthread_self()];
	thread.lastError = result;
	return result;
}

cuda::HostThreadContext& cuda::CudaRuntime::_bind() {
	_enumerateDevices();

	HostThreadContextMap::iterator t = _threads.find(pthread_self());
	if (t == _threads.end()) {
		report("Creating new context for thread " << pthread_self());
		t = _threads.insert(std::make_pair(pthread_self(), 
			HostThreadContext())).first;
	}	
	
	HostThreadContext& thread = t->second;

	if (_devices.empty()) return thread;
	
	_selectedDevice = thread.selectedDevice;
	executive::Device& device = _getDevice();

	assert(!device.selected());
	device.select();
	
	return thread;
}

void cuda::CudaRuntime::_unbind() {
	HostThreadContext& thread = _threads[pthread_self()];
	executive::Device& device = _getDevice();
	assert(thread.selectedDevice == _selectedDevice);
	
	_selectedDevice = -1;
	assert(device.selected());
	device.unselect();
}

void cuda::CudaRuntime::_acquire() {
	_lock();
	_bind();
	if (_devices.empty()) _unlock();
}

void cuda::CudaRuntime::_release() {
	_unbind();
	_unlock();
}

executive::Device& cuda::CudaRuntime::_getDevice() {
	assert(_selectedDevice >= 0);
	assert(_selectedDevice < (int)_devices.size());
	return *_devices[_selectedDevice];
}

std::string cuda::CudaRuntime::_formatError( const std::string& message ) {
	std::string result = "==Ocelot== ";
	for(std::string::const_iterator mi = message.begin(); 
		mi != message.end(); ++mi) {
		result.push_back(*mi);
		if(*mi == '\n') {
			result.append("==Ocelot== ");
		}
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cuda::CudaRuntime::CudaRuntime() : _devicesLoaded(false), 
	_selectedDevice(-1), _nextSymbol(1), _flags(0) {
	pthread_mutex_init(&_mutex, 0);
}

cuda::CudaRuntime::~CudaRuntime() {
	//
	// free things that need freeing
	//
	// devices
	for (DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device) {
		delete *device;
	}
	
	// mutex
	pthread_mutex_destroy(&_mutex);
	
	// thread contexts
	
	// textures
	
	// kernels
	
	// fat binaries
	
	// globals
}


//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	registers a CUDA fatbinary and returns a handle for referencing the fat binary
*/
void** cuda::CudaRuntime::cudaRegisterFatBinary(void *fatCubin) {
	size_t handle = 0;
	__cudaFatCudaBinary *binary = (__cudaFatCudaBinary *)fatCubin;
	
	_lock();
		
	for (FatBinaryVector::const_iterator it = _fatBinaries.begin();
		it != _fatBinaries.end(); ++it) {
		if (std::string(it->name()) == binary->ident) {
			_unlock();
		
			assert(0 && "binary already exists");		
			return 0;
		}	
	}

	assertM(binary->ptx->ptx != 0, "binary contains no PTX");

	// register associated PTX
	std::stringstream ptx( binary->ptx->ptx );
	ModuleMap::iterator module = _modules.insert(
		std::make_pair(binary->ident, ir::Module())).first;
	module->second.load(ptx, binary->ident);
	
	report("Loading module (fatbin) - " << module->first);
	
	handle = _fatBinaries.size();
	
	FatBinaryContext cubinContext;
	cubinContext.cubin_ptr = fatCubin;
	_fatBinaries.push_back(cubinContext);
	
	_unlock();
	
	return (void **)handle;
}

/*!
	unregister a cuda fat binary
*/
void cuda::CudaRuntime::cudaUnregisterFatBinary(void **fatCubinHandle) {
	// do we really care?
	// Greg: For most cuda applications, probably not.  The only use would be 
	// to remove and reinsert a fat binary.  Let's use a different interface
	//  for that
	size_t handle = (size_t)fatCubinHandle;
	if (handle >= _fatBinaries.size()) {
		Ocelot_Exception("cudaUnregisterFatBinary(" << handle 
			<< ") - invalid handle.");
	}
}

/*!
	\brief register a CUDA global variable
	\param fatCubinHandle
	\param hostVar
	\param deviceAddress
	\param deviceName
	\param ext
	\param size
	\param constant
	\param global
*/
void cuda::CudaRuntime::cudaRegisterVar(void **fatCubinHandle, char *hostVar, 
	char *deviceAddress, const char *deviceName, int ext, int size, 
	int constant, int global) {

	report("cuda::CudaRuntime::cudaRegisterVar() - host var: " << (void *)hostVar 
		<< ", deviceName: " << deviceName << ", size: " << size << " bytes,"
		<< (constant ? " constant" : " ") << (global ? " global" : " "));

	size_t handle = (size_t)fatCubinHandle;
	_lock();

	std::string moduleName = _fatBinaries[handle].name();
	
	_globals[(void *)hostVar] = RegisteredGlobal(moduleName, deviceName);
	
	_unlock();
}

/*!
	\brief registers a CUDA texture reference
	\param fatCubinHandle
	\param hostVar
	\param deviceAddress
	\param deviceName
	\param dim
	\param norm
	\param ext
*/
void cuda::CudaRuntime::cudaRegisterTexture(
	void **fatCubinHandle,
	const struct textureReference *hostVar,
	const void **deviceAddress,
	const char *deviceName,
	int dim,
	int norm,
	int ext) {
	
	size_t handle = (size_t)fatCubinHandle;
	
	_lock();
	
	std::string moduleName = _fatBinaries[handle].name();
	
	report("cudaRegisterTexture('" << deviceName << ", dim: " << dim 
		<< ", norm: " << norm << ", ext: " << ext);

	_textures[(void*)hostVar] = RegisteredTexture(moduleName, deviceName);
	
	ModuleMap::iterator module = _modules.find(moduleName);
	assert(module != _modules.end());
	
	ir::Module::TextureMap::iterator texture = module->second.textures.find(
		deviceName);
	assertM(texture != module->second.textures.end(), "cudaRegisterTexture - " 
		<< deviceName << " does not exist in module " << moduleName );
	
	texture->second.normalizedFloat = norm;
	
	_unlock();
}

void cuda::CudaRuntime::cudaRegisterShared(
	void **fatCubinHandle,
	void **devicePtr) {
	
	size_t handle = (size_t)fatCubinHandle;
	_lock();
	
	const char *moduleName = _fatBinaries[handle].name();
	const char *variableName = (const char *)devicePtr;
	
	report("cudaRegisterShared() - module " << moduleName << ", devicePtr: " 
		<< devicePtr << " named " << variableName);
	
	report(" Ignoring this variable.");
	
	_unlock();
}

void cuda::CudaRuntime::cudaRegisterSharedVar(
	void **fatCubinHandle,
	void **devicePtr,
	size_t size,
	size_t alignment,
	int storage) {

	size_t handle = (size_t)fatCubinHandle;
	_lock();
	
	const char *moduleName = _fatBinaries[handle].name();
	const char *variableName = (const char *)devicePtr;
	
	report("cudaRegisterSharedVar() - module " << moduleName 
		<< ", devicePtr: " << devicePtr << " named " << variableName 
		<< ", size: " << size << ", alignment: " << alignment << ", storage: " 
		<< storage);
	
	report(" Ignoring this variable.");
		
	_unlock();
}

void cuda::CudaRuntime::cudaRegisterFunction(
	void **fatCubinHandle,
	const char *hostFun,
	char *deviceFun,
	const char *deviceName,
	int thread_limit,
	uint3 *tid,
	uint3 *bid,
	dim3 *bDim,
	dim3 *gDim,
	int *wSize) {

	size_t handle = (size_t)fatCubinHandle;
	
	_lock();

	void *symbol = (void *)hostFun;
	std::string kernelName = deviceFun;
	std::string moduleName = _fatBinaries[handle].name();
	
	_kernels[symbol] = RegisteredKernel(handle, moduleName, kernelName);
	
	_unlock();
}
		
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory allocation

cudaError_t cuda::CudaRuntime::cudaMalloc(void **devPtr, size_t size) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocate(size);
		*devPtr = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}
	
	report("cudaMalloc( *devPtr = " << (void *)*devPtr 
	<< ", size = " << size << ")");

	_release();

	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMallocHost(void **ptr, size_t size) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocateHost(size);
		*ptr = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	report("cudaMallocHost( *pPtr = " << (void *)*ptr 
		<< ", size = " << size << ")");
		
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMallocPitch(void **devPtr, size_t *pitch, 
	size_t width, size_t height) {
	cudaError_t result = cudaErrorMemoryAllocation;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	*pitch = width;

	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocate(width * height);
		_dimensions[allocation->pointer()] = Dimension(width, height, 1);
		*devPtr = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}
	
	report("cudaMallocPitch( *devPtr = " << (void *)*devPtr 
		<< ", pitch = " << *pitch << ")");

	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMallocArray(struct cudaArray **array, 
	const struct cudaChannelFormatDesc *desc, size_t width, size_t height) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	size_t size = width * height * ( desc->x 
		+ desc->y + desc->z + desc->w ) / 8;
	
	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocate(size);
		_dimensions[allocation->pointer()] = Dimension(width, height, 1, *desc);
		*array = (struct cudaArray*)allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}
	
	report("cudaMallocArray( *array = " << (void *)*array << ")");

	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFree(void *devPtr) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaFree(" << devPtr << ")");
	
	try {
		if (devPtr) {
			_getDevice().free(devPtr);
		}
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFreeHost(void *ptr) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaFreeHost(" << ptr << ")");	
	
	try {
		if (ptr) {
			_getDevice().free(ptr);
		}
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFreeArray(struct cudaArray *array) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	try {
		if (array) {
			_getDevice().free(array);
		}
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	report("cudaFreeArray() array = " << (void *)array);

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMalloc3D(struct cudaPitchedPtr* devPtr, 
	struct cudaExtent extent) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMalloc3D() extent - width " << extent.width 
		<< " - height " << extent.height << " - depth " << extent.depth );

	devPtr->pitch = 0;
	devPtr->xsize = extent.width;
	devPtr->ysize = extent.height * extent.depth;
	
	size_t size = devPtr->xsize * devPtr->ysize;

	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocate(size);
		devPtr->ptr = allocation->pointer();
		_dimensions[allocation->pointer()] = Dimension(extent.width, 
			extent.height, extent.depth);
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMalloc3DArray(struct cudaArray** arrayPtr, 
	const struct cudaChannelFormatDesc* desc, struct cudaExtent extent) {

	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	size_t size = extent.width * extent.height * extent.depth * ( desc->x 
		+ desc->y + desc->z + desc->w ) / 8;

	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocate(size);
		*arrayPtr = (struct cudaArray*)allocation->pointer();
		_dimensions[allocation->pointer()] = Dimension(extent.width, 
			extent.height, extent.depth, *desc);
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}

	report("cudaMalloc3DArray() - *arrayPtr = " << (void *)(*arrayPtr));
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaHostAlloc(void **pHost, size_t bytes, 
	unsigned int flags) {
	cudaError_t result = cudaErrorMemoryAllocation;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	try {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().allocateHost(bytes, flags);
		*pHost = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	report("cudaHostAlloc() - *pHost = " << (void *)(*pHost) 
		<< ", bytes " << bytes << ", " << flags);
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaHostGetDevicePointer(void **pDevice, 
	void *pHost, unsigned int flags) {

	cudaError_t result = cudaErrorInvalidHostPointer;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	executive::Device::MemoryAllocation* 
		allocation = _getDevice().getMemoryAllocation(pHost);

	if (allocation != 0) {	
		if (allocation->host()) {
			size_t offset = (char*)pHost - (char*)allocation->mappedPointer();
			*pDevice = (char*)allocation->mappedPointer() + offset;
			result = cudaSuccess;
		}
	}

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaHostGetFlags(unsigned int *pFlags, 
	void *pHost) {

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	executive::Device::MemoryAllocation* 
		allocation = _getDevice().getMemoryAllocation(pHost);
	
	if (allocation != 0) {
		*pFlags = allocation->flags();
	}
	
	_release();
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory copying

cudaError_t cuda::CudaRuntime::cudaMemcpy(void *dst, const void *src, 
	size_t count, enum cudaMemcpyKind kind) {
	cudaError_t result = cudaErrorInvalidDevicePointer;
	if (kind >= 0 && kind <= 3) {
		_acquire();
		if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

		report("cudaMemcpy(" << dst << ", " << src << ", " << count << ")");
		_memcpy(dst, src, count, kind);
		result = cudaSuccess;

		_release();
	}
	else {
		result = cudaErrorInvalidMemcpyDirection;
	}

	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyToSymbol(const char *symbol, 
	const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind) {
	report("cuda::CudaRuntime::cudaMemcpyToSymbol('" << symbol << "' - " 
		<< (void *)symbol << " - value " 
		<< hydrazine::dataToString(src, count));
	
	if (kind != cudaMemcpyHostToDevice) {
		return _setLastError(cudaErrorInvalidMemcpyDirection);
	}

	cudaError_t result = cudaErrorInvalidDevicePointer;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	RegisteredGlobalMap::iterator global = _globals.find((void*)symbol);
	std::string name;
	std::string module;
	
	if (global == _globals.end()) {
		name = symbol;	
	}
	else {
		name = global->second.global;
		module = global->second.module;
	}

	executive::Device::MemoryAllocation* allocation = 
		_getDevice().getGlobalAllocation(module, name);

	if (allocation != 0) {
		if (!_getDevice().checkMemoryAccess((char*)allocation->pointer() 
			+ offset, count)) {
			_release();
			_memoryError((char*)allocation->pointer() + offset, 
				count, "cudaMemcpyToSymbol");
		}
	
		allocation->copy(offset, src, count);
		result = cudaSuccess;
	}
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyFromSymbol(void *dst, 
	const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind) {
	report("cuda::CudaRuntime::cudaMemcpyFromSymbol('" << symbol << "' - " 
		<< (void *)symbol << " - value " 
		<< hydrazine::dataToString(dst, count));

	if (kind != cudaMemcpyDeviceToHost) {
		return _setLastError(cudaErrorInvalidMemcpyDirection);
	}

	cudaError_t result = cudaErrorInvalidDevicePointer;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	RegisteredGlobalMap::iterator global = _globals.find((void*)symbol);
	std::string name;
	std::string module;
	
	if (global == _globals.end()) {
		name = symbol;	
	}
	else {
		name = global->second.global;
		module = global->second.module;
	}

	executive::Device::MemoryAllocation* allocation = 
		_getDevice().getGlobalAllocation(module, name);

	if (allocation != 0) {
		if (!_getDevice().checkMemoryAccess((char*)allocation->pointer() 
			+ offset, count)) {
			_release();
			_memoryError((char*)allocation->pointer() + offset, 
				count, "cudaMemcpyFromSymbol");
		}
	
		allocation->copy(dst, offset, count);
		result = cudaSuccess;
	}
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyAsync(void *dst, const void *src, 
	size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cudaMemcpy(dst, src, count, kind);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyToArray(struct cudaArray *dst, 
	size_t wOffset, size_t hOffset, const void *src, size_t count, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue ;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpyToArray("<< dst << ", " << src << ", " << wOffset 
		<< ", " << hOffset << ", " << count << ")");

	if (kind == cudaMemcpyHostToDevice) {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().getMemoryAllocation(dst);

		if (allocation != 0) {
			Dimension& dimension = _dimensions[allocation->pointer()];
			size_t offset = wOffset + hOffset * dimension.pitch();
			void* address = (char*)allocation->pointer() + offset;
			if (!_getDevice().checkMemoryAccess(address, count)) {
				_release();
				_memoryError(address, count, "cudaMemcpyToArray");
			}
			allocation->copy(offset, src, count);
			result = cudaSuccess;
		}
		else
		{
			_release();
			_memoryError(dst, count, "cudaMemcpyToArray");
		}
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* 
			destination = _getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* 
			source = _getDevice().getMemoryAllocation(src);
		if (destination != 0 && source != 0) {
			Dimension& dimension = _dimensions[destination->pointer()];
			size_t offset = wOffset + hOffset * dimension.pitch();
			void* address = (char*)destination->pointer() + offset;
			if (!_getDevice().checkMemoryAccess(address, count)) {
				_release();
				_memoryError(address, count, "cudaMemcpyToArray");
			}
			if (!_getDevice().checkMemoryAccess(src, count)) {
				_release();
				_memoryError(src, count, "cudaMemcpyToArray");
			}
			size_t sourceOffset = (char*)src - (char*)source->pointer();
			source->copy(destination, offset, sourceOffset, count);
			result = cudaSuccess;
		}
		else
		{
			_release();
			if(destination == 0)
			{
				_memoryError(dst, count, "cudaMemcpyToArray");
			}
			else
			{
				_memoryError(src, count, "cudaMemcpyToArray");
			}
		}
	}

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyFromArray(void *dst, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue ;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpyFromArray("<< dst << ", " << src << ", " << wOffset 
		<< ", " << hOffset << ", " << count << ")");

	if (kind == cudaMemcpyDeviceToHost) {
		executive::Device::MemoryAllocation* 
			allocation = _getDevice().getMemoryAllocation(src);

		if (allocation != 0) {
			Dimension& dimension = _dimensions[allocation->pointer()];
			assert(_dimensions.count(allocation->pointer()) != 0);
			size_t offset = wOffset + hOffset * dimension.pitch();
			void* address = (char*)allocation->pointer() + offset;
			if (!_getDevice().checkMemoryAccess(address, count)) {
				_release();
				_memoryError(address, count, "cudaMemcpyFromArray");
			}
			allocation->copy(dst, offset, count);
			result = cudaSuccess;
		}
		else
		{
			_release();
			_memoryError(src, count, "cudaMemcpyFromArray");
		}
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* 
			destination = _getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* 
			source = _getDevice().getMemoryAllocation(src);
		if (destination != 0 && source != 0) {
			Dimension& dimension = _dimensions[source->pointer()];
			size_t offset = wOffset + hOffset * dimension.pitch();
			void* address = (char*)destination->pointer() + offset;
			if (!_getDevice().checkMemoryAccess(address, count)) {
				_release();
				_memoryError(address, count, "cudaMemcpyFromArray");
			}
			if (!_getDevice().checkMemoryAccess(dst, count)) {
				_release();
				_memoryError(src, count, "cudaMemcpyFromArray");
			}
			size_t destinationOffset = (char*)dst 
				- (char*)destination->pointer();
			source->copy(destination, destinationOffset, offset, count);
			result = cudaSuccess;
		}
		else
		{
			_release();
			 if(destination == 0)
			 {
			 	_memoryError(dst, count, "cudaMemcpyFromArray");
			 }
			 else
			 {
			 	_memoryError(src, count, "cudaMemcpyFromArray");			 
			 }
		}
	}

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyArrayToArray(struct cudaArray *dst, 
	size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, 
	size_t wOffsetSrc, size_t hOffsetSrc, size_t count, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	report("cudaMemcpyArrayToArray()");

	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* 
			destination = _getDevice().getMemoryAllocation(dst);
		if (destination->pointer() != dst) {
			_release();
			_memoryError(dst, count, "cudaMemcpyArrayToArray");
		}
		executive::Device::MemoryAllocation* 
			source = _getDevice().getMemoryAllocation(src);
		if (source->pointer() != src) {
			_release();
			_memoryError(src, count, "cudaMemcpyArrayToArray");
		}
		if (destination != 0 && source != 0) {
			assert(_dimensions.count(source->pointer()) != 0);
			assert(_dimensions.count(destination->pointer()) != 0);
			Dimension& sourceDimension = _dimensions[source->pointer()];
			Dimension& destinationDimension = 
				_dimensions[destination->pointer()];
			size_t sourceOffset = wOffsetSrc 
				+ hOffsetSrc * sourceDimension.pitch();
			size_t destinationOffset = wOffsetDst 
				+ hOffsetDst * destinationDimension.pitch();
			void* sourceAddress = (char*)source->pointer() + sourceOffset;
			void* destinationAddress = (char*)destination->pointer() 
				+ destinationOffset;
			if (!_getDevice().checkMemoryAccess(sourceAddress, count)) {
				_release();
				_memoryError(sourceAddress, count, "cudaMemcpyArrayToArray");
			}
			if (!_getDevice().checkMemoryAccess(destinationAddress, count)) {
				_release();
				_memoryError(destinationAddress, 
					count, "cudaMemcpyArrayToArray");
			}
			source->copy(destination, destinationOffset, sourceOffset, count);
			result = cudaSuccess;
		}	
	}
	
	_release();
	return _setLastError(result);	
}

/*!
	\brief perform a 2D memcpy from a dense buffer
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2D(void *dst, size_t dpitch, 
	const void *src, size_t spitch, size_t width, size_t height, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpy2D()");	

	switch (kind) {
		case cudaMemcpyHostToHost:
		{
			for (size_t row = 0; row < height; row++) {
				char* dstPtr = (char*)dst + dpitch * row;
				char* srcPtr = (char*)src + spitch * row;
				std::memcpy(dstPtr, srcPtr, width);
			}
			result = cudaSuccess;
		}
		break;
		case cudaMemcpyDeviceToHost:
		{
			executive::Device::MemoryAllocation* source = 
				_getDevice().getMemoryAllocation(src);
			if (source != 0) {
				for (size_t row = 0; row < height; row++) {
					void* dstPtr = (char *)dst + dpitch * row;
					size_t srcOffset = spitch * row;

					if (!_getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcOffset, width)) {
						_release();
						_memoryError((char*)source->pointer() + srcOffset, 
							width, "cudaMemcpy2D");
					}
					
					source->copy(dstPtr, srcOffset, width);
				}
				result = cudaSuccess;
			}
			else {
				_release();
				_memoryError(src, width * height, "cudaMemcpy2D");
			}
		}
		break;		
		case cudaMemcpyHostToDevice:
		{
			executive::Device::MemoryAllocation* destination = 
				_getDevice().getMemoryAllocation(dst);
			size_t dstPitch = _dimensions[destination->pointer()].pitch();
			if (destination != 0) {
				for (size_t row = 0; row < height; row++) {
					void* srcPtr = (char *)src + spitch * row;
					size_t dstOffset = dstPitch * row;

					if (!_getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstOffset, width)) {
						_release();
						_memoryError((char*)destination->pointer() + dstOffset, 
							width, "cudaMemcpy2D");
					}
					
					destination->copy(dstOffset, srcPtr, width);
				}
				result = cudaSuccess;
			}
			else {
				_release();
				_memoryError(dst, width * height, "cudaMemcpy2D");
			}
		}
		break;
		case cudaMemcpyDeviceToDevice:
		{
			executive::Device::MemoryAllocation* destination = 
				_getDevice().getMemoryAllocation(dst);
			executive::Device::MemoryAllocation* source = 
				_getDevice().getMemoryAllocation(src);
			if (destination != 0 && source != 0) {
				for (size_t row = 0; row < height; row++) {
					size_t srcOffset = spitch * row;
					size_t dstOffset = dpitch * row;

					if (!_getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstOffset, width)) {
						_release();
						_memoryError((char*)destination->pointer() + dstOffset, 
							width, "cudaMemcpy2D");
					}
					if (!_getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcOffset, width)) {
						_release();
						_memoryError((char*)source->pointer() + srcOffset, 
							width, "cudaMemcpy2D");
					}
					
					source->copy(destination, dstOffset, srcOffset, width);
				}
				result = cudaSuccess;
			}
			else {
				_release();
				if (destination == 0) {
					_memoryError(dst, width * height, "cudaMemcpy2D");
				}
				else {
					_memoryError(src, width * height, "cudaMemcpy2D");
				}
			}
		}
		break;
		default: break;
	}
	
	_release();
	return _setLastError(result);	
}

/*!
	\brief perform a 2D memcpy to an array
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2DToArray(struct cudaArray *dst, 
	size_t wOffset, size_t hOffset, const void *src, size_t spitch, 
	size_t width, size_t height, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpy2DtoArray(dst = " << (void *)dst 
		<< ", src = " << (void *)src);
	
	if (kind == cudaMemcpyHostToDevice) {
		executive::Device::MemoryAllocation* destination = 
			_getDevice().getMemoryAllocation(dst);
		
		if (destination == 0) {
			_release();
			_memoryError(dst, width * height, "cudaMemcpy2DtoArray");
		}
		
		size_t dstPitch = _dimensions[destination->pointer()].pitch();

		for (size_t row = 0; row < height; ++row) {
			void* srcPtr = (char*)src + row * spitch;
			size_t dstOffset = (row + hOffset) * dstPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				_release();
				_memoryError((char*)destination->pointer() + dstOffset, 
					width, "cudaMemcpy2DtoArray");
			}
			
			destination->copy(dstOffset, srcPtr, width);
		}
		
		result = cudaSuccess;
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* destination = 
			_getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* source = 
			_getDevice().getMemoryAllocation(src);
		
		if (destination == 0) {
			_release();
			_memoryError(dst, width * height, "cudaMemcpy2DtoArray");
		}

		if (source == 0) {
			_release();
			_memoryError(src, width * height, "cudaMemcpy2DtoArray");
		}
		
		size_t dstPitch = _dimensions[destination->pointer()].pitch();
		
		for (size_t row = 0; row < height; ++row) {
			size_t srcOffset = row * spitch;
			size_t dstOffset = (row + hOffset) * dstPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				_release();
				_memoryError((char*)destination->pointer() 
					+ dstOffset, width, "cudaMemcpy2DtoArray");
			}

			if (!_getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				_release();
				_memoryError((char*)source->pointer() + srcOffset, 
					width, "cudaMemcpy2DtoArray");
			}
			
			source->copy(destination, dstOffset, srcOffset, width);
		}
		
		result = cudaSuccess;
	}
	
	_release();
	return _setLastError(result);
}

/*!
	\brief perform a 2D memcpy from an array
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2DFromArray(void *dst, size_t dpitch, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, 
	size_t height, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpy2DfromArray(dst = " << (void *)dst 
		<< ", src = " << (void *)src);
	
	if (kind == cudaMemcpyDeviceToHost) {
		executive::Device::MemoryAllocation* source = 
			_getDevice().getMemoryAllocation(dst);
		
		if (source == 0) {
			_release();
			_memoryError(src, width * height, "cudaMemcpy2DfromArray");
		}
		
		assert(_dimensions.count(source->pointer()) != 0);
		size_t srcPitch = _dimensions[source->pointer()].pitch();

		for (size_t row = 0; row < height; ++row) {
			void* dstPtr = (char*)dst + row * dpitch;
			size_t srcOffset = (row + hOffset) * srcPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				_release();
				_memoryError((char*)source->pointer() 
					+ srcOffset, width, "cudaMemcpy2DfromArray");
			}
			
			source->copy(dstPtr, srcOffset, width);
		}
		
		result = cudaSuccess;
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* destination = 
			_getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* source = 
			_getDevice().getMemoryAllocation(src);
		
		if (destination == 0) {
			_release();
			_memoryError(dst, width * height, "cudaMemcpy2DfromArray");
		}

		if (source == 0) {
			_release();
			_memoryError(src, width * height, "cudaMemcpy2DfromArray");
		}
		
		size_t srcPitch = _dimensions[source->pointer()].pitch();
		
		for (size_t row = 0; row < height; ++row) {
			size_t dstOffset = row * dpitch;
			size_t srcOffset = (row + hOffset) * srcPitch + wOffset;
			
			if (!_getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				_release();
				_memoryError((char*)destination->pointer() 
					+ dstOffset, width, "cudaMemcpy2DfromArray");
			}

			if (!_getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				_release();
				_memoryError((char*)source->pointer() + srcOffset, width, 
					"cudaMemcpy2DfromArray");
			}
			
			destination->copy(source, srcOffset, dstOffset, width);
		}
		
		result = cudaSuccess;
	}
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpy3D(const struct cudaMemcpy3DParms *p) {

	cudaError_t result = cudaErrorInvalidValue;

	cudaPitchedPtr dst;
	cudaPitchedPtr src;
	const cudaExtent& extent = p->extent;

	if (p->dstArray) {
		dst.ptr = (void *)p->dstArray;
		dst.pitch = _dimensions[p->dstArray].pitch();
		dst.xsize = _dimensions[p->dstArray].x;
		dst.ysize = _dimensions[p->dstArray].y;		
	}
	else {
		dst = p->dstPtr;
	}

	if (p->srcArray) {
		src.ptr = (void *)p->srcArray;
		src.pitch = _dimensions[p->srcArray].pitch();
		src.xsize = _dimensions[p->srcArray].x;
		src.ysize = _dimensions[p->srcArray].y;
	}
	else {
		src = p->srcPtr;
	}

	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaMemcpy3D() - dstPtr = (" << (void *)dst.ptr << ", " 
		<< dst.xsize << ", " << dst.ysize << ") - srcPtr = (" 
		<< (void *)src.ptr << ", " << src.xsize << ", " 
		<< src.ysize << ")");

	switch(p->kind) {
		case cudaMemcpyHostToHost:
		{
			for (size_t z = 0; z < extent.depth; ++z) {
				for (size_t y = 0; y < extent.height; ++y) {
					void* dstPtr = (char*)dst.ptr + p->dstPos.x + dst.xsize 
						* ((p->dstPos.y+y) + (z+p->dstPos.z) * dst.ysize);
					void* srcPtr = (char*)src.ptr + p->srcPos.x + src.xsize 
						* ((p->srcPos.y+y) + (z+p->srcPos.z) * src.ysize);

					std::memcpy(dstPtr, srcPtr, extent.width);
				}
			}
			result = cudaSuccess;
		}
		break;
		case cudaMemcpyHostToDevice:
		{
			executive::Device::MemoryAllocation* destination = 
				_getDevice().getMemoryAllocation(dst.ptr);
			
			if (destination == 0) {
				_release();
				_memoryError(dst.ptr, extent.width 
					* extent.height * extent.depth, "cudaMemcpy3D");
			}
			
			for (size_t z = 0; z < extent.depth; ++z) {
				for (size_t y = 0; y < extent.height; ++y) {
					size_t dstPtr = p->dstPos.x + dst.xsize 
						* ((p->dstPos.y+y) + (z+p->dstPos.z) * dst.ysize);
					void* srcPtr = (char*)src.ptr + p->srcPos.x + src.xsize 
						* ((p->srcPos.y+y) + (z+p->srcPos.z) * src.ysize);

					if (!_getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstPtr, extent.width)) {
						_release();
						_memoryError((char*)destination->pointer() + dstPtr, 
							extent.width, "cudaMemcpy3D");
					}

					destination->copy(dstPtr, srcPtr, extent.width);
				}
			}
			result = cudaSuccess;
		}
		break;
		case cudaMemcpyDeviceToHost:
		{
			executive::Device::MemoryAllocation* source = 
				_getDevice().getMemoryAllocation(src.ptr);
			
			if (source == 0) {
				_release();
				_memoryError(src.ptr, extent.width 
					* extent.height * extent.depth, "cudaMemcpy3D");
			}
			
			for (size_t z = 0; z < extent.depth; ++z) {
				for (size_t y = 0; y < extent.height; ++y) {
					void* dstPtr = (char*)dst.ptr + p->dstPos.x + dst.xsize 
						* ((p->dstPos.y+y) + (z+p->dstPos.z) * dst.ysize);
					size_t srcPtr = p->srcPos.x + src.xsize 
						* ((p->srcPos.y+y) + (z+p->srcPos.z) * src.ysize);

					if (!_getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcPtr, extent.width)) {
						_release();
						_memoryError((char*)source->pointer() + srcPtr, 
							extent.width, "cudaMemcpy3D");
					}

					source->copy(dstPtr, srcPtr, extent.width);
				}
			}
			result = cudaSuccess;
		}
		break;
		case cudaMemcpyDeviceToDevice:
		{
			executive::Device::MemoryAllocation* source = 
				_getDevice().getMemoryAllocation(src.ptr);
			
			if (source == 0) {
				_release();
				_memoryError(src.ptr, extent.width 
					* extent.height * extent.depth, "cudaMemcpy3D");
			}

			executive::Device::MemoryAllocation* destination = 
				_getDevice().getMemoryAllocation(dst.ptr);
			
			if (destination == 0) {
				_release();
				_memoryError(dst.ptr, extent.width 
					* extent.height * extent.depth, "cudaMemcpy3D");
			}
			
			for (size_t z = 0; z < extent.depth; ++z) {
				for (size_t y = 0; y < extent.height; ++y) {
					size_t dstPtr = p->dstPos.x + dst.xsize 
						* ((p->dstPos.y+y) + (z+p->dstPos.z) * dst.ysize);
					size_t srcPtr = p->srcPos.x + src.xsize 
						* ((p->srcPos.y+y) + (z+p->srcPos.z) * src.ysize);

					if (!_getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcPtr, extent.width)) {
						_release();
						_memoryError((char*)source->pointer() + srcPtr,
							extent.width, "cudaMemcpy3D");
					}

					if (!_getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstPtr, extent.width)) {
						_release();
						_memoryError((char*)destination->pointer() + dstPtr, 
							extent.width, "cudaMemcpy3D");
					}

					source->copy(destination, dstPtr, srcPtr, extent.width);
				}
			}
			result = cudaSuccess;
		}
		break;
	}
	
	_release();
	return _setLastError(result);	
}

cudaError_t cuda::CudaRuntime::cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, 
	cudaStream_t stream) {
	return cudaMemcpy3D(p);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memset
//

cudaError_t cuda::CudaRuntime::cudaMemset(void *devPtr, int value, size_t count) {
	cudaError_t result = cudaErrorInvalidDevicePointer;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	executive::Device::MemoryAllocation* allocation = 
		_getDevice().getMemoryAllocation(devPtr);
	
	if (allocation == 0) {
		_release();
		_memoryError(devPtr, count, "cudaMemset");
	}
	
	if (!_getDevice().checkMemoryAccess(devPtr, count)) {
		_release();
		_memoryError(devPtr, count, "cudaMemset");
	}
	
	size_t offset = (char*)devPtr - (char*)allocation->pointer();
	
	allocation->memset(offset, value, count);
	result = cudaSuccess;
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemset2D(void *devPtr, size_t pitch, 
	int value, size_t width, size_t height) {

	cudaError_t result = cudaErrorInvalidValue;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	executive::Device::MemoryAllocation* allocation = 
		_getDevice().getMemoryAllocation(devPtr);
	
	if (allocation == 0) {
		_release();
		_memoryError(devPtr, width * height, "cudaMemset2D");
	}
		
	size_t offset = (char*)devPtr - (char*)allocation->pointer();
	
	if (pitch == width) {
		if (!_getDevice().checkMemoryAccess(devPtr, width * height)) {
			_release();
			_memoryError(devPtr, width * height, "cudaMemset2D");
		}
		
		allocation->memset(offset, value, pitch * height);
	}
	else {
		for (size_t i = 0; i < height; i++) {
			size_t ptr = offset + pitch * i;
			void* address = (char*)allocation->pointer() + ptr;
			if (!_getDevice().checkMemoryAccess(address, width)) {
				_release();
				_memoryError(address, width, "cudaMemset2D");
			}
		
			allocation->memset(ptr, value, width);
		}
	}

	result = cudaSuccess;
	
	_release();
	return _setLastError(result);	
}


cudaError_t cuda::CudaRuntime::cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr,
	int value, struct cudaExtent extent) {

	cudaError_t result = cudaErrorNotYetImplemented;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	assert(0 && "unimplemented");
	
	_release();
	return _setLastError(result);	
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory allocation
//

cudaError_t cuda::CudaRuntime::cudaGetSymbolAddress(void **devPtr, 
	const char *symbol) {

	report("cuda::CudaRuntime::cudaGetSymbolAddress(" << devPtr << ", " 
		<< (void*)symbol << ")");
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	RegisteredGlobalMap::iterator global = _globals.find((void*)symbol);
	
	std::string name;
	std::string module;
	
	if (global != _globals.end()) {
		name = global->second.global;
		module = global->second.module;
	}
	else {
		name = symbol;
	}
	
	executive::Device::MemoryAllocation* 
		allocation = _getDevice().getGlobalAllocation(module, name);
	assertM(allocation != 0, "Invalid global name " << name 
		<< " in module " << module);

	*devPtr = allocation->pointer();
	report("devPtr: " << *devPtr);	
	
	_release();
	return _setLastError(result);	
}

cudaError_t cuda::CudaRuntime::cudaGetSymbolSize(size_t *size, const char *symbol) {
	cudaError_t result = cudaSuccess;
	report("cuda::CudaRuntime::cudaGetSymbolSize(" << size << ", " 
		<< (void*) symbol << ")");
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	RegisteredGlobalMap::iterator global = _globals.find((void*)symbol);
	
	std::string name;
	std::string module;
	
	if (global != _globals.end()) {
		name = global->second.global;
		module = global->second.module;
	}
	else {
		name = symbol;
	}
	
	executive::Device::MemoryAllocation* 
		allocation = _getDevice().getGlobalAllocation(module, name);
	assertM(allocation != 0, "Invalid global name " << name 
		<< " in module " << module);

	*size = allocation->size();
	report("size: " << *size);	
	
	_release();
	return _setLastError(result);	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetDeviceCount(int *count) {
	cudaError_t result = cudaSuccess;
	_acquire();
	
	if (_devices.empty())
	{
		*count = 0;
	}
	else
	{	
		*count = _devices.size();
		_release();
	}
	
	return _setLastError(result);
}

#define minimum(x, y) ((x) > (y) ? (y) : (x))

cudaError_t cuda::CudaRuntime::cudaGetDeviceProperties(struct cudaDeviceProp *prop, int dev) {
	cudaError_t result = cudaSuccess;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	if (dev < (int)_devices.size()) {
		const executive::Device& device = *_devices[dev];
		const executive::Device::Properties& properties = device.properties();
	
		report("cuda::CudaRuntime::cudaGetDeviceProperties(dev = " << dev 
			<< ") - major: " << properties.major 
			<< ", minor: " << properties.minor);

		memset(prop, 0, sizeof(prop));
		hydrazine::strlcpy( prop->name, properties.name.c_str(), 256 );
		prop->canMapHostMemory = 1;
		prop->clockRate = properties.clockRate;
		prop->computeMode = cudaComputeModeDefault;
		prop->deviceOverlap = properties.memcpyOverlap;
		prop->integrated = 0;
		prop->kernelExecTimeoutEnabled = 0;
		prop->major = properties.major;
		prop->minor = properties.minor;
		prop->maxGridSize[0] = properties.maxGridSize[0];
		prop->maxGridSize[1] = properties.maxGridSize[1];
		prop->maxGridSize[2] = properties.maxGridSize[2];
		prop->maxThreadsDim[0] = properties.maxThreadsDim[0];
		prop->maxThreadsDim[1] = properties.maxThreadsDim[1];
		prop->maxThreadsDim[2] = properties.maxThreadsDim[2];
		prop->maxThreadsPerBlock = properties.maxThreadsPerBlock;
		prop->memPitch = properties.memPitch;
		prop->multiProcessorCount = properties.multiprocessorCount;
		prop->regsPerBlock = properties.regsPerBlock;
		prop->sharedMemPerBlock = properties.sharedMemPerBlock;
		prop->textureAlignment = properties.textureAlign;
		prop->totalConstMem = properties.totalConstantMemory;
		prop->totalGlobalMem = properties.totalMemory;
		prop->warpSize = properties.SIMDWidth;
		
		report("  returning: prop->major = " << prop->major 
			<< ", prop->minor = " << prop->minor);
		
		result = cudaSuccess;
	}
	else {
		result = cudaErrorInvalidDevice;
	}
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaChooseDevice(int *device, 
	const struct cudaDeviceProp *prop) {
	cudaError_t result = cudaSuccess;
	*device = _getDevice().properties().guid;
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetDevice(int device) {
	cudaError_t result = cudaErrorSetOnActiveProcess;
	
	_lock();

	if ((int)_devices.size() <= device || device < 0) {
		result = cudaErrorInvalidDevice;
	}
	else {
		HostThreadContext& thread = _threads[pthread_self()];
		thread.selectedDevice = device;
		result = cudaSuccess;
	}

	_unlock();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGetDevice(int *device) {
	cudaError_t result = cudaSuccess;
	
	_lock();
	HostThreadContext& thread = _threads[pthread_self()];
	*device = thread.selectedDevice;
	_unlock();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetValidDevices(int *device_arr, int len) {
	cudaError_t result = cudaSuccess;
	_lock();
	HostThreadContext& thread = _threads[pthread_self()];
	thread.validDevices.resize(len);
	for (int i = 0 ; i < len; i++) {
		thread.validDevices[i] = device_arr[i];
	}
	_unlock();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetDeviceFlags(int f) {
	cudaError_t result = cudaSuccess;
	_lock();
	if(!_devicesLoaded)
	{
		_flags = f;
	}
	else
	{
		result = cudaErrorSetOnActiveProcess;
	}
	_unlock();
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! binds a texture to a reference and a CUDA memory block
cudaError_t cuda::CudaRuntime::cudaBindTexture(size_t *offset, 
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t size) {

	cudaError_t result = cudaErrorInvalidValue;
		
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	RegisteredTextureMap::iterator texture = _textures.find((void*)texref);
	if(texture != _textures.end()) {
		try {
			_getDevice().bindTexture((void*)devPtr, texture->second.module, 
				texture->second.texture, *desc, size);
			if(offset != 0) *offset = 0;
			result = cudaSuccess;
		}
		catch(hydrazine::Exception& e) {
		
		}
	}
	
	report("cudaBindTexture(ref = " << texref 
		<< ", devPtr = " << devPtr << ", size = " << size << ")");

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaBindTexture2D(size_t *offset,
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t width, 
	size_t height, size_t pitch) {
	cudaError_t result = cudaErrorInvalidValue;
	assert(pitch != 0);

	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	RegisteredTextureMap::iterator texture = _textures.find((void*)texref);

	if(texture != _textures.end()) {
		try {
			_getDevice().bindTexture((void*)devPtr, texture->second.module, 
				texture->second.texture, *desc, width * height);
			if(offset != 0) *offset = 0;
			result = cudaSuccess;
		}
		catch(hydrazine::Exception& e) {

		}
	}
	
	report("cudaBindTexture2D(ref = " << texref 
		<< ", devPtr = " << devPtr << ", width = " << width << ", height = " 
		<< height << ", pitch = " << pitch << ")");

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaBindTextureToArray(
	const struct textureReference *texref, const struct cudaArray *array, 
	const struct cudaChannelFormatDesc *desc) {
	cudaError_t result = cudaErrorInvalidValue;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaBindTextureToArray() - texref = '" << texref << "', array = " 
		<< (void *)array << " - format: " << desc->f << " (" << desc->x 
		<< ", " << desc->y << ", " << desc->z << ")");

	DimensionMap::iterator dimension = _dimensions.find((void*)array);
	assert(dimension != _dimensions.end());

	size_t size = dimension->second.x * dimension->second.y 
		* dimension->second.z;

	RegisteredTextureMap::iterator texture = _textures.find((void*)texref);
	if(texture != _textures.end()) {
		try {
			_getDevice().bindTexture((void*)array, texture->second.module, 
				texture->second.texture, *desc, size);
			result = cudaSuccess;
		}
		catch(hydrazine::Exception& e) {

		}
	}
	
	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaUnbindTexture(
	const struct textureReference *texref) {
	cudaError_t result = cudaErrorInvalidValue;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	RegisteredTextureMap::iterator texture = _textures.find((void*)texref);
	if(texture != _textures.end()) {
		try {
			_getDevice().unbindTexture(texture->second.module, 
				texture->second.texture);
			result = cudaSuccess;
		}
		catch(hydrazine::Exception& e) {

		}
	}
	
	_release();

	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGetTextureAlignmentOffset(size_t *offset, 
	const struct textureReference *texref) {
	*offset = 0;
	return _setLastError(cudaSuccess);
}

cudaError_t cuda::CudaRuntime::cudaGetTextureReference(
	const struct textureReference **texref, const char *symbol) {
	cudaError_t result = cudaErrorInvalidTexture;

	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	std::string name = symbol;
	RegisteredTextureMap::iterator matchedTexture = _textures.end();
	
	for(RegisteredTextureMap::iterator texture = _textures.begin(); 
		texture != _textures.end(); ++texture) {
		if(texture->second.texture == name) {
			if(matchedTexture != _textures.end()) {
				_release();
				Ocelot_Exception("==Ocelot== Ambiguous texture '" << name 
					<< "' declared in at least two modules ('" 
					<< texture->second.module << "' and '" 
					<< matchedTexture->second.module << "')");
			}
			matchedTexture = texture;
		}
	}
	
	if(matchedTexture != _textures.end()) {
		*texref = (const struct textureReference*)matchedTexture->first;
	}
	
	_release();
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetChannelDesc(
	struct cudaChannelFormatDesc *desc, const struct cudaArray *array) {
	cudaError_t result = cudaErrorInvalidValue;

	_lock();

	DimensionMap::iterator dimension = _dimensions.find((void*)array);
	
	if (dimension != _dimensions.end()) {
		*desc = dimension->second.format;
		result = cudaSuccess;
	}
	
	_unlock();
	return _setLastError(result);
}

struct cudaChannelFormatDesc cuda::CudaRuntime::cudaCreateChannelDesc(int x, 
	int y, int z, int w, enum cudaChannelFormatKind f) {

	struct cudaChannelFormatDesc desc;
	desc.w = w; desc.x = x; desc.y = y; desc.z = z; desc.f = f;
	return desc;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetLastError(void) {
	HostThreadContext& thread = _threads[pthread_self()];
	return thread.lastError;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
	
cudaError_t cuda::CudaRuntime::cudaConfigureCall(dim3 gridDim, dim3 blockDim, 
	size_t sharedMem, cudaStream_t stream) {

	_lock();
	report("cudaConfigureCall()");
	
	cudaError_t result = cudaErrorInvalidConfiguration;
	HostThreadContext &thread = _threads[pthread_self()];
	
	KernelLaunchConfiguration launch(gridDim, blockDim, sharedMem, stream);
	thread.launchConfigurations.push_back(launch);
	result = cudaSuccess;
	
	_unlock();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetupArgument(const void *arg, size_t size, 
	size_t offset) {
	cudaError_t result = cudaSuccess;
	
	_lock();
	
	HostThreadContext &thread = _threads[pthread_self()];

	report("cudaSetupArgument() - offset " << offset << ", size " << size);
	
	memcpy(thread.parameterBlock + offset, arg, size);
	
	thread.parameterIndices.push_back(offset);
	thread.parameterSizes.push_back(size);
	
	_unlock();
	
	return _setLastError(result);
}

static ir::Dim3 convert(const dim3& d) {
	return std::move(ir::Dim3(d.x, d.y, d.z));
}

cudaError_t cuda::CudaRuntime::cudaLaunch(const char *entry) {
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	HostThreadContext& thread = _threads[pthread_self()];
	cudaError_t result = cudaSuccess;
	
	assert(thread.launchConfigurations.size());
	
	KernelLaunchConfiguration launch(thread.launchConfigurations.back());
	thread.launchConfigurations.pop_back();
	
	RegisteredKernelMap::iterator kernel = _kernels.find((void*)entry);
	assert(kernel != _kernels.end());
	std::string moduleName = kernel->second.module;
	std::string kernelName = kernel->second.kernel;

	ModuleMap::iterator module = _modules.find(moduleName);
	assert(module != _modules.end());
	
	ir::Kernel* k = module->second.getKernel(kernelName);
	assert(k != 0);

	thread.mapParameters(k);
	
	report("cudaLaunch(" << kernelName 
		<< ") on thread " << pthread_self());
	
	try {
		trace::TraceGeneratorVector traceGens;

		if (api::OcelotConfiguration::getTrace().enabled) {
			traceGens = thread.persistentTraceGenerators;
			traceGens.insert(traceGens.end(), 
				thread.nextTraceGenerators.begin(), 
				thread.nextTraceGenerators.end());
		}

		_getDevice().launch(moduleName, kernelName, convert(launch.gridDim), 
			convert(launch.blockDim), launch.sharedMemory, 
			thread.parameterBlock, thread.parameterBlockSize, traceGens);
		report(" launch completed successfully");	
	}
	catch( const executive::RuntimeException& e ) {
		std::cerr << "==Ocelot== Emulator failed to run kernel \"" 
			<< kernelName 
			<< "\" with exception: \n";
		std::cerr << _formatError( e.toString() ) 
			<< "\n" << std::flush;
		thread.lastError = cudaErrorLaunchFailure;
		_release();
		throw e;
	}

	_release();
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFuncGetAttributes(
	struct cudaFuncAttributes *attr, const char *symbol) {
	cudaError_t result = cudaErrorInvalidDeviceFunction;
		
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	//
	// go find the kernel and fill out its attributes
	//
	RegisteredKernelMap::iterator kernel = _kernels.find((void*)symbol);
	if (kernel != _kernels.end()) {
		*attr = _getDevice().getAttributes(kernel->second.module, 
			kernel->second.kernel);
	}
	
	_release();
	
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// CUDA event creation

cudaError_t cuda::CudaRuntime::cudaEventCreate(cudaEvent_t *event) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	*event = _getDevice().createEvent( 0 );
	
	_release();

	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventCreateWithFlags(cudaEvent_t *event, 
	int flags) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	*event = _getDevice().createEvent(flags);
	
	_release();

	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventRecord(cudaEvent_t event, 
	cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	_getDevice().recordEvent(event, stream);
	
	_release();	
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventQuery(cudaEvent_t event) {
	cudaError_t result = cudaErrorInvalidValue;

	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	_getDevice().queryEvent(event);

	_release();

	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventSynchronize(cudaEvent_t event) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	_getDevice().synchronizeEvent(event);
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventDestroy(cudaEvent_t event) {
	cudaError_t result = cudaErrorInvalidValue;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	_getDevice().destroyEvent(event);
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventElapsedTime(float *ms, 
	cudaEvent_t start, cudaEvent_t end) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	*ms = _getDevice().getEventTime(start, end);
	
	_release();
	
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// CUDA streams
//

cudaError_t cuda::CudaRuntime::cudaStreamCreate(cudaStream_t *pStream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	*pStream = _getDevice().createStream();
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamDestroy(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	_getDevice().destroyStream(stream);
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamSynchronize(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;

	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	_getDevice().synchronizeStream(stream);
	
	_release();

	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamQuery(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;

	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	_getDevice().queryStream(stream);
	
	_release();
	
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaThreadExit(void) {
	cudaError_t result = cudaSuccess;
	
	// this is not required because state is shared across threads in Ocelot
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaThreadSynchronize(void) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	_getDevice().synchronize();

	_release();
	
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGLMapBufferObject(void **devPtr, 
	GLuint bufObj) {
	return cudaGLMapBufferObjectAsync(devPtr, bufObj, 0);
}

cudaError_t cuda::CudaRuntime::cudaGLMapBufferObjectAsync(void **devPtr, 
	GLuint bufObj, cudaStream_t stream) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaGLMapBufferObjectAsync()");
	_getDevice().mapGraphicsResource(devPtr, bufObj, stream);
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLRegisterBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaGLRegisterBufferObject(" << bufObj << ")");	
	_getDevice().glRegisterBuffer(bufObj, 0);
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLSetBufferObjectMapFlags(GLuint bufObj, 
	unsigned int flags) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);

	report("cudaGLRegisterBufferObjectMapFlags(" << bufObj << ")");	
	_getDevice().glRegisterBuffer(bufObj, flags);
	
	_release();
	
	return _setLastError(result);

}

cudaError_t cuda::CudaRuntime::cudaGLSetGLDevice(int device) {
	report("cudaGLSetGLDevice(" << device << ")");
	return cudaSuccess;
}

cudaError_t cuda::CudaRuntime::cudaGLUnmapBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGLUnmapBufferObject(" << bufObj << ")");
	
	_getDevice().unmapGraphicsResource((void*)bufObj);
	
	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLUnmapBufferObjectAsync(GLuint bufObj, 
	cudaStream_t stream) {
	assert(0 && "unimplemented");
}

cudaError_t cuda::CudaRuntime::cudaGLUnregisterBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGLUnregisterBufferObject");
	
	_getDevice().unRegisterGraphicsResource((void*)bufObj);	

	_release();
	
	return _setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGraphicsGLRegisterBuffer(
	struct cudaGraphicsResource **resource, GLuint buffer, unsigned int flags) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGraphicsGLRegisterBuffer");
	
	*resource = (struct cudaGraphicsResource*)_getDevice().glRegisterBuffer(
		buffer, flags);

	_release();
	
	return _setLastError(result);	
}

cudaError_t cuda::CudaRuntime::cudaGraphicsGLRegisterImage(
	struct cudaGraphicsResource **resource, GLuint image, int target, 
	unsigned int flags) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGraphicsGLRegisterImage");
	
	*resource = (struct cudaGraphicsResource*)_getDevice().glRegisterImage(
		image, target, flags);

	_release();
	
	return _setLastError(result);	
}

cudaError_t cuda::CudaRuntime::cudaGraphicsUnregisterResource(
	struct cudaGraphicsResource *resource) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGraphicsUnregisterResource");
	
	_getDevice().unRegisterGraphicsResource(resource);	

	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsResourceSetMapFlags(
	struct cudaGraphicsResource *resource, unsigned int flags) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGraphicsResourceSetMapFlags");
	
	_getDevice().setGraphicsResourceFlags(resource, flags);	

	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsMapResources(int count, 
	struct cudaGraphicsResource **resource, cudaStream_t stream) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("mapGraphicsResource");
	
	_getDevice().mapGraphicsResource(resource, count, stream);	

	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsUnmapResources(int count, 
	struct cudaGraphicsResource **resources, cudaStream_t stream) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGraphicsUnmapResources");
	
	_getDevice().mapGraphicsResource(resources, count, stream);	

	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsResourceGetMappedPointer(
	void **devPtr, size_t *size, struct cudaGraphicsResource *resource) {
	cudaError_t result = cudaSuccess;
	_acquire();
	if (_devices.empty()) return _setLastError(cudaErrorNoDevice);
	
	report("cudaGraphicsResourceGetMappedPointer");
	
	*devPtr = _getDevice().getPointerToMappedGraphicsResource(*size, resource);	

	_release();
	
	return _setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsSubResourceGetMappedArray(
	struct cudaArray **arrayPtr, struct cudaGraphicsResource *resource, 
	unsigned int arrayIndex, unsigned int mipLevel) {
	assertM(false, "Not implemented.");
}


//////////////////////////////////////////////////////////////////////////////////////////////////

void cuda::CudaRuntime::addTraceGenerator( trace::TraceGenerator& gen, 
	bool persistent ) {

	_lock();
	HostThreadContext& thread = _threads[pthread_self()];
	if (persistent) {
		thread.persistentTraceGenerators.push_back(&gen);
	}
	else {
		thread.nextTraceGenerators.push_back(&gen);
	}
	_unlock();
}

void cuda::CudaRuntime::clearTraceGenerators() {
	_lock();
	HostThreadContext& thread = _threads[pthread_self()];
	thread.persistentTraceGenerators.clear();
	thread.nextTraceGenerators.clear();
	_unlock();
}

void cuda::CudaRuntime::limitWorkerThreads(unsigned int limit) {
	_acquire();
	for (DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device) {
		(*device)->limitWorkerThreads(limit);
	}
	_release();
}

void cuda::CudaRuntime::registerPTXModule(std::istream& ptx, 
	const std::string& name) {
	assertM(false, "registerPTXModule not implemented.");
}

void** cuda::CudaRuntime::getFatBinaryHandle(const std::string& name) {
	assertM(false, "getFatBinaryHandle not implemented.");
}

ocelot::KernelPointer cuda::CudaRuntime::getKernelPointer(
	const std::string& name, const std::string& module) {
	assertM(false, "getKernelPointer not implemented.");
}

void cuda::CudaRuntime::reset() {
	assertM(false, "reset not implemented.");
}

ocelot::PointerMap cuda::CudaRuntime::contextSwitch(unsigned int destination, 
	unsigned int source) {
	assertM(false, "contextSwitch not implemented.");
}

//////////////////////////////////////////////////////////////////////////////////////////////////

