/*
 * software_timer.c
 *
 *  Created on: Nov 30, 2025
 *      Author: tntam
 */

#include "software_timer.h"

int timer_counter[NumOfTimer] = {0};
int timer_flag[NumOfTimer] = {0};

int TICK = 10;

void setTimer(int index, int duration){
	timer_counter[index] = duration / TICK;
	timer_flag[index] = 0;
}

void subTimerRun(int index){
	if(timer_counter[index] > 0){
		timer_counter[index]--;
		if(timer_counter[index] <= 0){
			timer_flag[index] = 1;
		}
	}
}

void timerRun(){
	subTimerRun(0);

}
