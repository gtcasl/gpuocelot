/*! \file   TestExternalFunctions.cpp
	\date   Thursday April 7, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the TestExternalFunctions class.
*/

#ifndef TEST_EXTERNAL_FUNCTIONS_CPP_INCLUDED
#define TEST_EXTERNAL_FUNCTIONS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/api/test/TestExternalFunctions.h>
#include <ocelot/api/interface/ocelot.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

// Hydrazine Includes
#include <hydrazine/implementation/ArgumentParser.h>

namespace test
{

TestExternalFunctions::TestExternalFunctions()
{
	name = "TestExternalFunctions";
	
	description = "A unit test for calling an external host function from PTX\n"
		"\n"
		"\t1) The first test calls malloc/free from a PTX kernel.\n"
		"\t2) The second test calls printf from a PTX kernel.\n"
		"\t3) The last test calls a user defined function from a PTX kernel.\n";
}

bool TestExternalFunctions::testMallocFree()
{
	std::string ptx = ".version 2.3\n"
		".address_size 64\n"
		"\n"
		".extern .func (.param .u64 pointer) malloc (.param .u64 bytes)\n"
		".extern .func free (.param .u64 pointer)\n"
		"\n"
		".entry kernel(.param .u64 result) {\n"
		"\t.reg .u64 %r<10>;\n"
		"\t.param .u64 returned;\n"
		"\t.param .u64 value;\n"
		"\t.param .u64 freeValue;\n"
		"\t\n"
		"\tmov.u64 %r0, 8;\n"
		"\tst.param.u64 [value], %r0;\n"
		"\tcall.uni (returned), malloc, (value);\n"
		"\tld.param.u64 %r1, [returned];\n"
		"\tst.global.u64 [%r1], %r0;\n"
		"\tld.global.u64 %r2, [%r1];\n"
		"\tld.param.u64 %r3, [result];\n"
		"\tst.global.u64 [%r3], %r2;\n"
		"\tst.param.u64 [freeValue], %r1;\n"
		"\tcall.uni free, (freeValue);\n"
		"\texit;\n"
		"}\n";

	std::stringstream stream(ptx);
	ocelot::registerPTXModule(stream, "someModule");
	
	long long unsigned int* sizeOfData = 0;
	cudaMalloc((void**)&sizeOfData, sizeof(long long unsigned int));
	
	cudaSetupArgument(&sizeOfData, sizeof(long long unsigned int), 0);
	cudaConfigureCall(dim3(1, 1, 1), dim3(1, 1, 1), 0, 0);
	ocelot::launch("someModule", "kernel");
	
	long long unsigned int result = 0;
	
	cudaMemcpy(&result, sizeOfData, sizeof(long long unsigned int),
		cudaMemcpyDeviceToHost);
	
	cudaFree(sizeOfData);
	ocelot::unregisterModule("someModule");
	
	return result == sizeof(long long unsigned int);
	
}

bool TestExternalFunctions::doTest()
{
	return testMallocFree();
}

}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser(argc, argv);
	test::TestExternalFunctions test;
	parser.description(test.testDescription());

	parser.parse( "-s", "--seed", test.seed, 0, 
		"Random number generator seed, 0 implies seed with time." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out information after the test has finished." );
	parser.parse();
	
	test.test();
	
	return test.passed();	
}

#endif

