/*
 * Function_qr.h
 *
 *  Created on: 13 mag 2019
 *      Author: ale_m
 */
#include "defines.h"
#include "math.h"

#ifndef FUNCTION_QR_H_
#define FUNCTION_QR_H_
void qr_opt(float X[][K_COMP], float Q[][K_COMP]);
void qyhous(int n_rows, int n_cols, float X[][n_cols], float i[n_cols]);
void qrhous(int n_samples, int n_cols, float X[][K_COMP], float* d);
void transform2(float X[][K_COMP], float i[K_COMP], int begin_index);
void transform1(int n_rows, int n_cols, float X[][K_COMP], int begin_index);
void part_div(float X[][K_COMP], int begin_index, int end_index, float div);
float norm(float x[][K_COMP], int begin_index, int end_index);
#endif /* FUNCTION_QR_H_ */
