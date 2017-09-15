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


static void sendOneBit(unsigned char dtmfData) {
	
	HT9200_CE_LOW;
	osDelay(10);
	for (int i = 0; i<5; i++) {
		HT9200_CLK_HIGH;
		osDelay(1);
		if (dtmfData & 0x01) {
			HT9200_DATA_HIGH;
			osDelay(1);
		}
		else {
			HT9200_DATA_LOW;
			osDelay(1);
		}
		osDelay(1);
		HT9200_CLK_LOW;
		osDelay(1);
		HT9200_CLK_HIGH;
		osDelay(1);
		dtmfData >>= 1;
	}
	osDelay(100);
	HT9200_CE_HIGH;
}

void telDial() {

	static uint8_t telSwitch = 0;
	static uint8_t keyStatusFlag[11];

	if (localData[3]&(1<<12))
	{
		if (telSwitch==0)
		{
			telSwitch = 1;
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
		}
		else
		{
			telSwitch = 0;
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
		}
	}

	if (telSwitch)
	{
		if (localData[3] & (1 << 0)) {
			if (keyStatusFlag[0]==0)
			{
				sendOneBit(0x0a);
			}
			keyStatusFlag[0] = 1;
		}
		else
		{
			keyStatusFlag[0] = 0;
		}

		if (localData[3] & (1 << 1)) {
			if (keyStatusFlag[1] == 0)
			{
				sendOneBit(1);
			}
			keyStatusFlag[1] = 1;
		}
		else
		{
			keyStatusFlag[1] = 0;
		}

		if (localData[3] & (1 << 2)) {
			if (keyStatusFlag[2] == 0)
			{
				sendOneBit(2);
			}
			keyStatusFlag[2] = 1;
		}
		else
		{
			keyStatusFlag[2] = 0;
		}

		if (localData[3] & (1 << 3)) {
			if (keyStatusFlag[3] == 0)
			{
				sendOneBit(3);
			}
			keyStatusFlag[3] = 1;
		}
		else
		{
			keyStatusFlag[3] = 0;
		}

		if (localData[3] & (1 << 4)) {
			if (keyStatusFlag[4] == 0)
			{
				sendOneBit(4);
			}
			keyStatusFlag[4] = 1;
		}
		else
		{
			keyStatusFlag[4] = 0;
		}

		if (localData[3] & (1 << 5)) {
			if (keyStatusFlag[5] == 0)
			{
				sendOneBit(5);
			}
			keyStatusFlag[5] = 1;
		}
		else
		{
			keyStatusFlag[5] = 0;
		}

		if (localData[3] & (1 << 6)) {
			if (keyStatusFlag[6] == 0)
			{
				sendOneBit(6);
			}
			keyStatusFlag[6] = 1;
		}
		else
		{
			keyStatusFlag[6] = 0;
		}

		if (localData[3] & (1 << 7)) {
			if (keyStatusFlag[7] == 0)
			{
				sendOneBit(7);
			}
			keyStatusFlag[7] = 1;
		}
		else
		{
			keyStatusFlag[7] = 0;
		}

		if (localData[3] & (1 << 8)) {
			if (keyStatusFlag[8] == 0)
			{
				sendOneBit(8);
			}
			keyStatusFlag[8] = 1;
		}
		else
		{
			keyStatusFlag[8] = 0;
		}

		if (localData[3] & (1 << 9)) {
			if (keyStatusFlag[9] == 0)
			{
				sendOneBit(9);
			}
			keyStatusFlag[9] = 1;
		}
		else
		{
			keyStatusFlag[9] = 0;
		}

		if (localData[3] & (1 << 10)) {
			if (keyStatusFlag[10] == 0)
			{
				sendOneBit(0x0b);
			}
			keyStatusFlag[10] = 1;
		}
		else
		{
			keyStatusFlag[10] = 0;
		}

		if (localData[3] & (1 << 11)) {
			if (keyStatusFlag[11] == 0)
			{
				sendOneBit(0x0c);
			}
			keyStatusFlag[11] = 1;
		}
		else
		{
			keyStatusFlag[11] = 0;
		}
		
	}

}
