/*
 * PCATask.h
 *
 *  Created on: May 25, 2021
 *      Author: miir_ho3ein
 */

#ifndef INC_FREERTOS_PCATASK_H_
#define INC_FREERTOS_PCATASK_H_

#include "arm_math.h"
#include "defines.h"


#define IN_DIM 5
#define CONV (float32_t)(7.62939453125/100000)
#define SAMPLES_NUM  (uint16_t)(1)
#define HIGH_DIM	 (uint16_t)(IN_DIM*100)
#define ENERGY_THR   (double)(0.000003125)
#define OK 	1U
#define LOW_DIM 31  /// This can be defined as HIGH_DIM/CF(=16)
#define EIGEN_TRANS_SIZE (HIGH_DIM*LOW_DIM) 
#define MSE_THR		(double)0.4141049338671898

/* Events of PCA*/
 
#define PCA_TRAIN_EVT			(1<<0)
#define PCA_INFERRING_EVT		(1<<1)

extern		EventGroupHandle_t PCAEvents;

extern		float32_t mse_res;
extern 		float32_t arsnr_db; 
 


void PCAFunc(void const* argument);

void PCA_Trainning(float X[][N_WINDOWS], float Q[D_DIM][K_COMP], float D[K_COMP],int itt); 
void PCA_Inferring(float X_valid[][D_DIM],float Q[][K_COMP],float FoM[2]); 


/*
int energy_filter(float32_t In[]);
void mean_centering(float32_t In[], float32_t Out[]); 
void data_scaling(float32_t In[], float32_t Out[]);
float32_t pca_computing(float32_t In[], const float Eigen_Val[], float32_t Eigen_Val_T[], float32_t Out[]);
*/ 
#endif /* INC_FREERTOS_PCATASK_H_ */
