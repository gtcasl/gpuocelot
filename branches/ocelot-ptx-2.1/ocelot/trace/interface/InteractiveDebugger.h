/*!	\file InteractiveDebugger.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 1, 2010
	\brief The header for the InteractiveDebugger class.
*/

#ifndef INTERACTIVE_DEBUGGER_H_INCLUDED
#define INTERACTIVE_DEBUGGER_H_INCLUDED

// Ocelot Includes
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/ir/interface/PTXOperand.h>

// Standard Library Includes
#include <unordered_set>

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
	class InteractiveDebugger : public TraceGenerator
	{	
	public:
		std::string filter;
		bool alwaysAttach;
	
	public:
		InteractiveDebugger();
		void initialize(const executive::ExecutableKernel& kernel);
		void event(const TraceEvent& event);
		void finish();

	private:
		/* \brief A set of program counters */
		typedef std::unordered_set<unsigned int> ProgramCounterSet;
	
	private:	
		/*! \brief A pointer to the kernel being debugged */
		const executive::ExecutableKernel* _kernel;
		/*! \brief A set of program counters with active breakpoints */
		ProgramCounterSet _breakpoints;
		/*! \brief Should the debugger break on the next instruction */
		bool _breakNow;
		/*! \brief Should the debugger continue processing commands */
		bool _processCommands;
		/*! \brief Is the debugger attached? */
		bool _attached;
		/*! \brief The current trace event */
		TraceEvent _event;

	private:
		/*! \brief Parse a command */
		void _command(const std::string& command);
		/*! \brief Print out a help message */
		void _help() const;

	private:
		/*! \brief Step to the next instruction */
		void _step();
		/*! \brief Break out of execution of the program into the debugger */
		void _break();
		/*! \brief Continue execution */
		void _continue();
	
	private:
		/*! \brief Jump to a specific PC */
		void _jump(unsigned int PC);
		/*! \brief Remove a breakpoint at a specific PC */
		void _removeBreakpoint(unsigned int PC);
		/*! \brief Set a breakpoint at a specific PC */
		void _setBreakpoint(unsigned int PC);
		/*! \brief View the value of a register */
		void _printRegister(unsigned int thread, 
			ir::PTXOperand::RegisterType reg) const;
		/*! \brief View values in memory near the specified device address */
		void _printMemory(ir::PTXU64 address) const;
		/*! \brief View the kernel assembly code near the specified address */
		void _printAssembly(unsigned int pc) const;
		/*! \brief Print the internal state of the currently executing warp */
		void _printWarpState() const;
		/*! \brief Print the PC of the currently executing warp */
		void _printPC() const;
		/*! \brief Print the location of the nearest source code line */
		void _printLocation() const;
	};
}


#endif

