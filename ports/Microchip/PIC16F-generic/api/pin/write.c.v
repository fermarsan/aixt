// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

// write function writes a logic value to a pin
@[as_macro]
pub fn write(name u8, value u8) {
	unsafe {
		*(&C.PORTA + (name >> 3))  &=  (~(0x01 << (name - ((name >> 3) << 3))))	// *(&C.PORTA + (name >> 3)) &= (~(0x01 << (name % 8)))
		*(&C.PORTA + (name >> 3))  |=  (value << (name - ((name >> 3) << 3)))	// *(&C.PORTA + (name >> 3)) |= (value << (name % 8))
	}
}
