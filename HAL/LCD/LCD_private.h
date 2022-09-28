/*==============================================================================================
===============================   - LCD_private.h				 ===============================
===============================   - Created: 16/9/2022			     ===============================
===============================   - Author: Abdelrahman_Kandil    ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/

/*===============================================================================================
*	 - Developer can't Edit in it
*	  - Register _ Definition
*	  - Design :
					- #define	:	Yes
					- Union		:	NO
					- Struct	:	NO

===================================================================================================*/


/*=======================================================================================
=====================     guard of file will call on time in .c  	=====================
=========================================================================================*/
#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

/*LCD control commands*/
#define LCD_CLR                  0x01 /* Clearing the complete display including RAM DATA */
#define LCD_HOME                 0x02 /* return cursor to first position on first line(return home) */
#define LCD_ENTRYMODE            0x06 /*Write from left to right*/
#define LCD_DISPOFF              0x08 /*Cursor and display OFF*/
#define LCD_DISPON_CURSON        0x0F /*Display data on cursor blinking*/
#define LCD_FUNCSET_8BIT         0x38 /*Activate 8-bit mode*/
#define LCD_FUNSET_4BIT_C1		 0x33 /*Activate 4-bit mode*/
#define LCD_FUNSET_4BIT_C2		 0x32 /*Activate 4-bit mode*/
#define LCD_FUNSET_4BIT_C3		 0x28 /*Activate 4-bit mode*/

#define LCD_SETCURSOR            0x80 // set cursor position
#define LCD_DISPON_CURSBLINK     0x0D //display on , cursor blinking
#define LCD_DISPON_CURSOFF       0x0C /*Display ON, cursor OFF*/
#define LCD_FIRST_LINEP0         0x80 /*go to first  line position 0*/
#define LCD_FIRST_LINEP1         0x81 /*go to first  line position 1*/
#define LCD_FIRST_LINEP2         0x82 /*go to first  line position 2*/
#define LCD_SECOND_LINEP0        0xC0 /*go to second line position 0*/
#define LCD_SECOND_LINEP1 	     0xC1 /*go to second line position 1*/
#define LCD_SECOND_LINEP2		 0xC2 /*go to second line position 2*/


#endif/*LCD_PRIVATE_H_*/
/*=======================================================================================
===============================     End of guard          ===============================
=========================================================================================*/
