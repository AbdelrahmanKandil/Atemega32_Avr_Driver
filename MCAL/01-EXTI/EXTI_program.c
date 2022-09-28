/*
 * EXTI_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Abdelrahman
 */
/***************************************************************************************

***************************  - EXTI_program.c				 ****************************
***************************   - Created: 23/9/2022			 ****************************
***************************   - Author: Abdelrahman_Kandil     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/
/***
 *      ________   _________ _____    _____
 *     |  ____\ \ / /__   __|_   _|  |  __ \
 *     | |__   \ V /   | |    | |    | |__) | __ ___   __ _ _ __ __ _ _ __ ___
 *     |  __|   > <    | |    | |    |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \
 *     | |____ / . \   | |   _| |_   | |   | | | (_) | (_| | | | (_| | | | | | |
 *     |______/_/ \_\  |_|  |_____|  |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|
 *                                                     __/ |
 *                                                    |___/
 */

/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "../../LIB/STD_TYPES.h"
		 #include "../../LIB/BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "../00-DIO/DIO_interface.h"
		#include "EXTI_private.h"
		#include "EXTI_interface.h"
		#include "EXTI_config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
static void (*GPtr_EXTI0_CallBack_Fun)(void) ;
static void (*GPtr_EXTI1_CallBack_Fun)(void) ;
static void (*GPtr_EXTI2_CallBack_Fun)(void) ;

void MEXTI_vInit(void)
{
	#if EXTI_INT0_ENABLE == ENABLE
		/* 1- Make pins Input*/
		MDIO_vSetPinMode(DIO_PORTD,DIO_PIN_2,INPUT);
		/*Enable Pull Up*/
	#if EXTI_INT0_PULLUP == ENABLE

		MDIO_vSetPinData(DIO_PORTD,DIO_PIN_2,HIGH);
	#endif
				/* 2- sense control -> select trigger mode in MCUCR*/
			#if INT0_TRIG_MODE == _FALLING_EDGE_
				CLEAR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
			#elif  INT0_TRIG_MODE == _RISING_EDGE_

				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);

			#elif  INT0_TRIG_MODE == _ANY_LOGICAL_CHANGE

				CLEAR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);

			#elif  INT0_TRIG_MODE == _LOW_LEVEL_

				CLEAR_BIT(MCUCR,0);
				CLEAR_BIT(MCUCR,1);
			#else
			#error "EXT_INT_ERROR: INT0->No Trigger Mode selected"
			#endif


	#endif

	#if EXTI_INT1_ENABLE == ENABLE
				/* 1- Make pins Input*/
			MDIO_vSetPinMode(DIO_PORTD,DIO_PIN_3,INPUT);
			/*Enable Pull Up*/
	#if EXTI_INT1_PULLUP == ENABLE
			MDIO_vSetPinData(DIO_PORTD,DIO_PIN_3,HIGH);
	#endif
			#if INT1_TRIG_MODE == _FALLING_EDGE_
				CLEAR_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
			#elif  INT1_TRIG_MODE == _RISING_EDGE_

				SET_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);

			#elif  INT1_TRIG_MODE == _ANY_LOGICAL_CHANGE

				CLEAR_BIT(MCUCR,3);
				SET_BIT(MCUCR,2);

			#elif  INT1_TRIG_MODE == _LOW_LEVEL_

				CLEAR_BIT(MCUCR,2);
				CLEAR_BIT(MCUCR,3);
			#else
			#error "EXT_INT_ERROR: INT1->No Trigger Mode selected"
			#endif


	#endif

	#if EXTI_INT2_ENABLE == ENABLE
				/* 1- Make pins Input*/
			MDIO_vSetPinMode(DIO_PORTB,DIO_PIN_2,INPUT);

			/*Enable Pull Up*/
	#if EXTI_INT2_PULLUP == ENABLE
			MDIO_vSetPinData(DIO_PORTB,DIO_PIN_2,HIGH);
	#endif

			#if INT2_TRIG_MODE == FALLING_EGDE
				CLEAR_BIT(MCUCSR,6);
			#elif INT2_TRIG_MODE == RISING_EGDE
				SET_BIT(MCUCSR,6);
			#else
			#error "EXT_INT_ERROR: INT2->No Trigger Mode selected"
			#endif

	#endif
}
void MEXTI_vSetSenseCtrl(u8 Copy_u8ExtiPin ,u8 Copy_u8SenseCtrl)
{
	switch (Copy_u8ExtiPin)
	{
		case _EXTI_0:	
		switch(Copy_u8SenseCtrl)
		{
			case _FALLING_EDGE_:
				CLEAR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
			break;
			case _RISING_EDGE_:
				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
			break;
			case _LOW_LEVEL_:
				CLEAR_BIT(MCUCR,0);
				CLEAR_BIT(MCUCR,1);
			break;
			case _ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR,0);
				CLEAR_BIT(MCUCR,1);
			break;			
		}
		break;
		case _EXTI_1:
		switch(Copy_u8SenseCtrl)
		{
			case _FALLING_EDGE_:
				CLEAR_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
			break;
			case _RISING_EDGE_:
				SET_BIT(MCUCR,2);
				SET_BIT(MCUCR,3);
			break;
			case _LOW_LEVEL_:
				CLEAR_BIT(MCUCR,2);
				CLEAR_BIT(MCUCR,3);
			break;
			case _ANY_LOGICAL_CHANGE:
				SET_BIT(MCUCR,2);
				CLEAR_BIT(MCUCR,3);
			break;			
		}		
		
		break;
		case _EXTI_2:
		switch(Copy_u8SenseCtrl)
		{
			case _FALLING_EDGE_:
				CLEAR_BIT(MCUCSR,6);
			break;
			case _RISING_EDGE_:
				SET_BIT(MCUCSR,6);
			break;

		}		
		
		break;
		default:	/*Error*/				break;
	}
}
void MEXTI_vEnableInterrupt(EXTIx_e Copy_eExtiPin )
{
	switch(Copy_eExtiPin)
	{
	case _EXTI_0:	SET_BIT(GICR,6);				break;
	case _EXTI_1:	SET_BIT(GICR,7);				break;
	case _EXTI_2:	SET_BIT(GICR,5);				break;
	default:										break;
	}
}
void MEXTI_vDisableInterrupt(EXTIx_e Copy_eExtiPin )
{
	switch(Copy_eExtiPin)
	{
	case _EXTI_0:	CLEAR_BIT(GICR,6);				break;
	case _EXTI_1:	CLEAR_BIT(GICR,7);				break;
	case _EXTI_2:	CLEAR_BIT(GICR,5);				break;
	default:										break;
	}
}
void MEXTI_vSetCallback(EXTIx_e Copy_eExtiPin , void (*Fptr)(void)) /*or SetCallback*/
{
	switch(Copy_eExtiPin)
	{
	case _EXTI_0:	GPtr_EXTI0_CallBack_Fun =Fptr;	break;
	case _EXTI_1:	GPtr_EXTI1_CallBack_Fun =Fptr;	break;
	case _EXTI_2:	GPtr_EXTI2_CallBack_Fun =Fptr;	break;
	default:										break;
	}
}

/* __vector_(Number of interrupt in vector table -1) __attribute__((signal))
 *
 * */
void __vector_1(void) __attribute__((signal));//name of function of ISR for special vector (Init0)
void __vector_2(void) __attribute__((signal));//name of function of ISR for special vector (Init1)
void __vector_3(void) __attribute__((signal));//name of function of ISR for special vector (Init2)

void __vector_1(void)
{
	if(GPtr_EXTI0_CallBack_Fun !=NULL)
	{
		GPtr_EXTI0_CallBack_Fun();
	}
}

void __vector_2(void)
{
	if(GPtr_EXTI1_CallBack_Fun !=NULL)
	{
		GPtr_EXTI1_CallBack_Fun();
	}
}

void __vector_3(void)
{
	if(GPtr_EXTI2_CallBack_Fun !=NULL)
	{
		GPtr_EXTI2_CallBack_Fun();
	}
}
