/*
 * PCATask.c
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */

 /* Main Includes */
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* FreeRTOS includes */
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"
#include "event_groups.h"

/* Peripheral Includes */
#include "tim.h"
#include "usart.h"
#include "dma.h"

/* Private Includes */
#include "VibrationTask.h"
#include "PCATask.h"
#include "DecisionUnitTask.h"

#include "defines.h"
#include "function_pca.h"
#include "function_qr.h"
#include "pca.h"
#include "V_init.h"

/* cmsis functions*/
#include "arm_math.h"

/* eigen values include */
#include "eig_buff_5sec_CF16.h"

/* Private Printf */
 

#pragma GCC diagnostic ignored "-Wunused-variable"

static StaticEventGroup_t PCAEventGroupBuffer;
EventGroupHandle_t PCAEvents;


/* ========= PCA variables ============== */

/* Inferring: */

float32_t arsnr_db = 0.0f; 
float32_t mse_res = 0.0f; 
float metrices[2] = {0.0f}; 
float X_compress[N_WINDOWS][K_COMP] = {{0.0f}}; 
float Xr[N_WINDOWS][D_DIM] = {{0.0f}};

/* Training */ 
float i[D_DIM];
float d[K_COMP] = {0.0f};
float Q[D_DIM][K_COMP];
float D[K_COMP];
float A[D_DIM][D_DIM]= {{0.0f}};
int itt = 0U; 

arm_status status;

/* Debugging Variables */
int debug = 0;
int eg_debug = 0;
int mean_debug = 0;
 /* USER CODE BEGIN Header_PCAFunc */
 /**
 * @brief Function implementing the PCATask thread.
 * @param argument: Not used
 * @retval None
 */
 /* USER CODE END Header_PCAFunc */
void PCAFunc(void const* argument)
{
    /* USER CODE BEGIN PCAFunc */
	PCAEvents = xEventGroupCreateStatic(&PCAEventGroupBuffer); //create the Group Event
	EventBits_t uxBits;
#define IS_EVT(x) 	uxBits & x
	osDelay(1);
	char* str1 = "PCA_EVENT_GROUP_CREATED_FAIL\r\n";
	char* str2 = "PCA_EVENT_GROUP_CREATED_SUCCESSFULLY\r\n";
	char* str3 = "==============================================\r\n";
	if (PCAEvents == NULL) 	HAL_UART_Transmit(&huart3, (uint8_t*)str1, strlen(str1), 300);
	else 	HAL_UART_Transmit(&huart3, (uint8_t*)str2, strlen(str2), 300);
	HAL_UART_Transmit(&huart3, (uint8_t*)str3, strlen(str3), 300);
	configASSERT(PCAEvents);
    /* Infinite loop */
    for (;;)
    {
		uxBits = xEventGroupWaitBits(
			PCAEvents,
			PCA_TRAIN_EVT | PCA_INFERRING_EVT,
			pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
			pdFALSE,       /* Don't wait for both bits, either bit will do. */
			100);

		if (IS_EVT(PCA_TRAIN_EVT))
		{
			 

				PCA_Trainning(X1_train, Q, D, itt);
				itt++;

			 
		}
		/* END OF MEAN_CENTERING_EVT Event*/
 
		if (IS_EVT(PCA_INFERRING_EVT))
		{
			 
			if (buf_sel == 0)
			{
				PCA_Inferring(X1_valid, Q, metrices);
				arsnr_db = metrices[0]; 
				mse_res = metrices[1]; 
			}		
			
			else if (buf_sel == 1)	
			{
				PCA_Inferring(X2, Q, metrices);
				arsnr_db = metrices[0]; 
				mse_res = metrices[1]; 
			}


 			if (arsnr_db>16)			Set_Event(DecisionUnitEvents, VIB_EVT);
			 
			 
		}
       // osDelay(1);
    }
    /* USER CODE END PCAFunc */
}

void PCA_Trainning(float X[][N_WINDOWS], float Q[D_DIM][K_COMP], float D[K_COMP],int itt)
{
 
  HPCA_step(X, itt , Q, D);
}

void PCA_Inferring(float X_valid[][D_DIM],float Q[][K_COMP],float FoM[2])
{
    miir_mat_compression_f32(X_valid, Q, X_compress); 
    miir_mat_decompression_f32(X_compress, Q, Xr); 


    FoM[0] = miir_arsnrdb_f32(X_valid, Xr); 
    FoM[1] = miir_mse_f32(X_valid, Xr);
     
}
