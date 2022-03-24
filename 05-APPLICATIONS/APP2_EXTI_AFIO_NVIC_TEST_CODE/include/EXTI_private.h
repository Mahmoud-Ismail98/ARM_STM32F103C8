/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 12 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : EXTI_private.h ***************/
/*********************************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H

typedef struct{
    volatile  u32  IMR;	
    volatile  u32  EMR;
    volatile  u32  RTSR;
    volatile  u32  FTSR;
    volatile  u32  SWIER;
    volatile  u32  PR;
}EXTI_Type;

#define EXTI  ((volatile EXTI_Type *)0x40010400) /*pointer to struct */



  
#endif
