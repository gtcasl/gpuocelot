/*! \file Device.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Jan 16, 2009
	\brief The source file for the Device class
*/

#include <ocelot/executive/interface/Device.h>
#include <ocelot/executive/interface/NVIDIAGPUDevice.h>
#include <ocelot/executive/interface/EmulatorDevice.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

executive::Device::MemoryAllocation::MemoryAllocation(bool g, 
	bool h) : _global(g), _host(h) {

}

executive::Device::MemoryAllocation::~MemoryAllocation()
{

}

bool executive::Device::MemoryAllocation::host() const {
	return _host;
}

bool executive::Device::MemoryAllocation::global() const {
	return _global;
}


executive::Device::Properties::Properties(int id) : guid(id) {
}

std::ostream& executive::Device::Properties::write(std::ostream &out) const {
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

executive::DeviceVector executive::Device::createDevices(
	ir::Instruction::Architecture isa, unsigned int flags) {
	switch(isa) {
		case ir::Instruction::SASS:
		{
			return NVIDIAGPUDevice::createDevices(flags);
		}
		break;
		case ir::Instruction::Emulated:
		{
			DeviceVector emulators;
			emulators.push_back(new EmulatorDevice(flags));
			return emulators;
		}
		break;
		default: break;
	}
	assertM(false, "Invalid ISA - " << ir::Instruction::toString(isa));
}

executive::Device::Device(int guid, unsigned int flags) : _properties(guid), 
	_driverVersion(0), _runtimeVersion(0), _flags(flags) {
}

executive::Device::~Device() {
}

bool executive::Device::checkMemoryAccess(const void* pointer, 
	size_t size) const
{
	MemoryAllocation* allocation = getMemoryAllocation(pointer, false);
	if(allocation == 0) return false;
	
	report(" Checking access " << pointer << " (" << size 
		<< " against allocation at " << allocation->pointer() 
		<< " of size " << allocation->size());
	if((char*)pointer + size 
		<= (char*)allocation->pointer() + allocation->size())
	{
		return true;
	}
	
	return false;
}


std::string executive::Device::nearbyAllocationsToString(void* pointer) const {
	std::stringstream result;
	MemoryAllocationVector allocations = getNearbyAllocations(pointer);
	
	for(MemoryAllocationVector::iterator allocation = allocations.begin(); 
		allocation != allocations.end(); ++allocation)
	{
		result << "[" << (*allocation)->pointer() << "] - [" 
			<< ((char*)(*allocation)->pointer() + (*allocation)->size()) 
			<< "]\n";
	}
	
	return result.str();
}

const executive::Device::Properties& executive::Device::properties() const {
	return _properties;
}

int executive::Device::driverVersion() const {
	return _driverVersion;
}

int executive::Device::runtimeVersion() const {
	return _runtimeVersion;
}

