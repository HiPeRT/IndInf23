/*
 * FSM.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Gianb
 */
#include "FSM.h"

void output_fn (int current_state) {
	switch (current_state) {
		case S0:
			HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_SET  );
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
			break;
		case S1:
			HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_SET  );
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
			break;
		case S2:
			HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_SET  );
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_RESET);
			break;
		case S3:
			HAL_GPIO_WritePin(S0_GPIO_Port, S0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S1_GPIO_Port, S1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S2_GPIO_Port, S2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(S3_GPIO_Port, S3_Pin, GPIO_PIN_SET  );
			break;
	}
}

int next_state (int current_state, char input) {
	switch (current_state) {
		case S0:
			switch (input) {
				case 'a': return S1;
				case 'b': return S2;
				case 'c': return S3;
			}
		break;
		case S1:
			switch (input) {
				case 'a': return S0;
				case 'b': break;
				case 'c': return S3;
			}
		break;
		case S2:
			switch (input) {
				case 'a': break;
				case 'b': return S2;
				case 'c': return S3;
			}
		break;
		case S3: 	return -2;	// is final state
		default: 	return -3;	// wrong state
	}
	return -1; // there was an error in the input
}

int is_final_state (int state) {
	return state == S3;
}
