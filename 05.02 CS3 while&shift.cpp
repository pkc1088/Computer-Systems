#include <stdio.h>

int dw_loop(int x) {
    int val = 1;
    while(x!= 0) {
        val ^= x;
        x >>= 1;   // x /= 2;
        printf("x : %d\n val : %d\n", x, val);
    } 
    return val & 0;
}

int main(void) {
    printf("%d\n", dw_loop(100));
    
    return 0;
}
//////////////////////
dw_loop:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	%edi, %ebx
	movl	$1, %ebp
.L2:
	testl	%ebx, %ebx
	je	.L5
	xorl	%ebx, %ebp
	sarl	%ebx
	movl	%ebp, %ecx
	movl	%ebx, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	jmp	.L2
.L5:
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
