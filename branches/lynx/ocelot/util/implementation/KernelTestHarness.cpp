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

// Boost includes

// CUDA Includes

// Ocelot includes
#include <ocelot/util/interface/ExtractedDeviceState.h>

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
	
	std::cout << "KernelTestHarness:\n";
		testExtractedDeviceStateSerialize();
		
	if (help) {

	}
	else if (testSerialization) {
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

