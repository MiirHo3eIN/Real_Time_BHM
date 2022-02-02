import numpy as np 
import pandas as pd 



if __name__ == "__main__": 
    df0 = pd.read_parquet('values/ss335-acc2019-05-10S613.parquet')
    d = 100
    N0 = len(df0) // d
    print('Raw values... \n')
    print(df0[:20])
    print('\n')
    
    
    df0 = df0['z'].values[:d*N0].reshape(N0, d).T
    X0 = df0 - np.mean(df0, axis=0)
    X0 = X0 / np.std(X0, axis=0) 
    print("z-scored values... \n")
    print(X0[:20, 0])