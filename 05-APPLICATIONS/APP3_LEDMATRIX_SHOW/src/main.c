/*
 * main.c
 *
 *  Created on: march 28, 2022
 *      Author: Mahmoud_Korayem
 */
/* Library_ includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* MCAL includes */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMAT_interface.h"

//u8 DateArray[16]={0,124,18,18,18,124,0,0,0,124,18,18,18,124,0,0};
u8 DateArray[40] ={0, 124, 2, 126, 2, 124,0,124,18,18,18,124,0, 126, 16, 16, 126, 0, 124, 2, 126, 2, 124, 0, 24, 36, 36, 24, 0, 28, 32, 32, 28, 0, 126,66, 36, 24,0};
void main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* Enable GPIOA Clock */
	RCC_voidEnableClock(RCC_APB2,3); /* Enable GPIOB Clock */

	MSTK_voidInit();
	HLEDMAT_voidInit();
	HLEDMAT_voidDisplay(DateArray,sizeof(DateArray));
}
