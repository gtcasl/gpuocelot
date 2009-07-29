/*!
	\file Kernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief implements the Kernel base class
*/

#ifndef IR_KERNEL_H_INCLUDED
#define IR_KERNEL_H_INCLUDED

#include <deque>

#include <ocelot/ir/interface/Parameter.h>
#include <ocelot/ir/interface/Instruction.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXStatement.h>

#include <ocelot/ir/interface/DominatorTree.h>
#include <ocelot/ir/interface/PostdominatorTree.h>

namespace ir {

	class Module;
	/*!
		Class representing dimensions of blocks and grids
	*/
	class dim3 {
	public:
		dim3(int X=1, int Y=1, int Z=1): x(X), y(Y), z(Z) { }
		int x, y, z;
	};
	
	/*!
		Base class for kernels
	*/
	class Kernel {
	public:
		/*!
			\brief Vector of statements
		*/
		typedef std::deque<PTXStatement> PTXStatementVector;

		/*!
			\brief Vector of instructions
		*/
		typedef std::deque<PTXInstruction> PTXInstructionVector;

		/*!
			\brief Vector of parameters
		*/
		typedef std::vector<Parameter> ParameterVector;

		/*! \brief A map from strings to registers */
		typedef std::unordered_map< std::string, 
			PTXOperand::RegisterType > RegisterMap;

	public:

		/*!
			Constructs a kernel from an iterator into the PTXStatement vector

			\param start iterator into start of kernel [i.e. entry statement]
			\param end iterator into end of kernel [i.e. EndEntry statement]
		*/
		Kernel(
			PTXStatementVector::const_iterator start,
			PTXStatementVector::const_iterator end);

		/*!
			Constructs an empty kernel
		*/
		Kernel();

		/*!
			Destructs kernel
		*/
		virtual ~Kernel();
	
		/*!
			Returns true if the kernel instance is derived from ExecutableKernel
		*/
		virtual bool executable() const { return false; }

		/*!
			Returns a reference to a parameter identified by 'name'
		*/		
		Parameter & getParameter(const std::string& name);

		/*!
			Returns a const reference to a parameter identified by 'name'
		*/		
		const Parameter & getParameter(const std::string& name) const;

		/*!
			Constructs a control flow graph from iterators into the Module's PTXStatement vector

			\param reference to newly constructed CFG
			\param count maximum number of instructions to allocate in CFG
			\param kernelStart iterator to start of kernel [i.e. the entry statement]
			\param kenelEnd iterator to end of kernel [i.e. the EndEntry statement]
			\return true on successful creation
		*/
		static bool constructCFG(
			ControlFlowGraph &cfg,
			PTXInstructionVector &instructions,
			PTXStatementVector::const_iterator kernelStart,
			PTXStatementVector::const_iterator kernelEnd);

		/*! \brief Assigns register IDs to identifiers */
		static RegisterMap assignRegisters( 
			PTXInstructionVector& instructions );

		void clone(const Kernel &kernel);
		
	public:

		/*!	[mangled] name of kernel within module */
		std::string name;

		/*!	Instruction Set Architecture of the kernel */
		Instruction::Architecture ISA;

		/*!	Set of parameters in order specified in the kernel's definition */
		ParameterVector parameters;

		/*!	Iterator pointing to start of kernel in module's PTX statement 
			vector
		*/
		PTXStatementVector::const_iterator start_iterator;
		
		/*! Iterator pointing to end of kernel in module's PTX statement vector
		*/
		PTXStatementVector::const_iterator end_iterator;

		/*! the CFG references this vector of instructions */
		PTXInstructionVector instructions;
		
		/*! Global variable statements */
		PTXStatementVector globalStatements;
	
		/*!
			Control flow graph of kernel - this is the primary store of 
				instructions belonging to the kernel
		*/
		ControlFlowGraph *ptxCFG;

		/*!	Dominator tree constructed from ptxCFG */
		DominatorTree *dom_tree;

		/*!	Post-dominator tree constructed from ptxCFG */
		PostdominatorTree *pdom_tree;
		
		/*!	Pointer to the module this kernel belongs to */
		const Module* module;
	
	};

}

#endif

