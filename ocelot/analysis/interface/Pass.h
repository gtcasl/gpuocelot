/*! \file Pass.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday September 15, 2009
	\brief The header file for the Pass class.
*/

#ifndef PASS_H_INCLUDED
#define PASS_H_INCLUDED

#include <string>
#include <list>

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
			
			/*! \brief Analysis type */
			enum AnalysisType
			{
				NoAnalysis = 0x0,
				ControlTreeAnalysis = 0x1,
				DominatorTreeAnalysis = 0x2,
				PostDominatorTreeAnalysis = 0x4,
				DataflowGraphAnalysis = 0x8,
				StaticSingleAssignment = 0x10
			};
			
		public:
			/*! \brief The type of this pass */
			const Type type;
			
			/*! \brief What types of analysis routines does the pass require? */
			const int analyses;
			
			/*! \brief The name of the pass */
			const std::string name;
		
		protected:
			//! \brief Pass instances should set this to true or false if they are coalescable
			bool _coalesce;
		
		public:
			/*! \brief The default constructor sets the type */
			explicit Pass( Type t = InvalidPass, int a = NoAnalysis,
				const std::string& n = "" );
			/*! \brief Virtual destructor */
			virtual ~Pass();
			/*! \brief The type requires a new copy constructor */
			Pass( const Pass& p );
			/*! \brief The type requires a new assignment operator */
			Pass& operator=( const Pass& p );
			/*! \brief Report the name of the pass */
			std::string toString() const;
			//! returns true if pass is coalescable
			bool coalesce() const;
	};
	
	
	/*! \brief A pass that generates information about a 
		program without modifying it */
	class ImmutablePass : public Pass
	{
		public:
			/*! \brief The default constructor sets the type */
			ImmutablePass( int a = NoAnalysis, const std::string& n = "" );
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
			ModulePass( int a = NoAnalysis, const std::string& n = "" );
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
			KernelPass( int a = NoAnalysis, const std::string& n = "" );
			/*! \brief Virtual destructor */
			virtual ~KernelPass();
			
		public:
			/*! \brief Initialize the pass using a specific module */
			virtual void initialize( const ir::Module& m );
			
			/*! 
				\brief called before runOnKernel() is called 
			*/
			virtual void doInitialize( ir::Module &module);
			
			/*! \brief Run the pass on a specific kernel in the module */
			virtual void runOnKernel( ir::Kernel& k ) = 0;
			
			/*! \brief Finalize the pass */
			virtual void finalize( );
	};

	/*! \brief A pass over a single basic block in a kernel */
	class BasicBlockPass : public Pass
	{
		public:
			/*! \brief The default constructor sets the type */
			BasicBlockPass( int a = NoAnalysis, const std::string& n = "" );
			/*! \brief Virtual destructor */
			virtual ~BasicBlockPass();
			
		public:
			/*! \brief Initialize the pass using a specific module */
			virtual void initialize( const ir::Module& m );
			
			/*! 
				\brief called before runOnBlock() is called 
			*/
			virtual void doInitialize( ir::Module &module);
			
			/*! \brief Initialize the pass using a specific kernel */
			virtual void initialize( const ir::Kernel& kernel );
			
			/*! 
				\brief called before runOnBlock() is called 
				
				Note, this function can perform kernel-level transformations and in
				all cases is guaranteed to return before runOnBlock() is called.
			*/
			virtual void doInitialize( ir::Kernel &kernel);
			
			/*! \brief Run the pass on a specific kernel in the module */
			virtual void runOnBlock( ir::BasicBlock& b ) = 0;		
			
			/*! \brief Finalize the pass on the kernel */
			virtual void finalizeKernel( );
			
			/*! \brief Finalize the pass on the module */
			virtual void finalize( );
	};

	typedef std::list< Pass * > PassList;
}

#endif

