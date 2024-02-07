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
pub fn update() {
    system("clear")
    printf(" Aixt virtual pins     [#] = ON   [ ] = OFF\n")
    printf(" _____ _____ _____ _____ _____ _____ _____ _____\n")
    printf("|  a  |  b  |  c  |  d  |  w  |  x  |  y  |  z  |\n")
    for i__ := 0; i__<=7; i__++ {
        if pins__[i__] == 0 {
            printf("| [ ] ")
        } else {
            printf("| [#] ")
        }
    }
    printf("|\n")
    printf("'-----'-----'-----'-----'-----'-----'-----'-----'\n")
}