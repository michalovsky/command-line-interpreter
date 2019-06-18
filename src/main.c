/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "stm32f429i_discovery.h"
#include <string.h>
#include "usart.h"
#include "usart_unit_test.h"

int main(void)
{

 HAL_Init();
 USART_Init();

 GPIO_InitTypeDef gpio;
  gpio.Pin = GPIO_PIN_13;
  gpio.Mode = GPIO_MODE_OUTPUT_PP;
  gpio.Pull = GPIO_NOPULL;
  gpio.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &gpio);

 //USART_WriteString("Hello world \n\r");
 char c;

 USART_UnitTest();

 while (1)
 {
	 if(USART_GetChar(&c))
	 {
	     USART_PutChar(c);
	 }

	 //char * s = "asdasda\n\r";
	 //HAL_UART_Transmit(&UartHandle, (uint8_t*)s, strlen(s), 10);
 }
}
