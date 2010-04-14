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

#include <hydrazine/implementation/Exception.h>
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
	bool loaded = false;
	
	string path = "ocelot/executive/test/kernels.ptx";
	
	try {
		loaded = module.load(path);
	}
	catch(const hydrazine::Exception& e) {
		status << " error - " << e.what() << "\n";
	}

	if(!loaded) {
		status << "failed to load module '" << path << "'\n";
		return (result = false);
	}
	
	report("loaded module");
	
	rawKernel = module.getKernel("_Z19k_sequenceDivergentPf");
	if (!rawKernel) {
		status << "failed to get kernel\n";
		return (result = false);
	}

	rawKernel = module.getKernel("_Z17k_sequenceLoopingPfi");
	if (!rawKernel) {
		status << "failed to get kernel\n";
		return (result = false);
	}

	rawKernel = module.getKernel("_Z21k_matrixVectorProductPKfS0_Pfii");
	if (!rawKernel) {
		status << "failed to get kernel \n";
		return (result = false);
	}

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
	
	kernelDivergence = 0;
	kernelLooping = 0;
	kernelMVProduct = 0;
	
	description = "A test for the Executive and GPUKernel classes:\n";
	description += " Load a PTX module. Translate to NVIDIAExecutableKernel using the Executive and the GPU device.\n";
	description += " Configure and launch kernel grid. Compare results to expectations.";
}

test::TestGPUKernel::~TestGPUKernel() {
	delete kernelDivergence;
	delete kernelLooping;
	delete kernelMVProduct;
}

int main( int argc, char** argv ) {
	test::TestGPUKernel testApp;
	bool verbose = true;
	
	testApp.test();

	if( verbose ) {
		std::cout << testApp.toString();
	}
	
	return testApp.passed();
}

#endif

