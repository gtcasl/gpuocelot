{
    unsigned long currentBlockDim = blockDim();
    unsigned long currentThreadId = globalThreadId();

    ON_BASIC_BLOCK_ENTRY:{
        unsigned long offset = currentBlockDim * basicBlockId() + currentThreadId;
        globalMem[offset] = globalMem[offset] + 1;
    }
}
