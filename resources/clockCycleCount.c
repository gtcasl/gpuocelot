{
    unsigned long start;
    unsigned long stop;
    ON_KERNEL_ENTRY:{
        start = clockCounter();
        syncThreads();
    }
    ON_KERNEL_EXIT:{
    syncThreads();
    stop = clockCounter();
        if (threadIndexX() == 0) {
            unsigned long currentBlockId = blockId();
            deviceMem[2 * currentBlockId] = stop - start;
            deviceMem[2 * currentBlockId + 1] = smId();
        }
    }
}
