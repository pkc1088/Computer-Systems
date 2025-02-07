long rfact(long n) {
    long result;
    if (n <= 1)
        result = 1;
    else
        result = n * rfact(n-1);
    return result;
}

//////////////

rfact:
.LFB0:
        .cfi_startproc
        endbr64
        cmpq    $1, %rdi
        jg      .L8
        movl    $1, %eax
        ret
.L8:
        pushq   %rbx
        .cfi_def_cfa_offset 16
        .cfi_offset 3, -16
        movq    %rdi, %rbx
        leaq    -1(%rdi), %rdi
        call    rfact
        imulq   %rbx, %rax
        popq    %rbx
        .cfi_def_cfa_offset 8
        ret
        .cfi_endproc
