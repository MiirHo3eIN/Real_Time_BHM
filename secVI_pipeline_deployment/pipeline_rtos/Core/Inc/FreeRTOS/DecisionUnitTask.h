/*
 * DecisionUnitTask.h
 *
 *  Created on: May 31, 2021
 *      Author: miir_ho3ein
 */

#ifndef INC_FREERTOS_DECISIONUNITTASK_H_
#define INC_FREERTOS_DECISIONUNITTASK_H_



#define OUT_DIM	12*15 // equal to 15 minutes of acquiering 


#define NOISE_EVT		(1<<0)
#define VIB_EVT			(1<<1)
#define DECISION_EVT	(1<<2)


extern EventGroupHandle_t DecisionUnitEvents;
extern int valid_window_c; 



void DecisionUnitFunc(void const* argumnet);







#endif /* INC_FREERTOS_DECISIONUNITTASK_H_ */
