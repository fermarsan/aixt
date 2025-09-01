// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin_oop

// write puts a logic value to a specific pin
@[inline]
pub fn (mut pin Pin) read() int {  
	pin__input_value = 0
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
	C.printf(' Aixt virtual pins input	  pin %d : ', pin.id)
    C.scanf('%ld', &pin__input_value)
	if pin__input_value == 0 {
        pin__pins[pin.id] = 0
    } else {
        pin__pins[pin.id] = 1
    }
    pin_oop.update()
    return pin__input_value
}
