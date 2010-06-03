/*!	\file InteractiveDebugger.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 1, 2010
	\brief The header for the InteractiveDebugger class.
*/

#ifndef INTERACTIVE_DEBUGGER_H_INCLUDED
#define INTERACTIVE_DEBUGGER_H_INCLUDED

namespace trace
{
	/*! \brief A heavy-weight tool for debugging the emulator.
	
		This should provide an interface similar to the gdb command line for 
		the emulator, or anything else that exports the trace generator 
		interface.
		
		
	*/
	class InterativeDebugger : public TraceGenerator
	{
	
	};
}


#endif

