{
    ON_INSTRUCTION:
    PREDICATE: 
    {
        unsigned long offset = warpCount() * instructionId() + warpId();
        deviceMem[offset] = predicateEvalWarpDivergent();
    }
}
