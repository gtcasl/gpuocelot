/*!
*	\file Clonable.cpp
*
*	\author Gregory Diamos
*	\date 4/22/2008
*	
*
*	
*
*	\brief 	The source file for the Clonable class
*
*			THis is an object that implements a combined new and copy constructor.
*/

#ifndef CLONABLE_CPP_INCLUDED
#define CLONABLE_CPP_INCLUDED

#include "Clonable.h"


////////////////////////////////////////////////////////////////////////////////

namespace hydrazine
{

	Clonable::~Clonable()
	{
	
	
	}
	
	Clonable::Byte Clonable::bytes() const
	{
	
		return sizeof( Clonable );
	
	}
	
	std::string Clonable::toString() const
	{
	
		std::stringstream stream;
		
		stream << "Class Clonable\n";
		
		stream << " pointer : " << this << "\n";
		stream << " bytes : " << this->bytes() << "\n";
		
		return stream.str();

	}
	
}

////////////////////////////////////////////////////////////////////////////////
#endif
