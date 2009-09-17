/*!
	\file TestDataflowGraph.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday July 7, 2009
	\brief The source file for the TestDataflowGraph class.
*/

#ifndef TEST_DATAFLOW_GRAPH_CPP_INCLUDED
#define TEST_DATAFLOW_GRAPH_CPP_INCLUDED

#include <ocelot/analysis/test/TestDataflowGraph.h>
#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/Exception.h>

#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <boost/filesystem.hpp>
#include <queue>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace fs = boost::filesystem;

namespace test
{
	class Double
	{
		public:
			unsigned int operator()( 
				analysis::DataflowGraph::RegisterPointerVector::const_iterator 
				it )
			{
				return *it->pointer;
			}
	};

	class ToId
	{
		public:
			unsigned int operator()( 
				analysis::DataflowGraph::RegisterVector::const_iterator it )
			{
				return it->id;
			}
	};

	bool TestDataflowGraph::_verify( const analysis::DataflowGraph& graph )
	{
		for( analysis::DataflowGraph::const_iterator block = graph.begin(); 
			block != graph.end(); ++block )
		{
			analysis::DataflowGraph::Block::RegisterSet defined;
			
			report( " Alive in registers:" );
			for( analysis::DataflowGraph::Block::RegisterSet::const_iterator 
				reg = block->aliveIn().begin(); 
				reg != block->aliveIn().end(); ++reg )
			{
				report( "  " << reg->id );
				defined.insert( *reg );
			}
				
			if( !block->phis().empty() )
			{
				status << "  Block " << block->label() 
					<< " has " << block->phis().size() 
					<< " phi instructions." << std::endl;
				return false;			
			}
			
			for( analysis::DataflowGraph::InstructionVector::const_iterator 
				instruction = block->instructions().begin(); 
				instruction != block->instructions().end(); ++instruction )
			{
				report( " " << instruction->label << ":  " 
					<< hydrazine::toFormattedString( instruction->d.begin(), 
					instruction->d.end(), Double() ) << " <- " 
					<< hydrazine::toFormattedString( instruction->s.begin(), 
					instruction->s.end(), Double() ) );
					
				analysis::DataflowGraph::RegisterPointerVector::const_iterator
					reg = instruction->s.begin();
				for( ; reg != instruction->s.end(); ++reg )
				{
					if( !defined.count( *reg ) )
					{
						status << "  Register " << *reg->pointer 
							<< " in instruction " << instruction->label 
							<< " in block " << block->label() 
							<< " used uninitialized." << std::endl;
						return false;
					}
				}
				
				reg = instruction->d.begin();
					
				for( ; reg != instruction->d.end(); ++reg )
				{
					defined.insert( *reg );
				}
			}
			
			for( analysis::DataflowGraph::Block::RegisterSet::const_iterator 
				reg = block->aliveOut().begin(); 
				reg != block->aliveOut().end(); ++reg )
			{
				if( !defined.count( *reg ) )
				{
					status << "  Register " << reg->id 
						<< " out set of block " << block->label() 
						<< " used uninitialized." << std::endl;
					return false;
				}
			}			
		}
		return true;
	}

	bool TestDataflowGraph::_verifySsa( const analysis::DataflowGraph& graph )
	{
		analysis::DataflowGraph::Block::RegisterSet global;
		for( analysis::DataflowGraph::const_iterator block = graph.begin(); 
			block != graph.end(); ++block )
		{
			analysis::DataflowGraph::Block::RegisterSet defined;
			
			report( block->label() );
			report( " Alive in registers:" );
			for( analysis::DataflowGraph::Block::RegisterSet::const_iterator 
				reg = block->aliveIn().begin(); 
				reg != block->aliveIn().end(); ++reg )
			{
				report( "  " << reg->id );
				defined.insert( *reg );
			}
			
			for( analysis::DataflowGraph::PhiInstructionVector::const_iterator 
				phi = block->phis().begin(); 
				phi != block->phis().end(); ++phi )
			{
				report( " phi " << phi->d.id << " <- " 
					<< hydrazine::toFormattedString( phi->s.begin(), 
						phi->s.end(), ToId() ) );
				for( analysis::DataflowGraph::RegisterVector::const_iterator
					reg = phi->s.begin(); reg != phi->s.end(); ++reg )
				{
					if( !defined.count( *reg ) )
					{
						status << "  Register " << reg->id
							<< " in phi instruction " 
							<< ( phi - block->phis().begin() )
							<< " in " << block->label() 
							<< " used uninitialized." << std::endl;
						return false;
					}
				}
				defined.insert( phi->d );
				if( !global.insert( phi->d ).second )
				{
					status << "  In " << block->label() 
						<< ", instruction phi " 
						<< ( phi - block->phis().begin() ) 
						<< ", reg " << phi->d.id
						<< " already defined globally." << std::endl;
					return false;
				}
			}
			
			for( analysis::DataflowGraph::InstructionVector::const_iterator 
				instruction = block->instructions().begin(); 
				instruction != block->instructions().end(); ++instruction )
			{
				report( " " << instruction->label << ":  " 
					<< hydrazine::toFormattedString( instruction->d.begin(), 
					instruction->d.end(), Double() ) << " <- " 
					<< hydrazine::toFormattedString( instruction->s.begin(), 
					instruction->s.end(), Double() ) );
					
				analysis::DataflowGraph::RegisterPointerVector::const_iterator
					reg = instruction->s.begin();
				for( ; reg != instruction->s.end(); ++reg )
				{
					if( !defined.count( *reg ) )
					{
						status << "  Register " << *reg->pointer 
							<< " in instruction " << instruction->label 
							<< " in " << block->label() 
							<< " used uninitialized." << std::endl;
						return false;
					}
				}
				
				for( reg = instruction->d.begin(); 
					reg != instruction->d.end(); ++reg )
				{
					defined.insert( *reg );
					if( !global.insert( *reg ).second )
					{
						status << "  In " << block->label() 
							<< ", instruction " 
							<< instruction->label << ", reg " << *reg->pointer
							<< " already defined globally." << std::endl;
						return false;
					}
				}
			}
			
			for( analysis::DataflowGraph::Block::RegisterSet::const_iterator 
				reg = block->aliveOut().begin(); 
				reg != block->aliveOut().end(); ++reg )
			{
				if( !defined.count( *reg ) )
				{
					status << "  Register " << reg->id 
						<< " out set of block " << block->label() 
						<< " used uninitialized." << std::endl;
					return false;
				}
			}			
		}
		return true;
	}

	void TestDataflowGraph::_getFileNames()
	{
		fs::path path = base;
		_files.clear();
		
		if( fs::is_directory( path ) )
		{
			std::queue< fs::directory_iterator > directories;
			directories.push( path );
			
			fs::directory_iterator end;
			
			while( !directories.empty() )
			{
				for( fs::directory_iterator 
					file = directories.front(); 
					file != end; ++file )
				{
					if( fs::is_directory( file->status() ) )
					{
						directories.push( file->path() );
					}
					else if( fs::is_regular_file( file->status() ) )
					{
						if( file->path().extension() == ".ptx" )
						{
							_files.push_back( file->path().string() );
						}
					}
				}
				directories.pop();
			}
		}
		else if( fs::is_regular_file( path ) )
		{
			if( path.extension() == ".ptx" )
			{
				_files.push_back( path.string() );
			}
		}
	}
	
	bool TestDataflowGraph::_testGeneric()
	{
		status << "Testing Generic Dataflow" << std::endl;
		for( StringVector::const_iterator file = _files.begin(); 
			file != _files.end(); ++file )
		{
			status << " For File: " << *file << std::endl;
			ir::Module module( *file );
			
			for( ir::Module::KernelVector::iterator 
				ki = module.begin( ir::Instruction::PTX ); 
				ki != module.end( ir::Instruction::PTX ); ++ki )
			{
				ir::PTXKernel& kernel = static_cast< ir::PTXKernel& >( **ki );
				status << "  For Kernel: " << kernel.name << std::endl;
				ir::PTXKernel::assignRegisters( kernel.instructions );
				kernel.dfg()->compute();
				if( !_verify( *kernel.dfg() ) )
				{
					return false;
				}
			}
		}
		status << " Test Passed" << std::endl;
		return true;
	}
	
	bool TestDataflowGraph::_testSsa()
	{
		status << "Testing SSA Dataflow" << std::endl;
		for( StringVector::const_iterator file = _files.begin(); 
			file != _files.end(); ++file )
		{
			status << " For File: " << *file << std::endl;
			ir::Module module( *file );
			
			for( ir::Module::KernelVector::iterator 
				ki = module.begin( ir::Instruction::PTX ); 
				ki != module.end( ir::Instruction::PTX ); ++ki )
			{
				ir::PTXKernel& kernel = static_cast< ir::PTXKernel& >( **ki );
				status << "  For Kernel: " << kernel.name << std::endl;
				ir::PTXKernel::assignRegisters( kernel.instructions );
				kernel.dfg()->compute();
				kernel.dfg()->toSsa();
				if( !_verifySsa( *kernel.dfg() ) )
				{
					return false;
				}
			}
		}
		status << " Test Passed" << std::endl;
		return true;
	}
	
	bool TestDataflowGraph::_testReverseSsa()
	{
		status << "Testing SSA then back Dataflow" << std::endl;
		for( StringVector::const_iterator file = _files.begin(); 
			file != _files.end(); ++file )
		{
			status << " For File: " << *file << std::endl;
			ir::Module module( *file );
			
			for( ir::Module::KernelVector::iterator 
				ki = module.begin( ir::Instruction::PTX ); 
				ki != module.end( ir::Instruction::PTX ); ++ki )
			{
				ir::PTXKernel& kernel = static_cast< ir::PTXKernel& >( **ki );
				status << "  For Kernel: " << kernel.name << std::endl;
				ir::PTXKernel::assignRegisters( kernel.instructions );
				kernel.dfg()->compute();
				kernel.dfg()->toSsa();
				kernel.dfg()->fromSsa();
				if( !_verify( *kernel.dfg() ) )
				{
					return false;
				}
			}
		}
		status << " Test Passed" << std::endl;
		return true;	
	}
	
	bool TestDataflowGraph::doTest()
	{
		_getFileNames();
		return _testGeneric() && _testSsa() && _testReverseSsa();
	}
	
	TestDataflowGraph::TestDataflowGraph()
	{
		name  = "TestDataflowGraph";
		
		description = "A test for the DataflowGraph class. Test Points: 1) ";
		description += "Generic: load PTX files, convert them into dataflow";
		description += " graphs, verify that all live ranges spanning blocks";
		description += " are consistent. 2) SSA: convert to ssa form, verify";
		description += " that no register is declared more than once. 3)";
		description += " reverse SSA: convert to ssa then out of ssa, verify";
		description += " that all live ranges spanning blocks are consistent.";
	}
}

int main( int argc, char** argv )
{
	hydrazine::ArgumentParser parser( argc, argv );
	test::TestDataflowGraph test;
	parser.description( test.testDescription() );

	parser.parse( "-i", "--input", test.base, "../tests/ptx", 
		"Search path for PTX files." );
	parser.parse( "-v", "--verbose", test.verbose, false, 
		"Print out info after the test." );
	parser.parse();
	
	test.test();
	
	return test.passed();	
}

#endif

