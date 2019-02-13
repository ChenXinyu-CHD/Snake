	.file	"a.cpp"
	.text
	.section	.text._ZN6DirectC2Ev,"axG",@progbits,_ZN6DirectC5Ev,comdat
	.align 2
	.weak	_ZN6DirectC2Ev
	.type	_ZN6DirectC2Ev, @function
_ZN6DirectC2Ev:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN6DirectC2Ev, .-_ZN6DirectC2Ev
	.weak	_ZN6DirectC1Ev
	.set	_ZN6DirectC1Ev,_ZN6DirectC2Ev
	.section	.text._ZN6DirectC2ENS_6directE,"axG",@progbits,_ZN6DirectC5ENS_6directE,comdat
	.align 2
	.weak	_ZN6DirectC2ENS_6directE
	.type	_ZN6DirectC2ENS_6directE, @function
_ZN6DirectC2ENS_6directE:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	_ZN6DirectC2ENS_6directE, .-_ZN6DirectC2ENS_6directE
	.weak	_ZN6DirectC1ENS_6directE
	.set	_ZN6DirectC1ENS_6directE,_ZN6DirectC2ENS_6directE
	.section	.text._ZN6DirectaSES_,"axG",@progbits,_ZN6DirectaSES_,comdat
	.align 2
	.weak	_ZN6DirectaSES_
	.type	_ZN6DirectaSES_, @function
_ZN6DirectaSES_:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	movl	$4, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	cmpl	%eax, %edx
	je	.L5
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, (%rax)
.L5:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	_ZN6DirectaSES_, .-_ZN6DirectaSES_
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6DirectC1Ev
	leaq	-12(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZN6DirectC1ENS_6directE
	movl	-12(%rbp), %edx
	leaq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN6DirectaSES_
	leaq	-12(%rbp), %rax
	movl	$3, %esi
	movq	%rax, %rdi
	call	_ZN6DirectC1ENS_6directE
	movl	-12(%rbp), %edx
	leaq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN6DirectaSES_
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.2.1 20181127"
	.section	.note.GNU-stack,"",@progbits
