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
#include "usart.h"
#include "usart_unit_test.h"
#include "cli.h"
#include <string.h>


void LED_Init(void)
{
  __GPIOG_CLK_ENABLE();

  // Configure GPIO pin PG13
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin   = GPIO_PIN_13;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;        // push-pull output
  GPIO_InitStruct.Pull  = GPIO_NOPULL;                // no pull resistor
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;             // analog pin bandwidth limited
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
  GPIO_InitStruct.Pin   = GPIO_PIN_14;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

} /* LED_Init */

void commandLED(char *args)
{
    if(strcmp(args, "on") == 0)
    {
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
    }
    else if(strcmp(args, "off") == 0)
    {
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
    }
    else
    {
        USART_WriteString("Unrecognized argument. Available arguments are \"on\" and \"off\"\n\r");
    }
}

void commandLED2(char *args)
{
    if(strcmp(args, "on") == 0)
    {
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
    }
    else if(strcmp(args, "off") == 0)
    {
        HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
    }
    else
    {
        USART_WriteString("Unrecognized argument. Available arguments are \"on\" and \"off\"\n\r");
    }
}



int main(void)
{

	HAL_Init();
	USART_Init();
	LED_Init();


 CLI_CommandItem item_LED = { .callback = commandLED,
                           .commandName = "LED",
                           .description = NULL};

 CLI_CommandItem item_LED2 = { .callback = commandLED2,
                           .commandName = "LED2",
                           .description = NULL};

 if(CLI_AddCommand(&item_LED) == false)
 {
     USART_WriteString("ERROR in adding LED.\n\r");
 }

 if(CLI_AddCommand(&item_LED2) == false)
 {
     USART_WriteString("ERROR in adding LED2.\n\r");
 }

 CLI_PrintAllCommands();

 while (true)
 {
	 CLI_Proc();
	 HAL_Delay(10);
 }
}
