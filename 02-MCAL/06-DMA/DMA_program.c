/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 12 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : DMAI_program.h  ****************/
/*********************************************************/

include "STD_TYPES.h"
#include "BIT_MARH.h"

#include "DMAI_interface.h"
#include "EXRTI_config.h"
#include "DMAI_private.h"


void MDMA_voidChannel1Init(void)
{
	/*
		Memory to memory
		Priority very high
		Source, destination size=32bit
		MINC , PINC activated
		No circular
		Direction: peripheral to memory
		Transfer complete interrupt enable
		Channel Disable
	*/	
	DMA ->Channel[0].CCR
	
}	

void MDMA_voidChannel1Start(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);
{
	/* make sure channel is disable */
	CLR_BIT(DMA ->Channel.CCR ,0); 
	/*Load the addresses*/
	DMA->Channel[0].CPAR=Copy_pu32SourceAddress;
	DMA->Channel[0].CMAR=Copy_pu32DestinationAddress;
	
	/*Load the block length*/
	DMA->Channel[0].CNDTR=Copy_u16BlockLength;
	
	SET_BIT(DMA->Channel[0].CCR,0);

}	