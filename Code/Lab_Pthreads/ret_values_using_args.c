#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct numbers {
    int a;
    int b;
    int sum;
} numbers_t;

void * pthreads_fn(void * args)
{
    numbers_t * data = (numbers_t *)args;
    
    data->sum = data->a + data->b;

    return NULL;
}

int main()
{
    pthread_t tid;

    numbers_t data;

    data.a = 5;
    data.b = 3;

    pthread_create (&tid, NULL, pthreads_fn, (void *) &data); // Pass 'i' as identifier for thread

    // Now, the man (master) thread can do other useful stuff, here
    // while other (slave) threads execute in parallel
    
    pthread_join(tid, NULL); // Now, returnvalue contains the value returned by pthreads_fn

    printf("the result is %d\n", data.sum);

    return 0;
}