/*!	\file TestBarriers.h
	\date Friday November 13, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief A test for barrier overhead.
*/

#ifndef TEST_BARRIERS_H_INCLUDED
#define TEST_BARRIERS_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	class TestBarriers : public Test
	{
		private:
			bool testBarriers();
			bool doTest();
		
		public:
			TestBarriers();
		
		public:
			unsigned int variables;
			unsigned int barriers;
			unsigned int iterations;
	};
}

int main(int argc, char** argv);

#endif

