{
    ON_INSTRUCTION:
    PREDICATE: 
    BRANCH:
    {
        unsigned long offset = warpCount() * instructionId() + warpId();
        deviceMem[offset] = predicateEvalWarpDivergent();
    }
}
