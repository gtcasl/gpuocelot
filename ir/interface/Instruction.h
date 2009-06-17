/*!
	\file Instruction.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\date Jan 15, 2009

	\brief base class for all instructions
*/

#ifndef IR_INSTRUCTION_H_INCLUDED
#define IR_INSTRUCTION_H_INCLUDED

#include <string>

/*!
	\brief A namespace for the Ocelot internal program representation
*/
namespace ir {

	/*!
		Instruction class
	*/
	class Instruction {
	public:
		enum Architecture {
			PTX,								// ir/interface/Kernel
			GPU,								// executive/interface/GPUKernel
			Emulated,						// executive/interface/EmulatedKernel
			LLVM,
			x86,
			x86_64,
			SPU,
			Unknown
		};

	public:
		Instruction();
		virtual ~Instruction();

		/*!
			Returns a string representation of the instruction
		*/
		virtual std::string toString() const = 0;

		/*!
			Determines if the instruction is valid, returns an empty string if
				valid otherwise an error message.
		*/
		virtual std::string valid() const = 0;

	public:

		/*!
			Label that may identify the instruction
		*/
		std::string label;

		/*!
			Indicates ISA of the instruction
		*/
		Architecture ISA;
	};


}

#endif

