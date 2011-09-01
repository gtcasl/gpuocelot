{
    unsigned long totalThreads = blockDim() * gridDim();
    unsigned long currentThreadId = globalThreadId();
    ON_BASIC_BLOCK_EXIT:
    {
            unsigned long offset = totalThreads * basicBlockId() + currentThreadId;
            atomicAdd(globalMem, offset, basicBlockExecutedInstructionCount());
    }
}
