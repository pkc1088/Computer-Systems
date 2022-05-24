#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define N 4

void *thread(void *vargp);

int main() {
    pthread_t tid[N];
    int i, *ptr;

    for (i = 0; i < N; i++) {
        ptr = Malloc(sizeof(int));                    
        *ptr = i;                                     
        Pthread_create(&tid[i], NULL, thread, ptr);   
        //i의 증가와 vargp의 역참조간의 경쟁을 없애기위해 별도의 블록을 동적으로
        //할당해서 쓰레드 루틴에 이 블록의 포인터를 전달함
    } 
    for (i = 0; i < N; i++) 
        Pthread_join(tid[i], NULL);
    exit(0);
}

void *thread(void *vargp) {
    int myid = *((int *)vargp); 
    Free(vargp); //반환 필수 for 메모리 누수
    printf("Hello from thread %d\n", myid);
    return NULL;
}


