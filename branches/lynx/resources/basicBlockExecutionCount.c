{
    unsigned long currentBlockDim = blockDim();
    unsigned long currentThreadId = threadId();
    ENTER_BASIC_BLOCK:{
        unsigned long offset = currentBlockDim * basicBlockId() + currentThreadId;
        deviceMem[offset] = deviceMem[offset] + 1;
    }
}
