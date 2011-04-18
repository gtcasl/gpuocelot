/*! \file IRKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 15, 2009
	\brief The header file for the IRKernel class.
*/

#ifndef IR_KERNEL_H_INCLUDED
#define IR_KERNEL_H_INCLUDED

// Ocelot Includes
#include <ocelot/ir/interface/Kernel.h>

namespace analysis {
	class DataflowGraph;
	class DivergenceAnalysis;
}

namespace ir {
	class ControlFlowGraph;
	class DominatorTree;
	class PostdominatorTree;
	class ControlTree;
}

namespace ir {
	/*! A wrapper class containging common analysis for kernels */
	class IRKernel : public Kernel {
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
		/*! \brief Divergence analysis constructed from the dfg */
		analysis::DivergenceAnalysis* _dva;
		/*! \brief Control tree constructed from the cfg */
		ControlTree* _ct;
		
	public:
		/*!	Constructs an empty kernel */
		IRKernel(Instruction::Architecture isa = Instruction::Unknown,
			const std::string& name = "", bool isFunction = false,
			const ir::Module* module = 0);
		/*!	Destructs kernel */
		virtual ~IRKernel();
		/*! \brief Copy constructor (deep) */
		IRKernel( const IRKernel& k );
		/*! \brief Assignment operator (deep) */
		const IRKernel& operator=( const IRKernel& k );

	public:
		/*! \brief Builds the Pdom tree within the kernel */
		PostdominatorTree* pdom_tree();
		/*! \brief Builds the dominator tree within the kernel */
		DominatorTree* dom_tree();
		/*! \brief Builds the data flow graph within the kernel */
		virtual analysis::DataflowGraph* dfg();
		/*! \brief Gets the const dfg */
		virtual const analysis::DataflowGraph* dfg() const;
		/*! \brief Builds the divergence analysis within the kernel */
		virtual analysis::DivergenceAnalysis* div_analy();
		/*! \brief Gets the const divergence analysis  */
		virtual const analysis::DivergenceAnalysis* div_analy() const;
		/*! \brief Builds the Control tree within the kernel */
		ControlTree* ctrl_tree();
		/*! \brief Gets the cfg */
		ControlFlowGraph* cfg();
		/*! \brief Gets the const cfg */
		const ControlFlowGraph* cfg() const;

	public:
		/*! \brief Clear dataflow graph */
		void clear_dfg();
		/*! \brief Clear control tree */
		void clear_ctrl_tree();
		/*! \brief Clear post dominator tree */
		void clear_pdom_tree();
		/*! \brief Clear dominator tree */
		void clear_dom_tree();
		/*! \brief Clear divergence analysis */
		void clear_div_analy();

	public:	
		/*!	Returns true if the kernel instance is derived from 
			ExecutableKernel */
		virtual bool executable() const;
	};

}

#endif

