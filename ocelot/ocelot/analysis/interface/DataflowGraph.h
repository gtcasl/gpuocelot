/*!
	\file DataflowGraph.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 23, 2009
	\file The header file for the DataflowGraph class.
*/

#ifndef DATAFLOW_GRAPH_H_INCLUDED
#define DATAFLOW_GRAPH_H_INCLUDED

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
			typedef long long unsigned int RegisterId;
			/*! \brief A unique ID for a logical instruction */
			typedef long long unsigned int InstructionId;
		
			/*!
				\brief A class for referring to a generic instruction.
			*/
			class Instruction
			{
				public:
					/*! \brief The id of the instruction */
					InstructionId id;
					/*! \brief Destination registers */
					RegisterId d[4];
					/*! \brief Source registers */
					RegisterId s[6];
			};
			
			/*! \brief A vector of Instructions */
			typedef std::deque< Instruction > InstructionVector;
			
			class Block;
			
			/*! \brief A vector of Block pointers */
			typedef std::unordered_set< Block* > BlockPointerSet;
			
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
					Block* _fallthrough;
					/*! \brief The target block */
					Block* _target;
					/*! \brief A list of predecessor blocks */
					BlockPointerSet _predecessors;
					/*! \brief The type of block */
					Type _type;
					/*! \brief Ordered set of instructions in the block */
					InstructionVector _instructions;

				private:
					/*! \brief Private constructor */
					Block( Type type );
			
				public:
					/*! \brief Constructor from a sequence of instructions */
					template< typename InstructionIterator >
					Block( InstructionIterator begin, InstructionIterator end );
					/*! \brief Default constructor */
					Block();
					
				public:
					/*! \brief Get registers that are alive entering the block*/
					const RegisterIdSet& aliveIn() const;
					/*! \brief Get registers that are alive exiting the block */
					const RegisterIdSet& aliveOut() const;
					/*! \brief Get the fallthrough block */
					Block* fallthrough() const;
					/*! \brief Get the target block */
					Block* target() const;
					/*! \brief Get a list of predecessor blocks */
					const BlockPoitnerVector& predecessors() const;
					/*! \brief Get the type of the block */
					Type type() const;
					/*! \brief Get an ordered set of instructions in the block*/
					const InstructionVector& instructions() const;
			};
			
			/*! \brief A vector of blocks */
			typedef std::list< Block > BlockVector;

		public:
			
			/*! \brief iterator */
			typedef BlockVector::iterator iterator;
					
			/*! \brief const_iterator */
			typedef BlockVector::const_iterator const_iterator;

			/*! \brief Value type */
			typedef BlockVector::value_type value_type;

			/*! \brief Size type */
			typedef BlockVector::size_type value_type;

		private:
			BlockVector _blocks;
			bool _consistent;

		public:
			/*! \brief Default constructor */
			DataflowGraph();

		public:
			/*! \brief Return an iterator to the program entry point */
			iterator begin();
			/*! \brief Return an iterator to the program entry point */
			const_iterator begin() const;
			
			/*! \brief Return an iterator to the program exit point */
			iterator end();
			/*! \brief Return an iterator to the program exit point */
			const_iterator end();

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

	template< typename InstructionIterator >
	DataflowGraph::Block::Block( InstructionIterator begin, 
		InstructionIterator end )
	{
		
	}

}

#endif

