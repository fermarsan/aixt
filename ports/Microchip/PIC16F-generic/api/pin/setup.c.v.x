// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F8x port)
module pin

// setup configures the mode of a pin
@[inline]
pub fn setup(name u8, mode u8) {
	unsafe { 
		addr = &C.TRISA + (name >> 3)  // &C.TRISA + (name / 8)		// base address plus shift
		if mode == input { // as input (1)
			*addr |= (u8(0x01) << (name - ((name >> 3) << 3)))
			// |=  (u8(0x01) << (name % 8))
		} else { // as output (0)
			*addr &= ~(u8(0x01) << (name - ((name >> 3) << 3)))
			// &= ~(u8(0x01) << (name % 8))
		}
	}
}
