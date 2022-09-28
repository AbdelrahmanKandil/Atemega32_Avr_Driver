/*
 * ADC_interface.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Abdelrahman
 */

#ifndef MCAL_03_ADC_ADC_INTERFACE_H_
#define MCAL_03_ADC_ADC_INTERFACE_H_


/***************_FUNCTION_PROTOTYPE_************/
void MADC_vInit(void);
u16	 MADC_u16ReadDigitalValue_synch(u8 Copy_u8Channel); //Synchronous Function
void MADC_vSetCallback(void (*Fptr)(void)); /*or SetCallback*/
void MADC_vEnableInterrupt(void);
void MADC_vDisableInterrupt(void);
void MADC_vSelectChannel(u8 Copy_u8Channel);
void MADC_vStartConversion(u8 Copy_u8Channel);
u16	 MADC_u16ReadDigitalValue_asynch(u8 Copy_u8Channel); //Synchronous Function

#endif /* MCAL_03_ADC_ADC_INTERFACE_H_ */
