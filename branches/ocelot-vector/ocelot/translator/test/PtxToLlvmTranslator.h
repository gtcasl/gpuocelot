/*!
	\file PtxToLlvmTranslator.h
	\date Tuesday August 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the PtxToLlvmTranslator class.
*/

#ifndef PTX_TO_LLVM_TRANSLATOR_BIN_H_INCLUDED
#define PTX_TO_LLVM_TRANSLATOR_BIN_H_INCLUDED

/*! \brief A class used to transform a PTX file into an LLVM equivalent */
class PtxToLlvmTranslator
{
	public:
		std::string input;
	
	public:
		void translate();
};

#endif

