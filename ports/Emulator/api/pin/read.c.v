// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module pin

// write puts a logic value to a specific pin
pub fn read(name int) int {  
	input_value := 0
    $if linux {
        C.system("clear")
    } $else {
        C.system("cls")
    }
	C.printf(' Aixt virtual pins input	  pin %ld : ', name)
    C.scanf('%ld', &input_value)
	if input_value == 0 {
        pin__pins[name] = 0
    } else {
        pin__pins[name] = 1
    }
    pin.update()
    return input_value
}