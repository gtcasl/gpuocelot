/*! \file PTXToILTranslator.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 19, 2010
 *  \brief The header file for the PTX to IL Translator class.
 */

#ifndef PTX_TO_IL_TRANSLATOR_H_INCLUDED
#define PTX_TO_IL_TRANSLATOR_H_INCLUDED

//C++ standard library includes
#include <string>
#include <map>

//Ocelot includes
#include <ocelot/translator/interface/Translator.h>
#include <ocelot/ir/interface/ILKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/ControlTree.h>

typedef ir::ControlTree ControlTree;

namespace translator
{
	/*! \brief A translator from PTX to IL */
	class PTXToILTranslator : public Translator
	{
		public:
			/*! \brief Translate a module from PTX to IL */
			ir::Kernel *translate(const ir::Kernel *k);

			void addProfile(const ProfilingData &d);

			PTXToILTranslator(OptimizationLevel l = NoOptimization);

		private:
			typedef std::map<int, std::string> ILiteralMap;
			typedef std::map<float, std::string> FLiteralMap;

			ir::ILKernel *_ilKernel;
			ILiteralMap _intLiterals;
			FLiteralMap _floatLiterals;
			ir::ILInstruction::RegisterType _tempRegisterCount;

			void _translate(const ControlTree::Node* node);
			void _translate(const ControlTree::InstNode* insts);
			void _translate(const ControlTree::BlockNode* block);
			void _translate(const ControlTree::IfThenNode* ifthen);
			void _translate(const ControlTree::IfThenElseNode* ifthenelse);
			void _translate(const ControlTree::SelfLoopNode* selfloop);

			void _translate(const ir::PTXInstruction &i); 
			ir::ILOperand _translate(const ir::PTXOperand &o);
			ir::ILInstruction::DataType _translate(
					const ir::PTXOperand::DataType d);
			std::string _translate(const ir::PTXOperand::RegisterType &reg);
			ir::ILOperand::SpecialRegister _translate(
					const ir::PTXOperand::SpecialRegister &s);

			void _translateAbs(const ir::PTXInstruction &i);
			void _translateAdd(const ir::PTXInstruction &i);
			void _translateAnd(const ir::PTXInstruction &i);
			void _translateAtom(const ir::PTXInstruction& i);
			void _translateBar(const ir::PTXInstruction &i);
			void _translateBra(const ir::PTXInstruction &i);
			void _translateCvt(const ir::PTXInstruction &i);
			void _translateDiv(const ir::PTXInstruction &i);
			void _translateEx2(const ir::PTXInstruction &i);
			void _translateExit(const ir::PTXInstruction &i);
			void _translateLd(const ir::PTXInstruction &i);
			void _translateLdSharedByte(const ir::PTXInstruction &i);
			void _translateLdSharedDword(const ir::PTXInstruction &i);
			void _translateLg2(const ir::PTXInstruction &i);
			void _translateMad(const ir::PTXInstruction &i);
			void _translateMax(const ir::PTXInstruction &i);
			void _translateMin(const ir::PTXInstruction &i);
			void _translateMov(const ir::PTXInstruction &i);
			void _translateMul(const ir::PTXInstruction &i);
			void _translateNeg(const ir::PTXInstruction &i);
			void _translateNot(const ir::PTXInstruction &i);
			void _translateOr(const ir::PTXInstruction &i);
			void _translateRcp(const ir::PTXInstruction &i);
			void _translateRem(const ir::PTXInstruction &i);
			void _translateSelP(const ir::PTXInstruction &i);
			void _translateSet(const ir::PTXInstruction &i);
			void _translateSetP(const ir::PTXInstruction &i);
			void _translateShl(const ir::PTXInstruction &i);
			void _translateShr(const ir::PTXInstruction &i);
			void _translateSt(const ir::PTXInstruction &i);
			void _translateSub(const ir::PTXInstruction &i);
			void _translateXor(const ir::PTXInstruction& i);

			void _translateStSharedByte(const ir::PTXInstruction &i);
			void _translateStSharedDword(const ir::PTXInstruction &i);
			ir::ILOperand _translateLiteral(int l);
			ir::ILOperand _translateLiteral(float l);
			std::string _translateConstantBuffer(const std::string &ident);

			void _translateIDiv(const ir::PTXInstruction &i);
			void _translateFDiv(const ir::PTXInstruction &i);

			void _translateISetP(const ir::PTXInstruction &i);
			void _translateFSetP(const ir::PTXInstruction &i);

			void _convertSrc(const ir::PTXInstruction &i);
			void _convert(const ir::PTXInstruction &i);
			void _convertDst(const ir::PTXInstruction &i);

			void _addKernelPrefix();

			ir::ILOperand _tempRegister();
			void _add(const ir::ILInstruction &i);
	};

	/*! \brief returns the last instruction in a control tree node */
	ir::PTXInstruction* getLastIns(const ControlTree::Node* node);
}

#endif
