#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#define MAXTHREADS 32    

void *sum_local(void *vargp); /* Thread routine */

long psum[MAXTHREADS];  
long nelems_per_thread;

int main(int argc, char **argv) {
    long i, nelems, log_nelems, nthreads, myid[MAXTHREADS], result = 0;
    pthread_t tid[MAXTHREADS];

    if (argc != 3) { 
	    printf("Usage: %s <nthreads> <log_nelems>\n", argv[0]);
	    exit(0);
    }

    nthreads = atoi(argv[1]);
    log_nelems = atoi(argv[2]);
    nelems = (1L << log_nelems);

    if ((nelems % nthreads) != 0 || (log_nelems > 31)) {
	    printf("Error: invalid nelems\n");
	    exit(0);
    }
    nelems_per_thread = nelems / nthreads;

    for (i = 0; i < nthreads; i++) {                  
	    myid[i] = i;                                  
	    pthread_create(&tid[i], NULL, sum_local, &myid[i]); 
    }                                                 
    
    for (i = 0; i < nthreads; i++)                    
	    pthread_join(tid[i], NULL);                   
    
    for (i = 0; i < nthreads; i++)                    
	    result += psum[i];                            

    if (result != (nelems * (nelems-1))/2)     
	    printf("Error: result=%ld\n", result); 
    else
        printf("result = %ld\n", result); 
    

    exit(0);
}

void *sum_local(void *vargp) 
{
    long myid = *((long *)vargp);          
    long start = myid * nelems_per_thread; 
    long end = start + nelems_per_thread;  
    long i, sum = 0;

    for (i = start; i < end; i++) {        
	    sum += i;                          
    }	                                   
    psum[myid] = sum; 
    printf("myid[%ld] : %ld\n", myid, sum);
    return NULL;
}

/*
    clock_t start, end;
    start = clock();
    end = clock();
    printf("%f\n", ((double)(end - start)) / CLOCKS_PER_SEC);
*/
