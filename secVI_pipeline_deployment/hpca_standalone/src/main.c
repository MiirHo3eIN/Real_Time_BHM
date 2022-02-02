/**
  ******************************************************************************
  * @file    main.c
  * @author  Benatti Simone & Bojan Milosevic
  * @version V1.0
  * @date    22-Mar-2017
  * @brief   Main function and LEDS
  ******************************************************************************
*/


/******** Includes  **********/
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "defines.h"
#include "Function_qr.h"
#include "pca.h"
#include "data.h"
/******** Dfines  ***********/
// PROFILING
unsigned int cyc[2];
volatile unsigned int *DWT_CYCCNT = (volatile unsigned int *)0xE0001004; 	// Cycle counter
volatile unsigned int *DWT_CONTROL= (volatile unsigned int *)0xE0001000;	// counter control
volatile unsigned int *SCB_DEMCR  = (volatile unsigned int *)0xE000EDFC;
#define STOPWATCH_START {cyc[0]=*DWT_CYCCNT;} 								// start counting
#define STOPWATCH_STOP  {cyc[1]=*DWT_CYCCNT; cyc[1]=cyc[1]-cyc[0];}			// stop counting, result is in cyc[1]
#define STOPWATCH_INIT {*SCB_DEMCR = *SCB_DEMCR | 0x01000000; *DWT_CYCCNT = 0; *DWT_CONTROL = *DWT_CONTROL | 1 ;}


/******** Declarations ******/

/* Function prototype */
// float X_local[D_DIM][K_COMP+4] = {{0.0f}};
 //float X_step[D_DIM][B];
 float i[D_DIM];
 float d[K_COMP] = {0.0f};
void HPCA(float X[][N_WINDOWS], float Q[][K_COMP], float D[K_COMP])
{
	/*for (int ib =0;ib<(N_WINDOWS/B);ib++){
		for(int j = 0; j < B; j++){
			for(int i = 0; i < D_DIM; i++){
			  X_step[i][j] = X[i][ib*B+j];
			}
		}*/
		STOPWATCH_INIT
		STOPWATCH_START	/* Start counting cycles */
		HPCA_step(X, 0, Q, D);
		STOPWATCH_STOP /* Stop counting cycles, result is in cyc[1] */
		STOPWATCH_INIT
		STOPWATCH_START	/* Start counting cycles */
		HPCA_step(X, 0, Q, D);
		STOPWATCH_STOP /* Stop counting cycles, result is in cyc[1] */
	//}
}
/******** Main *******/
int main() {
	float Q[D_DIM][K_COMP];
	float D[K_COMP];
	//random_generator_Vinit();

	HPCA(X, Q, D);
	/* Blink */
	while(1);
}

