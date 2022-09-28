/*
 * TIMER_private.h
 *
 *  Created on: Sep 24, 2022
 *      Author: Abdelrahman
 */

#ifndef MCAL_04_TIMERS_TIMERS_PRIVATE_H_
#define MCAL_04_TIMERS_TIMERS_PRIVATE_H_

#define FOC0   7
#define WGM00  6
#define WGM01  3
#define COM01  5
#define COM00  4
#define TOIE0  0
#define OCIE0  1
#define TOV0   0

#define PRESCALER_NO_CLOCK	0b000
#define NO_PRESCALER	    0b001
#define PRESCALER_8			0b010

////////TIMER_0_REGISTERS_///////////////
#define TCNT0  (*(volatile u8*)(0x52))
#define TCCR0  (*(volatile u8*)(0x53))
#define TIMSK  (*(volatile u8*)(0x59))
#define OCR0   (*(volatile u8*)(0x5C))
#define TIFR   (*(volatile u8*)(0x58))

#endif /* MCAL_04_TIMERS_TIMERS_PRIVATE_H_ */
