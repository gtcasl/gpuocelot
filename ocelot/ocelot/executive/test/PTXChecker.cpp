/*!
	\file PTXChecker.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\date 26 October 2009

	\brief uses the CUDA driver API to attempt to load a .ptx source module and print error messages
		if it fails
*/

#include <sstream>
#include <fstream>

#include <hydrazine/interface/Test.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/debug.h>

#include <ocelot/cuda/include/cuda.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

class PTXChecker : public test::Test {
public:

	PTXChecker() {
		name = "PTX Checker";

		status << "Test output:\n";
	}

	~PTXChecker() { }

	/*!
		Test driver
	*/
	bool doTest() {
		bool result = true;
		std::ostream &out = std::cout;

		if (ptxSourceFile != "") {
			CUresult result = cuInit(0);
			if (result != CUDA_SUCCESS) {
				out << "cuInit(0) failed with result " << result << std::endl;
				return false;
			}
			CUcontext context;
			result = cuCtxCreate(&context, 0, 0);
			if (result != CUDA_SUCCESS) {
				out << "cuCtxCreate() failed with result " << result << std::endl;
				return false;
			}
			CUmodule module;
			result = cuModuleLoad(&module, ptxSourceFile.c_str());
			if (result == CUDA_SUCCESS) {
				out << "Success" << std::endl;
			}
			else {
				out << "cuModuleLoad() failed with result " << result << std::endl;
			}
		}
		return result;
	}

public:

	std::string ptxSourceFile;
};

/////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv) {
	using namespace std;
	using namespace test;

	hydrazine::ArgumentParser parser( argc, argv );
	PTXChecker test;

	parser.description( test.testDescription() );

	parser.parse("-i", test.ptxSourceFile, "", "PTX source file");
	parser.parse();

	test.test();

	return (int)(test.passed() ? 0 : -1);
}

