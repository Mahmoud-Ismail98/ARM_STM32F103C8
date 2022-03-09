/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 9 MAR 2022     ****************/
/********** version     : V 02			  ****************/
/********** Description : main.c   ****************/
/*********************************************************/
/* Library includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* MCAL includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"

void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA Clock */

	/* Pin Mode */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP );


	MNVIC_voidInitGroupSub();
	/* Enable EXTI0 Interupt From NVIC */
    MNVIC_voidEnableInerupt(6);   /*EXTI 0 */
    MNVIC_voidEnableInerupt(7);   /*EXTI 1 */

    MNVIC_voidSetPeriority(6,1,0); /* EXTI 0 GROUP 1 SUB 0*/
    MNVIC_voidSetPeriority(7,0,3); /* EXTI 1 GROUP 0 SUB 3*/

	MNVIC_voidSetPendingFlag(6);
	while(1)
	{

	}

}

void EXTI0_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,0,GPIO_HIGH);
	MNVIC_voidSetPendingFlag(7);
	MGPIO_voidSetPinValue(GPIOA,1,GPIO_HIGH);
}

void EXTI1_IRQHandler(void)
{
	MGPIO_voidSetPinValue(GPIOA,2,GPIO_HIGH);
}
