/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 5 mar  2022     ****************/
/********** version     : V 02			  ****************/
/********** Description : NVIC-interface.h ***************/
/*********************************************************/



#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


void MNVIC_voidEnableInerupt    (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInerupt   (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8   MNVIC_u8GetActiveFlag		(u8 Copy_u8IntNumber);
void MNVIC_voidInitGroupSub(void);
void MNVIC_voidSetPeriority(s8 Copy_s8PeripheralID , u8 Copy_u8tGroupPriority,u8 Copy_u8SubPriority);

                
#endif
