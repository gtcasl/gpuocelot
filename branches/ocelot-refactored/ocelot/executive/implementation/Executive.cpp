/*!
	\file Executive.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements Ocelot's executive manager
*/

// C stdlib includes
#include <assert.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

// C++ stdlib includes
#include <fstream>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/Executive.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/GPUExecutableKernel.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>
#include <ocelot/executive/interface/RuntimeException.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/interface/Casts.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot executive construction/destruction
//

executive::Executive::Executive() {

	// translator initialization
	hostWorkerThreads = api::OcelotConfiguration::getExecutive().workerThreadLimit;
	optimizationLevel = 
		(translator::Translator::OptimizationLevel)api::OcelotConfiguration::getExecutive().optimizationLevel;
	optimizationLevel = translator::Translator::MemoryCheckOptimization;
	enumerateDevices();
}

executive::Executive::~Executive() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Linear memory allocation functions
//
// note: each address space may require special handling
//

/*!
	Registers an external memory allocation
	\param ptr pointer to allocation
	\param bytes size of the allocation in bytes
	\param addressSpace address space of the allocation
*/
void executive::Executive::registerExternal(void *ptr, size_t bytes, int addressSpace) {
	MemoryAllocation memory;
	
	memory.structure = MemoryAllocation::Struct_linear;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.dimension = MemoryAllocation::Dim_1D;
	memory.addressSpace = addressSpace;
	memory.pointer.ptr = ptr;
	memory.pointer.xsize = bytes;
	memory.pointer.pitch = bytes;
	memory.pointer.ysize = 1;
	memory.internal = false;
	
	memoryAllocations[memory.addressSpace][memory.pointer.ptr] = memory;
}

bool executive::Executive::malloc(void **devPtr, size_t size) {
	bool result = true;
	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_linear;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.pointer.xsize = size;
	memory.pointer.pitch = size;
	memory.pointer.ysize = 1;
	memory.dimension = MemoryAllocation::Dim_1D;
	
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = size;
			memory.pointer.ptr = (void *)::malloc(size);
		}
		break;
		
	default:
		// device is in GPU memory somewhere
		assert(0 && "unimplemented");
		break;
	}
	
	*devPtr = memory.pointer.ptr;
	memoryAllocations[memory.addressSpace][*devPtr] = memory;
	
	return result;
}

bool executive::Executive::mallocHost(void **ptr, size_t size) {
	bool result = true;
	MemoryAllocation memory;
	
	memory.addressSpace = 0;
	memory.structure = MemoryAllocation::Struct_linear;
	memory.affinity = MemoryAllocation::Affinity_host;
	memory.pointer.xsize = size;
	memory.pointer.pitch = size;
	memory.pointer.ysize = 1;
	memory.dimension = MemoryAllocation::Dim_1D;
	
	switch (getDeviceAddressSpace()) {
	case 0:
		{
			memory.allocationSize = size;
			memory.pointer.ptr = (void *)::malloc(size);
		}
		break;
	default:
		// maybe use cuHostMalloc() instead
		assert(0 && "unimplemented");
	break;
	}
	
	*ptr = memory.pointer.ptr;
	memoryAllocations[memory.addressSpace][*ptr] = memory;
	
	report("Executive::mallocHost(" << *ptr << ")");
	
	return result;
}

bool executive::Executive::mallocPitch(void **devPtr, size_t *pitch, size_t width, 
	size_t height) {
	bool result = true;
	
	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_pitch;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.pointer.xsize = width;
	memory.pointer.ysize = height;

	memory.dimension = MemoryAllocation::Dim_2D;
		
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = width * height;
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize);
			memory.pointer.pitch = width;
		}
		break;
	default:
		// device is in GPU memory somewhere
		assert(0 && "unimplemented");		
		break;
	}
	
	*devPtr = memory.pointer.ptr;
	*pitch = memory.pointer.pitch;
	
	memoryAllocations[memory.addressSpace][*devPtr] = memory;
	
	return result;
}

bool executive::Executive::mallocArray(struct cudaArray **array, 
	const ChannelFormatDesc & desc, size_t width, size_t height) {
	bool result = true;

	MemoryAllocation memory;
	
	memory.addressSpace = getDeviceAddressSpace();
	
	memory.structure = MemoryAllocation::Struct_array;
	memory.affinity = MemoryAllocation::Affinity_device;
	memory.pointer.xsize = width;
	memory.pointer.ysize = height;
	memory.desc = desc;

	memory.dimension = MemoryAllocation::Dim_2D;
	
	switch (memory.addressSpace) {
	case 0:
		{
			// device is in host memory
			memory.allocationSize = width * height;
			memory.pointer.ptr = (void *)::malloc(memory.allocationSize);
			memory.pointer.pitch = width;
		}
		break;
	default:
		assert(0 && "unimplemented");
		break;
	}
	
	*array = (struct cudaArray *)memory.pointer.ptr;
	memoryAllocations[memory.addressSpace][memory.pointer.ptr] = memory;
	
	return result;
}

bool executive::Executive::free(void *devPtr) {
	bool result = true;
	
	MemoryAllocationMap::iterator it = memoryAllocations[getDeviceAddressSpace()].find(devPtr);
	if (it == memoryAllocations[getDeviceAddressSpace()].end()) {
		// not found
		assert(0 && "unimplemented");		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			if (it->second.internal) {
				::free(it->second.pointer.ptr);
			}
		}
		memoryAllocations[getDeviceAddressSpace()].erase(it);
	}
	return result;
}

bool executive::Executive::freeHost(void *ptr) {
	bool result = true;

	MemoryAllocationMap::iterator it = memoryAllocations[getDeviceAddressSpace()].find(ptr);
	if (it == memoryAllocations[getDeviceAddressSpace()].end()) {
		// not found
		report("Executive::freeHost(" << ptr << ")");
		
		assert(0 && "unimplemented");
		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			if (it->second.internal) {
				::free(it->second.pointer.ptr);
			}
		}
		memoryAllocations[getDeviceAddressSpace()].erase(it);
	}
	
	return result;
}

bool executive::Executive::freeArray(struct cudaArray *array) {
	bool result = true;
	MemoryAllocationMap::iterator it = memoryAllocations[getDeviceAddressSpace()].find((void *)array);
	if (it == memoryAllocations[getDeviceAddressSpace()].end()) {
		// not found
		assert(0 && "unimplemented");		
	}
	else {
		if (it->second.addressSpace) {
			// delete on CUDA device
			assert(0 && "unimplemented");
		}
		else {
			if (it->second.internal) {
				free(it->second.pointer.ptr);
			}
		}
		memoryAllocations[getDeviceAddressSpace()].erase(it);
	}
	return result;
}

bool executive::Executive::checkMemoryAccess(int device, const void* base, size_t size) const {
	bool found = true;
	
	/*
	int devAddrSpace = devices[device].addressSpace;
	MemoryAllocation allocation;
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(devAddrSpace);
	const MemoryAllocationMap & memoryMap = memoryMap_it->second;
	MemoryAllocationMap::const_iterator alloc_it = memoryMap.find((void *)ptr);
	if (alloc_it == memoryMap.end()) {
		// find nearest
		bool found = false;
		MemoryAllocationMap::const_iterator bound = memoryMap.upper_bound((void *)ptr);
		if (bound != memoryMap.end()) {
			char *base_ptr = (char *)bound->first;
			char *end_ptr = base_ptr + bound->second.size();
			if ((const char *)ptr >= base_ptr && ptr < end_ptr) {
				allocation = bound->second;
				found = true;
			}
		}
	}
	else {
		found = true;
	}
	*/
	
	return found;
}

/*!
	Given a pointer, determine the allocated block and 
	corresponding MemoryAllocation record to which it belongs.

	\param ptr pointer to some byte
	\return record of memory allocation; if nothing could be found, 
		the record's ISA is Unknown
*/
executive::MemoryAllocation executive::Executive::getMemoryAllocation(const void *ptr) const {
	
	MemoryAllocation allocation;
	DeviceMemoryAllocationMap::const_iterator memoryMap_it = memoryAllocations.find(getDeviceAddressSpace());
	const MemoryAllocationMap & memoryMap = memoryMap_it->second;
	MemoryAllocationMap::const_iterator alloc_it = memoryMap.find((void *)ptr);
	if (alloc_it == memoryMap.end()) {
		// find nearest
		bool found = false;
		MemoryAllocationMap::const_iterator bound = memoryMap.upper_bound((void *)ptr);
		if (bound != memoryMap.end()) {
			char *base_ptr = (char *)bound->first;
			char *end_ptr = base_ptr + bound->second.size();
			if ((const char *)ptr >= base_ptr && ptr < end_ptr) {
				allocation = bound->second;
				found = true;
			}
		}
		if (!found) {
			// throw an exception
			std::stringstream ss;
			ss << "device memory fault - device pointer " << std::hex << ptr 
				<< " does not point to an allocation on device " << std::dec 
				<< devices[getSelectedDevice()].name 
				<< "\n";
			if (bound != memoryMap.end()) {
				bound = memoryMap.lower_bound((void *)ptr);
			}
			if (bound != memoryMap.end()) {
				ss << "nearest allocation is " << std::dec << bound->second.pointer.ptr 
					<< std::dec << "\n";
			}
			throw hydrazine::Exception(ss.str());
		}
	}
	else {
		allocation = alloc_it->second;
	}
	
	return allocation;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Memcpy functions

/*!
	\brief copies to or from the selected device - will check whether device pointers are allocated
	
	\param dest pointer to destination
	\param src pointer to source
	\param size number of bytes to transfer
	\param indicates the kind of transfer
	\return true on success
*/
bool executive::Executive::deviceMemcpy(void *dest, const void *src, size_t size, 
	executive::MemcpyKind kind) {

	int selectedDevice = getSelectedDevice();
	int deviceAddrSpace = getDeviceAddressSpace();
	
	report("deviceMemcpy(" << std::hex << dest << ", " << src << std::dec << ", " << size << " bytes)");
	
	switch (kind) {
	case HostToHost:
	{
		::memcpy(dest, src, size);
		return true;
	}
	break;
	
	case HostToDevice:
	{
		if (checkMemoryAccess(selectedDevice, dest, size)) {
		
			switch (deviceAddrSpace) {
			case 0:
				{
					::memcpy(dest, src, size);
					return true;
				}
			break;
			default:
				{
					assert(0 && "address space not supported");
				}
			}
		}
		else {
			throw hydrazine::Exception("device memory fault");
		}
	}
	break;
	
	case DeviceToHost:
	{
		if (checkMemoryAccess(selectedDevice, src, size)) {
		
			switch (deviceAddrSpace) {
			case 0:
				{
					::memcpy(dest, src, size);
					return true;
				}
			break;
			default:
				{
					assert(0 && "address space not supported");
				}
			}
		}
		else {
			throw hydrazine::Exception("device memory fault");
		}
	}
	break;
	
	case DeviceToDevice:
	{
		if (checkMemoryAccess(selectedDevice, src, size) && 
			checkMemoryAccess(selectedDevice, dest, size)) {
			
			switch (deviceAddrSpace) {
			case 0:
				{
					::memcpy(dest, src, size);
					return true;
				}
			break;
			default:
				{
					assert(0 && "address space not supported");
				}
			}
		}
		else {
			throw hydrazine::Exception("device memory fault");
		}
	}
	break;
	
	default:
		throw hydrazine::Exception("device memory fault - kind invalid");
	}
	
	return false;
}

/*!
	\brief copies to a symbol on the device
	\param symbol name of symbol
	\param src pointer to source data
	\param count number of bytes to copy
	\param offset offset to add to destination
	\param kind indicates direction to copy - src must be Device
*/
bool executive::Executive::deviceMemcpyToSymbol(const char *symbol, const void *src, size_t count, 
	size_t offset, MemcpyKind kind) {
	
	GlobalVariable &globalVar = globals[std::string(symbol)];
	if (count + offset <= globalVar.size) {
		::memcpy((char *)globalVar.host_pointer + offset, src, count);
	}
	else {
		Ocelot_Exception("memcpyToSymbol attempting to copy more data to global variable than available");
	}
	
	return true;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// register functions

/*!
	\brief loads a PTX module
	\param path name of module
	\param ptx std::istream defining PTX module
*/
bool executive::Executive::loadModule(std::string path, bool translateOnLoad, std::istream & ptx) {

	//
	// parse PTX into a module with PTX kernels then translate to available devices
	//

	report("Loading module " << path << (translateOnLoad ? " translate on load" : ""));
	
	ir::Module *module = new ir::Module(path);
	module->load(ptx);
	module->modulePath = path;
	
	ModuleMap::iterator mod_it = modules.find(path);
	if (mod_it != modules.end()) {
		delete mod_it->second;
		modules.erase(mod_it);
	}
	
	modules.insert(std::make_pair(path, module));

	if (translateOnLoad) {
		translateModuleToISA(path, getSelectedISA(), true);
	}
	return true;
}

/*!
	\brief loads a module with a given name from a file
*/
bool executive::Executive::loadModule(std::string filename, bool translateOnLoad) {
	std::ifstream file(filename.c_str());
	return loadModule(filename, translateOnLoad, file);
}

void executive::Executive::registerGlobalVariable(const std::string & module, 
	const  std::string varName, void *hostPtr, void *devicePtr, size_t size, 
	DeviceAddressSpace addrSpace) {
	
	//
	// register global variables and allocate [if necessary] on available address spaces
	//
	
	GlobalMap::iterator g_it = globals.find(varName);
	if (g_it == globals.end()) {
		GlobalVariable globalVar;
		
		globalVar.name = varName;
		globalVar.host_pointer = hostPtr;
		globalVar.size = size;
		globalVar.modules[module] = devicePtr;
		globalVar.deviceAddressSpace = addrSpace;
		globals[varName] = globalVar;
	}
	else {
		globals[varName].modules[module] = devicePtr;
		const GlobalVariable &globalVar = globals[varName];
		if (globalVar.host_pointer != hostPtr) {
			Ocelot_Exception("previously registered global variable '" << varName 
				<< "' - has host pointer " << std::hex << globalVar.host_pointer 
				<< " - attempting to register with host ptr " << hostPtr << std::dec);
		}
		if (globalVar.size != size) {
			Ocelot_Exception("previously registered global variable '" << varName 
				<< "' - has size " << globalVar.size << " bytes"
				<< " - attempting to register with size " << size << " bytes");
		}
		if (globalVar.deviceAddressSpace != addrSpace) {
			Ocelot_Exception("previously registered global variable '" << varName 
				<< "' - in device address space " << globalVar.deviceAddressSpace
				<< " - attempting to register with addr space " << addrSpace);
		}
	}
}

void executive::Executive::registerTexture(const char *module, const char *name, int dimensions,
	int normalized) {

	//
	// register global variables and allocate [if necessary] on available address spaces
	//
	
	ir::Texture texture;
	texture.normalize = (bool)normalized;

	textures[name] = texture;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot kernel execution
//

/*!
	Gets a kernel by ISA, module, kernel name.

	\param isa instruction set of desired kernel
	\param moduleName name of module from which kernel is to be selected
	\param kernelName name of kernel

	\return instance of kernel with requested ISA or 0 on failure.
*/
ir::Kernel * executive::Executive::getKernel(ir::Instruction::Architecture isa, 
	const std::string& moduleName, const std::string& kernelName) {
	
	ir::Kernel * kernel	= 0;
	
	ModuleMap::iterator mod_it = modules.find(moduleName);
	if (mod_it != modules.end()) {
		kernel = mod_it->second->getKernel(isa, kernelName);
	}
	
	return kernel;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot device management

/*!
	inserts devices into device vector
*/
size_t executive::Executive::enumerateDevices() {
	if (api::OcelotConfiguration::getExecutive().enableEmulated) {
		// emulator
		Device device;
		device.ISA = ir::Instruction::Emulated;
		device.name = "Ocelot PTX Emulator";
		device.guid = 8803;
		device.totalMemory = get_avphys_pages() * getpagesize();
		device.multiprocessorCount = sysconf(_SC_NPROCESSORS_ONLN);
		device.memcpyOverlap = 0;
		device.maxThreadsPerBlock = 512;
		device.maxThreadsDim[0] = 512;
		device.maxThreadsDim[1] = 512;
		device.maxThreadsDim[2] = 64;
		device.maxGridSize[0] = 65535;
		device.maxGridSize[1] = 65535;
		device.maxGridSize[2] = 1;
		device.sharedMemPerBlock = 16384;
		device.totalConstantMemory = 65536;
		device.SIMDWidth = device.maxThreadsPerBlock;
		device.memPitch = device.totalMemory;
		device.regsPerBlock = MIN( INT_MAX, device.totalMemory );
		device.clockRate = 2000000;
		device.textureAlign = 1;
		device.major = 1;
		device.minor = 3;

		devices.push_back(device);
		
		if (devices.size() == 1 || 
			api::OcelotConfiguration::getExecutive().preferredISA == device.ISA) {

			selectDevice((int)devices.size() - 1);
		}
	}

#ifdef HAVE_LLVM
	if (api::OcelotConfiguration::getExecutive().enableLLVM) {
		// multicore
		Device device;
		device.ISA = ir::Instruction::LLVM;
		device.name = "Ocelot LLVM JIT-Compiler";
		device.guid = 8833;
		device.totalMemory = get_avphys_pages() * getpagesize();
		device.multiprocessorCount = sysconf(_SC_NPROCESSORS_ONLN);
		device.memcpyOverlap = 0;
		device.maxThreadsPerBlock = 512;
		device.maxThreadsDim[0] = 512;
		device.maxThreadsDim[1] = 512;
		device.maxThreadsDim[2] = 64;
		device.maxGridSize[0] = 65535;
		device.maxGridSize[1] = 65535;
		device.maxGridSize[2] = 1;
		device.sharedMemPerBlock = 16384;
		device.totalConstantMemory = 65536;
		device.SIMDWidth = 1;
		device.memPitch = device.totalMemory;
		device.regsPerBlock = MIN( INT_MAX, device.totalMemory );
		device.clockRate = 2000000;
		device.textureAlign = 1;
		device.major = 1;
		device.minor = 3;
		report( " Initialized PTX-To-LLVM JIT." );

		devices.push_back(device);

		if (api::OcelotConfiguration::getExecutive().preferredISA == device.ISA) {
			selectDevice((int)devices.size() - 1);
		}
	}#endif

	if (api::OcelotConfiguration::getExecutive().enableGPU) {
		// GPU
	}
	return devices.size();
}

/*! 
	selects a device [ this is intended to be a low-cost operation called at every CUDA runtime 
	API call]
*/
bool executive::Executive::selectDevice(int device) {
	if (device >= 0 && device < (int)devices.size()) {
		selectedDevice = device;
	}
	return true;
}

/*! 
	gets selected device identifier
*/
int executive::Executive::getSelectedDevice() const {
	return selectedDevice;
}

/*!
	gets the ISA of the selected device
*/
ir::Instruction::Architecture executive::Executive::getSelectedISA() const {
	return devices[selectedDevice].ISA;
}

/*!
	indicates preferred ISA [device will be chosen if available]
*/
void executive::Executive::setPreferredISA(ir::Instruction::Architecture isa) {
	assert(0 && "unimplemented");
}

bool executive::Executive::selectDeviceByISA(ir::Instruction::Architecture isa) {
	size_t n = 0;
	for (; n < devices.size(); n++) {
		if (devices[n].ISA == isa) {
			return selectDevice((int)n);
		}
	}
	return false;
}

/*! 
	\brief only listed devices may be selected
*/
void executive::Executive::filterDevices(std::vector<int> & devices) {
	assert(0 && "unimplemented");
}

/*!
	\brief only devices with listed ISAs may be selected
*/
void executive::Executive::filterISAs(std::vector<int> & ISAs) {
	assert(0 && "unimplemented");
}

/*!
	\brief returns the address space of the selected device
*/
int executive::Executive::getDeviceAddressSpace() const {
	return devices[selectedDevice].addressSpace;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot translation settings
//

/*!
	\brief This sets the optimization level 

	\param l The new optimization level.
*/
void executive::Executive::setOptimizationLevel(translator::Translator::OptimizationLevel l) {

}

/*!
	\brief ensures that all kernels have an executable translation for the indicated ISA	
*/
void executive::Executive::translateAllToISA(ir::Instruction::Architecture isa, bool retranslate) {
	ModuleMap::iterator mod_it = modules.begin();
	for (; mod_it != modules.end(); ++mod_it) {
		if (mod_it->second->kernels.find(ir::Instruction::PTX) != mod_it->second->kernels.end()) {
			ir::Module::KernelMap & target = mod_it->second->kernels[ir::Instruction::PTX];
			for (ir::Module::KernelMap::iterator k_it = target.begin(); k_it != target.end(); 
				++k_it) {
				
				if (retranslate || mod_it->second->kernels[isa].find(k_it->second->name) ==
					mod_it->second->kernels[isa].end()) {
					translateToISA(isa, mod_it->first, k_it->second->name);
				}
			}
		}
	}
}

/*!

*/
void executive::Executive::translateModuleToISA(std::string moduleName, 
	ir::Instruction::Architecture isa, bool retranslate) {
	
	ModuleMap::iterator mod_it = modules.find(moduleName);
	if (mod_it != modules.end()) {
		if (mod_it->second->kernels.find(ir::Instruction::PTX) != mod_it->second->kernels.end()) {
			ir::Module::KernelMap & target = mod_it->second->kernels[ir::Instruction::PTX];
			for (ir::Module::KernelMap::iterator k_it = target.begin(); k_it != target.end(); 
				++k_it) {
				
				if (retranslate || mod_it->second->kernels[isa].find(k_it->second->name) ==
					mod_it->second->kernels[isa].end()) {
					translateToISA(isa, mod_it->first, k_it->second->name);
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot kernel launch and synchronization functions
//

/*!
	\brief translates a kernel to the given ISA and inserts it into the module map
	\param isa ISA to translate to
	\param module name of module to which kernel belongs
	\param kernel name of kernel
	\return translated kernel or NULL on translation failure
*/
ir::Kernel *executive::Executive::translateToISA(ir::Instruction::Architecture isa, 
	const std::string &moduleName, const std::string &kernelName) {
	
	report("Executive::translateToISA(" << isa << ", module: " << moduleName 
		<< ", kernel: " << kernelName);
	
	ModuleMap::iterator mod_it = modules.find(moduleName);
	if (mod_it == modules.end()) {
		report("failed to find named module");
		throw hydrazine::Exception("failed to find module registerd with Ocelot");
	}
	
	ir::Kernel *translated = 0;
	ir::Kernel *kernel = mod_it->second->getKernel(ir::Instruction::PTX, kernelName);

	// translate
	switch (isa) {
		case ir::Instruction::Emulated:
		{
			EmulatedKernel *emuKernel = new EmulatedKernel(kernel, this);
			translated = emuKernel;
		}
		break;
	
		case ir::Instruction::LLVM:
		{
			LLVMExecutableKernel* llvmKernel = new LLVMExecutableKernel(*kernel, this, 
				optimizationLevel);

			llvmKernel->setDevice(&devices[getSelected()], hostWorkerThreads);
			//
			// ...
			//
			translated = llvmKernel;
		}
		break;
	
		case ir::Instruction::GPU:
		{
			//
			//
			assert(0 && "unimplemented");
		}
		break;
	
		default:
			break;
	}
	
	// insert kernel
	if (translated) {
		mod_it->second->kernels[isa][translated->name] = translated;
	}
	
	return translated;
}


/*!
	\brief limits the number of working threads available
*/
void executive::Executive::setWorkerThreadLimit(int limit) {
	hostWorkerThreads = limit;
}

/*!
	\brief determines whether kernel exceeds memory bounds through static analysis
	\param exeKernel executable kernel under test
	\param sharedMemory size of dynamic shared memory
	\param paramSize size of parameter memory
	\return true if kernel meets memory capacity
*/
bool executive::Executive::verifyKernelMemoryBounds(ir::ExecutableKernel *exeKernel, 
	size_t sharedMemory, size_t paramSize) {

	const executive::Device & device = devices[getSelected()];

	//
	// Ensure enough shared memory is available
	//
	size_t dynamicSharedSize = exeKernel->sharedMemorySize() + sharedMemory;
	if(dynamicSharedSize > (size_t)device.sharedMemPerBlock) {
#if CUDA_VERBOSE == 1
		std::cerr << "==Ocelot== Out of shared memory for kernel \""
			<< kernel->name 
			<< "\" : \n==Ocelot==\tpreallocated ";
		std::cerr << exeKernel->sharedMemorySize() << " + requested " 
			<< sharedMemory
			<< " is greater than available " 
			<< device.sharedMemPerBlock 
			<< " for device " << device.name 
			<< "\n" << std::flush;
#endif
		return false;
	}

	if((size_t)exeKernel->constMemorySize() > (size_t)device.totalConstantMemory) {
#if CUDA_VERBOSE == 1
		std::cerr << "==Ocelot== Out of const memory for kernel \"" 
			<< exeKernel->name 
			<< "\" : \n==Ocelot==\tpreallocated ";
		std::cerr << exeKernel->constMemorySize() 
			<< " is greater than available " 
			<< device.totalConstantMemory 
			<< " for device " << device.name << "\n" << std::flush;
#endif
		return false;
	}

	return true;
}

/*!
	\brief helper function for launching a kernel
	\param module module name
	\param kernel kernel name
	\param grid grid dimensions
	\param block block dimensions
	\param sharedMemory shared memory size
	\param parameterBlock array of bytes for parameter memory
	\param parameterBlockSize number of bytes in parameter memory
*/
void executive::Executive::launch(const std::string & moduleName, const std::string & kernelName,
	dim3 grid, dim3 block, size_t sharedMemory, unsigned char *parameterBlock,
	size_t parameterBlockSize) {

	trace::TraceGeneratorVector none;

	// launch with no trace generators
	this->launch(moduleName, kernelName, grid, block, sharedMemory, parameterBlock, 
		parameterBlockSize, none);
}

/*!
	\brief helper function for launching a kernel
	\param module module name
	\param kernel kernel name
	\param grid grid dimensions
	\param block block dimensions
	\param sharedMemory shared memory size
	\param parameterBlock array of bytes for parameter memory
	\param parameterBlockSize number of bytes in parameter memory
	\param traceGenerators vector of trace generators to run on kernel
*/
void executive::Executive::launch(const std::string & moduleName, const std::string & kernelName,
	dim3 grid, dim3 block, size_t sharedMemory, unsigned char *parameterBlock,
	size_t parameterBlockSize, const trace::TraceGeneratorVector & traceGenerators) {
	
	report("launch('" << moduleName << "', '" << kernelName << "')");
	report("   grid: " << grid.x << ", " << grid.y << ", " << grid.z);
	report("  block: " << block.x << ", " << block.y << ", " << block.z);
	report("  shmem: " << sharedMemory);
	report("  param block size: " << parameterBlockSize << " bytes");
	
	ir::Instruction::Architecture isa = getSelectedISA();
	ir::Kernel *kernel = getKernel(isa, moduleName, kernelName);
	if (!kernel) {
		kernel = translateToISA(isa, moduleName, kernelName);
	}
	ir::ExecutableKernel *exeKernel = static_cast<ir::ExecutableKernel *>(kernel);	
	
	fenceGlobalVariables();

	if (!verifyKernelMemoryBounds(exeKernel, sharedMemory, parameterBlockSize)) {
		return;
	}

	if (isa == ir::Instruction::Emulated && api::OcelotConfiguration::getTrace().enabled) {
		for( trace::TraceGeneratorVector::const_iterator gen = traceGenerators.begin(); 
			gen != traceGenerators.end(); ++gen) {
			exeKernel->addTraceGenerator( *gen );
		}
	}

	exeKernel->setKernelShape(block.x, block.y, block.z);

	if (parameterBlockSize) {
		exeKernel->setParameterBlock(parameterBlock, parameterBlockSize);
	}

	exeKernel->updateParameterMemory();
	exeKernel->updateMemory();
	if (sharedMemory) {
		exeKernel->setExternSharedMemorySize(sharedMemory);
	}
	
	try {
		exeKernel->launchGrid(grid.x, grid.y);
	}
	catch (executive::RuntimeException &exp) {
		report("Runtime exception: " << exp.toString());
		throw;
	}

	if (isa == ir::Instruction::Emulated && api::OcelotConfiguration::getTrace().enabled) {
		// remove trace generators
		if (api::OcelotConfiguration::get().trace.enabled) {
			for( trace::TraceGeneratorVector::const_iterator gen = traceGenerators.begin(); 
				gen != traceGenerators.end(); ++gen) {
				exeKernel->removeTraceGenerator( *gen );
			}
		}
	}
}
	
/*!
	\brief block on kernel executing on selected device
*/
void executive::Executive::synchronize() {
	ir::Instruction::Architecture isa = getSelectedISA();
	switch (isa) {
		case ir::Instruction::Emulated:	// fall through
		case ir::Instruction::LLVM:
			break;
		case ir::Instruction::GPU:
			break;
		default:
			break;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Global variable synchronization
//

void executive::Executive::fenceGlobalVariables() {
	if (getDeviceAddressSpace()) {
		assert(0 && "devices with non-system address spaces not yet supported");
		for (GlobalMap::iterator glb_it = globals.begin(); glb_it != globals.end(); ++glb_it) {
			// do something
		}
	}
	else {
		//
		// do something else entirely
		//
		for (GlobalMap::iterator glb_it = globals.begin(); glb_it != globals.end(); ++glb_it) {
			// do something about each module
			
			if (glb_it->second.deviceAddressSpace != Device_shared) {
				std::map< std::string, void *>::iterator mod_it = glb_it->second.modules.begin();
				for (; mod_it != glb_it->second.modules.end(); ++mod_it) {
					ir::Global & global = modules[mod_it->first]->globals[glb_it->first];
					global.pointer = (char *)glb_it->second.host_pointer;
					global.registered = true;
					global.local = true;
				}
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Texture binding and unbinding functions

/*!
	\brief binds a texture by name to a pointer to a device memory allocation
	\param offset [out] offset that must be added to fetches to achieved desired pixel
	\param texture name of texture
	\param devPtr device memory allocation
	\param format channel description
	\param size bytes in texture
	\return true on success
*/
bool executive::Executive::bindTexture(size_t *offset, const std::string & texture, 
	const void *devPtr, const ChannelFormatDesc &format, size_t size) {

	assert(0 && "unimplemented");

	return true;
}

/*!
	\brief binds a 2D texture by name to a device pointer with a given width, height, and pitch
	\param offset [out] offset that must be added to fetches to achieved desired pixel
	\param textureName name of texture
	\param devPtr device memory allocation
	\param format channel description
	\param width width of texture in texels
	\param height height of texture in texels
	\param pitch number of bytes between texels of the same column in consecutive rows
	\return true on success
*/
bool executive::Executive::bindTexture2D(size_t *offset, const std::string & textureName, 
	const void *devPtr, const ChannelFormatDesc &format, size_t width, size_t height, size_t pitch) {

	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {
		ir::Texture &texture = tex_it->second;

		texture.x = format.x;
		texture.y = format.y;
		texture.z = format.z;
		texture.w = format.w;

		switch (format.kind) {
			case ChannelFormatDesc::Kind_signed:
				texture.type = ir::Texture::Signed;
				break;
			case ChannelFormatDesc::Kind_unsigned:
				texture.type = ir::Texture::Unsigned;
				break;
			case ChannelFormatDesc::Kind_float:
				texture.type = ir::Texture::Float;
				break;
			default:
				texture.type = ir::Texture::Invalid;
				break;
		}

		texture.size.x = width;
		texture.size.y = height;
		texture.data = (void *)devPtr;

		if (offset) {
			*offset = (size_t)devPtr % 16;
		}
	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
		return false;
	}

	return true;
}

/*!
	\brief binds a texture to an array
*/
bool executive::Executive::bindTextureToArray(const std::string & textureName, void *array, 
	const ChannelFormatDesc &desc) {

	assert(0 && "unimplemented");

	return false;
}

/*!
	\brief unbinds a previously bound texture
*/
void executive::Executive::unbindTexture(const std::string & textureName) {
	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {
		ir::Texture &texture = tex_it->second;
		texture.data = 0;
	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
	}
}

/*!
	gets alignment of a named texture
*/
size_t executive::Executive::getTextureAlignmentOffset(const std::string & textureName) {
	size_t offset = 0;
	TextureMap::iterator tex_it = textures.find(textureName);
	if (tex_it != textures.end()) {

	}
	else {
		Ocelot_Exception("Texture '" << textureName << "' was not registered");
	}
	return offset;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// end

