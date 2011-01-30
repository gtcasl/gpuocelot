/*!	\file TestMemoryAccesses.h
	\date Thursday November 12, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A test for memory access patterns.
*/

#ifndef TEST_MEMORY_ACCESSES_H_INCLUDED
#define TEST_MEMORY_ACCESSES_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	class TestMemoryAccesses : public Test
	{
		private:
			bool testStridedAccess();
			bool testLinearAccess();
			bool doTest();
		
		public:
			TestMemoryAccesses();
		
		public:
			unsigned int ctas;
			unsigned int threads;
			unsigned int bytes;
			unsigned int stride;
	};
}

int main(int argc, char** argv);

#endif

