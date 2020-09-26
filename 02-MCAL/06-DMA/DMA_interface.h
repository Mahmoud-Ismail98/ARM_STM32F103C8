/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 12 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : NVIC-interface.h ***************/
/*********************************************************/

#ifndef  DMA_INTERFACE_H
#define  DMA_INTERFACE_H


void MDMA_voidChannel1Init(void);
void MDMA_voidChannel1Start(u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);
#endif