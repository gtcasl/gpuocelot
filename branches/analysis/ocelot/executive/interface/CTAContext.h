/*!
	\file CTAContext.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief the CTAContext contain block- and thread-specific data structures
*/

#ifndef EXECUTIVE_CTACONTEXT_H_INCLUDED
#define EXECUTIVE_CTACONTEXT_H_INCLUDED

#include <iostream>
#include <vector>
#include <boost/dynamic_bitset.hpp>

#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/Kernel.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

	class EmulatedKernel;
	class CooperativeThreadArray;
	
	class CTABarrier {
	public:
		CTABarrier() { }
	
		CTABarrier(size_t size): participating(size), arrived(size, 0) {
		}
		
		void initialize(size_t size) {
			arrived = boost::dynamic_bitset<>(size, 0);
			participating = size;
		}
	
		void setParticipating(size_t size) {
			participating = size;
		}
	
		/*! returns true if enough threads have reached the barrier */
		bool satisfied() const {
			return participating == arrived.count();
		}
		
		void arrive(const boost::dynamic_bitset<> & threads) {
			arrived |= threads;
		}
		
		void clear() {
			arrived.reset();
		}
		
	public:
	
		size_t participating;
	
		boost::dynamic_bitset<> arrived;
	};

	class CTAContext {
	public:
		CTAContext(const EmulatedKernel *kernel = 0,
			CooperativeThreadArray *cta = 0);

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
	
		/*! Get the active mask after predication */
		boost::dynamic_bitset<> predicateMask( const ir::PTXInstruction &instr);

		
	};
}

#endif

