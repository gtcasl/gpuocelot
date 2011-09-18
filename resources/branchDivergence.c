{   
    unsigned long warpId = (blockId() * blockDim() + blockThreadId()) >> 5;

    ON_INSTRUCTION:
    PREDICATED:
    BRANCH:
    {
        
        if(leastActiveThreadInWarp())
        {
            globalMem[warpId * 2 + 1] = globalMem[warpId * 2 + 1] + activeThreadCount();
            globalMem[warpId * 2] = globalMem[warpId * 2] + divergentThreadCount();
            
        }
    }
}
