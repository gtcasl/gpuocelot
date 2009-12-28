/*!
	\file TestTrace.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief simple test of the TraceGenerator class and subsystem
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

/*!
	A sample trace generator
*/
class Tracer: public trace::TraceGenerator {
public:
	std::ofstream file;
	int eventCount;

	Tracer(): file("testtrace.trace"), eventCount(0) {

	}

	~Tracer() {

	}

	/*!
		called when a traced kernel is launched to retrieve some parameters from the kernel
	*/
	void initialize(const executive::EmulatedKernel *kernel) {

	}

	/*!
		Called whenever an event takes place.

		Note, the const reference 'event' is only valid until event() returns
	*/
	void event(const trace::TraceEvent & event) {
		file << "[" << (eventCount++) << "]: " << event.toString() << "\n" << flush;
	}

};

class MemoryTraceGen: public trace::TraceGenerator {
public:
	std::ofstream file_Global, file_Shared;
	int eventCount;

	int uncoalescedGlobalLoads, uncoalescedGlobalStores;

	int threadCount;

	MemoryTraceGen(): 
		file_Global("memtrace_global.trace"), 
		file_Shared("memtrace_shared.trace"), 
		eventCount(0),
		uncoalescedGlobalLoads(0),
		uncoalescedGlobalStores(0),
		threadCount(0) {


	}

	~MemoryTraceGen() {

	}

	/*!
		called when a traced kernel is launched to retrieve some parameters from the kernel
	*/
	void initialize(const ir::ExecutableKernel& kernel) {
		threadCount = kernel.maxThreadsPerBlock();
	}

	/*!
		Called whenever an event takes place.

		Note, the const reference 'event' is only valid until event() returns
	*/
	void event(const trace::TraceEvent & event) {
		if (event.instruction->opcode == PTXInstruction::Ld || event.instruction->opcode == PTXInstruction::St) {
			if (event.instruction->addressSpace == PTXInstruction::Global) {
				// global load/store
				
				file_Global << PTXInstruction::toString(event.instruction->opcode) << ".global " << event.active << " ";
				for (size_t z = 0; z < event.memory_addresses.size(); z++) {
					file_Global << hex << event.memory_addresses[z] << " ";
				}
				file_Global << "\n";
			}
			else if (event.instruction->addressSpace == PTXInstruction::Shared) {
				file_Shared << PTXInstruction::toString(event.instruction->opcode) << ".shared " << event.active << " ";
				for (size_t z = 0; z < event.memory_addresses.size(); z++) {
					file_Shared << hex << event.memory_addresses[z] << " ";
				}
				file_Shared << "\n";
			}
		}
	}
};

#define SIZE 8

namespace test {

class TestTrace: public Test {
public:
	int threadCount;
	bool valid;

	Executive context;
	EmulatedKernel *kernel;
	CooperativeThreadArray cta;
	std::string module;

	float A[SIZE*SIZE], V[SIZE], R[SIZE];

	TestTrace() {
		valid = false;
		name = "TestTrace";

		status << "Test output:\n";

		threadCount = 8;

		module = "ocelot/executive/test/kernels.ptx";

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				A[i * SIZE + j] = 1.0f / (float)(1 + abs(i - j));
			}
			V[i] = 1.0f + (float)(i % 3);
			R[i] = -1;
		}
		
		if (!context.selectDeviceByISA(Instruction::Emulated)) {
			status << "Failed to select Emulated device\n";
			valid = false;
		}

		if (!context.loadModule(module)) {
			status << "failed to load module '" << module << "'\n";
			valid = false;
		}

		Kernel *rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z21k_matrixVectorProductPKfS0_Pfii");
		if (rawKernel == 0) {
			status << "failed to get kernel\n";
			valid = false;
		}
		else {
			kernel = static_cast<EmulatedKernel *>(rawKernel);
			kernel->setKernelShape(threadCount, 1, 1);
			valid = true;
		}
	}

	/*!
		Implements test
	*/
	bool  doTest() {
		MemoryTraceGen tracer;
		bool result = valid;

		if (valid) {
			context.registerExternal( A, sizeof(float) * SIZE * SIZE );
			context.registerExternal( V, sizeof(float) * SIZE );
			context.registerExternal( R, sizeof(float) * SIZE );
			// configure trace generator
			kernel->addTraceGenerator(&tracer);

			// configure parameters
			Parameter &param_A = kernel->getParameter(
				"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii___val_paramA");
			Parameter &param_V = kernel->getParameter(
				"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii___val_paramV");
			Parameter &param_R = kernel->getParameter(
				"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_R");
			Parameter &param_M = kernel->getParameter(
				"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_M");
			Parameter &param_N = kernel->getParameter(
				"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_N");

			// set parameter values
			param_A.arrayValues.resize(1);
			param_A.arrayValues[0].val_u64 = (PTXU64)A;
			param_V.arrayValues.resize(1);
			param_V.arrayValues[0].val_u64 = (PTXU64)V;
			param_R.arrayValues.resize(1);
			param_R.arrayValues[0].val_u64 = (PTXU64)R;
			param_M.arrayValues.resize(1);
			param_M.arrayValues[0].val_u64 = (PTXU64)SIZE;
			param_N.arrayValues.resize(1);
			param_N.arrayValues[0].val_u64 = (PTXU64)SIZE;
		
			kernel->updateParameterMemory();

			// launch the kernel
			try {
				kernel->setKernelShape(threadCount,1,1);
				kernel->launchGrid(1,1);
				context.synchronize();
			}
			catch (RuntimeException &exp) {
				status << "[m-v test] Runtime exception on instruction [ " 
					<< exp.instruction.toString() << " ]:\n" 
					<< exp.message << "\n";
				result = false;
			}

			kernel->removeTraceGenerator(&tracer);

			if (result) {
				// now make sure the kernel worked
				float sq_error = 0;
				for (int i = 0; i < SIZE; i++) {
					float x = 0;
					for (int k = 0; k < SIZE; k++) {
						x += A[i + k * SIZE] * V[k];
					}
					x = R[i] - x;
					sq_error += x * x;
				}
				if (sq_error > 0.01) {
					result = false;
				}
			}
			
			context.free(A);
			context.free(R);
			context.free(V);
		}

		return result;
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
	test::TestTrace test;

	parser.description( test.testDescription() );

	parser.parse( "-s", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", test.verbose, false, "Print out info after the test." );
	parser.parse();

	test.test();

	return test.passed();
}

