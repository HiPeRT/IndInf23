#include <stdio.h>
#include <pthread.h>

#include "utils.h"

#define N_ELEM 16

// This is global, because we want it to be visible both to main() and pthread_fn()
// NOTE as a genral rule, we should NEVER work on global objects, as they represent an uncontrolled dependency
int arr[N_ELEM];

void * pthreads_fn(void * args)
{
    // This is my uniqe and progressive identifier, as assigned by programmer in main()
    int myid = (int) args;
    
    printf("Hello PThreads world! My id is: %u\n", myid);
    //printf("The OS / PThreads runtime, instead, assigned me \\
    //    the following id: %u\n", pthread_self());


    // This is my partition strategy: here, I map the ID of the thread
    // onto the data space, by using it for indexing the array
    // Strategy => Each thread will work on the "myid-th" element of the array
    arr[myid] = arr[myid] * 2;

    // We work on a global object. No need to return anything, here
    return NULL;
}

int main()
{
    // We spawn as many threads as the elements of the array:
    // this means that our data partitioning strategy assigns one array element to each thread
    const unsigned int NUM_THREADS = N_ELEM;

    pthread_t mythreads[NUM_THREADS];
    pthread_attr_t myattr;

    // To store pthreads' return val (not used here, else we'd need an array of these,
    // one for each thread)
    void *returnvalue;

    // Init arr
    for(int i=0; i<N_ELEM; i++)
        arr[i]= i;        

    unsigned long long start = gettime();
    printf("Start at %llu\n", start );
    // Slave threads have id >= 1. Id '0' is reserved for master thread
    for(int i=1; i<NUM_THREADS; i++)                        // ==> FORK
    {
        pthread_attr_init(&myattr);

        // Pass 'i' as the progressive identifier for thread (last argument of pthread_create)
        int err = pthread_create (&mythreads[i], &myattr, pthreads_fn, (void *) i);
        
        pthread_attr_destroy(&myattr);
    }

    // We want the master thread to do the very same work of other threads
    // Master thread has ID '0'
    pthreads_fn((void *) 0);
    
    for(int i=1; i<NUM_THREADS; i++)                        // <== JOIN
        pthread_join(mythreads[i], &returnvalue);

    unsigned long long end = gettime();
    
    printf("End at %llu.\n", end );
    printf("<TOTAL TIME>%llu</TOTAL TIME>\n", end-start );

    // Check (after join!!)
    for(int i=0; i<N_ELEM; i++)
        printf("[CHECK] arr[%d] now is %d\n", i, arr[i]);

    return 0;
}