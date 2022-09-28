/*
 * GIE_program.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Abdelrahman
 */
/**/

/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "../../LIB/STD_TYPES.h"
		 #include "../../LIB/BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "GIE_private.h"
		#include "GIE_interface.h"
		#include "GIE_config.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/


/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
void MGIE_vEnable(void)
{
	SET_BIT(SREG,I_BIT);
}
void MGIE_vDisable(void)
{
	CLEAR_BIT(SREG,I_BIT);
}

