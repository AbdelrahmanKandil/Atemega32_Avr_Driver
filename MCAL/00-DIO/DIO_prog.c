/***************************************************************************************

***************************  - DIO_program.c				 ****************************
***************************   - Created: 16/9/2022			 ****************************
***************************   - Author: Abdelrahman_Kandil     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/
/***
 *      _____ _____ ____    _____  _____   ____   _____ _____            __  __
 *     |  __ \_   _/ __ \  |  __ \|  __ \ / __ \ / ____|  __ \     /\   |  \/  |
 *     | |  | || || |  | | | |__) | |__) | |  | | |  __| |__) |   /  \  | \  / |
 *     | |  | || || |  | | |  ___/|  _  /| |  | | | |_ |  _  /   / /\ \ | |\/| |
 *     | |__| || || |__| | | |    | | \ \| |__| | |__| | | \ \  / ____ \| |  | |
 *     |_____/_____\____/  |_|    |_|  \_\\____/ \_____|_|  \_\/_/    \_\_|  |_|
 *
 *
 */
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "../../LIB/STD_TYPES.h"
		 #include "../../LIB/BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "DIO_private.h"
		#include "DIO_interface.h"
		#include "DIO_config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Mode Of Pin  
*			1- INPUT
*			2- OUTPUT
*/
void MDIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  )
{
	if(Copy_u8Mode == OUTPUT)
	{
		switch (Copy_u8PortName)
		{
			case DIO_PORTA:	SET_BIT(DDRA,Copy_u8PinNum);   break;
			case DIO_PORTB:	SET_BIT(DDRB,Copy_u8PinNum);   break;
			case DIO_PORTC:	SET_BIT(DDRC,Copy_u8PinNum);   break;
			case DIO_PORTD:	SET_BIT(DDRD,Copy_u8PinNum);   break;
			default : /*ERROR*/ break ;

		}
	}
	else if (Copy_u8Mode == INPUT)
	{
		switch (Copy_u8PortName)
		{
			case DIO_PORTA:	CLEAR_BIT(DDRA,Copy_u8PinNum);   break;
			case DIO_PORTB:	CLEAR_BIT(DDRB,Copy_u8PinNum);   break;
			case DIO_PORTC:	CLEAR_BIT(DDRC,Copy_u8PinNum);   break;
			case DIO_PORTD:	CLEAR_BIT(DDRD,Copy_u8PinNum);   break;
			 default : /*ERROR*/ break ;

		}
	}

}

/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
* Function To Write Data At PIN :
*									  - HIGH
*									  - LOW
*/
void MDIO_vSetPinData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Data)
{

	if(Copy_u8Data == HIGH)
		{
			switch (Copy_u8PortName)
			{
				case DIO_PORTA:	SET_BIT(PORTA,Copy_u8PinNum);   break;
				case DIO_PORTB:	SET_BIT(PORTB,Copy_u8PinNum);   break;
				case DIO_PORTC:	SET_BIT(PORTC,Copy_u8PinNum);   break;
				case DIO_PORTD:	SET_BIT(PORTD,Copy_u8PinNum);   break;
				 default : /*ERROR*/ break ;

			}
		}
		else if (Copy_u8Data == LOW)
		{
			switch (Copy_u8PortName)
			{
				case DIO_PORTA:	CLEAR_BIT(PORTA,Copy_u8PinNum);   break;
				case DIO_PORTB:	CLEAR_BIT(PORTB,Copy_u8PinNum);   break;
				case DIO_PORTC:	CLEAR_BIT(PORTC,Copy_u8PinNum);   break;
				case DIO_PORTD:	CLEAR_BIT(PORTD,Copy_u8PinNum);   break;
				 default : /*ERROR*/ break ;

			}
		}

	}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
 *Function To Read Data From PINx 
 */

u8   MDIO_u8ReadPinData(u8 Copy_u8PortName ,u8 Copy_u8PinNum)
{
	u8 L_u8PinData = 0;

			switch (Copy_u8PortName)
			{
				case DIO_PORTA:	L_u8PinData = GET_BIT(PINA,Copy_u8PinNum);   break;
				case DIO_PORTB:	L_u8PinData = GET_BIT(PINB,Copy_u8PinNum);   break;
				case DIO_PORTC:	L_u8PinData = GET_BIT(PINC,Copy_u8PinNum);   break;
				case DIO_PORTD:	L_u8PinData = GET_BIT(PIND,Copy_u8PinNum);   break;
				 default : /*ERROR*/ break ;

			}
		return L_u8PinData;
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
 *Function To Toggle PINx  
 */
void MDIO_vPinToggle(u8 Copy_u8PortName ,u8 Copy_u8PinNum )
{

			switch (Copy_u8PortName)
			{
				case DIO_PORTA: TOGGLE_BIT(PORTA,Copy_u8PinNum);   break;
				case DIO_PORTB: TOGGLE_BIT(PORTB,Copy_u8PinNum);   break;
				case DIO_PORTC: TOGGLE_BIT(PORTC,Copy_u8PinNum);   break;
				case DIO_PORTD: TOGGLE_BIT(PORTD,Copy_u8PinNum);   break;
				 default : /*ERROR*/ break ;

			}
}


/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*	Function Set The Mode Of PORTx  
*			1- INPUT
*			2- OUTPUT
*/
void MDIO_vSetPortMode(u8 Copy_u8PortName ,u8 Copy_u8Mode  )
{	
		switch (Copy_u8PortName)
		{
			case DIO_PORTA:	DDRA = Copy_u8Mode;   break;
			case DIO_PORTB:	DDRB = Copy_u8Mode;   break;
			case DIO_PORTC:	DDRC = Copy_u8Mode;   break;
			case DIO_PORTD:	DDRD = Copy_u8Mode;   break;
			default : /*ERROR*/ break ;

		}
}
/*====================================================   END_ FUNCTION   ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
/*
 *Function To Read Data From PORTx Register
 */

u8   MDIO_u8ReadPortData(u8 Copy_u8PortName ,u8 Copy_u8Data)
{
		u8 L_u8PortData = 0;

			switch (Copy_u8PortName)
			{
				case DIO_PORTA:	L_u8PortData = PINA;   break;
				case DIO_PORTB:	L_u8PortData = PINB;   break;
				case DIO_PORTC:	L_u8PortData = PINC;   break;
				case DIO_PORTD:	L_u8PortData = PIND;   break;
				 default : /*ERROR*/ break ;

			}
		return L_u8PortData;
}

/*====================================================   END_ FUNCTION   ====================================================*/
/*====================================================   Start_FUNCTION   ====================================================*/
/*
* Function To Write Data At PIN Register :
*									  - HIGH
*									  - LOW
*/
void MDIO_vSetPortData(u8 Copy_u32PortName ,u8 Copy_u8Data)
{
			switch (Copy_u32PortName)
			{
				case DIO_PORTA:	PORTA = Copy_u8Data;   break;
				case DIO_PORTB:	PORTB = Copy_u8Data;   break;
				case DIO_PORTC:	PORTC = Copy_u8Data;   break;
				case DIO_PORTD:	PORTD = Copy_u8Data;   break;
				 default : /*ERROR*/ break ;

			}
}

