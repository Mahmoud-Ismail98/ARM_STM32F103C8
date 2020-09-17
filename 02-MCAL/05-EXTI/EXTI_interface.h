/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 12 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : NVIC-interface.h ***************/
/*********************************************************/

#ifndef  EXT_INTERFACE_H
#define  EXT_INTERFACE_H

/* Line and Mode */
void MEXTI_voidInit();
void MEXTI_voidSetSignalLatch (u8 Copy_u8EXTILine,Copy_u8EXTISenseMode);
void MEXTI_voidEnableEXTI (u8 Copy_u8Line);
void MEXTI_voidDisableEXTI (u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetCallBack(void (*ptr)(void))

#endif