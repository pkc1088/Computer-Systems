#include <stdio.h>

struct test {
    short *p;
    struct {
        short x;
        short y;
    } s;
    struct test *next;
};

void st_init(struct test *st) {
    st->s.y = st->s.x;
    st->p = &(st->s.y);
    st->next = st;
}
 
/////////////

st_init:
.LFB23:
        .cfi_startproc
        endbr64
        movzwl  8(%rdi), %eax
        movw    %ax, 10(%rdi) //책이랑 다른데 short니깐 w가 맞는듯 
        leaq    10(%rdi), %rax
        movq    %rax, (%rdi)
        movq    %rdi, 16(%rdi) 
        ret
        .cfi_endproc
