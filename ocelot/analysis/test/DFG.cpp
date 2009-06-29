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
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <fstream>

static void analyze( const std::string& ptx, const std::string& dot )
{
	ir::Module module( ptx );

	ir::Module::KernelVector::iterator 
		k_it = module.begin( ir::Instruction::PTX );

	for (; k_it != module.end( ir::Instruction::PTX ); ++k_it) {

		ir::Kernel* kernel = *k_it;

		std::string dfg = dot + kernel->name + "_dfg.dot";

		std::ofstream dfgFile( dfg.c_str() );
		
		dfgFile << "// Kernel: " << kernel->name << "\n";
		dfgFile << "// Dataflow flow graph\n";
		
		ir::Kernel::assignRegisters( kernel->instructions );
		analysis::DataflowGraph graph( *kernel->ptxCFG, kernel->instructions );
		
		dfgFile << graph;
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );	
	parser.description("Create a dataflow graph from a PTX source file.");

	std::string ptx;
	std::string dot;
	
	parser.parse( "-i", "--input", ptx, "", "Input PTX file." );
	parser.parse( "-o", "--output", dot, ptx, "Output base file name." );
	parser.parse();

	if( ptx == "" )
	{
		throw hydrazine::Exception( "Input ptx file name required." );
	}
	
	analyze( ptx, dot );
}

#endif

