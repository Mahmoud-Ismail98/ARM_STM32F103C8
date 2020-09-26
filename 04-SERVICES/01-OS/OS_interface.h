/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 18 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : OS_INTERFACE_H ****************/




#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Priodicity , void (*ptr)(void) , u8 Copy_u8FirstDelay);


void SOS_voidStart(void);

#endif