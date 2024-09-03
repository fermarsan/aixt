// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F8x port)
module pin

// write function writes a logic value to a pin
@[inline]
pub fn write(name u8, value u8) {
	unsafe {
		addr = &C.PORTA + (name >> 3) // &(C.PORTA) + (name / 8)
		*addr  &=  (~(u8(0x01) << (name - ((name >> 3) << 3)))) // *addr &= (~((0x01) << (name % 8)))
		*addr  |=  (value << (name - ((name >> 3) << 3))) // *addr |= (value << (name % 8))
	}
}
