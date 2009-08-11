/*! \file ocelot.h
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the Ocelot API functions.
*/

#ifndef OCELOT_H_INCLUDED
#define OCELOT_H_INCLUDED

namespace trace
{
	class TraceGenerator;
}

/*! \brief A namespace for ocelot API functions */
namespace ocelot
{

	/*! \brief Adds a trace generator for the next kernel invocation 
	
		\param gen A reference to the generator being added, it must not
			be destroyed until the next kernel is executed.
		\param persistent The trace generator will be associated with all
			subsequent kernels until clear is called, otherwise it will
			only be associated with the next kernel.
		\param safe Make this a thread safe call
	*/
	void addTraceGenerator( trace::TraceGenerator& gen, 
		bool persistent = false, bool safe = true );
				
	/*! \brief Clear all trace generators 
		\param safe Make this a thread safe call*/
	void clearTraceGenerators(bool safe = true);
}

#endif

