/*! \file PTXOptimzer.cpp
	\date Thursday December 31, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the Ocelot PTX optimizer
*/

#ifndef PTX_OPTIMIZER_CPP_INCLUDED
#define PTX_OPTIMIZER_CPP_INCLUDED

#include <ocelot/analysis/interface/PTXOptimizer.h>
#include <ocelot/analysis/interface/PassManager.h>
#include <ocelot/analysis/interface/LinearScanRegisterAllocationPass.h>
#include <ocelot/analysis/interface/RemoveBarrierPass.h>
#include <ocelot/analysis/interface/StructuralAnalysis.h>
#include <ocelot/analysis/interface/ConvertPredicationToSelectPass.h>
#include <ocelot/analysis/interface/SubkernelFormationPass.h>

#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#include <fstream>

namespace analysis
{
	PTXOptimizer::PTXOptimizer() : registerAllocationType( 
		InvalidRegisterAllocationType ), passes( 0 )
	{
	
	}

	void PTXOptimizer::optimize()
	{		
		report("Running PTX to PTX Optimizer.");
		
		report(" Loading module '" << input << "'");
		ir::Module module( input );

		PassManager manager( &module );

		if( registerAllocationType == LinearScan )
		{
			Pass* pass = new analysis::LinearScanRegisterAllocationPass( 
				registerCount );
			manager.addPass( *pass );
		}

		if( passes & SubkernelFormation )
		{
			Pass* pass = new analysis::SubkernelFormationPass;
			manager.addPass( *pass );
		}
		
		if( passes & RemoveBarriers )
		{
			Pass* pass = new analysis::RemoveBarrierPass;
			manager.addPass( *pass );
		}

		if( passes & StructuralAnalysis )
		{
			Pass* pass = new analysis::StructuralAnalysis;
			manager.addPass( *pass );
		}

		if( passes & ReverseIfConversion )
		{
			Pass* pass = new analysis::ConvertPredicationToSelectPass;
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
		
		module.writeIR( out );

		if(!cfg) return;
		
		for( ir::Module::KernelMap::const_iterator 
			kernel = module.kernels().begin(); 
			kernel != module.kernels().end(); ++kernel )
		{
			report(" Writing CFG for kernel '" << kernel->first << "'");
			std::ofstream out( kernel->first + "_cfg.dot" );
		
			if( !out.is_open() )
			{
				throw hydrazine::Exception( "Could not open output file " 
					+ output + " for writing." );
			}
		
			module.getKernel( kernel->first )->cfg()->write( out );
		}
	}
}

static int parsePassTypes( const std::string& passList )
{
	int types = analysis::PTXOptimizer::InvalidPassType;
	
	report("Checking for pass types.");
	hydrazine::StringVector passes = hydrazine::split( passList, "," );
	for( hydrazine::StringVector::iterator pass = passes.begin(); 
		pass != passes.end(); ++pass )
	{
		*pass = hydrazine::strip( *pass, " " );
		report( " Checking option '" << *pass << "'" );
		if( *pass == "remove-barriers" )
		{
			report( "  Matched remove-barriers." );
			types |= analysis::PTXOptimizer::RemoveBarriers;
		}
		else if( *pass == "reverse-if-conversion" )
		{
			report( "  Matched reverse-if-conversion." );
			types |= analysis::PTXOptimizer::ReverseIfConversion;
		}
		else if( *pass == "structural-analysis" )
		{
			report( "  Matched structural-analysis." );
			types |= analysis::PTXOptimizer::StructuralAnalysis;
		}
		else if( *pass == "subkernel-formation" )
		{
			report( "  Matched subkernel-formation." );
			types |= analysis::PTXOptimizer::SubkernelFormation;
		}
		else if( !pass->empty() )
		{
			std::cout << "==Ocelot== Warning: Unknown pass name - '" << *pass 
				<< "'\n";
		}
	}
	return types;
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	parser.description( "The Ocelot PTX to PTX optimizer." );
	analysis::PTXOptimizer optimizer;
	std::string allocator;
	std::string passes;
	
	parser.parse( "-i", "--input", optimizer.input, "",
		"The ptx file to be optimized." );
	parser.parse( "-o", "--output", optimizer.output, 
		"_optimized_" + optimizer.input, "The resulting optimized file." );
	parser.parse( "-a", "--allocator", allocator, "none",
		"The type of register allocator to use (linearscan)." );
	parser.parse( "-r", "--max-registers", optimizer.registerCount, 32,
		"The number of registers available for allocation." );
	parser.parse( "-p", "--passes", passes, "", 
		"A list of optimization passes (remove-barriers, " 
		"reverse-if-conversion, subkernel-formation)" );
	parser.parse( "-c", "--cfg", optimizer.cfg, false, 
		"Dump out the CFG's of all generated kernels." );
	parser.parse();

	if( allocator == "linearscan" )
	{
		optimizer.registerAllocationType = analysis::PTXOptimizer::LinearScan;
	}
	
	optimizer.passes = parsePassTypes( passes );
	
	optimizer.optimize();

	return 0;
}

#endif

