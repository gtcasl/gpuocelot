/*!
	\file PTXInstruction.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief base class for all instructions
*/

#include <ocelot/ir/interface/PTXInstruction.h>
#include <hydrazine/implementation/debug.h>
#include <sstream>

std::string ir::PTXInstruction::toString( Level l ) {
	switch( l ) {
		case CtaLevel: return "cta"; break;
		case GlobalLevel: return "gl"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( PermuteMode m ) {
	switch( m ) {
		case ForwardFourExtract: return "f4e"; break;
		case BackwardFourExtract: return "b4e"; break;
		case ReplicateEight: return "rc8"; break;
		case EdgeClampLeft: return "ecl"; break;
		case EdgeClampRight: return "ecr"; break;
		case ReplicateSixteen: return "rc16"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( FloatingPointMode m ) {
	switch( m ) {
		case Finite: return "finite"; break;
		case Infinite: return "infinite"; break;
		case Number: return "number"; break;
		case NotANumber: return "notanumber"; break;
		case Normal: return "normal"; break;
		case SubNormal: return "subnormal"; break;
		default: break;
	}
	return "";
}
std::string ir::PTXInstruction::toString( Vec v ) {
	switch( v ) {
		case PTXOperand::v1: return "v1"; break;
		case PTXOperand::v2: return "v2"; break;
		case PTXOperand::v4: return "v4"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( AddressSpace space ) {
	switch( space ) {
		case Reg:
		case SReg: return "reg"; break;
		case Const: return "const"; break;
		case Global: return "global"; break;
		case Local: return "local"; break;
		case Param: return "param"; break;
		case Shared: return "shared"; break;
		case Texture: return "tex"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( AtomicOperation operation ) {
	switch( operation ) {
		case AtomicAnd: return "and"; break;
		case AtomicOr: return "or"; break;
		case AtomicXor: return "xor"; break;
		case AtomicCas: return "cas"; break;
		case AtomicExch: return "exch"; break;
		case AtomicAdd: return "add"; break;
		case AtomicInc: return "inc"; break;
		case AtomicDec: return "dec"; break;
		case AtomicMin: return "min"; break;
		case AtomicMax: return "max"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( ReductionOperation operation ) {
	switch( operation ) {
		case ReductionAnd: return "and"; break;
		case ReductionOr: return "or"; break;
		case ReductionXor: return "xor"; break;
		case ReductionAdd: return "add"; break;
		case ReductionInc: return "inc"; break;
		case ReductionDec: return "dec"; break;
		case ReductionMin: return "min"; break;
		case ReductionMax: return "max"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::roundingMode( Modifier modifier ) {
	switch( modifier ) {
		case rn: return "rn"; break;
		case rz: return "rz"; break;
		case rm: return "rm"; break;
		case rp: return "rp"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::modifierString( unsigned int modifier, 
	CarryFlag carry ) {
	std::string result;
	switch( modifier ) {
		case approx: return result += "approx."; break;
		case wide: return result += "wide."; break;
		case hi: return result += "hi."; break;
		case lo: return result += "lo."; break;
		case rn: return result += "rn."; break;
		case rz: return result += "rz."; break;
		case rm: return result += "rm."; break;
		case rp: return result += "rp."; break;
		default: break;
	}
	if( modifier & ftz ) {
		result += "ftz.";
	}
	if( modifier & sat ) {
		result += "sat.";
	}
	if( carry == CC ) {
		result += "cc.";
	}
	return result;
}

std::string ir::PTXInstruction::toString( Modifier modifier ) {
	switch( modifier ) {
		case hi: return "hi"; break;
		case lo: return "lo"; break;
		case wide: return "wide"; break;
		case sat: return "sat"; break;
		case rn: return "rn"; break;
		case rz: return "rz"; break;
		case rm: return "rm"; break;
		case rp: return "rp"; break;
		case approx: return "approx"; break;
		case ftz: return "ftz"; break;
		default: break;
	}
	return "";	
}

std::string ir::PTXInstruction::toString( CmpOp operation ) {
	switch( operation ) {
		case Eq: return "eq"; break;
		case Ne: return "ne"; break;
		case Lt: return "lt"; break;
		case Le: return "le"; break;
		case Gt: return "gt"; break;
		case Ge: return "ge"; break;
		case Lo: return "lo"; break;
		case Ls: return "ls"; break;
		case Hi: return "hi"; break;
		case Hs: return "hs"; break;
		case Equ: return "equ"; break;
		case Neu: return "neu"; break;
		case Ltu: return "ltu"; break;
		case Leu: return "leu"; break;
		case Gtu: return "gtu"; break;
		case Geu: return "geu"; break;
		case Num: return "num"; break;
		case Nan: return "nan"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( BoolOp operation ) {
	switch( operation ) {
		case BoolAnd: return "and"; break;
		case BoolOr: return "or"; break;
		case BoolXor: return "xor"; break;	
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( Geometry geometry ) {
	switch( geometry ) {
		case _1d: return "1d"; break;
		case _2d: return "2d"; break;
		case _3d: return "3d"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( VoteMode mode ) {
	switch( mode ) {
		case All: return "all"; break;
		case Any: return "any"; break;
		case Uni: return "uni"; break;
		default: break;
	}
	return "";
}

std::string ir::PTXInstruction::toString( Opcode opcode ) {
	switch( opcode ) {
		case Abs: return "abs"; break;
		case Add: return "add"; break;
		case AddC: return "addc"; break;
		case And: return "and"; break;
		case Atom: return "atom"; break;
		case Bar: return "bar"; break;
		case Bfe: return "bfe"; break;
		case Bfi: return "bfi"; break;
		case Bfind: return "bfind"; break;
		case Bra: return "bra"; break;
		case Brev: return "brev"; break;
		case Brkpt: return "brkpt"; break;
		case Call: return "call"; break;
		case Clz: return "clz"; break;
		case CNot: return "cnot"; break;
		case Cos: return "cos"; break;
		case Cvt: return "cvt"; break;
		case Cvta: return "cvta"; break;
		case Div: return "div"; break;
		case Ex2: return "ex2"; break;
		case Exit: return "exit"; break;
		case Fma: return "fma"; break;
		case Isspacep: return "isspacep"; break;
		case Ld: return "ld"; break;
		case Ldu: return "ldu"; break;
		case Lg2: return "lg2"; break;
		case Mad24: return "mad24"; break;
		case Mad: return "mad"; break;
		case Max: return "max"; break;
		case Membar: return "membar"; break;
		case Min: return "min"; break;
		case Mov: return "mov"; break;
		case Mul24: return "mul24"; break;
		case Mul: return "mul"; break;
		case Neg: return "neg"; break;
		case Not: return "not"; break;
		case Or: return "or"; break;
		case Pmevent: return "pmevent"; break;
		case Popc: return "popc"; break;
		case Prefetch: return "prefetch"; break;
		case Prefetchu: return "prefetchu"; break;
		case Prmt: return "prmt"; break;
		case Rcp: return "rcp"; break;
		case Red: return "red"; break;
		case Rem: return "rem"; break;
		case Ret: return "ret"; break;
		case Rsqrt: return "rsqrt"; break;
		case Sad: return "sad"; break;
		case SelP: return "selp"; break;
		case Set: return "set"; break;
		case SetP: return "setp"; break;
		case Shl: return "shl"; break;
		case Shr: return "shr"; break;
		case Sin: return "sin"; break;
		case SlCt: return "slct"; break;
		case Sqrt: return "sqrt"; break;
		case St: return "st"; break;
		case Sub: return "sub"; break;
		case SubC: return "subc"; break;
		case Suld: return "suld"; break;
		case Sured: return "sured"; break;
		case Sust: return "sust"; break;
		case Suq: return "suq"; break;
		case TestP: return "testp"; break;
		case Tex: return "tex"; break;
		case Txq: return "txq"; break;
		case Trap: return "trap"; break;
		case Vabsdiff: return "vabsdiff"; break;
		case Vadd: return "vadd"; break;
		case Vmad: return "vmad"; break;
		case Vmax: return "vmax"; break;
		case Vmin: return "vmin"; break;
		case Vset: return "vset"; break;
		case Vshl: return "vshl"; break;
		case Vshr: return "vshr"; break;
		case Vsub: return "vsub"; break;
		case Vote: return "vote"; break;
		case Xor: return "xor"; break;
		case Reconverge: return "reconverge"; break;
		case Phi: return "phi"; break;
		case Nop: return "nop"; break;
	}
	return "INVALID";
}

bool ir::PTXInstruction::isPt( const PTXOperand& op )
{
	return op.toString() == "%pt";
}

ir::PTXInstruction::PTXInstruction( Opcode op, const PTXOperand& _d, 
	const PTXOperand& _a, const PTXOperand& _b, const PTXOperand& _c ) 
	: opcode(op), d(_d), a(_a), b(_b), c(_c) {
	ISA = Instruction::PTX;
	type = PTXOperand::s32;
	modifier = 0;
	reconvergeInstruction = 0;
	branchTargetInstruction = 0;
	vec = PTXOperand::v1;
	pg.condition = PTXOperand::PT;
	pg.type = PTXOperand::pred;
	booleanOperator = BoolNop;
	carry = None;
	statementIndex = 0;
	divideFull = false;
}

ir::PTXInstruction::~PTXInstruction() {

}

bool ir::PTXInstruction::operator==( const PTXInstruction& i ) const {
	return opcode == i.opcode;
}

std::string ir::PTXInstruction::valid() const {
	switch (opcode) {
		case Abs: {
			if ( !( type == PTXOperand::s16 || type == PTXOperand::s32 || 
				type == PTXOperand::s64 || type == PTXOperand::f32 || 
				type == PTXOperand::f64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );	
			}			
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}		
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Add: {
			if ( !( type != PTXOperand::s8 && type != PTXOperand::u8 && 
				type != PTXOperand::b8 && type != PTXOperand::f16 
				&& type != PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( carry == CC ) {
				if( ( modifier & sat ) ) {
					return "saturate not supported with carry out";
				}
				if( !( type == PTXOperand::u32 || type == PTXOperand::s32 ) ) {
					return "invalid instruction type " 
						+ PTXOperand::toString( type );
				}
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case AddC: {
			if( !( type == PTXOperand::u32 || type == PTXOperand::s32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case And: {
			if( !( type == PTXOperand::b16 || type == PTXOperand::b32 || 
				type == PTXOperand::b64 || type == PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;	
		}
		case Atom: {
			if( !PTXOperand::valid( PTXOperand::b32, type ) 
				&& !PTXOperand::valid( PTXOperand::b64, type ) 
				&& ( atomicOperation == AtomicAnd || atomicOperation == AtomicOr 
				|| atomicOperation == AtomicXor || atomicOperation == AtomicCas 
				|| atomicOperation == AtomicExch ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type ) + " for atomic " 
					+ toString( atomicOperation );
			}
				
			if( !PTXOperand::valid( PTXOperand::u32, type ) 
				&& !PTXOperand::valid( PTXOperand::u64, type ) 
				&& !PTXOperand::valid( PTXOperand::s32, type ) 
				&& ( atomicOperation == AtomicInc 
				|| atomicOperation == AtomicDec ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type ) + " for atomic " 
					+ toString( atomicOperation );
			}
			if( !PTXOperand::valid( PTXOperand::f32, type ) 
				&& !PTXOperand::valid( PTXOperand::u32, type ) 
				&& !PTXOperand::valid( PTXOperand::u64, type ) 
				&& !PTXOperand::valid( PTXOperand::s32, type ) 
				&& ( atomicOperation == AtomicAdd 
				|| atomicOperation == AtomicMin 
				|| atomicOperation == AtomicMax ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type ) + " for atomic " 
					+ toString( atomicOperation );
			}
			if( !( addressSpace == Shared || addressSpace == Global ) ) {
				return "invalid adress space " + toString( addressSpace );
			}
			break;
		}
		case Bar: {
			if( d.addressMode != PTXOperand::Immediate ) {
				return "only support Immediate targets";
			}
			break;
		}
		case Bfi: {
			if( !( type == PTXOperand::b32 || type == PTXOperand::b64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, pq.type ) 
				&& pq.addressMode != PTXOperand::Immediate ) {
				return "operand 1 type " + PTXOperand::toString( pq.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand 2 type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( PTXOperand::u32, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand 3 type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " 
					+ PTXOperand::toString( PTXOperand::u32 );
			}
			if( !PTXOperand::valid( PTXOperand::u32, b.type ) 
				&& c.addressMode != PTXOperand::Immediate ) {
				return "operand 4 type " + PTXOperand::toString( c.type ) 
					+ " cannot be assigned to " 
					+ PTXOperand::toString( PTXOperand::u32 );
			}
			break;
		}
		case Bfind: {
			if( !( type == PTXOperand::u32 || type == PTXOperand::u64 
				|| type == PTXOperand::s32 || type == PTXOperand::s64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( PTXOperand::u32, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " 
					+ PTXOperand::toString( PTXOperand::u32 );
			}
			break;
		}
		case Bra: {
			if( !( d.addressMode == PTXOperand::Label 
				|| d.addressMode == PTXOperand::Register ) ) {
				return "no support for types other than Label and Register";
			}
			break;
		}
		case Brev: {
			if( !( type == PTXOperand::b32 || type == PTXOperand::b64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case Brkpt: {
			break;
		}
		case Call: {
			if( a.addressMode != PTXOperand::Register
				&& a.addressMode != PTXOperand::FunctionName ) {
				return "operand A must be a function name or register.";
			}
			if( d.addressMode != PTXOperand::ArgumentList 
				&& d.addressMode != PTXOperand::Invalid ) {
				return "operand D must be an argument list if it is specified.";
			}
			if( b.addressMode != PTXOperand::ArgumentList ) {
				return "operand B must be an argument list.";
			}
			if( a.addressMode == PTXOperand::Register
				&& c.addressMode != PTXOperand::FunctionName ) {
				return "operand C must be function name if A is a register.";
			}
			break;
		}
		case Clz: {
			if( !( type == PTXOperand::b32 || type == PTXOperand::b64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( PTXOperand::u32, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " 
					+ PTXOperand::toString( PTXOperand::u32 );
			}
			break;
		}
		case CNot: {
			if( !( type == PTXOperand::b16 || type == PTXOperand::b32 || 
				type == PTXOperand::b64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case Cos: {
			if( !( type == PTXOperand::f32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Cvt: {
			if( type == PTXOperand::pred ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}					
			if( d.bytes() < PTXOperand::bytes( type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned from " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			if( !PTXOperand::relaxedValid( type, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type ) 
					+ ", not even for relaxed typed instructions.";
			}
			break;
		}
		case Div: {
			if( ( modifier & sat ) ) {
				return "no support for saturating divide.";
			}
			if( ( modifier & approx ) ) {
				if( type != PTXOperand::f32 ) {
					return "only f32 supported for approximate";
				}
			}
			if( type == PTXOperand::f64 ) {
				if( !( modifier & rn ) && !( modifier & rz ) 
					&& !( modifier & rm ) && !( modifier & rp ) ) {
					return "requires a rounding modifier";
				}
				if( !( modifier & rn ) ) {
					return "only nearest rounding supported";
				}
			}
			if( !( type == PTXOperand::u16 || type == PTXOperand::u32 
				|| type == PTXOperand::u64 || type == PTXOperand::s16 
				|| type == PTXOperand::s32 || type == PTXOperand::s64 
				|| type == PTXOperand::f32 || type == PTXOperand::f64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Ex2: {
			if( !( type == PTXOperand::f32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Exit: {
			break;
		}
		case Ld: {
			if( !( a.addressMode == PTXOperand::Register 
				|| a.addressMode == PTXOperand::Address 
				|| a.addressMode == PTXOperand::Indirect 
				|| a.addressMode == PTXOperand::Immediate ) ) {
				return "invalid address mode " 
					+ PTXOperand::toString( a.addressMode ) 
					+ " for operand A ";
			}
			if( addressSpace != Global && addressSpace != Shared 
				&& volatility == Volatile ) {
				return "only shared and global address spaces supported " 
					+ std::string( "for volatile loads" );
			}
			if( d.addressMode != PTXOperand::Register ) {
				return "operand D must be a register not a " 
					+ PTXOperand::toString( d.addressMode );
			}
			if( !PTXOperand::relaxedValid( type, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type ) 
					+ ", not even for relaxed typed instructions.";
			}
			break;
		}
		case Lg2: {
			if( !( type == PTXOperand::f32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Mad24: {
			if( !( type == PTXOperand::u32 || type == PTXOperand::s32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, c.type ) 
				&& c.addressMode != PTXOperand::Immediate ) {
				return "operand C type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case Mad: {
			if( !( type != PTXOperand::s8 && type != PTXOperand::u8 && 
				type != PTXOperand::b8 && type != PTXOperand::f16 
				&& type != PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( type == PTXOperand::f64 ) {
				if( !( modifier & rn ) && !( modifier & rz ) 
					&& !( modifier & rm ) && !( modifier & rp ) ) {
					return "requires a rounding modifier";
				}
			}
			if( a.type != b.type ) {
				return "type of operand A " + PTXOperand::toString( a.type ) 
					+ " does not equal type of operand B " 
					+ PTXOperand::toString( b.type );
			}
			if( !( c.bytes() == d.bytes() ) ) {
				std::stringstream stream;
				stream << "size of operand C " << c.bytes() 
					<< " does not equal size of operand D " << d.bytes();
				return stream.str();
			}
			if( ( ( modifier & hi ) || ( modifier & lo ) ) 
				&& ( a.bytes() != d.bytes() ) ) {
				std::stringstream stream;
				stream << "not wide and size of operand A " << a.bytes() 
					<< " does not equal size of operand D " << d.bytes();
				return stream.str();
			}
			if( ( modifier & wide ) && ( 2 * a.bytes() != d.bytes() ) ) {
				std::stringstream stream;
				stream << "wide and size of operand A " << a.bytes() 
					<< " does not equal half the size of operand D " 
					<< d.bytes();
				return stream.str();
			}
			if( ( modifier & sat ) && ( type != PTXOperand::s32 ) ) {
				return "saturate only valid for s32";
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Max: {
			if( !( type != PTXOperand::s8 && type != PTXOperand::u8 && 
				type != PTXOperand::b8 && type != PTXOperand::f16 
				&& type != PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Membar: {
			break;
		}
		case Min: {
			if( !( type != PTXOperand::s8 && type != PTXOperand::u8 && 
				type != PTXOperand::b8 && type != PTXOperand::f16 
				&& type != PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Mov: {
			if ( ( a.type == PTXOperand::s8 || a.type == PTXOperand::u8 
				|| a.type == PTXOperand::b8 || a.type == PTXOperand::f16 ) &&
				a.addressMode != PTXOperand::Address &&
				a.addressMode != PTXOperand::Immediate ) {
				return "invalid type for operand A " 
					+ PTXOperand::toString( a.type );
			}
			if ( !( d.type != PTXOperand::s8 && d.type != PTXOperand::u8 
				&& d.type != PTXOperand::b8 && d.type != PTXOperand::f16 ) ) {
				return "invalid type for operand D " 
					+ PTXOperand::toString( d.type );
			}
			if( ( a.vec != PTXOperand::v1 || d.vec != PTXOperand::v1 ) 
				&& ( a.bytes() != d.bytes() ) ) {
				std::stringstream stream;
				stream << "at least one vector operand and A size " << a.bytes()
					<< " does not equal D size " << d.bytes();
				return stream.str();
			}
			break;
		}
		case Mul24: {
			if( type != PTXOperand::u32 && type != PTXOperand::s32 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !( modifier & lo ) && !( modifier & hi ) ) {
				return "must be either lo or hi";
			}
			break;
		}
		case Mul: {
			if( type == PTXOperand::s8 || type == PTXOperand::u8 
				|| type == PTXOperand::b8 || type == PTXOperand::f16 
				|| type == PTXOperand::pred ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( PTXOperand::isInt( type ) && ( !( modifier & lo ) 
				&& !( modifier & hi ) && !( modifier & wide ) ) ) {
				return "int operations must be hi, lo, or wide";
			}
			if( ( ( modifier & lo ) || ( modifier & hi ) ) 
				&& a.bytes() != d.bytes() ) {
				std::stringstream stream;
				stream << "for lo and hi, size of operand A " << a.bytes() 
					<< " does not equal size of operand D " << d.bytes();
				return stream.str();
			}
			if( ( modifier & wide ) && ( 2 * a.bytes() != d.bytes() ) ) {
				std::stringstream stream;
				stream << "wide, size of operand A " << a.bytes() 
					<< " does not equal half the size of operand D " 
					<< d.bytes();
				return stream.str();
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Neg: {
			if( type != PTXOperand::s16 && type != PTXOperand::s32 && 
				type != PTXOperand::s64 && type != PTXOperand::f32 && 
				type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Nop: {
			return "NOP is not a valid instruction.";
			break;
		}
		case Not: {
			if( !( type == PTXOperand::b16 || type == PTXOperand::b32 || 
				type == PTXOperand::b64 || type == PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case Pmevent: {
			if( d.addressMode != PTXOperand::Immediate ) {
				return "only support Immediate targets";
			}
			break;
		}
		case Popc: {
			if( !( type == PTXOperand::b32 || type == PTXOperand::b64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( PTXOperand::u32, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " 
					+ PTXOperand::toString( PTXOperand::u32 );
			}
			break;
		}
		case Prmt: {
			if( type != PTXOperand::b32 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, c.type ) 
				&& c.addressMode != PTXOperand::Immediate ) {
				return "operand C type " + PTXOperand::toString( c.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case Or: {
			if( !( type == PTXOperand::b16 || type == PTXOperand::b32 || 
				type == PTXOperand::b64 || type == PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case Rcp: {
			if( ( modifier & approx ) ) {
				if( type != PTXOperand::f32 ) {
					return "only f32 supported for approximate";
				}
			}
			if( type != PTXOperand::f32 && type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( type == PTXOperand::f64 ) {
				if( !( modifier & rn ) && !( modifier & rz ) 
					&& !( modifier & rm ) && !( modifier & rp ) ) {
					return "requires a rounding modifier";
				}
				if( !( modifier & rn ) ) {
					return "only nearest rounding supported";
				}
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case Red: {
			if( ( reductionOperation == ReductionAnd 
				|| reductionOperation == ReductionOr
				|| reductionOperation == ReductionXor ) 
				&& type != PTXOperand::b32 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type ) + " for reduction " 
					+ toString( reductionOperation );
			}
			if( reductionOperation == ReductionAdd
				&& ( type != PTXOperand::u32 && type != PTXOperand::s32 
				&& type != PTXOperand::f32 && type != PTXOperand::u64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type ) + " for reduction " 
					+ toString( reductionOperation );
			}
			if( ( reductionOperation == ReductionInc
				|| reductionOperation == ReductionDec )
				&& type != PTXOperand::u32 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type ) + " for reduction " 
					+ toString( reductionOperation );
			}
			if( ( reductionOperation == ReductionMin
				|| reductionOperation == ReductionMax )
				&& ( type != PTXOperand::u32 && type != PTXOperand::s32 
				&& type != PTXOperand::f32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type ) + " for reduction " 
					+ toString( reductionOperation );
			}
			if( a.addressMode != PTXOperand::Address 
				&& a.addressMode != PTXOperand::Register 
				&& a.addressMode != PTXOperand::Indirect
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A must be an address";
			}
			if( addressSpace != Shared && addressSpace != Global ) {
				return "address space much be either shared or global";
			}
			break;
		}
		case Rem: {
			if( type != PTXOperand::s16 && type != PTXOperand::s32 
				&& type != PTXOperand::s64 && type != PTXOperand::u16 
				&& type != PTXOperand::u32 && type != PTXOperand::u64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;		
		}
		case Ret: {
			break;
		}
		case Rsqrt: {
			if( type != PTXOperand::f32 && type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;			
		}
		case Sad: {
			if( type != PTXOperand::s16 && type != PTXOperand::s32 
				&& type != PTXOperand::s64 && type != PTXOperand::u16 
				&& type != PTXOperand::u32 && type != PTXOperand::u64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, c.type ) 
				&& c.addressMode != PTXOperand::Immediate ) {
				return "operand C type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;		
		}
		case SelP: {
			if( type != PTXOperand::s16 && type != PTXOperand::s32 
				&& type != PTXOperand::s64 && type != PTXOperand::u16 
				&& type != PTXOperand::u32 && type != PTXOperand::u64
				&& type != PTXOperand::b16 && type != PTXOperand::b32 
				&& type != PTXOperand::b64 && type != PTXOperand::f32
				&& type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( c.type != PTXOperand::pred ) {
				return "operand C type " + PTXOperand::toString( c.type ) 
					+ " must be a predicate.";
			}
			break;
		}
		case Set: {
			if( type != PTXOperand::s16 && type != PTXOperand::s32 
				&& type != PTXOperand::s64 && type != PTXOperand::u16 
				&& type != PTXOperand::u32 && type != PTXOperand::u64
				&& type != PTXOperand::b16 && type != PTXOperand::b32 
				&& type != PTXOperand::b64 && type != PTXOperand::f32
				&& type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( d.type != PTXOperand::s32 && d.type != PTXOperand::f32 
				&& d.type != PTXOperand::u32 ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " invalid (must be u32, s32, or f32)";
			}
			if( c.type != PTXOperand::pred && 
				c.addressMode != PTXOperand::Invalid ) {
				return "operand C type " + PTXOperand::toString( c.type ) 
					+ " must be a predicate.";
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case SetP: {
			if( d.type != PTXOperand::pred ) {
				return "destination must be a predicate";
			}
			if( pq.type != PTXOperand::pred 
				&& pq.addressMode != PTXOperand::Invalid ) {
				return "Pq must be a predicate";
			}
			if( c.type != PTXOperand::pred 
				&& c.addressMode != PTXOperand::Invalid ) {
				return "operand C type " + PTXOperand::toString( c.type ) 
					+ " must be a predicate.";
			}
			if( type != PTXOperand::s16 && type != PTXOperand::s32 
				&& type != PTXOperand::s64 && type != PTXOperand::u16 
				&& type != PTXOperand::u32 && type != PTXOperand::u64
				&& type != PTXOperand::b16 && type != PTXOperand::b32 
				&& type != PTXOperand::b64 && type != PTXOperand::f32
				&& type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;			
		}
		case Shl: {
			if( type != PTXOperand::b16 && type != PTXOperand::b32 
				&& type != PTXOperand::b64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( d.bytes() != a.bytes() 
				&& a.addressMode != PTXOperand::Immediate ) {
				std::stringstream stream;
				stream << "size of operand A " << a.bytes() 
					<< " does not match size of operand D " << d.bytes();
				return stream.str(); 
			}
			if( b.bytes() != 4 && b.addressMode != PTXOperand::Immediate ) {
				std::stringstream stream;
				stream << "size of operand B " << a.bytes() 
					<< " must be 4 bytes";
				return stream.str();
			}
			break;
		}
		case Shr: {
			if( type != PTXOperand::b16 && type != PTXOperand::b32 
				&& type != PTXOperand::b64 && type != PTXOperand::s16 
				&& type != PTXOperand::s32 && type != PTXOperand::s64 
				&& type != PTXOperand::u16 && type != PTXOperand::u32 
				&& type != PTXOperand::u64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( d.bytes() != a.bytes() ) {
				std::stringstream stream;
				stream << "size of operand A " << a.bytes() 
					<< " does not match size of operand D " << d.bytes();
				return stream.str(); 
			}
			if( b.bytes() != 4 && b.addressMode != PTXOperand::Immediate ) {
				std::stringstream stream;
				stream << "size of operand B " << a.bytes() 
					<< " must be 4 bytes";
				return stream.str();
			}
			break;
		}
		case Sin: {
			if( !( type == PTXOperand::f32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case SlCt: {
			if( type != PTXOperand::s16 && type != PTXOperand::s32 
				&& type != PTXOperand::s64 && type != PTXOperand::u16 
				&& type != PTXOperand::u32 && type != PTXOperand::u64
				&& type != PTXOperand::b16 && type != PTXOperand::b32 
				&& type != PTXOperand::b64 && type != PTXOperand::f32
				&& type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			unsigned int bytes = PTXOperand::bytes( type );
			if( bytes != a.bytes() ) {
				std::stringstream stream;
				stream << "size of operand A " << a.bytes() 
					<< " does not match size of instruction " << bytes;
				return stream.str(); 	
			}
			if( bytes != b.bytes() ) {
				std::stringstream stream;
				stream << "size of operand B " << b.bytes() 
					<< " does not match size of instruction " << bytes;
				return stream.str(); 	
			}
			if( bytes != d.bytes() ) {
				std::stringstream stream;
				stream << "size of operand D " << d.bytes() 
					<< " does not match size of instruction " << bytes;
				return stream.str(); 	
			}
			if( !PTXOperand::valid( PTXOperand::f32, c.type ) 
				&& !PTXOperand::valid( PTXOperand::s32, c.type ) ) {
				return "operand C must be either s32 or f32 assignable";
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
			
		}
		case Sqrt: {
			if( ( modifier & approx ) ) {
				if( type != PTXOperand::f32 ) {
					return "only f32 supported for approximate";
				}
			}
			if( type != PTXOperand::f32 && type != PTXOperand::f64 ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( type == PTXOperand::f64 ) {
				if( !( modifier & rn ) && !( modifier & rz ) 
					&& !( modifier & rm ) && !( modifier & rp ) ) {
					return "requires a rounding modifier";
				}
				if( !( modifier & rn ) ) {
					return "only nearest rounding supported";
				}
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;			
		}
		case St: {
			if( d.addressMode != PTXOperand::Register 
				&& d.addressMode != PTXOperand::Address 
				&& d.addressMode != PTXOperand::Indirect 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "invalid address mode " 
					+ PTXOperand::toString( d.addressMode ) 
					+ " for operand D ";
			}
			if( ( addressSpace != Global && addressSpace != Shared ) 
				&& volatility == Volatile ) {
				return "only shared and global address spaces supported " 
					+ std::string( "for volatile stores" );
			}
			if( a.addressMode != PTXOperand::Register ) {
				return "operand A must be a register";
			}
			if( !PTXOperand::relaxedValid( type, a.type ) ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type ) 
					+ ", not even for relaxed typed instructions.";
			}
			break;
		}
		case Sub: {
			if ( !( type != PTXOperand::s8 && type != PTXOperand::u8 && 
				type != PTXOperand::b8 && type != PTXOperand::f16 
				&& type != PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( carry == CC ) {
				if( ( modifier & sat ) ) {
					return "saturate not supported with carry out";
				}
				if( !( type == PTXOperand::u32 || type == PTXOperand::s32 ) ) {
					return "invalid instruction type " 
						+ PTXOperand::toString( type );
				}
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}			
			if( !PTXOperand::valid( type, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( modifier & ftz ) {
				if( PTXOperand::isInt( type ) ) {
					return toString( ftz ) 
						+ " only valid for float point instructions.";
				}
			}
			break;
		}
		case SubC: {
			if( !( type == PTXOperand::u32 || type == PTXOperand::s32 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case TestP: {
			if( !( type == PTXOperand::f32 || type == PTXOperand::f64 ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( d.type != ir::PTXOperand::pred ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " should be a predicate instead.";
			}
			break;
		}
		case Tex: {
			if( a.addressMode != PTXOperand::Address ) {
				return "operand A must be a label with the texture name";
			}
			if( geometry == _2d && c.vec == PTXOperand::v1 ) {
				return "for 2d tectures, C must be a at least a 2d vector";
			}
			if( geometry == _3d && c.vec != PTXOperand::v2 
				&& c.vec != PTXOperand::v4  ) {
				return "for 3d textures, C must be at least a 4d vector";
			}
			if( !PTXOperand::valid( PTXOperand::s32, c.type ) 
				&& !PTXOperand::valid( PTXOperand::f32, c.type ) ) {
				return "operand C must be assignable to f32 or s32";
			}
			if( !PTXOperand::valid( PTXOperand::s32, type ) 
				&& !PTXOperand::valid( PTXOperand::f32, type )
				&& !PTXOperand::valid( PTXOperand::s32, type ) ) {
				return "instruction must be be assignable to u32, f32, or s32";
			}
			if( !PTXOperand::valid( type, c.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand C type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		case Trap: {
			break;
		}
		case Vote: {
			if( d.type != PTXOperand::pred ) {
				return "destination must be a predicate";
			}
			if( a.type != PTXOperand::pred ) {
				return "operand A must be a predicate";
			}
			break;
		}
		case Xor: {
			if( !( type == PTXOperand::b16 || type == PTXOperand::b32 || 
				type == PTXOperand::b64 || type == PTXOperand::pred ) ) {
				return "invalid instruction type " 
					+ PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, a.type ) 
				&& a.addressMode != PTXOperand::Immediate ) {
				return "operand A type " + PTXOperand::toString( a.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, d.type ) 
				&& d.addressMode != PTXOperand::Immediate ) {
				return "operand D type " + PTXOperand::toString( d.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			if( !PTXOperand::valid( type, b.type ) 
				&& b.addressMode != PTXOperand::Immediate ) {
				return "operand B type " + PTXOperand::toString( b.type ) 
					+ " cannot be assigned to " + PTXOperand::toString( type );
			}
			break;
		}
		default: return "check not implemented for " + toString(opcode); break;
	}
	return "";
}

std::string ir::PTXInstruction::guard() const {
	switch( pg.condition ) {
		case PTXOperand::PT: return ""; break;
		case PTXOperand::nPT: return "@!%pt "; break;
		case PTXOperand::Pred: return "@" + pg.toString() + " " ; break;
		case PTXOperand::InvPred: return "@!" + pg.toString() + " "; break;
	}
	return "";
}

std::string ir::PTXInstruction::toString() const {
	switch (opcode) {
		case Abs: {
			return guard() + "abs." + PTXOperand::toString( type ) + " " 
				+ d.toString() + ", " + a.toString();
		}
		case Add: {
			std::string result = guard() + "add.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " 
					+ d.toString() + ", " + a.toString() + ", " 
					+ b.toString();
			return result;
		}
		case AddC: {
			std::string result = guard() + "addc.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " 
					+ d.toString() + ", " + a.toString() + ", " 
					+ b.toString();
			return result;
		}
		case And: {
			return guard() + "and." + PTXOperand::toString( type ) + " " 
					+ d.toString() + ", " + a.toString() + ", " 
					+ b.toString();
		}
		case Atom: {
			std::string result = guard() + "atom." + toString( addressSpace ) 
				+ "." + toString( atomicOperation ) + "." 
				+ PTXOperand::toString( type ) + " "
				+ d.toString() + ", [" + a.toString() + "], " 
				+ b.toString();
			if( c.addressMode != PTXOperand::Invalid ) {
				result += ", " + c.toString();
			}
			return result;
		}
		case Bar: {
			return guard() + "bar.sync " + d.toString();
		}
		case Bfi: {
			return guard() + "bfi." + PTXOperand::toString( type ) + " " 
				+ d.toString() + ", " + pq.toString() + ", " + a.toString()
				+ ", " + b.toString() + ", " + c.toString();
		}
		case Bfind: {
			std::string result = guard() + "bfind.";
			if( shiftAmount ) result += "shiftamt.";
			result += PTXOperand::toString( type ) + " " 
				+ d.toString() + ", " + a.toString();
			return result;
		}
		case Bra: {
			std::string result = guard() + "bra";
			if( uni ) {
				result += ".uni";
			}
			return result + " " + d.toString();
		}
		case Brev: {
			return guard() + "brev." + PTXOperand::toString( type ) + " " 
				+ d.toString() + ", " + a.toString();
		}
		case Brkpt: {
			return guard() + "brkpt";
		}
		case Call: {
			std::string result = guard() + "call";
			if( uni ) {
				result += ".uni";
			}
			result += " ";
			if( d.addressMode != PTXOperand::Invalid ) {
				result += d.toString() + ", ";
			}
			result += a.toString() + ", " + b.toString();
			if( a.addressMode == PTXOperand::Register ) {
				result += ", " + c.toString();
			}
			return result;
		}
		case Clz: {
			return guard() + "clz." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString();
		}
		case CNot: {
			return guard() + "cnot." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString();
		}
		case Cos: {
			std::string result = guard() + "cos.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() 
				+ ", " + a.toString();
			return result;
		}
		case Cvt: {
			std::string result = guard() + "cvt.";
			if( PTXOperand::isFloat( d.type )) {
				if ((d.type == PTXOperand::f32 && a.type == PTXOperand::f64) 
					|| PTXOperand::isInt(a.type)) {
					result += modifierString( modifier, carry );
				}
			}
			else {
				if( modifier & rn ) {
					result += "rni.";
				} else if( modifier & rz ) {
					result += "rzi.";
				} else if( modifier & rm ) {
					result += "rmi.";
				} else if( modifier & rp ) {
					result += "rpi.";
				}
				if( modifier & sat ) {
					result += "sat.";
				}
			}			
			result += PTXOperand::toString( type ) + "." 
				+ PTXOperand::toString( a.type ) + " " + d.toString() + ", " 
				+ a.toString();
			return result;
		}
		case Div: {
			std::string result = guard() + "div.";
			if( divideFull ) {
				result += "full.";
			}
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() + ", " 
				+ a.toString() + ", " + b.toString();
			return result;
		}
		case Ex2: {
			std::string result = guard() + "ex2.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() 
				+ ", " + a.toString();
			return result;
		}
		case Exit: {
			return "exit";
		}
		case Ld: {
			std::string result = guard() + "ld.";
			if( volatility == Volatile ) {
				result += "volatile.";
			}
			if( addressSpace != AddressSpace_Invalid ) {
				result += toString(addressSpace) + ".";
			}
			if( d.vec != PTXOperand::v1 ) {
				result += toString( d.vec ) + ".";
			}
			result += PTXOperand::toString( type ) + " " + d.toString() + ", [" 
				+ a.toString() + "]";
			return result;
		}
		case Lg2: {
			std::string result = guard() + "lg2."; 
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() 
				+ ", " + a.toString();
			return result;
		}
		case Mad24: {
			std::string result = guard() + "mad24.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() + ", " 
				+ a.toString() + ", " + b.toString() + ", " + c.toString();
			return result;
		}
		case Mad: {
			std::string result = guard() + "mad.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() + ", " 
				+ a.toString() + ", " + b.toString() + ", " + c.toString();
			return result;
		}
		case Max: {
			return guard() + "max." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
		}
		case Membar: {
			return guard() + "membar." + toString( level );
		}
		case Min: {
			return guard() + "min." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
		}
		case Mov: {
			return guard() + "mov." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString();
		}
		case Mul24: {
			std::string result = guard() + "mul24.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() + ", " 
				+ a.toString() + ", " + b.toString();
			return result;
		}
		case Mul: {
			std::string result = guard() + "mul.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() + ", " 
				+ a.toString() + ", " + b.toString();
			return result;
		}
		case Neg: {
			return guard() + "neg." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString();
		}
		case Not: {
			return guard() + "not." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString();
		}
		case Pmevent: {
			return guard() + "pmevent." + toString( level );
		}
		case Popc: {
			return guard() + "popc." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString();
		}
		case Prmt: {
			std::string result = guard() + "prmt." 
				+ PTXOperand::toString( type );
			if( permuteMode != DefaultPermute )
			{
				result += "." + toString( permuteMode );
			}
			result += " " + d.toString() + ", " + a.toString() + ", " 
				+ b.toString() + ", " + c.toString();
			return result;
		}
		case Or: {
			return guard() + "or." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
		}
		case Rcp: {
			std::string result = guard() + "rcp.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString();
			return result;
		}
		case Red: {
			return guard() + "red." + toString( addressSpace ) + "." 
				+ toString( reductionOperation ) + "." 
				+ PTXOperand::toString( type ) + " " + d.toString() + ", " 
				+ a.toString();
		}
		case Rem: {
			return guard() + "rem." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
		}
		case Ret: {
			std::string result = guard() + "ret";
			if( uni ) {
				result += ".uni";
			}
			if( d.addressMode != ir::PTXOperand::Invalid )
			{
				result += " " + d.toString();
			}
			return result;
		}
		case Rsqrt: {
			std::string result = guard() + "rsqrt.";
			result += modifierString( modifier, carry );			
			result += PTXOperand::toString( type ) + " " + d.toString() 
				+ ", " + a.toString();			
			return result;
		}
		case Sad: {
			return guard() + "sad." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString() 
				+ ", " + c.toString();
		}
		case SelP: {
			return guard() + "selp." + PTXOperand::toString( type ) 
				+ " " + d.toString() + ", " + a.toString() + ", " + b.toString()
				+ ", " + c.toString();
		}
		case Set: {
			std::string result = guard() + "set." 
				+ toString( comparisonOperator ) + ".";
			if( c.addressMode != PTXOperand::Invalid ) {
				result += toString( booleanOperator ) + ".";
			}
			result += PTXOperand::toString( type ) + "." 
				+ PTXOperand::toString( a.type ) + " " + d.toString() 
				+ ", " + a.toString() + ", " + b.toString();
			if( c.addressMode != PTXOperand::Invalid ) {
				result += ", " + c.toString();
			}
			return result;				
		}
		case SetP: {
			std::string result = guard() + "setp." 
				+ toString( comparisonOperator ) + ".";
			if( c.addressMode != PTXOperand::Invalid ) {
				result += toString( booleanOperator ) + ".";
			}
			result += PTXOperand::toString( type ) + " " + d.toString();
			if( pq.addressMode != PTXOperand::Invalid && !isPt( pq ) ) {
				result += "|" + pq.toString();
			}
			result += ", " + a.toString() + ", " + b.toString();
			if( c.addressMode != PTXOperand::Invalid ) {
				result += ", " + c.toString();
			}
			return result;
		}
		case Shl: {
			return guard() + "shl." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
		}
		case Shr: {
			return guard() + "shr." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
		}
		case Sin: {
			std::string result = guard() + "sin.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() 
				+ ", " + a.toString();
			return result;
		}
		case SlCt: {
			return guard() + "slct." + PTXOperand::toString( type ) + "." 
				+ PTXOperand::toString( c.type ) + " " + d.toString() + ", " 
				+ a.toString() + ", " + b.toString() + ", " + c.toString();
		}
		case Sqrt: {
			std::string result = guard() + "sqrt.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " " + d.toString() 
				+ ", " + a.toString();
			return result;
		}
		case St: {
			std::string result = guard() + "st.";
			if( volatility == Volatile ) {
				result += "volatile.";
			}
			if( addressSpace != AddressSpace_Invalid ) {
				result += toString(addressSpace) + ".";
			}
			if( a.vec != PTXOperand::v1 ) {
				result += toString( a.vec ) + ".";
			}
			result += PTXOperand::toString( type ) + " [" + d.toString() + "], "
				+ a.toString();
			return result;
		}
		case Sub: {
			std::string result = guard() + "sub.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
			return result;
		}
		case SubC: {
			std::string result = guard() + "subc.";
			result += modifierString( modifier, carry );
			result += PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
			return result;
		}
		case TestP: {
			return guard() + "testp." + toString( floatingPointMode ) 
				+ "." + PTXOperand::toString( type ) + " " + d.toString() + ", " 
				+ a.toString();
		}
		case Tex: {
			return guard() + "tex." + toString( geometry ) + ".v4." 
				+ PTXOperand::toString( d.type ) + "." 
				+ PTXOperand::toString( type ) + " " + d.toString() + ", [" 
				+ a.toString() + ", " + c.toString() + "]"; 
		}
		case Trap: {
			return guard() + "trap";
		}
		case Vote: {
			return guard() + "vote." + toString( vote ) + ".pred " 
				+ d.toString() + ", " + a.toString();
		}
		case Xor: {
			return guard() + "xor." + PTXOperand::toString( type ) + " "
				+ d.toString() + ", " + a.toString() + ", " + b.toString();
		}
		case Reconverge: {
			return "reconverge";
		}
		default: break;
	}
	assertM(false, "Instruction opcode " << toString(opcode) 
		<< " not implemented.");
}

ir::Instruction* ir::PTXInstruction::clone(bool copy) const {
	if (copy) {
		return new PTXInstruction(*this);
	}
	else {
		return new PTXInstruction;
	}
}

