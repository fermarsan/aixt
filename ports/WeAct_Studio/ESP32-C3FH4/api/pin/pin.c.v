// Project Name : Aixt: http://github.com/fermansan/aixt.git
// Author: Farith Ochoa León, Delipe Cardozo and Fernando M. Santa 
// License : MIT
// Date: 2024-2025
//
// Description: Pin management functions Arduino devices
module pin

// pin names 
pub const d0 = 0 
pub const d1 = 1
pub const d2 = 2
pub const d3 = 3
pub const d4 = 4
pub const d5 = 5
pub const d6 = 6
pub const d7 = 7
pub const d8 = 8
pub const d9 = 9
pub const d10 = 10

pub const d18 = 18
pub const d19 = 19
pub const d20 = 20
pub const d21 = 21

// pin mode
pub const input		= u8(C.INPUT)
pub const output	= u8(C.OUTPUT)
pub const in_pullup = u8(C.INPUT_PULLUP)
pub const in_pulldown = u8(C.INPUT_PULLDOWN)