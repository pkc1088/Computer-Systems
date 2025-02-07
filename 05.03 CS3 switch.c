void switch_eg(long x, long n, long *dest) {
    long val = x;

    switch (n) {

    case 100:
        val *= 13;
        break;

    case 102:
        val += 10;
        /* Fall through */

    case 103:
        val += 11;
        break;

    case 104:
    case 106:
        val *= val;
        break;

    default:
        val = 0;
    }
    *dest = val;
}
//////////////
       .file   "test.c"
        .text
        .globl  switch_eg
        .type   switch_eg, @function
switch_eg:
.LFB0:
        .cfi_startproc
        endbr64
        subq    $100, %rsi
        cmpq    $6, %rsi
        ja      .L8
        leaq    .L4(%rip), %rcx
        movslq  (%rcx,%rsi,4), %rax
        addq    %rcx, %rax
        notrack jmp     *%rax
        .section        .rodata
        .align 4
        .align 4
.L4:		////////////////////////
        .long   .L7-.L4
        .long   .L8-.L4
        .long   .L6-.L4
        .long   .L5-.L4
        .long   .L3-.L4
        .long   .L8-.L4
        .long   .L3-.L4
        .text
.L7:
        leaq    (%rdi,%rdi,2), %rax
        leaq    (%rdi,%rax,4), %rdi
        jmp     .L2
.L6:
        addq    $10, %rdi
.L5:
        addq    $11, %rdi
.L2:
        movq    %rdi, (%rdx)
        ret
.L3:
        imulq   %rdi, %rdi
        jmp     .L2
.L8:
        movl    $0, %edi
        jmp     .L2
        .cfi_endproc
.LFE0:
        .size   switch_eg, .-switch_eg
        .ident  "GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
        .section        .note.GNU-stack,"",@progbits
        .section        .note.gnu.property,"a"
        .align 8
        .long    1f - 0f
        .long    4f - 1f
        .long    5
0:
"test.s" 65L, 917C                        1,2-9         Top
