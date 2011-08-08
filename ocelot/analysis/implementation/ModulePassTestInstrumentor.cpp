/*! \file ModulePassTestInstrumentor.cpp
	\date Monday July 30, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the ModulePassTestInstrumentor class.
*/

#ifndef MODULE_PASS_TEST_INSTRUMENTOR_CPP_INCLUDED
#define MODULE_PASS_TEST_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/ModulePassTestInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/CToPTXModulePass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

using namespace hydrazine;

namespace analysis
{

    void ModulePassTestInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void ModulePassTestInstrumentor::analyze(ir::Module &module) {
       
  
    }

    void ModulePassTestInstrumentor::initialize() {
        
        
    }

    transforms::Pass *ModulePassTestInstrumentor::createPass() {

        return new transforms::CToPTXModulePass;  
    }

    void ModulePassTestInstrumentor::extractResults(std::ostream *out) {

     
    }

    ModulePassTestInstrumentor::ModulePassTestInstrumentor() : description("Module Pass Test") {
    }
    

}

#endif
