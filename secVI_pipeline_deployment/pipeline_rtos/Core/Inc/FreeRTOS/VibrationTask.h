/*
 * VibrationTask.h
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */

#ifndef INC_FREERTOS_VIBRATIONTASK_H_
#define INC_FREERTOS_VIBRATIONTASK_H_

#include "main.h" 
#include "PCATask.h"
#include "event_groups.h"
#include "arm_math.h"
#include "defines.h"



#define BYTE 8
#define RX_SIZE D_DIM*BYTE*2
#define UART_INIT (1<<0)

typedef struct
{
	//uint8_t		win_end;				/* String end flag*/
	//uint16_t	rx_sample_c;				/* String lenght*/
	uint8_t    *buff_p;					/* String buffer pointer*/
	uint16_t	sample_c;				/* Counter of the windows */
	uint8_t		rx_sample[RX_SIZE];		/* receieved sample */
}VibrationStructTypeDef;


extern VibrationStructTypeDef sample;

extern float32_t X1_train[D_DIM][N_WINDOWS];
extern float32_t X1_valid[N_WINDOWS][D_DIM];
extern float32_t X2[N_WINDOWS][D_DIM];
extern int buf_sel; 


extern EventGroupHandle_t VibrationEvents;

void VibrationFunc(void const* argument);
void Inferring_shape(void);
void Training_shape(void); 

#endif /* INC_FREERTOS_VIBRATIONTASK_H_ */
