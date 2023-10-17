/*
 * runtime.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Gianb
 */

#ifndef SRC_RUNTIME_RUNTIME_H_
#define SRC_RUNTIME_RUNTIME_H_

	#include "stdio.h"
	#include "stm32l4xx_hal.h"

	extern UART_HandleTypeDef huart1;

	char next_char ();
	void debug (char str []);
	void error (char str []);
	void info  (char str []);

#endif /* SRC_RUNTIME_RUNTIME_H_ */
