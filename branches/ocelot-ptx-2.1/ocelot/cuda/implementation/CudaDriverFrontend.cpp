/*!
	\file CudaDriverFrontend.cpp

	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a CUDA Driver API front-end interface for GPU Ocelot
	\date Sept 16 2010
	\location somewhere over western Europe
*/

// C standard library includes
#include <assert.h>

// C++ standard library includes
#include <sstream>
#include <algorithm>

// Ocelot includes
#include <ocelot/cuda/interface/cuda.h>
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/cuda/interface/CudaDriverFrontend.h>
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

///////////////////////////////////////////////////////////////////////////////////////////////////

typedef api::OcelotConfiguration config;

cuda::CudaDriverFrontend *cuda::CudaDriverFrontend::_instance = 0;

class CudaDriverFrontendDestructor {
public:
	~CudaDriverFrontendDestructor() {
		if (cuda::CudaDriverFrontend::_instance) {
			report("!CudaDriverFrontendDestructor()");
			delete cuda::CudaDriverFrontend::_instance;
		}
	}
};

cuda::CudaDriverFrontend::CudaDriverFrontend():
	_devicesLoaded(false)
{
	_enumerateDevices();
}

cuda::CudaDriverFrontend::~CudaDriverFrontend() {
	// delete contexts
	for (ContextQueueThreadMap::iterator ctx_thread_it = _contexts.begin();
		ctx_thread_it != _contexts.end(); ++ctx_thread_it) {
		for (ContextQueue::iterator ctx_it = ctx_thread_it->second.begin(); 
			ctx_it != ctx_thread_it->second.end(); ++ctx_it) {
			delete *ctx_it;
		}
	}
}

cuda::CudaDriverFrontend * cuda::CudaDriverFrontend::get() {
	if (!_instance) {
		_instance = new CudaDriverFrontend;
	}
	return _instance;
}

//! \brief create devices if they do not exist
void cuda::CudaDriverFrontend::_enumerateDevices() {
	if(_devicesLoaded) return;
	report("Creating devices.");
	if(config::get().executive.enableNVIDIA) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::SASS, _flags);
		report(" - Added " << d.size() << " nvidia gpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableEmulated) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::Emulated, _flags);
		report(" - Added " << d.size() << " emulator devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableLLVM) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::LLVM, _flags);
		report(" - Added " << d.size() << " llvm-cpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableAMD) {
		executive::DeviceVector d =
			executive::Device::createDevices(ir::Instruction::CAL, _flags);
		report(" - Added " << d.size() << " amd gpu devices." );
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
}

//! \brief gets active context
cuda::CudaDriverFrontend::Context * cuda::CudaDriverFrontend::_getContext() {
	return _getThreadContextQueue().back();
}

//! \brief locks context thread map
void cuda::CudaDriverFrontend::_lock() {
	_mutex.lock();
}

//! \brief unlocks context thread map
void cuda::CudaDriverFrontend::_unlock() {
	_mutex.unlock();
}

cuda::CudaDriverFrontend::ContextQueue & cuda::CudaDriverFrontend::_getThreadContextQueue() {
	return _contexts[_getThreadId()];
}

//! \brief gets the calling thread's ID
boost::thread::id cuda::CudaDriverFrontend::_getThreadId() {
	return boost::this_thread::get_id();
}

//! \brief locks and gets the thread's active context
cuda::CudaDriverFrontend::Context * cuda::CudaDriverFrontend::_bind() {
	_lock();
	return _getContext();
}

//! \brief unlocks thread's active context
void cuda::CudaDriverFrontend::_unbind() {
	_unlock();
}


////////////////////////////////////////////////////////////////////////////////////////////////////

cuda::CudaDriverFrontend::Context::Context():
	_selectedDevice(0), _nextSymbol(0), _flags(0),
	_optimization(translator::Translator::DebugOptimization), _referenceCount(1) {

}

cuda::CudaDriverFrontend::Context::~Context() { 

}

//! \brief performs a memcpy on selected device
void cuda::CudaDriverFrontend::Context::_memcpy(void *dst, const void *src, size_t count, 
	MemcpyKind kind) {

}

//! \brief report a memory error and throw an exception
void cuda::CudaDriverFrontend::Context::_memoryError(const void *address, size_t count, 
	const std::string &func) {

}

//! \brief gets the current device for the current thread
executive::Device& cuda::CudaDriverFrontend::Context::_getDevice() {
	return *_device;
}

//! \brief returns an Ocelot-formatted error message
std::string cuda::CudaDriverFrontend::Context::_formatError(const std::string & message) {
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

// Load module and register it with all devices
void cuda::CudaDriverFrontend::Context::_registerModule(ModuleMap::iterator module) {

}

// Load module and register it with all devices
void cuda::CudaDriverFrontend::Context::_registerModule(const std::string& name) {

}

// Load all modules and register them with all devices
void cuda::CudaDriverFrontend::Context::_registerAllModules() {

}

///////////////////////////////////////////////////////////////////////////////////////////////////
			
/*********************************
** Initialization
*********************************/
CUresult cuda::CudaDriverFrontend::cuInit(unsigned int Flags) {
	//
	//
	// 
	return CUDA_SUCCESS;
}


/*********************************
** Driver Version Query
*********************************/
CUresult cuda::CudaDriverFrontend::cuDriverGetVersion(int *driverVersion) {
	*driverVersion = 0x3001;
	return CUDA_SUCCESS;
}


/************************************
**
**    Device management
**
***********************************/

CUresult cuda::CudaDriverFrontend::cuDeviceGet(CUdevice *device, int ordinal) {
	CUresult result = CUDA_ERROR_NOT_FOUND;
	_lock();
	if ((size_t)ordinal < _devices.size() && ordinal >= 0) {
		*device = ordinal;
		result = CUDA_SUCCESS;
	}
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuDeviceGetCount(int *count) {
	CUresult result = CUDA_ERROR_NOT_FOUND;
	_lock();
	result = CUDA_SUCCESS;
	*count = (int)_devices.size();
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuDeviceGetName(char *name, int len, CUdevice dev) {
	CUresult result = CUDA_ERROR_NOT_FOUND;
	_lock();
	int ordinal = (int)dev;
	executive::Device *device = _devices.at(ordinal);
	
	std::string devName = device->properties().name;
	std::memcpy(name, devName.c_str(), std::min(len, (int)devName.size()));
	result = CUDA_SUCCESS;
	
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuDeviceComputeCapability(int *major, int *minor, 
	CUdevice dev) {
	CUresult result = CUDA_ERROR_NOT_FOUND;
	_lock();

	int ordinal = (int)dev;
	executive::Device *device = _devices.at(ordinal);

	*major = device->properties().major;
	*minor = device->properties().minor;
	result = CUDA_SUCCESS;
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuDeviceTotalMem(unsigned int *bytes, CUdevice dev) {
	CUresult result = CUDA_ERROR_NOT_FOUND;
	_lock();

	int ordinal = (int)dev;
	executive::Device *device = _devices.at(ordinal);
	
	*bytes = device->properties().totalMemory;
	result = CUDA_SUCCESS;

	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuDeviceGetProperties(CUdevprop *prop, CUdevice dev) {
	CUresult result = CUDA_ERROR_NOT_FOUND;
	_lock();

	int ordinal = (int)dev;
	executive::Device *device = _devices.at(ordinal);
	//
	// TODO
	//
	assert(device);
	assert(0 && "cuDeviceGetProperties() not implemented yet");
	result = CUDA_ERROR_UNKNOWN;

	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, 
	CUdevice dev) {

	CUresult result = CUDA_ERROR_NOT_FOUND;
	_lock();

	int ordinal = (int)dev;
	executive::Device *device = _devices.at(ordinal);
	assert(device);
	switch (attrib) {
		case CU_DEVICE_ATTRIBUTE_COMPUTE_MODE:
			*pi = CU_COMPUTEMODE_EXCLUSIVE;
			result = CUDA_SUCCESS;
			break;
		default:
			*pi = 0;
			assert(0 && "cuDeviceGetAttribute() - unsupported attribute requested");
			break;
	}
	
	_unlock();
	return result;
}

/************************************
**
**    Context management
**
***********************************/

CUresult cuda::CudaDriverFrontend::cuCtxCreate(CUcontext *pctx, unsigned int flags, 
	CUdevice dev ) {

	_lock();

	// check to see if the device is in use - only support exclusive mode use of devices
	Context *newContext = new Context;
	
	*pctx = reinterpret_cast<CUcontext>(newContext);
	_getThreadContextQueue().push_back(newContext);
	
	_unlock();
	
	return CUDA_SUCCESS;
}

CUresult cuda::CudaDriverFrontend::cuCtxDestroy( CUcontext ctx ) {
	CUresult result = CUDA_ERROR_INVALID_VALUE;
	Context *context = reinterpret_cast<Context *>(ctx);
	_lock();
	if (_getThreadContextQueue().size() == 0 || _getThreadContextQueue().back() != context) {
		result = CUDA_ERROR_INVALID_CONTEXT;
	}
	else if (context->_referenceCount == 1) {
		_getThreadContextQueue().pop_back();
		delete context;
		result = CUDA_SUCCESS;
	}
	_unlock();

	return result;
}

CUresult cuda::CudaDriverFrontend::cuCtxAttach(CUcontext *pctx, unsigned int flags) {
	CUresult result = CUDA_ERROR_INVALID_VALUE;
	_lock();
	Context *context = 0;
	ContextQueue &queue = _getThreadContextQueue();
	if (queue.size()) {
		context = queue.back();
		++ context->_referenceCount;
		*pctx = reinterpret_cast<CUcontext>(context);
	}
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuCtxDetach(CUcontext ctx) {
	CUresult result = CUDA_ERROR_INVALID_CONTEXT;
	_lock();
	Context *context = reinterpret_cast<Context *>(ctx);
	ContextQueue &queue = _getThreadContextQueue();
	if (queue.size() == 0 || queue.back() != context) {
		result = CUDA_ERROR_INVALID_CONTEXT;
	}	
	else {
		if (!(--context->_referenceCount)) {
			// free context
		}
		result = CUDA_SUCCESS;
	}
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuCtxPushCurrent( CUcontext ctx ) {
	CUresult result = CUDA_SUCCESS;
	_lock();
	Context *context = reinterpret_cast<Context *>(ctx);
	ContextQueue &queue = _getThreadContextQueue();
	queue.push_back(context);
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuCtxPopCurrent( CUcontext *pctx ) {
	CUresult result = CUDA_ERROR_INVALID_CONTEXT;
	_lock();
	ContextQueue &queue = _getThreadContextQueue();
	if (queue.size()) {
		Context *context = queue.back();
		if (context->_referenceCount == 1) {
			queue.pop_back();
			*pctx = reinterpret_cast<CUcontext>(context);
			result = CUDA_SUCCESS;
		}
		else {
			result = CUDA_ERROR_INVALID_CONTEXT;
		}
	}
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuCtxGetDevice(CUdevice *device) {
	CUresult result = CUDA_ERROR_INVALID_CONTEXT;
	_lock();
	ContextQueue &queue = _getThreadContextQueue();
	if (queue.size()) {
		Context *context = queue.back();
		// return the thread's device
		*device = context->_selectedDevice;
		result = CUDA_SUCCESS;
	}
	_unlock();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuCtxSynchronize(void) {
	CUresult result = CUDA_ERROR_INVALID_CONTEXT;
	_lock();
	ContextQueue &queue = _getThreadContextQueue();
	if (queue.size()) {
		Context *context = queue.back();
		_unlock();
		// block on waiting operations
		context->_getDevice().synchronize();
		result = CUDA_SUCCESS;
	}
	else {
		_unlock();
	}
	return result;
}


/************************************
**
**    Module management
**

	CUresult result = CUDA_ERROR_NOT_FOUND;
	Context *context = _bind();
	if (context) {
		
		result = CUDA_SUCCESS;
	}
	_unbind();
	return result;

***********************************/

CUresult cuda::CudaDriverFrontend::cuModuleLoad(CUmodule *module, const char *fname) {
	CUresult result = CUDA_ERROR_NOT_FOUND;
	Context *context = _bind();
	if (context) {
		std::ifstream file(fname);
		if (file.good()) {
/*			ModuleMap::iterator module = _modules.insert(std::make_pair(fname, ir::Module())).first;
			if (module->second.load(fname)) {
				result = CUDA_SUCCESS;
				//
				// return 
				//
			}
			else {
				_modules.erase(module);
				result = CUDA_ERROR_INVALID_VALUE;
			}
			*/
			assert(0 && "unimplemented");
		}	
		else {
			report("cuModuleLoad() - failed to load module '" << fname << "' from file");
			result = CUDA_ERROR_FILE_NOT_FOUND;
		}
	}
	else {
		report("cuModuleLoad() - context not valid");
		result = CUDA_ERROR_INVALID_CONTEXT;
	}
	_unbind();
	return result;
}

CUresult cuda::CudaDriverFrontend::cuModuleLoadData(CUmodule *module, 
	const void *image) {
	assert(0 && "unimplemented");
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuModuleLoadDataEx(CUmodule *module, 
	const void *image, unsigned int numOptions, 
	CUjit_option *options, void **optionValues) {
	assert(0 && "unimplemented");
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuModuleLoadFatBinary(CUmodule *module, 
	const void *fatCubin) {
	assert(0 && "unimplemented");
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuModuleUnload(CUmodule hmod) {
	assert(0 && "unimplemented");
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuModuleGetFunction(CUfunction *hfunc, 
	CUmodule hmod, const char *name) {
	assert(0 && "unimplemented");
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuModuleGetGlobal(CUdeviceptr *dptr, 
	unsigned int *bytes, CUmodule hmod, const char *name) {
	assert(0 && "unimplemented");
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, 
	const char *name) {
	assert(0 && "unimplemented");
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Memory management
**
***********************************/

CUresult cuda::CudaDriverFrontend::cuMemGetInfo(unsigned int *free, 
	unsigned int *total) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuMemAlloc( CUdeviceptr *dptr, 
	unsigned int bytesize) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemAllocPitch( CUdeviceptr *dptr, 
			          unsigned int *pPitch,
			          unsigned int WidthInBytes, 
			          unsigned int Height, 
			          unsigned int ElementSizeBytes
			         ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemFree(CUdeviceptr dptr) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemGetAddressRange( CUdeviceptr *pbase, 
	unsigned int *psize, CUdeviceptr dptr ) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuMemAllocHost(void **pp, unsigned int bytesize) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemFreeHost(void *p) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuMemHostAlloc(void **pp, 
	unsigned long long bytesize, unsigned int Flags ) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuMemHostGetDevicePointer( CUdeviceptr *pdptr, 
	void *p, unsigned int Flags ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemHostGetFlags( unsigned int *pFlags, void *p ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Synchronous Memcpy
**
** Intra-device memcpy's done with these functions may execute 
**	in parallel with the CPU,
** but if host memory is involved, they wait until the copy is 
**	done before returning.
**
***********************************/

// 1D functions
// system <-> device memory
CUresult cuda::CudaDriverFrontend::cuMemcpyHtoD (CUdeviceptr dstDevice, 
	const void *srcHost, unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemcpyDtoH (void *dstHost, CUdeviceptr srcDevice, 
	unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}


// device <-> device memory
CUresult cuda::CudaDriverFrontend::cuMemcpyDtoD (CUdeviceptr dstDevice, 
	CUdeviceptr srcDevice, unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}


// device <-> array memory
CUresult cuda::CudaDriverFrontend::cuMemcpyDtoA ( CUarray dstArray, 
	unsigned int dstIndex, CUdeviceptr srcDevice, 
	unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemcpyAtoD ( CUdeviceptr dstDevice, 
	CUarray hSrc, unsigned int SrcIndex, unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}


// system <-> array memory
CUresult cuda::CudaDriverFrontend::cuMemcpyHtoA( CUarray dstArray, 
	unsigned int dstIndex, const void *pSrc, 
	unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemcpyAtoH( void *dstHost, CUarray srcArray, 
	unsigned int srcIndex, unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}


// array <-> array memory
CUresult cuda::CudaDriverFrontend::cuMemcpyAtoA( CUarray dstArray, 
	unsigned int dstIndex, CUarray srcArray, unsigned int srcIndex, 
	unsigned int ByteCount ) {
	return CUDA_ERROR_NOT_FOUND;
}


// 2D memcpy

CUresult cuda::CudaDriverFrontend::cuMemcpy2D( const CUDA_MEMCPY2D *pCopy ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemcpy2DUnaligned( const CUDA_MEMCPY2D *pCopy ) {
	return CUDA_ERROR_NOT_FOUND;
}


// 3D memcpy

CUresult cuda::CudaDriverFrontend::cuMemcpy3D( const CUDA_MEMCPY3D *pCopy ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Asynchronous Memcpy
**
** Any host memory involved must be DMA'able (e.g., 
** allocated with cuMemAllocHost).
** memcpy's done with these functions execute in parallel with 
** the CPU and, if
** the hardware is available, may execute in parallel with the GPU.
** Asynchronous memcpy must be accompanied by appropriate stream 
** synchronization.
**
***********************************/

// 1D functions
// system <-> device memory
CUresult cuda::CudaDriverFrontend::cuMemcpyHtoDAsync (CUdeviceptr dstDevice, 
const void *srcHost, unsigned int ByteCount, CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemcpyDtoHAsync (void *dstHost, 
CUdeviceptr srcDevice, unsigned int ByteCount, CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}


// system <-> array memory
CUresult cuda::CudaDriverFrontend::cuMemcpyHtoAAsync( CUarray dstArray, 
	unsigned int dstIndex, const void *pSrc, 
	unsigned int ByteCount, CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemcpyAtoHAsync( void *dstHost, CUarray srcArray, 
	unsigned int srcIndex, unsigned int ByteCount, 
	CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}


// 2D memcpy
CUresult cuda::CudaDriverFrontend::cuMemcpy2DAsync( const CUDA_MEMCPY2D *pCopy, 
	CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}


// 3D memcpy
CUresult cuda::CudaDriverFrontend::cuMemcpy3DAsync( const CUDA_MEMCPY3D *pCopy, 
	CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Memset
**
***********************************/
CUresult cuda::CudaDriverFrontend::cuMemsetD8( CUdeviceptr dstDevice, 
	unsigned char uc, unsigned int N ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemsetD16( CUdeviceptr dstDevice, 
	unsigned short us, unsigned int N ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemsetD32( CUdeviceptr dstDevice, 
	unsigned int ui, unsigned int N ) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuMemsetD2D8( CUdeviceptr dstDevice,
	unsigned int dstPitch, unsigned char uc, unsigned int Width, 
	unsigned int Height ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemsetD2D16( CUdeviceptr dstDevice, 
	unsigned int dstPitch, unsigned short us, unsigned int Width, 
	unsigned int Height ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuMemsetD2D32( CUdeviceptr dstDevice, 
	unsigned int dstPitch, unsigned int ui, unsigned int Width, 
	unsigned int Height ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Function management
**
***********************************/


CUresult cuda::CudaDriverFrontend::cuFuncSetBlockShape (CUfunction hfunc, int x, 
	int y, int z) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuFuncSetSharedSize (CUfunction hfunc, 
	unsigned int bytes) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuFuncGetAttribute (int *pi, 
	CUfunction_attribute attrib, CUfunction hfunc) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Array management 
**
***********************************/

CUresult cuda::CudaDriverFrontend::cuArrayCreate( CUarray *pHandle, 
	const CUDA_ARRAY_DESCRIPTOR *pAllocateArray ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuArrayGetDescriptor( 
	CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuArrayDestroy( CUarray hArray ) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuArray3DCreate( CUarray *pHandle, 
	const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuArray3DGetDescriptor( 
	CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray ) {
	return CUDA_ERROR_NOT_FOUND;
}



/************************************
**
**    Texture reference management
**
***********************************/
CUresult cuda::CudaDriverFrontend::cuTexRefCreate( CUtexref *pTexRef ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefDestroy( CUtexref hTexRef ) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuTexRefSetArray( CUtexref hTexRef, CUarray hArray, 
	unsigned int Flags ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefSetAddress( unsigned int *ByteOffset, 
	CUtexref hTexRef, CUdeviceptr dptr, unsigned int bytes ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefSetAddress2D( CUtexref hTexRef, 
	const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, 
	unsigned int Pitch) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefSetFormat( CUtexref hTexRef, 
	CUarray_format fmt, int NumPackedComponents ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefSetAddressMode( CUtexref hTexRef, int dim, 
	CUaddress_mode am ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefSetFilterMode( CUtexref hTexRef, 
	CUfilter_mode fm ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefSetFlags( CUtexref hTexRef, 
	unsigned int Flags ) {
	return CUDA_ERROR_NOT_FOUND;
}


CUresult cuda::CudaDriverFrontend::cuTexRefGetAddress( CUdeviceptr *pdptr, 
	CUtexref hTexRef ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefGetArray( CUarray *phArray, 
	CUtexref hTexRef ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefGetAddressMode( CUaddress_mode *pam, 
	CUtexref hTexRef, int dim ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefGetFilterMode( CUfilter_mode *pfm, 
	CUtexref hTexRef ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefGetFormat( CUarray_format *pFormat, 
	int *pNumChannels, CUtexref hTexRef ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuTexRefGetFlags( unsigned int *pFlags, 
	CUtexref hTexRef ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Parameter management
**
***********************************/

CUresult cuda::CudaDriverFrontend::cuParamSetSize (CUfunction hfunc, 
	unsigned int numbytes) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuParamSeti    (CUfunction hfunc, int offset, 
	unsigned int value) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuParamSetf    (CUfunction hfunc, int offset, 
	float value) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuParamSetv    (CUfunction hfunc, int offset, 
	void * ptr, unsigned int numbytes) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuParamSetTexRef(CUfunction hfunc, int texunit, 
	CUtexref hTexRef) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Launch functions
**
***********************************/

CUresult cuda::CudaDriverFrontend::cuLaunch ( CUfunction f ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuLaunchGrid (CUfunction f, int grid_width, 
	int grid_height) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuLaunchGridAsync( CUfunction f, int grid_width, 
	int grid_height, CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Events
**
***********************************/
CUresult cuda::CudaDriverFrontend::cuEventCreate( CUevent *phEvent, 
	unsigned int Flags ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuEventRecord( CUevent hEvent, CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuEventQuery( CUevent hEvent ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuEventSynchronize( CUevent hEvent ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuEventDestroy( CUevent hEvent ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuEventElapsedTime( float *pMilliseconds, 
	CUevent hStart, CUevent hEnd ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Streams
**
***********************************/
CUresult cuda::CudaDriverFrontend::cuStreamCreate( CUstream *phStream, 
	unsigned int Flags ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuStreamQuery( CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuStreamSynchronize( CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuStreamDestroy( CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    Graphics
**
***********************************/
CUresult cuda::CudaDriverFrontend::cuGraphicsUnregisterResource(
	CUgraphicsResource resource) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuGraphicsSubResourceGetMappedArray(
	CUarray *pArray, CUgraphicsResource resource, 
	unsigned int arrayIndex, unsigned int mipLevel ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuGraphicsResourceGetMappedPointer(
	CUdeviceptr *pDevPtr, unsigned int *pSize, 
	CUgraphicsResource resource ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuGraphicsResourceSetMapFlags(
	CUgraphicsResource resource, unsigned int flags ) {
	return CUDA_ERROR_NOT_FOUND;
}
 
CUresult cuda::CudaDriverFrontend::cuGraphicsMapResources(unsigned int count, 
	CUgraphicsResource *resources, CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuGraphicsUnmapResources(unsigned int count, 
	CUgraphicsResource *resources, CUstream hStream ) {
	return CUDA_ERROR_NOT_FOUND;
}


/************************************
**
**    OpenGL
**
***********************************/
CUresult cuda::CudaDriverFrontend::cuGLInit() {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuGLCtxCreate(CUcontext *pCtx, 
	unsigned int Flags, CUdevice device) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuGraphicsGLRegisterBuffer( 
	CUgraphicsResource *pCudaResource, unsigned int buffer, 
	unsigned int Flags ) {
	return CUDA_ERROR_NOT_FOUND;
}

CUresult cuda::CudaDriverFrontend::cuGraphicsGLRegisterImage( 
	CUgraphicsResource *pCudaResource, unsigned int image, 
	int target, unsigned int Flags) {
	return CUDA_ERROR_NOT_FOUND;
}


std::string cuda::CudaDriverFrontend::toString(CUresult result) {
	return "CUresult";
}

///////////////////////////////////////////////////////////////////////////////////////////////////

