/*
 * pca_wrapper.c
 *
 *  Created on: Jan 21, 2021
 *      Author: MiiR_Ho3e!N
 */

//#include "pca_defines.h"
//#include "pca_functions.h"
#include "main.h"

#if INPUT_DIM == 1

	#if		CF == 4
			#include "eig_buff_1sec_CF4.h"
	#elif 	CF == 8
			#include "eig_buff_1sec_CF8.h"
	#elif 	CF == 16
			#include "eig_buff_1sec_CF16.h"
	#elif 	CF == 32
			#include "eig_buff_1sec_CF32.h"
	#elif	CF 	== NO
			#include "eig_buff_1.h"
#endif // CF endif

#endif


#if INPUT_DIM == 2
	#if	   CF == 4
			#include "eig_buff_2sec_CF4.h"
	#elif  CF == 8
			#include "eig_buff_2sec_CF8.h"
	#elif  CF == 16
			#include "eig_buff_2sec_CF16.h"
	#elif  CF == 32
			#include "eig_buff_2sec_CF32.h"
	#elif  CF == NO
			#include "eig_buff_2.h"
#endif // CF endif

#endif

#if INPUT_DIM == 5
	#if    	CF == 4
			#include "eig_buff_5sec_CF4.h"
			#include "eig_buff_5sec_CF4_tran.h"
	#elif  	CF == 8
			#include "eig_buff_5sec_CF8.h"
			#include "eig_buff_5sec_CF4_tran.h"
	#elif 	CF == 16
			#include "eig_buff_5sec_CF16.h"
	#elif 	CF == 32
			#include "eig_buff_5sec_CF32.h"
	#elif	CF 	== NO
			#include "eig_buff_5.h"

#endif // CF endif


#endif // input window endif


/* Variables */
float32_t shaped_data[(int16_t)INPUT_SIZE];  				// shaped data
float32_t pca_entry_data[(int16_t)INPUT_SIZE];
#ifndef FLASH_USE
float32_t eigen_val_tran[(int16_t)COMPRESSION_SIZE];
#endif
float32_t mse_res;
int energy_valid;
arm_status status;

float32_t pca(float32_t In[], float32_t Out[]){


	mean_centering(In, shaped_data);		/* 	mean centered data  */

	energy_valid 	=  energy_filter(shaped_data);
	if (energy_valid == OK)
	{
			data_scaling(shaped_data, pca_entry_data);

			mse_res = pca_computing(pca_entry_data, eig_buff, eigen_val_tran, Out); 	/* It does the PCA and return MSE */


	}
	else if(energy_valid == NOK)	mse_res = 0;

	return mse_res;


}
