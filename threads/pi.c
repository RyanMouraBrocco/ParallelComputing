#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int threadCount;

void *threadSum(void *rank);

int main()
{
    long thread;
    pthread_t *threads;
    threadCount = 200;
    threads = malloc(threadCount * sizeof(pthread_t));

    printf("hello from the main thread\n");

    for (thread = 0; thread < threadCount; thread++)
    {
        pthread_create(&threads[thread], NULL, hello, (void *)(thread + 1));
    }

    for (thread = 0; thread < threadCount; thread++)
    {
        pthread_join(threads[thread], NULL);
    }

    free(threads);

    return 0;
}

void* threadSum(void *rank)
{
    long thisRank = (long)rank;
    double factor;
    long long i;
    printf("hello from thread %ld of %d\n", thisRank, threadCount);

    return NULL;
}
