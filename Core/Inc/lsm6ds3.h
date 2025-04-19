/*
 * lsm6dso.h
 *
 *  Created on: Apr 18, 2025
 *      Author: borsuk
 */

#define LSM6DSO_ADDR (0x6B << 1)
#define WHO_AM_I 0x0F

#define CTRL1_XL 0x10
#define CTRL2_G 0x11

#define OUTX_L_G 0x22
#define OUTX_H_G 0x23

#define OUTY_L_G 0x24
#define OUTY_H_G 0x25

#define OUTZ_L_G 0x26
#define OUTZ_H_G 0x27

#define OUTX_L_XL 0x28
#define OUTX_H_XL 0x29

#define OUTY_L_XL 0x2A
#define OUTY_H_XL 0x2B

#define OUTZ_L_XL 0x2C
#define OUTZ_H_XL 0x2D


#ifndef INC_LSM6DSO_H_
#define INC_LSM6DSO_H_

#include "stm32f1xx_hal.h"
void INIT_LSM6DSO();
void set_ctrl1_xl(I2C_HandleTypeDef* hi2cx, uint8_t value);
void set_ctrl2_g(I2C_HandleTypeDef* hi2cx, uint8_t value);

uint8_t get_outx_l_g(I2C_HandleTypeDef* hi2cx);
uint8_t get_outx_h_g(I2C_HandleTypeDef* hi2cx);
uint16_t get_x_g(I2C_HandleTypeDef* hi2cx);

uint8_t get_outy_l_g(I2C_HandleTypeDef* hi2cx);
uint8_t get_outy_h_g(I2C_HandleTypeDef* hi2cx);
uint16_t get_y_g(I2C_HandleTypeDef* hi2cx);

uint8_t get_outz_l_g(I2C_HandleTypeDef* hi2cx);
uint8_t get_outz_h_g(I2C_HandleTypeDef* hi2cx);
uint16_t get_z_g(I2C_HandleTypeDef* hi2cx);

uint8_t get_outx_l_xl(I2C_HandleTypeDef* hi2cx);
uint8_t get_outx_h_xl(I2C_HandleTypeDef* hi2cx);
uint16_t get_x_xl(I2C_HandleTypeDef* hi2cx);

uint8_t get_outy_l_xl(I2C_HandleTypeDef* hi2cx);
uint8_t get_outy_h_xl(I2C_HandleTypeDef* hi2cx);
uint16_t get_y_xl(I2C_HandleTypeDef* hi2cx);

uint8_t get_outz_l_xl(I2C_HandleTypeDef* hi2cx);
uint8_t get_outz_h_xl(I2C_HandleTypeDef* hi2cx);
uint16_t get_z_xl(I2C_HandleTypeDef* hi2cx);

uint8_t get_who_am_i(I2C_HandleTypeDef* hi2cx);
uint8_t is_valid_who_am_i(uint8_t who_am_i);
float convert_accel_raw_to_g(int16_t raw, float scale);

#endif /* INC_LSM6DSO_H_ */
