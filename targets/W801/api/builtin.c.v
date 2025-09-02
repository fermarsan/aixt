// Project name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	- Johann Escobar Guzmán 
//	- Daniel Andrés Vásquez Gómez
//	- Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// Description: Builtin definitions (W801 port) 
module main

// builtin LEDs
pub const led0 = u8(C.PB5)
pub const led1 = u8(C.PB25)
pub const led2 = u8(C.PB26)
pub const led3 = u8(C.PB18)
pub const led4 = u8(C.PB17)
pub const led5 = u8(C.PB16)
pub const led6 = u8(C.PB11)

__global (
	led_array = [u8(C.PB5), C.PB25, C.PB26, C.PB18, C.PB17, C.PB16, C.PB11]
)