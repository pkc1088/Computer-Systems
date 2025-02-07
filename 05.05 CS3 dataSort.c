#include <stdio.h>
typedef enum {N_LEAF, N_INTERNAL} nodetpye_t;
struct test {
    int p;  //4
    short x;   //2
    nodetpye_t type;    //4
    union {
        struct {
            struct test *left;
            struct test *right;
         } internal;
        double data[2];
    } info; //16
} hey;

int main(void) {
    printf("%ld\n", sizeof(hey));
    // 4+2+4+16 = 26 -> 32 (���� ū �ڷ����� 16�� ���) 
}
/*
1. ����ü�� ũ��� ����ü�� ���� ū �ڷ����� ����� ��
2. ����ü�� ���� ū �ڷ������� �����͸� ������
3. ����ü�� �ڷ����� ���� �ڷ����� ������� ���� �ּҸ� ����
*/
