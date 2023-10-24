/*
 * next_char_lib.c
 *
 *  Created on: Oct 11, 2023
 *      Author: Gianb
 */


#include "../runtime.h"

int __io_putchar (int ch) {

	HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, 0xFFFFFFFF);

	return ch;
}

int __io_getchar (void) {

	int ch;

	HAL_UART_Receive(&huart1, (uint8_t*)&ch, 1, 0xFFFFFFFF);

	return ch;
}

char next_char () {
	char ch;
	scanf ("%c", &ch);
	return ch;
}

void debug (char str []) {
	printf("[DEBUG] %s\n\r", str);
}

void error (char str []) {
	printf("[ERROR] %s\n\r", str);
}

void info (char str []) {
	printf("[INFO] %s\n\r", str);
}
