#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;	// unsigned int 
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    
    printf("\n");
}
 
int main(void) {
	size_t q = 10;
	short x = 12345;	//sizeof(short) 는 2 byte임 
	printf("%d\n", q);
	show_bytes((byte_pointer) &x, sizeof(short));
	
	short mx = -x;
	show_bytes((byte_pointer) &mx, sizeof(short));
	
	 
	return 0;	//결과값이 39 30 이니 리틀 엔디안 머신임 
}
