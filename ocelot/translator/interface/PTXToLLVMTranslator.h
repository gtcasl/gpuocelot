/*!
	\file PTXToLLVMTranslator.h
	\date Wednesday July 29, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the PTXToLLVMTranslator class
*/

#ifndef PTX_TO_LLVM_TRANSLATOR_H_INCLUDED
#define PTX_TO_LLVM_TRANSLATOR_H_INCLUDED

#include <ocelot/translator/interface/Translator.h>

namespace ir
{
	class PTXInstruction;
	class LLVMInstruction;
	class Instruction;
}

namespace translator
{

	/*! \brief A translator from PTX to LLVM */
	class PTXToLLVMTranslator : public Translator
	{
		private:
			/*! \brief A vector of instruction pointers */
			typedef std::vector< ir::Instruction* > InstructionVector;
		
		private:
			/*! \brief Translated Instructions */
			InstructionVector _instructions;
		
		private:
			void _translate( const PTXInstruction& i );
			void _translateAdd( const PTXInstruction& i );
			void _translateAbs( const PTXInstruction& i );
			void _translateAdd( const PTXInstruction& i );
			void _translateAddC( const PTXInstruction& i );
			void _translateAnd( const PTXInstruction& i );
			void _translateAtom( const PTXInstruction& i );
			void _translateBar( const PTXInstruction& i );
			void _translateBra( const PTXInstruction& i );
			void _translateBrkpt( const PTXInstruction& i );
			void _translateCall( const PTXInstruction& i );
			void _translateCNot( const PTXInstruction& i );
			void _translateCos( const PTXInstruction& i );
			void _translateCvt( const PTXInstruction& i );
			void _translateDiv( const PTXInstruction& i );
			void _translateEx2( const PTXInstruction& i );
			void _translateExit( const PTXInstruction& i );
			void _translateLd( const PTXInstruction& i );
			void _translateLg2( const PTXInstruction& i );
			void _translateMad24( const PTXInstruction& i );
			void _translateMad( const PTXInstruction& i );
			void _translateMax( const PTXInstruction& i );
			void _translateMembar( const PTXInstruction& i );
			void _translateMin( const PTXInstruction& i );
			void _translateMov( const PTXInstruction& i );
			void _translateMul24( const PTXInstruction& i );
			void _translateMul( const PTXInstruction& i );
			void _translateNeg( const PTXInstruction& i );
			void _translateNot( const PTXInstruction& i );
			void _translateOr( const PTXInstruction& i );
			void _translatePmevent( const PTXInstruction& i );
			void _translateRcp( const PTXInstruction& i );
			void _translateRed( const PTXInstruction& i );
			void _translateRem( const PTXInstruction& i );
			void _translateRet( const PTXInstruction& i );
			void _translateRsqrt( const PTXInstruction& i );
			void _translateSad( const PTXInstruction& i );
			void _translateSelP( const PTXInstruction& i );
			void _translateSet( const PTXInstruction& i );
			void _translateSetP( const PTXInstruction& i );
			void _translateShl( const PTXInstruction& i );
			void _translateShr( const PTXInstruction& i );
			void _translateSin( const PTXInstruction& i );
			void _translateSlCt( const PTXInstruction& i );
			void _translateSqrt( const PTXInstruction& i );
			void _translateSt( const PTXInstruction& i );
			void _translateSub( const PTXInstruction& i );
			void _translateSubC( const PTXInstruction& i );
			void _translateTex( const PTXInstruction& i );
			void _translateTrap( const PTXInstruction& i );
			void _translateVote( const PTXInstruction& i );
			void _translateXor( const PTXInstruction& i );

		public:
			PTXToLLVMTranslator( OptimizationLevel l = NoOptimization );
			~PTXToLLVMTranslator();
			
		public:
			ir::Kernel* translate( const ir::Kernel* i );
			void addProfile( const ProfilingData& d );
	};
}

#endif

