/*! \file CToPTXInterface.h
	\date Friday July 8, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the CToPTXInterface class
*/

#ifndef C_TO_PTX_INTERFACE_H_INCLUDED
#define C_TO_PTX_INTERFACE_H_INCLUDED

#define NUM_THREADS 1
#define NUM_BLOCKS  1
#define NUM_GRIDS   1

unsigned long deviceMem[NUM_THREADS * NUM_BLOCKS * NUM_GRIDS];

unsigned long clockCounter();
unsigned long numThreadsPerBlock();
unsigned long threadId();
unsigned long threadIdx();
unsigned long threadIdy();
unsigned long threadIdz();
unsigned long blockId();
unsigned long blockIdx();
unsigned long blockIdy();
unsigned long blockIdz();
unsigned long smId();
void syncThreads();

#endif
