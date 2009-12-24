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
		\brief Internal representation of an instruction.
	*/
	class Instruction {
	public:
		enum Architecture {
			PTX,						// ir/interface/Kernel
			Emulated,					// ir/interface/Emulated
			GPU, 						// ir/interface/GpuKernel
			LLVM,
			x86,
			x86_64,
			SPU,
			Unknown
		};

		/*! \brief A type for a register identifier */
		typedef unsigned int RegisterType;
		
	public:
		/*! \brief Get a string represention of an architecture */
		static std::string toString( Architecture a );

	public:
		Instruction();
		virtual ~Instruction();

		/*!	\brief Returns a string representation of the instruction */
		virtual std::string toString() const = 0;

		/*!
			\brief Determines if the instruction is valid, returns an empty 
				string if valid otherwise an error message.
		*/
		virtual std::string valid() const = 0;

	public:
		/*! \brief Label that may identify the instruction */
		std::string label;

		/*!	\brief Indicates ISA of the instruction */
		Architecture ISA;
	};


}

#endif

