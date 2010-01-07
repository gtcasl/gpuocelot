/*!
	\file Device.cpp
	
	\author Andrew Kerr
	
	\date Jan 16, 2009
	
	\brief class for identifying and reporting properties of devices targeted
		by the executive
*/

#include <ocelot/executive/interface/Device.h>

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
}

executive::Device::~Device() {
	
}
/*
		enum Architecture {
			PTX,
			GPU,
			Emulated,
			LLVM,
			x86,
			x86_64,
			SPU,
			Unknown
		};
*/

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


