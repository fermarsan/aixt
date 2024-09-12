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
	pin__pins  = [0, 0, 0, 0, 0, 0, 0, 0] // virtual pin array
	input_value = 0
)

enum Pin_names { 
    a = 0
    b
    c
    d
    w
    x
    y
    z
}

// pin_update prints the pins table in the command line
pub fn update() {
	$if linux {
		C.system('clear')
	} $else {
		C.system('cls')
	}
	C.printf(' Aixt virtual pins     [#] = ON   [ ] = OFF\n')
	C.printf(' _____ _____ _____ _____ _____ _____ _____ _____\n')
	C.printf('|  a  |  b  |  c  |  d  |  w  |  x  |  y  |  z  |\n')
	for i in 0 .. 8 {
		C.printf('| [')
		if i <= 3 {
			C.printf('\033[1;32m') // green
		} else {
			C.printf('\033[1;31m') // red
		}
		if pin__pins[i] == 0 {
			C.printf(' ')
		} else {
			C.printf('#')
		}
		C.printf('\033[1;37m') // white
		C.printf('] ')
	}
	C.printf('|\n')
	C.printf("'-----'-----'-----'-----'-----'-----'-----'-----'\n")
}

fn init() {
	pin.update()
}
