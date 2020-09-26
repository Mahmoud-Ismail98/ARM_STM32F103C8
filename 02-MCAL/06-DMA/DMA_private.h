/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 12 SEP 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : DMA_private.h ***************/
/*********************************************************/

#ifndef  DMA_PRIVATE_H
#define  DMA_PRIVATE_H

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;

#define DMA	((volatile DMA_t*)0x40020000) /*pointer to struct */

#define     DMAI_LINE0        0
#define     DMAI_LINE1        1
#define     DMAI_LINE2        2
#define     DMAI_LINE3        3
#define     DMAI_LINE4        4
#define     DMAI_LINE5        5 
#define     DMAI_LINE6        6 
#define     DMAI_LINE7        7 
#define     DMAI_LINE8        8 
#define     DMAI_LINE9        9 
#define     DMAI_LINE10       10
#define     DMAI_LINE11       11
#define     DMAI_LINE12       12
#define     DMAI_LINE13       13
#define     DMAI_LINE14       14
#define     DMAI_LINE15       15

#define    RISING_EDGE        1
#define    FALLING_EDGE       3
#define    ON_CHANGE    	  5

  
#endif