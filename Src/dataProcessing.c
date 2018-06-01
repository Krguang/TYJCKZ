#include "dataProcessing.h"
#include "modbusToAndroid.h"
#include "adc.h"
#include "usart.h"
#include "gasAlermRxTx.h"
#include "cmsis_os.h"

static void backgroundMusic() {

	switch (localData[0])
	{
	case 0:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;

	case 1:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
		break;
	
	default:
		break;
	}
}

static void relayControl() {
	if ((uint8_t)(localData[1]&0x01))
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);
	}

	if ((uint8_t)(localData[1] & 0x02)>>1)
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
	}

	if ((uint8_t)(localData[1] & 0x04) >> 2)
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	}

	if ((uint8_t)(localData[1] & 0x08) >> 3)
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
	}

	if ((uint8_t)(localData[1] & 0x10) >> 4)
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_11, GPIO_PIN_RESET);
	}

	if ((uint8_t)(localData[1] & 0x20) >> 5)
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	}

	if ((uint8_t)(localData[1] & 0x40) >> 6)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_0, GPIO_PIN_RESET);
	}

	if ((localData[1] >> 10) & 0x0001)
	{
		osDelay(1000);
		HAL_GPIO_WritePin(gaoSu_GPIO_Port, gaoSu_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(gaoSu_GPIO_Port, gaoSu_Pin, GPIO_PIN_RESET);
	}

	if ((localData[1] >> 11) & 0x0001)
	{
		osDelay(1000);
		HAL_GPIO_WritePin(zhongSu_GPIO_Port, zhongSu_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(zhongSu_GPIO_Port, zhongSu_Pin, GPIO_PIN_RESET);
	}

	if ((localData[1] >> 12) & 0x0001)
	{
		osDelay(1000);
		HAL_GPIO_WritePin(diSu_GPIO_Port, diSu_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(diSu_GPIO_Port, diSu_Pin, GPIO_PIN_RESET);
	}

	if ((localData[1] >> 13) & 0x0001)
	{
		HAL_GPIO_WritePin(lengShui_GPIO_Port, lengShui_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(lengShui_GPIO_Port, lengShui_Pin, GPIO_PIN_RESET);
	}

	if ((localData[1] >> 14) & 0x0001)
	{
		HAL_GPIO_WritePin(reShui_GPIO_Port, reShui_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(reShui_GPIO_Port, reShui_Pin, GPIO_PIN_RESET);
	}

	if ((localData[1] >> 15) & 0x0001)
	{
		HAL_GPIO_WritePin(beiYong_GPIO_Port, beiYong_Pin, GPIO_PIN_SET);
	}
	else {
		HAL_GPIO_WritePin(beiYong_GPIO_Port, beiYong_Pin, GPIO_PIN_RESET);
	}
}

static void getAdcValue() {

	for (uint8_t i = 0; i < 100; i++)
	{
		for (uint8_t j = 0; j < 10; j++) {
			ADC_Average[j] += ADC_ConvertedValue[j];
		}
	}
}


static void gasCollect() {

	uint16_t gasTemp[10];

	
	for (uint8_t i = 0; i < 7; i++)
	{

		if (ADC_Average[i]<84000)
		{
			ADC_Average[i] = 84000;
		}
		gasTemp[i] = (uint16_t)((ADC_Average[i] / 100 - 840) * 999 / 3255);
		
		localData[i + 6] = gasTemp[i];
		ADC_Average[i] = 0;
	}
}

static void getTempAndHumi() {

	localData[13] = (uint16_t)(ADC_Average[7] / 100 * 1000 / 4096);
	localData[14] = (uint16_t)(ADC_Average[8] / 100 * 500 / 4096);
	localData[15] = (uint16_t)(ADC_Average[9] / 100 * 1000 / 4096);
	ADC_Average[7] = 0;
	ADC_Average[8] = 0;
	ADC_Average[9] = 0;

}

static void gasAlerm() {
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)== GPIO_PIN_RESET) {
		localData[3] |= (1 << 0);
	}
	else
	{
		localData[3] &= ~(1 << 0);
	}
	
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 1);
	}
	else
	{
		localData[3] &= ~(1 << 1);
	}
	
	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 2);
	}
	else
	{
		localData[3] &= ~(1 << 2);
	}

	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 3);
	}
	else
	{
		localData[3] &= ~(1 << 3);
	}

	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_15) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 4);
	}
	else
	{
		localData[3] &= ~(1 << 4);
	}

	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 5);
	}
	else
	{
		localData[3] &= ~(1 << 5);
	}

	if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 6);
	}
	else
	{
		localData[3] &= ~(1 << 6);
	}

	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_6) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 7);
	}
	else
	{
		localData[3] &= ~(1 << 7);
	}

	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 8);
	}
	else
	{
		localData[3] &= ~(1 << 8);
	}

	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 9);
	}
	else
	{
		localData[3] &= ~(1 << 9);
	}

	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 10);
	}
	else
	{
		localData[3] &= ~(1 << 10);
	}

	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 11);
	}
	else
	{
		localData[3] &= ~(1 << 11);
	}

	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_1) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 12);
	}
	else
	{
		localData[3] &= ~(1 << 12);
	}

	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0) == GPIO_PIN_RESET) {
		localData[3] |= (1 << 13);
	}
	else
	{
		localData[3] &= ~(1 << 13);
	}
}

/*
static uint8_t SD2405_BCDtoDEC(uint8_t BCD_data)//change BCD_data to DEC_data
{
	uint8_t m_DEC_data[3];
	m_DEC_data[0] = (BCD_data >> 4) & 0x0f;
	m_DEC_data[1] = BCD_data & 0x0f;
	m_DEC_data[2] = m_DEC_data[0] * 10 + m_DEC_data[1];
	return m_DEC_data[2];
}


static void sendTime() {
	static uint8_t timeTemp[7];
	HAL_I2C_Mem_Read(&hi2c1, 0x64, 0, I2C_MEMADD_SIZE_8BIT , timeTemp , 7, 0xff);
	for (uint8_t i = 0; i < 7; i++)
	{
		if (i==2)//小时数据去除前3位，保留真实数据
		{
			timeTemp[2] &= 0x3f;
		}
		localData[13 + i] = SD2405_BCDtoDEC(timeTemp[i]);
	}
}
*/


void dataProcessing() {
	backgroundMusic();
	relayControl();
	getAdcValue();
	getTempAndHumi();
	//sendTime();
	if (gasSensorSwitch==1)
	{
		gasCollect();
		gasAlerm();
	}
}