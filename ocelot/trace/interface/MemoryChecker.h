/*! \file MemoryChecker.h
	\date Wednesday March 17, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the MemoryChecker class.
*/

#ifndef MEMORY_CHECKER_H_INCLUDED
#define MEMORY_CHECKER_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/trace/interface/TraceGenerator.h>
#include <iostream>
#include <sstream>
#include <set>
#include <unordered_map>

namespace executive
{
	class Device;
	class EmulatedKernel;
}

namespace trace
{
	/*! \brief A trace generator for checking all memory accesses */
	class MemoryChecker : public TraceGenerator
	{
		public:

			class RelEvent
			{
				public:
					RelEvent(size_t pc, size_t t, bool r, uint64_t m) :
						PC(pc), 
						time(t),
						read(r),
						ace(false),
						paMask(m)
					{}
				public:
					size_t PC;
					size_t time;
					bool read;	//is this a read or write?
					bool ace;
					uint64_t paMask;
			};

			class DynInst
			{
				public:
					DynInst(std::string op, size_t pc, size_t t) :
						opcode(op), 
						PC(pc),  
						time(t),
				 		ace(false),
						init(false)
					{ opcode.append(1,'\0'); }
				public:
					class ProgramPoint //wrapper for relEvent on a particular register
					{
						public:
							ProgramPoint(size_t r, DynInst* l, RelEvent* ra) : 
								reg(r), 
								dynInstPtr(l), 
								relEvent(ra)
							{}
						public:
							size_t reg;
							DynInst* dynInstPtr;
							RelEvent* relEvent; 
					};
					std::vector<ProgramPoint*> write, read;
					std::string opcode;
					size_t PC;
					size_t time;
					bool ace;
					bool init;	//for use in DefUseChain.regFile
			};

			class DefUseChain
			{
				public:
					int check(DynInst * l, std::set<DynInst*> &chain); //check to find ace links in chain
					void mark(DynInst *, uint64_t m);	//traverses ace chain backwards, marking all links as ace
					void count(DynInst *);	//traverses ace chain backwards, marking all links as ace
					void print(DynInst * link);
#if 1
					~DefUseChain()
					{
						for ( auto& link : chain)
							delete link;
					}
#endif
				public:
					std::vector <DynInst*> regFileInst;	//latest DynInst on each register
					static std::vector <DynInst*> sharedMemInst;	//latest DynInst on each shared mem location byte size granularity
					std::vector <DynInst*> chain;	//manages all links
					std::vector <DynInst*> ace;	//all links directly responsible for global store
			};


			//live range tracker, per register
			class Util
			{
				public:
					Util():
						lastRead(0), 
						lrPC(0), 
						lastWritten(0), 
						lwPC(0), 
						utilization(0), 
						readCount(0), 
						writeCount(0),
						sizeInBits(-1)
				{
					it = begin(trace);
				}
					~Util()
					{
						for( auto &actions : relEventList)
						{
							delete actions;
						}
						relEventList.clear();
						trace.clear();
						tracePC.clear();
					}
				public:
					size_t lastRead;
					size_t lrPC;
					size_t lastWritten;
					size_t lwPC;
					size_t utilization;
					size_t readCount, writeCount;
					uint64_t paMask;
					int sizeInBits;
					//tracks each bit, 1 = potentially ace
					std::vector<RelEvent*> relEventList; 			//chronological list of events (reads, writes)
					std::vector<std::pair<size_t, size_t> > trace; //begin, end time point of utilization
					std::vector<std::pair<size_t, size_t> > tracePC; //begin, end time point of utilization
					std::vector<std::pair<size_t, size_t> >::const_iterator it, itPC;
			};

			/*! \brief Per CTA reliability structures*/
			class RelStructures
			{
				public:
					std::vector <std::vector <Util> > regFile;  //[threads][reg]
					static std::vector <Util> sharedMemory;
					static std::vector <Util> globalMemory;
			};


			size_t time();
			void incTime();

			/*! \brief A class for a cached memory allocation */
			class Allocation
			{
				public:
					bool valid; // is this a valid allocation?
					ir::PTXU64 base; // base allocation pointer
					ir::PTXU64 extent; // size of the allocation
			
				public:
					Allocation(bool valid = false, 
						ir::PTXU64 base = 0, ir::PTXU64 extent = 0);
			};

			enum Status {
				INVALID,
				NOT_DEFINED,
				PARTIALLY_DEFINED,
				DEFINED
			};

			class ShadowMemory
			{
			    public:
        			/*! \brief Distinguished Secondary Mapping for shadow memory */
        			std::vector <Status> map;

			    public:
			        ShadowMemory();

			        void resize(unsigned int size);

			        unsigned int size();

					/*! \brief Check if region is initialized */
			        Status checkRegion(unsigned int idx, unsigned int size);
				
					/*! \brief Set initialization status of a region */
					void setRegion(unsigned int idx, unsigned int size, Status stat);

					/*! \brief Check if region is initialized */
					Status checkRegister(ir::PTXOperand::RegisterType idx);

					/*! \brief Set initialization status of a register */
					void setRegister(ir::PTXOperand::RegisterType idx, Status stat);
					    
			};
			
		private:
			/*! \brief The block dimensions */
			ir::Dim3 _dim;
			ir::Dim3 _grid;
		
			/*! \brief The last allocation referenced */
			Allocation _cache;
			
			/*! \brief Parameter memory allocation */
			Allocation _parameter;
			
			/*! \brief Shared memory allocation */
			Allocation _shared;
			
			/*! \brief Local memory allocation */
			Allocation _local;
			
			/*! \brief Global local memory allocation */
			Allocation _globalLocal;
			
			/*! \brief Constant memory allocation */
			Allocation _constant;
			
			/*! \brief A pointer to the executive class */
			const executive::Device* _device;
		
			/*! \brief A pointer to the executable kernel */
			const executive::EmulatedKernel* _kernel;

			/*! \brief Flag to toggle initialization checks */
			bool checkInitialization;

			/*! \brief Shadow maps for checking uninitialized memory */
			ShadowMemory _globalShadow;		

			ShadowMemory _sharedShadow;	

			ShadowMemory _constShadow;

			ShadowMemory _localShadow;
		
			ShadowMemory _registerFileShadow;

			//std::vector<RelStructures> relStructures;
			RelStructures relStructures;
			std::vector<DefUseChain> duChain;

			bool checkPVF;
			size_t _time;
			
			struct Masks{
							uint64_t a,b,c,d;
							Masks() : a(-1), b(-1), c(-1), d(-1) {}
						};
		private:
			/*! \brief Check the alignment of a memory access */
			void _checkAlignment(const TraceEvent& e);
			
			/*! \brief Check whether or not the access falls within 
				an allocated region */
			void _checkValidity(const TraceEvent& e);
			
			/*! \brief Check for an uninitialized memory access */
			void _checkInitialized(const TraceEvent& e);

			/*! \brief Track initialization status of registers */
			void _checkInstructions(const TraceEvent& e);

			/*! \brief Track register-to-register status and control redirect */
			Status checkInstruction(const TraceEvent& e,
				bool useMemoryFlag=false, ShadowMemory *shadowMem=NULL);
		
			/*! \brief track pvf values in register, memory space */
			void _checkPVF(const TraceEvent & e);	

			void setMask( const TraceEvent& e,
					unsigned int thread, Masks &ms);

			void finishPVFAnalysis(const unsigned int cta, unsigned int lastCTA);
			uint64_t getInitMask(ir::PTXOperand::DataType type);

			/*! \brief print to file the boundaries of live ranges in PC 
			  	threshold is the duration cut off 
			*/
			void printLiveRangePC(int threshold);
			
			void pvfRegFileHistogram();

			void checkMismatchedLinks();
			/*! \brief print to file the durations of live ranges in instructions
			  	threshold is the duration cut off 
			*/
			void printLiveRangeDuration(size_t threshold);
			
			/*! \brief compute PVF and return the average PVF
			 *
			 */
			size_t computePVF();

			void pvfRegFile();
			/*! \brief get value from register
			 *
			 */
			uint64_t getRegister(ir::PTXOperand::DataType type, int thread, int reg,
					const TraceEvent& e);

			int getOperandSize(ir::PTXOperand::DataType type);

		public:
			/*! \brief The constructor initializes the cached allocations */
			MemoryChecker();

			/*! \brief Set initialization checking toggle */
			void setCheckInitialization(bool toggle);
			
			/*! \brief Set the cache and get a pointer to the memory mappings */
			virtual void initialize(const executive::ExecutableKernel& kernel);

			/*! \brief Called whenever an event takes place.

				Note, the const reference 'event' is only valid until event() 
				returns
			*/
			virtual void event(const TraceEvent& event);
			
			virtual void postEvent(const TraceEvent& event);

			/*!  \brief Called when a kernel is finished. There will be no more 
					events for this kernel.
			*/
			virtual void finish();
		
	};
}

#endif

