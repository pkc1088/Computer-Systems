long cmp(long a, long b) {
    return a < b;
}

////

comp:
.LFB0:
    .cfi_startproc
    cmpq    %rsi, %rdi    ; Compare a:b
    setl    %al           ; Set low-order byte to %eax to 0 or 1
    movzbl  %al, %eax     $ Clear rest of %eax (and rest of %rax)
    ret
    .cfi_endproc
