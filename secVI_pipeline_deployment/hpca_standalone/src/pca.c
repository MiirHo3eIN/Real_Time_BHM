/*
 * pca.c

 *
 *  Created on: 15 mag 2019
 *      Author: ale_m
 */
#include "pca.h"

extern  float Vinit[D_DIM][K_COMP];
void HPCA_step(float X[][B], int ib, float Q[][K_COMP], float D[K_COMP])
{
	/*
	 * Dimensions of the matrixes:
	 * X is D_DIM x B
	 * Q is D_DIM x K_COMP
	 * S is D_DIM x K_COMP
	 * D is K x K diagonal
	 * A is D_DIM x D_DIM
	 */
	float S[D_DIM][K_COMP];
	float A[D_DIM][D_DIM];

	if (ib==0)
	{

		qr_opt(Vinit, Q);
		for (int i = 0; i<D_DIM; i++)
		{
			for(int j=0; j<D_DIM; j++)
			{
		          float sum = 0;
		          for(int ui=0; ui<B; ui++)
		          {
		        	  sum += X[i][ui]*X[j][ui];
		          }
		          A[i][j]=sum/B;
		    }
			A[i][i] += 1;
		 }
	}
	else
	{
		for (int i = 0; i<D_DIM; i++)
		{
			for(int j=0; j<D_DIM; j++)
			{
		          float sum = 0;
		          for(int ui=0; ui<K_COMP; ui++)
		          {
		        	  sum += Q[i][ui]*D[ui]*Q[j][ui];
		          }
		          A[i][j]=sum/(ib+1)*ib;
		          sum = 0;
		          for(int ui=0; ui<B; ui++)
		          {
		        	  sum += X[i][ui]*X[j][ui];
		          }
		          A[i][j]+=sum/B/(ib+1);
		    }
		}
	}
	for (int z = 0; z<INNER_LOOP; z++)
	{
		for (int j = 0; j<D_DIM; j++)
		{
			for(int i=0; i<K_COMP; i++)
			{
		          float sum = 0;
		          for(int ui=0; ui<D_DIM; ui++)
		          {
		        	  sum += A[j][ui]*Q[ui][i];
		          }
		          S[j][i]=sum;
		    }
		}

		if (z == (INNER_LOOP-1))
		{
			for(int i = 0; i<K_COMP;i++){
				float n = 0.0f;
				for(int j=0;j<D_DIM;j++) {
					n = n + S[j][i] * S[j][i];
				}
				D[i] = sqrt(n);
			}
		}
		qr_opt(S, Q);
	}

}

void random_generator_Vinit()
{
	int z = 0;
	for (int i=0;i<D_DIM;i++)
		for (int j=0;j<K_COMP;j++){
			Vinit[i][j]=z;
			z = z+1;}
			//Vinit[i][j]=rand()/RAND_MAX*100;
}

