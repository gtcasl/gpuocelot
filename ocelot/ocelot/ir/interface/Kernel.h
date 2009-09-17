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

namespace analysis {
	class DataflowGraph;
}

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
		/*!	\brief Vector of statements */
		typedef std::deque<PTXStatement> PTXStatementVector;

		/*!	\brief Vector of instructions */
		typedef std::deque<PTXInstruction> PTXInstructionVector;

		/*!	\brief Vector of parameters */
		typedef std::vector<Parameter> ParameterVector;

		/*! \brief A map from strings to registers */
		typedef std::unordered_map< std::string, 
			PTXOperand::RegisterType > RegisterMap;

		/*! \brief Unique identifier to statement representing a local variable */
		typedef std::unordered_map< std::string, PTXStatement > StatementMap;

	public:

		/*!
			Constructs a kernel from an iterator into the PTXStatement vector

			\param start iterator into start of kernel [i.e. entry statement]
			\param end iterator into end of kernel [i.e. EndEntry statement]
		*/
		Kernel(
			PTXStatementVector::const_iterator start,
			PTXStatementVector::const_iterator end);

		/*!	Constructs an empty kernel */
		Kernel();

		/*!	Destructs kernel */
		virtual ~Kernel();

		/*! \brief Copy constructor (deep) */
		Kernel( const Kernel& k );
		
		/*! \brief Assignment operator (deep) */
		const Kernel& operator=( const Kernel& k );
		
		/*! \brief Get the version of the PTX instruction set being used */
		PTXInstruction::Version version() const;
	
		/*!	Returns true if the kernel instance is derived from 
			ExecutableKernel */
		virtual bool executable() const;

		/*!	Returns a reference to a parameter identified by 'name' */		
		Parameter& getParameter(const std::string& name);

		/*!	Returns a const reference to a parameter identified by 'name' */		
		const Parameter& getParameter(const std::string& name) const;

		/*! \brief Builds the Pdom tree within the kernel */
		void buildPostDominatorTree();
		
		/*! \brief Builds the dominator tree within the kernel */
		void buildDominatorTree();
		
		/*! \brief Builds the data flow graph within the kernel */
		void buildDataflowGraph();
		
		/*! \brief Adds a statement defining a local variable to the kernel */
		void addLocalVariable( const PTXStatement& statement );

	public:
		/*!
			Constructs a control flow graph from iterators into the 
			Module's PTXStatement vector

			\param reference to newly constructed CFG
			\param count maximum number of instructions to allocate in CFG
			\param kernelStart iterator to start of kernel 
				[i.e. the entry statement]
			\param kenelEnd iterator to end of kernel 
				[i.e. the EndEntry statement]
			\return true on successful creation
		*/
		static void constructCFG(
			ControlFlowGraph &cfg,
			PTXInstructionVector &instructions,
			PTXStatementVector::const_iterator kernelStart,
			PTXStatementVector::const_iterator kernelEnd);

		/*! \brief Assigns register IDs to identifiers */
		static RegisterMap assignRegisters( 
			PTXInstructionVector& instructions );
		
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
		
		/*! \brief Local variables */
		StatementMap locals;
		
		/*!	Control flow graph of kernel - this is the primary store of 
				instructions belonging to the kernel */
		ControlFlowGraph* ptxCFG;

		/*!	Dominator tree constructed from ptxCFG */
		DominatorTree* dom_tree;

		/*!	Post-dominator tree constructed from ptxCFG */
		PostdominatorTree* pdom_tree;
		
		/*! \brief Dataflow graph constructed from ptxCFG */
		analysis::DataflowGraph* dfg;
		
		/*!	Pointer to the module this kernel belongs to */
		const Module* module;
	
	};

}

std::ostream& operator<<( std::ostream& s, const ir::Kernel& k );

#endif

