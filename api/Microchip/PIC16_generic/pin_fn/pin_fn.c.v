// File: https://github.com/fermarsan/aixt/blob/main/api/Microchip/PIC16_generic/PIC16_core/api/pin_fn/pin_fn.c.v
// Author: Fernando M. Santa
// Date: 2024-2025
//
// ## Description
// Pin management functions for the PIC16F family.
module pin_fn

// setup function configures the mode of a pin.
// `id` is the pin id for example `pin.c7` and
// `mode` is the pin mode, `pin.input` or `pin.output`.
@[as_macro]
pub fn setup(id u8, mode u8) {
	unsafe {
		if mode == 1 { // as input (1)
			*(&C.TRISA + (id / 8))  |=  (0x01 << (id % 8))
		} else { // as output (0)
			*(&C.TRISA + (id / 8))  &=  ~(0x01 << (id % 8))
		}
	}
}

// high function puts a logic `1` to a pin through its `id`
@[as_macro]
pub fn high(id u8) {
    unsafe {
		*(&C.PORTA + (id / 8))  |=  0x01 << (id % 8)
	}
}

// low function puts a logic `0` to a pin through its `id`
@[as_macro]
pub fn low(id u8) {
	unsafe {
		*(&C.PORTA + (id / 8))  &=  ~(0x01 << (id % 8))
	}
}

// write function writes a logic `value` to a pin through its `id`
@[as_macro]
pub fn write(id u8, value u8) {
	unsafe {
		*(&C.PORTA + (id >> 3))  &=  (~(0x01 << (id % 8)))
		*(&C.PORTA + (id >> 3))  |=  (value << (id % 8))
	}
}

// toggle function toggles the logic `value` of a pin through its `id`
@[as_macro]
pub fn toggle(id u8) {
	unsafe {
		*(&C.PORTA + (id / 8))  ^=  0x01 << (id % 8)
	}
}

// read function reads the logic value of a pin pin through its `id`
@[as_macro]
pub fn read(id u8) u8 {
	unsafe {
		return	u8( (*(&C.PORTA + (id / 8)) >> (id % 8))  &  0x01 )
	}
}
