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

unsigned long threadId() {
    return 0;
}

unsigned long threadIdxX() { 
    return 0; 
}

unsigned long threadIdxY() { 
    return 0; 
}

unsigned long threadIdxZ() { 
    return 0; 
}

unsigned long threadIdx() { 
    return 0; 
}

unsigned long blockIdxX() { 
    return 0; 
}

unsigned long blockIdxY() { 
    return 0; 
}

unsigned long blockIdxZ() { 
    return 0; 
}

unsigned long blockIdx() { 
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

unsigned long instructionsPerBasicBlock() {
    return 1;
}

#endif
