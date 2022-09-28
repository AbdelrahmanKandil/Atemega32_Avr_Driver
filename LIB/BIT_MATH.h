/*
 * BIT_MATH.h
 *
 * Created: 4/6/2022 12:42:00 PM
 *  Author: Abdelrahman
 */


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(REG,BIT) 				REG|=(1<<BIT) //to clear a bit to be 1
#define CLEAR_BIT(REG,BIT) 				REG&=~(1<<BIT) //to clear a bit to be 0
#define GET_BIT(REG,BIT)				1&(REG>>BIT)  //to read value from the bit
#define TOGGLE_BIT(REG,BIT)				REG^=(1<<BIT) //To toggle a bit make 1 to zero and zero to 1
#define SET_HIGH_REG(REG)  				REG|=240
#define SET_LOW_REG(REG)   				REG&=240
//#define GET_BIT(REG,BIT) 				REG&=(1<<BIT) //to read value from the bit


#endif /* BIT_MATH_H_ */
