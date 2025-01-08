// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: HiTechnic sensors module for NXT(NXC backend)

module ht_sens


@[as_macro]
pub fn as_gyro(port u8) {
	SetSensorHTGyro(port)
}
 
@[as_macro]
pub fn as_magnet(port u8) {
	SetSensorHTMagnet(port)
}
 
@[as_macro]
pub fn as_eopd(port u8, b_standard bool) {
	SetSensorHTEOPD(port, b_standard)
}
 
@[as_macro]
pub fn as_force(port u8) {
	SetSensorHTForce(port)
}
 
 
@[as_macro]
pub fn read_gyro(port u8, offset i16) i16 {
	return SensorHTGyro(port, offset)
}
 
 
@[as_macro]
pub fn read_magnet(port u8, offset i16) i16 {
	return SensorHTMagnet(port, offset)
}
 
 
@[as_macro]
pub fn read_eopd(port u8) i16 {
	return SensorHTEOPD(port)
}
 
 
@[as_macro]
pub fn read_force(port u8) i16 {
	return SensorHTForce(port)
}
 
 
@[as_macro]
pub fn read_color_num(port u8) i16 {
	return SensorHTColorNum(port)
}
 
 
@[as_macro]
pub fn read_compass(port u8) i16 {
	return SensorHTCompass(port)
}
 
@[as_macro]
pub fn read_ir_seeker_dir(port u8) i16 {
	return SensorHTIRSeekerDir(port)
}

@[as_macro]
pub fn as_color(port u8, mode u8) i8 {
	return SetHTColor2Mode(port, mode)
}
 
@[as_macro]
pub fn as_ir_seeker(port u8, mode u8) i8 {
	return SetHTIRSeeker2Mode(port, mode)
}
 
@[as_macro]
pub fn read_accel(port u8, x &i16, y  &i16, z  &i16) bool {
	return ReadSensorHTAccel(port, x, y, z)
}
 
@[as_macro]
pub fn read_color(port u8, color_num &u8,  red &u8, green &u8, blue &u8) bool {
	return ReadSensorHTColor(port, color_num, red, green, blue)
}
 
@[as_macro]
pub fn read_ir_seeker(port u8, dir &u8, s1 &u8, s3 &u8, s5 &u8, s7 &u8, s9 &u8) bool {
	return ReadSensorHTIRSeeker(port, dir, s1, s3, s5, s7, s9)
}
 
@[as_macro]
pub fn read_norm_color(port u8, idx &u8, red &u8, green &u8, blue &u8) bool {
	return ReadSensorHTNormalizedColor(port, idx, red, green, blue)
}
 
@[as_macro]
pub fn read_raw_color(port u8, red &u16, green &u16, blue &u16) bool {
	return ReadSensorHTRawColor(port, red, green, blue)
}

 
@[as_macro]
pub fn read_ir_receiver(port u8, pfdata &[]i8{}) bool {
	return ReadSensorHTIRReceiver(port, pfdata)
}
 
@[as_macro]
pub fn reset_angle(port u8, mode u8) i8 {
	return ResetSensorHTAngle(port, mode)
}
 
@[as_macro]
pub fn read_angle(port u8, angle &i16, acc_angle &int, rpm &i16) bool {
	return ReadSensorHTAngle(port, angle, acc_angle, rpm)
}
 
@[as_macro]
pub fn reset_barometric(port u8) bool {
	ResetHTBarometricCalibration(u8 port)
}
 
@[as_macro]
pub fn setup_barometric(port u8) bool {
	return SetHTBarometricCalibration(u8 port, unsigned i16 cal)
}
 
@[as_macro]
pub fn read_barometric(port u8, temp &i16, press &u16) bool {
	return ReadSensorHTBarometric(port, temp, press)
}
 
 
@[as_macro]
pub fn setup_pir_deadband(port u8, value u8) bool {
	return SetSensorHTPIRDeadband(port, value)
}
 
@[as_macro]
pub fn read_pir(port u8) i8 {
	return SensorHTPIR(port)
}
 
@[as_macro]
pub fn read_touch_mux(port u8, t1 &u8, t2 &u8, t3 &u8, t4 &u8) {
	ReadSensorHTTouchMultiplexer(port, t1, t2, t3, t4)
}
 

