{
    unsigned long warpId = (blockId() * blockDim() + blockThreadId())/32;
    
    ON_BASIC_BLOCK_EXIT:
    {
        if(leastActiveThreadInWarp() != 0)
        {   
            unsigned long instCount = basicBlockPredicatedInstructionCount() * activeThreadCount();
            globalMem[warpId] = globalMem[warpId] + instCount;
            
        }
    }    
}

