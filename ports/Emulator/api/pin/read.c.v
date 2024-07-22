// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// write puts a logic value to a specific pin
pub fn read(name int) int {  
	pin__value := 0
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
	C.printf(' Aixt virtual pins input	  pin %ld : ', name)
    C.scanf('%ld', &pin__value)
	if pin__value == 0 {
        pin__pins[name] = 0
    } else {
        pin__pins[name] = 1
    }
    pin.update()
    return pin__value
}