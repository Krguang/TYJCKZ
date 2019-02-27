#ifndef __MODBUSTOANDROID_
#define __MODBUSTOANDROID_

#include "stm32f1xx_hal.h"
#include "main.h"

extern unsigned short localData[];

void Usart1RxMonitor();
void sendDataMaster03(uint8_t start, uint8_t num);
void sendDataMaster16();

#endif // __MODBUSTOANDROID_
