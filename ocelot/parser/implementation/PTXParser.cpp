/*! \file PTXParser.cpp
	\date Monday January 19, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the PTXParser class.
*/

#ifndef PTX_PARSER_CPP_INCLUDED
#define PTX_PARSER_CPP_INCLUDED

#include <ocelot/parser/interface/PTXParser.h>
#include <cassert>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/string.h>

#define throw_exception( messageData, type ) \
	{\
		std::stringstream error;\
		error << messageData;\
		parser::PTXParser::Exception exception;\
		exception.error = type;\
		exception.message = error.str();\
		throw exception;\
	}
	
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

/*! \brief A namespace for parsing PTX */
namespace ptx
{ 
	extern int yyparse( parser::PTXLexer&, parser::PTXParser::State& );
}

namespace parser
{
	PTXParser::State::OperandWrapper::OperandWrapper( const ir::PTXOperand& o, 
		ir::PTXInstruction::AddressSpace s ) : operand( o ), space( s )
	{
	
	}

	ir::PTXInstruction::AddressSpace PTXParser::State::_toAddressSpace( 
		ir::PTXStatement::Directive directive )
	{
		switch( directive )
		{
			case ir::PTXStatement::Shared : return ir::PTXInstruction::Shared;
			case ir::PTXStatement::Local : return ir::PTXInstruction::Local;
			case ir::PTXStatement::Param : return ir::PTXInstruction::Param;
			case ir::PTXStatement::Global : return ir::PTXInstruction::Global;
			case ir::PTXStatement::Const : return ir::PTXInstruction::Const;
			case ir::PTXStatement::Tex : return ir::PTXInstruction::Texture;
			default: break;
		}
		return ir::PTXInstruction::AddressSpace_Invalid;
	}
	
	void PTXParser::State::_setImmediateTypes()
	{
		ir::PTXOperand::DataType type = ir::PTXOperand::TypeSpecifier_invalid;
		for( OperandVector::iterator operand = operandVector.begin(); 
			operand != operandVector.end(); ++operand )
		{
			if( operand->addressMode != ir::PTXOperand::Immediate 
				&& operand->addressMode != ir::PTXOperand::Invalid
				&& operand->type != ir::PTXOperand::pred )
			{
				type = operand->type;
			}
		}
		
		if( type == ir::PTXOperand::TypeSpecifier_invalid ) return;
		
		for( OperandVector::iterator operand = operandVector.begin(); 
			operand != operandVector.end(); ++operand )
		{
			if( operand->addressMode == ir::PTXOperand::Immediate 
				&& ( ir::PTXOperand::isFloat( operand->type ) 
				== ir::PTXOperand::isFloat( type ) ) )
			{
				operand->type = type;
			}
		}
	}

	void PTXParser::State::maxnreg( unsigned int regs )
	{
		report( "  Rule: TOKEN_MAXNREG TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::maxntid( unsigned int tidx, unsigned int tidy, 
		unsigned int tidz )
	{
		report( "  Rule: TOKEN_MAXNTID TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::ctapersm( int target, unsigned int ctas )
	{
		report( "  Rule: shareModel ':' TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::maxnctapersm( unsigned int ctas )
	{
		report( "  Rule: TOKEN_MAXNCTAPERSM TOKEN_DECIMAL_CONSTANT" );
	}
	
	void PTXParser::State::maxnctapersm()
	{
		report( "  Rule: TOKEN_MAXNCTAPERSM ctapersmList" );
	}

	void PTXParser::State::version( double version, YYLTYPE& location )
	{
		report( "  Rule: VERSION DOUBLE_CONSTANT" );

		std::stringstream stream1;
		stream1.setf( std::ios::fixed, std::ios::floatfield );
		stream1.precision( 1 );
		stream1 << version;
		std::string value( stream1.str() );
	
		std::stringstream stream2;
		std::string::iterator fi = value.begin();
	
		for( ; fi != value.end(); ++fi )
		{
			if( *fi == '.' )
			{
				++fi;
				break;
			}
			stream2 << *fi;
		}
		
		if( fi == value.end() )
		{
			throw_exception( toString( location, *this ) 
				<< "Malformed version number " << value, MalformedVersion );
		}
	
		statement.directive = ir::PTXStatement::Version;
		stream2 >> statement.major;
	
		std::stringstream stream3;
	
		for( ; fi != value.end(); ++fi )
		{
			stream3 << *fi;
		}
	
		if( stream3.str().empty() )
		{
			throw_exception( toString( location, *this ) 
				<< "Malformed version number " << value, MalformedVersion );
		}
	
		stream3 >> statement.minor;

		if( statement.minor != 4 || statement.major != 1 )
		{
			throw_exception( toString( location, *this ) 
				<< "Cannot parse PTX version " << statement.major 
				<< "." << statement.minor << " with version 1.4 parser.", 
				NotVersion1_4 );
		}
	}
	
	void PTXParser::State::identifierList( const std::string& identifier )
	{
		report( "  Rule: IDENTIFIER" );
		identifiers.clear();
		report( "   Appending " << identifier << " to list." );
		identifiers.push_back( identifier );
	}

	void PTXParser::State::identifierList2( const std::string& identifier )
	{
		report( "  Rule: identifierList , IDENTIFIER" );
		report( "   Appending " << identifier << " to list." );
		identifiers.push_back( identifier );
	}

	void PTXParser::State::decimalListSingle( long long int value )
	{
		report( "  Rule: DECIMAL_CONSTANT" );
	
		if( statement.array.stride.empty() )
		{
			statement.array.stride.push_back( 1 );
		}
	
		report( "   Appending " << value << " to decimal list.");
		ir::PTXStatement::Data data;
		data.s64 = value;
		statement.array.values.push_back( data );
	}
	
	void PTXParser::State::decimalListSingle2( long long int value )
	{
		report( "  Rule: decimalList ',' DECIMAL_CONSTANT" );
	
		report( "   Appending " << value << " to decimal list.");
		ir::PTXStatement::Data data;
		data.s64 = value;
		statement.array.values.push_back( data );
	}

	void PTXParser::State::floatList( double value )
	{
		report( "  Rule: DOUBLE_CONSTANT" );
	
		if( statement.array.stride.empty() )
		{
			statement.array.stride.push_back( 1 );
		}
	
		report( "   Appending " << value << " to float list.");
		ir::PTXStatement::Data data;
		data.f64 = value;

		statement.array.values.push_back( data );
	}

	void PTXParser::State::floatList1( double value )
	{
		report( "  Rule: floatList ',' DOUBLE_CONSTANT" );
		report( "   Appending " << value << " to float list.");
		ir::PTXStatement::Data data;
		data.f64 = value;
		statement.array.values.push_back( data );
	}
	
	void PTXParser::State::singleList( float value )
	{
		report( "  Rule: DOUBLE_CONSTANT" );
	
		if( statement.array.stride.empty() )
		{
			statement.array.stride.push_back( 1 );
		}
	
		report( "   Appending " << value << " to single list.");
		ir::PTXStatement::Data data;
		data.f64 = value;
		statement.array.values.push_back( data );
	}

	void PTXParser::State::singleList1( float value )
	{
		report( "  Rule: singleList ',' SINGLE_CONSTANT" );
	
		report( "   Appending " << value << " to single list.");
		ir::PTXStatement::Data data;
		data.f64 = value;
		statement.array.values.push_back( data );	
	}
	
	void PTXParser::State::targetElement( int token )
	{
		report( "  Rule: targetOption" );
		if( token == TOKEN_SM10 ) statement.targets.push_back( "sm_10" );
		else if( token == TOKEN_SM11 ) statement.targets.push_back( "sm_11" );
		else if( token == TOKEN_SM12 ) statement.targets.push_back( "sm_12" );
		else if( token == TOKEN_SM13 ) statement.targets.push_back( "sm_13" );
		else if( token == TOKEN_SM20 ) statement.targets.push_back( "sm_20" );
		else if( token == TOKEN_MAP_F64_TO_F32 )
		{
			statement.targets.push_back( "map_f64_to_f32" );
		}
		else
		{
			assertM(false, "Ocelot internal error - invalid token.");
		}
	}
	
	void PTXParser::State::target()
	{
		report( "  Rule: TARGET targetElementList" );
		statement.directive = ir::PTXStatement::Target;
	}
	
	void PTXParser::State::addressSpace( int value )
	{
		statement.instruction.addressSpace = tokenToAddressSpace( value );
	}

	void PTXParser::State::dataType( int value )
	{
		operand.type = tokenToDataType( value );
	}
	
	void PTXParser::State::instructionVectorType( int value )
	{
		statement.instruction.vec = tokenToVec( value );
	}

	void PTXParser::State::statementVectorType( int value )
	{
		statement.array.vec = tokenToVec( value );
	}
	
	void PTXParser::State::attribute( bool visible, bool external )
	{
		assert( !( visible && external ) );
		if( visible )
		{
			statement.attribute = ir::PTXStatement::Visible;
		}
		else if( external )
		{
			statement.attribute = ir::PTXStatement::Extern;
		}
		else
		{
			statement.attribute = ir::PTXStatement::NoAttribute;
		}
	}

	void PTXParser::State::arrayDimensionSet( long long int value, 
		YYLTYPE& location, bool add )
	{
		report( "  Rule: '[' DECIMAL_CONSTANT ']'" );

		if( !add )
		{
			statement.array.stride.clear();
		}
		
		if( value <= 0 )
		{
			throw_exception( toString( location, *this ) 
				<< "Invalid array dimension " << value, InvalidArray );
		}
	
		report( "   Got dimension " << value );
		statement.array.stride.push_back( ( unsigned int ) value );
	}

	void PTXParser::State::arrayDimensionSet()
	{
		report( "  Rule: arrayDimensions '[' ']'" );
		statement.array.stride.clear();
	
		report( "   Got dimension " << 0 );
		statement.array.stride.push_back( 0 );
	}
	
	void PTXParser::State::arrayDimensions()
	{
		statement.array.stride.clear();
	}
	
	void PTXParser::State::statementEnd( YYLTYPE& location )
	{
		statement.line   = location.first_line;
		statement.column = location.first_column;		

		report( "   At (" << statement.line << "," << statement.column
			<< ") : Parsed statement " << statements.size() 
			<< " \"" << statement.toString() << "\"" );
		statements.push_back( statement );

		operand = ir::PTXOperand();
		statement.array.values.clear();
		alignment = 1;
		statement.array.vec = ir::PTXOperand::v1;
		statement.instruction.statementIndex = statements.size();
	}
	
	void PTXParser::State::assignment()
	{
		report( "  Clearing doubles" );
		statement.array.values.clear();
	}
	
	void PTXParser::State::registerDeclaration( const std::string& name, 
		YYLTYPE& location, unsigned int regs )
	{
		report( "  Rule: REG dataType IDENTIFIER ';' : " << name 
			<< " ["  << regs << "]" );
		statement.directive = ir::PTXStatement::Reg;
		statement.type = operand.type;
		statement.name = name;
		statement.array.vec = ir::PTXOperand::v1;
		statement.attribute = ir::PTXStatement::NoAttribute;

		if( operand.type == ir::PTXOperand::pred )
		{
			operand.condition = ir::PTXOperand::Pred;
		}

		statement.array.stride.resize(1);
		statement.array.stride[0] = regs;
		
		if( regs == 0 )
		{
			statement.array.stride[0] = 0;
			
			if( operands.count( statement.name ) != 0 ) 
			{
				throw_exception( toString( location, *this ) 
					<< "Variable name " << statement.name 
					<< " already declared in this scope.", 
					DuplicateDeclaration );
			}

			operand.addressMode = ir::PTXOperand::Register;
			operand.identifier = statement.name;
			operand.vec = ir::PTXOperand::v1;

			operands.insert( std::make_pair( statement.name, 
				OperandWrapper( operand, 
				statement.instruction.addressSpace ) ) );
			
			if( inEntry )
			{
				localOperands.push_back( statement.name );
			}
		}
		
		for( unsigned int i = 0; i < regs; ++i )
		{
			std::stringstream name;
			name << statement.name << i;
	
			if( operands.count( name.str() ) != 0 ) 
			{
				throw_exception( toString( location, *this ) 
					<< "Variable name " << statement.name 
					<< " already declared in this scope.", 
					DuplicateDeclaration );
			}

			operand.identifier = name.str();
			operand.addressMode = ir::PTXOperand::Register;
			operand.vec = ir::PTXOperand::v1;

			operands.insert( std::make_pair( name.str(), 
				OperandWrapper( operand, 
				statement.instruction.addressSpace ) ) );
		
			if( inEntry )
			{
				localOperands.push_back( name.str() );
			}
		}
	}

	void PTXParser::State::initializableDeclaration( const std::string& name, 
		YYLTYPE& one, YYLTYPE& two )
	{
		report( "  Rule: initializable addressableVariablePrefix IDENTIFIER " 
			<< "arrayDimensions initializer ';'" );

		assert( directive == ir::PTXStatement::Const 
			|| directive == ir::PTXStatement::Global 
			|| directive == ir::PTXStatement::Tex );

		statement.directive = directive;
		report( "   Name = " << name );
		statement.name = name;
		statement.alignment = alignment;
		statement.type = operand.type;
	
		// correct for single precision
		if( statement.type == ir::PTXOperand::f32 )
		{
			for( ir::PTXStatement::ArrayVector::iterator 
				fi = statement.array.values.begin();
				fi != statement.array.values.end(); ++fi )
			{
				fi->f32 = (float) fi->f64;			
			}	
		}
	
		if( statement.array.values.size() != 0 )
		{
			unsigned int expected = 0;
	
			for( ir::PTXStatement::ArrayStrideVector::iterator 
				fi = statement.array.stride.begin(); 
				fi != statement.array.stride.end(); ++fi )
			{
				expected += *fi;
			}
		
			if( statement.array.vec == ir::PTXOperand::v2 )
			{
				expected *= 2;
			} 
			else if( statement.array.vec == ir::PTXOperand::v4 )
			{
				expected *= 4;
			}
		
			if( expected != statement.array.values.size() )
			{
				throw_exception( toString( two, *this ) 
					<< "Array size " << expected 
					<< " does not match initializer size " 
					<< statement.array.values.size(), 
					InitializerSizeMismatch );
			}
		}
		
		if( operands.count( statement.name ) != 0 ) 
		{
			throw_exception( toString( one, *this ) 
				<< "Variable name " << statement.name 
				<< " already declared in this scope.", 
				DuplicateDeclaration );
		}

		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
		operands.insert( std::make_pair( statement.name, 
			OperandWrapper( operand, _toAddressSpace( directive ) ) ) );
	
		if( inEntry )
		{
			localOperands.push_back( statement.name );
		}
	}

	void PTXParser::State::fileDeclaration( unsigned int file, 
		const std::string& name )
	{
		report( "  Rule: TOKEN_FILE DECIMAL_CONSTANT TOKEN_STRING: .file " 
			<< file << " " << name );
		statement.directive = ir::PTXStatement::File;
		statement.name = name;
		statement.sourceFile = file;
	}

	void PTXParser::State::entry( const std::string& name, YYLTYPE& location, 
		bool paramList )
	{
		report( "  Half Rule: ENTRY IDENTIFIER '{'" );

		statement.directive = ir::PTXStatement::Entry;
		statement.name = name;
	
		statementEnd( location );
		
		if( paramList )
		{
			statement.directive = ir::PTXStatement::StartParam;
			statementEnd( location );		
		}		
	}
	
	void PTXParser::State::entryMid( YYLTYPE& location, bool paramList )
	{
		if( paramList )
		{
			statement.directive = ir::PTXStatement::EndParam;
			statementEnd( location );		
		}
	
		statement.directive = ir::PTXStatement::StartEntry;	
		inEntry = true;
		
		statementEnd( location );
	}
	
	void PTXParser::State::entryEnd( YYLTYPE& location )
	{
		statement.directive = ir::PTXStatement::EndEntry;	
		report( "  Rule: ENTRY IDENTIFIER '{' entryDeclarations '}'" );
		statementEnd( location );
	
		inEntry = false;
	
		for( StringList::iterator operand = localOperands.begin(); 
			operand != localOperands.end(); ++operand )
		{
			OperandMap::iterator fi = operands.find( *operand );
			assert( fi != operands.end() );
			report( "   Local variable " << fi->first << " went out of scope" );
			operands.erase( fi );
		}
	
		localOperands.clear();
	}
	
	void PTXParser::State::entryDeclaration( YYLTYPE& location )
	{
		statementEnd( location );
	
		report( "  Rule: guard instruction : " 
			<< statements.back().instruction.toString() );
	
		// check for an error
		assert( !statements.empty() );
		assert( statements.back().directive == ir::PTXStatement::Instr );
	
		std::string message = 
			statements.back().instruction.valid();
	
		if( message != "" )
		{
			throw_exception( toString( location, *this ) 
				<< "Parsed invalid instruction " 
				<< statements.back().instruction.toString() 
				<< " : " << message, InvalidInstruction );
		}
	
		operandVector.clear();
	}

	void PTXParser::State::locationAddress( int token )
	{
		directive = tokenToDirective( token );
		operand.addressMode = ir::PTXOperand::Address;
		operand.offset = 0;
	}
	
	void PTXParser::State::uninitializableDeclaration( const std::string& name )
	{
		report( "  Rule: uninitializable addressableVariablePrefix IDENTIFIER " 
			<< "arrayDimensions';' : " << name );

		assert( directive == ir::PTXStatement::Param || 
			directive == ir::PTXStatement::Local ||
			directive == ir::PTXStatement::Shared );

		statement.directive = directive;
		statement.name = name;
		statement.alignment = alignment;
		statement.type = operand.type;
		statement.array.stride.assign( 
			statement.array.stride.begin(), 
			statement.array.stride.end() );
	
		operand.identifier = statement.name;
		operand.addressMode = ir::PTXOperand::Address;
	
		operands.insert( std::make_pair( 
			statement.name, OperandWrapper( operand, 
			_toAddressSpace( directive ) ) ) );
		
		if( inEntry )
		{
			localOperands.push_back( statement.name );
		}
	}

	void PTXParser::State::location( long long int one, long long int two, 
		long long int three )
	{
		report( "  Rule: LOC DECIMAL_CONSTANT DECIMAL_CONSTANT " 
			<< "DECIMAL_CONSTANT : " << one << ", " << two << ", " << three );

		std::stringstream stream;
	
		stream << one << " " << two << " " << three;

		statement.directive = ir::PTXStatement::Loc;
		statement.sourceFile = (unsigned int) one;
		statement.sourceLine = (unsigned int) two;
		statement.sourceColumn = (unsigned int) three;
		
		statement.name = stream.str();
	}
	
	void PTXParser::State::label( const std::string& string )
	{
		report( "  Rule: LABEL : " << string );

		statement.directive = ir::PTXStatement::Label;
		statement.name = string;
	}
	
	void PTXParser::State::labelOperand( const std::string& string )
	{
		OperandMap::iterator mode = operands.find( string );
		
		if( mode == operands.end() )
		{
			operand.identifier = string;
			operand.addressMode = ir::PTXOperand::Label;
			operand.type = ir::PTXOperand::TypeSpecifier_invalid;
		}
		else
		{
			if( mode->second.operand.addressMode == ir::PTXOperand::Address )
			{
				assert( mode->second.space != ir::PTXInstruction::Reg );
				statement.instruction.addressSpace = mode->second.space;
			}	
			operand = mode->second.operand;
		}
	
		operandVector.push_back( operand );
	}
	
	void PTXParser::State::nonLabelOperand( const std::string& string, 
		YYLTYPE& location, bool invert )
	{
		OperandMap::iterator mode = operands.find( string );
		
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand " 
				<< string << " not declared in this scope.", NoDeclaration );
		}
		else
		{
			if( mode->second.operand.addressMode == ir::PTXOperand::Address )
			{
				statement.instruction.addressSpace = mode->second.space;
			}
			operand = mode->second.operand;
		}
		
		if( invert )
		{
			if( operand.type != ir::PTXOperand::pred )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< string << " is not a predicate and can't be inverted.", 
					NotPredicate );
			}
			operand.condition = ir::PTXOperand::InvPred;
		}
	
		operandVector.push_back( operand );		
	}
			
	void PTXParser::State::baseOperand( long long int value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_int = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = smallestType( operand.imm_int );
		operandVector.push_back( operand );	
	}
	
	void PTXParser::State::baseOperand( unsigned long long int value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_int = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = smallestType( operand.imm_uint );
		operandVector.push_back( operand );
	}
	
	void PTXParser::State::baseOperand( float value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_float = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = ir::PTXOperand::f32;	
		operandVector.push_back( operand );
	}
	void PTXParser::State::baseOperand( double value )
	{
		operand.addressMode = ir::PTXOperand::Immediate;
		operand.imm_float = value;
		operand.vec = ir::PTXOperand::v1;
		operand.type = ir::PTXOperand::f64;
		operandVector.push_back( operand );
	}
	
	void PTXParser::State::clockOperand( const std::string& value )
	{
		operand.addressMode = ir::PTXOperand::Special;
		operand.identifier = value;
		operand.type = ir::PTXOperand::u32;
		operand.special = parser::PTXParser::stringToSpecial( value );
		operand.vec = ir::PTXOperand::v1;
		operandVector.push_back( operand );	
	}
	
	void PTXParser::State::specialOperand( const std::string& value )
	{
		operand.addressMode = ir::PTXOperand::Special;
		operand.identifier = value;
		operand.type = ir::PTXOperand::b16;
		operand.special = parser::PTXParser::stringToSpecial( value );
		operand.vec = ir::PTXOperand::v1;
		operandVector.push_back( operand );	
	}
	
	void PTXParser::State::addressableOperand( const std::string& name, 
		long long int value, YYLTYPE& location, bool invert )
	{
		OperandMap::iterator mode = operands.find( name );
		
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand " 
				<< name << " not declared in this scope.", NoDeclaration );
		}
		else
		{
			if( mode->second.operand.addressMode == ir::PTXOperand::Register )
			{
				operand.addressMode = ir::PTXOperand::Indirect;
			}
			else
			{
				operand.addressMode = ir::PTXOperand::Address;
			}
		}
	
		operand.identifier = name;
		operand.vec = ir::PTXOperand::v1;
		if( invert )
		{ 
			value = -value;
		}
		operand.offset = (int) value;
		operand.type = mode->second.operand.type;
	
		operandVector.push_back( operand );
	}

	void PTXParser::State::arrayOperand( YYLTYPE& location )
	{
		assert( !identifiers.empty() );

		OperandMap::iterator mode = operands.find( identifiers.front() );
	
		if( identifiers.size() > 4 )
		{
			throw_exception( toString( location, *this ) 
				<< "Array operand \"" 
				<< hydrazine::toString( identifiers.begin(), 
				identifiers.end(), "," ) 
				<< "\" has more than 4 elements.", InvalidArray );
		}

		if( identifiers.size() == 3 )
		{
			throw_exception( toString( location, *this ) 
				<< "Array operand \"" 
				<< hydrazine::toString( identifiers.begin(), 
				identifiers.end(), "," ) 
				<< "\" has exactly 3 elements.", InvalidArray );
		}
	
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Operand " 
				<< identifiers.front() << " not declared in this scope.", 
				NoDeclaration );
		}
		
		operand = mode->second.operand;
	
		if( identifiers.size() == 1 )
		{
			operand.vec = ir::PTXOperand::v1;
		
			operand.array.push_back( mode->second.operand );
		}
		else if( identifiers.size() >= 2 )
		{
			operand.vec = ir::PTXOperand::v2;
			operand.array.push_back( mode->second.operand );
		
			mode = operands.find( identifiers[1] );
		
			if( mode == operands.end() )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< identifiers[1] << " not declared in this scope.", 
					NoDeclaration );
			}
				
			operand.array.push_back( mode->second.operand );
		}
	
		if( identifiers.size() == 4 )
		{
	
			operand.vec = ir::PTXOperand::v4;
		
			mode = operands.find( identifiers[2] );
		
			if( mode == operands.end() )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< identifiers[2] << " not declared in this scope.", 
					NoDeclaration );
			}
		
			operand.array.push_back( mode->second.operand );
		
			mode = operands.find( identifiers[3] );
		
			if( mode == operands.end() )
			{
				throw_exception( toString( location, *this ) << "Operand " 
					<< identifiers[3] << " not declared in this scope.", 
					NoDeclaration );
			}

			operand.array.push_back( mode->second.operand );
		}
	
		operandVector.push_back( operand );
		operand.array.clear();
	}

	void PTXParser::State::guard( const std::string& name, YYLTYPE& location, 
		bool invert )
	{
		report( "  Rule: PREDICATE_IDENTIFIER : " << name  );

		OperandMap::iterator mode = operands.find( name );
	
		if( mode == operands.end() )
		{
			throw_exception( toString( location, *this ) << "Predciate " 
				<< name << " not declared in this scope.", NoDeclaration );
		}

		operand = mode->second.operand;
		if( invert )
		{
			operand.condition = ir::PTXOperand::InvPred;
		}
		else
		{
			operand.condition = ir::PTXOperand::Pred;
		}
		
		if( mode->second.operand.addressMode == ir::PTXOperand::Address )
		{
			statement.instruction.addressSpace = mode->second.space;
		}
		
		operandVector.push_back( operand );
	}

	void PTXParser::State::guard()
	{
		report( "  Rule: No guard predicate" );
		operand.addressMode = ir::PTXOperand::Register;
		operand.type = ir::PTXOperand::pred;
		operand.condition = ir::PTXOperand::PT;
		operandVector.push_back( operand );
	}
	
	void PTXParser::State::uni( bool condition )
	{
		statement.instruction.uni = condition;
	}

	void PTXParser::State::carry( bool condition )
	{
		if( condition )
		{
			report( "  Rule: Carry" );
			statement.instruction.carry = ir::PTXInstruction::CC; 		
		}
		else
		{
			report( "  Rule: No Carry" );
			statement.instruction.carry = ir::PTXInstruction::None;
		}
	}

	void PTXParser::State::full()
	{
		statement.instruction.divideFull = true;
	}

	void PTXParser::State::modifier( int token )
	{
		statement.instruction.modifier |= tokenToModifier( token );
	}

	void PTXParser::State::atomic( int token )
	{
		statement.instruction.atomicOperation = tokenToAtomicOperation( token );
	}

	void PTXParser::State::volatileFlag( bool condition )
	{
		if( condition )
		{
			statement.instruction.volatility = ir::PTXInstruction::Volatile;
		}
		else
		{
			statement.instruction.volatility = ir::PTXInstruction::Nonvolatile;
		}
	}
	
	void PTXParser::State::reduction( int token )
	{
		statement.instruction.reductionOperation 
			= tokenToReductionOperation( token );
	}
	
	void PTXParser::State::comparison( int token )
	{
		statement.instruction.comparisonOperator = tokenToCmpOp( token );
	}

	void PTXParser::State::boolean( int token )
	{
		statement.instruction.booleanOperator = tokenToBoolOp( token );
	}

	void PTXParser::State::geometry( int token )
	{
		statement.instruction.geometry = tokenToGeometry( token );
	}

	void PTXParser::State::vote( int token )
	{
		statement.instruction.vote = tokenToVoteMode( token );
	}
	
	void PTXParser::State::level( int token )
	{
		statement.instruction.level = tokenToLevel( token );
	}

	void PTXParser::State::instruction()
	{
		statement.instruction = ir::PTXInstruction( );
		statement.instruction.statementIndex = statements.size();
	}

	void PTXParser::State::instruction( const std::string& opcode, int dataType, 
		unsigned int operands )
	{
		report( "  Rule: instruction : " << opcode );

		assert( operandVector.size() == operands );
		_setImmediateTypes();

		statement.directive = ir::PTXStatement::Instr;
		statement.instruction.type = tokenToDataType( dataType );
		statement.instruction.opcode = stringToOpcode( opcode );
		statement.instruction.pg = operandVector[0];

		if( operands == 6 )
		{
			statement.instruction.d  = operandVector[1];
			statement.instruction.pq = operandVector[2];
			statement.instruction.a  = operandVector[3];
			statement.instruction.b  = operandVector[4];
			statement.instruction.c  = operandVector[5];		
		}
		else
		{
			if( operands >= 2 )
			{
				statement.instruction.d = operandVector[1];
			}
			if( operands >= 3 )
			{
				statement.instruction.a = operandVector[2];
			}
			if( operands >= 4 )
			{
				statement.instruction.b = operandVector[3];
			}
			if( operands >= 5 )
			{
				statement.instruction.c = operandVector[4];
			}
		}
	}
	
	void PTXParser::State::instruction( const std::string& opcode, 
		unsigned int operands )
	{
		instruction( opcode, TOKEN_B64, operands );
	}

	void PTXParser::State::tex( int dataType )
	{
		report( "  Rule: instruction : tex" );

		assert( operandVector.size() == 4 );

		statement.directive          = ir::PTXStatement::Instr;
		statement.instruction.type   = tokenToDataType( dataType );
		statement.instruction.opcode = stringToOpcode( "tex" );
		statement.instruction.pg = operandVector[0];
		statement.instruction.d = operandVector[1];
		statement.instruction.a = operandVector[2];
		statement.instruction.c = operandVector[3];		
	}
	

	void PTXParser::State::relaxedConvert( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::relaxedValid( tokenToDataType( token ),
			statement.instruction.a.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.a.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.a.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " using relaxed conversion rules.", InvalidDataType );
		}
	
		statement.instruction.a.type = tokenToDataType( token );
	}

	void PTXParser::State::convert( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::valid( tokenToDataType( token ),
			statement.instruction.a.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.a.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.a.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " .", InvalidDataType );
		}
	
		statement.instruction.a.type = tokenToDataType( token );
	}

	void PTXParser::State::convertC( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::valid( tokenToDataType( token ),
			statement.instruction.c.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.c.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.c.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " .", InvalidDataType );
		}
	
		statement.instruction.c.type = tokenToDataType( token );
	}

	void PTXParser::State::convertD( int token, YYLTYPE& location )
	{
		if( !ir::PTXOperand::valid( tokenToDataType( token ),
			statement.instruction.d.type ) )
		{
			throw_exception( parser::PTXParser::toString( location, *this ) 
				<< "Type of " << statement.instruction.d.identifier << " " 
				<< ir::PTXOperand::toString( statement.instruction.d.type ) 
				<< " not convertable to type " 
				<< ir::PTXOperand::toString( tokenToDataType( token ) ) 
				<< " .", InvalidDataType );
		}
	
		statement.instruction.d.type = tokenToDataType( token );
	}

	void PTXParser::State::structure( YYLTYPE& location )
	{
		throw_exception( parser::PTXParser::toString( location, *this ) 
			<< "Structs not supported in this version.", NotSupported );
	}
	
	void PTXParser::State::aUnion( YYLTYPE& location )
	{
		throw_exception( parser::PTXParser::toString( location, *this ) 
			<< "Unions not supported in this version.", NotSupported );
	}

	void PTXParser::State::function( YYLTYPE& location )
	{
		throw_exception( parser::PTXParser::toString( location, *this ) 
			<< "Functions not supported in this version.", NotSupported );
	}

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

	void PTXParser::checkLabels()
	{
		typedef std::unordered_map< std::string, ir::PTXStatement > 
			StatementMap;
		
		report( "Checking labels." );
		
		StatementMap labels;
		
		ir::Module::StatementVector::iterator 
			begin = state.statements.begin();
		
		for( ir::Module::StatementVector::iterator 
			statement = state.statements.begin(); 
			statement != state.statements.end(); ++statement )
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
			else if( statement->directive == ir::PTXStatement::EndEntry )
			{
				for( ir::Module::StatementVector::iterator 
					s = begin; s != statement; ++s )
				{
					if( s->directive == ir::PTXStatement::Instr )
					{
						ir::PTXOperand* operands[] = { &s->instruction.a, 
							&s->instruction.b, &s->instruction.c, 
							&s->instruction.d };
				
						for( unsigned int i = 0; i < 4; ++i )
						{
							ir::PTXOperand& operand = *operands[ i ];
				
							if( operand.addressMode == ir::PTXOperand::Label )
							{
								StatementMap::iterator label = 
									labels.find( operand.identifier );
				
								if( label == labels.end() )
								{
									std::stringstream error;
									error << state.fileName << " ("  
										<< s->line << "," << s->column 
										<< "): Label "
										<< operand.identifier 
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
				
				labels.clear();
				begin = statement;
			}
		}	
	}
	
	void PTXParser::reset()
	{
		state.inEntry = false;
		state.identifiers.clear();
		state.operands.clear();
		state.localOperands.clear();
		state.operandVector.clear();
		state.statements.clear();
		state.fileName = fileName;
		
		ir::PTXOperand bucket;
		bucket.type = ir::PTXOperand::b64;
		bucket.addressMode = ir::PTXOperand::BitBucket;
		bucket.vec = ir::PTXOperand::v1;
		
		state.operands.insert( std::make_pair( "_", 
			State::OperandWrapper( bucket, 
			ir::PTXInstruction::Global ) ) );
	}

	ir::PTXOperand::DataType PTXParser::tokenToDataType( int token )
	{
		switch( token )
		{
			case TOKEN_U8:   return ir::PTXOperand::u8; break;
			case TOKEN_U16:  return ir::PTXOperand::u16; break;
			case TOKEN_U32:  return ir::PTXOperand::u32; break;
			case TOKEN_U64:  return ir::PTXOperand::u64; break;
			case TOKEN_S8:   return ir::PTXOperand::s8; break;
			case TOKEN_S16:  return ir::PTXOperand::s16; break;
			case TOKEN_S32:  return ir::PTXOperand::s32; break;
			case TOKEN_S64:  return ir::PTXOperand::s64; break;
			case TOKEN_B8:   return ir::PTXOperand::b8; break;
			case TOKEN_B16:  return ir::PTXOperand::b16; break;
			case TOKEN_B32:  return ir::PTXOperand::b32; break;
			case TOKEN_B64:  return ir::PTXOperand::b64; break;
			case TOKEN_PRED: return ir::PTXOperand::pred; break;
			case TOKEN_F16:  return ir::PTXOperand::f16; break;
			case TOKEN_F32:  return ir::PTXOperand::f32; break;
			case TOKEN_F64:  return ir::PTXOperand::f64; break;
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
			case TOKEN_FTZ: return ir::PTXInstruction::ftz; break;
			case TOKEN_APPROX: return ir::PTXInstruction::approx; break;			
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

	ir::PTXStatement::Directive PTXParser::tokenToDirective( int token )
	{
		switch( token )
		{
			case TOKEN_CONST: return ir::PTXStatement::Const; break;
			case TOKEN_GLOBAL: return ir::PTXStatement::Global; break;
			case TOKEN_LOCAL: return ir::PTXStatement::Local; break;
			case TOKEN_PARAM: return ir::PTXStatement::Param; break;
			case TOKEN_SHARED: return ir::PTXStatement::Shared; break;
			case TOKEN_TEX: return ir::PTXStatement::Tex; break;
			default: break;
		}
		
		return ir::PTXStatement::Directive_invalid;
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
	
	ir::PTXInstruction::Level PTXParser::tokenToLevel( int token )
	{
		switch( token )
		{
			case TOKEN_CTA: return ir::PTXInstruction::CtaLevel; break;
			case TOKEN_GL: return ir::PTXInstruction::GlobalLevel; break;
			default: break;
		}
		
		return ir::PTXInstruction::Level_Invalid;		
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

	}
				
	void PTXParser::parse( std::istream& input, 
		ir::Instruction::Architecture language )
	{
		assert( language == ir::Instruction::PTX );
	
		std::stringstream temp;
		
		parser::PTXLexer lexer( &input, &temp );
		reset();
		
		report( "Parsing file " << fileName );
		report( "Running 1.4 main parse pass." );
		
		try 
		{
			ptx::yyparse( lexer, state );
			assert( temp.str().empty() );
		
			checkLabels();
		}
		catch( Exception& e )
		{
			input.seekg( 0, std::ios::end );
			unsigned int length = input.tellg();
			input.seekg( 0, std::ios::beg );
			
			char* temp = new char[ length + 1 ];
			temp[ length ] = '\0';
			input.read( temp, length );
			e.message = "\nFailed to parse file '" + fileName + "':\n" 
				+ hydrazine::addLineNumbers(temp) + "\n" + e.message;
			delete[] temp;
			
			throw e;
		}
	}
	
	ir::Module::StatementVector&& PTXParser::statements()
	{
		return std::move( state.statements );
	}
		
}

#endif

