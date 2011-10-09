/*! \file   ProgramStructureGraph.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Monday August 1, 2011
	\brief  The header file for the ProgramStructureGraph class.
*/

#pragma once

// Ocelot Includes
#include <ocelot/analysis/interface/Analysis.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>

namespace analysis
{

/*! \brief ProgramStructureGraphs are overlays over the ControlFlowGraph that
	capture some structure other than basic blocks.  
	
	Examples of program structures from literature may include Superblocks,
		Hyperblocks, Treegions, or Subkernels.
*/
class ProgramStructureGraph : public KernelAnalysis
{
public:
	class Block
	{
	public:
		// ProgramStructureGraph Typedefs
		typedef std::list<Block>            BlockVector;
		typedef BlockVector::iterator       pointer_iterator;
		typedef BlockVector::const_iterator const_pointer_iterator;
		typedef size_t                      Id;
		
		// CFG Typedefs
		typedef ir::ControlFlowGraph               CFG;
		typedef ir::BasicBlock                     BB;
		typedef std::list<CFG::iterator>           BBPointerList;
		typedef BB::instruction_iterator           instruction_iterator;
		typedef BBPointerList::iterator            bb_pointer_iterator;
		typedef BBPointerList::const_iterator      const_bb_pointer_iterator;
		typedef CFG::iterator                      cfg_iterator;
		typedef CFG::const_iterator                const_cfg_iterator;
		typedef CFG::pointer_iterator              cfg_pointer_iterator;
		typedef BB::const_instruction_iterator     const_instruction_iterator;
		typedef CFG::const_pointer_iterator        const_cfg_pointer_iterator;

		// Forward Declarations
		class const_iterator;
		
		/*! \brief An iterator over basic blocks */
		class block_iterator
		{
		public:
			typedef block_iterator self;
			typedef ir::BasicBlock value_type;
			typedef value_type&    reference;
			typedef value_type*    pointer;
		
		public:	      
			block_iterator();
			block_iterator(const block_iterator&);
			explicit block_iterator(const bb_pointer_iterator& i,
				const pointer_iterator& b);

		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
			
			bool operator==(const self&) const;
			bool operator!=(const self&) const;	
		
			bool begin() const;
			bool end() const;
			
			operator pointer_iterator();
			operator bb_pointer_iterator();
		
		private:
			bb_pointer_iterator _iterator;	
			pointer_iterator    _block;

			friend class const_block_iterator;
			friend class Block;
		};

		/*! \brief A const iterator over basic blocks */
		class const_block_iterator
		{
		public:
			typedef const_block_iterator self;
			typedef ir::BasicBlock       value_type;
			typedef const value_type&    reference;
			typedef const value_type*    pointer;
		
		public:
			const_block_iterator();
			const_block_iterator(const const_block_iterator&);
			const_block_iterator(const block_iterator&);
			explicit const_block_iterator(const const_bb_pointer_iterator& i,
				const const_pointer_iterator& b);

		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
			
			bool operator==(const self&) const;
			bool operator!=(const self&) const;	
			
			bool begin() const;
			bool end() const;
			
			operator const_pointer_iterator();
			operator const_bb_pointer_iterator();
			
		private:
			const_bb_pointer_iterator _iterator;
			const_pointer_iterator     _block;
		};

		/*! \brief An iterator over the instructions in the
			contained basic blocks */
		class iterator
		{
		public:
			typedef iterator                         self;
			typedef instruction_iterator::value_type value_type;
			typedef value_type&                      reference;
			typedef value_type*                      pointer;

		public:	      
			iterator();
			explicit iterator(const block_iterator&,
				const instruction_iterator&);

		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
			
			bool operator==(const self&) const;
			bool operator!=(const self&) const;

		public:
			void align();

		private:
			instruction_iterator _instruction;
			block_iterator       _basicBlock;
		
			friend class const_iterator;
			friend class Block;

		};
		
		/*! \brief A const iterator */
		class const_iterator
		{
		public:
			typedef const_iterator                   self;
			typedef instruction_iterator::value_type value_type;
			typedef value_type&                      reference;
			typedef value_type*                      pointer;
		
		public:	      
			const_iterator();
			const_iterator(const iterator&);
			const_iterator(const const_iterator&);
			explicit const_iterator(const const_block_iterator&,
				const const_instruction_iterator&);
		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
			
			bool operator==(const self&) const;
			bool operator!=(const self&) const;	
		
		private:
			const_instruction_iterator _instruction;
			const_block_iterator       _basicBlock;		
		};
		
		class const_successor_iterator;
		
		/*! \brief An iterator over block successors */
		class successor_iterator
		{
		public:
			typedef successor_iterator self;
			typedef ir::BasicBlock     value_type;
			typedef value_type&        reference;
			typedef value_type*        pointer;
		
		public:	      
			successor_iterator();
			successor_iterator(const successor_iterator&);
			explicit successor_iterator(const block_iterator&,
				const cfg_pointer_iterator&);
			explicit successor_iterator(const block_iterator&);
			
		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
					
			bool operator==(const self&) const;
			bool operator!=(const self&) const;	
		
			operator pointer_iterator();
			operator cfg_pointer_iterator();
		
		public:
			void align();
		
		private:
			block_iterator       _block;
			cfg_pointer_iterator _successor;
		
			friend class const_successor_iterator;
		};
		
		/*! \brief An iterator over block successors */
		class const_successor_iterator
		{
		public:
			typedef const_successor_iterator self;
			typedef ir::BasicBlock           value_type;
			typedef const value_type&        reference;
			typedef const value_type*        pointer;
		
		public:
			const_successor_iterator();
			const_successor_iterator(const const_successor_iterator&);
			const_successor_iterator(const successor_iterator&);
			explicit const_successor_iterator(const const_block_iterator&,
				const const_cfg_pointer_iterator&);
			explicit const_successor_iterator(const const_block_iterator&);

		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
						
			bool operator==(const self&) const;
			bool operator!=(const self&) const;	
		
			operator const_pointer_iterator();
			operator const_cfg_pointer_iterator();

		public:
			void align();
			
		private:
			const_block_iterator       _block;
			const_cfg_pointer_iterator _successor;		
		};
		
		class const_predecessor_iterator;
		
		/*! \brief An iterator over block predecessors */
		class predecessor_iterator
		{
		public:
			typedef predecessor_iterator self;
			typedef ir::BasicBlock       value_type;
			typedef value_type&          reference;
			typedef value_type*          pointer;
		
		public:	      
			predecessor_iterator();
			predecessor_iterator(const predecessor_iterator&);
			explicit predecessor_iterator(const block_iterator&,
				const cfg_pointer_iterator&);
			explicit predecessor_iterator(const block_iterator&);
			
		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
			
			bool operator==(const self&) const;
			bool operator!=(const self&) const;
		
			operator pointer_iterator();
			operator block_iterator();
			operator cfg_pointer_iterator();
			
		public:
			void align();
		
		private:
			block_iterator       _block;
			cfg_pointer_iterator _predecessor;	
		
			friend class const_predecessor_iterator;
		};
		
		/*! \brief A const iterator over block predecessors */
		class const_predecessor_iterator
		{
		public:
			typedef const_predecessor_iterator self;
			typedef ir::BasicBlock             value_type;
			typedef const value_type&          reference;
			typedef const value_type*          pointer;
		
		public:	      
			const_predecessor_iterator();
			const_predecessor_iterator(const const_predecessor_iterator&);
			const_predecessor_iterator(const predecessor_iterator&);
			explicit const_predecessor_iterator(const const_block_iterator&,
				const const_cfg_pointer_iterator&);
			explicit const_predecessor_iterator(const const_block_iterator&);
			
		public:
			reference operator*() const;
			pointer operator->() const;
			self& operator++();
			self operator++(int);
			self& operator--();
			self operator--(int);
			
			bool operator==(const self&) const;
			bool operator!=(const self&) const;	
		
			operator const_pointer_iterator();
			operator const_block_iterator();
			operator const_cfg_pointer_iterator();

		public:
			void align();
		
		private:
			const_block_iterator       _block;
			const_cfg_pointer_iterator _predecessor;	
		};
		
	public:
		/*! \brief Get an iterator to the first instruction in the block */
		iterator begin();
		/*! \brief Get an iterator to the end of the instruction list */
		iterator end();
		
		/*! \brief Get a const iterator to the first instruction in the block */
		const_iterator begin() const;
		/*! \brief Get a const iterator to the end of the instruction list */
		const_iterator end() const;
		
	public:
		/*! \brief Get a block iterator to the first block */
		block_iterator block_begin();
		/*! \brief Get an iterator to the end of the block list */
		block_iterator block_end();
		
		/*! \brief Get a const iterator to the first block */
		const_block_iterator block_begin() const;
		/*! \brief Get a const iterator to the end of the block list */
		const_block_iterator block_end() const;

	public:
		/*! \brief Get a block iterator to the first successor */
		successor_iterator successors_begin();
		/*! \brief Get an iterator to the end of the successor list */
		successor_iterator successors_end();
		
		/*! \brief Get a const iterator to the first successor */
		const_successor_iterator successors_begin() const;
		/*! \brief Get a const iterator to the end of the successor list */
		const_successor_iterator successors_end() const;

	public:
		/*! \brief Get a block iterator to the first predecessor */
		predecessor_iterator predecessors_begin();
		/*! \brief Get an iterator to the end of the predecessor list */
		predecessor_iterator predecessors_end();
		
		/*! \brief Get a const iterator to the first predecessor */
		const_predecessor_iterator predecessors_begin() const;
		/*! \brief Get a const iterator to the end of the predecessor list */
		const_predecessor_iterator predecessors_end() const;

	public:
		/*! \brief insert a new block */
		block_iterator insert(ir::ControlFlowGraph::iterator block,
			block_iterator position);
		/*! \brief insert a new block to the end */
		block_iterator insert(ir::ControlFlowGraph::iterator block);

	public:
		/*! \brief insert a new instruction */
		iterator insert(ir::Instruction* instruction, iterator position);
		/*! \brief insert a new instruction to the end of the last block */
		iterator insert(ir::Instruction* instruction);
		
	public:
		/*! \brief Are there any instructions in the block? */
		bool empty() const;
		/*! \brief Get the number of instructions in the block */
		size_t instructions() const;
		/*! \brief Get the number of basic blocks in the block */
		size_t basicBlocks() const;
		/*! \brief Does the block have a fallthrough edge */
		bool hasFallthroughEdge() const;
		/*! \brief Get an iterator to an incomming fallthrough block */
		block_iterator getFallthrough();
		/*! \brief Does the block have an incomming fallthrough edge */
		bool hasIncommingFallthrough() const;
		/*! \brief Get an iterator to an incomming fallthrough block */
		block_iterator getIncommingFallthrough();
		/*! \brief Does the block contain the specified basic block ? */
		bool contains(const const_cfg_iterator& bb) const;
		/*! \brief Get an iterator the block containing the specified BB */
		pointer_iterator findBlockWithBasicBlock(const const_cfg_iterator& bb);
		/*! \brief Get an iterator the block containing the specified BB */
		const_pointer_iterator findBlockWithBasicBlock(
			const const_cfg_iterator& bb) const;
	
	public:
		/*! \brief Get a unique id for the block */
		Id id() const;
	
	public:
		/*! \brief Construct a new block */
		explicit Block(ProgramStructureGraph* g, Id id);
		
	private:
		BBPointerList          _blocks;
		ProgramStructureGraph* _graph;
		pointer_iterator       _this;
		Id                     _id;
		
	private:
		friend class ProgramStructureGraph;
	};

public:
	typedef Block::BlockVector            BlockVector;
	typedef Block::pointer_iterator       iterator;
	typedef Block::const_pointer_iterator const_iterator;
	typedef std::vector<iterator>         BlockPointerVector;
	typedef Block::Id                     Id;

public:
	/*! \brief The constructor sets the block id */
	ProgramStructureGraph();

public:
	/*! \brief Get an iterator to the first block */
	iterator begin();
	/*! \brief Get an iterator to the end of the block list */
	iterator end();
	
	/*! \brief Get a const iterator to the first block */
	const_iterator begin() const;
	/*! \brief Get a const iterator to the end of the block list */
	const_iterator end() const;

public:
	/*! \brief Reorders blocks into an executable sequence */
	void reorderIntoExecutableSequence();

public:
	/*! \brief Get the number of basic blocks in the graph */
	size_t size() const;
	/*! \brief Is the graph empty? */
	bool empty() const;
	/*! \brief Clear the graph */
	void clear();
	
protected:
	/*! \brief Create and link a new block against this graph */
	iterator newBlock();
	
protected:
	BlockVector _blocks;
	iterator    _entry;
	Id          _nextId;
};

}

namespace std
{
	template<>
	struct hash< analysis::ProgramStructureGraph::iterator >
	{
		inline size_t operator()(
			const analysis::ProgramStructureGraph::iterator& it ) const
		{
			return ( size_t )it->id();
		}
	};
}

