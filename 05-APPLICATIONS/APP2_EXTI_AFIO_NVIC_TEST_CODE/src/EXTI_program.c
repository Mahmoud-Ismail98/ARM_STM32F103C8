/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 12 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : EXTI_program.h  ****************/
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#define NULL		(void * )0
//static void (* EXTI0_CallBack)(void) = NULL;
//static void (* EXTI1_CallBack)(void) = NULL;
static void (* EXTI_CallBack[16])(void); //arr of pointer to fun


void MEXTI_voidInit(void)
{
	#if		EXTI_LINE == EXTI_LINE0
			SET_BIT(EXTI -> IMR , EXTI_LINE0 );
	#elif	EXTI_LINE == EXTI_LINE1
			SET_BIT(EXTI -> IMR , EXTI_LINE1 );
	#elif	EXTI_LINE == EXTI_LINE2
			SET_BIT(EXTI -> IMR , EXTI_LINE2 );
	#else
		#error ("Wrong Externl Interrupt Line !")
	#endif
	
	
	#if		EXTI_SENSE_MODE == FALLING_EDGE
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#elif	EXTI_SENSE_MODE == RISING_EDGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
	#elif	EXTI_SENSE_MODE == ON_CHANGE
			SET_BIT(EXTI -> RTSR , EXTI_LINE);
			SET_BIT(EXTI -> FTSR , EXTI_LINE);
	#else
		#error ("Wrong Externl Interrupt Sense Mode !")
	#endif

}
void MEXTI_voidEnableEXTI (u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI ->IMR , Copy_u8EXTILine);
}
void MEXTI_voidDisableEXTI (u8 Copy_u8EXTILine)
{
	CLR_BIT(EXTI ->IMR , Copy_u8EXTILine);
}
void MEXTI_voidSwTrigger(u8 Copy_u8EXTILine)
{
	SET_BIT(EXTI -> PR ,  Copy_u8EXTILine);
}
void MEXTI_voidSetSignalLatch (u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode)  //change mode in run time
{
	switch(Copy_u8EXTISenseMode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);	break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR , Copy_u8EXTILine);	break;
		case	ON_CHANGE		:	SET_BIT(EXTI -> RTSR , Copy_u8EXTILine);
									SET_BIT(EXTI -> FTSR , Copy_u8EXTILine);	break;
	}
	SET_BIT(EXTI -> IMR , Copy_u8EXTILine);
}
void MEXTI_voidSetCallBack(void (*ptr)(void), u8 Copy_U8EXTILINE)
{
	EXTI_CallBack[Copy_U8EXTILINE] = ptr ;
	//EXTI1_CallBack = ptr ;

}

void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	//	Clear pending Bit For EXTI0
	SET_BIT(EXTI -> PR , EXTI_LINE0);
}

void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	//	Clear pending Bit For EXTI1
	SET_BIT(EXTI -> PR , EXTI_LINE1);
}

