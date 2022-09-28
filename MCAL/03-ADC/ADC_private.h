/*
 * ADC_private.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Abdelrahman
 */
/*===============================================================================================
*	 - Developer can't Edit in it
*	  - Register _ Definition
*	  - Design :
					- #define	:	Yes
					- Union		:	NO
					- Struct	:	NO

===================================================================================================*/
#ifndef MCAL_03_ADC_ADC_PRIVATE_H_
#define MCAL_03_ADC_ADC_PRIVATE_H_

					/*////////_ADC operates within a frequency range of 50kHz to 200kHz*/
#define PRESCALER_DIV_FACTOR_2_		0b001		// for 16 MHz/2	  = 8   MHz
#define PRESCALER_DIV_FACTOR_4_		0b010		// for 16 MHz/4	  = 4	MHz
#define PRESCALER_DIV_FACTOR_8_		0b011		// for 16 MHz/8	  = 2	MHz
#define PRESCALER_DIV_FACTOR_16_	0b100		// for 16 MHz/16  = 1	MHz
#define PRESCALER_DIV_FACTOR_32_	0b101		// for 16 MHz/32  = 500 KHz
#define PRESCALER_DIV_FACTOR_64_	0b110		// for 16 MHz/64  = 250 KHz
#define PRESCALER_DIV_FACTOR_128_	0b111		// for 16 MHz/128 = 125 KHz

#define VREF_AVCC          					  0b01
#define VREF_AREF         					  0b00
#define VREF_2_56_INTERNAL_VOLT_              0b11
/***************_ADC_REGISTERS_**************/
#define ADMUX           (*(volatile u8*)(0x27)) /*ADC Multiplexer Selection Register –> ADMUX*/
#define ADCSRA          (*(volatile u8*)(0x26)) /*ADC Control and Status Register A –> ADCSRA*/
#define ADCH            (*(volatile u8*)(0x25)) /*ADC Data Register High –> ADCH */
#define ADCL            (*(volatile u8*)(0x24)) /*ADC Data Register LOW –> ADCL */
#define SFIOR            (*(volatile u8*)(0x50))/*Special Function IO Register –> SFIOR*/
#define ADC_Data       (*(volatile u16*)(0x24))/*To READ 2 REGISTER ARE JUST SEQUENTIALY 0X25 + 0X24 */

#endif /* MCAL_03_ADC_ADC_PRIVATE_H_ */


