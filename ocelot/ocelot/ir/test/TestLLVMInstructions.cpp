/*!
	\file TestLLVMInstructions.cpp
	\date Monday July 27, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the TestLLVMInstructions class.
*/

#ifndef TEST_LLVM_INSTRUCTIONS_CPP_INCLUDED
#define TEST_LLVM_INSTRUCTIONS_CPP_INCLUDED

#include <ocelot/ir/test/TestLLVMInstructions.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <ir/interface/LLVMInstruction.h>

namespace test
{

	bool TestLLVMInstructions::testAdd()
	{
		ir::LLVMAdd add;
		add.d.name = "<result>";
		add.d.type.category = Type::
		add.a.constant = true;
		add.
		
	}
	
	bool TestLLVMInstructions::testAlloca();
	bool TestLLVMInstructions::testAnd();
	bool TestLLVMInstructions::testAshr();
	bool TestLLVMInstructions::testBitcast()	
	bool TestLLVMInstructions::testBr();
	bool TestLLVMInstructions::testCall();
	bool TestLLVMInstructions::testExtractelement();
	bool TestLLVMInstructions::testExtractvalue();
	bool TestLLVMInstructions::testFadd();
	bool TestLLVMInstructions::testFcmp();
	bool TestLLVMInstructions::testFdiv();
	bool TestLLVMInstructions::testFmul();
	bool TestLLVMInstructions::testFpext()	
	bool TestLLVMInstructions::testFptosi()	
	bool TestLLVMInstructions::testFptoui();
	bool TestLLVMInstructions::testFptrunc();
	bool TestLLVMInstructions::testFree();
	bool TestLLVMInstructions::testFrem();
	bool TestLLVMInstructions::testFsub();
	bool TestLLVMInstructions::testGetelementptr();
	bool TestLLVMInstructions::testIcmp();
	bool TestLLVMInstructions::testInsertelement();
	bool TestLLVMInstructions::testInsertvalue();
	bool TestLLVMInstructions::testInttoptr();
	bool TestLLVMInstructions::testInvoke();
	bool TestLLVMInstructions::testLoad();
	bool TestLLVMInstructions::testLshr();
	bool TestLLVMInstructions::testMalloc();
	bool TestLLVMInstructions::testMul();
	bool TestLLVMInstructions::testOr();
	bool TestLLVMInstructions::testPhi();
	bool TestLLVMInstructions::testPtrtoint();
	bool TestLLVMInstructions::testRet();
	bool TestLLVMInstructions::testSdiv();
	bool TestLLVMInstructions::testSelect();
	bool TestLLVMInstructions::testSext();
	bool TestLLVMInstructions::testShl();
	bool TestLLVMInstructions::testShufflevector();
	bool TestLLVMInstructions::testSitofp();
	bool TestLLVMInstructions::testSrem();
	bool TestLLVMInstructions::testStore();
	bool TestLLVMInstructions::testSub();
	bool TestLLVMInstructions::testSwitch();
	bool TestLLVMInstructions::testTrunc();
	bool TestLLVMInstructions::testUdiv();
	bool TestLLVMInstructions::testUitofp()	
	bool TestLLVMInstructions::testUnreachable();
	bool TestLLVMInstructions::testUnwind();
	bool TestLLVMInstructions::testUrem();
	bool TestLLVMInstructions::testVaArg();
	bool TestLLVMInstructions::testXor();
	bool TestLLVMInstructions::testZext();
	
	bool TestLLVMInstructions::doTest()
	{
		return testAdd() && testAlloca() && testAnd() && testAshr() 
			&& testBitcast() && testBr() && testCall() && testExtractelement() 
			&& testExtractvalue() && testFadd() && testFcmp() && testFdiv() 
			&& testFmul() && testFpext() && testFptosi() && testFptoui() 
			&& testFptrunc() && testFree() && testFrem() && testFsub() 
			&& testGetelementptr() && testIcmp() && testInsertelement() 
			&& testInsertvalue() && testInttoptr() && testInvoke() 
			&& testLoad() && testLshr() && testMalloc() && testMul() 
			&& testOr() && testPhi() && testPtrtoint() && testRet() 
			&& testSdiv() && testSelect() && testSext() && testShl() 
			&& testShufflevector() && testSitofp() && testSrem() 
			&& testStore() && testSub() && testSwitch() && testTrunc() 
			&& testUdiv() && testUitofp() && testUnreachable() && testUnwind() 
			&& testUrem() && testVaArg() && testXor() && testZext();
	}

	TestLLVMInstructions::TestLLVMInstructions()
	{
		name = "TestLLVMInstructions";
		
		description = "A test for the assembly code generation and automatic \
			verfication of individual LLVM instructions.\
		\
		Test Points:\
			1) For each instruction, generate several assembly strings using\
				the instruction's toString method, make sure that these pass\
				the valid() check, compare to references from the LLVM manual.";
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestLLVMInstructions test;
	parser.description( test.testDescription() );
	
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out info after the test is over." );
	parser.parse( "-s", "--seed", test.seed, 0, 
		"The random seed for repeatability.  0 imples seed with time." );
	parser.parse();
	
	test.test();
	
	return test.passed();
}

#endif

