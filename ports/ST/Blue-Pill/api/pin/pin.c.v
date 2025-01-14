// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management Blue-Pill
module pin

// pin names
pub const a0 = u8(C.PA0)
pub const a1 = u8(C.PA1)
pub const a2 = u8(C.PA2)
pub const a3 = u8(C.PA3)
pub const a4 = u8(C.PA4)
pub const a5 = u8(C.PA5)
pub const a6 = u8(C.PA6)
pub const a7 = u8(C.PA7)
pub const a8 = u8(C.PA8)
pub const a9 = u8(C.PA9)
pub const a10 = u8(C.PA10)
pub const a11 = u8(C.PA11)
pub const a12 = u8(C.PA12)
pub const a13 = u8(C.PA13)
pub const a14 = u8(C.PA14)
pub const a15 = u8(C.PA15)

pub const b0 = u8(C.PB0)
pub const b1 = u8(C.PB1)
pub const b2 = u8(C.PB2)
pub const b3 = u8(C.PB3)
pub const b4 = u8(C.PB4)
pub const b5 = u8(C.PB5)
pub const b6 = u8(C.PB6)
pub const b7 = u8(C.PB7)
pub const b8 = u8(C.PB8)
pub const b9 = u8(C.PB9)
pub const b10 = u8(C.PB10)
pub const b11 = u8(C.PB11)
pub const b12 = u8(C.PB12)
pub const b13 = u8(C.PB13)
pub const b14 = u8(C.PB14)
pub const b15 = u8(C.PB15)

// pub const c0 = u8(C.PC0)
// pub const c1 = u8(C.PC1)
// pub const c2 = u8(C.PC2)
// pub const c3 = u8(C.PC3)
// pub const c4 = u8(C.PC4)
// pub const c5 = u8(C.PC5)
// pub const c6 = u8(C.PC6)
// pub const c7 = u8(C.PC7)
// pub const c8 = u8(C.PC8)
// pub const c9 = u8(C.PC9)
// pub const c10 = u8(C.PC10)
// pub const c11 = u8(C.PC11)
// pub const c12 = u8(C.PC12)
pub const c13 = u8(C.PC13)
pub const c14 = u8(C.PC14)
pub const c15 = u8(C.PC15)


// pin modes
pub const input		= 0
pub const output	= 1
pub const in_pullup = 2
