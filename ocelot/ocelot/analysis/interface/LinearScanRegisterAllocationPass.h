/*! \file LinearScanRegisterAllocationPass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Monday December 21, 2009
	\brief The header file for the LinearScanRegisterAllocationPass class.
*/

#ifndef LINEAR_SCAN_REGISTER_ALLOCATION_PASS_H_INCLUDED
#define LINEAR_SCAN_REGISTER_ALLOCATION_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/Pass.h>

#include <map>

namespace analysis
{
	/*! \brief Implements the linear scan register allocation algorithm */
	class LinearScanRegisterAllocationPass : public KernelPass
	{
		private:
			/*! \brief A unique ID for a register */
			typedef DataflowGraph::RegisterId RegisterId;

			/*! \brief The range of instructios for which a register is alive */
			class Interval
			{
				public:
					/*! \brief The first instruction in the interval */
					unsigned int begin;
					/*! \brief One past the last instruction in the interval */
					unsigned int end;
			};
	
			/*! \brief A coalesced register represents aliased SSA registers */
			class CoalescedRegister
			{
				public:
					/*! \brief The unique id of the register */
					RegisterId reg;
					/* \brief The live interval for the register */
					Interval interval;
					/*! \brief The allocated name of the register */
					RegisterId allocated;
					/*! \brief Has the register been spilled */
					bool spilled;
					/*! \brief If the register has been spilled, where is 
						it in memory? */
					unsigned int offset;
					/*! \brief The type of the register */
					DataflowGraph::Type type;
			
				public:
					/*! \brief The constructor sets the default values */
					CoalescedRegister();
			};
			
			/*! \brief A vector of coalesced registers */
			typedef std::vector< CoalescedRegister > CoalescedRegisterVector;
			/*! \brief A map from SSA registers to Coalesced registers */
			typedef std::unordered_map< RegisterId, 
				unsigned int > CoalescedRegisterMap;
			/*! \brief A sorted set of registers */
			typedef std::multimap< unsigned int, 
				unsigned int > SortedRegisterMap;

		private:
			/*! \brief The kernel being operated on */
			ir::Kernel* _kernel;
			/*! \brief This is the number of registers reserved for spills */
			RegisterId _reserved;
			/*! \brief This is the total number of spilled registers */
			unsigned int _spills;
			/*! \brief The current number of spilled bytes */
			unsigned int _bytes;
			/*! \brief The total set of coalesced registers */
			CoalescedRegisterVector _coalesced;
			/*! \brief The map from SSA to coalesced registers */
			CoalescedRegisterMap _ssa;
			/*! \brief This is the set of all registers sorted by start point */
			SortedRegisterMap _intervals;
			/*! \brief Sequence of basic blocks stored in program order */
			DataflowGraph::BlockPointerVector _sequence;
			
		public:
			/*! \brief This is the total number of registers */
			RegisterId registers;
			
		private:
			/*! \brief The first pass coalesces SSA registers */
			void _coalesce();
			/*! \brief The second pass computes the live intervals */
			void _computeIntervals();
			/*! \brief The third pass performs register allocation */
			void _allocate();
			/*! \brief The final pass inserts the spill code */
			void _spill();
			/*! \brief Allocate stack space for the spilled regsters */
			void _extendStack();
			
		public:
			/*! \brief Constructor on the number of registers to allocate */
			LinearScanRegisterAllocationPass( unsigned int regs = 8 );		
			/*! \brief Initialize the pass using a specific module */
			void initialize( const ir::Module& m );
			/*! \brief Run the pass on a specific kernel in the module */
			void runOnKernel( ir::Kernel& k );
			/*! \brief Finalize the pass */
			void finalize( );
			
	};
}

#endif

