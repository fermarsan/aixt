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
pub fn as_gyro(args ..any) {
	C.SetSensorHTGyro(...args)
}
 
@[as_macro]
pub fn as_magnet(args ..any) {
	C.SetSensorHTMagnet(...args)
}
 
@[as_macro]
pub fn as_eopd(args ..any) {
	C.SetSensorHTEOPD(...args)
}
 
@[as_macro]
pub fn as_force(args ..any) {
	C.SetSensorHTForce(...args)
}
 
 
@[as_macro]
pub fn read_gyro(args ..any) i16 {
	return C.SensorHTGyro(...args)
}
 
 
@[as_macro]
pub fn read_magnet(args ..any) i16 {
	return C.SensorHTMagnet(...args)
}
 
 
@[as_macro]
pub fn read_eopd(args ..any) i16 {
	return C.SensorHTEOPD(...args)
}
 
 
@[as_macro]
pub fn read_force(args ..any) i16 {
	return C.SensorHTForce(...args)
}
 
 
@[as_macro]
pub fn read_color_num(args ..any) i16 {
	return C.SensorHTColorNum(...args)
}
 
 
@[as_macro]
pub fn read_compass(args ..any) i16 {
	return C.SensorHTCompass(...args)
}
 
@[as_macro]
pub fn read_ir_seeker_dir(args ..any) i16 {
	return C.SensorHTIRSeekerDir(...args)
}

@[as_macro]
pub fn as_color(args ..any) i8 {
	return C.SetHTColor2Mode(...args)
}
 
@[as_macro]
pub fn as_ir_seeker(args ..any) i8 {
	return C.SetHTIRSeeker2Mode(...args)
}
 
@[as_macro]
pub fn read_accel(args ..any) bool {
	return C.ReadSensorHTAccel(...args)
}
 
@[as_macro]
pub fn read_color(args ..any) bool {
	return C.ReadSensorHTColor(...args)
}
 
@[as_macro]
pub fn read_ir_seeker(args ..any) bool {
	return C.ReadSensorHTIRSeeker(...args)
}
 
@[as_macro]
pub fn read_norm_color(args ..any) bool {
	return C.ReadSensorHTNormalizedColor(...args)
}
 
@[as_macro]
pub fn read_raw_color(args ..any) bool {
	return C.ReadSensorHTRawColor(...args)
}

 
@[as_macro]
pub fn read_ir_receiver(args ..any) bool {
	return C.ReadSensorHTIRReceiver(...args)
}
 
@[as_macro]
pub fn reset_angle(args ..any) i8 {
	return C.ResetSensorHTAngle(...args)
}
 
@[as_macro]
pub fn read_angle(args ..any) bool {
	return C.ReadSensorHTAngle(...args)
}
 
@[as_macro]
pub fn reset_barometric(args ..any) bool {
	C.ResetHTBarometricCalibration(u8 port)
}
 
@[as_macro]
pub fn as_barometric(args ..any) bool {
	return C.SetHTBarometricCalibration(...args)
}
 
@[as_macro]
pub fn read_barometric(args ..any) bool {
	return C.ReadSensorHTBarometric(...args)
}
 
 
@[as_macro]
pub fn as_pir(args ..any) bool {
	return C.SetSensorHTPIRDeadband(...args)
}
 
@[as_macro]
pub fn read_pir(args ..any) i8 {
	return C.SensorHTPIR(...args)
}
 
@[as_macro]
pub fn read_touch_mux(args ..any) {
	C.ReadSensorHTTouchMultiplexer(...args)
}
 

