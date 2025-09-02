// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2025
// License: MIT
//
// Description: This is a module to emulate digital pines in console.
module pin

#include <stdio.h>
#include <stdlib.h>

pub const a = 0	// pin names
pub const b = 1
pub const c = 2
pub const d = 3
pub const w = 4
pub const x = 5
pub const y = 6
pub const z = 7

__global (
	pin__pins = [0, 0, 0, 0, 0, 0, 0, 0] // virtual pin array
	pin__input_value = 0
)

// update function prints the pins table in the command line
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

// init function initialize the module
fn init() {
	pin.update()
}

// high function puts a high value (logic 1) to a specific pin
@[inline]
pub fn high(pin_id int) {
    pin__pins[pin_id] = 1
    pin.update()
}

// low function puts a low value (logic 0) to a specific pin
@[inline]
pub fn low(pin_id int) {
    pin__pins[pin_id] = 0
    pin.update()
}

// read puts a logic value to a specific pin
@[inline]
pub fn read(pin_id int) int { 
	pin__input_value = 0
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
	C.printf(' Aixt virtual pins input\t  pin %d : ', pin_id)
    C.scanf('%ld', &pin__input_value)
	if pin__input_value == 0 {
        pin__pins[pin_id] = 0
    } else {
        pin__pins[pin_id] = 1
    }
    pin.update()
    return pin__input_value
}

// toggle function toggles the logic value of a specific pin
@[inline]
pub fn toggle(pin_id int) {
    pin__pins[pin_id] ^= int(1)
    pin.update()
}

// write puts a logic value to a specific pin
@[inline]
pub fn write(pin_id int, val int) {  
    pin__pins[pin_id] = val
    pin.update()
}