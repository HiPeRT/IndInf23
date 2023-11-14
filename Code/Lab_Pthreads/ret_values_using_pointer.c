#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct numbers {
    int a;
    int b;
//    int sum;
} numbers_t;

void * pthreads_fn(void * args)
{
    numbers_t * data = (numbers_t *) args;
    void      * ret  = (void *) (data->a + data->b);

    printf("thread - ret: %p\n", ret);

    return ret;
}

int main()
{
    pthread_t tid;

    numbers_t data;

    data.a = 5;
    data.b = 3;

    pthread_create (&tid, NULL, pthreads_fn, (void *) &data); // Pass 'data' as in working set

    // Now, the man (master) thread can do other useful stuff, here
    // while other (slave) threads execute in parallel
    
    void * ret = NULL;

    pthread_join(tid, (void **)&ret); // Now, 'ret' contains the value returned by pthreads_fn

    printf("main - the result is %d and the pointer is %p\n", (int) ret, ret);

    return 0;
}