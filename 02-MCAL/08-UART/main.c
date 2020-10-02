

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"

int main(void)
{
	MRCC_voidInitSysClock();
	MGPIO_voidPORTA_Init();
	MRCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	GPIO_voidSetPinMode(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating */
	GPIO_voidSetPinMode(GPIOA,PIN10,INPUT_FLOATING);

	GPIO_voidSetPinMode(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);

	MUSART1_voidInit();

	u8 x;

	while(1)
	{
		MUSART1_voidTransmit("97");
		x = MUSART1_u8Receive();
		if(x == '5')
		{
			GPIO_voidSetPinVal(GPIOA,PIN0,HIGH);
		}
		if(x == 'r')
		{
			GPIO_voidSetPinVal(GPIOA,PIN0,LOW);
		}
	}

	return 0;
}
