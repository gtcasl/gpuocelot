/*!
	\file LLVMInstruction.cpp
	\date Tuesday July 21, 2009
	\author Gregroy Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMInstruction class.
*/

#ifndef LLVM_INSTRUCTION_CPP_INCLUDED
#define LLVM_INSTRUCTION_CPP_INCLUDED

#include <ocelot/ir/interface/Instruction.h>
#include <hydrazine/implementation/debug.h>

namespace ir
{
	LLVMInstruction::Opeand::Operand( Mode m, DataType t, unsigned int v ) : 
		mode( m ), type( t ), vector( v )
	{
	
	}

	LLVMInstruction::Opeand::Parameter( Attribute a, Mode m, DataType t, 
		unsigned int v ) : Operand( m, t, v), attribute( a )
	{
		
	}

	std::string LLVMInstruction::Opeand::toString() const
	{
		switch( mode )
		{
			case Register:
			{
				std::stringstream stream;
				stream << "r" << reg;
				return stream.str();
			}
			case Immediate:
			{
				std::stringstream stream;
				switch( type )
				{
					case S8: stream << s8; break;
					case S16: stream << s16; break;
					case S32: stream << s32; break;
					case S64: stream << s64; break;
					case U8: stream << u8; break;
					case U16: stream << u16; break;
					case U32: stream << u32; break;
					case U64: stream << u64; break;
					case F32: stream << f32; break;
					case F64: stream << f64; break;
					case LLVMInstruction::Invalid: 
						assertM( 0, "Invalid LLVM Instruction DataType." );
				}
				return stream.str();
			}
			case Label:
			{
				return label;
			}
			case Invalid : assertM( 0, "Invalid LLVM Instruction Operand." );
		}
		return "";
	}

	std::string LLVMInstruction::tailToString( int attribute )
	{
		if( attribute & Tail) return "tail";
		return "";
	}

	std::string LLVMInstruction::conventionToString( int attribute )
	{
		if( attribute & FastCallingConvention) return "fastcc";
		if( attribute & CCallingConvention) return "ccc";
		if( attribute & ColdCallingConvention) return "coldcc";
		return "";
	}

	std::string LLVMInstruction::toString( int attribute )
	{
		if( attribute & ZeroExtend) return "zeroext";
		if( attribute & SignExtend) return "signext";
		if( attribute & InReg) return "inreg";
		return "";		
	}

	std::string LLVMInstruction::functionAttributesToString( int attribute )
	{
		if( attribute & NoReturn) return "noreturn";
		if( attribute & NoUnwind) return "nounwind";
		if( attribute & ReadOnly) return "readonly";
		if( attribute & ReadNone) return "readnone";
		return "";
	}
	
	std::string LLVMInstruction::toString( ParameterAttribute attribute )
	{
		switch( attribute )
		{
			case ZeroExtend: return "zeroext"; break;
			case SignExtend: return "signext"; break;
			case InReg: return "inreg"; break;
			case ByValue: return "byval"; break;
			case StructureReturn: return "sret"; break;
			case NoAlias: return "noalias"; break;
			case NoCapture: return "nocapture"; break;
			case Nest: return "nest"; break;
			case NoAttribute: return ""; break;
		}
		return "";
	}

	std::string LLVMInstruction::toString( DataType d )
	{
		switch( d )
		{
			case U8: /* fall through */
			case S8: return "i8"; break;
			case U16: /* fall through */
			case S16: return "i16"; break;
			case U32: /* fall through */
			case S32: return "i32"; break;
			case S64: /* fall through */
			case U64: return "i64"; break;
			case F32: return "f32"; break;
			case F64: return "f64"; break;
			default: break;
		}
		return "";
	}

	std::string LLVMInstruction::toString( Comparison comp )
	{
		switch( comp )
		{
			case False: return "false"; break;
			case Oeq: return "oeq"; break;
			case Ogt: return "ogt"; break;
			case Oge: return "oge"; break;
			case Olt: return "olt"; break;
			case Ole: return "ole"; break;
			case One: return "one"; break;
			case Ord: return "ord"; break;
			case Ueq: return "ueq"; break;
			case Ugt: return "ugt"; break;
			case Uge: return "uge"; break;
			case Ult: return "ult"; break;
			case Ule: return "ule"; break;
			case Une: return "une"; break;
			case Uno: return "uno"; break;
			case True: return "true"; break;
		}
		return "";
	}

	LLVMInstruction::LLVMInstruction( Opcdode op ) : opcode( op )
	{
		
	}

	std::string LLVMInstruction::toString() const
	{
		return "";
	}

	std::string LLVMInstruction::valid() const
	{
		return "A base LLVMInstruction is not valid";
	}
}

#endif


