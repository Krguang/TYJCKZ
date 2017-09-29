#include "telDial.h"
#include "cmsis_os.h"
#include "stm32f1xx_hal.h"
#include "modbusToAndroid.h"



#define HT9200_CE_LOW		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET)
#define HT9200_CE_HIGH		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_SET)

#define HT9200_DATA_LOW		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_RESET)
#define HT9200_DATA_HIGH	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_SET)

#define HT9200_CLK_LOW		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET)
#define HT9200_CLK_HIGH		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET)

uint8_t keyStatusFlag[15];

static void sendOneBit(uint8_t dtmfData) {
	
	HT9200_CE_LOW;
	osDelay(20);
	for (int i = 0; i<5; i++) {
		HT9200_CLK_HIGH;
		osDelay(4);
		if (dtmfData & 0x01) {
			HT9200_DATA_HIGH;
			osDelay(4);
		}
		else {
			HT9200_DATA_LOW;
			osDelay(4);
		}
		HT9200_CLK_LOW;
		osDelay(4);
		HT9200_CLK_HIGH;
		osDelay(4);
		dtmfData >>= 1;
	}
	osDelay(100);
	HT9200_CE_HIGH;
	osDelay(10);
	HT9200_CLK_LOW;
}


void telDial() {


	if (((localData[2] >> 13) & 1) != keyStatusFlag[13])
	{
		keyStatusFlag[13] = (localData[2] >> 13) & 1;
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET);
		osDelay(1000);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET);
	}

	if (((localData[2] >> 12) & 1) != 0)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
	}



	if (((localData[2] >> 0) & 1) != keyStatusFlag[0])
	{
		keyStatusFlag[0] = (localData[2] >> 0) & 1;
		sendOneBit(0x0a);
	}

	if (((localData[2] >> 1) & 1) != keyStatusFlag[1])
	{
		keyStatusFlag[1] = (localData[2] >> 1) & 1;
		sendOneBit(1);
	}

	if (((localData[2] >> 2) & 1) != keyStatusFlag[2])
	{
		keyStatusFlag[2] = (localData[2] >> 2) & 1;
		sendOneBit(2);
	}

	if (((localData[2] >> 3) & 1) != keyStatusFlag[3])
	{
		keyStatusFlag[3] = (localData[2] >> 3) & 1;
		sendOneBit(3);
	}

	if (((localData[2] >> 4) & 1) != keyStatusFlag[4])
	{
		keyStatusFlag[4] = (localData[2] >> 4) & 1;
		sendOneBit(4);
	}

	if (((localData[2] >> 5) & 1) != keyStatusFlag[5])
	{
		keyStatusFlag[5] = (localData[2] >> 5) & 1;
		sendOneBit(5);
	}

	if (((localData[2] >> 6) & 1) != keyStatusFlag[6])
	{
		keyStatusFlag[6] = (localData[2] >> 6) & 1;
		sendOneBit(6);
	}

	if (((localData[2] >> 7) & 1) != keyStatusFlag[7])
	{
		keyStatusFlag[7] = (localData[2] >> 7) & 1;
		sendOneBit(7);
	}

	if (((localData[2] >> 8) & 1) != keyStatusFlag[8])
	{
		keyStatusFlag[8] = (localData[2] >> 8) & 1;
		sendOneBit(8);
	}

	if (((localData[2] >> 9) & 1) != keyStatusFlag[9])
	{
		keyStatusFlag[9] = (localData[2] >> 9) & 1;
		sendOneBit(9);
	}

	if (((localData[2] >> 10) & 1) != keyStatusFlag[10])
	{
		keyStatusFlag[10] = (localData[2] >> 10) & 1;
		sendOneBit(0x0b);
	}

	if (((localData[2] >> 11) & 1) != keyStatusFlag[11])
	{
		keyStatusFlag[11] = (localData[2] >> 11) & 1;
		sendOneBit(0x0c);
	}
}
