{
    unsigned long threadId = globalThreadId();
    unsigned long sharedMemSize = gridDim() * blockDim();

    MEM_READ:
    MEM_WRITE:
    GLOBAL:
    {
        ON_INSTRUCTION:
        {
            SHARED_MEM: 
            {
                sharedMem[instructionId() * sharedMemSize + threadId] = computeBaseAddress();
            }
        }

        ON_KERNEL_EXIT:
        {
        
            if(leastActiveThreadInWarp())
            {
                int i = 0;
                for(; i < instructionCount(); i++)
                {
                    unsigned long startIndex = i * sharedMemSize;
                    
                        GLOBAL_MEM:
                        {
                            deviceMem[i] = uniqueElementCount(sharedMem, startIndex, sharedMemSize);
                        }
                }        
            }
        }
    }    
}
