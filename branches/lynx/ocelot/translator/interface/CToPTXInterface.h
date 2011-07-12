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

unsigned long deviceMem[NUM_THREADS * NUM_BLOCKS * NUM_GRIDS];

/* corresponds to PTX register clock/clock64 */
unsigned long clockCounter();

/* Utility API that returns the thread identifier as a single scalar value. 
    Calculated as follows:
    
    threadIdx = threadIdxX + threadIdxY * blockDimX + threadIdxZ * blockDimX * blockDimY
    blockDim = blockDimX * blockDimY * blockDimZ
    threadId = (blockIdxX + blockIdxY * gridDimX) * blockDim + threadIdx
*/
unsigned long threadId();

/* corresponds to PTX register tid */
unsigned long threadIdxX();
unsigned long threadIdxY();
unsigned long threadIdxZ();

/* threadIdx = threadIdxX + threadIdxY * blockDimX + threadIdxZ * blockDimX * blockDimY */
unsigned long threadIdx();

/* corresponds to PTX register ctaid */
unsigned long blockIdxX();
unsigned long blockIdxY();
unsigned long blockIdxZ();

/* blockIdx = blockIdxX + blockIdxY * gridDimX */
unsigned long blockIdx();

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

unsigned long basicBlockId();
unsigned long instructionsPerBasicBlock();


#endif
