{
    unsigned long threadId = blockThreadId();
    
    ON_INSTRUCTION:
    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    {
        SHARED_MEM: 
        {
            sharedMem[threadId] = computeBaseAddress();
        }
        
        if(leastActiveThreadInWarp() != 0)
        {
            GLOBAL_MEM:
            {
                unsigned long uniqueCount = uniqueElementCount(sharedMem, 1);
                atomicAdd(deviceMem, 0, uniqueCount);   
                atomicIncrement(deviceMem, 1);
            }
        }
    }    
}
