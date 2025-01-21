// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Button module for M5Stack (arduino backend)

module button	// M5Stack button module

#include "button.c"


const btn_a = u8(0)
const btn_b = u8(1)
const btn_c = u8(2)

fn C.M5_Btn_READ(button any)
fn C.M5_Btn_ISPRESSED(button any)
fn C.M5_Btn_ISRELEASED(button any)
fn C.M5_Btn_WASPRESSED(button any)
fn C.M5_Btn_WASRELEASED(button any)
fn C.M5_Btn_WASRELEASEDFOR(button any)
fn C.M5_Btn_PRESSEDFOR(button any, ms u32)
fn C.M5_Btn_RELEASEDFOR(button any, ms u32)
fn C.M5_Btn_LASTCHANGE(button any)



@[as_macro]
pub fn read(button any) {
	C.M5_Btn_READ(button)	
}

@[as_macro]
pub fn is_pressed(button any) {
	C.M5_Btn_ISPRESSED(button)	
}

@[as_macro]
pub fn is_released(button any) {
	C.M5_Btn_ISRELEASED(button)	
}

@[as_macro]
pub fn was_pressed(button any) {
	C.M5_Btn_WASPRESSED(button)	
}

@[as_macro]
pub fn was_released(button any) {
	C.M5_Btn_WASRELEASED(button)	
}

@[as_macro]
pub fn was_released_for(button any) {
	C.M5_Btn_WASRELEASEDFOR(button)	
}

@[as_macro]
pub fn pressed_for(button any, ms u32) {
	C.M5_Btn_PRESSEDFOR(button, ms)	
}

@[as_macro]
pub fn released_for(button any, ms u32) {
	C.M5_Btn_RELEASEDFOR(button, ms)	
}

@[as_macro]
pub fn last_change(button any) {
	C.M5_Btn_LASTCHANGE(button)	
}
