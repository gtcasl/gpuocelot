{   
    unsigned long start;
    unsigned long stop;
    unsigned long warpId;

    start = clockCounter();
    syncThreads();
    
    warpId = (blockId() * blockDim() + blockThreadId()) >> 5;

    ON_INSTRUCTION:
    BRANCH:
    {
        
        if(leastActiveThreadInWarp())
        {
            globalMem[warpId * 2] = globalMem[warpId * 2] + divergentWarp();
            globalMem[warpId * 2 + 1] = globalMem[warpId * 2 + 1] + 1;   
        }
    }

    ON_KERNEL_EXIT:
    {
        syncThreads();
        stop = clockCounter();
        if (threadIndexX() == 0) {
            unsigned long currentBlockId = blockId();
            unsigned long currentWarpCount = 2 * warpCount();
            globalMem[currentBlockId * 2 + currentWarpCount] = stop - start;
            globalMem[currentBlockId * 2 + 1 + currentWarpCount] = smId();
            
        }
    }
}
