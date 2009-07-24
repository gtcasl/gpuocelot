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
	*/
	void addTraceGenerator( trace::TraceGenerator& gen, 
		bool persistent = false );
				
	/*! \brief Clear all trace generators */
	void clearTraceGenerators();
}

#endif

