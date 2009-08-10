/*!
	\file PtxToLlvmTranslator.cpp
	\date Tuesday August 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the PtxToLlvmTranslator class.
*/

#ifndef PTX_TO_LLVM_TRANSLATOR_BIN_CPP_INCLUDED
#define PTX_TO_LLVM_TRANSLATOR_BIN_CPP_INCLUDED

#include <hydrazine/interface/Version.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/debug.h>
#include <ocelot/translator/test/PtxToLlvmTranslator.h>
#include <ocelot/translator/interface/PTXToLLVMTranslator.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/ir/interface/LLVMKernel.h>
#include <fstream>

void PtxToLlvmTranslator::translate()
{
	assertM( !input.empty(), "Input PTX file is required for translation." );
	
	translator::PTXToLLVMTranslator translator;
	ir::Module module( input );

	ir::Module::KernelVector::iterator 
		k_it = module.begin( ir::Instruction::PTX );

	for (; k_it != module.end( ir::Instruction::PTX ); ++k_it) {

		ir::Kernel* kernel = *k_it;

		std::string llvm = kernel->name + ".ll";

		ir::LLVMKernel* translatedKernel = dynamic_cast< ir::LLVMKernel* >( 
			translator.translate( kernel ) );
		translatedKernel->assemble();
		std::ofstream llvmFile( llvm.c_str() );
		
		hydrazine::Version version;
		
		llvmFile << "// Kernel: " << kernel->name << "\n";
		llvmFile << "// Translated from PTX to LLVM by Ocelot " 
			<< version.toString() << " \n";		
		llvmFile << translatedKernel->code();
	}
	
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	PtxToLlvmTranslator translator;
	
	parser.parse( "-p", "--ptx-file", translator.input, "", 
		"The input PTX file being translated.");
	parser.parse();

	translator.translate();
}

#endif

