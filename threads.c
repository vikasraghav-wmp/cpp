
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *threadfunc (void *tid)
{
    long *myid=(long*)tid;
    printf("hello world! This is thread %ld",*myid);
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, threadfunc, (void*)&tid);
    pthread_exit(NULL);
    return 0;
}