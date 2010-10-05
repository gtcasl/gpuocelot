/*!
	\file CTAContext.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief the CTAContext contain block- and thread-specific data structures
*/

#ifndef EXECUTIVE_CTACONTEXT_H_INCLUDED
#define EXECUTIVE_CTACONTEXT_H_INCLUDED

#include <boost/dynamic_bitset.hpp>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/Kernel.h>


#define IPDOM_RECONVERGENCE 1
#define BARRIER_RECONVERGENCE 2
#define GEN6_RECONVERGENCE 3
#define SORTED_PREDICATE_STACK_RECONVERGENCE 4

// specify reconvergence mechanism here
#define RECONVERGENCE_MECHANISM IPDOM_RECONVERGENCE

namespace executive {

	class EmulatedKernel;
	class CooperativeThreadArray;

	class CTAContext {
	public:
		CTAContext() { }
		
		CTAContext(const EmulatedKernel *kernel, CooperativeThreadArray *cta);

		~CTAContext();

		/*! Program counter - index into PTXInstruction vector */
		int PC;

		/*! Indicates whether the block is still running */
		bool running;

		/*! Thread mask with a 1 indicating activity */
		boost::dynamic_bitset<> active;

		/*! Pointer to owning kernel */
		const EmulatedKernel *kernel;

		/*! Pointer to owning CTA */
		CooperativeThreadArray *cta;

	public:

		/*! Given a thread's ID, determine if the instruction should execute */
		bool predicated(int threadID, const ir::PTXInstruction &instr);
		
	};

}

#endif

