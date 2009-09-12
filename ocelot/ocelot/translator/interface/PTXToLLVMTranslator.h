/*!
	\file PTXToLLVMTranslator.h
	\date Wednesday July 29, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the PTXToLLVMTranslator class
*/

#ifndef PTX_TO_LLVM_TRANSLATOR_H_INCLUDED
#define PTX_TO_LLVM_TRANSLATOR_H_INCLUDED

#include <ocelot/translator/interface/Translator.h>
#include <ocelot/ir/interface/LLVMInstruction.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace ir
{
	class PTXInstruction;
	class Instruction;
	class LLVMKernel;
	class PTXOperand;
}

namespace translator
{

	/*! \brief A translator from PTX to LLVM */
	class PTXToLLVMTranslator : public Translator
	{
		private:
			typedef std::vector< analysis::DataflowGraph::Register > 
				RegisterVector;
		
		private:
			ir::LLVMKernel* _llvmKernel;
			analysis::DataflowGraph* _graph;
			unsigned int _tempRegisterCount;
			unsigned int _tempCCRegisterCount;
			unsigned int _tempBlockCount;
			unsigned int _continuation;
			analysis::DataflowGraph::InstructionId _instructionId;
			RegisterVector _uninitialized;
		
		private:
			static ir::LLVMInstruction::DataType _translate( 
				ir::PTXOperand::DataType type );
			static void _doubleWidth( ir::LLVMInstruction::DataType& v );
			static ir::LLVMInstruction::Comparison _translate( 
				ir::PTXInstruction::CmpOp, bool isInt );
			
			static ir::LLVMInstruction::Type _getCtaContextType();
			
		private:
			void _yield( unsigned int continuation );

			ir::LLVMInstruction::Operand _translate( const ir::PTXOperand& o, 
				ir::PTXInstruction::AddressSpace space = 
				ir::PTXInstruction::AddressSpace_Invalid, 
				ir::PTXInstruction::Vec vector = ir::PTXOperand::v1 );
			void _swapAllExceptName( ir::LLVMInstruction::Operand& o, 
				const ir::PTXOperand& i );
			
			void _convertPtxToSsa();
			void _translateInstructions();
			void _newBlock( const std::string& name );
			void _translate( const analysis::DataflowGraph::Instruction& i, 
				const analysis::DataflowGraph::Block& block );
			void _translate( const ir::PTXInstruction& i, 
				const analysis::DataflowGraph::Block& block );
			void _translateAbs( const ir::PTXInstruction& i );
			void _translateAdd( const ir::PTXInstruction& i );
			void _translateAddC( const ir::PTXInstruction& i );
			void _translateAnd( const ir::PTXInstruction& i );
			void _translateAtom( const ir::PTXInstruction& i );
			void _translateBar( const ir::PTXInstruction& i );
			void _translateBra( const ir::PTXInstruction& i, 
				const analysis::DataflowGraph::Block& block );
			void _translateBrkpt( const ir::PTXInstruction& i );
			void _translateCall( const ir::PTXInstruction& i );
			void _translateCNot( const ir::PTXInstruction& i );
			void _translateCos( const ir::PTXInstruction& i );
			void _translateCvt( const ir::PTXInstruction& i );
			void _translateDiv( const ir::PTXInstruction& i );
			void _translateEx2( const ir::PTXInstruction& i );
			void _translateExit( const ir::PTXInstruction& i );
			void _translateLd( const ir::PTXInstruction& i );
			void _translateLg2( const ir::PTXInstruction& i );
			void _translateMad24( const ir::PTXInstruction& i );
			void _translateMad( const ir::PTXInstruction& i );
			void _translateMax( const ir::PTXInstruction& i );
			void _translateMembar( const ir::PTXInstruction& i );
			void _translateMin( const ir::PTXInstruction& i );
			void _translateMov( const ir::PTXInstruction& i );
			void _translateMul24( const ir::PTXInstruction& i );
			void _translateMul( const ir::PTXInstruction& i );
			void _translateNeg( const ir::PTXInstruction& i );
			void _translateNot( const ir::PTXInstruction& i );
			void _translateOr( const ir::PTXInstruction& i );
			void _translatePmevent( const ir::PTXInstruction& i );
			void _translateRcp( const ir::PTXInstruction& i );
			void _translateRed( const ir::PTXInstruction& i );
			void _translateRem( const ir::PTXInstruction& i );
			void _translateRet( const ir::PTXInstruction& i );
			void _translateRsqrt( const ir::PTXInstruction& i );
			void _translateSad( const ir::PTXInstruction& i );
			void _translateSelP( const ir::PTXInstruction& i );
			void _translateSet( const ir::PTXInstruction& i );
			void _translateSetP( const ir::PTXInstruction& i );
			void _translateShl( const ir::PTXInstruction& i );
			void _translateShr( const ir::PTXInstruction& i );
			void _translateSin( const ir::PTXInstruction& i );
			void _translateSlCt( const ir::PTXInstruction& i );
			void _translateSqrt( const ir::PTXInstruction& i );
			void _translateSt( const ir::PTXInstruction& i );
			void _translateSub( const ir::PTXInstruction& i );
			void _translateSubC( const ir::PTXInstruction& i );
			void _translateTex( const ir::PTXInstruction& i );
			void _translateTrap( const ir::PTXInstruction& i );
			void _translateVote( const ir::PTXInstruction& i );
			void _translateXor( const ir::PTXInstruction& i );
			
			void _bitcast( const ir::PTXInstruction& i );
			
			std::string _tempRegister();
			std::string _loadSpecialRegister( 
				ir::PTXOperand::SpecialRegister s );
			std::string _loadMemoryBase( ir::PTXInstruction::AddressSpace space, 
				ir::PTXOperand::DataType type, size_t offset, 
				ir::PTXInstruction::Vec vector );
			
			void _setFloatingPointRoundingMode( const ir::PTXInstruction& i );
			ir::LLVMInstruction::Operand _destination( 
				const ir::PTXInstruction& i, bool pd = false );
			ir::LLVMInstruction::Operand _destinationCC( 
				const ir::PTXInstruction& i );
			ir::LLVMInstruction::Operand _conditionCodeRegister( 
				const ir::PTXOperand& op );
			void _predicateEpilogue( const ir::PTXInstruction& i, 
				const ir::LLVMInstruction::Operand& temp );
			void _add( const ir::LLVMInstruction& i );
			
			void _initializeRegisters();

			void _addKernelPrefix();
			void _addKernelSuffix();

		public:
			PTXToLLVMTranslator( OptimizationLevel l = NoOptimization );
			~PTXToLLVMTranslator();
			
		public:
			ir::Kernel* translate( const ir::Kernel* i );
			void addProfile( const ProfilingData& d );
	};
}

#endif

