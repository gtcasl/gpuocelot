/*!
	\file Device.cpp
	
	\author Andrew Kerr
	
	\date Jan 16, 2009
	
	\brief class for identifying and reporting properties of devices targeted
		by the executive
*/

#include <ocelot/executive/interface/Device.h>
#include <hydrazine/implementation/Exception.h>

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; throw hydrazine::Exception(ss.str()); }

executive::Device::Device() {
	ISA = ir::Instruction::Emulated;
	name = "PTX Emulator";
	guid = 0;
	totalMemory = (1 << 22);
	multiprocessorCount = 4;
	maxThreadsPerBlock = 768;
	maxThreadsDim[0] = maxThreadsDim[1] = maxThreadsDim[2] = maxThreadsPerBlock;
	maxGridSize[0] = maxGridSize[1] = maxGridSize[2] = 65536;
	sharedMemPerBlock = 16384;
	totalConstantMemory = 8192;
	SIMDWidth = 32;
	memPitch = (4<<10);
	regsPerBlock = 8192;
	clockRate = 2400000;
	textureAlign = 16;
	addressSpace = 0;
	cudaContext = 0;
}

executive::Device::~Device() {
	for (DriverTextureMap::iterator texture = textures.begin(); texture != textures.end(); ++texture) {
		cuda::CudaDriver::cuTexRefDestroy(texture->second);
	}

	for (DriverModuleMap::iterator module = modules.begin(); module != modules.end(); ++module) {
		cuda::CudaDriver::cuModuleUnload(module->second);
	}
	
	for (KernelMap::iterator kernel = kernels.begin(); kernel != kernels.end(); ++kernel) {
		delete kernel->second;
	}
	
	if (cudaContext != 0) {
		if( cuda::CudaDriver::cuCtxDestroy(cudaContext) != CUDA_SUCCESS ) {
			Ocelot_Exception("cuCtxDestroy(" << cudaContext << ") failed.");
		}
	}
}

std::ostream & executive::Device::write(std::ostream &out) const {
	out << name << "( " << guid << " ):\n";
	out << "  " << "total memory: " << (totalMemory >> 10) << " kB\n";
	out << "  " << "ISA: " << ir::Instruction::toString(ISA) << "\n";
	out << "  " << "multiprocessors: " << multiprocessorCount << "\n";
	out << "  " << "max threads: " << maxThreadsPerBlock << "\n";
	out << "  " << "shared memory: " << (sharedMemPerBlock >> 10) << " kB\n";
	out << "  " << "const memory: " << (totalConstantMemory >> 10) << " kB\n";
	out << "  " << "SIMD width: " << SIMDWidth << "\n";
	out << "  " << "regs per block: " << regsPerBlock << "\n";
	out << "  " << "clock rate: " << clockRate << " Hz\n";
	return out;
}


