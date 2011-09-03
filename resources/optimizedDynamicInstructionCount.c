{
    unsigned long warpId = (blockId() * blockDim() + blockThreadId())/32;
    
    unsigned long leastActive = leastActiveThreadInWarp();
    
    if(leastActive != 0)
    {
        unsigned long activeThreads = activeThreadCount();
    
        ON_BASIC_BLOCK_EXIT: {
            globalMem[warpId] = globalMem[warpId] + (basicBlockPredicatedInstructionCount() * activeThreads);
        }    
    }    
}

