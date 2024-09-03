// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F8x port)
module pin

// read function reads the logic value of a pin
@[inline]
pub fn read(name u8) u8 {
	return unsafe {
		u8(*(&C.PORTA + (name >> 3))  >>  (name - ((name >> 3) << 3))  &  u8(0x01))
	}// *(&C.PORTA + (name / 8))  >>  (name % 8)  &  0x01
}
