/*! \file AlignmentCheckPass.h
    \author Naila Farooqui <naila@cc.gatech.edu>
    \date Friday, April 1, 2011
    \brief The header file for the AlignmentCheckPass class.
*/

#ifndef ALIGNMENT_CHECK_PASS_H_INCLUDED
#define ALIGNMENT_CHECK_PASS_H_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/transforms/interface/BasicBlockInstrumentationPass.h>

namespace ir
{
    class Module;
}

namespace transforms
{
    /*! \brief Implements the dynamic instruction count instrumentation */
    class AlignmentCheckPass: public BasicBlockInstrumentationPass//KernelPass
    {
        public:
            /*! \brief default constructor */
            AlignmentCheckPass();
            
        public:
            void initialize(ir::Module &);
            
            void finalize();
            
            /*! \brief Run the pass on a specific kernel */
            void runOnKernel( ir::IRKernel& k );
            
            /*! \brief Run the pass on a specific block */
            void _runOnBlock( analysis::DataflowGraph::iterator block, 
                size_t location);
            
            analysis::DataflowGraph& dfg();
            
            void calcOffset(analysis::DataflowGraph::iterator block, 
                size_t& location);
            
            void checkAlignment( 
                const analysis::DataflowGraph::iterator block, 
                const ir::PTXInstruction& memInst, 
                unsigned long &loc );
            
            std::string kernelReportInfo() const;
            
        public:
            std::string baseAddress;
            unsigned int entries;
    };
}

#endif

