
#include "ocelot/transforms/interface/MemoryAccessSizePass.h"
#include "ocelot/analysis/interface/DataflowGraph.h"

#include "iostream"

namespace transforms {

	MemoryAccessSizePass::MemoryAccessSizePass(std::list<void *> &readPtrs, std::list<void *> &writePtrs)
		: KernelPass(Analysis::DataflowGraphAnalysis, "MemoryAccessSizePass"), 
		_readPtrs(readPtrs), _writePtrs(writePtrs) {
	}

	ir::PTXInstruction MemoryAccessSizePass::_readSizeInstruction(ir::PTXOperand::DataType dataType,
		ir::PTXOperand::RegisterType addReg) {
		ir::PTXOperand::DataType addType = ir::PTXOperand::u32;
		ir::PTXInstruction addSizeInst(ir::PTXInstruction::Add); 
		addSizeInst.a = addSizeInst.d = ir::PTXOperand(ir::PTXOperand::Register, addType, addReg);
		addSizeInst.type = addType;

		switch(dataType) {
		case ir::PTXOperand::s8:
		case ir::PTXOperand::u8:
		case ir::PTXOperand::b8:
			addSizeInst.b = ir::PTXOperand(1, addType);
			break;
		case ir::PTXOperand::s16:
		case ir::PTXOperand::u16:
		case ir::PTXOperand::f16:
		case ir::PTXOperand::b16:
			addSizeInst.b = ir::PTXOperand(2, addType);
			break;
		case ir::PTXOperand::s32:
		case ir::PTXOperand::u32:
		case ir::PTXOperand::f32:
		case ir::PTXOperand::b32:
			addSizeInst.b = ir::PTXOperand(4, addType);
			break;
		case ir::PTXOperand::s64:
		case ir::PTXOperand::u64:
		case ir::PTXOperand::f64:
		case ir::PTXOperand::b64:
			addSizeInst.b = ir::PTXOperand(8, addType);
			break;

		default:
			assertM(false, "Invalid read size");
			break;

		}

		return addSizeInst;
	}
	
	void MemoryAccessSizePass::runOnKernel( ir::IRKernel& k ) {
		Analysis* dfg_structure = getAnalysis(Analysis::DataflowGraphAnalysis);
		assert(dfg_structure != 0);
		
		analysis::DataflowGraph& dfg =  *static_cast<analysis::DataflowGraph *>(dfg_structure);

		ir::PTXOperand::DataType addressType = ir::PTXOperand::u64;
		ir::PTXOperand::DataType countType = ir::PTXOperand::u32;
		ir::PTXKernel& kernel = *static_cast<ir::PTXKernel *>(&k);
		ir::PTXOperand::RegisterType newRegister = kernel.getUnusedRegister();

		//instructions for storing memory access size
		//global memory address for storing

		std::list<ir::PTXInstruction> mvAddrs;
		for(auto ptrIt = _readPtrs.begin(); ptrIt != _readPtrs.end(); ptrIt++) {
			ir::PTXInstruction mvAddr(ir::PTXInstruction::Mov);
			mvAddr.a = ir::PTXOperand((uint64_t)(*ptrIt), addressType);
			mvAddr.d = ir::PTXOperand(ir::PTXOperand::Register, addressType, newRegister++);
			mvAddr.type = addressType;
			mvAddrs.push_back(mvAddr);
		}
		for(auto ptrIt = _writePtrs.begin(); ptrIt != _writePtrs.end(); ptrIt++) {
			ir::PTXInstruction mvAddr(ir::PTXInstruction::Mov);
			mvAddr.a = ir::PTXOperand((uint64_t)(*ptrIt), addressType);
			mvAddr.d = ir::PTXOperand(ir::PTXOperand::Register, addressType, newRegister++);
			mvAddr.type = addressType;
			mvAddrs.push_back(mvAddr);
		}

		//initalize read count register to 0
		ir::PTXInstruction mvReadCount(ir::PTXInstruction::Mov);
		mvReadCount.a = ir::PTXOperand(0, countType);
		ir::PTXOperand::RegisterType addReadReg = newRegister;
		mvReadCount.d = ir::PTXOperand(ir::PTXOperand::Register, countType, newRegister++);
		mvReadCount.type = countType;

		//store count register, using atomic
		std::list<ir::PTXInstruction> atomExchanges;
		for(auto movInstIt = mvAddrs.begin(); movInstIt != mvAddrs.end(); movInstIt++) {
		ir::PTXInstruction atomExchange(ir::PTXInstruction::Atom);
			atomExchange.atomicOperation = ir::PTXInstruction::AtomicMax; 
			atomExchange.a = (*movInstIt).d;
			atomExchange.b = mvReadCount.d;
			atomExchange.d = ir::PTXOperand(ir::PTXOperand::Register, countType, newRegister);
			atomExchange.type = countType;
			atomExchange.addressSpace = ir::PTXInstruction::Global;
			atomExchanges.push_back(atomExchange);
		}
		newRegister++;

		//instructions for compute memory access size
		//ir::PTXInstruction 
		for(auto blockIt = dfg.begin(); blockIt != dfg.end(); blockIt++) {
			for(auto instIt = blockIt->instructions().begin(); instIt != blockIt->instructions().end();
				instIt++) {
				ir::PTXInstruction* inst = static_cast<ir::PTXInstruction *>(instIt->i);
				if(inst->opcode == ir::PTXInstruction::Ld &&
					inst->addressSpace == ir::PTXInstruction::Global) {
					ir::PTXInstruction addReadSize = _readSizeInstruction(inst->type,
							addReadReg);
					dfg.insert(blockIt, addReadSize, instIt);
				}
			}
		}

	
		//insert instructions for storing count regsiters

		//insert instructions at the entry block to initialize global address and counter value
		analysis::DataflowGraph::iterator blockBegin = dfg.begin();
		analysis::DataflowGraph::InstructionIterator instBegin = blockBegin->instructions().begin();
		instBegin = blockBegin->instructions().begin();
		dfg.insert(blockBegin, mvReadCount, instBegin);
		instBegin = blockBegin->instructions().begin();
		for(auto mvAddrIt = mvAddrs.begin(); mvAddrIt != mvAddrs.end(); mvAddrIt++)
			dfg.insert(blockBegin, *mvAddrIt, instBegin);

		//insert atomic operation at the end to store counter value
		analysis::DataflowGraph::iterator blockEnd = --dfg.end();
		for(auto blockIt = blockEnd->predecessors().begin(); blockIt != blockEnd->predecessors().end(); blockIt++) {

			for(auto instIt = (*blockIt)->instructions().begin();
				instIt != (*blockIt)->instructions().end(); instIt++) {
				ir::PTXInstruction* inst = static_cast<ir::PTXInstruction *>(instIt->i);
				if(inst->opcode == ir::PTXInstruction::Ret) {
					for(auto atomIt = atomExchanges.begin(); atomIt != atomExchanges.end(); atomIt++) {
						dfg.insert((*blockIt), *atomIt, instIt);
					}
				}
			}
		}
	//		for(auto i = block->block()->instructions.begin(); 
		//		i != block->block()->instructions.end(); ++i) {
		//		ir::PTXInstruction* inst = static_cast<ir::PTXInstruction *>(*i);
	//			std::cout << inst->toString() << std::endl;
	//		}
	//	}
	}
}
