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

extern UART_HandleTypeDef UartHandle;

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

 /*__HAL_RCC_GPIOA_CLK_ENABLE();
 __HAL_RCC_USART1_CLK_ENABLE();

 GPIO_InitTypeDef gpio;
 gpio.Mode = GPIO_MODE_AF_PP;
 gpio.Alternate = GPIO_AF7_USART1;
 gpio.Pin = GPIO_PIN_9;
 gpio.Pull = GPIO_NOPULL;
 gpio.Speed = GPIO_SPEED_FREQ_LOW;
 HAL_GPIO_Init(GPIOA, &gpio);

 gpio.Mode = GPIO_MODE_AF_OD;
 gpio.Pin = GPIO_PIN_10;
 HAL_GPIO_Init(GPIOA, &gpio);

 uart.Instance = USART1;
 uart.Init.BaudRate = 115200;
 uart.Init.WordLength = UART_WORDLENGTH_8B;
 uart.Init.Parity = UART_PARITY_NONE;
 uart.Init.StopBits = UART_STOPBITS_1;
 uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
 uart.Init.OverSampling = UART_OVERSAMPLING_16;
 uart.Init.Mode = UART_MODE_TX_RX;
 HAL_UART_Init(&uart);
 */
 while (1)
 {
	 char * s = "asdasda\n\r";
	 HAL_UART_Transmit(&UartHandle, (uint8_t*)s, strlen(s), 10);
 }
}
