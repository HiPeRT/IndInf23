#include "runtime.h"
#include "FSM.h"

#include <stdio.h>

int main()
{
	// cout << "Inputs size is " << ninputs << endl;

    write("main");
	int currState = 0;
	int state = -1;
	char c;
	
	while(1)
	{
		// Get next input
		c = nextChar();
		
		// We ran out of inputs, and
		if(c == 'x')
		{
			if(!isFinalState(currState))
				goto error;
			// This should never happen, if our algo works well
			else
				break;
		}


		//debug

		
		state = nextState(currState, c);
		
		// Check for errors
		if(state < 0)
			goto error;
		

		
		if(isFinalState(state))
			break;
		
		// Update curr state
		currState = state;
	}
	
	debug("Input sequence is legal for our Language\n");;
	return 0;

error:
	debug("ERROR!\n");
	//cout << "Input " << c << " not legal for state " << currState << endl;
	//cout << "Error code is " << state << endl;
	return state;
}

