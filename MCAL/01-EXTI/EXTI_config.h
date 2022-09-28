
/***************************************************************************************
***************************  - EXTI_config.h				 ****************************
***************************   - Created: 23/9/2022			 ****************************
***************************   - Author: Abdelrahman_Kandil     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/
#ifndef MCAL_01_EXTI_EXTI_CONFIG_H_
#define MCAL_01_EXTI_EXTI_CONFIG_H_


/********_SELECT_THE_SENSE_TRIGGER_CONTROL_OPTIONS_********/
/*_OPTIONS_1_-> [_FALLING_EDGE_] ********/
/*_OPTIONS_2_-> [_RISING_EDGE_] ********/
/*_OPTIONS_3_-> [_LOW_LEVEL_] ********/
/*_OPTIONS_4_-> [_ANY_LOGICAL_CHANGE] ********/

/*****************  MACROS *****************/

#define INT0_TRIG_MODE	_RISING_EDGE_
#define INT1_TRIG_MODE	_FALLING_EDGE_
#define INT2_TRIG_MODE	_FALLING_EDGE_


/*options:
 * ENABLE
 * DISABLE
 */

#define EXTI_INT0_PULLUP        ENABLE
#define EXTI_INT1_PULLUP        ENABLE
#define EXTI_INT1_PULLUP        ENABLE

#define EXTI_INT0_ENABLE        ENABLE
#define EXTI_INT1_ENABLE        ENABLE
#define EXTI_INT2_ENABLE        DISABLE

/*=======================================================================================
===============================     End of guard          ===============================
=========================================================================================*/
#endif /* MCAL_01_EXTI_EXTI_CONFIG_H_ */
