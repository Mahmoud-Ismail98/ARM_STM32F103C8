/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 24 MAR 2022     ****************/
/********** version     : V 01			  ****************/
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
#include "AFIO_interface.h"

void TASK1(void);
void TASK2(void);
void TASK1_RETURN(void);
void TASK2_RETURN(void);
void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA Clock */
	RCC_voidEnableClock(RCC_APB2,0); /* Enable AFIO Clock */

	/* Pin Mode */
	MGPIO_voidSetPinDirection(GPIOA,PIN0,INPUT_PULL_UP_DOWEN );
	MGPIO_voidSetPinValue(GPIOA,0,GPIO_HIGH);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,INPUT_PULL_UP_DOWEN );
	MGPIO_voidSetPinValue(GPIOA,1,GPIO_HIGH);

	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP );
	MGPIO_voidSetPinDirection(GPIOA,PIN3,OUTPUT_SPEED_2MHZ_PP );

	//MEXTI_voidInit();
   // MEXTI_voidEnableEXTI(EXTI_LINE0); //to change in run time
	MEXTI_voidSetSignalLatch(EXTI_LINE0 , FALLING_EDGE);
	MEXTI_voidSetSignalLatch(EXTI_LINE1 , FALLING_EDGE);

	MEXTI_voidSetCallBack(TASK1 , EXTI_LINE0);
	MEXTI_voidSetCallBack(TASK2 , EXTI_LINE1);


	MNVIC_voidInitGroupSub();
	/* Enable EXTI0 Interupt From NVIC */
    MNVIC_voidEnableInerupt(6);   /*EXTI 0 */
    MNVIC_voidEnableInerupt(7);   /*EXTI 1 */

    MNVIC_voidSetPeriority(6,1,0); /* EXTI 0 GROUP 1 SUB 0*/
    MNVIC_voidSetPeriority(7,0,3); /* EXTI 1 GROUP 0 SUB 3*/

	while(1)
	{

	}

}

void TASK1(void)
{
	MSTK_voidStopInterval();
	MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_HIGH);
	//delay for 10 sec
	//MSTK_voidSetBusyWait(10000000);

	//delay for 5sec
	MSTK_voidSetIntervalSingle(5000000,TASK1_RETURN);
	MSTK_voidStopInterval();


}
void TASK1_RETURN(void)
{
	MGPIO_voidSetPinValue(GPIOA,PIN2,GPIO_LOW);
}
void TASK2(void)
{

	MGPIO_voidSetPinValue(GPIOA,PIN3,GPIO_HIGH);
	//MSTK_voidSetBusyWait(10000000);

	//delay for 5sec
	MSTK_voidSetIntervalSingle(5000000,TASK2_RETURN);


}
void TASK2_RETURN(void)
{
	MGPIO_voidSetPinValue(GPIOA,PIN3,GPIO_LOW);
}
