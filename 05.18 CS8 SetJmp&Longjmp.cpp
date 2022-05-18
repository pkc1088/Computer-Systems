#include "csapp.h"
/*
함수 기능
함수의 경계를 넘나드는 분기처리를 하기 위해 사용되는 함수입니다.
setjmp() 를 통해 마킹을 해두고, 나중에 longjmp() 를 호출하면 해당 
마킹장소로 돌아오는 방식입니다.

env
현재 상태에 대한 정보를 저장하는 객체입니다.
setjmp() 가 실행되는 순간의 함스 스택 환경과 레지스터 환경을 env 
변수에 저장합니다.
이후 longjmp() 함수가 호출되면 env 에 담긴 정보를 바탕으로 회귀하는 
방식입니다.

val
longjmp() 함수에서 넘긴 val 값이 setjmp() 함수의 리턴값이 됩니다.

반환값
스스로 호출된 경우 0 리턴

longjmp()에 의해 호출된 경우 0이 아닌 정수 리턴
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <setjmp.h> 
#include <signal.h> 
//goto와 달리 longjmp를 호출하면 setjmp()를 한 곳으로 돌아갑니다.

void p1(); 
void intHandler(); 
jmp_buf env; 

int main() { 
	signal( SIGINT, intHandler ); 
	if( setjmp( env ) != 0 ) { 
		printf( "오류로 인해 복귀\n" ); 
		exit( 0 ); 
	} else 
		printf( "처음 통과\n" ); 
		
	p1(); 
} 

void p1() { 
	while( 1 ){ 
		printf( "루프\n" ); sleep( 1 ); 
	} 
} 
void intHandler() { 
	printf( "인터럽트\n" ); 
	longjmp( env, 1 ); 
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf glob_buffer;


void ssu_nested_func(int loc_var, int loc_volatile, int loc_register) {
    // longjmp 이 전에 값을 찍어봄
    printf("before longjmp, loc_var = %d, loc_volatile = %d, loc_register = %d\n", loc_var, loc_volatile, loc_register);

    // longjmp() 를 호출하여 마킹지점 setjmp() 로 이동함
    longjmp(glob_buffer, 1);
}

int main(int argc, char *argv[], char *envpp[]) {
    // 레지스터 변수
    register int loc_register;

    // 어떤 경우에도 최적화를 하지 않는 volatile 변수
    // 따라서 레지스터에 저장되지 않음
    volatile int loc_volatile;

    // 지역변수는 레지스터에 들어갈수도 안들어갈수도 있음
    int loc_var;

    loc_var = 10;
    loc_volatile = 11;
    loc_register = 12;

    // 점프 지점 마킹
    if (setjmp(glob_buffer) != 0) {
        // 여기는 longjmp() 함수를 통해 setjmp() 가 호출된 경우
        // -O 옵션을 통해 최적화를 하는 컴파일을 했다면 loc_var, loc_register 는 각각 변경 전의 값 10, 12 가 출력되고
        // volatile 변수는 값이 되돌아 가지 않고 81이 출력
        // -O 옵션을 주지 않으면 모든 값이 되돌아가지 않고 80 81 82 가 출력
        printf("after longjmp, loc_var = %d, loc_volatile = %d, loc_register = %d\n", loc_var, loc_volatile, loc_register);
        exit(0);
    }

    // 값 수정
    loc_var = 80;
    loc_volatile = 81;
    loc_register = 82;

    // 함수 호출
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
