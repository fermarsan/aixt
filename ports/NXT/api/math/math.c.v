// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Math module for NXT (NXC backend)

module math

// Miscellaneous NBC/NXC constants
@[as_macro] pub const pi			= C.PI
@[as_macro] pub const rad_per_deg	= C.RADIANS_PER_DEGREE
@[as_macro] pub const deg_per_rad	= C.DEGREES_PER_RADIAN

// cmath.h
@[as_macro]
pub fn sqrt(x f32) f32{
	return C.sqrt(x) 
}

@[as_macro]
pub fn cos(x f32) f32 {
	return C.cos(x) 
}

@[as_macro]
pub fn sin(x f32) f32 {
	return C.sin(x) 
}

@[as_macro]
pub fn tan(x f32) f32 {
	return C.tan(x) 
}

@[as_macro]
pub fn acos(x f32) f32 {
	return C.acos(x) 
}

@[as_macro]
pub fn asin(x f32) f32 {
	return C.asin(x) 
}

@[as_macro]
pub fn atan(x f32) f32 {
	return C.atan(x) 
}

@[as_macro]
pub fn atan2(y f32, x f32) f32 {
	return C.atan2(y, x) 
}

@[as_macro]
pub fn cosh(x f32) f32 {
	return C.cosh(x) 
}

@[as_macro]
pub fn sinh(x f32) f32 {
	return C.sinh(x) 
}

@[as_macro]
pub fn tanh(x f32) f32 {
	return C.tanh(x) 
}

@[as_macro]
pub fn exp(x f32) f32 {
	return C.exp(x) 
}

@[as_macro]
pub fn log(x f32) f32 {
	return C.log(x) 
}

@[as_macro]
pub fn log10(x f32) f32 {
	return C.log10(x) 
}

@[as_macro]
pub fn trunc(x f32) f32 {
	return C.trunc(x) 
}

@[as_macro]
pub fn frac(x f32) f32 {
	return C.frac(x) 
}

@[as_macro]
pub fn pow(base f32, exponent f32) f32 {
	return C.pow(base, exponent) 
}

@[as_macro]
pub fn ceil(x f32) f32 {
	return C.ceil(x) 
}

@[as_macro]
pub fn floor(x f32) f32 {
	return C.floor(x) 
}

@[as_macro]
pub fn cosd(x f32) f32 {
	return C.cosd(x) 
}

@[as_macro]
pub fn sind(x f32) f32 {
	return C.sind(x) 
}

@[as_macro]
pub fn tand(x f32) f32 {
	return C.tand(x) 
}

@[as_macro]
pub fn acosd(x f32) f32 {
	return C.acosd(x) 
}

@[as_macro]
pub fn asind(x f32) f32 {
	return C.asind(x f32) 
}

@[as_macro]
pub fn atand(x f32) f32 {
	return C.atand(x) 
}

@[as_macro]
pub fn atan2d(y f32, x f32) f32 {
	return C.atan2d(y, x) 
}

@[as_macro]
pub fn coshd(x f32) f32 {
	return C.coshd(x) 
}

@[as_macro]
pub fn sinhd(x f32) f32 {
	return C.sinhd(x) 
}

@[as_macro]
pub fn tanhd(x f32) f32 {
	return C.tanhd(x) 
}

@[as_macro]
pub fn bcd2dec(bcd u8) u8 {
	return C.bcd2dec(bcd) 
}

// cstdlib.c
@[as_macro]
pub fn abs(num any) any {
	return C.abs(num) 
}

@[as_macro]
pub fn labs(n i32) i32 {
	return C.labs(n) 
}

