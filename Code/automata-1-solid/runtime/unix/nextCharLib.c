#include "runtime.h"
#include <stdio.h>

const char inputs[] = {'a', 'a', 'b', 'c'};
int ninputs = sizeof(inputs) / sizeof(inputs[0]);

char nextChar()
{
    static int i = 0;
    if (i >= ninputs)
        return 'x';
    return inputs[i++];
}

void write(char str[])
{
    printf("%s\n", str);
}

void debug(char str[])
{
    printf("[DEBUG] %s\n", str);
}