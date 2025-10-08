// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2025
// License: MIT
//
// Description: Pin management functions PIC24 Family
module pin

#include <p24FJ128GA010.h>


// high puts a logic 1 to a pin
@[as_macro]
pub fn high(id u8) {
    unsafe {
		*(&C.PORTA + (id >> 3)) |=  0x01 << (id- ((id >> 3) << 3))
	}// *(&C.PORTA + (id / 8))  |=  0x01 << (id % 8)
}

// low puts a logic 0 to a pin
@[as_macro]
pub fn low(id u8) {
	unsafe {
		*(&C.PORTA + (id >> 3))  &=  ~(0x01 << (id- ((id >> 3) << 3)))
	}// *(&C.PORTA + (id / 8))   &=  ~(0x01 << (id % 8))
}

// read function reads the logic value of a pin
@[as_macro]
pub fn read(id u8) u8 {
	unsafe {
		return	u8( (*(&C.PORTA + (id >> 3))  >>  (id- ((id >> 3) << 3)))  &  0x01 )
	}// return	u8( (*(&C.PORTA + (id / 8))   >>  (id % 8))  &  0x01 )
}

// setup configures the mode of a pin
@[as_macro]
pub fn setup(id u8, mode u8) {
	unsafe { 
		if mode == 1 { // as input (1)
			*(&C.TRISA + (id >> 3)) |= (0x01 << (id- ((id >> 3) << 3)))
		//  *(&C.TRISA + (id / 8))  |= (0x01 << (id % 8))
		} else { // as output (0)
			*(&C.TRISA + (id >> 3)) &= ~(0x01 << (id- ((id >> 3) << 3)))	
		//  *(&C.TRISA + (id / 8))  &= ~(0x01 << (id % 8))
		}
	}
}

// toggle function toggles the logic value of a pin
@[as_macro]
pub fn TOGGLE(id u8) {
	unsafe {
		*(&C.PORTA + (id >> 3))  ^=  0x01 << (id- ((id >> 3) << 3))
	}// *(&C.PORTA + (id / 8))   ^=  0x01 << (id % 8)
}

// write function writes a logic value to a pin
@[as_macro]
pub fn write(id u8, value u8) {
	unsafe {
		*(&C.PORTA + (id >> 3))  &=  (~(0x01 << (id- ((id >> 3) << 3))))	// *(&C.PORTA + (id >> 3)) &= (~(0x01 << (id % 8)))
		*(&C.PORTA + (id >> 3))  |=  (value << (id- ((id >> 3) << 3)))	// *(&C.PORTA + (id >> 3)) |= (value << (id % 8))
	}
}