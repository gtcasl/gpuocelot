/*! \file BoundsCheckPass.h
    \author Naila Farooqui <naila@cc.gatech.edu>
    \date Friday, April 1, 2011
    \brief The header file for the BoundsCheckPass class.
*/

#ifndef BOUNDS_CHECK_PASS_H_INCLUDED
#define BOUNDS_CHECK_PASS_H_INCLUDED

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
    class BoundsCheckPass: public BasicBlockInstrumentationPass//KernelPass
    {
        public:
            /*! \brief default constructor */
            BoundsCheckPass();
            
        public:
            void initialize(ir::Module &);
            
            void finalize();
            
            /*! \brief Run the pass on a specific kernel */
            void runOnKernel( ir::IRKernel& k );
            
            /*! \brief Run the pass on a specific block */
            void _runOnBlock( analysis::DataflowGraph::iterator &block, 
                size_t location);
            
            void runOnModule( ir::Module& m);
            
            analysis::DataflowGraph& dfg();
            
            void calcOffset(analysis::DataflowGraph::iterator block, 
                size_t& location);
            
            void _checkBounds(ir::ControlFlowGraph::iterator &block);
            
            void checkBounds( 
                analysis::DataflowGraph::iterator &block, 
                const ir::PTXInstruction& memInst, 
                unsigned long &loc );
            
            std::string kernelReportInfo() const;
            
            /*! \brief returns label of allocation map */
            std::string getAllocMap();
            
            /*! \brief returns label of allocation map */
            std::string getFuncName();
            
        public:
            std::string baseAddress;
            std::string allocMapAddress;
            analysis::DataflowGraph::RegisterId finalAddr;
            unsigned int entries;
            ir::IRKernel *kernelPointer;
    };
}

#endif

