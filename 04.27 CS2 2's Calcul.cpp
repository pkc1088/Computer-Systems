#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;
 
int main(void) {
	unsigned short a1 = 2;
	unsigned short a2 = 5;
	printf("%x\n", a1 + a2);

	unsigned short b1 = -8;
	unsigned short b2 = -5;
	printf("%x\n", b1 + b2);
	
	int x = 11;
	printf("%d\n", x<<2);
	
	return 0;
}
