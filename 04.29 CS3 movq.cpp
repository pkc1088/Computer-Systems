/*
void decode1(long *xp, long *yp, long *zp)

decode1 :
	movq (%rdi), %r8
	movq (%rsi), %rcx
	movq (%rdx), %rax  // �޸� -> �������� ���� 
	movq %r8, (%rsi)	// �������� -> �޸� ���� 
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
