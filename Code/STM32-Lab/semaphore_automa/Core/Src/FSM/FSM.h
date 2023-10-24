/*
 * FSM.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Gianb
 */

#ifndef SRC_FSM_FSM_H_
#define SRC_FSM_FSM_H_

	#include "main.h"
	#include "../runtime/runtime.h"

	// --- delays in milliseconds --- //
	#define DELAY_S1 5000
	#define DELAY_S2 6000
	#define DELAY_S3 8000
	// ------------------------------ //

	enum State {S0, S1, S2, S3};

	void output_fn 		(int current_state);
	int next_state 		(int current_state);
	int is_final_state 	(int state);

#endif /* SRC_FSM_FSM_H_ */

