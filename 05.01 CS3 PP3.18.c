https://stackoverflow.com/questions/21440403/what-does-the-cmpq-instruction-do
https://stackoverflow.com/questions/45652477/different-answers-in-recovering-c-codes-from-assembly-code-in-att

#include <stdio.h>

short test(short x, short y, short z) {
    short val = x + y + z;
    if (x < -3) {
        if (y < z) {
            val = x * y;
        }
        else { 
            val = y * z;
        }
    } else if (x > 2) {
        val = x * z;
    }
    return val;
}

int main(void) {
    
    printf("%d\n", test(100, 200, 300));
    return 0;
}


///////////////////


test:
.LFB23:
	.cfi_startproc
	endbr64
	movl	%edx, %eax
	cmpw	$-3, %di
	jge	.L2
	cmpw	%dx, %si
	jge	.L3
	movl	%esi, %eax
	imull	%edi, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L2:
	cmpw	$2, %di
	jle	.L7
	imull	%edi, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	addl	%esi, %eax
	addl	%edi, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L3:
	imull	%esi, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	test, .-test
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$30000, %edx
	movl	$1, %edi
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	call	__printf_chk@PLT
	xorl	%eax, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:

