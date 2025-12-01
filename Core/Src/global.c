/*
 * global.c
 *
 *  Created on: Nov 30, 2025
 *      Author: tntam
 */


#include "global.h"


uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

int command_flag = NORMAL;
int command_data = 0;

int status_uart = UART_IDLE;
