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
	
	std::string LLVMInstruction::toString( Opcode code )
	{
		switch( code )
		{
			case Add: return "add"; break;
			case Alloca: return "alloca"; break;
			case And: return "and"; break;
			case Ashr: return "ashr"; break;
			case Bitcast: return "bitcast"; break;
			case Br: return "br"; break;
			case Call: return "call"; break;
			case Extractelement: return "extractelement"; break;
			case Extractvalue: return "extractvalue"; break;
			case Fadd: return "fadd"; break;
			case Fcmp: return "fcmp"; break;
			case Fdiv: return "fdiv"; break;
			case Fmul: return "fmul"; break;
			case Fpext: return "fpext"; break;
			case Fptosi: return "fptosi"; break;
			case Fptoui: return "fptoui"; break;
			case Fptrunc: return "fptrunc"; break;
			case Free: return "free"; break;
			case Frem: return "frem"; break;
			case Fsub: return "fsub"; break;
			case Getelementptr: return "getelementptr"; break;
			case Icmp: return "icmp"; break;
			case Insertelement: return "insertelement"; break;
			case Insertvalue: return "insertvalue"; break;
			case Inttoptr: return "inttoptr"; break;
			case Invoke: return "invoke"; break;
			case Load: return "load"; break;
			case Lshr: return "lshr"; break;
			case Malloc: return "malloc"; break;
			case Mul: return "mul"; break;
			case Or: return "or"; break;
			case Phi: return "phi"; break;
			case Ptrtoint: return "ptrtoint"; break;
			case Ret: return "ret"; break;
			case Sdiv: return "sdiv"; break;
			case Select: return "select"; break;
			case Sext: return "sext"; break;
			case Shl: return "shl"; break;
			case Shufflevector: return "shufflevector"; break;
			case Sitofp: return "sitofp"; break;
			case Srem: return "srem"; break;
			case Store: return "store"; break;
			case Sub: return "sub"; break;
			case Switch: return "switch"; break;
			case Trunc: return "trunc"; break;
			case Udiv: return "udiv"; break;
			case Uitofp: return "uitofp"; break;
			case Unreachable: return "unreachable"; break;
			case Unwind: return "unwind"; break;
			case Urem: return "urem"; break;
			case VaArg: return "va_arg"; break;
			case Xor: return "xor"; break;
			case Zext: return "zext"; break;
			case InvalidOpcode: return "INVALID_OPCODE"; break;
		}
		return "";
	}

	std::string LLVMInstruction::toString( CallingConvention cc )
	{
		switch( cc )
		{
			case CCallingConvention: return "ccc"; break;
			case FastCallingConvention: return "fastcc"; break;
			case ColdCallingConvention: return "coldcc"; break;
			case DefaultCallingConvention: return "ccc"; break;
			case InvalidCallingConventio: return "INVALID_CC"; break;
		}
		return "";
	}
	
	std::string LLVMInstruction::toString( ParameterAttribute attribute )
	{
		switch( attribute )
		{
			case ZeroExtend: return "zeroext"; break;
			case SignExtend: return "signext"; break;
			case InRegister: return "inreg"; break;
			case ByValue: return "byval"; break;
			case StructureReturn: return "sret"; break;
			case NoAlias: return "noalias"; break;
			case NoCapture: return "nocapture"; break;
			case Nested: return "nest"; break;
			case InvalidParameterAttribute: return "INVALID_PARAM_ATTR"; break;
		}
		return "";
	}

	std::string LLVMInstruction::toString( DataType d )
	{
		switch( d )
		{
			case I8: return "i8"; break;
			case I16: return "i16"; break;
			case I32: return "i32"; break;
			case I64: return "i64"; break;
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
			case Eq: return "eq"; break;
			case Ne: return "ne"; break;
			case Sgt: return "sgt"; break;
			case Sge: return "sge"; break;
			case Slt: return "slt"; break;
			case Sle: return "sle"; break;
		}
		return "";
	}
	
	std::string LLVMInstruction::functionAttributesToString( int attributes )
	{
		std::string result;
		if( attributes & AlwaysInline )
		{
			result += "alwaysinline;"
		}
		if( attributes & NoInline )
		{
			if( !result.empty() ) result += " ";
			result += "noinline;"
		}
		if( attributes & OptimizeSize )
		{
			if( !result.empty() ) result += " ";
			result += "optsize;"
		}
		if( attributes & NoReturn )
		{
			if( !result.empty() ) result += " ";
			result += "noreturn;"
		}
		if( attributes & NoUnwind )
		{
			if( !result.empty() ) result += " ";
			result += "nounwind;"
		}
		if( attributes & ReadNone )
		{
			if( !result.empty() ) result += " ";
			result += "readnone;"
		}
		if( attributes & ReadOnly )
		{
			if( !result.empty() ) result += " ";
			result += "readonly;"
		}
		if( attributes & StackSmashingProtector )
		{
			if( !result.empty() ) result += " ";
			result += "ssp;"
		}
		if( attributes & StackSmashingProtectorRequired )
		{
			if( !result.empty() ) result += " ";
			result += "sspreq;"
		}
		if( attributes & NoRedZone )
		{
			if( !result.empty() ) result += " ";
			result += "noredzone;"
		}
		if( attributes & NoImplicitFloat )
		{
			if( !result.empty() ) result += " ";
			result += "noimplicitfloat;"
		}
		if( attributes & Naked )
		{
			if( !result.empty() ) result += " ";
			result += "naked;"
		}
		return result;
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


