/*!
*	\file Clonable.h
*
*	\author Gregory Diamos
*	\date 4/22/2008
*	
*
*	
*
*	\brief 	The header file for the Clonable class
*
*			THis is an object that implements a combined new and copy constructor.
*/

#ifndef CLONABLE_H_INCLUDED
#define CLONABLE_H_INCLUDED

#include "Stringable.h"

////////////////////////////////////////////////////////////////////////////////

namespace hydrazine
{

	/*!
		\brief An object that has a clone method to allocate a new object
	*/
	class Clonable : public Stringable
	{
	
		public:
			
			/*!
				\brief Type for holding memory size in bytes
			*/
			typedef long long unsigned int Byte;
	
		public:
			/*!
				\brief A pure virtual destructor
			*/		
			virtual ~Clonable() = 0;
			
			/*!
				\brief allocate a new object and make it a duplicate of this 
					object
					
				\param copy Should the variable be copied or just allocated.
				
				\return TA newly allocated variable of the same type.
			*/
			virtual Clonable* clone( bool copy = true ) const = 0;
			
			/*!
				\brief Determine the number of bytes consumbed by this object
				
				\return The number of bytes used by this object
			*/
			virtual Byte bytes() const;
			
			/*!
				\brief Convert the object to a string.			
				\return A string representation of the object.
			*/
			virtual std::string toString() const;
	
	};

}

////////////////////////////////////////////////////////////////////////////////
#endif

