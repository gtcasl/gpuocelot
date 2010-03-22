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
#include <ocelot/executive/interface/ApplicationState.h>
#include <ocelot/cuda/interface/CudaRuntime.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/RuntimeException.h>

// Hydrazine includes
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

static executive::ChannelFormatDesc convert(const cudaChannelFormatDesc &cudaDesc) {
	executive::ChannelFormatDesc desc;
	desc.w = cudaDesc.w;
	desc.x = cudaDesc.x;
	desc.y = cudaDesc.y;
	desc.z = cudaDesc.z;
	desc.kind = (executive::ChannelFormatDesc::Kind)(int)cudaDesc.f;
	return desc;
}

static executive::MemcpyKind convert(const cudaMemcpyKind kind) {
	switch (kind) {
		case cudaMemcpyHostToHost:
			return executive::HostToHost;
		case cudaMemcpyDeviceToHost:
			return executive::DeviceToHost;
		case cudaMemcpyHostToDevice:
			return executive::HostToDevice;
		case cudaMemcpyDeviceToDevice:
			return executive::DeviceToDevice;
	}
	return executive::MemcpyKind_invalid;
}

static void convert(executive::ChannelFormatDesc &format, 
	const struct cudaChannelFormatDesc *desc) {
	switch (desc->f) {
		case cudaChannelFormatKindSigned: 
			format.kind = executive::ChannelFormatDesc::Kind_signed; break;
		case cudaChannelFormatKindUnsigned: 
			format.kind = executive::ChannelFormatDesc::Kind_unsigned; break;
		case cudaChannelFormatKindFloat: 
			format.kind = executive::ChannelFormatDesc::Kind_float; break;
		case cudaChannelFormatKindNone: // fall through
		default:
			format.kind = executive::ChannelFormatDesc::Kind_none;
			break;
	}

	format.x = desc->x;
	format.y = desc->y;
	format.z = desc->z;
	format.w = desc->w;
}

static void convert(struct cudaChannelFormatDesc *desc, 
	const executive::ChannelFormatDesc &format) {
	switch (format.kind) {
		case executive::ChannelFormatDesc::Kind_signed: desc->f = cudaChannelFormatKindSigned; break;
		case executive::ChannelFormatDesc::Kind_unsigned: desc->f = cudaChannelFormatKindUnsigned; break;
		case executive::ChannelFormatDesc::Kind_float: desc->f = cudaChannelFormatKindFloat; break;
		default:
			desc->f = cudaChannelFormatKindNone;
			break;
	}
	desc->x = format.x;
	desc->y = format.y;
	desc->z = format.z;
	desc->w = format.w;
}

static executive::Extent convert(struct cudaExtent cudaExtent) {
	executive::Extent extent;
	extent.depth = cudaExtent.depth;
	extent.height = cudaExtent.height;
	extent.width = cudaExtent.width;
	return extent;
}

static void convert(struct cudaPitchedPtr *cuda, const executive::PitchedPointer & pitched) {
	cuda->pitch = pitched.pitch;
	cuda->ptr = (char*)pitched.ptr + pitched.offset;
	cuda->xsize = pitched.width;
	cuda->ysize = pitched.height;
}

static executive::dim3 convert(dim3 dim) {
	executive::dim3 ed3 = {dim.x, dim.y, dim.z};
	return ed3;
}

static executive::dim3 convert(cudaPos pos) {
	executive::dim3 ed3 = {(int)pos.x, (int)pos.y, (int)pos.z};
	return ed3;
}

std::string cuda::CudaRuntime::formatError( const std::string& message ) {
	std::string result = "==Ocelot== ";
	for(std::string::const_iterator mi = message.begin(); mi != message.end(); ++mi) {
		result.push_back(*mi);
		if(*mi == '\n') {
			result.append("==Ocelot== ");
		}
	}
	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cuda::HostThreadContext::HostThreadContext(): selectedDevice(0), 
	nextStream(0), nextEvent(0), parameterBlock(0), parameterBlockSize(1<<13) {
	parameterBlock = (unsigned char *)malloc(parameterBlockSize);
}

cuda::HostThreadContext::~HostThreadContext() {
	::free(parameterBlock);
}

cuda::HostThreadContext::HostThreadContext(const HostThreadContext& c): 
	selectedDevice(c.selectedDevice),
	validDevices(c.validDevices),
	launchConfigurations(c.launchConfigurations),
	nextStream(c.nextStream),
	nextEvent(c.nextEvent),
	lastError(c.lastError),
	parameterBlock((unsigned char *)malloc(c.parameterBlockSize)),
	parameterBlockSize(c.parameterBlockSize),
	parameterIndices(c.parameterIndices),
	parameterSizes(c.parameterSizes),
	registeredGLbuffers(c.registeredGLbuffers),
	persistentTraceGenerators(c.persistentTraceGenerators),
	nextTraceGenerators(c.nextTraceGenerators)
{
	memcpy(parameterBlock, c.parameterBlock, parameterBlockSize);
}

cuda::HostThreadContext& cuda::HostThreadContext::operator=(const HostThreadContext& c) {
	if(&c == this) return *this;
	selectedDevice = c.selectedDevice;
	validDevices = c.validDevices;
	nextStream = c.nextStream;
	nextEvent = c.nextEvent;
	lastError = c.lastError;
	launchConfigurations = c.launchConfigurations;
	parameterIndices = c.parameterIndices;
	parameterSizes = c.parameterSizes;
	registeredGLbuffers = c.registeredGLbuffers;
	persistentTraceGenerators = c.persistentTraceGenerators;
	nextTraceGenerators = c.nextTraceGenerators;
	memcpy(parameterBlock, c.parameterBlock, parameterBlockSize);
	return *this;
}

cuda::HostThreadContext::HostThreadContext(HostThreadContext&& c): 
	selectedDevice(0), nextStream(0), nextEvent(0), parameterBlock(0), 
	parameterBlockSize(1<<13) {
	*this = std::move(c);
}

cuda::HostThreadContext& cuda::HostThreadContext::operator=(HostThreadContext&& c) {
	if (this == &c) return *this;
	std::swap(selectedDevice, c.selectedDevice);
	std::swap(validDevices, c.validDevices);
	std::swap(nextStream, c.nextStream);
	std::swap(nextEvent, c.nextEvent);
	std::swap(lastError, c.lastError);
	std::swap(parameterBlock, c.parameterBlock);
	std::swap(launchConfigurations, c.launchConfigurations);
	std::swap(parameterIndices, c.parameterIndices);
	std::swap(parameterSizes, c.parameterSizes);
	std::swap(registeredGLbuffers, c.registeredGLbuffers);
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
	streams.clear();
	events.clear();
	clearParameters();
	for (RegisteredGLBufferMap::iterator buffer = registeredGLbuffers.begin(); 
		buffer != registeredGLbuffers.end(); ++buffer) {
		if (buffer->second.mapped) {
			glBindBuffer(GL_ARRAY_BUFFER, buffer->first);
			glUnmapBuffer(GL_ARRAY_BUFFER);
			assert( glGetError() != GL_NO_ERROR );
		}
	}
	registeredGLbuffers.clear();
	persistentTraceGenerators.clear();
	nextTraceGenerators.clear();
}

void cuda::HostThreadContext::mapParameters(executive::Executive& context, 
	const std::string& moduleName, const std::string& kernelName) {
	ir::Instruction::Architecture isa = context.getSelectedISA();
	ir::Kernel *kernel = context.getKernel(isa, moduleName, kernelName);
	if (!kernel) {
		kernel = context.translateToISA(isa, moduleName, kernelName);
	}
	assert(kernel->parameters.size() == parameterIndices.size());
	IndexVector::iterator offset = parameterIndices.begin();
	SizeVector::iterator size = parameterSizes.begin();
	unsigned int dst = 0;
	unsigned char* temp = (unsigned char*)malloc(parameterBlockSize);
	for (ir::Kernel::ParameterVector::iterator parameter = kernel->parameters.begin(); 
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

cuda::CudaContext::CudaContext(): thread(0)
#if HAVE_CUDA_DRIVER_API == 1
, context(0) 
#endif
{ }

//////////////////////////////////////////////////////////////////////////////////////////////////

cuda::RegisteredGLBuffer::RegisteredGLBuffer(): flags(0), ptr(0), mapped(false) { 

}

//////////////////////////////////////////////////////////////////////////////////////////////////

cuda::CudaRuntime::CudaRuntime() : nextSymbol(1) {
	pthread_mutex_init(&mutex, 0);
}

cuda::CudaRuntime::~CudaRuntime() {
	//
	// free things that need freeing
	//
	
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

//! sets the last error state for the CudaRuntime object
cudaError_t cuda::CudaRuntime::setLastErrorAndUnlock(HostThreadContext &thread, 
	cudaError_t result) {
	thread.lastError = result;
	unlock();
	return result;
}

//! gets the context of a thread
cuda::HostThreadContext & cuda::CudaRuntime::getHostThreadContext() {
	pthread_t self = pthread_self();
	
	HostThreadContextMap::iterator it = threads.find(self);
	if (it == threads.end()) {
		it = threads.insert(std::make_pair(self, HostThreadContext())).first;
	}
	
	context.selectDevice(it->second.selectedDevice);
	
	return it->second;
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

	// register associated PTX
	if( binary->ptx->ptx != 0 ) {
		std::stringstream ptx( binary->ptx->ptx );
		context.loadModule( binary->ident, false, ptx );
	}
	else {
		assert(0 && "binary contains no PTX");
	}
	
	FatBinaryContext cubinContext;
	cubinContext.cubin_ptr = fatCubin;
	fatBinaries.push_back(cubinContext);
	handle = fatBinaries.size();
	
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
	char *deviceAddress, const char *deviceName, int ext, int size, int constant, int global) {

	report("cuda::CudaRuntime::cudaRegisterVar() - host var: " << (void *)hostVar 
		<< ", deviceName: " << deviceName << ", size: " << size << " bytes,"
		<< (constant ? " constant" : " ") << (global ? " global" : " "));

	size_t handle = (size_t)fatCubinHandle - 1;
	lock();

	globalSymbolMap[(void *)hostVar] = deviceName;
	
	const char *moduleName = fatBinaries[handle].name();
	void *hostVariable = (void *)hostVar;
	
	executive::DeviceAddressSpace addrSpace = (constant ? executive::Device_constant : 
		executive::Device_global);
	context.registerGlobalVariable(moduleName, deviceName, hostVariable, (void *)deviceAddress, 
		size, addrSpace);
	
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

	
	// register the texture object to the runtime and declare it to the executive
	
	RegisteredTexture texture;
	
	texture.handle = handle;
	texture.pointer = (void *)hostVar;
	texture.module = fatBinaries[handle].name();
	texture.texture = deviceName;
	
	report("cudaRegisterTexture('" << texture.texture << ", dim: " << dim 
		<< ", norm: " << norm << ", ext: " << ext);

	// now tell the executive about it
	context.registerTexture(texture.module, texture.texture, dim, norm);
	
	textures[std::string(texture.texture)] = texture;
	textureReferences[(const void *)hostVar] = texture.texture;
	
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
	
	context.registerGlobalVariable(moduleName, variableName, 0, 0, sizeof(void*), 
		executive::Device_shared);
	
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
	
	report("cudaRegisterSharedVar() - module " << moduleName << ", devicePtr: " << std::hex 
		<< devicePtr << std::dec << " named " << variableName << ", size: " << size 
		<< ", alignment: " << alignment << ", storage: " << storage);
	
	/*
	context.registerGlobalVariable(moduleName, variableName, 0, 0, sizeof(void*), 
		executive::Device_shared);
	*/
	
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
		
	void *funcPtr = (void *)hostFun;
	const char *funcName = deviceFun;
	const char *moduleName = fatBinaries[handle].name();

	globalSymbolMap[funcPtr] = std::string(funcName);
	
	// associate the function pointer with the kernel name and maybe ir::Kernel
	RegisteredKernel kernel;
	kernel.handle = handle;
	kernel.module = moduleName;
	kernel.kernel = funcName;
	kernel.pointer = funcPtr;
	
	kernels[funcPtr] = kernel;
	
	unlock();
}
		
//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory allocation

cudaError_t cuda::CudaRuntime::cudaMalloc(void **devPtr, size_t size) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();
		
	if (context.malloc(devPtr, size)) {
		result = cudaSuccess;

		report("CudaRuntime::cudaMalloc( *devPtr = " << (void *)*devPtr << ", size = " << size << ")");
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMallocHost(void **ptr, size_t size) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	
	if (context.mallocHost(ptr, size)) {
		result = cudaSuccess;
		report("CudaRuntime::cudaMallocHost( *pPtr = " << (void *)*ptr << ", size = " << size << ")");
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMallocPitch(void **devPtr, size_t *pitch, size_t width, 
	size_t height) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	if (context.mallocPitch(devPtr, pitch, width, height)) {
		result = cudaSuccess;
		report("CudaRuntime::cudaMallocPitch( *devPtr = " << (void *)*devPtr << ", pitch = " 
			<< *pitch << ")");
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMallocArray(struct cudaArray **array, 
	const struct cudaChannelFormatDesc *desc, size_t width, size_t height) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	if (context.mallocArray(array, convert(*desc), width, height)) {
		result = cudaSuccess;
		report("CudaRuntime::cudaMallocArray( *array = " << (void *)*array << ")");
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaFree(void *devPtr) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	report("cudaFree()");
	
	HostThreadContext & thread = getHostThreadContext();
	if (!devPtr || context.free(devPtr)) {
		result = cudaSuccess;
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaFreeHost(void *ptr) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	if (!ptr || context.freeHost(ptr)) {
		result = cudaSuccess;
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaFreeArray(struct cudaArray *array) {
	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	report("CudaRuntime::cudaFreeArray() array = " << (void *)array);
	if (!array || context.freeArray(array)) {
		result = cudaSuccess;
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMalloc3D(struct cudaPitchedPtr* devPtr, 
	struct cudaExtent extent) {

	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	executive::PitchedPointer pitchedPointer;
	if (context.mallocPitch(&pitchedPointer, convert(extent))) {
		convert(devPtr, pitchedPointer);
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMalloc3DArray(struct cudaArray** arrayPtr, 
	const struct cudaChannelFormatDesc* desc, struct cudaExtent extent) {

	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	executive::PitchedPointer pitchedPointer;
	if (context.mallocPitch(&pitchedPointer, convert(extent))) {
		result = cudaSuccess;
		*arrayPtr = (struct cudaArray *)((char*)pitchedPointer.ptr 
			+ pitchedPointer.offset);

		report("cudaMalloc3DArray() - *arrayPtr = " << (void *)(*arrayPtr));
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaHostAlloc(void **pHost, size_t bytes, unsigned int flags) {

	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	bool portable = (flags & cudaHostAllocPortable);
	bool mapped = (flags & cudaHostAllocMapped);
	bool writeCombined = (flags & cudaHostAllocWriteCombine);
	if (context.mallocHost(pHost, bytes, portable, mapped, writeCombined)) {
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaHostGetDevicePointer(void **pDevice, void *pHost, 
	unsigned int flags) {

	cudaError_t result = cudaErrorMemoryAllocation;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	const executive::MemoryAllocation* memory = context.getMemoryAllocation(pHost);
	if (memory->get()) {
		result = cudaSuccess;
		*pDevice = memory->get();
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaHostGetFlags(unsigned int *pFlags, void *pHost) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	assert(0 && "unimplemented");

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory copying

cudaError_t cuda::CudaRuntime::cudaMemcpy(void *dst, const void *src, size_t count, 
	enum cudaMemcpyKind kind) {
	cudaError_t result = cudaSuccess;
	if (kind >= 0 && kind <= 3) {
		lock();
		getHostThreadContext();

		report("cudaMemcpy()");
		bool success = context.deviceMemcpy(dst, src, count, convert(kind));
		if (!success) {
			result = cudaErrorInvalidDevicePointer;
		}
		unlock();
	}
	else {
		result = cudaErrorInvalidMemcpyDirection;
	}

	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyToSymbol(const char *symbol, const void *src,
	size_t count, size_t offset, enum cudaMemcpyKind kind) {

	report("cuda::CudaRuntime::cudaMemcpyToSymbol('" << symbol << "' - " 
		<< (void *)symbol << " - value " << hydrazine::dataToString(src, count));

	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	std::map< void *, std::string >::const_iterator sym_it = globalSymbolMap.find((void *)symbol);
	if (sym_it != globalSymbolMap.end()) {
		symbol = sym_it->second.c_str();
	}

	report("cudaMemcpyToSymbol() '" << symbol << "'");
	bool success = context.deviceMemcpyToSymbol(symbol, src, count, offset, convert(kind));	
	if (!success) {
		result = cudaErrorInvalidDevicePointer;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyFromSymbol(void *dst, const char *symbol,
	size_t count, size_t offset, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	std::map< void *, std::string >::const_iterator sym_it = globalSymbolMap.find((void *)symbol);
	if (sym_it != globalSymbolMap.end()) {
		symbol = sym_it->second.c_str();
	}

	report("cudaMemcpyFromSymbol() '" << symbol << "'");

	bool success = context.deviceMemcpyFromSymbol(symbol, dst, count, offset, convert(kind));	
	if (!success) {
		result = cudaErrorInvalidDevicePointer;
	}
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyAsync(void *dst, const void *src, size_t count, 
	enum cudaMemcpyKind kind, cudaStream_t streamHandle) {
	
	cudaError_t result = cudaErrorNotYetImplemented;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	
	StreamMap::iterator s_it = thread.streams.find(streamHandle);
	if (!streamHandle || s_it != thread.streams.end()) {
		if (!context.getDeviceAddressSpace()) {
			//
			// host address space transfers aren't asynchronous
			//
			bool success = context.deviceMemcpy(dst, src, count, convert(kind));
			if (!success) {
				result = cudaErrorInvalidDevicePointer;
			}
		}
		else {
			assert(0 && "unimplemented");
		}
	}
	else {
		result = cudaErrorInvalidValue;
	}
	
	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, 
	size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue ;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	report("cudaMemcpyToArray()");

	if (context.deviceMemcpyToArray(dst, (void *)src, wOffset, hOffset, count, convert(kind))) {
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyFromArray(void *dst, const struct cudaArray *src, 
	size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue ;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	report("cudaMemcpyFromArray()");

	if (context.deviceMemcpyFromArray((struct cudaArray *)src, dst, wOffset, hOffset, count, 
		convert(kind))) {
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, 
	size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, 
	size_t count, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	report("cudaMemcpyArrayToArray()");

	if (context.deviceMemcpyArrayToArray((struct cudaArray *)dst, wOffsetDst, hOffsetDst,
		(struct cudaArray *)src, wOffsetSrc, hOffsetSrc, count, convert(kind))) {
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}

/*!
	\brief perform a 2D memcpy from a dense buffer
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2D(void *dst, size_t dpitch, const void *src, 
	size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	report("cudaMemcpy2D()");	

	if (context.deviceMemcpy2D(dst, dpitch, src, spitch, width, height, convert(kind))) {
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}

/*!
	\brief perform a 2D memcpy to an array
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, 
	size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	report("cudaMemcpy2DtoArray(dst = " << (void *)dst << ", src = " << (void *)src);
	
	if (context.deviceMemcpy2DtoArray(dst, wOffset, hOffset, src, spitch, 
		width, height, convert(kind))) {

		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);		
}

/*!
	\brief perform a 2D memcpy from an array
*/
cudaError_t cuda::CudaRuntime::cudaMemcpy2DFromArray(void *dst, size_t dpitch, 
	const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, 
	enum cudaMemcpyKind kind) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	
	if (context.deviceMemcpy2DfromArray(dst,dpitch, src, wOffset, hOffset, width, height, 
		convert(kind))) {

		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);		
}

cudaError_t cuda::CudaRuntime::cudaMemcpy3D(const struct cudaMemcpy3DParms *p) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	executive::PitchedPointer dstPtr;
	executive::PitchedPointer srcPtr;

	if (p->dstArray) {
		dstPtr.ptr = (void *)p->dstArray;
		dstPtr.offset = 0;
		dstPtr.xsize = 0;
		dstPtr.ysize = 0;
	}
	else {
		dstPtr.ptr = p->dstPtr.ptr;
		dstPtr.offset = 0;
		dstPtr.xsize = p->dstPtr.xsize;
		dstPtr.ysize = p->dstPtr.ysize;
		dstPtr.pitch = p->dstPtr.pitch;
	}
	if (p->srcArray) {
		srcPtr.ptr = (void *)p->srcArray;
		srcPtr.offset = 0;
		srcPtr.xsize = 0;
		srcPtr.ysize = 0;
	}
	else {
		srcPtr.ptr = p->srcPtr.ptr;
		srcPtr.offset = 0;
		srcPtr.xsize = p->srcPtr.xsize;
		srcPtr.ysize = p->srcPtr.ysize;
		srcPtr.pitch = p->srcPtr.pitch;
	}

	report("cudaMemcpy3D() - dstPtr = (" << (void *)dstPtr.ptr << ", " << dstPtr.xsize << ", " 
		<< dstPtr.ysize << ") - srcPtr = (" << (void *)p->srcPtr.ptr << ", " 
		<< p->srcPtr.xsize << ", " << p->srcPtr.ysize << ")");

	if (context.deviceMemcpy3D(dstPtr, convert(p->dstPos), convert(p->extent), convert(p->kind),
		srcPtr, convert(p->srcPos))) {
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}

cudaError_t cuda::CudaRuntime::cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, 
	cudaStream_t stream) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	assert(0 && "unimplemented");

	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memset
//

cudaError_t cuda::CudaRuntime::cudaMemset(void *devPtr, int value, size_t count) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	getHostThreadContext();
	if (!context.getDeviceAddressSpace()) {
		::memset((void *)devPtr, value, count);
		result = cudaSuccess;
	}
	else {
		assert(0 && "unimplemented");
		result = cudaErrorNotYetImplemented;
	}
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaMemset2D(void *devPtr, size_t pitch, int value, size_t width, 
	size_t height) {

	cudaError_t result = cudaErrorInvalidValue;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	if (context.getDeviceAddressSpace()) {
		assert(0 && "unimplemented");
		result = cudaErrorNotYetImplemented;
	}
	else {
		if (pitch == width) {
			::memset((void *)devPtr, value, pitch * height);
		}
		else {
			for (size_t i = 0; i < height; i++) {
				char *ptr = (char *)devPtr + pitch * i;
				::memset((void *)ptr, value, width);
			}
		}
		result = cudaSuccess;
	}
	
	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}


cudaError_t cuda::CudaRuntime::cudaMemset3D(struct cudaPitchedPtr pitchedDevPtr, int value, 
	struct cudaExtent extent) {

	cudaError_t result = cudaErrorNotYetImplemented;
	lock();
	HostThreadContext & thread = getHostThreadContext();

	assert(0 && "unimplemented");
	
	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// memory allocation
//

cudaError_t cuda::CudaRuntime::cudaGetSymbolAddress(void **devPtr, const char *symbol) {

	report("cuda::CudaRuntime::cudaGetSymbolAddress(" << devPtr << ", " << (void*) symbol << ")");
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	if (!*symbol) {
		symbol = globalSymbolMap[(void *)symbol].c_str();
	}
	executive::GlobalVariable & global = context.getGlobalVariable(symbol);
	*devPtr = global.host_pointer;

	report("devPtr: " << *devPtr);	

	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}

cudaError_t cuda::CudaRuntime::cudaGetSymbolSize(size_t *size, const char *symbol) {
	cudaError_t result = cudaSuccess;
	report("cuda::CudaRuntime::cudaGetSymbolSize(" << size << ", " << (void*) symbol << ")");
	lock();
	HostThreadContext & thread = getHostThreadContext();
	if (!*symbol) {
		symbol = globalSymbolMap[(void *)symbol].c_str();
	}
	executive::GlobalVariable & global = context.getGlobalVariable(symbol);
	*size = global.size;
	
	TestError(result);
	return setLastErrorAndUnlock(thread, result);	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetDeviceCount(int *count) {
	cudaError_t result = cudaSuccess;
	lock();
	
	*count = context.getDevices().size();
	
	unlock();
	TestError(result);
	return setLastError(result);
}

#define minimum(x, y) ((x) > (y) ? (y) : (x))

cudaError_t cuda::CudaRuntime::cudaGetDeviceProperties(struct cudaDeviceProp *prop, int dev) {
	cudaError_t result = cudaSuccess;
	
	lock();
	if (dev < (int)context.getDevices().size()) {
		const executive::Device & device = context.getDevices().at(dev);
	
		report("cuda::CudaRuntime::cudaGetDeviceProperties(dev = " << dev 
			<< ") - major: " << device.major << ", minor: " << device.minor);

		memset(prop, 0, sizeof(prop));
		hydrazine::strlcpy( prop->name, device.name.c_str(), 256 );
		prop->canMapHostMemory = 1;
		prop->clockRate = device.clockRate;
		prop->computeMode = cudaComputeModeDefault;
		prop->deviceOverlap = device.memcpyOverlap;
		prop->integrated = 0;
		prop->kernelExecTimeoutEnabled = 0;
		prop->major = device.major;
		prop->minor = device.minor;
		prop->maxGridSize[0] = device.maxGridSize[0];
		prop->maxGridSize[1] = device.maxGridSize[1];
		prop->maxGridSize[2] = device.maxGridSize[2];
		prop->maxThreadsDim[0] = device.maxThreadsDim[0];
		prop->maxThreadsDim[1] = device.maxThreadsDim[1];
		prop->maxThreadsDim[2] = device.maxThreadsDim[2];
		prop->maxThreadsPerBlock = device.maxThreadsPerBlock;
		prop->memPitch = device.memPitch;
		prop->multiProcessorCount = device.multiprocessorCount;
		prop->regsPerBlock = device.regsPerBlock;
		prop->sharedMemPerBlock = device.sharedMemPerBlock;
		prop->textureAlignment = device.textureAlign;
		prop->totalConstMem = device.totalConstantMemory;
		prop->totalGlobalMem = device.totalMemory;
		prop->warpSize = device.SIMDWidth;
		
		report("  returning: prop->major = " << prop->major << ", prop->minor = " << prop->minor);
		
		result = cudaSuccess;
	}
	else {
		result = cudaErrorInvalidDevice;
	}
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaChooseDevice(int *device, const struct cudaDeviceProp *prop) {
	cudaError_t result = cudaSuccess;
	*device = context.getSelectedDevice();
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetDevice(int device) {
	cudaError_t result = cudaErrorSetOnActiveProcess;
	
	lock();
	if ((int)context.getDevices().size() <= device) {
		result = cudaErrorInvalidDevice;
	}
	else {
		HostThreadContext &thread = getHostThreadContext();
		thread.selectedDevice = device;
		context.selectDevice(device);
		result = cudaSuccess;
	}
	unlock();
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGetDevice(int *device) {
	cudaError_t result = cudaSuccess;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();
	*device = thread.selectedDevice;
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetValidDevices(int *device_arr, int len) {
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	thread.validDevices.resize(len);
	for (int i = 0 ; i < len; i++) {
		thread.validDevices[i] = device_arr[i];
	}
	unlock();
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetDeviceFlags( int flags ) {
	cudaError_t result = cudaSuccess;
	
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! binds a texture to a reference and a CUDA memory block
cudaError_t cuda::CudaRuntime::cudaBindTexture(size_t *offset, 
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t size) {

	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();

	executive::ChannelFormatDesc format;
	convert(format, desc);
	if (context.bindTexture(offset, textureReferences[texref], devPtr, format, size, 
		(ir::Texture::AddressMode *)texref->addressMode, 
		(ir::Texture::Interpolation)texref->filterMode, texref->normalized)) {

		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaBindTexture2D(size_t *offset,
	const struct textureReference *texref, const void *devPtr, 
	const struct cudaChannelFormatDesc *desc, size_t width, size_t height, size_t pitch) {
	cudaError_t result = cudaErrorInvalidValue;

	lock();
	HostThreadContext &thread = getHostThreadContext();

	executive::ChannelFormatDesc format;
	convert(format, desc);

	if (context.bindTexture2D(offset, textureReferences[texref], devPtr, format, width, height, 
		pitch, (ir::Texture::AddressMode *)texref->addressMode, 
		(ir::Texture::Interpolation)texref->filterMode, texref->normalized)) {
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaBindTextureToArray(const struct textureReference *texref, 
	const struct cudaArray *array, const struct cudaChannelFormatDesc *desc) {
	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();

	executive::ChannelFormatDesc format;
	convert(format, desc);

	report("cudaBindTextureToArray() - texref = '" << textureReferences[texref] << "', array = " 
		<< (void *)array << " - format: " << format.kind << " (" << format.x << ", " << format.y 
		<< ", " << format.z << ")");

	if (context.bindTextureToArray(textureReferences[texref], (void *)array, format, 
		(ir::Texture::AddressMode *)texref->addressMode, 
		(ir::Texture::Interpolation)texref->filterMode, texref->normalized)) {

		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaUnbindTexture(const struct textureReference *texref) {
	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();

	context.unbindTexture(textureReferences[(void *)texref]);
	result = cudaSuccess;

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaGetTextureAlignmentOffset(size_t *offset, 
	const struct textureReference *texref) {
	cudaError_t result = cudaErrorInvalidValue;

	lock();
	HostThreadContext &thread = getHostThreadContext();

	*offset = context.getTextureAlignmentOffset(textureReferences[texref]);

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaGetTextureReference(const struct textureReference **texref, 
	const char *symbol) {
	cudaError_t result = cudaErrorInvalidTexture;
	lock();
	
	RegisteredTextureMap::iterator it = textures.find(symbol);
	if (it != textures.end()) {
		*texref = (const struct textureReference *)it->second.pointer;
		result = cudaSuccess;
	}
	
	unlock();
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGetChannelDesc(struct cudaChannelFormatDesc *desc, 
	const struct cudaArray *array) {
	cudaError_t result = cudaErrorInvalidValue;

	lock();
	HostThreadContext &thread = getHostThreadContext();

	const executive::MemoryAllocation* memory = context.getMemoryAllocation(
		(const void *)array);
	if (memory->get()) {
		convert(desc, memory->desc);
		result = cudaSuccess;
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

struct cudaChannelFormatDesc cuda::CudaRuntime::cudaCreateChannelDesc(int x, int y, int z, int w, 
	enum cudaChannelFormatKind f) {

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
	
cudaError_t cuda::CudaRuntime::cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem,
	cudaStream_t stream) {

	lock();
	report("cudaConfigureCall()");
	
	cudaError_t result = cudaErrorInvalidConfiguration;
	HostThreadContext &thread = getHostThreadContext();
	
	KernelLaunchConfiguration launch(gridDim, blockDim, sharedMem, stream);
	thread.launchConfigurations.push_back(launch);
	result = cudaSuccess;
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaSetupArgument(const void *arg, size_t size, size_t offset) {
	cudaError_t result = cudaSuccess;
	
	lock();
	
	HostThreadContext &thread = getHostThreadContext();

	report("cudaSetupArgument() - offset " << offset << ", size " << size);
	
	memcpy(thread.parameterBlock + offset, arg, size);
	
	thread.parameterIndices.push_back(offset);
	thread.parameterSizes.push_back(size);
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaLaunch(const char *entry) {

	lock();
	
	cudaError_t result = cudaSuccess;
	HostThreadContext & thread = getHostThreadContext();
	
	assert(thread.launchConfigurations.size());
	
	KernelLaunchConfiguration launch(thread.launchConfigurations.back());
	thread.launchConfigurations.pop_back();
	
	const RegisteredKernel & kernel = kernels[(void *)entry];
	std::string moduleName = kernel.module;
	std::string kernelName = kernel.kernel;

	thread.mapParameters(context, moduleName, kernelName);
	
	report("CudaRuntime::cudaLaunch(" << kernelName 
		<< ") on thread " << pthread_self());
	
	try {

		trace::TraceGeneratorVector traceGens;

		if (api::OcelotConfiguration::getTrace().enabled) {
			traceGens = thread.persistentTraceGenerators;
			traceGens.insert(traceGens.end(), thread.nextTraceGenerators.begin(), 
				thread.nextTraceGenerators.end());
		}

		context.launch(moduleName, kernelName, convert(launch.gridDim), 
			convert(launch.blockDim), launch.sharedMemory, 
			thread.parameterBlock, thread.parameterBlockSize, traceGens);
		report(" launch completed successfully");	
	}
	catch( const executive::RuntimeException& e ) {
#if CUDA_VERBOSE == 1
		std::cerr << "==Ocelot== Emulator failed to run kernel \"" 
			<< kernelName 
			<< "\" with exception: \n";
		std::cerr << formatError( e.toString() ) 
			<< "\n" << std::flush;
#endif
		thread.lastError = cudaErrorLaunchFailure;
#if CATCH_RUNTIME_EXCEPTIONS != 1
		throw e;
#endif
	}

	TestError(result);
	return setLastErrorAndUnlock(thread, result);
}

cudaError_t cuda::CudaRuntime::cudaFuncGetAttributes(struct cudaFuncAttributes *attr, 
	const char *func) {
	cudaError_t result = cudaErrorInvalidDeviceFunction;
		
	lock();
	
	//
	// go find the kernel and fill out its attributes
	//
	const char *symbol = func;
	std::map< void *, std::string >::const_iterator sym_it = globalSymbolMap.find((void *)symbol);
	if (sym_it != globalSymbolMap.end()) {
		ir::Kernel *kernel = 0;
		RegisteredKernelMap::const_iterator kernel_it = kernels.begin(); 

		symbol = sym_it->second.c_str();

		for (; kernel_it != kernels.end(); ++kernel_it) {
			if (std::string(kernel_it->second.kernel) == symbol) {
				kernel = context.getKernel(context.getSelectedISA(), kernel_it->second.module, 
					kernel_it->second.kernel);
				break;
			}
		}

		if (kernel && kernel->ISA != ir::Instruction::PTX) {
			const ir::ExecutableKernel *exeKernel = static_cast<const ir::ExecutableKernel *>(kernel);

			attr->constSizeBytes = exeKernel->constMemorySize();
			attr->localSizeBytes = exeKernel->localMemorySize();
			attr->maxThreadsPerBlock = exeKernel->maxThreadsPerBlock();
			attr->numRegs = exeKernel->registerCount();
			attr->sharedSizeBytes = exeKernel->sharedMemorySize();

			result = cudaSuccess;
		}
		else if (kernel) {
			report("cudaFuncGetAttributes() - got kernel '" << kernel->name << "' but ISA was " 
				<< kernel->ISA << ", selected ISA is " << context.getSelectedISA());
		}
	}
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// CUDA event creation

cudaError_t cuda::CudaRuntime::cudaEventCreate(cudaEvent_t *event) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();
	
	//
	// create an event
	//
	Event createdEvent;
	createdEvent.flags = 0;
	createdEvent.handle = thread.events.size();
	*event = createdEvent.handle;
	thread.events[*event] = createdEvent;
	result = cudaSuccess;
	
	// special behavior for CUDA devices
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}
	
	unlock();

	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventCreateWithFlags(cudaEvent_t *event, int flags) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();
	
	//
	// create an event
	//
	Event createdEvent;
	createdEvent.flags = flags;
	createdEvent.handle = thread.events.size();
	*event = createdEvent.handle;
	thread.events[*event] = createdEvent;
	result = cudaSuccess;

	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}
		
	unlock();

	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventRecord(cudaEvent_t event, cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();
	
	StreamMap::iterator s_it = thread.streams.find(stream);
	EventMap::iterator e_it = thread.events.find(event);
	if (e_it != thread.events.end() && (!stream || s_it != thread.streams.end())) {
		e_it->second.timer.start();
		if (stream) {
			s_it->second.events.push_back(event);
		}
		
		result = cudaSuccess;
	}
	else {
		if (e_it == thread.events.end()) {
			report("event not found");
		}
		if (s_it == thread.streams.end()) {
			report("stream not found");
		}
		result = cudaErrorInvalidResourceHandle;
	}
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}
		
	unlock();	
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventQuery(cudaEvent_t event) {
	cudaError_t result = cudaErrorInvalidValue;

	lock();
	
	HostThreadContext &thread = getHostThreadContext();
	
	EventMap::iterator e_it = thread.events.find(event);
	if (e_it != thread.events.end()) {
		result = cudaSuccess;
	}
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}	
	unlock();

	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventSynchronize(cudaEvent_t event) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	
	HostThreadContext &thread = getHostThreadContext();
	
	EventMap::iterator e_it = thread.events.find(event);
	if (e_it != thread.events.end()) {
		result = cudaSuccess;
	}
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventDestroy(cudaEvent_t event) {
	cudaError_t result = cudaErrorInvalidValue;
	
	lock();
	
	HostThreadContext &thread = getHostThreadContext();
	
	EventMap::iterator e_it = thread.events.find(event);
	if (e_it != thread.events.end()) {
		thread.events.erase(e_it);
		result = cudaSuccess;
	}
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaEventElapsedTime(float *ms, cudaEvent_t start, cudaEvent_t end) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	
	HostThreadContext &thread = getHostThreadContext();
	
	EventMap::iterator e_start_it = thread.events.find(start);
	EventMap::iterator e_end_it = thread.events.find(end);
	
	if (e_start_it != thread.events.end() && e_end_it != thread.events.end()) {
		e_end_it->second.timer.stop();
		e_start_it->second.timer.stop();
		
		long long end_cycles = (long long)e_end_it->second.timer.cycles();
		long long start_cycles = (long long)e_start_it->second.timer.cycles();
		long long total_cycles = start_cycles - end_cycles;

		e_end_it->second.timer.start();
		e_start_it->second.timer.start();
		
		*ms = (float)((total_cycles + 0.0 ) * 1.0e-9);
		result = cudaSuccess;
	}
	else {
		result = cudaErrorInvalidResourceHandle;
	}
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}
	unlock();
	
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// CUDA streams
//

cudaError_t cuda::CudaRuntime::cudaStreamCreate(cudaStream_t *pStream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	
	HostThreadContext &thread = getHostThreadContext();
	
	Stream stream;
	stream.handle = (cudaStream_t)thread.streams.size();
	thread.streams[stream.handle] = stream;
	*pStream = stream.handle;
	result = cudaSuccess;
	
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}
		
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamDestroy(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;
	
	lock();
	HostThreadContext &thread = getHostThreadContext();
	StreamMap::iterator s_it = thread.streams.find(stream);

	if (s_it != thread.streams.end()) {
		thread.streams.erase(s_it);
		result = cudaSuccess;
	}
	else {
		result = cudaErrorInvalidResourceHandle;
	}	
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}	
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamSynchronize(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;

	lock();
	HostThreadContext &thread = getHostThreadContext();
	StreamMap::iterator s_it = thread.streams.find(stream);

	if (s_it != thread.streams.end()) {
		result = cudaSuccess;
	}
	else {
		result = cudaErrorInvalidResourceHandle;
	}	
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}	
	
	unlock();

	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaStreamQuery(cudaStream_t stream) {
	cudaError_t result = cudaErrorNotYetImplemented;

	lock();
	HostThreadContext &thread = getHostThreadContext();
	StreamMap::iterator s_it = thread.streams.find(stream);

	if (s_it != thread.streams.end()) {
		result = cudaSuccess;
	}
	else {
		result = cudaErrorInvalidResourceHandle;
	}	
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}	
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaThreadExit(void) {
	cudaError_t result = cudaSuccess;
	
	lock();
	getHostThreadContext();
	
	//
	// kill potentially running kernels
	//
	if (context.getSelectedISA() == ir::PTXInstruction::GPU) {
		assert(0 && "unimplemented");
	}
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaThreadSynchronize(void) {
	cudaError_t result = cudaSuccess;
	lock();
	getHostThreadContext();
	unlock();
	
	//
	// block on executing threads
	//
	context.synchronize();
	
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

cudaError_t cuda::CudaRuntime::cudaGLMapBufferObject(void **devPtr, GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext &thread = getHostThreadContext();

	report("cudaGLMapBufferObject()");
	
	RegisteredGLBufferMap::iterator buf_it = thread.registeredGLbuffers.find(bufObj);
	if (buf_it == thread.registeredGLbuffers.end()) {
		result = cudaErrorMapBufferObjectFailed;
	}
	else {
		if (context.getDeviceAddressSpace()) {
			assert(0 && "unimplemented");
		}
		else {
			glBindBuffer(GL_ARRAY_BUFFER, bufObj);
			buf_it->second.ptr = glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
			int bytes = 0;
			glGetBufferParameteriv( GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bytes );

			*devPtr = buf_it->second.ptr;
			buf_it->second.mapped = true;

			context.registerExternal(*devPtr, bytes);
			
			if( glGetError() != GL_NO_ERROR ) {
				//report("  error - mapped " << bytes << " bytes");
			}

			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLMapBufferObjectAsync(void **devPtr, GLuint bufObj, 
	cudaStream_t stream) {
	assert(0 && "unimplemented");
}

cudaError_t cuda::CudaRuntime::cudaGLRegisterBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext &thread = getHostThreadContext();

	report("cudaGLRegisterBufferObject(" << bufObj << ")");	
	
	if (context.getDeviceAddressSpace()) {
		report("context.deviceAddrSpace = " << context.getDeviceAddressSpace());
		assert(0 && "unimplemented");
	}
	else {
		glBindBuffer(GL_ARRAY_BUFFER, bufObj);
		RegisteredGLBufferMap::iterator buf_it = thread.registeredGLbuffers.find(bufObj);
		if (buf_it != thread.registeredGLbuffers.end()) {
			glUnmapBuffer(GL_ARRAY_BUFFER);
		}
		RegisteredGLBuffer buffer;
		thread.registeredGLbuffers[bufObj] = buffer;
	}
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLSetBufferObjectMapFlags(GLuint bufObj, unsigned int flags) {
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext &thread = getHostThreadContext();
	
	report("cudaGLSetBufferObjectMapFlags()");
	
	RegisteredGLBufferMap::iterator buf_it = thread.registeredGLbuffers.find(bufObj);
	if (buf_it == thread.registeredGLbuffers.end()) {
		result = cudaErrorMapBufferObjectFailed;
	}
	else {
		if (context.getDeviceAddressSpace()) {
			assert(0 && "unimplemented");
		}
		else {
			buf_it->second.flags = flags;
		}
	}
	
	unlock();
	
	TestError(result);
	return setLastError(result);

}

cudaError_t cuda::CudaRuntime::cudaGLSetGLDevice(int device) {
	report("cudaGLSetGLDevice(" << device << ")");
	return cudaSuccess;
}

cudaError_t cuda::CudaRuntime::cudaGLUnmapBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	
	report("cudaGLUnmapBufferObject(" << bufObj << ")");
	
	RegisteredGLBufferMap::iterator buf_it = thread.registeredGLbuffers.find(bufObj);
	if (buf_it != thread.registeredGLbuffers.end()) {
		if (buf_it->second.mapped) {
			if (context.getDeviceAddressSpace()) {
				assert(0 && "unimplemented");
			}
			else {
				context.unregisterExternal(buf_it->second.ptr);

				glBindBuffer(GL_ARRAY_BUFFER, bufObj);
				glUnmapBuffer(GL_ARRAY_BUFFER);

				if( glGetError() != GL_NO_ERROR ) {
					report("  error");
				}

				buf_it->second.mapped = false;
				buf_it->second.ptr = 0;
			}
		}
	}
	else {
		result = cudaErrorMapBufferObjectFailed;
	}
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

cudaError_t cuda::CudaRuntime::cudaGLUnmapBufferObjectAsync(GLuint bufObj, cudaStream_t stream) {
	assert(0 && "unimplemented");
}

cudaError_t cuda::CudaRuntime::cudaGLUnregisterBufferObject(GLuint bufObj) {
	cudaError_t result = cudaSuccess;
	lock();
	HostThreadContext & thread = getHostThreadContext();
	
	report("cudaGLUnregisterBufferObject");
	
	RegisteredGLBufferMap::iterator buf_it = thread.registeredGLbuffers.find(bufObj);
	if (buf_it != thread.registeredGLbuffers.end()) {
		if (buf_it->second.mapped) {
			if (context.getDeviceAddressSpace()) {
				assert(0 && "unimplemented");
			}
			else {
			}
			thread.registeredGLbuffers.erase(buf_it);
		}
	}
	else {
		result = cudaErrorMapBufferObjectFailed;
	}
	
	unlock();
	
	TestError(result);
	return setLastError(result);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void cuda::CudaRuntime::addTraceGenerator( trace::TraceGenerator& gen, bool persistent, 
	bool safe ) {

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

void cuda::CudaRuntime::clearTraceGenerators(bool safe) {
	lock();
	HostThreadContext & thread = getHostThreadContext();
	thread.persistentTraceGenerators.clear();
	thread.nextTraceGenerators.clear();
	unlock();
}

void cuda::CudaRuntime::limitWorkerThreads(unsigned int limit) {
	lock();
	getHostThreadContext();
	context.setWorkerThreadLimit((int)limit);
	unlock();
}

void cuda::CudaRuntime::registerPTXModule(std::istream& ptx, const std::string& name) {
	lock();
	getHostThreadContext();
	context.loadModule(name, false, ptx);
	executive::StringVector kernelNames = context.enumerateKernels(name);
	
	FatBinaryContext cubinContext;
	cubinContext.cubin_ptr = 0;
	fatBinaries.push_back(cubinContext);
	size_t handle = fatBinaries.size();

	for (executive::StringVector::iterator kernel = kernelNames.begin(); 
		kernel != kernelNames.end(); ++kernel) {
		void* symbol = (void*)nextSymbol++;
		assert(kernels.count(symbol) == 0);
		
		globalSymbolMap[symbol] = *kernel;
	
		RegisteredKernel registeredKernel;
		registeredKernel.handle = handle;
		registeredKernel.module = name;
		registeredKernel.kernel = *kernel;
		registeredKernel.pointer = symbol;
	
		kernels[symbol] = registeredKernel;
	}
	
	unlock();
}

void** cuda::CudaRuntime::getFatBinaryHandle(const std::string& name) {
	for (RegisteredKernelMap::iterator kernel = kernels.begin(); 
		kernel != kernels.end(); ++kernel) {
		if (kernel->second.module == name) {
			return (void**)kernel->second.handle;
		}
	}
	
	for (FatBinaryVector::iterator bin = fatBinaries.begin(); bin != fatBinaries.end(); ++bin) {
		if (bin->name() == name) {
			return (void**) std::distance(fatBinaries.begin(), bin);
		}
	}
	Ocelot_Exception("FatBinary " << name << " not registered.");
}

ocelot::KernelPointer 
	cuda::CudaRuntime::getKernelPointer(const std::string& name, 
	const std::string& module) {
	ocelot::KernelPointer symbol = 0;
	lock();
	for (RegisteredKernelMap::iterator kernel = kernels.begin(); 
		kernel != kernels.end(); ++kernel) {
		if (kernel->second.kernel == name && kernel->second.module == module) {
			symbol = (const char*)kernel->second.pointer;
			break;
		}	
	}
	if (symbol == 0) {
		unlock();
		Ocelot_Exception("Kernel " << name 
			<< " not registered in module " << module);
	}
	unlock();
	return symbol;
}

void cuda::CudaRuntime::reset() {
	lock();
	
	for (HostThreadContextMap::iterator thread = threads.begin(); 
		thread != threads.end(); ++thread) {
		thread->second.clear();
	}
	context.clear();
	kernels.clear();
	textures.clear();
	textureReferences.clear();
	globalSymbolMap.clear();
	fatBinaries.clear();
		
	unlock();
}

ocelot::PointerMap cuda::CudaRuntime::contextSwitch(unsigned int destination, 
	unsigned int source) {
	lock();
	ocelot::PointerMap map;
	try {
		map = std::move(context.contextSwitch(destination, source));
	}
	catch(...) {
		unlock();
		throw;
	}
	unlock();
	return std::move(map);
}

//////////////////////////////////////////////////////////////////////////////////////////////////

