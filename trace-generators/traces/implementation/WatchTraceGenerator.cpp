/*!
	\file WatchTraceGenerator.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief trace generator for watching particular addresses
*/

// C++ includes
#include <iostream>

// Ocelot includes
#include <traces/interface/WatchTraceGenerator.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WatchTraceGenerator::Location::Location():
	base(0), size(0), space(ir::PTXInstruction::AddressSpace_Invalid)
{

}
trace::WatchTraceGenerator::Location::Location(const void *_base, size_t _size, 
	ir::PTXInstruction::AddressSpace _space) :
	base(_base), size(_size), space(_space)
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////

trace::WatchTraceGenerator::WatchTraceGenerator():
	blockDim(1, 1, 1)
{
	locations.reserve((int)ir::PTXInstruction::AddressSpace_Invalid);
	for (int i = 0; i < (int)ir::PTXInstruction::AddressSpace_Invalid; i++) {
		LocationMap map;
		locations.push_back(map);
	}
}

trace::WatchTraceGenerator::~WatchTraceGenerator() {

}

/*!
	\brief called when a traced kernel is launched to retrieve some 
		parameters from the kernel
*/
void trace::WatchTraceGenerator::initialize(const ir::ExecutableKernel& kernel) {
	blockDim = kernel.blockDim();
}

ir::Dim3 trace::WatchTraceGenerator::threadIdxFromThreadID(int tid) {
	ir::Dim3 threadIdx;
	
	threadIdx.x = (tid % blockDim.x);
	threadIdx.y = ((tid / blockDim.x) % blockDim.y);
	threadIdx.z = ((tid / (blockDim.x * blockDim.y)) % blockDim.z);
	
	return threadIdx;
}

/*!
	\brief Called whenever an event takes place.

	Note, the const reference 'event' is only valid until event() 
	returns
*/
void trace::WatchTraceGenerator::event(const trace::TraceEvent & event) {

	int threadID = 0;
	for (TraceEvent::U64Vector::const_iterator 
		addr_it = event.memory_addresses.begin(); 
		addr_it != event.memory_addresses.end(); ++addr_it) {
		
		for (; !event.active[threadID]; ++threadID) {}
		
		ir::PTXInstruction::AddressSpace space = event.instruction->addressSpace;
		Location location = findLocation((const void *)*addr_it, space);
		if (location.base) {
			switch (event.instruction->opcode) {
			case ir::PTXInstruction::Ld:
			case ir::PTXInstruction::Tex:
				loadAccess(event.PC, *event.instruction, (const void *)*addr_it, 
					event.memory_size, event.blockId,
					threadIdxFromThreadID(threadID), threadID, location);
				break;
	
			case ir::PTXInstruction::St:
				storeAccess(event.PC, *event.instruction, 
					(const void *)*addr_it, event.memory_size, event.blockId,
					threadIdxFromThreadID(threadID), threadID, location);
				break;
	
			default:
				break;
			}
		}
	}
}

/*!
	\brief examines the registered addresses and finds the location that includes address
	\param address the base address accessed
	\param space address space accessed
*/
trace::WatchTraceGenerator::Location trace::WatchTraceGenerator::findLocation(const void *address, 
	ir::PTXInstruction::AddressSpace space) {
	
	Location location;
	LocationMap & map = locations[(int)space];
	
	LocationMap::iterator lower = map.find(address);
	if (lower != map.end()) {
		return lower->second;
	}
	
	lower = map.lower_bound(address);
	do {
		if ((const char *)lower->second.base + lower->second.size > (const char *)address) {
			return lower->second;
		}
		if (lower == map.begin()) break;
		--lower;
	} while (true);
	
	return location;
}

/*! 
	\brief Called when a kernel is finished. There will be no more 
		events for this kernel.
*/
void trace::WatchTraceGenerator::finish() {

}

/*!
	\brief registers a particular address to watch
	\param base pointer to start of memory
	\param size number of bytes
	\param space indicates which state space to examine
*/
void trace::WatchTraceGenerator::registerAddress(const void *base, size_t size, 
	ir::PTXInstruction::AddressSpace space) {
	
	LocationMap &map = locations[(int)space];
	map[base] = Location(base, size, space);
}

void trace::WatchTraceGenerator::unregisterAddress(const void *base, 
	ir::PTXInstruction::AddressSpace space) {
	
	LocationMap &map = locations[(int)space];
	LocationMap::iterator it = map.find(base);
	if (it != map.end()) {
		map.erase(it);
	}
}
	
/*!

*/
void trace::WatchTraceGenerator::loadAccess(size_t PC, const ir::PTXInstruction &instruction, 
	const void *address, size_t size, ir::Dim3 block, ir::Dim3 threadIdx, int threadID, 
	const trace::WatchTraceGenerator::Location &location) {
	
	using namespace std;
	
	cout << "======Ocelot memory watch event======\n";
	cout << "= LOAD ACCESS - " << ir::PTXInstruction::toString(location.space) << "\n";
	cout << "= \n";
	cout << "= watching: " << location.base << " - " << location.size << " bytes\n";
	cout << "= \n";
	cout << "= load access to address: " << address << " - " << size << " bytes \n";
	cout << "= \n";
	cout << "= [" << PC << "] " << instruction.toString() << "\n";
	cout << "= \n";
	cout << "= by block(" << block.x << ", " << block.y << ") - thread(" << threadIdx.x << ", " 
		<< threadIdx.y << ", " << threadIdx.z << ") \n";
	cout << "=====================================\n";
}
	
/*!
	\brief a watched address has been stored to
	\param address actual address of the store
	\param threadID ID of thread performing the store
*/
void trace::WatchTraceGenerator::storeAccess(size_t PC, const ir::PTXInstruction &instruction, 
	const void *address, size_t size, ir::Dim3 block, ir::Dim3 threadIdx, int threadID, 
	const trace::WatchTraceGenerator::Location &location) {
	using namespace std;
	
	cout << "======Ocelot memory watch event======\n";
	cout << "= STORE ACCESS - " << ir::PTXInstruction::toString(location.space) << "\n";
	cout << "= \n";
	cout << "= watching: " << location.base << " - " << location.size << " bytes\n";
	cout << "= \n";
	cout << "= store access to address: " << address << " - " << size << " bytes \n";
	cout << "= \n";
	cout << "= [" << PC << "] " << instruction.toString() << "\n";
	cout << "= \n";
	cout << "= by block(" << block.x << ", " << block.y << ") - thread(" << threadIdx.x << ", " 
		<< threadIdx.y << ", " << threadIdx.z << ") \n";
	cout << "=====================================\n";	
}
	
//////////////////////////////////////////////////////////////////////////////////////////////////

