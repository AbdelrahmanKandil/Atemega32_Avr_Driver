/****************************** *********************************************************
 ***************************  - LCD_program.c				 ****************************
***************************   - Created: 11/5/2022			 ****************************
***************************   - Author: Abdelrahman_Kandil     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/
/***
 *      _      _____ _____      _____  _____   ____   _____ _____            __  __
 *     | |    / ____|  __ \    |  __ \|  __ \ / __ \ / ____|  __ \     /\   |  \/  |
 *     | |   | |    | |  | |   | |__) | |__) | |  | | |  __| |__) |   /  \  | \  / |
 *     | |   | |    | |  | |   |  ___/|  _  /| |  | | | |_ |  _  /   / /\ \ | |\/| |
 *     | |___| |____| |__| |   | |    | | \ \| |__| | |__| | | \ \  / ____ \| |  | |
 *     |______\_____|_____/    |_|    |_|  \_\\____/ \_____|_|  \_\/_/    \_\_|  |_|
 *
 *
 */
/*=======================================================================================
============================   The Foundation Of Function   =============================
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include <util/delay.h>
		 #include "../../LIB/STD_TYPES.h"
		 #include "../../LIB/BIT_MATH.h"
/*=====================================*/
/*===========  INCLUDE MCAL  ===========*/
		#include "../../MCAL/00-DIO/DIO_interface.h"
/*======================================*/
/*===========  INCLUDE HAL   ===========*/
		#include "LCD_config.h"
		#include "LCD_private.h"
     	#include"LCD_interface.h"
/*======================================*/

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/


static void H_LcdWriteNumber(f64 f64_local_number);

/*==================================================== Start_FUNCTION  ====================================================*/

void H_vLcdInit(void)
{
	// LCD_DATA_PORT = 0xff ;

	// SET_BIT(LCD_CONTROL_PORT , LCD_RS_PIN);
	// SET_BIT(LCD_CONTROL_PORT , LCD_RW_PIN);
	// SET_BIT(LCD_CONTROL_PORT , LCD_EN_PIN);

	// _delay_ms(50);
	// LCD_SendCommand(0b00111000);
	// _delay_ms(1);
	// LCD_SendCommand(0b00001100);
	// _delay_ms(1);
	// LCD_SendCommand(0b00000001);
	// _delay_ms(2);
	// LCD_SendCommand(0b00000110);
	// _delay_ms(1);
		
		MDIO_vSetPinMode(LCD_CONTROL_PORT ,LCD_RS_PIN ,OUTPUT  );
		MDIO_vSetPinMode(LCD_CONTROL_PORT ,LCD_EN_PIN ,OUTPUT  );
		MDIO_vSetPinMode(LCD_CONTROL_PORT ,LCD_RW_PIN ,OUTPUT  );


#if LCD_MODE     ==   _8_BIT_MODE
		MDIO_vSetPortMode (LCD_DATA_PORT , 0xff);
	
		/*_THIS_COMMAND_TO_LEAVE_TIME_LCD MCU_POWER UP_AND_FIX_PROPLEM_OF_STARTUP_CODE_RUNNING*/
		_delay_ms(500);
		/*_THIS_COMMAND_TO_ACTIVE_8_BIT_MODE_*/
		H_vLcdWriteCommand(LCD_FUNCSET_8BIT);			/*THIS_COMMAND_TO_ACTIVE_8_BIT_MODE_*/
		_delay_ms(1);
		H_vLcdWriteCommand(LCD_DISPON_CURSOFF);         /*_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_*/
		_delay_ms(1);
		H_vLcdWriteCommand(LCD_HOME);                   /*_THIS_COMMAND_TO_RETURN_HOME_*/
		_delay_ms(1);
		H_vLcdWriteCommand(LCD_ENTRYMODE);              /*_THIS_COMMAND_TO_DISPLAY_FROM_LEFT_TO_RIGHT_*/
		_delay_ms(1);
		H_vLcdWriteCommand(LCD_CLR);                    /*_THIS_COMMAND_TO_CLEAR_LCD_*/
		_delay_ms(1);
#elif 	LCD_MODE == _4_BIT_MODE
		MDIO_vSetPinMode(LCD_DATA_PORT ,LCD_DATA_PIN_4 ,OUTPUT  );
		MDIO_vSetPinMode(LCD_DATA_PORT ,LCD_DATA_PIN_5 ,OUTPUT  );
		MDIO_vSetPinMode(LCD_DATA_PORT ,LCD_DATA_PIN_6 ,OUTPUT  );
		MDIO_vSetPinMode(LCD_DATA_PORT ,LCD_DATA_PIN_7 ,OUTPUT  );
		/*_THIS_COMMAND_TO_LEAVE_TIME_LCD MCU_POWER UP_AND_FIX_PROPLEM_OF_STARTUP_CODE_RUNNING*/
		_delay_ms(500);
		/*_THIS_3_COMMANDS_TO_ACTIVE_4_BIT_MODE_*/
		H_vLcdWriteCommand(LCD_FUNSET_4BIT_C1);
		H_vLcdWriteCommand(LCD_FUNSET_4BIT_C2);
		H_vLcdWriteCommand(LCD_FUNSET_4BIT_C3);
		H_vLcdWriteCommand(LCD_DISPON_CURSOFF);         /*_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_*/
		H_vLcdWriteCommand(LCD_HOME);                   /*_THIS_COMMAND_TO_RETURN_HOME_*/
		H_vLcdWriteCommand(LCD_ENTRYMODE);              /*_THIS_COMMAND_TO_DISPLAY_FROM_LEFT_TO_RIGHT_*/
		H_vLcdWriteCommand(LCD_CLR);                    /*_THIS_COMMAND_TO_CLEAR_LCD_*/

#endif



}


/*==================================================== End_FUNCTION  ====================================================*/



/*====================================================   Start_FUNCTION   ====================================================*/

void H_vLcdWriteCommand(u8 Copy_u8Command)
{
	// /*select RS -> 1*/
	// CLR_BIT(LCD_CONTROL_PORT , LCD_RS_PIN);
	// /*select RW*/
	// CLR_BIT(LCD_CONTROL_PORT , LCD_RW_PIN);
	// /*put data on LCD pins*/
	// LCD_DATA_PORT = Copy_u8Command ;

	// /*pulse on Enable*/
	// SET_BIT(LCD_CONTROL_PORT , LCD_EN_PIN);
	// _delay_ms(1);
	// CLR_BIT(LCD_CONTROL_PORT , LCD_EN_PIN);
	// _delay_ms(1);


	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_RS_PIN ,LOW);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_RW_PIN ,LOW);

	#if LCD_MODE    ==   _8_BIT_MODE
	MDIO_vSetPortData(LCD_DATA_PORT,Copy_u8Command);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,HIGH);
	_delay_ms(1);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,LOW);
	_delay_ms(5);

	#elif LCD_MODE    ==   _4_BIT_MODE
				/***SEND_HIGH_PART***/
	MDIO_vSetPortData(LCD_DATA_PORT,((Copy_u8Command & 0b1111000) | (LCD_DATA_PORT & 0b00001111)));
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,HIGH);
	_delay_ms(1);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,LOW);
	_delay_ms(5);
	
		/***SEND_LOW_PART***/

	MDIO_vSetPortData(LCD_DATA_PORT,((Copy_u8Command<<4) | (LCD_DATA_PORT & 0b00001111)));
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,HIGH);
	_delay_ms(1);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,LOW);
	_delay_ms(5);
	#endif
}


/*====================================================   Start_FUNCTION   ====================================================*/
void H_vLcdWriteCharacter(u8 Copy_u8Character)
{
	// /*select RS -> 1*/
	// SET_BIT(LCD_CONTROL_PORT , LCD_RS_PIN);
	// /*select RW*/
	// CLR_BIT(LCD_CONTROL_PORT , LCD_RW_PIN);
	// /*put data on LCD pins*/
	// LCD_DATA_PORT = Copy_u8Character ;

	// /*pulse on Enable*/
	// SET_BIT(LCD_CONTROL_PORT, LCD_EN_PIN);
	// _delay_ms(1);
	// CLR_BIT(LCD_CONTROL_PORT , LCD_EN_PIN);
	// _delay_ms(1);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_RS_PIN ,HIGH);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_RW_PIN ,LOW);


	#if LCD_MODE    ==  _8_BIT_MODE
	MDIO_vSetPortData(LCD_DATA_PORT,Copy_u8Character);
	//LCD_DATA_PORT = Copy_u8Character;
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,HIGH);
	_delay_ms(1);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,LOW);
	_delay_ms(5);

	#elif LCD_MODE    ==   _4_BIT_MODE
					/***SEND_HIGH_PART***/
	MDIO_vSetPortData(LCD_DATA_PORT,( (Copy_u8Character & 0b1111000) | (LCD_DATA_PORT & 0b00001111) ) );
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,HIGH);
	_delay_ms(1);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,LOW);
	_delay_ms(5);
			/***SEND_LOW_PART***/
	MDIO_vSetPortData(LCD_DATA_PORT,((Copy_u8Character<<4) | (LCD_DATA_PORT & 0b00001111)));
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,HIGH);
	_delay_ms(1);
	MDIO_vSetPinData(LCD_CONTROL_PORT ,LCD_EN_PIN ,LOW);
	_delay_ms(5);
	#endif
}

/*==================================================== End_FUNCTION  ====================================================*/

void H_LcdWriteIntNumber(s32 Copy_s32Number)
{
	s32 rev=0;
		u8 counter =0;
	if (Copy_s32Number <0)
	{
		H_vLcdWriteCharacter('-');
		Copy_s32Number*=-1;
	}


	if(Copy_s32Number%10 == 0)
	{
		Copy_s32Number++;
	}

			while(Copy_s32Number>0)
			{
				rev = (rev*10) + (Copy_s32Number%10);
				Copy_s32Number/=10;
				counter++;
			}


			while(rev > 0)
			{
				if (rev == 1)
				{
					rev-=1;
				}

				H_vLcdWriteCharacter((rev%10)+'0');
				rev/=10;
				counter--;
			}
}

static void H_LcdWriteNumber(f64 f64_local_number)
{
	s32 s32_local_number_copy = f64_local_number;
	u8 u8_local_arr [10] = {0};
	s8 s8_local_counter = 0;
	if(s32_local_number_copy == 0)
	{
		H_vLcdWriteCharacter('0');
	}
	else if(s32_local_number_copy < 0)
	{
		H_vLcdWriteCharacter('-');
		s32_local_number_copy = s32_local_number_copy * (-1);
	}
	while(s32_local_number_copy != 0)
	{
		u8_local_arr [s8_local_counter] = s32_local_number_copy % 10;
		s8_local_counter++;
		s32_local_number_copy = s32_local_number_copy / 10;
	}
	s8_local_counter--;
	while (s8_local_counter >= 0)
	{
		H_vLcdWriteCharacter(u8_local_arr[s8_local_counter] + '0');
		s8_local_counter--;
	}
}
void H_LcdWriteFloat(f64 f64_local_number)
{
	u8 u8_local_counter = 0;
	s32 s32_local_Number_copy = f64_local_number;
	f64 f64_local_fraction_copy = f64_local_number - s32_local_Number_copy;
	if(f64_local_fraction_copy == 0)
	{
		H_LcdWriteNumber(f64_local_number);
	}
	else
	{
		if(f64_local_number < 0 && s32_local_Number_copy == 0 )
		{
			H_vLcdWriteCharacter('-');
		}
		H_LcdWriteNumber(f64_local_number);
		H_vLcdWriteCharacter('.');
		if(f64_local_number < 0)
		{
			f64_local_fraction_copy*=-1;
		}
		else{}
		for (u8_local_counter=0;u8_local_counter < AFTER_DECIMAL;u8_local_counter++)
		{
			f64_local_fraction_copy *= 10;
		}

		H_LcdWriteNumber(f64_local_fraction_copy);

	}
}
/*==================================================== End_FUNCTION  ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/

void H_vLcdWriteString(u8 str[])
{
	/*for(int i=0; str[i]!='\0'; i++)
		{
			H_vLcdWriteCharacter(str[i]);
		}*/

	while(*str!='\0')
	{
		H_vLcdWriteCharacter(*str);
		str++;
	}
}

/*==================================================== End_FUNCTION  ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void H_LcdClear(void)
{
	H_vLcdWriteCommand(LCD_CLR); /*0x01 is a command registered in LCD ROM and LCD_MC will interpret it*/
}

/*==================================================== End_FUNCTION  ====================================================*/

/*====================================================   Start_FUNCTION   ====================================================*/
void H_vLcdGoTo(u8 Copy_u8Row,u8 Copy_u8Col)
{
	u8 arr[2] = {0x80,0xC0};
	H_vLcdWriteCommand(arr[Copy_u8Row]+Copy_u8Col);
}


/*==================================================== End_FUNCTION  ====================================================*/



