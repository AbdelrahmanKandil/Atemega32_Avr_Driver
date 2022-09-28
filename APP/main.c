#define Code_Interrupt	0
#define Code_TIMERS		0
/*===========   INCLUDE LIB   ===========*/
		#include<util/delay.h>
		 #include "../LIB/STD_TYPES.h"
		 #include "../LIB/BIT_MATH.h"
/*======================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "../MCAL/00-DIO/DIO_interface.h"
		#include "../MCAL/01-EXTI/EXTI_interface.h"
		#include "../MCAL/02-GIE/GIE_interface.h"
		#include "../MCAL/03-ADC/ADC_interface.h"
		#include "../MCAL/04-TIMERS/TIMERS_interface.h"


/*======================================*/
/*===========  INCLUDE HAL   ===========*/
		#include"../HAL/LCD/LCD_interface.h"
/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/
#if 0
/*function for interrupt*/
void Toggle(void)
{
	/*Over Flow Mode*/
	static u32 counter =0;
	counter++;
	if(counter == 1954)
	{
		counter =0;
		/*preload*/
		MTIMERS_vSetPreloadValue(224);
		MDIO_vPinToggle(DIO_PORTA,DIO_PIN_0);

	}
}
#endif

void LedToggle(void)
{
static u32 counter =0;
counter++;
	if(counter == 4000)
	{
		counter =0;
		MDIO_vPinToggle(DIO_PORTA,DIO_PIN_0);
	}
}
void LED_ON(void)
{
	MDIO_vSetPinData(DIO_PORTA,DIO_PIN_0,HIGH);
}
void LED_OFF(void)
{
	MDIO_vSetPinData(DIO_PORTA,DIO_PIN_0,LOW);
}

/*=========================================================================*/

int main()
{
#if Code_Interrupt == 1
// /*EXTI CODE*/
	MDIO_vSetPinMode(DIO_PORTA,DIO_PIN_0,OUTPUT);
/*	MEXTI_vInit();
	MEXTI_vSetSenseCtrl(_EXTI_1,_RISING_EDGE_);
	MEXTI_vSetCallback(_EXTI_0,LED_ON);
	MEXTI_vSetCallback(_EXTI_1,LED_OFF);*/


	/*Enable Interrupt*/
//	MEXTI_vEnableInterrupt(_EXTI_0);
//	MEXTI_vEnableInterrupt(_EXTI_1);

	// /*Enable Global Interrupt*/
	 MGIE_vEnable();

#endif
#if Code_TIMERS ==1
	 /*TIMERS Init*/
MTIMERS_vInit();
/*Timers Call Back Interrupt*/
MTIMERS_vSetCallBack(LedToggle);
// /*Enable Global Interrupt*/
MGIE_vEnable();
/*Using Compare Match*/
MTIMERS_vSetCompareMatchValue(250);
MTIMERS_vStartTimer();
#endif
H_vLcdInit();
	/*ADC Application*/
	//MADC_vInit();

	//u16 Temp_Value =0;
	//Temp_Value= MADC_u16ReadDigitalValue_synch(2);
/**************************************/
//H_vLcdWriteIntNumber(200.5);
//LCD_enuWriteFloatNum(455.66);
H_LcdWriteFloat(100);
while(1)
{

}

}
