/*
 * lsm6dso.h
 *
 *  Created on: Apr 18, 2025
 *      Author: borsuk
 */

#ifndef INC_LSM6DSO_H_
#define INC_LSM6DSO_H_
#include "stm32f1xx_hal.h"
#include <string.h>
#include <inttypes.h>
#include "lsm6ds3.h"

float convert_accel_raw_to_g(int16_t raw, float scale) {
    return raw * scale;
}

void set_ctrl1_xl(I2C_HandleTypeDef* hi2cx, uint8_t value) {
	HAL_I2C_Mem_Write(hi2cx, LSM6DSO_ADDR, CTRL1_XL, 1, &value, 1, HAL_MAX_DELAY);
}

void set_ctrl2_g(I2C_HandleTypeDef* hi2cx, uint8_t value) {
	HAL_I2C_Mem_Write(hi2cx, LSM6DSO_ADDR, CTRL2_G, 1, &value, 1, HAL_MAX_DELAY);
}

uint8_t get_outx_l_g(I2C_HandleTypeDef* hi2cx) {
    uint8_t outx_l_g = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTX_L_G, 1, &outx_l_g, 1, HAL_MAX_DELAY);

    return outx_l_g;
}

uint8_t get_outx_h_g(I2C_HandleTypeDef* hi2cx) {
    uint8_t outx_h_g = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTX_H_G, 1, &outx_h_g, 1, HAL_MAX_DELAY);

    return outx_h_g;
}

int16_t get_x_g(I2C_HandleTypeDef* hi2cx) {
    return (uint16_t)(get_outx_h_g(hi2cx) << 8 | get_outx_l_g(hi2cx));
}

uint8_t get_outy_l_g(I2C_HandleTypeDef* hi2cx) {
    uint8_t outy_l_g = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTY_L_G, 1, &outy_l_g, 1, HAL_MAX_DELAY);

    return outy_l_g;
}

uint8_t get_outy_h_g(I2C_HandleTypeDef* hi2cx) {
    uint8_t outy_h_g = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTY_H_G, 1, &outy_h_g, 1, HAL_MAX_DELAY);

    return outy_h_g;
}

int16_t get_y_g(I2C_HandleTypeDef* hi2cx) {
	return (int16_t)((get_outy_h_g(hi2cx) << 8) | get_outy_l_g(hi2cx));
}

uint8_t get_outz_l_g(I2C_HandleTypeDef* hi2cx) {
    uint8_t outz_l_g = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTZ_L_G, 1, &outz_l_g, 1, HAL_MAX_DELAY);

    return outz_l_g;
}

uint8_t get_outz_h_g(I2C_HandleTypeDef* hi2cx) {
    uint8_t outz_h_g = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTY_H_G, 1, &outz_h_g, 1, HAL_MAX_DELAY);

    return outz_h_g;
}

int16_t get_z_g(I2C_HandleTypeDef* hi2cx) {
    return (int16_t)(get_outz_h_g(hi2cx) << 8 | get_outz_l_g(hi2cx));
}

uint8_t get_outx_l_xl(I2C_HandleTypeDef* hi2cx) {
    uint8_t outx_l_xl = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTX_L_XL, 1, &outx_l_xl, 1, HAL_MAX_DELAY);

    return outx_l_xl;
}

uint8_t get_outx_h_xl(I2C_HandleTypeDef* hi2cx) {
    uint8_t outx_h_xl = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTX_H_XL, 1, &outx_h_xl, 1, HAL_MAX_DELAY);

    return outx_h_xl;
}

int16_t get_x_xl(I2C_HandleTypeDef* hi2cx) {
    return (int16_t)(get_outx_h_xl(hi2cx) << 8 | get_outx_l_xl(hi2cx));
}

uint8_t get_outy_l_xl(I2C_HandleTypeDef* hi2cx) {
    uint8_t outy_l_xl = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTY_L_XL, 1, &outy_l_xl, 1, HAL_MAX_DELAY);

    return outy_l_xl;
}

uint8_t get_outy_h_xl(I2C_HandleTypeDef* hi2cx) {
    uint8_t outy_h_xl = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTY_H_XL, 1, &outy_h_xl, 1, HAL_MAX_DELAY);

    return outy_h_xl;
}

int16_t get_y_xl(I2C_HandleTypeDef* hi2cx) {
    return (uint16_t) get_outy_h_xl(hi2cx) << 8 | get_outy_l_xl(hi2cx);
}

uint8_t get_outz_l_xl(I2C_HandleTypeDef* hi2cx) {
    uint8_t outz_l_xl = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTZ_L_XL, 1, &outz_l_xl, 1, HAL_MAX_DELAY);

    return outz_l_xl;
}

uint8_t get_outz_h_xl(I2C_HandleTypeDef* hi2cx) {
    uint8_t outz_h_xl = 0;
    HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, OUTZ_H_XL, 1, &outz_h_xl, 1, HAL_MAX_DELAY);

    return outz_h_xl;
}

int16_t get_z_xl(I2C_HandleTypeDef* hi2cx) {
    return (int16_t)(get_outz_h_xl(hi2cx) << 8 | get_outz_l_xl(hi2cx));
}


uint8_t get_who_am_i(I2C_HandleTypeDef* hi2cx) {

	uint8_t who_am_i = 0;
	HAL_I2C_Mem_Read(hi2cx, LSM6DSO_ADDR, WHO_AM_I, 1, &who_am_i, 1, HAL_MAX_DELAY);

	return who_am_i;
}

uint8_t is_valid_who_am_i(uint8_t who_am_i) {
	return who_am_i == 0x69;
}

void INIT_LSM6DSO(I2C_HandleTypeDef* hi2cx) {
	uint8_t who_am_i = get_who_am_i(hi2cx);

	if (is_valid_who_am_i(who_am_i)) {
		set_ctrl1_xl(hi2cx, (uint8_t)0b10100000);
		set_ctrl2_g(hi2cx, (uint8_t)0b10000000);
	}
}

#endif /* INC_LSM6DSO_H_ */
