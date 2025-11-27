// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2025
// License: MIT
//
// Description: Pin management functions PIC24 Family
module pin

// pin modes
@[as_macro] pub const input		= u8(1)
@[as_macro] pub const output	= u8(0)

// setup configures the mode of a pin
@[as_macro]
pub fn setup(id u8, mode u8) {
	unsafe { 
		if mode == 1 { // as input (1)
			*(&C.TRISA + u16(id / 16)*3)  |=  (0x0001 << (id % 16))
		} else {  // as output (0)    
			*(&C.TRISA + u16(id / 16)*3)  &=  ~(0x0001 << (id % 16))
		}	
	}
}

// high puts a logic 1 to a pin
@[as_macro]
pub fn high(id u8) {
    unsafe {
		*(&C.LATA + u16(id / 16)*3)  |=  0x0001 << (id % 16)
	}
}

// low puts a logic 0 to a pin
@[as_macro]
pub fn low(id u8) {
    unsafe {
		*(&C.LATA + u16(id / 16)*3)  &=  ~(0x0001 << (id % 16))
	}
}

// write function writes a logic value to a pin
@[as_macro]
pub fn write(id u8, value u8) {
	unsafe {
		*(&C.LATA + u16(id / 16)*3)  &=  (~(0x0001 << (id % 16)))
		*(&C.LATA + u16(id / 16)*3)  |=  (value << (id % 16))
	}
}

// toggle function toggles the logic value of a pin
@[as_macro]
pub fn toggle(id u8) {
	unsafe {
		*(&C.LATA + u16(id / 16)*3)  ^=  0x0001 << (id % 16)
	}
}

// read function reads the logic value of a pin
@[as_macro]
pub fn read(id u8) u8 {
	unsafe {
		return	u8( (*(&C.PORTA + u16(id / 16)*3) >> (id % 16))  &  0x0001 )
	}
}