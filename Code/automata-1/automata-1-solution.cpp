#include <iostream>

using namespace std;

const char inputs[] = {'a', 'a', 'b', 'c'};
int ninputs = sizeof(inputs) / sizeof(inputs[0]);

/* Gets next inputs, or 'x' if no inputs available */
char next()
{
	static int i = 0;
	if(i >= ninputs)
		return 'x';
	return inputs[i++];
}

/*
 * Computes next state. Returns the following
 *   >0 : the next state
 *   -1 : input sequence not legal
 *   -2 : we're in final state
 *   -3 : internal error
 */
int nextState(int currState, char input)
{
	switch(currState)
	{
		case 0:
			switch(input)
			{
				case 'a': return 2;
				case 'b': return 1;
				case 'c': return 3;
				default:  break;
			}
			break;
			
		case 1:
			switch(input)
			{
				case 'a': break;
				case 'b': return 1;
				case 'c': return 3;
				default:  break;
			}
			break;
			
		case 2:
			switch(input)
			{
				case 'a': return 0;
				case 'b': break;
				case 'c': break;
				default: break;
			}
			break;
			
		case 3:
			return -2;
			
		default:
			return -3;
	}
	
	// If we're here, it's an error
	return -1;
}

bool isFinalState(int s)
{
	return s == 3;
}

int main()
{
	cout << "Inputs size is " << ninputs << endl;
	int currState = 0;
	int state = -1;
	char c;
	
	while(1)
	{
		// Get next input
		c = next();
		
		// We ran out of inputs, and
		if(c == 'x')
		{
			if(!isFinalState(currState))
				goto error;
			// This should never happen, if our algo works well
			else
				break;
		}
		
		cout << "Next input word is " << c << ", current state is " << currState << endl;
		
		state = nextState(currState, c);
		
		// Check for errors
		if(state < 0)
			goto error;
		
		cout << "Next state will be " << state << endl;
		
		if(isFinalState(state))
			break;
		
		// Update curr state
		currState = state;
	}
	
	cout << "Input sequence is legal for our Language" << endl;
	return 0;

error:
	cout << "ERROR!" << endl;
	cout << "Input " << c << " not legal for state " << currState << endl;
	cout << "Error code is " << state << endl;
	return state;
}