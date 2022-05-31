/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 31 may 2020     ****************/
/********** version     : V 02			  ****************/
/********** Description : OS_PROGRAM_C    ****************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Priodicity , void (*ptr)(void) , u8 Copy_u8FirstDelay)
{
	OS_Tasks[Copy_u8ID].Priodicity = Copy_u8Priodicity ;
	OS_Tasks[Copy_u8ID].Fptr = ptr ;
	OS_Tasks[Copy_u8ID].FirstDelay = Copy_u8FirstDelay ;
	OStasks[Copy_u8ID].State = TASK_READY;	
}

void SOS_voidStart(void)
{
	/* Intiallization */
	MSTK_voidInit();
	/* Tick = 1Msec  */
	/* HSE 8MHZ/8  ==> 1000 Micro sec ==> 1 m sec  */
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);
}

void SOS_voidSuspendTask(u8 Copy_u8ID)
{
	OStasks[Copy_u8ID].State=TASK_SUSPENDED;
}

void SOS_voidResumeTask(u8 Copy_u8ID)
{
	OStasks[Copy_u8ID].State=TASK_READY;
}

void SOS_voidDeleteTask(u8 Copy_u8ID)
{
	OStasks[Copy_u8ID].TaskHandler=NULL;
}
