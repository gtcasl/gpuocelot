/*! \file Kernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief implements the Kernel base class
*/

#ifndef IR_KERNEL_H_INCLUDED
#define IR_KERNEL_H_INCLUDED

#include <deque>
#include <map>

#include <ocelot/ir/interface/Local.h>
#include <ocelot/ir/interface/Parameter.h>
#include <ocelot/ir/interface/Instruction.h>

namespace analysis {
	class DataflowGraph;
}

namespace ir {
	class Module;
	class ControlFlowGraph;
	class DominatorTree;
	class PostdominatorTree;
	class ControlTree;
}

namespace ir {
	/*! Base class for kernels */
	class Kernel {
	public:
		/*!	\brief Vector of parameters */
		typedef std::vector<Parameter> ParameterVector;
		/*! \brief Unique identifier to statement representing 
			a local variable */
		typedef std::map<std::string, Local> LocalMap;

	protected:
		/*!	Control flow graph of kernel - this is the primary store of 
				instructions belonging to the kernel */
		ControlFlowGraph* _cfg;
		/*!	Dominator tree constructed from the cfg */
		DominatorTree* _dom_tree;
		/*!	Post-dominator tree constructed from the cfg */
		PostdominatorTree* _pdom_tree;
		/*! \brief Dataflow graph constructed from the cfg */
		analysis::DataflowGraph* _dfg;
		/*! \brief Control tree constructed from the cfg */
		ControlTree* _ct;
		/*! \brief Is this kernel a function? */
		bool _function;
		
	public:
		/*!	Constructs an empty kernel */
		Kernel(Instruction::Architecture isa = Instruction::Unknown,
			bool isFunction = false);
		/*!	Destructs kernel */
		virtual ~Kernel();
		/*! \brief Copy constructor (deep) */
		Kernel( const Kernel& k );
		/*! \brief Assignment operator (deep) */
		const Kernel& operator=( const Kernel& k );

	public:
		/*!	Returns a pointer to a parameter identified by 'name' */		
		Parameter* getParameter(const std::string& name);
		/*!	Returns a const pointer to a parameter identified by 'name' */
		const Parameter* getParameter(const std::string& name) const;

	public:
		/*! \brief Builds the Pdom tree within the kernel */
		PostdominatorTree* pdom_tree();
		/*! \brief Builds the dominator tree within the kernel */
		DominatorTree* dom_tree();
		/*! \brief Builds the data flow graph within the kernel */
		virtual analysis::DataflowGraph* dfg();
		/*! \brief Gets the const dfg */
		virtual const analysis::DataflowGraph* dfg() const;
		/*! \brief Builds the Control tree within the kernel */
		ControlTree* ctrl_tree();
		/*! brief Gets the cfg */
		ControlFlowGraph* cfg();
		/*! brief Gets the const cfg */
		const ControlFlowGraph* cfg() const;

	public:	
		/*!	Returns true if the kernel instance is derived from 
			ExecutableKernel */
		virtual bool executable() const;
		/*! \brief Is this kernel actually a function, not a kernel? */
		bool function() const;
		/*! \brief Write this kernel to a parseable string */
		virtual void write(std::ostream& stream) const;
		
	public:
		/*!	[mangled] name of kernel within module */
		std::string name;
		/*!	Instruction Set Architecture of the kernel */
		Instruction::Architecture ISA;
		/*!	Set of parameters in order specified in the kernel's definition */
		ParameterVector parameters;
		/*! \brief Local variables */
		LocalMap locals;
		/*!	Pointer to the module this kernel belongs to */
		const Module* module;
	};

}

std::ostream& operator<<(std::ostream& s, const ir::Kernel& k);

#endif

