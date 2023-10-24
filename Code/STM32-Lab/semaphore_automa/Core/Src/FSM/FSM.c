/*
 * FSM.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Gianb
 */
#include "FSM.h"

void output_fn (int current_state) {
	switch (current_state) {
		case S0:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			debug("semaphore in S0, all LEDs will be off");
			break;
		case S1:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET  );
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			debug("semaphore in S1, green LED will be on");
			break;
		case S2:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET  );
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET  );
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
			debug("semaphore in S2, green and yellow LEDs will be on");
			break;
		case S3:
			HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET  );
			debug("semaphore in S3, red LED will be on");
			break;
	}
}

int change_state_temporized (int delay, int initial_state, int next_state) {
	uint32_t tickstart = HAL_GetTick();
	while ((HAL_GetTick() - tickstart) < delay) {
		if (next_char () == '0') return initial_state;
	}
	return next_state;
}

int next_state (int current_state) {
	switch (current_state) {
		case S0:
			switch (next_char ()) {
				case '1': return S1;
				default : return S0;
			}
		case S1: return change_state_temporized (DELAY_S1, S0, S2);
		case S2: return change_state_temporized (DELAY_S2, S0, S3);
		case S3: return change_state_temporized (DELAY_S3, S0, S1);
	}
	return -1; // there was an error in the input
}
