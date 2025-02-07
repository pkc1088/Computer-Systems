#include <stdio.h>

long p[5][3];
long q[3][5];

long sum_element(long i, long j) {
    return p[i][j] + q[j][i];
}

int main(void) {
        
    return 0;
}

///////////////

sum_element:
.LFB23:
        .cfi_startproc
        endbr64
        leaq    (%rdi,%rdi,2), %rdx
        addq    %rsi, %rdx
        leaq    (%rsi,%rsi,4), %rax
        addq    %rax, %rdi
        leaq    q(%rip), %rax
        movq    (%rax,%rdi,8), %rax
        leaq    p(%rip), %rcx
        addq    (%rcx,%rdx,8), %rax
        ret
        .cfi_endproc
.LFE23:
        .size   sum_element, .-sum_element
        .globl  main
        .type   main, @function
main:
.LFB24:
        .cfi_startproc
        endbr64
        movl    $0, %eax
        ret
        .cfi_endproc
.LFE24:
        .size   main, .-main
        .comm   q,120,32
        .comm   p,120,32
        .ident  "GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
        .section        .note.GNU-stack,"",@progbits
        .section        .note.gnu.property,"a"
        .align 8
        .long    1f - 0f
        .long    4f - 1f
        .long    5
