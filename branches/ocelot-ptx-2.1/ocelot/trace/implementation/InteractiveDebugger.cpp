/*!	\file InteractiveDebugger.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 1, 2010
	\brief The source for the InteractiveDebugger class.
*/

#ifndef INTERACTIVE_DEBUGGER_CPP_INCLUDED
#define INTERACTIVE_DEBUGGER_CPP_INCLUDED

// C++ includes
#include <algorithm>

// Ocelot Includes
#include <ocelot/trace/interface/InteractiveDebugger.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/executive/interface/Device.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

// Standard Library Includes
#include <iostream>

namespace trace
{

InteractiveDebugger::InteractiveDebugger() : alwaysAttach(false)
{

}

void InteractiveDebugger::initialize(const executive::ExecutableKernel& kernel)
{
	_breakNow = alwaysAttach || kernel.name == filter;
	_attached = _breakNow;
	if(_attached)
	{
		std::cout << "(ocelot-dbg) Attaching debugger to kernel '" 
		<< kernel.name << "'\n";
	}
	_kernel = &kernel;
}

void InteractiveDebugger::event(const TraceEvent& event)
{
	bool memoryError = false;
	for(TraceEvent::U64Vector::const_iterator 
		address = event.memory_addresses.begin(); 
		address != event.memory_addresses.end() && !memoryError; ++address)
	{
		switch(event.instruction->addressSpace)
		{
		case ir::PTXInstruction::Const:
		{
			if(*address + _event.memory_size > _kernel->constMemorySize())
			{
				std::cout << "(ocelot-dbg) Constant memory access violation at " 
					<< (void*)*address << "\n";
				memoryError = true;
			}
		}
		break;
		case ir::PTXInstruction::Global:
		{
			if(!_kernel->device->checkMemoryAccess(
				(void*)*address, _event.memory_size))
			{
				std::cout << "(ocelot-dbg) Global memory access violation at " 
					<< (void*)*address << "\n";
				memoryError = true;
			}
		}
		break;
		case ir::PTXInstruction::Local:
		{
			if(*address + _event.memory_size > _kernel->localMemorySize())
			{
				std::cout << "(ocelot-dbg) Local memory access violation at " 
					<< (void*)*address << "\n";
				memoryError = true;
			}
		}
		break;
		case ir::PTXInstruction::Param:
		{
			if(*address + _event.memory_size > _kernel->parameterMemorySize())
			{
				std::cout << "(ocelot-dbg) Parameter memory access " 
					<< "violation at " << (void*)*address << "\n";

				memoryError = true;
			}
		}
		break;
		case ir::PTXInstruction::Shared:
		{
			if(*address + _event.memory_size > _kernel->totalSharedMemorySize())
			{
				std::cout << "(ocelot-dbg) Shared memory access violation at " 
					<< (void*)*address << "\n";
				memoryError = true;
			}
		}
		break;
		default:
		{
		
		}
		break;	
		}
	}

	if(memoryError && !_attached)
	{
		std::cout << "(ocelot-dbg) Attaching ocelot debugger.\n";
		_attached = true;
	}

	if(!_attached) return;
	
	if(memoryError && !_breakNow)
	{
		std::cout << "(ocelot-dbg) Breaking into program now!\n";
		_breakNow = true;
	}
	
	if(!_breakNow)
	{
		_breakNow = _breakpoints.count(event.PC) != 0;
	}
	
	if(_breakNow)
	{
		_event = event;
		_break();
	}
}

void InteractiveDebugger::finish()
{
	if(_attached)
	{
		std::cout << "(ocelot-dbg) Kernel '" << _kernel->name 
			<< "' finished, detaching.\n";
	}
	_breakpoints.clear();
}

void InteractiveDebugger::_command(const std::string& command)
{
	std::stringstream stream(command);
	
	std::string base;
	stream >> base;
	
	_processCommands = false;
	
	if(base == "help" || base == "h")
	{
		_help();
		_processCommands = true;
	}
	else if(base == "jump" || base == "j")
	{
		unsigned int PC = 0;
		stream >> PC;
		_jump(PC);
		_processCommands = true;
	}
	else if(base == "remove" || base == "r")
	{
		unsigned int PC = 0;
		stream >> PC;
		_removeBreakpoint(PC);
	}
	else if(base == "break" || base == "b")
	{
		unsigned int PC = 0;
		stream >> PC;
		_setBreakpoint(PC);
	}
	else if(base == "print" || base == "p")
	{
		std::string modifier;
		stream >> modifier;
		_processCommands = true;
		if(modifier == "asm" || modifier == "a")
		{
			unsigned int PC = _event.PC;
			stream >> PC;
			_printAssembly(PC);
		}
		else if(modifier == "reg" || modifier == "r")
		{
			unsigned int thread = 0;
			stream >> thread;
			unsigned int reg = 0;
			stream >> reg;
			_printRegister(thread, reg);
		}
		else if(modifier == "mem" || modifier == "m")
		{
			ir::PTXU64 address = 0;
			stream >> std::hex;
			stream >> address;
			_printMemory(address);
		}
		else if(modifier == "pc")
		{
			_printPC();
		}
		else if(modifier == "warp" || modifier == "w")
		{
			_printWarpState();
		}
		else if(modifier == "loc" || modifier == "l")
		{
			_printLocation();
		}
		else
		{
			std::cout << "(ocelot-dbg) Unknown print command '" 
				<< modifier << "'\n";
		}
	}
	else if(base == "step" || base == "s")
	{
		_step();
	}
	else if(base == "continue" || base == "c")
	{
		_continue();
	}
	else if(base == "quit" || base == "q")
	{
		_breakNow = false;
		_attached = false;
	}
	else
	{
		_processCommands = true;
		std::cout << "(ocelot-dbg) Unknown command '" << base << "'\n";
	}
}

void InteractiveDebugger::_help() const
{
	std::cout << "\n";
	std::cout << "  _                ___       _.--.\n";
    std::cout << "  \\`.|\\..----...-'`   `-._.-'_.-'`\n";
    std::cout << "  /  ' `         ,       __.--'   \n";
    std::cout << "  )/' _/     \\   `-_,   /         \n";
    std::cout << "  `-'\" `\"\\_  ,_.-;_.-\\_ ',      \n";
    std::cout << "      _.-'_./   {_.'   ; /        \n";
    std::cout << "     {_.-``-'         {_/         \n";
	std::cout << "\n";
	std::cout << "This is the Ocelot Interactive PTX Debugger\n";
	std::cout << "\n";
	std::cout << " Commands:\n";
	std::cout << "  help     (h) - Print this message.\n";
	std::cout << "  jump     (j) - Jump current warp to the specified PC.\n";
	std::cout << "  remove   (r) - Remove a breakpoint from a specific PC.\n";
	std::cout << "  break    (b) - Set a breakpoint at the specified PC.\n";
	std::cout << "  print    (p) - Print the value of a memory resource.\n";
	std::cout << "   asm  (a) - Print instructions near the specified PC.\n";
	std::cout << "   reg  (r) - Print the value of a register.\n";
	std::cout << "   mem  (m) - Print the values near an address.\n";
	std::cout << "   warp (w) - Print the current warp status.\n";
	std::cout << "   pc       - Print the PC of the current warp.\n";
	std::cout << "   loc  (l) - Print the nearest CUDA source line.\n";
	std::cout << "  step     (s) - Execute the next instruction.\n";
	std::cout << "  continue (c) - Run until the next breakpoint.\n";
	std::cout << "  quit     (q) - Detach the debugger, resume execution.\n";
}

void InteractiveDebugger::_step()
{
	std::cout << "(" << _event.PC << ") - " 
		<< _event.instruction->toString() << "\n";
}

void InteractiveDebugger::_break()
{
	std::string command;

	_processCommands = true;

	while(_processCommands)
	{
		std::cout << "(ocelot-dbg) ";
		std::getline(std::cin, command);
		_command(command);
	}
}

void InteractiveDebugger::_continue()
{
	_breakNow = false;
}

void InteractiveDebugger::_jump(unsigned int PC)
{
	switch(_kernel->ISA)
	{
	case ir::Instruction::Emulated:
	{
		const executive::EmulatedKernel& constKernel =
			static_cast<const executive::EmulatedKernel&>(*_kernel);
		executive::EmulatedKernel& kernel = 
			const_cast<executive::EmulatedKernel&>(constKernel);
		
		if(PC < kernel.instructions.size())
		{
			kernel.jumpToPC(PC);
			_event.PC = PC;
			_event.instruction = &kernel.instructions[PC];
		}
		else
		{
			std::cout << "(ocelot-dbg) Cannot jump to PC " << PC 
				<< ", kernel only has " 
				<< kernel.instructions.size() << " instructions.\n";
		}
	}
	break;
	default:
	{
		assertM(false, "Jump to PC not implemented for '" 
			<< ir::Instruction::toString(_kernel->ISA) << "' kernels.");
	}
	break;
	}
}

void InteractiveDebugger::_removeBreakpoint(unsigned int PC)
{
	_breakpoints.erase(PC);
}

void InteractiveDebugger::_setBreakpoint(unsigned int PC)
{
	_breakpoints.insert(PC);
}

void InteractiveDebugger::_printRegister(unsigned int thread, 
	ir::PTXOperand::RegisterType reg) const
{
	switch(_kernel->ISA)
	{
	case ir::Instruction::Emulated:
	{
		const executive::EmulatedKernel& kernel =
			static_cast<const executive::EmulatedKernel&>(*_kernel);
		executive::EmulatedKernel::RegisterFile 
			file = kernel.getCurrentRegisterFile();
		
		unsigned int threads = _event.blockDim.x * _event.blockDim.y 
			* _event.blockDim.z;
		unsigned int registers = file.size() / threads;
		
		unsigned int maxReg = std::min(registers, reg + 10);
		unsigned int maxThread = std::min(threads, thread + 5);

		std::cout << "     ";
		std::cout << std::right;
		for(unsigned int tid = thread; tid < maxThread; ++tid)
		{
			std::stringstream stream;
			stream << "THREAD " << tid;
			std::cout.fill( ' ' );
			std::cout.width( 16 );
			std::cout << stream.str();
			std::cout.width( 1 );
			std::cout.fill( ' ' );
			std::cout << " ";
		}
		std::cout << "\n";
		for(; reg < maxReg; ++reg)
		{
			std::cout << std::left;
			std::cout.width( 1 );
			std::cout.fill( ' ' );
			std::cout << "R";
			std::cout.width( 3 );
			std::cout.fill( ' ' );
			std::cout << reg;
			std::cout.width( 1 );
			std::cout.fill( ' ' );
			std::cout << " ";
			std::cout << std::hex;
			std::cout << std::right;
			for(unsigned int tid = thread; tid < maxThread; ++tid)
			{
				std::cout.width( 16 );
				std::cout.fill( ' ' );
				std::cout << file[tid * registers + reg];
				std::cout.width( 1 );
				std::cout << " ";
			}
			std::cout << std::dec << "\n";
		}
	}
	break;
	default:
	{
		assertM(false, "Print registers not implemented for '" 
			<< ir::Instruction::toString(_kernel->ISA) << "' kernels.");
	}
	break;
	}

}

void InteractiveDebugger::_printMemory(ir::PTXU64 address) const
{
	const executive::Device* device = _kernel->device;

	std::cout.width( 16 );
	std::cout.fill( '0' );
	std::cout << std::right;
	for(unsigned int row = 0; row != 10; ++row)
	{
		std::cout << std::hex;
		std::cout.width( 16 );
		std::cout.fill( '0' );
		std::cout << address;
		std::cout.width( 1 );
		std::cout << " | ";
		for(unsigned int col = 0; col != 5; ++col)
		{
			for(unsigned int byte = 0; byte != 8; ++byte)
			{
				void* byteAddress = (void*) (7 - byte + address);
				if(device->checkMemoryAccess(byteAddress, 1))
				{
					std::cout.width( 2 );
					std::cout.fill( '0' );
					std::cout << ((unsigned int)(*(char*)byteAddress) & 0xff);
				}
				else
				{
					std::cout.width( 2 );
					std::cout << "XX";
				}
			}
			std::cout.width( 1 );
			std::cout << " ";
		}
		address += 8;
		std::cout << std::dec << "\n";
	}

}

void InteractiveDebugger::_printAssembly(unsigned int PC) const
{
	switch(_kernel->ISA)
	{
	case ir::Instruction::Emulated:
	{
		const executive::EmulatedKernel& kernel =
			static_cast<const executive::EmulatedKernel&>(*_kernel);
		
		for(unsigned int pc = PC; 
			pc < std::min(kernel.instructions.size(), (size_t)PC + 10); ++pc)
		{
			std::cout << "(" << pc << ") - " 
				<< kernel.instructions[pc].toString() << "\n";
		}
	}
	break;
	default:
	{
		assertM(false, "Print assembly not implemented for '" 
			<< ir::Instruction::toString(_kernel->ISA) << "' kernels.");
	}
	break;
	}
}

void InteractiveDebugger::_printWarpState() const
{
	std::cout << "CTA ID:              (" << _event.blockId.x << ", " 
		<< _event.blockId.y << ", " << _event.blockId.z << ")\n";
	std::cout << "Warp ID:             " << 0 << "\n";
	std::cout << "PC:                  " << _event.PC << "\n";
	std::cout << "Context Stack Depth: " << _event.contextStackSize << "\n";
	std::cout << "Active Mask:         [" << _event.active << "]\n";
}

void InteractiveDebugger::_printPC() const
{
	std::cout << "(ocelot-dbg) Current PC is " << _event.PC << "\n";
}

void InteractiveDebugger::_printLocation() const
{
	switch(_kernel->ISA)
	{
	case ir::Instruction::Emulated:
	{
		const executive::EmulatedKernel& kernel =
			static_cast<const executive::EmulatedKernel&>(*_kernel);
		
		std::cout << "(ocelot-dbg) Near: " 
			<< kernel.location(_event.PC) << "\n";
	}
	break;
	default:
	{
		assertM(false, "Print location not implemented for '" 
			<< ir::Instruction::toString(_kernel->ISA) << "' kernels.");
	}
	break;
	}
}

}

#endif

