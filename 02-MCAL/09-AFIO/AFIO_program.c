/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 28 FEB 2022     ****************/
/********** version     : V 01			  ****************/
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"

void MAFIO_voidSetEXTILineNum(u8 Copy_u8ExtiLine , u8 Copy_u8ExtiPinNum)
{
	
	u8 Local_u8RegIndex = 0;  
	Local_u8RegIndex = 	Copy_u8ExtiLine / 4 ;
	Copy_u8ExtiLine =Copy_u8ExtiLine%4;
	AFIO->EXTICR[Local_u8RegIndex] &= ~ ((0b1111) << (4*Copy_u8ExtiLine));
	AFIO->EXTICR[Local_u8RegIndex] |=  ((Copy_u8ExtiPinNum) << (4*Copy_u8ExtiLine));
}

/*

Copy_u8ExtiLine
0,1,2,3   --> EXTICR[0]
4,5,6,7   --> EXTICR[1]
8,9,10,11 --> EXTICR[2]


#define	APIN	0b0000
#define	BPIN	0b0001
#define	CPIN	0b0010

#define  EXTI_LINE    EXTI_LINE6   //0:15 

ex: external interupt on pin B6
	EXTICR[(Local_u8RegIndex=6/4)=1]	= BPIN(0b0001)<< (4*2)
*/
