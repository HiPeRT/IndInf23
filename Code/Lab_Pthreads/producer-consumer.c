#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a = 0;
sem_t mysemaphore;

void * producer_fn(void * arg)
{
    a = 11;

    // We produced the datum; go Signal/Post
    sem_post(&mysemaphore);
}

void * consumer_fn(void * arg)
{
    int b = 5;

    // Cannot consume a before it is produced
    // We must Wait
    sem_wait(&mysemaphore);
    // Ok, let's go...

    printf("a is %d, b is %d\n", a, b);
}

int main()
{
    pthread_attr_t myattr;
    pthread_t producer, consumer;
    void *returnvalue;
    int err;

    // Initialize semaphore
    sem_init(&mysemaphore, 0, 0); // Forget about the former '0', it indicates whether the semaphore is shared among processes

    // Fork two threads
    pthread_attr_init(&myattr);
    err = pthread_create (&consumer, &myattr, consumer_fn, NULL);
    pthread_attr_destroy(&myattr);

    pthread_attr_init(&myattr);
    err = pthread_create (&producer, &myattr, producer_fn, NULL);
    pthread_attr_destroy(&myattr);

    
    // From now on, the two threads are running...

    // Join the two threads
    pthread_join(producer, &returnvalue);
    pthread_join(consumer, &returnvalue);

    return 0;
}
