/*!
*	\file Stringable.cpp
*
*	\author Gregory Diamos
*	\date 5/4/2008
*	
*
*	
*
*	\brief 	The source file for the Stringable class
*
*	This class is used to provide an interface for classes that provide a toString
*	method describing the object.
*
*
*/

#ifndef STRINGABLE_CPP_INCLUDED
#define STRINGABLE_CPP_INCLUDED

#include "Stringable.h"
////////////////////////////////////////////////////////////////////////////////
namespace hydrazine
{

	Stringable::~Stringable()
	{
	
	
	}
	
	std::string Stringable::toString() const
	{
		
		std::string result;
		
		result = "This is the basic Stringable description.  This should be reimplemented by the derived class.";
		
		return result;
	
	}


}

////////////////////////////////////////////////////////////////////////////////
#endif
