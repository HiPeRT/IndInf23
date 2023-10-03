#ifndef __FSM_H__
#define __FSM_H__

/*
 * Computes next state. Returns the following
 *   >=0 : the next state
 *   -1  : input sequence not legal
 *   -2  : we're in final state
 *   -3  : internal error
 */
int nextState(int currState, char input);

/* This function returns zero if s is not the final state */
int isFinalState(int s);

#endif
