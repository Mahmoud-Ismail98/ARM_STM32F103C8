/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 31 may 2020     ****************/
/********** version     : V 02			  ****************/
/********** Description : OS_PRIVATE_H    ****************/




#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

#define NULL 		(void *)0

#define			TASK_SUSPENDED			1

#define			TASK_READY				2

typedef struct
{
	u16 Priodicity	   ;
	void (*Fptr)(void) ;
	u8 FirstDelay;
	u8 State
}Task;

//Array Of Task "Array Of Structure"
static Task OS_Tasks[NUM_OF_TASKS] = {NULL};

static void Scheduler(void)
{
	/*LOOP ON TASKS*/
	for(u8 i = 0;i < NUM_OF_TASKS ;i++)
	{
	/*chack that task isn't deleted or suspended */
		if((OStasks[i].TaskHandler != NULL) && (OStasks[i].State == TASK_READY) )
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
	
}
#endif