/*
 * FSM.h
 *
 *  Created on: Oct 11, 2023
 *      Author: Gianb
 */

#ifndef SRC_FSM_FSM_H_
#define SRC_FSM_FSM_H_

	#include "main.h"

	enum State {S0, S1, S2, S3};

	void output_fn 		(int current_state);
	int next_state 		(int current_state, char input);
	int is_final_state 	(int state);

#endif /* SRC_FSM_FSM_H_ */
