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
			case I1: return "i1"; break;
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

	LLVMInstruction::LLVMInstruction( Opcode op ) : opcode( op )
	{
		
	}

	LLVMInstruction::LLVMInstruction( const LLVMInstruction& i )
	{
		/* intentionally empty */
	}
	
	const LLVMInstruction& LLVMInstruction::operator=( 
		const LLVMInstruction& i )
	{
		/* intentionally empty */
	}

	std::string LLVMInstruction::toString() const
	{
		return "";
	}

	std::string LLVMInstruction::valid() const
	{
		return "A base LLVMInstruction is not ::valid";
	}

	LLVMUnaryInstruction::LLVMUnaryInstruction( Opcode op ) 
		: LLVMInstruction( op )
	{
	
	}
	
	std::string LLVMUnaryInstruction::toString() const;
	std::string LLVMUnaryInstruction::valid() const;

	LLVMBinaryInstruction::LLVMBinaryInstruction( Opcode op )
		: LLVMInstruction( op )
	{
	
	}

	std::string LLVMBinaryInstruction::toString() const;
	std::string LLVMBinaryInstruction::valid() const;

	LLVMConversionInstruction::LLVMConversionInstruction( Opcode op )
		: LLVMUnaryInstruction( op )
	{
	
	}

	std::string LLVMConversionInstruction::toString() const;
	std::string LLVMConversionInstruction::valid() const;

	LLVMComparisonInstruction::LLVMComparisonInstruction( Opcode op )
		: LLVMBinaryInstruction( op )
	{
	
	}
	
	std::string LLVMComparisonInstruction::toString() const;
	std::string LLVMComparisonInstruction::valid() const;

	LLVMAdd::LLVMAdd() : LLVMBinaryInstruction( Add ), noUnsignedWrap( false ),
		noSignedWrap( false )
	{
	
	}
	
	std::string LLVMAdd::toString() const;
	std::string LLVMAdd::valid() const;

	LLVMAlloca::LLVMAlloca( LLVMI32 e, LLVMI32 a ) : LLVMInstruction( Alloca ), 
		elements( e ), alignment( a )
	{
	
	}
	
	std::string LLVMAlloca::toString() const;
	std::string LLVMAlloca::valid() const;

	LLVMAnd::LLVMAnd() : LLVMBinaryInstruction( And )
	{
	
	}
	
	LLVMAshr::LLVMAshr() : LLVMBinaryInstruction( Ashr )
	{
	
	}

	LLVMBitcast::LLVMBitcast() : LLVMConversionInstruction( Bitcast )
	{
	
	}

	LLVMBr::LLVMBr() : LLVMInstruction( Br )
	{
	
	}
	
	std::string LLVMBr::toString() const;
	std::string LLVMBr::valid() const;	

	LLVMCall::LLVMCall() : LLVMInstruction( Call ), tail( false ), 
		convention( DefaultCallingConvention ), 
		returnAttributes( InvalidParameterAttribute ),
		functionAttributes( 0 )
	{
	
	}
	
	std::string LLVMCall::toString() const;
	std::string LLVMCall::valid() const;

	LLVMExtractelement::LLVMExtractelement() 
		: LLVMBinaryInstruction( ExtractElement )
	{
	
	}
	
	std::string LLVMExtractelement::toString() const;
	std::string LLVMExtractelement::valid() const;

	LLVMExtractvalue::LLVMExtractvalue() : LLVMBinaryInstruction( Extractvalue )
	{
	
	}
	
	std::string LLVMExtractvalue::toString() const;
	std::string LLVMExtractvalue::valid() const;

	LLVMFadd::LLVMFadd() : LLVMBinaryInstruction( Fadd )
	{
	
	}
	
	LLVMFcmp::LLVMFcmp() : LLVMComparisonInstruction( Fcmp )
	{
	
	}
	
	LLVMFdiv::LLVMFdiv() : LLVMBinaryInstruction( Fdiv )
	{
	
	}
	
	LLVMFmul::LLVMFmul() : LLVMBinaryInstruction( Fmul )
	{
	
	}
	
	LLVMFpext::LLVMFpext() : LLVMConversionInstruction( Fpext )
	{
	
	}

	LLVMFptosi::LLVMFptosi() : LLVMConversionInstruction( Fptosi )
	{
	
	}

	LLVMFptoui::LLVMFptoui() : LLVMConversionInstruction( Fptoui )
	{
	
	}

	LLVMFptrunc::LLVMFptrunc() : LLVMConversionInstruction( Fptrunc )
	{
	
	}
	
	LLVMFree::LLVMFree() : LLVMUnaryInstruction( Free )
	{
	
	}
	
	LLVMFrem::LLVMFrem() : LLVMBinaryInstruction( Frem )
	{
	
	}

	LLVMFsub::LLVMFsub() : LLVMBinaryInstruction( Fsub )
	{
	
	}

	LLVMGetelementptr::LLVMGetelementptr() : LLVMInstruction( Getelementptr )
	{
		
	}
	
	std::string LLVMGetelementptr::toString() const;
	std::string LLVMGetelementptr::valid() const;

	LLVMIcmp::LLVMIcmp() : LLVMComparisonInstruction( Icmp )
	{
	
	}

	LLVMInsertelement::LLVMInsertelement() 
		: LLVMBinaryInstruction( Insertelement )
	{
	
	}
	
	std::string LLVMInsertelement::toString() const;
	std::string LLVMInsertelement::valid() const;

	LLVMInsertvalue::LLVMInsertvalue() : LLVMInstruction( Insertvalue )
	{
	
	}
	
	std::string LLVMInsertvalue::toString() const;
	std::string LLVMInsertvalue::valid() const;

	LLVMInttoptr::LLVMInttoptr() : LLVMConversionInstruction( Inttoptr )
	{
	
	}

	LLVMInvoke::LLVMInvoke() : LLVMInstruction( Invoke )
	{
	
	}
	
	std::string LLVMInvoke::toString() const;
	std::string LLVMInvoke::valid() const;

	LLVMLoad::LLVMLoad() : LLVMUnaryInstruction( Load ), isVolatile( false ), 
		alignment( 1 )
	{
	
	}
	
	std::string LLVMLoad::toString() const;
	std::string LLVMLoad::valid() const;

	LLVMLshr::LLVMLshr() : LLVMBinaryInstruction( Lshr )
	{
	
	}

	LLVMMalloc::LLVMMalloc() : LLVMInstruction( Malloc ), elements( 1 ), 
		alignment( 1 )
	{
	
	}
	
	std::string LLVMMalloc::toString() const;
	std::string LLVMMalloc::valid() const;

	LLVMMul::LLVMMul() : LLVMBinaryInstruction( Mul ), noUnsignedWrap( false ),
		noSignedWrap( false )
	{
	
	}
	
	std::string LLVMMul::toString() const;
	std::string LLVMMul::valid() const;

	LLVMOr::LLVMOr() : LLVMBinaryInstruction( Or )
	{
	
	}
	
	std::string LLVMOr::toString() const;
	std::string LLVMOr::valid() const;

	LLVMPhi::LLVMPhi() : LLVMInstruction( Phi )
	{
	
	} 
	
	std::string LLVMPhi::toString() const;
	std::string LLVMPhi::valid() const;

	LLVMPtrtoint::LLVMPtrtoint() : LLVMConversionInstruction( Ptrtoint )
	{
	
	}

	LLVMRet::LLVMRet() : LLVMInstruction( Ret )
	{
	
	}
	
	std::string LLVMRet::toString() const;
	std::string LLVMRet::valid() const;

	LLVMSdiv::LLVMSdiv() : LLVMBinaryInstruction( Sdiv ), exact( false )
	{
	
	}
	
	std::string LLVMSdiv::toString() const;
	std::string LLVMSdiv::valid() const;

	LLVMSelect::LLVMSelect() : LLVMBinaryInstruction( Select )
	{
	
	}
	
	std::string LLVMSelect::toString() const;
	std::string LLVMSelect::valid() const;

	LLVMSext::LLVMSext() : LLVMConversionInstruction( Sext )
	{
	
	}

	LLVMShl::LLVMShl() : LLVMBinaryInstruction( Shl )
	{
	
	}

	LLVMShufflevector::LLVMShufflevector() 
		: LLVMBinaryInstruction( ShuffleVector )
	{
	
	}
	
	std::string LLVMShufflevector::toString() const;
	std::string LLVMShufflevector::valid() const;

	LLVMSitofp::LLVMSitofp() : LLVMConversionInstruction( Sitofp )
	{
	
	}
	
	LLVMSrem::LLVMSrem() : LLVMBinaryInstruction( Srem )
	{
	
	}
	
	LLVMStore::LLVMStore() : LLVMUnaryInstruction( Store ), isVolatile( false ),
		alignment( 1 )
	{
	
	}
	
	std::string LLVMStore::toString() const;
	std::string LLVMStore::valid() const;

	LLVMSub::LLVMSub() : LLVMBinaryInstruction( Sub ), noUnsignedWrap( false ),
		noSignedWrap( false )
	{
	
	}
	
	std::string LLVMSub::toString() const;
	std::string LLVMSub::valid() const;

	LLVMSwitch::LLVMSwitch() : LLVMInstruction( Switch )
	{
	
	}
	std::string LLVMSwitch::toString() const;
	std::string LLVMSwitch::valid() const;

	LLVMTrunc::LLVMTrunc() : LLVMConversionInstruction( Trunk )
	{
	
	}

	LLVMUdiv::LLVMUdiv() : LLVMBinaryInstruction( Udiv )
	{
	
	}

	LLVMUitofp::LLVMUitofp() : LLVMConversionInstruction( Uitofp )
	{
	
	}

	LLVMUnreachable::LLVMUnreachable() : LLVMInstruction( Unreachable )
	{
	
	}
	
	std::string LLVMUnreachable::toString() const;
	std::string LLVMUnreachable::valid() const;

	LLVMUnwind::LLVMUnwind() : LLVMInstruction( Unwind )
	{
	
	}
	std::string LLVMUnwind::toString() const;
	std::string LLVMUnwind::valid() const;

	LLVMUrem::LLVMUrem() : LLVMBinaryInstruction( Urem )
	{
	
	}
	std::string LLVMUrem::toString() const;
	std::string LLVMUrem::valid() const;

	LLVMVaArg::LLVMVaArg() : LLVMUnaryInstruction( VaArg )
	{
	
	}
	std::string LLVMVaArg::toString() const;
	std::string LLVMVaArg::valid() const;

	LLVMXor::LLVMXor() : LLVMBinaryInstruction( Xor )
	{
	
	}

	LLVMZext::LLVMZext() : LLVMConversionInstruction( Zext )
	{
	
	}
	
}

#endif

