void proc(long a1, long *a1p, int a2, int *a2p,
          short a3, short *a3p, char a4, char *a4p) {
    
    *a1p += a1;
    *a2p += a2;
    *a3p += a3;
    *a4p += a4;
}

//////////////////
//인자 1~6은 레지스터, 인자 7~8은 스택(Argument build area)로 저장됨 

        .file   "test.c"
        .text
        .globl  proc
        .type   proc, @function
proc:
.LFB0:
        .cfi_startproc
        endbr64
        movq    16(%rsp), %rax
        addq    %rdi, (%rsi)
        addl    %edx, (%rcx)
        addw    %r8w, (%r9)
        movl    8(%rsp), %edx
        addb    %dl, (%rax)
        ret
        .cfi_endproc
.LFE0:
        .size   proc, .-proc
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
~                 
