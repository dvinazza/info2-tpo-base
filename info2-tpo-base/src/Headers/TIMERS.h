/*
 * TIMERS.h
 *
 *  Created on: Nov 30, 2015
 *      Author: Catan
 */

#ifndef TIMERS_H_
#define TIMERS_H_



#define TIMERS 2

void TmrEvent(void);
void AnalizarTimer(void);
void TmrStart(uint8_t Ev,uint8_t t);
void TmrClose(void);
void TmrStop(uint8_t Ev);


#endif /* TIMERS_H_ */
