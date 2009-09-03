/*!
	\file LLVMKernel.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Saturday August 1, 2009
	\brief The header file for the LLVMKernel class.
*/

#ifndef LLVM_KERNEL_H_INCLUDED
#define LLVM_KERNEL_H_INCLUDED

#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/ir/interface/LLVMInstruction.h>
#include <ocelot/ir/interface/LLVMStatement.h>

namespace translator
{
	class PTXToLLVMTranslator;
}

namespace ir
{

	/*! \brief A class containing a complete representation of an LLVM kernel */
	class LLVMKernel : public ExecutableKernel
	{
		friend class translator::PTXToLLVMTranslator;
		public:
			/*! \brief A vector of LLVM instructions */
			typedef std::vector< LLVMInstruction* > LLVMInstructionVector;
			
			/*! \brief A vector of LLVM Statements */
			typedef std::deque< LLVMStatement > LLVMStatementVector;
		
		private:
			/*! \brief The assembled LLVM kernel */
			std::string _code;
			/*! \brief The set of statements representing the kernel */
			LLVMStatementVector _statements;
			/*! \brief The CTA dimensions */
			ir::dim3 ctaDimensions;
			/*! \brief The kernel dimensions */
			ir::dim3 kernelDimensions;
		
		public:
			/*! \brief Sets the ISA */
			LLVMKernel();
			/*! \brief Initialized the base class from a kernel and executive */
			LLVMKernel( const Kernel& k, const executive::Executive* c = 0 );
			
		public:
			/*! \brief Launch a kernel on a 2D grid */
			void launchGrid(int width, int height);
			/*! \brief Sets the shape of a cta in the kernel */
			void setKernelShape(int x, int y, int z);
			/*! \brief Is the kernel executable? yes */
			bool executable();
			
		public:
			/*! \brief Assemble the LLVM kernel from the set of statements */
			void assemble();
			
			/*! \brief Is the kernel assembled? */
			bool assembled() const;
			
			/*! \brief Get the assembly code */
			const std::string& code() const;
			
			/*! \brief Get the set of statements */
			const LLVMStatementVector& llvmStatements() const;
	};

}

#endif

