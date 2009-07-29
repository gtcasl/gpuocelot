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

namespace test
{
	
	bool TestLLVMInstructions::check( const ir::Instruction& i, 
		const std::string& reference )
	{
		if( !i.valid().empty() )
		{
			status << "Instruction " << i.toString() << " is not valid: " 
				<< i.valid() << "\n";
			return false;
		}
		
		if( reference != i.toString() )
		{
			status << "Instruction \"" << i.toString() 
				<< "\" does not match reference \"" << reference << "\"\n";
			return false;
		}
		return true;
	}

	bool TestLLVMInstructions::testAdd()
	{
		ir::LLVMAdd add;
		add.d.name = "<result>";
		add.d.type.category = Type::Element;
		add.d.type.type = Instruction::I32;

		add.a.constant = true;
		add.a.i32 = 4;
		add.a.type.category = Type::Element;
		add.a.type.type = Instruction::I32;
		
		add.b.name = "%var";
		add.b.type.category = Type::Element;
		add.b.type.type = Instruction::I32;

		std::string reference = "<result> = add i32 4, %var";
	
		if( !check( add, reference ) ) return false;

		status << "Add Instruction Passed\n";
		return true;
	}
	
	bool TestLLVMInstructions::testAlloca()
	{
		ir::LLVMAlloca alloca;
		alloca.d.name = "%ptr";
		alloca.d.type.category = Type::Pointer;
		alloca.d.type.type = Instruction::I32;
		
		std::string reference = "%ptr = alloca i32";
		
		if( !check( alloca, reference) ) return false;

		alloca.elements = 4;
		reference = "%ptr = alloca i32, i32 4";
		
		if( !check( alloca, reference ) ) return false;
		
		alloca.alignment = 1024;
		reference = "%ptr = alloca i32, i32 4, align 1024";
		
		if( !check( alloca, reference ) ) return false;
		
		alloca.elements = 1;
		reference = "%ptr = alloca i32, align 1024";
		
		if( !check( alloca, reference ) ) return false;
		
		status << "Alloca Instruction Passed\n";
		return true;
	}
	
	bool TestLLVMInstructions::testAnd()
	{
		ir::LLVMAnd And;
		And.d.name = "<result>";
		And.d.type.category = Type::Element;
		And.d.type.type = Instruction::I32;
		And.a.type.category = Type::Element;
		And.a.type.type = Instruction::I32;
		And.a.constant = true;
		And.a.i32 = 4;
		And.b.name = "%var";
		And.b.type.category = Type::Element;
		And.b.type.type = Instruction::I32;
		
		std::string reference = "<result> = and i32 4, %var";
		
		if( !check( And, reference ) ) return false;
		
		And.b.constant = true;
		And.a.i32 = 15;
		And.b.i32 = 40;
		
		reference = "<result> = and i32 15, 40";
		
		if( !check( And, reference ) ) return false;
		
		And.b.constant = true;
		And.a.i32 = 4;
		And.b.i32 = 8;
		
		reference = "<result> = and i32 4, 8";
		
		if( !check( And, reference ) ) return false;
		
		status << "And Instruction Passed\n";
		return true;
	}
	
	bool TestLLVMInstructions::testAshr()
	{
		ir::LLVMAshr ashr;
		ashr.d.name = "<result>";
		ashr.d.type.category = Type::Element;
		ashr.d.type.type = Instruction::I32;
		ashr.a.type.category = Type::Element;
		ashr.a.type.type = Instruction::I32;
		ashr.a.constant = true;
		ashr.a.i32 = 4;
		
		ashr.b.type.category = Type::Element;
		ashr.b.type.type = Instruction::I32;
		ashr.b.constant = true;
		ashr.b.i32 = 1;
		
		std::string reference = "<result> = ashr i32 4, 1";
	
		if( !check( ashr, reference ) ) return false;
	
		ashr.b.type.type = Instruction::I8;
		ashr.a.type.type = Instruction::I8;
		ashr.d.type.type = Instruction::I8;
		
		ashr.a.i8 = -2;
		ashr.b.i8 = 1;
		
		reference = "<result> = ashr i8 -2, 1";
	
		if( !check( ashr, reference ) ) return false;
		
		ashr.b.type.type = Instruction::I32;
		ashr.a.type.type = Instruction::I32;
		ashr.d.type.type = Instruction::I32;
		
		ashr.d.type.category = Type::Vector;
		ashr.d.type.vector = 2;
		
		ashr.a.type.category = Type::Vector;
		ashr.a.type.vector = 2;
		ashr.a.values.resize( 2 );
		ashr.a.values[0].i32 = -2;
		ashr.a.values[1].i32 = 4;
		
		ashr.b.type.category = Type::Vector;
		ashr.b.type.vector = 2;
		ashr.b.values.resize( 2 );
		ashr.b.values[0].i32 = 1;
		ashr.b.values[1].i32 = 3;
		
		reference 
			= "<result> = ashr < 2 x i32 > < i32 -2, i32 4 >, < i32 1, i32 3 >";
	
		if( !check( ashr, reference ) ) return false;
		
		status << "Ashr Instruction Passed\n";
		return true;
	}
	
	bool TestLLVMInstructions::testBitcast()	
	{
		ir::LLVMBitcast bitcast;
		bitcast.d.name = "%X";
		bitcast.d.type.category = Type::Element;
		bitcast.d.type.type = Instruction::I8;

		bitcast.a.type.category = Type::Element;
		bitcast.a.type.type = Instruction::I8;
		bitcast.a.constant = true;
		bitcast.a.i8 = -1;

		std::string reference = "%X = bitcast i8 -1 to i8";
		
		if( !check( bitcast, reference ) ) return false;
	
		bitcast.d.type.category = Type::Element;
		bitcast.d.type.type = Instruction::I64;
		bitcast.d.name = "%Z";
		
		bitcast.a.type.category = Type::Vector;
		bitcast.a.type.vector = 2;
		bitcast.a.type.type = Instruction::I32;
		bitcast.a.constant = false;
		bitcast.a.name = "%V";
	
		reference = "%Z = bitcast < 2 x i32 > %V to i64";

		if( !check( bitcast, reference ) ) return false;
	
		status << "Bitcast Instruction Passed\n";
		return true;
	}
	
	bool TestLLVMInstructions::testBr()
	{
		ir::LLVMBr br;
		br.condition.name = "%cond";
		br.condition.type.category = Type::Element;
		br.condition.type.type = Instruction::I1;
		br.iftrue = "%IfEqual";
		br.iffalse = "%IfUnequal";
	
		std::string reference = "br i1 %cond, label %IfEqual, label %IfUnequal";
		
		if( !check( br, reference ) ) return false;
	
		status << "Br Instruction Passed\n";
		return true;
	}
	
	bool TestLLVMInstructions::testCall()
	{
		ir::LLVMCall call;
		call.d.name = "%retval";
		call.d.type.category = Type::Element;
		call.d.type.type = Instruction::I32;
		call.name = "@test";
		call.parameters.resize( 1 );
		call.parameters[0].type.category = Type::Element;
		call.parameters[0].type.type = Instruction::I32;
		call.parameters[0].name = "%argc";
	
		std::string reference = "%retval = call i32 @test(i32 %argc)";

		if( !check( call, reference ) ) return false;
	
		status << "Call Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testExtractelement()
	{
		status << "Extractelement Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testExtractvalue()
	{
		status << "Extractvalue Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFadd()
	{
		status << "Fadd Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFcmp()
	{
		status << "Fcmp Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFdiv()
	{
		status << "Fdiv Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFmul()
	{
		status << "Fmul Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFpext()	
	{
		status << "Fpext Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFptosi()
	{
		status << "Fptosi Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFptoui()
	{
		status << "Fptoui Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFptrunc()
	{
		status << "Fptrunc Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFree()
	{
		status << "Free Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFrem()
	{
		status << "Frem Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testFsub()
	{
		status << "Fsub Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testGetelementptr()
	{
		status << "Getelementptr Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testIcmp()
	{
		status << "Icmp Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testInsertelement()
	{
		status << "Insertelement Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testInsertvalue()
	{
		status << "Insertvalue Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testInttoptr()
	{
		status << "Inttoptr Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testInvoke()
	{
		status << "Invoke Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testLoad()
	{
		status << "Load Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testLshr()
	{
		status << "Lshr Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testMalloc()
	{
		status << "Malloc Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testMul()
	{
		status << "Mul Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testOr()
	{
		status << "Or Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testPhi()
	{
		status << "Phi Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testPtrtoint()
	{
		status << "Prtoint Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testRet()
	{
		status << "Ret Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testSdiv()
	{
		status << "Sdiv Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testSelect()
	{
		status << "Select Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testSext()
	{
		status << "Sext Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testShl()
	{
		status << "Shl Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testShufflevector()
	{
		status << "ShuffleVector Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testSitofp()
	{
		status << "Sitofp Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testSrem()
	{
		status << "Srem Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testStore()
	{
		status << "Store Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testSub()
	{
		status << "Sub Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testSwitch()
	{
		status << "Switch Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testTrunc()
	{
		status << "Trunc Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testUdiv()
	{
		status << "Udiv Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testUitofp()
	{
		status << "Uitofp Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testUnreachable()
	{
		status << "Unreachable Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testUnwind()
	{
		status << "Unwind Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testUrem()
	{
		status << "Urem Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testVaArg()
	{
		status << "VarArg Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testXor()
	{
		status << "Xor Instruction Passed\n";
		return false;
	}
	
	bool TestLLVMInstructions::testZext()
	{
		status << "Zext Instruction Passed\n";
		return false;
	}
	
	
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

