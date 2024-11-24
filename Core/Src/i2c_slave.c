/*
 * i2c_slave.c
 *
 *  Created on: Nov 24, 2024
 *      Author: Hp User
 */

#include "main.h"
#include "i2c_slave.h"

//I2C handle as the external variable
extern I2C_HandleTypeDef hi2c1;

//receive buffer size
#define RxSIZE 6
uint8_t RxData[RxSIZE];

int count =0;

void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c) {

	HAL_I2C_EnableListen_IT(hi2c);
}

// smaller<=6bytes data accepts

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
 if(TransferDirection == I2C_DIRECTION_TRANSMIT)
 {
	 HAL_I2C_Slave_Seq_Receive_IT(hi2c, RxData, RxSIZE, I2C_FIRST_AND_LAST_FRAME);
 }

 else {
	 Error_Handler();
 }
}

void HAL_I2C_SlaveRxCpltCallback (I2C_HandleTypeDef *hi2c){

	count++;
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c) {

	HAL_I2C_EnableListen_IT(hi2c);
}
