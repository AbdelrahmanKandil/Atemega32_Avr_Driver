/*
 * TIMER0_program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: Abdelrahman
 */

/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "../../LIB/STD_TYPES.h"
		 #include "../../LIB/BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "../04-TIMERS/TIMERS_config.h"
#include "../04-TIMERS/TIMERS_interface.h"
#include "../04-TIMERS/TIMERS_private.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

static void (*TIMER0_OVF_Callback)(void);
static void (*TIMER0_CTC_Callback)(void);

void MTIMERS_vInit(void)
{


	/* 1- Select Wave Generation mode*/
#if TIMER0_MODE == NORMAL
		CLEAR_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,WGM00);
#elif TIMER0_MODE == CTC
		SET_BIT(TCCR0,WGM01);
		CLEAR_BIT(TCCR0,WGM00);
#endif
	/* 2- Output Compare Mode*/
	CLEAR_BIT(TCCR0,COM00);
	CLEAR_BIT(TCCR0,COM01);

	/* 3- Preload*/
	TCNT0=TIMER0_PRELOAD;
	/* 4- Interrupt Over Flow EN/DIS*/
//	SET_BIT(TIMSK,TOV0);
	/* Interrupt compare Match EN/DIS*/
	SET_BIT(TIMSK,OCIE0);
	/* 5- */

	/*PWM Mode : 1- Disable Interrupts
	 * 			 2- Select WMP Mode
	 * 			 3- PWM: Non-Converting Mode in Compare Mode */
}
void MTIMERS_vSetBusyWait_synch(u32 Copy_u32Ticks)
{
	
}
void MTIMERS_vStartTimer(/*u8 Copy_u8TimerID*/void)
{
	TCCR0=  (TCCR0 & ~(0b111))|(TIMER0_PRESCALER);

}
void MTIMERS_vStopTimer(/*u8 Copy_u8TimerID*/void)
{
	TCCR0=  (TCCR0 & ~(0b111))|(NO_PRESCALER);

}
void MTIMERS_vSetCallBack(/*u8 Copy_u8TimerID*/void(*fptr)(void))
{
	//TIMER0_OVF_Callback =fptr;
	TIMER0_CTC_Callback=fptr;
}

void MTIMERS_vSetPreloadValue(/**u8 Copy_u8TimerID*/  u16 Copy_u16Preload)
{
	TCNT0 = Copy_u16Preload;
}
void MTIMERS_vSetCompareMatchValue(/**u8 Copy_u8TimerID*/  u16 Copy_u16OcrValue)
{
	OCR0 = Copy_u16OcrValue;
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if (TIMER0_OVF_Callback!= NULL)
	{
		TIMER0_OVF_Callback();
	}
}
void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)
{
	if (TIMER0_CTC_Callback!= NULL)
	{
		TIMER0_CTC_Callback();
	}
}
