{
    ON_BASIC_BLOCK_EXIT:
    {
        unsigned long instCount = basicBlockExecutedInstructionCount();

        if(leastActiveThreadInWarp() != 0)
        {
            unsigned long activeThreads = activeThreadCount();
            unsigned long dynInstCount = instCount * activeThreads;
            atomicAdd(globalMem, 0, dynInstCount);   
        }
    }    
}
