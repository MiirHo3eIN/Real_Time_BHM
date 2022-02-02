/*
 * function_pca.h
 *
 *  Created on: Jun 18, 2021
 *      Author: miirho3ein
 */

#ifndef INC_FUNCTION_PCA_H_
#define INC_FUNCTION_PCA_H_

#include <stdint.h>
#include "defines.h"

//#define NOK 0U



/* z-Score Conversion */ 
float miir_mean_f32(int16_t n_col, float X[][n_col], int16_t blockSize);
void miir_mean_centering_f32(int16_t n_col,  float X[][n_col], int16_t blockSize); 

float miir_std_f32(int16_t n_col ,float X[][n_col], int16_t blockSize);
void miir_zscore_f32(int16_t n_col  ,float  X[][n_col], uint16_t blockSize); 




/* Reconstruction functions */
void miir_mat_compression_f32( float X[N_WINDOWS][D_DIM], float Q[][K_COMP], float XC[][K_COMP]);
void miir_mat_decompression_f32( float XC[N_WINDOWS][K_COMP], float Q[][K_COMP], float Dst[][D_DIM]);


/* ARSNRdB computation */

float  miir_rsnr_f32(float x[N_WINDOWS][D_DIM],float xr[N_WINDOWS][D_DIM]);
float miir_arsnrdb_f32(float x[N_WINDOWS][D_DIM],float xr[N_WINDOWS][D_DIM]);

void miir_power_f32(float X[N_WINDOWS][D_DIM] , float  Res[N_WINDOWS]);
void miir_mat_sub_2d_f32( float X[][D_DIM], float Xr[][D_DIM],float Dst[][D_DIM]);

/* mean square error computation */ 
float miir_mse_f32( float X[][D_DIM], float Xr[][D_DIM]); 


#endif /* INC_FUNCTION_PCA_H_ */
