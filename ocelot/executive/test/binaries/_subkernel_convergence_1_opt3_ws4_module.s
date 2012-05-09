	.file	"_subkernel_convergence_1_opt3_ws4_module.bc"
	.section	.rodata.cst4,"aM",@progbits,4
	.align	4
.LCPI0_0:
	.long	1065353216              # float 1.000000e+00
                                        #  (0x3f800000)
	.text
	.globl	_Z_ocelotTranslated__subkernel_convergence_1
	.align	16, 0x90
	.type	_Z_ocelotTranslated__subkernel_convergence_1,@function
_Z_ocelotTranslated__subkernel_convergence_1: # @_Z_ocelotTranslated__subkernel_convergence_1
# BB#0:                                 # %$BB_1_0002
	movq	80(%rdi), %rax
	movq	(%rax), %rax
	movslq	(%rdi), %rcx
	cvtsi2ss	%ecx, %xmm0
	addss	%xmm0, %xmm0
	addss	.LCPI0_0(%rip), %xmm0
	movss	%xmm0, (%rax,%rcx,4)
	movq	48(%rdi), %rax
	movl	$6, 4(%rax)
	ret
.Ltmp0:
	.size	_Z_ocelotTranslated__subkernel_convergence_1, .Ltmp0-_Z_ocelotTranslated__subkernel_convergence_1

	.section	.rodata.cst16,"aM",@progbits,16
	.align	16
.LCPI1_0:
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.long	1065353216              # float 1.000000e+00
	.text
	.globl	_subkernel_convergence_1_opt3_ws4
	.align	16, 0x90
	.type	_subkernel_convergence_1_opt3_ws4,@function
_subkernel_convergence_1_opt3_ws4:      # @_subkernel_convergence_1_opt3_ws4
# BB#0:                                 # %exit
	movd	336(%rdi), %xmm1
	movd	112(%rdi), %xmm0
	punpckldq	%xmm1, %xmm0    # xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
	movd	224(%rdi), %xmm1
	movslq	(%rdi), %rax
	movd	%eax, %xmm2
	punpckldq	%xmm1, %xmm2    # xmm2 = xmm2[0],xmm1[0],xmm2[1],xmm1[1]
	punpckldq	%xmm0, %xmm2    # xmm2 = xmm2[0],xmm0[0],xmm2[1],xmm0[1]
	cvtdq2ps	%xmm2, %xmm0
	addps	%xmm0, %xmm0
	movq	384(%rdi), %r8
	movq	272(%rdi), %rdx
	movq	160(%rdi), %rsi
	movq	48(%rdi), %rcx
	movq	80(%rdi), %rdi
	addps	.LCPI1_0(%rip), %xmm0
	movq	(%rdi), %rdi
	movaps	%xmm0, (%rdi,%rax,4)
	movl	$6, 4(%rcx)
	movl	$6, 4(%rsi)
	movl	$6, 4(%rdx)
	movl	$6, 4(%r8)
	ret
.Ltmp1:
	.size	_subkernel_convergence_1_opt3_ws4, .Ltmp1-_subkernel_convergence_1_opt3_ws4


	.section	".note.GNU-stack","",@progbits
