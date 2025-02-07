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
    // 4+2+4+16 = 26 -> 32 (가장 큰 자료형인 16의 배수) 
}
/*
1. 구조체의 크기는 구조체의 가장 큰 자료형의 배수가 됨
2. 구조체의 가장 큰 자료형으로 데이터를 정렬함
3. 구조체의 자료형은 본인 자료형의 배수에서 시작 주소를 가짐
*/
