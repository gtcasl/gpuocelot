{
    unsigned long start;
    unsigned long stop;
    unsigned long warpId;
    unsigned long threadId;
    
    start = clockCounter();
    syncThreads();

    threadId = blockThreadId();
    warpId = (blockId() * blockDim() + threadId) >> 5;
    
    ON_INSTRUCTION:
    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    {
        sharedMem[threadId] = computeBaseAddress();

        if(leastActiveThreadInWarp())
        {
            unsigned long uniqueCount = uniqueElementCount(sharedMem, 1);
            globalMem[warpId * 2] = globalMem[warpId * 2] + uniqueCount;
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
