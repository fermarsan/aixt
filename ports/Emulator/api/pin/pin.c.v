// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
//
// Description: This is a module to emulate digital pines in console.
module pin

#include <stdio.h>
#include <stdlib.h>

const (
    a = 0
    b = 1
    c = 2
    d = 3
    w = 4
    x = 5
    y = 6
    z = 7
)

// struct PinStruct {
//     pins    []int{cap: 8}
//     input   int
// }

__global (
    pin__pins = [0, 0, 0, 0, 0, 0, 0, 0]   // virtual pin array
    pin__input = 0
)

// pin_update prints the pins table in the command line
pub fn update() {
    main.clear_screen()
    C.printf(' Aixt virtual pins     [#] = ON   [ ] = OFF\n')
    C.printf(' _____ _____ _____ _____ _____ _____ _____ _____\n')
    C.printf('|  a  |  b  |  c  |  d  |  w  |  x  |  y  |  z  |\n')
    for i in 0..8 {
        C.printf('| [')
        if i <= 3 {
            C.printf('\033[1;32m')    // green
        } else {
            C.printf('\033[1;31m')    // red
        }
        if pin__pins[i] == 0 {
            C.printf(' ')
        } else {
            C.printf('#')
        }
        C.printf('\033[1;37m')    // white
        C.printf('] ')
    }
    C.printf('|\n')
    C.printf("'-----'-----'-----'-----'-----'-----'-----'-----'\n")
}

fn init() {
    pin.update()
}