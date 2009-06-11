/*!

	\file PTXParser.h
	
	\date Monday January 19, 2009
	
	\author Gregory Diamos <gregory.diamos@gatech.edu>

	\brief The header file for the PTXParser class.

*/

#ifndef PTX_PARSER_H_INCLUDED
#define PTX_PARSER_H_INCLUDED

#include <ocelot/parser/interface/Parser.h>
#include <FlexLexer.h>
#include <ocelot/parser/interface/PTXLexer.h>
#include <ptxgrammar.h>
#include <unordered_map>
#include <deque>

namespace parser
{
	/*!
	
		\brief An implementation of the Parser interface for PTX
	
	*/
	class PTXParser : public Parser
	{
		
		public:
		
			class State
			{
			
				public:
				
					typedef std::unordered_map< std::string, unsigned int > 
						StringMap;
					typedef std::deque< std::string > StringList;
					typedef std::deque< unsigned int > DimensionVector;
					typedef std::deque< double > DoubleVector;
					typedef std::unordered_map< std::string, 
						ir::PTXOperand > OperandMap;
					typedef std::deque< ir::PTXOperand > OperandVector;
			
					enum Error
					{
						Success,
						SyntaxError,
						MalformedVersion,
						InvalidDataType,
						InvalidVecType,
						InitializerSizeMismatch,
						InvalidInstruction,
						DuplicateDeclaration,
						NoDeclaration,
						InvalidOpcode,
						DuplicateLabel,
						NoLabel,
						InvalidArray,
						NotSupported,
						NotVersion1_3,
						NotVersion1_4,
						Invalid
					};
			
				public:
				
					ir::Module module;
					StringMap labels;
					std::string fileName;
					
				public:
					
					std::string sectionType;
					std::string sectionName;
					
					StringList identifiers;
					OperandMap operands;
					StringList localOperands;
					
					bool inEntry;
					
					unsigned int alignment;
					ir::PTXOperand operand;
					OperandVector operandVector;
					ir::PTXStatement statement;
					
					ir::PTXStatement::Directive directive;
									
				public:
				
					/*!
			
						\brief Warn if part of the input file is ignored by 
							the lexer
			
					*/
					bool warnLexer;
					
			};
			
			class Exception : public std::exception
			{
			
				public:
				
					std::string message;
					State::Error error;
					
				public:
					
					const char* what() const throw();
					~Exception() throw();
			
			};
		
		private:
		
			State state;
		
		private:
		
			void checkLables();
			void reset();
		
		public:
		
			static std::string toString( YYLTYPE&, State& );
			static ir::PTXOperand::DataType tokenToDataType( int );
			static ir::PTXInstruction::Vec tokenToVec( int );
			static ir::PTXInstruction::Opcode stringToOpcode( std::string );
			static ir::PTXOperand::SpecialRegister 
				stringToSpecial( std::string );
			static ir::PTXInstruction::Modifier tokenToModifier( int );
			static ir::PTXInstruction::AddressSpace tokenToAddressSpace( int );
			static ir::PTXInstruction::ReductionOperation 
				tokenToReductionOperation( int );
			static ir::PTXInstruction::AtomicOperation 
				tokenToAtomicOperation( int );
			static ir::PTXInstruction::CmpOp tokenToCmpOp( int );
			static ir::PTXInstruction::BoolOp tokenToBoolOp( int );
			static ir::PTXInstruction::Geometry tokenToGeometry( int );
			static ir::PTXInstruction::VoteMode tokenToVoteMode( int );
			static ir::PTXOperand::DataType smallestType( long long int );
			static ir::PTXOperand::DataType 
				smallestType( long long unsigned int );
				
		public:

			PTXParser();
						
			ir::Module parse( std::istream& input, 
				ir::Instruction::Architecture 
				language = ir::Instruction::PTX );
				
			void configure( const Configuration& configuration );
	
	};

}

#endif

