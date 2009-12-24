/*!
	\file Global.h
	
	\date Tuesday March 31, 2009
	\author Gregory Diamos
	
	\brief The header file for the Global class.	
*/

#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <ocelot/ir/interface/PTXStatement.h>

namespace ir
{

	/*! \brief A class for referencing preinitialized global variables */
	class Global
	{
		public:	
			bool local; //! Is variable set via an initializer
			char* pointer; //! Pointer to memory base
			bool registered; //! Has this global variable had its value set
			ir::PTXStatement statement; //! Statement that the variable was declared in
	
		public:
			/*! \brief Constructor */
			Global();
			
			/*! \brief Initializing constructor */
			Global( char* );
			
			/*!	\brief Construct from Statement */
			Global( const ir::PTXStatement& );

			/*!	\brief Copy constructor */
			Global( const Global& );

			/*!	\brief Destructor for preinitialized globals */
			~Global();
			
			/*!	\brief Assignment */
			Global& operator=(const Global&);
			
			/*! \brief Get the address space of the global */
			PTXInstruction::AddressSpace space() const;
	
	};

}

#endif

