#include <stdio.h>

#include <pthread.h>

// Thiese are global, because we want it to be visible both to main() and pthread_fn()
// NOTE as a genral rule, we should NEVER work on global objects, as they represent an uncontrolled dependency
const int N_ELEM = 16;
int arr[N_ELEM];

const unsigned int NUM_THREADS = 4;

// Local sums (for Reduction pattern)
int sum_local[NUM_THREADS];

void * pthreads_fn(void * args)
{
    // This is my uniqe and progressive identifier, as assigned by programmer in main()
    int myid = (int) args;

    // Init my local sum
    sum_local[myid] = 0;

    // MOTE We assume N_ELEM is a multiple of NUM_THREADS!!
    int chunk = N_ELEM / NUM_THREADS;
    int istart = chunk * myid;
    int iend = istart + chunk;

    for(int i = istart; i<iend; i++ )
        sum_local[myid] = sum_local[myid] + arr[i];

    // We work on global objects (discouraged)
    return NULL;
}

int main()
{
    pthread_t mythreads[NUM_THREADS];
    pthread_attr_t myattr;

    // To store pthreads' return val (not used here, else we'd need an array of these,
    // one for each thread)
    void *returnvalue;

    // Init arr
    for(int i=0; i<N_ELEM; i++)
        arr[i]= i;        

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

    int sum = 0;
    for(int i=0; i<NUM_THREADS; i++)
        sum += sum_local[i];

    // Check (after join!!)
    printf("[CHECK] average value is %f\n", ((float) sum) / N_ELEM);

    return 0;
}