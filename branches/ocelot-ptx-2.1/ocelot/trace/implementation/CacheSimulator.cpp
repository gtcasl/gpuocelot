/*!
	\file CacheSimulator.cpp

	\author Sudnya Padalikar <sudnya.padalikar@gatech.edu>
	\date Sunday November 29, 2009
	\brief implementation of a CacheSimulator class to be the child of 
	TraceGenerator class for evaluating performance of various STL Containers.
*/

#ifndef TRACE_CACHESIMULATOR_CPP_INCLUDED
#define TRACE_CACHESIMULATOR_CPP_INCLUDED

#include <ocelot/trace/interface/CacheSimulator.h>
#include <hydrazine/implementation/debug.h>
#include <cmath>


#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace trace 
{

	CacheSimulator::CacheSimulator() 
	{
		
		writebackTime=50;
		addressWidth=64;
		cacheSize=8192;
		lineSize=64;
		hitTime=1;
		missTime=200;
		ways=1;
	}

	CacheSimulator::~CacheSimulator() 
	{

	}

	/*!
		called when a traced kernel is launched to retrieve some parameters 
		from the kernel
	*/
	void CacheSimulator::initialize(const executive::ExecutableKernel& kernel) 
	{
		_time=0;

		_missCount=0;
		_hitCount=0;
		_missLatency=0;
		_hitLatency=0;
	
		_memoryAccess=0;

		_cache.resize(cacheSize / (lineSize * ways) );
		for(CacheContainer::iterator i = _cache.begin(); i!= _cache.end(); ++i)
		{
			i->valid = false;
			i->dirty = false;
		}
		//report( "Initializing trace generator for kernel " << kernel->name );
	}

	void CacheSimulator::lookupEntry(int setNumber, int tag, bool accessType)
	{
		if( ! _cache[setNumber].valid) //miss
		{
			++_missCount;
			
			_missLatency += missTime;
			_time +=missTime;
			
			_cache[setNumber].valid = true;
			_cache[setNumber].tag = tag;
			if(accessType)
			{
				_cache[setNumber].dirty = true;
			}
		}
		
		else if (_cache[setNumber].valid) // go ahead and check the tag
		{
			if(_cache[setNumber].tag == tag) //hit
			{
				++_hitCount;
				_hitLatency+=hitTime;
				_time +=hitTime;
				
				if(accessType)
				{
					_cache[setNumber].dirty = true;//maybe redundant here?
				}

			}
			
			else
			{
				++_missCount;
				_missLatency += missTime;
				_time +=missTime;
				_cache[setNumber].tag = tag;
				
				if(accessType) //write miss
				{
					if(_cache[setNumber].dirty)
					{
						_time+=writebackTime;//do we need this if we're over writing?
					}
					_cache[setNumber].dirty = true;
				}
				
				else //read miss
				{
					//check dirty bit, if set writeback and then load
					if(_cache[setNumber].dirty)
					{
						_time+=writebackTime; //???????????????
					}
				}
							
			}		
		}
	}
	
	long long unsigned int CacheSimulator::getTag(ir::PTXU64 addressAccessed)
	{
		int shiftAmount = std::log2( cacheSize / lineSize ) 
			+ std::log2(lineSize); 
		addressAccessed >>= shiftAmount;		
		return addressAccessed;
	}
	
	int CacheSimulator::findSet(ir::PTXU64 addressAccessed)
	{
		addressAccessed >>= (int)std::log2(lineSize);

		ir::PTXU64 mask = (cacheSize / lineSize) - 1;
		return addressAccessed & mask;
	}

	int CacheSimulator::getOffset(ir::PTXU64 addressAccessed)
	{
		ir::PTXU64 mask = lineSize - 1;
		return addressAccessed & mask;				
	}
	
		
	bool CacheSimulator::cachelineSplit(ir::PTXU64 addressAccessed, 
		ir::PTXU32 bytesAccessed)
	{
		unsigned int offset;
		offset = getOffset(addressAccessed);
		if(offset+bytesAccessed > lineSize)
		{
			return false;
		}

		return true;
	}
	
	void CacheSimulator::read(ir::PTXU64 addressAccessed, 
		ir::PTXU32 bytesAccessed)
	{
		long long unsigned int tag;
		int setNumber;
		assertM(cachelineSplit(addressAccessed, bytesAccessed), 
			" Access accross split cache lines is not supported at this time.");
		//get tags, which set to look etc
		tag = getTag(addressAccessed);
		setNumber = findSet(addressAccessed);
		
		lookupEntry(setNumber, tag, false);
	
	}
	
	void CacheSimulator::write(ir::PTXU64 addressAccessed, 
		ir::PTXU32 bytesAccessed)
	{
		long long unsigned int tag;
		int setNumber;
		assertM(cachelineSplit(addressAccessed, bytesAccessed), 
			" Access accross split cache lines is not supported at this time.");

		//get tags, which set to look etc
		tag = getTag(addressAccessed);
		setNumber = findSet(addressAccessed);
		
		lookupEntry(setNumber, tag, true);
		
	}
		
	/*!
		called whenever an event takes place
	*/
	void CacheSimulator::event(const TraceEvent & event) 
	{
		if(!event.memory_addresses.empty())
		{
			_memoryAccess+=event.memory_addresses.size();
			
			if(event.instruction->opcode == ir::PTXInstruction::St) //write
			{
				for(TraceEvent::U64Vector::const_iterator 
					i = event.memory_addresses.begin(); 
					i != event.memory_addresses.end(); ++i)
				{
					write(*i, event.memory_size);
				}	
			}
			else
			{
				for(TraceEvent::U64Vector::const_iterator 
					i = event.memory_addresses.begin(); 
					i != event.memory_addresses.end(); ++i)
				{
					read(*i, event.memory_size);
				}	
			}
		}
		//report( "Default Trace: " << event.toString() );
	}

	void CacheSimulator::finish() 
	{
		_cache.clear();
		std::cout << "Miss Rate: " << (_missCount+0.0)/_memoryAccess << "\n";	
		std::cout << "Miss Latency: " << _missLatency<< "\n";
		std::cout << "Hit Latency: " << _hitLatency<< "\n";
		std::cout << "Total time for memory accesses: " << _time<< "\n";
		
		//a) Miss Rate (total_misses/total_accesses)
     //  b) Miss latency (total number of cycles servicing misses)
      // c) Hit latency (total number of cycles servicing hits)
	}

}

#endif

