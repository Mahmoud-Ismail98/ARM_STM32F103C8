/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 26 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : SPI_program.c   ****************/
/*********************************************************/

#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*CallBack)(u8);

void MSPI1_voidInit(void)
{
	MSPI1->CR1 = 0x0347;
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

 	/* Return to the rec eived data */
	*Copy_DataToReceive = MSPI1 -> DR;
	
	/* Set Salve Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

