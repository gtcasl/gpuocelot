{
    unsigned long threadId = blockThreadId();
    unsigned long warpId = (blockId() * blockDim() + threadId)/32;
    unsigned long leastActive = leastActiveThreadInWarp();
    
    ON_INSTRUCTION:
    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    {

        sharedMem[threadId] = computeBaseAddress();

        if(leastActive != 0)
        {
            unsigned long uniqueCount = uniqueElementCount(sharedMem, 1);
            globalMem[warpId * 2] = globalMem[warpId * 2] + uniqueCount;
            globalMem[warpId * 2 + 1] = globalMem[warpId * 2 + 1] + 1;
        }
    }    
}
