{
    ON_INSTRUCTION:
    PREDICATED: 
    BRANCH:
    {
        unsigned long offset = warpCount() * instructionId() + warpId();
        deviceMem[offset] = deviceMem[offset] + predicateEvalWarpDivergent();
    }
}
