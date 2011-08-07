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

unsigned long basicBlockId() {
    return 0;
}

unsigned long basicBlockInstructionCount() {
    return 1;
}

unsigned long basicBlockExecutedInstructionCount() {
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

unsigned long predicateEvalWarpUniform(){
    return 0;
}

unsigned long predicateEvalWarpDivergent(){
    return 0;
}

unsigned long memoryTransactionCount(){
    return 0;
}

void computeUniqueMemoryTransactions() {

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

unsigned long uniqueElementCount(unsigned long *memBuffer) {
    return 1;
}

#endif
