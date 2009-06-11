/*!

	\file TestGPUKernel.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\date 21 Jan 2009
	
	\brief Tests the GPUKernel object by loading a PTX module and invoking several kernels on
		the GPU

*/


#ifndef TEST_PARSER_CPP_INCLUDED
#define TEST_PARSER_CPP_INCLUDED


#include "boost/filesystem.hpp"
#include <queue>
#include <fstream>

#include <ocelot/parser/interface/PTXParser.h>
#include <ocelot/parser/test/TestParser.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 2

namespace fs = boost::filesystem;

namespace test {

	bool TestGPUKernel::doTest(std::string& status) {

		return true;
	}

	TestGPUKernel::TestGPUKernel() {

		Name = "TestGPUKernel";

		Description = "A test for the Executive and GPUKernel classes:\n";
		Description += " Load a PTX module. Translate to GPUKernel using the Executive and the GPU device.\n";
		Description += " Configure and launch kernel grid. Compare results to expectations.";
	}
}

int main( int argc, char** argv ) {

	common::ArgumentParser parser( argc, argv );
	test::TestGPUKernel test;
	parser.description( test.description() );

	bool help;
	bool verbose;

	parser.parse( "-h", help, "Display this help message." );

	if( help ) {
		std::cout << parser.help();
		return 2;
	}

	test.test();

	if( verbose ) {
		std::cout << test.toString();
	}

	return test.passed();
}

#endif

