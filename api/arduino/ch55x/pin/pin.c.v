// Author: Fernando M. Santa
// Date: 2024
//
// ## Description
// Pin management functions Arduino devices
module pin

@[as_macro] pub const d0 = u8(0)    // pin ids
@[as_macro] pub const d1 = u8(1)
@[as_macro] pub const d2 = u8(2)
@[as_macro] pub const d3 = u8(3)
@[as_macro] pub const d4 = u8(4)
@[as_macro] pub const d5 = u8(5)
@[as_macro] pub const d6 = u8(6)
@[as_macro] pub const d7 = u8(7)
@[as_macro] pub const d8 = u8(8)
@[as_macro] pub const d9 = u8(9)
@[as_macro] pub const d10 = u8(10)
@[as_macro] pub const d11 = u8(11)
@[as_macro] pub const d12 = u8(12)
@[as_macro] pub const d13 = u8(13)
@[as_macro] pub const d14 = u8(14)
@[as_macro] pub const d15 = u8(15)
@[as_macro] pub const d16 = u8(16)
@[as_macro] pub const d17 = u8(17)
@[as_macro] pub const d18 = u8(18)
@[as_macro] pub const d19 = u8(19)
@[as_macro] pub const d20 = u8(20)
@[as_macro] pub const d21 = u8(21)

__global (
	led0 = pin.Pin{ pin.d13 } // builtin LED
)

fn init() {
	led0.setup(pin.output)
}
