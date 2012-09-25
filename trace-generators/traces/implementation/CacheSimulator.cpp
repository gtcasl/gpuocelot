/*!
	\file CacheSimulator.cpp

	\author Sudnya Padalikar <sudnya.padalikar@gatech.edu>
	\date Sunday November 29, 2009
	\brief implementation of a CacheSimulator class to be the child of 
	TraceGenerator class for evaluating performance of various STL Containers.
*/

#ifndef TRACE_CACHESIMULATOR_CPP_INCLUDED
#define TRACE_CACHESIMULATOR_CPP_INCLUDED

#include <traces/interface/CacheSimulator.h>
#include <hydrazine/interface/debug.h>
#include <cmath>


#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace trace 
{

	CacheSimulator::CacheWay::CacheWay(ir::PTXU64 t, bool d) : dirty(d), tag(t)
	{
	
	}

	CacheSimulator::CacheEntry::CacheEntry(unsigned int a) : _associativity(a)
	{
	
	}
			
	bool CacheSimulator::CacheEntry::write(ir::PTXU64 tag, bool& writeback)
	{
		for(WayList::iterator way = _ways.begin();
			way != _ways.end(); ++way)
		{
			if(way->tag == tag)
			{
				_ways.erase(way);
				_ways.push_back(CacheWay(tag, true));
				writeback = false;
				return true;
			}
		}
		
		// miss
		if(_ways.size() == _associativity)
		{
			writeback = _ways.front().dirty;
			_ways.erase(_ways.begin());
		}
		
		_ways.push_back(CacheWay(tag, true));
		
		return false;
	}

	bool CacheSimulator::CacheEntry::read(ir::PTXU64 tag, bool& writeback)
	{
		for(WayList::iterator way = _ways.begin();
			way != _ways.end(); ++way)
		{
			if(way->tag == tag)
			{
				CacheWay newEntry(tag, way->dirty);
				_ways.erase(way);
				_ways.push_back(newEntry);
				writeback = false;
				return true;
			}
		}
		
		// miss
		if(_ways.size() == _associativity)
		{
			writeback = _ways.front().dirty;
			_ways.erase(_ways.begin());
		}
		
		_ways.push_back(CacheWay(tag, false));
		
		return false;
	}

	CacheSimulator::CacheSimulator() 
	{
		writebackTime = 50;
		cacheSize     = 8192;
		lineSize      = 64;
		hitTime       = 1;
		missTime      = 200;
		associativity = 1;
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
		_time         = 0;
		_missCount    = 0;
		_hitCount     = 0;
		_missLatency  = 0;
		_hitLatency   = 0;
		_memoryAccess = 0;

		unsigned int sets = cacheSize / (lineSize * associativity);

		_cache.resize(sets, CacheEntry(associativity));
		//report( "Initializing trace generator for kernel " << kernel->name );
	}

	void CacheSimulator::lookupEntry(int setNumber, int tag, bool accessType)
	{
		bool writeback = false;
		if(accessType)
		{
			if(!_cache[setNumber].write(tag, writeback))
			{
				++_missCount;
			
				_missLatency += missTime;
				_time        += missTime;
				
				if(writeback)
				{
					_time += writebackTime;
				}
			}
			else
			{
				++_hitCount;
				_hitLatency += hitTime;
				_time       += hitTime;
			}
		}
		else
		{
			if(!_cache[setNumber].read(tag, writeback))
			{
				++_missCount;
			
				_missLatency += missTime;
				_time        += missTime;
				
				if(writeback)
				{
					_time += writebackTime;
				}
			}
			else
			{
				++_hitCount;

				_hitLatency += hitTime;
				_time       += hitTime;
			}
		}
	}
	
	ir::PTXU64 CacheSimulator::getTag(ir::PTXU64 addressAccessed)
	{
		int shiftAmount = std::log2( cacheSize / (lineSize * associativity) ) 
			+ std::log2((lineSize * associativity)); 
		addressAccessed >>= shiftAmount;		
		return addressAccessed;
	}
	
	int CacheSimulator::findSet(ir::PTXU64 addressAccessed)
	{
		addressAccessed >>= (int)std::log2((lineSize * associativity));

		ir::PTXU64 mask = (cacheSize / (lineSize * associativity)) - 1;
		return addressAccessed & mask;
	}

	int CacheSimulator::getOffset(ir::PTXU64 addressAccessed)
	{
		ir::PTXU64 mask = (lineSize * associativity) - 1;
		return addressAccessed & mask;				
	}
	
		
	bool CacheSimulator::cachelineSplit(ir::PTXU64 addressAccessed, 
		ir::PTXU32 bytesAccessed)
	{
		unsigned int offset;
		offset = getOffset(addressAccessed);
		if(offset+bytesAccessed > (lineSize * associativity))
		{
			return true;
		}

		return false;
	}
	
	void CacheSimulator::read(ir::PTXU64 addressAccessed, 
		ir::PTXU32 bytesAccessed)
	{
		long long unsigned int tag;
		int setNumber;
		assertM(!cachelineSplit(addressAccessed, bytesAccessed), 
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
		assertM(!cachelineSplit(addressAccessed, bytesAccessed), 
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
		if(instructionMemory)
		{
			_memoryAccess+=4;
		
			read(event.PC*4, 4);
		}
		else
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
		}
		//report( "Default Trace: " << event.toString() );
	}

	void CacheSimulator::finish() 
	{
		_cache.clear();
		std::cout << "Miss Rate: " << (_missCount+0.0)/(_missCount + _hitCount) << "\n";	
		std::cout << "Miss Latency: " << _missLatency<< "\n";
		std::cout << "Hit Latency: " << _hitLatency<< "\n";
		std::cout << "Total time for memory accesses: " << _time<< "\n";
		
		//a) Miss Rate (total_misses/total_accesses)
     //  b) Miss latency (total number of cycles servicing misses)
      // c) Hit latency (total number of cycles servicing hits)
	}

}

#endif

