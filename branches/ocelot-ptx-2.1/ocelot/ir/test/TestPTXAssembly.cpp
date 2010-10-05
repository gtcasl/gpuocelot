/*! \file TestPTXAssembly.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday May 11, 2010
	\brief The source file for the TestPTXAssembly class.
*/

#ifndef TEST_PTX_ASSEMBLY_CPP_INCLUDED
#define TEST_PTX_ASSEMBLY_CPP_INCLUDED

#include <ocelot/ir/test/TestPTXAssembly.h>
#include <ocelot/ir/interface/PTXInstruction.h>

#include <ocelot/api/interface/ocelot.h>

#include <hydrazine/interface/Casts.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/math.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <limits>

#include <climits>
#include <cmath>

template<typename T>
T getParameter(void* in, unsigned int offset)
{
	return *(T*)((char*)in + offset);
}

template<typename T>
void setParameter(void* output, unsigned int offset, T value)
{
	*(T*)((char*)output + offset) = value;
}

template <typename type, unsigned int size>
char* uniformRandom(test::Test::MersenneTwister& generator)
{
	type* allocation = new type[size];
	char* result = (char*) allocation;

	for(unsigned int i = 0; i < size * sizeof(type); ++i)
	{
		result[i] = generator();
	}
	
	return result;
}

template <typename type, unsigned int size>
char* uniformNonZero(test::Test::MersenneTwister& generator)
{
	type* allocation = new type[size];
	char* result = (char*) allocation;

	for(unsigned int i = 0; i < size * sizeof(type); ++i)
	{
		char value = generator();
		result[i] = ( value == 0 ) ? 1 : value;
	}
	
	return result;
}

template <typename type, unsigned int size>
char* uniformFloat(test::Test::MersenneTwister& generator)
{
	type* allocation = new type[size];
	char* result = (char*) allocation;

	for(unsigned int i = 0; i < size * sizeof(type); ++i)
	{
		unsigned int fptype = generator();
		
		if(fptype & 0x1)
		{
			if(fptype & 0x10)
			{
				result[i] = std::numeric_limits<type>::signaling_NaN();
			}
			else
			{
				result[i] = std::numeric_limits<type>::denorm_min();
			}
		}
		else
		{
			if(fptype & 0x10)
			{
				result[i] = std::numeric_limits<type>::infinity();		
			}
			else
			{
				result[i] = hydrazine::bit_cast<type>(generator());
			}
		}
	}
	
	return result;
}


////////////////////////////////////////////////////////////////////////////////
// TEST TESTP
std::string testTestp_PTX(ir::PTXOperand::DataType type, 
	ir::PTXInstruction::FloatingPointMode mode)
{
	std::stringstream ptx;
	
	std::string typeString;
	
	if(type == ir::PTXOperand::f32)
	{
		typeString = ".f32";
	}
	else
	{
		typeString = ".f64";
	}
	
	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << typeString << " %f0;               \n";
	ptx << "\t.reg .u32 %r0;                               \n";
	ptx << "\t.reg .pred %p0;                              \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	ptx << "\ttestp." << ir::PTXInstruction::toString(mode) 
		<< typeString << " %p0, %f0;\n";
	ptx << "\tselp.u32 %r0, 0xffffffff, 0x0, %p0;          \n";
	ptx << "\tst.global.u32 [%rOut], %r0;                  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, ir::PTXInstruction::FloatingPointMode mode>
void testTestP_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);

	bool condition = false;

	switch(mode)
	{
	default:
	case ir::PTXInstruction::Finite:
	{
		condition = !std::isinf(r0);
	}
	break;
	case ir::PTXInstruction::Infinite:
	{
		condition = std::isinf(r0);
	}
	break;
	case ir::PTXInstruction::Number:
	{
		condition = !std::isnan(r0);
	}
	break;
	case ir::PTXInstruction::NotANumber:
	{
		condition = std::isnan(r0);
	}
	break;
	case ir::PTXInstruction::Normal:
	{
		condition = std::isnormal(r0);
	}
	break;
	case ir::PTXInstruction::SubNormal:
	{
		condition = !std::isnormal(r0) && !std::isnan(r0) && !std::isinf(r0);
	}
	break;
	}

	unsigned int result = condition ? 0xffffffff : 0x0;

	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testTestp_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

test::TestPTXAssembly::TypeVector testTestp_OUT()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST INDIRECT FUNCTION CALLS
std::string testIndirectFunctionCall_PTX()
{
	std::stringstream ptx;
	
	ptx << ".version 2.1\n";
	ptx << ".visible .func (.param .u32 return) add0(.param .u32 a)\n";
	ptx << ".visible .func (.param .u32 return) add1(.param .u32 a)\n";
	ptx << ".visible .func (.param .u32 return) add2(.param .u32 a)\n";
	ptx << ".visible .func (.param .u32 return) add3(.param .u32 a)\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg .u32 %r<3>;                             \n";
	ptx << "\t.reg .u64 %functionPointer;                  \n";
	ptx << "\t.reg .pred %p0;                              \n";
	ptx << "\t.reg .u32 %thread;                           \n";
	ptx << "\t.reg .u64 %offset;                           \n";
	ptx << "\t.param .u32 operandA;                        \n";
	ptx << "\t.param .u32 result;                          \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global.u32 %r0, [%rIn];                   \n";
	ptx << "\tst.param.u32 [operandA], %r0;                \n";
	ptx << "\tmov.u32 %thread, %tid.x;                     \n";
	ptx << "\tmov.u64 %functionPointer, add0;              \n";
	ptx << "\tsetp.eq.u32 %p0, %thread, 1;                 \n";
	ptx << "\t@%p0 mov.u64 %functionPointer, add1;         \n";
	ptx << "\tsetp.eq.u32 %p0, %thread, 2;                 \n";
	ptx << "\t@%p0 mov.u64 %functionPointer, add2;         \n";
	ptx << "\tsetp.eq.u32 %p0, %thread, 3;                 \n";
	ptx << "\t@%p0 mov.u64 %functionPointer, add3;         \n";
	ptx << "\tprototype: .callprototype (.param .u32 _)    \n";
	ptx << "\t    _ (.param .u32 _);                       \n";
	ptx << "\tcall (result), %functionPointer,             \n";
	ptx << "\t    (operandA), prototype;                   \n";
	ptx << "\tld.param.u32 %r2, [result];                  \n";
	ptx << "\tcvt.u64.u32 %offset, %thread;                \n";
	ptx << "\tmul.lo.u64 %offset, %offset, 4;              \n";
	ptx << "\tadd.u64 %rOut, %offset, %rOut;               \n";
	ptx << "\tst.global.u32 [%rOut], %r2;                  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";

	ptx << ".visible .func (.param .u32 return) add0(.param .u32 a) \n";
	ptx << "{\t                                 \n";
	ptx << "\t.reg .u32 %r<3>;                  \n";
	ptx << "\tld.param.u32 %r0, [a];            \n";
	ptx << "\tadd.u32 %r0, %r0, 0;              \n";
	ptx << "\tst.param.u32 [return], %r0;       \n";
	ptx << "\tret 0;                            \n";
	ptx << "}                                   \n";

	ptx << ".visible .func (.param .u32 return) add1(.param .u32 a) \n";
	ptx << "{\t                                 \n";
	ptx << "\t.reg .u32 %r<3>;                  \n";
	ptx << "\tld.param.u32 %r0, [a];            \n";
	ptx << "\tadd.u32 %r0, %r0, 1;              \n";
	ptx << "\tst.param.u32 [return], %r0;       \n";
	ptx << "\tret 0;                            \n";
	ptx << "}                                   \n";

	ptx << ".visible .func (.param .u32 return) add2(.param .u32 a) \n";
	ptx << "{\t                                 \n";
	ptx << "\t.reg .u32 %r<3>;                  \n";
	ptx << "\tld.param.u32 %r0, [a];            \n";
	ptx << "\tadd.u32 %r0, %r0, 2;              \n";
	ptx << "\tst.param.u32 [return], %r0;       \n";
	ptx << "\tret 0;                            \n";
	ptx << "}                                   \n";

	ptx << ".visible .func (.param .u32 return) add3(.param .u32 a) \n";
	ptx << "{\t                                 \n";
	ptx << "\t.reg .u32 %r<3>;                  \n";
	ptx << "\tld.param.u32 %r0, [a];            \n";
	ptx << "\tadd.u32 %r0, %r0, 3;              \n";
	ptx << "\tst.param.u32 [return], %r0;       \n";
	ptx << "\tret 0;                            \n";
	ptx << "}                                   \n";
	
	return ptx.str();
}

void testIndirectFunctionCall_REF(void* output, void* input)
{
	unsigned int r0 = getParameter<unsigned int>(input, 0);

	setParameter(output, 0, (unsigned int)r0);
	setParameter(output, sizeof(unsigned int), (unsigned int)(r0 + 1));
	setParameter(output, 2 * sizeof(unsigned int), (unsigned int)(r0 + 2));
	setParameter(output, 3 * sizeof(unsigned int), (unsigned int)(r0 + 3));
}

test::TestPTXAssembly::TypeVector testIndirectFunctionCall_IN()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}

test::TestPTXAssembly::TypeVector testIndirectFunctionCall_OUT()
{
	return test::TestPTXAssembly::TypeVector(4, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST RECURSIVE FUNCTION CALLS
std::string testRecursiveFunctionCall_PTX()
{
	std::stringstream ptx;
	
	ptx << ".version 2.1\n";
	ptx << ".visible .func (.param .u32 return) count(.param .u32 a)\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in) \n";
	ptx << "{\t                                 \n";
	ptx << "\t.reg .u64 %rIn, %rOut;            \n";
	ptx << "\t.reg .u32 %r<3>;                  \n";
	ptx << "\t.param .u32 operandA;             \n";
	ptx << "\t.param .u32 result;               \n";
	ptx << "\tld.param.u64 %rIn, [in];          \n";
	ptx << "\tld.param.u64 %rOut, [out];        \n";
	ptx << "\tld.global.u32 %r0, [%rIn];        \n";
	ptx << "\trem.u32 %r0, %r0, 10;             \n";
	ptx << "\tst.param.u32 [operandA], %r0;     \n";
	ptx << "\tcall (result), count, (operandA); \n";
	ptx << "\tld.param.u32 %r2, [result];       \n";
	ptx << "\tst.global.u32 [%rOut], %r2;       \n";
	ptx << "\texit;                             \n";
	ptx << "}                                   \n";
	ptx << "                                    \n";

	ptx << ".visible .func (.param .u32 return) count(.param .u32 a) \n";
	ptx << "{\t                                 \n";
	ptx << "\t.reg .u32 %r<3>;                  \n";
	ptx << "\t.reg .pred %p0;                   \n";
	ptx << "\tld.param.u32 %r0, [a];            \n";
	ptx << "\tsetp.ne.u32 %p0, %r0, 0;          \n";
	ptx << "\tst.param.u32 [return], %r0;       \n";
	ptx << "\tsub.u32 %r0, %r0, 1;              \n";
	ptx << "\tst.param.u32 [a], %r0;            \n";
	ptx << "\t@%p0 call (return), count, (a);   \n";
	ptx << "\tret 0;                            \n";
	ptx << "}                                   \n";
	
	return ptx.str();
}

void testRecursiveFunctionCall_REF(void* output, void* input)
{
	setParameter(output, 0, (unsigned int)0);
}

test::TestPTXAssembly::TypeVector testRecursiveFunctionCall_IN()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}

test::TestPTXAssembly::TypeVector testRecursiveFunctionCall_OUT()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST DIVERGENT FUNCTION CALLS
std::string testDivergentFunctionCall_PTX()
{
	std::stringstream ptx;
	
	ptx << ".version 2.1\n";
	ptx << ".visible .func (.param .u32 return) " 
		<< "add(.param .u32 a, .param .u32 b)\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in) \n";
	ptx << "{\t\n";
	ptx << "\t.reg .u64 %rIn, %rOut; \n";
	ptx << "\t.reg .u32 %r<3>;               \n";
	ptx << "\t.reg .pred %less;              \n";
	ptx << "\t.reg .u32 %thread;             \n";
	ptx << "\t.reg .u64 %offset;             \n";
	ptx << "\t.param .u32 operandA;          \n";
	ptx << "\t.param .u32 operandB;          \n";
	ptx << "\t.param .u32 result;            \n";
	ptx << "\tmov.u32 %thread, %tid.x;       \n";
	ptx << "\tld.param.u64 %rIn, [in];       \n";
	ptx << "\tld.param.u64 %rOut, [out];     \n";
	ptx << "\tld.global.u32 %r0, [%rIn];     \n";
	ptx << "\tld.global.u32 %r1, [%rIn + 4]; \n";
	ptx << "\tst.param.u32 [operandA], %r0; \n";
	ptx << "\tst.param.u32 [operandB], %r1; \n";
	ptx << "\tst.param.u32 [result], %r1; \n";
	ptx << "\tsetp.lt.u32 %less, %thread, 1; \n";
	ptx << "\t@%less call (result), add, (operandA, operandB); \n";
	ptx << "\tld.param.u32 %r2, [result]; \n";
	ptx << "\tcvt.u64.u32 %offset, %thread; \n";
	ptx << "\tmul.lo.u64 %offset, %offset, 4; \n";
	ptx << "\tadd.u64 %rOut, %rOut, %offset; \n";
	ptx << "\tst.global.u32 [%rOut], %r2; \n";
	ptx << "\texit; \n";
	ptx << "}\n";
	ptx << "\n";

	ptx << ".visible .func (.param .u32 return) " 
		<< "add(.param .u32 a, .param .u32 b) \n";
	ptx << "{\t\n";
	ptx << "\t.reg .u32 %r<3>; \n";
	ptx << "\tld.param.u32 %r0, [a];\n";
	ptx << "\tld.param.u32 %r1, [b];\n";
	ptx << "\tadd.u32 %r2, %r1, %r0;\n";
	ptx << "\tst.param.u32 [return], %r2;\n";
	ptx << "\tret 0;\n";
	ptx << "}\n";
	
	return ptx.str();
}

void testDivergentFunctionCall_REF(void* output, void* input)
{
	unsigned int r0 = getParameter<unsigned int>(input, 0);
	unsigned int r1 = getParameter<unsigned int>(input, sizeof(unsigned int));
	
	unsigned int result = r0 + r1;
	
	setParameter(output, 0, result);
	setParameter(output, sizeof(unsigned int), r1);
}

test::TestPTXAssembly::TypeVector testDivergentFunctionCall_IN()
{
	return test::TestPTXAssembly::TypeVector(2, test::TestPTXAssembly::I32);
}

test::TestPTXAssembly::TypeVector testDivergentFunctionCall_OUT()
{
	return test::TestPTXAssembly::TypeVector(2, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST FUNCTION CALLS
std::string testFunctionCalls_PTX(bool uni)
{
	std::stringstream ptx;
	
	ptx << ".version 2.1\n";
	ptx << ".visible .func (.param .u32 return) " 
		<< "add(.param .u32 a, .param .u32 b)\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in) \n";
	ptx << "{\t\n";
	ptx << "\t.reg .u64 %rIn, %rOut; \n";
	ptx << "\t.reg .u32 %r<3>; \n";
	ptx << "\t.param .u32 operandA;\n";
	ptx << "\t.param .u32 operandB;\n";
	ptx << "\t.param .u32 result;\n";
	ptx << "\tld.param.u64 %rIn, [in]; \n";
	ptx << "\tld.param.u64 %rOut, [out]; \n";
	ptx << "\tld.global.u32 %r0, [%rIn]; \n";
	ptx << "\tld.global.u32 %r1, [%rIn + 4]; \n";
	ptx << "\tst.param.u32 [operandA], %r0; \n";
	ptx << "\tst.param.u32 [operandB], %r1; \n";
	ptx << "\tcall";
	if(uni) ptx << ".uni";
	ptx << " (result), add, (operandA, operandB); \n";
	ptx << "\tld.param.u32 %r2, [result]; \n";
	ptx << "\tst.global.u32 [%rOut], %r2; \n";
	ptx << "\texit; \n";
	ptx << "}\n";
	ptx << "\n";

	ptx << ".visible .func (.param .u32 return) " 
		<< "add(.param .u32 a, .param .u32 b) \n";
	ptx << "{\t\n";
	ptx << "\t.reg .u32 %r<3>; \n";
	ptx << "\tld.param.u32 %r0, [a];\n";
	ptx << "\tld.param.u32 %r1, [b];\n";
	ptx << "\tadd.u32 %r2, %r1, %r0;\n";
	ptx << "\tst.param.u32 [return], %r2;\n";
	ptx << "\tret 0;\n";
	ptx << "}\n";
	
	return ptx.str();
}

void testFunctionCalls_REF(void* output, void* input)
{
	unsigned int r0 = getParameter<unsigned int>(input, 0);
	unsigned int r1 = getParameter<unsigned int>(input, sizeof(unsigned int));
	
	unsigned int result = r0 + r1;
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testFunctionCalls_IN()
{
	return test::TestPTXAssembly::TypeVector(2, test::TestPTXAssembly::I32);
}

test::TestPTXAssembly::TypeVector testFunctionCalls_OUT()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST VECTOR ELEMENTS
std::string testVectorElements_PTX()
{
	std::stringstream result;

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg .v4 .u32 %rv<2>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global.v4.u32 %rv0, [%rIn]; \n";
	result << "\tmov.u32 %rv1.x, %rv0.y; \n";
	result << "\tmov.u32 %rv1.y, %rv0.z; \n";
	result << "\tmov.u32 %rv1.z, %rv0.w; \n";
	result << "\tmov.u32 %rv1.w, %rv0.x; \n";
	result << "\tst.global.v4.u32 [%rOut], %rv1; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

void testVectorElements_REF(void* output, void* input)
{
	unsigned int r0 = getParameter<unsigned int>(input, 0);
	unsigned int r1 = getParameter<unsigned int>(input, sizeof(unsigned int));
	unsigned int r2 = getParameter<unsigned int>(input, 2*sizeof(unsigned int));
	unsigned int r3 = getParameter<unsigned int>(input, 3*sizeof(unsigned int));
		
	setParameter(output, 0, r1);
	setParameter(output, sizeof(unsigned int), r2);
	setParameter(output, 2*sizeof(unsigned int), r3);
	setParameter(output, 3*sizeof(unsigned int), r0);
}

test::TestPTXAssembly::TypeVector testVectorElements_IN()
{
	return test::TestPTXAssembly::TypeVector(4, test::TestPTXAssembly::I32);
}

test::TestPTXAssembly::TypeVector testVectorElements_OUT()
{
	return test::TestPTXAssembly::TypeVector(4, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST ADD/SUB
std::string testAdd_PTX(ir::PTXOperand::DataType type, bool sat, bool sub)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<3>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	if(sub)
	{
		result << "\tsub";
	}
	else
	{
		result << "\tadd";
	}
	if(sat) result << ".sat";
	result << typeString << " %r2, %r0, %r1; \n";
	result << "\tst.global" << typeString << " [%rOut], %r2; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type, bool sat, bool sub>
void testAdd_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	
	type result = 0;
	
	if(sat)
	{
		long long int t0 = r0;
		long long int t1 = r1;
		
		long long int tresult = 0;
		if(sub)
		{
			tresult = t0 - t1;
		}
		else
		{
			tresult = t0 + t1;
		}
		tresult = std::max(tresult, (long long int)INT_MIN);
		tresult = std::min(tresult, (long long int)INT_MAX);
		
		result = (type)tresult;
	}
	else
	{
		if(sub)
		{
			result = r0 - r1;
		}
		else
		{
			result = r0 + r1;
		}
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testAdd_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testAdd_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST Carry
std::string testCarry_PTX(ir::PTXOperand::DataType type, bool sub)
{
	std::stringstream stream;
	std::string typeString = "." + ir::PTXOperand::toString(type);
	
	stream << ".version 2.1\n";
	stream << ".entry test(.param .u64 out, .param .u64 in)\n";
	stream << "{\n";
	stream << "\t.reg .u64 %rIn, %rOut;\n";
	stream << "\t.reg " << typeString << " %r<5>;\n";
	stream << "\tld.param.u64 %rIn, [in];\n";
	stream << "\tld.param.u64 %rOut, [out];\n";
	stream << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	stream << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	
	if(sub)
	{
		stream << "\tsub.cc" << typeString << " %r2, %r1, %r0;\n";
		stream << "\tsubc.cc" << typeString << " %r3, %r2, %r0;\n";
		stream << "\tsubc" << typeString << " %r4, %r3, %r0;\n";
	}
	else
	{
		stream << "\tadd.cc" << typeString << " %r2, %r1, %r0;\n";
		stream << "\taddc.cc" << typeString << " %r3, %r2, %r0;\n";
		stream << "\taddc" << typeString << " %r4, %r3, %r0;\n";
	}
	
	stream << "\tst.global" << typeString << " [%rOut], %r4;\n";
	stream << "\texit;\n";
	stream << "}\n";
	
	return stream.str();
}

template <typename type, bool sub>
void testCarry_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	
	type result = 0;
	
	long long int t0 = r0;
	long long int t1 = r1;
	
	long long int tresult = 0;
	long long int carry = 0;

	if(sub)
	{
		tresult = t1 - t0;
		carry = (tresult & 0x100000000LLU) >> 32;
		tresult = (type)tresult - t0 + carry;
		carry = (tresult & 0x100000000LLU) >> 32;
		tresult = (type)tresult - t0 + carry;
	}
	else
	{
		tresult = t1 + t0;
		carry = (tresult & 0x100000000LLU) >> 32;
		tresult = (type)tresult + t0 + carry;
		carry = (tresult & 0x100000000LLU) >> 32;
		tresult = (type)tresult + t0 + carry;
	}

	result = (type)tresult;
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testCarry_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testCarry_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST MUL
enum MulType
{
	MulHi,
	MulLo,
	MulWide
};

std::string testMul_PTX(ir::PTXOperand::DataType type, MulType op)
{
	std::stringstream stream;
	std::string typeString = "." + ir::PTXOperand::toString(type);
	std::string dTypeString = "." + ir::PTXOperand::toString(type);

	if(op == MulWide)
	{
		switch(type)
		{
			case ir::PTXOperand::u16: dTypeString = ".u32"; break;
			case ir::PTXOperand::u32: dTypeString = ".u64"; break;
			case ir::PTXOperand::s16: dTypeString = ".s32"; break;
			case ir::PTXOperand::s32: dTypeString = ".s64"; break;
			default: assertM(false, "Invalid data type.");
		}
	}
	
	stream << ".version 2.1\n";
	stream << ".entry test(.param .u64 out, .param .u64 in)\n";
	stream << "{\n";
	stream << "\t.reg .u64 %rIn, %rOut;\n";
	stream << "\t.reg " << typeString << " %r<2>;\n";
	stream << "\t.reg " << dTypeString << " %r2;\n";
	stream << "\tld.param.u64 %rIn, [in];\n";
	stream << "\tld.param.u64 %rOut, [out];\n";
	stream << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	stream << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	
	if( op == MulHi )
	{
		stream << "\tmul.hi" << typeString << " %r2, %r1, %r0;\n";
	}
	else if( op == MulLo )
	{
		stream << "\tmul.lo" << typeString << " %r2, %r1, %r0;\n";
	}
	else
	{
		stream << "\tmul.wide" << typeString << " %r2, %r1, %r0;\n";
	}

	
	stream << "\tst.global" << dTypeString << " [%rOut], %r2;\n";
	stream << "\texit;\n";
	stream << "}\n";
	
	return stream.str();
}

template <typename type, MulType op>
void testMul_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	type hi;
	type lo;
	
	hydrazine::multiplyHiLo(hi, lo, r0, r1);
	
	if(op == MulWide)
	{
		setParameter(output, 0, lo);
		setParameter(output, sizeof(type), hi);
	}
	else if(op == MulLo)
	{
		setParameter(output, 0, lo);
	}
	else
	{
		setParameter(output, 0, hi);
	}
}

test::TestPTXAssembly::TypeVector testMul_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testMul_OUT(
	test::TestPTXAssembly::DataType type, MulType op)
{
	if(op != MulWide)
	{
		return test::TestPTXAssembly::TypeVector(1, type);
	}
	else
	{
		switch(type)
		{
			case test::TestPTXAssembly::I16:
			{
				return test::TestPTXAssembly::TypeVector(1, 
					test::TestPTXAssembly::I32);
			}
			case test::TestPTXAssembly::I32:
			{
				return test::TestPTXAssembly::TypeVector(1, 
					test::TestPTXAssembly::I64);
			}
			default: assertM(false, "Invalid data type for wide multiply.");
		}		
	}
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST MAD
std::string testMad_PTX(ir::PTXOperand::DataType type, MulType op, bool sat)
{
	std::stringstream stream;
	std::string typeString = "." + ir::PTXOperand::toString(type);
	std::string dTypeString = "." + ir::PTXOperand::toString(type);

	if(op == MulWide)
	{
		switch(type)
		{
			case ir::PTXOperand::u16: dTypeString = ".u32"; break;
			case ir::PTXOperand::u32: dTypeString = ".u64"; break;
			case ir::PTXOperand::s16: dTypeString = ".s32"; break;
			case ir::PTXOperand::s32: dTypeString = ".s64"; break;
			default: assertM(false, "Invalid data type.");
		}
	}
	
	stream << ".version 2.1\n";
	stream << ".entry test(.param .u64 out, .param .u64 in)\n";
	stream << "{\n";
	stream << "\t.reg .u64 %rIn, %rOut;\n";
	stream << "\t.reg " << typeString << " %r<2>;\n";
	stream << "\t.reg " << dTypeString << " %r2;\n";
	stream << "\t.reg " << dTypeString << " %r3;\n";
	stream << "\tld.param.u64 %rIn, [in];\n";
	stream << "\tld.param.u64 %rOut, [out];\n";
	stream << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	stream << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	stream << "\tld.global" << dTypeString << " %r2, [%rIn + " 
		<< 2 * ir::PTXOperand::bytes(type) << "]; \n";
	
	if( op == MulHi )
	{
		if( sat )
		{
			stream << "\tmad.hi.sat" << typeString << " %r3, %r0, %r1, %r2;\n";
		}
		else
		{
			stream << "\tmad.hi" << typeString << " %r3, %r0, %r1, %r2;\n";
		}
	}
	else if( op == MulLo )
	{
		stream << "\tmad.lo" << typeString << " %r3, %r0, %r1, %r2;\n";
	}
	else
	{
		stream << "\tmad.wide" << typeString << " %r3, %r0, %r1, %r2;\n";
	}

	
	stream << "\tst.global" << dTypeString << " [%rOut], %r3;\n";
	stream << "\texit;\n";
	stream << "}\n";
	
	return stream.str();
}

template <typename type, MulType op, bool sat>
void testMad_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	type hi;
	type lo;
	
	hydrazine::multiplyHiLo(hi, lo, r0, r1);
	
	if(op == MulWide)
	{
		type r2 = getParameter<type>(input, 2 * sizeof(type));
		type r3 = getParameter<type>(input, 3 * sizeof(type));
		hydrazine::addHiLo(hi, lo, r2);
		hi += r3;
		setParameter(output, 0, lo);
		setParameter(output, sizeof(type), hi);
	}
	else if(op == MulLo)
	{
		type r2 = getParameter<type>(input, 2 * sizeof(type));
		lo += r2;
		setParameter(output, 0, lo);
	}
	else
	{
		type r2 = getParameter<type>(input, 2 * sizeof(type));
		if(sat)
		{
			long long int t = (long long int)hi + (long long int)r2;
			t = std::max(t, (long long int)INT_MIN);
			t = std::min(t, (long long int)INT_MAX);
			hi = t;
		}
		else
		{
			hi += r2;
		}
		setParameter(output, 0, hi);
	}
}

test::TestPTXAssembly::TypeVector testMad_IN(
	test::TestPTXAssembly::DataType type, MulType op)
{
	test::TestPTXAssembly::TypeVector vector(2, type);

	if(op != MulWide)
	{
		vector.push_back( type );
	}
	else
	{
		switch(type)
		{
			case test::TestPTXAssembly::I16:
			{
				vector.push_back( test::TestPTXAssembly::I32 );
				break;
			}
			case test::TestPTXAssembly::I32:
			{
				vector.push_back( test::TestPTXAssembly::I64 );
				break;
			}
			default: assertM(false, "Invalid data type for wide multiply.");
		}	
	}
	
	return vector;
}

test::TestPTXAssembly::TypeVector testMad_OUT(
	test::TestPTXAssembly::DataType type, MulType op)
{
	if(op != MulWide)
	{
		return test::TestPTXAssembly::TypeVector(1, type);
	}
	else
	{
		switch(type)
		{
			case test::TestPTXAssembly::I16:
			{
				return test::TestPTXAssembly::TypeVector(1, 
					test::TestPTXAssembly::I32);
			}
			case test::TestPTXAssembly::I32:
			{
				return test::TestPTXAssembly::TypeVector(1, 
					test::TestPTXAssembly::I64);
			}
			default: assertM(false, "Invalid data type for wide multiply.");
		}		
	}
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST SAD
std::string testSad_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<4>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	result << "\tld.global" << typeString << " %r2, [%rIn + " 
		<< 2 * ir::PTXOperand::bytes(type) << "]; \n";
	result << "\tsad" << typeString << " %r3, %r0, %r1, %r2; \n";
	result << "\tst.global" << typeString << " [%rOut], %r3; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testSad_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	type r2 = getParameter<type>(input, 2 * sizeof(type));
	
	type result = r2 + ( ( r0 < r1 ) ? ( r1 - r0 ) : ( r0 - r1 ) );
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testSad_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(3, type);
}

test::TestPTXAssembly::TypeVector testSad_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST DIV
std::string testDiv_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<4>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	result << "\tdiv" << typeString << " %r2, %r0, %r1; \n";
	result << "\tst.global" << typeString << " [%rOut], %r2; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testDiv_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	
	type result = r0 / r1;
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testDiv_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testDiv_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST REM
std::string testRem_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<4>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	result << "\trem" << typeString << " %r2, %r0, %r1; \n";
	result << "\tst.global" << typeString << " [%rOut], %r2; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testRem_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	
	type result = r0 % r1;
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testRem_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testRem_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST ABS
std::string testAbs_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<2>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tabs" << typeString << " %r1, %r0; \n";
	result << "\tst.global" << typeString << " [%rOut], %r1; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testAbs_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	
	type result = std::abs( r0 );
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testAbs_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

test::TestPTXAssembly::TypeVector testAbs_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST NEG
std::string testNeg_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<2>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tneg" << typeString << " %r1, %r0; \n";
	result << "\tst.global" << typeString << " [%rOut], %r1; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testNeg_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	
	type result = -r0;
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testNeg_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

test::TestPTXAssembly::TypeVector testNeg_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST MIN-MAX
std::string testMinMax_PTX(ir::PTXOperand::DataType type, bool max)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<3>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	if(max)
	{
		result << "\tmax" << typeString << " %r2, %r0, %r1; \n";
	}
	else
	{
		result << "\tmin" << typeString << " %r2, %r0, %r1; \n";
	}
	result << "\tst.global" << typeString << " [%rOut], %r2; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type, bool max>
void testMinMax_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	
	type result = 0;
	
	if(max)
	{
		result = std::max(r0, r1);
	}
	else
	{
		result = std::min(r0, r1);
	}

	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testMinMax_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testMinMax_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST POPC
std::string testPopc_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r0; \n";
	result << "\t.reg .u32 %r1; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tpopc" << typeString << " %r1, %r0; \n";
	result << "\tst.global.u32 [%rOut], %r1; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testPopc_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	
	unsigned int result = hydrazine::popc( r0 );
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testPopc_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

test::TestPTXAssembly::TypeVector testPopc_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST CLZ
std::string testClz_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r0; \n";
	result << "\t.reg .u32 %r1; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tclz" << typeString << " %r1, %r0; \n";
	result << "\tst.global.u32 [%rOut], %r1; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testClz_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	
	unsigned int result = hydrazine::countLeadingZeros( r0 );
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testClz_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

test::TestPTXAssembly::TypeVector testClz_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST BFIND
std::string testBfind_PTX(ir::PTXOperand::DataType type, bool shift)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r0; \n";
	result << "\t.reg .u32 %r1; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	if(shift)
	{
		result << "\tbfind.shiftamt" << typeString << " %r1, %r0; \n";
	}
	else
	{
		result << "\tbfind" << typeString << " %r1, %r0; \n";
	}
	result << "\tst.global.u32 [%rOut], %r1; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type, bool shift>
void testBfind_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	
	unsigned int result = hydrazine::bfind(r0, shift);
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testBfind_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

test::TestPTXAssembly::TypeVector testBfind_OUT()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST BREV
std::string testBrev_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<2>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tbrev" << typeString << " %r1, %r0; \n";
	result << "\tst.global" << typeString << " [%rOut], %r1; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testBrev_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	
	type result = hydrazine::brev(r0);
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testBrev_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

test::TestPTXAssembly::TypeVector testBrev_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST BFI
std::string testBfi_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream result;
	std::string typeString = "." + ir::PTXOperand::toString(type);

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg " << typeString << " %r<3>; \n";
	result << "\t.reg .u32 %r3, %r4; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global" << typeString << " %r0, [%rIn]; \n";
	result << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "]; \n";
	result << "\tld.global.u32 %r3, [%rIn + " 
		<< (2 * ir::PTXOperand::bytes(type)) << "]; \n";
	result << "\tld.global.u32 %r4, [%rIn + " 
		<< (2 * ir::PTXOperand::bytes(type) 
		+ ir::PTXOperand::bytes(ir::PTXOperand::u32)) << "]; \n";
	result << "\tbfi" << typeString << " %r2, %r0, %r1, %r3, %r4; \n";
	result << "\tst.global" << typeString << " [%rOut], %r2; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <typename type>
void testBfi_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	unsigned int r2 = getParameter<unsigned int>(input, 2 * sizeof(type));
	unsigned int r3 = getParameter<unsigned int>(input, 2 * sizeof(type) 
		+ sizeof(unsigned int));
	
	type result = hydrazine::bitFieldInsert(r0, r1, r2, r3);
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testBfi_IN(
	test::TestPTXAssembly::DataType type)
{
	test::TestPTXAssembly::TypeVector input(4, type);
	
	input[2] = test::TestPTXAssembly::I32;
	input[3] = test::TestPTXAssembly::I32;
	
	return input;
}

test::TestPTXAssembly::TypeVector testBfi_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST PRMT
std::string testPrmt_PTX(ir::PTXInstruction::PermuteMode mode)
{
	std::string modeString;
	
	if( mode != ir::PTXInstruction::DefaultPermute )
	{
		modeString = "." + ir::PTXInstruction::toString( mode );
	}
	
	std::stringstream result;

	result << ".version 2.1 \n";
	result << ".entry test(.param .u64 out, .param .u64 in) \n";
	result << "{\t\n";
	result << "\t.reg .u64 %rIn, %rOut; \n";
	result << "\t.reg .u32 %r<4>; \n";
	result << "\tld.param.u64 %rIn, [in]; \n";
	result << "\tld.param.u64 %rOut, [out]; \n";
	result << "\tld.global.u32 %r0, [%rIn]; \n";
	result << "\tld.global.u32 %r1, [%rIn + 4]; \n";
	result << "\tld.global.u32 %r2, [%rIn + 8]; \n";
	result << "\tprmt.b32" << modeString << " %r3, %r0, %r1, %r2; \n";
	result << "\tst.global.u32 [%rOut], %r3; \n";
	result << "\texit; \n";
	result << "}\n";
	
	return result.str();
}

template <ir::PTXInstruction::PermuteMode mode>
void testPrmt_REF(void* output, void* input)
{
	unsigned int r0 = getParameter<unsigned int>(input, 0);
	unsigned int r1 = getParameter<unsigned int>(input, sizeof(unsigned int));
	unsigned int r2 = getParameter<unsigned int>(input, 
		2 * sizeof(unsigned int));
	
	unsigned int result = 0;
	
	switch( mode )
	{
		case ir::PTXInstruction::ForwardFourExtract:
		{
			result = hydrazine::permute<hydrazine::ForwardFourExtract>(
				r0,r1,r2);
			break;
		}
		case ir::PTXInstruction::BackwardFourExtract:
		{
			result = hydrazine::permute<hydrazine::BackwardFourExtract>(
				r0,r1,r2);
			break;
		}
		case ir::PTXInstruction::ReplicateEight:
		{
			result = hydrazine::permute<hydrazine::ReplicateEight>(r0,r1,r2);
			break;
		}
		case ir::PTXInstruction::EdgeClampLeft:
		{
			result = hydrazine::permute<hydrazine::EdgeClampLeft>(r0,r1,r2);
			break;
		}
		case ir::PTXInstruction::EdgeClampRight:
		{
			result = hydrazine::permute<hydrazine::EdgeClampRight>(r0,r1,r2);
			break;
		}
		case ir::PTXInstruction::ReplicateSixteen:
		{
			result = hydrazine::permute<hydrazine::ReplicateSixteen>(r0,r1,r2);
			break;
		}
		case ir::PTXInstruction::DefaultPermute:
		{
			result = hydrazine::permute<hydrazine::DefaultPermute>(
				r0,r1,r2);
			break;
		}
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testPrmt_IN()
{
	return test::TestPTXAssembly::TypeVector(3, test::TestPTXAssembly::I32);
}

test::TestPTXAssembly::TypeVector testPrmt_OUT()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////


namespace test
{
	unsigned int TestPTXAssembly::bytes(DataType t)
	{
		switch(t)
		{
			case I8: return 1;
			case I16: return 2;
			case I32: return 4;
			case I64: return 8;
			case FP32: return 4;
			case FP64: return 8;
		}
		return 1;
	}
	
	bool TestPTXAssembly::_doOneTest(const TestHandle& test, unsigned int seed)
	{
		random.seed(seed);
		
		unsigned int inputSize = 0;
		unsigned int outputSize = 0;
		
		for(TypeVector::const_iterator type = test.inputTypes.begin(); 
			type != test.inputTypes.end(); ++type)
		{
			inputSize += bytes(*type);
		}
		
		for(TypeVector::const_iterator type = test.outputTypes.begin(); 
			type != test.outputTypes.end(); ++type)
		{
			outputSize += bytes(*type);
		}
		
		char* inputBlock = (*test.generator)(random);
		char* outputBlock = new char[outputSize];
		char* referenceBlock = new char[outputSize];
		
		bool pass = true;
		int devices = 0;
		int device = 0;
		
		cudaGetDeviceCount(&devices);
		
		try
		{
			std::stringstream stream(test.ptx);
			ocelot::registerPTXModule(stream, test.name);
			
			char* deviceInput;
			char* deviceOutput;
						
			if(devices > 0) device = random() % devices;
			cudaSetDevice(device);
			
			cudaMalloc((void**)&deviceInput, inputSize);
			cudaMalloc((void**)&deviceOutput, outputSize);
			
			cudaMemcpy(deviceInput, inputBlock, 
				inputSize, cudaMemcpyHostToDevice);
				
			cudaSetupArgument(&deviceOutput, 8, 0);
			cudaSetupArgument(&deviceInput, 8, 8);
			cudaConfigureCall( dim3( test.ctas, 1, 1 ), 
				dim3( test.threads, 1, 1 ), 0, 0 );
			ocelot::launch(test.name, "test");
			
			cudaMemcpy(outputBlock, deviceOutput, 
				outputSize, cudaMemcpyDeviceToHost);
			
			cudaFree(deviceInput);
			cudaFree(deviceOutput);
			
			ocelot::unregisterModule(test.name);
		}
		catch(const std::exception& e)
		{
			status << " Test '" << test.name 
				<< "' failed during CUDA run with exception - \n" 
				<< e.what() << "\n";
				
			cudaDeviceProp properties;
			cudaGetDeviceProperties(&properties, device);
			
			status << "  On device - " << device << " - '" 
				<< properties.name << "'\n";
			
			pass = false;
		}
		
		if(pass)
		{
			try
			{
				(*test.reference)(referenceBlock, inputBlock);
			}
			catch(const hydrazine::Exception& e)
			{
				status << " Failed during reference run with exception - " 
					<< e.what() << "\n";

				cudaDeviceProp properties;
				cudaGetDeviceProperties(&properties, device);
			
				status << "  On device - " << device << " - '" 
					<< properties.name << "'\n";
				pass = false;
			}
		}
		
		unsigned int index = 0;
		for(TypeVector::const_iterator type = test.outputTypes.begin(); 
			type != test.outputTypes.end() && pass; ++type)
		{
			switch(*type)
			{
				case I8:
				{
					char computed = getParameter<char>(outputBlock, index);
					char reference = getParameter<char>(referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I8) computed value - " << (int)computed 
							<< " does not match reference value - " 
							<< (int)reference << "\n";
						cudaDeviceProp properties;
						cudaGetDeviceProperties(&properties, device);
			
						status << "  On device - " << device << " - '" 
							<< properties.name << "'\n";
					}
					break;
				}
				case I16:
				{
					short computed = getParameter<short>(outputBlock, index);
					short reference = getParameter<short>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I16) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
						cudaDeviceProp properties;
						cudaGetDeviceProperties(&properties, device);
			
						status << "  On device - " << device << " - '" 
							<< properties.name << "'\n";
					}
					break;
				}				
				case I32:
				{
					int computed = getParameter<int>(outputBlock, index);
					int reference = getParameter<int>(referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << "Test '" << test.name << "' (seed " 
							<< seed << "): failed, output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I32) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
						cudaDeviceProp properties;
						cudaGetDeviceProperties(&properties, device);
			
						status << "  On device - " << device << " - '" 
							<< properties.name << "'\n";
					}
					break;
				}
				case I64:
				{
					long long int computed = getParameter<long long int>(
						outputBlock, index);
					long long int reference = getParameter<long long int>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << "Test '" << test.name << "' (seed " 
							<< seed << "): failed, output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (I64) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
						cudaDeviceProp properties;
						cudaGetDeviceProperties(&properties, device);
			
						status << "  On device - " << device << " - '" 
							<< properties.name << "'\n";
					}
					break;
				}
				case FP32:
				{
					float computed = getParameter<float>(outputBlock, index);
					float reference = getParameter<float>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (F32) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
						cudaDeviceProp properties;
						cudaGetDeviceProperties(&properties, device);
			
						status << "  On device - " << device << " - '" 
							<< properties.name << "'\n";
					}
					break;
				}
				case FP64:
				{
					double computed = getParameter<double>(outputBlock, index);
					double reference = getParameter<double>(
						referenceBlock, index);
					if(computed != reference)
					{
						pass = false;
						status << " Output parameter " 
							<< std::distance(test.outputTypes.begin(), type) 
							<< " (F64) computed value - " << computed 
							<< " does not match reference value - " 
							<< reference << "\n";
						cudaDeviceProp properties;
						cudaGetDeviceProperties(&properties, device);
			
						status << "  On device - " << device << " - '" 
							<< properties.name << "'\n";
					}
					break;
				}

			}
			index += bytes(*type);
		}
		
		delete[] inputBlock;
		delete[] outputBlock;
		delete[] referenceBlock;
	
		return pass;
	}

	void TestPTXAssembly::_loadTests()
	{
		add("TestVectorElements-u32", testVectorElements_REF, 
			testVectorElements_PTX(), testVectorElements_OUT(), 
			testVectorElements_IN(), uniformRandom<unsigned int, 4>, 1, 1);
		
		add("TestAdd-u16", testAdd_REF<unsigned short, false, false>, 
			testAdd_PTX(ir::PTXOperand::u16, false, false), 
			testAdd_OUT(I16), testAdd_IN(I16), 
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestAdd-s16", testAdd_REF<signed short, false, false>, 
			testAdd_PTX(ir::PTXOperand::s16, false, false), 
			testAdd_OUT(I16), testAdd_IN(I16), 
			uniformRandom<signed short, 2>, 1, 1);
		add("TestAdd-u32", testAdd_REF<unsigned int, false, false>, 
			testAdd_PTX(ir::PTXOperand::u32, false, false), 
			testAdd_OUT(I32), testAdd_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestAdd-s32", testAdd_REF<signed int, false, false>, 
			testAdd_PTX(ir::PTXOperand::s32, false, false), 
			testAdd_OUT(I32), testAdd_IN(I32), 
			uniformRandom<signed int, 2>, 1, 1);
		add("TestAdd-s32-sat", testAdd_REF<signed int, true, false>, 
			testAdd_PTX(ir::PTXOperand::s32, true, false), 
			testAdd_OUT(I32), testAdd_IN(I32), 
			uniformRandom<signed int, 2>, 1, 1);
		add("TestAdd-u64", testAdd_REF<long long unsigned int, false, false>, 
			testAdd_PTX(ir::PTXOperand::u64, false, false), 
			testAdd_OUT(I64), testAdd_IN(I64), 
			uniformRandom<long long unsigned int, 2>, 1, 1);
		add("TestAdd-s64", testAdd_REF<long long signed int, false, false>, 
			testAdd_PTX(ir::PTXOperand::s64, false, false), 
			testAdd_OUT(I64), testAdd_IN(I64), 
			uniformRandom<long long signed int, 2>, 1, 1);

		add("TestSub-u16", testAdd_REF<unsigned short, false, true>, 
			testAdd_PTX(ir::PTXOperand::u16, false, true), 
			testAdd_OUT(I16), testAdd_IN(I16), 
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestSub-s16", testAdd_REF<signed short, false, true>, 
			testAdd_PTX(ir::PTXOperand::s16, false, true), 
			testAdd_OUT(I16), testAdd_IN(I16), 
			uniformRandom<signed short, 2>, 1, 1);
		add("TestSub-u32", testAdd_REF<unsigned int, false, true>, 
			testAdd_PTX(ir::PTXOperand::u32, false, true), 
			testAdd_OUT(I32), testAdd_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestSub-s32", testAdd_REF<signed int, false, true>, 
			testAdd_PTX(ir::PTXOperand::s32, false, true), 
			testAdd_OUT(I32), testAdd_IN(I32), 
			uniformRandom<signed int, 2>, 1, 1);
		add("TestSub-s32-sat", testAdd_REF<signed int, true, true>, 
			testAdd_PTX(ir::PTXOperand::s32, true, true), 
			testAdd_OUT(I32), testAdd_IN(I32), 
			uniformRandom<signed int, 2>, 1, 1);
		add("TestSub-u64", testAdd_REF<long long unsigned int, false, true>, 
			testAdd_PTX(ir::PTXOperand::u64, false, true), 
			testAdd_OUT(I64), testAdd_IN(I64), 
			uniformRandom<long long unsigned int, 2>, 1, 1);
		add("TestSub-s64", testAdd_REF<long long signed int, false, true>, 
			testAdd_PTX(ir::PTXOperand::s64, false, true), 
			testAdd_OUT(I64), testAdd_IN(I64), 
			uniformRandom<long long signed int, 2>, 1, 1);

		add("TestSub-Carry-s32", testCarry_REF<signed int, true>, 
			testCarry_PTX(ir::PTXOperand::s32, true), 
			testCarry_OUT(I32), testCarry_IN(I32), 
			uniformRandom<signed int, 2>, 1, 1);
		add("TestSub-Carry-u32", testCarry_REF<unsigned int, true>, 
			testCarry_PTX(ir::PTXOperand::u32, true), 
			testCarry_OUT(I32), testCarry_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);

		add("TestAdd-Carry-s32", testCarry_REF<signed int, false>, 
			testCarry_PTX(ir::PTXOperand::s32, false), 
			testCarry_OUT(I32), testCarry_IN(I32), 
			uniformRandom<signed int, 2>, 1, 1);
		add("TestAdd-Carry-u32", testCarry_REF<unsigned int, false>, 
			testCarry_PTX(ir::PTXOperand::u32, false), 
			testCarry_OUT(I32), testCarry_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);	

		add("TestMul-Lo-u16", testMul_REF<unsigned short, MulLo>, 
			testMul_PTX(ir::PTXOperand::u16, MulLo), 
			testMul_OUT(I16, MulLo), testMul_IN(I16), 
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestMul-Hi-u16", testMul_REF<unsigned short, MulHi>, 
			testMul_PTX(ir::PTXOperand::u16, MulHi), 
			testMul_OUT(I16, MulHi), testMul_IN(I16), 
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestMul-Wide-u16", testMul_REF<unsigned short, MulWide>, 
			testMul_PTX(ir::PTXOperand::u16, MulWide), 
			testMul_OUT(I16, MulWide), testMul_IN(I16), 
			uniformRandom<unsigned short, 2>, 1, 1);

		add("TestMul-Lo-s16", testMul_REF<short, MulLo>, 
			testMul_PTX(ir::PTXOperand::s16, MulLo), 
			testMul_OUT(I16, MulLo), testMul_IN(I16), 
			uniformRandom<short, 2>, 1, 1);
		add("TestMul-Hi-s16", testMul_REF<short, MulHi>, 
			testMul_PTX(ir::PTXOperand::s16, MulHi), 
			testMul_OUT(I16, MulHi), testMul_IN(I16), 
			uniformRandom<short, 2>, 1, 1);
		add("TestMul-Wide-s16", testMul_REF<short, MulWide>, 
			testMul_PTX(ir::PTXOperand::s16, MulWide), 
			testMul_OUT(I16, MulWide), testMul_IN(I16), 
			uniformRandom<short, 2>, 1, 1);

		add("TestMul-Lo-u32", testMul_REF<unsigned int, MulLo>, 
			testMul_PTX(ir::PTXOperand::u32, MulLo), 
			testMul_OUT(I32, MulLo), testMul_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestMul-Hi-u32", testMul_REF<unsigned int, MulHi>, 
			testMul_PTX(ir::PTXOperand::u32, MulHi), 
			testMul_OUT(I32, MulHi), testMul_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestMul-Wide-u32", testMul_REF<unsigned int, MulWide>, 
			testMul_PTX(ir::PTXOperand::u32, MulWide), 
			testMul_OUT(I32, MulWide), testMul_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);

		add("TestMul-Lo-s32", testMul_REF<int, MulLo>, 
			testMul_PTX(ir::PTXOperand::s32, MulLo), 
			testMul_OUT(I32, MulLo), testMul_IN(I32), 
			uniformRandom<int, 2>, 1, 1);
		add("TestMul-Hi-s32", testMul_REF<int, MulHi>, 
			testMul_PTX(ir::PTXOperand::s32, MulHi), 
			testMul_OUT(I32, MulHi), testMul_IN(I32), 
			uniformRandom<int, 2>, 1, 1);
		add("TestMul-Wide-s32", testMul_REF<int, MulWide>, 
			testMul_PTX(ir::PTXOperand::s32, MulWide), 
			testMul_OUT(I32, MulWide), testMul_IN(I32), 
			uniformRandom<int, 2>, 1, 1);

		add("TestMul-Lo-u64", testMul_REF<long long unsigned int, MulLo>, 
			testMul_PTX(ir::PTXOperand::u64, MulLo), 
			testMul_OUT(I64, MulLo), testMul_IN(I64), 
			uniformRandom<long long unsigned int, 2>, 1, 1);
		add("TestMul-Hi-u64", testMul_REF<long long unsigned int, MulHi>, 
			testMul_PTX(ir::PTXOperand::u64, MulHi), 
			testMul_OUT(I64, MulHi), testMul_IN(I64), 
			uniformRandom<long long unsigned int, 2>, 1, 1);

		add("TestMul-Lo-s64", testMul_REF<long long int, MulLo>, 
			testMul_PTX(ir::PTXOperand::s64, MulLo), 
			testMul_OUT(I64, MulLo), testMul_IN(I64), 
			uniformRandom<long long int, 2>, 1, 1);
		add("TestMul-Hi-s64", testMul_REF<long long int, MulHi>, 
			testMul_PTX(ir::PTXOperand::s64, MulHi), 
			testMul_OUT(I64, MulHi), testMul_IN(I64), 
			uniformRandom<long long int, 2>, 1, 1);

		add("TestMad-Lo-u16", testMad_REF<unsigned short, MulLo, false>, 
			testMad_PTX(ir::PTXOperand::u16, MulLo, false), 
			testMad_OUT(I16, MulLo), testMad_IN(I16, MulLo), 
			uniformRandom<unsigned short, 3>, 1, 1);
		add("TestMad-Hi-u16", testMad_REF<unsigned short, MulHi, false>, 
			testMad_PTX(ir::PTXOperand::u16, MulHi, false), 
			testMad_OUT(I16, MulHi), testMad_IN(I16, MulHi), 
			uniformRandom<unsigned short, 3>, 1, 1);
		add("TestMad-Wide-u16", testMad_REF<unsigned short, MulWide, false>, 
			testMad_PTX(ir::PTXOperand::u16, MulWide, false), 
			testMad_OUT(I16, MulWide), testMad_IN(I16, MulWide), 
			uniformRandom<unsigned short, 4>, 1, 1);

		add("TestMad-Lo-s16", testMad_REF<short, MulLo, false>, 
			testMad_PTX(ir::PTXOperand::s16, MulLo, false), 
			testMad_OUT(I16, MulLo), testMad_IN(I16, MulLo), 
			uniformRandom<short, 3>, 1, 1);
		add("TestMad-Hi-s16", testMad_REF<short, MulHi, false>, 
			testMad_PTX(ir::PTXOperand::s16, MulHi, false), 
			testMad_OUT(I16, MulHi), testMad_IN(I16, MulHi), 
			uniformRandom<short, 3>, 1, 1);
		add("TestMad-Wide-s16", testMad_REF<short, MulWide, false>, 
			testMad_PTX(ir::PTXOperand::s16, MulWide, false), 
			testMad_OUT(I16, MulWide), testMad_IN(I16, MulWide), 
			uniformRandom<short, 4>, 1, 1);

		add("TestMad-Lo-u32", testMad_REF<unsigned int, MulLo, false>, 
			testMad_PTX(ir::PTXOperand::u32, MulLo, false), 
			testMad_OUT(I32, MulLo), testMad_IN(I32, MulLo), 
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestMad-Hi-u32", testMad_REF<unsigned int, MulHi, false>, 
			testMad_PTX(ir::PTXOperand::u32, MulHi, false), 
			testMad_OUT(I32, MulHi), testMad_IN(I32, MulHi), 
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestMad-Wide-u32", testMad_REF<unsigned int, MulWide, false>, 
			testMad_PTX(ir::PTXOperand::u32, MulWide, false), 
			testMad_OUT(I32, MulWide), testMad_IN(I32, MulWide), 
			uniformRandom<unsigned int, 4>, 1, 1);

		add("TestMad-Lo-s32", testMad_REF<int, MulLo, false>, 
			testMad_PTX(ir::PTXOperand::s32, MulLo, false), 
			testMad_OUT(I32, MulLo), testMad_IN(I32, MulLo), 
			uniformRandom<int, 3>, 1, 1);
		add("TestMad-Hi-s32", testMad_REF<int, MulHi, false>, 
			testMad_PTX(ir::PTXOperand::s32, MulHi, false), 
			testMad_OUT(I32, MulHi), testMad_IN(I32, MulHi), 
			uniformRandom<int, 3>, 1, 1);
		add("TestMad-Sat-Hi-s32", testMad_REF<int, MulHi, true>, 
			testMad_PTX(ir::PTXOperand::s32, MulHi, true), 
			testMad_OUT(I32, MulHi), testMad_IN(I32, MulHi), 
			uniformRandom<int, 3>, 1, 1);
		add("TestMad-Wide-s32", testMad_REF<int, MulWide, false>, 
			testMad_PTX(ir::PTXOperand::s32, MulWide, false), 
			testMad_OUT(I32, MulWide), testMad_IN(I32, MulWide), 
			uniformRandom<int, 4>, 1, 1);

		add("TestMad-Lo-u64", testMad_REF<long long unsigned int, MulLo, false>,
			testMad_PTX(ir::PTXOperand::u64, MulLo, false), 
			testMad_OUT(I64, MulLo), testMad_IN(I64, MulLo), 
			uniformRandom<long long unsigned int, 3>, 1, 1);
		add("TestMad-Hi-u64", testMad_REF<long long unsigned int, MulHi, false>,
			testMad_PTX(ir::PTXOperand::u64, MulHi, false), 
			testMad_OUT(I64, MulHi), testMad_IN(I64, MulHi), 
			uniformRandom<long long unsigned int, 3>, 1, 1);

		add("TestMad-Lo-s64", testMad_REF<long long int, MulLo, false>, 
			testMad_PTX(ir::PTXOperand::s64, MulLo, false), 
			testMad_OUT(I64, MulLo), testMad_IN(I64, MulLo), 
			uniformRandom<long long int, 3>, 1, 1);
		add("TestMad-Hi-s64", testMad_REF<long long int, MulHi, false>, 
			testMad_PTX(ir::PTXOperand::s64, MulHi, false), 
			testMad_OUT(I64, MulHi), testMad_IN(I64, MulHi), 
			uniformRandom<long long int, 3>, 1, 1);

		add("TestSad-u16", testSad_REF<unsigned short>, 
			testSad_PTX(ir::PTXOperand::u16), 
			testSad_OUT(I16), testSad_IN(I16), 
			uniformRandom<unsigned short, 3>, 1, 1);
		add("TestSad-s16", testSad_REF<short>, 
			testSad_PTX(ir::PTXOperand::s16), 
			testSad_OUT(I16), testSad_IN(I16), 
			uniformRandom<short, 3>, 1, 1);

		add("TestSad-u32", testSad_REF<unsigned int>, 
			testSad_PTX(ir::PTXOperand::u32), 
			testSad_OUT(I32), testSad_IN(I32), 
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestSad-s32", testSad_REF<int>, 
			testSad_PTX(ir::PTXOperand::s32), 
			testSad_OUT(I32), testSad_IN(I32), 
			uniformRandom<int, 3>, 1, 1);

		add("TestSad-u64", testSad_REF<long long unsigned int>, 
			testSad_PTX(ir::PTXOperand::u64), 
			testSad_OUT(I64), testSad_IN(I64), 
			uniformRandom<long long unsigned int, 3>, 1, 1);
		add("TestSad-s64", testSad_REF<long long int>, 
			testSad_PTX(ir::PTXOperand::s64), 
			testSad_OUT(I64), testSad_IN(I64), 
			uniformRandom<long long int, 3>, 1, 1);

		add("TestDiv-u16", testDiv_REF<unsigned short>, 
			testDiv_PTX(ir::PTXOperand::u16), 
			testDiv_OUT(I16), testDiv_IN(I16), 
			uniformNonZero<unsigned short, 2>, 1, 1);
		add("TestDiv-s16", testDiv_REF<short>, 
			testDiv_PTX(ir::PTXOperand::s16), 
			testDiv_OUT(I16), testDiv_IN(I16), 
			uniformNonZero<short, 2>, 1, 1);

		add("TestDiv-u32", testDiv_REF<unsigned int>, 
			testDiv_PTX(ir::PTXOperand::u32), 
			testDiv_OUT(I32), testDiv_IN(I32), 
			uniformNonZero<unsigned int, 2>, 1, 1);
		add("TestDiv-s32", testDiv_REF<int>, 
			testDiv_PTX(ir::PTXOperand::s32), 
			testDiv_OUT(I32), testDiv_IN(I32), 
			uniformNonZero<int, 2>, 1, 1);

		add("TestDiv-u64", testDiv_REF<long long unsigned int>, 
			testDiv_PTX(ir::PTXOperand::u64), 
			testDiv_OUT(I64), testDiv_IN(I64), 
			uniformNonZero<long long unsigned int, 2>, 1, 1);
		add("TestDiv-s64", testDiv_REF<long long int>, 
			testDiv_PTX(ir::PTXOperand::s64), 
			testDiv_OUT(I64), testDiv_IN(I64), 
			uniformNonZero<long long int, 2>, 1, 1);

		add("TestRem-u16", testRem_REF<unsigned short>, 
			testRem_PTX(ir::PTXOperand::u16), 
			testRem_OUT(I16), testRem_IN(I16), 
			uniformNonZero<unsigned short, 2>, 1, 1);
		add("TestRem-s16", testRem_REF<short>, 
			testRem_PTX(ir::PTXOperand::s16), 
			testRem_OUT(I16), testRem_IN(I16), 
			uniformNonZero<short, 2>, 1, 1);
		add("TestRem-u32", testRem_REF<unsigned int>, 
			testRem_PTX(ir::PTXOperand::u32), 
			testRem_OUT(I32), testRem_IN(I32), 
			uniformNonZero<unsigned int, 2>, 1, 1);
		add("TestRem-s32", testRem_REF<int>, 
			testRem_PTX(ir::PTXOperand::s32), 
			testRem_OUT(I32), testRem_IN(I32), 
			uniformNonZero<int, 2>, 1, 1);
		add("TestRem-u64", testRem_REF<long long unsigned int>, 
			testRem_PTX(ir::PTXOperand::u64), 
			testRem_OUT(I64), testRem_IN(I64), 
			uniformNonZero<long long unsigned int, 2>, 1, 1);
		add("TestRem-s64", testRem_REF<long long int>, 
			testRem_PTX(ir::PTXOperand::s64), 
			testRem_OUT(I64), testRem_IN(I64), 
			uniformNonZero<long long int, 2>, 1, 1);

		add("TestAbs-s16", testAbs_REF<short>, 
			testAbs_PTX(ir::PTXOperand::s16), 
			testAbs_OUT(I16), testAbs_IN(I16), 
			uniformRandom<short, 1>, 1, 1);
		add("TestAbs-s32", testAbs_REF<int>, 
			testAbs_PTX(ir::PTXOperand::s32), 
			testAbs_OUT(I32), testAbs_IN(I32), 
			uniformRandom<int, 1>, 1, 1);
		add("TestAbs-s64", testAbs_REF<long long int>, 
			testAbs_PTX(ir::PTXOperand::s64), 
			testAbs_OUT(I64), testAbs_IN(I64), 
			uniformRandom<long long int, 1>, 1, 1);

		add("TestNeg-s16", testNeg_REF<short>, 
			testNeg_PTX(ir::PTXOperand::s16), 
			testNeg_OUT(I16), testNeg_IN(I16), 
			uniformRandom<short, 1>, 1, 1);
		add("TestNeg-s32", testNeg_REF<int>, 
			testNeg_PTX(ir::PTXOperand::s32), 
			testNeg_OUT(I32), testNeg_IN(I32), 
			uniformRandom<int, 1>, 1, 1);
		add("TestNeg-s64", testNeg_REF<long long int>, 
			testNeg_PTX(ir::PTXOperand::s64), 
			testNeg_OUT(I64), testNeg_IN(I64), 
			uniformRandom<long long int, 1>, 1, 1);

		add("TestMax-u16", testMinMax_REF<unsigned short, true>, 
			testMinMax_PTX(ir::PTXOperand::u16, true), 
			testMinMax_OUT(I16), testMinMax_IN(I16), 
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestMax-u32", testMinMax_REF<unsigned int, true>, 
			testMinMax_PTX(ir::PTXOperand::u32, true), 
			testMinMax_OUT(I32), testMinMax_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestMax-u64", testMinMax_REF<long long unsigned int, true>, 
			testMinMax_PTX(ir::PTXOperand::u64, true), 
			testMinMax_OUT(I64), testMinMax_IN(I64), 
			uniformRandom<long long unsigned int, 2>, 1, 1);
		add("TestMax-s16", testMinMax_REF<short, true>, 
			testMinMax_PTX(ir::PTXOperand::s16, true), 
			testMinMax_OUT(I16), testMinMax_IN(I16), 
			uniformRandom<short, 2>, 1, 1);
		add("TestMax-s32", testMinMax_REF<int, true>, 
			testMinMax_PTX(ir::PTXOperand::s32, true), 
			testMinMax_OUT(I32), testMinMax_IN(I32), 
			uniformRandom<int, 2>, 1, 1);
		add("TestMax-s64", testMinMax_REF<long long int, true>, 
			testMinMax_PTX(ir::PTXOperand::s64, true), 
			testMinMax_OUT(I64), testMinMax_IN(I64), 
			uniformRandom<long long int, 2>, 1, 1);

		add("TestMin-u16", testMinMax_REF<unsigned short, false>, 
			testMinMax_PTX(ir::PTXOperand::u16, false), 
			testMinMax_OUT(I16), testMinMax_IN(I16), 
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestMin-u32", testMinMax_REF<unsigned int, false>, 
			testMinMax_PTX(ir::PTXOperand::u32, false), 
			testMinMax_OUT(I32), testMinMax_IN(I32), 
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestMin-u64", testMinMax_REF<long long unsigned int, false>, 
			testMinMax_PTX(ir::PTXOperand::u64, false), 
			testMinMax_OUT(I64), testMinMax_IN(I64), 
			uniformRandom<long long unsigned int, 2>, 1, 1);
		add("TestMin-s16", testMinMax_REF<short, false>, 
			testMinMax_PTX(ir::PTXOperand::s16, false), 
			testMinMax_OUT(I16), testMinMax_IN(I16), 
			uniformRandom<short, 2>, 1, 1);
		add("TestMin-s32", testMinMax_REF<int, false>, 
			testMinMax_PTX(ir::PTXOperand::s32, false), 
			testMinMax_OUT(I32), testMinMax_IN(I32), 
			uniformRandom<int, 2>, 1, 1);
		add("TestMin-s64", testMinMax_REF<long long int, false>, 
			testMinMax_PTX(ir::PTXOperand::s64, false), 
			testMinMax_OUT(I64), testMinMax_IN(I64), 
			uniformRandom<long long int, 2>, 1, 1);

		add("TestPopc-b32", testPopc_REF<unsigned int>, 
			testPopc_PTX(ir::PTXOperand::b32), 
			testPopc_OUT(I32), testPopc_IN(I32), 
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestPopc-b64", testPopc_REF<long long unsigned int>, 
			testPopc_PTX(ir::PTXOperand::b64), 
			testPopc_OUT(I32), testPopc_IN(I64), 
			uniformRandom<long long unsigned int, 1>, 1, 1);

		add("TestClz-b32", testClz_REF<unsigned int>, 
			testClz_PTX(ir::PTXOperand::b32), 
			testClz_OUT(I32), testClz_IN(I32), 
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestClz-b64", testClz_REF<long long unsigned int>, 
			testClz_PTX(ir::PTXOperand::b64), 
			testClz_OUT(I32), testClz_IN(I64), 
			uniformRandom<long long unsigned int, 1>, 1, 1);

		add("TestBfind-u32", testBfind_REF<unsigned int, false>, 
			testBfind_PTX(ir::PTXOperand::u32, false), testBfind_OUT(), 
			testBfind_IN(I32), uniformRandom<unsigned int, 1>, 1, 1);
		add("TestBfind-u64", testBfind_REF<long long unsigned int, false>, 
			testBfind_PTX(ir::PTXOperand::u64, false), testBfind_OUT(), 
			testBfind_IN(I64), uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestBfind-s32", testBfind_REF<int, false>, 
			testBfind_PTX(ir::PTXOperand::s32, false), testBfind_OUT(), 
			testBfind_IN(I32), uniformRandom<int, 1>, 1, 1);
		add("TestBfind-s64", testBfind_REF<long long int, false>, 
			testBfind_PTX(ir::PTXOperand::s64, false), testBfind_OUT(), 
			testBfind_IN(I64), uniformRandom<long long int, 1>, 1, 1);

		add("TestBfind-shiftamount-u32", testBfind_REF<unsigned int, true>, 
			testBfind_PTX(ir::PTXOperand::u32, true), testBfind_OUT(), 
			testBfind_IN(I32), uniformRandom<unsigned int, 1>, 1, 1);
		add("TestBfind-shiftamount-u64", 
			testBfind_REF<long long unsigned int, true>, 
			testBfind_PTX(ir::PTXOperand::u64, true), testBfind_OUT(), 
			testBfind_IN(I64), uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestBfind-shiftamount-s32", testBfind_REF<int, true>, 
			testBfind_PTX(ir::PTXOperand::s32, true), testBfind_OUT(), 
			testBfind_IN(I32), uniformRandom<int, 1>, 1, 1);
		add("TestBfind-shiftamount-s64", testBfind_REF<long long int, true>, 
			testBfind_PTX(ir::PTXOperand::s64, true), testBfind_OUT(), 
			testBfind_IN(I64), uniformRandom<long long int, 1>, 1, 1);

		add("TestBrev-b32", testBrev_REF<unsigned int>, 
			testBrev_PTX(ir::PTXOperand::b32), testBrev_OUT(I32), 
			testBrev_IN(I32), uniformRandom<unsigned int, 1>, 1, 1);
		add("TestBrev-b64", testBrev_REF<long long unsigned int>, 
			testBrev_PTX(ir::PTXOperand::b64), testBrev_OUT(I64), 
			testBrev_IN(I64), uniformRandom<long long unsigned int, 1>, 1, 1);

		add("TestBfi-b32", testBfi_REF<unsigned int>, 
			testBfi_PTX(ir::PTXOperand::b32), testBfi_OUT(I32), 
			testBfi_IN(I32), uniformRandom<unsigned int, 4>, 1, 1);
		add("TestBfi-b64", testBfi_REF<long long unsigned int>, 
			testBfi_PTX(ir::PTXOperand::b64), testBfi_OUT(I64), 
			testBfi_IN(I64), uniformRandom<long long unsigned int, 3>, 1, 1);
	
		add("TestPrmt-b32", testPrmt_REF<ir::PTXInstruction::DefaultPermute>, 
			testPrmt_PTX(ir::PTXInstruction::DefaultPermute), testPrmt_OUT(), 
			testPrmt_IN(), uniformRandom<unsigned int, 3>, 1, 1);
		add("TestPrmt-f4e-b32", 
			testPrmt_REF<ir::PTXInstruction::ForwardFourExtract>, 
			testPrmt_PTX(ir::PTXInstruction::ForwardFourExtract), 
			testPrmt_OUT(), testPrmt_IN(), uniformRandom<unsigned int, 3>, 
			1, 1);
		add("TestPrmt-b4e-b32", 
			testPrmt_REF<ir::PTXInstruction::BackwardFourExtract>, 
			testPrmt_PTX(ir::PTXInstruction::BackwardFourExtract), 
			testPrmt_OUT(), testPrmt_IN(), uniformRandom<unsigned int, 3>, 
			1, 1);
		add("TestPrmt-rc8-b32", 
			testPrmt_REF<ir::PTXInstruction::ReplicateEight>, 
			testPrmt_PTX(ir::PTXInstruction::ReplicateEight), testPrmt_OUT(), 
			testPrmt_IN(), uniformRandom<unsigned int, 3>, 1, 1);
		add("TestPrmt-ecl-b32", testPrmt_REF<ir::PTXInstruction::EdgeClampLeft>, 
			testPrmt_PTX(ir::PTXInstruction::EdgeClampLeft), testPrmt_OUT(), 
			testPrmt_IN(), uniformRandom<unsigned int, 3>, 1, 1);
		add("TestPrmt-ecr-b32", 
			testPrmt_REF<ir::PTXInstruction::EdgeClampRight>, 
			testPrmt_PTX(ir::PTXInstruction::EdgeClampRight), testPrmt_OUT(), 
			testPrmt_IN(), uniformRandom<unsigned int, 3>, 1, 1);
		add("TestPrmt-rc16-b32", 
			testPrmt_REF<ir::PTXInstruction::ReplicateSixteen>, 
			testPrmt_PTX(ir::PTXInstruction::ReplicateSixteen), testPrmt_OUT(), 
			testPrmt_IN(), uniformRandom<unsigned int, 3>, 1, 1);
			
		add("TestCall-Uni", testFunctionCalls_REF, 
			testFunctionCalls_PTX(true), testFunctionCalls_OUT(), 
			testFunctionCalls_IN(), uniformRandom<unsigned int, 2>, 1, 1);
		add("TestCall-Nondivergent", testFunctionCalls_REF, 
			testFunctionCalls_PTX(false), testFunctionCalls_OUT(), 
			testFunctionCalls_IN(), uniformRandom<unsigned int, 2>, 1, 1);
		add("TestCall-Divergent", testDivergentFunctionCall_REF, 
			testDivergentFunctionCall_PTX(), testDivergentFunctionCall_OUT(), 
			testDivergentFunctionCall_IN(), 
			uniformRandom<unsigned int, 4>, 2, 1);
		add("TestCall-Recursive", testRecursiveFunctionCall_REF, 
			testRecursiveFunctionCall_PTX(), testRecursiveFunctionCall_OUT(), 
			testRecursiveFunctionCall_IN(), 
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCall-Indirect", testIndirectFunctionCall_REF, 
			testIndirectFunctionCall_PTX(), testIndirectFunctionCall_OUT(), 
			testIndirectFunctionCall_IN(), 
			uniformRandom<unsigned int, 1>, 4, 1);

		add("TestTestP-f32-Finite", 
			testTestP_REF<float, ir::PTXInstruction::Finite>, 
			testTestp_PTX(ir::PTXOperand::f32, ir::PTXInstruction::Finite), 
			testTestp_OUT(), testTestp_IN(FP32), uniformFloat<float, 1>, 1, 1);
		add("TestTestP-f32-Infinite", 
			testTestP_REF<float, ir::PTXInstruction::Infinite>, 
			testTestp_PTX(ir::PTXOperand::f32, ir::PTXInstruction::Infinite), 
			testTestp_OUT(), testTestp_IN(FP32), uniformFloat<float, 1>, 1, 1);
		add("TestTestP-f32-Number", 
			testTestP_REF<float, ir::PTXInstruction::Number>, 
			testTestp_PTX(ir::PTXOperand::f32, ir::PTXInstruction::Number), 
			testTestp_OUT(), testTestp_IN(FP32), uniformFloat<float, 1>, 1, 1);
		add("TestTestP-f32-NotANumber", 
			testTestP_REF<float, ir::PTXInstruction::NotANumber>, 
			testTestp_PTX(ir::PTXOperand::f32, ir::PTXInstruction::NotANumber), 
			testTestp_OUT(), testTestp_IN(FP32), uniformFloat<float, 1>, 1, 1);
		add("TestTestP-f32-Normal", 
			testTestP_REF<float, ir::PTXInstruction::Normal>, 
			testTestp_PTX(ir::PTXOperand::f32, ir::PTXInstruction::Normal), 
			testTestp_OUT(), testTestp_IN(FP32), uniformFloat<float, 1>, 1, 1);
		add("TestTestP-f32-SubNormal", 
			testTestP_REF<float, ir::PTXInstruction::SubNormal>, 
			testTestp_PTX(ir::PTXOperand::f32, ir::PTXInstruction::SubNormal), 
			testTestp_OUT(), testTestp_IN(FP32), uniformFloat<float, 1>, 1, 1);

		add("TestTestP-f64-Finite", 
			testTestP_REF<double, ir::PTXInstruction::Finite>, 
			testTestp_PTX(ir::PTXOperand::f64, ir::PTXInstruction::Finite), 
			testTestp_OUT(), testTestp_IN(FP64), uniformFloat<double, 1>, 1, 1);
		add("TestTestP-f64-Infinite", 
			testTestP_REF<double, ir::PTXInstruction::Infinite>, 
			testTestp_PTX(ir::PTXOperand::f64, ir::PTXInstruction::Infinite), 
			testTestp_OUT(), testTestp_IN(FP64), uniformFloat<double, 1>, 1, 1);
		add("TestTestP-f64-Number", 
			testTestP_REF<double, ir::PTXInstruction::Number>, 
			testTestp_PTX(ir::PTXOperand::f64, ir::PTXInstruction::Number), 
			testTestp_OUT(), testTestp_IN(FP64), uniformFloat<double, 1>, 1, 1);
		add("TestTestP-f64-NotANumber", 
			testTestP_REF<double, ir::PTXInstruction::NotANumber>, 
			testTestp_PTX(ir::PTXOperand::f64, ir::PTXInstruction::NotANumber), 
			testTestp_OUT(), testTestp_IN(FP64), uniformFloat<double, 1>, 1, 1);
		add("TestTestP-f64-Normal", 
			testTestP_REF<double, ir::PTXInstruction::Normal>, 
			testTestp_PTX(ir::PTXOperand::f64, ir::PTXInstruction::Normal), 
			testTestp_OUT(), testTestp_IN(FP64), uniformFloat<double, 1>, 1, 1);
		add("TestTestP-f64-SubNormal", 
			testTestP_REF<double, ir::PTXInstruction::SubNormal>, 
			testTestp_PTX(ir::PTXOperand::f64, ir::PTXInstruction::SubNormal), 
			testTestp_OUT(), testTestp_IN(FP64), uniformFloat<double, 1>, 1, 1);

	}

	TestPTXAssembly::TestPTXAssembly(hydrazine::Timer::Second l, 
		unsigned int t) : _tolerableFailures(t), timeLimit(l)
	{
		name = "TestPTXAssembly";
		
		description = "A unit test framework for PTX. Runs random inputs ";
		description += "through unit tests on all available devices until ";
		description += "a timer expires.";		
	}
	
	void TestPTXAssembly::add(const std::string& name, 
		ReferenceFunction function, const std::string& ptx, 
		const TypeVector& out, const TypeVector& in, 
		GeneratorFunction generator, unsigned int threads, unsigned int ctas)
	{
		// TODO change this to std::tr1::regex when gcc gets its act together
		if(!regularExpression.empty() && regularExpression != name) return;
		
		if(enumerate)
		{
			std::cout << name << "\n";
			return;	
		}
		
		TestHandle test;
		test.name = name;
		test.reference = function;
		test.generator = generator;
		test.ptx = ptx;
		test.inputTypes = in;
		test.outputTypes = out;
		test.threads = threads;
		test.ctas = ctas;
		
		if(print)
		{
			std::cout << "Added test - '" << name << "'\n";
			std::cout << ptx << "\n";
		}
		
		_tests.push_back(std::move(test));
	}	
	
	bool TestPTXAssembly::doTest()
	{
		_loadTests();
		
		hydrazine::Timer::Second perTestTimeLimit = timeLimit / _tests.size();
		hydrazine::Timer timer;
		
		unsigned int failures = 0;
		
		for(TestVector::iterator test = _tests.begin(); 
			test != _tests.end(); ++test)
		{
			timer.stop();
			timer.start();
			unsigned int i = 0;
			for( ; timer.seconds() < perTestTimeLimit; ++i)
			{
				bool result = _doOneTest(*test, seed + i);
				
				if(!result)
				{
					status << "Test '" << test->name << "' seed '" 
						<< (seed + i) << "' failed.\n";
					if(++failures > _tolerableFailures) return false;
				}
				
				timer.stop();
			}
			status << "Ran '" << test->name << "' for " 
				<< i << " iterations.\n";	
		}
		
		return failures == 0;
	}
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser(argc, argv);
	test::TestPTXAssembly test;
	parser.description(test.testDescription());

	parser.parse("-v", "--verbose", test.verbose, false,
		"Print out status info after the test.");
	parser.parse("-p", "--print-ptx", test.print, false,
		"Print test kernels as they are added.");
	parser.parse("-e", "--enumerate", test.enumerate, false,
		"Only enumerate tests, do not run them.");
	parser.parse("-t", "--test", test.regularExpression, "",
		"Only select tests matching this expression.");
	parser.parse("-s", "--seed", test.seed, 0,
		"Random seed for generating input data. 0 implies seed with time.");
	parser.parse("-l", "--time-limit", test.timeLimit, 10, 
		"How many seconds to run tests.");
	parser.parse();

	test.test();
	
	return test.passed();
}

#endif

