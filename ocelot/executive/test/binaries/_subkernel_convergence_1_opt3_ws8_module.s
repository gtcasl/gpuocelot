	.file	"_subkernel_convergence_1_opt3_ws8_module.bc"
	.section	.rodata.cst4,"aM",@progbits,4
	.align	4
.LCPI0_0:
	.long	1065353216              # float 1.000000e+00
                                        #  (0x3f800000)

	.section	.rodata,"a",@progbits
	.align	32
.LCPI1_0:
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.text
	.globl	_subkernel_convergence_1_opt3_ws8
	.align	16, 0x90
	.type	_subkernel_convergence_1_opt3_ws8,@function
_subkernel_convergence_1_opt3_ws8:      # @_subkernel_convergence_1_opt3_ws8
# BB#0:                                 # %exit
	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	movslq	(%rdi), %rax
	vmovd	%eax, %xmm0
	vpinsrd	$1, 112(%rdi), %xmm0, %xmm0
	vpinsrd	$2, 224(%rdi), %xmm0, %xmm0
	vpinsrd	$3, 336(%rdi), %xmm0, %xmm0
	vmovd	448(%rdi), %xmm1
	vpinsrd	$1, 560(%rdi), %xmm1, %xmm1
	vpinsrd	$2, 672(%rdi), %xmm1, %xmm1
	vpinsrd	$3, 784(%rdi), %xmm1, %xmm1
	movq	832(%rdi), %r8
	movq	720(%rdi), %r9
	movq	608(%rdi), %r10
	movq	496(%rdi), %r11
	movq	384(%rdi), %rdx
	movq	272(%rdi), %rsi
	movq	160(%rdi), %rcx
	movq	48(%rdi), %rbx
	movq	80(%rdi), %rdi
	vinsertf128	$1, %xmm1, %ymm0, %ymm0
	movq	(%rdi), %rdi
	vcvtdq2ps	%ymm0, %ymm0
	vaddps	%ymm0, %ymm0, %ymm0
	vaddps	.LCPI1_0(%rip), %ymm0, %ymm0
	vmovaps	%ymm0, (%rdi,%rax,4)
	movl	$6, 4(%rbx)
	movl	$6, 4(%rcx)
	movl	$6, 4(%rsi)
	movl	$6, 4(%rdx)
	movl	$6, 4(%r11)
	movl	$6, 4(%r10)
	movl	$6, 4(%r9)
	movl	$6, 4(%r8)
	popq	%rbx
	popq	%rbp
	vzeroupper
	ret
.Ltmp1:
	.size	_subkernel_convergence_1_opt3_ws8, .Ltmp1-_subkernel_convergence_1_opt3_ws8


	.section	".note.GNU-stack","",@progbits
