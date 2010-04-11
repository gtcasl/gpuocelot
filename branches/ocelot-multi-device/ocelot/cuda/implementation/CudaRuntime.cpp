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
#include <ocelot/cuda/include/__cudaFatFormat.h>
#include <ocelot/cuda/interface/CudaRuntime.h>
#include <ocelot/cuda/interface/CudaDriver.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/executive/interface/ExecutableKernel.h>
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
#define REPORT_BASE 0

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Error handling macros

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

#if REPORT_BASE > 0
#define TestError(x) { if (x != cudaSuccess) { report("CUDA Error: " << __func__); } }
#else
#define TestError(x) {}
#endif

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

std::string cuda::CudaRuntime::formatError( const std::string& message ) {
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
	nextTraceGenerators(c.nextTraceGenerators)
{
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

//////////////////////////////////////////////////////////////////////////////////////////////////

void cuda::CudaRuntime::_memcpy(void* dst, const void* src, size_t count, 
	enum cudaMemcpyKind kind) {
	switch(kind) {
		case cudaMemcpyHostToHost: {
			memcpy(dst, src, count);
		}
		break;
		case cudaMemcpyDeviceToHost: {
			if (!getDevice().checkMemoryAccess(src, count)) {
				unlock();
				_memoryError(src, count);
			}
			
			executive::Device::MemoryAllocation* allocation = 
				getDevice().getMemoryAllocation(src);
			size_t offset = (char*)src - (char*)allocation->pointer();
			allocation->copy(dst, offset, count);
		}
		break;
		case cudaMemcpyDeviceToDevice: {
			if (!getDevice().checkMemoryAccess(src, count)) {
				unlock();
				_memoryError(src, count);
			}
			if (!getDevice().checkMemoryAccess(dst, count)) {
				unlock();
				_memoryError(dst, count);
			}
				
			executive::Device::MemoryAllocation* fromAllocation = 
				getDevice().getMemoryAllocation(src);
			executive::Device::MemoryAllocation* toAllocation =
				getDevice().getMemoryAllocation(dst);
			size_t fromOffset = (char*)src 
				- (char*)fromAllocation->pointer();
			size_t toOffset = (char*)dst - (char*)toAllocation->pointer();
			fromAllocation->copy(toAllocation, toOffset, fromOffset, count);
		}
		break;
		case cudaMemcpyHostToDevice: {
			if (!getDevice().checkMemoryAccess(dst, count)) {
				unlock();
				_memoryError(dst, count);
			}
			
			executive::Device::MemoryAllocation* allocation = 
				getDevice().getMemoryAllocation(dst);
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

}

cuda::CudaRuntime::CudaRuntime() : selectedDevice(-1), nextSymbol(1) {
	pthread_mutex_init(&mutex, 0);
	_enumerateDevices();
}

cuda::CudaRuntime::~CudaRuntime() {
	//
	// free things that need freeing
	//
	// devices
	for (DeviceVector::iterator device = devices.begin(); 
		device != devices.end(); ++device) {
		delete *device;
	}
	
	// mutex
	pthread_mutex_destroy(&mutex);
	
	// thread contexts
	
	// textures
	
	// kernels
	
	// fat binaries
	
	// globals
}

//! acquires mutex and locks the runtime
void cuda::CudaRuntime::lock() {
	pthread_mutex_lock(&mutex);
}

//! releases mutex
void cuda::CudaRuntime::unlock() {
	pthread_mutex_unlock(&mutex);
}


//! sets the last error state for the CudaRuntime object
cudaError_t cuda::CudaRuntime::setLastError(cudaError_t result) {
	HostThreadContext &thread = getHostThreadContext();
	thread.lastError = result;
	return result;
}

//! gets the context of a thread
cuda::HostThreadContext & cuda::CudaRuntime::getHostThreadContext() {
	pthread_t self = pthread_self();
	
	HostThreadContextMap::iterator it = threads.find(self);
	if (it == threads.end()) {
		it = threads.insert(std::make_pair(self, HostThreadContext())).first;
	}
	
	if (it->second.selectedDevice != selectedDevice) {
		if (selectedDevice >= 0) {
			assert(devices[selectedDevice]->selected());
			devices[selectedDevice]->unselect();
		}
		selectedDevice = it->second.selectedDevice;
		devices[selectedDevice]->select();
	}
	
	return it->second;
}

executive::Device& cuda::CudaRuntime::getDevice() {
	assert(selectedDevice > 0);
	assert(selectedDevice < (int)devices.size());
	return *devices[selectedDevice];
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	registers a CUDA fatbinary and returns a handle for referencing the fat binary
*/
void** cuda::CudaRuntime::cudaRegisterFatBinary(void *fatCubin) {
	size_t handle = 0;
	__cudaFatCudaBinary *binary = (__cudaFatCudaBinary *)fatCubin;
	
	lock();
	
	//! inserts thread context if not already exists
	getHostThreadContext();
	
	for (FatBinaryVector::const_iterator it = fatBinaries.begin();
		it != fatBinaries.end(); ++it) {
		if (std::string(it->name()) == binary->ident) {
			unlock();
		
			assert(0 && "binary already exists");		
			return 0;
		}	
	}

	assertM(binary->ptx->ptx != 0, "binary contains no PTX");

	// register associated PTX
	std::stringstream ptx( binary->ptx->ptx );
	ModuleMap::iterator module = modules.insert(
		std::make_pair(binary->ident, ir::Module())).first;
	module->second.load(ptx, binary->ident);
	
	FatBinaryContext cubinContext;
	cubinContext.cubin_ptr = fatCubin;
	fatBinaries.push_back(cubinContext);
	handle = fatBinaries.size();

	for(DeviceVector::iterator device = devices.begin(); 
		device != devices.end(); ++device) {
		(*device)->load(&module->second);
	}
	
	unlock();
	
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
	if (handle >= fatBinaries.size()) {
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

	size_t handle = (size_t)fatCubinHandle - 1;
	lock();

	std::string moduleName = fatBinaries[handle].name();
	
	globals[(void *)hostVar] = RegisteredGlobal(moduleName, deviceName);
	
	unlock();
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
	
	size_t handle = (size_t)fatCubinHandle - 1;
	
	lock();
	
	getHostThreadContext();

	std::string moduleName = fatBinaries[handle].name();
	
	report("cudaRegisterTexture('" << deviceName << ", dim: " << dim 
		<< ", norm: " << norm << ", ext: " << ext);

	textures[(void*)hostVar] = RegisteredTexture(moduleName, deviceName);
	
	ModuleMap::iterator module = modules.find(moduleName);
	assert(module != modules.end());
	
	ir::Module::TextureMap::iterator texture = module->second.textures.find(
		deviceName);
	assertM(texture != module->second.textures.end(), "cudaRegisterTexture - " 
		<< deviceName << " does not exist in module " << moduleName );
	
	texture->second.normalizedFloat = norm;
	
	unlock();
}

void cuda::CudaRuntime::cudaRegisterShared(
	void **fatCubinHandle,
	void **devicePtr) {
	
	size_t handle = (size_t)fatCubinHandle - 1;
	lock();
	
	const char *moduleName = fatBinaries[handle].name();
	const char *variableName = (const char *)devicePtr;
	
	report("cudaRegisterShared() - module " << moduleName << ", devicePtr: " << std::hex 
		<< devicePtr << std::dec << " named " << variableName);
	
	report(" Ignoring this variable.");
	
	unlock();
}

void cuda::CudaRuntime::cudaRegisterSharedVar(
	void **fatCubinHandle,
	void **devicePtr,
	size_t size,
	size_t alignment,
	int storage) {

	size_t handle = (size_t)fatCubinHandle - 1;
	lock();
	
	const char *moduleName = fatBinaries[handle].name();
	const char *variableName = (const char *)devicePtr;
	
	report("cudaRegisterSharedVar() - module " << moduleName 
		<< ", devicePtr: " << devicePtr << " named " << variableName 
		<< ", size: " << size << ", alignment: " << alignment << ", storage: " 
		<< storage);
	
	report(" Ignoring this variable.");
		
	unlock();
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

	size_t handle = (size_t)fatCubinHandle - 1;
	
	lock();

	getHostThreadContext();
		
	void *symbol = (void *)hostFun;
	std::string kernelName = deviceFun;
	std::string moduleName = fatBinaries[handle].name();
	
	kernels[symbol] = RegisteredKernel(handle, moduleName, kernelName);
	
	unlock();
}
		
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory allocation

cudaError_t cuda::CudaRuntime::cudaMalloc(void **devPtr, size_t size) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	getHostThreadContext();
	
	report("CudaRuntime::cudaMalloc( *devPtr = " << (void *)*devPtr 
		<< ", size = " << size << ")");

	try {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().allocate(size);
		*devPtr = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	unlock();

	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMallocHost(void **ptr, size_t size) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	
	report("CudaRuntime::cudaMallocHost( *pPtr = " << (void *)*ptr 
		<< ", size = " << size << ")");
	
	getHostThreadContext();
	
	try {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().allocateHost(size);
		*ptr = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMallocPitch(void **devPtr, size_t *pitch, 
	size_t width, size_t height) {
	cudaError_t result = cudaErrorMemoryAllocation;
	
	lock();
	
	getHostThreadContext();

	*pitch = width;
	report("CudaRuntime::cudaMallocPitch( *devPtr = " << (void *)*devPtr 
		<< ", pitch = " << *pitch << ")");

	try {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().allocate(width * height);
		dimensions[allocation->pointer()] = Dimension(width, height, 1);
		*devPtr = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMallocArray(struct cudaArray **array, 
	const struct cudaChannelFormatDesc *desc, size_t width, size_t height) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();

	report("CudaRuntime::cudaMallocArray( *array = " << (void *)*array << ")");
	
	size_t size = width * height * ( desc->x 
		+ desc->y + desc->z + desc->w ) / 8;
	
	getHostThreadContext();

	try {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().allocate(size);
		dimensions[allocation->pointer()] = Dimension(width, height, 1);
		*array = (struct cudaArray*)allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFree(void *devPtr) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	report("cudaFree(" << devPtr << ")");
	
	getHostThreadContext();
	
	try {
		if (devPtr) {
			getDevice().free(devPtr);
		}
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}
	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFreeHost(void *ptr) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	report("cudaFreeHost(" << ptr << ")");
	
	getHostThreadContext();
	
	try {
		if (ptr) {
			getDevice().free(ptr);
		}
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFreeArray(struct cudaArray *array) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	getHostThreadContext();

	try {
		if (array) {
			getDevice().free(array);
		}
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	report("CudaRuntime::cudaFreeArray() array = " << (void *)array);

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMalloc3D(struct cudaPitchedPtr* devPtr, 
	struct cudaExtent extent) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();

	report("CudaRuntime::cudaMalloc3D() extent - width " << extent.width 
		<< " - height " << extent.height << " - depth " << extent.depth );
	getHostThreadContext();

	devPtr->pitch = 0;
	devPtr->xsize = extent.width;
	devPtr->ysize = extent.height * extent.depth;
	
	size_t size = devPtr->xsize * devPtr->ysize;

	try {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().allocate(size);
		devPtr->ptr = allocation->pointer();
		dimensions[allocation->pointer()] = Dimension(extent.width, 
			extent.height, extent.depth);
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}
	
	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMalloc3DArray(struct cudaArray** arrayPtr, 
	const struct cudaChannelFormatDesc* desc, struct cudaExtent extent) {

	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	getHostThreadContext();

	size_t size = extent.width * extent.height * extent.depth * ( desc->x 
		+ desc->y + desc->z + desc->w ) / 8;

	try {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().allocate(size);
		*arrayPtr = (struct cudaArray*)allocation->pointer();
		dimensions[allocation->pointer()] = Dimension(extent.width, 
			extent.height, extent.depth, *desc);
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
	
	}

	report("cudaMalloc3DArray() - *arrayPtr = " << (void *)(*arrayPtr));

	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaHostAlloc(void **pHost, size_t bytes, 
	unsigned int flags) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	getHostThreadContext();

	try {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().allocateHost(bytes, flags);
		*pHost = allocation->pointer();
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {
		
	}

	report("cudaHostAlloc() - *pHost = " << (void *)(*pHost) 
		<< ", bytes " << bytes << ", " << flags);

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaHostGetDevicePointer(void **pDevice, 
	void *pHost, unsigned int flags) {

	cudaError_t result = cudaErrorInvalidHostPointer;
	lock();
	getHostThreadContext();

	executive::Device::MemoryAllocation* 
		allocation = getDevice().getMemoryAllocation(pHost);

	if (allocation != 0) {	
		if (allocation->host()) {
			size_t offset = (char*)pHost - (char*)allocation->mappedPointer();
			*pDevice = (char*)allocation->mappedPointer() + offset;
			result = cudaSuccess;
		}
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaHostGetFlags(unsigned int *pFlags, 
	void *pHost) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	getHostThreadContext();

	executive::Device::MemoryAllocation* 
		allocation = getDevice().getMemoryAllocation(pHost);
	
	if (allocation != 0) {
		*pFlags = allocation->flags();
	}

	unlock();
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory copying

cudaError_t cuda::CudaRuntime::cudaMemcpy(void *dst, const void *src, 
	size_t count, enum cudaMemcpyKind kind) {
	cudaError_t result = cudaErrorInvalidDevicePointer;
	if (kind >= 0 && kind <= 3) {
		lock();
		getHostThreadContext();

		report("cudaMemcpy(" << dst << ", " << src << ", " << count << ")");
		_memcpy(dst, src, count, kind);
		unlock();
	}
	else {
		result = cudaErrorInvalidMemcpyDirection;
	}

	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyToSymbol(const char *symbol, 
	const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind) {
	report("cuda::CudaRuntime::cudaMemcpyToSymbol('" << symbol << "' - " 
		<< (void *)symbol << " - value " 
		<< hydrazine::dataToString(src, count));

	cudaError_t result = cudaErrorInvalidDevicePointer;
	lock();
	
	getHostThreadContext();

	RegisteredGlobalMap::iterator global = globals.find((void*)symbol);
	std::string name;
	std::string module;
	
	if (global == globals.end()) {
		name = symbol;	
	}
	else {
		name = global->second.global;
		module = global->second.module;
	}

	executive::Device::MemoryAllocation* allocation = 
		getDevice().getGlobalAllocation(module, name);

	if (allocation != 0) {
		if (!getDevice().checkMemoryAccess((char*)src + offset, count)) {
			unlock();
			_memoryError((char*)src + offset, count);
		}
	
		allocation->copy(offset, src, count);
		result = cudaSuccess;
	}
	
	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyFromSymbol(void *dst, 
	const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind) {
	report("cuda::CudaRuntime::cudaMemcpyFromSymbol('" << symbol << "' - " 
		<< (void *)symbol << " - value " 
		<< hydrazine::dataToString(dst, count));

	cudaError_t result = cudaErrorInvalidDevicePointer;
	lock();
	
	getHostThreadContext();

	RegisteredGlobalMap::iterator global = globals.find((void*)symbol);
	std::string name;
	std::string module;
	
	if (global == globals.end()) {
		name = symbol;	
	}
	else {
		name = global->second.global;
		module = global->second.module;
	}

	executive::Device::MemoryAllocation* allocation = 
		getDevice().getGlobalAllocation(module, name);

	if (allocation != 0) {
		if (!getDevice().checkMemoryAccess((char*)dst + offset, count)) {
			_memoryError((char*)dst + offset, count);
		}
	
		allocation->copy(dst, offset, count);
		result = cudaSuccess;
	}
		
	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyAsync(void *dst, const void *src, 
	size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
	return cudaMemcpy(dst, src, count, kind);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyToArray(struct cudaArray *dst, 
	size_t wOffset, size_t hOffset, const void *src, size_t count, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue ;
	lock();
	getHostThreadContext();

	report("cudaMemcpyToArray()");

	if (kind == cudaMemcpyHostToDevice) {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().getMemoryAllocation(dst);

		if (allocation != 0) {
			Dimension& dimension = dimensions[allocation->pointer()];
			size_t offset = wOffset + hOffset * dimension.x;
			void* address = (char*)allocation->pointer() + offset;
			if (!getDevice().checkMemoryAccess(address, count)) {
				unlock();
				_memoryError(address, count);
			}
			allocation->copy(offset, src, count);
			result = cudaSuccess;
		}
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* 
			destination = getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* 
			source = getDevice().getMemoryAllocation(src);
		if (destination != 0 && source != 0) {
			Dimension& dimension = dimensions[destination->pointer()];
			size_t offset = wOffset + hOffset * dimension.x;
			void* address = (char*)destination->pointer() + offset;
			if (!getDevice().checkMemoryAccess(address, count)) {
				unlock();
				_memoryError(address, count);
			}
			if (!getDevice().checkMemoryAccess(src, count)) {
				unlock();
				_memoryError(src, count);
			}
			destination->copy(source, offset, 0, count);
			result = cudaSuccess;
		}
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyFromArray(void *dst, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue ;
	lock();
	getHostThreadContext();

	report("cudaMemcpyFromArray()");

	if (kind == cudaMemcpyDeviceToHost) {
		executive::Device::MemoryAllocation* 
			allocation = getDevice().getMemoryAllocation(src);

		if (allocation != 0) {
			Dimension& dimension = dimensions[allocation->pointer()];
			size_t offset = wOffset + hOffset * dimension.x;
			void* address = (char*)allocation->pointer() + offset;
			if (!getDevice().checkMemoryAccess(address, count)) {
				unlock();
				_memoryError(address, count);
			}
			allocation->copy((void*)src, offset, count);
			result = cudaSuccess;
		}
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* 
			destination = getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* 
			source = getDevice().getMemoryAllocation(src);
		if (destination != 0 && source != 0) {
			Dimension& dimension = dimensions[source->pointer()];
			size_t offset = wOffset + hOffset * dimension.x;
			void* address = (char*)destination->pointer() + offset;
			if (!getDevice().checkMemoryAccess(address, count)) {
				unlock();
				_memoryError(address, count);
			}
			if (!getDevice().checkMemoryAccess(dst, count)) {
				unlock();
				_memoryError(src, count);
			}
			destination->copy(source, 0, offset, count);
			result = cudaSuccess;
		}
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyArrayToArray(struct cudaArray *dst, 
	size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, 
	size_t wOffsetSrc, size_t hOffsetSrc, size_t count, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	report("cudaMemcpyArrayToArray()");

	lock();
	
	if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* 
			destination = getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* 
			source = getDevice().getMemoryAllocation(src);
		if (destination != 0 && source != 0) {
			Dimension& sourceDimension = dimensions[source->pointer()];
			Dimension& destinationDimension = 
				dimensions[destination->pointer()];
			size_t sourceOffset = wOffsetSrc + hOffsetSrc * sourceDimension.x;
			size_t destinationOffset = wOffsetDst 
				+ hOffsetDst * destinationDimension.x;
			void* sourceAddress = (char*)source->pointer() + sourceOffset;
			void* destinationAddress = (char*)destination->pointer() 
				+ destinationOffset;
			if (!getDevice().checkMemoryAccess(sourceAddress, count)) {
				unlock();
				_memoryError(sourceAddress, count);
			}
			if (!getDevice().checkMemoryAccess(destinationAddress, count)) {
				unlock();
				_memoryError(destinationAddress, count);
			}
			destination->copy(source, destinationOffset, sourceOffset, count);
			result = cudaSuccess;
		}	
	}
	
	unlock();
	return setLastError(result);	
}

/*!
	\brief perform a 2D memcpy from a dense buffer
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2D(void *dst, size_t dpitch, 
	const void *src, size_t spitch, size_t width, size_t height, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	getHostThreadContext();

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
				getDevice().getMemoryAllocation(src);
			if (source != 0) {
				for (size_t row = 0; row < height; row++) {
					void* dstPtr = (char *)dst + dpitch * row;
					size_t srcOffset = spitch * row;

					if (!getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcOffset, width)) {
						unlock();
						_memoryError((char*)source->pointer() + srcOffset, 
							width);
					}
					
					source->copy(dstPtr, srcOffset, width);
				}
				result = cudaSuccess;
			}
			else {
				unlock();
				_memoryError(src, width * height);
			}
		}
		break;		
		case cudaMemcpyHostToDevice:
		{
			executive::Device::MemoryAllocation* destination = 
				getDevice().getMemoryAllocation(dst);
			size_t dstPitch = dimensions[destination->pointer()].x;
			if (destination != 0) {
				for (size_t row = 0; row < height; row++) {
					void* srcPtr = (char *)src + spitch * row;
					size_t dstOffset = dstPitch * row;

					if (!getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstOffset, width)) {
						unlock();
						_memoryError((char*)destination->pointer() + dstOffset, 
							width);
					}
					
					destination->copy(dstOffset, srcPtr, width);
				}
				result = cudaSuccess;
			}
			else {
				unlock();
				_memoryError(dst, width * height);
			}
		}
		break;
		case cudaMemcpyDeviceToDevice:
		{
			executive::Device::MemoryAllocation* destination = 
				getDevice().getMemoryAllocation(dst);
			executive::Device::MemoryAllocation* source = 
				getDevice().getMemoryAllocation(src);
			if (destination != 0 && source != 0) {
				for (size_t row = 0; row < height; row++) {
					size_t srcOffset = spitch * row;
					size_t dstOffset = dpitch * row;

					if (!getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstOffset, width)) {
						unlock();
						_memoryError((char*)destination->pointer() + dstOffset, 
							width);
					}
					if (!getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcOffset, width)) {
						unlock();
						_memoryError((char*)source->pointer() + srcOffset, 
							width);
					}
					
					destination->copy(source, dstOffset, srcOffset, width);
				}
				result = cudaSuccess;
			}
			else {
				unlock();
				if (destination == 0) {
					_memoryError(dst, width * height);
				}
				else {
					_memoryError(src, width * height);
				}
			}
		}
		break;
		default: break;
	}
	
	unlock();
	return setLastError(result);	
}

/*!
	\brief perform a 2D memcpy to an array
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2DToArray(struct cudaArray *dst, 
	size_t wOffset, size_t hOffset, const void *src, size_t spitch, 
	size_t width, size_t height, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	getHostThreadContext();

	report("cudaMemcpy2DtoArray(dst = " << (void *)dst 
		<< ", src = " << (void *)src);
	
	if (kind == cudaMemcpyHostToDevice) {
		executive::Device::MemoryAllocation* destination = 
			getDevice().getMemoryAllocation(dst);
		
		if (destination == 0) {
			unlock();
			_memoryError(dst, width * height);
		}
		
		size_t dstPitch = dimensions[destination->pointer()].x;

		for (size_t row = 0; row < height; ++row) {
			void* srcPtr = (char*)src + row * spitch;
			size_t dstOffset = (row + hOffset) * dstPitch + wOffset;
			
			if (!getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				unlock();
				_memoryError((char*)destination->pointer() + dstOffset, width);
			}
			
			destination->copy(dstOffset, srcPtr, width);
		}
		
		result = cudaSuccess;
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* destination = 
			getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* source = 
			getDevice().getMemoryAllocation(src);
		
		if (destination == 0) {
			unlock();
			_memoryError(dst, width * height);
		}

		if (source == 0) {
			unlock();
			_memoryError(src, width * height);
		}
		
		size_t dstPitch = dimensions[destination->pointer()].x;
		
		for (size_t row = 0; row < height; ++row) {
			size_t srcOffset = row * spitch;
			size_t dstOffset = (row + hOffset) * dstPitch + wOffset;
			
			if (!getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				unlock();
				_memoryError((char*)destination->pointer() 
					+ dstOffset, width);
			}

			if (!getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				unlock();
				_memoryError((char*)source->pointer() + srcOffset, width);
			}
			
			destination->copy(source, dstOffset, srcOffset, width);
		}
		
		result = cudaSuccess;
	}
	
	unlock();
	return setLastError(result);
}

/*!
	\brief perform a 2D memcpy from an array
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2DFromArray(void *dst, size_t dpitch, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, 
	size_t height, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	getHostThreadContext();

	report("cudaMemcpy2DfromArray(dst = " << (void *)dst 
		<< ", src = " << (void *)src);
	
	if (kind == cudaMemcpyDeviceToHost) {
		executive::Device::MemoryAllocation* source = 
			getDevice().getMemoryAllocation(dst);
		
		if (source == 0) {
			unlock();
			_memoryError(src, width * height);
		}
		
		assert(dimensions.count(source->pointer()) != 0);
		size_t srcPitch = dimensions[source->pointer()].x;

		for (size_t row = 0; row < height; ++row) {
			void* dstPtr = (char*)dst + row * dpitch;
			size_t srcOffset = (row + hOffset) * srcPitch + wOffset;
			
			if (!getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				unlock();
				_memoryError((char*)source->pointer() 
					+ srcOffset, width);
			}
			
			source->copy(dstPtr, srcOffset, width);
		}
		
		result = cudaSuccess;
	}
	else if (kind == cudaMemcpyDeviceToDevice) {
		executive::Device::MemoryAllocation* destination = 
			getDevice().getMemoryAllocation(dst);
		executive::Device::MemoryAllocation* source = 
			getDevice().getMemoryAllocation(src);
		
		if (destination == 0) {
			unlock();
			_memoryError(dst, width * height);
		}

		if (source == 0) {
			unlock();
			_memoryError(src, width * height);
		}
		
		size_t srcPitch = dimensions[source->pointer()].x;
		
		for (size_t row = 0; row < height; ++row) {
			size_t dstOffset = row * dpitch;
			size_t srcOffset = (row + hOffset) * srcPitch + wOffset;
			
			if (!getDevice().checkMemoryAccess((char*)destination->pointer() 
				+ dstOffset, width)) {
				unlock();
				_memoryError((char*)destination->pointer() 
					+ dstOffset, width);
			}

			if (!getDevice().checkMemoryAccess((char*)source->pointer() 
				+ srcOffset, width)) {
				unlock();
				_memoryError((char*)source->pointer() + srcOffset, width);
			}
			
			source->copy(destination, srcOffset, dstOffset, width);
		}
		
		result = cudaSuccess;
	}
	
	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpy3D(const struct cudaMemcpy3DParms *p) {

	cudaError_t result = cudaErrorInvalidValue;

	cudaPitchedPtr dst;
	cudaPitchedPtr src;
	const cudaExtent& extent = p->extent;

	if (p->dstArray) {
		dst.ptr = (void *)p->dstArray;
		dst.pitch = 0;
		dst.xsize = dimensions[p->dstArray].x;
		dst.ysize = dimensions[p->dstArray].y;		
	}
	else {
		dst = p->dstPtr;
	}

	if (p->srcArray) {
		src.ptr = (void *)p->srcArray;
		src.pitch = 0;
		src.xsize = dimensions[p->srcArray].x;
		src.ysize = dimensions[p->srcArray].y;
	}
	else {
		src = p->srcPtr;
	}

	lock();
	getHostThreadContext();

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
				getDevice().getMemoryAllocation(dst.ptr);
			
			if (destination == 0) {
				unlock();
				_memoryError(dst.ptr, extent.width 
					* extent.height * extent.depth);
			}
			
			for (size_t z = 0; z < extent.depth; ++z) {
				for (size_t y = 0; y < extent.height; ++y) {
					size_t dstPtr = p->dstPos.x + dst.xsize 
						* ((p->dstPos.y+y) + (z+p->dstPos.z) * dst.ysize);
					void* srcPtr = (char*)src.ptr + p->srcPos.x + src.xsize 
						* ((p->srcPos.y+y) + (z+p->srcPos.z) * src.ysize);

					if (!getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstPtr, extent.width)) {
						unlock();
						_memoryError((char*)destination->pointer() + dstPtr, 
							extent.width);
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
				getDevice().getMemoryAllocation(src.ptr);
			
			if (source == 0) {
				unlock();
				_memoryError(src.ptr, extent.width 
					* extent.height * extent.depth);
			}
			
			for (size_t z = 0; z < extent.depth; ++z) {
				for (size_t y = 0; y < extent.height; ++y) {
					void* dstPtr = (char*)dst.ptr + p->dstPos.x + dst.xsize 
						* ((p->dstPos.y+y) + (z+p->dstPos.z) * dst.ysize);
					size_t srcPtr = p->srcPos.x + src.xsize 
						* ((p->srcPos.y+y) + (z+p->srcPos.z) * src.ysize);

					if (!getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcPtr, extent.width)) {
						unlock();
						_memoryError((char*)source->pointer() + srcPtr, 
							extent.width);
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
				getDevice().getMemoryAllocation(src.ptr);
			
			if (source == 0) {
				unlock();
				_memoryError(src.ptr, extent.width 
					* extent.height * extent.depth);
			}

			executive::Device::MemoryAllocation* destination = 
				getDevice().getMemoryAllocation(dst.ptr);
			
			if (destination == 0) {
				unlock();
				_memoryError(dst.ptr, extent.width 
					* extent.height * extent.depth);
			}
			
			for (size_t z = 0; z < extent.depth; ++z) {
				for (size_t y = 0; y < extent.height; ++y) {
					size_t dstPtr = p->dstPos.x + dst.xsize 
						* ((p->dstPos.y+y) + (z+p->dstPos.z) * dst.ysize);
					size_t srcPtr = p->srcPos.x + src.xsize 
						* ((p->srcPos.y+y) + (z+p->srcPos.z) * src.ysize);

					if (!getDevice().checkMemoryAccess(
						(char*)source->pointer() + srcPtr, extent.width)) {
						unlock();
						_memoryError((char*)source->pointer() + srcPtr,
							extent.width);
					}

					if (!getDevice().checkMemoryAccess(
						(char*)destination->pointer() + dstPtr, extent.width)) {
						unlock();
						_memoryError((char*)destination->pointer() + dstPtr, 
							extent.width);
					}

					source->copy(destination, dstPtr, srcPtr, extent.width);
				}
			}
			result = cudaSuccess;
		}
		break;
	}
	
	unlock();
	return setLastError(result);	
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
	
	lock();
	getHostThreadContext();
	
	executive::Device::MemoryAllocation* allocation = 
		getDevice().getMemoryAllocation(devPtr);
	
	if (allocation == 0) {
		unlock();
		_memoryError(devPtr, count);
	}
	
	if (!getDevice().checkMemoryAccess(devPtr, count)) {
		unlock();
		_memoryError(devPtr, count);		
	}
	
	size_t offset = (char*)devPtr - (char*)allocation->pointer();
	
	allocation->memset(offset, value, count);
	result = cudaSuccess;
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemset2D(void *devPtr, size_t pitch, 
	int value, size_t width, size_t height) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	getHostThreadContext();

	executive::Device::MemoryAllocation* allocation = 
		getDevice().getMemoryAllocation(devPtr);
	
	if (allocation == 0) {
		unlock();
		_memoryError(devPtr, width * height);
	}
		
	size_t offset = (char*)devPtr - (char*)allocation->pointer();
	
	if (pitch == width) {
		if (!getDevice().checkMemoryAccess(devPtr, width * height)) {
			unlock();
			_memoryError(devPtr, width * height);
		}
		
		allocation->memset(offset, value, pitch * height);
	}
	else {
		for (size_t i = 0; i < height; i++) {
			size_t ptr = offset + pitch * i;
			void* address = (char*)allocation->pointer() + ptr;
			if (!getDevice().checkMemoryAccess(address, width)) {
				unlock();
				_memoryError(address, width);
			}
		
			allocation->memset(ptr, value, width);
		}
	}

	result = cudaSuccess;
	
	unlock();
	return setLastError(result);	
}


cudaError_t cuda::CudaRuntime::cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr,
	int value, struct cudaExtent extent) {

	cudaError_t result = cudaErrorNotYetImplemented;
	lock();
	getHostThreadContext();

	assert(0 && "unimplemented");
	
	return setLastError(result);	
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
	lock();
	getHostThreadContext();
	
	RegisteredGlobalMap::iterator global = globals.find((void*)symbol);
	
	std::string name;
	std::string module;
	
	if (global != globals.end()) {
		name = global->second.global;
		module = global->second.module;
	}
	else {
		name = symbol;
	}
	
	executive::Device::MemoryAllocation* 
		allocation = getDevice().getGlobalAllocation(module, name);
	assertM(allocation != 0, "Invalid global name " << name 
		<< " in module " << module);

	*devPtr = allocation->pointer();
	report("devPtr: " << *devPtr);	
	
	unlock();
	return setLastError(result);	
}

cudaError_t cuda::CudaRuntime::cudaGetSymbolSize(size_t *size, const char *symbol) {
	cudaError_t result = cudaSuccess;
	report("cuda::CudaRuntime::cudaGetSymbolSize(" << size << ", " 
		<< (void*) symbol << ")");
	lock();
	getHostThreadContext();
	
	RegisteredGlobalMap::iterator global = globals.find((void*)symbol);
	
	std::string name;
	std::string module;
	
	if (global != globals.end()) {
		name = global->second.global;
		module = global->second.module;
	}
	else {
		name = symbol;
	}
	
	executive::Device::MemoryAllocation* 
		allocation = getDevice().getGlobalAllocation(module, name);
	assertM(allocation != 0, "Invalid global name " << name 
		<< " in module " << module);

	*size = allocation->size();
	report("size: " << *size);	
	
	unlock();
	return setLastError(result);	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetDeviceCount(int *count) {
	cudaError_t result = cudaSuccess;
	lock();
	
	*count = devices.size();
	
	unlock();
	TestError(result);
	return setLastError(result);
}

#define minimum(x, y) ((x) > (y) ? (y) : (x))

cudaError_t cuda::CudaRuntime::cudaGetDeviceProperties(struct cudaDeviceProp *prop, int dev) {
	cudaError_t result = cudaSuccess;
	
	lock();
	if (dev < (int)devices.size()) {
		const executive::Device& device = *devices[dev];
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
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaChooseDevice(int *device, 
	const struct cudaDeviceProp *prop) {
	cudaError_t result = cudaSuccess;
	*device = getDevice().properties().guid;
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetDevice(int device) {
	cudaError_t result = cudaErrorSetOnActiveProcess;
	
	lock();
	if ((int)devices.size() <= device) {
		result = cudaErrorInvalidDevice;
	}
	else {
		HostThreadContext& thread = getHostThreadContext();
		if (thread.selectedDevice != device) {
			assert(devices[thread.selectedDevice]->selected());
			devices[thread.selectedDevice]->unselect();
			selectedDevice = device;
			thread.selectedDevice = device;
			devices[thread.selectedDevice]->select();
		}
		result = cudaSuccess;
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGetDevice(int *device) {
	cudaError_t result = cudaSuccess;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();
	*device = thread.selectedDevice;
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetValidDevices(int *device_arr, int len) {
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext& thread = getHostThreadContext();
	thread.validDevices.resize(len);
	for (int i = 0 ; i < len; i++) {
		thread.validDevices[i] = device_arr[i];
	}
	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetDeviceFlags(int flags) {
	cudaError_t result = cudaSuccess;
	lock();
	getDevice().setDeviceFlags(flags);
	unlock();
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! binds a texture to a reference and a CUDA memory block
cudaError_t cuda::CudaRuntime::cudaBindTexture(size_t *offset, 
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t size) {

	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	getHostThreadContext();

	try {
		getDevice().bindTexture((void*)devPtr, (void*)texref, *desc, size);
		*offset = 0;
	}
	catch(hydrazine::Exception& e) {
		
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaBindTexture2D(size_t *offset,
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t width, 
	size_t height, size_t pitch) {
	cudaError_t result = cudaErrorInvalidValue;
	assert(pitch != 0);

	lock();
	getHostThreadContext();

	try {
		getDevice().bindTexture((void*)devPtr, (void*)texref, 
			*desc, width * height);
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {

	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaBindTextureToArray(
	const struct textureReference *texref, const struct cudaArray *array, 
	const struct cudaChannelFormatDesc *desc) {
	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	getHostThreadContext();

	report("cudaBindTextureToArray() - texref = '" << texref << "', array = " 
		<< (void *)array << " - format: " << desc->f << " (" << desc->x 
		<< ", " << desc->y << ", " << desc->z << ")");

	DimensionMap::iterator dimension = dimensions.find((void*)array);
	assert(dimension != dimensions.end());

	size_t size = dimension->second.x * dimension->second.y 
		* dimension->second.z;

	try {
		getDevice().bindTexture((void*)array, (void*)texref, *desc, size);
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {

	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaUnbindTexture(
	const struct textureReference *texref) {
	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	getHostThreadContext();

	try {
		getDevice().unbindTexture((void*)texref);
		result = cudaSuccess;
	}
	catch(hydrazine::Exception& e) {

	}

	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGetTextureAlignmentOffset(size_t *offset, 
	const struct textureReference *texref) {
	*offset = 0;
	return setLastError(cudaSuccess);
}

cudaError_t cuda::CudaRuntime::cudaGetTextureReference(
	const struct textureReference **texref, const char *symbol) {
	cudaError_t result = cudaErrorInvalidTexture;
	lock();
	
	RegisteredTextureMap::iterator it = textures.find((void*)symbol);
	if (it != textures.end()) {
		*texref = (const struct textureReference*)
			getDevice().getTextureReference(it->second.module, 
			it->second.texture);
		result = cudaSuccess;
	}
	
	unlock();
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetChannelDesc(
	struct cudaChannelFormatDesc *desc, const struct cudaArray *array) {
	cudaError_t result = cudaErrorInvalidValue;

	lock();
	getHostThreadContext();

	DimensionMap::iterator dimension = dimensions.find((void*)array);
	
	if (dimension != dimensions.end()) {
		*desc = dimension->second.format;
		result = cudaSuccess;
	}
	
	unlock();
	return setLastError(result);
}

struct cudaChannelFormatDesc cuda::CudaRuntime::cudaCreateChannelDesc(int x, 
	int y, int z, int w, enum cudaChannelFormatKind f) {

	struct cudaChannelFormatDesc desc;
	desc.w = w; desc.x = x; desc.y = y; desc.z = z; desc.f = f;
	return desc;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetLastError(void) {
	HostThreadContext &thread = getHostThreadContext();
	return thread.lastError;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
	
cudaError_t cuda::CudaRuntime::cudaConfigureCall(dim3 gridDim, dim3 blockDim, 
	size_t sharedMem, cudaStream_t stream) {

	lock();
	report("cudaConfigureCall()");
	
	cudaError_t result = cudaErrorInvalidConfiguration;
	HostThreadContext &thread = getHostThreadContext();
	
	KernelLaunchConfiguration launch(gridDim, blockDim, sharedMem, stream);
	thread.launchConfigurations.push_back(launch);
	result = cudaSuccess;
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetupArgument(const void *arg, size_t size, 
	size_t offset) {
	cudaError_t result = cudaSuccess;
	
	lock();
	
	HostThreadContext& thread = getHostThreadContext();

	report("cudaSetupArgument() - offset " << offset << ", size " << size);
	
	memcpy(thread.parameterBlock + offset, arg, size);
	
	thread.parameterIndices.push_back(offset);
	thread.parameterSizes.push_back(size);
	
	unlock();
	
	return setLastError(result);
}

static ir::Dim3 convert(const dim3& d) {
	return std::move(ir::Dim3(d.x, d.y, d.z));
}

cudaError_t cuda::CudaRuntime::cudaLaunch(const char *entry) {
	lock();
	
	cudaError_t result = cudaSuccess;
	HostThreadContext& thread = getHostThreadContext();
	
	assert(thread.launchConfigurations.size());
	
	KernelLaunchConfiguration launch(thread.launchConfigurations.back());
	thread.launchConfigurations.pop_back();
	
	RegisteredKernelMap::iterator kernel = kernels.find((void*)entry);
	assert(kernel != kernels.end());
	std::string moduleName = kernel->second.module;
	std::string kernelName = kernel->second.kernel;

	ModuleMap::iterator module = modules.find(moduleName);
	assert(module != modules.end());
	
	ir::Kernel* k = module->second.getKernel(kernelName);
	assert(k != 0);

	thread.mapParameters(k);
	
	report("CudaRuntime::cudaLaunch(" << kernelName 
		<< ") on thread " << pthread_self());
	
	try {
		trace::TraceGeneratorVector traceGens;

		if (api::OcelotConfiguration::getTrace().enabled) {
			traceGens = thread.persistentTraceGenerators;
			traceGens.insert(traceGens.end(), 
				thread.nextTraceGenerators.begin(), 
				thread.nextTraceGenerators.end());
		}

		getDevice().launch(moduleName, kernelName, convert(launch.gridDim), 
			convert(launch.blockDim), launch.sharedMemory, 
			thread.parameterBlock, thread.parameterBlockSize, traceGens);
		report(" launch completed successfully");	
	}
	catch( const executive::RuntimeException& e ) {
		std::cerr << "==Ocelot== Emulator failed to run kernel \"" 
			<< kernelName 
			<< "\" with exception: \n";
		std::cerr << formatError( e.toString() ) 
			<< "\n" << std::flush;
		thread.lastError = cudaErrorLaunchFailure;
		throw e;
	}

	unlock();
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaFuncGetAttributes(
	struct cudaFuncAttributes *attr, const char *symbol) {
	cudaError_t result = cudaErrorInvalidDeviceFunction;
		
	lock();
	getHostThreadContext();
	
	//
	// go find the kernel and fill out its attributes
	//
	RegisteredKernelMap::iterator kernel = kernels.find((void*)symbol);
	if (kernel != kernels.end()) {
		*attr = getDevice().getAttributes(kernel->second.module, 
			kernel->second.kernel);
	}
	
	unlock();
	
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// CUDA event creation

cudaError_t cuda::CudaRuntime::cudaEventCreate(cudaEvent_t *event) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	
	*event = getDevice().createEvent( 0 );
	
	unlock();

	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventCreateWithFlags(cudaEvent_t *event, 
	int flags) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	
	*event = getDevice().createEvent(flags);
	
	unlock();

	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventRecord(cudaEvent_t event, 
	cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	
	getDevice().recordEvent(event, stream);
	
	unlock();	
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventQuery(cudaEvent_t event) {
	cudaError_t result = cudaErrorInvalidValue;

	lock();
	getHostThreadContext();
	
	getDevice().queryEvent(event);

	unlock();

	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventSynchronize(cudaEvent_t event) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	
	getDevice().synchronizeEvent(event);
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventDestroy(cudaEvent_t event) {
	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	getHostThreadContext();
	
	getDevice().destroyEvent(event);
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventElapsedTime(float *ms, 
	cudaEvent_t start, cudaEvent_t end) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	
	*ms = getDevice().getEventTime(start, end);
	
	unlock();
	
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// CUDA streams
//

cudaError_t cuda::CudaRuntime::cudaStreamCreate(cudaStream_t *pStream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	
	*pStream = getDevice().createStream();
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamDestroy(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	
	getDevice().destroyStream(stream);
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamSynchronize(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;

	lock();
	getHostThreadContext();
	
	getDevice().synchronizeStream(stream);
	
	unlock();

	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamQuery(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;

	lock();
	getHostThreadContext();
	
	getDevice().queryStream(stream);
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaThreadExit(void) {
	cudaError_t result = cudaSuccess;
	
	// this is not required because state is shared across threads in Ocelot
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaThreadSynchronize(void) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	getDevice().synchronize();

	unlock();
	
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGLMapBufferObject(void **devPtr, 
	GLuint bufObj) {
	return cudaGLMapBufferObjectAsync(devPtr, bufObj, 0);
}

cudaError_t cuda::CudaRuntime::cudaGLMapBufferObjectAsync(void **devPtr, 
	GLuint bufObj, cudaStream_t stream) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();

	report("cudaGLMapBufferObjectAsync()");
	getDevice().mapGraphicsResource(devPtr, bufObj, stream);
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLRegisterBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();

	report("cudaGLRegisterBufferObject(" << bufObj << ")");	
	getDevice().glRegisterBuffer(bufObj, 0);
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLSetBufferObjectMapFlags(GLuint bufObj, 
	unsigned int flags) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();

	report("cudaGLRegisterBufferObjectMapFlags(" << bufObj << ")");	
	getDevice().glRegisterBuffer(bufObj, flags);
	
	unlock();
	
	return setLastError(result);

}

cudaError_t cuda::CudaRuntime::cudaGLSetGLDevice(int device) {
	report("cudaGLSetGLDevice(" << device << ")");
	return cudaSuccess;
}

cudaError_t cuda::CudaRuntime::cudaGLUnmapBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	
	report("cudaGLUnmapBufferObject(" << bufObj << ")");
	
	getDevice().unmapGraphicsResource((void*)bufObj);
	
	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLUnmapBufferObjectAsync(GLuint bufObj, 
	cudaStream_t stream) {
	assert(0 && "unimplemented");
}

cudaError_t cuda::CudaRuntime::cudaGLUnregisterBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	
	report("cudaGLUnregisterBufferObject");
	
	getDevice().unRegisterGraphicsResource((void*)bufObj);	

	unlock();
	
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGraphicsUnregisterResource(
	struct cudaGraphicsResource *resource) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	
	report("cudaGraphicsUnregisterResource");
	
	getDevice().unRegisterGraphicsResource(resource);	

	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsResourceSetMapFlags(
	struct cudaGraphicsResource *resource, unsigned int flags) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	
	report("cudaGraphicsResourceSetMapFlags");
	
	getDevice().setGraphicsResourceFlags(resource, flags);	

	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsMapResources(int count, 
	struct cudaGraphicsResource **resource, cudaStream_t stream) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	
	report("mapGraphicsResource");
	
	getDevice().mapGraphicsResource(resource, count, stream);	

	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsUnmapResources(int count, 
	struct cudaGraphicsResource **resources, cudaStream_t stream) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	
	report("cudaGraphicsUnmapResources");
	
	getDevice().mapGraphicsResource(resources, count, stream);	

	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsResourceGetMappedPointer(
	void **devPtr, size_t *size, struct cudaGraphicsResource *resource) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	
	report("cudaGraphicsResourceGetMappedPointer");
	
	*devPtr = getDevice().getPointerToMappedGraphicsResource(*size, resource);	

	unlock();
	
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGraphicsSubResourceGetMappedArray(
	struct cudaArray **arrayPtr, struct cudaGraphicsResource *resource, 
	unsigned int arrayIndex, unsigned int mipLevel) {
	assertM(false, "Not implemented.");
}


//////////////////////////////////////////////////////////////////////////////////////////////////

void cuda::CudaRuntime::addTraceGenerator( trace::TraceGenerator& gen, 
	bool persistent ) {

	lock();
	HostThreadContext & thread = getHostThreadContext();
	if (persistent) {
		thread.persistentTraceGenerators.push_back(&gen);
	}
	else {
		thread.nextTraceGenerators.push_back(&gen);
	}
	unlock();
}

void cuda::CudaRuntime::clearTraceGenerators() {
	lock();
	HostThreadContext& thread = getHostThreadContext();
	thread.persistentTraceGenerators.clear();
	thread.nextTraceGenerators.clear();
	unlock();
}

void cuda::CudaRuntime::limitWorkerThreads(unsigned int limit) {
	lock();
	getHostThreadContext();
	for (DeviceVector::iterator device = devices.begin(); 
		device != devices.end(); ++device) {
		(*device)->limitWorkerThreads(limit);
	}
	unlock();
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

