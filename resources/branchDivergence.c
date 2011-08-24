{
    unsigned long threadId = blockThreadId();
    
    ON_INSTRUCTION:
    PREDICATED: 
    BRANCH:
    {
        SHARED_MEM: 
        {
            sharedMem[threadId] = getPredicateValue();
        }
        
        if(leastActiveThreadInWarp() != 0)
        {
            GLOBAL_MEM:
            {
                atomicIncrement(deviceMem, 0);
                unsigned long uniqueCount = uniqueElementCount(sharedMem);
                if(uniqueCount > 2)
                    atomicIncrement0(deviceMem, 1);                
            }
        }
    }
}
