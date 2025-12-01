/*
 * command_parser.c
 *
 *  Created on: Nov 30, 2025
 *      Author: tntam
 */


#include "command_parser.h"
#include "string.h"

void command_parser_fsm(){
	buffer[index_buffer] = '\0';

	//detect string !RST#
	char *rst_ptr = strstr((char *)buffer, "!RST#");
	if(rst_ptr != NULL){
		command_flag = RST_DETECTED;
		//reset buffer
		index_buffer = 0;
		buffer[0] = '\0';
		return;
	}

	//detect string !OK#
	char *ok_ptr = strstr((char *)buffer, "!OK#");
	if(ok_ptr != NULL){
		command_flag = OK_DETECTED;
		//reset buffer
		index_buffer = 0;
		buffer[0] = '\0';
		return;
	}

    if(index_buffer >= MAX_BUFFER_SIZE - 1){
        index_buffer = 0;
        buffer[0] = '\0';
    }

}
