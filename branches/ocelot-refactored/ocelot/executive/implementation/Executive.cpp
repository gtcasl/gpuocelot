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
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/executive/interface/Executive.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/GPUExecutableKernel.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>

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

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Ocelot executive construction/destruction
//

executive::Executive::Executive() {
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
	memoryAllocations[memory.addressSpace][ptr] = memory;
	
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

void executive::Executive::registerGlobalVariable(const char *module, const char *name, 
	void *hostPtr, void *devicePtr, size_t size, DeviceAddressSpace addrSpace) {
	
	//
	// register global variables and allocate [if necessary] on available address spaces
	//
	
	assert(0 && "unimplemented");
}

void executive::Executive::registerTexture(const char *module, const char *name, int dimensions,
	int normalized) {

	//
	// register global variables and allocate [if necessary] on available address spaces
	//
	
	assert(0 && "unimplemented");
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
	{
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
	}
	{
		// multicore
	}
	{
		// GPU
	}
	return devices.size();
}

/*! 
	selects a device [ this is intended to be a low-cost operation called at every CUDA runtime 
	API call]
*/
bool executive::Executive::selectDevice(int device) {
	selectedDevice = device;
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
			ir::Module::KernelDirectory & target = mod_it->second->kernelDirectory[ir::Instruction::PTX];
			for (ir::Module::KernelDirectory::iterator k_it = target.begin(); k_it != target.end(); 
				++k_it) {
				
				if (retranslate || mod_it->second->kernelDirectory[isa].find(k_it->second->name) ==
					mod_it->second->kernelDirectory[isa].end()) {
					translateToISA(isa, mod_it->first, k_it->second->name);
				}
			}
		}
	}
}

void executive::Executive::translateModuleToISA(std::string moduleName, 
	ir::Instruction::Architecture isa, bool retranslate) {
	
	ModuleMap::iterator mod_it = modules.find(moduleName);
	if (mod_it != modules.end()) {
		if (mod_it->second->kernels.find(ir::Instruction::PTX) != mod_it->second->kernels.end()) {
			ir::Module::KernelDirectory & target = mod_it->second->kernelDirectory[ir::Instruction::PTX];
			for (ir::Module::KernelDirectory::iterator k_it = target.begin(); k_it != target.end(); 
				++k_it) {
				
				if (retranslate || mod_it->second->kernelDirectory[isa].find(k_it->second->name) ==
					mod_it->second->kernelDirectory[isa].end()) {
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
			translator::Translator::OptimizationLevel level = translator::Translator::FullOptimization;
			LLVMExecutableKernel* llvmKernel = new LLVMExecutableKernel(*kernel, this, level);
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
		mod_it->second->insertKernel(isa, translated);
	}
	
	return translated;
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
	
	switch (isa) {
	case ir::Instruction::Emulated:
		{
			EmulatedKernel *emuKernel = static_cast<EmulatedKernel *>(kernel);
			emuKernel->setParameterBlock(parameterBlock, parameterBlockSize);
			emuKernel->setKernelShape(block.x, block.y, block.z);
			emuKernel->launchGrid(grid.x, grid.y);
		}
		break;
	
	case ir::Instruction::LLVM:
		{
			LLVMExecutableKernel *llvmKernel = static_cast<LLVMExecutableKernel*>(kernel);
			llvmKernel->setParameterBlock(parameterBlock, parameterBlockSize);
			llvmKernel->setKernelShape(block.x, block.y, block.z);
			llvmKernel->launchGrid(grid.x, grid.y);
		}
		break;
		
	case ir::Instruction::GPU:
		{
			GPUExecutableKernel *gpuKernel = static_cast<GPUExecutableKernel *>(kernel);
			gpuKernel->setParameterBlock(parameterBlock, parameterBlockSize);
			gpuKernel->setKernelShape(block.x, block.y, block.z);
			gpuKernel->launchGrid(grid.x, grid.y);
		}
		break;
		
	default:
		throw hydrazine::Exception("unsupported ISA selected for kernel launch");
	}
}
	
/*!
	\brief block on kernel executing on selected device
*/
void executive::Executive::synchronize() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
// 
//

