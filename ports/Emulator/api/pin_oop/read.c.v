// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2025
// License: MIT
module pin_oop

// write puts a logic value to a specific pin
@[as_macro]
pub fn read(name int) int {  
	pin__input_value = 0
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
	C.printf(' Aixt virtual pins input	  pin %d : ', name)
    C.scanf('%ld', &pin__input_value)
	if pin__input_value == 0 {
        pin__pins[name] = 0
    } else {
        pin__pins[name] = 1
    }
    pin_oop.update()
    return pin__input_value
}