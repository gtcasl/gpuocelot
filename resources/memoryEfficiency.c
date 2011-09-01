{
    unsigned long threadId = blockThreadId();
    
    ON_INSTRUCTION:
    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    {

        sharedMem[threadId] = computeBaseAddress();

        if(leastActiveThreadInWarp() != 0)
        {
            unsigned long uniqueCount = uniqueElementCount(sharedMem, 1);
            globalMem[0] = globalMem[0] + uniqueCount;
            atomicIncrement(globalMem, 1);
        }
    }    
}
