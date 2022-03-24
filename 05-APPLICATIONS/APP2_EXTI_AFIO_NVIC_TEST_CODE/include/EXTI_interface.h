/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 12 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : NVIC-interface.h ***************/
/*********************************************************/

#ifndef  EXTI_INTERFACE_H
#define  EXTI_INTERFACE_H

/* Line and Mode */
void MEXTI_voidInit(void);
void MEXTI_voidSetSignalLatch (u8 Copy_u8EXTILine,u8 Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI (u8 Copy_u8Line);
void MEXTI_voidDisableEXTI (u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetCallBack(void (*ptr)(void),u8 Copy_U8EXTILINE);

#define     EXTI_LINE0        0
#define     EXTI_LINE1        1
#define     EXTI_LINE2        2
#define     EXTI_LINE3        3
#define     EXTI_LINE4        4
#define     EXTI_LINE5        5
#define     EXTI_LINE6        6
#define     EXTI_LINE7        7
#define     EXTI_LINE8        8
#define     EXTI_LINE9        9
#define     EXTI_LINE10       10
#define     EXTI_LINE11       11
#define     EXTI_LINE12       12
#define     EXTI_LINE13       13
#define     EXTI_LINE14       14
#define     EXTI_LINE15       15

#define    RISING_EDGE        1
#define    FALLING_EDGE       3
#define    ON_CHANGE    	  5
#endif
