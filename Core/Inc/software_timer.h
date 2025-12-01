/*
 * software_timer.h
 *
 *  Created on: Nov 30, 2025
 *      Author: tntam
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


#define NumOfTimer	36

extern int timer_flag[NumOfTimer];
extern int TICK;

void setTimer(int index, int duration);
void subTimerRun(int index);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
