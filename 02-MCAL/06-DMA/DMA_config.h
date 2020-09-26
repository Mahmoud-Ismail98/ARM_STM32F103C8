/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 30 AUG 2020     ****************/
/********** version     : V 01			  ****************/
/********** Description : NVIC-interface.h ***************/
/*********************************************************/

#ifndef  DMAI_CONFIG_H
#define  DMAI_CONFIG_H


/*
DMAI_LINE0
DMAI_LINE1
DMAI_LINE2
DMAI_LINE3
.
.
.
.
DMAI_LINE15
*/

#define  DMAI_LINE    DMAI_LINE0   /* 0:15 */

/*
FALLING_EDGE
RISING_EDGE
ON_CHANGE
*/
#define	 DMAI_SENSE_MODE    FALLING_EDGE

#endif
