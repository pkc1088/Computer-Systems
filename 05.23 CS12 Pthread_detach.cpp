#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
void* thread_routine(void *arg){
        int i = 1;
        
        printf("tid2 : %x\n", (unsigned int) pthread_self());

        while(i < 10000000) {
            printf("t2 : %d\n", i++);
        }
}
 
int main() {
        int i = 1;
        pthread_t t2, t3;
        pthread_create(&t2, NULL, thread_routine, NULL);
        
        printf("tid1 : %x\n", (unsigned int) pthread_self());
        sleep(2);
        pthread_detach(t2);
        while(i < 10) {
            printf("t1 : %d\n", i++);
        }
        i = 0;

}
/*
t2를 만들고 thread_routine함수를 돌때 sleep 2이후 t2를 detach함으로 중간에 detach해버림
이때 이 쓰레드가 종료되면서 시스템에 의해 자동으로 반환됨 돌려보면 i가 364279일때 쯤에 종료됨
그 후 t1은 알아서 실행됨 
즉 만약 쓰레드의 종료 상태를 주 쓰레드에서 확인할 필요가 없거나
추가적인 쓰레드의 뒷정리를 시스템에서 자동적으로 하기를 원할 때는 
쓰레드를 detach를 통해서 분리한다.



*/    



