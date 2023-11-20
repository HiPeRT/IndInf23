#include <stdio.h>

#include <pthread.h>
#include <semaphore.h>

#include "libQ.h"

task* newTasks[3];

void * t0(void * data)
{
    printf("Running task t0\n");
    return NULL;
}

void * t1(void * data)
{
    printf("Running task t1\n");
    return NULL;
}

void * t2(void * data)
{
    printf("Running task t2\n");
    return NULL;
}


void * consumer_fn(void * args)
{
    int myid = (int) args;

    printf("Hello, I am consumer thread #%d, and I am popping a task\n", myid);

    task *t = q_pop();
    t->fn(t->data);

    return NULL;
}

void * producer_fn(void * args)
{
    printf("Hello, I am producer thread\n");

    newTasks[0] = new task;
    newTasks[0]->fn = t0;
    newTasks[0]->data = NULL;
    q_push(newTasks[0]);

    newTasks[1] = new task;
    newTasks[1]->fn = t1;
    newTasks[1]->data = NULL;
    q_push(newTasks[1]);

    newTasks[2] = new task;
    newTasks[2]->fn = t2;
    newTasks[2]->data = NULL;
    q_push(newTasks[2]);

    return NULL;
}


int main()
{
    const int NUM_THREADS = 4;
    pthread_t mythreads[NUM_THREADS];
    pthread_attr_t myattr;
    int err;
    void *returnvalue;

    q_init();

    for(int i=1; i<NUM_THREADS; i++)
    {
        pthread_attr_init(&myattr);
        int err = pthread_create (&mythreads[i], &myattr, consumer_fn, (void *) i);
        pthread_attr_destroy(&myattr);
    }

    producer_fn(NULL);

    for(int i=1; i<NUM_THREADS; i++)
        pthread_join(mythreads[i], &returnvalue);

    return 0;
}