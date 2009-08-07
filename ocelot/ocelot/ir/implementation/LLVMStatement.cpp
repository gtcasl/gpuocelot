/*!
	\file LLVMStatement.cpp
	\date Wednesday July 29, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMStatement class.
*/

#ifndef LLVM_STATEMENT_CPP_INCLUDED
#define LLVM_STATEMENT_CPP_INCLUDED

#include <ocelot/ir/interface/LLVMStatement.h>
#include <hydrazine/implementation/debug.h>

namespace ir
{
	LLVMStatement::LLVMStatement( Type t, const LLVMInstruction* i ) : type( t )
	{
		if( i != 0 )
		{
			instruction = i->clone();
			assertM( type == Instruction, "Statement given non-zero " 
				<< "instruction pointer, but not specified as an " 
				<< "instruction statement." );
		}
		else
		{
			instruction = 0;
		}
	}

	LLVMStatement::LLVMStatement( const LLVMStatement& s ) : type( s.type )
	{
		if( s.instruction != 0 )
		{
			instruction = s.instruction->clone();
			assertM( type == Instruction, "Statement given non-zero " 
				<< "instruction pointer, but not specified as an " 
				<< "instruction statement." );
		}
		else
		{
			instruction = 0;
		}
	}

	LLVMStatement::LLVMStatement( const LLVMInstruction& i ) 
		: type( Instruction )
	{
		instruction = i.clone();
	}

	LLVMStatement::LLVMStatement( const std::string& l ) 
		: instruction( 0 ), type( Label ), label( l )
	{
	}
	
	LLVMStatement::~LLVMStatement()
	{
		delete instruction;
	}
	
	const LLVMStatement& LLVMStatement::operator=( const LLVMStatement& s )
	{
		if( &s == this ) return *this;
		delete instruction;
		type = s.type;
		if( s.instruction != 0 )
		{
			instruction = s.instruction->clone();
			assertM( type == Instruction, "Statement given non-zero " 
				<< "instruction pointer, but not specified as an " 
				<< "instruction statement." );
		}
		else
		{
			instruction = 0;
		}
		return *this;
	}
}

#endif

