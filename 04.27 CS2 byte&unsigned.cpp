#include <stdio.h>
int main(void) {
	unsigned char b1 = 0x85;	// 1000 0101
								// unsigned는 부호 고려 x 
	printf("%d\n", b1);
	
	signed char b2 = 0x85;
	printf("%d\n", b2);
	
	char b3 = 0x85;	// 1000 0000 (-128) 이 제일 작은거임
					// 이때 맨 앞 1은 음수 나머지 7자리 2^7 = 128 
					// 1000 0101 (-128 + 5) 이니깐 123이 나옴 
	printf("%d\n", b3);
	
	
	return 0;
}
