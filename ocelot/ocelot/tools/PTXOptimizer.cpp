/*! \file PTXOptimzer.cpp
	\date Thursday December 31, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the Ocelot PTX optimizer
*/

#ifndef PTX_OPTIMIZER_CPP_INCLUDED
#define PTX_OPTIMIZER_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/tools/PTXOptimizer.h>
#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/transforms/interface/PassFactory.h>

#include <ocelot/transforms/interface/LinearScanRegisterAllocationPass.h>
#include <ocelot/transforms/interface/SubkernelFormationPass.h>
#include <ocelot/transforms/interface/SplitBasicBlockPass.h>
#include <ocelot/transforms/interface/FunctionInliningPass.h>
#include <ocelot/transforms/interface/ConstantPropagationPass.h>

#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/interface/ArgumentParser.h>
#include <hydrazine/interface/Exception.h>
#include <hydrazine/interface/string.h>
#include <hydrazine/interface/debug.h>

// Standard Library Includes
#include <fstream>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace tools
{

PTXOptimizer::PTXOptimizer()
{

}

void PTXOptimizer::optimize()
{		
	report("Running PTX to PTX Optimizer.");
	
	report(" Loading module '" << input << "'");
	ir::Module module( input );

	transforms::PassManager manager( &module );

	if( registerAllocationType != "none" &&
		!registerAllocationType.empty() )
	{
		transforms::Pass* pass =
			transforms::PassFactory::createPass( registerAllocationType );
		
		applyOptions( pass );
		
		manager.addPass( *pass );
	}

	for( auto name = passes.begin(); name != passes.end(); ++name )
	{
		if( name->empty() ) continue;
		
		transforms::Pass* pass =
			transforms::PassFactory::createPass( *name );
		
		applyOptions( pass );
		
		manager.addPass( *pass );
	}
	
	if( input.empty() )
	{
		std::cout << "No input file name given.  Bailing out." << std::endl;
		return;
	}

	manager.runOnModule();
	manager.destroyPasses();
	
	std::ofstream out( output.c_str() );
	
	if( !out.is_open() )
	{
		throw hydrazine::Exception( "Could not open output file " 
			+ output + " for writing." );
	}
	
	module.writeIR( out, ir::PTXEmitter::Target_NVIDIA_PTX30 );

	if(!cfg) return;
	
	for( ir::Module::KernelMap::const_iterator 
		kernel = module.kernels().begin(); 
		kernel != module.kernels().end(); ++kernel )
	{
		report(" Writing CFG for kernel '" << kernel->first << "'");
		std::ofstream out( std::string( 
			kernel->first + "_cfg.dot" ).c_str() );
	
		if( !out.is_open() )
		{
			throw hydrazine::Exception( "Could not open output file " 
				+ output + " for writing." );
		}
	
		module.getKernel( kernel->first )->cfg()->write( out );
	}
}

void PTXOptimizer::applyOptions( transforms::Pass* pass )
{
	transforms::LinearScanRegisterAllocationPass* linearscan = 
		dynamic_cast<transforms::LinearScanRegisterAllocationPass*>( pass );
	
	if( linearscan != 0 )
	{
		linearscan->setRegisterCount( registerCount );
	}
	
	transforms::SplitBasicBlockPass* splitblocks = 
		dynamic_cast<transforms::SplitBasicBlockPass*>( pass );
	
	if( splitblocks != 0 )
	{
		splitblocks->setMaximumBlockSize( basicBlockSize );
	}

	transforms::FunctionInliningPass* inlining = 
		dynamic_cast<transforms::FunctionInliningPass*>( pass );
	
	if( inlining != 0 )
	{
		inlining->thresholdToInline = inliningThreshold;
	}
	
	transforms::SubkernelFormationPass* subkernel = 
		dynamic_cast<transforms::SubkernelFormationPass*>( pass );
	
	if( subkernel != 0 )
	{
		subkernel->setExpectedRegionSize( subkernelSize );
	}
}
	
}

static tools::PTXOptimizer::StringSet parsePassTypes(
	const std::string& passList )
{
	report("Checking for pass types.");
	hydrazine::StringVector passes = hydrazine::split( passList, "," );
	
	for( auto pass = passes.begin(); pass != passes.end(); ++pass )
	{
		*pass = hydrazine::strip( *pass, " " );
	}
	
	return tools::PTXOptimizer::StringSet( passes.begin(), passes.end() );
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	parser.description( "The Ocelot PTX to PTX optimizer." );
	tools::PTXOptimizer optimizer;
	std::string passes;
	
	parser.parse( "-i", "--input", optimizer.input, "",
		"The ptx file to be optimized." );
	parser.parse( "-o", "--output", optimizer.output, 
		"_optimized_" + optimizer.input, "The resulting optimized file." );
	parser.parse( "-a", "--allocator", optimizer.registerAllocationType, "none",
		"The type of register allocator to use (linearscan)." );
	parser.parse( "-r", "--max-registers", optimizer.registerCount, 32,
		"The number of registers available for allocation." );
	parser.parse( "-s", "--subkernel-size", optimizer.subkernelSize, 70,
		"The target size for subkernel formation." );
	parser.parse( "-I", "--inlining-threshold",
		optimizer.inliningThreshold, 1000,
		"Inline functions with bodies smaller than this." );
	parser.parse( "-b", "--block-size", optimizer.basicBlockSize, 50,
		"The target size for block splitting." );
	parser.parse( "-p", "--passes", passes, "", 
		"A list of optimization passes (remove-barriers, " 
		"reverse-if-conversion, subkernel-formation, structural-transform, "
		"mimd-threading, dead-code-elimination, split-blocks, "
		"sync-elimination, hoist-special-definitions, "
		"simplify-cfg, loop-unrolling, lock-step, function-inlining, "
		"global-value-numbering, shared-ptr-attribute, "
		"constant-propagation, hoist-parameters)" );
	parser.parse( "-c", "--cfg", optimizer.cfg, false, 
		"Dump out the CFG's of all generated kernels." );
	parser.parse();
	
	optimizer.passes = parsePassTypes( passes );
	
	optimizer.optimize();

	return 0;
}

#endif

