## _The work Flow Of Applications :_
### APP1_NVIC_TEST_CODE --> main.c :
![alt text](05-APPLICATIONS\images\APP1_NVIC_TEST_CODE.png "APP1_main.c")

* #### I change in sowftware periority between EXTI_0 and EXTI_1 
* #### the EXTI_0 higher in hardware periority than EXTI_1 but i change in sowftware periority to make EXTI_1 CUT EXTI_0 through this two step in main.c 


    1. MNVIC_voidSetPeriority(6,1,0); /* put EXTI_0 GROUP_1 SUB_GROUP_0*/
    2. MNVIC_voidSetPeriority(7,0,3); /* PIUT EXTI_1 GROUP_0 SUB_GROUP_3*/

* #### EXTI_1 happen while EXTI_0 excute and because i put EXTI_1 in GROUP periority higher than EXTI_0 his due to EXTI_1 cut EXTI_0
* #### to see the output enter debuging session and make some breakpoints in EXTI_IRQHandler and  make some leds_on and if order led_on first and third and second that indicator of the NVIC driver work perfect 