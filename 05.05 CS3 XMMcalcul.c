#include <stdio.h>

float vframe(double a, float x, double b, int i) {
    return a*x - b/i;
}
//////////
  vframe:
.LFB23:
        .cfi_startproc
        endbr64
        vcvtss2sd       %xmm1, %xmm1, %xmm1
        vmulsd  %xmm0, %xmm1, %xmm1
        vxorps  %xmm0, %xmm0, %xmm0
        vcvtsi2sdl      %edi, %xmm0, %xmm0
        vdivsd  %xmm0, %xmm2, %xmm0
        vsubsd  %xmm0, %xmm1, %xmm1
        vcvtsd2ss       %xmm1, %xmm1, %xmm0
        ret
        .cfi_endproc
