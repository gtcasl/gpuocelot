/*!

*/


#include <sstream>
#include <fstream>

#include <hydrazine/interface/Test.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/implementation/debug.h>

#include <ocelot/executive/interface/Executive.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/RuntimeException.h>
#include <ocelot/executive/interface/CooperativeThreadArray.h>

#include <ocelot/trace/interface/TraceGenerator.h>

#include <math.h>

using namespace std;
using namespace ir;
using namespace executive;

extern "C" int test_entry();		// defined in TestMemoryTraceGenerator_kernel.cu

namespace test {

class TestMemoryTraceGenerator: public Test {
public:

	bool valid;
	
	TestMemoryTraceGenerator() {
		valid = true;
		
		name = "TestMemoryTraceGenerator";

		status << "Test output:\n";
	}
	
	bool doTest() {
		return (valid && (test_entry() == 0));
	}
};

}

/*!

*/
int main(int argc, char **argv) {
	using namespace std;
	using namespace ir;
	using namespace test;

	hydrazine::ArgumentParser parser( argc, argv );
	test::TestMemoryTraceGenerator test;

	parser.description( test.testDescription() );

	parser.parse( "-v", test.verbose, false, "Print out info after the test." );
	parser.parse();
	
	test.test();

	return test.passed();
}

///////////////////////////////////////////////////////////////////////////////////////////////////


