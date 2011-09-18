{
    unsigned long start;
    unsigned long stop;
    unsigned long warpId;
    
    start = clockCounter();
    syncThreads();

    warpId = (blockId() * blockDim() + blockThreadId()) >> 5;
    
    ON_BASIC_BLOCK_EXIT:
    {
        if(leastActiveThreadInWarp())
        {
            globalMem[warpId] = globalMem[warpId] + 
                (basicBlockPredicatedInstructionCount() * activeThreadCount());
        }
    
    }
    
    ON_KERNEL_EXIT:
        {
            syncThreads();
            stop = clockCounter();
            if (threadIndexX() == 0) {
                unsigned long currentBlockId = blockId();
                unsigned long currentWarpCount = warpCount();
                globalMem[currentBlockId * 2 + currentWarpCount] = stop - start;
                globalMem[currentBlockId * 2 + 1 + currentWarpCount] = smId();
                
            }
        }
    
}

