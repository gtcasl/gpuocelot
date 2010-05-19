/*!
	\file SamplePTX.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief initializes vectors with statements defining PTX programs useful for testing 
		independently of the parser

	\date 24 Jan 2009
*/

#ifndef IRTEST_SAMPLEPTX_H_INCLUDED
#define IRTEST_SAMPLEPTX_H_INCLUDED

#include <vector>
#include <ocelot/ir/interface/Kernel.h>

namespace test {

	/*!
		Constructs a sample program with interesting CFG
	*/
	ir::Kernel::PTXStatementVector Sample_cfg();
	ir::Kernel::PTXStatementVector Sample_Divergence();

}

#endif

