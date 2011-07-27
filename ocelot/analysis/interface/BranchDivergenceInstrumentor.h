/*! \file BranchDivergenceInstrumentor.h
	\date Monday July 18, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for BranchDivergenceInstrumentor
*/

#ifndef BRANCH_DIVERGENCE_INSTRUMENTOR_H_INCLUDED
#define BRANCH_DIVERGENCE_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <map>
#include <algorithm>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/transforms/interface/Pass.h>

#define WARP_SIZE   32

namespace analysis
{
	/*! \brief Able to run the branch divergence instrumentation pass over PTX modules */
	class BranchDivergenceInstrumentor : public analysis::PTXInstrumentor
	{
		public:       
            /*! \brief The description of the specified pass */
            std::string description;
      
            size_t *branchDivInfo;
            
        private:
            unsigned long warpCount;
		    unsigned long totalBranches;
		    unsigned long conditionalBranches;
			
		public:
			/*! \brief The default constructor */
			BranchDivergenceInstrumentor();

            /*! \brief The checkConditions method verifies that the defined conditions are met for this instrumentation */
            void checkConditions();

            /*! \brief The analyze method performs any necessary static analysis */
            virtual void analyze(ir::Module &module);

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPass method instantiates the instrumentation pass */
            transforms::Pass *createPass();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();	

            /*! \brief extracts results for the branch divergence instrumentation */
            void extractResults(std::ostream *out);
	};
}

#endif
