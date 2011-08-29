{
    unsigned long threadId = blockThreadId();
    
    ON_BASIC_BLOCK_EXIT:
    {
        sharedMem[threadId] = basicBlockExecutedInstructionCount();

        if(leastActiveThreadInWarp() != 0)
        {
            unsigned long sum = activeThreadSum(sharedMem);
            atomicAdd(globalMem, 0, sum);   
        }
    }    
}
