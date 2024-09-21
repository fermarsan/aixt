// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Authors:
//	- Johann Escobar Guzmán 
//	- Daniel Andrés Vásquez Gómez
//	- Fernando M. Santa
// Date: 2023-2024
// License: MIT
//
// Description: Builtin definitions (W801 port) 
module main

enum Pin_names { // enumerated type for digital pin names
    
	a1	 = C.PB21
	a2
	a3
	a4
	a5
	a6

	pin1 = C.PB21
	pin2
	
}

enum Builtin_names {
	led1 = PB25
	led2 = PB26
	led3 = PB18
	led4 = PB16
	led5 = PB17
	led6 = PB11
	led7 = PB5

}

enum Pin_modes {  
    input  = C.INPUT  
	output
}

enum Port__names {
	b = 0
	c
	d
}