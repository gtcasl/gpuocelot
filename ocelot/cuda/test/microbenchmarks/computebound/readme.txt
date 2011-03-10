Code Scheduling Discards Instruction-Level Parallelism

Andrew Kerr <arkerr@gatech.edu>
November 5, 2010

I. Introduction

I've noticed an unusual behavior of the LLVM x86 code generator (with default options)
that results in nearly a 4x slow-down in floating-point throughput for my microbenchmark.

I've written a compute-intensive microbenchmark to approach theoretical peak
throughput of the target processor by issuing a large number of independent
floating-point multiplies. The distance between dependent instructions is at
least four instructions to match the latency of the floating-point functional
unit in my Intel Core2 Quad (Q9550 at 2.83 GHz).

II.

The attached microbenchmark can be built with both gcc and clang using the following
command:

$ make run

gcc
# blocks   GFLOPs/second
1          5.648591
2          5.650618
3          5.650704
4          5.649433

llvm
# blocks   GFLOPs/second
1          0.857245
2          0.857162
3          0.857154
4          0.857187
$

This prints performance results for several runs. On my Intel Q9550, I see

Additionally, assembly files are produced by both compilers which reveal the problem
in code scheduling.

III.

The microbenchmark itself replicates the following block 512 times:

 .
 .
 {
  p1 = p1 * a;
  p2 = p2 * b;
  p3 = p3 * c;
  p4 = p4 * d;
 }
 .
 .

Compiling with NVCC, Ocelot, and LLVM, I can confirm the interleaved instruction
schedule with a four-instruction reuse distance. An excerpt follows:

  .
  .
  %r1500 = fmul float %r1496, %r24  ; compute %1500
  %r1501 = fmul float %r1497, %r23
  %r1502 = fmul float %r1498, %r22
  %r1503 = fmul float %r1499, %r21

  %r1504 = fmul float %r1500, %r24  ; first use of %1500
  %r1505 = fmul float %r1501, %r23
  %r1506 = fmul float %r1502, %r22
  %r1507 = fmul float %r1503, %r21

  %r1508 = fmul float %r1504, %r24  ; first use of %1504
  .
  .

The JIT compiler, however, seems to break the interleaving of independent instructions
and issues a long sequence of instructions with back-to-back dependencies. It is as if
all p1 = .. expressions are collected at once followed by all p2 = .. expressions and so
forth.

 p1 = p1 * a
 p1 = p1 * a
 .
 .

 p2 = p2 * b
 p2 = p2 * b
 .
 .

 p3 = p3 * c
 p3 = p3 * c
 .
 .

An actual excerpt of the generated x86 assembly follows:

  mulss        %xmm8, %xmm10
  mulss        %xmm8, %xmm10
  .
  . repeated 512 times
  .

  mulss        %xmm7, %xmm9
  mulss        %xmm7, %xmm9
  .
  . repeated 512 times
  .
  
  mulss        %xmm6, %xmm3
  mulss        %xmm6, %xmm3
  .
  . repeated 512 times
  .

Since p1, p2, p3, and p4 are all independent, this reordering is correct. This would have
the possible advantage of reducing live ranges of values. However, in this microbenchmark,
the number of live values is eight single-precision floats - well within SSE's sixteen
architectural registers.

Moreover, the pipeline latency is four cycles meaning back-to-back instructions with true
dependencies cannot issue immediately. The benchmark was intentionally written to avoid this
hazard but LLVM's code generator seems to ignore that when it schedules instructions.

When I run this benchmark on my 2.83 GHz CPU, I observe the following performance results:

  1 threads       0.648891 GFLOP/s
  2 threads       1.489049 GFLOP/s
  3 threads       2.209838 GFLOP/s
  4 threads       2.940443 GFLOP/s

When I rewrite the generated assembly by hand to exhibit the same interleaving as in the
LLVM IR form
  
  .
  .
  mulss        %xmm8, %xmm10
  mulss        %xmm7, %xmm9
  mulss        %xmm6, %xmm3
  mulss        %xmm5, %xmm11

  mulss        %xmm8, %xmm10
  mulss        %xmm7, %xmm9
  mulss        %xmm6, %xmm3
  mulss        %xmm5, %xmm11

  mulss        %xmm8, %xmm10
  mulss        %xmm7, %xmm9
  .
  .

observed performance increases by nearly a factor of four:

  1 threads       2.067118 GFLOP/s
  2 threads       5.569419 GFLOP/s
  3 threads       8.285519 GFLOP/s
  4 threads       10.81742 GFLOP/s

I show similar results with packed single-precision floating point SIMD instructions. The
LLVM-generated machine code is nearly 4x slower than the interleaved schedule 'suggested' by
the LLVM IR input.

  Vectorized - No instruction interleaving - back-to-back dependencies
    (issued by LLVM code generator)

  1 threads        1.540621 GFLOP/s
  2 threads        5.900833 GFLOP/s
  3 threads        8.755953 GFLOP/s
  4 threads        11.257122 GFLOP/s

  Vectorized - Interleaved - stride-4 reuse distance
    (hand-modified to interleave instructions)

  1 threads       3.157255 GFLOP/s
  2 threads       22.104369 GFLOP/s
  3 threads       32.300111 GFLOP/s
  4 threads       39.112162 GFLOP/s

It is worth noting that 39.1 GFLOP/s is approaching the theoretical limits of the processor
(stated to be 45.25 GFLOP/s single-precision).

I've used the llc utility to test various pre-register-allocation instruction schedulers
with the following results:

  -pre-RA-sched
    =default         - discards ILP
    =list-burr       - discards ILP
    =list-tdrr       - crashes during code generation

    =source          - preserves interleaved instruction ordering and ILP

    =list-hybrid     - discards ILP
    =list-ilp        - discards ILP
    =list-td         - crashes during code generation
    =fast            - discards ILP


