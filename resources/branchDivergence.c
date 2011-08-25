{
    unsigned long threadId = blockThreadId();
    
    ON_INSTRUCTION:
    PREDICATED: 
    BRANCH:
    {
        sharedMem[threadId] = getPredicateValue();
        
        if(leastActiveThreadInWarp() != 0)
        {
            unsigned long uniqueCount = uniqueElementCount(sharedMem, 0);
            atomicIncrement(globalMem, 0);    
            if(uniqueCount > 1)
                atomicIncrement(globalMem, 1);      
            
        }
    }
}
