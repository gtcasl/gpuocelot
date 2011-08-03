{

    ON_INSTRUCTION:
    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    {
        deviceMem[instructionId()] = memoryTransactionCount();
    }
    
}
