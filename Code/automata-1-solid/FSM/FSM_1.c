#include "runtime.h"

int nextState(int currState, char input)
{
    debug ("nextState()\n");
    switch(currState)
    {
        case 0: // if in S0
            switch(input)
            {
                case 'a':
                    write ("output is 4\n");
                    return 2;
                case 'b':
                    write ("output is 2\n");
                    return 1;
                case 'c':
                    write ("output is 9\n");
                    return 3;
                default:
                    break;
            }
            break;

        case 1: // if I am in S1
            switch(input)
            {
                case 'a':
                    break;
                case 'b':
                    write ("output is 1\n");
                    return 1;
                case 'c':
                    write ("output is 6\n");
                    return 3;
                default:
                    break;
            }
            break;

        case 2: // if I am in S2
            switch(input)
            {
                case 'a':
                    write ("output is 5\n");
                    return 0;
                case 'b':
                    break;
                case 'c':
                    break;
                default:
                    break;
            }
            break;

        case 3: // if I am in S3
            return -2;

        default: // if I am in S>4
            return -3;
    }

    // If we're here, it's an error
    return -1;
}

int isFinalState(int s)
{
    return s == 3;
}