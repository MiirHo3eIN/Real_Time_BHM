/*
 * Function_qr.c
 *
 *  Created on: 13 mag 2019
 *      Author: ale_m
 */
#include "defines.h"
#include "Function_qr.h"


//extern float X_local[D_DIM][K_COMP];
extern float i[D_DIM];
extern float d[K_COMP];
float fak;

float Av[D_DIM] = {0.0f};
float iv[D_DIM] = {0.0f};
float AvAvtiv[D_DIM] = {0.0f};
float Avtiv = 0.0f;
float vvtM[D_DIM][K_COMP] = {{0.0f}};
float vtM[K_COMP] = {0.0f};

float norm(float x[][K_COMP], int begin_index, int end_index) {
	float n = 0.0f;
	for(int i=begin_index;i<end_index;i++) {
		n = n + x[i][begin_index] * x[i][begin_index];
    //if(begin_index == 2) printf("%d;", (int)(x[i]*1000));
	}
	return sqrt(n);
}

void part_div(float X[][K_COMP], int begin_index, int end_index, float div) {
	for(int i=begin_index; i<end_index; i+=2) {
		X[i][begin_index]   = X[i][begin_index] / div;
		X[i+1][begin_index] = X[i+1][begin_index] / div;
		// X[i] = X[i] / div;
	}
}

void qr_opt(float X[][K_COMP], float Q[][K_COMP]) {
  // INIT_STATS();
  // PRE_START_STATS();
  //
  // START_STATS();
  for(int j = 0; j < K_COMP; j++){
   /* for(int i = 0; i < D_DIM; i++){
      X_local[i][j] = X[i][j];
       // printf("%d ", (int)(X_local[i][j] * 1000));
    }*/
     // printf("\n");
    i[j] = 0.0f;
  }
  // STOP_STATS();
  qrhous(D_DIM,K_COMP, X, d);

  for (int col_index=0; col_index<K_COMP; col_index++) {
    for(int index=0; index<D_DIM; index++) {
      i[index] = 0.0f;
    }
    i[col_index] = 1.0f;
    qyhous(D_DIM,K_COMP, X, i);
    for(int j=0; j<D_DIM; j++) {
       Q[j][col_index] = i[j];
    }

  }
}

void qrhous(int n_samples, int n_cols, float X[][K_COMP], float* d) {
	float s;
	for(int col_index=0;col_index<n_cols; col_index++)
	{
		s = norm(X,col_index,n_samples);
			if(X[col_index][col_index] >= 0.0f) {
				d[col_index]=-s;
				fak = sqrt(s*(s+X[col_index][col_index]));
			}
			else {
				d[col_index]=s;
				fak = sqrt(s*(s-X[col_index][col_index]));
			}
			X[col_index][col_index] = X[col_index][col_index] - d[col_index];
		part_div(X, col_index, n_samples, fak);
		if(col_index < n_cols-1)
			transform1(n_samples, n_cols, X, col_index);
	}
}

void qyhous(int n_rows, int n_cols, float X[][n_cols], float i[n_rows]) {
	for(int col_counter=n_cols-1; col_counter>=0; col_counter--)
		transform2(X, i, col_counter);
}

void transform2(float X[][K_COMP], float i[D_DIM], int begin_index) {

	int new_n_rows = D_DIM-begin_index;
	for(int row_index=begin_index; row_index<D_DIM; row_index++) {
		Av[row_index] = X[row_index][begin_index];
		iv[row_index] = i[row_index];
		AvAvtiv[row_index] = 0.0f;
	}
	Avtiv = 0.0f;
	for(int i = begin_index; i < D_DIM; i++) {
		Avtiv += Av[i] * iv[i];
	}
	for(int ix = begin_index; ix < D_DIM; ix++){
		AvAvtiv[ix] = Av[ix] * Avtiv;
		//iv[ix] = iv[ix] - AvAvtiv[ix];
		i[ix] = iv[ix] - AvAvtiv[ix];
	}
}
void transform1(int n_rows, int n_cols, float X[][K_COMP], int begin_index) {
	int new_n_rows = n_rows - begin_index;
	int new_n_cols = n_cols - (begin_index + 1);
	for(int i = 0; i < K_COMP; i++){
		vtM[i] = 0.0f;}
	for(int row_index=0; row_index<new_n_rows; row_index++) {
		for(int col_index = begin_index+1; col_index < K_COMP; col_index++){
			if (begin_index == 0 && col_index == 9){
				int z = 0;}
			vtM[col_index] +=  X[begin_index+row_index][begin_index]*X[row_index+begin_index][col_index];
			// printf("===1 [%d %d] %d\n", col_index,  row_index, (int)(X[col_index][row_index+begin_index]*1000));
		}
	}

	for(int i = 0; i < new_n_cols; i++){
		for(int j = 0; j < new_n_rows; j++){
			vvtM[begin_index + j][i + begin_index + 1] = X[begin_index + j][begin_index] * vtM[i + begin_index + 1];
			//printf("=== [%d %d] %d\n", i + begin_index + 1, begin_index + j, (int)(vvtM[i + begin_index + 1][begin_index + j]*1000));
		}
	}
	for(int i = 0; i < new_n_cols; i++){
		for(int j = 0; j < new_n_rows; j++){
			X[begin_index + j][i + begin_index + 1] -= vvtM[begin_index + j][i + begin_index + 1];
		}
	}

}
