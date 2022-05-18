#include "csapp.h"
/*
�Լ� ���
�Լ��� ��踦 �ѳ���� �б�ó���� �ϱ� ���� ���Ǵ� �Լ��Դϴ�.
setjmp() �� ���� ��ŷ�� �صΰ�, ���߿� longjmp() �� ȣ���ϸ� �ش� 
��ŷ��ҷ� ���ƿ��� ����Դϴ�.

env
���� ���¿� ���� ������ �����ϴ� ��ü�Դϴ�.
setjmp() �� ����Ǵ� ������ �Խ� ���� ȯ��� �������� ȯ���� env 
������ �����մϴ�.
���� longjmp() �Լ��� ȣ��Ǹ� env �� ��� ������ �������� ȸ���ϴ� 
����Դϴ�.

val
longjmp() �Լ����� �ѱ� val ���� setjmp() �Լ��� ���ϰ��� �˴ϴ�.

��ȯ��
������ ȣ��� ��� 0 ����

longjmp()�� ���� ȣ��� ��� 0�� �ƴ� ���� ����
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <setjmp.h> 
#include <signal.h> 
//goto�� �޸� longjmp�� ȣ���ϸ� setjmp()�� �� ������ ���ư��ϴ�.

void p1(); 
void intHandler(); 
jmp_buf env; 

int main() { 
	signal( SIGINT, intHandler ); 
	if( setjmp( env ) != 0 ) { 
		printf( "������ ���� ����\n" ); 
		exit( 0 ); 
	} else 
		printf( "ó�� ���\n" ); 
		
	p1(); 
} 

void p1() { 
	while( 1 ){ 
		printf( "����\n" ); sleep( 1 ); 
	} 
} 
void intHandler() { 
	printf( "���ͷ�Ʈ\n" ); 
	longjmp( env, 1 ); 
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf glob_buffer;


void ssu_nested_func(int loc_var, int loc_volatile, int loc_register) {
    // longjmp �� ���� ���� ��
    printf("before longjmp, loc_var = %d, loc_volatile = %d, loc_register = %d\n", loc_var, loc_volatile, loc_register);

    // longjmp() �� ȣ���Ͽ� ��ŷ���� setjmp() �� �̵���
    longjmp(glob_buffer, 1);
}

int main(int argc, char *argv[], char *envpp[]) {
    // �������� ����
    register int loc_register;

    // � ��쿡�� ����ȭ�� ���� �ʴ� volatile ����
    // ���� �������Ϳ� ������� ����
    volatile int loc_volatile;

    // ���������� �������Ϳ� ������ �ȵ����� ����
    int loc_var;

    loc_var = 10;
    loc_volatile = 11;
    loc_register = 12;

    // ���� ���� ��ŷ
    if (setjmp(glob_buffer) != 0) {
        // ����� longjmp() �Լ��� ���� setjmp() �� ȣ��� ���
        // -O �ɼ��� ���� ����ȭ�� �ϴ� �������� �ߴٸ� loc_var, loc_register �� ���� ���� ���� �� 10, 12 �� ��µǰ�
        // volatile ������ ���� �ǵ��� ���� �ʰ� 81�� ���
        // -O �ɼ��� ���� ������ ��� ���� �ǵ��ư��� �ʰ� 80 81 82 �� ���
        printf("after longjmp, loc_var = %d, loc_volatile = %d, loc_register = %d\n", loc_var, loc_volatile, loc_register);
        exit(0);
    }

    // �� ����
    loc_var = 80;
    loc_volatile = 81;
    loc_register = 82;

    // �Լ� ȣ��
    ssu_nested_func(loc_var, loc_volatile, loc_register);

    exit(0);
}

/*
jmp_buf buf;

int error1 = 0; 
int error2 = 1;

void foo(void), bar(void);

int main() 
{
    switch(setjmp(buf)) {
    case 0: 
	foo();
        break;
    case 1: 
	printf("Detected an error1 condition in foo\n");
        break;
    case 2: 
	printf("Detected an error2 condition in foo\n");
        break;
    default:
	printf("Unknown error condition in foo\n");
    }
    exit(0);
}

void foo(void) 
{
    if (error1)
	longjmp(buf, 1); 
    bar();
}

void bar(void) 
{
    if (error2)
	longjmp(buf, 2); 
}
*/
