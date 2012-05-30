/*! \file ClockCycleCountPass.h
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the ClockCycleCountPass class
*/

#ifndef KERNEL_CLOCK_CYCLE_COUNT_PASS_H_INCLUDED
#define KERNEL_CLOCK_CYCLE_COUNT_PASS_H_INCLUDED

#include <ocelot/transforms/interface/Pass.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace ir
{
	class Module;
    class PTXKernel;
}

namespace transforms
{

	/*! \brief A class for an instrumentation pass that retrieves the 
        number of clock cycles and SM ID per kernel execution.
	*/
	class ClockCycleCountPass : public KernelPass
	{
		private:
			ir::PTXKernel* _kernel;
			
		protected:
		    analysis::DataflowGraph& dfg();
		
		public:
			ClockCycleCountPass();
            std::string kernelClockSMInfo() const;
			
		public:
			/*! \brief Initialize the pass using a specific kernel */
			void initialize( ir::Module& m );
			/*! \brief Run the pass on a specific kernel */
			void runOnKernel(ir::IRKernel& k);
			/*! \brief Finalize the pass */
			void finalize( );		     
            
	};
}

#endif

