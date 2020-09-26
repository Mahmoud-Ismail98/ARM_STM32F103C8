

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/*Array Of Task "Array Of Structure"
#define NULL 		(void *)0
static Task OS_Tasks[NUM_OF_TASKS] = {NULL};

void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Priodicity , void (*ptr)(void) , u8 Copy_u8FirstDelay)
{
	OS_Tasks[Copy_u8ID].Priodicity = Copy_u8Priodicity ;
	OS_Tasks[Copy_u8ID].Fptr = ptr ;
	OS_Tasks[Copy_u8ID].FirstDelay = Copy_u8FirstDelay ;
	
}

void SOS_voidStart(void)
{
	/* Intiallization */
	MSTK_voidInit();
	/* Tick = 1Msec  */
	/* HSE 8MHZ/8  ==> 1000 Micro sec ==> 1 m sec  */
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);
}

volatile u16 TickCount = 0; 
void Scheduler(void)
{
	for(u8 i = 0;i < NUM_OF_TASKS ;i++)
	{
		if(OS_Tasks[i].FirstDelay == 0)
		{
			OS_Tasks[i].FirstDelay = OS_Tasks[i].Priodicity-1;
			OS_Tasks[i].Fptr() ;
		}
		else
		{
			/*Decrement the first delay*/
			OS_Tasks[i].FirstDelay--;
		}	
	}
	
}