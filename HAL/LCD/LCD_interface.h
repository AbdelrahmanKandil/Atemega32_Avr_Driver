/*======================================================================================
===========================   - LCD_interface.h			     ===========================
===========================   - Created: 11/5/2022			     ===========================
===========================   - Author: Abdelrahman_Kandil   ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/
/***
 *      _      _____ _____     _____       _             __
 *     | |    / ____|  __ \   |_   _|     | |           / _|
 *     | |   | |    | |  | |    | |  _ __ | |_ ___ _ __| |_ __ _  ___ ___
 *     | |   | |    | |  | |    | | | '_ \| __/ _ \ '__|  _/ _` |/ __/ _ \
 *     | |___| |____| |__| |   _| |_| | | | ||  __/ |  | || (_| | (_|  __/
 *     |______\_____|_____/   |_____|_| |_|\__\___|_|  |_| \__,_|\___\___|
 *
 *
 */
/*=====================================================================================
		* What i sell To Customer
		*  The Architecture Give The API
						- The Name Of Function
						- What is The Input
						- What Is The Output
						- Macro

======================================================================================*/

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H




/*****************  MACROS *****************/
#define _4_BIT_MODE		4
#define _8_BIT_MODE		8


/***************** Functions PROTOTYPES *****************/
/*Function To Initialize LCD*/
void H_vLcdInit(void);
/*Function To Write Char on LCD*/
void H_vLcdWriteCharacter(u8 Copy_u8Character);
/*Function To Write Commands on LCD*/
void H_vLcdWriteCommand(u8 Copy_u8Command);
/*Function To Write String on LCD*/
void H_vLcdWriteString(u8 str[]);
/*Function To Write Number on LCD*/
void H_vLcdWriteIntNumber(s32 Copy_s32Number);
/*Function To Clear LCD*/
void H_vLcdClear(void);
/*Function To Go to any Location on LCD*/
void H_vLcdGoTo(u8 Copy_u8Row,u8 Copy_u8Col);
void H_LcdWriteFloat(f64 f64_local_number);



#endif /*LCD_INTERFACE_H*/
/*=======================================================================================
===============================     End of guard          ===============================
=========================================================================================*/

