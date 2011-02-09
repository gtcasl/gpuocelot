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
	
	// allocations before
	util::ExtractedDeviceState::MemoryAllocation alloc[6];
	alloc[0].base = new char[128];
	alloc[0].size = 128;
	for (size_t n = 0; n < alloc[0].size; n++) {
		alloc[0].base[n] = (char )(n >> 1);
	}
	alloc[1].base = new char[32];
	alloc[1].size = 32;
	for (size_t n = 0; n < alloc[1].size; n++) {
		alloc[1].base[n] = (char )n;
	}
	alloc[2].base = new char[32];
	alloc[2].size = 32;
	for (size_t n = 0; n < alloc[2].size; n++) {
		alloc[2].base[n] = 0;
	}
	
	// allocations after
	alloc[3].base = new char[128];
	alloc[3].size = 128;
	for (size_t n = 0; n < alloc[3].size; n++) {
		alloc[3].base[n] = (char )(n >> 1);
	}
	alloc[4].base = new char[32];
	alloc[4].size = 32;
	for (size_t n = 0; n < alloc[4].size; n++) {
		alloc[4].base[n] = (char )n;
	}
	alloc[5].base = new char[32];
	alloc[5].size = 32;
	for (size_t n = 0; n < alloc[5].size; n++) {
		alloc[5].base[n] = (alloc[3].base[n] & alloc[4].base[n]);
	}
	deviceState.globalAllocationsBefore[alloc[0].base] = &alloc[0];
	deviceState.globalAllocationsBefore[alloc[1].base] = &alloc[1];
	deviceState.globalAllocationsBefore[alloc[2].base] = &alloc[2];
	deviceState.globalAllocationsAfter[alloc[3].base] = &alloc[3];
	deviceState.globalAllocationsAfter[alloc[4].base] = &alloc[4];
	deviceState.globalAllocationsAfter[alloc[5].base] = &alloc[5];
	
	// modules
	util::ExtractedDeviceState::Module module;
	module.name = "testModule";
	module.ptx = "	.version 2.1"
"	.target sm_20"
".entry genericmemory ("
".param .u64 __cudaparm_genericmemory_A)"
"{"
".reg .u32 %r<9>;"
".reg .u64 %rd<5>;"
".reg .pred %p<9>;"
".shared .u32 $rs;"
".local .u32 $rl;"
"$BB_01:"
""
"	ld.param.u64 %rd1, [__cudaparm_genericmemory_A];"
"	"
"	mov.u64 %rd2, %rd1;"
"	mov.u64 %rd3, $rs;"
"	mov.u64 %rd4, $rl;"
"	"
"	//"
"	//"
"	//"
"	"
"	cvta.global.u64 %rd2, %rd2;"
"	cvta.shared.u64 %rd3, %rd3;"
"	cvta.local.u64 %rd4, %rd4;"
"	"
"	//"
"	//"
"	//"
"	"
"	isspacep.global %p0, %rd2;			// expect TRUE"
"	isspacep.shared %p1, %rd3;			// expect TRUE"
"	isspacep.local %p2, %rd4;				// expect TRUE"
""
"	isspacep.global %p3, %rd3;			// expect all others to be FALSE"
"	isspacep.shared %p4, %rd4;"
"	isspacep.local %p5, %rd2;"
""
"	isspacep.global %p6, %rd4;"
"	isspacep.shared %p7, %rd2;"
"	isspacep.local %p8, %rd3;"
"	"
"	//"
"	//"
"	//"
"	"
"	selp.u32 %r0, 1000, 0, %p0;"
"	selp.u32 %r8, 1008, 0, %p8;"
"	"
""
"	st.global.u32 [%rd1+0], %r0;"
"	st.global.u32 [%rd1+4], %r1;"
"	st.global.u32 [%rd1+8], %r2;"
"	"
"$BB_02:"
"	exit;"
"}"
"";
	
	deviceState.modules[module.name] = module;
	
	// kernel launch
	deviceState.launch.moduleName = "";
	deviceState.launch.kernelName = "";
	deviceState.launch.blockDim = ir::Dim3(32, 2, 1);
	deviceState.launch.gridDim = ir::Dim3(4, 4, 4);
	deviceState.launch.parameterMemorySize = 24;
	deviceState.launch.sharedMemorySize = 0;
	deviceState.launch.parameterMemory = new char[deviceState.launch.parameterMemorySize];
	std::memcpy(&deviceState.launch.parameterMemory[0], &alloc[0].base, sizeof(void *));
	std::memcpy(&deviceState.launch.parameterMemory[8], &alloc[1].base, sizeof(void *));
	std::memcpy(&deviceState.launch.parameterMemory[16], &alloc[2].base, sizeof(void *));
	
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

