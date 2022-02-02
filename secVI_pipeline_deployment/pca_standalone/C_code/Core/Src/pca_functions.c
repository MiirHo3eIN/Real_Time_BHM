/*
 * pca_functions.c
 *
 *  Created on: Jan 21, 2021
 *      Author: MiiR_Ho3e!N
 */


//#include "pca_functions.h"
#include "main.h"
//#include "pca_defines.h"

/*
 * Variables Declarations
 */
arm_status status;
extern uint16_t high_dim;
extern uint16_t samples_num ;
extern uint16_t low_dim ;

/*
 * 1. Windowing and Mean Centering
 */
void mean_centering(float32_t In[], float32_t Out[]){

		float32_t conv = CONV;
		float32_t In_scaled[(int16_t)INPUT_SIZE];
		float32_t buff_mean_mat[(int16_t)INPUT_SIZE];
		float32_t buff_mean_org;

		arm_matrix_instance_f32 A; 					// High_Dimensionla_Data
		arm_matrix_instance_f32 A_scaled; 			// To scale it down
		arm_matrix_instance_f32 mean; 				// MSE to shape the window
		arm_matrix_instance_f32 data_ready; 		// shaped data

			arm_mat_init_f32(&A, 			samples_num, high_dim, (float32_t *)In);
			arm_mat_init_f32(&A_scaled,  	samples_num, high_dim, (float32_t *)In_scaled);
			arm_mat_init_f32(&mean, 		samples_num, high_dim, (float32_t *)buff_mean_mat);
			arm_mat_init_f32(&data_ready,  	samples_num, high_dim, (float32_t *)Out);




				status = arm_mat_scale_f32(&A, (float32_t)conv, &A_scaled); 								// first we multiply by conv in here
	   	   	  if (status == ARM_MATH_SIZE_MISMATCH)		Error_Handler();

	  	  	  arm_mean_f32((float32_t *)In_scaled, (uint32_t)INPUT_SIZE, &buff_mean_org); 					// Then we compute mean of the data
	  	  	  arm_fill_f32(buff_mean_org, (float32_t *)buff_mean_mat, INPUT_SIZE);							// fill the mean to be able to subtract
	  	  	  status = arm_mat_sub_f32(&A_scaled, &mean, &data_ready);										// mean centered data

	  	  	  if (status == ARM_MATH_SIZE_MISMATCH)		Error_Handler();

}

/*
 * 2. Energy Check
 */

int energy_filter(float32_t In[]){
	double eg_thr = ENERGY_THR;
	float32_t eg_validation;
	float32_t buff_energy;

	arm_power_f32(In, INPUT_SIZE, &buff_energy);
	eg_validation = buff_energy / INPUT_SIZE;

	if (eg_validation>eg_thr)
		return 1 ;
		else return 0;
}

/*
 * 3. Data Scaling
 */
void data_scaling(float32_t In[], float32_t Out[]){

		arm_status status;
		/* Local Buffer Instantiation ========== */
		float32_t row_mean;
		float32_t buff_mean_mat[(int16_t)INPUT_SIZE];
		float32_t row_std;
		float32_t buff_top[(int16_t)INPUT_SIZE];

		/* Local Matrix Instantiation  ========= */
		arm_matrix_instance_f32 In_mat;
		arm_matrix_instance_f32 mean_mat;
		arm_matrix_instance_f32 top;
		arm_matrix_instance_f32 Out_mat;
		/* Local Matrix Initialization ======== */
		arm_mat_init_f32(&In_mat, 	samples_num,high_dim,  		(float32_t *)In);
		arm_mat_init_f32(&mean_mat, samples_num,high_dim, 		(float32_t *)buff_mean_mat);
		arm_mat_init_f32(&top, 		samples_num,high_dim, 		(float32_t *)buff_top);
		arm_mat_init_f32(&Out_mat, 	samples_num,high_dim, 		(float32_t *)Out);
		/* center mean the shaped data ======== */
		arm_mean_f32((float32_t *)In, INPUT_SIZE, &row_mean);
		arm_fill_f32(row_mean, (float32_t *)buff_mean_mat, INPUT_SIZE);
		arm_mat_sub_f32(&In_mat, &mean_mat, &top);
		/* division by standard division */
		arm_std_f32(In, INPUT_SIZE, &row_std);
		float32_t std_top = 1/ row_std;
		status = arm_mat_scale_f32(&top, std_top, &Out_mat);
		if (status == ARM_MATH_SIZE_MISMATCH)
			  Error_Handler();

}

/*
 * 4. Reconstruction and MSE computation
 */

float32_t pca_computing(float32_t In[], float32_t Eigen_Val[], float32_t Eigen_Val_T[], float32_t Out[]){

	/*
	 * Local Buffers
	 */
	arm_status status;
	float32_t buff_compress[(int16_t)K];
	float32_t buff_sub_mse[(int16_t)INPUT_SIZE];
	float32_t buff_pow_mse;
	/*
	 * Matrix declaration
	 */
	arm_matrix_instance_f32 normalize_data; 		// insering to PCA
	arm_matrix_instance_f32 Compressor; 			// Eigen Values
	arm_matrix_instance_f32 deCompressor; 			// Eigen Value Transpose
	arm_matrix_instance_f32 compressed_data;		// In * EigenVal
	arm_matrix_instance_f32 reconstructed; 			// Reconstructed data
	arm_matrix_instance_f32 sub_mse;				// (x - rpca)
	/*
	 * Matrix Initialization
	 */
	arm_mat_init_f32(&normalize_data, samples_num, high_dim, (float32_t *)In);
	arm_mat_init_f32(&Compressor, high_dim, low_dim, (float32_t *)Eigen_Val);				/* eigen 		  */
	arm_mat_init_f32(&deCompressor, low_dim, high_dim, (float32_t *)Eigen_Val_T); 			/* eigen_transpose */

	arm_mat_init_f32(&compressed_data,  samples_num, low_dim, (float32_t *)buff_compress); 	/* compress result 		*/

	arm_mat_init_f32(&reconstructed, samples_num, high_dim, (float32_t *)Out);				/* Reconstructed	*/

	arm_mat_init_f32(&sub_mse, samples_num, high_dim, buff_sub_mse);							/* MSE */


			#ifndef FLASH_USE
			status = arm_mat_trans_f32(&Compressor, &deCompressor);
			#endif

			status = arm_mat_mult_f32(&normalize_data, &Compressor ,&compressed_data);     /*(1xIn_window) * (In_windowxK) = (1xK)*/

		    status = arm_mat_mult_f32(&compressed_data, &deCompressor, &reconstructed);

			status = arm_mat_sub_f32(&normalize_data, &reconstructed, &sub_mse);
			arm_power_f32(buff_sub_mse, INPUT_SIZE, &buff_pow_mse);
	  		return buff_pow_mse/(float)(INPUT_SIZE);

}



