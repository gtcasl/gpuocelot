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

	std::string LLVMInstruction::parameterAttributesToString( int attribute )
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

	LLVMInstruction::LLVMInstruction( Opcdode op ) : opcode( op )
	{
		
	}

	std::string LLVMInstruction::toString() const
	{
		switch( opcode )
		{
			case Alloca:
			{
				std::stringstream stream;
				stream << d.toString() << " = alloca " << toString( d.type ) 
					<< ", " << a.u64 << ", align " << allignment;
				return stream.str();
			}
			case And:
			{
				return d.toString() + " = and " + toString( d.type ) 
					+ " " + a.toString() + ", " + b.toString();
			}
			case Ashr:
			{
				return d.toString() + " = ashr " + toString( d.type ) + " " 
					+ a.toString() + ", " + b.toString();
			}
			case Bitcast:
			{
				return d.toString() + " = bitcast " + toString( a.type ) + " " 
					+ a.toString() + " to " + toString( d.type );
			}	
			case Br:
			{
				return "br " + toString( d.type ) + ", label " + a.toString() 
					+ ", label " + b.toString();
			}
			case Call:
			{
				return 
			}
			case Extractelement:
			{
			
			}
			case Extractvalue:
			{
			
			}
			case Fadd:
			{
			
			}
			case Fcmp:
			{
			
			}
			case Fdiv:
			{
			
			}
			case Fmul:
			{
			
			}
			case Fpext:
			{
			
			}	
			case Fptosi:
			{
			
			}	
			case Fptoui:
			{
			
			}
			case Fptrunc:
			{
			
			}	
			case Free:
			{
			
			}
			case Frem:
			{
			
			}
			case Fsub:
			{
			
			}
			case Getelementptr:
			{
			
			}
			case Icmp:
			{
			
			}
			case Insertelement:
			{
			
			}
			case Insertvalue:
			{
			
			}
			case Inttoptr:
			{
			
			}
			case Invoke:
			{
			
			}
			case Load:
			{
			
			}
			case Lshr:
			{
			
			}
			case Malloc:
			{
			
			}
			case Mul:
			{
			
			}
			case Or:
			{
			
			}
			case Phi:
			{
			
			}
			case Ptrtoint:
			{
			
			}
			case Ret:
			{
			
			}
			case Radd:
			{
			
			}
			case Sdiv:
			{
			
			}
			case Select:
			{
			
			}
			case Sext:
			{
			
			}
			case Shl:
			{
			
			}
			case Shufflevector:
			{
			
			}
			case Sitofp:
			{
			
			}
			case Srem:
			{
			
			}
			case Store:
			{
			
			}
			case Sub:
			{
			
			}
			case Switch:
			{
			
			}
			case Trunc:
			{
			
			}
			case Udiv:
			{
			
			}
			case Uitofp:
			{
			
			}	
			case Unreachable:
			{
			
			}
			case Unwind:
			{
			
			}
			case Urem:
			{
			
			}
			case Va_arg:
			{
			
			}
			case Xor:
			{
			
			}
			case Zext:
			{
			
			}
			case InvalidOpcode
		}
	}

	std::string LLVMInstruction::valid() const
	{
		return "";
	}
}

#endif


