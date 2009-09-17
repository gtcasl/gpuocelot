/*!
	\file TraceEvent.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief declares TraceEvent class for recording runtime information

*/

#include <ocelot/trace/interface/TraceEvent.h>

trace::TraceEvent::TraceEvent():
	blockId(0, 0, 0),
	PC(0) 
{

}

/*!
	Constructs a TraceEvent object
*/
trace::TraceEvent::TraceEvent(
			ir::Dim3 t_blockId,
			ir::PTXU64 t_PC, 
			const ir::PTXInstruction * t_instruction, 
			const boost::dynamic_bitset<> & t_active,
			const U64Vector & t_memory_addresses,
			const U32Vector & t_memory_sizes,
			const ir::PTXU32 ctxStackSize) :
	blockId(t_blockId),
	PC(t_PC),
	contextStackSize(ctxStackSize),
	instruction(t_instruction),
	active(t_active),
	memory_addresses(t_memory_addresses),
	memory_sizes(t_memory_sizes)
{

}

std::string trace::TraceEvent::toString() const
{

	std::stringstream stream;
	stream << "(" << PC << ") : \"" << instruction->toString() << "\" [" 
		<< active << "]";

	assert( memory_addresses.size() == memory_sizes.size() );
	
	U64Vector::const_iterator address = memory_addresses.begin();
	U32Vector::const_iterator size = memory_sizes.begin();
	
	if( !memory_addresses.empty() )
	{
	
		stream << " : <" << (void*)*address << std::dec 
			<< ", " << *size << ">";
	
		++address;
		++size;
	
	}
	
	for( ; address != memory_addresses.end(); ++address, ++size )
	{
	
		stream << " <" << (void*)*address << std::dec 
			<< ", " << *size << ">";
	
	}
	
	return stream.str();

}

