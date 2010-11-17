/*!
	\file CacheSimulator.h

	\author Sudnya Padalikar <sudnya.padalikar@gatech.edu>
			Gregory Diamos <gregory.diamos@gatech.edu>
	\date Sunday November 29, 2009
			November 11, 2010
	\brief declares a CacheSimulator class to be the child of TraceGenerator 
		class for evaluating performance of various STL Containers.
*/

#ifndef TRACE_CACHESIMULATOR_H_INCLUDED
#define TRACE_CACHESIMULATOR_H_INCLUDED

#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>

#include <vector>

namespace trace 
{
	class CacheSimulator : public TraceGenerator 
	{
		public:
			CacheSimulator();
			~CacheSimulator();

			/*!
				\brief called when a traced kernel is launched to retrieve some 
					parameters from the kernel
			*/
			void initialize(const executive::ExecutableKernel& kernel);

			/*!
				\brief Called whenever an event takes place.

				Note, the const reference 'event' is only valid until event() 
				returns
			*/
			void event(const TraceEvent& event);
		
			/*! 
				\brief Called when a kernel is finished. There will be no more 
					events for this kernel.
			*/
			void finish();

			unsigned int writebackTime;
			unsigned int cacheSize;
			unsigned int lineSize;
			unsigned int hitTime;
			unsigned int missTime;
			unsigned int associativity;
			bool         instructionMemory;

		private:
			class CacheWay
			{
				public:
					bool dirty;
					ir::PTXU64 tag;

				public:
					CacheWay(ir::PTXU64 tag, bool dirty);
			};

			typedef std::vector<CacheWay> WayList;

			class CacheEntry
			{
				public:
					CacheEntry(unsigned int associativity = 0);
					
					bool write(ir::PTXU64 tag, bool& writeback);
					bool read(ir::PTXU64 tag, bool& writeback);

				private:
					WayList      _ways;
					unsigned int _associativity;
			};
			
			typedef std::vector<CacheEntry> CacheContainer;

		private:
			CacheContainer _cache;
			
			void lookupEntry(int setNumber, int tag, bool);
			ir::PTXU64 getTag(ir::PTXU64 addressAccessed);
			int findSet(ir::PTXU64 addressAccessed);
			int getOffset(ir::PTXU64 addressAccessed);
			bool cachelineSplit(ir::PTXU64 addressAccessed, 
				ir::PTXU32 bytesAccessed);
			void read(ir::PTXU64 addressAccessed, ir::PTXU32 bytesAccessed);
			void write(ir::PTXU64 addressAccessed, ir::PTXU32 bytesAccessed);
		
			ir::PTXU64 _time;
			ir::PTXU64 _missCount;
			ir::PTXU64 _hitCount;
			ir::PTXU64 _missLatency;
			ir::PTXU64 _hitLatency;
			ir::PTXU64 _memoryAccess;
			
	};
	
}

#endif

