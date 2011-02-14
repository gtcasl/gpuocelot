/*!
	\file KernelTestHarness.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 31 January 2011
	\brief loads serialized device state and module. Configures device with 'before' state, executes
		a kernel, then compares resulting state to loaded 'after' state.
		
		Reports kernel runtime, correctness of results. Useful for analysis and unit testing
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
#include <ocelot/util/interface/KernelTestHarness.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////

// whether debugging messages are printed
#define REPORT_BASE 0

//////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

static dim3 toDim3(const ir::Dim3 &d) {
	return dim3(d.x, d.y, d.z);
}

/*
static ir::Dim3 toDim3(const dim3 &d) {
	return ir::Dim3(d.x, d.y, d.z);
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////

util::KernelTestHarness::KernelTestHarness(std::istream &input): state(input) {
	report("deserialized application");
}

util::KernelTestHarness::~KernelTestHarness() {

}

void util::KernelTestHarness::execute() {
	_setupExecution();

	// examine parameter memory, map pointers to pointers
	cudaError_t result = cudaConfigureCall(toDim3(state.launch.gridDim), toDim3(state.launch.blockDim), 
		state.launch.sharedMemorySize);
	if (result != cudaSuccess) {
		report("failed to configure function call")
		throw hydrazine::Exception("failed to configure function call");
	}

	// map parameter memory according to pointer rules
	for (size_t i = 0; i < state.launch.parameterMemory.size(); i += sizeof(void *)) {
		PointerMap::iterator p_it = pointers.find(*(void **)&state.launch.parameterMemory[i]);
		if (p_it != pointers.end()) {
			*(void **)&state.launch.parameterMemory[i] = p_it->second;
		}	
	}

	result = cudaSetupArgument(&state.launch.parameterMemory[0], state.launch.parameterMemory.size(), 0);
	if (result != cudaSuccess) {
		report("Failed to setup parameter memory");
		throw hydrazine::Exception("Failed to setup parameter memory");
	}
	
	ocelot::launch(state.launch.moduleName, state.launch.kernelName);
}

bool util::KernelTestHarness::compare() {
	// visit each allocation and compare 'after' results to 'before'
	
	// construct device allocations and retain mapping of pointers
	for (ExtractedDeviceState::GlobalAllocationMap::const_iterator alloc_it = state.globalAllocations.begin();
		alloc_it != state.globalAllocations.end(); ++alloc_it) {
		
		
	}
	
	return false;
}

void util::KernelTestHarness::_setupTextures(const util::ExtractedDeviceState::Module &module) {
	// TODO
	assert(0 && "unimplemented yet");
}

void util::KernelTestHarness::_setupMemory() {
	// construct device allocations and retain mapping of pointers
	for (ExtractedDeviceState::GlobalAllocationMap::const_iterator alloc_it = state.globalAllocations.begin();
		alloc_it != state.globalAllocations.end(); ++alloc_it) {
		
		void *devicePtr;
		cudaError_t result = cudaMalloc((void **)&devicePtr, alloc_it->second->size());
		
		if (result != cudaSuccess) {
			report("failed to allocate " << alloc_it->second->size() << " bytes on device");
			throw hydrazine::Exception("Failed to allocate global memory allocation on device");
		}
		pointers[alloc_it->second->devicePointer] = devicePtr;
		
		report("constructed allocation " << alloc_it->second->devicePointer << " (at " << devicePtr << ")");
				
		// copy
		result = cudaMemcpy(devicePtr, &alloc_it->second->data[0], alloc_it->second->size(), cudaMemcpyHostToDevice);
		if (result != cudaSuccess) {
			report("failed to copy to new device allocation");
			throw hydrazine::Exception("Failed to copy to new device allocation");
		}
	}
}

void util::KernelTestHarness::_setupModule() {
	report("setting up module (" << state.launch.moduleName << ")");
	
	// register launched module
	ExtractedDeviceState::ModuleMap::const_iterator mod_it = state.modules.find(state.launch.moduleName);
	if (mod_it != state.modules.end()) {
	
		// register module
		{
			report("registering PTX module '" << state.launch.moduleName << "' [" << mod_it->second.ptxFile << "]");
			std::ifstream file(mod_it->second.ptxFile);
			ocelot::registerPTXModule(file, state.launch.moduleName);
		}
		
		// configure global variables
		for (ExtractedDeviceState::GlobalVariableMap::const_iterator alloc_it = mod_it->second.globalVariables.begin(); 
			alloc_it != mod_it->second.globalVariables.end(); ++alloc_it) {
			
			void *devicePtr;
			cudaError_t result = cudaGetSymbolAddress(&devicePtr, alloc_it->first.c_str());
			if (result != cudaSuccess) {
				report("failed to get address of symbol '" << alloc_it->first << "' from module " << mod_it->second.name);
				throw hydrazine::Exception("failed to get address of symbol");
			}
			pointers[alloc_it->second->devicePointer] = devicePtr;
			
			result = cudaMemcpy(devicePtr, (void *)&alloc_it->second->data[0], alloc_it->second->size(), cudaMemcpyHostToDevice);
			if (result != cudaSuccess) {
				throw hydrazine::Exception("failed to copy initial values to global variable");
			}
		}		
		
		// look for pointer values and assume they should be updated among global variables whose
		// size is sizeof(void*)
		for (ExtractedDeviceState::GlobalVariableMap::const_iterator alloc_it = mod_it->second.globalVariables.begin(); 
			alloc_it != mod_it->second.globalVariables.end(); ++alloc_it) {

			size_t symbolSize = 0;
			void *devicePtr;
			cudaError_t result = cudaGetSymbolSize(&symbolSize, alloc_it->first.c_str());
			if (result != cudaSuccess) {
				report("failed to get size of symbol '" << alloc_it->first << "'");
				throw hydrazine::Exception("failed to get size of symbol");
			}
			if (symbolSize == sizeof(void*)) {
				PointerMap::iterator p_it = pointers.find(*(void **)&alloc_it->second->data[0]);
				if (p_it != pointers.end()) {
					result = cudaGetSymbolAddress(&devicePtr, alloc_it->first.c_str());
					if (result != cudaSuccess) {
						throw hydrazine::Exception("failed to get symbol address even though it's been previously written to");
					}
					result = cudaMemcpy(devicePtr, & p_it->second, sizeof(void*), cudaMemcpyHostToDevice);
					if (result != cudaSuccess) {
						throw hydrazine::Exception("failed to copy to a symbol");
					}
				}
			}
		}
	}
}

void util::KernelTestHarness::_setupExecution() {		
	report("setting up execution");
	_setupMemory();
	_setupModule();
}

void util::KernelTestHarness::_extractResultState() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////

static void testExtractedDeviceStateSerialize() {
	util::ExtractedDeviceState deviceState;
	
	// setup device state
	deviceState.application.name = "KernelTestHarness";
	deviceState.application.cudaDevice = "simulated CUDA device";
	
	// modules
	util::ExtractedDeviceState::Module module;
	module.name = "testModule";
	module.ptxFile = "textModule.ptx";
	deviceState.modules[module.name] = module;
	
	// global allocations
	void *ptr[] = { (void *)0x00a000000, (void *)0x00b000000};
	deviceState.globalAllocations[ptr[0]] = new util::ExtractedDeviceState::MemoryAllocation(ptr[0], 16);
	deviceState.globalAllocations[ptr[1]] = new util::ExtractedDeviceState::MemoryAllocation(ptr[1], 16);
	
	// kernel launch
	deviceState.launch.moduleName = "";
	deviceState.launch.kernelName = "";
	deviceState.launch.blockDim = ir::Dim3(32, 2, 1);
	deviceState.launch.gridDim = ir::Dim3(4, 4, 4);
	deviceState.launch.sharedMemorySize = 0;
	deviceState.launch.parameterMemory.resize(2*sizeof(void*), 0);
	std::memcpy(&deviceState.launch.parameterMemory[0], &ptr[0], sizeof(void *));
	std::memcpy(&deviceState.launch.parameterMemory[sizeof(void*)], &ptr[1], sizeof(void *));
	
	// serialize device state
	deviceState.serialize(std::cout);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	hydrazine::ArgumentParser parser(argc, argv);
	
	std::string input;
	bool help;
	bool testSerialization;
	
	parser.parse("-i", "--input", input, "", "Serialization output from libKernelExtractor.la");
	parser.parse("-h", "--help", help, false, "Displays this usage statement.");
	parser.parse("-s", "--test-serialization", testSerialization, false, "Performs a sample serialization to stdout");
			
	if (help) {

	}
	else if (testSerialization) {
		testExtractedDeviceStateSerialize();
	}
	else if (input != "") {
		std::ifstream file(input.c_str());	
			util::KernelTestHarness test(file);
			test.execute();

			if (test.compare()) {
				std::cout << "Test Passed" << std::endl;
			}
			else {
				std::cout << "TEST FAILED" << std::endl;
			}
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

