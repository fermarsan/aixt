// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F8x port)
module pin

// low puts a logic 0 to a pin
@[inline]
pub fn low(name u8) {
	unsafe {
		*(&C.PORTA + (name >> 3))  &=  ~(u8(0x01) << (name - ((name >> 3) << 3)))
	}// *(&C.PORTA + (name / 8))   &=  ~(0x01 << (name % 8))
}
