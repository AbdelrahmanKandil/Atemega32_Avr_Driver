/*
 * ADC_program.c
 *
 *  Created on: Sep 23, 2022
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
		#include "ADC_private.h"
		#include "ADC_interface.h"
		#include "ADC_config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


void MADC_vInit(void)
{
	/* 1- Select Reference bits*/
	ADMUX = ((ADMUX & ~(0b11<<6)) |(ADC_VREF<<6)); // Make Mask to clear bit 6 and 7 and write on them 1 and zero
	//ADMUX &=~(0b11<<6);
	//ADMUX |=(ADC_VREF<<6);
	/* 2- Select data adjust*/
	CLEAR_BIT(ADMUX,5);
	/* 3- ADC Enable*/
	SET_BIT(ADCSRA,7);
	/* 4- Auto Trigger Disable/Enable*/
	CLEAR_BIT(ADCSRA,5);
	/* 4- select auto trigger source*/
	/*By Default in Reset*/
	/* 5- Interrupt Enable/Disable*/
	CLEAR_BIT(ADCSRA,3);
	/* 6- Conversion Clock PRESCALER */  
	ADCSRA &=~(0b111); //to make mask on register to clear the bits i need to write on it .
	#if   ADC_PRESCALER == PRESCALER_DIV_FACTOR_2_
	ADCSRA |=(PRESCALER_DIV_FACTOR_2_); 
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_4_
	ADCSRA |=(PRESCALER_DIV_FACTOR_4_); 
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_8_
	ADCSRA |=(PRESCALER_DIV_FACTOR_8_); 
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_16_
	ADCSRA |=(PRESCALER_DIV_FACTOR_16_); 
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_32_
	ADCSRA |=(PRESCALER_DIV_FACTOR_32_); 
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_64_
	ADCSRA |=(PRESCALER_DIV_FACTOR_64_); 
	#elif ADC_PRESCALER == PRESCALER_DIV_FACTOR_128_
	ADCSRA |=(PRESCALER_DIV_FACTOR_128_); 

	#endif
}
u16	 MADC_u16ReadDigitalValue_synch(u8 Copy_u8Channel)
{
	/* 1- Select Channel*/
	ADMUX &=~(0b11111); //to make mask on register to clear the bits i need to write on it .
	ADMUX |=(Copy_u8Channel &0x07); //0x07 3lshan law el user entered wrong channel 
			//(Copy_u8Channel %8)	//%8  3lshan law el user entered wrong channel 
	/* 2- Start conversion*/
	SET_BIT(ADCSRA,6); 
	/* 3- Wait for conversion complete flag*/
	while((GET_BIT(ADCSRA,4))== 0){/*Just waiting */}; //this is poling
	/* 4- clear flag*/
	SET_BIT(ADCSRA,4); 

	/* 5- Return ADC Value*/
	/*u16 L_u16Value = ( ADCL | ((u16)ADCH<<8) ); //Another Method to Return ADC Value
	  return L_u16Value ;*/
	return ADC_Data;
}
