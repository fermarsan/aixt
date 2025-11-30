// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Button module for NXT (NXC backend)

module button


// Constants that are part of the NXT firmware's Button module.
@[as_macro] pub const btn1	  = 0       
@[as_macro] pub const btn2	  = 1       
@[as_macro] pub const btn3	  = 2       
@[as_macro] pub const btn4	  = 3 
@[as_macro] pub const no_btns = 4
@[as_macro] pub const exit    = 0       
@[as_macro] pub const right   = 1       
@[as_macro] pub const left	  = 2       
@[as_macro] pub const center  = 3 

// Constants for use with the ButtonState() function.
@[as_macro] pub const pressed   		= 0x01   
@[as_macro] pub const short_released   	= 0x02   
@[as_macro] pub const long_pressed   	= 0x04   
@[as_macro] pub const long_released   	= 0x08   
@[as_macro] pub const pressed_state   	= 0x80   
@[as_macro] pub const _none   			= 0x10   


fn C.ButtonPressed(args ...any) bool
fn C.ButtonCount(args ...any) u8
fn C.ReadButtonEx(args ...any) i8
fn C.ButtonPressCount(args ...any) u8
fn C.ButtonLongPressCount(args ...any) u8 
fn C.ButtonShortReleaseCount(args ...any) u8 
fn C.ButtonLongReleaseCount(args ...any) u8 
fn C.ButtonReleaseCount(args ...any) u8 
fn C.ButtonState(args ...any) u8
fn C.SetButtonPressCount(args ...any) 
fn C.SetButtonLongPressCount(args ...any) 
fn C.SetButtonLongReleaseCount(args ...any) 
fn C.SetButtonReleaseCount(args ...any) 
fn C.SetButtonShortReleaseCount(args ...any) 
fn C.SetButtonState(args ...any) 
fn C.SysReadButton(args ...any) 


// Functions for accessing and modifying Button module features. 
@[as_macro]
pub fn read(args ...any) bool {
	return C.ButtonPressed(...args) 
}

@[as_macro]
pub fn count(args ...any) u8 {
	return C.ButtonCount(...args) 
}

@[as_macro]
pub fn read_ex(args ...any) i8 {
	return C.ReadButtonEx(...args) 
}

@[as_macro]
pub fn press_count(args ...any) u8 {
	return C.ButtonPressCount(...args) 
}

@[as_macro]
pub fn long_press_count(args ...any) u8 {
	return C.ButtonLongPressCount(...args) 
}

@[as_macro]
pub fn short_release_count(args ...any) u8 {
	return C.ButtonShortReleaseCount(...args) 
}

@[as_macro]
pub fn long_release_count(args ...any) u8 {
	return C.ButtonLongReleaseCount(...args) 
}

@[as_macro]
pub fn release_count(args ...any) u8 {
	return C.ButtonReleaseCount(...args) 
}

@[as_macro]
pub fn state(args ...any) u8 {
	return C.ButtonState(...args) 
}

@[as_macro]
pub fn set_long_press_count(args ...any) {
	return C.SetButtonLongPressCount(...args) 
}

@[as_macro]
pub fn set_long_release_count(args ...any) {
	return C.SetButtonLongReleaseCount(...args) 
}

@[as_macro]
pub fn set_press_count(args ...any) {
	C.SetButtonPressCount(btn, n) 
}

@[as_macro]
pub fn set_release_count(args ...any) {
	return C.SetButtonReleaseCount(...args) 
}

@[as_macro]
pub fn set_short_release_count(args ...any) {
	return C.SetButtonShortReleaseCount(...args) 
}

@[as_macro]
pub fn set_state(args ...any) {
	return C.SetButtonState(...args) 
}

@[as_macro]
pub fn read_sys(args ...any) {
	return C.SysReadButton(...args) 
}