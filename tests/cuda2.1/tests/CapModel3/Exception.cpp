/*!	\file Exception.cpp
*
*	\brief Source file for the Exception class.
*
*	\author Gregory Diamos
*
*
*/

#ifndef EXCEPTION_CPP_INCLUDED
#define EXCEPTION_CPP_INCLUDED

#include "Exception.h"


namespace hydrazine
{

	const char* Exception::what() const throw()
	{
	
		return message.c_str();
	
	}

	Exception::~Exception() throw()
	{
	
	
	}

	Exception::Exception( const std::string& _message, int _code ): 
		message( _message ), code( _code )
	{
	
		
	
	}

}

#endif

