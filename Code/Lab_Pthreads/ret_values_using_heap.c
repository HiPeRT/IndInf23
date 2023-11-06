#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct numbers {
    int a;
    int b;
} numbers_t;

typedef struct results {
    int sum;
    int diff;
    int quotient;
    int module;
} results_t;

void * pthreads_fn(void * args)
{
    numbers_t numbers = *((numbers_t *) args);

    results_t * results = malloc(sizeof(results_t));

    results->sum        = numbers.a + numbers.b;
    results->diff       = numbers.a - numbers.b;
    results->quotient   = numbers.a / numbers.b;
    results->module     = numbers.a % numbers.b;

    return (void *) results;
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
    
    void * ret = NULL;

    pthread_join(tid, (void **)&ret); // Now, returnvalue contains the value returned by pthreads_fn

    results_t *results = (results_t *)ret;

    printf("main - the results of the operations are:\n");
    printf("sum: %d\n"      , results->sum       );
    printf("diff: %d\n"     , results->diff      );
    printf("quotient: %d\n" , results->quotient  );
    printf("module: %d\n"   , results->module    );

    free(results);

    return 0;
}