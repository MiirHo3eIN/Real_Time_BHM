import numpy as np 
import pandas as pd 
import datetime as dt 
from tqdm.notebook import tqdm
from common.preprocessing import *
from common.preprocessing import time_slot_gen, energy_filter


import tensorflow as tf
from sklearn.model_selection import train_test_split

from keras.models import Model, load_model

from keras.layers import Input, Dense

from keras.callbacks import ModelCheckpoint, TensorBoard

from keras import regularizers

import keras

from tensorflow.keras.optimizers import SGD,Adam

import math
from keras.layers import Input, Dense, Conv1D, MaxPooling1D, UpSampling1D, BatchNormalization, LSTM, RepeatVector, Flatten
from keras.models import Model
from keras.models import model_from_json
from keras import regularizers
import datetime
import time
import requests as req
import json
import pandas as pd
import os
from sklearn.preprocessing import MinMaxScaler
from tqdm import tqdm
from mpl_toolkits.mplot3d import Axes3D

from tqdm.notebook import tqdm


def fft_transform_(x, axis_):

	return np.abs(np.real(np.fft.fft(x, axis=axis_)))


class pca:

	def __init__(
		self, 
		input_dim, 
		domain, 
		energy_threshold, 
		CF):

		"""
		Principal Component Analysis builder and predictor. 

		:param input_dim:			Input Dimension of each rolled windows 
		:param domain:				Domain of Analysis time/frequency/Discrete Wavelet Transform
		:param energy_threshold:	Train threshold of Energy to discard the white noise 
		:param CF:					Latent dimension of subspace domain
		"""

		self.domain = domain
		self.energy_threshold = energy_threshold
		self.cf = CF
		self.dim = input_dim 

	def fit(self, dataset):
		"""
		fit the pca to find eigen values and eigen vectors of training set. 

		:param dataset: trainset in shape M (number of features) x N (number of samples)
		:retrun Ex: 	Eigen-Values of PCA 
		:return Vx: 	Eigen-Vectors of PCA 
		:return k:		Optimal Sub-space domain 
		"""
		energy_percentage = 0.97
		Cx = np.dot(dataset, dataset.T)/self.dim 
		Ex, Vx = np.linalg.eigh(Cx)
		Ex = Ex[::-1]
		Vx = Vx[:, ::-1]
		lcumsum = np.cumsum(Ex/np.sum(Ex))
		k = np.argmax(lcumsum > energy_percentage)
		return Ex,Vx,k


	def pca_reconst(self, data, eigenvector):
		"""
		Returns reconstructed signal based on Eigen Vectors and Compression Factor 

		:param data: 		original data in high space dimension 
		:param eigenvector: eigenvectors to project data from high dimensional to latens space
		:param k: 			latent space
		:return: 			reconstructed signal  
		""" 
		return np.linalg.multi_dot([eigenvector[:, :self.cf], eigenvector[:, :self.cf].T, data])


	def predict_time_(self, dataset, Vx):
		"""
		Compute Mean Square Error in time domain 

		:param dataset: 1D Acceleration 
		:param Vx: 		Eigen Values of trained pca 
		:return mse_:	Single MSE for a period in time domain 
		"""

		x_recons = self.pca_reconst(data = dataset, eigenvector = Vx) 
		mse_ =  mse(dataset, x_recons)
		return mse_

	def predict_dwt_(self, dataset, Vx):
		"""
		Compute Mean Square Error in Discerete Wavelet domain

		:param dataset:dataset: 1D Acceleration 
		:param Vx: 		Eigen Values of trained pca 
		:return mse_:	Single MSE for a period of DWT transform values   
		"""
		coef_Apx, coef_delta = pywt.dwt(dataset, wavelet = 'db10', mode='symmetric', axis= 0)
		x_recons = self.pca_reconst(data = coef_Apx, eigenvector = Vx)
		mse_ =  mse(coef_Apx, x_recons)
		return mse_

	def predict_freq_(self, dataset, Vx, axis_):
		"""
		Compute Mean Square Error in Frequency domain

		:param dataset:dataset: 1D Acceleration  
		:param Vx: 		Eigen Values of trained pca 
		:return mse_:	Single MSE for a period of DWT transform values   
		"""
		fft_amp = fft_transform_(dataset, axis_ = axis_)
		x_recons = self.pca_reconst(data = fft_amp, eigenvector = Vx)
		mse_       = mse(fft_amp, x_recons)
		return mse_

	def predict(self, ds, Vx, dt_start, dt_end):
		"""
		Returns MSE values of interval of 15 minutes 

		:param ds:			dataset of 5 days for testing 
		:param Vx:			Trained Eigen Vectors 
		:param ds_start:	Start date in dataset
		:param ds_end: 		Finish date in dateset
		:return output:		Dictionary with 2 <value/pair> of MSE/starting date of the interval  
		"""
		output = {}
		conv = (1*2.5)*2**-15
		for d_inx in tqdm([date for date in time_slot_gen(dt_start,dt_end, 4)]): 

			init = ds['ts']/1000 > d_inx
			last = ds['ts']/1000 < d_inx + (60*15) 
			section = ds['z'][init & last]
			if section.shape[0]>0: 
				filtered_data = energy_filter(section*conv, self.dim, self.energy_threshold)
				if filtered_data.shape[1]>0:
					filtered_data = sklearn.preprocessing.scale(filtered_data, axis=0, with_mean=True, with_std=True, copy=True)
					if self.domain == 'time':
						mse_temp = self.predict_time_(filtered_data, Vx)
					elif self.domain == 'frequency': 
						mse_temp = self.predict_freq_(filtered_data, Vx, axis_=0)
					elif self.domain == 'wavelet': 
						mse_temp = self.predict_dwt_(filtered_data, Vx )
					if output == {}:
						output['mse'] = mse_temp
						output['date'] = d_inx
					else: 
						output['mse'] = np.append(output['mse'], mse_temp)
						output['date'] = np.append(output['date'], d_inx)
		return output



import sklearn 
class fc_ae(tf.keras.Model):
	def __init__(
		self, 
		latent_dim, 
		input_dim, 
		batch_size, 
		epoch_num, 
		domain, 
		energy_threshold
		):

		"""
		Fully Connected Autoencoder Class for train & predict 

		:param latent_dim:
		:param input_dim:
		:param batch_size:
		:param epoch_num:
		:param domain:
		:param energy_threshold:
		"""


		super().__init__() 
		self.latent_dim 		= latent_dim 
		self.input_dim 			= input_dim 
		self.batch_size 		= batch_size
		self.nb_epoch 			= epoch_num
		self.domain 			= domain 
		self.energy_threshold 	= energy_threshold


		# define the model here 
		self.encoder = tf.keras.layers.Dense(self.latent_dim, activation = 'linear')
		self.decoder = tf.keras.layers.Dense(self.input_dim, activation = 'linear')

	def forward(self):
		input_layer  = tf.keras.layers.Input(shape=(self.input_dim,))
		hidden_layer = self.encoder(input_layer)
		output_layer = self.decoder(hidden_layer)
		model 		 = Model(inputs = input_layer, outputs = output_layer)
		model.summary()
		return model
	
	def step_decay(self, epoch):
		initial_lrate = 1e-1
		drop = 0.1
		epochs_drop = 10.0
		lrate = initial_lrate * math.pow(drop, math.floor((1+epoch)/epochs_drop))
		return lrate
	def compile_(self, model): 
		
		adam = Adam(learning_rate=1e-2, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False)
		lrCallBack = keras.callbacks.LearningRateScheduler(self.step_decay)
		model.compile(optimizer='adam', loss='mean_squared_error', metrics=['mse'])
		return model , lrCallBack
	def fit(self, build_model , X_train, X_test):
		model_compiled , lrCallBack = self.compile_(build_model) 
		#Checkpointer is used to save a model or weights (in a checkpoint file) at some interval. 
		checkpointer = ModelCheckpoint(filepath="model.h5", verbose=0, save_best_only=True)
		# TensorBoard is a visualization tool provided with TensorFlow.
		tensorboard = TensorBoard(log_dir='./logs', histogram_freq=0, write_graph=True, write_images=True)
		history = model_compiled.fit(X_train,X_train, epochs=self.nb_epoch, batch_size=self.batch_size, shuffle=True, validation_data=(X_test, X_test), verbose=1, callbacks=[tensorboard, lrCallBack]).history
		return model_compiled , history


	def predict_time_(self, dataset, trained_model):
		
		normalized_data = sklearn.preprocessing.scale(dataset, axis=0, with_mean=True, with_std=True, copy=True)
		predict = trained_model.predict(normalized_data.T)
		mse_ = np.mean(np.power(normalized_data.T-predict,2), axis = 1)
		return np.mean(mse_)

	def predict_dwt_(self, dataset, trained_model): 

		
		coef_Apx, coef_delta = pywt.dwt(dataset, wavelet = 'db10', mode='symmetric', axis= 0)
		normalized_data = sklearn.preprocessing.scale(coef_Apx, axis=0, with_mean=True, with_std=True, copy=True)
		predict = trained_model.predict(normalized_data.T)
		mse_ = np.mean(np.power(normalized_data.T-predict,2), axis = 1)
		return np.mean(mse_)

	def predict_freq_(self, dataset, Vx):
		
		fft_amp = fft_transform_(dataset, axis_ = 0)
		normalized_data = sklearn.preprocessing.scale(fft_amp, axis=0, with_mean=True, with_std=True, copy=True) 
		predict = trained_model.predict(normalized_data.T)
		mse_ = np.mean(np.power(normalized_data.T-predict,2), axis = 1)
		return np.mean(mse_)

	def predict(self, ds, trained_model, dt_start, dt_end):
		output = {}
		conv = (1*2.5)*2**-15
		for d_inx in tqdm([date for date in time_slot_gen(dt_start,dt_end, 4)]): 

			init = ds['ts']/1000 > d_inx
			last = ds['ts']/1000 < d_inx + (60*15) 
			section = ds['z'][init & last]
			if section.shape[0]>0: 
				filtered_data = energy_filter(section*conv, self.input_dim, self.energy_threshold)
				if filtered_data.shape[1]>0:
					if self.domain == 'time':
						mse_temp = self.predict_time_(filtered_data, trained_model)
					elif self.domain == 'frequency': 
						mse_temp = self.predict_freq_(filtered_data, trained_model)
					elif self.domain == 'wavelet': 
						mse_temp = self.predict_dwt_(filtered_data, trained_model )
					if output == {}:
						output['mse'] = mse_temp
						output['date'] = d_inx
					else: 
						output['mse'] = np.append(output['mse'], mse_temp)
						output['date'] = np.append(output['date'], d_inx)
		return output

class cnn_ae(tf.keras.Model):
	def __init__(
		self, 
		input_dim, 
		batch_size, 
		epoch_num, 
		domain, 
		energy_threshold
		):

		super().__init__()
		self.input_dim 			= input_dim 
		self.batch_size 		= batch_size
		self.nb_epoch 			= epoch_num
		self.domain 			= domain 
		self.energy_threshold 	= energy_threshold

		self.encoder1 = tf.keras.layers.Conv1D(16, 3, activation = 'sigmoid', padding = 'same')
		self.encoder2 = tf.keras.layers.Conv1D(1, 7, activation = 'sigmoid', padding = 'same')
		self.batch_norm1 = tf.keras.layers.BatchNormalization()
		self.batch_norm2 = tf.keras.layers.BatchNormalization()



		self.pooling1 = tf.keras.layers.MaxPooling1D(2, padding = 'same')
		self.pooling2 = tf.keras.layers.MaxPooling1D(2, padding = 'same')

		self.decoder1 = tf.keras.layers.Conv1D(1, 7, activation = 'sigmoid', padding = 'same')
		self.batch_norm3 = tf.keras.layers.BatchNormalization()
		self.decoder2 = tf.keras.layers.Conv1D(16, 2, activation = 'sigmoid', padding = 'same')
		self.batch_norm4 = tf.keras.layers.BatchNormalization()
		self.decoder3 = tf.keras.layers.Conv1D(1, 3, activation = 'linear', padding = 'same')

		self.upsampling1 = tf.keras.layers.UpSampling1D(2)
		self.upsampling2 = tf.keras.layers.UpSampling1D(2)


	def forward_fit(self,X_train, X_test):
		input_layer = tf.keras.layers.Input(shape = (self.input_dim, 1))
		hidden_layer1 = self.encoder1(input_layer)
		hidden_layer1 = self.batch_norm1(hidden_layer1)
		hidden_layer1 = self.pooling1(hidden_layer1)
		print(hidden_layer1.shape)

		hidden_layer2 = self.encoder2(hidden_layer1)
		print(hidden_layer2.shape)
		hidden_layer2 = self.batch_norm2(hidden_layer2)
		bottle_neck = self.pooling2(hidden_layer2)

		bottle_neck_model   = tf.keras.Model(input_layer, hidden_layer2) 

		hidden_layer3 = self.decoder1(bottle_neck)
		hidden_layer3 = self.batch_norm3(hidden_layer3)
		hidden_layer3 = self.upsampling1(hidden_layer3)

		hidden_layer4 = self.decoder2(hidden_layer3)
		hidden_layer4 = self.batch_norm4(hidden_layer4)
		hidden_layer4 = self.upsampling2(hidden_layer4)

		deoded_signal = self.decoder3(hidden_layer4) 
		model = tf.keras.Model(input_layer, deoded_signal)

		model.summary()

		def step_decay(epoch):
			initial_lrate = 1e-1
			drop = 0.1
			epochs_drop = 10.0
			lrate = initial_lrate * math.pow(drop, math.floor((1+epoch)/epochs_drop))
			return lrate
		adam = Adam(learning_rate=1e-2, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False)
		lrCallBack = keras.callbacks.LearningRateScheduler(step_decay)
		model.compile(optimizer='adam', loss='mean_squared_error', metrics=['mse'])
		
		#Checkpointer is used to save a model or weights (in a checkpoint file) at some interval. 
		checkpointer = ModelCheckpoint(filepath="model.h5", verbose=0, save_best_only=True)
		# TensorBoard is a visualization tool provided with TensorFlow.
		tensorboard = TensorBoard(log_dir='./logs', histogram_freq=0, write_graph=True, write_images=True)
		history = model.fit(X_train,X_train, epochs=self.nb_epoch, batch_size=self.batch_size, shuffle=True, validation_data=(X_test, X_test), verbose=1, callbacks=[tensorboard, lrCallBack]).history
		return model , history

	def predict_time_(self, dataset, trained_model):

		normalized_data = sklearn.preprocessing.scale(dataset.T, axis=0, with_mean=True, with_std=True, copy=True)

		predict = trained_model.predict(normalized_data.reshape(normalized_data.shape[0],normalized_data.shape[1],1))

		mse_ = np.mean(np.power(normalized_data - predict[:, :, 0], 2), axis = 1)
		return np.mean(mse_)

	def predict_dwt_(self, dataset, trained_model): 
		coef_Apx, coef_delta = pywt.dwt(dataset, wavelet = 'db10', mode='symmetric', axis= 0)

		shape = np.shape(coef_Apx)

		test_sec = np.zeros((shape[0]+1, shape[1]))
		test_sec[:shape[0],:shape[1]] = coef_Apx

		normalized_data = sklearn.preprocessing.scale(test_sec.T, axis=0, with_mean=True, with_std=True, copy=True)

		predict = trained_model.predict(normalized_data.reshape(normalized_data.shape[0],normalized_data.shape[1],1))

		mse_ = np.mean(np.power(normalized_data - predict[:, :, 0], 2), axis = 1)

		return np.mean(mse_)

	def predict_freq_(self, dataset, trained_model):
		
		X_test = fft_transform_(dataset, axis_ = 0)
		shape_zpad = np.shape(X_test)
		test_sec = np.zeros((shape_zpad[0]+2, shape_zpad[1]))
		test_sec[:shape_zpad[0],:shape_zpad[1]] = X_test

		normalized_data = sklearn.preprocessing.scale(test_sec.T, axis=0, with_mean=True, with_std=True, copy=True)
		predict = trained_model.predict(normalized_data.reshape(normalized_data.shape[0],normalized_data.shape[1],1))
		mse_ = np.mean(np.power(normalized_data-predict[:,:,0],2), axis = 1)
		return np.mean(mse_)

	def predict(self, ds, trained_model, dt_start, dt_end):
		output = {}
		conv = (1*2.5)*2**-15
		for d_inx in tqdm([date for date in time_slot_gen(dt_start,dt_end, 4)]): 

			init = ds['ts']/1000 > d_inx
			last = ds['ts']/1000 < d_inx + (60*15) 
			section = ds['z'][init & last]
			if section.shape[0]>0: 
				filtered_data = energy_filter(section*conv, self.input_dim, self.energy_threshold)
				if filtered_data.shape[1]>0:
					if self.domain == 'time':
						mse_temp = self.predict_time_(filtered_data, trained_model)
					elif self.domain == 'frequency': 
						mse_temp = self.predict_freq_(filtered_data, trained_model)
					elif self.domain == 'wavelet': 
						mse_temp = self.predict_dwt_(filtered_data, trained_model )
					
					if mse_temp != -math.inf and + math.inf:

						if mse_temp == 0 : 
							continue
						else:
							if output == {}:
								output['mse'] = mse_temp
								output['date'] = d_inx
							else: 
								output['mse'] = np.append(output['mse'], mse_temp)
								output['date'] = np.append(output['date'], d_inx)
		return output




