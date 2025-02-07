#include <stdio.h>

int divide(int x, int y) {
    return x / y;
}
int main(void) {
    int result = divide(4, 2);
    printf("%d\n", result);

    return 0;
}

///////////////////////////////////////////////

        .file   "test.c"
        .text
        .globl  divide
        .type   divide, @function
divide:
.LFB23:
        .cfi_startproc
        endbr64
        movl    %edi, %eax
        cltd
        idivl   %esi
        ret
        .cfi_endproc
.LFE23:
        .size   divide, .-divide
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
        movl    $2, %esi
        movl    $4, %edi
        call    divide
        movl    %eax, %edx
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
