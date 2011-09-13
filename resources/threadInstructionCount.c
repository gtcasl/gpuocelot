{
    unsigned long start;
    unsigned long stop;
    unsigned long currentBlockDim;
    unsigned long currentThreadId;
    unsigned long currentBlockId;
    
    start = clockCounter();
    syncThreads();    
    

    currentBlockDim = blockDim();
    currentThreadId = blockThreadId();
    currentBlockId = blockId();
        
    ON_BASIC_BLOCK_EXIT:
    {
            unsigned long offset = basicBlockCount() * basicBlockId() + currentBlockDim * currentBlockId + currentThreadId;
            globalMem[offset] = globalMem[offset] + basicBlockExecutedInstructionCount();
    }

    
   
    ON_KERNEL_EXIT:
    {
        syncThreads();
        stop = clockCounter();
        if (threadIndexX() == 0) {
            unsigned long total = basicBlockCount() * gridDim() * currentBlockDim;
            globalMem[currentBlockId * 2 + total] = stop - start;
            globalMem[currentBlockId * 2 + 1 + total] = smId();
            
        }
    }
}
