#include <stdio.h>
#include <stdlib.h>

typedef void (*Handler)(void);    /* A pointer to a handler function */

/* The functions */
void func3 (void) { printf( "3\n" ); }
void func2 (void) { printf( "2\n" ); }
void func1 (void) { printf( "1\n" ); }
void func0 (void) { printf( "0\n" ); }

Handler jump_table[4] = {func0, func1, func2, func3};

int main (int argc, char **argv) {
    int value;

    /* Convert first argument to 0-3 integer (modulus) */
    value = ((atoi(argv[1]) % 4) + 4) % 4;

    /* Call appropriate function (func0 thru func3) */
    jump_table[value]();

    return 0;
}

///////////////////
.LC0:
	.string	"3"
	.text
	.globl	func3
	.type	func3, @function
func3:
.LFB39:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
ret
	.cfi_endproc
.LFE39:
	.size	func3, .-func3
	.section	.rodata.str1.1
.LC1:
	.string	"2"
	.text
	.globl	func2
	.type	func2, @function
func2:
.LFB40:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE40:
	.size	func2, .-func2
	.section	.rodata.str1.1
.LC2:
	.string	"1"
	.text
	.globl	func1
	.type	func1, @function
func1:
.LFB41:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE41:
	.size	func1, .-func1
	.section	.rodata.str1.1
.LC3:
	.string	"0"
	.text
	.globl	func0
	.type	func0, @function
func0:
.LFB42:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE42:
	.size	func0, .-func0
	.globl	main
	.type	main, @function
main:
.LFB43:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	cltd
	shrl	$30, %edx
	addl	%edx, %eax
	andl	$3, %eax
	subl	%edx, %eax
	addl	$4, %eax
	cltd
	shrl	$30, %edx
	addl	%edx, %eax
	andl	$3, %eax
	subl	%edx, %eax
	cltq
	leaq	jump_table(%rip), %rdx
	call	*(%rdx,%rax,8)
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE43:
	.size	main, .-main
	.globl	jump_table
	.section	.data.rel.local,"aw"
	.align 32
	.type	jump_table, @object
	.size	jump_table, 32
jump_table:	//////////////////////////////////////
	.quad	func0
	.quad	func1
	.quad	func2
	.quad	func3
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
