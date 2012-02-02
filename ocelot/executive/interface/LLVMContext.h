/*!
	\file LLVMContext.h
	\date Tuesday September 8, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMContext class.
*/

#ifndef LLVM_CONTEXT_H_INCLUDED
#define LLVM_CONTEXT_H_INCLUDED

#include <cstring>

#include <ocelot/executive/interface/ExecutableKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/Module.h>

namespace executive
{



/*! \brief A class contains the state for executing a kernel */
class LLVMContext
{
public:
	/*! \brief A 3-D dimension corresponding to the CUDA notion */
	class Dimension
	{
		public:
			unsigned int x;
			unsigned int y;
			unsigned int z;
	};

public:
	Dimension tid;    //! [0] Thread ids
	Dimension ntid;   //! [1] CTA dimensions
	Dimension ctaid;  //! [2] CTA ids
	Dimension nctaid; //! [3] Kernel dimensions

public:
	char* local;               //! [4] Pointer to local memory
	char* shared;              //! [5] Pointer to shared memory
	char* constant;            //! [6] Pointer to constant memory
	char* parameter;           //! [7] Pointer to parameter memory
	char* argument;            //! [8] Pointer to argument memory
	char* globallyScopedLocal; //! [9] Pointer to globally scoped local memory
	
public:
	unsigned int externalSharedSize; //! [10] External shared size

public:
	/*! \brief Generic pointer back to other state */
	char* metadata;	// [11] 
};

class MetaData
{
public:
	
	typedef void (*Function)(LLVMContext*);
	typedef std::unordered_map<ir::ControlFlowGraph::BasicBlock::Id, 
		ir::ControlFlowGraph::const_iterator> BlockIdMap;
	typedef ExecutableKernel::TextureVector TextureVector;

public:
	BlockIdMap           blocks;
	const ir::PTXKernel* kernel;
	Function             function;
	TextureVector        textures;

public:
	unsigned int sharedSize;
	unsigned int localSize;
	unsigned int globalLocalSize;
	unsigned int parameterSize;
	unsigned int argumentSize;
	unsigned int constantSize;
	unsigned int warpSize;
	unsigned int subkernels;  
};

}

#endif

