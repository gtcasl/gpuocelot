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
                unsigned long uniqueCount = uniqueElementCount(sharedMem);
                atomicIncrement(deviceMem, 0);    
                if(uniqueCount > 1)
                    atomicIncrement(deviceMem, 1);      
            }
        }
    }
}
