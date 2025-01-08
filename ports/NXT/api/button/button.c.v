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
fn C.ButtonPressCount(args ...any) u8
fn C.ButtonState(args ...any) u8
fn C.SetButtonPressCount(args ...any) 


// Functions for accessing and modifying Button module features. 
@[as_macro]
pub fn read(btn u8) bool {
	return C.ButtonPressed(btn, false) 
}

@[as_macro]
pub fn read_count(btn u8) u8 {
	return C.ButtonPressCount(btn) 
}

@[as_macro]
pub fn read_state(btn u8) u8 {
	return C.ButtonState(btn) 
}

@[as_macro]
pub fn set_count(btn u8, n u8) {
	C.SetButtonPressCount(btn, n) 
}