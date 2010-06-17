/*!	\file InteractiveDebugger.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 1, 2010
	\brief The header for the InteractiveDebugger class.
*/

#ifndef INTERACTIVE_DEBUGGER_H_INCLUDED
#define INTERACTIVE_DEBUGGER_H_INCLUDED

#include <ocelot/trace/interface/TraceGenerator.h>

namespace executive
{
	class Device;
}

namespace trace
{
	/*! \brief A heavy-weight tool for debugging the emulator.
	
		This should provide an interface similar to the gdb command line for 
		the emulator, or anything else that exports the trace generator 
		interface.
	*/
	class InterativeDebugger : public TraceGenerator
	{
	private:	
		/*! \brief A pointer to the device that we are debugging */
		const executive::Device* _device;		

	private:
		/*! \brief Parse a command */
		void _command(const std::string& command);
		/*! \brief Print out a help message */
		void _help() const;
	
	public:
		void initialize(const executive::ExecutableKernel& kernel);
		void event(const TraceEvent & event);
		void finish();

	};
}


#endif

