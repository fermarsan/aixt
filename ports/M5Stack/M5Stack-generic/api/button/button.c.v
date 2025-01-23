// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Button module for M5Stack (arduino backend)

module button	// M5Stack button module

#include "button.c"


pub const a_pin = u8(39)
pub const b_pin = u8(38)
pub const c_pin = u8(37)

pub const a = u8(0)
pub const b = u8(1)
pub const c = u8(2)

fn C.M5_BTNA_READ()
fn C.M5_BTNA_ISPRESSED() bool
fn C.M5_BTNA_ISRELEASED() bool
fn C.M5_BTNA_WASPRESSED() bool
fn C.M5_BTNA_WASRELEASED() bool
fn C.M5_BTNA_WASRELEASEDFOR(ms u32) bool
fn C.M5_BTNA_PRESSEDFOR(ms u32) bool
fn C.M5_BTNA_RELEASEDFOR(ms u32) bool
fn C.M5_BTNA_PRESSEDFORCTIME(ms u32, continuous_time u32) bool
fn C.M5_BTNA_LASTCHANGE()
fn C.M5_BTNB_READ()
fn C.M5_BTNB_ISPRESSED() bool
fn C.M5_BTNB_ISRELEASED() bool
fn C.M5_BTNB_WASPRESSED() bool
fn C.M5_BTNB_WASRELEASED() bool
fn C.M5_BTNB_WASRELEASEDFOR(ms u32) bool
fn C.M5_BTNB_PRESSEDFOR(ms u32) bool
fn C.M5_BTNB_RELEASEDFOR(ms u32) bool
fn C.M5_BTNB_PRESSEDFORCTIME(ms u32, continuous_time u32) bool
fn C.M5_BTNB_LASTCHANGE()
fn C.M5_BTNC_READ()
fn C.M5_BTNC_ISPRESSED() bool
fn C.M5_BTNC_ISRELEASED() bool
fn C.M5_BTNC_WASPRESSED() bool
fn C.M5_BTNC_WASRELEASED() bool
fn C.M5_BTNC_WASRELEASEDFOR(ms u32) bool
fn C.M5_BTNC_PRESSEDFOR(ms u32) bool
fn C.M5_BTNC_RELEASEDFOR(ms u32) bool
fn C.M5_BTNC_PRESSEDFORCTIME(ms u32, continuous_time u32) bool
fn C.M5_BTNC_LASTCHANGE()


@[inline]
pub fn read(btn u8) {
	match btn {
		button.a {
			C.M5_BTNA_READ()
		}
		button.b {
			C.M5_BTNB_READ()
		}
		button.c {
			C.M5_BTNC_READ()	
		}
		else {
			
		}
	}
}

@[inline]
pub fn is_pressed(btn u8) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_ISPRESSED()
		}
		button.b {
			return 	C.M5_BTNB_ISPRESSED()
		}
		button.c {
			return 	C.M5_BTNC_ISPRESSED()	
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn is_released(btn u8) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_ISRELEASED()	
		}
		button.b {
			return 	C.M5_BTNB_ISRELEASED()	
		}
		button.c {
			return 	C.M5_BTNC_ISRELEASED()		
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn was_pressed(btn u8) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_WASPRESSED()
		}
		button.b {
			return 	C.M5_BTNB_WASPRESSED()
		}
		button.c {
			return 	C.M5_BTNC_WASPRESSED()	
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn was_released(btn u8) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_WASRELEASED()
		}
		button.b {
			return 	C.M5_BTNB_WASRELEASED()
		}
		button.c {
			return 	C.M5_BTNC_WASRELEASED()	
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn was_released_for(btn u8, ms u32) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_WASRELEASEDFOR(ms)
		}
		button.b {
			return 	C.M5_BTNB_WASRELEASEDFOR(ms)
		}
		button.c {
			return 	C.M5_BTNC_WASRELEASEDFOR(ms)	
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn pressed_for(btn u8, ms u32) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_PRESSEDFOR(ms)
		}
		button.b {
			return 	C.M5_BTNB_PRESSEDFOR(ms)
		}
		button.c {
			return 	C.M5_BTNC_PRESSEDFOR(ms)	
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn pressed_for_ctime(btn u8, ms u32, continuous_time u32) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_PRESSEDFORCTIME(ms, continuous_time)
		}
		button.b {
			return 	C.M5_BTNB_PRESSEDFORCTIME(ms, continuous_time)
		}
		button.c {
			return 	C.M5_BTNC_PRESSEDFORCTIME(ms, continuous_time)	
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn released_for(btn u8, ms u32) bool {
	match btn {
		button.a {
			return 	C.M5_BTNA_RELEASEDFOR(ms)	
		}
		button.b {
			return 	C.M5_BTNB_RELEASEDFOR(ms)	
		}
		button.c {
			return 	C.M5_BTNC_RELEASEDFOR(ms)		
		}
		else {
			return false
		}
	}
}

@[inline]
pub fn last_change(btn u8) {
	match btn {
		button.a {
			C.M5_BTNA_LASTCHANGE()
		}
		button.b {
			C.M5_BTNB_LASTCHANGE()
		}
		button.c {
			C.M5_BTNC_LASTCHANGE()	
		}
		else {
			
		}
	}
}
