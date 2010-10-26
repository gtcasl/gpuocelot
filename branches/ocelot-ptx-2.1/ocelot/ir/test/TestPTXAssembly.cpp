/*! \file TestPTXAssembly.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday May 11, 2010
	\brief The source file for the TestPTXAssembly class.
*/

#ifndef TEST_PTX_ASSEMBLY_CPP_INCLUDED
#define TEST_PTX_ASSEMBLY_CPP_INCLUDED

#include <ocelot/ir/test/TestPTXAssembly.h>
#include <ocelot/ir/interface/PTXInstruction.h>

#include <ocelot/executive/interface/TextureOperations.h>

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

////////////////////////////////////////////////////////////////////////////////
// HELPER FUNCTIONS
template<typename T>
bool issubnormal(T r0)
{
	return !std::isnormal(r0) && !std::isnan(r0) && !std::isinf(r0);
}

bool compareFloat(float a, float b)
{
	if(std::isnan(a) && std::isnan(b)) return true;

	return a == b;
}

bool compareDouble(double a, double b)
{
	if(std::isnan(a) && std::isnan(b)) return true;

	return a == b;
}

template<typename T>
bool isFloat()
{
	if(typeid(T) == typeid(float) || typeid(T) == typeid(double)) return true;
	return false;
}

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
		result[i] = (value == 0) ? 1 : value;
	}
	
	return result;
}

template <typename type, unsigned int size>
char* uniformFloat(test::Test::MersenneTwister& generator)
{
	char* allocation = new char[size*sizeof(type)];
	type* result = (type*) allocation;

	for(unsigned int i = 0; i < size; ++i)
	{
		unsigned int fptype = generator();
		
		if(fptype & 0x100)
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
				if(fptype & 0x1)
				{
					result[i] = hydrazine::bit_cast<type>(generator());
				}
				else
				{
					result[i] = (type)generator();
				}
			}
		}
	}
	
	return allocation;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST TEXTURES
std::string testTex_PTX(ir::PTXInstruction::Geometry dim,
	ir::PTXOperand::DataType dtype,
	ir::PTXOperand::DataType samplerType)
{
	std::stringstream ptx;

	std::string samplerTypeString = "." + ir::PTXOperand::toString(samplerType);
	std::string dTypeString       = "." + ir::PTXOperand::toString(dtype);

	ptx << ".version 2.1\n";
	ptx << ".global .texref Texture;\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << samplerTypeString << " %rs<4>;     \n";
	ptx << "\t.reg " << dTypeString << " %rd<4>;           \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << samplerTypeString << " %rs0, [%rIn];   \n";
	if(dim >= ir::PTXInstruction::_2d)
	{
		ptx << "\tld.global" << samplerTypeString << " %rs1, [%rIn + "
			<< ir::PTXOperand::bytes(samplerType) << "];   \n";
	}
	if(dim >= ir::PTXInstruction::_3d)
	{
		ptx << "\tld.global" << samplerTypeString << " %rs2, [%rIn + "
			<< 2 * ir::PTXOperand::bytes(samplerType) << "];   \n";
	}
	
	ptx << "\ttex." << ir::PTXInstruction::toString(dim) << ".v4"
		<< dTypeString << samplerTypeString 
		<< " {%rd0, %rd1, %rd2, %rd3}, [Texture, {%rs0";
	
	if(dim >= ir::PTXInstruction::_2d)
	{
		ptx << ", %rs1";
	}
	if(dim >= ir::PTXInstruction::_3d)
	{
		ptx << ", %rs2, %rs3}];\n";
	}
	
	ptx << "\tst.global" << dTypeString << " [%rOut], %rd0;\n";
	ptx << "\tst.global" << dTypeString << " [%rOut + " 
		<< ir::PTXOperand::bytes(dtype) << "], %rd1;\n";
	ptx << "\tst.global" << dTypeString << " [%rOut + " 
		<< 2 * ir::PTXOperand::bytes(dtype) << "], %rd2;\n";
	ptx << "\tst.global" << dTypeString << " [%rOut + " 
		<< 3 * ir::PTXOperand::bytes(dtype) << "], %rd3;\n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename dtype, typename stype, ir::PTXInstruction::Geometry dim>
void testTex_REF(void* output, void* input)
{
	stype r[3];

	const ir::Texture& texture = *getParameter<const ir::Texture*>(input, 0);
	
	r[0] = getParameter<stype>(input, sizeof(const ir::Texture*));
	
	if(dim >= ir::PTXInstruction::_2d)
	{
		r[1] = getParameter<stype>(input,
			sizeof(const ir::Texture*) + sizeof(stype));
	}
	if(dim == ir::PTXInstruction::_3d)
	{
		r[2] = getParameter<stype>(input,
			sizeof(const ir::Texture*) + 2 * sizeof(stype));
	}

	dtype d[4];

	if(dim == ir::PTXInstruction::_1d)
	{
		d[0] = executive::tex::sample<0, dtype>(texture, r[0]);
		d[1] = executive::tex::sample<1, dtype>(texture, r[0]);
		d[2] = executive::tex::sample<2, dtype>(texture, r[0]);
		d[3] = executive::tex::sample<3, dtype>(texture, r[0]);
	}
	else if(dim == ir::PTXInstruction::_2d)
	{
		d[0] = executive::tex::sample<0, dtype>(texture, r[0], r[1]);
		d[1] = executive::tex::sample<1, dtype>(texture, r[0], r[1]);
		d[2] = executive::tex::sample<2, dtype>(texture, r[0], r[1]);
		d[3] = executive::tex::sample<3, dtype>(texture, r[0], r[1]);
	}
	else
	{
		d[0] = executive::tex::sample<0, dtype>(texture, r[0], r[1], r[2]);
		d[1] = executive::tex::sample<1, dtype>(texture, r[0], r[1], r[2]);
		d[2] = executive::tex::sample<2, dtype>(texture, r[0], r[1], r[2]);
		d[3] = executive::tex::sample<3, dtype>(texture, r[0], r[1], r[2]);
	}
	
	setParameter(output, 0 * sizeof(dtype), d[0]);
	setParameter(output, 1 * sizeof(dtype), d[1]);
	setParameter(output, 2 * sizeof(dtype), d[2]);
	setParameter(output, 3 * sizeof(dtype), d[3]);
}

test::TestPTXAssembly::TypeVector testTex_IN(
	test::TestPTXAssembly::DataType type, ir::PTXInstruction::Geometry dim)
{
	return test::TestPTXAssembly::TypeVector(dim, type);
}

test::TestPTXAssembly::TypeVector testTex_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(4, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST CVT
std::string testCvt_PTX(ir::PTXOperand::DataType dtype, 
	ir::PTXOperand::DataType stype, bool ftz, bool sat, bool round)
{
	std::stringstream ptx;

	std::string sTypeString = "." + ir::PTXOperand::toString(stype);
	std::string dTypeString = "." + ir::PTXOperand::toString(dtype);

	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << sTypeString    << " %rs;           \n";
	ptx << "\t.reg " << dTypeString    << " %rd;           \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << sTypeString << " %rs, [%rIn];   \n";

	ptx << "\tcvt";
	
	if(round)
	{
		if(ir::PTXOperand::isFloat(stype))
		{
			ptx << ".rn";
		}
		else
		{
			ptx << ".rni";
		}
	}
	
	if(ftz) ptx << ".ftz";
	if(sat) ptx << ".sat";
	
	ptx << dTypeString << sTypeString << " %rd, %rs;       \n";
	
	ptx << "\tst.global" << dTypeString << " [%rOut], %rd; \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename dtype, typename stype, bool ftz, bool sat, bool round>
void testCvt_REF(void* output, void* input)
{
	stype r0 = getParameter<stype>(input, 0);

	if(isFloat<stype>() && !isFloat<dtype>())
	{
		if(isnan(r0)) r0 = (stype)0;
	}

	if(ftz)
	{
		if(issubnormal(r0)) r0 = (stype)0;
	}

	if(sat)
	{
		if(typeid(float) != typeid(dtype) && typeid(double) != typeid(dtype))
		{
			r0 = std::min((stype)std::numeric_limits<dtype>::max(), r0);
			r0 = std::max((stype)std::numeric_limits<dtype>::min(), r0);
		}
	}

	dtype r1 = r0;

	if(isFloat<stype>() && !isFloat<dtype>())
	{
		if((stype)std::numeric_limits<dtype>::max() < r0)
		{
			r1 = std::numeric_limits<dtype>::max();
		}
		if((stype)std::numeric_limits<dtype>::min() > r0)
		{
			r1 = std::numeric_limits<dtype>::min();	
		}
	}
	
	if(sat)
	{
		if(typeid(float) == typeid(dtype))
		{
			r1 = std::min((dtype)1.0f, r1);
			r1 = std::max((dtype)0.0f, r1);
		}
		else if(typeid(double) == typeid(dtype))
		{
			r1 = std::min((dtype)1.0, r1);
			r1 = std::max((dtype)0.0, r1);
		}
	}
	
	setParameter(output, 0, r1);
}

test::TestPTXAssembly::TypeVector testCvt_INOUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST MOV LABELS
std::string testMovLabel_PTX(ir::PTXInstruction::AddressSpace space, bool index, 
	ir::PTXInstruction::Vec v)
{
	std::stringstream ptx;

	std::string spaceString = "." + ir::PTXInstruction::toString(space);
	std::string vecString;
	
	if(v != ir::PTXOperand::v1)
	{
		vecString = "." + ir::PTXInstruction::toString(v);
	}
	
	ptx << ".version 2.1\n";

	if(space != ir::PTXInstruction::Param)
	{	
		if(index)
		{
			ptx << spaceString << " " << vecString << " .u32 global[2];\n";
		}
		else
		{
			ptx << spaceString << " " << vecString << " .u32 global;\n";
		}
	}

	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";

	if(space == ir::PTXInstruction::Param)
	{	
		if(index)
		{
			ptx << spaceString << " " << vecString << " .u32 global[2];\n";
		}
		else
		{
			ptx << spaceString << " " << vecString << " .u32 global;\n";
		}
	}

	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg .u32 %r<4>;                             \n";
	ptx << "\t.reg .u64 %address;                          \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	
	ptx << "\tld.global.u32 %r0, [%rIn];                   \n";

	if(index)
	{
		ptx << "\tmov.u64 %address, global[1];             \n";
	}
	else
	{
		ptx << "\tmov.u64 %address, global;                \n";
	}

	switch(v)
	{
	case ir::PTXOperand::v1:
	{
		ptx << "\tst" << spaceString << ".u32 [%address], %r0; \n";
		break;
	}
	case ir::PTXOperand::v2:
	{
		ptx << "\tst" << spaceString << ".v2.u32 [%address], {%r0, %r0}; \n";
		break;
	}
	case ir::PTXOperand::v4:
	{
		ptx << "\tst" << spaceString
			<< ".v4.u32 [%address], {%r0, %r0, %r0, %r0}; \n";
		break;
	}
	default: break;
	}
	
	if(index)
	{
		ptx << "\tmov.u64 %address, global + 4;            \n";
	}

	switch(v)
	{
	case ir::PTXOperand::v1:
	{
		ptx << "\tld" << spaceString << ".u32 %r0, [%address]; \n";
		break;
	}
	case ir::PTXOperand::v2:
	{
		ptx << "\tld" << spaceString << ".v2.u32 {%r0, %r1}, [%address]; \n";
		ptx << "\tand.b32 %r0, %r0, %r1;\n";
		break;
	}
	case ir::PTXOperand::v4:
	{
		ptx << "\tld" << spaceString 
			<< ".v4.u32 {%r0, %r1, %r2, %r3}, [%address]; \n";
		ptx << "\tand.b32 %r0, %r0, %r1;\n";
		ptx << "\tand.b32 %r0, %r0, %r2;\n";
		ptx << "\tand.b32 %r0, %r0, %r3;\n";
	break;
	}
	default: break;
	}

	ptx << "\tst.global.u32 [%rOut], %r0;                  \n";
	
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

void testMovLabel_REF(void* output, void* input)
{
	unsigned int r0 = getParameter<unsigned>(input, 0);

	setParameter(output, 0, r0);
}

test::TestPTXAssembly::TypeVector testMovLabel_INOUT()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST MOV
std::string testMov_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream ptx;

	std::string typeString = "." + ir::PTXOperand::toString(type);

	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << typeString    << " %r<2>;          \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	
	if(type == ir::PTXOperand::pred)
	{
		ptx << "\t.reg .u8  %rb0;                          \n";
		ptx << "\t.reg .u16 %rs0;                          \n";
		ptx << "\tld.global.u8 %rb0, [%rIn];               \n";
		ptx << "\tcvt.u16.u8 %rs0, %rb0;                   \n";
		ptx << "\tand.b16 %rs0, %rs0, 0x1;                 \n";
		ptx << "\tsetp.ne.u16 %r0, %rs0, 0;                \n";
		ptx << "\tmov" << typeString << " %r1, %r0;        \n";
		ptx << "\tselp.u16   %rs0, 1, 0, %r1;              \n";
		ptx << "\tcvt.u8.u16 %rb0, %rs0;                   \n";
		ptx << "\tst.global.u8 [%rOut], %rb0;              \n";
	}
	else
	{
		ptx << "\tld.global" << typeString << " %r0, [%rIn];   \n";
		ptx << "\tmov" << typeString << " %r1, %r0;            \n";
		ptx << "\tst.global" << typeString << " [%rOut], %r1;  \n";
	}
	
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type>
void testMov_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);

	if(typeid(bool) == typeid(type))
	{
		r0 &= 0x1;
	}

	type r1 = r0;

	setParameter(output, 0, r1);
}

test::TestPTXAssembly::TypeVector testMov_INOUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST LOGICAL OPs
std::string testLops_PTX(ir::PTXInstruction::Opcode opcode,
	ir::PTXOperand::DataType type)
{
	std::stringstream ptx;

	std::string typeString = "." + ir::PTXOperand::toString(type);

	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	if( opcode == ir::PTXInstruction::Shr 
		|| opcode == ir::PTXInstruction::Shl )
	{
		ptx << "\t.reg " << typeString    << " %r0, %r2;   \n";
		ptx << "\t.reg .u32 %r1;                           \n";
	}
	else
	{
		ptx << "\t.reg " << typeString    << " %r<3>;      \n";
	}
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	
	if(type == ir::PTXOperand::pred)
	{
		ptx << "\t.reg .u8  %rb<2>;                        \n";
		ptx << "\t.reg .u16 %rs<2>;                        \n";
		ptx << "\tld.global.u8 %rb0, [%rIn];               \n";
		ptx << "\tcvt.u16.u8 %rs0, %rb0;                   \n";
		ptx << "\tsetp.lt.u16 %r0, %rs0, 64;               \n";
		if(opcode == ir::PTXInstruction::And
			|| opcode == ir::PTXInstruction::Or
			|| opcode == ir::PTXInstruction::Xor)
		{
			ptx << "\tld.global.u8 %rb1, [%rIn + " 
				<< ir::PTXOperand::bytes(type) << "];          \n";
			ptx << "\tcvt.u16.u8 %rs1, %rb1;                   \n";
			ptx << "\tsetp.lt.u16 %r1, %rs1, 64;               \n";
		}
	}
	else
	{
		ptx << "\tld.global" << typeString << " %r0, [%rIn];   \n";
		if( opcode == ir::PTXInstruction::Shr 
			|| opcode == ir::PTXInstruction::Shl )
		{
			ptx << "\tld.global.u32 %r1, [%rIn + " 
				<< std::max((size_t)ir::PTXOperand::bytes(type), sizeof(unsigned int)) 
				<< "];              \n";
			ptx << "\trem.u32 %r1, %r1, " 
				<< 8 * ir::PTXOperand::bytes(type) << ";\n";
		}
		else if(opcode == ir::PTXInstruction::And
			|| opcode == ir::PTXInstruction::Or
			|| opcode == ir::PTXInstruction::Xor)
		{
			ptx << "\tld.global" << typeString << " %r1, [%rIn + " 
				<< ir::PTXOperand::bytes(type) << "];              \n";
		}
	}
	
	ptx << "\t" << ir::PTXInstruction::toString(opcode)
		<< typeString << " %r2, %r0";

	if(opcode == ir::PTXInstruction::And
		|| opcode == ir::PTXInstruction::Or
		|| opcode == ir::PTXInstruction::Xor
		|| opcode == ir::PTXInstruction::Shr
		|| opcode == ir::PTXInstruction::Shl)
	{
		ptx << ", %r1";
	}

	ptx << ";\n";

	if(type == ir::PTXOperand::pred)
	{
		ptx << "\tselp.u16   %rs0, 1, 0, %r2;                    \n";
		ptx << "\tcvt.u8.u16 %rb0, %rs0;                         \n";
		ptx << "\tst.global.u8 [%rOut], %rb0;                    \n";
	}
	else
	{
		ptx << "\tst.global" << typeString << " [%rOut], %r2;    \n";
	}
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<ir::PTXInstruction::Opcode opcode, typename type>
void testLops_REF(void* output, void* input)
{
	typedef long long unsigned int U64;

	switch(opcode)
	{
	case ir::PTXInstruction::And:
	{
		type r0 = getParameter<type>(input, 0);
		type r1 = getParameter<type>(input, sizeof(type));

		if(typeid(type) == typeid(bool))
		{
			r1 = r1 < 64;
			r0 = r0 < 64;
		}

		U64 a = hydrazine::bit_cast<U64>(r0);
		U64 b = hydrazine::bit_cast<U64>(r1);
		
		U64 d = a & b;
		
		setParameter(output, 0, hydrazine::bit_cast<type>(d));
		break;
	}
	case ir::PTXInstruction::Or:
	{
		type r0 = getParameter<type>(input, 0);
		type r1 = getParameter<type>(input, sizeof(type));

		if(typeid(type) == typeid(bool))
		{
			r1 = r1 < 64;
			r0 = r0 < 64;
		}

		U64 a = hydrazine::bit_cast<U64>(r0);
		U64 b = hydrazine::bit_cast<U64>(r1);
		
		U64 d = a | b;
		
		setParameter(output, 0, hydrazine::bit_cast<type>(d));
		break;
	}
	case ir::PTXInstruction::Xor:
	{
		type r0 = getParameter<type>(input, 0);
		type r1 = getParameter<type>(input, sizeof(type));

		if(typeid(type) == typeid(bool))
		{
			r1 = r1 < 64;
			r0 = r0 < 64;
		}

		U64 a = hydrazine::bit_cast<U64>(r0);
		U64 b = hydrazine::bit_cast<U64>(r1);
		
		U64 d = a ^ b;
		
		setParameter(output, 0, hydrazine::bit_cast<type>(d));
		break;
	}
	case ir::PTXInstruction::Shr:
	{
		type r0 = getParameter<type>(input, 0);
		unsigned int r1 = getParameter<unsigned int>(input,
			std::max(sizeof(type), sizeof(unsigned int)));

		if(typeid(type) == typeid(bool))
		{
			r1 = r1 < 64;
			r0 = r0 < 64;
		}

		type d = r0 >> (r1 % (sizeof(type) * 8));
		
		setParameter(output, 0, d);
		break;
	}
	case ir::PTXInstruction::Shl:
	{
		type r0 = getParameter<type>(input, 0);
		unsigned int r1 = getParameter<unsigned int>(input,
			std::max(sizeof(type), sizeof(unsigned int)));

		type d = r0 << (r1 % (sizeof(type) * 8));
		
		setParameter(output, 0, d);
		break;
	}
	case ir::PTXInstruction::Not:
	{
		type r0 = getParameter<type>(input, 0);

		if(typeid(type) == typeid(bool))
		{
			r0 = r0 < 64;
		}

		U64 a = hydrazine::bit_cast<U64>(r0);
		
		U64 d = ~a;
		
		if(typeid(type) == typeid(bool))
		{
			d = d & 1;
		}
		
		setParameter(output, 0, hydrazine::bit_cast<type>(d));
		break;
	}
	case ir::PTXInstruction::CNot:
	{
		type r0 = getParameter<type>(input, 0);

		if(typeid(type) == typeid(bool))
		{
			r0 = r0 < 64;
		}

		U64 a = hydrazine::bit_cast<U64>(r0);
		
		U64 d = a == 0 ? 1 : 0;
		
		setParameter(output, 0, hydrazine::bit_cast<type>(d));
		break;
	}
	default: assertM(false, "Invalid opcode for logical op.");
	}
	
}

test::TestPTXAssembly::TypeVector testLops_IN(
	ir::PTXInstruction::Opcode opcode, test::TestPTXAssembly::DataType type)
{
	if(opcode == ir::PTXInstruction::And
		|| opcode == ir::PTXInstruction::Or
		|| opcode == ir::PTXInstruction::Xor)
	{
		return test::TestPTXAssembly::TypeVector(2, type);
	}
	else if(opcode == ir::PTXInstruction::Shr
		|| opcode == ir::PTXInstruction::Shl)
	{
		test::TestPTXAssembly::TypeVector types(1, type);
		
		types.push_back(test::TestPTXAssembly::I32);
		
		return types;
	}
	else
	{
		return test::TestPTXAssembly::TypeVector(1, type);
	}
}

test::TestPTXAssembly::TypeVector testLops_OUT(
	test::TestPTXAssembly::DataType type)
{	
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST SLCT
std::string testSlct_PTX(ir::PTXOperand::DataType type,
	bool sourceFloat, bool ftz)
{
	std::stringstream ptx;

	std::string typeString = "." + ir::PTXOperand::toString(type);

	std::string cmpTypeString;
	
	if(sourceFloat)
	{
		cmpTypeString = ".f32";
	}
	else
	{
		cmpTypeString = ".s32";
	}
	
	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << typeString    << " %r<3>;          \n";
	ptx << "\t.reg " << cmpTypeString << " %rc;            \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %r0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "];              \n";
	ptx << "\tld.global" << cmpTypeString << " %rc, [%rIn + " 
		<< 2 * ir::PTXOperand::bytes(type) << "];          \n";

	ptx << "\tslct";
	if(ftz) ptx << ".ftz";
	
	ptx << typeString << cmpTypeString << " %r2, %r0, %r1, %rc; \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %r2;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, bool sourceFloat, bool ftz>
void testSlct_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	bool predicate = false;
	
	if(sourceFloat)
	{
		float value = getParameter<float>(input, 2 * sizeof(type));
	
		if(ftz)
		{
			if(issubnormal(value)) value = 0;
		}
		
		predicate = value >= 0.0f;
	}
	else
	{
		int value = getParameter<int>(input, 2 * sizeof(type));
		
		predicate = value >= 0;
	}
	
	if(predicate)
	{
		setParameter(output, 0, r0);
	}
	else
	{
		setParameter(output, 0, r1);
	}
}

test::TestPTXAssembly::TypeVector testSlct_IN(
	test::TestPTXAssembly::DataType type, bool sourceFloat)
{
	test::TestPTXAssembly::TypeVector types(2, type);
	
	if(sourceFloat)
	{
		types.push_back(test::TestPTXAssembly::FP32);
	}
	else
	{
		types.push_back(test::TestPTXAssembly::I32);
	}

	return types;
}

test::TestPTXAssembly::TypeVector testSlct_OUT(
	test::TestPTXAssembly::DataType type)
{	
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST SELP
std::string testSelP_PTX(ir::PTXOperand::DataType type)
{
	std::stringstream ptx;

	std::string typeString = "." + ir::PTXOperand::toString(type);
	
	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << typeString << " %r<3>;             \n";
	ptx << "\t.reg .b8 %b0;                                \n";
	ptx << "\t.reg .u16 %s0;                               \n";
	ptx << "\t.reg .pred %p0;                              \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %r0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %r1, [%rIn + " 
		<< ir::PTXOperand::bytes(type) << "];              \n";
	ptx << "\tld.global.u8 %b0, [%rIn + " 
		<< 2 * ir::PTXOperand::bytes(type) << "];          \n";
	ptx << "\tcvt.u16.u8 %s0, %b0;                         \n";
	ptx << "\tsetp.lt.u16 %p0, %s0, 128;                   \n";

	ptx << "\tselp" << typeString << " %r2, %r0, %r1, %p0; \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %r2;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type>
void testSelP_REF(void* output, void* input)
{
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	bool predicate = getParameter<unsigned char>(
		input, 2 * sizeof(type)) < 128;

	
	if(predicate)
	{
		setParameter(output, 0, r0);
	}
	else
	{
		setParameter(output, 0, r1);
	}
}

test::TestPTXAssembly::TypeVector testSelP_IN(
	test::TestPTXAssembly::DataType type)
{
	test::TestPTXAssembly::TypeVector types(2, type);
	
	types.push_back(test::TestPTXAssembly::I8);

	return types;
}

test::TestPTXAssembly::TypeVector testSelP_OUT(
	test::TestPTXAssembly::DataType type)
{	
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST SETP
std::string testSetP_PTX(ir::PTXOperand::DataType stype,
	ir::PTXOperand::PredicateCondition c, 
	ir::PTXInstruction::BoolOp boolOp, ir::PTXInstruction::CmpOp cmpOp,
	bool ftz, bool pq)
{
	std::stringstream ptx;

	std::string sTypeString = "." + ir::PTXOperand::toString(stype);
	
	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << sTypeString << " %rs<2>;           \n";
	ptx << "\t.reg .u16 %rh<2>;                            \n";
	ptx << "\t.reg .u8 %b0;                                \n";
	ptx << "\t.reg .u8 %rd<2>;                             \n";
	ptx << "\t.reg .u16 %s0;                               \n";
	ptx << "\t.reg .pred %p<3>;                            \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << sTypeString << " %rs0, [%rIn]; \n";
	ptx << "\tld.global" << sTypeString << " %rs1, [%rIn + " 
		<< ir::PTXOperand::bytes(stype) << "];             \n";
	ptx << "\tld.global.u8 %b0, [%rIn + " 
		<< 2 * ir::PTXOperand::bytes(stype) << "];         \n";
	ptx << "\tcvt.u16.u8 %s0, %b0;                         \n";
	ptx << "\tsetp.lt.u16 %p0, %s0, 128;                   \n";

	ptx << "\tsetp." << ir::PTXInstruction::toString(cmpOp);

	if(boolOp != ir::PTXInstruction::BoolOp_Invalid)
	{
		ptx << "." << ir::PTXInstruction::toString(boolOp);
	}
	
	if(ftz) ptx << ".ftz";
	
	ptx << sTypeString;
	
	ptx << " %p1";
	if(pq) ptx << " | %p2";

	ptx << ", %rs0, %rs1";
	
	if(boolOp != ir::PTXInstruction::BoolOp_Invalid)
	{
		ptx << ", ";
		
		if(c == ir::PTXOperand::InvPred)
		{
			ptx << "!%p0";
		}
		else
		{
			ptx << "%p0";
		}
	}
	
	ptx << ";\n";
	
	ptx << "\tselp.u16 %rh0, 1, 0, %p1;                      \n";
	ptx << "\tcvt.u8.u16 %rd0, %rh0;                         \n";
	ptx << "\tst.global.u8 [%rOut], %rd0;                    \n";
	if(pq)
	{
		ptx << "\tselp.u16   %rh1, 1, 0, %p2;                    \n";
		ptx << "\tcvt.u8.u16 %rd1, %rh1;                         \n";
		ptx << "\tst.global.u8 [%rOut + 1], %rd1;                \n";
	}
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename stype, ir::PTXOperand::PredicateCondition c, 
	ir::PTXInstruction::BoolOp boolOp, ir::PTXInstruction::CmpOp cmpOp,
	bool ftz, bool pq>
void testSetP_REF(void* output, void* input)
{
	stype r0 = getParameter<stype>(input, 0);
	stype r1 = getParameter<stype>(input, sizeof(stype));
	bool predicate = getParameter<unsigned char>(
		input, 2 * sizeof(stype)) < 128;

	if(ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
		if(issubnormal(r1)) r1 = 0.0f;
	}

	if(c == ir::PTXOperand::InvPred) predicate = !predicate;

	bool comparison = false;
	
	switch(cmpOp)
	{
	case ir::PTXInstruction::Eq:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 == r1;
		break;
	}
	case ir::PTXInstruction::Ne:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 != r1;
		break;
	}
	case ir::PTXInstruction::Lo:
	case ir::PTXInstruction::Lt:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 < r1;
		break;
	}
	case ir::PTXInstruction::Ls:
	case ir::PTXInstruction::Le:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 <= r1;
		break;
	}
	case ir::PTXInstruction::Hi:
	case ir::PTXInstruction::Gt:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 > r1;
		break;
	}
	case ir::PTXInstruction::Hs:
	case ir::PTXInstruction::Ge:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 >= r1;
		break;
	}
	case ir::PTXInstruction::Equ:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 == r1;
		break;
	}
	case ir::PTXInstruction::Neu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 != r1;
		break;
	}
	case ir::PTXInstruction::Ltu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 < r1;
		break;
	}
	case ir::PTXInstruction::Leu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 <= r1;
		break;
	}
	case ir::PTXInstruction::Gtu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 > r1;
		break;
	}
	case ir::PTXInstruction::Geu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 >= r1;
		break;
	}
	case ir::PTXInstruction::Num:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1);
		break;
	}
	case ir::PTXInstruction::Nan:
	{
		comparison = std::isnan(r0) || std::isnan(r1);
		break;
	}
	default: break;
	}

	bool inverse = !comparison;
	
	switch(boolOp)
	{
	case ir::PTXInstruction::BoolAnd:
	{
		comparison = comparison && predicate;
		inverse    = inverse    && predicate;
		break;
	}
	case ir::PTXInstruction::BoolOr:
	{
		comparison = comparison || predicate;
		inverse    = inverse    || predicate;
		break;
	}
	case ir::PTXInstruction::BoolXor:
	{
		comparison = comparison ^ predicate;
		inverse    = inverse    ^ predicate;
		break;
	}
	default: break;
	}
	
	setParameter(output, 0, comparison);
	if(pq) setParameter(output, sizeof(bool), inverse);
}

test::TestPTXAssembly::TypeVector testSetP_IN(
	test::TestPTXAssembly::DataType type)
{
	test::TestPTXAssembly::TypeVector types(2, type);
	
	types.push_back(test::TestPTXAssembly::I8);

	return types;
}

test::TestPTXAssembly::TypeVector testSetP_OUT(bool pq)
{
	if(pq)
	{
		return test::TestPTXAssembly::TypeVector(2, test::TestPTXAssembly::I8);
	}
	else
	{
		return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::I8);
	}
}
/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST SET
std::string testSet_PTX(ir::PTXOperand::DataType dtype,
	ir::PTXOperand::DataType stype, ir::PTXOperand::PredicateCondition c, 
	ir::PTXInstruction::BoolOp boolOp, ir::PTXInstruction::CmpOp cmpOp,
	bool ftz)
{
	std::stringstream ptx;

	std::string dTypeString = "." + ir::PTXOperand::toString(dtype);
	std::string sTypeString = "." + ir::PTXOperand::toString(stype);
	
	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg " << sTypeString << " %rs<2>;           \n";
	ptx << "\t.reg " << dTypeString << " %rd0;             \n";
	ptx << "\t.reg .u8 %b0;                                \n";
	ptx << "\t.reg .u16 %s0;                               \n";
	ptx << "\t.reg .pred %p0;                              \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << sTypeString << " %rs0, [%rIn]; \n";
	ptx << "\tld.global" << sTypeString << " %rs1, [%rIn + " 
		<< ir::PTXOperand::bytes(stype) << "];             \n";
	ptx << "\tld.global.u8 %b0, [%rIn + " 
		<< 2 * ir::PTXOperand::bytes(stype) << "];         \n";
	ptx << "\tcvt.u16.u8 %s0, %b0;                         \n";
	ptx << "\tsetp.lt.u16 %p0, %s0, 128;                   \n";

	ptx << "\tset." << ir::PTXInstruction::toString(cmpOp);

	if(boolOp != ir::PTXInstruction::BoolOp_Invalid)
	{
		ptx << "." << ir::PTXInstruction::toString(boolOp);
	}
	
	if(ftz) ptx << ".ftz";
	
	ptx << dTypeString << sTypeString;
	
	ptx << " %rd0, %rs0, %rs1";
	
	if(boolOp != ir::PTXInstruction::BoolOp_Invalid)
	{
		ptx << ", ";
		
		if(c == ir::PTXOperand::InvPred)
		{
			ptx << "!%p0";
		}
		else
		{
			ptx << "%p0";
		}
	}
	
	ptx << ";\n";
	
	ptx << "\tst.global" << dTypeString << " [%rOut], %rd0;\n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename dtype, typename stype, ir::PTXOperand::PredicateCondition c, 
	ir::PTXInstruction::BoolOp boolOp, ir::PTXInstruction::CmpOp cmpOp,
	bool ftz>
void testSet_REF(void* output, void* input)
{
	stype r0 = getParameter<stype>(input, 0);
	stype r1 = getParameter<stype>(input, sizeof(stype));
	bool predicate = getParameter<unsigned char>(
		input, 2 * sizeof(stype)) < 128;

	if(ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
		if(issubnormal(r1)) r1 = 0.0f;
	}

	if(c == ir::PTXOperand::InvPred) predicate = !predicate;

	bool comparison = false;
	
	switch(cmpOp)
	{
	case ir::PTXInstruction::Eq:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 == r1;
		break;
	}
	case ir::PTXInstruction::Ne:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 != r1;
		break;
	}
	case ir::PTXInstruction::Lo:
	case ir::PTXInstruction::Lt:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 < r1;
		break;
	}
	case ir::PTXInstruction::Ls:
	case ir::PTXInstruction::Le:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 <= r1;
		break;
	}
	case ir::PTXInstruction::Hi:
	case ir::PTXInstruction::Gt:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 > r1;
		break;
	}
	case ir::PTXInstruction::Hs:
	case ir::PTXInstruction::Ge:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1) && r0 >= r1;
		break;
	}
	case ir::PTXInstruction::Equ:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 == r1;
		break;
	}
	case ir::PTXInstruction::Neu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 != r1;
		break;
	}
	case ir::PTXInstruction::Ltu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 < r1;
		break;
	}
	case ir::PTXInstruction::Leu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 <= r1;
		break;
	}
	case ir::PTXInstruction::Gtu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 > r1;
		break;
	}
	case ir::PTXInstruction::Geu:
	{
		comparison = std::isnan(r0) || std::isnan(r1) || r0 >= r1;
		break;
	}
	case ir::PTXInstruction::Num:
	{
		comparison = !std::isnan(r0) && !std::isnan(r1);
		break;
	}
	case ir::PTXInstruction::Nan:
	{
		comparison = std::isnan(r0) || std::isnan(r1);
		break;
	}
	default: break;
	}
	
	switch(boolOp)
	{
	case ir::PTXInstruction::BoolAnd:
	{
		comparison = comparison && predicate;
		break;
	}
	case ir::PTXInstruction::BoolOr:
	{
		comparison = comparison || predicate;
		break;
	}
	case ir::PTXInstruction::BoolXor:
	{
		comparison = comparison ^ predicate;
		break;
	}
	default: break;
	}
	
	dtype result;
	
	if(typeid(float) == typeid(dtype))
	{
		result = comparison ? 1.0f : 0.0f;
	}
	else
	{
		result = comparison ? 0xffffffff : 0x00000000;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testSet_IN(
	test::TestPTXAssembly::DataType type)
{
	test::TestPTXAssembly::TypeVector types(2, type);
	
	types.push_back(test::TestPTXAssembly::I8);

	return types;
}

test::TestPTXAssembly::TypeVector testSet_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST Special Functions
std::string testSpecial_PTX(ir::PTXInstruction::Opcode opcode, bool ftz)
{
	std::stringstream ptx;
	
	ptx << ".version 2.1\n";
	ptx << "\n";
	
	ptx << ".entry test(.param .u64 out, .param .u64 in)   \n";
	ptx << "{\t                                            \n";
	ptx << "\t.reg .u64 %rIn, %rOut;                       \n";
	ptx << "\t.reg .f32 %f<2>;                             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global.f32 %f0, [%rIn];                   \n";

	ptx << "\t" << ir::PTXInstruction::toString(opcode) << ".approx";

	if(ftz) ptx << ".ftz";
	
	ptx << ".f32 %f1, %f0;\n";
	
	ptx << "\tst.global.f32 [%rOut], %f1;                  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<ir::PTXInstruction::Opcode opcode, bool ftz>
void testSpecial_REF(void* output, void* input)
{
	static_assert(opcode == ir::PTXInstruction::Cos
		|| opcode == ir::PTXInstruction::Sin
		|| opcode == ir::PTXInstruction::Lg2
		|| opcode == ir::PTXInstruction::Ex2, "Invalid special opcode.");

	float r0 = getParameter<float>(input, 0);

	if(ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
	}

	float result = 0.0f;

	switch(opcode)
	{
		case ir::PTXInstruction::Cos:
		{
			if(std::isinf(r0))
			{
				result = std::numeric_limits<float>::signaling_NaN();
			}
			else
			{
				result = std::cos(r0);
			}
			break;
		}
		case ir::PTXInstruction::Sin:
		{
			if(std::isinf(r0))
			{
				result = std::numeric_limits<float>::signaling_NaN();
			}
			else
			{
				result = std::sin(r0);
			}
			break;
		}
		case ir::PTXInstruction::Lg2:
		{
			if(std::isinf(r0) && std::copysign(1.0f, r0) < 0)
			{
				result = std::numeric_limits<float>::signaling_NaN();
			}
			else if(r0 == 0.0f)
			{
				result = -std::numeric_limits<float>::infinity();
			}
			else
			{
				result = std::log2f(r0);
			}
			break;
		}
		case ir::PTXInstruction::Ex2:
		{
			if(std::isinf(r0))
			{
				if(r0 < 0)
				{
					result = 0.0f;
				}
				else
				{
					result = r0;
				}
			}
			else
			{
				result = std::exp2f(r0);
			}
			break;
		}
		default: break;
	}
	
	if(ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testSpecial_INOUT()
{
	return test::TestPTXAssembly::TypeVector(1, test::TestPTXAssembly::FP32);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST RSQRT
std::string testRsqrt_PTX(ir::PTXOperand::DataType type, bool ftz)
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
	ptx << "\t.reg " << typeString << " %f<2>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";

	ptx << "\trsqrt.approx";
	
	if(ftz) ptx << ".ftz";
	
	ptx << typeString << " %f1, %f0;\n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f1;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, bool ftz>
void testRsqrt_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");

	type r0 = getParameter<type>(input, 0);

	if(ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
	}

	type result = 0;

	if(std::isinf(r0))
	{
		result = (type)0;
	}
	else
	{
		result = (type)1 / std::sqrt(r0);
	}
	
	if(ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testRsqrt_INOUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// TEST RCP/SQRT
std::string testRcpSqrt_PTX(ir::PTXOperand::DataType type, bool sqrt, 
	bool approx, bool ftz)
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
	ptx << "\t.reg " << typeString << " %f<2>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";

	if(sqrt)
	{
		ptx << "\tsqrt";
	}	
	else
	{
		ptx << "\trcp";
	}
	
	if(approx)
	{
		ptx << ".approx";
	}
	else
	{
		ptx << ".rn";
	}
	
	if(ftz) ptx << ".ftz";
	
	ptx << typeString << " %f1, %f0;\n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f1;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, bool sqrt, bool approx, bool ftz>
void testRcpSqrt_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");

	type r0 = getParameter<type>(input, 0);

	if(ftz || approx)
	{
		if(issubnormal(r0)) r0 = 0.0f;
	}

	type result = 0;

	if(sqrt)
	{
		if(r0 < (type)0)
		{
			result = std::numeric_limits<type>::signaling_NaN();
		}
		else
		{
			result = std::sqrt(r0);
		}
	}
	else
	{
		if(approx && std::isinf(r0))
		{
			result = std::copysign((type)0, r0);
		}
		else
		{
			result = (type)1 / r0;
		}
	}
	
	if(ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testRcpSqrt_INOUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}

////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST FMIN/FMAX
std::string testFMinMax_PTX(ir::PTXOperand::DataType type, bool min, bool ftz)
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
	ptx << "\t.reg " << typeString << " %f<3>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %f1, [%rIn + "
		<< ir::PTXOperand::bytes(type) << "];              \n";
	
	if(min)
	{
		ptx << "\tmin";
	}
	else
	{
		ptx << "\tmax";
	}
	
	if(ftz) ptx << ".ftz";
	
	ptx << typeString << " %f2, %f0, %f1;  \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f2;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, bool min, bool ftz>
void testFMinMax_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");
	static_assert(sizeof(type) != 8 || !ftz, "ftz only valid for f32");

	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));

	if(ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
		if(issubnormal(r1)) r1 = 0.0f;
	}

	type result = 0;

	if(std::isnan(r0))
	{	
		result = r1;
	}
	else if(std::isnan(r1))
	{
		result = r0;
	}
	else
	{
		if(min)
		{
			result = std::min(r0, r1);
		}
		else
		{
			result = std::max(r0, r1);
		}
	}
	
	if(ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testFMinMax_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testFMinMax_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST ABS/NEG
std::string testAbsNeg_PTX(ir::PTXOperand::DataType type, bool neg, bool ftz)
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
	ptx << "\t.reg " << typeString << " %f<2>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	
	if(neg)
	{
		ptx << "\tneg";
	}
	else
	{
		ptx << "\tabs";
	}
	
	if(ftz) ptx << ".ftz";
	
	ptx << typeString << " %f1, %f0;  \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f1;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, bool neg, bool ftz>
void testAbsNeg_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");
	static_assert(sizeof(type) != 8 || !ftz, "ftz only valid for f32");

	type r0 = getParameter<type>(input, 0);

	if(ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
	}

	type result = 0;
	
	if(neg)
	{
		result = -r0;
	}
	else
	{
		result = std::abs(r0);
	}
	if(ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testAbsNeg_INOUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST DIV
std::string testFdiv_PTX(ir::PTXOperand::DataType type, int modifier)
{
	bool sat = modifier & ir::PTXInstruction::sat;
	bool ftz = modifier & ir::PTXInstruction::ftz;
	std::string roundingString = ir::PTXInstruction::roundingMode(
		(ir::PTXInstruction::Modifier) modifier);
	
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
	ptx << "\t.reg " << typeString << " %f<3>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %f1, [%rIn + "
		<< ir::PTXOperand::bytes(type) << "];              \n";
	
	if(modifier & ir::PTXInstruction::approx)
	{
		ptx << "\tdiv.approx";
	}
	else if(modifier & ir::PTXInstruction::full)
	{
		ptx << "\tdiv.full";
	}
	else
	{
		ptx << "\tdiv.rn";
	}
	
	if(!roundingString.empty()) ptx << "." << roundingString;
	
	if(ftz) ptx << ".ftz";
	if(sat) ptx << ".sat";
	
	ptx << typeString << " %f2, %f0, %f1;  \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f2;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, int modifier>
void testFdiv_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");
	static_assert(sizeof(type) != 8 || !(modifier & ir::PTXInstruction::ftz),
		"ftz only valid for f32");

	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));

	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
		if(issubnormal(r1)) r1 = 0.0f;
	}

	type result = 0;
	
	if(modifier & ir::PTXInstruction::approx)
	{
		result = r0 * ( 1.0f / r1 );
	}
	else
	{
		result = r0 / r1;
	}

	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	if(modifier & ir::PTXInstruction::sat)
	{
		if(result < 0.0f) result = 0.0f;
		if(result > 1.0f) result = 1.0f;
		if(std::isnan(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testFdiv_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testFdiv_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST FMA
std::string testFma_PTX(ir::PTXOperand::DataType type, int modifier, bool mad)
{
	bool sat = modifier & ir::PTXInstruction::sat;
	bool ftz = modifier & ir::PTXInstruction::ftz;
	std::string roundingString = ir::PTXInstruction::roundingMode(
		(ir::PTXInstruction::Modifier) modifier);
	
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
	ptx << "\t.reg " << typeString << " %f<4>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %f1, [%rIn + "
		<< ir::PTXOperand::bytes(type) << "];              \n";
	ptx << "\tld.global" << typeString << " %f2, [%rIn + "
		<< 2 * ir::PTXOperand::bytes(type) << "];          \n";
	
	if(mad)
	{
		ptx << "\tmad.rn";
	}
	else
	{
		ptx << "\tfma";
	}
	
	if(!roundingString.empty()) ptx << "." << roundingString;
	
	if(ftz) ptx << ".ftz";
	if(sat) ptx << ".sat";
	
	ptx << typeString << " %f3, %f0, %f1, %f2;  \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f3;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, int modifier>
void testFma_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");
	static_assert(sizeof(type) != 8 || !(modifier & ir::PTXInstruction::sat),
		"sat only valid for f32");
	static_assert(sizeof(type) != 8 || !(modifier & ir::PTXInstruction::ftz),
		"ftz only valid for f32");

	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));
	type r2 = getParameter<type>(input, 2*sizeof(type));

	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
		if(issubnormal(r1)) r1 = 0.0f;
		if(issubnormal(r2)) r2 = 0.0f;
	}

	type result = r0 * r1 + r2;
		
	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	if(modifier & ir::PTXInstruction::sat)
	{
		if(result < 0.0f) result = 0.0f;
		if(result > 1.0f) result = 1.0f;
		if(std::isnan(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testFma_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(3, type);
}

test::TestPTXAssembly::TypeVector testFma_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST FMUL
std::string testFmul_PTX(ir::PTXOperand::DataType type, int modifier)
{
	bool sat = modifier & ir::PTXInstruction::sat;
	bool ftz = modifier & ir::PTXInstruction::ftz;
	std::string roundingString = ir::PTXInstruction::roundingMode(
		(ir::PTXInstruction::Modifier) modifier);
	
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
	ptx << "\t.reg " << typeString << " %f<3>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %f1, [%rIn + "
		<< ir::PTXOperand::bytes(type) << "];              \n";
	
	ptx << "\tmul";
	
	if(!roundingString.empty()) ptx << "." << roundingString;
	
	if(ftz) ptx << ".ftz";
	if(sat) ptx << ".sat";
	
	ptx << typeString << " %f2, %f0, %f1;  \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f2;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, int modifier>
void testFmul_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");
	static_assert(sizeof(type) != 8 || !(modifier & ir::PTXInstruction::sat),
		"sat only valid for f32");
	static_assert(sizeof(type) != 8 || !(modifier & ir::PTXInstruction::ftz),
		"ftz only valid for f32");

	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));

	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
		if(issubnormal(r1)) r1 = 0.0f;
	}


	type result = r0 * r1;
		
	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	if(modifier & ir::PTXInstruction::sat)
	{
		if(result < 0.0f) result = 0.0f;
		if(result > 1.0f) result = 1.0f;
		if(std::isnan(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testFmul_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testFmul_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST FADD
std::string testFadd_PTX(ir::PTXOperand::DataType type, int modifier, bool add)
{
	bool sat = modifier & ir::PTXInstruction::sat;
	bool ftz = modifier & ir::PTXInstruction::ftz;
	std::string roundingString = ir::PTXInstruction::roundingMode(
		(ir::PTXInstruction::Modifier) modifier);
	
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
	ptx << "\t.reg " << typeString << " %f<3>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %f1, [%rIn + "
		<< ir::PTXOperand::bytes(type) << "];              \n";
	
	if(add)
	{
		ptx << "\tadd";
	}
	else
	{
		ptx << "\tsub";
	}
	
	if(!roundingString.empty()) ptx << "." << roundingString;
	
	if(ftz) ptx << ".ftz";
	if(sat) ptx << ".sat";
	
	ptx << typeString << " %f2, %f0, %f1;  \n";
	
	ptx << "\tst.global" << typeString << " [%rOut], %f2;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type, int modifier, bool add>
void testFadd_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64 valid");
	static_assert(sizeof(type) != 8 || !(modifier & ir::PTXInstruction::sat),
		"sat only valid for f32");
	static_assert(sizeof(type) != 8 || !(modifier & ir::PTXInstruction::ftz),
		"ftz only valid for f32");

	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));

	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(r0)) r0 = 0.0f;
		if(issubnormal(r1)) r1 = 0.0f;
	}


	type result = 0;
	
	if(add)
	{
		result = r0 + r1;
	}
	else
	{
		result = r0 - r1;
	}
	
	if(modifier & ir::PTXInstruction::ftz)
	{
		if(issubnormal(result)) result = 0.0f;
	}
	
	if(modifier & ir::PTXInstruction::sat)
	{
		if(result < 0.0f) result = 0.0f;
		if(result > 1.0f) result = 1.0f;
		if(std::isnan(result)) result = 0.0f;
	}
	
	setParameter(output, 0, result);
}

test::TestPTXAssembly::TypeVector testFadd_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testFadd_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// TEST COPYSIGN
std::string testCopysign_PTX(ir::PTXOperand::DataType type)
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
	ptx << "\t.reg " << typeString << " %f<3>;             \n";
	ptx << "\tld.param.u64 %rIn, [in];                     \n";
	ptx << "\tld.param.u64 %rOut, [out];                   \n";
	ptx << "\tld.global" << typeString << " %f0, [%rIn];   \n";
	ptx << "\tld.global" << typeString << " %f1, [%rIn + "
		<< ir::PTXOperand::bytes(type) << "];              \n";
	ptx << "\tcopysign" << typeString << " %f2, %f0, %f1;  \n";
	ptx << "\tst.global" << typeString << " [%rOut], %f2;  \n";
	ptx << "\texit;                                        \n";
	ptx << "}                                              \n";
	ptx << "                                               \n";
	
	return ptx.str();
}

template<typename type>
void testCopysign_REF(void* output, void* input)
{
	static_assert(sizeof(type) == 4 || sizeof(type) == 8, "only f32/f64");
	
	type r0 = getParameter<type>(input, 0);
	type r1 = getParameter<type>(input, sizeof(type));

	if(sizeof(type) == 4)
	{
		const unsigned int bits = 31;
		const unsigned int mask = 1 << bits;
		unsigned int result = hydrazine::bit_cast<unsigned int>(r0) & mask;

		result = result | ( hydrazine::bit_cast<unsigned int>(r1) & ~mask );

		setParameter(output, 0, result);
	}
	else
	{
		const unsigned int bits = 63;
		const long long unsigned int mask = (
			(long long unsigned int) 1 << bits);
		long long unsigned int result = hydrazine::bit_cast<
			long long unsigned int>(r0) & mask;

		result = result | ( hydrazine::bit_cast<
			long long unsigned int>(r1) & ~mask );

		setParameter(output, 0, result);
	}
}

test::TestPTXAssembly::TypeVector testCopysign_IN(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(2, type);
}

test::TestPTXAssembly::TypeVector testCopysign_OUT(
	test::TestPTXAssembly::DataType type)
{
	return test::TestPTXAssembly::TypeVector(1, type);
}
////////////////////////////////////////////////////////////////////////////////

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
		condition = !std::isinf(r0) && !std::isnan(r0);
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
		condition = issubnormal(r0);
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
	static unsigned int align(unsigned int address, unsigned int bytes)
	{
		unsigned int remainder = address % bytes;
		if(remainder == 0) return address;
		return address + bytes - remainder;
	}

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
			inputSize = align(inputSize, bytes(*type));
			inputSize += bytes(*type);
		}
		
		for(TypeVector::const_iterator type = test.outputTypes.begin(); 
			type != test.outputTypes.end(); ++type)
		{
			outputSize = align(outputSize, bytes(*type));
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
			
			long long unsigned int deviceInput  = 0;
			long long unsigned int deviceOutput = 0;
						
			if(devices > 0) device = random() % devices;
			cudaSetDevice(device);
			
			cudaMalloc((void**)&deviceInput, inputSize);
			cudaMalloc((void**)&deviceOutput, outputSize);
			
			cudaMemcpy((void*)deviceInput, inputBlock, 
				inputSize, cudaMemcpyHostToDevice);
				
			cudaSetupArgument(&deviceOutput, 8, 0);
			cudaSetupArgument(&deviceInput, 8, 8);
			cudaConfigureCall( dim3( test.ctas, 1, 1 ), 
				dim3( test.threads, 1, 1 ), 0, 0 );
			ocelot::launch(test.name, "test");
			
			cudaMemcpy(outputBlock, (void*)deviceOutput, 
				outputSize, cudaMemcpyDeviceToHost);
			
			cudaFree((void*)deviceInput);
			cudaFree((void*)deviceOutput);
			
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
					if(!compareFloat(computed, reference))
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
					if(!compareDouble(computed, reference))
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

		add("TestCopysign-f32", testCopysign_REF<float>, 
			testCopysign_PTX(ir::PTXOperand::f32), testCopysign_OUT(FP32), 
			testCopysign_IN(FP32), uniformFloat<float, 2>, 1, 1);
		add("TestCopysign-f64", testCopysign_REF<double>, 
			testCopysign_PTX(ir::PTXOperand::f64), testCopysign_OUT(FP64), 
			testCopysign_IN(FP64), uniformFloat<double, 2>, 1, 1);

		add("TestAdd-f32", testFadd_REF<float, 0, true>, 
			testFadd_PTX(ir::PTXOperand::f32, 0, true), testFadd_OUT(FP32), 
			testFadd_IN(FP32), uniformFloat<float, 2>, 1, 1);
		add("TestAdd-f32-sat",
			testFadd_REF<float, ir::PTXInstruction::sat, true>, 
			testFadd_PTX(ir::PTXOperand::f32, ir::PTXInstruction::sat, true),
			testFadd_OUT(FP32), testFadd_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestAdd-f32-ftz",
			testFadd_REF<float, ir::PTXInstruction::ftz, true>, 
			testFadd_PTX(ir::PTXOperand::f32, ir::PTXInstruction::ftz, true),
			testFadd_OUT(FP32), testFadd_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestAdd-f32-ftz-sat", testFadd_REF<float, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat, true>, 
			testFadd_PTX(ir::PTXOperand::f32, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat, true),
			testFadd_OUT(FP32), testFadd_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestAdd-f64", testFadd_REF<double, 0, true>, 
			testFadd_PTX(ir::PTXOperand::f64, 0, true), testFadd_OUT(FP64), 
			testFadd_IN(FP64), uniformFloat<double, 2>, 1, 1);

		add("TestSub-f32", testFadd_REF<float, 0, false>, 
			testFadd_PTX(ir::PTXOperand::f32, 0, false), testFadd_OUT(FP32), 
			testFadd_IN(FP32), uniformFloat<float, 2>, 1, 1);
		add("TestSub-f32-sat",
			testFadd_REF<float, ir::PTXInstruction::sat, false>, 
			testFadd_PTX(ir::PTXOperand::f32, ir::PTXInstruction::sat, false),
			testFadd_OUT(FP32), testFadd_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestSub-f32-ftz",
			testFadd_REF<float, ir::PTXInstruction::ftz, false>, 
			testFadd_PTX(ir::PTXOperand::f32, ir::PTXInstruction::ftz, false),
			testFadd_OUT(FP32), testFadd_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestSub-f32-ftz-sat", testFadd_REF<float, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat, false>, 
			testFadd_PTX(ir::PTXOperand::f32, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat, false),
			testFadd_OUT(FP32), testFadd_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestSub-f64", testFadd_REF<double, 0, false>, 
			testFadd_PTX(ir::PTXOperand::f64, 0, false), testFadd_OUT(FP64), 
			testFadd_IN(FP64), uniformFloat<double, 2>, 1, 1);

		add("TestMul-f32", testFmul_REF<float, 0>, 
			testFmul_PTX(ir::PTXOperand::f32, 0), testFmul_OUT(FP32), 
			testFmul_IN(FP32), uniformFloat<float, 2>, 1, 1);
		add("TestMul-f32-sat",
			testFmul_REF<float, ir::PTXInstruction::sat>, 
			testFmul_PTX(ir::PTXOperand::f32, ir::PTXInstruction::sat),
			testFmul_OUT(FP32), testFmul_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestMul-f32-ftz",
			testFmul_REF<float, ir::PTXInstruction::ftz>, 
			testFmul_PTX(ir::PTXOperand::f32, ir::PTXInstruction::ftz),
			testFmul_OUT(FP32), testFmul_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestMul-f32-ftz-sat", testFmul_REF<float, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat>, 
			testFmul_PTX(ir::PTXOperand::f32, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat),
			testFmul_OUT(FP32), testFmul_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestMul-f64", testFmul_REF<double, 0>, 
			testFmul_PTX(ir::PTXOperand::f64, 0), testFmul_OUT(FP64), 
			testFmul_IN(FP64), uniformFloat<double, 2>, 1, 1);

		add("TestMad-f32", testFma_REF<float, 0>, 
			testFma_PTX(ir::PTXOperand::f32, 0, true), testFma_OUT(FP32), 
			testFma_IN(FP32), uniformFloat<float, 3>, 1, 1);
		add("TestMad-f32-sat",
			testFma_REF<float, ir::PTXInstruction::sat>, 
			testFma_PTX(ir::PTXOperand::f32, ir::PTXInstruction::sat, true),
			testFma_OUT(FP32), testFma_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestMad-f32-ftz",
			testFma_REF<float, ir::PTXInstruction::ftz>, 
			testFma_PTX(ir::PTXOperand::f32, ir::PTXInstruction::ftz, true),
			testFma_OUT(FP32), testFma_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestMad-f32-ftz-sat", testFma_REF<float, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat>, 
			testFma_PTX(ir::PTXOperand::f32, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat, true),
			testFma_OUT(FP32), testFma_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestMad-f64", testFma_REF<double, 0>, 
			testFma_PTX(ir::PTXOperand::f64, 0, true), testFma_OUT(FP64), 
			testFma_IN(FP64), uniformFloat<double, 3>, 1, 1);

		add("TestFma-f32", testFma_REF<float, 0>, 
			testFma_PTX(ir::PTXOperand::f32, 0, false), testFma_OUT(FP32), 
			testFma_IN(FP32), uniformFloat<float, 3>, 1, 1);
		add("TestFma-f32-sat",
			testFma_REF<float, ir::PTXInstruction::sat>, 
			testFma_PTX(ir::PTXOperand::f32, ir::PTXInstruction::sat, false),
			testFma_OUT(FP32), testFma_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestFma-f32-ftz",
			testFma_REF<float, ir::PTXInstruction::ftz>, 
			testFma_PTX(ir::PTXOperand::f32, ir::PTXInstruction::ftz, false),
			testFma_OUT(FP32), testFma_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestFma-f32-ftz-sat", testFma_REF<float, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat>, 
			testFma_PTX(ir::PTXOperand::f32, 
			ir::PTXInstruction::ftz | ir::PTXInstruction::sat, false),
			testFma_OUT(FP32), testFma_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestFma-f64", testFma_REF<double, 0>, 
			testFma_PTX(ir::PTXOperand::f64, 0, false), testFma_OUT(FP64), 
			testFma_IN(FP64), uniformFloat<double, 3>, 1, 1);

		add("TestDiv-f32", testFdiv_REF<float, 0>,
			testFdiv_PTX(ir::PTXOperand::f32, 0), testFdiv_OUT(FP32), 
			testFdiv_IN(FP32), uniformFloat<float, 2>, 1, 1);
		add("TestDiv-f32-ftz", testFdiv_REF<float, ir::PTXInstruction::ftz>,
			testFdiv_PTX(ir::PTXOperand::f32, ir::PTXInstruction::ftz), 
			testFdiv_OUT(FP32), testFdiv_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestDiv-f32-approx",
			testFdiv_REF<float, ir::PTXInstruction::approx>,
			testFdiv_PTX(ir::PTXOperand::f32, ir::PTXInstruction::approx), 
			testFdiv_OUT(FP32), testFdiv_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestDiv-f32-full", testFdiv_REF<float, ir::PTXInstruction::full>,
			testFdiv_PTX(ir::PTXOperand::f32, ir::PTXInstruction::full), 
			testFdiv_OUT(FP32), testFdiv_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestDiv-f32-approx-ftz",
			testFdiv_REF<float,
				ir::PTXInstruction::approx | ir::PTXInstruction::ftz>,
			testFdiv_PTX(ir::PTXOperand::f32,
				ir::PTXInstruction::approx | ir::PTXInstruction::ftz), 
			testFdiv_OUT(FP32), testFdiv_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestDiv-f32-full-ftz", 
			testFdiv_REF<float,
				ir::PTXInstruction::full | ir::PTXInstruction::ftz>,
			testFdiv_PTX(ir::PTXOperand::f32,
				ir::PTXInstruction::full | ir::PTXInstruction::ftz), 
			testFdiv_OUT(FP32), testFdiv_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestDiv-f64", testFdiv_REF<double, 0>,
			testFdiv_PTX(ir::PTXOperand::f64, 0), testFdiv_OUT(FP64), 
			testFdiv_IN(FP64), uniformFloat<double, 2>, 1, 1);

		add("TestAbs-f32", testAbsNeg_REF<float, false, false>,
			testAbsNeg_PTX(ir::PTXOperand::f32, false, false),
			testAbsNeg_INOUT(FP32), testAbsNeg_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestAbs-f32-ftz", testAbsNeg_REF<float, false, true>,
			testAbsNeg_PTX(ir::PTXOperand::f32, false, true),
			testAbsNeg_INOUT(FP32), testAbsNeg_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestAbs-f64", testAbsNeg_REF<double, false, false>,
			testAbsNeg_PTX(ir::PTXOperand::f64, false, false),
			testAbsNeg_INOUT(FP64), testAbsNeg_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestNeg-f32", testAbsNeg_REF<float, true, false>,
			testAbsNeg_PTX(ir::PTXOperand::f32, true, false),
			testAbsNeg_INOUT(FP32), testAbsNeg_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestNeg-f32-ftz", testAbsNeg_REF<float, true, true>,
			testAbsNeg_PTX(ir::PTXOperand::f32, true, true),
			testAbsNeg_INOUT(FP32), testAbsNeg_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestNeg-f64", testAbsNeg_REF<double, true, false>,
			testAbsNeg_PTX(ir::PTXOperand::f64, true, false),
			testAbsNeg_INOUT(FP64), testAbsNeg_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);
			
		add("TestMin-f32", testFMinMax_REF<float, true, false>,
			testFMinMax_PTX(ir::PTXOperand::f32, true, false),
			testFMinMax_OUT(FP32), testFMinMax_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestMin-f32-ftz", testFMinMax_REF<float, true, true>,
			testFMinMax_PTX(ir::PTXOperand::f32, true, true),
			testFMinMax_OUT(FP32), testFMinMax_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestMin-f64", testFMinMax_REF<double, true, false>,
			testFMinMax_PTX(ir::PTXOperand::f64, true, false),
			testFMinMax_OUT(FP64), testFMinMax_IN(FP64),
			uniformFloat<double, 2>, 1, 1);
			
		add("TestMax-f32", testFMinMax_REF<float, false, false>,
			testFMinMax_PTX(ir::PTXOperand::f32, false, false),
			testFMinMax_OUT(FP32), testFMinMax_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestMax-f32-ftz", testFMinMax_REF<float, false, true>,
			testFMinMax_PTX(ir::PTXOperand::f32, false, true),
			testFMinMax_OUT(FP32), testFMinMax_IN(FP32),
			uniformFloat<float, 2>, 1, 1);
		add("TestMax-f64", testFMinMax_REF<double, false, false>,
			testFMinMax_PTX(ir::PTXOperand::f64, false, false),
			testFMinMax_OUT(FP64), testFMinMax_IN(FP64),
			uniformFloat<double, 2>, 1, 1);

		add("TestRcp-f32", testRcpSqrt_REF<float, false, false, false>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, false, false, false),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestRcp-f32-approx", testRcpSqrt_REF<float, false, true, false>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, false, true, false),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestRcp-f32-ftz", testRcpSqrt_REF<float, false, false, true>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, false, false, true),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestRcp-f32-approx-ftz", testRcpSqrt_REF<float, false, true, true>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, false, true, true),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestRcp-f64", testRcpSqrt_REF<double, false, false, false>,
			testRcpSqrt_PTX(ir::PTXOperand::f64, false, false, false),
			testRcpSqrt_INOUT(FP64), testRcpSqrt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);
		add("TestRcp-f64-approx-ftz",
			testRcpSqrt_REF<double, false, true, true>,
			testRcpSqrt_PTX(ir::PTXOperand::f64, false, true, true),
			testRcpSqrt_INOUT(FP64), testRcpSqrt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestSqrt-f32", testRcpSqrt_REF<float, true, false, false>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, true, false, false),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestSqrt-f32-approx", testRcpSqrt_REF<float, true, true, false>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, true, true, false),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestSqrt-f32-ftz", testRcpSqrt_REF<float, true, false, true>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, true, false, true),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestSqrt-f32-approx-ftz", testRcpSqrt_REF<float, true, true, true>,
			testRcpSqrt_PTX(ir::PTXOperand::f32, true, true, true),
			testRcpSqrt_INOUT(FP32), testRcpSqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestSqrt-f64", testRcpSqrt_REF<double, true, false, false>,
			testRcpSqrt_PTX(ir::PTXOperand::f64, true, false, false),
			testRcpSqrt_INOUT(FP64), testRcpSqrt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestRsqrt-f32", testRsqrt_REF<float, false>,
			testRsqrt_PTX(ir::PTXOperand::f32, false),
			testRsqrt_INOUT(FP32), testRsqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestRsqrt-f32-ftz", testRsqrt_REF<float, true>,
			testRsqrt_PTX(ir::PTXOperand::f32, true),
			testRsqrt_INOUT(FP32), testRsqrt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestRsqrt-f64", testRsqrt_REF<double, false>,
			testRsqrt_PTX(ir::PTXOperand::f64, false),
			testRsqrt_INOUT(FP64), testRsqrt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCos-f32",
			testSpecial_REF<ir::PTXInstruction::Cos, false>,
			testSpecial_PTX(ir::PTXInstruction::Cos, false),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);
		add("TestCos-f32-ftz",
			testSpecial_REF<ir::PTXInstruction::Cos, true>,
			testSpecial_PTX(ir::PTXInstruction::Cos, true),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);

		add("TestSin-f32",
			testSpecial_REF<ir::PTXInstruction::Sin, false>,
			testSpecial_PTX(ir::PTXInstruction::Sin, false),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);
		add("TestSin-f32-ftz",
			testSpecial_REF<ir::PTXInstruction::Sin, true>,
			testSpecial_PTX(ir::PTXInstruction::Sin, true),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);

		add("TestEx2-f32",
			testSpecial_REF<ir::PTXInstruction::Ex2, false>,
			testSpecial_PTX(ir::PTXInstruction::Ex2, false),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);
		add("TestEx2-f32-ftz",
			testSpecial_REF<ir::PTXInstruction::Ex2, true>,
			testSpecial_PTX(ir::PTXInstruction::Ex2, true),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);

		add("TestLg2-f32",
			testSpecial_REF<ir::PTXInstruction::Lg2, false>,
			testSpecial_PTX(ir::PTXInstruction::Lg2, false),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);
		add("TestLg2-f32-ftz",
			testSpecial_REF<ir::PTXInstruction::Lg2, true>,
			testSpecial_PTX(ir::PTXInstruction::Lg2, true),
			testSpecial_INOUT(), testSpecial_INOUT(),
			uniformFloat<float, 1>, 1, 1);

		add("TestSet-lt-u32-u16",
			testSet_REF<unsigned int, unsigned short, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::u32, ir::PTXOperand::u16, 
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I16),
			uniformRandom<char, 2*sizeof(unsigned short) + sizeof(bool)>, 1, 1);
		add("TestSet-lt-s32-u16",
			testSet_REF<int, unsigned short, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::u16, 
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I16),
			uniformRandom<char, 2*sizeof(unsigned short) + sizeof(bool)>, 1, 1);
		add("TestSet-lt-f32-u16",
			testSet_REF<float, unsigned short, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::f32, ir::PTXOperand::u16, 
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(FP32), testSet_IN(I16),
			uniformRandom<char, 2*sizeof(unsigned short) + sizeof(bool)>, 1, 1);
		add("TestSet-lt-s32-u32",
			testSet_REF<int, unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::u32, 
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSet-lt-s32-u64",
			testSet_REF<int, long long unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::u64,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I64),
			uniformRandom<char, 2*sizeof(long long unsigned int)
				+ sizeof(bool)>, 1, 1);
		add("TestSet-lt-s32-s16",
			testSet_REF<int, short, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s16,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I16),
			uniformRandom<char, 2*sizeof(short) + sizeof(bool)>, 1, 1);
		add("TestSet-lt-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-lt-s32-s64",
			testSet_REF<int, long long int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s64,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I64),
			uniformRandom<char, 2*sizeof(long long int) + sizeof(bool)>, 1, 1);
		add("TestSet-lt-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(FP32), uniformFloat<float, 3>, 1, 1);
		add("TestSet-lt-s32-f64",
			testSet_REF<int, double, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f64,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(FP64), uniformFloat<double, 3>, 1, 1);
		add("TestSet-lt-ftz-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				true>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, true),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);

		add("TestSet-Eq-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Eq,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Eq, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Ne-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Ne,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Ne, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Le-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Le,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Le, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Gt-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Gt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Gt, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Ge-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Ge,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Ge, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Lo-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lo,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lo, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Ls-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Ls,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Ls, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Hi-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Hi,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Hi, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Hs-s32-s32",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Hs,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Hs, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);

		add("TestSet-Eq-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Eq,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Eq, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Ne-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Ne,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Ne, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Lt-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Le-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Le,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Le, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Gt-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Gt,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Gt, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Ge-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Ge,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Ge, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Lo-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lo,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Lo, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Ls-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Ls,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Ls, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Hi-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Hi,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Hi, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Hs-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Hs,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Hs, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Equ-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Equ,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Equ, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Neu-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Neu,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Neu, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Ltu-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Ltu,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Ltu, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Leu-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Leu,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Leu, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Gtu-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Gtu,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Gtu, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Geu-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Geu,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Geu, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Num-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Num,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Num, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);
		add("TestSet-Nan-s32-f32",
			testSet_REF<int, float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Nan,
				false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::f32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOp_Invalid,
				ir::PTXInstruction::Nan, false),
			testSet_OUT(I32), testSet_IN(FP32),
			uniformFloat<float, 3>, 1, 1);

		add("TestSet-Lt-s32-s32-And",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolAnd, ir::PTXInstruction::Lt, false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolAnd,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Lt-s32-s32-Or",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOr, ir::PTXInstruction::Lt, false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolOr,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Lt-s32-s32-Xor",
			testSet_REF<int, int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolXor, ir::PTXInstruction::Lt, false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::Pred, ir::PTXInstruction::BoolXor,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSet-Lt-s32-s32-And-Inv",
			testSet_REF<int, int, ir::PTXOperand::InvPred, 
				ir::PTXInstruction::BoolAnd, ir::PTXInstruction::Lt, false>,
			testSet_PTX(ir::PTXOperand::s32, ir::PTXOperand::s32,
				ir::PTXOperand::InvPred, ir::PTXInstruction::BoolAnd,
				ir::PTXInstruction::Lt, false),
			testSet_OUT(I32), testSet_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);

		add("TestSetP-lt-u16",
			testSetP_REF<unsigned short, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::u16, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(I16),
			uniformRandom<char, 2*sizeof(unsigned short) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-u32",
			testSetP_REF<unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::u32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(I32),
			uniformRandom<char, 2*sizeof(unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-u32-pq",
			testSetP_REF<unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, true>,
			testSetP_PTX(ir::PTXOperand::u32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, true),
			testSetP_OUT(true), testSetP_IN(I32),
			uniformRandom<char, 2*sizeof(unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-u64",
			testSetP_REF<long long unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::u64, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(I64),
			uniformRandom<char,
				2*sizeof(long long unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-s16",
			testSetP_REF<short, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::s16, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(I16),
			uniformRandom<char, 2*sizeof(short) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-s32",
			testSetP_REF<int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::s32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(I32),
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-s64",
			testSetP_REF<long long int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::s64, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(I64),
			uniformRandom<char, 2*sizeof(long long int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-f32",
			testSetP_REF<float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::f32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(FP32),
			uniformRandom<char, 2*sizeof(float) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-f64",
			testSetP_REF<double, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, ir::PTXInstruction::Lt,
				false, false>,
			testSetP_PTX(ir::PTXOperand::f64, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOp_Invalid, 
				ir::PTXInstruction::Lt, false, false),
			testSetP_OUT(false), testSetP_IN(FP64),
			uniformRandom<char, 2*sizeof(double) + sizeof(bool)>, 1, 1);
		
		add("TestSetP-lt-u32-pq-and",
			testSetP_REF<unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolAnd, ir::PTXInstruction::Lt,
				false, true>,
			testSetP_PTX(ir::PTXOperand::u32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolAnd, 
				ir::PTXInstruction::Lt, false, true),
			testSetP_OUT(true), testSetP_IN(I32),
			uniformRandom<char, 2*sizeof(unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-u32-pq-or",
			testSetP_REF<unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOr, ir::PTXInstruction::Lt,
				false, true>,
			testSetP_PTX(ir::PTXOperand::u32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolOr, 
				ir::PTXInstruction::Lt, false, true),
			testSetP_OUT(true), testSetP_IN(I32),
			uniformRandom<char, 2*sizeof(unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-u32-pq-xor",
			testSetP_REF<unsigned int, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolXor, ir::PTXInstruction::Lt,
				false, true>,
			testSetP_PTX(ir::PTXOperand::u32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolXor, 
				ir::PTXInstruction::Lt, false, true),
			testSetP_OUT(true), testSetP_IN(I32),
			uniformRandom<char, 2*sizeof(unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSetP-lt-f32-pq-and-ftz",
			testSetP_REF<float, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolAnd, ir::PTXInstruction::Lt,
				true, true>,
			testSetP_PTX(ir::PTXOperand::f32, ir::PTXOperand::Pred, 
				ir::PTXInstruction::BoolAnd, 
				ir::PTXInstruction::Lt, true, true),
			testSetP_OUT(true), testSetP_IN(FP32),
			uniformRandom<char, 2*sizeof(float) + sizeof(bool)>, 1, 1);
		
		add("TestSelp-u16", testSelP_REF<unsigned short>, 
			testSelP_PTX(ir::PTXOperand::u16), 
			testSelP_OUT(I16), testSelP_IN(I16), 
			uniformRandom<char, 2*sizeof(unsigned short) + sizeof(bool)>, 1, 1);
		add("TestSelp-u32", testSelP_REF<unsigned int>, 
			testSelP_PTX(ir::PTXOperand::u32), 
			testSelP_OUT(I32), testSelP_IN(I32), 
			uniformRandom<char, 2*sizeof(unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSelp-u64", testSelP_REF<long long unsigned int>, 
			testSelP_PTX(ir::PTXOperand::u64), 
			testSelP_OUT(I64), testSelP_IN(I64), 
			uniformRandom<char,
				2*sizeof(long long unsigned int) + sizeof(bool)>, 1, 1);
		add("TestSelp-s16", testSelP_REF<short>, 
			testSelP_PTX(ir::PTXOperand::s16), 
			testSelP_OUT(I16), testSelP_IN(I16), 
			uniformRandom<char, 2*sizeof(short) + sizeof(bool)>, 1, 1);
		add("TestSelp-s32", testSelP_REF<int>, 
			testSelP_PTX(ir::PTXOperand::u32), 
			testSelP_OUT(I32), testSelP_IN(I32), 
			uniformRandom<char, 2*sizeof(int) + sizeof(bool)>, 1, 1);
		add("TestSelp-s64", testSelP_REF<long long int>, 
			testSelP_PTX(ir::PTXOperand::u64), 
			testSelP_OUT(I64), testSelP_IN(I64), 
			uniformRandom<char, 2*sizeof(long long int) + sizeof(bool)>, 1, 1);
		add("TestSelp-f32", testSelP_REF<float>, 
			testSelP_PTX(ir::PTXOperand::f32), 
			testSelP_OUT(FP32), testSelP_IN(FP32), 
			uniformFloat<float, 3>, 1, 1);
		add("TestSelp-f64", testSelP_REF<double>, 
			testSelP_PTX(ir::PTXOperand::u64), 
			testSelP_OUT(I64), testSelP_IN(I64), 
			uniformFloat<double, 3>, 1, 1);
		
		add("TestSlct-u16-s32", testSlct_REF<unsigned short, false, false>,
			testSlct_PTX(ir::PTXOperand::u16, false, false),
			testSlct_OUT(I16), testSlct_IN(I16, false),
			uniformRandom<char, 2*sizeof(unsigned short)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-u32-s32", testSlct_REF<unsigned int, false, false>,
			testSlct_PTX(ir::PTXOperand::u32, false, false),
			testSlct_OUT(I32), testSlct_IN(I32, false),
			uniformRandom<char, 2*sizeof(unsigned int)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-u64-s32", 
			testSlct_REF<long long unsigned int, false, false>,
			testSlct_PTX(ir::PTXOperand::u64, false, false),
			testSlct_OUT(I64), testSlct_IN(I64, false),
			uniformRandom<char, 2*sizeof(long long unsigned int)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-s16-s32", testSlct_REF<short, false, false>,
			testSlct_PTX(ir::PTXOperand::s16, false, false),
			testSlct_OUT(I16), testSlct_IN(I16, false),
			uniformRandom<char, 2*sizeof(short)	+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-s32-s32", testSlct_REF<int, false, false>,
			testSlct_PTX(ir::PTXOperand::u32, false, false),
			testSlct_OUT(I32), testSlct_IN(I32, false),
			uniformRandom<char, 2*sizeof(int) + sizeof(unsigned int)>, 1, 1);
		add("TestSlct-s64-s32", 
			testSlct_REF<long long int, false, false>,
			testSlct_PTX(ir::PTXOperand::s64, false, false),
			testSlct_OUT(I64), testSlct_IN(I64, false),
			uniformRandom<char, 2*sizeof(long long int)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-f32-s32", testSlct_REF<float, false, false>,
			testSlct_PTX(ir::PTXOperand::f32, false, false),
			testSlct_OUT(FP32), testSlct_IN(FP32, false),
			uniformFloat<float, 3>, 1, 1);
		add("TestSlct-f64-s32", testSlct_REF<double, false, false>,
			testSlct_PTX(ir::PTXOperand::f64, false, false),
			testSlct_OUT(FP64), testSlct_IN(FP64, false),
			uniformFloat<double, 3>, 1, 1);

		
		add("TestSlct-u16-f32", testSlct_REF<unsigned short, true, false>,
			testSlct_PTX(ir::PTXOperand::u16, true, false),
			testSlct_OUT(I16), testSlct_IN(I16, true),
			uniformRandom<char, 2*sizeof(unsigned short)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-u32-f32", testSlct_REF<unsigned int, true, false>,
			testSlct_PTX(ir::PTXOperand::u32, true, false),
			testSlct_OUT(I32), testSlct_IN(I32, true),
			uniformRandom<char, 2*sizeof(unsigned int)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-u64-f32", 
			testSlct_REF<long long unsigned int, true, false>,
			testSlct_PTX(ir::PTXOperand::u64, true, false),
			testSlct_OUT(I64), testSlct_IN(I64, true),
			uniformRandom<char, 2*sizeof(long long unsigned int)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-s16-f32", testSlct_REF<short, true, false>,
			testSlct_PTX(ir::PTXOperand::s16, true, false),
			testSlct_OUT(I16), testSlct_IN(I16, true),
			uniformRandom<char, 2*sizeof(short)	+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-s32-f32", testSlct_REF<int, true, false>,
			testSlct_PTX(ir::PTXOperand::u32, true, false),
			testSlct_OUT(I32), testSlct_IN(I32, true),
			uniformRandom<char, 2*sizeof(int) + sizeof(unsigned int)>, 1, 1);
		add("TestSlct-s64-f32", 
			testSlct_REF<long long int, true, false>,
			testSlct_PTX(ir::PTXOperand::s64, true, false),
			testSlct_OUT(I64), testSlct_IN(I64, true),
			uniformRandom<char, 2*sizeof(long long int)
				+ sizeof(unsigned int)>, 1, 1);
		add("TestSlct-f32-f32", testSlct_REF<float, true, false>,
			testSlct_PTX(ir::PTXOperand::f32, true, false),
			testSlct_OUT(FP32), testSlct_IN(FP32, true),
			uniformFloat<float, 3>, 1, 1);
		add("TestSlct-f64-f32", testSlct_REF<double, true, false>,
			testSlct_PTX(ir::PTXOperand::f64, true, false),
			testSlct_OUT(FP64), testSlct_IN(FP64, true),
			uniformFloat<double, 3>, 1, 1);
		add("TestSlct-f32-f32-ftz", testSlct_REF<float, true, true>,
			testSlct_PTX(ir::PTXOperand::f32, true, true),
			testSlct_OUT(FP32), testSlct_IN(FP32, true),
			uniformFloat<float, 3>, 1, 1);

		add("TestAnd-pred", testLops_REF<ir::PTXInstruction::And, bool>,
			testLops_PTX(ir::PTXInstruction::And, ir::PTXOperand::pred),
			testLops_OUT(I8), testLops_IN(ir::PTXInstruction::And, I8),
			uniformRandom<bool, 3>, 1, 1);
		add("TestAnd-b16",
			testLops_REF<ir::PTXInstruction::And, unsigned short>,
			testLops_PTX(ir::PTXInstruction::And, ir::PTXOperand::b16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::And, I16),
			uniformRandom<unsigned short, 3>, 1, 1);
		add("TestAnd-b32",
			testLops_REF<ir::PTXInstruction::And, unsigned int>,
			testLops_PTX(ir::PTXInstruction::And, ir::PTXOperand::b32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::And, I32),
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestAnd-b64",
			testLops_REF<ir::PTXInstruction::And, long long unsigned int>,
			testLops_PTX(ir::PTXInstruction::And, ir::PTXOperand::b64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::And, I64),
			uniformRandom<long long unsigned int, 3>, 1, 1);
		add("TestOr-pred", testLops_REF<ir::PTXInstruction::Or, bool>,
			testLops_PTX(ir::PTXInstruction::Or, ir::PTXOperand::pred),
			testLops_OUT(I8), testLops_IN(ir::PTXInstruction::Or, I8),
			uniformRandom<bool, 3>, 1, 1);
		add("TestOr-b16",
			testLops_REF<ir::PTXInstruction::Or, unsigned short>,
			testLops_PTX(ir::PTXInstruction::Or, ir::PTXOperand::b16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::Or, I16),
			uniformRandom<unsigned short, 3>, 1, 1);
		add("TestOr-b32",
			testLops_REF<ir::PTXInstruction::Or, unsigned int>,
			testLops_PTX(ir::PTXInstruction::Or, ir::PTXOperand::b32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::Or, I32),
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestOr-b64",
			testLops_REF<ir::PTXInstruction::Or, long long unsigned int>,
			testLops_PTX(ir::PTXInstruction::Or, ir::PTXOperand::b64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::Or, I64),
			uniformRandom<long long unsigned int, 3>, 1, 1);
		add("TestXor-pred", testLops_REF<ir::PTXInstruction::Xor, bool>,
			testLops_PTX(ir::PTXInstruction::Xor, ir::PTXOperand::pred),
			testLops_OUT(I8), testLops_IN(ir::PTXInstruction::Xor, I8),
			uniformRandom<bool, 3>, 1, 1);
		add("TestXor-b16",
			testLops_REF<ir::PTXInstruction::Xor, unsigned short>,
			testLops_PTX(ir::PTXInstruction::Xor, ir::PTXOperand::b16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::Xor, I16),
			uniformRandom<unsigned short, 3>, 1, 1);
		add("TestXor-b32",
			testLops_REF<ir::PTXInstruction::Xor, unsigned int>,
			testLops_PTX(ir::PTXInstruction::Xor, ir::PTXOperand::b32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::Xor, I32),
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestXor-b64",
			testLops_REF<ir::PTXInstruction::Xor, long long unsigned int>,
			testLops_PTX(ir::PTXInstruction::Xor, ir::PTXOperand::b64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::Xor, I64),
			uniformRandom<long long unsigned int, 3>, 1, 1);
		add("TestNot-pred", testLops_REF<ir::PTXInstruction::Not, bool>,
			testLops_PTX(ir::PTXInstruction::Not, ir::PTXOperand::pred),
			testLops_OUT(I8), testLops_IN(ir::PTXInstruction::Not, I8),
			uniformRandom<bool, 2>, 1, 1);
		add("TestNot-b16",
			testLops_REF<ir::PTXInstruction::Not, unsigned short>,
			testLops_PTX(ir::PTXInstruction::Not, ir::PTXOperand::b16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::Not, I16),
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestNot-b32", testLops_REF<ir::PTXInstruction::Not, unsigned int>,
			testLops_PTX(ir::PTXInstruction::Not, ir::PTXOperand::b32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::Not, I32),
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestNot-b64",
			testLops_REF<ir::PTXInstruction::Not, long long unsigned int>,
			testLops_PTX(ir::PTXInstruction::Not, ir::PTXOperand::b64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::Not, I64),
			uniformRandom<long long unsigned int, 2>, 1, 1);
		add("TestCNot-b16",
			testLops_REF<ir::PTXInstruction::CNot, unsigned short>,
			testLops_PTX(ir::PTXInstruction::CNot, ir::PTXOperand::b16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::CNot, I16),
			uniformRandom<unsigned short, 2>, 1, 1);
		add("TestCNot-b32", testLops_REF<ir::PTXInstruction::CNot, unsigned int>,
			testLops_PTX(ir::PTXInstruction::CNot, ir::PTXOperand::b32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::CNot, I32),
			uniformRandom<unsigned int, 2>, 1, 1);
		add("TestCNot-b64",
			testLops_REF<ir::PTXInstruction::CNot, long long unsigned int>,
			testLops_PTX(ir::PTXInstruction::CNot, ir::PTXOperand::b64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::CNot, I64),
			uniformRandom<long long unsigned int, 2>, 1, 1);

		add("TestShl-b16",
			testLops_REF<ir::PTXInstruction::Shl, unsigned short>,
			testLops_PTX(ir::PTXInstruction::Shl, ir::PTXOperand::b16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::Shl, I16),
			uniformRandom<unsigned short, 4>, 1, 1);
		add("TestShl-b32", testLops_REF<ir::PTXInstruction::Shl, unsigned int>,
			testLops_PTX(ir::PTXInstruction::Shl, ir::PTXOperand::b32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::Shl, I32),
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestShl-b64",
			testLops_REF<ir::PTXInstruction::Shl, long long unsigned int>,
			testLops_PTX(ir::PTXInstruction::Shl, ir::PTXOperand::b64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::Shl, I64),
			uniformRandom<long long unsigned int, 3>, 1, 1);

		add("TestShr-u16",
			testLops_REF<ir::PTXInstruction::Shr, unsigned short>,
			testLops_PTX(ir::PTXInstruction::Shr, ir::PTXOperand::u16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::Shr, I16),
			uniformRandom<unsigned short, 4>, 1, 1);
		add("TestShr-u32", testLops_REF<ir::PTXInstruction::Shr, unsigned int>,
			testLops_PTX(ir::PTXInstruction::Shr, ir::PTXOperand::u32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::Shr, I32),
			uniformRandom<unsigned int, 3>, 1, 1);
		add("TestShr-u64",
			testLops_REF<ir::PTXInstruction::Shr, long long unsigned int>,
			testLops_PTX(ir::PTXInstruction::Shr, ir::PTXOperand::u64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::Shr, I64),
			uniformRandom<long long unsigned int, 3>, 1, 1);
		add("TestShr-s16",
			testLops_REF<ir::PTXInstruction::Shr, short>,
			testLops_PTX(ir::PTXInstruction::Shr, ir::PTXOperand::s16),
			testLops_OUT(I16), testLops_IN(ir::PTXInstruction::Shr, I16),
			uniformRandom<short, 4>, 1, 1);
		add("TestShr-s32", testLops_REF<ir::PTXInstruction::Shr, int>,
			testLops_PTX(ir::PTXInstruction::Shr, ir::PTXOperand::s32),
			testLops_OUT(I32), testLops_IN(ir::PTXInstruction::Shr, I32),
			uniformRandom<int, 3>, 1, 1);
		add("TestShr-s64",
			testLops_REF<ir::PTXInstruction::Shr, long long int>,
			testLops_PTX(ir::PTXInstruction::Shr, ir::PTXOperand::s64),
			testLops_OUT(I64), testLops_IN(ir::PTXInstruction::Shr, I64),
			uniformRandom<long long int, 3>, 1, 1);

		add("TestMov-pred", testMov_REF<bool>,
			testMov_PTX(ir::PTXOperand::pred), testMov_INOUT(I8),
			testMov_INOUT(I8), uniformRandom<bool, 1>, 1, 1);
		add("TestMov-u16", testMov_REF<unsigned short>,
			testMov_PTX(ir::PTXOperand::u16), testMov_INOUT(I16),
			testMov_INOUT(I16), uniformRandom<unsigned short, 1>, 1, 1);
		add("TestMov-u32", testMov_REF<unsigned int>,
			testMov_PTX(ir::PTXOperand::u32), testMov_INOUT(I32),
			testMov_INOUT(I32), uniformRandom<unsigned short, 1>, 1, 1);
		add("TestMov-u64", testMov_REF<long long unsigned int>,
			testMov_PTX(ir::PTXOperand::u64), testMov_INOUT(I64),
			testMov_INOUT(I64), uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestMov-s16", testMov_REF<short>,
			testMov_PTX(ir::PTXOperand::s16), testMov_INOUT(I16),
			testMov_INOUT(I16), uniformRandom<short, 1>, 1, 1);
		add("TestMov-s32", testMov_REF<int>,
			testMov_PTX(ir::PTXOperand::s32), testMov_INOUT(I32),
			testMov_INOUT(I32), uniformRandom<int, 1>, 1, 1);
		add("TestMov-s64", testMov_REF<long long int>,
			testMov_PTX(ir::PTXOperand::s64), testMov_INOUT(I64),
			testMov_INOUT(I64), uniformRandom<long long int, 1>, 1, 1);
		add("TestMov-f32", testMov_REF<int>,
			testMov_PTX(ir::PTXOperand::f32), testMov_INOUT(FP32),
			testMov_INOUT(FP32), uniformFloat<float, 1>, 1, 1);
		add("TestMov-f64", testMov_REF<long long int>,
			testMov_PTX(ir::PTXOperand::f64), testMov_INOUT(FP64),
			testMov_INOUT(FP64), uniformFloat<double, 1>, 1, 1);

		add("TestMovLabel-global-v1", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Global,
				false, ir::PTXOperand::v1), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-global-v1-index", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Global,
				true, ir::PTXOperand::v1), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-global-v2", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Global,
				false, ir::PTXOperand::v2), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-global-v4", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Global,
				false, ir::PTXOperand::v4), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-local-v1", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Local,
				false, ir::PTXOperand::v1), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-local-v1-index", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Local,
				true, ir::PTXOperand::v1), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-local-v2", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Local,
				false, ir::PTXOperand::v2), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-local-v4", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Local,
				false, ir::PTXOperand::v4), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-param-v1", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Param,
				false, ir::PTXOperand::v1), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-param-v1-index", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Param,
				true, ir::PTXOperand::v1),
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-param-v2", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Param,
				false, ir::PTXOperand::v2), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-param-v4", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Param,
				false, ir::PTXOperand::v4), 
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-shared-v1", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Shared,
				false, ir::PTXOperand::v1),
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-shared-v1-index", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Shared,
				true, ir::PTXOperand::v1),
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestMovLabel-shared-v4", testMovLabel_REF,
			testMovLabel_PTX(ir::PTXInstruction::Shared,
				false, ir::PTXOperand::v4),
			testMovLabel_INOUT(), testMovLabel_INOUT(),
			uniformRandom<unsigned int, 1>, 1, 1);

		add("TestCvt-u8-u8",
			testCvt_REF<unsigned char, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-u8-u16",
			testCvt_REF<unsigned char, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-u8-u32",
			testCvt_REF<unsigned char, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-u8-u64",
			testCvt_REF<unsigned char, long long unsigned int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-u8-s8",
			testCvt_REF<unsigned char, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-u8-s16",
			testCvt_REF<unsigned char, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-u8-s32",
			testCvt_REF<unsigned char, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-u8-s64",
			testCvt_REF<unsigned char, long long int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-u8-f32",
			testCvt_REF<unsigned char, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-u8-f64",
			testCvt_REF<unsigned char, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u8,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-u16-u8",
			testCvt_REF<unsigned short, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-u16-u16",
			testCvt_REF<unsigned short, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-u16-u32",
			testCvt_REF<unsigned short, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-u16-u64",
			testCvt_REF<unsigned short, long long unsigned int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-u16-s8",
			testCvt_REF<unsigned short, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-u16-s16",
			testCvt_REF<unsigned short, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-u16-s32",
			testCvt_REF<unsigned short, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-u16-s64",
			testCvt_REF<unsigned short, long long int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-u16-f32",
			testCvt_REF<unsigned short, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-u16-f64",
			testCvt_REF<unsigned short, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u16,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-u32-u8",
			testCvt_REF<unsigned int, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-u32-u16",
			testCvt_REF<unsigned int, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-u32-u32",
			testCvt_REF<unsigned int, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-u32-u64",
			testCvt_REF<unsigned int, long long unsigned int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-u32-s8",
			testCvt_REF<unsigned int, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-u32-s16",
			testCvt_REF<unsigned int, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-u32-s32",
			testCvt_REF<unsigned int, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-u32-s64",
			testCvt_REF<unsigned int, long long int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-u32-f32",
			testCvt_REF<unsigned int, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-u32-f64",
			testCvt_REF<unsigned int, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u32,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-u64-u8",
			testCvt_REF<long long unsigned int, unsigned char,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-u64-u16",
			testCvt_REF<long long unsigned int,
				unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-u64-u32",
			testCvt_REF<long long unsigned int, unsigned int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-u64-u64",
			testCvt_REF<long long unsigned int, long long unsigned int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-u64-s8",
			testCvt_REF<long long unsigned int, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-u64-s16",
			testCvt_REF<long long unsigned int, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-u64-s32",
			testCvt_REF<long long unsigned int, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-u64-s64",
			testCvt_REF<long long unsigned int, long long int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-u64-f32",
			testCvt_REF<long long unsigned int, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-u64-f64",
			testCvt_REF<long long unsigned int, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::u64,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-s8-u8",
			testCvt_REF<char, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-s8-u16",
			testCvt_REF<char, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-s8-u32",
			testCvt_REF<char, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-s8-u64",
			testCvt_REF<char, long long unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-s8-s8",
			testCvt_REF<char, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-s8-s16",
			testCvt_REF<char, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-s8-s32",
			testCvt_REF<char, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-s8-s64",
			testCvt_REF<char, long long int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-s8-f32",
			testCvt_REF<char, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-s8-f64",
			testCvt_REF<char, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s8,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I8), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-s16-u8",
			testCvt_REF<short, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-s16-u16",
			testCvt_REF<short, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-s16-u32",
			testCvt_REF<short, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-s16-u64",
			testCvt_REF<short, long long unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-s16-s8",
			testCvt_REF<short, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-s16-s16",
			testCvt_REF<short, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-s16-s32",
			testCvt_REF<short, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-s16-s64",
			testCvt_REF<short, long long int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-s16-f32",
			testCvt_REF<short, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-s16-f64",
			testCvt_REF<short, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s16,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I16), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-s32-u8",
			testCvt_REF<int, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-s32-u16",
			testCvt_REF<int, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-s32-u32",
			testCvt_REF<int, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-s32-u64",
			testCvt_REF<int, long long unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-s32-s8",
			testCvt_REF<int, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-s32-s16",
			testCvt_REF<int, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-s32-s32",
			testCvt_REF<int, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-s32-s64",
			testCvt_REF<int, long long int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-s32-f32",
			testCvt_REF<int, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-s32-f64",
			testCvt_REF<int, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s32,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I32), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-s64-u8",
			testCvt_REF<long long int, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-s64-u16",
			testCvt_REF<long long int, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-s64-u32",
			testCvt_REF<long long int, unsigned int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-s64-u64",
			testCvt_REF<long long int, long long unsigned int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-s64-s8",
			testCvt_REF<long long int, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-s64-s16",
			testCvt_REF<long long int, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-s64-s32",
			testCvt_REF<long long int, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-s64-s64",
			testCvt_REF<long long int, long long int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-s64-f32",
			testCvt_REF<long long int, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-s64-f64",
			testCvt_REF<long long int, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::s64,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(I64), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-f32-u8",
			testCvt_REF<float, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-f32-u16",
			testCvt_REF<float, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-f32-u32",
			testCvt_REF<float, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-f32-u64",
			testCvt_REF<float, long long unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-f32-s8",
			testCvt_REF<float, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-f32-s16",
			testCvt_REF<float, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-f32-s32",
			testCvt_REF<float, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-f32-s64",
			testCvt_REF<float, long long int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-f32-f32",
			testCvt_REF<float, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-f32-f64",
			testCvt_REF<float, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f32,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(FP32), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);

		add("TestCvt-f64-u8",
			testCvt_REF<double, unsigned char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::u8, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I8),
			uniformRandom<unsigned char, 1>, 1, 1);
		add("TestCvt-f64-u16",
			testCvt_REF<double, unsigned short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::u16, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I16),
			uniformRandom<unsigned short, 1>, 1, 1);
		add("TestCvt-f64-u32",
			testCvt_REF<double, unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::u32, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I32),
			uniformRandom<unsigned int, 1>, 1, 1);
		add("TestCvt-f64-u64",
			testCvt_REF<double, long long unsigned int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::u64, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I64),
			uniformRandom<long long unsigned int, 1>, 1, 1);
		add("TestCvt-f64-s8",
			testCvt_REF<double, char, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::s8, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I8),
			uniformRandom<char, 1>, 1, 1);
		add("TestCvt-f64-s16",
			testCvt_REF<double, short, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::s16, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I16),
			uniformRandom<short, 1>, 1, 1);
		add("TestCvt-f64-s32",
			testCvt_REF<double, int, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::s32, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I32),
			uniformRandom<int, 1>, 1, 1);
		add("TestCvt-f64-s64",
			testCvt_REF<double, long long int,
				false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::s64, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(I64),
			uniformRandom<long long int, 1>, 1, 1);
		add("TestCvt-f64-f32",
			testCvt_REF<double, float, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::f32, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(FP32),
			uniformFloat<float, 1>, 1, 1);
		add("TestCvt-f64-f64",
			testCvt_REF<double, double, false, false, false>,
			testCvt_PTX(ir::PTXOperand::f64,
				ir::PTXOperand::f64, false, false, false),
			testCvt_INOUT(FP64), testCvt_INOUT(FP64),
			uniformFloat<double, 1>, 1, 1);
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
		if(!regularExpression.empty() &&
			name.find(regularExpression) == std::string::npos) return;
		
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

