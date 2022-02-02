/*
 * pca_functions.h
 *
 *  Created on: Jan 21, 2021
 *      Author: MiiR_Ho3e!N
 */

#ifndef INC_PCA_FUNCTIONS_H_
#define INC_PCA_FUNCTIONS_H_
#include "arm_math.h"
#include "pca_defines.h"

float32_t pca(float32_t In[], float32_t Out[]);
int energy_filter(float32_t In[]);
void data_scaling(float32_t In[], float32_t Out[]);
void mean_centering(float32_t In[], float32_t Out[]);
float32_t pca_computing(float32_t In[], float32_t Eigen_Val[], float32_t Eigen_Val_T[], float32_t Out[]);
//void get_eigen_val(int8_t input_dim, float32_t Out[]);




#endif /* INC_PCA_FUNCTIONS_H_ */
