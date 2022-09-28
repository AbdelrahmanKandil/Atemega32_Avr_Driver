/*
 * STD_TYPES.h
 *
 * Created: 4/6/2022 12:43:18 PM
 *  Author: Abdelrahman
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char            u8; // 1 byte = 8 bit;
typedef signed char 		     s8;
typedef unsigned short int	     u16;
typedef signed short int 	     s16;
typedef unsigned long int    	 u32; // some types library unit_32
typedef signed long int 	     s32;
typedef unsigned long long int 	 u64;
typedef signed long long int 	 s64;
typedef float				 	 f32;
typedef double					 f64;
typedef long double				 f96;

#ifndef NULL
#define NULL  ((void*)0)
#endif


#endif /* STD_TYPES_H_ */
