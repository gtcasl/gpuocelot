/*!

	\file TestGPUKernel.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date 21 Jan 2009
	
	\brief Tests the GPUKernel object by loading a PTX module and invoking several kernels on
		the GPU

*/


#ifndef TEST_PARSER_CPP_INCLUDED
#define TEST_PARSER_CPP_INCLUDED

#include <ocelot/parser/interface/PTXParser.h>
#include <ocelot/parser/test/TestParser.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/debug.h>

#include <ocelot/executive/test/TestGPUKernel.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

/*!
	Tests initialization of executive, load of kernel, and translation to 
		EmulatedKernel
*/
bool test::TestGPUKernel::loadKernels() {
	using namespace std;
	using namespace ir;
	using namespace executive;

	Kernel *rawKernel = 0;
	
	bool result = true;
	
	string module = "ocelot/executive/test/kernels.ptx";
	
	report("selecting GPU device");
	
	if (!context.selectDeviceByISA(Instruction::GPU)) {
		status << "Failed to select GPU device\n";
		return (result = false);
	}

	report("selected GPU device");
	
	try {
		if (!context.loadModule(module)) {
			status << "failed to load module '" << module << "'\n";
			return (result = false);
		}
	}
	catch (...) {
		cout << "context.loadModule() threw an exception\n  " << status.str() << "\n" << flush;
		throw;
	}
	
	report("loaded module");
	
	rawKernel = context.getKernel(Instruction::GPU, module, 
		"_Z19k_sequenceDivergentPf");
	if (!rawKernel) {
		status << "failed to get kernel\n";
		return (result = false);
	}

	kernelDivergence = static_cast<GPUExecutableKernel *>(rawKernel);
	kernelDivergence->setKernelShape(ThreadCount, 1, 1);

	rawKernel = context.getKernel(Instruction::GPU, module, 
		"_Z17k_sequenceLoopingPfi");
	if (!rawKernel) {
		status << "failed to get kernel\n";
		return (result = false);
	}

	kernelLooping = static_cast<GPUExecutableKernel *>(rawKernel);
	kernelLooping->setKernelShape(ThreadCount, 1, 1);

	rawKernel = context.getKernel(Instruction::GPU, module,
		"_Z21k_matrixVectorProductPKfS0_Pfii");
	if (!rawKernel) {
		status << "failed to get kernel \n";
		return (result = false);
	}
	kernelMVProduct = static_cast<GPUExecutableKernel *>(rawKernel);
	kernelMVProduct->setKernelShape(ThreadCount, 1, 1);

	return true;
}

bool test::TestGPUKernel::doTest() {

	bool result = loadKernels();
	if (!result) {
		return result;
	}

	return true;
}

test::TestGPUKernel::TestGPUKernel() {

	name = "TestGPUKernel";
	ThreadCount = 8;
	
	description = "A test for the Executive and GPUKernel classes:\n";
	description += " Load a PTX module. Translate to GPUExecutableKernel using the Executive and the GPU device.\n";
	description += " Configure and launch kernel grid. Compare results to expectations.";
}

int main( int argc, char** argv ) {
	test::TestGPUKernel testApp;
	bool verbose = true;
	/*
	hydrazine::ArgumentParser parser( argc, argv );
	parser.description( testApp.testDescription() );

	bool help = false;

	parser.parse( "-h", help, "Display this help message.", false );
	parser.parse( "-v", verbose, "Verbose output", false );

	if( help ) {
		std::cout << parser.help();
		return 2;
	}
	*/
	
	testApp.test();

	if( verbose ) {
		std::cout << testApp.toString();
	}
	
	return testApp.passed();
}

#endif

