//#include <pthread.h>
//#include <stdio.h>
//#include <stdlib.h>
#include "test.h"

void *thread(void *vargp);                   

int main() {
    pthread_t tid;                           
    pthread_create(&tid, NULL, thread, NULL);   //void *(*func)(void *)
    pthread_join(tid, NULL);               
    exit(0);                                  
}

void *thread(void *vargp) {
    printf("Hello, world!\n");                 
    return NULL;                               
}             

// gcc -c -o test.o test.c
// gcc -pthread -o test test.o
// ./test  하면 컴파일됨
