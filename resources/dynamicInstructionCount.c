{
    unsigned long currentBlockDim = blockDim();
    unsigned long currentThreadId = globalThreadId();
    ON_BASIC_BLOCK_EXIT:
    {
            unsigned long offset = currentBlockDim * basicBlockId() + currentThreadId;
            globalMem[offset] = globalMem[offset] + basicBlockExecutedInstructionCount();
    }
}
