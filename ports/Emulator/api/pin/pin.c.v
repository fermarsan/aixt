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

// pin names
#define pin__a  0
#define pin__b  1
#define pin__c  2
#define pin__d  3
#define pin__w  4
#define pin__x  5
#define pin__y  6
#define pin__z  7

// pin_update prints the pins table in the command line
pub fn C.update()

fn init() {
    pin.update()
}