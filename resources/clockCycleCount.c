{
    unsigned long start;
    unsigned long stop;
    ENTER_KERNEL:{
        start = clockCounter();
        syncThreads();
    }
    EXIT_KERNEL:{
    syncThreads();
    stop = clockCounter();
        if (threadIdxX() == 0) {
            unsigned long currentBlockIdx = blockIdx();
            deviceMem[2 * currentBlockIdx] = stop - start;
            deviceMem[2 * currentBlockIdx + 1] = smId();
        }
    }
}
