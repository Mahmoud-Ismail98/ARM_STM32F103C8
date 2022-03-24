/*********************************************************/
/********** Author 		: Mahmoud Korayem ****************/
/********** Date        : 5 mar  2022     ****************/
/********** version     : V 02			  ****************/
/********** Description : NVIC-Private.h  ****************/
/*********************************************************/




#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* NVIC_base_Adress  0xE000E100 */

#define NVIC_ISER0   *((volatile u32*)0xE000E100) /*Enable External Interupts From 0  to 31 */
#define NVIC_ISER1   *((volatile u32*)0xE000E104) /*Enable External Interupts From 32 to 61 */

#define NVIC_ICER0   *((volatile u32*)0xE000E180)
#define NVIC_ICER1   *((volatile u32*)0xE000E184)

#define NVIC_ISPR0   *((volatile u32*)0xE000E200)
#define NVIC_ISPR1   *((volatile u32*)0xE000E204)

#define NVIC_ICPR0   *((volatile u32*)0xE000E280)
#define NVIC_ICPR1   *((volatile u32*)0xE000E284)

#define NVIC_IABR0   *((volatile u32*)0xE000E300) 
#define NVIC_IABR1   *((volatile u32*)0xE000E304) 

#define NVIC_IPR     ((volatile u8*)0xE000E100 + 0x300)

#define MNVIC_GROUP_4_SUB_0      0x05FA0300	// 4 Bits For Group  (IPR)=> Group
#define MNVIC_GROUP_3_SUB_1      0x05FA0400	// 3 Bits For Group 1 Bit For Sub
#define MNVIC_GROUP_2_SUB_2      0x05FA0500	// 2 Bits For Group 2 Bit For Sub
#define MNVIC_GROUP_1_SUB_3      0x05FA0600	// 1 Bits For Group 3 Bit For Sub
#define MNVIC_GROUP_0_SUB_4      0x05FA0700	// 0 Group 4 Bit For Sub

/* SCB_base_Adress  0xE000ED00  */

#define SCB_AIRCR   *((volatile u32*)0xE000ED00 + 0x0C )



#endif
