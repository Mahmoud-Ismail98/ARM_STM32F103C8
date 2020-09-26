/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 18 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : OS_PRIVATE_H    ****************/




#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
	u16 Priodicity	   ;
	void (*Fptr)(void) ;
	u8 FirstDelay;
	u8 State
}Task;

#endif