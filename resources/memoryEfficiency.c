{
    unsigned long currentThreadId = globalThreadId();

    ON_INSTRUCTION:
    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    SHARED_MEM:
    {
        deviceMem[instructionCount() * instructionId() + currentThreadId] = computeMaskedAddress();
    }
    
    ON_KERNEL_EXIT: {
        computeUniqueMemoryTransactions();
    }
}
