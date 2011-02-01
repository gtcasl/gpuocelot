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

// Hydrazine includes
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/json.h>

// Boost includes

// CUDA Includes

////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	hydrazine::ArgumentParser parser;
	
	std::string input;
	bool help;
	
	parser.parse("-i", "--input", input, "", "Serialization output from libKernelExtractor.la");
	parser.parse("-h", "--help", help, false, "Displays this usage statement.");
	
	
	
	if (help || input == "") {
	
	}
	else {
	
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

