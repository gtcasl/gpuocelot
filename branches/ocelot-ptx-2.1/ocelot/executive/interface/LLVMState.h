/*! \file LLVMState.h
	\date Friday September 24, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMState class.
*/

#ifndef LLVM_STATE_H_INCLUDED
#define LLVM_STATE_H_INCLUDED

namespace llvm
{
	class ExecutionEngine;
	class Module;
}

namespace executive
{

/*! \brief A class for managing global llvm state */
class LLVMState
{
public:
	/*! \brief Build the jit */
	LLVMState();
	/*! \brief Destroy the jit */
	~LLVMState();

public:
	/*! \brief Get a reference to the jit */
	llvm::ExecutionEngine* jit();

public:
	/*! \brief A global singleton for the LLVM JIT */ 
	static LLVMState llvmState;

private:
	/*! \brief LLVM JIT Engine */
	llvm::ExecutionEngine* _jit;
	/*! \brief LLVM fake mofule */
	llvm::Module* _module;
};

}

#endif

