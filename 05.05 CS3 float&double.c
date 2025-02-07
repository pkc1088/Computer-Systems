#include <stdio.h>

float vframe(float v1, float *src, float *dst) {
    float v2 = *src;
    *dst = v1;
    return v2;
}
///////////
//gcc -mavx2 -Og -S test.c 명령어임 

  vframe:
.LFB23:
        .cfi_startproc
        endbr64
        vmovaps %xmm0, %xmm1
        vmovss  (%rdi), %xmm0
        vmovss  %xmm1, (%rsi)
        ret
        .cfi_endproc
