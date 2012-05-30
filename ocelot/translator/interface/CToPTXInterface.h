/*! \file CToPTXInterface.h
	\date Friday July 8, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the CToPTXInterface class
*/

#ifndef C_TO_PTX_INTERFACE_H_INCLUDED
#define C_TO_PTX_INTERFACE_H_INCLUDED

/* device memory construct */
#define NUM_THREADS 1
#define NUM_BLOCKS  1
#define NUM_GRIDS   1

unsigned long globalMem[NUM_THREADS * NUM_BLOCKS * NUM_GRIDS];
unsigned long sharedMem[NUM_THREADS * NUM_BLOCKS * NUM_GRIDS];

/* corresponds to PTX register clock/clock64 */
unsigned long clockCounter();

/* Utility API that returns the thread identifier as a single scalar value. 
    Calculated as follows:
    
    threadIdx = threadIdxX + threadIdxY * blockDimX + threadIdxZ * blockDimX * blockDimY
    blockDim = blockDimX * blockDimY * blockDimZ
    threadId = (blockIdxX + blockIdxY * gridDimX) * blockDim + threadIdx
*/
unsigned long globalThreadId();

/* corresponds to PTX register tid */
unsigned long threadIndexX();
unsigned long threadIndexY();
unsigned long threadIndexZ();

/* threadIdx = threadIdxX + threadIdxY * blockDimX + threadIdxZ * blockDimX * blockDimY */
unsigned long blockThreadId();

/* corresponds to PTX register ctaid */
unsigned long blockIndexX();
unsigned long blockIndexY();
unsigned long blockIndexZ();

/* blockIdx = blockIdxX + blockIdxY * gridDimX */
unsigned long blockId();

/* corresponds to PTX register ntid */
unsigned long blockDimX();
unsigned long blockDimY();
unsigned long blockDimZ();

/* blockDim = blockDimX * blockDimY * blockDimZ */
unsigned long blockDim();

/* corresponds to PTX register nctaid */
unsigned long gridDimX();
unsigned long gridDimY();
unsigned long gridDimZ();

/* gridDim = gridDimX * gridDimY * gridDimZ */
unsigned long gridDim();

/* corresponds to PTX register gridId */
unsigned long gridId();

/* corresponds to PTX register smid */
unsigned long smId();

void syncThreads();

unsigned long basicBlockCount();

unsigned long basicBlockId();

unsigned long basicBlockInstructionCount();

/*  Only instructions that are actually executed will be counted. 
    Instructions that are predicated and the predicate is false
    will be ignored 
*/

unsigned long basicBlockExecutedInstructionCount();

unsigned long basicBlockPredicatedInstructionCount();

unsigned long instructionId();

unsigned long warpCount();

unsigned long warpId();

unsigned long getPredicateValue();

unsigned long instructionCount();

unsigned long computeBaseAddress();

unsigned long leastActiveThreadInWarp();

unsigned long activeThreadCount();

unsigned long uniqueElementCount(unsigned long *memBuffer, unsigned long overHalfWarp);

unsigned long activeThreadSum(unsigned long *memBuffer);

void atomicIncrement(unsigned long *memBuffer, unsigned long offset);

void atomicAdd(unsigned long *memBuffer, unsigned long offset, unsigned long toAdd);

unsigned long divergentWarp();

#endif
