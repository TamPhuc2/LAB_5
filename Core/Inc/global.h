/*
 * global.h
 *
 *  Created on: Nov 30, 2025
 *      Author: tntam
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define MAX_BUFFER_SIZE		30

//state of parser fsm
#define NORMAL				0
#define RST_DETECTED		1
#define OK_DETECTED			2

//state  of communication fsm
#define UART_IDLE		10
#define UART_SEND		11
#define UART_WAIT		12

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern int command_flag; // 0: empty, 1: RST, 2: OK

extern int status_uart;  // current state of uart fsm

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;



#endif /* INC_GLOBAL_H_ */
