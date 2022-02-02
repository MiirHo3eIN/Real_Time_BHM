/*
 * DecisionUnitTask.c
 *
 *  Created on: May 31, 2021
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


#pragma GCC diagnostic ignored "-Wunused-variable"

/* Create Event groups */
static StaticEventGroup_t DecisionUnitEventGroupBuffer;
EventGroupHandle_t DecisionUnitEvents; 

int dim_cnt = 0; 
int valid_window_c = 0;
int quarter_mse_cnt = 0;
int valid_quarters=0;

float32_t mse_buff[OUT_DIM];
float32_t tracker ;
float32_t status ;
float32_t quarter_mse[4];
 
 void DecisionUnitFunc(void const* argument)
{




	DecisionUnitEvents = xEventGroupCreateStatic(&DecisionUnitEventGroupBuffer); //create the Group Event
	EventBits_t uxBits;
#define IS_EVT(x) 	uxBits & x
	osDelay(250);
	char* str1 = "DECISION_UNIT_EVENT_GROUP_CREATED_FAIL\r\n";
	char* str2 = "DECISION_UNIT_EVENT_GROUP_CREATED_SUCCESSFULLY\r\n";
	char* str3 = "==============================================\r\n";
	if (DecisionUnitEvents == NULL) 	HAL_UART_Transmit(&huart3, (uint8_t*)str1, strlen(str1), 300);
	else 	HAL_UART_Transmit(&huart3, (uint8_t*)str2, strlen(str2), 300);
	HAL_UART_Transmit(&huart3, (uint8_t*)str3, strlen(str3), 300);
	configASSERT(DecisionUnitEvents);
int j;
	   for (;;)
	{
		   uxBits = xEventGroupWaitBits(
			   DecisionUnitEvents,
			   NOISE_EVT | VIB_EVT | DECISION_EVT,
			   pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
			   pdFALSE,       /* Don't wait for both bits, either bit will do. */
			   100);
		   char* cnt_str;
		   if (IS_EVT(NOISE_EVT))
		   {
			   if (dim_cnt == OUT_DIM-1)
			   {
				   Set_Event(DecisionUnitEvents, DECISION_EVT);
				   dim_cnt = 0;
				   for (j = 0; j < OUT_DIM ; j++)
				   {
					   tracker += mse_buff[j];
				   }
				   if (valid_window_c!=0) tracker /= valid_window_c;
				   else tracker = 0;
				   valid_window_c = 0;
				   memset(mse_buff, 0, OUT_DIM * sizeof(float32_t));
			   }
			   else dim_cnt++; 
		   }
		   if (IS_EVT(VIB_EVT))
		   {
			   if (dim_cnt == OUT_DIM-1)
			   {
				   mse_buff[dim_cnt] = mse_res;
				   Set_Event(DecisionUnitEvents, DECISION_EVT);
				   dim_cnt = 0;
				   valid_window_c++;
				   for (j = 0; j < OUT_DIM ; j++)
				   {
					   tracker += mse_buff[j];
				   }
				   if (valid_window_c!=0) tracker /= valid_window_c;
				   else tracker = 0;
				   valid_window_c = 0;
				   memset(mse_buff, 0, OUT_DIM * sizeof(float32_t));
			   }
			   else
			   {
				   mse_buff[dim_cnt] = mse_res;
				   valid_window_c++;
				   dim_cnt++;
			   }
		   }

		   if (IS_EVT(DECISION_EVT))
		   {	
 
			   if (quarter_mse_cnt == 2)
			   { 
				    if (tracker != 0) valid_quarters++;
					quarter_mse[quarter_mse_cnt] = tracker;
					status = (quarter_mse[0] + quarter_mse[1] + quarter_mse[2] + quarter_mse[3]) / valid_quarters;
					
					quarter_mse_cnt = 0;
					memset(quarter_mse, 0, 4 * sizeof(float32_t));
					valid_quarters = 0;



					if (status > MSE_THR)
					{
						char* fail_str;
						sprintf(fail_str ,"NOK because mse is %f\r\n\n", status); 
						HAL_UART_Transmit(&huart3, (uint8_t*)fail_str, strlen(fail_str), 100);
					}
					else
					{
						char* succ_str;
						sprintf(succ_str, "OK because mse is %f\r\n\n", status);
						HAL_UART_Transmit(&huart3, (uint8_t*)succ_str, strlen(succ_str), 100);
					}
			   }
			   else
			   {
				   quarter_mse[quarter_mse_cnt] =  tracker;
				   quarter_mse_cnt++;
				   if (tracker != 0) valid_quarters++;
			   }
			   
		   }




	   }


}
