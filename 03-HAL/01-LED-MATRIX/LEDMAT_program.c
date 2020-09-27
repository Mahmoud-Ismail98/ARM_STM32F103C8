/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 15 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : LEDMAT_PROGRAM.C****************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMAT_interface.h"
#include "LEDMAT_private.h"
#include "LEDMAT_config.h"

void HLEDMAT_voidInit(void)
{
	MGPIO_VidSetPinDirection(LEDMAT_ROW0,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_ROW1,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_ROW2,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_ROW3,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_ROW4,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_ROW5,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_ROW6,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_ROW7,OUTPUT_SPEED_2MHZ);


	MGPIO_VidSetPinDirection(LEDMAT_COL0,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_COL1,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_COL2,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_COL3,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_COL4,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_COL5,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_COL6,OUTPUT_SPEED_2MHZ);
	MGPIO_VidSetPinDirection(LEDMAT_COL7,OUTPUT_SPEED_2MHZ);


}

void HLEDMAT_voidDisplay(u8 *Copy_u8Date)
{
	/*  Colum 0 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[0]);
	MGPIO_VidSetPinValue(LEDMAT_COL0,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC

	/*  Colum 1 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[1]);
	MGPIO_VidSetPinValue(LEDMAT_COL1,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC

	/*  Colum 2 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[2]);
	MGPIO_VidSetPinValue(LEDMAT_COL2,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC

	/*  Colum 3 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[3]);
	MGPIO_VidSetPinValue(LEDMAT_COL3,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC

	/*  Colum 4 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[4]);
	MGPIO_VidSetPinValue(LEDMAT_COL4,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC

	/*  Colum 5 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[5]);
	MGPIO_VidSetPinValue(LEDMAT_COL5,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC

	/*  Colum 6 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[6]);
	MGPIO_VidSetPinValue(LEDMAT_COL6,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC
	/*  Colum 7 */	
	DisableAllCols();
	SetRowValues(Copy_u8Date[7]);
	MGPIO_VidSetPinValue(LEDMAT_COL7,GPIO_LOW);
	/* Start timer */
	MSTK_voidSetBusyWait(2500); //2.5 MSEC

}


static void SetRowValues  (u8 Copy_u8Value)
{
	u8 Local_u8Bit;
	Local_u8Bit =GET_BIT(Copy_u8Value,0);
	MGPIO_VidSetPinValue(LEDMAT_ROW0,Local_u8Bit);
	Local_u8Bit =GET_BIT(Copy_u8Value,1);
	MGPIO_VidSetPinValue(LEDMAT_ROW1,Local_u8Bit);
	Local_u8Bit =GET_BIT(Copy_u8Value,2);
	MGPIO_VidSetPinValue(LEDMAT_ROW2,Local_u8Bit);
	Local_u8Bit =GET_BIT(Copy_u8Value,3);
	MGPIO_VidSetPinValue(LEDMAT_ROW3,Local_u8Bit);
	Local_u8Bit =GET_BIT(Copy_u8Value,4);
	MGPIO_VidSetPinValue(LEDMAT_ROW4,Local_u8Bit);
	Local_u8Bit =GET_BIT(Copy_u8Value,5);
	MGPIO_VidSetPinValue(LEDMAT_ROW5,Local_u8Bit);
	Local_u8Bit =GET_BIT(Copy_u8Value,6);
	MGPIO_VidSetPinValue(LEDMAT_ROW6,Local_u8Bit);
	Local_u8Bit =GET_BIT(Copy_u8Value,7);
	MGPIO_VidSetPinValue(LEDMAT_ROW7,Local_u8Bit);
}

static void DisableAllCols(void)
{
	/* Disable All */
	MGPIO_VidSetPinValue(LEDMAT_COL0,GPIO_HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL1,GPIO_HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL2,GPIO_HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL3,GPIO_HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL4,GPIO_HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL5,GPIO_HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL6,GPIO_HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL7,GPIO_HIGH);

}
