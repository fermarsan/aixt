// File: https://github.com/fermarsan/aixt/blob/main/
// Author: Fernando M. Santa
// Date: 2025
//
// ## Description
// Pin management functions for 12F family
module pin_fn

@[as_macro] pub const io0 = 0     // pin `id`s as macros
@[as_macro] pub const io1 = 1
@[as_macro] pub const io2 = 2
@[as_macro] pub const io3 = 3
@[as_macro] pub const io4 = 4
@[as_macro] pub const io5 = 5

@[as_macro] pub const irq = 2     // IRQ (INT) pin


@[as_macro] pub const output = 0  // pin `mode`s as macros
@[as_macro] pub const input  = 1

// setup fucntion configures the `mode` of a pin (by `id`)
@[as_macro]
pub fn setup(id u8, mode u8) {
	if mode == 1 { // as input (1)
		C.TRISIO |= (0x01 << id)
	} else { // as output (0)
		C.TRISIO &= ~(0x01 << id)
	}
}

// high function puts a logical `1` to a pin by its `id`
@[as_macro]
pub fn high(id u8) {
    C.GPIO |=  0x01 << id
}

// low function puts a logical `0` to a pin by its `id`
@[as_macro]
pub fn low(id u8) {
	C.GPIO  &=  ~(0x01 << id)
}

// write function writes a logical `value` to a pin by its `ìd`
@[as_macro]
pub fn write(id u8, value u8) {
	C.GPIO  &=  (~(0x01 << id))	// clean the bit first
	C.GPIO  |=  (value << id)
}

// toggle function toggles the logic value of a pin by its `id`
@[as_macro]
pub fn toggle(id u8) {
	C.GPIO  ^=  0x01 << id
}

// read function reads the logic `value` of a pin by its `id`
@[as_macro]
pub fn read(id u8) u8 {
	return	u8( (C.GPIO  >>  id)  &  0x01 )
}
