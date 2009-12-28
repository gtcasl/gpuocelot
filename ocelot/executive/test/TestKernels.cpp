/*!
	\file TestKernels.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief tests a variety of CUDA kernels using the emulator. Validation is performed by
	comparing results to known kernel results.
*/

#include <cmath>

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
#include <hydrazine/implementation/Timer.h>

#include <iostream>

using namespace ir;
using namespace executive;

namespace test {

class TestKernels: public Test {
public:
	
	EmulatedKernel *kernelDivergence;
	EmulatedKernel *kernelLooping;
	EmulatedKernel *kernelMVProduct;

	Executive context;

	int ThreadCount;

	TestKernels() {
		name = "TestKernels";

		status << "Test output:\n";

		ThreadCount = 8;
	}

	std::ostream & print(std::ostream &out, EmulatedKernel *kernel) {
		for (unsigned int i = 0; i < kernel->instructions.size(); i++) {
			const PTXInstruction &instr = kernel->instructions[i];
			out << " [" << i << "] " << instr.toString();
			switch (instr.opcode) {
				case PTXInstruction::Bra:
					out << " // [target: " << instr.branchTargetInstruction 
						<< ", reconverge: " << instr.reconvergeInstruction 
						<< "]";
					break;
				default:
					break;
			}
			out << "\n";
		}
		return out;
	}

	/*!
		Tests initialization of executive, load of kernel, and translation to 
			EmulatedKernel
	*/
	bool loadKernels() {
		using namespace std;
		using namespace ir;
		using namespace executive;

		Kernel *rawKernel = 0;
		
		bool result = true;
		
		string module = "ocelot/executive/test/kernels.ptx";
		
		if (!context.selectDeviceByISA(Instruction::Emulated)) {
			status << "Failed to select Emulated device\n";
			return (result = false);
		}

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
		rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z19k_sequenceDivergentPf");
		if (!rawKernel) {
			status << "failed to get kernel\n";
			return (result = false);
		}

		kernelDivergence = static_cast<EmulatedKernel *>(rawKernel);
		kernelDivergence->setKernelShape(ThreadCount, 1, 1);

		rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z17k_sequenceLoopingPfi");
		if (!rawKernel) {
			status << "failed to get kernel\n";
			return (result = false);
		}

		kernelLooping = static_cast<EmulatedKernel *>(rawKernel);
		kernelLooping->setKernelShape(ThreadCount, 1, 1);

		rawKernel = context.getKernel(Instruction::Emulated, module,
			"_Z21k_matrixVectorProductPKfS0_Pfii");
		if (!rawKernel) {
			status << "failed to get kernel \n";
			return (result = false);
		}
		kernelMVProduct = static_cast<EmulatedKernel *>(rawKernel);
		kernelMVProduct->setKernelShape(ThreadCount, 1, 1);

		return true;
	}
	
	bool testDivergent() {
		using namespace std;

		bool result = true;
		EmulatedKernel *kernel = kernelDivergence;

		stringstream out;
		
		out << "divergent control flow kernel\n";
		print(out, kernel);

		if (result) {
			// allocate some data
			int N = ThreadCount;
			float *sequence = (float *)malloc(sizeof(float)*N);
			context.registerExternal(sequence, sizeof(float)*N);

			for (int i = 0; i < N; i++) {
				sequence[i] = -2;	
			}

			// configure parameters
			Parameter &param_A = kernel->getParameter(
				"__cudaparm__Z19k_sequenceDivergentPf_ptr");

			// set parameter values
			param_A.arrayValues.resize(1);
			param_A.arrayValues[0].val_u64 = (PTXU64)sequence;
			kernel->updateParameterMemory();

			hydrazine::Timer timer;
			timer.start();

			// launch the kernel
			try {
				kernel->setKernelShape(N,1,1);
				kernel->launchGrid(1,1);
				// context.synchronize();
			}
			catch (RuntimeException &exp) {
				out << "[divergent test] Runtime exception on instruction [ " 
					<< exp.instruction.toString() << " ]:\n" 
					<< exp.message << "\n";
				result = false;
			}
			
			timer.stop();
			
			cout << "Kernel launch time was " << timer.toString() << "\n";

			if (result) {
				for (int i = 0; i < N; i++) {
					float w = (float)i * 0.0625f;
					if (i % 2) {
						if (fabs(cos(w) - sequence[i]) > 0.001f) {
							out << "error on element " << i << " - cos(" << w << ") = " << cos(w) 
								<< ", encountered " << sequence[i] << "\n";
							result = false;
						}
					}
					else {
						if (fabs(sin(w) - sequence[i]) > 0.001f) {
							out << "error on element " << i << " - sin(" << w << ") = " << sin(w) 
								<< ", encountered " << sequence[i] << "\n";
							result = false;
						}
					}
				}
			}
			context.free(sequence);
			free(sequence);
		}

		if (!result) {
			status << out.str();
		}
		else {
			status << "divergent control flow succeeded\n";
		}
		return result;
	}
	
	
	bool testLooping() {
		using namespace std;

		bool result = true;

		bool local_verbose = false;
		
		EmulatedKernel *kernel = kernelLooping;
		stringstream out;

		out << "looping kernel with divergent control flow\n";
		print(out, kernel);

		if (result) {
			// allocate some data
			int N = ThreadCount * 5;
			float *sequence = (float *)malloc(sizeof(float)*N);
			context.registerExternal(sequence, sizeof(float)*N);

			for (int i = 0; i < N; i++) {
				sequence[i] = -2;	
			}

			// configure parameters
			Parameter &param_A = kernel->getParameter(
				"__cudaparm__Z17k_sequenceLoopingPfi_ptr");
			Parameter &param_B = kernel->getParameter(
				"__cudaparm__Z17k_sequenceLoopingPfi_N");

			// set parameter values
			param_A.arrayValues.resize(1);
			param_A.arrayValues[0].val_u64 = (PTXU64)sequence;
			param_B.arrayValues.resize(1);
			param_B.arrayValues[0].val_u64 = (PTXU64)N;
			kernel->updateParameterMemory();

			// launch the kernel
			try {
				kernel->setKernelShape(ThreadCount,1,1);
				kernel->launchGrid(1,1);
				context.synchronize();
			}
			catch (RuntimeException &exp) {
				out << "[looping test] Runtime exception on instruction [ " 
					<< exp.instruction.toString() << " ]:\n" 
					<< exp.message << "\n";
				result = false;
			}

			for (int i = 0; i < N; i++) {
				float w = (float)i * 0.0625f;
				if (i % 2) {
					if (fabs(cos(w) - sequence[i]) > 0.001f) {
						out << "error on element " << i << " - cos(" << w << ") = " << cos(w) 
							<< ", encountered " << sequence[i] << "\n";
						result = false;
					}
				}
				else {
					if (fabs(sin(w) - sequence[i]) > 0.001f) {
						out << "error on element " << i << " - sin(" << w << ") = " << sin(w) 
							<< ", encountered " << sequence[i] << "\n";
						result = false;
					}
				}
			}
			
			context.free(sequence);
			free(sequence);
		}
		if (result) {
			status << "looping kernel succeeded\n";
		}
		if (local_verbose || !result) {
			status << out.str();
		}
		return result;
	}

	bool testMatrixVectorProduct() {
		using namespace std;

		bool result = true;

		bool local_verbose = false;
		
		EmulatedKernel *kernel = kernelMVProduct;

		stringstream out;

		out << "matrix-vector product kernel\n";
		print(out, kernel);

		if (result) {
			const int M = 8, N = 8;

			float *A = new float[M * N];
			float *V = new float[N];
			float *R = new float[M];

			context.registerExternal(A, sizeof(float)*N*M);
			context.registerExternal(V, sizeof(float)*N);
			context.registerExternal(R, sizeof(float)*M);

			// initialize A and V
			out << "A = [\n";
			for (int i = 0; i < M; i++) {
				out << " ";
				for (int j = 0; j < N; j++) {
					A[i + j * N] = 0;
					if (i >= j) {
						A[i + j * N] = 1.0f / (float)(1 + i - j);
					}
					V[j] = (float)(1 + j);
					out << A[i + j * N] << " ";
				}
				R[i] = -2;
				out << ";\n";
			}
			out << "];\n";

			out << "V = [\n";
			for (int j = 0; j < N; j++) {
				out << " " << V[j] << " ;\n";
			}
			out << "];\n";

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
			param_M.arrayValues[0].val_u64 = (PTXU64)M;
			param_N.arrayValues.resize(1);
			param_N.arrayValues[0].val_u64 = (PTXU64)N;
			
			kernel->updateParameterMemory();

			// launch the kernel
			try {
				kernel->setKernelShape(ThreadCount,1,1);
				kernel->launchGrid(1,1);
				context.synchronize();
			}
			catch (RuntimeException &exp) {
				out << "[m-v test] Runtime exception on instruction [ " 
					<< exp.instruction.toString() << " ]:\n" 
					<< exp.message << "\n";
				result = false;
			}

			if (result) {
				out << "R = [\n";
				for (int i = 0; i < M; i++) {
					float r_ref = 0;
					for (int j = 0 ; j < N; j++) {
						r_ref += V[j] * A[i + j * N];
					}
					if (fabs(r_ref - R[i]) > 0.01f) {
						result = false;
					}
					out << " " << R[i] << " ;\n";
				}
				out << "];\n";
			}

			if (!result) {
				out << "FAIL: R is incorrect\n";
			}

			context.free(R);
			context.free(V);
			context.free(A);
			delete [] R;
			delete [] V;
			delete [] A;
		}
		if (result) {
			status << "looping kernel succeeded\n";
		}
		if (local_verbose || !result) {
			status << out.str();
		}
		return result;
	}

	/*!
		Test driver
	*/
	bool doTest( ) {
		return loadKernels() && testDivergent() && testLooping() 
			&& testMatrixVectorProduct();
	}

};
}

/*!
	Entry point
*/
int main(int argc, char **argv) {
	using namespace std;
	using namespace ir;
	using namespace test;

	hydrazine::ArgumentParser parser( argc, argv );
	test::TestKernels test;

	parser.description( test.testDescription() );

	parser.parse( "-s", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", test.verbose, false, "Print out info after the test." );
	parser.parse();

	test.test();

	return test.passed();
}

