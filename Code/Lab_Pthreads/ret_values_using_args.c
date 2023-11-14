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

    pthread_create (&tid, NULL, pthreads_fn, (void *) &data); // Pass 'data' as in/out working set

    // Now, the man (master) thread can do other useful stuff, here

    // ..for instance, it can participate to the parallel computation (completely useless, in this case)
    //pthreads_fn((void*) &data);
    
    // while other (slave) threads execute in parallel
    
    pthread_join(tid, NULL); // Now, 'data->sum' contains the value returned by pthreads_fn

    printf("the result is %d\n", data.sum);

    return 0;
}