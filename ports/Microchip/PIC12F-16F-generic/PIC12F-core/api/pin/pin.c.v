// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: Pin management functions for 12F family
module pin

// pin names as macros
@[as_macro] pub const io0 = 0
@[as_macro] pub const io1 = 1
@[as_macro] pub const io2 = 2
@[as_macro] pub const io3 = 3
@[as_macro] pub const io4 = 4
@[as_macro] pub const io5 = 5


// IRQ (INT) pin
@[as_macro] pub const irq = 2

// pin modes as macros
@[as_macro] pub const output = 0
@[as_macro] pub const input  = 1
