/*!
*	\file Stringable.h
*
*	\author Gregory Diamos
*	\date 5/4/2008
*	
*
*	
*
*	\brief 	The header file for the Stringable class
*
*	This class is used to provide an interface for classes that provide a toString
*	method describing the object.
*
*
*/

#ifndef STRINGABLE_H_INCLUDED
#define STRINGABLE_H_INCLUDED

#include <sstream>
////////////////////////////////////////////////////////////////////////////////
namespace hydrazine
{

	/*!
		\brief The Stringable class provides a default toString function describing
		an instance of an object.

	*/
	class Stringable
	{
	
		public:
		
			/*!
			
				\brief The default virtual destructor
			
			*/
			virtual ~Stringable();
		
			/*!
			
				\brief This method should return a standard string descibing an 
				instance of the object.
				
				It should be const in that it should not modify the object.
						
				\return A string describing the object.
			
			*/	
			virtual std::string toString() const;
	
	};


}

////////////////////////////////////////////////////////////////////////////////
#endif
