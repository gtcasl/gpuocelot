/*!

	\file PTXParser.cpp
	
	\date Monday January 19, 2009
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>

	\brief The source file for the PTXParser class.

*/

#ifndef PTX_PARSER_CPP_INCLUDED
#define PTX_PARSER_CPP_INCLUDED

#include <ocelot/parser/interface/PTXParser.h>
#include <cassert>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace ptx1_4
{ 
	extern int yyparse( parser::PTXLexer&, parser::PTXParser::State& );
}

namespace ptx1_3
{ 
	extern int yyparse( parser::PTXLexer&, parser::PTXParser::State& );
}

namespace parser
{

	const char* PTXParser::Exception::what() const throw()
	{
	
		return message.c_str();
	
	}

	PTXParser::Exception::~Exception() throw()
	{
	
	
	}

	std::string PTXParser::toString( YYLTYPE& location, State& state )
	{
		std::stringstream stream;
		stream << state.fileName << " (" << location.first_line << ", " 
			<< location.first_column << "): ";
		return stream.str();
	}

	void PTXParser::checkLables()
	{
	
		typedef std::unordered_map< std::string, ir::PTXStatement > 
			StatementMap;
		
		report( "Checking labels." );
		
		StatementMap labels;
		
		for( ir::Module::StatementVector::iterator 
			statement = state.module.statements.begin(); 
			statement != state.module.statements.end(); ++statement )
		{
		
			if( statement->directive == ir::PTXStatement::Label )
			{
			
				report( " Found label " << statement->name );
			
				StatementMap::iterator label = 
					labels.find( statement->name );
				
				if( label != labels.end() )
				{
				
					std::stringstream error;
					error << state.fileName << " ("  << statement->line << "," 
						<< statement->column << "): Duplicate label "
						<< statement->name << " previously defined at (" 
						<< label->second.line << "," << label->second.column 
						<< ")";
						
					Exception exception;
					exception.message = error.str();
					exception.error = State::DuplicateLabel;
					throw exception;
				
				}
				
				labels.insert( std::make_pair( statement->name, *statement ) );
			
			}
		
		}
		
		for( ir::Module::StatementVector::iterator 
			statement = state.module.statements.begin(); 
			statement != state.module.statements.end(); ++statement )
		{
		
			if( statement->directive == ir::PTXStatement::Instr )
			{
			
				if( statement->instruction.a.addressMode 
					== ir::PTXOperand::Label )
				{
				
					StatementMap::iterator label = 
						labels.find( statement->instruction.a.identifier );
				
					if( label == labels.end() )
					{
				
						std::stringstream error;
						error << state.fileName << " ("  << statement->line 
							<< "," << statement->column << "): Label "
							<< statement->instruction.a.identifier 
							<< " not delcared in this scope";
						
						Exception exception;
						exception.message = error.str();
						exception.error = State::NoLabel;
						throw exception;
				
					}
				
				}
				
				if( statement->instruction.b.addressMode 
					== ir::PTXOperand::Label )
				{
				
					StatementMap::iterator label = 
						labels.find( statement->instruction.b.identifier );
				
					if( label == labels.end() )
					{
				
						std::stringstream error;
						error << state.fileName << " ("  << statement->line 
							<< "," << statement->column << "): Label "
							<< statement->instruction.b.identifier 
							<< " not delcared in this scope";
						
						Exception exception;
						exception.message = error.str();
						exception.error = State::NoLabel;
						throw exception;
				
					}
				
				}
				
				if( statement->instruction.c.addressMode 
					== ir::PTXOperand::Label )
				{
				
					StatementMap::iterator label = 
						labels.find( statement->instruction.c.identifier );
				
					if( label == labels.end() )
					{
				
						std::stringstream error;
						error << state.fileName << " ("  << statement->line 
							<< "," << statement->column << "): Label "
							<< statement->instruction.c.identifier 
							<< " not delcared in this scope";
						
						Exception exception;
						exception.message = error.str();
						exception.error = State::NoLabel;
						throw exception;
				
					}
				
				}
				
				if( statement->instruction.d.addressMode 
					== ir::PTXOperand::Label )
				{
				
					StatementMap::iterator label = 
						labels.find( statement->instruction.d.identifier );
				
					if( label == labels.end() )
					{
				
						std::stringstream error;
						error << state.fileName << " ("  << statement->line 
							<< "," << statement->column << "): Label "
							<< statement->instruction.d.identifier 
							<< " not delcared in this scope";
						
						Exception exception;
						exception.message = error.str();
						exception.error = State::NoLabel;
						throw exception;
				
					}
				
				}
			
			}
		
		}
	
	}
	
	void PTXParser::reset()
	{
		state.module.statements.clear();
		state.module.kernels.clear();
		state.fileName = fileName;
		
		ir::PTXOperand bucket;
		bucket.identifier = "_";
		bucket.type = ir::PTXOperand::b64;
		bucket.addressMode = ir::PTXOperand::Register;
		bucket.vec = ir::PTXOperand::v1;
		
		state.operands.insert( std::make_pair( "_", bucket ) );
	}

	ir::PTXOperand::DataType PTXParser::tokenToDataType( int token )
	{
	
		switch( token )
		{
			
			case TOKEN_U8: return ir::PTXOperand::u8; break;
			case TOKEN_U16: return ir::PTXOperand::u16; break;
			case TOKEN_U32: return ir::PTXOperand::u32; break;
			case TOKEN_U64: return ir::PTXOperand::u64; break;
			case TOKEN_S8: return ir::PTXOperand::s8; break;
			case TOKEN_S16: return ir::PTXOperand::s16; break;
			case TOKEN_S32: return ir::PTXOperand::s32; break;
			case TOKEN_S64: return ir::PTXOperand::s64; break;
			case TOKEN_B8: return ir::PTXOperand::b8; break;
			case TOKEN_B16: return ir::PTXOperand::b16; break;
			case TOKEN_B32: return ir::PTXOperand::b32; break;
			case TOKEN_B64: return ir::PTXOperand::b64; break;
			case TOKEN_PRED: return ir::PTXOperand::pred; break;
			case TOKEN_F16: return ir::PTXOperand::f16; break;
			case TOKEN_F32: return ir::PTXOperand::f32; break;
			case TOKEN_F64: return ir::PTXOperand::f64; break;
			default:
			{
			
				Exception exception;
				exception.error = State::InvalidDataType;
				
				std::stringstream stream;
				stream << token;
				exception.message = "Got invalid data type " + stream.str();
				throw exception;
				break;
			
			}
			
		}
		
		return ir::PTXOperand::TypeSpecifier_invalid;
	
	}

	ir::PTXOperand::Vec PTXParser::tokenToVec( int token )
	{
	
		switch( token )
		{
					
			case TOKEN_V2: return ir::PTXOperand::v2; break;
			case TOKEN_V4: return ir::PTXOperand::v4; break;			
			default:
			{
			
				Exception exception;
				exception.error = State::InvalidVecType;
				
				std::stringstream stream;
				stream << token;
				exception.message = "Got invalid vector type " + stream.str();
				throw exception;
				break;
			
			}
		
		}
		
		return ir::PTXOperand::v1;
	
	}
	
	ir::PTXInstruction::Opcode PTXParser::stringToOpcode( std::string string )
	{
		if( string == "abs" ) return ir::PTXInstruction::Abs; 
		if( string == "add" ) return ir::PTXInstruction::Add;
		if( string == "addc" ) return ir::PTXInstruction::AddC;
		if( string == "and" ) return ir::PTXInstruction::And;
		if( string == "atom" ) return ir::PTXInstruction::Atom;
		if( string == "bar.sync" ) return ir::PTXInstruction::Bar;
		if( string == "bra" ) return ir::PTXInstruction::Bra;
		if( string == "brkpt" ) return ir::PTXInstruction::Brkpt;
		if( string == "call" ) return ir::PTXInstruction::Call;
		if( string == "cnot" ) return ir::PTXInstruction::CNot;
		if( string == "cos" ) return ir::PTXInstruction::Cos;
		if( string == "cvt" ) return ir::PTXInstruction::Cvt;
		if( string == "div" ) return ir::PTXInstruction::Div;
		if( string == "ex2" ) return ir::PTXInstruction::Ex2;
		if( string == "exit" ) return ir::PTXInstruction::Exit;
		if( string == "fma" ) return ir::PTXInstruction::Mad;
		if( string == "ld" ) return ir::PTXInstruction::Ld;
		if( string == "lg2" ) return ir::PTXInstruction::Lg2;
		if( string == "mad24" ) return ir::PTXInstruction::Mad24;
		if( string == "mad" ) return ir::PTXInstruction::Mad;
		if( string == "max" ) return ir::PTXInstruction::Max;
		if( string == "membar" ) return ir::PTXInstruction::Membar;
		if( string == "min" ) return ir::PTXInstruction::Min;
		if( string == "mov" ) return ir::PTXInstruction::Mov;
		if( string == "mul24" ) return ir::PTXInstruction::Mul24;
		if( string == "mul" ) return ir::PTXInstruction::Mul;
		if( string == "neg" ) return ir::PTXInstruction::Neg;
		if( string == "not" ) return ir::PTXInstruction::Not;
		if( string == "pmevent" ) return ir::PTXInstruction::Pmevent;
		if( string == "or" ) return ir::PTXInstruction::Or;
		if( string == "rcp" ) return ir::PTXInstruction::Rcp;
		if( string == "red" ) return ir::PTXInstruction::Red;
		if( string == "rem" ) return ir::PTXInstruction::Rem;
		if( string == "ret" ) return ir::PTXInstruction::Ret;
		if( string == "rsqrt" ) return ir::PTXInstruction::Rsqrt;
		if( string == "sad" ) return ir::PTXInstruction::Sad;
		if( string == "selp" ) return ir::PTXInstruction::SelP;
		if( string == "set" ) return ir::PTXInstruction::Set;
		if( string == "setp" ) return ir::PTXInstruction::SetP;
		if( string == "shl" ) return ir::PTXInstruction::Shl;
		if( string == "shr" ) return ir::PTXInstruction::Shr;
		if( string == "sin" ) return ir::PTXInstruction::Sin;
		if( string == "slct" ) return ir::PTXInstruction::SlCt;
		if( string == "sqrt" ) return ir::PTXInstruction::Sqrt;
		if( string == "st" ) return ir::PTXInstruction::St;
		if( string == "sub" ) return ir::PTXInstruction::Sub;
		if( string == "subc" ) return ir::PTXInstruction::SubC;
		if( string == "tex" ) return ir::PTXInstruction::Tex;
		if( string == "trap" ) return ir::PTXInstruction::Trap;
		if( string == "vote" ) return ir::PTXInstruction::Vote;
		if( string == "xor" ) return ir::PTXInstruction::Xor;
	
		return ir::PTXInstruction::Nop;
	}

	ir::PTXOperand::SpecialRegister 
		PTXParser::stringToSpecial( std::string reg )
	{
	
		if( reg == "%ctaid.x" )
		{
			return ir::PTXOperand::ctaIdX;
		}
		if( reg == "%ctaid.y" )
		{
			return ir::PTXOperand::ctaIdY;
		}
		if( reg == "%ctaid.z" )
		{
			return ir::PTXOperand::ctaIdZ;
		}
		if( reg == "%nctaid.x" )
		{
			return ir::PTXOperand::nctaIdX;
		}
		if( reg == "%nctaid.y" )
		{
			return ir::PTXOperand::nctaIdY;
		}
		if( reg == "%nctaid.z" )
		{
			return ir::PTXOperand::nctaIdZ;
		}
		if( reg == "%tid.x" )
		{
			return ir::PTXOperand::tidX;
		}
		if( reg == "%tid.y" )
		{
			return ir::PTXOperand::tidY;
		}
		if( reg == "%tid.z" )
		{
			return ir::PTXOperand::tidZ;
		}
		if( reg == "%ntid.x" )
		{
			return ir::PTXOperand::ntidX;
		}
		if( reg == "%ntid.y" )
		{
			return ir::PTXOperand::ntidY;
		}
		if( reg == "%ntid.z" )
		{
			return ir::PTXOperand::ntidZ;
		}
		if( reg == "%gridid" )
		{
			return ir::PTXOperand::gridId;
		}
		if( reg == "%warpid" )
		{
			return ir::PTXOperand::warpId;
		}
		if( reg == "WARP_SZ" )
		{
			return ir::PTXOperand::warpSize;
		}
		if( reg == "%laneid" )
		{
			return ir::PTXOperand::laneId;
		}
		if( reg == "%nsmId" )
		{
			return ir::PTXOperand::nsmId;
		}
		if( reg == "%smId" )
		{
			return ir::PTXOperand::smId;
		}
		if( reg == "%clock" )
		{
			return ir::PTXOperand::clock;
		}
		if( reg == "%pm0" )
		{
			return ir::PTXOperand::pm0;
		}
		if( reg == "%pm1" )
		{
			return ir::PTXOperand::pm1;
		}
		if( reg == "%pm2" )
		{
			return ir::PTXOperand::pm2;
		}
		if( reg == "%pm3" )
		{
			return ir::PTXOperand::pm3;
		}
		if( reg == "WARP_SZ" )
		{
			return ir::PTXOperand::pm3;
		}
		
		return ir::PTXOperand::SpecialRegister_invalid;
		
	}
	
	ir::PTXInstruction::Modifier PTXParser::tokenToModifier( int token )
	{
	
		switch( token )
		{
			case TOKEN_HI: return ir::PTXInstruction::hi; break;
			case TOKEN_LO: return ir::PTXInstruction::lo; break;
			case TOKEN_WIDE: return ir::PTXInstruction::wide; break;
			case TOKEN_SAT: return ir::PTXInstruction::sat; break;
			case TOKEN_RNI: /* fall through */
			case TOKEN_RN: return ir::PTXInstruction::rn; break;
			case TOKEN_RZI: /* fall through */
			case TOKEN_RZ: return ir::PTXInstruction::rz; break;
			case TOKEN_RMI: /* fall through */
			case TOKEN_RM: return ir::PTXInstruction::rm; break;
			case TOKEN_RPI: /* fall through */
			case TOKEN_RP: return ir::PTXInstruction::rp; break;
			default: break;
		}
		
		return ir::PTXInstruction::Modifier_invalid;
	
	}
	
	ir::PTXInstruction::AddressSpace PTXParser::tokenToAddressSpace( int token )
	{
	
		switch( token )
		{
		
			case TOKEN_REG: return ir::PTXInstruction::Reg; break;
			case TOKEN_SREG: return ir::PTXInstruction::SReg; break;
			case TOKEN_CONST: return ir::PTXInstruction::Const; break;
			case TOKEN_GLOBAL: return ir::PTXInstruction::Global; break;
			case TOKEN_LOCAL: return ir::PTXInstruction::Local; break;
			case TOKEN_PARAM: return ir::PTXInstruction::Param; break;
			case TOKEN_SHARED: return ir::PTXInstruction::Shared; break;
			case TOKEN_TEX: return ir::PTXInstruction::Texture; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::AddressSpace_Invalid;
	
	}
	
	ir::PTXInstruction::ReductionOperation 
		PTXParser::tokenToReductionOperation( int token )
	{
	
		switch( token )
		{
		
			case TOKEN_AND: return ir::PTXInstruction::ReductionAnd; break;
			case TOKEN_XOR: return ir::PTXInstruction::ReductionXor; break;
			case TOKEN_OR: return ir::PTXInstruction::ReductionOr; break;
			case TOKEN_ADD: return ir::PTXInstruction::ReductionAdd; break;
			case TOKEN_INC: return ir::PTXInstruction::ReductionInc; break;
			case TOKEN_DEC: return ir::PTXInstruction::ReductionDec; break;
			case TOKEN_MIN: return ir::PTXInstruction::ReductionMin; break;
			case TOKEN_MAX: return ir::PTXInstruction::ReductionMax; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::ReductionOperation_Invalid;
	
	}
	
	ir::PTXInstruction::AtomicOperation 
		PTXParser::tokenToAtomicOperation( int token )
	{
	
		switch( token )
		{
		
			case TOKEN_AND: return ir::PTXInstruction::AtomicAnd; break;
			case TOKEN_XOR: return ir::PTXInstruction::AtomicXor; break;
			case TOKEN_OR: return ir::PTXInstruction::AtomicOr; break;
			case TOKEN_ADD: return ir::PTXInstruction::AtomicAdd; break;
			case TOKEN_INC: return ir::PTXInstruction::AtomicInc; break;
			case TOKEN_DEC: return ir::PTXInstruction::AtomicDec; break;
			case TOKEN_MIN: return ir::PTXInstruction::AtomicMin; break;
			case TOKEN_MAX: return ir::PTXInstruction::AtomicMax; break;
			case TOKEN_CAS: return ir::PTXInstruction::AtomicCas; break;
			case TOKEN_EXCH: return ir::PTXInstruction::AtomicExch; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::AtomicOperation_Invalid;		
	
	}
	
	ir::PTXInstruction::CmpOp PTXParser::tokenToCmpOp( int token )
	{
	
		switch( token )
		{
		
			case TOKEN_EQ: return ir::PTXInstruction::Eq; break;
			case TOKEN_NE: return ir::PTXInstruction::Ne; break;
			case TOKEN_LT: return ir::PTXInstruction::Lt; break;
			case TOKEN_LE: return ir::PTXInstruction::Le; break;
			case TOKEN_GT: return ir::PTXInstruction::Gt; break;
			case TOKEN_GE: return ir::PTXInstruction::Ge; break;
			case TOKEN_LO: return ir::PTXInstruction::Lo; break;
			case TOKEN_LS: return ir::PTXInstruction::Ls; break;
			case TOKEN_HI: return ir::PTXInstruction::Hi; break;
			case TOKEN_HS: return ir::PTXInstruction::Hs; break;
			case TOKEN_EQU: return ir::PTXInstruction::Equ; break;
			case TOKEN_NEU: return ir::PTXInstruction::Neu; break;
			case TOKEN_LTU: return ir::PTXInstruction::Ltu; break;
			case TOKEN_LEU: return ir::PTXInstruction::Leu; break;
			case TOKEN_GTU: return ir::PTXInstruction::Gtu; break;
			case TOKEN_GEU: return ir::PTXInstruction::Geu; break;
			case TOKEN_NUM: return ir::PTXInstruction::Num; break;
			case TOKEN_NAN: return ir::PTXInstruction::Nan; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::CmpOp_Invalid;	
	
	}
	
	ir::PTXInstruction::BoolOp PTXParser::tokenToBoolOp( int token )
	{
	
		switch( token )
		{
		
			case TOKEN_AND: return ir::PTXInstruction::BoolAnd; break;
			case TOKEN_OR: return ir::PTXInstruction::BoolOr; break;
			case TOKEN_XOR: return ir::PTXInstruction::BoolXor; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::BoolOp_Invalid;		
	
	}

	ir::PTXInstruction::Geometry PTXParser::tokenToGeometry( int token )
	{
	
		switch( token )
		{
		
			case TOKEN_1D: return ir::PTXInstruction::_1d; break;
			case TOKEN_2D: return ir::PTXInstruction::_2d; break;
			case TOKEN_3D: return ir::PTXInstruction::_3d; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::Geometry_Invalid;		
	
	}
	
	ir::PTXInstruction::VoteMode PTXParser::tokenToVoteMode( int token )
	{
	
		switch( token )
		{
		
			case TOKEN_ANY: return ir::PTXInstruction::Any; break;
			case TOKEN_ALL: return ir::PTXInstruction::All; break;
			case TOKEN_UNI: return ir::PTXInstruction::Uni; break;
			default: break;
		
		}
		
		return ir::PTXInstruction::VoteMode_Invalid;		
	
	}
	
	ir::PTXOperand::DataType PTXParser::smallestType( long long int value )
	{
	
		return ir::PTXOperand::s64;
	
	}
	
	ir::PTXOperand::DataType 
		PTXParser::smallestType( long long unsigned int value )
	{
	
		return ir::PTXOperand::u64;
	
	}

	PTXParser::PTXParser()
	{
	
		state.warnLexer = false;
		state.inEntry = false;
	
	}
				
	ir::Module PTXParser::parse( std::istream& input, 
		ir::Instruction::Architecture language )
	{
	
		assert( language == ir::Instruction::PTX );
	
		std::stringstream temp;
		
		parser::PTXLexer lexer( &input, &temp );
		reset();
			
		report( "Running main parse pass." );
		
		try
		{
			ptx1_3::yyparse( lexer, state );
		}
		catch( const Exception& e )
		{
			if( e.error == State::NotVersion1_3 )
			{
				input.seekg( 0, std::ios::beg );
				temp.seekg( 0, std::ios::beg );
				reset();
				
				report( "Running secondary parse pass." );
				ptx1_4::yyparse( lexer, state );
			}
			else
			{
				throw;
			}
		}
		assert( temp.str().empty() );
		
		state.inEntry = false;
		state.identifiers.clear();
		state.operands.clear();
		state.localOperands.clear();
		state.operandVector.clear();
		
		checkLables();

		return state.module;
	
	}
		
	void PTXParser::configure( const Configuration& configuration )
	{
	
		hydrazine::Configurable::parse( "WarnLexer", state.warnLexer, 
			false, configuration );
	
	}
	
}

#endif

