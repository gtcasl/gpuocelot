/*!
	\file CacheSimulator.h

	\author Sudnya Padalikar <sudnya.padalikar@gatech.edu>
	\date Sunday November 29, 2009
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
			void event(const TraceEvent & event);
		
			/*! 
				\brief Called when a kernel is finished. There will be no more 
					events for this kernel.
			*/
			void finish();

			unsigned int writebackTime;
			unsigned int addressWidth;
			unsigned int cacheSize;
			unsigned int lineSize;
			unsigned int hitTime;
			unsigned int missTime;
			unsigned int ways;

		private:
			class CacheEntry
			{
				public:
					bool valid;
					bool dirty;
					long long int tag;
			};
			
		private:
			typedef std::vector< CacheEntry > CacheContainer;
//			typedef std::map< int, CacheEntry > CacheContainer;

			CacheContainer _cache;			
			
			void lookupEntry(int setNumber, int tag, bool);
			long long unsigned int getTag(ir::PTXU64 addressAccessed);
			int findSet(ir::PTXU64 addressAccessed);
			int getOffset(ir::PTXU64 addressAccessed);
			bool cachelineSplit(ir::PTXU64 addressAccessed, 
				ir::PTXU32 bytesAccessed);
			void read(ir::PTXU64 addressAccessed, ir::PTXU32 bytesAccessed);
			void write(ir::PTXU64 addressAccessed, ir::PTXU32 bytesAccessed);
		
			
			long long int _time;
			long long int _missCount;
			long long int _hitCount;
			long long int _missLatency;
			long long int _hitLatency;
			long long int _memoryAccess;
			
	};
	
}

#endif

