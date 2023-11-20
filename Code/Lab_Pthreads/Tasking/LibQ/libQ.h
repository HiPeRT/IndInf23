#pragma once

typedef struct q_item
{
    void* (*fn)(void*);
    void *data;
} task;

void q_push(task* item);

task* q_pop();

void q_init();