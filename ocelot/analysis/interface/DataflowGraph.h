/*!
	\file DataflowGraph.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 23, 2009
	\file The header file for the DataflowGraph class.
*/

#ifndef DATAFLOW_GRAPH_H_INCLUDED
#define DATAFLOW_GRAPH_H_INCLUDED

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <cassert>
#include <unordered_set>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define MAX_INSTRUCTION_INPUTS 6
#define MAX_INSTRUCTION_OUTPUTS 4
#define INVALID_REGISTER ((analysis::DataflowGraph::RegisterId)-1)

/*!
	\brief A namespace for compiler analysis modules.
*/
namespace analysis
{

	/*!
		\brief A class representing a graph of block of instructions, showing
			which registers are alive in each basic block.
	*/
	class DataflowGraph
	{
		public:
			/*! \brief A unique ID for a logical register */
			typedef unsigned int RegisterId;
			/*! \brief A unique ID for a logical instruction */
			typedef unsigned int InstructionId;
		
			/*!
				\brief A class for referring to a generic instruction.
			*/
			class Instruction
			{
				public:
					/*! \brief The instruction text */
					std::string label;
					/*! \brief The id of the instruction */
					InstructionId id;
					/*! \brief Destination registers */
					RegisterId d[ MAX_INSTRUCTION_OUTPUTS ];
					/*! \brief Source registers */
					RegisterId s[ MAX_INSTRUCTION_INPUTS ];
			};
			
			/*! \brief A vector of Instructions */
			typedef std::deque< Instruction > InstructionVector;
			
			class Block;
			
			/*! \brief A vector of blocks */
			typedef std::list< Block > BlockVector;
			
			/*! \brief A vector of Block pointers */
			typedef std::unordered_set< BlockVector::iterator > BlockPointerSet;
			
			/*!
				\brief A class for referring to a generic basic block of 
					instructions.
			*/
			class Block
			{
				friend class DataflowGraph;			
				public:
					/*! \brief The type of block */
					enum Type
					{
						Entry,
						Exit,
						Body,
						Invalid
					};
			
					/*! \brief A unique set of register Ids */
					typedef std::unordered_set< RegisterId > RegisterIdSet;

				private:
					/*! \brief Registers that are alive entering the block */
					RegisterIdSet _aliveIn;
					/*! \brief Register that are alive exiting the block */
					RegisterIdSet _aliveOut;
					/*! \brief The fallthrough block */
					BlockVector::iterator _fallthrough;
					/*! \brief The target block */
					BlockPointerSet _targets;
					/*! \brief A list of predecessor blocks */
					BlockPointerSet _predecessors;
					/*! \brief The type of block */
					Type _type;
					/*! \brief Ordered set of instructions in the block */
					InstructionVector _instructions;
					/*! \brief Block label */
					std::string _label;

				private:
					/*! \brief Compare two register sets */
					static bool _equal( const RegisterIdSet& one, 
						const RegisterIdSet& two );

				private:
					/*! \brief Private constructor */
					Block( Type type );
					
					/*! \brief Update the live ranges */
					bool compute();
			
				public:
					/*! \brief Constructor from a sequence of instructions */
					template< typename Inst >
					Block( const ir::BasicBlock& block, 
						const std::deque< Inst >& instructions  );
					/*! \brief Default constructor */
					Block();
					
				public:
					/*! \brief Get registers that are alive entering the block*/
					const RegisterIdSet& aliveIn() const;
					/*! \brief Get registers that are alive exiting the block */
					const RegisterIdSet& aliveOut() const;
					/*! \brief Get the fallthrough block */
					BlockVector::iterator fallthrough() const;
					/*! \brief Get the target block */
					const BlockPointerSet& targets() const;
					/*! \brief Get a list of predecessor blocks */
					const BlockPointerSet& predecessors() const;
					/*! \brief Get the type of the block */
					Type type() const;
					/*! \brief Get an ordered set of instructions in the block*/
					const InstructionVector& instructions() const;
					/*! \brief Get the block label */
					const std::string& label() const;
			};
			
			
		public:
			
			/*! \brief iterator */
			typedef BlockVector::iterator iterator;
					
			/*! \brief const_iterator */
			typedef BlockVector::const_iterator const_iterator;

			/*! \brief Value type */
			typedef BlockVector::value_type value_type;

			/*! \brief Size type */
			typedef BlockVector::size_type size_type;

		private:
			BlockVector _blocks;
			bool _consistent;

		private:
			/*! \brief Convert from a PTXInstruction to an Instruction  */
			static Instruction _convert( const ir::PTXInstruction& i, 
				InstructionId id  );

		public:
			/*! \brief Default constructor */
			DataflowGraph();
			
			/*! \brief Build from a CFG */
			template< typename Inst >
			DataflowGraph( const ir::ControlFlowGraph& cfg, 
				const std::deque< Inst >& instructions );

		public:
			/*! \brief Return an iterator to the program entry point */
			iterator begin();
			/*! \brief Return an iterator to the program entry point */
			const_iterator begin() const;
			
			/*! \brief Return an iterator to the program exit point */
			iterator end();
			/*! \brief Return an iterator to the program exit point */
			const_iterator end() const;

		public:			
			/*! \brief Is the graph empty? */
			bool empty() const;
			/*! \brief Get the number of blocks */
			size_type size() const;
			/*! \brief Get the max number of blocks */
			size_type max_size() const;

		public:
			/*!
				\brief Insert a Block between two existing blocks.
				\param predecessor An iterator to the previous block.
				\return An iterator to the inserted block.
			*/
			iterator insert( iterator predecessor, const Block& b );
			/*! \brief Set the target of a block */
			void target( iterator block, iterator target );
			/*! \brief Delete a block, joining predecessors and successors */
			iterator erase( iterator block );
			/*! \brief Revert back to a single entry and exit block */
			void clear();
			
		public:
			/*! \brief Compute live ranges */
			void compute();
	};

	template< typename Inst >
	DataflowGraph::DataflowGraph( const ir::ControlFlowGraph& _cfg, 
		const std::deque< Inst >& instructions )  
		: _consistent( instructions.empty() )
	{
		typedef std::unordered_map< ir::BasicBlock*, iterator > BlockMap;
		BlockMap map;
		
		ir::ControlFlowGraph& cfg = const_cast< ir::ControlFlowGraph& >( _cfg );
		ir::ControlFlowGraph::BlockPointerVector blocks 
			= cfg.executable_sequence();
		assert( blocks.size() >= 2 );
		assert( blocks.front() == cfg.get_entry_block() );
		assert( blocks.back() == cfg.get_exit_block() );
		
		report( "Importing " << blocks.size() << " blocks from CFG." );
		
		unsigned int count = 1;
		_blocks.push_back( Block( Block::Entry ) );
		for( ir::ControlFlowGraph::BlockPointerVector::iterator 
			bbi = blocks.begin() + 1; bbi != blocks.end() - 1; ++bbi, ++count )
		{
			Block newB( **bbi, instructions );
			std::stringstream label;
			label << "Block " << count << " " << (*bbi)->label;		
			newB._label = label.str();
			_blocks.push_back( newB );	
		}
		_blocks.push_back( Block( Block::Exit ) );
		
		iterator bi = _blocks.begin();
		ir::ControlFlowGraph::BlockPointerVector::iterator bbi = blocks.begin();
				
		for( ; bi != _blocks.end(); ++bi, ++bbi )
		{
			map.insert( std::make_pair( *bbi, bi ) );
		}
		
		bbi = blocks.begin();
		for( ; bbi != blocks.end(); ++bbi )
		{
			BlockMap::iterator bi = map.find( *bbi );
			assert( bi != map.end() );
		
			ir::BasicBlock::EdgeList inEdges = (*bbi)->get_in_edges();
		
			for( ir::BasicBlock::EdgeList::iterator ei = inEdges.begin(); 
				ei != inEdges.end(); ++ei )
			{
				BlockMap::iterator begin = map.find( (*ei)->head );
				assert( begin != map.end() );
				
				if( (*ei)->type == ir::Edge::FallThrough )
				{
					begin->second->_fallthrough = bi->second;
					bi->second->_predecessors.insert( begin->second );
				}
				else if( (*ei)->type == ir::Edge::Branch )
				{
					begin->second->_targets.insert( bi->second );
					bi->second->_predecessors.insert( begin->second );	
				}
			}
							
		}
	}

	template< typename Inst >
	DataflowGraph::Block::Block( const ir::BasicBlock& block, 
		const std::deque< Inst >& instructions ) : _type( Body )
	{
		for( ir::BasicBlock::InstructionList::const_iterator 
			fi = block.instructions.begin(); 
			fi != block.instructions.end(); ++fi )
		{
			assert( *fi < instructions.size() );
			_instructions.push_back( _convert( instructions[ *fi ], *fi ) );
		}
		
	}
	
	std::ostream& operator<<( std::ostream& out, const DataflowGraph& graph );
}

namespace std
{
	template<> inline size_t hash< 
		analysis::DataflowGraph::iterator >::operator()( 
		analysis::DataflowGraph::iterator it ) const
	{
		return ( size_t )&( *it );
	}
}

#endif

