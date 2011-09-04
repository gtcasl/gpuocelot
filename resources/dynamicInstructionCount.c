{
    unsigned long totalThreadsPerBlock = blockDim();
    unsigned long currentThreadId = blockThreadId();
    unsigned long currentBlockId = blockId();
    
    ON_BASIC_BLOCK_EXIT:
    {
            unsigned long offset = basicBlockCount() * basicBlockId() + totalThreadsPerBlock * currentBlockId + currentThreadId;
            globalMem[offset] = globalMem[offset] + basicBlockExecutedInstructionCount();
    }
}
