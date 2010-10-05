/*!
	\file WarpSynchronousGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 1 April 2010
	\brief detects suitability for kernels to execute in warp-synchronized regions
*/

#ifndef WARP_SYNCHRONOUS_GENERATOR_H_INCLUDED
#define WARP_SYNCHRONOUS_GENERATOR_H_INCLUDED

// C++ includes
#include <vector>
#include <map>

// Boost includes
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <traces/interface/KernelEntry.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

namespace boost
{
	namespace archive
	{
		class text_oarchive;
	}
}

namespace trace
{
	
	/*!
		\brief For each kernel, identify a set of instructions potentially worth promoting to
			vectorized instructions, then measure the activity mask for each n-wide virtual warp
			that might execute them.

	*/
	class WarpSynchronousGenerator : public TraceGenerator {
		public:
			
			/*!
				\brief base class for counting warp-synchronous events
			*/
			class WarpCounter {
			public:

				WarpCounter();

				void event(int warpSize, const TraceEvent &event);

			public:

				//! \brief a warp-synchronous event took place
				size_t synchronous;

				//! \brief an event took place
				size_t events;
			};
			
			/*!
				\brief control-flow sensitive counter recording potentially vectorizable instructions
			*/
			class InstructionCounter: public WarpCounter {
			public:

				InstructionCounter();

			public:

			};
			
			typedef std::map< ir::PTXOperand::DataType, InstructionCounter> DataInstructionCounter;

			/*!
				\brief maps an opcode and data type onto an instruction counter
			*/
			typedef std::map< ir::PTXInstruction::Opcode, 
				 DataInstructionCounter > WarpInstructionCounter;
			
			/*!
				\brief special counter structure for load/store operations
			*/
			class LSInstructionCounter: public WarpCounter {
			public:

				LSInstructionCounter();

				void event(int warpSize, const TraceEvent &event);

			public:
				
				//! \brief number of words loaded by a kernel
				size_t wordsLoaded;
				
				//! \brief number of words stored by a kernel
				size_t wordsStored;
			};

			/*!
				\brief counts number of times a warp diverges at a branch
			*/
			class BranchCounter: public WarpCounter {
			public:

				BranchCounter();

			public:

				int target;
			};

			class TargetCounter: public WarpCounter {
			public:
				TargetCounter();
			};
			
			typedef std::map< const ir::ControlFlowGraph::BasicBlock::Edge *, WarpCounter > EdgeCounterMap;

			/*!
				\brief all such counters for a particular warp size
			*/
			class SynchronousInstructionCounter {
			public:
				SynchronousInstructionCounter();
				void event(int warpSize, const TraceEvent &event);

			public:
			
				LSInstructionCounter counterLoadStore;
				
				WarpInstructionCounter counterVectorizable;

				//! \brief maps a particular branch's PC to a branch counter
				std::map< int, BranchCounter > counterBranches;

				//! \brief maps a particular branch target's PC to its counter
				std::map< int, TargetCounter > counterTargets;

				//! \brief maps a particular edge to a counter
				EdgeCounterMap counterEdges;
			};

			/*!
				\brief formatter for CFG
			*/
			class DotFormatter : public ir::ControlFlowGraph::BasicBlock::DotFormatter {
			public:
	
				WarpSynchronousGenerator *traceGenerator;

				int warpSize;

				size_t minEvents;	// minimum (nonzero) number of events
				size_t maxEvents; // maximum number of events
				std::map< std::string , TargetCounter > blockCounter;
				EdgeCounterMap counterEdges;

			public:
				static std::string colorToString(unsigned int color);
				static std::string colorToString(unsigned int r, unsigned int g, unsigned int b, unsigned int a=0);

				std::string toString(const ir::ControlFlowGraph::BasicBlock *block);
				std::string toString(const ir::ControlFlowGraph::BasicBlock::Edge *edge);
			};
			
			/*! 
				\brief maps warp size to a particular structure of counters
			*/
			std::map< int, SynchronousInstructionCounter > WarpSynchronousCounters;

		private:
			/*! \brief Counter for creating unique file names. */
			static unsigned int _counter;
		
		public:

			/*!	\brief Entry for the current kernel	*/
			KernelEntry _entry;

			/*! \brief control flow graph from kernel */
			const ir::ControlFlowGraph *controlFlowGraph;

			/*! \brief maps a PC to a basic block label */
			std::map< int, std::string > branchTargetsToBlock;

			/*! \brief inverse of branchTargetsToBlock */
			std::map< std::string, int > blockToBranchTarget;
			
		public:
		
			/*!
				\brief identifies collection of warp sizes to compute results for
			*/
			std::vector<int> warpSizes;

			/*!
				\brief collection of counters mapped to by warp sizes
			*/
			std::map< int, SynchronousInstructionCounter > warpCounters;
			
		public:
		
			/*!	\brief Initialize the file pointer to 0 */
			WarpSynchronousGenerator();
			
			~WarpSynchronousGenerator();
		
			/*!	\brief Initializes the trace generator when a new kernel is 
					about to be launched.
				\param kernel The kernel used to initialize the generator
			*/
			void initialize(const executive::ExecutableKernel& kernel);

			/*!
				\brief Called whenever an event takes place.

				\param even The TraceEvent that just occurred
				Note, the const reference 'event' is only valid until event() 
				returns
			*/
			void event( const TraceEvent& event );
			
			/*!	\brief Finalize the trace and dump the results to disk.
				
				Add a databse entry for the trace as well.
			*/
			void finish();

		protected:

			/*!
				\brief emits results of trace generator as JSON
			*/
			void outputSynchronousStatistics();

			/*!
				\brief emits DOT files for each kernel with blocks colored by hot path for a given
					warp size
			*/
			void outputHotPaths(int warpSize);
	};
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////

#endif

