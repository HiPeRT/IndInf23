#include <stdio.h>
#include <semaphore.h>

#include "libQ.h"

const int SIZE = 20;
int head, tail;
sem_t empty, full, mutex;
task **q;

void q_push(task* item)
{
    sem_wait(&full);
    sem_wait(&mutex);

    q[head] = item;
	head = (head + 1) % SIZE;

    sem_post(&mutex);
    sem_post(&empty); 
}

task* q_pop()
{
    sem_wait(&empty);
    sem_wait(&mutex);

	task* elem = q[tail];
	tail = (tail + 1) % SIZE;

    sem_post(&mutex);
    sem_post(&full);

    return elem;
}

void q_init()
{
    q = new task*[SIZE];
    head=0;
    tail=0;
    
    sem_init(&empty, 0, 0);
    sem_init(&full, 0, SIZE);
    sem_init(&mutex, 0, 1);
}