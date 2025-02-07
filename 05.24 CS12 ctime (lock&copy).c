#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAXSTR 128

static sem_t mutex; /* protects calls to ctime */

static void init_ctime_ts(void)
{
    sem_init(&mutex, 0, 1);
}

/* $begin ctime_ts */
char *ctime_ts(const time_t *timep, char *privatep)
{
    char *sharedp; 

    sem_wait(&mutex);
    sharedp = ctime(timep);
    strcpy(privatep, sharedp); /* Copy string from shared to private */
    sem_post(&mutex);
    return privatep;
}
/* $end ctime_ts */

int main()
{
    char timestr[MAXSTR];
    time_t timeval;

    /* Thread-safe code to print the current time string */
    init_ctime_ts();
    timeval = time(NULL);
    ctime_ts(&timeval, timestr);
    printf("%s", timestr);
    exit(0);
}

/*
    clock_t start, end;
    start = clock();
    end = clock();
    printf("%f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
*/
