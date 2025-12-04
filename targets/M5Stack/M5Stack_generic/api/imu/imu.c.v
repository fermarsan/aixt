// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Power module for M5Stack (arduino backend)
module imu

#include "imu.c"


fn C.M5_IMU_INIT() int
fn C.M5_IMU_GETGRES()
fn C.M5_IMU_GETARES()
fn C.M5_IMU_GETACCELADC(ax &i16, ay &i16, az &i16)
fn C.M5_IMU_GETGYROADC(gx &i16, gy &i16, gz &i16)
fn C.M5_IMU_GETTEMPADC(t &i16)
fn C.M5_IMU_GETACCELDATA(ax &f32, ay &f32, az &f32)
fn C.M5_IMU_GETGYRODATA(gx &f32, gy &f32, gz &f32)
fn C.M5_IMU_GETTEMPDATA(t &f32)
fn C.M5_IMU_GETAHRSDATA(pitch &f32, roll &f32, yaw &f32)
fn C.M5_IMU_SETFIFOENABLE(enable_flag bool)
fn C.M5_IMU_READFIFO()
fn C.M5_IMU_READFIFOBUFF(data_buf &u8, length u16)
fn C.M5_IMU_READFIFOCOUNT()
fn C.M5_IMU_RESTFIFO()

@[as_macro]
pub fn setup() int {
	return C.M5_IMU_INIT() 
}

@[as_macro]
pub fn get_gres() {
	C.M5_IMU_GETGRES()
}

@[as_macro]
pub fn get_ares() {
	C.M5_IMU_GETARES()
}

@[as_macro]
pub fn get_accel_adc(ax &i16, ay &i16, az &i16) {
	C.M5_IMU_GETACCELADC(ax, ay, az)
}

@[as_macro]
pub fn get_gyro_adc(gx &i16, gy &i16, gz &i16) {
	C.M5_IMU_GETGYROADC(gx, gy, gz)
}

@[as_macro]
pub fn get_temp_adc(t &i16) {
	C.M5_IMU_GETTEMPADC(t)
}

@[as_macro]
pub fn get_accel_data(ax &f32, ay &f32, az &f32) {
	C.M5_IMU_GETACCELDATA(ax, ay, az)
}

@[as_macro]
pub fn get_gyro_data(gx &f32, gy &f32, gz &f32) {
	C.M5_IMU_GETGYRODATA(gx, gy, gz)
}

@[as_macro]
pub fn get_temp_data(t &f32) {
	C.M5_IMU_GETTEMPDATA(t)
}

@[as_macro]
pub fn get_ahrs_data(pitch &f32, roll &f32, yaw &f32) {
	C.M5_IMU_GETAHRSDATA(pitch, roll, yaw)
}

@[as_macro]
pub fn fifo_enable(enable_flag bool) {
	C.M5_IMU_SETFIFOENABLE(enable_flag)
}

@[as_macro]
pub fn read_fifo() {
	C.M5_IMU_READFIFO()
}

@[as_macro]
pub fn read_fifo_buff(data_buf &u8, length u16) {
	C.M5_IMU_READFIFOBUFF(data_buf, length)
}

@[as_macro]
pub fn read_fifo_count() {
	C.M5_IMU_READFIFOCOUNT()
}

@[as_macro]
pub fn rest_fifo() {
	C.M5_IMU_RESTFIFO()}

