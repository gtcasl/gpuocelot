/*!
	\file Translator.cpp
	\date Wednesday July 29, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the Translator class
*/

#ifndef TRANSLATOR_CPP_INCLUDED
#define TRANSLATOR_CPP_INCLUDED

#include <ocelot/translator/interface/Translator.h>

namespace translator
{
	Translator::Translator( ir::Instruction::Architecture s, 
		ir::Instruction::Architecture t, 
		OptimizationLevel l ) : optimizationLevel( l ), 
		sourceArchitecture( s ), targetArchitecture( t )
	{
	
	}
	
	Translator::~Translator()
	{
	
	}
}

#endif

