/*!	\file TestInstructionThroughput.h
	\date Saturday November 14, 2009
	\author Sudnya Padalikar <sudnya.padalikar@gatech.edu>
	\brief A test for instruction throughput.
*/

#ifndef TEST_INSTRUCTION_THROUGHPUT_H_INCLUDED
#define TEST_INSTRUCTION_THROUGHPUT_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	class TestInstructionThroughput : public Test
	{
		private:
			bool testu32InstructionThroughput();
			bool testu64InstructionThroughput();
			bool testf32InstructionThroughput();
			
			bool doTest();
		
		public:
			TestInstructionThroughput();
		
		public:
			unsigned int threads;
			unsigned int ctas;
			unsigned int unroll;
			unsigned int iterations;
	};
}

int main(int argc, char** argv);

//u64 = long long unsigned int
//u32 = unsigned int
//f32 = float

#endif

