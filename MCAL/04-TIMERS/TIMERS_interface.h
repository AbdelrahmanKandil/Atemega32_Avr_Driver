/*
 * TIMER_interface.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Abdelrahman
 */

#ifndef MCAL_04_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_04_TIMERS_TIMERS_INTERFACE_H_

#define CTC		1
#define NORMAL
void MTIMERS_vInit(void);
void MTIMERS_vSetBusyWait_synch(/*u8 Copy_u8TimerID*/ u32 Copy_u32Ticks);
void MTIMERS_vStartTimer(/*u8 Copy_u8TimerID*/void);
void MTIMERS_vStopTimer(/*u8 Copy_u8TimerID*/void);
void MTIMERS_vSetCallBack(/*u8 Copy_u8TimerID*/void(*fptr)(void));
void MTIMERS_vSetPreloadValue(/**u8 Copy_u8TimerID*/  u16 Copy_u16Preload);
void MTIMERS_vSetCompareMatchValue(/**u8 Copy_u8TimerID*/  u16 Copy_u16OcrValue);
#endif /* MCAL_04_TIMERS_TIMERS_INTERFACE_H_ */
