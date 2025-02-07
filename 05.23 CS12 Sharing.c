#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define N 2
void *thread(void *vargp);

char **ptr; 

int main() 
{
    int i;  
    pthread_t tid;
    char *msgs[N] = {
	    "Hello from foo",  
	    "Hello from bar"   
    };

    ptr = msgs; 
    for (i = 0; i < N; i++)  
        pthread_create(&tid, NULL, thread, &i); 
    pthread_exit(NULL); 
}

void *thread(void *vargp) 
{
    static int cnt = 0;
    printf("[%d]: %s (cnt=%d)\n", *(int*)vargp, ptr[*(int*)vargp], ++cnt);
    return NULL;
}
