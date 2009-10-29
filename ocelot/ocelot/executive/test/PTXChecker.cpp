/*!
	\file PTXChecker.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 26 October 2009
	\brief uses the CUDA driver API to attempt to load a .ptx source module 
		and print error messages if it fails
*/

#include <sstream>
#include <fstream>

#include <hydrazine/interface/Test.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/debug.h>

#include <ocelot/cuda/include/cuda.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h> /* mmap() is defined in this header */
#include <fcntl.h>


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
		std::ostream &out = std::cout;
		#if HAVE_CUDA_DRIVER_API == 1
		bool result = true;
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

			void *src = 0;
			int fdin;
			struct stat statbuf;

			/* open the input file */
			if ((fdin = open (ptxSourceFile.c_str(), O_RDONLY)) < 0) {
				printf("can't open %s for reading", ptxSourceFile.c_str());
			}

			/* find size of input file */
			if (fstat (fdin,&statbuf) < 0) {
				printf("fstat error");
			}

			/* mmap the input file */
			if ((src = mmap (0, statbuf.st_size, PROT_READ, MAP_SHARED, fdin, 0))	== (caddr_t) -1) {
				printf("mmap error");
			}

			CUjit_option options[] = { CU_JIT_ERROR_LOG_BUFFER, CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES };
			const int errorLogSize = 2048;
			int errorLogActualSize = errorLogSize;
			char errorLogBuffer[errorLogSize] = {0};

			void *optionValues[2] = { (void *)errorLogBuffer, (void *)errorLogActualSize };
			result = cuModuleLoadDataEx(&module, src, 2, options, optionValues);
			if (result == CUDA_SUCCESS) {
				out << "Success" << std::endl;
			}
			else {
				out << "cuModuleLoad() failed with result " << result << std::endl;
				out << errorLogBuffer << "\n";
			}
		}
		return result;
		#else
			out << "No CUDA Driver API support\n";
			return false;
		#endif
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

