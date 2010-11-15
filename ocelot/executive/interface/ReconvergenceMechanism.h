/*!
	\file ReconvergenceMechanism.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 15, 2010
	\brief extracts the reconvergence mechanism from CooperativeThreadArray
*/

#ifndef OCELOT_EXECUTIVE_RECONVERGENCEMECHANISM_H_INCLUDED
#define OCELOT_EXECUTIVE_RECONVERGENCEMECHANISM_H_INCLUDED

// C++ includes
#include <deque>

// Ocelot includes
#include <ocelot/executive/interface/CTAContext.h>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/ir/interface/Texture.h>
#include <ocelot/trace/interface/TraceEvent.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

	class EmulatedKernel;

	/*!
		\brief base class for abstract reconvergence mechanism within emulator
	*/
	class ReconvergenceMechanism {
	public:
		typedef std::deque<CTAContext> RuntimeStack;
	
	public:
		ReconvergenceMechanism(executive::EmulatedKernel *kernel);
		
	public:
		//! \brief gets the active context
		virtual executive::CTAContext & getContext();
	
		//! \brief updates the predicate mask of the active context before instructions execute
		virtual void evalPredicate(executive::CTAContext &context);
		
		/*! 
			\brief implements branch instruction and updates CooperativeThreadArray state
			\return true on divergent branch
		*/
		virtual bool eval_Bra(executive::CTAContext &context, 
			const ir::PTXInstruction &instr, 
			const boost::dynamic_bitset<> & branch, 
			const boost::dynamic_bitset<> & fallthrough);

		/*! 
			\brief implements a barrier instruction
		*/
		virtual void eval_Bar(executive::CTAContext &context, const ir::PTXInstruction &instr);
		
		/*!
			\brief implements reconverge instructions
		*/
		virtual void eval_Reconverge(executive::CTAContext &context, const ir::PTXInstruction &instr);

		/*! 
			\brief updates the active context to the next instruction
		*/
		virtual void nextInstruction(executive::CTAContext &context, const ir::PTXInstruction &instr);

	public:
		//! \brief emulated kernel instance
		EmulatedKernel *kernel;
	
		//! \brief context stack
		RuntimeStack runtimeStack;
		
		//! \brief events specifically related to thread divergence and reconvergence
		trace::ReconvergenceTraceEvent currentEvent;
	};

	//
	//
	//
	
	class ReconvergenceIPDOM: public ReconvergenceMechanism {
	public:
		ReconvergenceIPDOM(executive::EmulatedKernel *kernel);
		
		virtual bool eval_Bra(executive::CTAContext &context, 
			const ir::PTXInstruction &instr, 
			const boost::dynamic_bitset<> & branch, 
			const boost::dynamic_bitset<> & fallthrough);
		virtual void eval_Bar(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void eval_Reconverge(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void nextInstruction(executive::CTAContext &context, const ir::PTXInstruction &instr);
	};
	
	class ReconvergenceBarrier: public ReconvergenceMechanism {
	public:

		ReconvergenceBarrier(executive::EmulatedKernel *kernel);
		
		virtual bool eval_Bra(executive::CTAContext &context, 
			const ir::PTXInstruction &instr, 
			const boost::dynamic_bitset<> & branch, 
			const boost::dynamic_bitset<> & fallthrough);
		virtual void eval_Bar(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void eval_Reconverge(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void nextInstruction(executive::CTAContext &context, const ir::PTXInstruction &instr);
	};
	
	
	class ReconvergenceTFGen6: public ReconvergenceMechanism {
	public:
		typedef std::vector <int> ThreadIdVector;
		
	public:
		ReconvergenceTFGen6(executive::EmulatedKernel *kernel);
	
		virtual void evalPredicate(executive::CTAContext &context);
		virtual bool eval_Bra(executive::CTAContext &context, 
			const ir::PTXInstruction &instr, 
			const boost::dynamic_bitset<> & branch, 
			const boost::dynamic_bitset<> & fallthrough);
		virtual void eval_Bar(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void eval_Reconverge(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void nextInstruction(executive::CTAContext &context, const ir::PTXInstruction &instr);
		
	public:
	
		//! \brief program counters for each thread
		ThreadIdVector threadPCs;
	};
	
	class ReconvergenceTFSortedStack: public ReconvergenceMechanism {
	public:
		ReconvergenceTFSortedStack(executive::EmulatedKernel *kernel);
	
		virtual void evalPredicate(executive::CTAContext &context);
		virtual bool eval_Bra(executive::CTAContext &context, 
			const ir::PTXInstruction &instr, 
			const boost::dynamic_bitset<> & branch, 
			const boost::dynamic_bitset<> & fallthrough);
		virtual void eval_Bar(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void eval_Reconverge(executive::CTAContext &context, const ir::PTXInstruction &instr);
		virtual void nextInstruction(executive::CTAContext &context, const ir::PTXInstruction &instr);
	};
}

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif

