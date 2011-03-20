/*! \file PTXOptimzer.h
	\date Thursday December 31, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the Ocelot PTX optimizer
*/

#ifndef PTX_OPTIMIZER_H_INCLUDED
#define PTX_OPTIMIZER_H_INCLUDED

#include <string>

namespace analysis
{
	/*! \brief Able to run various optimization passes over PTX modules */
	class PTXOptimizer
	{
		public:
			/*! \brief The type of register allocator to use */
			enum RegisterAllocationType
			{
				LinearScan,
				InvalidRegisterAllocationType
			};
			
			/*! \brief The possible PTX to PTX passes */
			enum PassType
			{
				InvalidPassType = 0x0,
				RemoveBarriers = 0x1,
				ReverseIfConversion = 0x2,
				SubkernelFormation = 0x4,
				StructuralTransform = 0x8,
				MIMDThreadScheduling = 0x10,
				SyncElimination = 0x20
			};
	
		public:
			/*! \brief The input file being optimized */
			std::string input;
			
			/*! \brief The output file being generated */
			std::string output;
			
			/*! \brief The type of register allocation to perform */
			RegisterAllocationType registerAllocationType;
			
			/*! \brief The set of passes to run */
			int passes;
			
			/*! \brief The number of registers to allocate */
			unsigned int registerCount;
			
			/*! \brief The target sub-kernel size */
			unsigned int subkernelSize;
			
			/*! \brief Print out the CFG of optimized kernels */
			bool cfg;
			
		public:
			/*! \brief The constructor sets the defaults */
			PTXOptimizer();

			/*! \brief Performs the optimizations */
			void optimize();			
	};
}

int main( int argc, char** argv );

#endif

