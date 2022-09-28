
/***************************************************************************************
 ***************************  - DIO_interface.c				 ****************************
***************************   - Created: 16/9/2022			 ****************************
***************************   - Author: Abdelrahman_Kandil     ***************************
***************************   - Version : _1_				 ****************************
***************************   - Note :
									*-
									*-
 **************************************************************************************/
/***
 *      _____ _____ ____    _____ _   _ _______ ______ _____  ______      _____ ______
 *     |  __ \_   _/ __ \  |_   _| \ | |__   __|  ____|  __ \|  ____/\   / ____|  ____|
 *     | |  | || || |  | |   | | |  \| |  | |  | |__  | |__) | |__ /  \ | |    | |__
 *     | |  | || || |  | |   | | | . ` |  | |  |  __| |  _  /|  __/ /\ \| |    |  __|
 *     | |__| || || |__| |  _| |_| |\  |  | |  | |____| | \ \| | / ____ \ |____| |____
 *     |_____/_____\____/  |_____|_| \_|  |_|  |______|_|  \_\_|/_/    \_\_____|______|
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
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*===========================     Function Prototypes     ===========================*/

/*======== Macros Of Port ========*/
#define DIO_PORTA   		   (0U)              /*!< DIO (A) PORT  */
#define DIO_PORTB   		   (1U)              /*!< DIO (B) PORT  */
#define DIO_PORTC   		   (2U)              /*!< DIO (C) PORT  */
#define DIO_PORTD   		   (3U)              /*!< DIO (D) PORT  */

#define DIO_PIN_0              (0U)      		  /*!< Pin 0 selected    */
#define DIO_PIN_1              (1U)      		  /*!< Pin 1 selected    */
#define DIO_PIN_2              (2U)      		  /*!< Pin 2 selected    */
#define DIO_PIN_3              (3U)      		  /*!< Pin 3 selected    */
#define DIO_PIN_4              (4U)      		  /*!< Pin 4 selected    */
#define DIO_PIN_5              (5U)      		  /*!< Pin 5 selected    */
#define DIO_PIN_6              (6U)      		  /*!< Pin 6 selected    */
#define DIO_PIN_7              (7U)      		  /*!< Pin 7 selected    */
/*======== Macros Of Mode ========*/
#define INPUT      	      (0b00)          /*!< MODE ---> INPUT     */
#define OUTPUT     	      (0b01)          /*!< MODE ---> OUTPUT    */
/*======== Macros Write Data  ========*/
#define LOW                     (0U)
#define HIGH	                (1U)

/*===============   1-Function Set The Mode Of Pin	 ===============*/
							/*(INPUT -OUTPUT )*/
void MDIO_vSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  ); //Direction Mode
void MDIO_vSetPinData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Data);
u8   MDIO_u8ReadPinData(u8 Copy_u8PortName ,u8 Copy_u8PinNum);
void MDIO_vPinToggle(u8 Copy_u8PortName ,u8 Copy_u8PinNum );

void MDIO_vSetPortMode(u8 Copy_u8PortName ,u8 Copy_u8Mode  );
u8   MDIO_u8ReadPortData(u8 Copy_u8PortName ,u8 Copy_u8Data);
void MDIO_vSetPortData(u8 Copy_u32PortName ,u8 Copy_u8State);





/*=======================================================================================
===============================     End of guard          ===============================
=========================================================================================*/
#endif /* DIO_INTERFACE_H_ */
