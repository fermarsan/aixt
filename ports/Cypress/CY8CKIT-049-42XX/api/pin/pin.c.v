// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: pin functions (CY8CKIT-049-42XX)

module pin

#include "pin.c"


fn C.PIN_WRITE(name any, value any) 
fn C.PIN_HIGH(name any) 
fn C.PIN_LOW(name any)
fn C.PIN_READ(name any) u8

