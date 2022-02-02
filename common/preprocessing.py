import numpy as np 
import pandas as pd 




RSNR = lambda x, xr: np.sum(x**2, axis=0)/np.sum((x - xr)**2, axis=0)
ARSNR = lambda x, xr: np.mean(RSNR(x, xr))
RSNRdB = lambda x, xr: 10*np.log10(RSNR(x, xr))
ARSNRdB = lambda x, xr: 10*np.log10(ARSNR(x, xr))
### ==================================================
mse_w = lambda x, xr: np.mean((x - xr)**2, axis=0)
mse = lambda x, xr: np.mean(mse_w(x, xr))



def roll_windows(ds, input_dim):
    d = input_dim
    n = ds.shape[0]
    n0 = n // input_dim
    data = ds[:n0*input_dim]
    data = data.reshape((n0,d)).T
    data_mean = data - np.mean(data, axis = 0)
    energy = np.sum(data_mean**2, axis = 0)/input_dim
    return data, data_mean, energy



def energy_filter(X, input_dim , thr):
    d = input_dim 
    raw , mean_, energy_ = roll_windows(X, d)
    valid_energies = energy_ > thr
    return mean_[:, valid_energies]



def threshold_finder(train_input, valid_input , input_dim): 
    init_threshold = 10e-10
    conv = (1*2.5)*2**-15
    d = input_dim
    for factor in np.arange(1,10): 
        threshold = init_threshold * (5**factor)
        print(f"threshold at step {factor} is {threshold}")
        train , mean_train, energy_train = roll_windows(train_input, d)
            
        valid_energies = energy_train > threshold
        
        reduced_train = mean_train[:, valid_energies]
        print('training set composed by {} instances'.format(mean_train.shape[1]))
        print('total valid windows is {} '.format(np.sum(valid_energies)))

        Ex_t, Vx_t, k_t = pca_preprocessing(reduced_train, d)
        valid , mean_valid,energy_valid = roll_windows(valid_input, d)
        valid_energies = energy_valid > threshold
        reduced_valid = mean_valid[:, valid_energies]
        valid_rpca = pca_reconst_preprocesing(reduced_valid, Vx_t, k_t)
        arsnrpca = ARSNRdB(reduced_valid, valid_rpca)
        print('ARSNR_PCA = {:.2f}'.format(arsnrpca))
        if arsnrpca*2 > 15:
        	print('Valid ARSNR_PCA = {:.2f}, correct threshold = {}, final k is = {}'.format(arsnrpca, threshold, k_t))
        	return threshold

import time 
import datetime as dt
def time_slot_gen(start_date, end_date, output_dim):
    # number of hours in the requested days
    frac = output_dim 
    hours = int((end_date - start_date).days)*24*frac
    # generating time stamps (second by second based on starting day)
    for n in np.arange(hours):
        yield (dt.datetime.utcfromtimestamp(time.mktime(start_date.timetuple())).timestamp() + 60*(60/frac)*n)

# finding EigenValues and Eigenfunctions and reduced dimention
def pca_preprocessing(dataset, n):
    energy_percentage = 0.97
    Cx = np.dot(dataset, dataset.T)/n
    Ex, Vx = np.linalg.eigh(Cx)
    Ex = Ex[::-1]
    Vx = Vx[:, ::-1]
    lcumsum = np.cumsum(Ex/np.sum(Ex))
    k = np.argmax(lcumsum > energy_percentage)
    return Ex,Vx,k

# Reconstruct of PCA
pca_reconst_preprocesing = lambda data,eigenvector, k: np.linalg.multi_dot([eigenvector[:, :k], eigenvector[:, :k].T, data])