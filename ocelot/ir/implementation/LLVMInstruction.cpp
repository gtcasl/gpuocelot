/*!
	\file LLVMInstruction.cpp
	\date Tuesday July 21, 2009
	\author Gregroy Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMInstruction class.
*/

#ifndef LLVM_INSTRUCTION_CPP_INCLUDED
#define LLVM_INSTRUCTION_CPP_INCLUDED

#include <ocelot/ir/interface/LLVMInstruction.h>
#include <hydrazine/implementation/debug.h>

namespace ir
{
	LLVMInstruction::Type::Type( DataType t, Category c, LLVMI32 v ) 
		: type( t ), category( c ), vector( v )
	{
	
	}
	
	std::string LLVMInstruction::Type::toString() const
	{
		switch( category )
		{
			case Element:
			{
				return LLVMInstruction::toString( type );
				break;
			}
			case Array:
			{
				std::stringstream stream;
				stream << "[ " << vector << " x " 
					<< LLVMInstruction::toString( type ) << " ]";
				return stream.str();
				break;
			}
			case Function:
			{
				assertM( false, "Basic LLVM Type does not support \
					functions." );
				break;
			}
			case Structure:
			{
				assertM( false, "Basic LLVM Type does not support \
					structures." );
				break;
			}
			case PackedStructure:
			{
				assertM( false, "Basic LLVM Type does not support \
					packed structures." );
				break;
			}
			case Pointer:
			{
				return LLVMInstruction::toString( type ) + "*";
				break;
			}
			case Vector:
			{
				std::stringstream stream;
				stream << "< " << vector << " x " 
					<< LLVMInstruction::toString( type ) << " >";
				return stream.str();
				break;
			}
			case Opaque:
			{
				return label;
				break;
			}
			case InvalidCategory:
			{
				return "INVALID_CATEGORY";
				break;
			}
		}
		return "";
	}
		
	LLVMInstruction::Operand::Operand( const std::string& n, bool c, 
		const Type& t ) : name( n ), constant( c ), type( t )
	{
	
	}

	bool LLVMInstruction::Operand::valid() const
	{
		return type.category != Type::InvalidCategory;
	}

	std::string LLVMInstruction::Operand::toString() const
	{
		if( constant )
		{
			switch( type.category )
			{
				case Type::Element:
				{
					std::stringstream stream;
					switch( type.type )
					{
						case I1: stream << (((int) i1) & 0x1); break;
						case I8: stream << (~((int) (~i8 + 1)) + 1); break;
						case I16: stream << i16; break;
						case I32: stream << i32; break;
						case I64: stream << i64; break;
						case F32: stream << f32; break;
						case F64: stream << f64; break;
						case InvalidDataType: break;
					}
					return stream.str();
					break;
				}
				case Type::Array:
				{
					assertM( false, "Array constant not implemented." );
					break;
				}
				case Type::Function:
				{
					assertM( false, "Function constant not implemented." );
					break;
				}
				case Type::Structure:
				{
					assertM( false, "Structure constant not implemented." );
					break;
				}
				case Type::PackedStructure:
				{
					assertM( false, 
						"Packed Structure constant not implemented." );
					break;
				}
				case Type::Pointer:
				{
					assertM( false, "Pointer constant not implemented." );
					break;
				}
				case Type::Vector:
				{
					std::stringstream stream;
					stream << "< ";
					for( ValueVector::const_iterator fi = values.begin(); 
						fi != values.end(); ++fi )
					{
						if( fi != values.begin() ) stream << ", ";
						stream << LLVMInstruction::toString( type.type ) << " ";
						switch( type.type )
						{
							case I1: stream << (((int) fi->i1) & 0x1); break;
							case I8: stream << (~((int) (~fi->i8 + 1)) + 1); 
								break;
							case I16: stream << fi->i16; break;
							case I32: stream << fi->i32; break;
							case I64: stream << fi->i64; break;
							case F32: stream << fi->f32; break;
							case F64: stream << fi->f64; break;
							case InvalidDataType: break;
						}
					}
					stream << " >";
					return stream.str();
					break;
				}
				case Type::Opaque:
				{
					return "Opaque constant not implemented.";
					break;
				}
				case Type::InvalidCategory:
				{
					return "INVALID_CATEGORY";
					break;
				}
			}
		}
		else
		{
			return name;
		}
		return "";
	}

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

	std::string LLVMInstruction::toString( CallingConvention cc )
	{
		switch( cc )
		{
			case CCallingConvention: return "ccc"; break;
			case FastCallingConvention: return "fastcc"; break;
			case ColdCallingConvention: return "coldcc"; break;
			case DefaultCallingConvention: return ""; break;
			case InvalidCallingConvention: return "INVALID_CC"; break;
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
			case InvalidParameterAttribute: return ""; break;
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
			result += "alwaysinline";
		}
		if( attributes & NoInline )
		{
			if( !result.empty() ) result += " ";
			result += "noinline";
		}
		if( attributes & OptimizeSize )
		{
			if( !result.empty() ) result += " ";
			result += "optsize";
		}
		if( attributes & NoReturn )
		{
			if( !result.empty() ) result += " ";
			result += "noreturn";
		}
		if( attributes & NoUnwind )
		{
			if( !result.empty() ) result += " ";
			result += "nounwind";
		}
		if( attributes & ReadNone )
		{
			if( !result.empty() ) result += " ";
			result += "readnone";
		}
		if( attributes & ReadOnly )
		{
			if( !result.empty() ) result += " ";
			result += "readonly";
		}
		if( attributes & StackSmashingProtector )
		{
			if( !result.empty() ) result += " ";
			result += "ssp";
		}
		if( attributes & StackSmashingProtectorRequired )
		{
			if( !result.empty() ) result += " ";
			result += "sspreq";
		}
		if( attributes & NoRedZone )
		{
			if( !result.empty() ) result += " ";
			result += "noredzone";
		}
		if( attributes & NoImplicitFloat )
		{
			if( !result.empty() ) result += " ";
			result += "noimplicitfloat";
		}
		if( attributes & Naked )
		{
			if( !result.empty() ) result += " ";
			result += "naked";
		}
		return result;
	}

	bool LLVMInstruction::isInt( DataType d )
	{
		switch( d )
		{
			case I1: /* fall through */
			case I8: /* fall through */
			case I16: /* fall through */
			case I32: /* fall through */
			case I64: return true; break;
			case F32: /* fall through */
			case F64: /* fall through */
			default: break;
		}
		return false;
	}

	LLVMInstruction::LLVMInstruction( Opcode op ) : opcode( op )
	{
		
	}

	LLVMInstruction::LLVMInstruction( const LLVMInstruction& i ) 
		: opcode( i.opcode )
	{
	
	}
	
	const LLVMInstruction& LLVMInstruction::operator=( 
		const LLVMInstruction& i )
	{
		/* intentionally empty */
		assert( i.opcode == opcode );
		return *this;
	}

	LLVMUnaryInstruction::LLVMUnaryInstruction( Opcode op, 
		const Operand& _d, const Operand& _a ) : LLVMInstruction( op ), 
		d( _d ), a( _a )
	{
	
	}
	
	std::string LLVMUnaryInstruction::toString() const
	{
		return d.toString() + " = " + LLVMInstruction::toString( opcode ) + " " 
			+ a.type.toString() + " " + a.toString();
	}
	std::string LLVMUnaryInstruction::valid() const
	{
		if( a.type.toString() != d.type.toString() )
		{
			return "Source operand type " + a.type.toString() 
				+ " does not equal destination operand type " 
				+ d.type.toString();
		}
		return "";
	}

	LLVMBinaryInstruction::LLVMBinaryInstruction( Opcode op, 
		const Operand& _d, const Operand& _a, const Operand& _b )
		: LLVMInstruction( op ), d( _d ), a( _a ), b( _b )
	{
	
	}

	std::string LLVMBinaryInstruction::toString() const
	{
		return d.toString() + " = " + LLVMInstruction::toString( opcode ) + " " 
			+ a.type.toString() + " " + a.toString() + ", " + b.toString();
	}

	std::string LLVMBinaryInstruction::valid() const
	{
		if( a.type.toString() != d.type.toString() )
		{
			return "First source operand type " + a.type.toString() 
				+ " does not equal destination operand type " 
				+ d.type.toString();
		}
		if( b.type.toString() != d.type.toString() )
		{
			return "First source operand type " + a.type.toString() 
				+ " does not equal destination operand type " 
				+ d.type.toString();
		}
		return "";
	}
	
	LLVMConversionInstruction::LLVMConversionInstruction( Opcode op, 
		const Operand& d, const Operand& a ) : LLVMUnaryInstruction( op, d, a )
	{
		
	}

	std::string LLVMConversionInstruction::toString() const
	{
		return d.toString() + " = " + LLVMInstruction::toString( opcode ) + " " 
			+ a.type.toString() + " " + a.toString() + " to " 
			+ d.type.toString();
	}

	std::string LLVMConversionInstruction::valid() const
	{
		return "";
	}

	LLVMComparisonInstruction::LLVMComparisonInstruction( Opcode op )
		: LLVMBinaryInstruction( op )
	{
	
	}
	
	std::string LLVMComparisonInstruction::toString() const
	{
		return d.toString() + " = " + LLVMInstruction::toString( opcode ) + " " 
			+ LLVMInstruction::toString( comparison ) + " " 
			+ a.type.toString() + " " + a.toString() + ", " + b.toString();
	}
	
	std::string LLVMComparisonInstruction::valid() const
	{
		if( a.type.toString() != d.type.toString() )
		{
			return "First source operand type " + a.type.toString() 
				+ " does not equal destination operand type " 
				+ d.type.toString();
		}
		if( b.type.toString() != d.type.toString() )
		{
			return "First source operand type " + a.type.toString() 
				+ " does not equal destination operand type " 
				+ d.type.toString();
		}
		return "";	
	}

	LLVMAdd::LLVMAdd( const Operand& d, const Operand& a, const Operand& b, 
		LLVMI1 nuw, LLVMI1 nsw ) : LLVMBinaryInstruction( Add, d, a, b ), 
		noUnsignedWrap( nuw ), noSignedWrap( nsw )
	{
	
	}
	
	std::string LLVMAdd::toString() const
	{
		std::string result = d.toString() + " = " 
			+ LLVMInstruction::toString( opcode ) + " ";
		if( noUnsignedWrap ) result += "nuw ";
		if( noSignedWrap ) result += "nsw ";
		result += a.type.toString() + " " + a.toString() + ", " + b.toString();		
		return result;
	}
	
	std::string LLVMAdd::valid() const
	{
		return LLVMBinaryInstruction::valid();
	}

	LLVMAlloca::LLVMAlloca( LLVMI32 e, LLVMI32 a ) : LLVMInstruction( Alloca ), 
		elements( e ), alignment( a )
	{
		
	}
	
	std::string LLVMAlloca::toString() const
	{
		std::stringstream stream;
		stream << d.toString() << " = " 
			<< LLVMInstruction::toString( opcode ) << " " 
			<< LLVMInstruction::toString( d.type.type );
		if( elements != 1 ) stream << ", i32 " << elements;
		if( alignment != 1 ) stream << ", align " << alignment;
		return stream.str();		
	}
	
	std::string LLVMAlloca::valid() const
	{
		if( alignment == 0 )
		{
			return "Alignment cannot be 0";
		}
		if( d.type.category != Type::Pointer )
		{
			return "Destination must be a pointer to a type";
		}
		return "";
	}

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
	
	std::string LLVMBr::toString() const
	{
		std::string result = LLVMInstruction::toString( opcode ) + " ";
		if( condition.valid() ) result += condition.type.toString() + " " 
			+ condition.toString() + ", ";
		result += "label " + iftrue;
		if( condition.valid() ) result += ", label " + iffalse;
		return result;		
	}
	
	std::string LLVMBr::valid() const
	{
		if( iftrue.empty() ) return "Target label must not be empty";
		
		if( condition.valid() )
		{
			if( iffalse.empty() ) 
			{
				return "For conditional branch, if-false \
					label must not be empty";
			}
			if( condition.type.type != I1 )
			{
				return "Condition type " 
					+ LLVMInstruction::toString( condition.type.type ) 
					+ " not valid for Br, only i1 is valid.";
			}
		}
		return "";
	}

	LLVMCall::LLVMCall() : LLVMInstruction( Call ), tail( false ), 
		convention( DefaultCallingConvention ), 
		returnAttributes( InvalidParameterAttribute ),
		functionAttributes( 0 )
	{
	
	}
	
	std::string LLVMCall::toString() const
	{
		std::string result;
		if( d.valid() ) result += d.name + " = ";
		if( tail ) result += "tail ";
		result += LLVMInstruction::toString( opcode ) + " ";
		std::string cc = LLVMInstruction::toString( convention );
		if( !cc.empty() ) result += cc + " ";
		std::string retats = LLVMInstruction::toString( returnAttributes );
		if( !retats.empty() ) result += retats + " ";
		if( !d.valid() )
		{
			result += "void ";
		}
		else
		{
			result += d.type.toString() + " ";
		}
		result += name + "(";
		for( OperandVector::const_iterator fi = parameters.begin(); 
			fi != parameters.end(); ++fi )
		{
			if( fi != parameters.begin() ) result += ", ";
			result += fi->type.toString() + " " + fi->name;
		}
		result += ")";
		std::string funats = LLVMInstruction::functionAttributesToString( 
			functionAttributes );
		if( !funats.empty() ) result += " " + funats;
		return result;
	}
	
	std::string LLVMCall::valid() const
	{
		switch( returnAttributes )
		{
			case ZeroExtend: /* fall through */
			case SignExtend: /* fall through */
			case InRegister: /* fall through */
			case InvalidParameterAttribute: break;
			case ByValue: /* fall through */
			case StructureReturn: /* fall through */
			case NoAlias: /* fall through */
			case NoCapture: /* fall through */
			case Nested: return LLVMInstruction::toString( returnAttributes ) 
				+ " not allowed in call";
		}
		
		// Only 'noreturn', 'nounwind', 'readonly' and 'readnone' attributes 
		// are valid here.
		if( functionAttributes & AlwaysInline )
		{
			return "alwaysinline not allowed in call";
		}
		if( functionAttributes & NoInline )
		{
			return "noinline not allowed in call";
		}
		if( functionAttributes & OptimizeSize  )
		{
			return "optsize not allowed in call";
		}
		if( functionAttributes & StackSmashingProtector )
		{
			return "ssp not allowed in call";
		}
		if( functionAttributes & StackSmashingProtectorRequired )
		{
			return "sspreq not allowed in call";
		}
		if( functionAttributes & NoRedZone )
		{
			return "noredzone not allowed in call";
		}
		if( functionAttributes & NoImplicitFloat )
		{
			return "noimplicitfloat not allowed in call";
		}
		return "";
	}

	LLVMExtractelement::LLVMExtractelement() 
		: LLVMBinaryInstruction( Extractelement )
	{
	
	}
	
	std::string LLVMExtractelement::toString() const
	{
		return LLVMBinaryInstruction::toString();
	}
	
	std::string LLVMExtractelement::valid() const
	{
		if( a.type.category != Type::Vector )
		{
			return "First operand must be a vector";
		}
		if( b.type.type != I32 )
		{
			return "Index must be i32 type";
		}
		if( a.type.type != d.type.type )
		{
			return "Destination primitive datatype " 
				+ LLVMInstruction::toString( d.type.type ) 
				+ " does not match source datatype " 
				+ LLVMInstruction::toString( a.type.type );
		}
		return "";
	}

	LLVMExtractvalue::LLVMExtractvalue() : LLVMInstruction( Extractvalue )
	{
		
	}
	
	std::string LLVMExtractvalue::toString() const
	{
		std::stringstream stream;
		stream << d.toString() << " = " 
			<< LLVMInstruction::toString( opcode ) << " " << a.toString() 
			<< " " << a.toString();
		for( IndexVector::const_iterator fi = indices.begin(); 
			fi != indices.end(); ++fi )
		{
			stream << ", " << *fi; 
		}
		return stream.str();
	}
	
	std::string LLVMExtractvalue::valid() const
	{
		if( a.type.category != Type::Structure )
		{
			return "Source operand must be a structure";
		}
		// TODO: add a check that the type at the index matches the destination
		return "";
	}

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
	
	std::string LLVMGetelementptr::toString() const
	{
		std::stringstream stream;
		stream << d.toString() << " = " 
			<< LLVMInstruction::toString( opcode ) << " " 
			<< a.toString() << " " << a.toString();
		for( IndexVector::const_iterator fi = indices.begin(); 
			fi != indices.end(); ++fi )
		{
			stream << ", i32 " << *fi; 
		}
		return stream.str();		
	}
	
	std::string LLVMGetelementptr::valid() const
	{
		if( a.type.category != Type::Structure )
		{
			return "Source operand must be a structure";
		}
		// TODO: add a check that the type at the index matches the destination
		return "";
	}

	LLVMIcmp::LLVMIcmp() : LLVMComparisonInstruction( Icmp )
	{
	
	}

	LLVMInsertelement::LLVMInsertelement() 
		: LLVMBinaryInstruction( Insertelement )
	{
	
	}
	
	std::string LLVMInsertelement::toString() const
	{
		return d.toString() + " = " + LLVMInstruction::toString( opcode ) + " " 
			+ a.type.toString() + " " + a.toString() + ", " + b.type.toString() 
			+ ", " + c.type.toString() + " " + c.toString();
	}
	
	std::string LLVMInsertelement::valid() const
	{
		if( d.type.type != b.type.type )
		{
			return "Destination base type " 
				+ LLVMInstruction::toString( d.type.type ) 
				+ " does not equal source element type " 
				+ LLVMInstruction::toString( b.type.type );
		}
		if( d.type.category != Type::Vector )
		{
			return "Destination is not a vector";
		}
		if( a.type.category != Type::Vector )
		{
			return "Source is not a vector";
		}
		if( a.type.toString() != d.type.toString() )
		{
			return "Destination type " + d.type.toString() 
				+ " does not match source type " + a.type.toString();
		}
		if( c.type.toString() != "i32" )
		{
			return "Index type " + c.type.toString() + " is not i32";
		}
		return "";
	}

	LLVMInsertvalue::LLVMInsertvalue() : LLVMInstruction( Insertvalue )
	{
	
	}
	
	std::string LLVMInsertvalue::toString() const
	{
		std::string result = d.toString() + " = " 
			+ LLVMInstruction::toString( opcode ) + " " + a.type.toString() 
			+ " " + a.toString() + ", " + b.type.toString();
		for( OperandVector::const_iterator fi = indices.begin(); 
			fi != indices.end(); ++fi )
		{
			result += ", " + fi->name;
		}
		return result;
	}
	
	std::string LLVMInsertvalue::valid() const
	{
		if( d.type.category != Type::Structure )
		{
			return "Destination is not a structure";
		}
		if( a.type.category != Type::Structure )
		{
			return "Source is not a structure";
		}
		if( d.type.toString() != a.type.toString() )
		{
			return "Source type " + a.type.toString() 
				+ " does not match destination type " + d.type.toString();
		}
		// TODO: Add a check to make sure that the inserted type matches 
		//	the desintation's type
		for( OperandVector::const_iterator fi = indices.begin(); 
			fi != indices.end(); ++fi )
		{
			if( fi->type.toString() != "i32" )
			{
				std::stringstream stream;
				stream << "Index " << std::distance( indices.begin(), fi ) 
					<< " type " << fi->type.toString() << " is not i32";
				return stream.str();
			}
		}
		return "";
	}

	LLVMInttoptr::LLVMInttoptr() : LLVMConversionInstruction( Inttoptr )
	{
	
	}

	LLVMInvoke::LLVMInvoke() : LLVMInstruction( Invoke )
	{
	
	}
	
	std::string LLVMInvoke::toString() const
	{
		std::string result;
		if( d.valid() ) result += d.toString() + " = ";
		std::string cc = LLVMInstruction::toString( convention );
		if( !cc.empty() ) result += cc + " ";
		std::string retats = LLVMInstruction::toString( returnAttributes );
		if( !retats.empty() ) result += retats + " ";
		if( !d.valid() )
		{
			result += "void ";
		}
		else
		{
			result += d.type.toString() + " ";
		}
		result += d.toString() + "( ";
		for( OperandVector::const_iterator fi = parameters.begin(); 
			fi != parameters.end(); ++fi )
		{
			if( fi != parameters.begin() ) result += ", ";
			result += fi->type.toString();
		}
		result += ")";
		std::string funats 
			= LLVMInstruction::functionAttributesToString( functionAttributes );
		if( !funats.empty() ) result += " " + funats;
		result += " to label " + tolabel + " unwind label " + unwindlabel;
		return result;
	}
	
	std::string LLVMInvoke::valid() const
	{
		switch( returnAttributes )
		{
			case ZeroExtend: /* fall through */
			case SignExtend: /* fall through */
			case InRegister: /* fall through */
			case InvalidParameterAttribute: break;
			case ByValue: /* fall through */
			case StructureReturn: /* fall through */
			case NoAlias: /* fall through */
			case NoCapture: /* fall through */
			case Nested: return LLVMInstruction::toString( returnAttributes ) 
				+ " not allowed in invoke";
		}
		
		// Only 'noreturn', 'nounwind', 'readonly' and 'readnone' attributes 
		// are valid here.
		if( functionAttributes & AlwaysInline )
		{
			return "alwaysinline not allowed in invoke";
		}
		if( functionAttributes & NoInline )
		{
			return "noinline not allowed in invoke";
		}
		if( functionAttributes & OptimizeSize  )
		{
			return "optsize not allowed in invoke";
		}
		if( functionAttributes & StackSmashingProtector )
		{
			return "ssp not allowed in invoke";
		}
		if( functionAttributes & StackSmashingProtectorRequired )
		{
			return "sspreq not allowed in invoke";
		}
		if( functionAttributes & NoRedZone )
		{
			return "noredzone not allowed in invoke";
		}
		if( functionAttributes & NoImplicitFloat )
		{
			return "noimplicitfloat not allowed in invoke";
		}
		
		if( tolabel.empty() ) return "invoke requires a to label";
		if( unwindlabel.empty() ) return "invoke requires an unwind label";
		
		return "";
	}

	LLVMLoad::LLVMLoad() : LLVMUnaryInstruction( Load ), isVolatile( false ), 
		alignment( 1 )
	{
	
	}
	
	std::string LLVMLoad::toString() const
	{
		std::stringstream stream;
		stream << d.toString() << " = ";
		if( isVolatile ) stream << "volatile ";
		stream << LLVMInstruction::toString( opcode ) << " " 
			<< a.type.toString() << " " << a.toString() << ", align " 
			<< alignment;
		return stream.str();
	}
	
	std::string LLVMLoad::valid() const
	{
		if( alignment == 0 ) return "Alignment must be greater than 0";
		if( a.type.category != Type::Pointer )
		{
			return "Address must be a pointer";
		}
		if( a.type.type != d.type.type )
		{
			return "Source " + a.type.toString() 
				+ " is not a pointer to destination type " + d.type.toString();
		}
		return "";
	}

	LLVMLshr::LLVMLshr() : LLVMBinaryInstruction( Lshr )
	{
	
	}

	LLVMMalloc::LLVMMalloc() : LLVMInstruction( Malloc ), elements( 1 ), 
		alignment( 1 )
	{
	
	}
	
	std::string LLVMMalloc::toString() const
	{
		std::stringstream stream;
		stream << d.toString() << " = " 
			<< LLVMInstruction::toString( opcode ) << " " << d.type.toString();
		if( elements != 1 ) stream << ", " << elements;
		if( alignment != 1 ) stream << ", align " << alignment;
		return stream.str();
	}
	
	std::string LLVMMalloc::valid() const
	{
		if( alignment == 0 )
		{
			return "Alignment cannot be 0";
		}
		return "";	
	}

	LLVMMul::LLVMMul() : LLVMBinaryInstruction( Mul ), noUnsignedWrap( false ),
		noSignedWrap( false )
	{
	
	}
	
	std::string LLVMMul::toString() const
	{
		std::string result = d.toString() + " = " 
			+ LLVMInstruction::toString( opcode ) + " ";
		if( noUnsignedWrap ) result += "nuw ";
		if( noSignedWrap ) result += "nsw ";
		result += a.type.toString() + " " + a.toString() + ", " + b.toString();		
		return result;	
	}
	
	LLVMOr::LLVMOr() : LLVMBinaryInstruction( Or )
	{
	
	}
	
	LLVMPhi::LLVMPhi() : LLVMInstruction( Phi )
	{
	
	} 
	
	std::string LLVMPhi::toString() const
	{
		std::string result = d.toString() + " = " 
			+ LLVMInstruction::toString( opcode ) + " " 
			+ d.type.toString() + " ";
		for( NodeVector::const_iterator ni = nodes.begin(); 
			ni != nodes.end(); ++ni )
		{
			if( ni != nodes.begin() )
			{
				result += ", ";
			}
			result += "[ " + ni->operand.toString() + ", " + ni->label + " ]";
		}
		return result;
	}
	
	std::string LLVMPhi::valid() const
	{
		for( NodeVector::const_iterator ni = nodes.begin(); 
			ni != nodes.end(); ++ni )
		{
			if( ni->operand.type.toString() != d.type.toString() )
			{
				return "Phi node from block " + ni->label + " type " 
					+ ni->operand.type.toString() 
					+ " does not match destination type " + d.type.toString();
			}
		}
		if( nodes.empty() ) return "No phi nodes";
		return "";
	}

	LLVMPtrtoint::LLVMPtrtoint() : LLVMConversionInstruction( Ptrtoint )
	{
	
	}

	LLVMRet::LLVMRet() : LLVMInstruction( Ret )
	{
	
	}
	
	std::string LLVMRet::toString() const
	{
		if( d.valid() )
		{
			return LLVMInstruction::toString( opcode ) + " " + d.toString();
		}
		else
		{
			return LLVMInstruction::toString( opcode ) + " void";
		}
	}
	
	std::string LLVMRet::valid() const
	{
		return "";
	}

	LLVMSdiv::LLVMSdiv() : LLVMBinaryInstruction( Sdiv ), exact( false )
	{
	
	}
	
	std::string LLVMSdiv::toString() const
	{
		std::string result = d.toString() + " = " 
			+ LLVMInstruction::toString( opcode ) + " ";
		if( exact ) result += "exact ";
		result += d.type.toString() + " " + a.toString() + ", " + b.toString();
		return result;
	}

	LLVMSelect::LLVMSelect() : LLVMBinaryInstruction( Select )
	{
	
	}
	
	std::string LLVMSelect::toString() const
	{
		std::string result = d.toString() + " = " 
			+ LLVMInstruction::toString( opcode ) + " " 
			+ condition.type.toString() + " " + condition.toString() + ", " 
			+ a.type.toString() + " " + a.toString() + ", " + b.type.toString() 
			+ " " + b.toString();
		return result;
	}
	
	std::string LLVMSelect::valid() const
	{
		if( condition.type.type != I1 ) return "Condition base type must be i1";
		return LLVMBinaryInstruction::valid();
	}

	LLVMSext::LLVMSext() : LLVMConversionInstruction( Sext )
	{
	
	}

	LLVMShl::LLVMShl() : LLVMBinaryInstruction( Shl )
	{
	
	}

	LLVMShufflevector::LLVMShufflevector() 
		: LLVMBinaryInstruction( Shufflevector )
	{
	
	}
	
	std::string LLVMShufflevector::toString() const
	{
		std::stringstream stream;
		stream << d.toString() << " = " << LLVMInstruction::toString( opcode ) 
			<< a.type.toString() << " " << a.toString() << ", " 
			<< b.type.toString() << " " << b.toString() << ", < ";
		for( Mask::const_iterator fi = mask.begin(); fi != mask.end(); ++fi )
		{
			if( fi != mask.begin() ) stream << ", ";
			stream << "i32 " << *fi;
		}
		stream << " >";
		return stream.str();
	}
	
	std::string LLVMShufflevector::valid() const
	{
		if( d.type.category != Type::Vector )
		{
			return "Destination must be a vector";
		}
		if( a.type.category != Type::Vector && a.valid() )
		{
			return "Source A must be a vector or undef";
		}
		if( b.type.category != Type::Vector && b.valid() )
		{
			return "Source B must be a vector or undef";
		}
		if( mask.size() != ( unsigned int ) 2 * d.type.vector )
		{
			std::stringstream stream;
			stream << "Mask size " << mask.size() 
				<< " is not twice of vector size " << d.type.vector;
			return stream.str();
		}
		for( Mask::const_iterator fi = mask.begin(); fi != mask.end(); ++fi )
		{
			if( *fi >= 2 * d.type.vector )
			{
				std::stringstream stream;
				stream << "For mask element " 
					<< std::distance( mask.begin(), fi ) << ", index " 
					<< *fi << " is beyond maximum vector index " 
					<< ( 2 * d.type.vector );
				return stream.str();
			}
		}
		return LLVMBinaryInstruction::valid();
	}

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
	
	std::string LLVMStore::toString() const
	{
		std::stringstream stream;
		if( isVolatile ) stream << "volatile";
		stream << LLVMInstruction::toString( opcode ) << " " 
			<< a.type.toString() << " " << a.toString() << ", " 
			<< d.type.toString() << " " << d.toString();
		if( alignment != 1 ) stream << ", align " << alignment;
		return stream.str();
	}
	
	std::string LLVMStore::valid() const
	{
		if( alignment == 0 ) return "Alignment must be greater than 0";
		if( d.type.category != Type::Pointer )
		{
			return "Address must be a pointer";
		}
		if( a.type.type != d.type.type )
		{
			return "Destination " + d.type.toString() 
				+ " is not a pointer to source type " + a.type.toString();
		}
		return "";
	}

	LLVMSub::LLVMSub() : LLVMBinaryInstruction( Sub ), noUnsignedWrap( false ),
		noSignedWrap( false )
	{
	
	}
	
	std::string LLVMSub::toString() const
	{
		std::string result = d.toString() + " = " 
			+ LLVMInstruction::toString( opcode ) + " ";
		if( noUnsignedWrap ) result += "nuw ";
		if( noSignedWrap ) result += "nsw ";
		result += a.type.toString() + " " + a.toString() + ", " + b.toString();		
		return result;		
	}

	LLVMSwitch::LLVMSwitch() : LLVMInstruction( Switch )
	{
	
	}
	
	std::string LLVMSwitch::toString() const
	{
		std::string result = LLVMInstruction::toString( opcode ) + " " 
			+ comparison.type.toString() + " " + comparison.toString() 
			+ ", label " + defaultTarget + " [ ";
		for( NodeVector::const_iterator fi = targets.begin(); 
			fi != targets.end(); ++fi )
		{
			result += fi->operand.type.toString() + " " + fi->operand.toString() 
				+ ", label " + fi->label;
		}
		result += " ]";
		return result;
	}
	
	std::string LLVMSwitch::valid() const
	{
		if( comparison.type.category != Type::Element )
		{
			return "Comparison value must be a basic element type";
		}
		if( !isInt( comparison.type.type ) )
		{
			return "Comparison value must be an int type";
		}
		if( defaultTarget.empty() ) return "Default target must not be empty";
		for( NodeVector::const_iterator fi = targets.begin(); 
			fi != targets.end(); ++fi )
		{
			if( fi->operand.type.category != Type::Element )
			{
				std::stringstream stream;
				stream << "Target " << std::distance( targets.begin(), fi ) 
					<< " is not a basic element type";
				return stream.str();
			}
			if( !isInt( fi->operand.type.type ) )
			{
				std::stringstream stream;
				stream << "Target " << std::distance( targets.begin(), fi ) 
					<< " is not an int type";
				return stream.str();
			}
			if( fi->label.empty() )
			{
				std::stringstream stream;
				stream << "Target " << std::distance( targets.begin(), fi ) 
					<< " has an empty target label";
				return stream.str();
			}
		}
		return "";
	}

	LLVMTrunc::LLVMTrunc() : LLVMConversionInstruction( Trunc )
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
	
	std::string LLVMUnreachable::toString() const
	{
		return LLVMInstruction::toString( opcode );
	}
	
	std::string LLVMUnreachable::valid() const
	{
		return "";
	}

	LLVMUnwind::LLVMUnwind() : LLVMInstruction( Unwind )
	{
	
	}
	
	std::string LLVMUnwind::toString() const
	{
		return LLVMInstruction::toString( opcode );
	}
	
	std::string LLVMUnwind::valid() const
	{
		return "";
	}

	LLVMUrem::LLVMUrem() : LLVMBinaryInstruction( Urem )
	{
	
	}

	LLVMVaArg::LLVMVaArg() : LLVMUnaryInstruction( VaArg )
	{
	
	}
	
	std::string LLVMVaArg::toString() const
	{
		return d.toString() + " = " + LLVMInstruction::toString( opcode ) 
			+ a.type.toString() + " " + a.toString() + ", " 
			+ d.type.toString();
	}
	
	std::string LLVMVaArg::valid() const
	{
		/* TODO Extra testing is needed here to make sure that any operands 
			are really valid. */
		return "";
	}

	LLVMXor::LLVMXor() : LLVMBinaryInstruction( Xor )
	{
	
	}

	LLVMZext::LLVMZext() : LLVMConversionInstruction( Zext )
	{
	
	}
	
}

#endif

