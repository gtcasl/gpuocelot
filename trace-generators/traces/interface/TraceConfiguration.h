/*! \file   TraceConfiguration.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday July 31, 2010
	\brief  The header file for the TraceConfiguration class.
*/

#ifndef TRACE_CONFIGURATION_H_INCLUDED
#define TRACE_CONFIGURATION_H_INCLUDED

#include <traces/interface/WarpSynchronousGenerator.h>
#include <traces/interface/MemoryTraceGenerator.h>
#include <traces/interface/InstructionTraceGenerator.h>
#include <traces/interface/ParallelismTraceGenerator.h>
#include <traces/interface/SharedComputationGenerator.h>
#include <traces/interface/BranchTraceGenerator.h>
#include <traces/interface/CacheSimulator.h>
#include <traces/interface/PerformanceBoundGenerator.h>
#include <traces/interface/ConvergenceGenerator.h>
#include <traces/interface/LoadBalanceGenerator.h>
#include <traces/interface/ControlFlowVisualizer.h>

namespace trace
{
	/*! \brief A singleton used to create instances of trace generators */
	class TraceConfiguration
	{
	public:
		//! \brief configuration for the warp synchronous trace generator
		class WarpSynchronous 
		{
		public:
			WarpSynchronous() : enabled(false), emitHotPaths(false), csv("warpsynchronous.csv") { }
			
			//! \brief whether trace generator is enabled
			bool enabled;

			//! \brief emits dot file visualizing hot paths
			bool emitHotPaths;
			
			//! \brief path to CSV collecting results
			std::string csv;
		};
		
		/*! \brief configuration properties for 
				trace::PerformanceBoundGenerator trace generator
		*/
		class PerformanceBound {
		public:
			PerformanceBound(): enabled(false), protocol(PerformanceBoundGenerator::Protocol_sm_20), 
				render(false), outputFormat(PerformanceBoundGenerator::Output_dot) {} 
		
			/*! \brief Enable the performance bound trace generator */
			bool enabled;
			
			/*! \brief Protocol for memory coalescing */
			PerformanceBoundGenerator::CoalescingProtocol protocol;
			
			/*! \brief if true, a PDF is constructed from the DOT file */
			bool render;
			
			PerformanceBoundGenerator::OutputFormat outputFormat;
		};
		
		/*! \brief configuration properties for ConvergenceGenerator */
		class Convergence {
		public:
			Convergence() : enabled(false), logfile("convergence"), dot(false), render(false) { }
		
			//! \brief indicates trace generator is enabled
			bool enabled;
			
			//! \brief log file to append results
			std::string logfile;		
			
			//! \brief emit CFG as dot file
			bool dot;	
			
			//! \brief if true, a PDF is constructed from the DOT file
			bool render;
		};
		
		/*! \brief configuration of ControlFlowVisualizer */
		class ControlFlow {
		public:
			ControlFlow(): enabled(false), allInstructions(false) { }
			
			//! \brief whether its enabled
			bool enabled;
			
			//! \brief if false, only branch and reconverge instructions are displayed
			bool allInstructions;
		};

	public:
		static TraceConfiguration Singleton;

	public:
		//! \brief path to trace generation database
		std::string database;

		//! \brief indicates traces are in place
		bool inPlaceTraces;

		//! \brief trace::MemoryTraceGenerator
		bool memory;

		//! \brief trace::BranchTraceGenerator
		bool branch;

		//! \brief trace::SharedComputationTraceGenerator
		bool sharedComputation;

		//! \brief trace::ParallelismTraceGenerator
		bool parallelism;

		//! \brief trace::InstructionTraceGenerator
		bool instruction;

		//! \brief trace::CacheSimulator
		bool cacheSimulator;

		//! \brief warp synchronous trace generator
		WarpSynchronous warpSynchronous;
		
		//! \brief performance bound generator
		PerformanceBound performanceBound;
		
		//! \brief trace::ConvergenceGenerator
		Convergence convergence;
		
		//! \brief trace::LoadBalanceGenerator
		bool loadBalance;
		
		ControlFlow controlFlowVisualizer;
	
	public:
		TraceConfiguration();

	private:
		trace::MemoryTraceGenerator _memoryTraceGenerator;
		trace::InstructionTraceGenerator _instructionTraceGenerator;
		trace::SharedComputationGenerator _sharedComputationGenerator;
		trace::BranchTraceGenerator _branchTraceGenerator;
		trace::ParallelismTraceGenerator _parallelismTraceGenerator;
		trace::CacheSimulator _cacheSimulator;
		trace::WarpSynchronousGenerator _warpSynchronous;
		trace::PerformanceBoundGenerator _performanceBound;
		trace::ConvergenceGenerator _convergence;
		trace::LoadBalanceGenerator _loadBalance;
		trace::ControlFlowVisualizer _controlFlowVisualizer;
	};
}

#endif

