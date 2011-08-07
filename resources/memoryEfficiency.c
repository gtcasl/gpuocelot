{
    unsigned long threadId = globalThreadId();

    ON_INSTRUCTION:
    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    {
        SHARED_MEM: 
        {
            sharedMem[threadId] = computeBaseAddress();
        }
       
        uniqueElementCount(sharedMem); 
    }    
}
