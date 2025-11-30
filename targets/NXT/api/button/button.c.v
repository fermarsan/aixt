// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Button module for NXT (NXC backend)

module button


// Constants that are part of the NXT firmware's Button module.
@[as_macro] pub const btn1	  = u8(0)       
@[as_macro] pub const btn2	  = u8(1)       
@[as_macro] pub const btn3	  = u8(2)       
@[as_macro] pub const btn4	  = u8(3) 
@[as_macro] pub const no_btns = u8(4)
@[as_macro] pub const exit    = u8(0)       
@[as_macro] pub const right   = u8(1)       
@[as_macro] pub const left	  = u8(2)       
@[as_macro] pub const center  = u8(3) 

// Constants for use with the ButtonState() function.
@[as_macro] pub const pressed   		= 0x01   
@[as_macro] pub const short_released   	= 0x02   
@[as_macro] pub const long_pressed   	= 0x04   
@[as_macro] pub const long_released   	= 0x08   
@[as_macro] pub const pressed_state   	= 0x80   
@[as_macro] pub const _none   			= 0x10   

// Button struct
pub struct Button {
mut:
	id	u8
}

__global (
	exit_btn 	= Button.new(exit)
	right_btn 	= Button.new(right)
	left_btn 	= Button.new(left)
	center_btn 	= Button.new(center)
)


// NXC functions redeclaration
fn C.ButtonPressed(btn u8, reset_count bool) bool
fn C.ButtonCount(btn u8, reset_count bool) u8
fn C.ReadButtonEx(btn u8, reset bool, pressed &bool, count &u32) i8
fn C.ButtonPressCount(btn u8) u8
fn C.ButtonLongPressCount(btn u8) u8 
fn C.ButtonShortReleaseCount(btn u8) u8 
fn C.ButtonLongReleaseCount(btn u8) u8 
fn C.ButtonReleaseCount(btn u8) u8 
fn C.ButtonState(btn u8) u8
fn C.SetButtonPressCount(btn u8, n u8) 
fn C.SetButtonLongPressCount(btn u8, n u8) 
fn C.SetButtonLongReleaseCount(btn u8, n u8) 
fn C.SetButtonReleaseCount(btn u8, n u8) 
fn C.SetButtonShortReleaseCount(btn u8, n u8) 
fn C.SetButtonState(btn u8, state u8) 
fn C.SysReadButton(args ...any) 

//new returns a new Sensor instance
@[inline]
pub fn Button.new(id u8) Sensor {
    return Sensor {
		id: id
	}
}

// Functions for accessing and modifying Button module features. 
@[inline]
pub fn (mut b Button) read(reset_count bool) bool {
	return C.ButtonPressed(b.id, reset_count) 
}

@[inline]
pub fn (mut b Button) count(reset_count bool) u8 {
	return C.ButtonCount(b.id, reset_count) 
}

@[inline]
pub fn (mut b Button) read_ex(reset bool, pressed &bool, count &u32) i8 {
	return C.ReadButtonEx(b.id, reset, pressed, count) 
}

@[inline]
pub fn (mut b Button) press_count() u8 {
	return C.ButtonPressCount(b.id) 
}

@[inline]
pub fn (mut b Button) long_press_count() u8 {
	return C.ButtonLongPressCount(b.id) 
}

@[inline]
pub fn (mut b Button) short_release_count() u8 {
	return C.ButtonShortReleaseCount(b.id) 
}

@[inline]
pub fn (mut b Button) long_release_count() u8 {
	return C.ButtonLongReleaseCount(b.id) 
}

@[inline]
pub fn (mut b Button) release_count() u8 {
	return C.ButtonReleaseCount(b.id) 
}

@[inline]
pub fn (mut b Button) state() u8 {
	return C.ButtonState(b.id) 
}

@[inline]
pub fn (mut b Button) set_long_press_count(n u8) {
	C.SetButtonLongPressCount(b.id, n) 
}

@[inline]
pub fn (mut b Button) set_long_release_count(n u8) {
	C.SetButtonLongReleaseCount(b.id, n) 
}

@[inline]
pub fn (mut b Button) set_press_count(n u8) {
	C.SetButtonPressCount(b.id, n) 
}

@[inline]
pub fn (mut b Button) set_release_count(n u8) {
	C.SetButtonReleaseCount(b.id, n) 
}

@[inline]
pub fn (mut b Button) set_short_release_count(n u8) {
	C.SetButtonShortReleaseCount(b.id, n) 
}

@[inline]
pub fn (mut b Button) set_state(state u8) {
	C.SetButtonState(b.id, state) 
}

@[as_macro]
pub fn read_sys(args ...any)  {
	C.SysReadButton(...args) 
}