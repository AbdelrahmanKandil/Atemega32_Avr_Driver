/*
 * ADC_config.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Abdelrahman
 */

#ifndef MCAL_03_ADC_ADC_CONFIG_H_
#define MCAL_03_ADC_ADC_CONFIG_H_

/*============================================================================
  ==================_Supported Voltage Reference by ADC_======================
  ============================================================================
				_OPTIONS_1_-> [VREF_AREF]
				_OPTIONS_2_-> [VREF_AVCC]
				_OPTIONS_3_-> [VREF_2_56_INTERNAL_VOLT_]
============================================================================*/
			
#define ADC_VREF	VREF_AVCC

/*============================================================================*/
/*==================_Supported Prescaler Options by ADC_======================
  ============================================================================
  ////////_ADC operates within a frequency range of 50kHz to 200kHz////

			_OPTIONS_1_->  [PRESCALER_DIV_FACTOR_2_]		// for 16 MHz/2	  = 8   MHz
			_OPTIONS_2_->  [PRESCALER_DIV_FACTOR_4_]        // for 16 MHz/4	  = 4	MHz
			_OPTIONS_3_->  [PRESCALER_DIV_FACTOR_8_]        // for 16 MHz/8	  = 2	MHz
			_OPTIONS_4_->  [PRESCALER_DIV_FACTOR_16_]       // for 16 MHz/16  = 1	MHz
			_OPTIONS_5_->  [PRESCALER_DIV_FACTOR_32_]       // for 16 MHz/32  = 500 KHz
			_OPTIONS_6_->  [PRESCALER_DIV_FACTOR_64_]       // for 16 MHz/64  = 250 KHz
			_OPTIONS_7_->  [PRESCALER_DIV_FACTOR_128_]		// for 16 MHz/128 = 125 KHz			      */
#define ADC_PRESCALER		PRESCALER_DIV_FACTOR_64_
/*============================================================================*/
#endif /* MCAL_03_ADC_ADC_CONFIG_H_ */
