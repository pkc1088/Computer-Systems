#include <stdio.h>
int main(void) {
	unsigned char b1 = 0x85;	// 1000 0101
								// unsigned�� ��ȣ ��� x 
	printf("%d\n", b1);
	
	signed char b2 = 0x85;
	printf("%d\n", b2);
	
	char b3 = 0x85;	// 1000 0000 (-128) �� ���� ��������
					// �̶� �� �� 1�� ���� ������ 7�ڸ� 2^7 = 128 
					// 1000 0101 (-128 + 5) �̴ϱ� 123�� ���� 
	printf("%d\n", b3);
	
	
	return 0;
}
