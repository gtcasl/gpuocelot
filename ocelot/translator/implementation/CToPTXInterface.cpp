/*! \file CToPTXInterface.cpp
	\date Friday July 8, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the CToPTXInterface class
*/

#ifndef C_TO_PTX_INTERFACE_CPP_INCLUDED
#define C_TO_PTX_INTERFACE_CPP_INCLUDED

unsigned long clockCounter() { 
    return 1; 
}

unsigned long globalThreadId() {
    return 0;
}

unsigned long threadIndexX() { 
    return 0; 
}

unsigned long threadIndexY() { 
    return 0; 
}

unsigned long threadIndexZ() { 
    return 0; 
}

unsigned long blockThreadId() { 
    return 0; 
}

unsigned long blockIndexX() { 
    return 0; 
}

unsigned long blockIndexY() { 
    return 0; 
}

unsigned long blockIndexZ() { 
    return 0; 
}

unsigned long blockId() { 
    return 0; 
}

unsigned long blockDimX() {
    return 0;
}

unsigned long blockDimY() {
    return 0;
}

unsigned long blockDimZ() {
    return 0;
}

unsigned long blockDim() {
    return 0;
}

unsigned long gridDimX() {
    return 0;
}

unsigned long gridDimY() {
    return 0;
}

unsigned long gridDimZ() {
    return 0;
}

unsigned long gridDim() {
    return 0;
}

unsigned long gridId() {
    return 0;
}

unsigned long smId() { 
    return 0; 
}

void syncThreads() {
}

unsigned long basicBlockCount() {
    return 1;
}

unsigned long basicBlockId() {
    return 0;
}

unsigned long basicBlockInstructionCount() {
    return 1;
}

unsigned long basicBlockExecutedInstructionCount() {
    return 1;
}

unsigned long basicBlockPredicatedInstructionCount() {
    return 1;
}

unsigned long instructionId() {
    return 0;
}

unsigned long warpCount() {
    return 1;
}

unsigned long warpId() {
    return 0;
}

unsigned long getPredicateValue(){
    return 0;
}

unsigned long instructionCount() {
    return 1;
}

unsigned long computeBaseAddress() {
    return 0;
}

unsigned long leastActiveThreadInWarp() {
    return 1;
}

unsigned long uniqueElementCount(unsigned long *memBuffer, unsigned long overHalfWarp) {
    return 1;
}

unsigned long activeThreadSum(unsigned long *memBuffer) {
    return 1;
}

unsigned long activeThreadCount() {
    return 1;
}

void atomicIncrement(unsigned long *memBuffer, unsigned long offset) {
    return;
}

void atomicAdd(unsigned long *memBuffer, unsigned long offset, unsigned long toAdd) {
    return;
}

unsigned long divergentWarp() {
    return 0;
}

#endif
