// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate digital pines in console.
module pin

#include <stdio.h>
#include <stdlib.h>

__global (
    pins__ = [0, 0, 0, 0, 0, 0, 0, 0]   // virtual pin array
    input__ = 0
)

// pin_update prints the pins table in the command line
pub fn C.update()

fn init() {
    pin.update()
}