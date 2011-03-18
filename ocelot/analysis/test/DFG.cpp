/*!
	\file DFG.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Thursday June 25, 2009
	\brief The file for the Dataflow Graph construction program.
*/

#ifndef DFG_CPP_INCLUDED
#define DFG_CPP_INCLUDED

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>

#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <fstream>

static void analyze( const std::string& ptx, const std::string& dot, bool ssa )
{
	ir::Module module( ptx );

	ir::Module::KernelMap::const_iterator k_it = module.kernels.begin();

	for (; k_it != module.kernels.end(); ++k_it) {

		ir::PTXKernel* kernel = static_cast< ir::PTXKernel* >(k_it->second);

		std::string dfg = dot + kernel->name + "_dfg.dot";

		std::ofstream dfgFile( dfg.c_str() );
		
		dfgFile << "// Kernel: " << kernel->name << "\n";
		dfgFile << "// Dataflow flow graph\n";
		
		ir::PTXKernel::assignRegisters( *kernel->cfg() );
				
		if( ssa )
		{
			kernel->dfg()->toSsa();
		}
		
		dfgFile << *kernel->dfg();
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );	
	parser.description("Create a dataflow graph from a PTX source file.");

	std::string ptx;
	std::string dot;
	bool ssa;
	
	parser.parse( "-i", "--input", ptx, "", "Input PTX file." );
	parser.parse( "-o", "--output", dot, ptx, "Output base file name." );
	parser.parse( "-s", "--ssa", ssa, false, 
		"Convert to SSA after doing dataflow" );
	parser.parse();

	if( ptx == "" )
	{
		throw hydrazine::Exception( "Input ptx file name required." );
	}
	
	analyze( ptx, dot, ssa );
	
	return 0;
}

#endif

