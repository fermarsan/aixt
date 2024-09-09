// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F8x port)
module pin

// high puts a logic 1 to a pin
@[inline]
pub fn high(name u8) {
    unsafe {
		*(&C.PORTA + (name >> 3)) |=  0x01 << (name - ((name >> 3) << 3))
	}// *(&C.PORTA + (name / 8))  |=  0x01 << (name % 8)
}