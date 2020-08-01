/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f10x.h"
#include "Timerconfiguration.h"

#define PRESCALER 65535
#define ARR_VALUE 550
custom_libraries::Timer_configuration timer(TIM2,PRESCALER,ARR_VALUE);

uint32_t counter = 0;

//IMPLEMENT INTERRUPT HANDLER
extern "C" void TIM2_IRQHandler(void){
	//CHECK THAT WE ARE HERE BECAUSE OF TIMER1 UPDATE EVENT
	if(TIM2->SR & TIM_SR_UIF){
		TIM2->SR &= ~TIM_SR_UIF;
		counter++;
	}

}

int main(void)
{
	timer.initialize();

	NVIC_SetPriority(TIM2_IRQn,0x03);
	NVIC_EnableIRQ(TIM2_IRQn);

	while(1){

	}
}
