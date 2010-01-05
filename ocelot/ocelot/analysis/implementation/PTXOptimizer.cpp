/*! \file PTXOptimzer.cpp
	\date Thursday December 31, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the Ocelot PTX optimizer
*/

#ifndef PTX_OPTIMIZER_CPP_INCLUDED
#define PTX_OPTIMIZER_CPP_INCLUDED

#include <ocelot/analysis/interface/PTXOptimizer.h>
#include <ocelot/analysis/interface/LinearScanRegisterAllocationPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

namespace analysis
{
	PTXOptimizer::PTXOptimizer() : registerAllocationType( 
		InvalidRegisterAllocationType )
	{
	
	}

	void PTXOptimizer::optimize()
	{
		ir::Module module( input );

		for( ir::Module::KernelVector::iterator 
			kernel = module.kernels[ ir::Instruction::PTX ].begin(); 
			kernel != module.kernels[ ir::Instruction::PTX ].end(); 
			++kernel )
		{
			(*kernel)->dfg()->toSsa();
		}
	
		if( registerAllocationType == LinearScan )
		{
			analysis::LinearScanRegisterAllocationPass pass( registerCount );
			pass.initialize( module );
			for( ir::Module::KernelVector::iterator 
				kernel = module.kernels[ ir::Instruction::PTX ].begin(); 
				kernel != module.kernels[ ir::Instruction::PTX ].end(); 
				++kernel )
			{
				pass.runOnKernel( **kernel );
			}
			pass.finalize();
		}

		for( ir::Module::KernelVector::iterator 
			kernel = module.kernels[ ir::Instruction::PTX ].begin(); 
			kernel != module.kernels[ ir::Instruction::PTX ].end(); 
			++kernel )
		{
			(*kernel)->dfg()->fromSsa();
		}
		
		std::ofstream out( output.c_str() );
		
		if( !out.is_open() )
		{
			throw hydrazine::Exception( "Could not open output file " 
				+ output + " for writing." );
		}
		
		module.writeIR( out );
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	analysis::PTXOptimizer optimizer;
	std::string allocator;
	
	parser.parse( "-i", "--input", optimizer.input, "",
		"The ptx file to be optimized." );
	parser.parse( "-o", "--output", optimizer.output, "Optimized.ptx", 
		"The resulting optimized file." );
	parser.parse( "-a", "--allocator", allocator, "linearscan",
		"The type of register allocator to use (linearscan)." );
	parser.parse( "-r", "--max-registers", optimizer.registerCount, 32,
		"The number of registers available for allocation." );
	parser.parse();

	if( allocator == "linearscan" )
	{
		optimizer.registerAllocationType = analysis::PTXOptimizer::LinearScan;
	}
	
	optimizer.optimize();

	return 0;
}

#endif

