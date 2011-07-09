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

unsigned long numThreadsPerBlock() {
    return 1;
}

unsigned long threadId() {
    return 0;
}

unsigned long threadIdx() { 
    return 0; 
}

unsigned long threadIdy() { 
    return 0; 
}

unsigned long threadIdz() { 
    return 0; 
}

unsigned long blockId() { 
    return 0; 
}

unsigned long blockIdx() { 
    return 0; 
}

unsigned long blockIdy() { 
    return 0; 
}

unsigned long blockIdz() { 
    return 0; 
}

unsigned long smId() { 
    return 0; 
}

void syncThreads() {
}

#endif
