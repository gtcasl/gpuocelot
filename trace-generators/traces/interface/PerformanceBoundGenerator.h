/*! \file PerformanceBoundGenerator.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief computes operations, flops, and memory bandwidth per basic block
*/

#ifndef TRACE_PERFORMANCEBOUNDGENERATOR_H_INCLUDED
#define TRACE_PERFORMANCEBOUNDGENERATOR_H_INCLUDED

// Ocelot includes
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <fstream>

namespace trace {

	/*!
		Base class for generating traces
	*/
	class PerformanceBoundGenerator: public TraceGenerator {	
	public:
		//! \brief specifies how memory bandwidth is computed
		enum CoalescingProtocol {
			Protocol_sm_10,
			Protocol_sm_11,
			Protocol_sm_12,
			Protocol_sm_13,
			Protocol_sm_20,
			Protocol_ideal,
			Protocol_invalid
		};
		
		enum OutputFormat {
			Output_dot,			//! output: dot
			Output_append_csv,	//! output: csv
			Output_invalid
		};
	
		class Counter {
		public:
			Counter();
			
			Counter & operator += (const Counter &c) {
				memoryDemand += c.memoryDemand;
				warpInstructions += c.warpInstructions;
				branchInstructions += c.branchInstructions;
				noopInstructions += c.noopInstructions;
				instructions += c.instructions;
				flops += c.flops;
				sharedBytes += c.sharedBytes;
				bankConflicts += c.bankConflicts;
				
				stackDepth += c.stackDepth;
				stackVisitNodes += c.stackVisitNodes;
				stackVisitEnd += c.stackVisitEnd;
				stackVisitMiddle += c.stackVisitMiddle;
				stackInsert += c.stackInsert;
				stackMerge += c.stackMerge;
				conservativeBranches += c.conservativeBranches;
				
				return *this;
			}
			
		public:
		
			//! \brief bytes transferred to or from global memory [including texture samples]
			size_t memoryDemand;
			
			//! \brief warp instructions
			size_t warpInstructions;
			
			//! \brief number of branch instructions
			size_t branchInstructions;
			
			//! \brief number of no-op instructions
			size_t noopInstructions;
			
			//! \brief dynamic instructions
			size_t instructions;
			
			//! \brief floating-point operations [subset of dynamic instructions]
			size_t flops;
			
			//! \brief counts number of bytes loaded or stored to shared memory
			size_t sharedBytes;
			
			/*! 
				\brief incremented every time a thread conflicts with the address bank of an earlier
					thread in the half-warp - efficiency of shared memory access
			*/
			size_t bankConflicts;

			size_t stackDepth;
			
			size_t stackVisitNodes;	

			size_t stackVisitEnd;
		
			size_t stackVisitMiddle;
		
			size_t stackInsert;
		
			size_t stackMerge;
			
			size_t conservativeBranches;
		};
		
		//! \brief maps basic block label to operation counters
		typedef std::map< std::string, Counter > OperationCounterMap;
	
	public:
		PerformanceBoundGenerator();
		virtual ~PerformanceBoundGenerator();

		/*! \brief called when a traced kernel is launched to retrieve some 
				parameters from the kernel
		*/
		virtual void initialize(const executive::ExecutableKernel& kernel);

		/*! \brief Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() 
			returns
		*/
		virtual void event(const TraceEvent & event);
		
		/*! \brief Called when a kernel is finished. There will be no more 
				events for this kernel.
		*/
		virtual void finish();
		
	protected:
	
		//! \brief visits each basic block and initializes a counter for each block
		void analyzeKernel(const executive::EmulatedKernel &kernel);
		
		//! \brief computes the number of bytes of effective demand from an event given a coalescing protocol
		static size_t computeMemoryDemand(const trace::TraceEvent &event, 
			CoalescingProtocol protocol);
		
		//! \brief determines if instruction is a significant floating-point operation
		static int isFlop(const ir::PTXInstruction &instr);

		//! \brief tests
		static bool isGlobalMemoryOp(const ir::PTXInstruction &instr);
		
		//! \brief computes bytes loaded or stored to shared memory and number of conflicts
		static size_t computeSharedDemand(const trace::TraceEvent &event, int * conflicts);
	
	public:
	
		bool render;
	
		//! \brief specifies the active memory coalescing protocol to employ
		CoalescingProtocol protocol;
		
		//! \brief specifies the output format of the trace generator: [ dot, csv ]
		OutputFormat outputFormat;
		
		//! \brief kernel
		const executive::EmulatedKernel * kernel;

		/*! \brief Counter for creating unique file names. */
		static unsigned int _counter;
		
		/*!	\brief Entry for the current kernel	*/
		KernelEntry _entry;
	
		//! \brief maps basic blocks onto performance counters
		OperationCounterMap counterMap;
		
		//! maps the PC of the last instruction of each block to the block's label
		std::map< int, std::string > PCsToBlocks;
	};
}

std::ostream & operator <<(std::ostream &out, const trace::PerformanceBoundGenerator::Counter &counter);

#endif

