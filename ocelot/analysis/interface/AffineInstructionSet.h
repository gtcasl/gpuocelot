/*!
	\file AffineInstructionSet.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date May 3, 2012
	\brief analysis data structure for determining and storing thread-invariance and affine results
*/

#ifndef OCELOT_ANALYSIS_AFFINEINSTRUCTIONSET_H_INCLUDED

// C++ includes
#include <list>
#include <map>
#include <vector>

// Ocelot includes
#include <ocelot/analysis/interface/LLVMUniformVectorization.h>

namespace llvm {
	class Value;
	class Instruction;
	class Function;
}

namespace analysis {

	/*!
		\brief simple data structure for querying this kind of thing
	*/
	class AffineInstructionSet {
	public:
		typedef std::set< llvm::Value *> ValueSet;

	public:
		AffineInstructionSet(llvm::Function *function, 
			const LLVMUniformVectorization::ThreadLocalArgument &threadArguments);
		~AffineInstructionSet();
		
	public:
	
		bool isThreadInvariant(llvm::Value *value, int indent = 0);
		bool isAffine(llvm::Value *value, int indent = 0);
	
		void write(std::ostream &out) const;
	
	protected:
		
		//! \brief more elaborate logic here
		bool _isBinaryOperatorAffine(llvm::BinaryOperator *binary, int indent = 0);
	
		//! \brief adds a value to the affineValues set and returns true
		bool _setAffine(llvm::Value *value);
		
		//! \brief adds a value to the invariantValues set and returns true
		bool _setInvariant(llvm::Value *value);
		
		//! \brief adds a value to the variantValues set and returns false
		bool _setVariant(llvm::Value *value);

		//! \brief walks up the def-use chain treaing int-to-int casts as transparent
		llvm::Value *_walk(llvm::Value *value);
	
	protected:
	
		//! \brief set of values equal to (threadIdx.x + threadIdx.y * blockDim.x + threadIdx.z * (blockDim.x * blockDim.y)
		ValueSet _threadIds;
		
		//! \brief set of thread-invariant instructions
		ValueSet _invariantValues;
		
		//!
		ValueSet _affineValues;
		
		//! 
		ValueSet _variantValues;
	};
}

#endif

