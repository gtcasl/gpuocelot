/*! \file Pass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday September 15, 2009
	\brief The header file for the Pass class.
*/

#ifndef PASS_H_INCLUDED
#define PASS_H_INCLUDED

#include <string>

namespace ir
{
	class Kernel;
	class Module;
	class BasicBlock;
}

namespace analysis
{
	/*! \brief A class modeled after the LLVM notion of an optimization pass.  
		Allows different transformations to be applied to PTX modules */
	class Pass
	{
		public:
			/*! \brief For virtual classes, the type of pass */
			enum Type
			{
				ImmutablePass,
				ModulePass,
				KernelPass,
				BasicBlockPass,
				InvalidPass
			};
			
		public:
			/*! \brief The type of this pass */
			Type type;

			/*! \brief Should the pass be run before or after ssa conversion */
			bool ssa;
			
			/*! \brief The name of the pass */
			std::string name;
		
		public:
			/*! \brief The default constructor sets the type */
			explicit Pass( Type t = InvalidPass );
			/*! \brief Virtual destructor */
			virtual ~Pass();
			/*! \brief The type requires a new copy constructor */
			Pass( const Pass& p );
			/*! \brief The type requires a new assignment operator */
			Pass& operator=( const Pass& p );
			/*! \brief Report the name of the pass */
			std::string toString() const;
	};
	
	
	/*! \brief A pass that generates information about a 
		program without modifying it */
	class ImmutablePass : public Pass
	{
		public:
			/*! \brief The default constructor sets the type */
			ImmutablePass();
			/*! \brief Virtual destructor */
			virtual ~ImmutablePass();
			
		public:
			/*! \brief Run the pass on a specific module */
			virtual void runOnModule( const ir::Module& m ) = 0;
	};
	
	/*! \brief A pass over an entire module */
	class ModulePass : public Pass
	{
		public:
			/*! \brief The default constructor sets the type */
			ModulePass();
			/*! \brief Virtual destructor */
			virtual ~ModulePass();
			
		public:
			/*! \brief Run the pass on a specific module */
			virtual void runOnModule( ir::Module& m ) = 0;		
	};
	
	/*! \brief A pass over a single kernel in a module */
	class KernelPass : public Pass
	{
		public:
			/*! \brief The default constructor sets the type */
			KernelPass();
			/*! \brief Virtual destructor */
			virtual ~KernelPass();
			
		public:
			/*! \brief Initialize the pass using a specific module */
			virtual void initialize( const ir::Module& m ) = 0;
			/*! \brief Run the pass on a specific kernel in the module */
			virtual void runOnKernel( ir::Kernel& k ) = 0;		
			/*! \brief Finalize the pass */
			virtual void finalize( ) = 0;
	};

	/*! \brief A pass over a single basic block in a kernel */
	class BasicBlockPass : public Pass
	{
		public:
			/*! \brief The default constructor sets the type */
			BasicBlockPass();
			/*! \brief Virtual destructor */
			virtual ~BasicBlockPass();
			
		public:
			/*! \brief Initialize the pass using a specific module */
			virtual void initialize( const ir::Module& m ) = 0;
			/*! \brief Initialize the pass using a specific kernel */
			virtual void initialize( const ir::Kernel& m ) = 0;
			/*! \brief Run the pass on a specific kernel in the module */
			virtual void runOnBlock( ir::BasicBlock& b ) = 0;		
			/*! \brief Finalize the pass on the kernel */
			virtual void finalizeKernel( ) = 0;
			/*! \brief Finalize the pass on the module */
			virtual void finalize( ) = 0;
	};

}

#endif

