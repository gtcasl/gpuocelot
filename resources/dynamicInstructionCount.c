{
    unsigned long totalThreadsPerBlock = blockDim();
    unsigned long currentThreadId = blockThreadId();
    ON_BASIC_BLOCK_EXIT:
    {
            unsigned long offset = basicBlockCount() * basicBlockId() + totalThreadsPerBlock * blockId() + currentThreadId;
            globalMem[offset] = globalMem[offset] + basicBlockExecutedInstructionCount();
    }
}
