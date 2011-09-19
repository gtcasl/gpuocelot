{   
    unsigned long warpId = (blockId() * blockDim() + blockThreadId()) >> 5;

    ON_INSTRUCTION:
    BRANCH:
    {
        
        if(leastActiveThreadInWarp())
        {
            globalMem[warpId * 2] = globalMem[warpId * 2] + divergentWarp();
            globalMem[warpId * 2 + 1] = globalMem[warpId * 2 + 1] + 1;   
        }
    }
}
