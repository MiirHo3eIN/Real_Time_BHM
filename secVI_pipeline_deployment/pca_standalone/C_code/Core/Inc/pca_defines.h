/*
 * pca_defines.h
 *
 *  Created on: Jan 21, 2021
 *      Author: MiiR_Ho3e!N
 */

#ifndef INC_PCA_DEFINES_H_
#define INC_PCA_DEFINES_H_


/* input dimesions */
#define INPUT_DIM 5

/* Compression Factor */
#define CF 32


#define OK 	1U
#define NOK 0U

#define FULL 1U
#define NFULL 0U


#if INPUT_DIM == 5
	#define HIGH_DIM 5*100
	#define SAMPLE_NUM 1
	#define NORMAL_THR 0.5
	#define ANOMALY_THR 1.5
	#define BUFF_OUTPUT_LEN 15*12 // each minute has 12 windows of 5 seconds
	#if    CF == 4
	#define K 124
	#define FLASH_USE
	#elif  CF == 8
	#define K 63
	#define FLASH_USE
	#elif CF == 16
	#define K 31
	#elif CF == 32
	#define K 16
	#elif CF == NO
	#define K 36
	#endif // CF endif
#endif // input window endif

#if INPUT_DIM == 2
	#define HIGH_DIM 2*100
	#define SAMPLE_NUM 1
	#define NORMAL_THR 0.26
	#define ANOMALY_THR 1.5
	#define BUFF_OUTPUT_LEN 15*30 //each minute has 30 windows of 2 second
	#if	   CF == 4
	#define K 50
	#elif  CF == 8
	#define K 25
	#elif  CF == 16
	#define K 13
	#elif  CF == 32
	#define K 6
	#elif  CF == NO
	#define K 20
#endif // CF endif

#endif

#if INPUT_DIM == 1
	#define HIGH_DIM 1*100
	#define SAMPLE_NUM 1
	#define NORMAL_THR 0.21
	#define ANOMALY_THR 1.5
	#define BUFF_OUTPUT_LEN 15*60 // each minute has 60 windows of 1 second
	#if	CF == 4
	#define K 25
	#elif CF == 8
	#define K 13
	#elif CF == 16
	#define K 6
	#elif CF == 32
	#define K 4
	#elif CF == NO
	#define K 18

#endif
#endif


#define INPUT_SIZE HIGH_DIM*SAMPLE_NUM
#define COMPRESSION_SIZE (HIGH_DIM*K)
#define ENERGY_THR 0.000003125
#define CONV (float32_t)(7.62939453125/100000)



#endif /* INC_PCA_DEFINES_H_ */
