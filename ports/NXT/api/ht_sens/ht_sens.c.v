// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: HiTechnic sensors module for NXT(NXC backend)

module ht_sens

fn C.SetSensorHTGyro(args ...any)
fn C.SetSensorHTMagnet(args ...any)
fn C.SetSensorHTEOPD(args ...any)
fn C.SetSensorHTForce(args ...any)
fn C.SensorHTGyro(args ...any) i16
fn C.SensorHTMagnet(args ...any) i16
fn C.SensorHTEOPD(args ...any) i16
fn C.SensorHTForce(args ...any) i16
fn C.SensorHTColorNum(args ...any) i16
fn C.SensorHTCompass(args ...any) i16
fn C.SensorHTIRSeekerDir(args ...any) i16
fn C.SetHTColor2Mode(args ...any) i8
fn C.SetHTIRSeeker2Mode(args ...any) i8
fn C.ReadSensorHTAccel(args ...any) bool
fn C.ReadSensorHTColor(args ...any) bool
fn C.ReadSensorHTIRSeeker(args ...any) bool
fn C.ReadSensorHTNormalizedColor(args ...any) bool
fn C.ReadSensorHTRawColor(args ...any) bool
fn C.ReadSensorHTIRReceiver(args ...any) bool
fn C.ResetSensorHTAngle(args ...any) i8
fn C.ReadSensorHTAngle(args ...any) bool
fn C.ResetHTBarometricCalibration(args ...any) bool
fn C.SetHTBarometricCalibration(args ...any) bool
fn C.ReadSensorHTBarometric(args ...any) bool
fn C.SetSensorHTPIRDeadband(args ...any) bool
fn C.SensorHTPIR(args ...any) i8
fn C.ReadSensorHTTouchMultiplexer(args ...any)

@[as_macro]
pub fn as_gyro(port u8) {
	C.SetSensorHTGyro(port)
}
 
@[as_macro]
pub fn as_magnet(port u8) {
	C.SetSensorHTMagnet(port)
}
 
@[as_macro]
pub fn as_eopd(port u8, b_standard bool) {
	C.SetSensorHTEOPD(port, b_standard)
}
 
@[as_macro]
pub fn as_force(port u8) {
	C.SetSensorHTForce(port)
}
 
 
@[as_macro]
pub fn read_gyro(port u8, offset i16) i16 {
	return C.SensorHTGyro(port, offset)
}
 
 
@[as_macro]
pub fn read_magnet(port u8, offset i16) i16 {
	return C.SensorHTMagnet(port, offset)
}
 
 
@[as_macro]
pub fn read_eopd(port u8) i16 {
	return C.SensorHTEOPD(port)
}
 
 
@[as_macro]
pub fn read_force(port u8) i16 {
	return C.SensorHTForce(port)
}
 
 
@[as_macro]
pub fn read_color_num(port u8) i16 {
	return C.SensorHTColorNum(port)
}
 
 
@[as_macro]
pub fn read_compass(port u8) i16 {
	return C.SensorHTCompass(port)
}
 
@[as_macro]
pub fn read_ir_seeker_dir(port u8) i16 {
	return C.SensorHTIRSeekerDir(port)
}

@[as_macro]
pub fn as_color(port u8, mode u8) i8 {
	return C.SetHTColor2Mode(port, mode)
}
 
@[as_macro]
pub fn as_ir_seeker(port u8, mode u8) i8 {
	return C.SetHTIRSeeker2Mode(port, mode)
}
 
@[as_macro]
pub fn read_accel(port u8, x &i16, y  &i16, z  &i16) bool {
	return C.ReadSensorHTAccel(port, x, y, z)
}
 
@[as_macro]
pub fn read_color(port u8, color_num &u8,  red &u8, green &u8, blue &u8) bool {
	return C.ReadSensorHTColor(port, color_num, red, green, blue)
}
 
@[as_macro]
pub fn read_ir_seeker(port u8, dir &u8, s1 &u8, s3 &u8, s5 &u8, s7 &u8, s9 &u8) bool {
	return C.ReadSensorHTIRSeeker(port, dir, s1, s3, s5, s7, s9)
}
 
@[as_macro]
pub fn read_norm_color(port u8, idx &u8, red &u8, green &u8, blue &u8) bool {
	return C.ReadSensorHTNormalizedColor(port, idx, red, green, blue)
}
 
@[as_macro]
pub fn read_raw_color(port u8, red &u16, green &u16, blue &u16) bool {
	return C.ReadSensorHTRawColor(port, red, green, blue)
}

 
@[as_macro]
pub fn read_ir_receiver(port u8, pfdata &[]i8{}) bool {
	return C.ReadSensorHTIRReceiver(port, pfdata)
}
 
@[as_macro]
pub fn reset_angle(port u8, mode u8) i8 {
	return C.ResetSensorHTAngle(port, mode)
}
 
@[as_macro]
pub fn read_angle(port u8, angle &i16, acc_angle &int, rpm &i16) bool {
	return C.ReadSensorHTAngle(port, angle, acc_angle, rpm)
}
 
@[as_macro]
pub fn reset_barometric(port u8) bool {
	ResetHTBarometricCalibration(u8 port)
}
 
@[as_macro]
pub fn setup_barometric(port u8) bool {
	return C.SetHTBarometricCalibration(u8 port, unsigned i16 cal)
}
 
@[as_macro]
pub fn read_barometric(port u8, temp &i16, press &u16) bool {
	return C.ReadSensorHTBarometric(port, temp, press)
}
 
 
@[as_macro]
pub fn setup_pir_deadband(port u8, value u8) bool {
	return C.SetSensorHTPIRDeadband(port, value)
}
 
@[as_macro]
pub fn read_pir(port u8) i8 {
	return C.SensorHTPIR(port)
}
 
@[as_macro]
pub fn read_touch_mux(port u8, t1 &u8, t2 &u8, t3 &u8, t4 &u8) {
	C.ReadSensorHTTouchMultiplexer(port, t1, t2, t3, t4)
}
 

