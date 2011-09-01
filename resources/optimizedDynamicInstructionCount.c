{
    ON_BASIC_BLOCK_EXIT:
    {
        if(leastActiveThreadInWarp() != 0)
        {   
            unsigned long dynInstCount = basicBlockPredicatedInstructionCount() * activeThreadCount();
            atomicAdd(globalMem, 0, dynInstCount);  
        }
    }    
}
