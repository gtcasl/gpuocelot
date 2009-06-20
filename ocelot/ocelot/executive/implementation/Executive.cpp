/*!
	\file Executive.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date Jan 16, 2009
	
	\brief class definition for loading modules, enumerating devices,
		and executing kernels on the selected device
*/

#include <assert.h>
#include <sys/sysinfo.h>

#include <ocelot/executive/interface/Executive.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <cstring>

#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

executive::Executive::Executive() {
	enumerateDevices();
}

executive::Executive::~Executive() {
	//free memory
	for (DeviceAllocationMap::iterator device = memoryAllocations.begin(); 
		device != memoryAllocations.end(); ++device) {
		for (AllocationMap::iterator allocation = device->second.begin(); 
			allocation != device->second.end(); ++allocation ) {
			delete[] (char*)allocation->second.ptr;
		}
	}
	// free modules
	for(ModuleMap::iterator module = modules.begin(); 
		module != modules.end(); ++module) {
		delete module->second;
	}
}

/*!
	Loads a module from a PTX source file. If the module is succesfully
	loaded, it may be obtained by indexing the modules[] map with the
	path name provided.
	
	\param path name of PTX source file
	\param translateToSelected after successful load, indicates whether module
		should be translated to selected device's ISA
	\return true if module loaded
*/
bool executive::Executive::loadModule(const std::string& path, 
	bool translateToSelected, std::istream* stream) {
	using namespace ir;
	report("Loading module " << path);
	ModuleMap::iterator m_it = modules.find(path);
	if (m_it != modules.end()) {
		delete m_it->second;
		modules.erase(m_it);
	}
	if ( stream == 0 ) {
		m_it = modules.insert(std::make_pair(path,new Module(path))).first;
	}
	else {	
		m_it = modules.insert(std::make_pair(path,new Module)).first;
		m_it->second->load( *stream );
		m_it->second->modulePath = path;
	}
	if (translateToSelected) {
		// translate the kernels of a module to the selected ISA
		if (getSelectedISA() == Instruction::Emulated) {
			// translate each PTX kernel to Emulated
			Module::KernelMap::iterator it = m_it->second->kernels.find(Instruction::PTX);
			if (it == m_it->second->kernels.end() ) {
				return true;
			}
			for (Module::KernelVector::iterator k_it = it->second.begin();
				k_it != it->second.end(); ++k_it) {
				EmulatedKernel *emKern = new EmulatedKernel(*k_it);
				m_it->second->kernels[Instruction::Emulated].push_back(emKern);
			} 
		}
	}
	return true;
}
		
/*!
	Unloads a module
*/
bool executive::Executive::unloadModule(const std::string& path) {
	ModuleMap::iterator m_it = modules.find(path);
	if (m_it != modules.end()) {
		delete m_it->second;
		modules.erase(m_it);
		return true;
	}
	return false;
}

/*!
	Blocks until all possibly executing kernels have completed.
*/
void executive::Executive::synchronize() {
	
}

/*!
	Enumerate available devices
*/
void executive::Executive::enumerateDevices() {
#if USE_CUDA_DRIVER_API
	int cudaDevices = 0;
	if (cuDeviceGetCount(&cudaDevices) == CUDA_SUCCESS) {
		for (int i = 0; i < cudaDevices; i++) {
			char devname[256] = {0};
			Device deviceDesc;
			CUdevice cudaDevice;
			CUdevprop prop;
			
			if (cuGetDevice(&cudaDevice, i) != CUDA_SUCCESS) {
				continue;
			}
			
			cuDeviceGetProperties(&prop, cudaDevice);
			cuGetDeviceName(devname, 255, i);
			device.ISA = ir::Instruction::GPU;
			device.name = std::string(devname);
			device.guid = i;
			device.maxThreadsPerBlock = prop.maxThreadsPerBlock;
			for (int j = 0; j < 3; j++) {
				device.maxThreadsDim[j] = prop.maxThreadsDim[j];
				device.maxGridSize[j] = prop.maxGridSize[j];
			}
			device.sharedMemPerBlock = prop.sharedMemPerBlock;
			device.totalConstantMemory = prop.totalConstantMemory;
			device.SIMDWidth = prop.SIMDwidth;
			device.memPitch = prop.memPitch;
			device.regsPerBlock = prop.regsPerBlock;
			device.clockRate = prop.clockRate;
			device.textureAlign = prop.textureAlign;
			device.major = prop.major;
			device.minor = prop.minor;
			
			device.multiprocessorCount = 0;
			cuDeviceGetAttribute(&device.multiprocessorCount,
				CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, cudaDev);
			
			cuDeviceGetAttribute(&device.memcpyOverlap,
				CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, cudaDev);
			
			cuDeviceGetTotalMem(&device.totalMemory, cudaDev);
			
			devices.push_back(device);
		}
	}
#endif
	{
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
}

/*!
	Select a device by GUID
*/
bool executive::Executive::select(int device) {
	for (int i = 0; i < (int)devices.size(); i++) {
		if (devices[i].guid == device) {
			if (devices[i].ISA == ir::Instruction::GPU) {
#if USE_CUDA_DRIVER_API
				if (cuDeviceGet(&cudaDevice, device) == CUDA_SUCCESS) {
					if (cuCtxCreate(&cudaContext, CU_CTX_SCHED_AUTO, 
						cudaDevice) == CUDA_SUCCESS) {
						selectedDevice = i;
						return true;
					}
				}
				else {
					return false;
				}
#else
			assert(0 == "The executive was compiled without support for CUDA");
#endif
			}
			else if (devices[i].ISA == ir::Instruction::Emulated) {
				selectedDevice=  i;
				return true;
			}
		}
	}
	return false;
}

/*!
	Selects a device given an ISA
*/
bool executive::Executive::selectDeviceByISA(ir::Instruction::Architecture ISA) {
	for (int i = 0; i < (int)devices.size(); i++) {
		if (devices[i].ISA == ISA) {
			if (devices[i].ISA == ir::Instruction::GPU) {
#if USE_CUDA_DRIVER_API
				if (cuDeviceGet(&cudaDevice, device) == CUDA_SUCCESS) {
					if (cuCtxCreate(&cudaContext, CU_CTX_SCHED_AUTO, 
						cudaDevice) == CUDA_SUCCESS) {
						selectedDevice = i;
						return true;
					}
				}
				else {
					return false;
				}
#else
			assert(0 == "The executive was compiled without support for CUDA");
#endif
			}
			else if (devices[i].ISA == ir::Instruction::Emulated) {
				selectedDevice = i;
				return true;
			}
		}
	}
	return false;
}

/*!
	Returns the index of the selected device
*/
int executive::Executive::getSelected() const {
	return selectedDevice;
}

/*!
	Returns the ISA of the selected device or PTX if no device selected
*/
ir::Instruction::Architecture executive::Executive::getSelectedISA() const {
	if (selectedDevice >= 0) {
		return devices[selectedDevice].ISA;
	}
	return ir::Instruction::PTX;
}

/*!
	Gets a kernel by ISA, module, kernel name.

	\param isa instruction set of desired kernel
	\param module name of module from which kernel is to be selected
	\param kernelName name of kernel

	\return instance of kernel with requested ISA or 0 on failure.
*/
ir::Kernel * executive::Executive::getKernel(ir::Instruction::Architecture isa, 
	const std::string& module, 
	const std::string& kernelName) {
	ModuleMap::iterator m_it = modules.find(module);
	if (m_it != modules.end()) {
		return m_it->second->getKernel(isa, kernelName);
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	Allocate <bytes> of memory on the device

	\return pointer to allocated memory block or NULL on error
*/
void *executive::Executive::malloc(size_t bytes) {
	using namespace std;

	switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{
				MemoryAllocation record;
				record.isa = ir::Instruction::Emulated;
				record.device = getSelected();
				record.external = false;
				record.size = bytes;
				record.ptr = (void *)(new char[bytes]);	// change this with some other call if need be
				memoryAllocations[getSelected()].insert(
					std::make_pair((char*)record.ptr,record));
				return record.ptr;
				
			}
			break;
/*
		case ir::Instruction::GPU:
			{

			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;
		case ir::Instruction::x86:
			{

			}
			break;
		case ir::Instruction::x86_64:
			{

			}
			break;
		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			break;
	}
	return 0;
}

void executive::Executive::registerExternal(void* pointer, size_t bytes) {
	using namespace std;

	switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{
				MemoryAllocation record;
				record.isa = ir::Instruction::Emulated;
				record.device = getSelected();
				record.size = bytes;
				record.external = true;
				record.ptr = pointer;	// change this with some other call if need be
				memoryAllocations[getSelected()].insert(
					std::make_pair((char*)record.ptr,record));
				
			}
			break;
/*
		case ir::Instruction::GPU:
			{

			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;
		case ir::Instruction::x86:
			{

			}
			break;
		case ir::Instruction::x86_64:
			{

			}
			break;
		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			break;
	}
}

void executive::Executive::registerGlobal(void *ptr, size_t bytes, 
	const std::string& name, ir::PTXInstruction::AddressSpace space, 
	const std::string& modulePath) {
	using namespace std;

	switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{

				report( "Registering global variable " << name 
					<< " in module " << modulePath );

				ModuleMap::iterator module = modules.find(modulePath);
				if (module == modules.end()) {
					throw hydrazine::Exception( "Module " + modulePath 
						+ " does not exist." );
				}

				ir::Module::GlobalMap::iterator 
					global = module->second->globals.find(name);
				if (global == module->second->globals.end()) {
					throw hydrazine::Exception("Global variable " 
						+ name + " not declared in module " + modulePath);
				}

				if (global->second.registered) {
					throw hydrazine::Exception("Duplicate global variable " 
						+ name + " registered in module " + modulePath);
				}

				if (global->second.local) {
					global->second.local = false;
					std::memcpy(ptr, global->second.pointer, bytes);
					delete[] global->second.pointer;
				}

				global->second.pointer = (char*) ptr;

				if (global->second.statement.bytes() > bytes) {
					std::stringstream stream;
					stream << "Insufficient storage " << bytes 
						<< " at " << ptr << " for global " << name 
						<< " in module " << modulePath << " (needs " 
						<< global->second.statement.bytes() << ")";
					throw hydrazine::Exception(stream.str());	
				}
				
				global->second.registered = true;

			}
			break;
/*
		case ir::Instruction::GPU:
			{

			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;
		case ir::Instruction::x86:
			{

			}
			break;
		case ir::Instruction::x86_64:
			{

			}
			break;
		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			assert("Invalid type" == 0);
			break;
	}
}

void executive::Executive::registerTexture(const ir::Texture& t, 
	const std::string& name, const std::string& modulePath) {
	using namespace std;

	switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{

				report( "Registering texture variable " << name 
					<< " in module " << modulePath );

				ModuleMap::iterator module = modules.find(modulePath);
				if (module == modules.end()) {
					throw hydrazine::Exception( "Module " + modulePath 
						+ " does not exist." );
				}

				ir::Module::GlobalMap::iterator 
					global = module->second->globals.find(name);
				if (global == module->second->globals.end()) {
					throw hydrazine::Exception("Global variable " 
						+ name + " not declared in module " + modulePath);
				}

				if (global->second.registered) {
					throw hydrazine::Exception("Duplicate texture variable " 
						+ name + " registered in module " + modulePath);
				}

				ir::Module::TextureMap::iterator 
					texture = module->second->textures.find(name);
				assert(texture != module->second->textures.end());
				texture->second = t;

				global->second.registered = true;

			}
			break;
/*
		case ir::Instruction::GPU:
			{

			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;
		case ir::Instruction::x86:
			{

			}
			break;
		case ir::Instruction::x86_64:
			{

			}
			break;
		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			assert("Invalid type" == 0);
			break;
	}
}


/*!
	\brief Bind a texture to another memory allocation
	\param target Pointer to the variable to bind the texture to
	\param texture Pointer to the texture variable
*/
void executive::Executive::rebind(const std::string& modulePath, 
	const std::string& texture, void* target, unsigned int width, 
	unsigned int height, unsigned int length, const ir::Texture& t) {
		switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{
				report( "Rebinding texture " << texture
					<< " to variable " << target );
				ModuleMap::iterator module = modules.find(modulePath);

				if (module == modules.end()) {
					throw hydrazine::Exception( "Module " + modulePath 
						+ " does not exist." );
				}

				ir::Module::GlobalMap::iterator 
					texture_it = module->second->globals.find(texture);
				if (texture_it == module->second->globals.end()) {
					throw hydrazine::Exception("Texture variable " 
						+ texture + " not declared in module " + modulePath, 1);
				}
				else if( texture_it->second.statement.directive 
					!= ir::PTXStatement::Tex ) {
					throw hydrazine::Exception("Invalid texture reference", 1);
				}
				
				if (!texture_it->second.registered) {
					throw hydrazine::Exception("Texture variable " 
						+ texture + " not registered in module " + modulePath);
				}

				if( target != 0 ) {
					if( memoryAllocations[getSelected()].count( 
						(char*) target ) == 0 ){
						throw hydrazine::Exception(
							"Invalid texture binding", 2);
					}
				}

				ir::Module::TextureMap::iterator 
					m_it = module->second->textures.find(texture);
				assert(m_it != module->second->textures.end());
				
				report( " Texture was previously bound to " 
					<< m_it->second.data );
				m_it->second.data = target;
				m_it->second.x = t.x;
				m_it->second.y = t.y;
				m_it->second.z = t.z;
				m_it->second.w = t.w;
				m_it->second.type = t.type;
				m_it->second.size.x = width;
				m_it->second.size.y = height;
				m_it->second.size.z = length;
								
				m_it->second.normalize = t.normalize;
				m_it->second.interpolation = t.interpolation;
				m_it->second.addressMode[0] = t.addressMode[0];
				m_it->second.addressMode[1] = t.addressMode[1];
				m_it->second.addressMode[2] = t.addressMode[2];
				
				if( target == 0 ) {
					m_it->second.type = ir::Texture::Invalid;
				}
				
			}
			break;
/*
		case ir::Instruction::GPU:
			{

			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;
		case ir::Instruction::x86:
			{

			}
			break;
		case ir::Instruction::x86_64:
			{

			}
			break;
		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			assert("Invalid type" == 0);
			break;
	}
}

/*!
	Free a memory block allocated to this device.

	\param ptr pointer to allocated memory block
*/
void executive::Executive::free(void *ptr) {
	using namespace std;

	switch (getSelectedISA()) {

		case ir::Instruction::Emulated:
			{
				
				DeviceAllocationMap::iterator l_it = 
					memoryAllocations.find(getSelected());
				assert (l_it != memoryAllocations.end());
				AllocationMap::iterator it = 
					l_it->second.lower_bound((char*)ptr);
				assert(it != l_it->second.end());
				assert((char*)ptr < ((char*)it->second.ptr + it->second.size));

				if (!it->second.external) {
					delete [] (char *)it->second.ptr;	// if another allocation scheme is required, modify this
				}
				
				l_it->second.erase(it);
				return;
				
			}
			break;

/*
		case ir::Instruction::GPU:
			{
				// allocate on the GPU
			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;

		case ir::Instruction::x86:
			{

			}
			break;

		case ir::Instruction::x86_64:
			{

			}
			break;

		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			break;
	}
}

void executive::Executive::freeGlobal(const std::string& name, 
	const std::string& modulePath) {
	using namespace std;

	switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{

				report( "Freeing global variable " << name 
					<< " from emulated kernels in module " << modulePath );

				ModuleMap::iterator module = modules.find(modulePath);
				if (module == modules.end()) {
					throw hydrazine::Exception( "Module " + modulePath 
						+ " is unknown." );
				}

				ir::Module::GlobalMap::iterator 
					global = module->second->globals.find(name);
				if (global == module->second->globals.end()) {
					throw hydrazine::Exception("Global variable " 
						+ name + " not declared in module " + modulePath);
				}
				
				if (global->second.local) {
					throw hydrazine::Exception(
						"Cannot free preinitialized global " 
						+ name + " in module " + modulePath);
				}
				
				global->second.registered = false;

			}
			break;
/*
		case ir::Instruction::GPU:
			{

			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;
		case ir::Instruction::x86:
			{

			}
			break;
		case ir::Instruction::x86_64:
			{

			}
			break;
		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			assert("Invalid type" == 0);
			break;
	}
}
		
void executive::Executive::memcpy( void* dest, const void* src, size_t bytes, 
	MemoryCopy type ) {
	switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{
				std::memcpy( dest, src, bytes );
			}
			break;

/*
		case ir::Instruction::GPU:
			{
				// copy on the GPU
			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;

		case ir::Instruction::x86:
			{

			}
			break;

		case ir::Instruction::x86_64:
			{

			}
			break;

		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			break;
	}
	
}

void executive::Executive::memset( void* dest, int value, size_t bytes ) {
	switch (getSelectedISA()) {
		case ir::Instruction::Emulated:
			{
				std::memset( dest, value, bytes );
			}
			break;

/*
		case ir::Instruction::GPU:
			{
				// copy on the GPU
			}
			break;
		case ir::Instruction::LLVM:
			{

			}
			break;

		case ir::Instruction::x86:
			{

			}
			break;

		case ir::Instruction::x86_64:
			{

			}
			break;

		case ir::Instruction::SPU:
			{

			}
			break;
*/
		default:	// PTX or invalid
			break;
	}
	
}
		
/*!
	Given a pointer, determine the allocated block and corresponding MemoryAllocation record
	to which it belongs. This merely performs a linear search, so uh a better data structure
	might improve performance.

	\param device GUID of device
	\param ptr pointer to some byte
	\return record of memory allocation; if nothing could be found, the record's ISA is Unknown
*/
executive::Executive::MemoryAllocation executive::Executive::getMemoryAllocation(int device, void *ptr) const {
	using namespace std;

	MemoryAllocation record;

	DeviceAllocationMap::const_iterator l_it = 
		memoryAllocations.find(getSelected());
	if (l_it != memoryAllocations.end()) {
		AllocationMap::const_iterator it = l_it->second.lower_bound((char*)ptr);
		if (it != l_it->second.end() 
			&& ((char*)ptr < ((char*)it->second.ptr + it->second.size))) {
			return it->second;
		}
	}
	return record;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

executive::Executive::MemoryAllocation::MemoryAllocation( ): 
	isa(ir::Instruction::Unknown), device(-1), size(0), ptr(0) {
}

executive::Executive::MemoryAllocation::MemoryAllocation(
	ir::Instruction::Architecture i, int d, ir::PTXU64 s, void *p):

	isa(i), device(d), size(s), ptr(p) {
	
}

executive::Executive::MemoryAllocation::~MemoryAllocation( ) {
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

