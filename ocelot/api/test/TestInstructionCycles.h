/*! \file TestInstructionCycles.h
	\date Thursday September 8, 2011
	\author Naila Farooqui
	\brief The header file for the TestInstructionCycles class.
*/

#ifndef TEST_INSTRUCTION_CYCLES_H_INCLUDED
#define TEST_INSTRUCTION_CYCLES_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	
	class TestInstructionCycles : public Test
	{
		private:

			bool testCycles();
			/*! \brief Dispatch function fot the unit tests */
			bool doTest();
	
		public:
			/*! \brief The constructor sets the description */
			TestInstructionCycles();
	};
}

int main(int argc, char** argv);

#endif

