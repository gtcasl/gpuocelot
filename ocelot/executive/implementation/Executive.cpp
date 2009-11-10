/*!
	\file Executive.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 16, 2009
	\brief class definition for loading modules, enumerating devices,
		and executing kernels on the selected device
*/

#include <assert.h>
#include <sys/sysinfo.h>

#include <ocelot/ir/interface/Module.h>
#include <ocelot/executive/interface/Executive.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/GPUExecutableKernel.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>

#if HAVE_CUDA_DRIVER_API == 1
#include <ocelot/cuda/include/cudaGL.h>
#endif

#include <cstring>

#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/interface/Casts.h>

#include <fstream>

#include <configure.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

std::string executive::Executive::nearbyGlobalsToString( 
	const Executive& executive, const void* ptr, unsigned int above,
	unsigned int below ) {
	std::stringstream stream;
	stream << " Nearby Global Variable Allocations" << std::endl;
	if (executive.globalAllocations.empty()) {
		stream << "  No Allocations." << std::endl;
		return stream.str();
	}
	
	GlobalAllocationMap::const_iterator closest 
		= executive.globalAllocations.upper_bound((char*)ptr);
	if (closest != executive.globalAllocations.begin()) --closest;
	
	GlobalAllocationMap::const_iterator bi = closest;
	for (unsigned int b = 0; b < below; ++b, --bi) {
		if (bi == executive.globalAllocations.begin()) break;
	}

	for ( ; bi != closest; ++bi ) {
		stream << "  [" << bi->second.ptr << "] - [" 
			<< ((void*)((char*)bi->second.ptr + bi->second.size)) << "]" 
			<< " (" << bi->second.size << " bytes) (" 
			<< ir::PTXInstruction::toString(bi->second.space) << ")"
			<< std::endl;
	}

	stream << "  [" << closest->second.ptr << "] - ";
	
	bool inRange = (char*)ptr < ((char*)closest->second.ptr 
		+ closest->second.size) && ((char*)ptr >= (char*)closest->second.ptr);

	if (inRange) {
		stream << "   ****" << ptr << "**** -";
	}
	
	stream << " [" << ((void*)((char*)closest->second.ptr 
		+ closest->second.size)) << "]" 
		<< " (" << closest->second.size << " bytes) (" 
		<< ir::PTXInstruction::toString(closest->second.space) << ")"
		<< std::endl;
	
	if (!inRange) {
		stream << "   ****" << ptr << "****" << std::endl;
	}
	
	GlobalAllocationMap::const_iterator ai = closest;
	if( ai != executive.globalAllocations.end() ) ++ai;

	for ( unsigned int a = 0; a < above 
		&& ai != executive.globalAllocations.end(); ++ai, ++a) {
		stream << "  [" << ai->second.ptr << "] - [" 
			<< ((void*)((char*)ai->second.ptr + ai->second.size)) << "]" 
			<< " (" << ai->second.size << " bytes) (" 
			<< ir::PTXInstruction::toString(ai->second.space) << ")"
			<< std::endl;		
	}
	
	return stream.str();
}

std::string executive::Executive::nearbyAllocationsToString( 
	const Executive& executive, const void* ptr, unsigned int above,
	unsigned int below ) {
	std::stringstream stream;
	stream << "Device " << executive.getSelected() << " : " 
		<< executive.devices[executive.getSelected()].name << std::endl;
	stream << nearbyGlobalsToString(executive, ptr, above, below) << std::endl;
	
	DeviceAllocationMap::const_iterator allocations 
		= executive.memoryAllocations.find(executive.getSelected());
	stream << " Nearby Device Memory Allocations" << std::endl;
	if (allocations == executive.memoryAllocations.end()) {
		stream << "  No Allocations" << std::endl;
		return stream.str();
	}
	if (allocations->second.empty()) {
		stream << "  No Allocations" << std::endl;
		return stream.str();
	}
	
	AllocationMap::const_iterator closest 
		= allocations->second.upper_bound((char*)ptr);
	if (closest != allocations->second.begin()) --closest;
	
	AllocationMap::const_iterator bi = closest;
	for (unsigned int b = 0; b < below; ++b, --bi) {
		if (bi == allocations->second.begin()) break;
	}

	for ( ; bi != closest; ++bi ) {
		stream << "  [" << bi->second.ptr << "] - [" 
			<< ((void*)((char*)bi->second.ptr + bi->second.size)) 
			<< "] (" << bi->second.size 
			<< " bytes) (global)" << std::endl;
	}

	stream << "  [" << closest->second.ptr << "] - ";
	
	bool inRange = (char*)ptr < ((char*)closest->second.ptr 
		+ closest->second.size) && ((char*)ptr >= (char*)closest->second.ptr);

	if (inRange) {
		stream << "   ****" << ptr << "**** -";
	}
	
	stream << " [" << ((void*)((char*)closest->second.ptr 
		+ closest->second.size)) << "] (" << closest->second.size 
		<< " bytes) (global)" << std::endl;
	
	if (!inRange) {
		stream << "   ****" << ptr << "****" << std::endl;
	}
	
	AllocationMap::const_iterator ai = closest;
	if( ai != allocations->second.end() ) ++ai;
	
	for ( unsigned int a = 0; a < above 
		&& ai != allocations->second.end(); ++ai, ++a) {
		stream << "  [" << ai->second.ptr << "] - [" 
			<< ((void*)((char*)ai->second.ptr + ai->second.size)) 
			<< "] (" << ai->second.size 
			<< " bytes) (global)" << std::endl;		
	}
	
	return stream.str();
}

#if HAVE_CUDA_DRIVER_API == 1
static CUfilter_mode_enum textureFilterMode(ir::Texture::Interpolation interpolation) {
	switch (interpolation) {
		case ir::Texture::Linear:
			return CU_TR_FILTER_MODE_LINEAR;
		case ir::Texture::Nearest:
			return CU_TR_FILTER_MODE_POINT;
		default: break;
	}
	return CU_TR_FILTER_MODE_POINT;
}

static  CUaddress_mode textureAddressMode(ir::Texture::AddressMode addr) {
	switch (addr) {
		case ir::Texture::Wrap:
			return CU_TR_ADDRESS_MODE_WRAP;
		case ir::Texture::Clamp:
			return CU_TR_ADDRESS_MODE_CLAMP;
		default: break;
	}
	return CU_TR_ADDRESS_MODE_WRAP;
}

/*
static CUarray_format textureDataFormat(ir::Texture::Type type) {
	switch (type) {
		case ir::Texture::Unsigned:
			report("  tex format: unsigned");
			return CU_AD_FORMAT_UNSIGNED_INT32;
		case ir::Texture::Signed:
			report("  tex format: signed");
			return CU_AD_FORMAT_SIGNED_INT32;
		case ir::Texture::Float:
			report("  tex format: float");
			return CU_AD_FORMAT_FLOAT;
		default: break;
	}
	return CU_AD_FORMAT_FLOAT;
}
*/

static CUarray_format textureDataFormat(const ir::Texture &texture) {
	switch (texture.type) {
		case ir::Texture::Unsigned:
			report("  tex format: unsigned - " << texture.x << " bits");
			switch (texture.x) {
				case 8:
					return CU_AD_FORMAT_UNSIGNED_INT8;
				case 16:
					return CU_AD_FORMAT_UNSIGNED_INT16;
				case 32:
				default:
					return CU_AD_FORMAT_UNSIGNED_INT32;
			}
			return CU_AD_FORMAT_UNSIGNED_INT32;
		case ir::Texture::Signed:
			report("  tex format: signed - " << texture.x << " bits");
			switch (texture.x) {
				case 8:
					return CU_AD_FORMAT_SIGNED_INT8;
				case 16:
					return CU_AD_FORMAT_SIGNED_INT16;
				case 32:
				default:
					return CU_AD_FORMAT_SIGNED_INT32;
			}
			return CU_AD_FORMAT_SIGNED_INT32;
		case ir::Texture::Float:
			report("  tex format: float - " << texture.x << " bits");
			switch (texture.x) {
				case 16:
					return CU_AD_FORMAT_HALF;
				case 32:
				default:
					return CU_AD_FORMAT_FLOAT;
			}
			return CU_AD_FORMAT_FLOAT;
		default: break;
	}
	return CU_AD_FORMAT_FLOAT;
}

#endif

/*!
	called to update global variables across all address spaces

	\param copyType specifies direction data should be copied to update globals
*/
void executive::Executive::fenceGlobalVariables(MemoryCopy copyType) {
#if HAVE_CUDA_DRIVER_API == 1
		
	if (getSelectedISA() == ir::Instruction::GPU) {
		// get it from the PTX module
		std::map<std::string, ir::PTXInstruction::AddressSpace > globalsSet;

		// globals
		for (GlobalAllocationMap::iterator glb_it = globalAllocations.begin();
			glb_it != globalAllocations.end(); ++glb_it) {
			std::string name(glb_it->second.identifier);
			
			// filter variables according to name and state space
			if (!(name.size() && 
				(glb_it->second.space == ir::PTXInstruction::Const || 
				 glb_it->second.space == ir::PTXInstruction::Global) )) {
				continue;
			}

			report("  updating global variable '" << name << "' in address space " 
				<< ir::PTXInstruction::toString(glb_it->second.space));

			if (globalsSet.find(name) == globalsSet.end()) {
				globalsSet[name] = glb_it->second.space;
			}
			else {
				report("  global variable allocation listed twice");
				continue;
			}

			for (ModuleMap::iterator mod_it = modules.begin(); mod_it != modules.end(); ++mod_it) {

				if (mod_it->second->cuModuleState == ir::Module::Loaded) {
					unsigned int bytes;
					CUdeviceptr devicePtr;
					if (cuModuleGetGlobal(&devicePtr, &bytes, mod_it->second->cuModule, 
						name.c_str()) == CUDA_SUCCESS) {
						report("    obtained pointer to global variable '" << name << "' in GPU memory: 0x" 
							<< std::hex << (unsigned int)devicePtr << ", \n\t\t\t\t\tcopying from host memory: 0x" 
							<< glb_it->second.ptr << std::dec);
						if (copyType == HostToDevice) {
							if (cuMemcpyHtoD(devicePtr, glb_it->second.ptr, glb_it->second.size) != CUDA_SUCCESS) {
								throw hydrazine::Exception("Executive::fenceGlobalVariables() - cuMemcpyHtoD() failed");
							}
						}
						else if (copyType == DeviceToHost) {
							if (cuMemcpyDtoH(glb_it->second.ptr, devicePtr, glb_it->second.size) != CUDA_SUCCESS) {
								throw hydrazine::Exception("Executive::fenceGlobalVariables() - cuMemcpyDtoH() failed");
							}
						}
						else { 
							throw hydrazine::Exception("ambiguous copyType for fence");
						}
					}
					else {
						throw hydrazine::Exception("Executive::fenceGlobalVariables() - cuModuleGetGlobal() failed");
					}
				}
			}
		}

		for (ModuleMap::iterator mod_it = modules.begin(); mod_it != modules.end(); ++mod_it) {
			if (mod_it->second->cuModuleState == ir::Module::Loaded) {
				for (ir::Module::TextureMap::iterator t_it = mod_it->second->textures.begin();
					t_it != mod_it->second->textures.end(); ++t_it) {

					CUtexref texRef;
					int textureFlags = (t_it->second.normalize ? CU_TRSF_NORMALIZED_COORDINATES:0)
						 | (!t_it->second.normalizedFloat ? CU_TRSF_READ_AS_INTEGER : 0);
					if (cuModuleGetTexRef(&texRef, mod_it->second->cuModule, t_it->first.c_str()) != CUDA_SUCCESS) {
						report("failed to get texture reference '"<< t_it->first 
							<< "'from module '" << mod_it->first << "'\n");
						throw hydrazine::Exception("FAILED to get texture reference");
					}
					for (int i = 0; i < 3; i++) {
						cuTexRefSetAddressMode(texRef, i, textureAddressMode(t_it->second.addressMode[i]));
					}
					cuTexRefSetFilterMode(texRef, textureFilterMode(t_it->second.interpolation));
					cuTexRefSetFormat(texRef, textureDataFormat(t_it->second), t_it->second.components());
					cuTexRefSetFlags(texRef, textureFlags);

					report("  texture flags: " << textureFlags << " - " 
						<< (textureFlags & CU_TRSF_READ_AS_INTEGER ? "read as integer " : "")
						<< (textureFlags & CU_TRSF_NORMALIZED_COORDINATES ? "normalized coordinates" : ""));

					switch (t_it->second.dimensions()) {
						case 1:
							if (cuTexRefSetAddress(0, texRef, 
								hydrazine::bit_cast<CUdeviceptr , void*>(t_it->second.data), 
								t_it->second.bytes()) != CUDA_SUCCESS) {

								report("failed to set texture '" << t_it->first << "' to array");
								throw hydrazine::Exception("FAILED to bind texture");
							}

							report("  successfully bound texture '" << t_it->first << "' to pointer " 
								<< std::hex << t_it->second.data << std::dec);
							break;
						case 2: 
							{
								CUDA_ARRAY_DESCRIPTOR desc;
								desc.Width = t_it->second.size.x;
								desc.Height = t_it->second.size.y;
								desc.NumChannels = t_it->second.components();
								desc.Format = textureDataFormat(t_it->second);

								if (cuTexRefSetAddress2D(texRef, &desc,
									hydrazine::bit_cast<CUdeviceptr , void*>(t_it->second.data), 
									t_it->second.pitch()) != CUDA_SUCCESS) {

									report("failed to set 2D texture '" << t_it->first << "' to array");
									throw hydrazine::Exception("FAILED to bind texture");
								}

								report("  successfully bound 2D texture '" << t_it->first << "' to pointer " 
									<< std::hex << t_it->second.data << std::dec << " with dimensions (" 
									<< desc.Width << ", " << desc.Height << ") and " << t_it->second.components() << " components");
							}
							break;
						default:
							break;
					}

					// add the texture reference somewhere where it can be destroyed or reused
				}
			}
		}
	}
#endif
}

void executive::Executive::_translateToSelected(ir::Module& m) {
	using namespace ir;
	report("Translating all kernels in module " << m.modulePath << " to ISA " << ir::Instruction::toString(getSelectedISA()));
	Module::KernelMap::iterator 
		it = m.kernels.find(Instruction::PTX);
	if (it == m.kernels.end()) {
		return;
	}
	// translate the kernels of a module to the selected ISA
	if (getSelectedISA() == Instruction::Emulated) {
		report(" Translating to EmulatedKernel.");
		// translate each PTX kernel to Emulated
		for (Module::KernelVector::iterator k_it = it->second.begin();
			k_it != it->second.end(); ++k_it) {
			report("  Creating emulated kernel for : " << (*k_it)->name);
			EmulatedKernel *emKern = new EmulatedKernel(*k_it, this);
			m.kernels[Instruction::Emulated].push_back(emKern);
		}
	}
	else if (getSelectedISA() == Instruction::GPU) {
		report(" Translating to GPUExecutableKernel.");
		_translateToGPUExecutable(m);
	}
	else if (getSelectedISA() == Instruction::LLVM) {
		report(" Translating all modules to LLVMKernel.");
		for (Module::KernelVector::iterator k_it = it->second.begin();
			k_it != it->second.end(); ++k_it) {
			report("  Creating LLVM kernel for : " << (*k_it)->name);
			LLVMExecutableKernel* 
				kernel = new LLVMExecutableKernel(**k_it, this, 
				optimizationLevel);
				kernel->setDevice(&devices[getSelected()], threadLimit);
			m.kernels[Instruction::LLVM].push_back(kernel);
		}
	}
}

void executive::Executive::_translateToGPUExecutable(ir::Module &m) {
	using namespace ir;
#if HAVE_CUDA_DRIVER_API == 1
	Module::KernelMap::iterator 
		it = m.kernels.find(Instruction::PTX);
	if (it == m.kernels.end()) {
		return;
	}
	if (m.cuModuleState != Module::Invalid) {
		cuModuleUnload(m.cuModule);
	}

	std::stringstream ss;	
	m.write(ss);

	cudaError_enum result;
	if ((result = cuModuleLoadData(&m.cuModule, (const void *)ss.str().c_str())) != CUDA_SUCCESS) {
		report("PTX kernel representation:\n" << ss.str());

		report("  cuModuleLoadData() returned " << result);

		// KERRDEBUG emit the ptx source file to a text file in the binary's directory
		{
			std::ofstream file("module.ptx");
			file << ss.str();
		}

		throw hydrazine::Exception("cuModuleLoadData() failed for module " + m.modulePath);

	}
	m.cuModuleState = Module::Dirty;
	
	for (Module::KernelVector::iterator k_it = it->second.begin();
		k_it != it->second.end(); ++k_it) {
		report("  Creating GPUExecutableKernel for : " << (*k_it)->name);
		executive::GPUExecutableKernel *gpuKern = 
			new executive::GPUExecutableKernel(**k_it, this);
		
		report("    constructed GPUExecutableKernel");

		if (cuModuleGetFunction(&gpuKern->cuFunction, m.cuModule, gpuKern->name.c_str()) != CUDA_SUCCESS) {
			std::string exception = "cuModuleGetFunction() failed for module " + m.modulePath 
				+ ", kernel " + gpuKern->name;
			delete gpuKern;
			throw hydrazine::Exception(exception);

		}
		report("    added kernel '" << gpuKern->name << "' to module");

		m.kernels[Instruction::GPU].push_back(gpuKern);
	}		

	m.cuModuleState = Module::Loaded;
#else
	throw hydrazine::Exception("CUDA Driver API Not Enabled");
#endif
}

bool executive::Executive::cudaInitialized = false;

executive::Executive::Executive() : selectedDevice(-1), 
	optimizationLevel( translator::Translator::NoOptimization ),
	threadLimit(-1) {
	cudaGLInitialized = true;
	enumerateDevices();
}

executive::Executive::~Executive() {
	//free memory
	for (DeviceAllocationMap::iterator device = memoryAllocations.begin(); 
		device != memoryAllocations.end(); ++device) {
		for (AllocationMap::iterator allocation = device->second.begin(); 
			allocation != device->second.end(); ++allocation ) {
			if (!allocation->second.external) {
				delete [] ((char *)allocation->second.ptr 
					- allocation->second.offset);
			}
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
		m_it->second->load(*stream, path);
	}
	if (translateToSelected) {
		_translateToSelected( *m_it->second );
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

/*! Enumerate available devices */
void executive::Executive::enumerateDevices() {
	report( "Initializing devices:" );

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
		report( " Initialized PTX emulated." );
		allDevices.push_back(device);
	}

	#ifdef HAVE_LLVM
	{
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
		allDevices.push_back(device);
	}
	#endif
	
	#if HAVE_CUDA_DRIVER_API == 1
	// enumerate actual CUDA-capable GPUs
	int deviceCount = 0;

	if (!cudaInitialized) {
		cuInit(0);
		// create a CUDA context as well
		report("Created CUDA driver context.");
		cudaInitialized = true;
	}
	
	if (cuDeviceGetCount(&deviceCount) != CUDA_SUCCESS) {
		report("cuDeviceGetCount() - failed");
		return;
	}
	for (int i = 0; i < deviceCount; i++) {
		CUdevprop devProperties = {0};
		char cudaDeviceName[128] = {0};
		unsigned int totalMemoryBytes = 0;

		Device device;
		device.ISA = ir::Instruction::GPU;

		cuDeviceGetName(cudaDeviceName, 127, i);
		device.name = std::string(cudaDeviceName);

		device.guid = i;

		cuDeviceTotalMem(&totalMemoryBytes, i);
		device.totalMemory = (size_t)totalMemoryBytes;

		cuDeviceGetAttribute(&device.multiprocessorCount, 
			CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, i);

		cuDeviceGetProperties(&devProperties, i);

		device.memcpyOverlap = 0;
		device.maxThreadsPerBlock = devProperties.maxThreadsPerBlock;
		device.maxThreadsDim[0] = devProperties.maxThreadsDim[0];
		device.maxThreadsDim[1] = devProperties.maxThreadsDim[1];
		device.maxThreadsDim[2] = devProperties.maxThreadsDim[2];
		device.maxGridSize[0] = devProperties.maxGridSize[0];
		device.maxGridSize[1] = devProperties.maxGridSize[1];
		device.maxGridSize[2] = devProperties.maxGridSize[2];
		device.sharedMemPerBlock = devProperties.sharedMemPerBlock;
		device.totalConstantMemory = devProperties.totalConstantMemory;
		device.SIMDWidth = devProperties.SIMDWidth;
		device.memPitch = devProperties.memPitch;
		device.regsPerBlock = devProperties.regsPerBlock;
		device.clockRate = devProperties.clockRate;
		device.textureAlign = devProperties.textureAlign;

		cuDeviceComputeCapability(&device.major, &device.minor, i);

		allDevices.push_back(device);
	}
	#endif
	restoreFilteredDevices();
}

/*!
	idempotent - called to init GL interoperability
*/
bool executive::Executive::useGLInteroperability() {
	#if HAVE_CUDA_DRIVER_API == 1
	if (!cudaGLInitialized) {
		cudaGLInitialized = false;
		if (cuGLInit() != CUDA_SUCCESS) {
			report("  failed to initialize GL interoperability");
			return false;
		}
		if (cuDeviceGet(&cudaDevice, devices[selectedDevice].guid) != CUDA_SUCCESS) {
			report("  cuDeviceGet() failed");
			return false;
		}
		if (cuGLCtxCreate(&cudaContext, 0, cudaDevice) == CUDA_SUCCESS) {
			cudaGLInitialized = true;
			report("  cuGLCtxCreate() - created a GL context");
			return true;
		}
		else {
			report("  CANNOT create select GL-capable CUDA context");
			return false;
		}
	}
	return true;
	#else
	return false;
	#endif
}

/*!
	Select a device by GUID
*/
bool executive::Executive::select(int device) {
	if (selectedDevice >= 0 && devices[selectedDevice].guid == device) {
		return true;	
	}
	report("selecting device " << device);
	for (int i = 0; i < (int)devices.size(); i++) {
		if (devices[i].guid == device) {
			if (devices[i].ISA == ir::Instruction::Emulated
				|| devices[i].ISA == ir::Instruction::LLVM) {
				selectedDevice = i;
				return true;
			}
#if HAVE_CUDA_DRIVER_API == 1
			else if (devices[i].ISA == ir::Instruction::GPU) {
				selectedDevice = i;
				cudaGLInitialized = false;

				if (cuCtxCreate(&cudaContext, 0, devices[i].guid) == CUDA_SUCCESS) {
					report("  cuCtxCreate() successful - creaetd CUDA device " << i);
					return true;
				}
				report("cuGLCtxCreate(&context,0, " << devices[i].guid << ") failed");
				return false;
			}
#endif
		}
	}
	return false;
}

bool executive::Executive::selectDeviceByISA(ir::Instruction::Architecture ISA) {
	for (int i = 0; i < (int)devices.size(); i++) {
		if (devices[i].ISA == ISA) {
			return select(devices[i].guid);
		}
	}
	return false;
}

void executive::Executive::setPreferredISA(ir::Instruction::Architecture ISA) {
	DeviceVector newDevices;
	
	for (DeviceVector::const_iterator device = devices.begin(); 
		device != devices.end(); ++device) {
		if (device->ISA == ISA) {
			newDevices.push_back(*device);
		}
	}
	for (DeviceVector::const_iterator device = devices.begin(); 
		device != devices.end(); ++device) {
		if (device->ISA != ISA) {
			newDevices.push_back(*device);
		}
	}
	
	devices = std::move(newDevices);
}

void executive::Executive::filterDevicesByISA(
	ir::Instruction::Architecture ISA) {
	DeviceVector newDevices;
	for (DeviceVector::const_iterator device = devices.begin(); 
		device != devices.end(); ++device) {
		if (device->ISA != ISA) {
			newDevices.push_back(*device);
		}
	}
	devices = newDevices;
}

void executive::Executive::restoreFilteredDevices() {
	devices = allDevices;
}

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
ir::Kernel* executive::Executive::getKernel(ir::Instruction::Architecture isa, 
	const std::string& module, 
	const std::string& kernelName) {
	ModuleMap::iterator m_it = modules.find(module);
	report( "From module " << module << " getting kernel " << kernelName 
		<< " for architecture " << ir::Instruction::toString( isa ) );
	if (m_it != modules.end()) {
		ir::Kernel* kernel = m_it->second->getKernel(isa, kernelName);
		if (kernel == 0) {
			_translateToSelected( *m_it->second );
			kernel = m_it->second->getKernel(isa, kernelName);
		}
		return kernel;
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
		case ir::Instruction::LLVM:
		case ir::Instruction::Emulated:
			{
				MemoryAllocation record;
				record.isa = ir::Instruction::Emulated;
				record.device = getSelected();
				record.external = false;
				record.size = bytes;
				record.ptr = (void *)(new AllocationType[CEIL_DIV(bytes, 
					sizeof(AllocationType)) + sizeof(AllocationType)]);
				record.offset = (size_t)record.ptr 
					% sizeof(AllocationType);
				record.offset = (record.offset == 0) 
					? 0 : sizeof(AllocationType) - record.offset;
				record.ptr = (void*)((size_t)record.ptr + record.offset);
				memoryAllocations[getSelected()].insert(
					std::make_pair((char*)record.ptr,record));
				return record.ptr;
			}
			break;
#if HAVE_CUDA_DRIVER_API == 1
		case ir::Instruction::GPU:
			{
				MemoryAllocation record;
				record.isa = ir::Instruction::GPU;
				record.device = getSelected();
				record.external = false;
				record.size = bytes;
				record.ptr = 0;
				if (cuMemAlloc((CUdeviceptr *)&record.ptr, bytes) == CUDA_SUCCESS) {
					record.offset = 0;
					memoryAllocations[getSelected()].insert(
						std::make_pair((char *)record.ptr, record));
					report("executive::Executive::malloc() - cuMemAlloc() allocated " 
						<< bytes << " bytes on device " << record.device << " at 0x" << std::hex << record.ptr << std::dec);
					return record.ptr;
				}
			}
			break;
#endif
/*
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
		case ir::Instruction::LLVM:
		case ir::Instruction::Emulated:
			{
				MemoryAllocation record;
				record.isa = getSelectedISA();
				record.device = getSelected();
				record.size = bytes;
				record.external = true;
				record.ptr = pointer;
				record.offset = 0;
				memoryAllocations[getSelected()].insert(
					std::make_pair((char*)record.ptr,record));
			}
			break;
#if HAVE_CUDA_DRIVER_API == 1
		case ir::Instruction::GPU:
			{
				MemoryAllocation record;
				record.isa = getSelectedISA();
				record.device = getSelected();
				record.size = bytes;
				record.external = true;
				record.ptr = pointer;
				record.offset = 0;
				memoryAllocations[getSelected()].insert(
					std::make_pair((char*)record.ptr,record));
			}
			break;
#endif
/*

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
	Makes a static array visible to the Executive class

	\param ptr Pointer to the start of the memory
	\param bytes Size of memory in bytes
	\param name Identifier of the variable
	\param module Path to the module with the variable
	\param space The address space it should exist in
	\param normalize If the global is a texture, 
		should it be normalized?
*/
void executive::Executive::registerGlobal(void *ptr, size_t bytes, 
	const std::string& name, ir::PTXInstruction::AddressSpace space, 
	const std::string& modulePath) {
	using namespace std;

	switch (getSelectedISA()) {
		case ir::Instruction::LLVM:
		case ir::Instruction::Emulated:
			{
				report( "Registering global variable (LLVM,emulated) '" << name 
					<< "' in module " << modulePath );

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
				
				if (global->second.statement.directive 
					!= ir::PTXStatement::Tex) {
					GlobalAllocationMap::iterator ai 
						= globalAllocations.find((char*)ptr);
					if (ai != globalAllocations.end()) {
						assert(ai->second.modules.count(modulePath) == 0);
						ai->second.modules.insert(modulePath);
					}
					else {
						GlobalMemoryAllocation allocation;
						allocation.ptr = ptr;
						allocation.size = bytes;
						allocation.space = space;
						allocation.identifier = name;
						allocation.modules.insert(modulePath);				
					
						globalAllocations.insert(std::make_pair((char*)ptr, 
							allocation));
					}
				}
			}
			break;

#if HAVE_CUDA_DRIVER_API == 1
		/*!
			Register the GPU
		*/
		case ir::Instruction::GPU:
			{

				report( "Registering global variable (GPU) '" << name 
					<< "' in module " << modulePath );

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
				global->second.registered = true;

				if (global->second.statement.directive != ir::PTXStatement::Tex) {
					GlobalAllocationMap::iterator ai = globalAllocations.find((char*)ptr);
					if (ai != globalAllocations.end()) {
						assert(ai->second.modules.count(modulePath) == 0);
						ai->second.modules.insert(modulePath);
					}
					else {
						GlobalMemoryAllocation allocation;
						allocation.ptr = ptr;
						allocation.size = bytes;
						allocation.space = space;
						allocation.identifier = name;
						allocation.modules.insert(modulePath);				
					
						globalAllocations.insert(std::make_pair((char*)ptr, allocation));
					}
				}

				//throw hydrazine::Exception("Executive::registerGlobal() - not implemented for GPU device");
			}
			break;
#endif

/*
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
		case ir::Instruction::LLVM:
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
		case ir::Instruction::GPU:
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

	report("Executive::rebind() - module: " << modulePath << ", texture: " << texture 
		<< ", target: 0x" << std::hex << target << std::dec << ", width: " << width 
		<< ", height: " << height << ", length: " << length);

		switch (getSelectedISA()) {
		case ir::Instruction::LLVM:
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
		case ir::Instruction::GPU:
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
					t_it = module->second->textures.find(texture);
				assert(t_it != module->second->textures.end());
				
				report( " Texture was previously bound to " 
					<< t_it->second.data );
									
				t_it->second.data = target;
				t_it->second.x = t.x;
				t_it->second.y = t.y;
				t_it->second.z = t.z;
				t_it->second.w = t.w;
				t_it->second.type = t.type;
				t_it->second.size.x = width;
				t_it->second.size.y = height;
				t_it->second.size.z = length;
								
				t_it->second.normalize = t.normalize;
				t_it->second.interpolation = t.interpolation;
				t_it->second.addressMode[0] = t.addressMode[0];
				t_it->second.addressMode[1] = t.addressMode[1];
				t_it->second.addressMode[2] = t.addressMode[2];
				
				if( target == 0 ) {
					t_it->second.type = ir::Texture::Invalid;
				}		
			}
			break;
/*
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

#if HAVE_CUDA_DRIVER_API == 1
typedef struct {
	union {
		void *void_ptr;
		CUdeviceptr device_ptr;
	};
} Union_device_ptr;

static CUdeviceptr painful_cast(void *ptr) {
	Union_device_ptr u_ptr;
	u_ptr.void_ptr = ptr;
	return u_ptr.device_ptr;
}

static CUdeviceptr painful_cast(const void *ptr) {
	Union_device_ptr u_ptr;
	u_ptr.void_ptr = const_cast<void *>(ptr);
	return u_ptr.device_ptr;
}
#endif

/*!
	Free a memory block allocated to this device.

	\param ptr pointer to allocated memory block
*/
void executive::Executive::free(void *ptr) {
	using namespace std;

	switch (getSelectedISA()) {
		case ir::Instruction::LLVM:
		case ir::Instruction::Emulated:
			{
				DeviceAllocationMap::iterator l_it = 
					memoryAllocations.find(getSelected());
				assert (l_it != memoryAllocations.end());
				AllocationMap::iterator it = 
					l_it->second.lower_bound((char*)ptr);
				assert(it != l_it->second.end());
				assert((char*)ptr <= ((char*)it->second.ptr + it->second.size));

				if (!it->second.external) {
					delete [] ((char *)it->second.ptr - it->second.offset);
				}
				
				l_it->second.erase(it);
				return;
				
			}
			break;

#if HAVE_CUDA_DRIVER_API == 1
		case ir::Instruction::GPU:
			{
				DeviceAllocationMap::iterator l_it = 
					memoryAllocations.find(getSelected());
				assert (l_it != memoryAllocations.end());
				AllocationMap::iterator it = 
					l_it->second.lower_bound((char*)ptr);
				assert(it != l_it->second.end());

				if (!it->second.external) {
					cuMemFree(painful_cast(it->second.ptr));
				}
				
				l_it->second.erase(it);
				return;
			}
			break;
#endif

/*
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
		case ir::Instruction::LLVM:
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

#if HAVE_CUDA_DRIVER_API == 1
		case ir::Instruction::GPU:
			{
				report( "Freeing global variable " << name 
					<< " from GPU kernels in module " << modulePath );

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
#endif

/*
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
		case ir::Instruction::LLVM:
		case ir::Instruction::Emulated:
			{
				if (type == DeviceToDevice) {
					if (!checkMemoryAccess(getSelected(), dest, bytes)) {
						std::stringstream stream;
						stream << "Invalid destination " << dest << " (" 
							<< bytes << " bytes) in device to device memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, dest, bytes);
						throw hydrazine::Exception(stream.str());
					}
					if (!checkMemoryAccess(getSelected(), src, bytes)) {
						std::stringstream stream;
						stream << "Invalid source " << src << " (" 
							<< bytes << " bytes) in device to device memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, src, bytes);
						throw hydrazine::Exception(stream.str());
					}
				}
				else if (type == HostToDevice) {
					if (!checkMemoryAccess(getSelected(), dest, bytes)) {
						std::stringstream stream;
						stream << "Invalid destination " << dest << " (" 
							<< bytes << " bytes) in host to device memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, dest, bytes);
						throw hydrazine::Exception(stream.str());
					}
				}
				else if (type == DeviceToHost) {
					if (!checkMemoryAccess(getSelected(), src, bytes)) {
						std::stringstream stream;
						stream << "Invalid source " << src << " ( " 
							<< bytes << "bytes) in device to host memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, src, bytes);
						throw hydrazine::Exception(stream.str());
					}
				}
				std::memcpy( dest, src, bytes );
			}
			break;

#if HAVE_CUDA_DRIVER_API == 1
		case ir::Instruction::GPU:
			{
				if (type == DeviceToDevice) {
					if (!checkMemoryAccess(getSelected(), dest, bytes)) {
						std::stringstream stream;
						stream << "Invalid destination " << dest << " (" 
							<< bytes << " bytes) in device to device memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, dest, bytes);
						throw hydrazine::Exception(stream.str());
					}
					if (!checkMemoryAccess(getSelected(), src, bytes)) {
						std::stringstream stream;
						stream << "Invalid source " << src << " (" 
							<< bytes << " bytes) in device to device memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, src, bytes);
						throw hydrazine::Exception(stream.str());
					}
					cuMemcpyDtoD(painful_cast(dest), painful_cast(src), bytes);
				}
				else if (type == HostToDevice) {
					if (!checkMemoryAccess(getSelected(), dest, bytes)) {
						std::stringstream stream;
						stream << "Invalid destination " << dest << " (" 
							<< bytes << " bytes) in host to device memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, dest, bytes);
						throw hydrazine::Exception(stream.str());
					}
					cuMemcpyHtoD(painful_cast(dest), (src), bytes);
				}
				else if (type == DeviceToHost) {
					if (!checkMemoryAccess(getSelected(), src, bytes)) {
						std::stringstream stream;
						stream << "Invalid source " << src << " ( " 
							<< bytes << "bytes) in device to host memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, src, bytes);
						throw hydrazine::Exception(stream.str());
					}
					cuMemcpyDtoH((dest), painful_cast(src), bytes);
				}
				else if (type == HostToHost) {
					if (!checkMemoryAccess(getSelected(), dest, bytes)) {
						std::stringstream stream;
						stream << "Invalid destination " << dest << " (" 
							<< bytes << " bytes) in host to device memcpy." 
							<< std::endl;
						stream << nearbyAllocationsToString(*this, dest, bytes);
						throw hydrazine::Exception(stream.str());
					}
					std::memcpy(dest, src, bytes);
				}
			}
			break;
#endif
			
			/*
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
		case ir::Instruction::LLVM:
		case ir::Instruction::Emulated:
			{
				if (!checkMemoryAccess(getSelected(), dest, bytes)) {
					std::stringstream stream;
					stream << "Invalid destination " << dest << " (" 
						<< bytes << " bytes) in device to device memcpy." 
						<< std::endl;
					stream << nearbyAllocationsToString(*this, dest, bytes);
					throw hydrazine::Exception(stream.str());
				}
				std::memset( dest, value, bytes );
			}
			break;

/*
		case ir::Instruction::GPU:
			{
				// copy on the GPU
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

bool executive::Executive::checkMemoryAccess(int device, 
	const void* _base, size_t size) const {
	const char* base = reinterpret_cast<const char*>(_base);
	
	GlobalAllocationMap::const_iterator global 
		= globalAllocations.upper_bound(const_cast<char*>(base));
	if (global != globalAllocations.begin()) --global;
	if (base + size <= ((char*)global->second.ptr + global->second.size) 
		&& (base >= (char*)global->second.ptr)) {
		return true;
	}
	
	MemoryAllocation allocation = getMemoryAllocation(device, _base);
	if( allocation.isa == ir::Instruction::Unknown ) {
		return false;
	}
	assert(allocation.device == device || allocation.external);
	const char* allocationBase = reinterpret_cast<const char*>(allocation.ptr);
	return (base >= allocationBase) 
		&& ((base + size) <= (allocationBase + allocation.size));
}

executive::Executive::MemoryAllocation 
	executive::Executive::getMemoryAllocation(int device, 
	const void *ptr) const {
	using namespace std;

	MemoryAllocation record;

	DeviceAllocationMap::const_iterator l_it = 
		memoryAllocations.find(device);
	if (l_it != memoryAllocations.end()) {
		AllocationMap::const_iterator it = l_it->second.upper_bound((char*)ptr);
		if (it != l_it->second.begin()) --it;
		if (it != l_it->second.end()) {
			if ((char*)ptr < ((char*)it->second.ptr + it->second.size)) {
				return it->second;
			}
		}
	}
	return record;
}

void executive::Executive::setOptimizationLevel( 
	translator::Translator::OptimizationLevel l) {
	optimizationLevel = l;
}

void executive::Executive::limitWorkerThreads(unsigned int limit) {
	threadLimit = limit;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

executive::Executive::MemoryAllocation::MemoryAllocation( ): 
	isa(ir::Instruction::Unknown), device(-1), size(0), ptr(0), 
	external(false), offset(0) {
}

executive::Executive::MemoryAllocation::MemoryAllocation(
	ir::Instruction::Architecture i, int d, ir::PTXU64 s, void *p):
	isa(i), device(d), size(s), ptr(p), external(false) {
	
}

executive::Executive::MemoryAllocation::~MemoryAllocation( ) {
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

