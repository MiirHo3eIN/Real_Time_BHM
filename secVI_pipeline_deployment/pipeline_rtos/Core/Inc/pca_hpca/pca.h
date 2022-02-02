/*
 * pca.h
 *
 *  Created on: 15 mag 2019
 *      Author: ale_m
 */

#ifndef PCA_H_
#define PCA_H_

#include "function_qr.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"


void HPCA_step(float X[D_DIM][B], int ib, float Q[D_DIM][K_COMP], float D[K_COMP]);
void random_generator_Vinit();


#endif /* PCA_H_ */