#include "core.h"
#include "stm32f4xx_hal.h"


void CORE_EnterCriticalSection(void){
	__disable_irq();
}

void CORE_ExitCriticalSection(void) {
	__enable_irq();
}
