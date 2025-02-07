#include <stdio.h>

long vframe(long n, long idx, long *q) {
    long i;
    long *p[n];
    p[0] = &i;
    for (i = 1; i < n; i++)
        p[i] = q;
    return *p[idx];
}

///////////

vframe:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	//rsp : frame pointer
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	15(,%rdi,8), %rax
	movq	%rax, %rcx
	andq	$-16, %rcx
	andq	$-4096, %rax
	movq	%rsp, %r10
	subq	%rax, %r10
	movq	%r10, %rax
.L2:
	cmpq	%rax, %rsp
	je	.L3
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L2
.L3:
	movq	%rcx, %rax
	andl	$4095, %eax
	subq	%rax, %rsp
	testq	%rax, %rax
	je	.L4
	orq	$0, -8(%rsp,%rax)
.L4:
	leaq	7(%rsp), %r8
	movq	%r8, %rax
	shrq	$3, %rax
	andq	$-8, %r8
	movq	%r8, %rcx
	leaq	-16(%rbp), %r9
	movq	%r9, 0(,%rax,8)
	movq	$1, -16(%rbp)
.L5:
	movq	-16(%rbp), %rax
	cmpq	%rax, %rdi
	jle	.L9
	movq	%rdx, (%rcx,%rax,8)
	addq	$1, -16(%rbp)
	jmp	.L5
.L9:
	movq	(%r8,%rsi,8), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	jne	.L10
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L10:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
