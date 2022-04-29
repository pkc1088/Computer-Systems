/*
void decode1(long *xp, long *yp, long *zp)

decode1 :
	movq (%rdi), %r8
	movq (%rsi), %rcx
	movq (%rdx), %rax  // 메모리 -> 레지스터 읽음 
	movq %r8, (%rsi)	// 레지스터 -> 메모리 쓰기 
	movq %rcx, (%rdx)
	movq %rax, (%rdi)
	
	-> c style
	x = x*p
	y = y*p
	z = *zp
	*yp = x
	*zp = y
	*xp = z
*/
