#include <stdio.h>

short dw_loop(short x) {
    short y = x / 9;
    short *p = &x;
    short n = 4 * x;
    do {
        x += y;
        (*p) += 5;
        n -= 2;
    } while (n > 0);
    return x;
}

int main(void) {
    
    printf("%d\n", dw_loop(100));
    return 0;
}

/////////////////////

dw_loop:
.LFB23:
        .cfi_startproc
        endbr64
        movl    %edi, %edx
        movswl  %di, %ecx
        imull   $7282, %ecx, %ecx
        shrl    $16, %ecx
        movl    %edi, %eax
        sarw    $15, %ax
        subl    %eax, %ecx
        sall    $2, %edi
.L2:
        leal    5(%rcx,%rdx), %edx
        leal    -2(%rdi), %eax
        movl    %eax, %edi
        testw   %ax, %ax
        jg      .L2
        movl    %edx, %eax
        ret
        .cfi_endproc
.LFE23:
        .size   dw_loop, .-dw_loop
        .section        .rodata.str1.1,"aMS",@progbits,1
.LC0:
        .string "%d\n"
        .text
        .globl  main
        .type   main, @function
main:
.LFB24:
        .cfi_startproc
        endbr64
        subq    $8, %rsp
        .cfi_def_cfa_offset 16
        movl    $100, %edi
        call    dw_loop
        movswl  %ax, %edx
        leaq    .LC0(%rip), %rsi
        movl    $1, %edi
        movl    $0, %eax
        call    __printf_chk@PLT
        movl    $0, %eax
        addq    $8, %rsp
        .cfi_def_cfa_offset 8
        ret
        .cfi_endproc
.LFE24:
        .size   main, .-main
        .ident  "GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
        .section        .note.GNU-stack,"",@progbits
        .section        .note.gnu.property,"a"
        .align 8
        .long    1f - 0f
        .long    4f - 1f
        .long    5
0:
        .string  "GNU"
1:
        .align 8
        .long    0xc0000002
        .long    3f - 2f
2:
        .long    0x3
3:
        .align 8
4:
