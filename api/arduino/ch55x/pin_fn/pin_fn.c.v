// _Author:_
//	- Fernando M. Santa
//	- Katalina Guzman
//	- Paola Carreño
// Date: 2024-2026
//
// ## Description
// Pin management functions Arduino devices
module pin_fn

@[as_macro] pub const p11 = u8(11)  // pin ids
@[as_macro] pub const p14 = u8(14)
@[as_macro] pub const p15 = u8(15)
@[as_macro] pub const p16 = u8(16)
@[as_macro] pub const p17 = u8(17)
@[as_macro] pub const p30 = u8(30)
@[as_macro] pub const p31 = u8(31)
@[as_macro] pub const p32 = u8(32)
@[as_macro] pub const p33 = u8(33)
@[as_macro] pub const p34 = u8(34)

@[as_macro]	pub const led0 = u8(30) // builtin LED

fn init() {
	setup(led0, output)
}
