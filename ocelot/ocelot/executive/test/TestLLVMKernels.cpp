/*!
	\file TestLLVMKernels.cpp
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the TestLLVMKernels unit test.
*/

#ifndef TEST_LLVM_KERNELS_CPP_INCLUDED
#define TEST_LLVM_KERNELS_CPP_INCLUDED

#include <ocelot/executive/test/TestLLVMKernels.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <cmath>

namespace test
{
	bool TestLLVMKernels::_loadKernels()
	{
		if( !_context.selectDeviceByISA( ir::Instruction::LLVM ) )
		{
			status << "Failed to select llvm device.";
			return false;
		}
		
		if( !_context.loadModule( kernelFile ) )
		{
			status << "Failed to load module " << kernelFile << "\n";
		}
		
		ir::Kernel* kernel = _context.getKernel( ir::Instruction::LLVM, 
			kernelFile, "_Z19k_sequenceDivergentPf" );
		if( !kernel )
		{
			status << "Failed to get kernel _Z19k_sequenceDivergentPf\n";
			return false;
		}
		
		_divergentKernel = static_cast< 
			executive::LLVMExecutableKernel* >( kernel );
		_divergentKernel->setKernelShape( 8, 1, 1 );

		kernel = _context.getKernel( ir::Instruction::LLVM, 
			kernelFile, "_Z17k_sequenceLoopingPfi" );
		if( !kernel )
		{
			status << "Failed to get kernel _Z17k_sequenceLoopingPfi\n";
			return false;
		}
		
		_loopingKernel = static_cast< 
			executive::LLVMExecutableKernel* >( kernel );
		_loopingKernel->setKernelShape( 8, 1, 1 );
		
		kernel = _context.getKernel( ir::Instruction::LLVM, 
			kernelFile, "_Z21k_matrixVectorProductPKfS0_Pfii" );
		if( !kernel )
		{
			status << "Failed to get kernel " 
				<< "_Z21k_matrixVectorProductPKfS0_Pfii\n";
			return false;
		}
		
		_matrixMultiplyKernel = static_cast< 
			executive::LLVMExecutableKernel* >( kernel );
		_matrixMultiplyKernel->setKernelShape( 8, 1, 1 );
		
		return true;
	}

	bool TestLLVMKernels::testDivergent()
	{
		executive::LLVMExecutableKernel* kernel = _divergentKernel;
		
		unsigned int N = 8;
		
		float* sequence = new float[ N ];
		_context.registerExternal( sequence, sizeof( float ) * N );

		for( unsigned int i = 0; i < N; ++i ) 
		{
			sequence[ i ] = -2.0;
		}

		// configure parameters
		ir::Parameter& param_A = kernel->getParameter(
			"__cudaparm__Z19k_sequenceDivergentPf_ptr" );

		// set parameter values
		param_A.arrayValues.resize( 1 );
		param_A.arrayValues[ 0 ].val_u64 = (ir::PTXU64)sequence;
		kernel->updateParameterMemory();

		// launch the kernel
		kernel->setKernelShape( N, 1, 1 );
		kernel->launchGrid( 1, 1 );
	
		for( unsigned int i = 0; i < N; i++ )
		{
			float w = i * 0.0625f;
			if( i % 2 ) 
			{
				if( fabs( cos( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i << " - cos(" 
						<< w << ") = " << cos( w ) << ", encountered " 
						<< sequence[ i ] << "\n";
					return false;
				}
			}
			else
			{
				if( fabs( sin( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i << " - sin(" 
						<< w << ") = " << sin( w ) << ", encountered " 
						<< sequence[ i ] << "\n";
					return false;
				}
			}
		}

		_context.free( sequence );
		delete[] sequence;
	
		return true;
	}

	bool TestLLVMKernels::testLooping()
	{
		executive::LLVMExecutableKernel* kernel = _loopingKernel;
		
		unsigned int N = 8 * 5;
		float* sequence = new float[ N ];
		_context.registerExternal( sequence, sizeof( float ) * N );

		for( unsigned int i = 0; i < N; ++i ) 
		{
			sequence[ i ] = -2;	
		}

		ir::Parameter& param_A = kernel->getParameter(
			"__cudaparm__Z17k_sequenceLoopingPfi_ptr");
		ir::Parameter& param_B = kernel->getParameter(
			"__cudaparm__Z17k_sequenceLoopingPfi_N");

		param_A.arrayValues.resize( 1 );
		param_A.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) sequence;
		param_B.arrayValues.resize( 1 );
		param_B.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) N;
		kernel->updateParameterMemory();

		kernel->setKernelShape( 8, 1, 1 );
		kernel->launchGrid( 1, 1 );

		for( unsigned int i = 0; i < N; ++i ) 
		{
			float w = i * 0.0625f;
			if( i % 2 )
			{
				if( fabs( cos( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i 
						<< " - cos(" << w << ") = " << cos( w ) 
						<< ", encountered " << sequence[ i ] << "\n";
					return false;
				}
			}
			else 
			{
				if( fabs( sin( w ) - sequence[ i ] ) > 0.001f ) 
				{
					status << "error on element " << i 
						<< " - sin(" << w << ") = " << sin(w) 
						<< ", encountered " << sequence[i] << "\n";
					return false;
				}
			}
		}
		
		_context.free( sequence );
		delete[] sequence;
		
		return true;
	}
	
	bool TestLLVMKernels::testMatrixMultiply()
	{
		executive::LLVMExecutableKernel* kernel = _matrixMultiplyKernel;

		const unsigned int M = 8, N = 8;

		float* A = new float[ M * N ];
		float* V = new float[ N ];
		float* R = new float[ M ];

		_context.registerExternal( A, sizeof( float ) * N * M );
		_context.registerExternal( V, sizeof( float ) * N );
		_context.registerExternal( R, sizeof( float ) * M );

		for( unsigned int i = 0; i < M; i++ ) 
		{
			for( unsigned int j = 0; j < N; j++ ) 
			{
				A[ i + j * N ] = 0;
				if ( i >= j )
				{
					A[ i + j * N ] = 1.0f / ( float )( 1 + i - j );
				}
				V[ j ] = ( float )( 1 + j );
			}
			R[ i ] = -2;
		}

		ir::Parameter &param_A = kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii___val_paramA" );
		ir::Parameter &param_V = kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii___val_paramV" );
		ir::Parameter &param_R = kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_R" );
		ir::Parameter &param_M = kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_M" );
		ir::Parameter &param_N = kernel->getParameter(
			"__cudaparm__Z21k_matrixVectorProductPKfS0_Pfii_N" );

		param_A.arrayValues.resize( 1 );
		param_A.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) A;
		param_V.arrayValues.resize( 1 );
		param_V.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) V;
		param_R.arrayValues.resize( 1 );
		param_R.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) R;
		param_M.arrayValues.resize( 1 );
		param_M.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) M;
		param_N.arrayValues.resize( 1 );
		param_N.arrayValues[ 0 ].val_u64 = ( ir::PTXU64 ) N;
		
		kernel->updateParameterMemory();

		kernel->setKernelShape( 8, 1, 1 );
		kernel->launchGrid( 1, 1 );

		for( unsigned int i = 0; i < M; i++ ) 
		{
			float r_ref = 0;
			for( unsigned int j = 0 ; j < N; j++ ) 
			{
				r_ref += V[ j ] * A[ i + j * N ];
			}
			if( fabs( r_ref - R[ i ] ) > 0.01f ) 
			{
				status << "Computed and reference results do not match.\n";
				return false;
			}
		}

		_context.free( R );
		_context.free( V );
		_context.free( A );
		delete[] R;
		delete[] V;
		delete[] A;
		
		return true;
	}
	
	bool TestLLVMKernels::doTest()
	{
		bool result = _loadKernels();
		
		return result && testDivergent() && testLooping() 
			&& testMatrixMultiply();
	}
	
	TestLLVMKernels::TestLLVMKernels()
	{
		name = "TestLLVMKernels";
		
		description = "A unit test for the LLVM executive runtime.";
		description += " Test Points: 1) Execute a kernel with divergent ";
		description += "control flow. 2) Execute a kernel with a loop. ";
		description += "3) Execute a matrix multiply kernel.";
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestLLVMKernels test;

	parser.description( test.testDescription() );

	parser.parse( "-i", test.kernelFile, "ocelot/executive/test/kernels.ptx", 
		"The input file containing the kernels being tested." );
	parser.parse( "-s", test.seed, 0,
		"Set the random seed, 0 implies seed with time." );
	parser.parse( "-v", test.verbose, false, "Print out info after the test." );
	parser.parse();

	test.test();

	return test.passed();
}

#endif

