/*!
	\file TestEmulator.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief tests the emulation layer
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

static float fabs(float a) {
	if (a < 0) return -a;
	return a;
}

namespace test {

class TestEmulator: public Test {
public:
	TestEmulator() {
		name = "TestEmulator";

		status << "Test output:\n";
	}

	/*!
		Tests initialization of executive, load of kernel, and translation to 
			EmulatedKernel
	*/
	bool testKernelLoading() {
		using namespace std;
		using namespace ir;
		using namespace executive;

		bool result = true;

		Kernel *rawKernel = 0;
		Executive context;
		
		string module = "ocelot/executive/test/sequence.ptx";
		
		if (!context.selectDeviceByISA(Instruction::Emulated)) {
			status << "Failed to select Emulated device\n";
			return (result = false);
		}

		if (!context.loadModule(module)) {
			status << "failed to load module '" << module << "'\n";
			return (result = false);
		}

		rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z17k_simple_sequencePi");
		if (!rawKernel) {
			status << "failed to get kernel\n";
			return (result = false);
		}

		return result;
	}

	/*!
		Tests register getters and setters:

			Construct a Module, 
	*/
	bool testRegisterAccessors() {

		using namespace std;
		using namespace ir;
		using namespace executive;

		bool result = true;

		Kernel *rawKernel = 0;
		EmulatedKernel *kernel = 0;
		Executive context;
		string module = "ocelot/executive/test/sequence.ptx";
		
		if (!context.selectDeviceByISA(Instruction::Emulated)) {
			status << "Failed to select Emulated device\n";
			return (result = false);
		}

		if (!context.loadModule(module)) {
			status << "failed to load module '" << module << "'\n";
			return (result = false);
		}

		rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z17k_simple_sequencePi");
		if (!rawKernel) {
			status << "failed to get kernel\n";
			return (result = false);
		}

		kernel = static_cast<EmulatedKernel *>(rawKernel);
		
		trace::TraceGenerator generator;
		kernel->addTraceGenerator( &generator );

		// construct a CooperativeThreadArray from kernel
		const int Threads = 8;

		kernel->setKernelShape(Threads,1,1);
		status << kernel->RegisterCount << " registers\n";

		CooperativeThreadArray cta(kernel);
		cta.initialize();

		for (int j = 0; j < kernel->RegisterCount; j++) {
			for (int i = 0; i < Threads; i++) {
				cta.setRegAsU32(i, j, i*(j+1));
			}
		}
		for (int j = 0; result && j < kernel->RegisterCount; j++) {
			for (int i = 0; result && i < Threads; i++) {
				if (cta.getRegAsU32(i, j) != (ir::PTXU32)(i*(j+1))) {
					result = false;
					status << "set/getRegAsU32 test failed\n";
				}
			}
		}

		for (int i = 0; result && i < Threads; i ++) {
			// set as float, get as float
			if (result) {
				cta.setRegAsF32(i, 1, 12.5f);
				if (fabs(cta.getRegAsF32(i, 1) - 12.5f) > 0.01f) {
					result = false;
					status << "set/getRegAsF32 failed\n";
				}
			}

			// handling types of mixed sizes
			if (result) {
				PTXU64 value = 0xffffffffffffffffULL;
				PTXU64 outval = 0xffffffffffff0000ULL;
				PTXU64 encountered;
				cta.setRegAsU64(i, 3, value);
				cta.setRegAsU16(i, 3, 0);
				encountered = cta.getRegAsU64(i, 3);
				if (encountered != outval) {
					result = false;
					status << "setAsU64, setAsU16 failed: getAsU64 returned 0x" 
						<< std::hex;
					status << encountered << ", expected: 0x" << outval 
						<< std::dec << " for thread " << i << "\n";
					status << "read the register one more time: 0x" 
						<< std::hex << cta.getRegAsU64(i, 3) << dec << "\n";
				}
			}

			// set as float, get as uint
			if (result) {
				cta.setRegAsF32(i, 2, 1.0f);
				if (cta.getRegAsU32(i, 2) != 0x3F800000) {
					result = false;
					status << "setRegAsF32, getRegAsU32 failed: 0x" 
						<< std::hex <<  cta.getRegAsU32(i, 2) << std::dec 
						<<  "\n";
				}
			}
		}
		
		if (result) {
			status << "Register test passed\n";
		}
		
		return result;
	}

	/*!
		Tests load instructions
	*/
	bool testLd() {
		using namespace std;
		using namespace ir;
		using namespace executive;

		bool result = true;

		Kernel *rawKernel = 0;
		EmulatedKernel *kernel = 0;
		Executive context;
		string module = "ocelot/executive/test/sequence.ptx";
		
		if (!context.selectDeviceByISA(Instruction::Emulated)) {
			status << "Failed to select Emulated device\n";
			return (result = false);
		}

		if (!context.loadModule(module)) {
			status << "failed to load module '" << module << "'\n";
			return (result = false);
		}

		rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z17k_simple_sequencePi");
		if (!rawKernel) {
			status << "failed to get kernel\n";
			return (result = false);
		}

		int Threads = 1;

		kernel = static_cast<EmulatedKernel *>(rawKernel);
		kernel->setKernelShape(Threads, 1, 1);

		trace::TraceGenerator generator;
		kernel->addTraceGenerator( &generator );

		CooperativeThreadArray cta(kernel);

		// load and store to global memory
		PTXU32 block[64];
		context.registerExternal(block, sizeof(PTXU32)*64);

		PTXInstruction ld( PTXInstruction::ptx1_3 );
		ld.opcode = PTXInstruction::Ld;
		ld.addressSpace = PTXInstruction::Global;
		ld.d.reg = 0;
		ld.d.type = PTXOperand::u32;
		ld.d.addressMode = PTXOperand::Register;
		ld.a.type = PTXOperand::u32;
		ld.a.offset = 0;
		ld.a.reg = 1;
		ld.a.addressMode = PTXOperand::Indirect;
		ld.volatility = PTXInstruction::Nonvolatile;

		if (ld.valid() != "") {
			status << "ld.global instruction invalid: " << ld.valid() << "\n";
			return (result = false);
		}

		block[0] = 0xa5a500a3;
		cta.setRegAsU32(0, 0, 0);
		cta.setRegAsU64(0, 1, (PTXU64)block);

		try {
			cta.eval_Ld(cta.runtimeStack.back(), ld);
			if (cta.getRegAsU32(0, 0) != 0xa5a500a3) {
				// load failed
				result = false;
				status << "ld.global failed. Got: 0x" << hex 
					<< cta.getRegAsU32(0,0) << "\n";
			}
		}
		catch (RuntimeException &exp) {
			status << "load test 1 failed\n";
			status << "runtime exception on instruction " 
				<< exp.instruction.toString() << ":\n";
			status << "  " << exp.message << "\n";
			result = false;
		}

		block[1] = 0x3F800000;
		ld.a.offset = 4;

		try {
			cta.eval_Ld(cta.runtimeStack.back(), ld);
			if (fabs(cta.getRegAsF32(0, 0) - 1.0f) > 0.1f) {
				// load failed
				result = false;
				status << "ld.global failed. Got: " << cta.getRegAsF32(0,0) 
					<< "\n";
			}
		}
		catch (RuntimeException &exp) {
			status << "load test 2 failed\n";
			status << "runtime exception on instruction " 
				<< exp.instruction.toString() << ":\n";
			status << "  " << exp.message << "\n";
			result = false;
		}
		
		ld.type = PTXOperand::f32;
		ld.d.addressMode = PTXOperand::Register;
		ld.d.reg = 0;
		ld.d.type = PTXOperand::f32;
		ld.a.reg = 1;
		ld.a.type = PTXOperand::u64;
		ld.a.addressMode = PTXOperand::Indirect;
		ld.a.offset = 8;
		ld.addressSpace = PTXInstruction::Global;

		if (ld.valid() != "") {
			result = false;
			status << "ld.global instruction invalid: " << ld.valid() << "\n";
		}
		cta.setRegAsU64(0, 1, (PTXU64)block);
		cta.setRegAsF32(0, 0, -1.0f);
		block[2] = 0xC0490E56;	// -3.14159f

		try {
			cta.eval_Ld(cta.runtimeStack.back(), ld);
			if (fabs(cta.getRegAsF32(0, 0) + 3.14159f) > 0.1f) {
				result = false;
				status << "ld.global failed: got " 
					<< cta.getRegAsF32(0,0) << "\n";
			}
		}
		catch (RuntimeException &exp) {
			status << "load test 3 failed\n";
			status << "runtime exception on instruction " 
				<< exp.instruction.toString() << ":\n";
			status << "  " << exp.message << "\n";
			result = false;
		}

		if (result) {
			status << "Load test passed\n";
		}

		context.free(block);

		return result;
	}

	/*!
		Tests store instructions
	*/
	bool testSt() {
		using namespace std;
		using namespace ir;
		using namespace executive;

		bool result = true;

		Kernel *rawKernel = 0;
		EmulatedKernel *kernel = 0;
		Executive context;
		string module = "ocelot/executive/test/sequence.ptx";
		
		if (!context.selectDeviceByISA(Instruction::Emulated)) {
			status << "Failed to select Emulated device\n";
			return (result = false);
		}

		if (!context.loadModule(module)) {
			status << "failed to load module '" << module << "'\n";
			return (result = false);
		}

		rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z17k_simple_sequencePi");
		if (!rawKernel) {
			status << "failed to get kernel\n";
			return (result = false);
		}

		int Threads = 1;

		kernel = static_cast<EmulatedKernel *>(rawKernel);
		kernel->setKernelShape(Threads, 1, 1);

		trace::TraceGenerator generator;
		kernel->addTraceGenerator( &generator );

		CooperativeThreadArray cta(kernel);

		// load and store to global memory
		PTXU32 u_block[4];
		PTXF32 f_block[2];

		context.registerExternal(u_block, 4*sizeof(PTXU32));
		context.registerExternal(f_block, 2*sizeof(PTXF32));

		PTXInstruction st( PTXInstruction::ptx1_3 );
		st.opcode = PTXInstruction::St;
		st.addressSpace = PTXInstruction::Global;
		st.a.reg = 0;
		st.a.type = PTXOperand::u32;
		st.a.addressMode = PTXOperand::Register;
		st.a.identifier = "source";
		st.d.type = PTXOperand::u64;
		st.d.offset = 0;
		st.d.reg = 1;
		st.d.addressMode = PTXOperand::Indirect;
		st.d.identifier = "dest";

		if (st.valid() != "") {
			status << "st.global instruction invalid: " << st.valid() << "\n";
			return (result = false);
		}

		cta.setRegAsU64(0, 1, (PTXU64)u_block);
		cta.setRegAsU32(0, 0, 74);

		try {
			cta.eval_St(cta.runtimeStack.back(), st);
			if (u_block[0] != 74) {
				result = false;
				status << "st.global failed - got " << hex 
					<< u_block[0] << ", expected: " << cta.getRegAsU32(0, 0) 
					<< "\n";

			}
		}
		catch (RuntimeException &exp) {
			status << "store test 1 failed\n";
			status << "runtime exception on instruction " 
				<< exp.instruction.toString() << ":\n";
			status << "  " << exp.message << "\n";
			result = false;
		}

		cta.setRegAsU64(0, 1, (PTXU64)f_block);
		cta.setRegAsF32(0, 0, 24.3f);
		st.type = PTXOperand::f32;
		st.a.type = PTXOperand::f32;

		try {
			cta.eval_St(cta.runtimeStack.back(), st);
			if (fabs(f_block[0] - 24.3f) > 0.1f) {
				result = false;
				status << "st.global failed - got " << f_block[0] 
					<< ", expected: " << cta.getRegAsF32(0, 0) << "\n";

			}
		}
		catch (RuntimeException &exp) {
			status << "store test 2 failed\n";
			status << "runtime exception on instruction " 
				<< exp.instruction.toString() << ":\n";
			status << "  " << exp.message << "\n";
			result = false;
		}

		if (result) {
			status << "Store test passed\n";
		}
		
		context.free(u_block);
		context.free(f_block);
		
		return result;
	}

	/*!
		Loads a kernel, configures parameters, executes kernel, 
		and tests for accurate results
	*/
	bool testFullKernel() {
		using namespace std;
		using namespace ir;
		using namespace executive;

		bool result = true;

		Kernel *rawKernel = 0;
		EmulatedKernel *kernel = 0;
		Executive context;
		string module = "ocelot/executive/test/sequence.ptx";
		
		if (!context.selectDeviceByISA(Instruction::Emulated)) {
			status << "Failed to select Emulated device\n";
			return (result = false);
		}

		if (!context.loadModule(module)) {
			status << "failed to load module '" << module << "'\n";
			return (result = false);
		}

		rawKernel = context.getKernel(Instruction::Emulated, module, 
			"_Z17k_simple_sequencePi");
		if (!rawKernel) {
			status << "failed to get kernel\n";
			return (result = false);
		}
		
		// this cast is safe becuase a Kernel with ISA = Instruction::Emulated 
		// is guaranteed to be of type EmulatedKernel.
		kernel = static_cast<EmulatedKernel*>(rawKernel);

		trace::TraceGenerator generator;
		kernel->addTraceGenerator( &generator );

		{
			ofstream file("emulated_kernel.ptx");

			// print register map
			file << "Registers:\n";

			for (ir::Kernel::RegisterMap::iterator 
				r_it = kernel->registerMap.begin();
				r_it != kernel->registerMap.end(); ++r_it) {
				file << "  " << r_it->first << ": " << r_it->second << "\n";
			}

			file << "Instructions:\n";

			for (ir::Kernel::PTXInstructionVector::iterator 
				it = kernel->KernelInstructions.begin();
				it != kernel->KernelInstructions.end(); ++it) {
				file << PTXInstruction::toString((*it).opcode) << " ";
				if (it->opcode == PTXInstruction::Bra) {
					file << "[target: " << it->branchTargetInstruction 
					<< ", reconverge: " << it->reconvergeInstruction << "]";
				}
				else if (it->opcode == PTXInstruction::Ld && it->addressSpace 
					== PTXInstruction::Param) {
					file << "[ " 
					<< (kernel->registerMap.find(it->d.identifier))->second 
					<< " param: " << it->a.offset << " ]";
				}
				else if (it->opcode == PTXInstruction::St && it->addressSpace 
					== PTXInstruction::Param) {
					file << "[ param: " << it->d.offset << " " 
					<< (kernel->registerMap.find(it->a.identifier))->second 
					<< " ]";
				}
				else {
					PTXInstruction &instr = *it;
					PTXOperand PTXInstruction:: * operands[] = { 
						&PTXInstruction::d, &PTXInstruction::a, 
						&PTXInstruction::b, &PTXInstruction::c
					};

					file << "[";
					for (int i = 0; i < 4; i++) {
						if ((instr.*operands[i]).addressMode 
							== PTXOperand::Register 
							|| (instr.*operands[i]).addressMode 
							== PTXOperand::Indirect ) {
							ir::Kernel::RegisterMap::iterator 
								o_it = kernel->registerMap.find(
								(instr.*operands[i]).identifier);
							file << " " << o_it->second;
						}
					}
					file << " ]";
				}
				file << "\n";
			}
		}

		const int N = 32;
		int *inputSequence = new int[N];
		context.registerExternal(inputSequence, N*sizeof(int));

		// configure parameters
		Parameter &param_A = kernel->getParameter(
			"__cudaparm__Z17k_simple_sequencePi_A");

		// set parameter values
		param_A.arrayValues.resize(1);
		param_A.arrayValues[0].val_u64 = (PTXU64)inputSequence;

		kernel->updateParameterMemory();

		// launch the kernel
		try {
			kernel->setKernelShape(N,1,1);
			kernel->launchGrid(1,1);
			// context.synchronize();
		}
		catch (RuntimeException &exp) {
			status << "Full kernel test failed\n";
			status << "Runtime exception on instruction [ " 
				<< exp.instruction.toString() << " ]:\n" 
				<< exp.message << "\n";
		}

		int errors = 0;
		for (int i = 0; !errors && i < N; i++) {
			if (inputSequence[i] != 2*i + 1) {
				++ errors;
				status << "error on status[" << i << "]: " 
				<< inputSequence[i] << "\n";
			}
		}
		if (errors) {
			status << "there were errors\n";
			result = false;
		}
		else {
			status << "no errors\n";
			result = true;
		}

		context.free(inputSequence);
		delete[] inputSequence; 

		if (result) {
			status << "Full kernel test passed\n";
		}

		return result;
	}

	/*!
		Test driver
	*/
	bool doTest( ) {
		bool result = testKernelLoading() && testRegisterAccessors() 
			&& testLd();
		result = (result && testSt());
		result = (result && testFullKernel());
		return result;
	}

private:

};

}

int main(int argc, char **argv) {
	using namespace std;
	using namespace ir;
	using namespace test;

	hydrazine::ArgumentParser parser( argc, argv );
	test::TestEmulator test;

	parser.description( test.testDescription() );

	parser.parse( "-s", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", test.verbose, false, "Print out info after the test." );
	parser.parse();

	test.test();

	return test.passed();
}

