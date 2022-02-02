/*
 * VibrationTask.c
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */


/* Main Includes */
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "event_groups.h"

/* Peripheral Includes */
#include "tim.h"
#include "usart.h"
#include "dma.h"
/* cmsis includes */
#include "arm_math.h"

/* Private Includes */
#include "VibrationTask.h"
#include "PCATask.h"
#include "DecisionUnitTask.h"
#include "defines.h"
#include "function_pca.h"


#pragma GCC diagnostic ignored "-Wunused-variable"

/* Create Groups Variables*/
static StaticEventGroup_t VibrationEventGroupBuffer; 
EventGroupHandle_t VibrationEvents; 
int buf_sel;
/* UART Variables */
VibrationStructTypeDef sample;
float32_t X1_train[D_DIM][N_WINDOWS] = {{0.0f}};
float32_t X1_valid[N_WINDOWS][D_DIM] = {{0.0f}};
float32_t X2[N_WINDOWS][D_DIM] = {{0.0f}};


/* USER CODE BEGIN Header_VibrationFunc */
/**
  * @brief  Function implementing the VibrationTask thread.
  * @param  argument: Not used
  * @retval None
  */
  /* USER CODE END Header_VibrationFunc */
void VibrationFunc(void const* argument)
{
    /* USER CODE BEGIN VibrationFunc */

	/* Event Variables */
	 VibrationEvents = xEventGroupCreateStatic(&VibrationEventGroupBuffer); //create the Group Event
	 EventBits_t uxBits;
#define IS_EVT(x) 	uxBits & x
	 osDelay(1);
	 char* str1 = "VIBRATION_EVENT_GROUP_CREATED_FAIL\r\n";
	 char* str2 = "VIBRATION_EVENT_GROUP_CREATED_SUCCESSFULLY\r\n";
	 char* str3 = "==============================================\r\n";
	 if (VibrationEvents == NULL) 	HAL_UART_Transmit(&huart3, (uint8_t*)str1, strlen(str1), 300);
	 else 	HAL_UART_Transmit(&huart3, (uint8_t*)str2, strlen(str2), 300);
	 HAL_UART_Transmit(&huart3, (uint8_t*)str3, strlen(str3), 300);
	 configASSERT(VibrationEvents);

	 /* Set Initial state of UART */
	 Set_Event(VibrationEvents, UART_INIT);
	 /* set Initial state of sample structs */
 
	 sample.sample_c = 0;
	 buf_sel = 0;
 
    /* Infinite loop */
    for (;;)
    {
		uxBits = xEventGroupWaitBits(
			VibrationEvents,
			UART_INIT,
			pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
			pdFALSE,       /* Don't wait for both bits, either bit will do. */
			100);

		if (IS_EVT(UART_INIT))
		{

			HAL_UART_Receive_DMA(&huart2, sample.rx_sample, RX_SIZE);
			char *str1 = "DMA is initiated\r\n";
			HAL_UART_Transmit(&huart3, (uint8_t *)str1, strlen(str1), 300);
		}
			//osDelay(1);
    }
    /* USER CODE END VibrationFunc */
}

/* Global Variables for the CallBack Functions */
float32_t rx_vib;
uint8_t rx_str[BYTE-1];
int i = 0;
int full_debug = 0;
/* Logic In here is: 
	if we point at one pointer then we fill another one, because 
	the array we are pointing at is the one under processing...*/
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef* huart)
{
 
	buf_sel = 0;
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	if (arsnr_db > 16)
				Inferring_shape();
	else 		
				Training_shape();


}
/* END of HALF CALL BACK FUNCTION */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
	//full_debug = 1;
	buf_sel = 1;
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, RESET);
	//sample.buff_p = rx_window2;
	Inferring_shape();

 
	/* END OF ELSE SAMPLE.BUFF_P */

}

void Training_shape(void)
{

	if (buf_sel == 0)
	{

		for (i = 0; i < RX_SIZE >> 1; i = i + 8)
		{
			rx_str[0] = sample.rx_sample[i + 1];
			rx_str[1] = sample.rx_sample[i + 2];
			rx_str[2] = sample.rx_sample[i + 3];
			rx_str[3] = sample.rx_sample[i + 4];
			rx_str[4] = sample.rx_sample[i + 5];
			rx_str[5] = sample.rx_sample[i + 6];
			rx_str[6] = sample.rx_sample[i + 7];
			//rx_str[7] = sample.rx_sample[i + 7];
 			X1_train[sample.sample_c][0] = atof((char*)rx_str);
			sample.sample_c++;
		}
				
			sample.sample_c = 0;
		 	miir_zscore_f32(N_WINDOWS, X1_train, D_DIM); 
			Set_Event(PCAEvents, PCA_TRAIN_EVT);
	}
	 
}


void Inferring_shape(void)
{

	if (buf_sel == 0)
	{

		for (i = 0; i < RX_SIZE >> 1; i = i + 8)
		{
			rx_str[0] = sample.rx_sample[i + 1];
			rx_str[1] = sample.rx_sample[i + 2];
			rx_str[2] = sample.rx_sample[i + 3];
			rx_str[3] = sample.rx_sample[i + 4];
			rx_str[4] = sample.rx_sample[i + 5];
			rx_str[5] = sample.rx_sample[i + 6];
			rx_str[6] = sample.rx_sample[i + 7];
			//rx_str[7] = sample.rx_sample[i + 7];
 
				X1_valid[0][sample.sample_c] = atof((char*)rx_str);
				sample.sample_c++;
		}
				sample.sample_c = 0;

		/* Vibrations z-scoring function - I can just call it here */ 
			miir_zscore_f32(D_DIM, X1_valid, D_DIM); 
			Set_Event(PCAEvents, PCA_INFERRING_EVT);
	}
	else if (buf_sel == 1)
	{

		for (i = RX_SIZE >> 1; i < RX_SIZE; i = i + 8)
		{
			rx_str[0] = sample.rx_sample[i + 1];
			rx_str[1] = sample.rx_sample[i + 2];
			rx_str[2] = sample.rx_sample[i + 3];
			rx_str[3] = sample.rx_sample[i + 4];
			rx_str[4] = sample.rx_sample[i + 5];
			rx_str[5] = sample.rx_sample[i + 6];
			rx_str[6] = sample.rx_sample[i + 7];
			X2[0][sample.sample_c] = atof((char*)rx_str);
			sample.sample_c++;
		}
		sample.sample_c = 0;
		/* Vibrations z-scoring function - I can just call it here */
		miir_zscore_f32(D_DIM, X2, D_DIM); 
		Set_Event(PCAEvents, PCA_INFERRING_EVT);
	}
}




















