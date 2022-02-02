/*
 * functions_pca.c
 *
 *  Created on: Jun 18, 2021
 *      Author: miirho3ein
 */

#include <stdint.h>
#include "function_pca.h"
#include <stdio.h>
//#include "arm_math.h"
#include <math.h>
#include "defines.h"

/*
 * This function returns 
    result = (pSrc[0]+pSrc[1]+pSrc[2]+ ... + pSrc[blockSize-1]/blockSize); 

    implementation only valid for floating-point   
 */

 float miir_mean_f32(int16_t n_col, float X[][n_col], int16_t blockSize)
 {

    float temp_acm = 0.0f; 
    int i = 0U;
    if (n_col == N_WINDOWS)
    {
        while(i<blockSize)
        {
            temp_acm += X[i][0]; 
            i++; 
        }
    }
    else if (n_col == D_DIM)
    {
        while (i<blockSize)
        {
            temp_acm += X[0][i]; 
            i++;
        }
    }

    return (temp_acm/blockSize);
 }


/* 
*   this function returns the mean centered value of a given vector pSrcs[] 
    
    python equaivalnet of this implementation: 
    pDst = pSrc  - np.mean(pSrc[], axis = 0);

    valid only for floating-point 
*/  
 
void miir_mean_centering_f32(int16_t n_col, float X[][n_col], int16_t blockSize)
{

    float sample_mean = 0.0f;
    sample_mean = miir_mean_f32(n_col , X , D_DIM);
  
        for (int i_cnt= 0 ; i_cnt<D_DIM ; i_cnt ++)
        {
            if (n_col == N_WINDOWS)     X[i_cnt][0] = X[i_cnt][0] - sample_mean ;

            else if (n_col == D_DIM)    X[0][i_cnt] = X[0][i_cnt] - sample_mean ; 

        }       
}


float miir_std_f32(int16_t n_col, float X[][n_col], int16_t blockSize)
{
    float sample_mean = 0.0f ; 
    float temp_div = 0.0f; 
    float temp_sum = 0.0f;

    sample_mean = miir_mean_f32(n_col, X, blockSize);
    for (int i_cnt = 0 ; i_cnt < D_DIM; i_cnt++)
    {
        if (n_col == N_WINDOWS)             temp_div = X[i_cnt][0] - sample_mean;

        else if (n_col == D_DIM)            temp_div = X[0][i_cnt] - sample_mean; 

        temp_sum += temp_div * temp_div; 
    }
        return sqrt(temp_sum/blockSize);

}

 

/*
    This function returns the zscore values of raw vibrated data. 
    It accept int and also float and returns float. 

    @brief:
    python implementation is: 
    X0 = X0 - np.mean(X0)
    X0 = X0 / np.std(X0)
    note that this implementation is only for 1D arrays(vector) since we observe only one window 
    in realtime proccessing.
    
    @param[in]          pSrc - Input vector 
    @param[in]          blockSize - size of input 
    @param[out]         pDst - output vector  

*/ 
 
 
void miir_zscore_f32(int16_t n_col, float  X[][n_col], uint16_t blockSize) 
{

 
    float std_val = 0.0f ;

 

    miir_mean_centering_f32(n_col, X, blockSize); 
    std_val = miir_std_f32(n_col, X, blockSize);

    for (int i = 0; i < D_DIM; i ++)
    {
        
        if (n_col == N_WINDOWS)       X[i][0] /=  std_val; 

        else if (n_col == D_DIM)      X[0][i] /= std_val; 
    }


}
 

 


/*
    *   Returns matrix multplication of two input array. 
*/
void miir_mat_compression_f32( float X[N_WINDOWS][D_DIM], float Q[][K_COMP], float XC[][K_COMP])
{

    int i= 0, j= 0, k= 0; 
    float temp_val;

    for(i= 0; i<N_WINDOWS; i++)
    {
        for(k = 0; k< K_COMP ; k++)
        {
            for(j= 0; j<D_DIM; j++)
            {
 
                temp_val += X[i][j] * Q[j][k];
            }

            XC[i][k] = temp_val;
            temp_val = 0;
            j = 0;
        }// End of Src2 Row

    } // End of Src1 Row

}



void miir_mat_decompression_f32( float XC[N_WINDOWS][K_COMP], float Q[][K_COMP], float Dst[][D_DIM])
{

    int i= 0, j= 0, k= 0; 
    float temp_val;

    for(i= 0; i<N_WINDOWS; i++)
    {
        for(j = 0; j< D_DIM ; j++)
        {
            for(k= 0; k<K_COMP; k++)
            {

                 
                temp_val += XC[i][k] * Q[j][k];
            }

            Dst[i][j] = temp_val;
            temp_val = 0;
            k = 0;
        }// End of Src2 Row
       j = 0;
    } // End of Src1 Row

}
/* Evaluation functions */ 
 
/*


* @defpower 
*   Calculates the sum of squares of the elements in a 2d vector in the axis =0 direction   
*   python implementation is np.pow(x, axis = 0)
*
*   Algorithm implemented is proposed by ARM software team is as follows: 
*   
*       res[i][j] = x[0][j]*x[0][j] + x[1][j]*x[1][j] + ... + x[n-1][j]*x[n-1][j]
*
*   @param[in]      X[D_DIM][N_WINDOWS]
*   @param[out]     Res[N_WINDOWS]
* 
*/
void miir_power_f32(float X[N_WINDOWS][D_DIM] , float  Res[N_WINDOWS])
{

    float temp_res = 0.0f; 

      
     
        for (int i_cnt =0 ; i_cnt<N_WINDOWS; i_cnt++)
        {
            for (int j_cnt = 0; j_cnt<D_DIM; j_cnt++)
            {
                temp_res += X[i_cnt][j_cnt] * X[i_cnt][j_cnt];
            }
            Res[i_cnt] = temp_res;
            temp_res = 0.0f; 
        }
     
}



/* 
* @defmatrixSubtractiom 
*    
*
*   @param[in]      X[D_DIM][N_WINDOWS]
*   @param[in]      Xr[N_WINDOWS][D_DIM]
*   @param[out]     Res[N_WINDOWS]
* 
*/

void miir_mat_sub_2d_f32( float X[][D_DIM], float Xr[][D_DIM],float Dst[][D_DIM])
{

    for (int i_cnt = 0; i_cnt< N_WINDOWS; i_cnt++)
    {
        for (int j_cnt = 0; j_cnt<D_DIM; j_cnt++)
        {
            //printf("x[%d][%d] = %5.5f\n", j_cnt, i_cnt, X[j_cnt][i_cnt]);
            //printf("xr[%d][%d] = %5.5f\n", j_cnt, i_cnt, Xr[i_cnt][j_cnt]);

            Dst[i_cnt][j_cnt] = X[i_cnt][j_cnt] - Xr[i_cnt][j_cnt]; 
        

            //printf("Dst[%d][%d] = %5.5f \n", j_cnt, i_cnt, Dst[j_cnt][i_cnt] );

        }
    }

}

float  miir_rsnr_f32( float x[][D_DIM],float xr[][D_DIM])
{

 

    float sum_sqr_x[N_WINDOWS] = {0.0f};
    float sum_sqr_x_xr[N_WINDOWS] = {0.0f};
    float temp_d[N_WINDOWS][D_DIM] = {{0.0f}};

 


    miir_power_f32(x, sum_sqr_x);  

    miir_mat_sub_2d_f32(x, xr, temp_d);
 
    miir_power_f32(temp_d, sum_sqr_x_xr);

    return (sum_sqr_x[0]/sum_sqr_x_xr[0]);

}

 
float miir_arsnrdb_f32(float x[N_WINDOWS][D_DIM],float xr[N_WINDOWS][D_DIM])
{

    float rsnr_val_temp;
    float temp_log_val;

    rsnr_val_temp = miir_rsnr_f32(x, xr);
    temp_log_val = log10(rsnr_val_temp);

    return 10*temp_log_val;
}
 


float miir_mse_f32( float X[][D_DIM], float Xr[][D_DIM])
{

    float temp_buf[][D_DIM] = {{0.0f}}; 
    float temp_pow[N_WINDOWS] = {0.0f}; 

    miir_mat_sub_2d_f32(X, Xr, temp_buf); 

    miir_power_f32(temp_buf, temp_pow); 
    
    return temp_pow[0]/ D_DIM; 



}


