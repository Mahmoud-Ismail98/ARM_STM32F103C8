/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 5 mar  2022     ****************/
/********** version     : V 02			  ****************/
/********** Description : RCC-Program.c   ****************/
/*********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInerupt(u8 Copy_u8IntNumber)
{
		if (Copy_u8IntNumber <=31)
		{
			NVIC_ISER0=(1 << Copy_u8IntNumber);  /*direct assing as write 0 has not effect */
		}

		else if (Copy_u8IntNumber <=59)
		{
			Copy_u8IntNumber -=32;
			NVIC_ISER1=(1 << Copy_u8IntNumber);
		}		

		else
		{
			/* Return Error */
		}			
}	

void MNVIC_voidDisableInerupt(u8 Copy_u8IntNumber)
{
		if (Copy_u8IntNumber <=31)
		{
			NVIC_ICER0=(1 << Copy_u8IntNumber);  /*direct assing as write 0 has not effect */
		}

		else if (Copy_u8IntNumber <=59)
		{
			Copy_u8IntNumber -=32;
			NVIC_ICER1=(1 << Copy_u8IntNumber);
		}		

		else
		{
			/* Return Error */
		}			
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
		if (Copy_u8IntNumber <=31)
		{
			NVIC_ISPR0=(1 << Copy_u8IntNumber);  /*direct assing as write 0 has not effect */
		}

		else if (Copy_u8IntNumber <=59)
		{
			Copy_u8IntNumber -=32;
			NVIC_ISPR1=(1 << Copy_u8IntNumber);
		}		

		else
		{
			/* Return Error */
		}			
}	

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
		if (Copy_u8IntNumber <=31)
		{
			NVIC_ICPR0=(1 << Copy_u8IntNumber);  /*direct assing as write 0 has not effect */
		}

		else if (Copy_u8IntNumber <=59)
		{
			Copy_u8IntNumber -=32;
			NVIC_ICPR1=(1 << Copy_u8IntNumber);
		}		

		else
		{
			/* Return Error */
		}			
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
		u8 Local_u8Result=0;
		if (Copy_u8IntNumber <=31)
		{
			Local_u8Result =GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
		}

		else if (Copy_u8IntNumber <=59)
		{
			Copy_u8IntNumber -=32;
			Local_u8Result =GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
		}		

		else
		{
			/* Return Error */
		}

		return Local_u8Result;	
}

void MNVIC_voidInitGroupSub(void)
{
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION ;
	
}

void MNVIC_voidSetPeriority(s8 Copy_s8PeripheralID , u8 Copy_u8tGroupPriority,u8 Copy_u8SubPriority)
{							/*0x05FA0400 3 Group & 1 sub priority*/
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8tGroupPriority<<((MNVIC_GROUP_SUB_DISTRIBUTION - 0x05FA0300)/256));
	/* Copy_s8PeripheralID < 0 ----> core peripheral 			*/

	/* external peripheral		*/ /*EXTI0 = 6*/
	if(Copy_s8PeripheralID >= 0 , Copy_s8PeripheralID <60)
	{
		NVIC_IPR[Copy_s8PeripheralID] = Local_u8Priority << 4 ;
	}

	else
	{
		/* Report Error */
	}	

}
