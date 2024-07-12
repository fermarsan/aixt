// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate digital pines in console.
module pin

#include <stdio.h>
#include <stdlib.h>
#include "pin.c"
#include "update.c"

__global (
    pin__pins = [0, 0, 0, 0, 0, 0, 0, 0]   // virtual pin array
    pin__input = 0
)

// pin_update prints the pins table in the command line
pub fn update()

fn init() {
    pin.update()
}