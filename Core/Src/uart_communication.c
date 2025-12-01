/*
 * uart_communication.c
 *
 *  Created on: Nov 30, 2025
 *      Author: tntam
 */


#include "uart_communication.h"
#include "software_timer.h"
#include <stdio.h>
#include <string.h>

uint32_t ADC_value = 0;
char str[30];

void uart_communication_fsm(){
	switch(status_uart){
		case UART_IDLE:
			//next state
			if(command_flag == RST_DETECTED){
				status_uart = UART_SEND;
				command_flag = NORMAL;
			}
			break;
		case UART_SEND:
			//read ADC
			HAL_ADC_PollForConversion(&hadc1, 1000);
			ADC_value = HAL_ADC_GetValue(&hadc1);

			//send uart signal !ADC=1234#
			sprintf(str, "!ADC=%ld#\r\n", ADC_value);
			HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 1000);

			//wait status
			status_uart = UART_WAIT;

			//set timer 3s
			setTimer(0, 3000);
			break;
		case UART_WAIT:
			//next state
			if(command_flag == OK_DETECTED){
				//setTimer(0, 10);
				status_uart = UART_IDLE;
				command_flag = NORMAL;
			}
			else{
				if(timer_flag[0] == 1){
                    // time out 3s -> send again
                    HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 1000);
                    //reset timer s3
                    setTimer(0, 3000);
				}
			}
			break;
		default:
			status_uart = UART_IDLE;
			break;
	}

}
