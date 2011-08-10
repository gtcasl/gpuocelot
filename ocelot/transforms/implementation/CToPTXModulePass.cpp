/*! \file CToPTXModulePass.cpp
	\date Tuesday July 1, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CToPTXModulePass class
*/

#ifndef C_TO_PTX_MODULE_PASS_CPP_INCLUDED
#define C_TO_PTX_MODULE_PASS_CPP_INCLUDED

#include <ocelot/transforms/interface/CToPTXModulePass.h>
#include <ocelot/transforms/interface/CToPTXInstrumentationPass.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXStatement.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace transforms
{

    void CToPTXModulePass::runOnModule(ir::Module& m)
    {
        /*
        CToPTXInstrumentationPass pass("resources/memoryEfficiency.c");
	
	    pass.initialize(m);

	    for(ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		    kernel != m.kernels().end(); ++kernel)
	    {
		    pass.runOnKernel(*kernel->second);
	    }

	    pass.finalize();
	    */
	    
	    ir::PTXKernel *kernel = new ir::PTXKernel("myKernel", true);
        m.insertKernel(kernel);
    }
	
    void CToPTXModulePass::initialize( ir::Module& m )
	{   

	}

    void CToPTXModulePass::finalize( )
	{
	
	}

    
    
}


#endif
