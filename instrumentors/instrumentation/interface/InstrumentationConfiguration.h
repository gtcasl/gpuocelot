/*! \file   InstrumentationConfiguration.h
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date   Tuesday November 22, 2011
	\brief  The header file for the InstrumentationConfiguration class.
*/

#ifndef INSTRUMENTATION_CONFIGURATION_H_INCLUDED
#define INSTRUMENTATION_CONFIGURATION_H_INCLUDED

#include <instrumentation/interface/ClockCycleCountInstrumentor.h>
#include <instrumentation/interface/BasicBlockInstrumentor.h>
#include <instrumentation/interface/WarpReductionInstrumentor.h>

#include <mqueue.h>

namespace instrumentation
{
	/*! \brief A singleton used to create instances of instrumentors */
	class InstrumentationConfiguration
	{
	
	public:
		//! \brief configuration for the clock cycle count instrumentor */
		class ClockCycleCountInstrumentor 
		{
		public:
			ClockCycleCountInstrumentor() : enabled(false) { }
			
			//! \brief whether instrumentor is enabled
			bool enabled;
			
			//! \brief path to log file
			std::string logfile;
		};
		
		/*! \brief configuration properties for analysis::BasicBlockInstrumentor */
			class BasicBlockInstrumentor
			{
			public:
					BasicBlockInstrumentor() : enabled(false) { }
				
			public:
			        enum BasicBlockInstrumentationType {
			            executionCount,
			            instructionCount
		            };	
			
					//! \brief specifies if instrumentation is enabled */
					bool enabled;
                    //! \brief specifies the logfile for storing results of this instrumentation */
                    std::string logfile;			
                    //! \brief type of basic block instrumentation */
                    BasicBlockInstrumentationType type;
			};

            /*! \brief configuration properties for analysis::WarpReductionInstrumentor */
			class WarpReductionInstrumentor
			{
			public:
					WarpReductionInstrumentor() : enabled(false) { }
				
            public:
                    enum InstrumentationType {
			            memoryEfficiency,
			            branchDivergence,
                        instructionCount
		            };	

			public:
			
					//! \brief specifies if instrumentation is enabled */
					bool enabled;
                    //! \brief specifies the logfile for storing results of this instrumentation */
                    std::string logfile;		
                    //! \brief type of instrumentation */
                    InstrumentationType type;	
			};
		
	public:
		static InstrumentationConfiguration Singleton;

	public:
    
        //! \brief message queue descriptor
        mqd_t messageQueue;    

		
		bool clockCycleCount;
		bool memoryEfficiency;
		bool branchDivergence;
		bool threadInstructionCount;
		bool warpInstructionCount;
		bool basicBlockExecutionCount;

		//! \brief clock cycle count instrumentor
		ClockCycleCountInstrumentor clockCycleCountInstrumentor;
		
		//! \brief basic block instrumentor
		BasicBlockInstrumentor basicBlockInstrumentor;
		
		//! \brief warp reduction instrumentor
		WarpReductionInstrumentor warpReductionInstrumentor;
	
	public:
		InstrumentationConfiguration();
		~InstrumentationConfiguration();

	private:
		instrumentation::ClockCycleCountInstrumentor _clockCycleCountInstrumentor;
		instrumentation::BasicBlockInstrumentor _basicBlockInstrumentor;
		instrumentation::WarpReductionInstrumentor _warpReductionInstrumentor;
		
	};
}

#endif


