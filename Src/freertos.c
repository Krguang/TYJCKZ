/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* USER CODE BEGIN Includes */     
#include "stm32f1xx_hal.h"
#include "modbusToAndroid.h"
#include "dataProcessing.h"
#include "telDial.h"
#include "gasAlermRxTx.h"
#include "iwdg.h"
/* USER CODE END Includes */

/* Variables -----------------------------------------------------------------*/
osThreadId TaskModbusRecHandle;
osThreadId TaskDataProcHandle;
osThreadId TaskModbusSendHandle;
osThreadId TaskTelDialHandle;
osThreadId TaskGasRxTxHandle;

/* USER CODE BEGIN Variables */

/* USER CODE END Variables */

/* Function prototypes -------------------------------------------------------*/
void FuncModbusRec(void const * argument);
void FuncDataProc(void const * argument);
void FuncModbusSend(void const * argument);
void FuncTelDial(void const * argument);
void FuncGasRxTx(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Hook prototypes */

/* Init FreeRTOS */

void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the thread(s) */
  /* definition and creation of TaskModbusRec */
  osThreadDef(TaskModbusRec, FuncModbusRec, osPriorityNormal, 0, 128);
  TaskModbusRecHandle = osThreadCreate(osThread(TaskModbusRec), NULL);

  /* definition and creation of TaskDataProc */
  osThreadDef(TaskDataProc, FuncDataProc, osPriorityNormal, 0, 128);
  TaskDataProcHandle = osThreadCreate(osThread(TaskDataProc), NULL);

  /* definition and creation of TaskModbusSend */
  osThreadDef(TaskModbusSend, FuncModbusSend, osPriorityNormal, 0, 128);
  TaskModbusSendHandle = osThreadCreate(osThread(TaskModbusSend), NULL);

  /* definition and creation of TaskTelDial */
  osThreadDef(TaskTelDial, FuncTelDial, osPriorityNormal, 0, 128);
  TaskTelDialHandle = osThreadCreate(osThread(TaskTelDial), NULL);

  /* definition and creation of TaskGasRxTx */
  osThreadDef(TaskGasRxTx, FuncGasRxTx, osPriorityNormal, 0, 128);
  TaskGasRxTxHandle = osThreadCreate(osThread(TaskGasRxTx), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
}

/* FuncModbusRec function */
void FuncModbusRec(void const * argument)
{

  /* USER CODE BEGIN FuncModbusRec */
  /* Infinite loop */
  for(;;)
  {
	  Usart1RxMonitor();
	  osDelay(1);
  }
  /* USER CODE END FuncModbusRec */
}

/* FuncDataProc function */
void FuncDataProc(void const * argument)
{
  /* USER CODE BEGIN FuncDataProc */
  /* Infinite loop */
  for(;;)
  {
	  dataProcessing();
	  telDial();
	  osDelay(1);
  }
  /* USER CODE END FuncDataProc */
}

/* FuncModbusSend function */
void FuncModbusSend(void const * argument)
{
  /* USER CODE BEGIN FuncModbusSend */
  /* Infinite loop */
  for(;;)
  {
	  sendDataMaster03();
	  osDelay(50);
	  sendDataMaster16();
	  osDelay(50);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11);
  }
  /* USER CODE END FuncModbusSend */
}

/* FuncTelDial function */
void FuncTelDial(void const * argument)
{
  /* USER CODE BEGIN FuncTelDial */
  /* Infinite loop */
  for(;;)
  {
	  osDelay(10);
	  HAL_IWDG_Refresh(&hiwdg);
	  gasAlermRx();
  }
  /* USER CODE END FuncTelDial */
}

/* FuncGasRxTx function */
void FuncGasRxTx(void const * argument)
{
  /* USER CODE BEGIN FuncGasRxTx */
  /* Infinite loop */
  for(;;)
  {
	 gasAlermRxTx();
	 osDelay(1);

  }
  /* USER CODE END FuncGasRxTx */
}

/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
