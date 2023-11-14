#include <pthread.h>
#include <stdio.h>

void * thread_fn (void * args) {
    printf("My id is %u\n", pthread_self());

    return NULL;
    // pthread_exit(NULL);
}

int main () {

    const int N = 10;

    pthread_t threads[N];

    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, thread_fn, NULL);  // =====> FORK (open PARREG)
    }
    
    // Now, the man (master) thread can do other useful stuff, here

    // It participates to the parallel computation
    thread_fn ();

    // while other (slave) threads execute in parallel
    
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);  // <===== JOIN (close PARREG)
    }

    printf("Programma terminato\n");

    return 0;
}