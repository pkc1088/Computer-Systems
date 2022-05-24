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
        //i�� ������ vargp�� ���������� ������ ���ֱ����� ������ ����� ��������
        //�Ҵ��ؼ� ������ ��ƾ�� �� ����� �����͸� ������
    } 
    for (i = 0; i < N; i++) 
        Pthread_join(tid[i], NULL);
    exit(0);
}

void *thread(void *vargp) {
    int myid = *((int *)vargp); 
    Free(vargp); //��ȯ �ʼ� for �޸� ����
    printf("Hello from thread %d\n", myid);
    return NULL;
}


