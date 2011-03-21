/*!
	\file KernelTestHarness.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 31 January 2011
	\brief loads serialized device state and module. Configures device with
		'before' state, executes a kernel, then compares resulting state to
		loaded 'after' state.
		
		Reports kernel runtime, correctness of results. Useful for analysis
		and unit testing
*/

// C++ includes
#include <iostream>
#include <cstring>

// Hydrazine includes
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/json.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/interface/Casts.h>

// Boost includes

// CUDA Includes
#include <ocelot/cuda/interface/cuda_runtime.h>

// Ocelot includes
#include <ocelot/util/interface/ExtractedDeviceState.h>
#include <ocelot/api/interface/ocelot.h>
#include <ocelot/tools/KernelTestHarness.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

////////////////////////////////////////////////////////////////////////////////

// whether debugging messages are printed
#define REPORT_BASE 0

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////

static dim3 toDim3(const ir::Dim3 &d) {
	return dim3(d.x, d.y, d.z);
}

////////////////////////////////////////////////////////////////////////////////

util::KernelTestHarness::KernelTestHarness(std::istream &input): state(input) {
	report("deserialized application");
}

util::KernelTestHarness::~KernelTestHarness() {

}

void util::KernelTestHarness::execute() {
	_setupExecution();

	// examine parameter memory, map pointers to pointers
	cudaError_t result = cudaConfigureCall(toDim3(state.launch.gridDim),
		toDim3(state.launch.blockDim), state.launch.sharedMemorySize);
	if (result != cudaSuccess) {
		report("failed to configure function call")
		throw hydrazine::Exception("failed to configure function call");
	}

	// map parameter memory according to pointer rules
	report("Remapping parameter memory pointers (size "
		<< state.launch.parameterMemory.size() << ")");
		
	char* parameterMemory = new char[state.launch.parameterMemory.size()];
	std::memcpy(parameterMemory, state.launch.parameterMemory.data(),
		state.launch.parameterMemory.size());
	for (size_t i = 0; i < state.launch.parameterMemory.size();
		i += sizeof(void *)) {

		void *pointer = *(void **)&parameterMemory[i];
		report(" checking parameter value " << pointer << " at offset " << i);
				
		PointerMap::iterator p_it = pointers.find(pointer);
		if (p_it != pointers.end()) {
			*(const void **)&parameterMemory[i] = p_it->second;
			report("  remapping parameter value " << pointer
				<< " to " << p_it->second);
		}	
	}

	report("setting up argument memory, size "
		<< state.launch.parameterMemory.size() << " bytes");
	result = cudaSetupArgument(parameterMemory,
		state.launch.parameterMemory.size(), 0);
	delete[] parameterMemory;
	
	if (result != cudaSuccess) {
		report("Failed to setup parameter memory");
		throw hydrazine::Exception("Failed to setup parameter memory");
	}
	
	ocelot::launch(state.launch.moduleName, state.launch.kernelName);
	
	result = cudaThreadSynchronize();
	if (result != cudaSuccess) {
		report("Kernel execution FAILED");
	}
	else {
		report("Kernel execution succeeded.");
	}
}

typedef long long unsigned int uint64;

static void compareAllocation(unsigned int& errors, uint64 size,
	const void* referenceAddress, const void* computedAddress) {

	char* computedData = new char[size];
		
	cudaError_t result = cudaMemcpy(computedData,
		computedAddress, size, cudaMemcpyDeviceToHost);
	
	if (result != cudaSuccess) {
		report(" failed to copy from computed device allocation");
		delete[] computedData;
		throw hydrazine::Exception(
			"Failed to copy from computed device allocation");
	}
	
	uint64 address = 0;
	uint64 bytes   = size;

	for (; address + sizeof(uint64) <= bytes; address += sizeof(uint64)) {
		uint64 computed  = 0;
		uint64 reference = 0;
	
		std::memcpy(&computed,  computedData + address, sizeof(uint64));
		std::memcpy(&reference, (char*)referenceAddress + address,
			sizeof(uint64));
	
		if(computed != reference) {
			std::cout << "at " << (void*)(address + (char*)referenceAddress)
				<< " - computed '0x" << std::hex << computed
				<< "' != reference '0x" << std::hex << reference << "'\n";
			++errors;
		}
		
		if (errors > 20) break;
	}
	
	if(errors <= 20) {
		uint64 computed  = 0;
		uint64 reference = 0;
	
		std::memcpy(&computed,  computedData + address, bytes - address);
		std::memcpy(&reference, (char*)referenceAddress + address,
			bytes - address);
	
		if(computed != reference) {
			std::cout << "at " << (void*)(address + (char*)referenceAddress)
				<< " - computed '0x" << std::hex << computed
				<< "' != reference '0x" << std::hex << reference << "'\n";
			++errors;
		}
	}
	
	delete[] computedData;
}

bool util::KernelTestHarness::compare() {
	// visit each allocation and compare 'after' results to 'before'
	
	unsigned int errors = 0;
	report("Comparing computed data with reference");

	// compare global memory allocations
	for (ExtractedDeviceState::GlobalAllocationMap::const_iterator
		alloc_it = state.globalAllocations.begin();
		alloc_it != state.globalAllocations.end(); ++alloc_it) {
		report(" comparing global allocation at " << alloc_it->first);
		
		ExtractedDeviceState::GlobalAllocationMap::const_iterator
			referenceAllocation = state.postLaunchGlobalAllocations.find(
			alloc_it->first);
		assertM(referenceAllocation != state.postLaunchGlobalAllocations.end(),
			"Reference data corresponding to allocation at " << alloc_it->first
			<< " not found, malformed kernel checkpoint.");
		
		compareAllocation(errors, alloc_it->second->size(),
			referenceAllocation->second->data.data(),
			pointers[alloc_it->second->devicePointer]);

		if (errors > 20) break;
	}

	// compare global variable allocations
	for (ExtractedDeviceState::GlobalVariableMap::const_iterator
		alloc_it = state.globalVariables.begin();
		alloc_it != state.globalVariables.end(); ++alloc_it) {
		report(" comparing global variable " << alloc_it->first);
		
		ExtractedDeviceState::GlobalVariableMap::const_iterator
			referenceAllocation = state.postLaunchGlobalVariables.find(
			alloc_it->first);
		assertM(referenceAllocation != state.postLaunchGlobalVariables.end(),
			"Reference data corresponding to variable " << alloc_it->first
			<< " not found, malformed kernel checkpoint.");
		
		void* address = 0;
		
		cudaError_t result = cudaGetSymbolAddress(&address,
			alloc_it->second->name.c_str());
		
		if (result != cudaSuccess) {
			throw hydrazine::Exception(
				"Failed to get address of device global variable '"
				+ alloc_it->second->name + "'");
		}
		
		compareAllocation(errors, alloc_it->second->size(),
			referenceAllocation->second->data.data(), address);

		if (errors > 20) break;
	}	
	
	
	return errors == 0;
}

void util::KernelTestHarness::reset() {
	for(PointerMap::iterator pointer = pointers.begin();
		pointer != pointers.end(); ++pointer) {
		cudaFree((void*)pointer->second);
	}
	
	pointers.clear();
	ocelot::unregisterModule(state.launch.moduleName);
}

void util::KernelTestHarness::_setupTextures(
	const util::ExtractedDeviceState::Module &module) {
	// TODO
	assert(0 && "unimplemented yet");
}

void util::KernelTestHarness::_setupMemory() {
	// construct device allocations and retain mapping of pointers
	for (ExtractedDeviceState::GlobalAllocationMap::const_iterator
		alloc_it = state.globalAllocations.begin();
		alloc_it != state.globalAllocations.end(); ++alloc_it) {
		
		void *devicePtr;
		cudaError_t result = cudaMalloc((void **)&devicePtr,
			alloc_it->second->size());
		
		if (result != cudaSuccess) {
			report("failed to allocate " << alloc_it->second->size()
				<< " bytes on device");
			throw hydrazine::Exception(
				"Failed to allocate global memory allocation on device");
		}
		pointers[alloc_it->second->devicePointer] = devicePtr;
		
		report("constructed allocation " << alloc_it->second->devicePointer
			<< " (at " << devicePtr << ")");
				
		// copy
		result = cudaMemcpy(devicePtr, alloc_it->second->data.data(),
			alloc_it->second->size(), cudaMemcpyHostToDevice);
		if (result != cudaSuccess) {
			report(" failed to copy to new device allocation");
			throw hydrazine::Exception(
				"Failed to copy to new device allocation");
		}
	}

}

void util::KernelTestHarness::_setupModule() {
	report("setting up module (" << state.launch.moduleName << ")");
	
	// register launched module
	ExtractedDeviceState::ModuleMap::const_iterator 
		mod_it = state.modules.find(state.launch.moduleName);
	if (mod_it != state.modules.end()) {
	
		// register module
		{
			report("registering PTX module '" << state.launch.moduleName
				<< "'");
			std::stringstream file(mod_it->second.ptx);
			ocelot::registerPTXModule(file, state.launch.moduleName);
		}

	}
	
	// fill out the initial contents of global variables
	for (ExtractedDeviceState::GlobalVariableMap::const_iterator
		global = state.globalVariables.begin();
		global != state.globalVariables.end(); ++global) {
		cudaError_t result = cudaMemcpyToSymbol(global->second->name.c_str(),
			global->second->data.data(), global->second->size(), 0);

		if (result != cudaSuccess) {
			throw hydrazine::Exception(
				"Failed to copy to device global variable '"
				+ global->second->name + "'");
		}
	}
}

void util::KernelTestHarness::_setupExecution() {		
	report("setting up execution");
	_setupMemory();
	_setupModule();
}

////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	hydrazine::ArgumentParser parser(argc, argv);
	parser.description("Runs the specified kernel checkpoint through all "
		"available Ocelot devices, reports any failures.");
	
	std::string input;
	
	parser.parse("-i", "--input", input, "",
		"The name of a captured kernel trace file.");
	
	parser.parse();
	bool pass = true;
	
	std::stringstream stream;
	if (input != "") {
		std::ifstream file(input.c_str());
		if(file.is_open()) {
			util::KernelTestHarness test(file);
			
			int devices = 0;
			cudaGetDeviceCount(&devices);
			
			stream << "Running on " << devices << " devices:\n";
			
			for(int device = 0; device != devices; ++device) {
				try {
					cudaDeviceProp properties;
					cudaGetDeviceProperties(&properties, device);
			
					stream << " On device - " << device << " - '" 
						<< properties.name << "' ";
				
					cudaSetDevice(device);
				
					test.execute();
			
					if(test.compare()) {
						stream << "Pass\n";
					}
					else {
						stream << "Fail\n";
						pass = false;
					}
				
					test.reset();
				}
				catch(const std::exception& e) {
					stream << e.what() << "\n";
					pass = false;
				}
			}
		}
		else {
			std::cout << "Failed to open input file '"
				<< input << "' from memory.\n";
			pass = false;
		}
	}
	else {
		std::cout << "No input file specified.\n";
		std::cout << parser.help();
		pass = false;
	}

	if(pass) {
		std::cout << stream.str() << "Pass/Fail : Pass\n";
	}
	else {
		std::cout << stream.str() << "Pass/Fail : Fail\n";
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

